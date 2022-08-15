// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.



// FILE:      AsyncRPCs.c
//
// USAGE:     AsyncRPCs /?
//
// PURPOSE:   Server side main program
//
// COMMENTS:  The Microsoft RPC AsyncRPC sample program demonstrates
//            the use of the [async] attribute and the related asynchronous
//            RPC API functions. For more information, see MSDN online reference.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "AsyncRPC.h" // header file generated by MIDL compiler

const int DEFAULT_MIN_CALLS   = 1;
const int DEFAULT_MAX_CALLS   = 20;
const BOOL DEFAULT_WAIT_FLAG  = FALSE;

PSECURITY_DESCRIPTOR pszSecurity   = NULL;

void Usage(char * pszProgramName)
{
   fprintf_s(stderr, "Usage:  %s\n", pszProgramName);
   fprintf_s(stderr, " -p protocol_sequence (default is '%s')\n", DEFAULT_PROTOCOL_SEQUENCE);
   fprintf_s(stderr, " -e endpoint (default is '%s')\n", DEFAULT_ENDPOINT);
   fprintf_s(stderr, " -m maxcalls (default is %d)\n", DEFAULT_MAX_CALLS);
   fprintf_s(stderr, " -n mincalls (default is %d)\n", DEFAULT_MIN_CALLS);
   fprintf_s(stderr, " -f flag_wait_op (default is %d)\n", DEFAULT_WAIT_FLAG);
  
   exit(1);
}

void Quit(RPC_STATUS status)
{
   if (pszSecurity != NULL)
      free(pszSecurity);

   exit(status);
}

void __cdecl main(int argc, char * argv[])
{
   unsigned char *pszProtocolSequence = DEFAULT_PROTOCOL_SEQUENCE;
   unsigned char *pszEndpoint         = DEFAULT_ENDPOINT;
   unsigned int   nMinCalls           = DEFAULT_MIN_CALLS;
   unsigned int   nMaxCalls           = DEFAULT_MAX_CALLS;
   BOOL bDontWait                     = DEFAULT_WAIT_FLAG;
   PSECURITY_DESCRIPTOR pszSecurity   = NULL;
   int i;
   RPC_STATUS status;
   unsigned int    ifFlag             = RPC_C_AUTHN_LEVEL_NONE;

   // allow the user to override settings with command line switches
   for (i = 1; i < argc; i++)
   {
      if ((*argv[i] == '-') || (*argv[i] == '/'))
      {
         switch (tolower(*(argv[i]+1)))
         {
            case 'p':
               pszProtocolSequence = argv[++i];
               break;
            case 'e':
               pszEndpoint = argv[++i];
               break;
            case 'm':
               nMaxCalls = (unsigned int) atoi(argv[++i]);
               break;
            case 'n':
               nMinCalls = (unsigned int) atoi(argv[++i]);
               break;
            case 'f':
               bDontWait = (unsigned int) atoi(argv[++i]);
               break;
	  
            case 'h':
            case '?':
            default:
               Usage(argv[0]);
         }
      }
      else
         Usage(argv[0]);
   }

   if ((pszProtocolSequence == NULL) || (pszEndpoint == NULL) ||
       (nMinCalls < 1) || (nMinCalls > nMaxCalls))
      Usage(argv[0]);

   status = RpcServerUseProtseqEp(pszProtocolSequence,
                                  nMaxCalls,
                                  pszEndpoint,
                                  pszSecurity);
   printf_s("RpcServerUseProtseqEp returned 0x%x\n", status);
   if (status)
      Quit(status);

   

   status = RpcServerRegisterIfEx(AsyncRPC_ServerIfHandle,  NULL, NULL, ifFlag, RPC_C_LISTEN_MAX_CALLS_DEFAULT, NULL ); 

   printf_s("RpcServerRegisterIfEx returned 0x%x\n", status);
   if (status)
      Quit(status);

   printf_s("Calling RpcServerListen\n");
   status = RpcServerListen(nMinCalls,
                      nMaxCalls,
                      bDontWait);
   printf_s("RpcServerListen returned: 0x%x\n", status);
   if (status)
      Quit(status);

   if (bDontWait)
   {
      printf_s("Calling RpcMgmtWaitServerListen\n");
      status = RpcMgmtWaitServerListen();  // wait operation
      printf_s("RpcMgmtWaitServerListen returned: 0x%x\n", status);
      if (status)
         Quit(status);
   }

   free(pszSecurity);
}


// MIDL allocate and free
void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
   return(malloc(len));
}


void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
   free(ptr);
}
