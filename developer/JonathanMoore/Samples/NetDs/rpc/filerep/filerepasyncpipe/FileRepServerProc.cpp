// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.


/*

    File Replication Sample
    Server System Service

    FILE: FileRepServerProc.cpp
    
    PURPOSE: Remote procedures for server system service
    
    FUNCTIONS:

    COMMENTS:

*/

#include "common.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <tchar.h>
#include <string.h>
#include <time.h>

// header file generated by MIDL compiler
#include "FileRepServer.h"

// Declarations for service routines.
#include "Service.h"

#ifdef DEBUG2
#include "DbgMsg.h"
#endif

extern HANDLE ServerCompletionPort;
extern LONG nThreadsAtServerCompletionPort;

#define ServerCompletionPortTimeout (20*1000)


typedef enum tSReqState {
    StateArrived,
    StateQueued,
    StateActive
} SReqState;

typedef enum {
  IoFileRep,
  IoPipe,
  IoFile
} IoCompletionType;

typedef enum {
  Activate,
  Read,
  Push,
  Wait,
} ActionType;

#ifdef DEBUG1
unsigned nServerReqs = 0;
#endif

//
// Packages up the variables to be passed
// to the processing thread.
//
typedef struct tSReq{

    handle_t hFileRepClient;
    HANDLE hTokenHandle;

    HANDLE hLocalFile;

    LPTSTR LocalFileName;

    // Set when we are impersonating the client.
    BOOL bImpersonating;

    // Priority of this request.
    UINT Pri;

    // User SID.
    PSID pSID;

    SReqState State;

    // The out-pipe we use to pull data from the server.
    ASYNC_CHAR_PIPE_TYPE *OutPipe;

    // The async handle for the call to RemoteOpen.
    RPC_ASYNC_STATE *Async;

    BYTE pbReadBuf[PULL_BUFSIZE];
  
    LONG FileReadPos;
    ULONG PushSize;

    OVERLAPPED FileOl;

    ActionType Action;

    CRITICAL_SECTION Lock;

    BOOL bPushOutstanding;
    BOOL bReadOutstanding;
    BOOL bBuf;

    ULONG cbRead;

    // Set when all the non-null pushes have been dispatched.
    // This happens after reading the last segment of the file
    // and calling a push for it.  What remains to be done
    // is waiting for notification for the last data push and issuing a
    // NULL push.
    BOOL bLastDataPushIssued;

    // Set when all of the file reads have completed.
    BOOL bReadsDone;

    // Set when issuing the last push of 0 length.
    BOOL bNullPush;

    // Set when a pull fails and RPC runtime cleans up the call.
    // There is no need to call Cancel after that.
    BOOL fCallInvalidated;

    // We use this wariable to set an error code so that
    // ServerShutdownRequest can know whether an error has occurred.
    // If no error occurred, the async call will be completed.
    // Otherwise it will be cancelled.
    DWORD Status;

} SReq;


