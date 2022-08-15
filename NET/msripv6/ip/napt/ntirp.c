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

#include <oscfg.h>
#include <ndis.h>
#include <ip6.h>
#include <ip6imp.h>
#include <ip6def.h>
#include <ntddip6.h>
#include "route.h"
#include "icmp.h"
#include "neighbor.h"
#include "ntreg.h"

#include "naptdef.h"
#include "ntddnapt.h"

extern NaptIP4Filter naptIP4Filter[];
extern int numNaptIP4Filters;


//* AddDropMapping
//
NTSTATUS
AddDropMapping(NaptMapping UNALIGNED *Map, uint AddorDrop)
{
    if (AddorDrop == 0) {
        //
        // Don't insert v4 translated|mapped addresses into
        // addr-map table.
        //
        if ((IsV4Translated(&Map->ip6addr) ||
            (IsV4Mapped(&Map->ip6addr)))) {
            return STATUS_INVALID_PARAMETER_1;
        }
        IP6Put(IP6toIP4tbl, &Map->ip6addr, &Map->ip4addr);
        IP4Put(IP4toIP6tbl, &Map->ip4addr, &Map->ip6addr);
    }
    else {
        IP6Del(IP6toIP4tbl, &Map->ip6addr, &Map->ip4addr);
        IP4Del(IP4toIP6tbl, &Map->ip4addr, &Map->ip6addr);
    }
    return STATUS_SUCCESS;
}


//* iterIP4toIP6
//
static void
iterIP4toIP6(in_addr *ip4, in6_addr *ip6, void *context){
    struct Context {
        void *oBuf;
        int numEntry;
    } *Context = context;
    NaptMapping* mapping;

    mapping = (NaptMapping*)Context->oBuf;
    mapping += Context->numEntry;
    mapping->ip6addr = *ip6;
    mapping->ip4addr = *ip4;
    Context->numEntry++;
} // iterIP4toIP6


//* iterIP6toIP4
//
static void
iterIP6toIP4(in6_addr *ip6, in_addr *ip4, void * context){
    struct Context {
        void *oBuf;
        int numEntry;
    } *Context = context;
    NaptMapping* mapping;

    mapping = (NaptMapping*)Context->oBuf;
    mapping += Context->numEntry;
    mapping->ip6addr = *ip6;
    mapping->ip4addr = *ip4;
    Context->numEntry++;
} // iterIP6toIP4


//* ip4strcmp
//
// Compare two NaptIP4Filter entries. This is used by insertionsort.
//
static
int ip4strcmp(NaptIP4Filter *i, NaptIP4Filter *j)
{
    if ((i)->lower < (j)->lower)
        return -1;
    else if ((i)->lower > (j)->lower)
        return 1;
    else if ((i)->upper < (j)->upper)
        return -1;
    else if ((i)->upper > (j)->upper)
        return 1;
    else
        return 0;
}


//* insertionsort
//
// Insert an entry into the NaptIP4Filter array.  Compact overlapping
// or adjacent entries.
//
static int
insertionsort(NaptIP4Filter *tbl, int n, int (*cmp)())
{
    int i, j;
    NaptIP4Filter *pl, *pm;
    NaptIP4Filter temp;

    // Insertion sort.
    for (pm = tbl + 1; pm < tbl + n; pm++) {
        for (pl = pm; pl > tbl && cmp(pl - 1, pl) > 0; pl--) {
            temp = *pl;
            *pl = *(pl - 1);
            *(pl - 1) = temp;
        }   
    }

    // Eliminate overlapping/adjacent entries.
    for (i = 1; i < n; i++) {
        unsigned int cur = i - 1;
        unsigned int a, b, c;

        a = tbl[cur].upper;
        b = tbl[i].lower;
        c = tbl[i].upper;

        // Check if there is an overlap/adjacent entry.
        while ((tbl[cur].upper >= (tbl[i].lower - 1)) && (i < n) && (n > 1)) {
            // Check if there is an overlap.
            if (tbl[cur].upper < tbl[i].upper) {
                // Raise upper to the next region.
                tbl[cur].upper = tbl[i].upper;
            }
            // Copy everything up one entry.
            for (j = i + 1; j < n; j++)
                tbl[j - 1] = tbl[j];

            n--;
        }
    }
    return n;
}


