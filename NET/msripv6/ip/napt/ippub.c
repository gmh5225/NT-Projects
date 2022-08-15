// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil -*- (for GNU Emacs)
//
// Copyright (c) 1985-2000 Microsoft Corporation
//
// This file is part of the Microsoft Research IPv6 Network Protocol Stack.
// You should have received a copy of the Microsoft End-User License Agreement
// for this software along with this release; see the file "license.txt".
// If not, please see http://www.research.microsoft.com/msripv6/license.htm,
// or write to Microsoft Research, One Microsoft Way, Redmond, WA 98052-6399.
//

//////////////////////////////////////////////////////////////////////
// NAPT support to send RAW IP4 packets on NT5.0 Beta2 using TDI
// and the IPHDRINCL option.  This code is based on the Tunnel
// support from the tcpip6.
//
// MEFBUG: NT5.0 Beta2 ntos/tdi/tcpipmerge/ip/ipxmit.c requires minor
// MEFBUG: modification to send 'really' raw IP packets.
//

#include "oscfg.h"
#include "ndis.h"
#include "tdi.h"
#include "tdiinfo.h"
#include "tdikrnl.h"
#include "ntddtcp.h"

#include "naptdef.h"

//
// RawIP4 protocol constants.
//
#define RawIP4_DEVICE_NAME (DD_RAW_IP_DEVICE_NAME L"\\41")

typedef struct RawIP4Context {
    PFILE_OBJECT AOFile;
    HANDLE AOHandle;
} RawIP4Context;

// Information we keep globally.
typedef struct RawIP4Globals {
    KSPIN_LOCK Lock;
    RawIP4Context Pseudo;
} RawIP4Globals;

//
// Context information that we pass to the IPv4 stack
// when transmitting.
//
typedef struct RawIP4TransmitContext {
    PNDIS_PACKET packet;
    TA_IP_ADDRESS taIPAddress;
    TDI_CONNECTION_INFORMATION tdiConnInfo;
} RawIP4TransmitContext;

//
// Global variable to send data on the raw IP4.
//
static RawIP4Globals RawIP4;

//* RawIP4OpenAddressObject
//
//  Opens a raw IPv4 address object,
//  returning a handle (or NULL on error).
//
static
HANDLE
OpenAddressObject(in_addr Address)
{
    UNICODE_STRING objectName;
    OBJECT_ATTRIBUTES objectAttributes;
    IO_STATUS_BLOCK iosb;
    PTRANSPORT_ADDRESS transportAddress;
    TA_IP_ADDRESS taIPAddress;
    union { // Get correct alignment.
        FILE_FULL_EA_INFORMATION ea;
        char bytes[sizeof(FILE_FULL_EA_INFORMATION) - 1 +
                  TDI_TRANSPORT_ADDRESS_LENGTH + 1 + sizeof taIPAddress];
    } eaBuffer;
    PFILE_FULL_EA_INFORMATION ea = &eaBuffer.ea;
    HANDLE tdiHandle;
    NTSTATUS status;

    //
    // Initialize an IPv4 address.
    //
    taIPAddress.TAAddressCount = 1;
    taIPAddress.Address[0].AddressLength = TDI_ADDRESS_LENGTH_IP;
    taIPAddress.Address[0].AddressType = TDI_ADDRESS_TYPE_IP;
    taIPAddress.Address[0].Address[0].sin_port = 0;
    taIPAddress.Address[0].Address[0].in_addr = Address;

    //
    // Initialize the extended-attributes information,
    // to indicate that we are opening an address object
    // with the specified IPv4 address.
    //
    ea->NextEntryOffset = 0;
    ea->Flags = 0;
    ea->EaNameLength = TDI_TRANSPORT_ADDRESS_LENGTH;
    ea->EaValueLength = (USHORT)sizeof taIPAddress;

    RtlMoveMemory(ea->EaName, TdiTransportAddress, ea->EaNameLength + 1);

    transportAddress = (PTRANSPORT_ADDRESS)(&ea->EaName[ea->EaNameLength + 1]);

    RtlMoveMemory(transportAddress, &taIPAddress, sizeof taIPAddress);

    //
    // Open a raw IP address object.
    //

    RtlInitUnicodeString(&objectName, RawIP4_DEVICE_NAME);

    InitializeObjectAttributes(&objectAttributes,
                               &objectName,
                               OBJ_CASE_INSENSITIVE,  // Attributes
                               NULL,                  // RootDirectory
                               NULL);                 // SecurityDescriptor

    status = ZwCreateFile(&tdiHandle,
                          GENERIC_READ | GENERIC_WRITE | SYNCHRONIZE,
                          &objectAttributes,
                          &iosb,
                          NULL,                         // AllocationSize
                          0,                            // FileAttributes
                          FILE_SHARE_READ | FILE_SHARE_WRITE,
                          FILE_CREATE,
                          0,                            // CreateOptions
                          ea,
                          sizeof eaBuffer);
    if (!NT_SUCCESS(status))
        return NULL;

    return tdiHandle;
}


