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
#include "netio.h"

//Private Variables and Declarations

//Max string size for a host name
#define MAXHOSTNAME 100

//Timeout for waiting between "packets" in seconds
#define NETIO_CONN_TIMEOUT 180 //3 min

#ifndef MSRIPv6
DWORD LocalIPNumber;
#endif // MSRIPv6
char LocalName[MAXHOSTNAME];


//Private Function Declarations
DWORD GetHostID();

//Public Functions
/******************************************************************************/
void InitNetIO() {
   //Load Winsock
	WSADATA Data;
	if (WSAStartup(MAKEWORD(1, 1), &Data) != 0) {
		LogCriticalError("Failure to start up winsock\n");
		}

#ifndef MSRIPv6
	//Get our local IP number
	LocalIPNumber = GetHostID();
#endif // MSRIPv6

   //Figure out the local name on first querry, set to "" until then...
   LocalName[0] = 0;
	}
/******************************************************************************/
void CleanUpNetIO() {
	//Experimental, heard this will better clean up, especialy if a call is
	//blocking....
	WSAUnhookBlockingHook();

	//Clean up Winsock
	if (WSACleanup() == SOCKET_ERROR) {
		LogError("Failure to cleanup Winsock");
		}
	}
/******************************************************************************/
void ResetNetIO() {
   //Figure out the local name on first querry, set to "" until then...
   LocalName[0] = 0;
	}
/******************************************************************************/
#ifndef MSRIPv6
DWORD GetLocalIP() {
	return LocalIPNumber;
	}
#endif // MSRIPv6
/******************************************************************************/
#ifndef MSRIPv6
char *GetLocalName() {
	if (LocalName[0] == 0) {
   	hostent *DNSResult;
		in_addr LocalInAddr;

		//Convert the number to an in_addr struct
		LocalInAddr.s_addr = LocalIPNumber;

		//Do a DNS lookup on the IP number
		DNSResult = gethostbyaddr((char *)&(LocalInAddr), 4, PF_INET);
		if (DNSResult == NULL)
			//Didn't work, user the address in dotted string format
			strcpy(LocalName, inet_ntoa(LocalInAddr));
		else {
   		//Worked, use the primary name
			strcpy(LocalName, DNSResult->h_name);
      	//Convert it to lower case for cosmedic reasons
			CharLower(LocalName);
			}
   	}
	return LocalName;
	}
#endif // MSRIPv6
/******************************************************************************/
int CreateListeningSocket(WORD PortNum, HWND MsgWindow, WORD SocketMsg, SOCKET &ServerSocket) {
#ifdef MSRIPv6
	SOCKADDR_IN6 ServerSockAddr;

	//Set up the Server Socket Address
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin6_port = htons( (WORD) PortNum);
	ServerSockAddr.sin6_family = AF_INET6;
	//ServerSockAddr.sin6_addr.s6_addr is zero'd by memset above.

	//Create the Server Socket
	ServerSocket = socket(AF_INET6, SOCK_STREAM, 0);
#else
	SOCKADDR_IN ServerSockAddr;

	//Set up the Server Socket Address
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr)); //Needed?
	ServerSockAddr.sin_port = htons( (WORD) PortNum);
	ServerSockAddr.sin_family = AF_INET;
	ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	//Create the Server Socket
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
#endif // MSRIPv6
	if (ServerSocket == INVALID_SOCKET) {
		LogCriticalError("Failure to create socket");
		return -1;
		}

	//Bind the socket with the address
	if (bind(ServerSocket, (LPSOCKADDR) &ServerSockAddr, sizeof(ServerSockAddr))
		== SOCKET_ERROR) {
		LogCriticalError("Couldn't bind socket");
		return -1;
		}

	//Start listening for connections
	if (listen(ServerSocket, 5) == SOCKET_ERROR) {
		LogCriticalError("Failure to listen for connections");
		return -1;
		}

	//Set up event for new connections
	if (WSAAsyncSelect(ServerSocket, MsgWindow, SocketMsg, FD_ACCEPT) == SOCKET_ERROR) {
		LogCriticalError("Failure to setup event");
		return -1;
		}
   return 0;
	}
/******************************************************************************/
int AnswerListeningSocket(SOCKET ServerSocket, SOCKET &ClientSocket,
#ifdef MSRIPv6
SOCKADDR_IN6
#else
SOCKADDR_IN
#endif // MSRIPv6
&ClientSockAddr, int AddrLen) {
	ClientSocket = accept(ServerSocket, (LPSOCKADDR) &ClientSockAddr, &AddrLen);
	if (ClientSocket == INVALID_SOCKET) {
		LogError("Invalid client socket in ServerAnswer");
		return -1;
		}
   return 0;
	}
