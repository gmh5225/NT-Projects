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

#include "oscfg.h"
#include "ndis.h"
#include "ip6imp.h"
#include "ip6def.h"
#include "icmp6.h"
#include "route.h"
#include "ntddip6.h"
#include "alloca.h"
#include "fragment.h"
#include "neighbor.h"

#include "naptdef.h"
#include "ntddnapt.h"

//
// NAPT Global Variables.
//

PDRIVER_OBJECT NaptDriverObject;
int NaptUnloading = FALSE;
Interface *NaptInterface;
NeighborCacheEntry *NaptNCE;

//
// Global variable containing {ip4addr, range} values that NAPT should
// filter on.
//
NaptIP4Filter naptIP4Filter[128];
int numNaptIP4Filters = 0;

//
// Address Mapping Tables.
//
PHashTable IP6toIP4tbl = NULL;
PHashTable IP4toIP6tbl = NULL;

//
// Common IPv6 addresses.
// REVIEW: these should be defined in some header file.
//
IPv6Addr UnspecifiedAddr = { 0 };
IPv6Addr V4MappedPrefix = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00};
IPv6Addr NaptLinkLocalAddr = {0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
IPv6Addr IFLinkLocalAddr = {0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02};


//
// NAPT Support Routines.
//

//* NaptAllocateIP6Packet
//
//  Allocates a single-buffer packet from the Napt{Packet, Buffer}Pool.
//  This function is nearly identical to the IPv6AllocatePacket()
//  provided by the MSRIPv6 stack.
//
NTSTATUS
NaptAllocateIP6Packet(
    PNDIS_PACKET *Packet,
    uchar** Mem,
    uint MemLen)
{
    NDIS_STATUS Status;
    PNDIS_BUFFER Buffer;

    NdisAllocatePacket(&Status, Packet, NaptPacketPool);
    if (Status != NDIS_STATUS_SUCCESS) {
        KdPrint(("NaptAllocateIP6Packet: Couldn't alloc Ip6 packet hdr!?!\n"));
        return STATUS_UNSUCCESSFUL;
    }
    PC(*Packet)->CompletionHandler = IPv6FreePacket;

    // Allocate memory for buffer.
    *Mem = ExAllocatePool(NonPagedPool, MemLen);
    if (*Mem == NULL) {
        KdPrint(("NaptAllocateIP6Packet: Couldn't allocate memory!?!\n"));
        goto release_packet;
    }
    // Allocate a buffer header and put it on the packet chain.
    NdisAllocateBuffer(&Status, &Buffer, NaptBufferPool, *Mem, MemLen);
    if (Status != NDIS_STATUS_SUCCESS) {
        KdPrint(("NaptAllocateIP6Packet: Couldn't alloc buffer header!?!\n"));
        goto release_packet;
    }
    NdisChainBufferAtFront(*Packet, Buffer);
    return STATUS_SUCCESS;

release_packet:
    IPv6FreePacket(*Packet);  // Part of MSRIPv6.
    return STATUS_UNSUCCESSFUL;
} // NaptAllocateIP6Packet()


//* NaptCopyPayload
//
//  Be a little smarter about copying data.
//
//  If the Destination and Source overlap it will use RtlMoveMemory.
//  Otherwise, it uses RtlCopyMemory.  Finally, if the Destination and
//  Source are identical, this function is a noop.
//
__inline 
static VOID
NaptCopyPayload(
    VOID UNALIGNED *Destination,
    CONST VOID UNALIGNED *Source,
    ULONG Length)
{
    //
    // If the payload pointers aren't the same, then deep copy the
    // payload.  Otherwise, the translation on the packet payload is
    // done in place and it is unnecessary to copy the data.
    //
    if (Destination == Source) {
        ; // No need to copy.
    }
    else if ((Destination > Source) &&
             (Destination <= ((VOID*)((ULONG)Source + Length)))) {
        // Safely move memory around.
        RtlMoveMemory(Destination, Source, Length);
    } else {
        RtlCopyMemory(Destination, Source, Length);
    }
} // NaptCopyPayload


//* NaptIP6SendFragments
//
//  Fragment an IPv6 datagram.
//
//  Slightly modified helper routine for creating and sending IPv6
//  fragments taken from the MSRIPv6 stack.
//
//  The MSRIPv6 stack will never refragment an existing fragment, as
//  1) the stack used by host applications will never generate such
//  packets, and 2) the stack used as a forwarder/router may not
//  refragment existing fragments.
//
void
NaptIP6SendFragments(
    PNDIS_PACKET Packet,   // Packet to send.
    uint Offset,           // Offset from start of Packet to IP header.
    IPv6Header *IP,        // Pointer to Packet's IPv6 header.
    uint PayloadLength,    // Packet payload length.
    RouteCacheEntry *RCE,  // First-hop neighbor information.
    uint PathMTU)          // PathMTU to use when fragmenting.
{
    NeighborCacheEntry *NCE;
    NDIS_STATUS Status;
    PNDIS_PACKET FragPacket;
    PNDIS_BUFFER SrcBuffer;
    uint SrcOffset;
    FragmentHeader FragHdr;
    uchar *Mem;
    uint MemLen;
    uint PktOffset;
    uint UnfragBytes;
    uint BytesLeft;
    uint BytesSent;
    uchar *tbuf;
    uint NextHeaderOffset;
    uint FragPayloadLength;
    uint ContainsFrag;
    uchar HdrType;

    //
    // Determine the 'unfragmentable' portion of this packet.
    // We do this by scanning through all extension headers,
    // and noting the last occurrence, if any, of
    // a routing or hop-by-hop header.
    // We do not assume the extension headers are in recommended order,
    // but otherwise we assume that the headers are well-formed.
    // BUGBUG: We assume that they are contiguous.
    //
    UnfragBytes = sizeof *IP;
    HdrType = IP->NextHeader;
    NextHeaderOffset = (uchar *)&IP->NextHeader - (uchar *)IP;
    tbuf = (uchar *)(IP + 1);
    PktOffset = 0; // Relative to fragmentable part of original packet.
    ContainsFrag = FALSE;
    
    while ((HdrType == IP_PROTOCOL_HOP_BY_HOP) ||
           (HdrType == IP_PROTOCOL_ROUTING) ||
           (HdrType == IP_PROTOCOL_DEST_OPTS) ||
           (HdrType == IP_PROTOCOL_DEST_OPTS) ||
           (HdrType == IP_PROTOCOL_FRAGMENT)) {
        ExtensionHeader *EHdr = (ExtensionHeader *) tbuf;
        uint EHdrLen = (EHdr->HeaderExtLength + 1) * 8;

        if ((HdrType != IP_PROTOCOL_DEST_OPTS) &&
            (HdrType != IP_PROTOCOL_FRAGMENT)) {
            UnfragBytes = tbuf - (uchar *)IP;
            NextHeaderOffset = (uchar *)&EHdr->NextHeader - (uchar *)IP;
        }
        else if (HdrType == IP_PROTOCOL_FRAGMENT) {
            FragmentHeader* frag = (FragmentHeader*)EHdr;

            // This IP packet already started out as a fragment.
            ContainsFrag = TRUE;

            // Inherit ID/offset from the original fragment header.
            FragHdr.Id = frag->Id;
            PktOffset = net_short((ushort)frag->OffsetFlag)
                &FRAGMENT_OFFSET_MASK;

            // Record the HdrType of the next header.
            HdrType = frag->NextHeader;
            break;
        }
        tbuf += EHdrLen;
        HdrType = EHdr->NextHeader;
    }

    //
    // Check that we can actually fragment this packet.
    // If the unfragmentable part is too large, we can't.
    // We need to send at least 8 bytes of fragmentable data
    // in each fragment.
    //
    if (UnfragBytes + sizeof(FragmentHeader) + 8 > PathMTU) {
        KdPrint(("NaptIP6SendFragments: can't fragment\n"));
        Status = NDIS_STATUS_REQUEST_ABORTED;
        goto ErrorExit;
    }

    //
    // Initialize SrcBuffer and SrcOffset, which point
    // to the fragmentable data in the packet.
    // SrcOffset is the offset into SrcBuffer's data,
    // NOT an offset into the packet.
    //
    NdisQueryPacket(Packet, NULL, NULL, &SrcBuffer, NULL);
    SrcOffset = Offset + UnfragBytes;

    //
    // Create new packets of MTU size until all data is sent.
    //
    BytesLeft = sizeof *IP + PayloadLength - UnfragBytes;

    FragHdr.NextHeader = HdrType;
    FragHdr.Reserved = 0;
    if (!ContainsFrag) {
        //
        // Get a fragment ID that is in sync with what the MSRIPv6
        // stack is using.
        //
        FragHdr.Id = net_long(NewFragmentId());
    } else {
        //
        // Skip over the fragment header in the orig ip packet.
        //
        SrcOffset += sizeof(FragmentHeader);
    }

    while (BytesLeft != 0) {
        //
        // Determine new IP payload length (a multiple of 8) and 
        // and set the Fragment Header offset.
        //
        if ((BytesLeft + UnfragBytes + sizeof(FragmentHeader)) > PathMTU) {
            BytesSent = (PathMTU - UnfragBytes - sizeof(FragmentHeader)) & ~7;
            // Not the last fragment, so turn on the M bit.
            FragHdr.OffsetFlag = net_short((ushort)(PktOffset | 1));
        } else {
            BytesSent = BytesLeft;
            FragHdr.OffsetFlag = net_short((ushort)(PktOffset |
                                                    (ContainsFrag ? 1 : 0)));
        }

        //
        // Allocate packet (and a buffer) and memory for new fragment.
        //
        MemLen = Offset + UnfragBytes + sizeof(FragmentHeader) + BytesSent;

        Status = NaptAllocateIP6Packet(&FragPacket, &Mem, MemLen);
        if (Status != NDIS_STATUS_SUCCESS) {
            goto ErrorExit;
        }

        //
        // Copy IP header, Frag Header, and a portion of data to fragment.
        //
        RtlCopyMemory(Mem + Offset, IP, UnfragBytes);
        RtlCopyMemory(Mem + Offset + UnfragBytes, &FragHdr,
                      sizeof(FragmentHeader));
        CopyNdisToFlat(Mem + Offset + UnfragBytes + sizeof(FragmentHeader),
                       SrcBuffer, SrcOffset, BytesSent, &SrcBuffer,
                       &SrcOffset);

        //
        // Correct the PayloadLength and NextHeader fields.
        //
        FragPayloadLength = UnfragBytes + sizeof(FragmentHeader) + BytesSent -
                                sizeof(IPv6Header);
        ASSERT(FragPayloadLength <= MAX_IPv6_PAYLOAD);
        ((IPv6Header *)(Mem + Offset))->PayloadLength =
            net_short((ushort) FragPayloadLength);
        // ASSERT(Mem[Offset + NextHeaderOffset] == HdrType);
        Mem[Offset + NextHeaderOffset] = IP_PROTOCOL_FRAGMENT;

        BytesLeft -= BytesSent;
        PktOffset += BytesSent;

        //
        // Send the fragment.
        //
        NCE = RCE->NCE;
        IPv6Send0(FragPacket, Offset, NCE, &NCE->IF->LinkLocalNTE->Address);
    }
    Status = NDIS_STATUS_SUCCESS;

  ErrorExit:
    IPv6SendComplete(NULL, Packet, Status);
} // NaptIP6SendFragments()


//
// NAPT IP6 -> IP4 TRANSLATION CODE.
//


//* NaptIP6toIP4Checksum
//
//  Computes the incremental checksum differences when converting from
//  an IPv6 to an IPv4 header.
//
ushort
NaptIP6toIP4Checksum(
    IPv6Header UNALIGNED *IP6,
    IPHeader UNALIGNED *IP4,
    ushort headcsum)
{
    uint csum, csum6;
    csum = headcsum;

    headcsum = ~headcsum;
    // Layer4 checksum + checksum over IP4 src/dst addrs.
    csum = headcsum +
        (((IP4->iph_src) >> 16) + ((IP4->iph_src) & 0xffff)) +
        (((IP4->iph_dest) >> 16) + ((IP4->iph_dest) & 0xffff));

    // Checksum over IP6 src/dest addrs.
    csum6 = 
        Cksum(&IP6->Source, sizeof(IPv6Addr)) + 
        Cksum(&IP6->Dest, sizeof(IPv6Addr));
    // Fold 32 bits -> 16 bits.
    csum6 = ((csum6 >> 16) & 0xffff) + (csum6 & 0xffff);
    csum6 += (csum6 >> 16);

    // Ones complement subtract.
    // csum = csum - csum6;
    csum = csum + (~csum6 & 0xffff);
    // Fold 32 bits -> 16 bits.
    csum = ((csum >> 16) & 0xffff) + (csum & 0xffff);
    csum += (csum >> 16);

    csum = (ushort) ~csum;
    if (csum == 0)
        csum = 0xffff;
    return csum;
} // NaptIP6toIP4Checksum()


//* NaptIP6toIP4
//
// Assumptions:
// - Ptrs to IP6 and IP4 headers don't point at same or overlapping memory.
// - Packet payload is continguous.
//
NTSTATUS
NaptIP6toIP4(
    IPv6Header UNALIGNED *IP6, 
    IPHeader UNALIGNED *IP4,
    void *ip6Payload,
    void *ip4Payload, 
    ushort Length,
    uint icmpError)
{
    NTSTATUS status;
    uint proto;
    uint frag_off;
    uint len;
    uint Stateful;
    uint Class;

    IP4->iph_verlen = IP_DEFAULT_VERLEN;
    //
    // Extract the traffic class.
    //
    Class = IP6->VersClassFlow & IP_TRAFFIC_CLASS_MASK;
    if (Class==0) {
        IP4->iph_tos = 0;
    } else {
        IP4->iph_tos = (uchar)(net_long(Class) >> 20);
    }

    if (IP6->NextHeader == IP_PROTOCOL_FRAGMENT) {
        FragmentHeader* FH;
        unsigned short upper_id, lower_id;
        unsigned int id;

        //
        // Translate the fragmentation information.
        //

        IP4->iph_length = net_short((short)(net_short(IP6->PayloadLength) + 
                                            sizeof(IPHeader) - 
                                            sizeof(FragmentHeader)));
        FH = (FragmentHeader*)(IP6 + 1);
        id = net_long(FH->Id);
        upper_id = (unsigned short)(id >> 16);
        lower_id = (unsigned short)(id);

        IP4->iph_id = net_short(lower_id);
        frag_off = net_short(FH->OffsetFlag);
        IP4->iph_offset =
            net_short((short)(((frag_off & 0x7) << 13) | (frag_off >> 3)));
        proto = FH->NextHeader;
    } else {
        IP4->iph_length = net_short((short)(net_short(IP6->PayloadLength) +
                                            sizeof(IPHeader)));
        IP4->iph_id = 0;
        IP4->iph_offset = net_short(0x4000);  // Set don't fragment bit.
        frag_off = 0;
        proto = IP6->NextHeader;
    }
    IP4->iph_ttl = IP6->HopLimit;
    IP4->iph_xsum = 0; 

    //
    // We will do either stateless or stateful address translation base
    // on the type of v6 address.
    //

    Stateful = 0;
    if ((IsV4Translated(&IP6->Source))||
        (icmpError && IsV4Mapped(&IP6->Source))){
        IP4->iph_src = IP6->Source.u.DWord[3];      
    } 
    else if ((IP6toIP4tbl != NULL) && 
            (IP6Get(IP6toIP4tbl, &IP6->Source, &IP4->iph_src))){
        //
        // v4 src address set in the Get operation.
        //
        Stateful = 1;
    } else {
        KdPrint(("NaptIP4toIP6: IP6 src to IP4 lookup failed "));
        return STATUS_UNSUCCESSFUL;
    }

    if ((IsV4Mapped(&IP6->Dest))||
        (icmpError && IsV4Translated(&IP6->Dest))){
        IP4->iph_dest = IP6->Dest.u.DWord[3];
    }
    else if ((IP6toIP4tbl != NULL) && 
            (IP6Get(IP6toIP4tbl, &IP6->Dest, &IP4->iph_dest))){
        //
        // v4 dest address set in the Get operation.
        //
        Stateful = 1;

    } else {
        KdPrint(("NaptIP4toIP6: IP6 dst to IP4 lookup failed\n"));
        return STATUS_UNSUCCESSFUL;
    }

    status = STATUS_SUCCESS;

    //
    // Compute the "len" that we need to bcopy.
    //
    len = net_short(IP4->iph_length) - sizeof(IPHeader);
    if (len < Length)
        Length = len;

    if (proto == IP_PROTOCOL_ICMPv6) {  // Not taken in the common case.

        //
        // ICMP requires special treatment.
        //

        IP4->iph_protocol = IP_PROTOCOL_ICMP;
        if ((frag_off & FRAGMENT_OFFSET_MASK) == 0) {
            //
            // Translate from ICMPv6 format to ICMPv4 format.
            //
            status = NaptIcmp6toIcmp4(IP6, IP4, ip6Payload, ip4Payload,
                                      Length, icmpError);
        } else {
            NaptCopyPayload(ip4Payload, ip6Payload, Length);
        }

        //
        // Compute csum of ip header after NaptIcmp6toIcmp4.
        //
        if (icmpError) {
            IP4->iph_xsum = ~Cksum(IP4, sizeof(IPHeader));
        }
    } else {
        IP4->iph_protocol = proto;
        if (icmpError) {
            IP4->iph_xsum = ~Cksum(IP4, sizeof(IPHeader));
        }

        NaptCopyPayload(ip4Payload, ip6Payload, Length);

        //
        // If its the first fragment or a non-fragment, and we are not
        // translating an icmp error message, and the translation is
        // stateful, then update the transport layer checksum value.
        //
        if (((frag_off & FRAGMENT_OFFSET_MASK)==0) && (Stateful)){
            switch (proto) {
            case IP_PROTOCOL_TCP: {
                TCPHeader *tcpHdr = ip4Payload;
                tcpHdr->tcp_xsum = NaptIP6toIP4Checksum(IP6, IP4,
                                                        tcpHdr->tcp_xsum);
                break;
            }

            case IP_PROTOCOL_UDP: {
                UDPHeader *udpHdr = (UDPHeader*)ip4Payload;
                udpHdr->Checksum = NaptIP6toIP4Checksum(IP6, IP4,
                                                        udpHdr->Checksum);
                break;
            } 

            default:
                //
                // Oops, it's a protocol that we currently do not support.
                // 
                KdPrint(("got unexpected protocol number: %x\n", proto));
                status = STATUS_UNSUCCESSFUL;

            }
        }
    }
    return STATUS_SUCCESS;
} // NaptIP6toIP4()


//* NaptIcmp6toIcmp4
//
//  Translates from icmpv6 to icmpv4 header format.  For error messages
//  it will translate the error causing IP6 header to IP4 that is
//  embedded in the payload of the icmpv6 packet.  For informational
//  messages the icmp payload is copied.
//
NTSTATUS
NaptIcmp6toIcmp4(
    IPv6Header UNALIGNED *IP6,
    IPHeader UNALIGNED *IP4,
    void* ip6Payload,
    void* ip4Payload,
    ushort Length,
    uint IcmpError)
{
    NTSTATUS status;
    ICMPv6Header *v6;
    ICMPv6Header icmpv6;
    ICMPHeader *v4;
    ULONG Offset;

    v4 = ip4Payload;
    v6 = ip6Payload;

    //
    // We copy the icmpv6 header into a local buffer, in case
    // ip6Payload and ip4Payload overlap or are identical.
    //
    RtlCopyMemory(&icmpv6, v6, sizeof *v6);
    v6 = &icmpv6;
  
    //
    // BUGBUG: Need to check icmp checksum before doing conversion.
    // 

    //
    // Skip over type, code, csum fields in icmp header.
    //
    Offset = sizeof(ulong);

    //
    // Translate icmp type, code and parameter field.
    //

    if (v6->Type == ICMPv6_ECHO_REQUEST) {
        v4->Type = ICMP_ECHO_REQUEST;
        v4->Code = 0;
        goto icmp_message_out;
    }
    else if (v6->Type == ICMPv6_ECHO_REPLY) {
        v4->Type = ICMP_ECHO_REPLY;
        v4->Code = 0;
        goto icmp_message_out;
    } else if (!IcmpError) {
#ifdef SHOULD_WE_DO_THIS // ??
        //
        // We can verify the v6 csum before continuing, as icmpv6
        // error message should never be fragmented.  Not sure if we
        // should be doing this or not. 
        //
        csum = CheckSumPacket(NULL, 0, ip6payload, Length,
                              IP6, IP_PROTOCOL_ICMPv6);
        if (csum != 0xffff) {
            KdPrint(("NaptIcmp6toIcmp4: Checksum failed 0x%x\n", csum));
            return STATUS_UNSUCCESSFUL;
        }
#endif //  SHOULD_WE_DO_THIS??
        switch (v6->Type) {
        case ICMPv6_DESTINATION_UNREACHABLE:
            v4->Type = ICMP_DEST_UNREACH;
            switch (v6->Code){
            case 0:
            case 3:
                v4->Code = HOST_UNREACH;
                break;
            case 1:
                v4->Code = HOST_ANO;
                break;
            case 2:
                v4->Code = SR_FAILED;
                break;
            case 4:
                v4->Code = PORT_UNREACH;
                break;
            default:
                // drop packet;
                return STATUS_UNSUCCESSFUL;
            }
            {
                uint UNALIGNED *v4unused;
                v4unused = (uint UNALIGNED*)(v4 + 1);
                *v4unused = 0;
            }
            goto icmp_error_out;

        case ICMPv6_PACKET_TOO_BIG:
            v4->Type = ICMP_DEST_UNREACH;
            v4->Code = 4;
            {
                uint *v6mtu = (uint*)(v6 + 1);
                uint *v4mtu = (uint*)(v4 + 1);
                // Adjust the MTU for the difference between an v4header and
                // (v6header + v6fragment).
                *v4mtu = net_long(net_long(*v6mtu) - (sizeof(IPv6Header) +
                                                      sizeof(FragmentHeader) -
                                                      sizeof(IPHeader)));
            }
            goto icmp_error_out;

        case ICMPv6_TIME_EXCEEDED:
            v4->Type = ICMP_TIME_EXCEEDED;
            v4->Code = v6->Code;
            {
                uint UNALIGNED *v4unused;
                v4unused = (uint UNALIGNED*)(v4 + 1);
                *v4unused = 0;
            }
            goto icmp_error_out;
    
        case ICMPv6_PARAMETER_PROBLEM:
            if (v6->Code = 1){
                uint UNALIGNED *v4unused;
                v4->Type = ICMP_DEST_UNREACH;
                v4->Code = PROT_UNREACH;
                v4unused = (uint UNALIGNED*)(v4 + 1);
                *v4unused = 0;

            } else {
                uint v6ptr;
                uchar *v4ptr;

                v4->Type = ICMP_PARAMETER_PROBLEM;
                v4->Code = 0;

                // Adjust the v4ptr field to the corresponding v6ptr field.
                v6ptr = net_long(*(uint*)(v6 + 1));
                v4ptr = (uchar*)(v4 + 1);

                if (v6ptr < sizeof(IPv6Header)){
                    switch (v6ptr) {
                    case 0:  // VersClassFlow -> iph_verlen.
                        *v4ptr = 0;
                        break;
                    case 4:  // PayloadLength -> iph_length.
                        *v4ptr = 2;
                        break;
                    case 6:  // NextHeader -> iph_protocol.
                        *v4ptr = 9;
                        break;
                    case 7:  // HopLimit -> iph_ttl.
                        *v4ptr = 8;
                        break;
                    case 8:  // Source -> iph_src.
                        *v4ptr = 12;
                        break;
                    case 24:  // Dest -> iph_dest.
                        *v4ptr = 16;
                        break;
                    default:
                        *v4ptr = 0xff;
                        break;
                    }
                } else {
                    *v4ptr = 0xff;
                }
            }
            goto icmp_error_out;

        default:
            // Drop packet.
            return STATUS_UNSUCCESSFUL;
        }
    } else {
        return STATUS_UNSUCCESSFUL;
    }

icmp_error_out:
    // Set payload length to min of the ip4 payload length
    // and what can fit into a icmp packet, and whatever
    // the caller passed in.
    {
        IPv6Header *errIP6;
        struct _errorHeader {
            IPv6Header IP;
            FragmentHeader Frag;
        } errorcausingIPHeader;
        IPHeader *errIP4;
        uchar *errIp6Payload = (uchar*)ip6Payload;
        uchar *errIp4Payload = (uchar*)ip4Payload;
        ushort errLength;

        //
        // Skip over the 4bytes that contain either the icmpv6
        // pointer, mtu, unused, etc. values.
        //
        Offset += sizeof(ulong);

        //
        // Update payload ptr to beginning of icmp data.
        //
        errIp6Payload += Offset;
        errIp4Payload += Offset;

        //
        // Ptr to IP6 header of the error causing packet.
        //
        errIP6 = (IPv6Header*) errIp6Payload;

        //
        // We copy the error causing IPv6 header into a local buffer,
        // in case errIp4Payload and errIp6Payload overlap.
        //
        RtlCopyMemory(&errorcausingIPHeader.IP, errIP6, sizeof(IPv6Header));
        if (errIP6->NextHeader == IP_PROTOCOL_FRAGMENT) {
            errIP6 = errIP6 + 1;
            RtlCopyMemory(&errorcausingIPHeader.Frag, errIP6,
                          sizeof (FragmentHeader));
        }
        errIP6 = (IPv6Header UNALIGNED*)&errorcausingIPHeader;

        //
        // Ptr to IP4 header that we will translate.
        //
        errIP4 = (IPHeader*) errIp4Payload;

        //
        // Update payload ptr to beginning of icmp data.
        //
        errIp6Payload += sizeof(IPv6Header);
        errIp4Payload += sizeof(IPHeader);

        //
        // Need to adjust the IPv4 payload length, because we are
        // shrinking the payload when converting the error causing
        // IPv6 header to an IPv4 header.
        //
        Length = net_short(IP4->iph_length);
        Length -= (sizeof(IPv6Header) - sizeof(IPHeader));
        if (errIP6->NextHeader == IP_PROTOCOL_FRAGMENT) {
            IP4->iph_length -= sizeof(FragmentHeader);
        }

        //
        // If length > ip + icmp + ip + 8 bytes of transport.
        //
        // BUGBUG: should use the ip header len field rather than
        // static ipv4 header size.
        //
        if (Length > ((2*sizeof(IPHeader)) + 2 * 8))
            Length = ((2*sizeof(IPHeader)) + 2 * 8);
        errLength = Length - sizeof(IPHeader);
        IP4->iph_length = net_short(Length);

        //
        // NOTE: The payload will be copied by NaptIP6toIP4 function.
        //
        status = NaptIP6toIP4(errIP6, errIP4, errIp6Payload, errIp4Payload,
                              errLength, TRUE);

        //
        // If successful in translation, then compute csum for icmpv4
        // header.
        //
        if (NT_SUCCESS(status)) {
            v4->Checksum = 0;
            v4->Checksum = ~Cksum(v4, Length);
        } else {
            KdPrint(("NaptIcmp6toIcmp4: IP header translation failed %x\n",
                     status));
        }
        return status;
    }

icmp_message_out:
    {
        //
        // We copy the payload and adjust the checksum for icmp echo/reply
        // messages.  The checksum adjustment algorithm is as follows:
        // csumA = CSUM(ipv6 src/dest/nextheader/payloadlength)
        // csumB = CSUM(icmpv6 type and code fields)
        // csumC = CSUM(icmpv4 type and code fields)
        // icmpv4->csum = icmpv6->csum - csumA - csumB + csumC;
        //

        uint csum;

        //
        // Deep copy the v6 payload to the v4 payload area.
        //
        NaptCopyPayload((void UNALIGNED*)(((uchar*)ip4Payload) + Offset),
                        (void UNALIGNED*)(((uchar*)ip6Payload) + Offset),
                        Length - Offset);

        //
        // Compute IP6 pseudo-header csum value.
        //
        csum = Cksum(&IP6->Source, sizeof(IPv6Addr) + sizeof(IPv6Addr));
        {
            register uint PayloadLength;
            PayloadLength = net_long(Length);
            csum += (PayloadLength >> 16) + (PayloadLength & 0xffff);
        }
        csum += (IP_PROTOCOL_ICMPv6 << 8);

        //
        // Need to fold 32bit csum -> 16bits before we can use it in the
        // "subtract" statement below.
        //
        csum = (csum >> 16) + (csum & 0xffff);
        csum += (csum >> 16);

        //
        // Subtract pseudo-header csum value from icmpv6 csum to get csum
        // value just over the icmp header and its data.
        //
        csum = (ushort)(~v6->Checksum) + (ushort)(~csum);

        //
        // Compute difference in v6/v4 type/code values:
        //   1) subtract v6 type/code values from csum.
        //   2) add v4 type/code values to csum.
        //
        csum += (ushort)(~(*(ushort *)&v6->Type));
        csum += (ushort)(*(ushort *)&v4->Type);

        //
        // Fold 32bit csum -> 16bits and convert to ones-complement.
        //
        csum = (csum >> 16) + (csum & 0xffff);
        csum += (csum >> 16);
        csum = (ushort)~csum;
        if (csum == 0)
            csum = 0xffff;
        v4->Checksum = csum;
        return STATUS_SUCCESS;
    }
} // NaptIcmp6toIcmp4


#if 0  // Nothing calls this?
//* NaptSendICMP6Err
//
//  Support to send ICMPv6 error packets.
//
void
NaptSendICMP6Err(
    IPv6Addr UNALIGNED *Dest,
    uchar Type,
    uchar Code,
    uint Param,
    uchar *Data,
    uint PayloadLength)
{
    PNDIS_PACKET Packet;
    uchar *Mem;
    uint MemLen;
    uint Offset;
    uint PayloadOffset;
    RouteCacheEntry *RCE;
    NeighborCacheEntry *NCE;
    NetTableEntry *NTE;
    IP_STATUS istatus;
    NTSTATUS status;
    IPv6Header *IP6;
    ICMPv6Header *icmp6;

    Offset = MaxLinkLevelHeader;
    PayloadOffset = Offset + sizeof(IPv6Header);
    if (Data) {
        PayloadLength += sizeof(ICMPv6Header) + sizeof(uint);
    } else {
        PayloadLength = sizeof(ICMPv6Header) + sizeof(uint);
    }
    MemLen = PayloadOffset + PayloadLength;
    status = NaptAllocateIP6Packet(&Packet, &Mem, MemLen);
    if (!NT_SUCCESS(status)) {
        KdPrint(("NaptSendICMP6Err: could not allocate packet\n"));
        return;
    }

    IP6 = (IPv6Header *)(Mem + Offset);
    IP6->VersClassFlow = IP_VERSION | 0;
    IP6->PayloadLength = net_short((short)PayloadLength);
    IP6->NextHeader = IP_PROTOCOL_ICMPv6;
    IP6->HopLimit = 255;
    IP6->Source = UnspecifiedAddr;
    IP6->Dest = *Dest;

    icmp6 = (ICMPv6Header*)(Mem + PayloadOffset);
    icmp6->Type = Type;
    icmp6->Code = Code;
    *((int*)&icmp6 + 1) = Param;
    icmp6->Checksum = 0;
    if (Data) {
        // Skip over the icmp header and parameter field.
        RtlCopyMemory((uchar*)(icmp6 + 2), Data, PayloadLength - 
                      sizeof(ICMPv6Header) - sizeof(uint));
    }
    istatus = RouteToDestination(&IP6->Dest, NULL, RTD_FLAG_NORMAL, &RCE);
    if (istatus != IP_SUCCESS) {
        KdPrint(("NaptSendICMP6Err: no route to v6 dest.\n"));
        goto release_packet;
    }
    NTE = RCE->NTE;
    IP6->Source = NTE->Address;

    icmp6->Checksum = ChecksumPacket(
        NULL, 0, (uchar*)icmp6, PayloadLength,
        &IP6->Source, &IP6->Dest, IP_PROTOCOL_ICMPv6);

    // Send packet.
    NCE = RCE->NCE;
    IPv6Send0(Packet, Offset, NCE, &NCE->IF->LinkLocalNTE->Address);
    return;

release_packet:
    IPv6FreePacket(Packet);  // Part of MSRIPv6.
} // NaptSendICMP6Err
#endif


//
// NAPT IP4 -> IP6 TRANSLATION CODE
//


//* NaptIP4toIP6Checksum
//
//  Computes the incremental checksum differences when converting from
//  an IPv4 to an IPv6 header.
//
ushort
NaptIP4toIP6Checksum(
    IPHeader UNALIGNED *IP4,
    IPv6Header UNALIGNED *IP6,
    ushort headcsum)
{
    uint csum, csum4;

    headcsum = ~headcsum;
    // Layer4 checksum + checksum over IP6 src/dst addrs.
    csum = headcsum + Cksum(&IP6->Source, 2 * sizeof(IPv6Addr));

    // Checksum over IP4 src/dest addrs.
    csum4 = 
        (((IP4->iph_src) >> 16) + ((IP4->iph_src) & 0xffff)) +
        (((IP4->iph_dest) >> 16) + ((IP4->iph_dest) & 0xffff));
    // Fold 32 bits -> 16 bits.
    csum4 = ((csum4 >> 16) & 0xffff) + (csum4 & 0xffff);
    csum4 += (csum4 >> 16);

    // Ones complement subtract.
    // csum = csum - csum4;
    csum = csum + (~csum4 & 0xffff);
    // Fold 32 bits -> 16 bits.
    csum = ((csum >> 16) & 0xffff) + (csum & 0xffff);
    csum += (csum >> 16);

    csum = (ushort) ~csum;
    if (csum == 0)
        csum = 0xffff;
    return csum;
} // NaptIP4toIP6Checksum()


//* NaptIP4toIP6
//
//  Assumes that packet is continguous.
//
NTSTATUS
NaptIP4toIP6(
    IPHeader UNALIGNED *IP4,
    IPv6Header UNALIGNED *IP6,
    void *ip4Payload,
    void *ip6Payload,
    ushort Length,
    uint icmpError)
{
    NTSTATUS status;
    uchar *nextHdrPtr;
    uint HopLimit;
    uint frag_info;
    uint fragment;
    uint len;
    uint Stateful;
    uint PayloadLength = Length;
    uint proto;

    //
    // Calc v6 hoplimit value from v4 ttl.
    //
    HopLimit = IP4->iph_ttl - 1;

    //
    // Set the IP6 version, traffic class and flow label.
    // Common case should be that tos = 0.
    //
    if (IP4->iph_tos == 0) {
        IP6->VersClassFlow = IP_VERSION | 0;
    } else {
        uint VersClassFlow = ((6 << 28) | (IP4->iph_tos << 20));
        IP6->VersClassFlow = net_long(VersClassFlow);
    }

    //
    // Extract frag offset information.
    //
    frag_info = net_short(IP4->iph_offset);

    //
    // Check if "more fragment" bit or frag offset are non-zero
    // OR if the "don't fragment" bit is NOT set.
    //
    // REVIEW: I think the common case is that the "don't fragment" bit is
    // REVIEW: NOT set, or it is a fragment part of a (udp) stream.
    //
    if (((frag_info & 0x4000) == 0) || ((frag_info & 0x3FFF) != 0)){
        // Adjust v6 length for fragment header.
        PayloadLength += sizeof(FragmentHeader);
        fragment = TRUE;
    } else {
        fragment = FALSE;
    }

    //
    // Set the payload length, which may have been extended by
    // 8 bytes above if we needed to add an extension header.
    //
    IP6->PayloadLength = net_short((ushort)PayloadLength);

    //
    // Set NextHeader and HopLimit fields using values computed above.
    //
    IP6->HopLimit = (uchar) HopLimit;

    //
    // Indicate that the tcp/udp checksum doesn't need adjustment.
    //
    Stateful = 0;

    //
    // Check if we have a mapping for the ip src addr.
    //
    if ((IP4toIP6tbl != NULL) &&
        (IP4Get(IP4toIP6tbl, &IP4->iph_src, &IP6->Source))){
        // Indicate that the tcp/udp checksum need adjustment.
        Stateful = 1;
    } else {
        // Use either a v4-translated or v4-mapped addr.
        IP6->Source.u.DWord[0] = 0;
        IP6->Source.u.DWord[1] = 0;
        if (!icmpError) {
            // Use v4-mapped prefix.
            IP6->Source.u.Word[4] = 0;
            IP6->Source.u.Word[5] = 0xffff;
        } else {
            // Use v4-translated prefix.
            IP6->Source.u.Word[4] = 0xffff;
            IP6->Source.u.Word[5] = 0;
        }
        IP6->Source.u.DWord[3] = IP4->iph_src;  // Already in net order.
    }

    //
    // Check if we have a mapping for the ip dest addr.
    //
    if ((IP4toIP6tbl != NULL) &&
        (IP4Get(IP4toIP6tbl, &IP4->iph_dest, &IP6->Dest))){
        // Indicate that the tcp/udp checksum need adjustment.
        Stateful = 1;
    } else {
        // Use either a v4-translated or v4-mapped addr.
        IP6->Dest.u.DWord[0] = 0;
        IP6->Dest.u.DWord[1] = 0;
        if (!icmpError) {
            // Use v4-translated prefix.
            IP6->Dest.u.Word[4] = 0xffff;
            IP6->Dest.u.Word[5] = 0;
        } else {
            // Use v4-mapped prefix.
            IP6->Dest.u.Word[4] = 0;
            IP6->Dest.u.Word[5] = 0xffff;
        }
        IP6->Dest.u.DWord[3] = IP4->iph_dest;  // Already in net order.
    }

    //
    // Do we need to propagate fragmentation information?
    //
    if (fragment){
        FragmentHeader *FH;
        uint Id;
        ushort OffsetFlag;

        //
        // This IP6 packet will contain a fragment header.
        //
        IP6->NextHeader = IP_PROTOCOL_FRAGMENT;

        //
        // Initialize the v6 fragment header values.
        //
        FH = (FragmentHeader*)(IP6 + 1);
        FH->Reserved = 0;
        OffsetFlag = ((frag_info & 0x1fff) << 3) |
            ((frag_info >> 13) & 0x0007);
        FH->OffsetFlag = net_short(OffsetFlag);
        Id = net_short(IP4->iph_id);
        FH->Id = net_long(Id);
        nextHdrPtr = &FH->NextHeader;
    } else {
        nextHdrPtr = &IP6->NextHeader;
    }

    //
    // Compute the "len" that we need to bcopy.
    //
    len = net_short(IP4->iph_length) - sizeof(IPHeader);
    if (len < Length)
        Length = len;

    //
    // Process higher layer packet.
    //
    proto = IP4->iph_protocol;

    if (proto == IP_PROTOCOL_ICMP){  // Not taken in the common case.

        //
        // ICMP requires a special treatment.
        //
        *nextHdrPtr = IP_PROTOCOL_ICMPv6;

        //
        // Convert icmp formats only if head- or non-fragment packet.
        //
        if ((frag_info & 0x1fff)==0) {
            ICMPv6Header *icmp6 = (ICMPv6Header*)ip6Payload;

            //
            // Translate from ICMPv4 format to ICMPv6 format.
            //
            return NaptIcmp4toIcmp6(IP4, IP6, ip4Payload, ip6Payload, 
                                    Length, icmpError);
        } else {
            NaptCopyPayload(ip6Payload, ip4Payload, Length);
        }

    } else {
        *nextHdrPtr = proto;
        //
        // Deep copy the v4 payload to the v6 payload area.
        //
        NaptCopyPayload(ip6Payload, ip4Payload, Length);

        //
        // Adjust checksum for head- or non-fragment packets.
        //
        if (((frag_info & 0x1fff)==0) && (Stateful)) {
            switch (proto) {
            case IP_PROTOCOL_TCP: {
                TCPHeader *tcpHdr = ip6Payload;
                tcpHdr->tcp_xsum = NaptIP4toIP6Checksum(IP4, IP6,
                                                        tcpHdr->tcp_xsum);
                break;
            }

            case IP_PROTOCOL_UDP: {
                UDPHeader *udpHdr = ip6Payload;
                udpHdr->Checksum = NaptIP4toIP6Checksum(IP4, IP6,
                                                        udpHdr->Checksum);
                break;
            }

            default:
                //
                // Oops, it's a protocol that we currently do not support.
                // 
                KdPrint(("got unexpected protocol number: %x\n", proto));
                return STATUS_UNSUCCESSFUL;

            }
        }
    }
    return STATUS_SUCCESS;
} // NaptIP4toIP6();


//* NaptIcmp4toIcmp6
//
//  Translates from icmpv4 to icmpv6 header format.  For error messages
//  it will translate the error causing IPv4 header to IPv6 header that
//  is embedded in the payload of the icmpv4 packet.  For informational
//  messages the icmp payload is copied.
//
NTSTATUS
NaptIcmp4toIcmp6(
    IPHeader UNALIGNED *IP4,
    IPv6Header UNALIGNED *IP6,
    void* ip4Payload,
    void* ip6Payload,
    ushort Length,
    uint IcmpError)
{
    NTSTATUS status;
    ICMPHeader UNALIGNED *v4;
    ICMPHeader icmpv4;
    ICMPv6Header UNALIGNED *v6;
    uint Offset;
    uint UNALIGNED *v6parameter;

    v6 = (ICMPv6Header UNALIGNED*)ip6Payload;
    v4 = (ICMPHeader UNALIGNED*)ip4Payload;

    //
    // We copy the icmpv4 header into a local buffer, in case
    // ip6Payload and ip4Payload overlap or are identical.
    //
    RtlCopyMemory(&icmpv4, v4, sizeof *v4);
    v4 = &icmpv4;

    //
    // BUGBUG: Need to check icmp checksum before doing conversion.
    // 

    //
    // Skip over type, code, csum fields in icmp header.
    //
    Offset = sizeof(ulong);

    if (v4->Type == ICMP_ECHO_REQUEST) {
        v6->Type = ICMPv6_ECHO_REQUEST;
        v6->Code = 0;
        goto icmp_message_out;
    }
    else if (v4->Type == ICMP_ECHO_REPLY) {
        v6->Type = ICMPv6_ECHO_REPLY;
        v6->Code = 0;
        goto icmp_message_out;
    }
    else if (!IcmpError) {
        //
        // BUGBUG: should verify v4 csum before continuing. 
        //
        switch (v4->Type){
        case ICMP_DEST_UNREACH:
            v6->Type = ICMPv6_DESTINATION_UNREACHABLE;
            switch (v4->Code) {
            case NET_UNREACH:
            case HOST_UNREACH: 
            case NET_UNKNOWN: 
            case HOST_UNKNOWN: 
            case HOST_ISOLATED: 
            case NET_UNR_TOS:
            case HOST_UNR_TOS:
                v6->Code = ICMPv6_NO_ROUTE_TO_DESTINATION;
                break;
            case PORT_UNREACH:
                v6->Code = ICMPv6_PORT_UNREACHABLE;
                break;
            case SR_FAILED:
                v6->Code = ICMPv6_ADDRESS_UNREACHABLE;
                break;
            case PROT_UNREACH: 
            { 
                uint* UNALIGNED v6ptr = (uint*)(v6 + 1);
                v6->Type = ICMPv6_PARAMETER_PROBLEM;
                v6->Code = ICMPv6_UNRECOGNIZED_NEXT_HEADER;

                //
                // Set pointer filed to "6".
                // "6" = octet offset to IPv6Header.NextHdr field.
                //
                *v6ptr = net_long(6); 
                goto icmp_error_out;
            }

            case FRAG_NEEDED:
            { 
                uint UNALIGNED *v6mtu = (uint UNALIGNED *)(v6 + 1);
                //
                // Need to change Type value for this error message.
                //
                v6->Type = ICMPv6_PACKET_TOO_BIG;
                v6->Code = 0;

                //
                // According to RFC 1191 5 we can't really trust this
                // ICMP error message.  So for now we'll just reduce
                // the path MTU to the IPv4 min MTU of 576.
                //
                // Hope that IPv6 implementations will handle this
                // case correctly.  The MSRIPv6 stack doesn't accept a
                // PathMTU < 1280, but it records info correctly to
                // always include a fragment header.
                //
                *v6mtu = net_long(576);
                goto icmp_error_out;
            }

            case NET_ANO:
            case HOST_ANO:
            default:
                v6->Code = ICMPv6_COMMUNICATION_PROHIBITED;
                break;
            }
            //
            // Ensure that the unused field is zero.
            //
            v6parameter = (uint UNALIGNED*)(v6 + 1);
            *v6parameter = 0;
            goto icmp_error_out;

        case ICMP_TIME_EXCEEDED:
            v6->Type = ICMPv6_TIME_EXCEEDED;
            v6->Code = v4->Code;
            v6parameter = (uint UNALIGNED*)(v6 + 1);
            *v6parameter = 0;
            goto icmp_error_out;

        case ICMP_PARAMETER_PROBLEM:
        {
            uint UNALIGNED *v6pointer;
            uint v4pointer;

            v6->Type = ICMPv6_PARAMETER_PROBLEM;
            v6->Code = 0;

            v6pointer = (uint UNALIGNED*)(v6 + 1);
            v4pointer = *(uchar*)(v4 + 1);
      
            if (v4pointer < sizeof(IPHeader)){
                switch (v4pointer) {
                case 0:  // iph_verlen -> VersClassFlow.
                    *v6pointer = 0; 
                    break;
                case 2:  // iph_length -> PayloadLength.
                    *v6pointer = net_long(4);
                    break;
                case 8:  // iph_ttl -> HopLimit.
                    *v6pointer = net_long(7);
                    break;
                case 9:  // iph_protocol -> NextHeader.
                    *v6pointer = net_long(6);
                    break;
                case 12:  // iph_src -> Source.
                    *v6pointer = net_long(8);
                    break;
                case 16:  // iph_dest -> Dest.
                    *v6pointer = net_long(24);
                    break;
                default:
                    // REVIEW: For now we'll blame the error on the
                    // 'versclassflow', though it may be something else.
                    *v6pointer = 0;
                    break;
                }
            } else {
                // REVIEW: the error pointer states that there is an
                // error in the transport layer header or possibly in
                // the ipv4 options.  We'll just blame it on the
                // 'versclassflow' field.
                *v6pointer = 0;
            }
        }
        goto icmp_error_out;
        default:
            // Indicate that we cannot translate this icmp packet.
            return STATUS_UNSUCCESSFUL;
        }
    } else {
        return STATUS_UNSUCCESSFUL;
    }

  icmp_error_out:
    // Set payload length to min of the ip4 payload length
    // and what can fit into a icmp packet, and whatever
    // the caller passed in.
    {
        IPHeader errorcausingIPHeader;
        IPHeader UNALIGNED *errIP4;
        IPv6Header UNALIGNED *errIP6;
        uchar *errIp4Payload = ip4Payload;
        uchar *errIp6Payload = ip6Payload;
        ushort errLength;
        ushort frag_info;

        //
        // Skip over the 4bytes that contain either the icmpv6
        // pointer, mtu, unused, etc. values.
        //
        Offset += sizeof(ulong);

        //
        // Update payload ptr to beginning of icmp data.
        //
        errIp4Payload += Offset;
        errIp6Payload += Offset;

        //
        // Ptr to IP4 header of error causing packet.
        //
        errIP4 = (IPHeader UNALIGNED*)errIp4Payload;

        //
        // We copy the error causing IPv4 header into a local buffer,
        // in case errIp4Payload and errIp6Payload overlap.
        //
        RtlCopyMemory(&errorcausingIPHeader, errIP4, sizeof *errIP4);
        errIP4 = &errorcausingIPHeader;

        //
        // Ptr to IP6 header that we will translate.
        //
        errIP6 = (IPv6Header UNALIGNED*)errIp6Payload;

        errIp4Payload += sizeof(IPHeader);
        errIp6Payload += sizeof(IPv6Header);

        //
        // Need to adjust the IPv6 payload length, because we are
        // expanding the payload when converting the error causing
        // IPv4 header to an IPv6 header.
        //
        Length = net_short(IP6->PayloadLength);
        Length += (sizeof(IPv6Header) - sizeof(IPHeader));
        frag_info = net_short(errIP4->iph_offset);
        if (((frag_info & 0x4000) == 0) || ((frag_info & 0x3FFF) != 0)){
            Length += sizeof(FragmentHeader);
        }

        //
        // BUGBUG: it really should be 576 - xxx (last minute fix).
        //
        if (Length > 500)
            Length = 500;
        IP6->PayloadLength = net_short(Length);

        if (IP6->NextHeader == IP_PROTOCOL_FRAGMENT) {
            Length -= sizeof(FragmentHeader);
        }

        //
        // NOTE: The error payload will be copied by NaptIP4toIP6 function.
        // errLength = total payload length - icmp6 header;
        //
        ASSERT(Length >= (sizeof(IPv6Header) + sizeof(ICMPv6Header) +
                          sizeof(ulong)));
        errLength = Length - (sizeof(IPv6Header) + sizeof(ICMPv6Header) +
                              sizeof(ulong));
        status = NaptIP4toIP6(errIP4, errIP6, errIp4Payload, errIp6Payload,
                              errLength, TRUE);
        if (NT_SUCCESS(status)){
            //
            // Calculate a new checksum for the icmpv6 pkt.
            //
            v6->Checksum = 0;
            v6->Checksum = ChecksumPacket(
                NULL, 0, ip6Payload, Length,
                &IP6->Source, &IP6->Dest, IP_PROTOCOL_ICMPv6);
        } else {
            KdPrint(("NaptIcmp4toIcmp6: IP header translation failed %x\n",
                     status));
        }
        return status;
    }

  icmp_message_out:
    {
        //
        // We copy the payload and adjust the checksum for icmp echo/reply
        // messages.  The checksum adjustment algorithm is as follows:
        // csumA = CSUM(ipv6 src/dest/nextheader/payloadlength)
        // csumB = CSUM(icmpv6 type and code fields)
        // csumC = CSUM(icmpv4 type and code fields)
        // icmpv6->csum = icmpv4->csum + csumA + csumB - csumC;
        //
        uint csum;

        // Deep copy the v4 payload to the v6 payload area.
        RtlCopyMemory(((uchar*)ip6Payload) + Offset,
                      ((uchar*)ip4Payload) + Offset,
                      Length - Offset);

        // Compute pseudo-header csum over IP6 src/dest.
        csum = Cksum(&IP6->Source, 2 * sizeof(IPv6Addr));
        csum += net_long(Length);
        csum += (IP_PROTOCOL_ICMPv6 << 8);

        // Add in v4 checksum over data.
        csum += (ushort)~v4->Checksum;

        // Compute difference in v4/v6 type/code values:
        //   1) subtract v4 type/code values from csum
        //   2) add v6 type/code values to csum
        csum += (ushort)(~(*(ushort*)&v4->Type));
        csum += (ushort)(*(ushort*)&v6->Type);

        // Fold 32bit csum -> 16bits and convert to ones-complement.
        csum = (csum >> 16) + (csum & 0xffff);
        csum += (csum >> 16);
        csum = (ushort)~csum;
        if (csum == 0)
            csum = 0xffff;

        v6->Checksum = csum;
        return STATUS_SUCCESS;
    }
} // NaptIcmp4toIcmp6


//* NaptSendICMP4Err
//
//  Support to send an Icmpv4 error packet.
//
void
NaptSendICMP4Err(
    in_addr Src,
    in_addr Dest,
    uchar Type,
    uchar Code, 
    uint Param,
    uchar *Data,
    uint DataLength)
{
    PNDIS_PACKET Packet;
    PNDIS_BUFFER Buffer;
    IPHeader UNALIGNED *IP4;
    ICMPHeader UNALIGNED *icmp4;
    NTSTATUS status;
    void *ip4Payload;
    uint MemLen;
    uint UNALIGNED *icmp4Param, *icmp4Data;

#define ICMP4_ERR_SIZE (sizeof(IPHeader) + sizeof(ICMPHeader) + sizeof(uint))
    if (Data) {
        DataLength += ICMP4_ERR_SIZE;
    } else {
        DataLength = ICMP4_ERR_SIZE;
    }
    status = NaptAllocateIP4Packet(&Packet, &Buffer, DataLength, &IP4);
    if (!NT_SUCCESS(status)) {
        KdPrint(("NaptSendICMP4Err couldn't allocate packet\n"));
        return;
    }

    //
    // Setup the IP4 header that's going to carry back the icmp error message.
    // REVIEW: What should our source address be?
    //
    IP4->iph_verlen = IP_DEFAULT_VERLEN;
    IP4->iph_tos = 0;
    IP4->iph_length = net_short((short)DataLength);
    IP4->iph_id = 0;
    IP4->iph_offset = 0;
    IP4->iph_ttl = 255;
    IP4->iph_protocol = IP_PROTOCOL_ICMP;
    IP4->iph_xsum = 0;
    IP4->iph_src = Src;
    IP4->iph_dest = Dest;  

    NdisQueryBuffer(Buffer, &icmp4, &MemLen);
    icmp4->Type = Type;
    icmp4->Code = Code;
    icmp4Param = (uint UNALIGNED *)icmp4 + 1;
    *icmp4Param = Param;
    icmp4->Checksum = 0;

    if (Data) {
        //
        // Skip over the parameter field and copy in the icmp err
        // message data.
        //
        icmp4Data = icmp4Param + 1;
        RtlCopyMemory(icmp4Data, Data, DataLength - ICMP4_ERR_SIZE);
    }

    //
    // Calculate csum over icmp header and its data.
    // NOTE: for icmp4 we do not do pseudo-header csum.
    //
    icmp4->Checksum = ~Cksum(icmp4, DataLength - sizeof(IPHeader));

    //
    // Send the IP4 packet.
    //
    NaptSendIP4Packet(IP4, Packet, Buffer);

} // NaptSendICMP4Err()


//* NaptIP4PacketFilter
//
//  Checks if an IP4 address falls within one of the
//  IP4 address ranges that the NAPT is supposed to handle.
//
//  The implementation is a binary search on a sorted array of IP4
//  {address, range} pairs.
//
//  Assumes that the ip4f filter array datastructure is always
//  non-NULL.
//
__inline
static int  // Returns: 1 if found, 0 otherwise.
NaptIP4PacketFilter(
    struct NaptIP4Filter* ip4f,
    int numentries,
    unsigned int addr)
{
    int lo, hi, mid;

    // Binary search the region array.
    lo = 0;
    hi = numentries - 1;

    // DbgPrint("NaptIP4PacketFilter %x\n", addr);

    while (1) {
        if (lo > hi) return 0;

        mid = (lo + hi) / 2;
        if (addr < ip4f[mid].lower) {
            hi = mid - 1;
            // DbgPrint("miss mid=%d %x<%x\n", mid, addr, ip4f[mid].lower);
        } 
        else if (addr <= ip4f[mid].upper) {
            // DbgPrint("hit mid=%d %x<=%x\n", mid, addr, ip4f[mid].upper);
            return 1;
        } else {
            // DbgPrint("miss mid=%d %x>%x\n", mid, addr, ip4f[mid].upper);
            lo = mid + 1;
        }
    }
}


//* NaptIP4Receive
//
//  NaptIP4Receive - Receive an incoming IPv4 datagram.
//  Returns: Reference count of packets held.
//
int
NaptIP4Receive(
    void *MyContext,
    PNDIS_PACKET ip4Packet,
    uint Position,
    void *InitialData,
    uint InitialSize,
    uint TotalSize)
{
    NTSTATUS status;
    IP_STATUS istatus;

    PNDIS_PACKET Packet;
    uchar *Mem;
    uint MemLen;
    uint Offset;

    RouteCacheEntry *RCE;
    NeighborCacheEntry *NCE;

    uint FragInfo, FragmentOK;
    uint len; 
    uint PathMTU;
    uint PacketLength;
    uint PayloadLength;
    uint PayloadOffset;
    uint HopLimit;
    uint HeaderLength;  // Length in bytes if header.

    IPHeader UNALIGNED *IP4;
    void *ip4Payload;
    IPv6Header UNALIGNED *IP6;
    void *ip6Payload;
    in_addr daddr;

    IP4 = (IPHeader UNALIGNED *) InitialData;
    daddr = net_long(IP4->iph_dest);

    // Filter out broadcast addresses, as we don't translate those.
    if ((daddr & 0xff) != 0xff) {
        // Range check based on user-provided information.
        if (NaptIP4PacketFilter(naptIP4Filter, numNaptIP4Filters, daddr)){

            HeaderLength = (IP4->iph_verlen & IP_HEADER_MASK) << 2;

            //
            // Only plain IPv4 packets are translated.  Drop packet if
            // IPv4 header size is larger than 20 bytes.
            //
            if (HeaderLength != sizeof(IPHeader))
                return 0;

            //
            // Check if hop limit has been reached.
            //
            if ((IP4->iph_ttl - 1) == 0) {

                //
                // Double check to make sure it's an initial fragment.
                //
                if ((IP4->iph_offset & IP_OFFSET_MASK) != 0)
                    return 0;

                //
                // Don't send error message for icmp packets.
                //
                if (IP4->iph_protocol == IP_PROTOCOL_ICMP) {
                    ICMPHeader UNALIGNED *icmp;
                    icmp = (ICMPHeader UNALIGNED *)((uchar *)IP4 +
                                                    HeaderLength);
                    // Unless it is a icmp echo request packet.
                    if (icmp->Type != ICMP_ECHO_REQUEST)
                        return 0;
                }
                NaptSendICMP4Err(IP4->iph_dest,
                                 IP4->iph_src,
                                 ICMP_TIME_EXCEEDED,
                                 EXC_TTL,
                                 0,
                                 (uchar*)IP4,
                                 HeaderLength + 8);
                return 0;
            }

            //
            // Calculate the payload length.
            //
            PayloadLength = net_short(IP4->iph_length) - HeaderLength;
            Offset = MAX_LINK_HEADER_SIZE;
            PayloadOffset = Offset + sizeof(IPv6Header);

            //
            // Extract fragmentation offset information.
            //
            FragInfo = net_short(IP4->iph_offset);
    
            //
            // Check if "more fragment" bit or fragmentation offset
            // are non-zero OR if the "don't fragment" bit is NOT set.
            //
            if (((FragInfo & 0x4000) == 0) || ((FragInfo & 0x3FFF) != 0)){
                //
                // Adjust the PayloadOffset to account for the length
                // of the IPv6 fragment header.
                //
                PayloadOffset += sizeof(FragmentHeader);
                FragmentOK = TRUE;
            } else {
                FragmentOK = FALSE;
            }

            //
            // Calculate the overall buffer size necessary for the IPv6
            // header(s), payload data and allocate the packet.
            //
            MemLen = PayloadOffset + PayloadLength;

            //
            // BUGBUG: pad the buffer in case we need to expand
            // payload for icmp6 error messages.  I don't like this,
            // but other solutions requires a reorganization of code.
            //
            if (MemLen < (IPv6_MINIMUM_MTU - 32)) {
                MemLen += 32;
            }
            status = NaptAllocateIP6Packet(&Packet, &Mem, MemLen);
            if (!NT_SUCCESS(status))
                goto out;

            IP6 = (IPv6Header *)(Mem + Offset);
            ip6Payload = (void*)(Mem + PayloadOffset);
            ip4Payload = (void*)(IP4 + 1);

            //
            // Translate v4 packet to v6 packet. 
            //
            status = NaptIP4toIP6(IP4, IP6, ip4Payload, ip6Payload,
                                  (ushort)PayloadLength, FALSE);
            if (!NT_SUCCESS(status))
                goto release_packet;

            //
            // Obtain a routecacheentry (RCE) to the IPv6 destination.
            // REVIEW: Assumes the v6 destination is not scoped.
            //
            istatus = RouteToDestination(&IP6->Dest, 0, NULL, RTD_FLAG_NORMAL,
                                         &RCE);
            if (istatus != IP_SUCCESS) {
                KdPrint(("NaptIP4Receive: no route to v6 dest.\n"));
                goto release_packet;
            }

            //
            // Drop the packet if the interface we are about to send
            // on is the napt interface.
            //
            if (RCE->NCE->IF == NaptInterface) {
                ReleaseRCE(RCE);
                KdPrint(("NaptIP4Receive: cannot route to napt v6 IF.\n"));
                goto release_packet;
            }

            //
            // Check the path's MTU.  If the packet is larger than the
            // PMTU, then fragment accordingly.
            //
            PacketLength = PayloadLength + sizeof(IPv6Header);
            PathMTU = GetPathMTUFromRCE(RCE);
            if (PacketLength > PathMTU) {
                if (FragmentOK) {
                    NaptIP6SendFragments(Packet, Offset, IP6,
                                         PayloadLength, RCE, PathMTU);
                } else {
                    //
                    // We wont be sending on the IPv6 RCE, as we are
                    // going to generate an ICMPv4 error packet.  Can
                    // just go ahead and release the RCE now.
                    //
                    ReleaseRCE(RCE);

                    //
                    // The IPv4 packet has the "don't fragment" bit
                    // set.  Need to send an ICMPv4 packet indicating
                    // the PathMTU to the IPv4 sender.  The v4 PathMTU
                    // that we ship back is the v6 PathMTU, but also
                    // accounting for the size difference of the IP
                    // headers.
                    //
                    ASSERT(PathMTU > (sizeof(IPv6Header) +
                                      sizeof(FragmentHeader) -
                                      sizeof(IPHeader)));
                    PathMTU = PathMTU - (sizeof(IPv6Header) +
                                         sizeof(FragmentHeader) -
                                         sizeof(IPHeader));
                    PathMTU = net_long(PathMTU);
                    NaptSendICMP4Err(IP4->iph_dest,
                                     IP4->iph_src,
                                     ICMP_DEST_UNREACH,
                                     FRAG_NEEDED,
                                     PathMTU,
                                     (uchar*)IP4,
                                     HeaderLength + 8);
                    
                    goto release_packet;
                }
            } else {
                NCE = RCE->NCE;
                IPv6Send0(Packet, Offset, NCE,
                          &NCE->IF->LinkLocalNTE->Address);
            }
            ReleaseRCE(RCE);
            return 1;
        }
    }

out:
    return 0;

release_packet:
    IPv6FreePacket(Packet);  // Part of MSRIPv6.
    return 0;
}

//
// Support to hook napt as an interface into the IPv6 code.  We are
// going to create an Interface and a NCE that we register with the
// IPv6 code, which will call us when it forwards a packet that needs
// to be translated.
//


//* NaptIP6Receive
//
void
NaptIP6Receive(
    void *Context,              
    PNDIS_PACKET Packet,        // Pointer to packet to be transmitted.
    uint Offset,                // Offset from start of packet to IPv6 header.
    void *LinkAddress)          // Link-level address.
{
    PNDIS_BUFFER Buffer;
    VOID *VirtAddr;
    UINT BufLen, TotLen;
    IPv6Header UNALIGNED *IP6;
    IPHeader UNALIGNED *IP4;
    uint PayloadLength;
    uint PayloadOffset;
    void* ip4Payload;
    void* ip6Payload;
    NTSTATUS status;
    NDIS_STATUS nstatus;
    PNDIS_PACKET IP4Packet;
    PNDIS_BUFFER IP4Header;
    PNDIS_BUFFER IP4Buffer;
    uint Unused, sawFragment = FALSE;

    uchar *tbuf;
    uchar HdrType;

    NdisGetFirstBufferFromPacket(Packet, &Buffer, &VirtAddr, &BufLen, &TotLen);

    if (BufLen < Offset + sizeof(IPv6Header)) {
        IPv6FreePacket(Packet);
        return;
    }


    IP6 = (IPv6Header UNALIGNED *)((uchar *)VirtAddr + Offset);
    PayloadLength = net_short(IP6->PayloadLength);
    PayloadOffset = sizeof(IPv6Header);

    //
    // Walk down the nextheader fileds and make sure that we are not
    // dealing with any options, routing, security, authentication,
    // etc. heades.  Only icmp, tcp, udp, and fragment next header
    // fields are currently supported by the translator.  
    //
    HdrType = IP6->NextHeader;
    tbuf = (uchar*)(IP6 + 1);

    while (1) { // Should go through this loop at most twice.
        if ((HdrType == IP_PROTOCOL_TCP) ||
            (HdrType == IP_PROTOCOL_UDP) ||
            (HdrType == IP_PROTOCOL_ICMPv6)) {
            break; // ok to translate
        }
        else if (HdrType == IP_PROTOCOL_FRAGMENT) {
            ExtensionHeader UNALIGNED *EHdr;
    
            //
            // Sanity check - an malicious sender might stick more
            // than one fragment header into this packet.
            //
            if (sawFragment) {
                IPv6FreePacket(Packet);
                return;
            }
            sawFragment = TRUE;

            //
            // Adjust the payload length/offset to account for
            // fragment header.
            //
            PayloadLength -= sizeof(FragmentHeader);
            PayloadOffset += sizeof(FragmentHeader);

            EHdr = (ExtensionHeader UNALIGNED*)tbuf;
            HdrType = EHdr->NextHeader;
            tbuf += ((EHdr->HeaderExtLength + 1) * 8);
        } else {

            //
            // Encountered a protocol, option or extension header that we
            // cannot translate.  So we just drop the packet here.
            //
            IPv6FreePacket(Packet);
            return;
        }
    }

    //
    // The code currently assumes that the packet forwarded from the
    // IPv6 stack is contiguous.
    //
    ASSERT(BufLen == TotLen);

    //
    // BUGBUG: Need to clean this up so that it works with the
    // ippriv.c version of NaptAllocateIP4Packet.
    //
    status = NaptAllocateIP4Packet(&IP4Packet, 0, 0, &IP4);
    if (!NT_SUCCESS(status)) { 
        IPv6FreePacket(Packet);
        return;
    }

    //
    // Remember the original ndis packet given to us by the MSRIPv6
    // stack.  We'll need to free it, its ndis buffers, and associated
    // memory later.
    //
    NAPTPC(IP4Packet)->OrigPacket = Packet;

    //
    // Allocate the ndis buffer that will point at the ip6Payload.
    // This buffer will be used as the ip4Payload.  It is OK for the
    // translation to scribble over this data.
    //
    ip6Payload = (void*)(((uchar*)IP6) + PayloadOffset);
    ip4Payload = ip6Payload;
    NdisAllocateBuffer(&nstatus, &IP4Buffer, NaptBufferPool,
                       ip4Payload, PayloadLength);
    if (nstatus != NDIS_STATUS_SUCCESS) {
        NaptFreeIP4Packet(IP4Packet);
        return;
    }

    //
    // Chain the payload data at the end of the ip4 ndis packet.
    //
    NdisChainBufferAtBack(IP4Packet, IP4Buffer);

    //
    // Do the translation of the IP headers.  May also update the csum
    // fields for udp/tcp, and replace the icmp headers.  Finally, the
    // overall size of the packet may shrink if we are translating an
    // icmp error message.
    //
    status = NaptIP6toIP4(IP6, IP4, ip6Payload, ip4Payload,
                          (ushort)PayloadLength, FALSE);

    if (NT_SUCCESS(status)) {
        //
        // The translation succedded and we can go ahead and send this
        // packet.
        //
        NaptSendIP4Packet(IP4, IP4Packet, IP4Buffer);
    } else {
        NaptFreeIP4Packet(IP4Packet);
    }
}


//* NaptClosePseudoInterface
//
//  The IPv6 layer calls this function to close a connection to an interface.
//  For this pseduo interface, we really don't have any "link-layer" state to
//  clean up.  All we do is drop our pointer to the Interface, if we have one.
//
void
NaptClosePseudoInterface(void *Context)
{
    //
    // Check to see if we're closing down as a result of Napt unloading,
    // or if the IPv4 stack has told us to go away.
    //
    if (NaptUnloading == FALSE) {

        //
        // IPv6 stack is deleting this interface.
        // Stop Napt as well.  Note that this causes this routine to reenter.
        //
        DriverUnload(NaptDriverObject);
    }

    //
    // If we're still holding on to our NeighborCacheEntry, drop it now.
    // REVIEW: Do we need to guard against multiple instances of this call?
    //
    if (NaptNCE != NULL) {
        ReleaseNCE(NaptNCE);
        NaptNCE = NULL;
    }

    //
    // If we're still holding on to our Interface pointer, drop it now.
    // REVIEW: Do we need to guard against multiple instances of this call?
    //
    if (NaptInterface != NULL) {
        ReleaseInterface(NaptInterface);
        NaptInterface = NULL;
    }
}


//* NaptCreatePseudoInterface
//
//  Creates a pseudo-interface used by IPv6 code to send on.
//
//  Support to hook napt as an interface into the IPv6 code.  We are
//  going to create an Interface and a NCE that we register with the
//  IPv6 code, which will call us when it forwards a packet that needs
//  to be translated.
//
//  REVIEW: There is only one such pseudo-interface, so we could use
//  REVIEW: statically allocated memory.  But we don't for some reason.
//
//  REVIEW: Could we just call the IPv6 stack's CreateInterface here and
//  REVIEW: clean up the things it does that we don't like?
//
Interface *
NaptCreatePseudoInterface(void)
{
    Interface *IF;
    NetTableEntry *NTE;

    IF = ExAllocatePool(NonPagedPool, sizeof(Interface));
    if (IF == NULL) {
        return NULL;
    }
    RtlZeroMemory(IF, sizeof(Interface));

    IF->IF = IF;

    //
    // Start with one reference for being an active interface,
    // and one reference for ourselves (this routine returns an Interface).
    //
    IF->RefCnt = 2;

    //
    // REVIEW: What should we use this for in the future?
    //
    IF->LinkContext = NULL;

    //
    // The NaptTransmit function will try to translate the IPv6 packet
    // to a IPv4 packet.
    // REVIEW: how do we indicate a failure in sending/translating
    // this packet?
    //
    IF->Transmit = NaptIP6Receive;

    //
    // The IPv6 stack will call this routine when it wants us to release
    // all interest we have in this interface.
    //
    IF->Close = NaptClosePseudoInterface;

    IF->Site = 1;  // Arbitrary.

    //
    // Enable forwarding on this interface, and disable Neighbor Discovery.
    // Since we only forward to, and not from, this interface, the
    // forwarding flag doesn't actually matter, but it looks good.
    //
    IF->Flags = IF_FLAG_FORWARDS;

    //
    // Even though we don't source packets from this inteface, it needs
    // to have an NTE in order for RouteToDestination to work when the
    // IPv6 stack wants to foward packets to it.  And while technically
    // we don't need a LinkLocalNTE on Interface's that don't participate
    // in Neighbor Discovery, the code makes more sense to have one.
    //
    // So accomplish both of these goals by creating a link-local address
    // on this interface.  We use a hardwired value of which the lower 64
    // bits are completely arbitrary.
    //
    // NOTE: CreateNTE also creates a route for this address, but via the
    // loopback interface!  So Napt won't receive packets at this address.
    //
    NTE = CreateNTE(IF, &IFLinkLocalAddr, FALSE,
                    INFINITE_LIFETIME, INFINITE_LIFETIME);
    if (NTE == NULL) {
        KdPrint(("Napt: Couldn't create LinkLocalNTE\n"));
        goto Fail;
    }
    IF->LinkLocalNTE = NTE;
    ReleaseNTE(NTE);

    // 
    // Initialise our Neighbor Cache Entry bookkeeping.
    //
    NeighborCacheInit(IF);

    //
    // Set MTU to a large value.  We want all packets to be forwarded
    // to us.  Packets will either be rejected if they do not have a
    // fragment header and the pathMTU is less than the linkMTU, or
    // they will be fragmented by the IPv4 send code.
    //
    IF->LinkMTU = IF->TrueLinkMTU = 0xffff;  // Something large.

    //
    // Use maximum hoplimit allowed.
    // Since we don't source packets from this interface, this isn't used.
    //
    IF->CurHopLimit = 0xff;

    //
    // Set up a dummy linkaddress.
    // I don't think this is actually used either.
    //
    IF->LinkAddressLength = 0;
    IF->LinkAddress = (uchar *) &UnspecifiedAddr;  // Dummy.

    //
    // Initialize spin lock before anyone else uses it.
    // 
    KeInitializeSpinLock(&IF->Lock);

    //
    // Setup the IPSec related stuff.
    //
    {
        extern void DefaultSPforIF(Interface *IF);
        DefaultSPforIF(IF);
    }

    //
    // Create a permanent neighbor cache entry for the translator.
    // This makes the translator appear as a translating router hanging
    // off of the NaptInterface.
    //
    NaptNCE = CreatePermanentNeighbor(IF, &NaptLinkLocalAddr, NULL);
    if (NaptNCE == NULL) {
        KdPrint(("Napt: Couldn't create LinkLocalNTE\n"));
        goto Fail;
    }

    //
    // Add the pseudo-interface to the global list of interfaces.
    //
    AddInterface(IF);

    return IF;

  Fail:
    // BUBUG: Cleanup is tricky...
    return NULL;
}


//* NaptStart
//
//  Called when the translator is loaded.
//
void
NaptStart(void)
{
    //
    // Create the Interface to hook into the MSRIPv6 forwarding
    // support.
    //
    NaptInterface = NaptCreatePseudoInterface();
    if (NaptInterface == NULL) {
        KdPrint(("Napt: Failed to create translator Interface\n"));
    }

    //
    // Initialize mapping table.
    //
    IP6toIP4tbl = Init(NEW(HashTable, 1), 0, 0);
    IP4toIP6tbl = Init(NEW(HashTable, 1), 0, 0);
  
    //
    // Initialize support for sending IP4 packet.
    //
    NaptIP4Init();

    //
    // Read settings from the Registry.
    //
    NaptReadRegistry();
}


//* NaptStop
//
//  Called when the translator is unloaded.
//
void
NaptStop(void)
{
    //
    // Clean up the v6<->v4 mapping tables.
    //
    if (IP6toIP4tbl){
        KdPrint(("NaptStop: Disposing IP6toIP4tbl\n"));
        Dispose(IP6toIP4tbl);
    }
    if (IP4toIP6tbl){
        KdPrint(("NaptStop: Disposing IP4toIP6tbl\n"));
        Dispose(IP4toIP6tbl);
    }

    //
    // Clean out the IF from the IPv6 datastructures.
    //
    if (NaptInterface != NULL)
        DestroyInterface(NaptInterface);

    //
    // Give the IPv4 send support a chance to uninstall itself.
    //
    NaptIP4UnInit();

} // NaptStop