//* AddIP4Filter
//
NTSTATUS
AddIP4Filter(NaptIP4Filter *Filter)
{
    NTSTATUS Status;
    if (numNaptIP4Filters + 1 < 128) {
        naptIP4Filter[numNaptIP4Filters].lower = net_long(Filter->lower);
        naptIP4Filter[numNaptIP4Filters].upper = net_long(Filter->upper);
        numNaptIP4Filters = 
            insertionsort(naptIP4Filter,
                          numNaptIP4Filters + 1,
                          ip4strcmp);
        Status = STATUS_SUCCESS;
    }
    else {
        Status = STATUS_INSUFFICIENT_RESOURCES;
    }

    return Status;
}


//* DelIP4Filter
//
NTSTATUS
DelIP4Filter(NaptIP4Filter *Filter)
{
    return STATUS_NOT_IMPLEMENTED;
}


//
// Registry Processing functions.
//
// Our configuration values live under this key:
//
WCHAR RegKeyNameParam[] = L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Napt\\Parameters";


//* StatelessV4RangeFiltersConfiguration
//
//  Attempt stateless translation configuration.
//
NTSTATUS
StatelessV4RangeFiltersConfiguration(HANDLE RegKeyParam)
{
    WCHAR *Address, *Terminator;
    NaptIP4Filter Filter;
    UNICODE_STRING MultiSZ;
    NTSTATUS Status;
    uint Index;
#if DBG
    char DebugBuffer[96];
#endif

    MultiSZ.Length = MultiSZ.MaximumLength = 0;
    MultiSZ.Buffer = NULL;

    //
    // Look for the value "StatelessV4RangeFilters".
    //
    Status = GetRegMultiSZValue(RegKeyParam, L"StatelessV4RangeFilters",
                                &MultiSZ);
    if (NT_SUCCESS(Status) && (MultiSZ.Buffer != NULL)) {
        //
        // Entry exists.  Each line should contain two IPv4 addresses,
        // which bound a filter range.  Add a filter for each line.
        //
        for (Index = 0; ; Index++) {
            Address = EnumRegMultiSz(MultiSZ.Buffer, MultiSZ.Length + 1,
                                     Index);
            if (Address == NULL)
                break;

            if (!ParseV4Address(Address, &Terminator, &Filter.lower)) {
                KdPrint(("\tfailed to read lower v4 address\n"));
                break;
            }
#if DBG
            FormatV4AddressWorker(DebugBuffer, Filter.lower);
            KdPrint(("StatelessTranslationV4Range [%s,", DebugBuffer));
#endif
            Address = Terminator;
            while (*Address == L' ')
                Address++;

            Filter.upper = Filter.lower;
            if (!ParseV4Address(Address, &Terminator, &Filter.upper)) {
                KdPrint(("\tfailed to read upper v4 address\n"));
                break;
            }
#if DBG
            FormatV4AddressWorker(DebugBuffer, Filter.upper);
            KdPrint(("%s]\n", DebugBuffer));
#endif
            Status = AddIP4Filter(&Filter);
            if (!NT_SUCCESS(Status))
                return Status;
        }

        //
        // Since we succeeded in configuring ourselves with IPv4 addresses
        // ranges to translate to v6, we'll want to also configure ourselves
        // to snag IPv6 packets to translate to v4.  Unlike the IPv4 ranges,
        // which must be individually specified, all the IPv6 packets we want
        // will have the IPv4-mapped prefix.
        //
        // Install a route to direct all packets with IPv4-mapped destination
        // addresses to the translator.
        //
        KdPrint(("TRUE = %d\n", TRUE));
        RouteTableUpdate(NaptInterface, NaptNCE, &V4MappedPrefix, 96, 0,
                         INFINITE_LIFETIME, 0, TRUE, FALSE);
    }

    return STATUS_SUCCESS;
}


