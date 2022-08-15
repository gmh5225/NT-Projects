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
// Hash table defintions.
//

#ifndef __HASH_INCLUDE__
#define __HASH_INCLUDE__
#include "oscfg.h"

#if 0 // for 64 bit archs
#define Multiplier  ((0x9e3779b9 << 32) + 0x7f4a7c15)
#else
#define Multiplier  (0x9e3779b9)
#endif 

#define MaxLogBuckets  (((sizeof (unsigned long))*8) - 2)
#define MaxBuckets     (1<<MaxLogBuckets)
#define MinLogBuckets  (4)
#define MinBuckets     (1<<MinLogBuckets)

// Thresholds for rehashing the table: *)
// to avoid crazy oscillations, we must have MaxDensity > 2*MinDensity; *)
// to avoid excessive probes, we must try to keep MaxDensity low. *)
// Divide by 100 before using
#define MaxDensity 75 /* max numEntries/NUMBER(buckets) */
#define MinDensity 20 /* min numEntries/NUMBER(buckets) */
#define IdealDensity 50
#define BITSIZE(x) (sizeof(x)*8)

#define NEW(type,num) ((type*)ExAllocatePool(NonPagedPool,sizeof(type)*num))
#define DISPOSE(ptr) (ExFreePool((void*)ptr))

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// Generic Hash Entry Type
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

typedef struct VoidList {
  struct VoidList *tail;
} VoidList, *PVoidList;

typedef struct HashTable {
  PVoidList *buckets;
  unsigned int numBuckets;    // number of buckets
  unsigned int minLogBuckets; // minimum value for Log_2(initial size) 
  unsigned int logBuckets;    // CEILING(Log2(NUMBER(buckets^))) 
  unsigned int maxEntries;    // maximum number of entries 
  unsigned int minEntries;    // minimum number of entries 
  unsigned int numEntries;    // current num of entries in table 
  PVoidList cache;            // cache of removed elements 
  int cacheSize;              // current size of the cache 
  int maxCacheSize;           // maximum size, -1 means unbounded, 0 no cache 
} HashTable, *PHashTable;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
// Hash Prototypes
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

PHashTable
Init(PHashTable tbl, unsigned int n, int maxCacheSize);

void
Dispose(PHashTable tbl);

unsigned int
Log_2(unsigned int x);

void
NewBuckets(PHashTable tbl, unsigned int logBuckets);
#endif __HASH_INCLUDE__