//
// Handles the requests placed on req queue and active req queue
// and returns when no requests are available.
//
SReq* FindSReq(void) {

    SReq *pReq = NULL;

    //
    // We will now go and check if the request or the active request sets of queues have anything that we
    // can service.  If they do not, then this thread can terminate.
    //

    // Check if the request queues have anything on them.  If they do,
    // pick a request off the highest priority queue and handle it, but only if we
    // are not handling enough of those requests already.
    for (UINT pri = NumPriGroups; pri > 0; pri--) {
      pReq = (SReq *) QueueRemove(ServerReqQueues[pri-1]);
      if (pReq != NULL) {
        break;
      }
    }

    if (pReq != NULL) {

#ifdef DEBUG2
      _stprintf(Msg, TEXT("RequestFile: Took req %p off Req queue %p\n"), pReq, ServerReqQueues[pReq->Pri]);
      DbgMsgRecord(Msg);
#endif
      
      if (CounterIncrement(pServerActiveReqCounters[pReq->Pri])) {
        if (QueueHashIncrementCounter(ServerActiveReqHashCounters[pReq->Pri], pReq->pSID)) {
#ifdef DEBUG2
          _stprintf(Msg, TEXT("Incremented ServerActiveReqCounters[%d] and ServerActiveReqHashCounters[%d]\n"), pReq->Pri, pReq->Pri);
          DbgMsgRecord(Msg);
#endif
          // The request now resides on a new queue.
          CounterDecrement(pServerReqCounters[pReq->Pri]);
#ifdef DEBUG2
          _stprintf(Msg, TEXT("Decremented ServerReqCounters[%d]\n"), pReq->Pri);
          DbgMsgRecord(Msg);
#endif            
          pReq->State = StateActive;
          
#ifdef DEBUG2
          _stprintf(Msg, TEXT("RequestFile: Handling active req %p\n"), pReq);
          DbgMsgRecord(Msg);
#endif
          return pReq;

        }
        else {
          // There were too many requests for a given SID, place the request back
          // onto the queue.
          
          // Don't forget to decrement the counter for the group!
          CounterDecrement(pServerActiveReqCounters[pReq->Pri]);

          QueueAdd(ServerReqQueues[pReq->Pri], pReq, TRUE);
          
#ifdef DEBUG2
          _stprintf(Msg, TEXT("Too many active requests for a SID\n"));
          DbgMsgRecord(Msg);
          _stprintf(Msg, TEXT("RequestFile: Put req %p onto Req queue %p\n"), pReq, ServerReqQueues[pReq->Pri]);
          DbgMsgRecord(Msg);
#endif
        }
      }
      else {
        // There were too many active requests for the user group, place the request back
        // onto the queue.
        
        QueueAdd(ServerReqQueues[pReq->Pri], pReq, TRUE);

#ifdef DEBUG2
        _stprintf(Msg, TEXT("Too many active requests for priority %d\n"), pReq->Pri);
        DbgMsgRecord(Msg);
        _stprintf(Msg, TEXT("RequestFile: Put req %p onto Req queue %p\n"), pReq, ServerReqQueues[pReq->Pri]);
        DbgMsgRecord(Msg);
#endif
      }
    }

    return NULL;
}

VOID FindAndActivateSReq(VOID) {
    DWORD status;

    tSReq *pReq = FindSReq();

    if (pReq) {

#ifdef DEBUG1
      QueueAdd(ServerActiveReqQueue, pReq, TRUE);
#endif

      // All that is requeired to activate the request is to queue a completion
      // packet with Activate key and the Req as Overlapped.
      status = PostQueuedCompletionStatus(ServerCompletionPort,
                                          0,
                                          IoFileRep,
                                          (LPOVERLAPPED)pReq);
      ASSERT(status);
    }
}

//
// Closes the file handle and frees all thread data if an error occured
// in one of the following functions.
//
VOID ServerShutdownRequest(SReq *pReq) {
    DWORD status;
    RPC_STATUS rpcstatus;


#ifdef DEBUG2
    TCHAR Msg[MSG_SIZE];

    DbgMsgRecord(TEXT("-> ServerShutdownRequest\n"));
#endif

    ASSERT(pReq != NULL);

#ifdef DEBUG1
nServerReqs--;
#endif


    // We are actually deleting a request, pick a new one from the queue.
    FindAndActivateSReq();

    // Stop impersonating if we are.
    // The first thing we do in handling a request is impersonating the client.
    if (pReq->bImpersonating) {
      rpcstatus = RpcRevertToSelf();
      if (rpcstatus != RPC_S_OK) {
        AddToMessageLogProcFailureEEInfo(TEXT("ServerShutdownRequest: RpcRevertToSelf"), rpcstatus);
      }
    }
    
    // Complete or cancel the async call, depending on whether an error
    // has occurred.
    if (pReq->Status && !pReq->fCallInvalidated) {
      RpcAsyncAbortCall(pReq->Async,
                        TRUE);
    }
    else {
      RpcAsyncCompleteCall(pReq->Async,
                           &status);
    }
    
    // Check that hLocalFile has been initialized and that initialization
    // was successful.
    if (pReq->hLocalFile != NULL && pReq->hLocalFile != INVALID_HANDLE_VALUE) {
      status = CloseHandle(pReq->hLocalFile);
      ASSERT(status != 0);
    }

    if (pReq->LocalFileName != NULL) {
      AutoHeapFree(pReq->LocalFileName);
    }
    
    // Check if any of the counters need to be decremented
    // since we are removing the request.
    if (pReq->State == StateQueued) {
      CounterDecrement(pServerReqCounters[pReq->Pri]);
#ifdef DEBUG2
      _stprintf(Msg, TEXT("Decremented ServerReqCounters[%d]\n"), pReq->Pri);
      DbgMsgRecord(Msg);
#endif            
    }
    if (pReq->State == StateActive) {
      CounterDecrement(pServerActiveReqCounters[pReq->Pri]);
      QueueHashDecrementCounter(ServerActiveReqHashCounters[pReq->Pri], pReq->pSID);
#ifdef DEBUG2
      _stprintf(Msg, TEXT("Decremented ServerActiveReqCounters[%d] and ServerActiveReqHashCounters[%d]\n"), pReq->Pri, pReq->Pri);
      DbgMsgRecord(Msg);
#endif

#ifdef DEBUG1
      QueueRemoveData(ServerActiveReqQueue, pReq);
#endif
    }
    
    if (pReq->hTokenHandle != NULL) {
      status = CloseHandle(pReq->hTokenHandle);
      ASSERT(status != NULL);
    }
    
    if (pReq->pSID != NULL) {
      AutoHeapFree(pReq->pSID);
    }
    
    if (pReq->Lock.DebugInfo) {
      DeleteCriticalSection(&pReq->Lock);
    }
    
    AutoHeapFree(pReq);

#ifdef DEBUG2
    DbgMsgRecord(TEXT("<- ServerShutdownRequest\n"));
#endif
}

