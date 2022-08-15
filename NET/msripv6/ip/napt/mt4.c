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

#include "mt4.h"
#include "mt4imp.h"

// IP4Hash - IP4 hash function.
//
// This is the function to compute the hash index
//
//  Input:  IP4 in_addr Address
//
//  Returns: Hashed value.
//
static
unsigned int
IP4Hash(PKEY Address){
    return *(unsigned int*)Address;
} // IP4Hash()

static
int
IP4Equal(PKEY key1, PKEY key2){
  return (*(unsigned int*)key1==*(unsigned int*)key2);
} // IP4Equal()


int // boolean
IP4Get(PHashTable tbl, PKEY key, PVAL val){
  return Get(tbl, key, val);
}

int // boolean
IP4Put(PHashTable tbl, PKEY key, PVAL val){
  return Put(tbl, key, val);
}

int
IP4Del(PHashTable tbl,PKEY key, PVAL val){
  return Delete(tbl, key, val);
}

void
IP4Iter(
   PHashTable tbl, 
   void (*iter)(PKEY, PVAL, void*),
   void* context){
  Iterate(tbl, iter,context);
}