//* StatefulTranslationMappingConfiguration
//
//  Attempt stateful translation configuration.
//
NTSTATUS
StatefulTranslationMappingConfiguration(HANDLE RegKeyParam)
{
    WCHAR *Address, *Terminator;
    NaptMapping Map;
    NaptIP4Filter Filter;
    UNICODE_STRING MultiSZ;
    NTSTATUS Status;
    uint Index;
    int V6isReal = FALSE;
#if DBG
    char DebugBuffer[96];
#endif


    MultiSZ.Length = MultiSZ.MaximumLength = 0;
    MultiSZ.Buffer = NULL;

    //
    // Look for the value "StatefulTranslations".
    //
    Status = GetRegMultiSZValue(RegKeyParam, L"StatefulTranslations",
                                &MultiSZ);
    if (NT_SUCCESS(Status) && (MultiSZ.Buffer != NULL)) {
        //
        // Entry exists.  Each line should contain two addresses; the
        // first is the real address of a host, the second is the host's
        // translated address.  One must be an IPv4 address and the other
        // must be an IPv6 address, together they form a translation mapping.
        //
        for (Index = 0; ; Index++) {
            Address = EnumRegMultiSz(MultiSZ.Buffer, MultiSZ.Length + 1,
                                     Index);
            if (Address == NULL)
                break;
                
            //
            // Read in the real address, it could be either v4 or v6.
            //
            if (!ParseV6Address(Address, &Terminator, &Map.ip6addr)) {
                KdPrint(("Failed to read v6 address, trying v4...\n"));
                if (!ParseV4Address(Address, &Terminator, &Map.ip4addr)) {
                    KdPrint(("Failed to read v4 address, giving up\n"));
                    break;
                }
#if DBG
                FormatV4AddressWorker(DebugBuffer, Map.ip4addr);
                KdPrint(("StatefulTranslationMapping %s ", DebugBuffer));
#endif

                Address = Terminator;
                while (*Address == L' ')
                    Address++;

                if (!ParseV6Address(Address, &Terminator, &Map.ip6addr)) {
                    KdPrint(("Failed to read v6 address, giving up\n"));
                    break;
                }

#if DBG
                FormatV6AddressWorker(DebugBuffer, &Map.ip6addr);
                KdPrint(("<-> %s\n", DebugBuffer));
#endif
                //
                // Real address is v4, translated is v6.
                // Route packets with the v6 address to the translator.
                //
                RouteTableUpdate(NaptInterface, NaptNCE, &Map.ip6addr, 128, 0,
                                 INFINITE_LIFETIME, 0, TRUE, FALSE);

            } else {
                V6isReal = TRUE;
#if DBG
                FormatV6AddressWorker(DebugBuffer, &Map.ip6addr);
                KdPrint(("StatefulTranslationMapping %s ", DebugBuffer));
#endif

                Address = Terminator;
                while (*Address == L' ')
                    Address++;

                if (!ParseV4Address(Address, &Terminator, &Map.ip4addr)) {
                    KdPrint(("Failed to read v4 address, giving up\n"));
                    break;
                }
#if DBG
                FormatV4AddressWorker(DebugBuffer, Map.ip4addr);
                KdPrint(("<-> %s\n", DebugBuffer));
#endif
                //
                // Real address is v6, translated is v4.
                // Add a filter to snag packets with the v4 address.
                //
                Filter.lower = Filter.upper = Map.ip4addr;
                Status = AddIP4Filter(&Filter);
                if (!NT_SUCCESS(Status)) {
                    KdPrint(("Failed to add v4 filter\n"));
                    return Status;
                }
            }

            //
            // Add the v4 <-> v6 address mapping.
            //
            Status = AddDropMapping(&Map, 0 /* add */);
            if (!NT_SUCCESS(Status)) {
                //
                // Didn't work.  Try to cleanup.
                //
                KdPrint(("Failed to add v4 <-> v6 address mapping\n"));
                if (V6isReal) {
                    (void) DelIP4Filter(&Filter);
                } else {
                    RouteTableUpdate(NaptInterface, NaptNCE, &Map.ip6addr,
                                     128, 0, 0, 0, TRUE, FALSE);
                }
                return Status;
            }
        }
    }

    return STATUS_SUCCESS;
}


