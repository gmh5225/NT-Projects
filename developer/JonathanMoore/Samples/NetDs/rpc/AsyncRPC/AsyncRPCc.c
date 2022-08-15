// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.


// FILE:      AsyncRPCc.c
//
// USAGE:     AsyncRPCc /?
//
// PURPOSE:   Client side main program
//
// COMMENTS:  The Microsoft RPC AsyncRPC sample program demonstrates
//            the use of the [async] attribute and the related asynchronous
//            RPC API functions. The client will first call the asynchronous
//            function. The time it will take to run on the server side is
//            specified by the user and is passed by the asynchronous function
//            to the server as one of its parameters (asynchronous_delay).
//            The non-asynchronous routine is called next while the asynchronous one
//            is still running on the server side. The asynchronous routine can be
//            cancelled by supplying the command line option "-c".
//
//            The user can choose any of the following three types of asynchronous
//            notification methods: event, iocp, or apc.
//              
//            For more information, see MSDN online reference.
//
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AsyncRPC.h"   // header file generated by MIDL compiler

#define DEFAULT_NOTIFICATION "event"
#define DEFAULT_MESSAGE      "message from client"

void Usage(char * pszProgramName)
{
   fprintf_s(stderr, "USAGE:  %s\n", pszProgramName);
   fprintf_s(stderr, "          -p protocol_sequence\n");
   fprintf_s(stderr, "          -e endpoint\n");
   fprintf_s(stderr, "          -n network_address\n");
   fprintf_s(stderr, "          -o network_options\n");
   fprintf_s(stderr, "          -m notification_method\n");
   fprintf_s(stderr, "          -d asynchronous_delay\n");
   fprintf_s(stderr, "          -c\n");
   fprintf_s(stderr, "          -s\n\n");

   fprintf_s(stderr, "DESCRIPTION:\n");
   fprintf_s(stderr, " -p protocol_sequence:\n"
                   "   Specifies the protocol sequence (default is %s).\n",
                   DEFAULT_PROTOCOL_SEQUENCE);
   fprintf_s(stderr, " -e endpoint:\n"
                   "   Specifies the endpoint (default is %s).\n",
                   DEFAULT_ENDPOINT);
   fprintf_s(stderr, " -n network_address:\n"
                   "   Specifies the host name or IP address (default is localhost).\n");
   fprintf_s(stderr, " -o network_options:\n"
                   "   Specified the network options.\n");
   fprintf_s(stderr, " -m notification_method:\n"
                   "   Specifies the notification method used by the asynchronous function.\n"
                   "   Supported method: event, iocp, or apc (default is %s).\n",
                   DEFAULT_NOTIFICATION);
   fprintf_s(stderr, " -d asynchronous_delay:\n"
                   "   Specifies the number of seconds how long the asynchronous function\n"
                   "   will take ro run on the server (default is %u seconds).\n",
                   DEFAULT_ASYNC_DELAY);
   fprintf_s(stderr, " -c:\n"
                   "   Indicates the asynchronous call will be cancelled.\n");
   fprintf_s(stderr, " -s:\n"
                   "   Indicates the server will be shutdown.\n");
   exit(1);
}


void RPC_ENTRY APCNotificationRoutine(PRPC_ASYNC_STATE pAsync,
                                      void *Context,
                                      RPC_ASYNC_EVENT Event);


