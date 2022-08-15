/*
Copyright (C) 1996

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

The author can be contacted via Email at bmorin@wpi.edu
*/
#ifdef MSRIPv6
#include <winsock2.h>
#include <ws2ip6.h>
#endif // MSRIPv6
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "build.h"
#include "error.h"
#include "debug.h"
#pragma hdrstop
#include <process.h>
#include "netio.h"
#include "tray.h"
#include "registry.h"
#include "users.h"
#include "httpmime.h"
#include "httplog.h"
#include "httpreq.h"
#include "httpmap.h"
#include "httpsrv.h"
#include "isapi.h"

/*
Implementaion Notes:
Contributors:
	Cliff Kotnik
*/

//Private Functions

/*
Function Name: HTTP Server Answer
Purpose: Answers messages saying that a connection is ready to start
*/
void HTTPServerAnswer();

/*
Function Name: Create HTTP Handler Thread
Purpose: If NumThreads < MaxNumThreads another thread is created
*/
void CreateHTTPHandlerThread();

/*
Function Name: Destroy HTTP Handler Thread
Purpose: Attempts to destroy a request handling thread.  Will fail if unable
   to find a free thread.
Returns: TRUE on success  FALSE on failure, nasty failures are reported to
   the error log.
*/
BOOL DestroyHTTPHandlerThread();

/*
Function Name: Destroy All HTTP Handler Threads
Purpose: Destroys all request handling threads.  Should be called on shutdown.
*/
void DestroyAllHTTPHandlerThreads();

//Private Data
//Constants
#define INIT_THREAD_STACK_SIZE 16384
#define FIRST_THREAD_ID 1000
#define LAST_THREAD_ID  1999
static const DWORD TaskTimeout = 2 * 60 * 1000; //2 min timeout
static const DWORD ShutdownTimeout = 30 * 1000; //30 sec timeout

//Registry Variables
static WORD PortNum;
static int InitNumThreads;          //Initial Number of threads to start
static int MaxNumThreads;           //Max number of threads we can have
static UINT CompactPeriod;          //5 min period between compacting threads
static int NumKeepFree;             //Number of threads to try to keep free
static int CompactLazy;             //How lazy the compact operations are

//Module Vars
static SOCKET ServerSocket = INVALID_SOCKET;
static BOOL ThreadsStarted = FALSE;
static int NumThreads = 0;
static int NumFreeThreads = 0;
static int LeastNumFree = 0;
static CRITICAL_SECTION FreeThreadsCritSec;
static UINT CompactTimerID;

static int NextThreadId = FIRST_THREAD_ID;
static int *ThreadIds;

static HANDLE *GoEventHnds;
static HANDLE *FreeEventHnds;
static HGLOBAL *ParamMems;

static HWND MsgWindow;

/******************************************************************************/
void StartHTTPServer(HWND PassedMsgWindow) {
	MsgWindow = PassedMsgWindow;

   //Init Critical Sections
   InitializeCriticalSection(&FreeThreadsCritSec);

	//Get registry vars
	PortNum = GetPortNum();

	InitNumThreads = GetInitNumThreads();
	MaxNumThreads = GetMaxNumThreads();
	NumKeepFree = GetNumThreadsKeepFree();
   CompactPeriod = GetThreadCompactPeriod();
	CompactLazy = GetThreadCompactLaziness();

	//Init the MIME and Path Map module
	LoadHTTPMIMETable();
	LoadHTTPPathMap();

	//Init the logs
	InitHTTPLogs();

   //Init ISAPI
   InitISAPI();

   //Create the server socket
   CreateListeningSocket(PortNum, MsgWindow, HTTP_SERVER_MSG, ServerSocket);

	//Allocate the arrays we need for handling the threads
	GoEventHnds = new HANDLE[MaxNumThreads];
	FreeEventHnds = new HANDLE[MaxNumThreads];
	ParamMems = new HGLOBAL[MaxNumThreads];
   ThreadIds = new int[MaxNumThreads];

	//Launch the threads
	int i;

	for (i=0; i<InitNumThreads; i++) {
      CreateHTTPHandlerThread();
		}
	ThreadsStarted = TRUE;

   //Start compacting the threads
   CompactTimerID = SetTimer(MsgWindow, HTTP_TIMER_ID, CompactPeriod, NULL);
	}

/******************************************************************************/
void EndHTTPServer() {

	//Stop compacting the threads
   KillTimer(NULL, CompactTimerID);

   //Stop the listening socket
   DestroyListeningSocket(ServerSocket, MsgWindow);

	//Shutdown Threads if they exits
	if (ThreadsStarted) {
   	DestroyAllHTTPHandlerThreads();

      //Delete the arrays
		delete[] FreeEventHnds;
		delete[] GoEventHnds;
      delete[] ParamMems;
      delete[] ThreadIds;

      //In case we restart later...
      ThreadsStarted = FALSE;
		}

   CleanUpISAPI();
	CleanUpHTTPLogs();

	//Unload modules
	UnloadHTTPMIMETable();
	UnloadHTTPPathMap();

   DeleteCriticalSection(&FreeThreadsCritSec);
	}
