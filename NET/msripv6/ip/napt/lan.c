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
// Abstract:
//
// Internet Protocol Version 6 link-level support for some common
// LAN types: Ethernet, Token Ring, etc.
//
// This module is based on the version from tcpip6/ip6/lan.c.  The
// main difference is that it can be dynamically loadable and it
// interfaces directly with the IPv6/IPv4 Network Address and Protocol
// Translator (NAPT).  It is used to receive IPv6/IPv4 packets and
// send IPv6 router advertisement multicast packets.
//


//
// This manifest constant causes the NDIS_PROTOCOL_CHARACTERISTICS struct to 
// use the NDIS 5 format if compiled using the NT 5 ddk.  If using the NT4 ddk
// this has no effect.
//
#ifndef NDIS50
#define NDIS50 1
#endif

#include "oscfg.h"
#include "ndis.h"
#include "ip6imp.h"
#include "ip6def.h"
#include "llip6if.h"
#include "lan.h"
#include "tdiinfo.h"
#include "tdistat.h"
#include "ntddip6.h"
#include "route.h"
#include "naptdef.h"

#define NDIS_MAJOR_VERSION4 0x04
#define NDIS_MAJOR_VERSION5 0x05
#define NDIS_MINOR_VERSION 0

#ifndef NDIS_API
#define NDIS_API
#endif


NDIS_HANDLE NaptPacketPool, NaptBufferPool;
Interface *NAPTIFList;  // List of interfaces active.
uint NumIF;

extern
void *
AdjustPacketBuffer(
    PNDIS_PACKET Packet,  // Packet to adjust.
    uint SpaceAvailable,  // Extra space available at start of first buffer.
    uint SpaceNeeded);    // Amount of space we need for the header.

extern 
void
UndoAdjustPacketBuffer(PNDIS_PACKET Packet);

uint ArpUseEtherSnap = FALSE;


//* UseEtherSNAP
//
//  Determines whether the EtherSNAP protocol should be used on an interface.
//
uint  // Returns: Nonzero if SNAP is to be used. Zero otherwise.
UseEtherSNAP(
    PNDIS_STRING Name)  // Device name of the interface in question.
{
    UNREFERENCED_PARAMETER(Name);

    //
    // We currently set this on a global basis.
    //
    return(ArpUseEtherSnap);
}


//* AddInterface
//
//  Add a new interface to the global list.
//
void
NAPTAddInterface(Interface *IF)
{
    IF->Next = NAPTIFList;
    NAPTIFList = IF;
    IF->Index = ++NumIF;
}


//* NAPTCreateInterface
//
//  Create an interface structure, but don't actually register it
//  with IPv6.  Similar to tcpip6's init.c:CreateInterface().
//
void *
NAPTCreateInterface(LLIPBindInfo *BindInfo)
{
    NetTableEntry *NTE;             // Current NTE being initialized.
    Interface *IF;                  // Interface being added.
    uint IFIndex = 0;               // Index to be assigned to this I/F.
    IPv6Addr Address;

    //
    // Allocate memory to hold an interface.
    //
    IF = ExAllocatePool(NonPagedPool, sizeof *IF);
    if (IF == NULL) {
        // Couldn't allocate memory.
        goto failure;
    }

    RtlZeroMemory(IF, sizeof *IF);

    KeInitializeSpinLock(&IF->Lock);

    IF->LinkContext = BindInfo->lip_context;
    IF->Transmit = BindInfo->lip_transmit;
    IF->CreateToken = BindInfo->lip_token;
    IF->ReadLLOpt = BindInfo->lip_rdllopt;
    IF->WriteLLOpt = BindInfo->lip_wrllopt;
    IF->ConvertMCastAddr = BindInfo->lip_mcaddr;
    IF->SetMCastAddrList = BindInfo->lip_mclist;
    IF->LinkAddressLength = BindInfo->lip_addrlen;
    IF->LinkAddress = BindInfo->lip_addr;
    IF->LinkHeaderSize = BindInfo->lip_hdrsize;
    IF->TrueLinkMTU = BindInfo->lip_maxmtu;
    IF->LinkMTU = BindInfo->lip_defmtu;
    IF->BaseReachableTime = REACHABLE_TIME;
    IF->ReachableTime = REACHABLE_TIME; // MEF CalcReachableTime(IF->BaseReachableTime);
    IF->RetransTimer = RETRANS_TIMER;
    IF->DupAddrDetectTransmits = 1; // BUGBUG Should be configurable.
    IF->CurHopLimit = 0x80; // MEF DefaultCurHopLimit;

    // Allow Neighbor Discovery for this interface.
    // IF->DisableND = FALSE;
    // NeighborCacheInit(IF);

    //
    // Initialize so IPv6Timeout will send the first Router Solicitation.
    // BUGBUG: Should have random delay here.
    //
    IF->RSTimer = 1;

    //
    // Create a link-local address for this interface.
    // Other addresses will be created later via stateless
    // auto-configuration.
    //
    // Address = LinkLocalPrefix;
    // (*IF->CreateToken)(IF->LinkContext, IF->LinkAddress, &Address);

    //
    // Normally should have the interface locked to call CreateNTE,
    // but because we are just initializing the interface it's OK.
    //
    // NTE = CreateNTE(IF, &Address,
    // DAD_LIFETIME_INFINITE, DAD_LIFETIME_INFINITE);
    // if (NTE == NULL)
    // goto failure;

    //
    // Add ourselves to the front of the global interface list.
    //
    NAPTAddInterface(IF);

    return IF;

failure:
    // BUGBUG - cleanup
    return NULL;
}


UCHAR NdisVersion = 0x00;  // Set to the major NDIS version we actualy register with.
static ulong LanLookahead = LOOKAHEAD_SIZE;
NDIS_HANDLE LanHandle;              // Our NDIS protocol handle.
static WCHAR LanName[] = TCPIPV6_NAME;

#ifdef ALLOC_PRAGMA
//
// Disposable init code.
//
int LanInit(WCHAR *RegKeyNameParam);
#pragma alloc_text(INIT, LanInit)

//
// Paged code.
//
void LanOpen(void *Context);
void FreeLanInterface(LanInterface *Interface);
int LanRegister(PNDIS_STRING Adapter, struct LanInterface **Interface);
#pragma alloc_text(PAGE, LanOpen)
#pragma alloc_text(PAGE, LanRegister)

#endif // ALLOC_PRAGMA


