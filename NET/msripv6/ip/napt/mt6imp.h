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

#ifndef __MT6IMP__INCLUDE__
#define __MT6IMP__INCLUDE__
#include "hash.h"

typedef in6_addr KEY;
typedef KEY *PKEY;
typedef in_addr VAL;
typedef VAL *PVAL;

static
unsigned int
IP6Hash(PKEY key);

static
int
IP6Equal(PKEY key1, PKEY key2);
#define HASH(x) (IP6Hash(x))
#define EQUAL(x1,x2) (IP6Equal(x1,x2))

#include "hashimp.h" // must be last

#endif // !__MT6IMP__INCLUDE__