/******************************************************************************/
void ProcessHTTPServerMsg(WPARAM Socket, LPARAM MsgInfo) {
	if (Socket != ServerSocket) {
		LogError("Incorrect socket sent in message");
		return;
		}
	switch (WSAGETSELECTEVENT(MsgInfo)) {
		case FD_ACCEPT:
			switch (WSAGETSELECTERROR(MsgInfo)) {
				case WSAENETDOWN:
					LogCriticalError("Network Down");
					break;
				default: //No Error
					HTTPServerAnswer();
				}
			break;
		default:
			LogError("Unknown Message");
			break;
		}
	}
/******************************************************************************/
void HTTPServerAnswer() {
#ifdef MSRIPv6
	SOCKADDR_IN6 ClientSockAddr;
	int AddrLen = sizeof(SOCKADDR_IN6);
#else
	SOCKADDR_IN ClientSockAddr;
	int AddrLen = sizeof(SOCKADDR_IN);
#endif
	SOCKET ClientSocket;
	RequestThreadMessageT *Parameters;
	DWORD ReadyThread;
	int Ret;
	MSG Message;

   if ((NumFreeThreads - 1) < NumKeepFree) {
      CreateHTTPHandlerThread();
      }

	//Wait until there is a thread ready
	Ret = WaitForMultipleObjects(NumThreads, FreeEventHnds, FALSE, 0);
	while (Ret == WAIT_TIMEOUT) {
		//Do other events
		if (PeekMessage(&Message, MsgWindow, 0, 0, PM_REMOVE)) {
			//TranslateMessage(&Message);  Only needed for direct keyboard input
			DispatchMessage(&Message);
			}
		Sleep(0); //Let's not be rude...
		//Check again
		Ret = WaitForMultipleObjects(NumThreads, FreeEventHnds, FALSE, 0);
		}
	if (Ret == WAIT_FAILED) {
		LogCriticalError("Failure waiting for an avaible thread");
		return;
		}
	ReadyThread = Ret - WAIT_OBJECT_0;
	if (ReadyThread >= NumThreads) {
		LogCriticalError("Tried to send job to invalid thread number");
		return;
		}

   AnswerListeningSocket(ServerSocket, ClientSocket, ClientSockAddr, AddrLen);

	//Count the connection
	HTTPLogCountConnect();

	//Tell ready thread to handle the connection
	Parameters = (RequestThreadMessageT *) GlobalLock(ParamMems[ReadyThread]);
	Parameters->ClientSockAddr = ClientSockAddr;
	Parameters->ClientSocket = ClientSocket;
	Parameters->AddrLen = AddrLen;
	Parameters->Shutdown = FALSE;
   Parameters->CloseHandles = FALSE;
	GlobalUnlock(ParamMems[ReadyThread]);

	ResetEvent(FreeEventHnds[ReadyThread]); //Set the thread as busey
	PulseEvent(GoEventHnds[ReadyThread]);   //Tell the thread to start
	}
/******************************************************************************/
void CreateHTTPHandlerThread() {
   int i;
	int ThreadIndex; //Place thread is put in array
   int ThreadId;    //Id for duration of thread's existance

   DebugMessage("CreateHTTPHandlerThread()");

   if (NumThreads >= MaxNumThreads) {
      //We've reached our limit
      return;
   	}

   ThreadIndex = NumThreads;
   NumThreads++;

   //Assign an Id
   do {
      //Set ThreadId and Incriment the next ThreadId
      ThreadId = NextThreadId;
      NextThreadId++;
      if (NextThreadId == LAST_THREAD_ID) {
         NextThreadId = FIRST_THREAD_ID;
         }

      i = 0;
      while ((i < ThreadIndex) && (ThreadId != ThreadIds[i])) {
         i++;
         }
      } while ((i < ThreadIndex)); //while ThreadId collided with an existing Id

   ThreadIds[ThreadIndex] = ThreadId;

   //Create communication handles
   GoEventHnds[ThreadIndex] = CreateEvent(NULL, FALSE, FALSE, NULL);  //Off, AutoReset
   FreeEventHnds[ThreadIndex] = CreateEvent(NULL, FALSE, TRUE, NULL); //Off, ManualReset

   //Allocate and setup the parameter memory
   RequestThreadMessageT *Parameters;

   ParamMems[ThreadIndex] = GlobalAlloc(0, sizeof(RequestThreadMessageT));
   Parameters = (RequestThreadMessageT *) GlobalLock(ParamMems[ThreadIndex]);
   Parameters->GoEventHnd = GoEventHnds[ThreadIndex];
   Parameters->FreeEventHnd = FreeEventHnds[ThreadIndex];
   Parameters->Shutdown = FALSE;
   Parameters->CloseHandles = FALSE;
   Parameters->ThreadId = ThreadId;
   GlobalUnlock(ParamMems[ThreadIndex]);

   //Setup security attributes we can inherit
   SECURITY_ATTRIBUTES InheritSA;

   InheritSA.nLength = sizeof(SECURITY_ATTRIBUTES);
   InheritSA.bInheritHandle = TRUE;
   InheritSA.lpSecurityDescriptor = NULL;

   #ifdef __BORLANDC__ //Start thread code for Borland C++
   	unsigned long OSThreadID; //discard
      _beginthreadNT(RequestThread, INIT_THREAD_STACK_SIZE,
         (void *)ParamMems[ThreadIndex], &InheritSA, 0, &OSThreadID);
   #else //Start thread code for Visual C++, c.kotnik
   	_beginthread(RequestThread, INIT_THREAD_STACK_SIZE,
         (void *)ParamMems[ThreadIndex]);
   #endif
	}