//* DoNDISRequest - Submit a request to an NDIS driver.
//
//  This is a utility routine to submit a general request to an NDIS
//  driver.  The caller specifes the request code (OID), a buffer and
//  a length.  This routine allocates a request structure, fills it in,
//  and submits the request.
//
NDIS_STATUS
DoNDISRequest(
    LanInterface *Adapter,  // Pointer to the LanInterface adapter strucuture.
    NDIS_REQUEST_TYPE RT,   // Type of request to be done (Set or Query).
    NDIS_OID OID,           // Value to be set/queried.
    void *Info,             // Pointer to the buffer to be passed.
    uint Length,            // Length of data in above buffer.
    uint *Needed)           // Location to fill in with bytes needed in buffer.
{
    NDIS_REQUEST Request;   // Request structure we'll use.
    NDIS_STATUS Status;

    // Now fill it in.
    Request.RequestType = RT;
    if (RT == NdisRequestSetInformation) {
        Request.DATA.SET_INFORMATION.Oid = OID;
        Request.DATA.SET_INFORMATION.InformationBuffer = Info;
        Request.DATA.SET_INFORMATION.InformationBufferLength = Length;
    } else {
        Request.DATA.QUERY_INFORMATION.Oid = OID;
        Request.DATA.QUERY_INFORMATION.InformationBuffer = Info;
        Request.DATA.QUERY_INFORMATION.InformationBufferLength = Length;
    }

    // Initialize our event.
    KeInitializeEvent(&Adapter->ai_event, SynchronizationEvent, FALSE);

    // Submit the request.
    if (!Adapter->ai_resetting) {
        NdisRequest(&Status, Adapter->ai_handle, &Request);
    } else
        Status = NDIS_STATUS_NOT_ACCEPTED;

    // Wait for it to finish.
    if (Status == NDIS_STATUS_PENDING) {
        (void) KeWaitForSingleObject(&Adapter->ai_event, UserRequest,
                                     KernelMode, FALSE, NULL);
        Status = (NDIS_STATUS)Adapter->ai_status;
    }

    if (Needed != NULL)
        *Needed = Request.DATA.QUERY_INFORMATION.BytesNeeded;

    return Status;
}


//* LanTransmitComplete - Lan transmit complete handler.
//
//  This routine is called by the NDIS driver when a send completes.
//  This is a pretty time critical operation, we need to get through here
//  quickly.  We just take statistics and call the upper layer send
//  complete handler.
//
void NDIS_API
LanTransmitComplete(
    NDIS_HANDLE Handle,   // Binding handle (really LanInterface we sent on).
    PNDIS_PACKET Packet,  // Packet that was sent.
    NDIS_STATUS Status)   // Final status of send.
{
    LanInterface *Interface = (LanInterface *)Handle;

    Interface->ai_qlen--;

    //
    // Take statistics.
    //
    if (Status == NDIS_STATUS_SUCCESS) {
        UINT TotalLength;

        NdisQueryPacket(Packet, NULL, NULL, NULL, &TotalLength);
        Interface->ai_outoctets += TotalLength;
    } else {
        if (Status == NDIS_STATUS_RESOURCES)
            Interface->ai_outdiscards++;
        else
            Interface->ai_outerrors++;
    }

    UndoAdjustPacketBuffer(Packet);

    IPv6SendComplete(Interface->ai_context, Packet, Status);
}


//* LanTransmit - Send a frame.
//
//  The main Lan transmit routine, called by the upper layer.
//
void
LanTransmit(
    void *Context,        // A pointer to the LanInterface.
    PNDIS_PACKET Packet,  // Packet to send.
    uint Offset,          // Offset from start of packet to IP header.
    void *LinkAddress)    // Link-level address of destination.
{
    LanInterface *Interface = (LanInterface *)Context;
    void *BufAddr;
    NDIS_STATUS Status;

    //
    // Obtain a pointer to space for the link-level header.
    //
    BufAddr = AdjustPacketBuffer(Packet, Offset, Interface->ai_hdrsize);

    switch (Interface->ai_media) {
    case NdisMedium802_3: {
        EtherHeader *EHdr;

        // This is an Ethernet.
        EHdr = (EtherHeader *)BufAddr;
        RtlCopyMemory(EHdr->eh_daddr, LinkAddress, IEEE_802_ADDR_LENGTH);
        RtlCopyMemory(EHdr->eh_saddr, Interface->ai_addr,
                      IEEE_802_ADDR_LENGTH);
        EHdr->eh_type = net_short(ETYPE_IPv6);

#if 0
        //
        // See if we're using SNAP here.
        //
        if (Interface->ai_hdrsize != sizeof(EtherHeader)) {
                ...
        }
#endif
        break;
    }

    // BUGBUG: Eventually we should support other media types here.

    default:
        KdPrint(("LanTransmit: Unknown media type\n"));
    }

    //
    // Send the packet down to NDIS.
    //

    (Interface->ai_outpcount[AI_UCAST_INDEX])++;
    Interface->ai_qlen++;

    if (!Interface->ai_resetting) {
        NdisSend(&Status, Interface->ai_handle, Packet);
    } else
        Status = NDIS_STATUS_NOT_ACCEPTED;

    if (Status != NDIS_STATUS_PENDING) {
        //
        // The send finished synchronously.
        // Call LanTransmitComplete, unifying our treatment
        // of the synchronous and asynchronous cases.
        //
        LanTransmitComplete((NDIS_HANDLE)Interface, Packet, Status);
    }
}


//* LanOpenAdapterComplete - LanOpen completion handler.
//
//  This routine is called by the NDIS driver when an open adapter
//  call completes.  Wakeup anyone who is waiting for this event.
//
void NDIS_API
LanOpenAdapterComplete(
    NDIS_HANDLE Handle,       // Binding handle (really our LanInterface).
    NDIS_STATUS Status,       // Final status of command.
    NDIS_STATUS ErrorStatus)  // Final error status.
{
    LanInterface *ai = (LanInterface *)Handle;

    UNREFERENCED_PARAMETER(ErrorStatus);

    //
    // Signal whoever is waiting and pass the final status.
    //
    ai->ai_status = Status;
    KeSetEvent(&ai->ai_event, 0, FALSE);
}


//* LanCloseAdapterComplete - Lan close adapter complete handler.
//
//  This routine is called by the NDIS driver when a close adapter
//  call completes.
//
void NDIS_API
LanCloseAdapterComplete(
    NDIS_HANDLE Handle,  // Binding handle (really our LanInterface).
    NDIS_STATUS Status)  // Final status of command.
{
    LanInterface *ai = (LanInterface *)Handle;

    //
    // Signal whoever is waiting and pass the final status.
    //
    ai->ai_status = Status;
    KeSetEvent(&ai->ai_event, 0, FALSE);
}


//* LanTDComplete - Lan transfer data complete handler.
//
//  This routine is called by the NDIS driver when a transfer data
//  call completes.  Hopefully we now have a complete packet we can
//  pass up to IP.  Recycle our TD packet descriptor in any event.
//
void NDIS_API
LanTDComplete(
    NDIS_HANDLE Handle,   // Binding handle (really our LanInterface).
    PNDIS_PACKET Packet,  // The packet used for the Transfer Data (TD).
    NDIS_STATUS Status,   // Final status of command.
    uint BytesCopied)     // Number of bytes copied.
{
    LanInterface *Interface = (LanInterface *)Handle;

    //
    // If things went well, pass TD packet up to Napt.
    //
    if (Status == NDIS_STATUS_SUCCESS) {
        PNDIS_BUFFER Buffer;
        void *Address;            // Address of above Buffer.
        uint Length, TotalLength; // Length of Buffer, Packet.

        NdisGetFirstBufferFromPacket(Packet, &Buffer, &Address,
                                     &Length, &TotalLength);
        ASSERT(Length == TotalLength);

        (void)NaptIP4Receive(Interface->ai_context, NULL,
                             0, Address, BytesCopied, BytesCopied);
    }

    //
    // In any case, put the packet back on the list.
    //
    KeAcquireSpinLockAtDpcLevel(&Interface->ai_lock); 
    IP6PC(Packet)->pc_link = Interface->ai_tdpacket;
    Interface->ai_tdpacket = Packet;
    KeReleaseSpinLockFromDpcLevel(&Interface->ai_lock);
}