//* NaptReadRegistry
//
NTSTATUS
NaptReadRegistry(void)
{
    HANDLE RegKeyParam;
    NTSTATUS Status;

    KdPrint(("Napt: Reading configuration from registry\n"));

    Status = OpenRegKey(&RegKeyParam, NULL, RegKeyNameParam);
    if (!NT_SUCCESS(Status))
        goto Return;

    Status = StatelessV4RangeFiltersConfiguration(RegKeyParam);
    if (!NT_SUCCESS(Status))
        goto Return;

    Status = StatefulTranslationMappingConfiguration(RegKeyParam);
    if (!NT_SUCCESS(Status))
        goto Return;

  Return:
    ZwClose(RegKeyParam);
    return Status;
} // NaptReadRegistry


//
// Ioctl Processing functions.
//


//* IoctlAddDropMapping
//
// Processes IOCTL_NAPT_ADD_MAPPING and IOCTL_NAPT_DROP_MAPPING requests.
//
NTSTATUS
IoctlAddDropMapping(
    IN PIRP Irp,                 // I/O request packet.
    IN PIO_STACK_LOCATION IrpSp, // Current stack location in the Irp.
    ULONG Code)                  // Add/Drop code
{
    NTSTATUS Status;

    ulong oLen, iLen, i;
    void *oBuf, *iBuf;
    NaptMapping UNALIGNED *Map;
    uint AddorDrop;

    PAGED_CODE();

    oLen = IrpSp->Parameters.DeviceIoControl.OutputBufferLength;
    iLen = IrpSp->Parameters.DeviceIoControl.InputBufferLength;
    oBuf = oLen ? Irp->AssociatedIrp.SystemBuffer : NULL;
    iBuf = iLen ? Irp->AssociatedIrp.SystemBuffer : NULL;

    if (iLen < sizeof(NaptMapping)) {
        Status = STATUS_BUFFER_TOO_SMALL;
        goto Return;
    }
    AddorDrop = ((Code == IOCTL_NAPT_ADD_MAPPING) ? 0 : 1);
    Map = (NaptMapping UNALIGNED *)iBuf;
    AddDropMapping(Map, AddorDrop);
    Irp->IoStatus.Information = 0;

  Return:
    Irp->IoStatus.Status = Status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return Status;
}