/******************************************************************************/
void DestroyListeningSocket(SOCKET &ServerSocket, HWND MsgWindow) {
	//Remove any message notification
   WSAAsyncSelect(ServerSocket, MsgWindow, 0, 0);

	//Close the socket
	CloseSocket(ServerSocket);
	}
/******************************************************************************/
void CloseSocket(SOCKET &TargetSocket) {
	if (TargetSocket != INVALID_SOCKET) {
   	//Since we're closing the socket, there's not much I can do about errors
      //now so I'm not gonna bother checking...

      //Shutdown both ends, assume we have all data...
   	shutdown(TargetSocket, 2);
      closesocket(TargetSocket);

      //Make sure we can't use the old handle again...
      TargetSocket = INVALID_SOCKET;
   	}
	}
/******************************************************************************/
int GetData(SOCKET ClientSocket, BYTE *IOBuffer, int IOBufferSize,
   int ThreadNum) {

	int NumRecv;
	int Error;
	struct timeval Timeout;
	fd_set SocketSet;

	ThreadDebugMessage(ThreadNum, "GetData()");

	//Set up a socket set structure with just ClientSocket for  select(..)
	FD_ZERO(&SocketSet);
	FD_SET(ClientSocket, &SocketSet);
	//set timeout
	Timeout.tv_sec = NETIO_CONN_TIMEOUT;
	Timeout.tv_usec = 0;

	do {
		NumRecv = recv(ClientSocket, (char *) IOBuffer, IOBufferSize, 0);
		if (NumRecv == 0) {
			//Lost connect
			return -1;
			}
		else if (NumRecv == SOCKET_ERROR) {
			Error = WSAGetLastError();
			if (Error == WSAEWOULDBLOCK) {
				NumRecv = 0;
				//Wait for socket to be readable
				if (select(0, &SocketSet, NULL, NULL, &Timeout) != 1) {
					//Timeout
					return -1;
					}
				}
			else {
				//Assume connection terminated
				return -1;
				}
			}
		} while(NumRecv == 0);
	return NumRecv;
	}
/******************************************************************************/
int GetLine(char *OutStr, SOCKET ClientSocket, BYTE *IOBuffer, int IOBufferSize,
	int &BufferIndex, int &DataInBuffer, int ThreadNum) {

	int i;
	char CurChar;

	i = 0;
	do {
		if (BufferIndex == DataInBuffer) { //Need more data
			DataInBuffer = GetData(ClientSocket, IOBuffer, IOBufferSize, ThreadNum);
			if (DataInBuffer == -1) {
				//Lost connect
				return -1;
				}
			BufferIndex = 0;
			}
		CurChar = IOBuffer[BufferIndex];
		BufferIndex++;
		if ((CurChar != 10) && (CurChar != 13))  {
			OutStr[i] = CurChar;
			i++;
			}
		} while ((CurChar != 10) && (i < NETIO_MAX_LINE));
	if (i == NETIO_MAX_LINE) {
		LogError("GetLine Overflow");
		return -1;
		}

	OutStr[i] = 0;
	return 0;
	}
/******************************************************************************/
int SendData(SOCKET ClientSocket, BYTE *SendBuffer, int NumToSend,
	int ThreadNum) {

	int NumSent;
   int Offset = 0;
	int Error;
	struct timeval Timeout;
	fd_set SocketSet;

   #ifdef BUILD_DEBUG
	ThreadDebugMessage(ThreadNum, "SendData()");

   char NumSentStr[50];
   itoa(NumToSend, NumSentStr, 10);
   ThreadDebugMessage(ThreadNum, NumSentStr);
   #endif //BUILD_DEBUG

	//Set up a socket set structure with just ClientSocket for  select(..)
	FD_ZERO(&SocketSet);
	FD_SET(ClientSocket, &SocketSet);
	//set timeout
	Timeout.tv_sec = NETIO_CONN_TIMEOUT;
	Timeout.tv_usec = 0;

	while (NumToSend > 0) {
		NumSent = send(ClientSocket, (char *) SendBuffer + Offset, NumToSend, 0);
		if (NumSent == 0) {
			//Lost connect
			return -1;
			}
		else if (NumSent == SOCKET_ERROR) {
			Error = WSAGetLastError();
			if (Error == WSAEWOULDBLOCK) {
				NumSent = 0;
				if (select(0, NULL, &SocketSet, NULL, &Timeout) != 1) {
					//Timeout
					return -1;
					}
				}
			else {
				//Lost Connection
				return -1;
				}
			}
		NumToSend -= NumSent;
      Offset += NumSent;
		}
	return 0;
	}