/******************************************************************************/
BOOL DestroyHTTPHandlerThread() {
   DWORD ThreadIndex;
	int Ret;

   DebugMessage("DestroyHTTPHandlerThread()");

   //Wait until there is a thread ready
	Ret = WaitForMultipleObjects(NumThreads, FreeEventHnds, FALSE, 0);

   if (Ret == WAIT_TIMEOUT) {
   	DebugMessage("Wait for thread to kill timed out");
      return FALSE;
   	}
	else if (Ret == WAIT_FAILED) {
   	DebugMessage("Wait for thread to kill failed!");
		LogError("Failure waiting for an avaible thread to delete");
		return FALSE;
		}

	ThreadIndex = Ret - WAIT_OBJECT_0;
	if (ThreadIndex >= NumThreads) {
		LogCriticalError("Tried to delete an invalid thread number");
		return FALSE;
		}

   //Tell it to shutdown
   RequestThreadMessageT *Parameters;
   Parameters = (RequestThreadMessageT *) GlobalLock(ParamMems[ThreadIndex]);
   Parameters->Shutdown = TRUE;
   Parameters->CloseHandles = TRUE;
   GlobalUnlock(ParamMems[ThreadIndex]);
   ResetEvent(FreeEventHnds[ThreadIndex]); //Set thread as busey
   PulseEvent(GoEventHnds[ThreadIndex]);   //Tell it to go

   //Compact the Arrays and update variables
   int i;
   for(i=ThreadIndex; i<NumThreads-1; i++) {
   	FreeEventHnds[i] = FreeEventHnds[i+1];
      GoEventHnds[i] = GoEventHnds[i+1];
      ParamMems[i] = ParamMems[i+1];
      ThreadIds[i] = ThreadIds[i+1];
   	}

   //Thread will close its own handles...

   NumThreads--;

   DebugMessage("Thread killed");
   return TRUE;
	}
/******************************************************************************/
void DestroyAllHTTPHandlerThreads() {

   DebugMessage("DestroyAllHTTPHandlerThreads()");

	//Wait for threads to finish their current tasks
   WaitForMultipleObjects(NumThreads, FreeEventHnds, TRUE, TaskTimeout);

   int i;
   RequestThreadMessageT *Parameters;
   for (i=0; i<NumThreads; i++) {
   	Parameters = (RequestThreadMessageT *) GlobalLock(ParamMems[i]);
      Parameters->Shutdown = TRUE;
      Parameters->CloseHandles = FALSE;
      GlobalUnlock(ParamMems[i]);
      ResetEvent(FreeEventHnds[i]);
      PulseEvent(GoEventHnds[i]);
      };

   //Wait for threads to finish shutdown
   WaitForMultipleObjects(NumThreads, FreeEventHnds, TRUE, ShutdownTimeout);

   //Close the handles now that we're done with them
   for (i=0; i<NumThreads; i++) {
   	CloseHandle(FreeEventHnds[i]);
      CloseHandle(GoEventHnds[i]);
   	}

   NumThreads = 0;
   NumFreeThreads = 0;
   LeastNumFree = 0;
	}
/******************************************************************************/
void IncNumFreeThreads() {
   DebugMessage("IncNumFreeThreads()");

	EnterCriticalSection(&FreeThreadsCritSec);
   NumFreeThreads++;
   LeaveCriticalSection(&FreeThreadsCritSec);
	}
/******************************************************************************/
void DecNumFreeThreads() {
   DebugMessage("DecNumFreeThreads()");

	EnterCriticalSection(&FreeThreadsCritSec);

   NumFreeThreads--;
   if (NumFreeThreads < LeastNumFree) {
   	LeastNumFree = NumFreeThreads;
      }

   LeaveCriticalSection(&FreeThreadsCritSec);
	}
/******************************************************************************/
void ProcessHTTPTimerMsg() {
   int NumToKill;
   BOOL Ret = TRUE;

   DebugMessage("ProcessHTTPTimerMsg()");

   if (LeastNumFree > NumKeepFree) {
      NumToKill = (LeastNumFree - NumKeepFree + (CompactLazy - 1)) / CompactLazy;
      }
   else {
      NumToKill = 0;
   	}

   while ((NumToKill > 0) && (Ret == TRUE))  {
   	Ret = DestroyHTTPHandlerThread();
      NumToKill--;
      }
   LeastNumFree = NumThreads;
	}