//* IoctlGetMappings
//
//  Processes the IOCTL_NAPT_GET_IP6TOIP4_MAPPINGS and
//  IOCTL_NAPT_GET_IP4TOIP6_MAPPINGS requests.
//
NTSTATUS
IoctlGetMappings(
    IN PIRP Irp,                 // I/O request packet.
    IN PIO_STACK_LOCATION IrpSp, // Current stack location in the Irp.
    ULONG Code)                  // Add/Drop code
{
    struct Context {
        void *oBuf;
        int numEntry;
    } Context;

    NTSTATUS Status;

    ulong oLen, iLen, i;
    void *oBuf, *iBuf;
    PHashTable tbl;
    PAGED_CODE();

    oLen = IrpSp->Parameters.DeviceIoControl.OutputBufferLength;
    iLen = IrpSp->Parameters.DeviceIoControl.InputBufferLength;
    oBuf = oLen ? Irp->AssociatedIrp.SystemBuffer : NULL;
    iBuf = iLen ? Irp->AssociatedIrp.SystemBuffer : NULL;

    Context.oBuf = oBuf;
    Context.numEntry = 0;
  
    if (Code == IOCTL_NAPT_GET_IP6TOIP4_MAPPINGS) {
        if (IP6toIP4tbl != NULL){
            if (oLen >= (IP6toIP4tbl->numEntries * sizeof(NaptMapping))) {
                IP6Iter(IP6toIP4tbl, iterIP6toIP4, &Context);
                Status = STATUS_SUCCESS;
            }
            else {
                Status = STATUS_BUFFER_TOO_SMALL;
            }
        } 
        else {
            Status = STATUS_UNSUCCESSFUL;
        }
    }
    else {
        if (IP4toIP6tbl != NULL){
            if (oLen >= (IP4toIP6tbl->numEntries * sizeof(NaptMapping))) {
                IP4Iter(IP4toIP6tbl, iterIP4toIP6, &Context);
                Status = STATUS_SUCCESS;
            }
            else {
                Status = STATUS_BUFFER_TOO_SMALL;
            }
        } 
        else {
            Status = STATUS_UNSUCCESSFUL;
        }
    }

    Irp->IoStatus.Status = Status;
    Irp->IoStatus.Information = Context.numEntry*sizeof(NaptMapping);
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return Status;
}


//* IoctlAddDelIp4Filter
//
NTSTATUS
IoctlAddDelIp4Filter(
    IN PIRP Irp,
    IN PIO_STACK_LOCATION IrpSp,
    ULONG Code)
{
    NTSTATUS Status;

    ulong iLen, Len;
    void *iBuf;
    PAGED_CODE();

    iLen = IrpSp->Parameters.DeviceIoControl.InputBufferLength;
    iBuf = iLen ? Irp->AssociatedIrp.SystemBuffer : NULL;

    if (iLen != sizeof(NaptIP4Filter)) {
        Status = STATUS_INSUFFICIENT_RESOURCES;;
        goto Return;
    }

    if (Code == IOCTL_NAPT_ADD_IP4FILTER) {
        Status = AddIP4Filter((NaptIP4Filter*)iBuf);
    }
    else {
        Status = DelIP4Filter((NaptIP4Filter*)iBuf);
    }

  Return:
    Irp->IoStatus.Information = 0;
    Irp->IoStatus.Status = Status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}


//* IoctlListIp4Filters
//
NTSTATUS
IoctlListIp4Filters(
    IN PIRP Irp,
    IN PIO_STACK_LOCATION IrpSp)
{
    ulong oLen, Len;
    void *oBuf;
    PAGED_CODE();

    oLen = IrpSp->Parameters.DeviceIoControl.OutputBufferLength;
    oBuf = oLen ? Irp->AssociatedIrp.SystemBuffer : NULL;

    Len = numNaptIP4Filters * sizeof(NaptIP4Filter);
    if (oLen >= Len) {
        Irp->IoStatus.Information = Len;
        if (Len)
            RtlCopyMemory(oBuf, naptIP4Filter, Len);
        Irp->IoStatus.Status = STATUS_SUCCESS;
    }
    else {
        Irp->IoStatus.Information = 0;
        Irp->IoStatus.Status = STATUS_BUFFER_TOO_SMALL;
    }

    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}


//* IoctlReadRegistry
//
NTSTATUS
IoctlReadRegistry(IN PIRP Irp)
{
    Irp->IoStatus.Status = NaptReadRegistry();
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}