//* LanResetComplete - Lan reset complete handler.
//
//  This routine is called by the NDIS driver when a reset completes.
//
void NDIS_API
LanResetComplete(
    NDIS_HANDLE Handle,  // Binding handle (really LanInterface which reset)
    NDIS_STATUS Status)  // Final status of command.
{
    UNREFERENCED_PARAMETER(Handle);
    UNREFERENCED_PARAMETER(Status);

    // REVIEW: Do anything here?  Axe this routine?
}


//* LanRequestComplete - Lan request complete handler.
//
//  This routine is called by the NDIS driver when a general request
//  completes.  Lan blocks on all requests, so we'll just wake up
//  whoever's blocked on this request.
//
void NDIS_API
LanRequestComplete(
    NDIS_HANDLE Handle,     // Binding handle (really our LanInterface).
    PNDIS_REQUEST Request,  // Request that completed.
    NDIS_STATUS Status)     // Final status of requested command.
{
    LanInterface *ai = (LanInterface *)Handle;

    //
    // Signal the completion of a generic synchronous request.
    // See DoNDISRequest.
    //
    ai->ai_status = Status;
    KeSetEvent(&ai->ai_event, 0, FALSE);
}


//* LanReceive - Lan receive data handler.
//
//  This routine is called when data arrives from the NDIS driver.
//  Note that newer NDIS drivers are likely to call LanReceivePacket to
//  indicate data arrival instead of this routine.
//
NDIS_STATUS // Indication of whether or not we took the packet.
NDIS_API
LanReceive(
    NDIS_HANDLE Handle,   // The binding handle we gave NDIS earlier.
    NDIS_HANDLE Context,  // NDIS Context for TransferData operations.
    void *Header,         // Pointer to packet link-level header.
    uint HeaderSize,      // Size of above header (in bytes).
    void *Data,           // Pointer to look-ahead received data buffer.
    uint Size,            // Size of above data (in bytes).
    uint TotalSize)       // Total received data size (in bytes).
{
    LanInterface *Interface = Handle;  // Interface for this driver.
    EtherHeader UNALIGNED *EHdr = (EtherHeader UNALIGNED *)Header;
    ushort Type;                       // Protocol type.
    uint ProtOffset;                   // Offset in Data to non-media info.
    uint NUCast;                       // TRUE if the frame is not unicast.

    if (Interface->ai_state != INTERFACE_UP ||
        HeaderSize < (uint)Interface->ai_hdrsize) {
        // 
        // Interface is marked as down or headersize is bogus.
        //
        return NDIS_STATUS_NOT_RECOGNIZED;
    }

    Interface->ai_inoctets += TotalSize;

    if (Interface->ai_media != NdisMediumArcnet878_2) {
        if (Interface->ai_media == NdisMedium802_3 &&
            (Type = net_short(EHdr->eh_type)) >= ETYPE_MIN) {
            //
            // Classic Ethernet, no SNAP header.
            //
            ProtOffset = 0;
        } else {
            //
            // 802.3 Ethernet w/ SNAP header.  Protocol type is in
            // different spot and we have to remember to skip over it.
            //
            SNAPHeader UNALIGNED *SNAPHdr = (SNAPHeader UNALIGNED *)Data;

            if (Size >= sizeof(SNAPHeader) &&
                SNAPHdr->sh_dsap == SNAP_SAP &&
                SNAPHdr->sh_ssap == SNAP_SAP &&
                SNAPHdr->sh_ctl == SNAP_UI) {
    
                Type = net_short(SNAPHdr->sh_etype);
                ProtOffset = sizeof(SNAPHeader);

            } else {
                // BUGBUG handle XID/TEST here.
                Interface->ai_uknprotos++;
                return NDIS_STATUS_NOT_RECOGNIZED;
            }
        }
    } else {
        //
        // ARCNet has different protocol type encoding than Ethernet,
        // convert the type value here.
        //
        // BUGBUG: Need to add IPv6 values for ARCNet here.
        //
        ARCNetHeader UNALIGNED *AH = (ARCNetHeader UNALIGNED *)Header;

        ProtOffset = 0;

        // BUGBUG: check for both ip and ipv6
        if (AH->ah_prot == ARCPROT_IPv6)
            Type = ETYPE_IPv6;
        else if (AH->ah_prot == 0xd4 /* ipv4 */)
            Type = 0x0800 /* ETYPE_IPv4*/;
        else
            Type = 0;
    }

    //
    // See if the packet is for a protocol we handle.
    //
    if (Type != 0x0800 /* ETYPE_IPv4*/) {
        Interface->ai_uknprotos++;
        return NDIS_STATUS_NOT_RECOGNIZED;
    }

    //
    // Notice if this packet wasn't received in a unicast frame.
    // REVIEW: Is this really a media independent solution?  Do we care?
    //
    NUCast = ((*((uchar UNALIGNED *)Header + Interface->ai_bcastoff) &
               Interface->ai_bcastmask) == Interface->ai_bcastval) ?
             AI_NONUCAST_INDEX : AI_UCAST_INDEX;

    (Interface->ai_inpcount[NUCast])++;

    //
    // Check to see if we have the entire packet.
    //
    if (Size < TotalSize) {
        uint Transferred;
        NDIS_STATUS Status;
        PNDIS_PACKET TdPacket;  // Packet used by NdisTransferData.

        //
        // We need to issue a Transfer Data request to get the
        // portion of the packet we're missing, so we might as well
        // get the whole packet this way and have it be contiguous.
        //

        //
        // Pull a packet to use for the Transfer Data off the queue.
        //
        KeAcquireSpinLockAtDpcLevel(&Interface->ai_lock); 
        TdPacket = Interface->ai_tdpacket;
        if (TdPacket == (PNDIS_PACKET)NULL) {
            // Don't have a packet to put it in.
            // Have to drop it, but let NDIS know we recognized it.
            KeReleaseSpinLockFromDpcLevel(&Interface->ai_lock);
            return NDIS_STATUS_SUCCESS;
        }
        Interface->ai_tdpacket = IP6PC(TdPacket)->pc_link;
        KeReleaseSpinLockFromDpcLevel(&Interface->ai_lock);

        //
        // Issue the TD.  Start transfer at the IP header.
        //
        NdisTransferData(&Status, Interface->ai_handle, Context,
                         ProtOffset, TotalSize - ProtOffset,
                         TdPacket, &Transferred);

        if (Status != NDIS_STATUS_PENDING) {
            //
            // TD completed synchronously,
            // so call the completion function directly.
            //
            LanTDComplete(Handle, TdPacket, Status, Transferred);
        }

        return NDIS_STATUS_SUCCESS;
    }

    //
    // We were given all the data directly.  Just need to skip
    // over any link level headers.
    //
    (uchar *)Data += ProtOffset;
    ASSERT(Size == TotalSize);
    TotalSize -= ProtOffset;

    //
    // Pass incoming data up to Napt.
    //
    if (NaptIP4Receive(Interface->ai_context, NULL,
                       0, Data, TotalSize, TotalSize) == 0){
        return NDIS_STATUS_NOT_RECOGNIZED;
    }
    return NDIS_STATUS_SUCCESS;
}