//
// Handles a request taken off req queue.
// Returns TRUE on sucess.
//
BOOL HandleSReq(tSReq *pReq) {

#ifndef NO_SEC
    // We need to impersonate the user that has issued the
    // remote call.
    // We want to impersonate as soon as possible to minimise
    // the amount of resources that can be consumed by an attack.
    if (ImpersonateLoggedOnUser(pReq->hTokenHandle) == 0) {      
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddToMessageLogProcFailure(TEXT("HandleReq: ImpersonateLoggedOnUser"), GetLastError());
        return FALSE;
    }
    pReq->bImpersonating = TRUE;
#endif

    // Attempt to open the local file.
    if ((pReq->hLocalFile = CreateFile(pReq->LocalFileName,
                            GENERIC_READ,
                            FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_OVERLAPPED,
                            NULL)) == INVALID_HANDLE_VALUE) {
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddToMessageLogProcFailure(TEXT("HandleReq: CreateFile"), GetLastError());
        return FALSE;
    }

#ifndef NO_SEC
    // We need to stop impersonating before putting this request back into
    // a queue or quitting.
    if (RevertToSelf() == 0) {
        AddToMessageLogProcFailure(TEXT("HandleReq: RevertToSelf"), GetLastError());
    }
    pReq->bImpersonating = FALSE;
#endif

    // Initialize the request fileds for throtteling the IO

    pReq->FileOl.Offset = 0;
    pReq->FileOl.OffsetHigh = 0;
    pReq->FileOl.hEvent = NULL;

    pReq->Async->u.IOC.dwCompletionKey = IoPipe;
    pReq->Async->u.IOC.lpOverlapped = (LPOVERLAPPED) pReq;

    pReq->bLastDataPushIssued = FALSE;
    pReq->bReadsDone = FALSE;
    pReq->bNullPush = FALSE;

    pReq->Async->Flags = RPC_C_NOTIFY_ON_SEND_COMPLETE;
    pReq->Async->UserInfo = pReq;
    pReq->Async->NotificationType = RpcNotificationTypeIoc;
    pReq->Async->u.IOC.hIOPort = ServerCompletionPort;

    // Link this file to the client requests's IO completion port:
    if ((ServerCompletionPort = CreateIoCompletionPort (pReq->hLocalFile,
                                                        ServerCompletionPort,
                                                        IoFile,
                                                        0)) == NULL) {
        AddToMessageLogProcFailure(TEXT("HandleActiveReq: CreateIoCompletionPort"), GetLastError());
        return FALSE;
    }

    pReq->bReadOutstanding = FALSE;
    pReq->bPushOutstanding = FALSE;
    pReq->bBuf = FALSE;

    // Init the critsec.
    if (InitializeCriticalSectionAndSpinCount(&pReq->Lock, 10) == 0) {
        AddToMessageLogProcFailure(TEXT("HandleActiveReq: InitializeCriticalSectionAndSpinCount"), GetLastError());
        return FALSE;
    }

    return TRUE;
}

