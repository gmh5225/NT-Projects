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

#ifndef __MT6__INCLUDE__
#define __MT6__INCLUDE__
#include "hash.h"
#include "ip6.h"

typedef unsigned int in_addr;
typedef struct in6_addr in6_addr;

int // boolean
IP6Get(PHashTable tbl, in6_addr *key, in_addr *val);

int // boolean
IP6Put(PHashTable tbl, in6_addr *key, in_addr *val);

int // boolean
IP6Del(PHashTable tbl, in6_addr *key, in_addr *val);

void
IP6Iter(PHashTable tbl, void (*iter)(in6_addr*, in_addr*,void*),void*);

#endif // !__MT6__INCLUDE__