/******************************************************************************/
#ifdef BUILD_NT_EXP //Use NT's TransmitFile() API Call (code doesn't like with BC++ 5)
int SendFile(SOCKET ClientSocket, char *FileName, BYTE *Header, int HeaderSize,
	BYTE *, int, BYTE *Trailer, int TrailerSize,  int ThreadNum) {

   //Open the file
   HANDLE FileHandle;
   FileHandle = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING,
      FILE_FLAG_SEQUENTIAL_SCAN, 0);
   if (FileHandle == INVALID_HANDLE_VALUE) {
   	LogError("SendFile() tried to send invalid file");
   	return -1;
      }

   //Setup the TRANSMIT_FILE_BUFFERS structure
   TRANSMIT_FILE_BUFFERS XmitBuffs;
   XmitBuffs.Head = Header;
   XmitBuffs.HeadLength = HeaderSize;
   XmitBuffs.Tail = Trailer;
   XmitBuffs.TailLength = TrailerSize;

   //Transmit the file
   BOOL Ret;
   Ret = TransmitFile(ClientSocket, FileHandle, 0, 0, NULL, &XmitBuffs, 0);

   //Close the file
   CloseHandle(FileHandle);

   return Ret;
   }

#else //BUILD_NT_EXP not defined, can't use NT's TransmitFile() API Call

/*  Orignal version, pre-memory mapped IO
    Merges the all 3 sections in the same set of SendData() calls, but the
    file IO is probably less efficent.  Probably more packets sent for big
    files as well.
int SendFile(SOCKET ClientSocket, char *FileName, BYTE *Header, int HeaderSize,
	BYTE *IOBuffer, int IOBufferSize, BYTE *Trailer, int TrailerSize,  int ThreadNum) {

   int HeaderSent = 0;
   BOOL FileSent = FALSE;
   int TrailerSent = 0;
   int DataInIOBuffer;

   HANDLE FileHandle;
   DWORD NumRead;

   FileHandle = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING,
      FILE_FLAG_SEQUENTIAL_SCAN, 0);
   if (FileHandle == INVALID_HANDLE_VALUE) {
   	LogError("SendFile() tried to send invalid file");
   	return -1;
      }

   do {
   	DataInIOBuffer = 0;

		//--Fill IO Buffer--
      //Header
      if (HeaderSent < HeaderSize) {
      	//Assume DataInIOBuffer == 0
      	if ((HeaderSize - HeaderSent) <= IOBufferSize) {
         	//Send the rest of the header
      		memcpy(IOBuffer, Header + HeaderSent, HeaderSize - HeaderSent);
            DataInIOBuffer += HeaderSize - HeaderSent;
            HeaderSent = HeaderSize;
            }
         else {
         	//Send as much of the header as we can
            memcpy(IOBuffer, Header + HeaderSent, IOBufferSize);
            HeaderSent += IOBufferSize;
            DataInIOBuffer += IOBufferSize;
         	}
      	}
      //File
      if ((HeaderSent == HeaderSize) && (!FileSent) &&
      	(DataInIOBuffer < IOBufferSize)) {
         ReadFile(FileHandle, IOBuffer + DataInIOBuffer,
         	IOBufferSize - DataInIOBuffer, &NumRead, NULL);
         if (NumRead == 0) {
         	FileSent = TRUE;
         	}
         else {
         	DataInIOBuffer += NumRead;
         	}
      	}
      //Trailer
      if ((HeaderSent == HeaderSize) && (FileSent) &&
      	(TrailerSent < TrailerSize) && (DataInIOBuffer < IOBufferSize)) {
     		if ((TrailerSize - TrailerSent) <= (IOBufferSize - DataInIOBuffer)) {
         	//Send the rest of the trailer
      		memcpy(IOBuffer + DataInIOBuffer, Trailer + TrailerSent, TrailerSize - TrailerSent);
            DataInIOBuffer += TrailerSize - TrailerSent;
            TrailerSent = TrailerSize;
            }
         else {
         	//Send as much of the trailer as we can
            memcpy(IOBuffer + DataInIOBuffer, Trailer + TrailerSent, IOBufferSize - DataInIOBuffer);
            HeaderSent += IOBufferSize - DataInIOBuffer;
            DataInIOBuffer = IOBufferSize;
         	}
      	}

      //Send IO Buffer via network
      //(could be optimized to do a file read while we're waiting...)
      if (SendData(ClientSocket, IOBuffer, DataInIOBuffer, ThreadNum) == -1) {
      	//LogError("SendFile() Error sending data"); We get this on an early disconnect, not worth logging
			break;
         }

   	} while ((!FileSent) || (TrailerSent < TrailerSize) || (HeaderSent < HeaderSize));

   //Close the file
   CloseHandle(FileHandle);

   return 0;
   } */