//* RawIP4ObjectFromHandle
//
//  Converts a handle to an object pointer.
//
static
PVOID
RawIP4ObjectFromHandle(HANDLE Handle)
{
    PVOID Object;
    NTSTATUS Status;

    Status = ObReferenceObjectByHandle(
                    Handle,
                    GENERIC_READ | GENERIC_WRITE | SYNCHRONIZE,
                    NULL,           // object type
                    KernelMode,
                    &Object,
                    NULL);          // handle info
    ASSERT(NT_SUCCESS(Status));

    return Object;
} 


//* RawIP4SetAddressObjectInformation
//
//  Set information on the TDI address object.
//
//  Our caller should initialize the ID.toi_id, BufferSize, Buffer
//  fields of the SetInfo structure, but we initialize the rest.
//
static
NTSTATUS
RawIP4SetAddressObjectInformation(
    PFILE_OBJECT AO,
    PTCP_REQUEST_SET_INFORMATION_EX SetInfo,
    ULONG SetInfoSize)
{
    IO_STATUS_BLOCK iosb;
    KEVENT event;
    NTSTATUS status;
    PIRP irp;
    PIO_STACK_LOCATION irpSp;

    //
    // Finish initialization of the request structure for this IOCTL.
    //
    SetInfo->ID.toi_entity.tei_entity = CL_TL_ENTITY;
    SetInfo->ID.toi_entity.tei_instance = 0;
    SetInfo->ID.toi_class = INFO_CLASS_PROTOCOL;
    SetInfo->ID.toi_type = INFO_TYPE_ADDRESS_OBJECT;

    //
    // Initialize the event that we use to wait.
    //
    KeInitializeEvent(&event, NotificationEvent, FALSE);

    //
    // Create and initialize the IRP for this operation.
    //
    irp = IoBuildDeviceIoControlRequest(IOCTL_TCP_SET_INFORMATION_EX,
                                        AO->DeviceObject,
                                        SetInfo,
                                        SetInfoSize,
                                        NULL,   // output buffer
                                        0,      // output buffer length
                                        FALSE,  // internal device control?
                                        &event,
                                        &iosb);
    if (irp == NULL)
        return STATUS_INSUFFICIENT_RESOURCES;

    iosb.Status = STATUS_UNSUCCESSFUL;
    iosb.Information = (ULONG)-1;

    irpSp = IoGetNextIrpStackLocation(irp);
    irpSp->FileObject = AO;

    //
    // Make the IOCTL, waiting for it to finish if necessary.
    //
    status = IoCallDriver(AO->DeviceObject, irp);
    if (status == STATUS_PENDING) {
        KeWaitForSingleObject(&event, Executive, KernelMode,
                              FALSE, NULL);
        status = iosb.Status;
    }

    return status;
}


//* RawIP4SetAddressObjectIPHDRINCL
//
//  Set the unicast TTL on a TDI address object.
//  This sets the v4 header TTL that will be used
//  for unicast packets sent via this TDI address object.
//
static
NTSTATUS
RawIP4SetAddressObjectIPHDRINCL(PFILE_OBJECT AO)
{
    NTSTATUS Status;
    TCP_REQUEST_SET_INFORMATION_EX SetInfo;

#ifndef AO_OPTION_IP_HDRINCL
// MEFBUG: This is the value used in NT5.0 Beta2.
#define AO_OPTION_IP_HDRINCL 12
#endif // AO_OPTION_IP_HDRINCL

    SetInfo.ID.toi_id = AO_OPTION_IP_HDRINCL;
    SetInfo.BufferSize = 1;
    SetInfo.Buffer[0] = TRUE;

    Status = RawIP4SetAddressObjectInformation(AO, &SetInfo, sizeof SetInfo);
    // DbgPrint("RawIP4SetAddressObjectIPHDRINCL = %lx\n", Status);

    return Status;
}