//* LanReceiveComplete - Lan receive complete handler.
//
//  This routine is called by the NDIS driver after some number of
//  receives.  In some sense, it indicates 'idle time'.
//
void NDIS_API
LanReceiveComplete(
    NDIS_HANDLE Handle)  // Binding handle (really our LanInterface).
{
    UNREFERENCED_PARAMETER(Handle);
    // DbgPrint("(mef) LanReceiveComplete not calling IPv6ReceiveComplete\n");
    // IPv6ReceiveComplete();
}


//* LanReceivePacket - Lan receive data handler.
//
//  This routine is called when data arrives from the NDIS driver.
//  Note that older NDIS drivers are likely to call LanReceive to
//  indicate data arrival instead of this routine.
//
int  // Returns: number of references we hold to Packet upon return.
LanReceivePacket(
    NDIS_HANDLE Handle,   // The binding handle we gave NDIS earlier.
    PNDIS_PACKET Packet)  // Packet descriptor for incoming packet.
{
    LanInterface *Interface = Handle;  // Interface for this driver.
    PNDIS_BUFFER Buffer;               // Buffer in packet chain.
    void *Address;                     // Address of above Buffer.
    uint Length, TotalLength;          // Length of Buffer, Packet.
    EtherHeader UNALIGNED *Ether;      // Header for Ethernet media.
    ushort Type;                       // Protocol type.
    uint Position;                     // Offset to non-media info.
    uint NUCast;                       // TRUE if the frame is not unicast.
    IPv6Packet IPPacket;

    if (Interface->ai_state != INTERFACE_UP) {
        // Interface is marked as down.
        return 0;
    }

    //
    // Find out about the packet we've been handed.
    //
    NdisGetFirstBufferFromPacket(Packet, &Buffer, &Address, &Length,
                                 &TotalLength);

    Interface->ai_inoctets += TotalLength;  // Take statistic.

    //
    // Check for obviously bogus packets.
    //
    if (TotalLength < (uint)Interface->ai_hdrsize) {
        // Packet too small to hold media header, drop it.
        return 0;
    }        

    if (Length < (uint)Interface->ai_hdrsize) {
        //
        // First buffer in chain too small to hold header.
        // REVIEW: Are we guaranteed that this will never happen?
        // REVIEW: If so, we can do away with this check.
#if 0
        Insert code to do a packet pullup here
#else
        KdPrint(("IPv6: Yikesahooty!  Got a packet with tiny 1st buffer!\n"));
        KdPrint(("IPv6: 1st buffer length = %d, total length = %d\n",
                 Length, TotalLength));
        return 0;
#endif
    }        

    //
    // Figure out what protocol type this packet is by looking in the
    // media-specific header field for this type of media.
    //
    switch (Interface->ai_media) {

    case NdisMedium802_3: {
        Ether = (EtherHeader UNALIGNED *)Address;

        if ((Type = net_short(Ether->eh_type)) >= ETYPE_MIN) {
            //
            // Classic Ethernet, no SNAP header.
            //
            Position = sizeof(EtherHeader);
        } else {
            //
            // 802.3 Ethernet w/ SNAP header.  Protocol type is in
            // different spot and we have to remember to skip over it.
            // The great thing about standards is that there are so
            // many to choose from.
            //
            SNAPHeader UNALIGNED *SNAP = (SNAPHeader UNALIGNED *)
                ((char *)Address + sizeof(EtherHeader));

            if (Length >= (sizeof(EtherHeader) + sizeof(SNAPHeader))
                && SNAP->sh_dsap == SNAP_SAP && SNAP->sh_ssap == SNAP_SAP
                && SNAP->sh_ctl == SNAP_UI) {

                Type = net_short(SNAP->sh_etype);
                Position = sizeof(EtherHeader) + sizeof(SNAPHeader);
            } else {
                // BUGBUG: Again, do we need to check for pullup issues?
                // BUGBUG: handle XID/TEST here.
                Interface->ai_uknprotos++;
                return 0;
            }
        }
        break;
    }

    case NdisMediumFddi: {
        SNAPHeader UNALIGNED *SNAP = (SNAPHeader UNALIGNED *)
            ((char *)Address + sizeof(FDDIHeader));

        if (Length >= (sizeof(FDDIHeader) + sizeof(SNAPHeader))
            && SNAP->sh_dsap == SNAP_SAP && SNAP->sh_ssap == SNAP_SAP
            && SNAP->sh_ctl == SNAP_UI) {

            Type = net_short(SNAP->sh_etype);
            Position = sizeof(FDDIHeader) + sizeof(SNAPHeader);
        } else {
            // BUGBUG: Again, do we need to check for pullup issues?
            // BUGBUG: handle XID/TEST here.
            Interface->ai_uknprotos++;
            return 0;
        }
        break;
    }

    case NdisMediumArcnet878_2: {
        //
        // ARCNet has different protocol type encoding than Ethernet,
        // convert the type value here.
        //
        // BUGBUG: Need to add IPv6 values for ARCNet here.
        //
        ARCNetHeader UNALIGNED *AH = (ARCNetHeader UNALIGNED *)Address;

        Position = sizeof(ARCNetHeader);
        if (AH->ah_prot == ARCPROT_IPv6)
            Type = ETYPE_IPv6;
        else
            Type = 0;
        break;
    }

    default:
        // Should never happen.
        KdPrint(("IPv6: Got a packet from an unknown media!?!\n"));
    }

    //
    // Notice if this packet wasn't received in a unicast frame.
    // REVIEW: Is this really a media independent solution?
    //
    NUCast = ((*((uchar UNALIGNED *)Address + Interface->ai_bcastoff) &
               Interface->ai_bcastmask) == Interface->ai_bcastval) ?
               AI_NONUCAST_INDEX : AI_UCAST_INDEX;

    //
    // See if the packet is for a protocol we handle.
    //
    if (Type == 0x0800 /* ETYPE_IPv4*/) {
        (Interface->ai_inpcount[NUCast])++;

        //
        // Skip over any link level headers.
        //
        (uchar *)Address += Position;
        Length -= Position;
        TotalLength -= Position;

        return NaptIP4Receive(Interface->ai_context, NULL,
                              0, Address, Length, TotalLength);
    } else {
        //
        // Not a protocol we handle.
        //
        Interface->ai_uknprotos++;
        return 0;
    }
}


//* LanStatus - Lan status handler.
//
//  Called by the NDIS driver when some sort of status change occurs.
//  We take action depending on the type of status.
//
void NDIS_API
LanStatus(
    NDIS_HANDLE Handle,   // Binding handle (really our LanInterface).
    NDIS_STATUS GStatus,  // General status type which caused the call.
    void *Status,         // Pointer to buffer of status specific info.
    uint StatusSize)      // Size of the above status buffer.
{
    LanInterface *Interface = Handle;  // Interface for this driver.
    uint Index;

    //
    // While the interface is resetting, we must avoid calling
    // NdisSendPackets, NdisSend, and NdisRequest.
    //
    switch (GStatus) {
    case NDIS_STATUS_RESET_START:
        Interface->ai_resetting = TRUE;
        KdPrint(("Napt: LanStatus(%x) - start reset\n", Interface));
        break;
    case NDIS_STATUS_RESET_END:
        Interface->ai_resetting = FALSE;
        KdPrint(("Napt: LanStatus(%x) - end reset\n", Interface));
        break;
    default:
        KdPrint(("Napt: LanStatus(%x) - status %x\n", Interface, GStatus));
        for (Index = 0; Index < StatusSize/4; Index++)
            KdPrint((" status %08x\n", ((uint *)Status)[Index]));
        break;
    }
}