void __cdecl main(int argc, char **argv)
{
   unsigned char *pszUuid               = NULL;
   unsigned char *pszProtocolSequence   = DEFAULT_PROTOCOL_SEQUENCE;
   unsigned char *pszEndpoint           = DEFAULT_ENDPOINT;
   unsigned char *pszNetworkAddress     = NULL;
   unsigned char *pszOptions            = NULL;
   unsigned char *pszStringBinding      = NULL;
   unsigned char *pszNotificationMethod = DEFAULT_NOTIFICATION;
   unsigned char *pszMessage            = DEFAULT_MESSAGE;
   unsigned long nAsychDelay            = DEFAULT_ASYNC_DELAY;
   unsigned long ulCode;
   unsigned long nAsychTimeOut;
   BOOL bAsychCancel = FALSE;
   BOOL bShutDownServer = FALSE;
   BOOL bIsUDP = FALSE;
   BOOL bCallFinished = TRUE;
   BOOL bAsyncCallSuccess = TRUE;
   int i, nReply;
   RPC_ASYNC_STATE Async;
   RPC_STATUS status;
   DWORD dwResult;

   for (i = 1; i < argc; i++)
   {
      if ((*argv[i] == '-') || (*argv[i] == '/'))
      {
         switch (tolower(*(argv[i]+1)))
         {
            case 'p':
               pszProtocolSequence = argv[++i];
               break;
            case 'e':  // endpoint
               pszEndpoint = argv[++i];
               break;
            case 'n':  // network address
               pszNetworkAddress = argv[++i];
               break;
            case 'o':
               pszOptions = argv[++i];
               break;
            case 'm':
               pszNotificationMethod = argv[++i];
               break;
            case 'd':
               if (argv[i+1][0] != '-')
                  nAsychDelay = atol(argv[++i]);
               else
                  Usage(argv[0]);
               break;
            case 'c':
               bAsychCancel = TRUE;
               break;
            case 's':
               bShutDownServer = TRUE;
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
       (pszNotificationMethod == NULL) || (pszMessage == NULL) ||
       (nAsychDelay < 0))
   {
      Usage(argv[0]);
   }

   // Use a convenience function to concatenate the elements of
   // the string binding into the proper sequence.
   status = RpcStringBindingCompose(pszUuid,
                                    pszProtocolSequence,
                                    pszNetworkAddress,
                                    pszEndpoint,
                                    pszOptions,
                                    &pszStringBinding);
   printf_s("RpcStringBindingCompose returned 0x%x\n", status);
   printf_s("pszStringBinding = %s\n", pszStringBinding);

   if (status)
      exit(status);

   // Set the binding handle that will be used to bind to the server.
   status = RpcBindingFromStringBinding(pszStringBinding,
                                        &AsyncRPC_ClientIfHandle);
   printf_s("RpcBindingFromStringBinding returned 0x%x\n", status);
   if (status)
      exit(status);

   status = RpcAsyncInitializeHandle(&Async, sizeof(RPC_ASYNC_STATE));
   printf_s("RpcAsyncInitializeHandle returned 0x%x\n", status);
   if (status)
      exit(status);

   Async.UserInfo = NULL;

   // Detemine what type of notification method should be used
   if (_stricmp(pszNotificationMethod, "apc") == 0)
   {
      Async.NotificationType = RpcNotificationTypeApc;
      if (_stricmp(pszProtocolSequence, "ncadg_ip_udp") == 0)
         bIsUDP = TRUE;
   }
   else if (_stricmp(pszNotificationMethod, "iocp") == 0)
      Async.NotificationType = RpcNotificationTypeIoc;
   else // "event"
      Async.NotificationType = RpcNotificationTypeEvent;

   // Fill in the RPC_ASYNC_STATE structure
   switch (Async.NotificationType)
   {
      case RpcNotificationTypeApc:
         Async.u.APC.NotificationRoutine = (PFN_RPCNOTIFICATION_ROUTINE)APCNotificationRoutine;
         Async.u.APC.hThread = 0;
         // Using APC and UDP will potentially cause SleepEx() to
         // block forever. We use a user defined flag to check
         // whether the call is completed or not.
         if (bIsUDP)
            Async.UserInfo = (void*)&bCallFinished;
         break;
      case RpcNotificationTypeIoc:
         Async.u.IOC.hIOPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
         if (Async.u.IOC.hIOPort == NULL)
         {
            printf_s("CreateIoCompletionPort() failed: %d\n", GetLastError());
            exit(1);
         }
         break;
      default:  // case RpcNotificationTypeEvent:
         Async.u.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
         if (Async.u.hEvent == 0)
         {
            printf_s("CreateEvent() failed: %d\n", GetLastError());
			
            exit(1);
         }
         break;
   }

   // Call an asynchronous RPC rountine here
   RpcTryExcept
   {
      printf_s("\nCalling the remote procedure 'AsyncFunc'\n");
      AsyncFunc(&Async, AsyncRPC_ClientIfHandle, nAsychDelay);
   }
   RpcExcept(1)
   {
      ulCode = RpcExceptionCode();
      printf_s("AsyncFunc: Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);

     printf_s("\n!!!NOTE!!!\nIf you are running XP or Vista, this problem might be due to Access Denial. Kindly go through the MSDN material: http://msdn.microsoft.com/security/productinfo/XPSP2/networkprotection/restrict_remote_clients_devimp.aspx.  \n\n");
   }
   RpcEndExcept

   // Call a non-synchronous routine while
   // the synchronous routine is still running
   RpcTryExcept
   {
      printf_s("\nCalling the remote procedure 'NonAsyncFunc'\n");
      NonAsyncFunc(AsyncRPC_ClientIfHandle, pszMessage);
      fprintf_s(stderr, "You see, while 'AsyncFunc' is running asyncronously,\n"
                      "we still can send message to the server in the mean time.\n\n");
   }
   RpcExcept(( ( (RpcExceptionCode() != STATUS_ACCESS_VIOLATION) &&
                   (RpcExceptionCode() != STATUS_DATATYPE_MISALIGNMENT) &&
                   (RpcExceptionCode() != STATUS_PRIVILEGED_INSTRUCTION) &&
                   (RpcExceptionCode() != STATUS_BREAKPOINT) &&
                   (RpcExceptionCode() != STATUS_STACK_OVERFLOW) &&
                   (RpcExceptionCode() != STATUS_IN_PAGE_ERROR) &&
                   (RpcExceptionCode() != STATUS_GUARD_PAGE_VIOLATION)
                    )
                    ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH ))
   {
      ulCode = RpcExceptionCode();
     
 printf_s("NonAsyncFunc: Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);
printf_s("\n!!!NOTE!!!\nIf you are running XP or Vista, this problem might be due to Access Denial. Kindly go through the MSDN material: http://msdn.microsoft.com/security/productinfo/XPSP2/networkprotection/restrict_remote_clients_devimp.aspx.  \n\n");
   }
   RpcEndExcept

   if (bAsychCancel)
   {
      // nonabortive cancel
      status = RpcAsyncCancelCall(&Async, FALSE);
      printf_s("RpcAsyncCancelCall returned 0x%x\n", status);
      if (status)
         exit(status);
   }

   // should plus the synchronous call
   // time if it also takes long
   nAsychTimeOut = nAsychDelay * 1000 * 3;

   // Wait for asynchronous notification
   printf_s("Waiting for asynchronous call to finish ...\n");
   switch (Async.NotificationType)
   {
      case RpcNotificationTypeApc:
         // Over ncadg_ip_udp, the RPC calls are executed sequentially on the server side
         // according to the order they are called by the client, regardless of their
         // async attributes. When the client is using APC, we need to "manually" check
         // whether AsyncFunc() is finished or not.
         if (bIsUDP)
         {
            if (!bCallFinished)
            {
               printf_s("Asynchronous call failed\n");
               bAsyncCallSuccess = FALSE;
            }
         }
         else
         {
            dwResult = SleepEx(nAsychTimeOut, TRUE);
            if (dwResult != WAIT_IO_COMPLETION)
            {
               if (dwResult == 0)
                  printf_s("SleepEx() is timed out\n");
               else
                  printf_s("SleepEx() failed: %d\n", dwResult);

               bAsyncCallSuccess = FALSE;
            }
         }
         break;
      case RpcNotificationTypeIoc:
         if (!GetQueuedCompletionStatus(Async.u.IOC.hIOPort,
                                        &Async.u.IOC.dwNumberOfBytesTransferred,
                                        &Async.u.IOC.dwCompletionKey,
                                        &Async.u.IOC.lpOverlapped,
                                        nAsychTimeOut))
         {
            dwResult = GetLastError();

            if (dwResult == WAIT_TIMEOUT)
               printf_s("GetQueuedCompletionStatus() is timed out\n");
            else
               printf_s("GetQueuedCompletionStatus() failed: %d\n", dwResult);

            bAsyncCallSuccess = FALSE;
         }
         break;
      default:  // case RpcNotificationTypeEvent:
         dwResult = WaitForSingleObject(Async.u.hEvent, nAsychTimeOut);
         if (dwResult == WAIT_FAILED)
         {
            printf_s("WaitForSingleObject() failed: %d\n", GetLastError());
            bAsyncCallSuccess = FALSE;
         }
         else if (dwResult == WAIT_TIMEOUT)
         {
            printf_s("WaitForSingleObject() is timed out\n");
            bAsyncCallSuccess = FALSE;
         }
         break;
   }

   if (bAsyncCallSuccess)
   {
      printf_s("Calling RpcAsyncCompleteCall\n");
      status = RpcAsyncCompleteCall(&Async, &nReply);
      printf_s("RpcAsyncCompleteCall returned 0x%x\n", status);
      if (status)
         exit(status);

      printf_s("Remote procedure 'AsyncFunc' returned successfully\n\n");
   }

   // Clean up notification resources
   switch (Async.NotificationType)
   {
      case RpcNotificationTypeApc:
         break;
      case RpcNotificationTypeIoc:
         CloseHandle(Async.u.IOC.hIOPort);
         break;
      default:  // case RpcNotificationTypeEvent:
         CloseHandle(Async.u.hEvent);
         break;
   }

   if (bShutDownServer)
   {
      printf_s("Shutting down server ...\n");
      Shutdown(AsyncRPC_ClientIfHandle); // shut down the server side
   }

   // The calls to the remote procedures are complete.
   // Free the string and the binding handle.
   status = RpcStringFree(&pszStringBinding);
   printf_s("RpcStringFree returned 0x%x\n", status);
   if (status)
      exit(status);

   status = RpcBindingFree(&AsyncRPC_ClientIfHandle);
   printf_s("RpcBindingFree returned 0x%x\n", status);
   if (status)
      exit(status);

   exit(0);
}


void RPC_ENTRY APCNotificationRoutine(PRPC_ASYNC_STATE pAsync,
                            void *Context,
                            RPC_ASYNC_EVENT Event)
{
   BOOL *pbCallFinished = (BOOL*)(pAsync->UserInfo);

   printf_s("APCNotificationRoutine reported ");

   switch (Event)
   {
      case RpcCallComplete:
         printf_s("event RpcCallComplete\n");
         if (pbCallFinished != NULL)
            *pbCallFinished = TRUE;  // used for ncadg_ip_udp
         break;
      case RpcSendComplete:
         printf_s("event RpcSendComplete\n");
         break;
      case RpcReceiveComplete:
         printf_s("event RpcReceiveComplete\n");
         break;
      default:
         printf_s("event unknown\n");
         break;
   }

   return;
}


// MIDL allocate and free
void  __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
   return(malloc(len));
}


void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
   free(ptr);
}