//
// Handles a request taken off active req queue
//
VOID SServiceRequests(VOID) {
    tSReq *pReq;

#ifdef DEBUG2
    TCHAR Msg[MSG_SIZE];
#endif

    DWORD dwNumberOfBytesTransferred;
    DWORD dwCompletionKey;
    OVERLAPPED *lpOverlapped;

    ActionType Action = Wait;

    while(TRUE) {

      //
      // Read data from file.
      //
      if (Action == Read) {

        EnterCriticalSection(&pReq->Lock);

        ASSERT(!pReq->bBuf);
        ASSERT(!pReq->bReadOutstanding);


        // We did not read anything yet.
        pReq->cbRead = 0;

        pReq->bReadOutstanding = TRUE;

#ifdef DEBUG2
        _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: reading file for req %p\n"), GetCurrentThreadId(), pReq);
        DbgMsgRecord(Msg);
#endif

        if(!ReadFile(pReq->hLocalFile, pReq->pbReadBuf, PUSH_BUFSIZE, &pReq->cbRead, &pReq->FileOl)) {
          if (GetLastError() != ERROR_IO_PENDING) {
            AddToMessageLogProcFailure(TEXT("HandleActiveSReq: WriteFile"), GetLastError());
            pReq->Status = GetLastError();

            LeaveCriticalSection(&pReq->Lock);
            
            ServerShutdownRequest(pReq);

            Action = Wait;
          }
        }

        Action = Wait;

        LeaveCriticalSection(&pReq->Lock);
      }

      //
      // Push the data to the client.
      //
      else if (Action == Push) {

        EnterCriticalSection(&pReq->Lock);

#ifdef DEBUG2
        _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: pushing a buffer for req %p\n"), GetCurrentThreadId(), pReq);
        DbgMsgRecord(Msg);
#endif

        // Doing a regular Push for the data read from the file.
        if (!pReq->bNullPush) {
          ASSERT(!pReq->bReadOutstanding);
          ASSERT(!pReq->bPushOutstanding);
          ASSERT(pReq->bBuf);
          
          pReq->bPushOutstanding = TRUE;
          

          pReq->Status = ((WINAPI_MY_PIPE_PUSH) pReq->OutPipe->push)(pReq->OutPipe->state, (char *)pReq->pbReadBuf, pReq->cbRead);
          
          pReq->bBuf = FALSE;
          
          if(pReq->Status != RPC_S_OK) {
            pReq->bReadsDone = TRUE;
            pReq->bPushOutstanding = FALSE;
            pReq->fCallInvalidated = TRUE;

            if (pReq->bReadOutstanding == FALSE) {
              LeaveCriticalSection(&pReq->Lock);
              ServerShutdownRequest(pReq);
              
              Action = Wait;
            }
            else
              LeaveCriticalSection(&pReq->Lock);
          }
          else {

            if (!pReq->bReadsDone)
              Action = Read;
            else {
              Action = Wait;
              pReq->bLastDataPushIssued = TRUE;
            }

            LeaveCriticalSection(&pReq->Lock);
          }
        }

        // Doing a "NULL" push to signal the end of the pipe out-stream.
        else {
          ASSERT(!pReq->bReadOutstanding);
          ASSERT(!pReq->bPushOutstanding);
          ASSERT(!pReq->bBuf);
          
          pReq->bPushOutstanding = TRUE;

          
          WINAPI_MY_PIPE_PUSH pPush = (WINAPI_MY_PIPE_PUSH) pReq->OutPipe->push;
          
          pReq->Status = pPush(pReq->OutPipe->state, NULL, 0);

          if(pReq->Status != RPC_S_OK) {
            pReq->fCallInvalidated = TRUE;
            LeaveCriticalSection(&pReq->Lock);
            ServerShutdownRequest(pReq);
              
            Action = Wait;
            }
          else {
            Action = Wait;
            LeaveCriticalSection(&pReq->Lock);  
          }
        }
      }

      //
      // Wait on the completion port.
      //
      else if (Action == Wait) {

        InterlockedIncrement(&nThreadsAtServerCompletionPort);

        ASSERT(nThreadsAtServerCompletionPort >= 0);

#ifdef DEBUG2
        _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: waiting on a completion port\n"), GetCurrentThreadId());
        DbgMsgRecord(Msg);
#endif

        if (!GetQueuedCompletionStatus(ServerCompletionPort,
                                       &dwNumberOfBytesTransferred,
                                       (PULONG_PTR)&dwCompletionKey,
                                       &lpOverlapped,
                                       ServerCompletionPortTimeout)) {

          LONG nThreads = InterlockedDecrement(&nThreadsAtServerCompletionPort);
          
          if (GetLastError() == WAIT_TIMEOUT) {


#ifdef DEBUG2
            _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: timed out waiting on a completion port\n"), GetCurrentThreadId());
            DbgMsgRecord(Msg);
#endif

            if (nThreads != 0) {
              return;
            }
            else {
              continue;
            }
          }
          else {
            AddToMessageLogProcFailure(TEXT("SServiceRequests: GetQueuedCompletionStatus"), GetLastError());
            
            Action = Wait;
          }
        }

        else {

          // If this is the last thread to come off a completion port,
          // spin up an extra worker thread.
          if (InterlockedDecrement(&nThreadsAtServerCompletionPort) == 0) {
            HANDLE hThread;
            ULONG ThreadIdentifier;
            DWORD status;
            
            if ((hThread = CreateThread(NULL,
                                        0,
                                        (LPTHREAD_START_ROUTINE) SServiceRequests,
                                        NULL,
                                        0,
                                        &ThreadIdentifier)) == NULL) {

              // If creating a thread fails there is really nothing that we
              // we can do.  Just continue.
              AddToMessageLogProcFailure(TEXT("SServiceRequests: CreateThread"), GetLastError());
            }
            else {
              // Unless we close a handle to the thread, it will remain in the
              // system even after its execution has terminated.
              status = CloseHandle(hThread);
              ASSERT(status != 0);  
            }
          }
          
          ASSERT(nThreadsAtServerCompletionPort >= 0);
          

          //
          // Received file IO completion.
          //
          if (dwCompletionKey == IoFile) {
            
            pReq = (SReq *) ((size_t)lpOverlapped - offsetof(SReq, FileOl));

#ifdef DEBUG2
            _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: completed File IO for req %p\n"), GetCurrentThreadId(), pReq);
            DbgMsgRecord(Msg);
#endif
            
            EnterCriticalSection(&pReq->Lock);


            pReq->cbRead = dwNumberOfBytesTransferred;
            

            ASSERT(pReq->bReadOutstanding);
            ASSERT(!pReq->bBuf);
            
            pReq->bReadOutstanding = FALSE;
            pReq->bBuf = TRUE;
            
            ASSERT(!pReq->bLastDataPushIssued);
            
            if(pReq->Status != RPC_S_OK) {
              LeaveCriticalSection(&pReq->Lock);
              ServerShutdownRequest(pReq);
              
              Action = Wait;
            }
            else {
              
              // If we read less then we asked, then EOF has been reached.
              if (pReq->cbRead != PUSH_BUFSIZE) {
                
                pReq->bReadsDone = TRUE;
                
                // If we read 0 bytes, then the previous data push has been
                // the last one.  So the last data push has already been issued.
                if (pReq->cbRead == 0) {
                  pReq->bLastDataPushIssued = TRUE;
                  
                  // If there are no outstanding pushes, we can do a NULL push.
                  if (pReq->bPushOutstanding == FALSE) {
                    pReq->bNullPush = TRUE;
                  }
                }
              }
              
              pReq->FileOl.Offset += pReq->cbRead;
              
              // We have at most one outstanding push, since RPC runtime
              // guarantees proper notification if there are no more then
              // one push outstanding.
              if (pReq->bPushOutstanding == TRUE)
                Action = Wait;
              else
                Action = Push;
              
              LeaveCriticalSection(&pReq->Lock);
            }
            
          }
          
          //
          // Received pipe IO completion.
          //  
          else if(dwCompletionKey == IoPipe) {
            
#ifdef DEBUG2
            _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: completed Pipe IO for req %p\n"), GetCurrentThreadId(), pReq);
            DbgMsgRecord(Msg);
#endif

            pReq = (SReq *) lpOverlapped;
            
            EnterCriticalSection(&pReq->Lock);


            if (pReq->Async->Event != RpcSendComplete) {
              ASSERT(0);
            }
            
            ASSERT(pReq->bPushOutstanding);
            
            pReq->bPushOutstanding = FALSE;
            
            // The completion of the NULL push terminates the request.
            // The reuest is now handled.
            if (pReq->bNullPush) {
              LeaveCriticalSection(&pReq->Lock);
              ServerShutdownRequest(pReq);
              
              Action = Wait;
            }
            
            // This is a regular data push.
            else {
              
              // If there is a read outstanding, wait for it to complete
              // since we do not have any other data to push at present.
              if (pReq->bReadOutstanding)
                Action = Wait;
              
              // If there is a buffer to send, push it.
              else if (pReq->bBuf)
                Action = Push;
              
              // If the this is the completion of the last data push, then
              // we just need to do the NULL push.
              else if (pReq->bLastDataPushIssued) {
                Action = Push;
                pReq->bNullPush = TRUE;
              }
              
              else {
                /*ASSERT(0);*/Action = Wait;
              }
              
              LeaveCriticalSection(&pReq->Lock);
            }

          }
          
          //
          // Received an internal FileRep IO completion.
          //
          else if(dwCompletionKey == IoFileRep) {
            pReq = (SReq *) lpOverlapped;


#ifdef DEBUG2
            _stprintf(Msg, TEXT("THREAD %d: SServiceRequests: completed FileRep internal IO for req %p\n"), GetCurrentThreadId(), pReq);
            DbgMsgRecord(Msg);
#endif
            
            // This is a signal to handle a new request.
            // If the request can be activated, then handle it.
            if(HandleSReq(pReq)) {
              Action = Read;
            }
            // Otherwise, do event.
            else {
              Action = Wait;
            }
          }

          else {
            ASSERT(0);
          }
        }
      }

      else {
        ASSERT(0);
      }
    }
}