//* RawIP4TransmitComplete
//
//  Completion function for RawIP4Transmit,
//  called when the IPv4 stack completes our IRP.
//
static
NTSTATUS
RawIP4TransmitComplete(
    PDEVICE_OBJECT DeviceObject,
    PIRP Irp,
    PVOID Context)
{
    RawIP4TransmitContext *tc = (RawIP4TransmitContext *) Context;
    PNDIS_PACKET packet = tc->packet;

//    DbgPrint("tditest RawIP4TransmitComplete\nFreeing tc context\n");
    ExFreePool(tc);
    IoFreeIrp(Irp);
    NaptFreeIP4Packet(packet);

    // Tell IoCompleteRequest to stop working on the IRP.
    return STATUS_MORE_PROCESSING_REQUIRED;
}

//* RawIP4TransmitPacket
//
//  Encapsulate a v6 packet in a v4 packet and send it
//  to the specified v4 address, using the specified
//  file object. The file object implicitly specifies
//  the v4 source address.
//
// __inline
static void
RawIP4TransmitPacket(
    PNDIS_PACKET Packet,  // Pointer to packet to be transmitted.
    in_addr Address,      // Link-level (IPv4) destination address.
    PFILE_OBJECT File)    // IPv4 TDI Address Object.
{
    RawIP4TransmitContext *tc;
    PIRP irp;
    PMDL mdl;
    ULONG SendLen;
    NTSTATUS Status;

    //
    // TdiBuildSendDatagram needs an MDL and the total amount
    // of data that the MDL represents.
    //
    NdisQueryPacket(Packet, NULL, NULL, &mdl, &SendLen);

    //
    // Allocate the context that we will pass to the IPv4 stack.
    //
    tc = ExAllocatePool(NonPagedPool, sizeof *tc);
    if (tc == NULL) {
      ErrorReturn:
        NaptFreeIP4Packet(Packet);
        return;
    }

    // Allocate an IRP that we will pass to the IPv4 stack.
    irp = IoAllocateIrp(File->DeviceObject->StackSize, FALSE);
    if (irp == NULL) {
        ExFreePool(tc);
        goto ErrorReturn;
    }

    //
    // Initialize the context information.
    // Note that many fields of the "connection info" are unused.
    //
    tc->packet = Packet;

    tc->taIPAddress.TAAddressCount = 1;
    tc->taIPAddress.Address[0].AddressLength = TDI_ADDRESS_LENGTH_IP;
    tc->taIPAddress.Address[0].AddressType = TDI_ADDRESS_TYPE_IP;
    tc->taIPAddress.Address[0].Address[0].sin_port = 0;
    tc->taIPAddress.Address[0].Address[0].in_addr = Address;

    tc->tdiConnInfo.RemoteAddressLength = sizeof tc->taIPAddress;
    tc->tdiConnInfo.RemoteAddress = &tc->taIPAddress;

    //
    // Initialize the IRP.
    //
    TdiBuildSendDatagram(irp, File->DeviceObject, File,
                         RawIP4TransmitComplete, tc,
                         mdl, SendLen, &tc->tdiConnInfo);

    //
    // Pass the IRP to the IPv4 stack.
    // Note that unlike NDIS's asynchronous operations,
    // our completion routine will always be called,
    // no matter what the return code from IoCallDriver.
    //
    Status = IoCallDriver(File->DeviceObject, irp);
//    DbgPrint("RawIP4TransmitPacket = %x\n", Status);
}


//////////////////////////////////////////////////////////////////////
// PUBLIC NT5.0 NAPT IP4 support
//

int
NaptIP4Init()
{
    KeInitializeSpinLock(&RawIP4.Lock);

    // This can legitimately fail, if the IPv4 stack
    // is not available.
    RawIP4.Pseudo.AOHandle = OpenAddressObject(INADDR_ANY);
    if (RawIP4.Pseudo.AOHandle == NULL) {
        KdPrint(("RawIP4Init - IPv4 not available?\n"));
        return TRUE;
    }
    RawIP4.Pseudo.AOFile = RawIP4ObjectFromHandle(RawIP4.Pseudo.AOHandle);
    (void) RawIP4SetAddressObjectIPHDRINCL(RawIP4.Pseudo.AOFile);
    // DbgPrint("RawIP4.Pseudo.AOHandle = %x\n", RawIP4.Pseudo.AOHandle);
    // DbgPrint("RawIP4.Pseudo.AOFile = %x\n", RawIP4.Pseudo.AOFile);

    return TRUE;
}