//* LanStatusComplete - Lan status complete handler.
//
//  A routine called by the NDIS driver so that we can do postprocessing
//  after a status event.
//
void NDIS_API
LanStatusComplete(
    NDIS_HANDLE Handle)  // Binding handle (really our LanInterface).
{
    UNREFERENCED_PARAMETER(Handle);

    // REVIEW: Do anything here?
}

extern void NDIS_API
LanBindAdapter(PNDIS_STATUS RetStatus, NDIS_HANDLE BindContext,
               PNDIS_STRING AdapterName, PVOID SS1, PVOID SS2);

extern void NDIS_API
LanUnbindAdapter(PNDIS_STATUS RetStatus, NDIS_HANDLE ProtBindContext,
                 NDIS_HANDLE UnbindContext);

extern void NDIS_API
LanUnloadProtocol(void);

//
// Here we use the "don't loopback" option flag as an indicator that we're
// using the NT5/NDIS5 dev environment.  
//
#ifdef NDIS_FLAGS_DONT_LOOPBACK
//
// Structure passed to NDIS 5 to tell it how to call Lan Interfaces.
//
NDIS_PROTOCOL_CHARACTERISTICS LanCharacteristics = {
    NDIS_MAJOR_VERSION5,
    NDIS_MINOR_VERSION,
    0,
    0,
    LanOpenAdapterComplete,
    LanCloseAdapterComplete,
    LanTransmitComplete,
    LanTDComplete,
    LanResetComplete,
    LanRequestComplete,
    LanReceive,
    LanReceiveComplete,
    LanStatus,
    LanStatusComplete,
    {   sizeof(TCPIPV6_NAME),
        sizeof(TCPIPV6_NAME),
        0
    },
    LanReceivePacket,
    LanBindAdapter,
    LanUnbindAdapter,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};
#else
//
// Structure passed to NDIS 4 to tell it how to call Lan Interfaces.
//
NDIS_PROTOCOL_CHARACTERISTICS LanCharacteristics = {
    NDIS_MAJOR_VERSION4,
    NDIS_MINOR_VERSION,
    0,
    LanOpenAdapterComplete,
    LanCloseAdapterComplete,
    LanTransmitComplete,
    LanTDComplete,
    LanResetComplete,
    LanRequestComplete,
    LanReceive,
    LanReceiveComplete,
    LanStatus,
    LanStatusComplete,
    {   sizeof(TCPIPV6_NAME),
        sizeof(TCPIPV6_NAME),
        0
    },
    LanReceivePacket,
    LanBindAdapter,
    LanUnbindAdapter,
    NULL,
    NULL
};
#endif


#pragma BEGIN_INIT
//* LanInit - Initialize the Lan module.
//
//  This functions intializes all of the Lan module, including allocating
//  the Lan table and any other necessary data structures.
//
int  // Returns 0 if we fail to init., !0 if we succeed.
LanInit(
    WCHAR *RegKeyNameParam)
{
    NDIS_STATUS Status;

    RtlInitUnicodeString(&LanCharacteristics.Name, LanName);

    //
    // We try to register with NDIS major version = 5.  If this fails we try
    // again for NDIS major version = 4.  If this also fails we exit without
    // any further attempts to register with NDIS.
    //
    NdisRegisterProtocol(&Status, &LanHandle, &LanCharacteristics,
                         sizeof(LanCharacteristics));
    if (Status == NDIS_STATUS_SUCCESS) {
        //
        // We've registered OK using NDIS.
        //
        //KdPrint(("NAPT:LanInit: registered with NDIS %d.\n",
        // LanCharacteristics.MajorNdisVersion));
        NdisVersion = LanCharacteristics.MajorNdisVersion;
        return(1);
    } else {
        //
        // Can't register at all. Just bail out...
        //
        KdPrint(("NAPT:LanInit: could not register with NDIS. Status=%x\n",Status));
        return(0);
    }
}
#pragma END_INIT


#pragma BEGIN_INIT

//* FreeLanInterface - Free a Lan interface
//
//  Called in the event of some sort of initialization failure. We free all
//  the memory associated with an Lan interface.
//
//  REVIEW: rename this LanFreeInterface?
//
void
FreeLanInterface(
    LanInterface *Interface)  // Interface structure to be freed.
{
    NDIS_STATUS Status;
    KIRQL OldIrql;
    NDIS_HANDLE Handle;

    //
    // If we're bound to the adapter, close it now.
    //

    KeInitializeEvent(&Interface->ai_event, SynchronizationEvent, FALSE);

    KeAcquireSpinLock(&Interface->ai_lock, &OldIrql);
    if (Interface->ai_handle != (NDIS_HANDLE)NULL) {
        Handle = Interface->ai_handle;
        Interface->ai_handle = NULL;
        KeReleaseSpinLock(&Interface->ai_lock, OldIrql);

        NdisCloseAdapter(&Status, Handle);

        if (Status == NDIS_STATUS_PENDING) {
            (void) KeWaitForSingleObject(&Interface->ai_event, UserRequest,
                                         KernelMode, FALSE, NULL);
            Status = (NDIS_STATUS)Interface->ai_status;
        }
    } else {
        KeReleaseSpinLock(&Interface->ai_lock, OldIrql);
    }

    //
    // Free the interface structure itself.
    //
    ExFreePool(Interface);
}


//* LanOpen - Open an adapter for reception.
//
//  This routine is called when the upper layer is done initializing and
//  wishes to begin receiveing packets.  The adapter is actually 'open',
//  we just set the packet filter and lookahead size.
//
void  // Returns: Nothing
LanOpen(
    void *Context)  // Interface pointer we gave to IP earlier.
{
    LanInterface *Adapter = (LanInterface *)Context;
    NDIS_STATUS Status;

    if ((Status = DoNDISRequest(Adapter, NdisRequestSetInformation,
        OID_GEN_CURRENT_LOOKAHEAD, &LanLookahead, sizeof(LanLookahead), NULL))
        != NDIS_STATUS_SUCCESS) {
        Adapter->ai_state = INTERFACE_DOWN;
        return;
    }

    if ((Status = DoNDISRequest(Adapter, NdisRequestSetInformation,
        OID_GEN_CURRENT_PACKET_FILTER, &Adapter->ai_pfilter, sizeof(uint),
        NULL)) == NDIS_STATUS_SUCCESS) {
        Adapter->ai_state = INTERFACE_UP;
    } else
        Adapter->ai_state = INTERFACE_DOWN;
}