void s_RemoteReadAsyncPipe(PRPC_ASYNC_STATE pAsync,
                           handle_t hFileRepClient,
                           TCHAR FileName[128],
                           ASYNC_CHAR_PIPE_TYPE *OutPipe) {
    
    int nReply = 1;

    unsigned long ecount = 0;

    SReq *pReq = NULL;

#ifdef DEBUG2
    DbgMsgRecord(TEXT("-> s_RemoteReadAsyncPipe\n"));
#endif

    if((pReq = (SReq *) AutoHeapAlloc(sizeof(SReq))) == NULL) {
        AddRpcEEInfoAndRaiseException(ERROR_OUTOFMEMORY, TEXT("RequestFile: AutoHeapAlloc failed"));            
        return;
    }

    // Set pReq' fields to NULL so that we will know
    // in ServerShutdownRequest which ones have been initialized.
    pReq->hFileRepClient = hFileRepClient;

    pReq->hTokenHandle = NULL;

    pReq->hLocalFile = NULL;
    pReq->bImpersonating = FALSE;
    pReq->Pri = 0;
    pReq->State = StateArrived;

    pReq->pSID = NULL;

    pReq->Status = 0;

    pReq->Lock.DebugInfo = NULL;

    // The out-pipe we use to pull data from the server.
    pReq->OutPipe = OutPipe;

    // The async handle for the call to RemoteOpen.
    pReq->Async = pAsync;


    pReq->fCallInvalidated = FALSE;

#ifdef DEBUG1
    nServerReqs++;
#endif

    if ((pReq->LocalFileName = (LPTSTR) AutoHeapAlloc((_tcslen(FileName)+1) * sizeof(TCHAR))) == NULL) {
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(ERROR_OUTOFMEMORY, TEXT("RequestFile: AutoHeapAlloc failed"));            
        return;
    }
    CopyMemory(pReq->LocalFileName, FileName, (_tcslen(FileName)+1) * sizeof(TCHAR));

    //
    // Check that we are not exceeding the bound on the number
    // of concurrent requests for this user's priority group.
    // And update the number of such requests.
    //

#ifndef NO_SEC
    RPC_STATUS rpcstatus;

    // Impersonate the caller so that we can get the caller's SID
    if ((rpcstatus = RpcImpersonateClient(pReq->hFileRepClient)) != RPC_S_OK) {      
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(rpcstatus, TEXT("RequestFile: RpcImpersonateClient failed"));
        return;
    }
    pReq->bImpersonating = TRUE;

    // We need to write down the access token for the user so that
    // we can use it for impersonation later when the client binding handle
    // gets deallocated.
    if (OpenThreadToken(GetCurrentThread(),
                        TOKEN_QUERY | TOKEN_IMPERSONATE,
                        TRUE,
                        &pReq->hTokenHandle) == 0) {

        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(GetLastError(), TEXT("RequestFile: OpenThreadToken failed"));
        return;
    }

    // Determine current user's priority level.  This corresponds to the
    // priority level of the callee, since we are impersonating.
    pReq->Pri = GetCurrentUserPriority();

    // Write down the SID for the user.
    pReq->pSID = GetUserSID();

    // Stop impersonating.  We got what we wanted.
    if ((rpcstatus = RpcRevertToSelf()) != RPC_S_OK) {
        pReq->bImpersonating = FALSE;
        
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(rpcstatus, TEXT("RequestFile: RpcRevertToSelf failed"));
        return;
    }
    pReq->bImpersonating = FALSE;

#else

    pReq->Pri = 1;

    unsigned SidLength = GetLengthSid(pAnonSID);
    if ((pReq->pSID = AutoHeapAlloc(SidLength)) == NULL) {
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(GetLastError(), TEXT("RequestFile: AutoHeapAlloc failed"));
        return;
    }

    if (CopySid(SidLength, pReq->pSID, pAnonSID) == 0) {
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddRpcEEInfoAndRaiseException(GetLastError(), TEXT("RequestFile: CopySID failed"));
        return;
    }

#endif

#ifdef DEBUG2
    _stprintf(Msg, TEXT("RequestFile: Pri=%d for req %p\n"), pReq->Pri, pReq);
    DbgMsgRecord(Msg);
#endif

    // If there are no workers ot handle the request, create one.

    HANDLE hThread;
    ULONG ThreadIdentifier;
    DWORD status;

    if (nThreadsAtServerCompletionPort < 1) {

      // Go service some requests, remember that you are
      // an RPC thread.
      if ((hThread = CreateThread(NULL,
                                  0,
                                  (LPTHREAD_START_ROUTINE) SServiceRequests,
                                  NULL,
                                  0,
                                  &ThreadIdentifier)) == NULL) {
        
        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        AddToMessageLogProcFailure(TEXT("SServiceRequests: CreateThread"), GetLastError());
        return;
      }
      
      // Unless we close a handle to the thread, it will remain in the
      // system even after its execution has terminated.
      status = CloseHandle(hThread);
      ASSERT(status != 0);  
    }

    // We need to place request onto the queue only after we know that there is someone
    // who will actually be able to pick it up.  Thus, we need to create the thread first.

    // Increment the counter for the number of concurrent requests.
    if (!CounterIncrement(pServerReqCounters[pReq->Pri])) {

        pReq->Status = GetLastError();
        ServerShutdownRequest(pReq);
        // We have to raise exception after deallocating the data
        // since there is a possibility that a client thread
        // will retry and will attempt to open this local file
        // while it's previous request is still holding a lock.
        // This has been actually hit on an overloaded system.
        AddRpcEEInfoAndRaiseException(RPC_S_SERVER_TOO_BUSY, TEXT("RequestFile: CounterIncrement failed"));
        return;
    }
#ifdef DEBUG2
    _stprintf(Msg, TEXT("Incremented ServerReqCounters[%d]\n"), pReq->Pri);
    DbgMsgRecord(Msg);
#endif            
    
    pReq->State = StateQueued;

#ifdef DEBUG2
    _stprintf(Msg, TEXT("RequestFile: Put req %p onto Req queue %p\n"), pReq, ServerReqQueues[pReq->Pri]);
    DbgMsgRecord(Msg);
#endif    

    // Place the request onto the queue.
    QueueAdd(ServerReqQueues[pReq->Pri], pReq, TRUE);

    // After this point the request can be deleted.  Do not touch it.

    // Now if we can, find a queued request and activate it.
    FindAndActivateSReq();

#ifdef DEBUG2
    DbgMsgRecord(TEXT("<- RequestFile\n"));
#endif

    return;
}

// end FileRepServerProc.cpp


