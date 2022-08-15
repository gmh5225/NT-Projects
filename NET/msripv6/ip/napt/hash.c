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
// Generic Hash Table support.
//


#include "hash.h"

PHashTable
Init(PHashTable tbl, unsigned int n, int maxCacheSize){
  int idealBuckets;
  int minBuckets;
  
  idealBuckets = MIN(((n*100)/IdealDensity),MaxBuckets);
  minBuckets = MAX(MinBuckets, idealBuckets);
  tbl->minLogBuckets = Log_2(minBuckets);

  NewBuckets(tbl, tbl->minLogBuckets);
  tbl->numEntries = 0;
  tbl->maxCacheSize = maxCacheSize;
  tbl->cacheSize = 0;
  tbl->cache = 0;
  return tbl;
} // Init()

void
Dispose(PHashTable tbl)
{
  PVoidList that, next;
  unsigned int i;

  for(i=0;i<tbl->numBuckets;i++) {
    that = tbl->buckets[i];
    while( that != NULL) {
        next = that->tail;
        DISPOSE (that);
        tbl->numEntries--;
        that = next;
    }
  }
  DISPOSE(tbl->buckets);
  ASSERT(tbl->numEntries == 0);
} // Dispose;

//
// Internal procedures
//

unsigned int
Log_2(unsigned int x){
  // return CEILING(LOG_2(x))
  unsigned int log = 0;
  unsigned int n= 1;

  ASSERT(x != 0);
  while ((log < MaxLogBuckets) && (x > n)){
    log++; 
    n += n;
  }
  return log;
} // Log_2()

void
NewBuckets(PHashTable tbl, unsigned int logBuckets){
  // Allocate "2^logBuckets" buckets.
  unsigned int numBuckets = 1 << logBuckets;
  PVoidList *b;
  unsigned int i;

  tbl->buckets = NEW(PVoidList, numBuckets);
  tbl->numBuckets = numBuckets;
  b = tbl->buckets;

  for (i=0; i<tbl->numBuckets; i++){
    b[i] = NULL;
  }
  tbl->logBuckets = logBuckets;
  tbl->maxEntries = MaxDensity * numBuckets / 100;
  tbl->minEntries = MinDensity * numBuckets / 100;
} // NewBuckets()