//* NaptDispatchDeviceControl
//
// This is the dispatch routine for Napt.
//
NTSTATUS
NaptDispatchDeviceControl(
    IN PIRP Irp,                 // I/O request packet.
    IN PIO_STACK_LOCATION IrpSp) // Current stack location in the Irp.
{
    NTSTATUS Status;
    ULONG Code;
  
    PAGED_CODE();

    Code = IrpSp->Parameters.DeviceIoControl.IoControlCode;

    switch (Code) {

    case IOCTL_NAPT_ADD_MAPPING:
    case IOCTL_NAPT_DEL_MAPPING:
        return IoctlAddDropMapping(Irp, IrpSp, Code);

    case IOCTL_NAPT_GET_IP6TOIP4_MAPPINGS:
    case IOCTL_NAPT_GET_IP4TOIP6_MAPPINGS:
        return IoctlGetMappings(Irp, IrpSp, Code);

    case IOCTL_NAPT_ADD_IP4FILTER:
    case IOCTL_NAPT_DEL_IP4FILTER:
        return IoctlAddDelIp4Filter(Irp, IrpSp, Code);

    case IOCTL_NAPT_LIST_IP4FILTERS:
        return IoctlListIp4Filters(Irp, IrpSp);

    case IOCTL_NAPT_READ_REGISTRY:
        return IoctlReadRegistry(Irp);

    default:
        Status = STATUS_NOT_IMPLEMENTED;
        break;
    }

    Irp->IoStatus.Status = Status;
    Irp->IoStatus.Information = 0;
    IoCompleteRequest(Irp, IO_NETWORK_INCREMENT);
    return Status;
} // NaptDispatchDeviceControl


#include <stdio.h>

//* FormatV4AddressWorker
//
void
FormatV4AddressWorker(char *Sz, IPAddr Addr)
{
    uint addr = net_long(Addr);

    sprintf(Sz, "%u.%u.%u.%u",
             (addr >> 24) & 0xff,
             (addr >> 16) & 0xff,
             (addr >> 8) & 0xff,
             addr & 0xff);
}


//* FormatV6AddressWorker
//
void
FormatV6AddressWorker(char *Sz, IPv6Addr *Addr)
{
    //
    // Check for IPv6-compatible and IPv4-mapped addresses.
    //
    if ((Addr->u.Word[0] == 0) && (Addr->u.Word[1] == 0) &&
        (Addr->u.Word[2] == 0) && (Addr->u.Word[3] == 0) &&
        (Addr->u.Word[4] == 0) &&
        ((Addr->u.Word[5] == 0) || (Addr->u.Word[5] == 0xffff)) &&
        (Addr->u.Word[6] != 0)) {

        Sz += sprintf(Sz, "::%s%u.%u.%u.%u",
                      Addr->u.Word[5] == 0 ? "" : "ffff:",
                      Addr->u.Byte[12], Addr->u.Byte[13],
                      Addr->u.Byte[14], Addr->u.Byte[15]);
    } else {
        int maxFirst, maxLast;
        int curFirst, curLast;
        int i;

        //
        // Find largest contiguous substring of zeroes.
        // A substring is [First, Last), so it's empty if First == Last.
        //

        maxFirst = maxLast = 0;
        curFirst = curLast = 0;

        for (i = 0; i < 8; i++) {

            if (Addr->u.Word[i] == 0) {
                // Extend current substring.
                curLast = i + 1;

                // Check if current is now largest.
                if (curLast - curFirst > maxLast - maxFirst) {
                    maxFirst = curFirst;
                    maxLast = curLast;
                }
            } else {
                // Start a new substring.
                curFirst = curLast = i + 1;
            }
        }

        //
        // Ignore a substring of length 1.
        //
        if (maxLast - maxFirst <= 1)
            maxFirst = maxLast = 0;

        //
        // Write colon-separated words.
        // A double-colon takes the place of the longest string of zeroes.
        // All zeroes is just "::".
        //
        for (i = 0; i < 8; i++) {
            uint word;

            // Skip over string of zeroes.
            if ((maxFirst <= i) && (i < maxLast)) {

                Sz += sprintf(Sz, "::");
                i = maxLast - 1;
                continue;
            }

            // Need colon separator if not at beginning.
            if ((i != 0) && (i != maxLast))
                Sz += sprintf(Sz, ":");

            // Esthetically, I don't like 3 digit words.
            word = net_short(Addr->u.Word[i]);
            Sz += sprintf(Sz, word < 0x100 ? "%x" : "%04x", word);
        }
    }
}
