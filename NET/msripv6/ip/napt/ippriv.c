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
// NAPT support to send RAW IP4 packets via tcpip.sys
// This only works by exporting the following symbols from tcpip.sys:
//  LookupNextHop           from ntos/private/tdi/tcpip/ip/iproute.c
//  DerefIF                 from ntos/private/tdi/tcpip/ip/iproute.c
//  SendIPPacket            from ntos/private/tdi/tcpip/ip/ipxmit.c
//  GetIPHeader             from ntos/private/tdi/tcpip/ip/ipxmit.c
//  FreeIPPacket            from ntos/private/tdi/tcpip/ip/ipxmit.c

#include "oscfg.h"
#include "naptdef.h"


//
// Treat the ipdef.h 'Interface' structure as opaque datastructure.
//
typedef void IP4Interface;

extern
IP4Interface *
LookupNextHop(in_addr Destination, in_addr Src, in_addr *NextHop, uint *MTU);

#ifdef _NOT_NEEDED_
//  LookupNextHopWithBuffer from ntos/private/tdi/tcpip/ip/iproute.c
extern
IP4Interface *
LookupNextHopWithBuffer(in_addr Destination, in_addr Src, in_addr *NextHop,
                        uint *MTU, uchar Protocol, uchar *Buffer, uint Length);

#endif // _NOT_NEEDED_

#ifdef _THIS_DOES_NOT_WORK_
#ifdef _PNP_POWER
extern
void
DerefIF(IP4Interface *IF);
#endif // _PNP_POWER
#endif // _THIS_DOES_NOT_WORK_

extern
IP_STATUS
SendIPPacket(IP4Interface *IF, in_addr FirstHop, PNDIS_PACKET Packet,
             PNDIS_BUFFER Buffer, IPHeader *Header, uchar *Options, 
             uint OptionSize);

extern
IPHeader *
GetIPHeader(PNDIS_PACKET *PacketPtr);

extern
PNDIS_BUFFER
FreeIPPacket(PNDIS_PACKET Packet);

// Definitions of flags in pc_flags field.
// from ntos/private/tdi/tcpip/ip/ipdef.h
#define PACKET_FLAG_OPTIONS    1 // Set if packet has an options buffer.
#define PACKET_FLAG_IPBUF      2 // Set if packet is composed of IP buffers.
#define PACKET_FLAG_RA         4 // Set if packet is being used for reassembly.
#define PACKET_FLAG_FW         8 // Set if packet is a forwarding packet.
#define PACKET_FLAG_IPHDR   0x10 // Packet uses an IP hdr buffer.

// MEFBUG: changed name from ULStatusProc -> UL4StatusProc, because
// MEFBUG: ip6def.h defines it, too.
// from ntos/private/tdi/tcpip/ip/ipdef.h
typedef uint (*UL4StatusProc)(uchar, IP_STATUS, in_addr, in_addr, in_addr,
                              ulong, void*);

// MEFBUG: defining IPOptInfo and IPRcvBuf as opaque types, as I don't
// MEFBUG: want to pull in the definition of these into this file.
typedef void IP4OptInfo;
typedef void IP4RcvBuf;

// MEFBUG: changed IPAddr -> in_addr
// from ntos/private/tdi/tcpip/ip/ipdef.h
typedef IP_STATUS (*ULRcvProc)(void *, in_addr, in_addr, in_addr, in_addr,
                               IPHeader UNALIGNED *, uint, IP4RcvBuf *, uint,
                               uchar, uchar, IP4OptInfo *);

// Partial Protocol information structure. 
// from ntos/private/tdi/tcpip/ip/ipdef.h
typedef struct ProtInfo {
    void (*pi_xmitdone)(void *, PNDIS_BUFFER);  // Transmit done routine.
    ULRcvProc pi_rcv;                           // Receive routine.
/*X*/ UL4StatusProc pi_status;                    // Status handler.
    void (*pi_rcvcmplt)(void);                  // Receive complete handler.
    uchar pi_protocol;                          // Protocol type.
    uchar pi_pad[3];                            // Pad to dword.
} ProtInfo;


// Partial PacketContext structure 
// from ntos/private/inc/ip.h
struct IP4PacketContext {
    struct PCCommon {
        PNDIS_PACKET pc_link;  // Link on chain of packets.
        uchar pc_owner;        // Owner of packet.
        uchar pc_flags;        // Flags concerning this packet.
        ushort pc_pad;         // Pad to 32 bit boundary.
    } pc_common;
    void *pc_br;             // Opaque pointer to buffer reference structure.
    struct ProtInfo *pc_pi;  // Protocol info structure for this packet.
    void *pc_context;        // Protocol context passed back on send complete.
};

