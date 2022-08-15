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

#ifndef __HASHIMP_INCLUDE__
#define __HASHIMP_INCLUDE__
#include "hash.h"
#ifndef NULL
#define NULL (void*)0
#endif // !NULL
#ifndef TRUE
#define TRUE 1
#endif // !TRUE
#ifndef FALSE
#define FALSE 0
#endif // !FALSE

//
// Type specific hash entry.
//
typedef struct EntryList {
    struct EntryList *tail;
    KEY key;
    VAL val;
}EntryList, *PEntryList;

//
// Type specific hash implementation functions.
//

//* Rehash
//
// Reallocate "2^logBuckets" buckets, and rehash the entries into
// the new table.
//
static void
Rehash(PHashTable tbl, unsigned int logBuckets)
{
    PVoidList *oldBucketPointer;
    PEntryList *ob, obi;
    PEntryList *nb, *nbh;
    PEntryList that, tail;
    unsigned int index;
    unsigned int i;
    unsigned int oldNumBuckets;

    ASSERT(logBuckets <= MaxLogBuckets);
    ASSERT(logBuckets >= tbl->minLogBuckets);
    oldBucketPointer = tbl->buckets;
    ob = (PEntryList *)tbl->buckets;
    oldNumBuckets = tbl->numBuckets;

    NewBuckets(tbl, logBuckets);
    nb = (PEntryList *)tbl->buckets;

    for(i=0;i<oldNumBuckets;i++){
        obi = ob[i];
        that = obi;
        while (that != NULL) {
            index = (HASH(&(that->key)) * Multiplier) >>
                (BITSIZE(unsigned long) - tbl->logBuckets);
            nbh = &(nb[index]);
            tail = that->tail;
            that->tail = *nbh;
            *nbh = that;
            that = tail;
        }
    }
    DISPOSE(oldBucketPointer);
}


static
__inline
int // boolean
Get(PHashTable tbl, PKEY key, PVAL val){
    PEntryList that;
    unsigned int index;

    index = (HASH(key) * Multiplier) >> 
        (BITSIZE(unsigned long) - tbl->logBuckets);
    that = (PEntryList)tbl->buckets[index];
    while ((that != NULL) && !EQUAL(key, &(that->key))) {
        that = that->tail;
    }
    if (that != NULL){
        *val = that->val;
        return TRUE;
    } else {
        return FALSE;
    }
} // Get()


static
__inline
int // boolean
Put(PHashTable tbl, PKEY key, PVAL val)
{
    PEntryList that;
    PEntryList *first;
    unsigned int index;

    index = (HASH(key) * Multiplier) >>
        (BITSIZE(unsigned long) - tbl->logBuckets);
    first = (PEntryList *)&(tbl->buckets[index]);
    that = *first;
    while ((that != NULL) && !EQUAL(key, &(that->key))){
        that = that->tail;
    }
  
    // Found an entry in the hash table given above key.
    if (that != NULL){
        that->val = *val;
        return TRUE;
    }
    else {
        // Check if we can reuse something from the cache.
        if (tbl->cache != NULL) {
            that = (PEntryList)tbl->cache;
            tbl->cache = (PVoidList)tbl->cache->tail;
            that->key = *key;
            that->val = *val;
            that->tail = *first;
            *first = that;
        }
        else {
            that = NEW(EntryList, 1);
            that->key = *key;
            that->val = *val;
            that->tail = *first;
            *first = that;
        }
        tbl->numEntries++;
        if ((tbl->logBuckets < MaxLogBuckets)
            && (tbl->numEntries > tbl->maxEntries)){
            Rehash(tbl, tbl->logBuckets + 1);  // Too crowded.
        }
        return FALSE;
    }
} // Put()


static
__inline
int
Delete(PHashTable tbl, PKEY key, PVAL val)
{
    PEntryList that, prev;
    PEntryList *first;
    unsigned int index;

    index = (HASH(key) * Multiplier) >>
        (BITSIZE(unsigned long) - tbl->logBuckets);
    first = (PEntryList *)&(tbl->buckets[index]);
    that = *first;
    prev = NULL;

    while ((that != NULL) && !EQUAL(key, &(that->key))){
        prev = that;
        that = that->tail;
    }
    if (that != NULL) {
        *val = that->val;
        if (prev == NULL) {
            *first = that->tail;
        }
        else {
            prev->tail = that->tail;
        }
        if ((tbl->maxCacheSize == -1) ||
            (tbl->cacheSize < tbl->maxCacheSize)) {
            that->tail = (PEntryList)tbl->cache;
            tbl->cache = (PVoidList)that;
            tbl->cacheSize++;
        }
        else {
            DISPOSE(that);
        }
        tbl->numEntries--;
        if (tbl->maxCacheSize == 0) {
            if ((tbl->logBuckets > tbl->minLogBuckets)
                && (tbl->numEntries < tbl->minEntries)) {
                Rehash(tbl, tbl->logBuckets - 1); // too sparse
            }
        }
        return TRUE;
    }
    else {
        return FALSE;
    }
} // Delete()


static
__inline
void
Iterate(
    PHashTable tbl,
    void (*iter)(PKEY key, PVAL val, void* context),
    void *context)
{
    PEntryList that, next;
    unsigned int i;

    for(i = 0; i < tbl->numBuckets; i++) {
        that = (PEntryList)tbl->buckets[i];
        while(that != NULL) {
            (*iter)(&that->key, &that->val, context);
            next = that->tail;
            that = next;
        }
    }
} // Iterate()

#endif __HASHIMP_INCLUDE__
