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

#include "mt6.h"
#include "mt6imp.h"

//
// IP6Hash - IP6 hash function.
//
// This is the function to compute the hash index
//
//  Input:  IP6 in6_addr Address
//
//  Returns: Hashed value.
//
unsigned int
IP6Hash(PKEY key){
  return (key->u.DWord[3]);
} // IP6Hash()

int
IP6Equal(PKEY key1, PKEY key2){
  int i;
  for (i=0;i<4;i++)
    if (key1->u.DWord[i] != key2->u.DWord[i])
      return FALSE;
  return TRUE;
} // IP4Hash()

int // boolean
IP6Get(PHashTable tbl, PKEY key, PVAL val){
  return Get(tbl, key, val);
}

int // boolean
IP6Put(PHashTable tbl, PKEY key, PVAL val){
  return Put(tbl, key, val);
}

int
IP6Del(PHashTable tbl,PKEY key, PVAL val){
  return Delete(tbl, key, val);
}

void
IP6Iter(
   PHashTable tbl,
   void (*iter)(PKEY, PVAL, void*),
   void* context){
  Iterate(tbl, iter, context);
}