int SendFile(SOCKET ClientSocket, char *FileName, BYTE *Header, int HeaderSize,
	BYTE * /*IOBuffer*/, int /*IOBufferSize*/, BYTE *Trailer, int TrailerSize,  int ThreadNum) {

   //Send the header
   if (HeaderSize > 0) {
      if (SendData(ClientSocket, Header, HeaderSize, ThreadNum) == -1) {
         //We get this on an early disconnect, not worth logging
         return -1;
         }
      }

   //Send the File
   HANDLE FileHandle;

   FileHandle = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
      0, OPEN_EXISTING, 0, 0);
   if (FileHandle == INVALID_HANDLE_VALUE) {
   	LogError("SendFile() tried to send invalid file");
   	return -1;
      }

	DWORD FileSize;
	DWORD FileSizeLo;
	DWORD FileSizeHi;
   FileSizeLo = GetFileSize(FileHandle, &FileSizeHi);
   FileSize = FileSizeLo; //I think we're safe for size...

   HANDLE FileMapHandle;

   FileMapHandle = CreateFileMapping(FileHandle, 0, PAGE_READONLY, 0, 0, NULL);
   if (FileHandle == INVALID_HANDLE_VALUE) {
   	LogError("SendFile() failure to create file mapping");
   	return -1;
      }

   BYTE *MapView;
   MapView = (BYTE *) MapViewOfFile(FileMapHandle, FILE_MAP_READ, 0, 0, 0);
   if (FileHandle == INVALID_HANDLE_VALUE) {
   	LogError("SendFile() failure to map file view");
   	return -1;
      }

   if (SendData(ClientSocket, MapView, FileSize, ThreadNum) == -1) {
      //We get this on an early disconnect, not worth logging
      return -1;
      }

   if(!UnmapViewOfFile(MapView)) {
   	LogError("SendFile() failure to unmap file view");
   	return -1;
   	}
   CloseHandle(FileMapHandle);
   CloseHandle(FileHandle);

   //Send the trailer
   if (TrailerSize > 0) {
      if (SendData(ClientSocket, Trailer, TrailerSize, ThreadNum) == -1) {
         //We get this on an early disconnect, not worth logging
         return -1;
         }
      }
   return 0;
   }
#endif //BUILD_NT_EXP
/******************************************************************************/
//Private Functions
/******************************************************************************/
#ifndef MSRIPv6
/*-----------------------------------------------------------
 * Function: GetHostID()
 *
 * Description:
 *  Get the Local IP address using the following algorithm:
 *    - get local hostname with gethostname()
 *    - attempt to resolve local hostname with gethostbyname()
 *    if that fails:
 *    - get a UDP socket
 *    - connect UDP socket to arbitrary address and port
 *    - use getsockname() to get local address
 *
 * Notes: Copyright by Bob Quinn, 1995, taken from his Winsock library
 *        was removed from its original module unmodified
 */
DWORD GetHostID () {
	 char szLclHost [MAXHOSTNAME];
	 LPHOSTENT lpstHostent;
	 SOCKADDR_IN stLclAddr;
	 SOCKADDR_IN stRmtAddr;
	 int nAddrSize = sizeof(SOCKADDR);
	 SOCKET hSock;
	 int nRet;

	 /* Init local address (to zero) */
	 stLclAddr.sin_addr.s_addr = INADDR_ANY;

	 /* Get the local hostname */
	 nRet = gethostname(szLclHost, MAXHOSTNAME);
	 if (nRet != SOCKET_ERROR) {
		/* Resolve hostname for local address */
       	lpstHostent = gethostbyname((LPSTR)szLclHost);
		if (lpstHostent)
		  stLclAddr.sin_addr.s_addr = *((u_long FAR*) (lpstHostent->h_addr));
	 }

	 /* If still not resolved, then try second strategy */
	 if (stLclAddr.sin_addr.s_addr == INADDR_ANY) {
		/* Get a UDP socket */
		hSock = socket(AF_INET, SOCK_DGRAM, 0);
		if (hSock != INVALID_SOCKET)  {
		  /* Connect to arbitrary port and address (NOT loopback) */
		  stRmtAddr.sin_family = AF_INET;
		  stRmtAddr.sin_port   = htons(IPPORT_ECHO);
		  stRmtAddr.sin_addr.s_addr = inet_addr("128.127.50.1");
		  nRet = connect(hSock,
							  (LPSOCKADDR)&stRmtAddr,
							  sizeof(SOCKADDR));
		  if (nRet != SOCKET_ERROR) {
			 /* Get local address */
			 getsockname(hSock,
							 (LPSOCKADDR)&stLclAddr,
							 (int FAR*)&nAddrSize);
		  }
		  closesocket(hSock);   /* we're done with the socket */
		}
	 }
	 return (stLclAddr.sin_addr.s_addr);
}
#endif // MSRIPv6
/******************************************************************************/