//* LanAllocateTDPacket
//
//  Allocate a packet for NdisTransferData.
//  We always allocate contiguous space for a full MTU of data.
//
PNDIS_PACKET
LanAllocateTDPacket(
    LanInterface *Interface)  // Interface for which to allocate TD packet.
{
    PNDIS_PACKET Packet;
    PNDIS_BUFFER Buffer;
    void *Mem;
    NDIS_STATUS Status;

    NdisAllocatePacket(&Status, &Packet, NaptPacketPool);
    if (Status != NDIS_STATUS_SUCCESS)
        goto ErrorExit;

    Mem = ExAllocatePool(NonPagedPool, Interface->ai_mtu);
    if (Mem == NULL)
        goto ErrorExitFreePacket;

    NdisAllocateBuffer(&Status, &Buffer, NaptBufferPool,
                       Mem, Interface->ai_mtu);
    if (Status != NDIS_STATUS_SUCCESS)
        goto ErrorExitFreeMem;

    NdisChainBufferAtFront(Packet, Buffer);
    return Packet;

  ErrorExitFreeMem:
    ExFreePool(Mem);
  ErrorExitFreePacket:
    NdisFreePacket(Packet);
  ErrorExit:
    return NULL;
}

extern uint UseEtherSNAP(PNDIS_STRING Name);


//* LanRegister - Register a protocol with the Lan module.
//
//  We register an adapter for Lan processing and create a LanInterface
//  structure to represent it.  We also open the NDIS adapter here.
//
//  REVIEW: Should we set the packet filter to NOT accept broadcast packets?
//  REVIEW: Broadcast isn't used in IPv6.  Junk bcast* stuff as well?  Switch
//  REVIEW: this to keeping track of multicasts?
//
int
LanRegister(
    PNDIS_STRING Adapter,             // Name of the adapter to bind to.
    struct LanInterface **Interface)  // Where to return new interace.
{
    LanInterface *ai;  // Pointer to interface struct for this interface.
    NDIS_STATUS Status, OpenStatus;     // Status values.
    uint i = 0;                         // Medium index.
    NDIS_MEDIUM MediaArray[1];
    uchar *buffer;                      // Pointer to our buffers.
    uint mss;
    uint speed;
    uint Needed;
    uint MacOpts;
    uchar bcastmask, bcastval, bcastoff, addrlen, hdrsize, snapsize;
    uint OID;
    uint PF;
    PNDIS_BUFFER Buffer;

    //
    // Allocate memory to hold new interface.
    //
    ai = (LanInterface *) ExAllocatePool(NonPagedPool, sizeof(LanInterface));
    if (ai == NULL)
        return FALSE;  // Couldn't allocate memory for this one.
    RtlZeroMemory(ai, sizeof(LanInterface));

    //
    // In actual practice, we've only tested against Ethernet.
    // So disallow other media for now.
    //
    MediaArray[0] = NdisMedium802_3;
#if 0
    MediaArray[1] = NdisMedium802_5;
    MediaArray[2] = NdisMediumFddi;
    MediaArray[3] = NdisMediumArcnet878_2;
#endif

    // Initialize this adapter interface structure.
    ai->ai_state = INTERFACE_INIT;

    // Initialize the locks.
    KeInitializeSpinLock(&ai->ai_lock);

    KeInitializeEvent(&ai->ai_event, SynchronizationEvent, FALSE);

    // Open the NDIS adapter.
    NdisOpenAdapter(&Status, &OpenStatus, &ai->ai_handle,
                    &i, MediaArray, 1,
                    LanHandle, ai, Adapter, 0, NULL);

    // Block for open to complete.
    if (Status == NDIS_STATUS_PENDING) {
        (void) KeWaitForSingleObject(&ai->ai_event, UserRequest, KernelMode,
                                     FALSE, NULL);
        Status = (NDIS_STATUS)ai->ai_status;
    }

    ai->ai_media = MediaArray[i];   // Fill in media type.

    //
    // Open adapter completed.  If it succeeded, we'll finish our
    // intialization.  If it failed, bail out now.
    //
    if (Status != NDIS_STATUS_SUCCESS) {
        ai->ai_handle = NULL;
        FreeLanInterface(ai);
        return FALSE;
    }

    //
    // Read the local link-level address from the adapter.
    //
    switch (ai->ai_media) {
    case NdisMedium802_3:
        addrlen = IEEE_802_ADDR_LENGTH;
        bcastmask = ETHER_BCAST_MASK;
        bcastval = ETHER_BCAST_VAL;
        bcastoff = ETHER_BCAST_OFF;
        OID = OID_802_3_CURRENT_ADDRESS;
        hdrsize = sizeof(EtherHeader);
        if (UseEtherSNAP(Adapter)) {
            hdrsize += sizeof(SNAPHeader);
        }

        PF = NDIS_PACKET_TYPE_BROADCAST | NDIS_PACKET_TYPE_DIRECTED |
            NDIS_PACKET_TYPE_MULTICAST;
        break;

    case NdisMedium802_5:
        addrlen = IEEE_802_ADDR_LENGTH;
        bcastmask = TR_BCAST_MASK;
        bcastval = TR_BCAST_VAL;
        bcastoff = TR_BCAST_OFF;
        OID = OID_802_5_CURRENT_ADDRESS;
        hdrsize = sizeof(TRHeader) + sizeof(SNAPHeader);
        PF = NDIS_PACKET_TYPE_BROADCAST | NDIS_PACKET_TYPE_DIRECTED;
        break;

    case NdisMediumFddi:
        addrlen = IEEE_802_ADDR_LENGTH;
        bcastmask = FDDI_BCAST_MASK;
        bcastval = FDDI_BCAST_VAL;
        bcastoff = FDDI_BCAST_OFF;
        OID = OID_FDDI_LONG_CURRENT_ADDR;
        hdrsize = sizeof(FDDIHeader) + sizeof(SNAPHeader);
        PF = NDIS_PACKET_TYPE_BROADCAST | NDIS_PACKET_TYPE_DIRECTED |
            NDIS_PACKET_TYPE_MULTICAST;
        break;

    case NdisMediumArcnet878_2:
        addrlen = 1;
        bcastmask = ARC_BCAST_MASK;
        bcastval = ARC_BCAST_VAL;
        bcastoff = ARC_BCAST_OFF;
        OID = OID_ARCNET_CURRENT_ADDRESS;
        hdrsize = sizeof(ARCNetHeader);
        PF = NDIS_PACKET_TYPE_BROADCAST | NDIS_PACKET_TYPE_DIRECTED;
        break;

    default:
        KdBreakPoint();
        FreeLanInterface(ai);
        return FALSE;
    }

    ai->ai_bcastmask = bcastmask;
    ai->ai_bcastval = bcastval;
    ai->ai_bcastoff = bcastoff;
    ai->ai_addrlen = addrlen;
    ai->ai_hdrsize = hdrsize;
    ai->ai_pfilter = PF;

    Status = DoNDISRequest(ai, NdisRequestQueryInformation, OID,
                           ai->ai_addr, addrlen, NULL);

    if (Status != NDIS_STATUS_SUCCESS) {
        //
        // Failed to get link-level address.  Bail.
        //
        FreeLanInterface(ai);
        return FALSE;
    }

