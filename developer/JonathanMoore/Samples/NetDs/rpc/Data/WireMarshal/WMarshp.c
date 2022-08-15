// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.


/****************************************************************************
							Microsoft RPC
          
                         WMarsh Example

    FILE:       WMarshp.c

    PURPOSE:    Remote procedures that are linked with the server
                side of RPC distributed application

    FUNCTIONS:  ModifyListProc() - changes the doubly-linked list
                Shutdown() - shuts down the server side

    COMMENTS:   Related to WMarshs.c

****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "WMarsh.h"    // header file generated by MIDL compiler


/****************************************************************************

Function:   ModifyListProc

Parameters: pFirst : Pointer to the head of a doubly-linked list.

Returns:    none

Purpose:    Display the list passed to the function.
            For each element in the list, add another element.
            Display the modified list.

Comments:   This sample is meant to demonstrate a typical use of the
            transmit_as attribute:  A complex data structure is simplified
            for transmission over the network, restored on the server,
            then manipulated by the remote function on the server.
            The modified data is returned to the client.

            Calls InsertNewNode(param1, param2), a utility routine
            in WMarshs.c that creates a new node, assigns to it the
            value param1, and inserts it into the list after param2.

****************************************************************************/

DOUBLE_LINK_TYPE  InsertNewNode(short sValue, DOUBLE_LINK_TYPE pPrevious);

void ModifyListProc(IN RPC_BINDING_HANDLE hBinding,
					DOUBLE_LINK_TYPE *ppFirst)
{
    DOUBLE_LINK_TYPE  pList = *ppFirst;
	DOUBLE_LINK_TYPE  pFirst = *ppFirst;
    short newNumber;

    printf_s("ModifyListProc: Display contents of doubly linked list:\n");
    while (pList != NULL) {
         printf_s("pList @0x%p = %d, Next = 0x%p\n",
                pList, pList->sNumber, pList->pNext);
         pList = pList->pNext;
    }

    printf_s("ModifyListProc: Add one node for every node in tree\n");
    for (pList = pFirst; pList != NULL; pList = pList->pNext) {
        newNumber = pList->sNumber + 1;
        pList = InsertNewNode(newNumber, pList);
    }

    printf_s("ModifyListProc: Display modified contents of doubly linked list:\n");
    for (pList = pFirst; pList != NULL; pList = pList->pNext) {
        printf_s("pList @0x%p = %d, Next = 0x%p\n",
               pList, pList->sNumber, pList->pNext);
    }
}


/****************************************************************************

Function:   Shutdown

Parameters: binding handle

Returns:    none

Purpose:    Make the server stop listening for client applications.

Comments:   The two NULL parameters passed to RpcServerUnregisterIf are
            a show of brute force:  they tell the function to turn
            off all registered interfaces.  See the RPC API function
            reference for more information about these functions.

****************************************************************************/

void Shutdown(IN RPC_BINDING_HANDLE hBinding)
{
    RPC_STATUS status;

    printf_s("Calling RpcMgmtStopServerListening\n");
    status = RpcMgmtStopServerListening(NULL);
    printf_s("RpcMgmtStopServerListening returned: 0x%x\n", status);
    if (status) {
        exit(status);
    }

    printf_s("Calling RpcServerUnregisterIf\n");
    status = RpcServerUnregisterIf(NULL, NULL, FALSE);
    printf_s("RpcServerUnregisterIf returned 0x%x\n", status);
    if (status) {
        exit(status);
    }
}

/* end file WMarshp.c */