static
void
IP4XmitDone(void *DataPtr, PNDIS_BUFFER Buffer)
{
    PNDIS_BUFFER NextBuffer;

//    DbgPrint("napt_nt4 IP4XmitDone\n");

    while (Buffer != (PNDIS_BUFFER)NULL) {
        VOID *Mem;
        UINT Unused;

        NdisGetNextBuffer(Buffer, &NextBuffer);
        NdisQueryBuffer(Buffer, &Mem, &Unused);
        NdisFreeBuffer(Buffer);
        Buffer = NextBuffer;
        ExFreePool(Mem);
    }
}

static uint
IP4Status(uchar StatusType, IP_STATUS StatusCode, in_addr OrigDest,
          in_addr OrigSrc, in_addr Src, ulong Param, void *Data)
{
    DbgPrint("napt_nt4 IP4Status: StatusType=%x StatusCode=%x, OrigDest=%x, "
             "OrigSrc=%x, Src=%x\n",
             StatusType, StatusCode, OrigDest, OrigSrc, Src);
    return 0;
}

static
struct ProtInfo NaptIP4ProtInfo = {IP4XmitDone, 0, IP4Status, 0, 0,{0,0,0}};


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// PUBLIC NT4.0 NAPT IP4 support
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

int
NaptIP4Init(){
    // Do nothing.
    return TRUE;
}

void
NaptIP4UnInit(){
    // Do nothing.
}

__inline
void
NaptFreeIP4Packet(PNDIS_PACKET Packet) {
    FreeIPPacket(Packet);
}

void
NaptSendIP4Packet(IPHeader* IP4,
                  PNDIS_PACKET Packet,
                  PNDIS_BUFFER Buffer)
{
    IP4Interface *IF4;
    uint MTU;
    in_addr NextHop;
  
    IF4 = LookupNextHop(IP4->iph_dest, IP4->iph_src, &NextHop, &MTU);
    // MEFBUG: make sure route MTU < IF4->if_mtu; 
    // MEFBUG: make sure IP4->iph_lenght < MTU
    if (IF4 == (IP4Interface *)0){
        goto release_packet;
    }

    // MEFBUG: shouldn't we check return code?  You lazy bum!
    (void) SendIPPacket(IF4, NextHop, Packet, Buffer, IP4, (uchar *)0, 0);

#ifdef _THIS_DOES_NOT_WORK_
#ifdef _PNP_POWER
    // Ugh.  Don't ask me.
    DerefIF(IF4);
#endif // _PNP_POWER
#endif // _THIS_DOES_NOT_WORK_
    return;

release_packet:
    NaptFreeIP4Packet(Packet);
}

NTSTATUS
NaptAllocateIP4Packet(
    PNDIS_PACKET *Packet,
    PNDIS_BUFFER *Buffer,
    uint MemLen,
    IPHeader **IP4)
{
    NDIS_STATUS Status;
    uchar* Mem;

    *IP4 = GetIPHeader(Packet);
    if (*Packet != NULL) {
        struct IP4PacketContext *PContext;

        // Allocate memory for buffer.
        Mem = ExAllocatePool(NonPagedPool, MemLen);
        if (Mem == NULL) {
            KdPrint(("NaptAllocateIP4Packet: Couldn't allocate memory!?!\n"));
            goto release_packet;
        }

        // Allocate a buffer and put it on the packet chain.
        NdisAllocateBuffer(&Status, Buffer, NaptBufferPool, Mem, MemLen);
        if (Status != NDIS_STATUS_SUCCESS) {
            KdPrint(("NaptAllocateIP4Packet: "
                     "Couldn't allocate buffer header!?!\n"));
            goto release_packet;
        }

        PContext = (struct IP4PacketContext*)(*Packet)->ProtocolReserved;
        PContext->pc_common.pc_flags |= PACKET_FLAG_IPHDR;
        // Originally had PACKET_FLAG_IPBUF as well?
        PContext->pc_pi = &NaptIP4ProtInfo;
        PContext->pc_context = (void*)0;
        return STATUS_SUCCESS;

      release_packet:
        NaptFreeIP4Packet(*Packet);
    }

    return STATUS_UNSUCCESSFUL;

} // NaptAllocateIP4Packet()