void
NaptIP4UnInit()
{
    NTSTATUS Status;

    // MEFBUG: also need to close the Handle/Object?
    // DbgPrint("RawIP4.Pseudo.AOFile = %x\n",RawIP4.Pseudo.AOFile);
    // DbgPrint("RawIP4.Pseudo.AOHandle = %x\n",RawIP4.Pseudo.AOHandle);
    ObDereferenceObject(RawIP4.Pseudo.AOFile);
    Status = ZwClose(RawIP4.Pseudo.AOHandle);
    // DbgPrint("zwclose status = %x\n", Status);  
}

void
NaptFreeIP4Packet(PNDIS_PACKET Packet)
{
    PNDIS_PACKET OrigPacket;
    PNDIS_BUFFER Buffer, NextBuffer;
    UINT FirstBuffer = TRUE;

    //
    // Free all the buffers in the IPv4 packet to the NaptBufferPool.
    // Start with the first buffer in the packet and follow the chain.
    //
    NdisQueryPacket(Packet, NULL, NULL, &Buffer, NULL);

    for (; Buffer != NULL; Buffer = NextBuffer) {
        VOID *Mem;
        UINT Unused;

        NdisGetNextBuffer(Buffer, &NextBuffer);
        //
        // The first buffer contains the IPv4 header for which memory
        // was allocated explicitly in NaptAllocateIP4Packet().  The
        // other buffers simply point at the memory of the original
        // Ipv6 packet that are freed by the call to the completion
        // function below.
        //
        if (FirstBuffer) {
            NdisQueryBuffer(Buffer, &Mem, &Unused);
            ExFreePool(Mem);
            FirstBuffer = FALSE;
        }
        NdisFreeBuffer(Buffer);
    }

    //
    // Free the original IPv6 packet that contains the data back to
    // the IPv6 packet and buffer pool.
    //
    OrigPacket = NAPTPC(Packet)->OrigPacket;
    ASSERT(OrigPacket != (PNDIS_PACKET)0);
    ASSERT(IP6PC(OrigPacket)->CompletionHandler != NULL);
    (*IP6PC(OrigPacket)->CompletionHandler)(OrigPacket);

    //
    // Finally, free the IP4 packet to the NaptPacketPool.
    //
    NdisFreePacket(Packet);

} // NaptFreeIP4Packet


void
NaptSendIP4Packet(
    IPHeader* IP4,
    PNDIS_PACKET Packet,
    PNDIS_BUFFER Buffer)
{
    // Add buffer to Packet buffer chain.
    // DbgPrint("NaptSendIP4Packet:");
    RawIP4TransmitPacket(Packet,IP4->iph_dest,RawIP4.Pseudo.AOFile);
} // NaptSendIP4Packet


NTSTATUS
NaptAllocateIP4Packet(
    PNDIS_PACKET *Packet,
    PNDIS_BUFFER *Buffer,
    uint MemLen,
    IPHeader **IP4)
{
    NDIS_STATUS NStatus;
    PNDIS_BUFFER IP4Buffer;
    uchar* Mem;

    NdisAllocatePacket(&NStatus, Packet, NaptPacketPool);
    if (NStatus != NDIS_STATUS_SUCCESS) {
        KdPrint(("NaptAllocateIP4Packet: "
                 "Couldn't allocate Ip4 packet header!?!\n"));
        return STATUS_UNSUCCESSFUL;
    }

    //
    // Allocate memory for buffer.
    //
    Mem = ExAllocatePool(NonPagedPool, sizeof(IPHeader));
    if (Mem == NULL) {
        KdPrint(("NaptAllocateIP4Packet: Couldn't allocate memory!?!\n"));
        NdisFreePacket(*Packet);
        return STATUS_UNSUCCESSFUL;      
    }
    *IP4 = (IPHeader *)Mem;

    //
    // Allocate the buffer for the header and put it on the packet chain.
    //
    NdisAllocateBuffer(&NStatus, &IP4Buffer, NaptBufferPool, Mem,
                       sizeof(IPHeader));
    if (NStatus != NDIS_STATUS_SUCCESS) {
        KdPrint(("NaptAllocateIP4Packet: Couldn't allocate buffer header!\n"));
        ExFreePool(Mem);
        NdisFreePacket(*Packet);
        return STATUS_UNSUCCESSFUL;      
    }
    NdisChainBufferAtFront(*Packet, IP4Buffer);

    return STATUS_SUCCESS;

} // NaptAllocateIP4Packet()