    //
    // Read the maximum frame size.
    //
    Status = DoNDISRequest(ai, NdisRequestQueryInformation,
                           OID_GEN_MAXIMUM_FRAME_SIZE, &mss,
                           sizeof(mss), NULL);

    if (Status != NDIS_STATUS_SUCCESS) {
        //
        // Failed to get maximum frame size.  Bail.
        //
        FreeLanInterface(ai);
        return FALSE;
    }

    //
    // If this is token ring, figure out the RC len stuff now.
    //
    if (ai->ai_media == NdisMedium802_5) {
        mss -= (sizeof(RC) + (MAX_RD * sizeof(ushort)));
    } else {
        if (ai->ai_media == NdisMediumFddi) {
            mss = MIN(mss, FDDI_MSS);
        }
    }

    ai->ai_mtu = (ushort)mss;

    //
    // Read the speed for local purposes.
    //
    Status = DoNDISRequest(ai, NdisRequestQueryInformation,
                           OID_GEN_LINK_SPEED, &speed, sizeof(speed), NULL);

    if (Status == NDIS_STATUS_SUCCESS) {
        ai->ai_speed = speed * 100L;
    }

    //
    // Read and save the options.
    //
    (void) DoNDISRequest(ai, NdisRequestQueryInformation, OID_GEN_MAC_OPTIONS,
                         &MacOpts, sizeof(MacOpts), NULL);

    //
    // Read and store the vendor description string.
    //
    Status = DoNDISRequest(ai, NdisRequestQueryInformation,
                           OID_GEN_VENDOR_DESCRIPTION, &ai->ai_desc,
                           0, &Needed);

    if ((Status == NDIS_STATUS_INVALID_LENGTH) ||
        (Status == NDIS_STATUS_BUFFER_TOO_SHORT)) {
        //
        // We now know the size we need.  Allocate a buffer.
        //
        buffer = ExAllocatePool(NonPagedPool, Needed);
        if (buffer != NULL) {
            Status = DoNDISRequest(ai, NdisRequestQueryInformation,
                OID_GEN_VENDOR_DESCRIPTION, buffer, Needed, NULL);
            if (Status == NDIS_STATUS_SUCCESS) {
                ai->ai_desc = buffer;
                ai->ai_desclen = Needed;
            }
        }
    }

    //
    // Allocate a Tranfer Data packet for this interface.
    //
    ai->ai_tdpacket = LanAllocateTDPacket(ai);

    *Interface = ai;

    return TRUE;
}

#pragma END_INIT


//* LanCreateToken
//
//  Given a link-layer address, creates a 64-bit "interface identifier"
//  in the low eight bytes of an IPv6 address.
//  Does not modify the other bytes in the IPv6 address.
//
void
LanCreateToken(
    void *Context,      // Unused (nominally, our LanInterface).
    void *LinkAddress,  // Link-layer address.
    IPv6Addr *Address)  // IPv6 address to place token into.
{
    uchar *IEEEAddress = (uchar *)LinkAddress;

    Address->u.Byte[8] = IEEEAddress[0] ^ 0x2;
    Address->u.Byte[9] = IEEEAddress[1];
    Address->u.Byte[10] = IEEEAddress[2];
    Address->u.Byte[11] = 0xff;
    Address->u.Byte[12] = 0xfe;
    Address->u.Byte[13] = IEEEAddress[3];
    Address->u.Byte[14] = IEEEAddress[4];
    Address->u.Byte[15] = IEEEAddress[5];
}


//* LanReadLinkLayerAddressOption - Parse a ND link-layer address option.
//
//  Parses a Neighbor Discovery link-layer address option
//  and if valid, returns a pointer to the link-layer address.
//
void *
LanReadLinkLayerAddressOption(
    void *Context,      // Interface for which ND option applies.
    uchar *OptionData)  // Option data to parse.
{
    LanInterface *Interface = (LanInterface *)Context;

    //
    // Check that the option length is correct,
    // allowing for the option type/length bytes
    // and rounding up to 8-byte units.
    //
    if (((Interface->ai_addrlen + 2 + 7) / 8) != OptionData[1])
        return NULL;

    //
    // Skip over the option type and length bytes,
    // and return a pointer to the option data.
    //
    return OptionData + 2;
}


//* LanWriteLinkLayerAddressOption - Create a ND link-layer address option.
//
//  Creates a Neighbor Discovery link-layer address option.
//  Our caller takes care of the option type & length fields.
//  We handle the padding/alignment/placement of the link address
//  into the option data.
//
//  (Our caller allocates space for the option by adding 2 to the
//  link address length and rounding up to a multiple of 8.)
//
void
LanWriteLinkLayerAddressOption(
    void *Context,      // Interface to create option regarding.
    uchar *OptionData,  // Where the option data resides.
    void *LinkAddress)  // Link-level address.
{
    LanInterface *Interface = (LanInterface *)Context;

    //
    // Place the address after the option type/length bytes.
    //
    RtlCopyMemory(OptionData + 2, LinkAddress, Interface->ai_addrlen);
}


//* LanConvertMulticastAddress
//
//  Converts an IPv6 multicast address to a link-layer address.
//  Generally this requires hashing the IPv6 address into a set
//  of link-layer addresses, in a link-layer-specific way.
//
void
LanConvertMulticastAddress(
    void *Context,      // Unused (nominally, our LanInterface).
    IPv6Addr *Address,  // IPv6 multicast address.
    void *LinkAddress)  // Where link-level address to be filled resides.
{
    uchar *IEEEAddress = (uchar *)LinkAddress;

    IEEEAddress[0] = 0x33;
    IEEEAddress[1] = 0x33;
    IEEEAddress[2] = Address->u.Byte[12];
    IEEEAddress[3] = Address->u.Byte[13];
    IEEEAddress[4] = Address->u.Byte[14];
    IEEEAddress[5] = Address->u.Byte[15];
}


//* LanSetMulticastAddressList
//
//  Takes an array of link-layer multicast addresses
//  (from LanConvertMulticastAddress) from which we should
//  receive packets.  Passes them to NDIS.
//
NDIS_STATUS
LanSetMulticastAddressList(
    void *Context,
    void *LinkAddresses,
    uint NumKeep,
    uint NumAdd,
    uint NumDel)
{
    LanInterface *Interface = (LanInterface *)Context;
    NDIS_STATUS Status;

    Status = DoNDISRequest(Interface,
                           NdisRequestSetInformation,
                           OID_802_3_MULTICAST_LIST,
                           LinkAddresses,
                           (NumKeep + NumAdd) * Interface->ai_addrlen,
                           NULL);

    //
    // If NDIS reports no problems then turn off the all-mullticast 
    // fileter in case we had previously set it.
    //
    if (Status == NDIS_STATUS_SUCCESS) {
        Interface->ai_pfilter &= ~NDIS_PACKET_TYPE_ALL_MULTICAST;
        DoNDISRequest(Interface, NdisRequestSetInformation,
                      OID_GEN_CURRENT_PACKET_FILTER,  &Interface->ai_pfilter,
                      sizeof(uint), NULL);
    }


    // 
    // If NDIS reports that the multicast address list is full, try setting
    // the receive filter to pick up all multicast packets.
    //
    // This code was swiped from the V4 stack: arp.c
    //
    if (Status == NDIS_STATUS_MULTICAST_FULL) {
        Interface->ai_pfilter |= NDIS_PACKET_TYPE_ALL_MULTICAST;
        Status = DoNDISRequest(Interface, NdisRequestSetInformation,
                      OID_GEN_CURRENT_PACKET_FILTER, &Interface->ai_pfilter,
                      sizeof(uint), NULL);
    }

    return Status;
}


