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

#ifndef __NAPTDEF_INCLUDE__
#define __NAPTDEF_INCLUDE__ 1

#include "oscfg.h"
#include "ndis.h"
#include "ip6imp.h"
#include "ip6def.h"
#include "llip6if.h"
#include "hash.h"
#include "mt4.h"
#include "mt6.h"

//
// Some common types needed in various places.
// MEFBUG: where should these come from?
typedef unsigned int uint;
typedef unsigned long DWORD;
typedef void * PVOID;
typedef unsigned int in_addr;

//
// The following protocol "Header" typedefs should be pulled in from
// v4 icmp.h & ip.h, udp.h, and tcp.h.
//
#define INADDR_ANY 0

//
// MEFBUG: get this from tcp.h 
// #include "tcp.h"
// Structure of a TCP packet header.
#define IP_PROTOCOL_TCP 6
typedef int SeqNum;  // A sequence number.
typedef struct TCPHeader {
    ushort tcp_src;     // Source port.
    ushort tcp_dest;    // Destination port.
    SeqNum tcp_seq;     // Sequence number.
    SeqNum tcp_ack;     // Ack number.
    ushort tcp_flags;   // Flags and data offset.
    ushort tcp_window;  // Window offered.
    ushort tcp_xsum;    // Checksum.
    ushort tcp_urgent;  // Urgent pointer.
} TCPHeader;

// MEFBUG: get this from udp.h 
// #include "udp.h"
// Structure of a UDP header.
#define IP_PROTOCOL_UDP 17
typedef struct UDPHeader {
    ushort Source;    // Source port.
    ushort Dest;      // Destination port.
    ushort Length;    // Length.
    ushort Checksum;  // Checksum.
} UDPHeader;

// MEFBUG: get this from v4 ip.h
#define IP_DEFAULT_VERLEN 0x45
#define IP_VERSION_MASK   0xF0
#define IP_HEADER_MASK    0x0F
#define IP_OFFSET_MASK    ~0x00E0

typedef struct _IPHeader {
    uchar iph_verlen;    // Version and length.
    uchar iph_tos;       // Type of service.
    ushort iph_length;   // Total length of datagram.
    ushort iph_id;       // Identification.
    ushort iph_offset;   // Flags and fragment offset.
    uchar iph_ttl;       // Time to live.
    uchar iph_protocol;  // Protocol.
    ushort iph_xsum;     // Header checksum.
    in_addr iph_src;     // Source address.
    in_addr iph_dest;    // Destination address.
} IPHeader;

// MEFBUG: get this from v4 icmp.h header file.
#define IP_PROTOCOL_ICMP 1
typedef struct ICMPHeader {
    uchar Type;       // Type of message (high bit zero for error messages).
    uchar Code;       // Type-specific differentiater.
    ushort Checksum;  // Calculated over ICMPv6 message and IPv6 psuedo-header.
} ICMPHeader;

// ICMPv4 type field definitons.
#define ICMP_ECHO_REPLY 0
#define ICMP_DEST_UNREACH 3
#define ICMP_ECHO_REQUEST 8
#define ICMP_TIME_EXCEEDED 11
#define ICMP_PARAMETER_PROBLEM 12

// ICMPv4 codes for destination_unreachable.
#define NET_UNREACH 0
#define HOST_UNREACH 1
#define PROT_UNREACH 2
#define PORT_UNREACH 3
#define FRAG_NEEDED 4
#define SR_FAILED 5
#define NET_UNKNOWN 6
#define HOST_UNKNOWN 7
#define HOST_ISOLATED 8
#define NET_ANO 9
#define HOST_ANO 10
#define NET_UNR_TOS 11
#define HOST_UNR_TOS 12

// Codes for REDIRECT.
#define REDIR_NET 0
#define REDIR_HOST 1
#define REDIR_NETTOS 2
#define REDIR_HOSTTOS 3
  
// Codes for TIME_EXCEEDED.
#define EXC_TTL 0
#define EXC_FRAGTIME 1

//
// Global variables.
//
extern PDRIVER_OBJECT NaptDriverObject;
extern int NaptUnloading;
extern NDIS_HANDLE NaptPacketPool, NaptBufferPool;
extern PHashTable IP6toIP4tbl;
extern PHashTable IP4toIP6tbl;
extern IPv6Addr UnspecifiedAddr, V4MappedPrefix;
extern IPv6Addr NaptLinkLocalAddr, IFLinkLocalAddr;
extern Interface *NaptInterface;
extern NeighborCacheEntry *NaptNCE;

//
// NAPT Procedure Prototypes.
//

extern NTSTATUS
DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath);

extern VOID
DriverUnload(IN PDRIVER_OBJECT DriverObject);

extern
NTSTATUS
NaptAllocateIP6Packet(
    PNDIS_PACKET *Packet,
    uchar** Mem,
    uint MemLen);

extern
NTSTATUS
NaptAllocateIP4Packet(
    PNDIS_PACKET *Packet, 
    PNDIS_BUFFER *Buffer, 
    uint MemLen,
    IPHeader **IP4);

extern
void
NaptIP6Receive(
    void *MyContext,
    PNDIS_PACKET Packet,
    uint Offset,
    void *LinkAddress);


extern
int
NaptIP4Receive(
    void *MyContext,
    PNDIS_PACKET ip4Packet,
    uint Position,
    void *InitialData,
    uint InitialSize,
    uint TotalSize);

extern
ushort
NaptIP6toIP4Checksum(
    IPv6Header UNALIGNED *IP6,
    IPHeader UNALIGNED *IP4,
    ushort headcsum);

extern
ushort
NaptIP4toIP6Checksum(
    IPHeader UNALIGNED *IP4,
    IPv6Header UNALIGNED *IP6,
    ushort headcsum);

extern
NTSTATUS
NaptIcmp4toIcmp6(
    IPHeader UNALIGNED *IP4,
    IPv6Header UNALIGNED *IP6,
    void* ip4Payload,
    void* ip6Payload,
    ushort Length,
    uint IcmpError);

extern
NTSTATUS
NaptIcmp6toIcmp4(
    IPv6Header UNALIGNED *IP6,
    IPHeader UNALIGNED *IP4,
    void* ip6Payload,
    void* ip4Payload,
    ushort Length,
    uint IcmpError);

extern
void
NaptSendIP4Packet(
    IPHeader UNALIGNED *IP4,
    PNDIS_PACKET Packet,
    PNDIS_BUFFER Buffer);

extern
void
NaptFreeIP4Packet(PNDIS_PACKET Packet);

extern
int
NaptIP4Init(void);

extern
void
NaptIP4UnInit(void);


extern
NTSTATUS
NaptReadRegistry(void);

//
// Structure of a packet context.
//
typedef struct PacketNaptContext {
    PNDIS_PACKET pc_link;                     // For lists of packets.
    union {
        uint pc_offset;                       // Offset where real data starts.
        uint pc_nucast;                       // Used only in lan.c.
    };
    PNDIS_PACKET OrigPacket;
} PacketNaptContext;

typedef struct NaptPacketContext {
    union { 
        Packet6Context packet6Context;
        PacketNaptContext packetNaptContext;
    } u;
} NaptPacketContext;

//
// Context used for sending Ip4 packets.
//
#define NAPTPC(Packet) ((PacketNaptContext *)(Packet)->ProtocolReserved)

//
// Context used for sending Ip6 packets.
//
#define IP6PC(Packet) PC(Packet)

#endif // NAPTDEF_INCLUDED