//* LanBindAdapter - Bind and initialize an adapter.
//
//  Called in a PNP environment to initialize and bind an adapter. We open
//  the adapter and get it running, and then we call up to IP to tell him
//  about it. IP will initialize, and if all goes well call us back to start
//  receiving.
//
void NDIS_API
LanBindAdapter(
    PNDIS_STATUS RetStatus,    // Where to return status of this call.
    NDIS_HANDLE BindContext,   // Handle for calling BindingAdapterComplete.
    PNDIS_STRING AdapterName,  // Name of adapeter.
    PVOID SS1,                 // System specific parameter 1.
    PVOID SS2)                 // System specific parameter 2.
{
    LanInterface *Interface;  // Newly created interface.
    IP_STATUS Status;         // State of IPAddInterface call.
    LLIPBindInfo BindInfo;    // Binding informatio for IP.
    NDIS_HANDLE Handle;

    //
    // First, open the adapter and get the info.
    //
    if (!LanRegister(AdapterName, &Interface)) {
        *RetStatus = NDIS_STATUS_FAILURE;
        return;
    }

    //
    // OK, we're opened the adapter.  Notify IP about it.
    //
    BindInfo.lip_context = Interface;
    BindInfo.lip_transmit = LanTransmit;
    BindInfo.lip_token = LanCreateToken;
    BindInfo.lip_rdllopt = LanReadLinkLayerAddressOption;
    BindInfo.lip_wrllopt = LanWriteLinkLayerAddressOption;
    BindInfo.lip_mcaddr = LanConvertMulticastAddress;
    BindInfo.lip_mclist = LanSetMulticastAddressList;
    BindInfo.lip_flags = LIP_MCLOOP_FLAG;
    BindInfo.lip_defmtu = BindInfo.lip_maxmtu = Interface->ai_mtu;
    BindInfo.lip_hdrsize = Interface->ai_hdrsize;
    BindInfo.lip_addrlen = Interface->ai_addrlen;
    BindInfo.lip_addr = Interface->ai_addr;

    Interface->ai_context = NAPTCreateInterface(&BindInfo);
    if (Interface->ai_context == NULL) {
        //
        // Attempt to create IP inteface failed.  Need to close the binding.
        // FreeLanInterface will do that, as well as freeing resources.
        //
        FreeLanInterface(Interface);
        *RetStatus = NDIS_STATUS_FAILURE;
    } else {
        LanOpen(Interface);
        *RetStatus = NDIS_STATUS_SUCCESS;
    }
}


//* LanUnbindAdapter - Unbind from an adapter.
//
//  Called when we need to unbind from an adapter.
//  We'll notify IP, then free our memory and return.
//
void NDIS_API  // Returns: Nothing.
LanUnbindAdapter(
    PNDIS_STATUS RetStatus,       // Where to return status from this call.
    NDIS_HANDLE ProtBindContext,  // Context we gave NDIS earlier.
    NDIS_HANDLE UnbindContext)    // Context for completing this request.
{
    LanInterface *Interface = (LanInterface *)ProtBindContext;
    NDIS_STATUS Status;
    KIRQL OldIrql;
    NDIS_HANDLE Handle;

    //
    // Shut adapter up, so we don't get any more frames.
    //
    Interface->ai_pfilter = 0;
    DoNDISRequest(Interface, NdisRequestSetInformation,
                  OID_GEN_CURRENT_PACKET_FILTER,
                  &Interface->ai_pfilter, sizeof(uint), NULL);

    // Mark adapter down.
    Interface->ai_state = INTERFACE_DOWN;

    //
    // Tell IP it's gone.  We need to make sure that we don't tell IP twice.
    // To do this we set the context to NULL after we tell IP the first time.
    //
    if (Interface->ai_context != NULL) {
#if 0
        // BUGBUG: put code to call an IPv6 delete interface function here.
#endif
        Interface->ai_context = NULL;
    }

    //
    // Finally, close it.  We do this here so we can return a valid status.
    //
    KeAcquireSpinLock(&Interface->ai_lock, &OldIrql);

    if (Interface->ai_handle != NULL) {
        Handle = Interface->ai_handle;
        Interface->ai_handle = NULL;
        KeReleaseSpinLock(&Interface->ai_lock, OldIrql);

        KeInitializeEvent(&Interface->ai_event, SynchronizationEvent, FALSE);
        NdisCloseAdapter(&Status, Handle);

        // Block for close to complete.
        if (Status == NDIS_STATUS_PENDING) {
            (void) KeWaitForSingleObject(&Interface->ai_event, UserRequest,
                                         KernelMode, FALSE, NULL);
            Status = (NDIS_STATUS)Interface->ai_status;
        }
    } else {
        KeReleaseSpinLock(&Interface->ai_lock, OldIrql);
        Status = NDIS_STATUS_SUCCESS;
    }

    *RetStatus = Status;

    if (Status == NDIS_STATUS_SUCCESS) {
        FreeLanInterface(Interface);
    }
}


//* LanloadProtocol - Load.
//
//  Called when we dynamically load the protocol.
//
//  Input: Nothing.
//
//  Returns: Nothing.
//
void NDIS_API
LanLoadProtocol(void)
{
    NDIS_STATUS Status;

    //
    // Create Packet and Buffer pools for IPv6.
    //
    NdisAllocatePacketPool(&Status, &NaptPacketPool, 512,
                           sizeof(NaptPacketContext));
    NdisAllocateBufferPool(&Status, &NaptBufferPool, 512);

    if (LanInit((WCHAR*)0) == 1) {
        // KdPrint(("LanInit succeeded\n"));
    } else {
        KdPrint(("Warning: LanInit failed\n"));
    }
}


//* LanUnloadProtocol - Unload.
//
//  Called when we need to unload.  All we do is call up to IP, and return.
//
//  Input: Nothing.
//
//  Returns: Nothing.
//
void NDIS_API
LanUnloadProtocol(void)
{
    NDIS_STATUS Status;
    LanInterface *Adapter;
    Interface *IF;

    KdPrint(("Napt LanUnloadProtocol\n"));
    // Unbind protocol from adapter.
    for (IF = NAPTIFList; IF != (Interface *)0; IF = IF->Next){
        Adapter = (LanInterface*)IF->LinkContext;

        // BUGBUG: there is some magic NDIS call to invoke
        // this properly.
        LanUnbindAdapter(&Status, Adapter, (NDIS_HANDLE)0);
    }

    KdPrint(("Napt\tderegister protocol\n"));
    // Deregister protocol.
    NdisDeregisterProtocol(&Status, LanHandle);

    KdPrint(("Napt\trelease packet pool\n"));
    // Release packet pool memory.
    NdisFreePacketPool(NaptPacketPool);

    KdPrint(("Napt\trelease buffer pool\n"));
    // Release buffer pool memory.
    NdisFreeBufferPool(NaptBufferPool);
}
