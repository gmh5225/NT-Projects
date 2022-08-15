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

/*
Module Name: Net IO
Purpose: High level Socket IO and Misc socket routines
Public Functions:
	InitNetIO
   CleanUpNetIO

	GetLocalIP
	GetLocalName

   CreateListeningSocket
   AnswerListeningSocket
   DestroyListeningSocket

   CloseSocket

	GetData
	GetLine

	SendData
	SendFile
*/

//Public definitions
//Max line size for GetLine
#define NETIO_MAX_LINE 300

//Public Functions

/*
Function Name: Init Net IO
Purpose: Initializes the module so calls can be made querying network
	information for the local macnine.
Notes: MUST be called before GetLocalIP and GetLocalName
*/
void InitNetIO();

/*
Function Name: Cleanup Net IO
Purpose: Cleans up the module and unloads Winsock
*/
void CleanUpNetIO();

/*
Function Name: Reset Net IO
Purpose: Resets internal data in NetIO to reflect registry changes, etc.
*/
void ResetNetIO();

/*
Function Name: Get Local IP
Purpose: Gets the local IP number
Returns: The local IP number as an double word (4 bytes)
*/
DWORD GetLocalIP();

/*
Function Name: Get Local Name
Purpose: Gets the local Domain name, or if there is none, then the server
address in dotted format.
Returns: A string containing the local address
*/
char *GetLocalName();

int CreateListeningSocket(WORD PortNum, HWND MsgWindow, WORD SocketMsg, SOCKET &ServerSocket);

int AnswerListeningSocket(SOCKET ServerSocket, SOCKET &ClientSocket,
#ifdef MSRIPv6
SOCKADDR_IN6
#else
SOCKADDR_IN
#endif // MSRIPv6
&ClientSockAddr, int AddrLen);

void DestroyListeningSocket(SOCKET &ServerSocket, HWND MsgWindow);

void CloseSocket(SOCKET &TargetSocket);

/*
Function Name: Get Data
Purpose: Gets data from a socket with muli-threaded debugging
Parameters:
	ClientSocket - The socket to get data from
	IOBuffer - A pointer to a chunk of memory to put data in
	IOBufferSize - Size of the buffer
	ThreadNum - Number of the thread that called this functions used for debugging

Returns: -1 on error, else the number of bytes received

Notes:
Removed socket error checking because I was unable to isolate what
errors I was getting when getting a "rude" disconnect
*/
int GetData(SOCKET ClientSocket, BYTE *IOBuffer, int IOBufferSize, int ThreadNum);

/*
Function Name: Get Line
Purpose: Gets a line of text (ended by a LF (10)) from a socket with buffered
			input.  If the buffer is empty this function fills the buffer, else it
			just changes an index. Also has the ability to do multi-threaded debuging
Parameters:
	OutStr - Varible were output is put (a length of NETIO_MAX_LINE is assumed)
	ClientSocket - The socket to get data from
	IOBuffer - A pointer to a chunk of memory to put data in
	IOBufferSize - Size of the buffer
	BufferIndex - A zero based index of what charactor in the buffer we're at
	DataInBuffer - Amount of data in the buffer
	ThreadNum - Number of the thread that called this functions used for debugging

Returns: -1 on disconnect or error (abort connection), 0 on success
*/
int GetLine(char *OutStr, SOCKET ClientSocket, BYTE *IOBuffer, int IOBufferSize, int &BufferIndex, int &DataInBuffer, int ThreadNum);

/*
Function Name: Send Data
Purpose: Sends data to a socket with muli-thread debugging
Parameters:
	ClientSocket - The socket to get data from
	SendBuffer - A pointer to a chunk of memory to put data in
	NumToSend - Number of bytes to send from buffer
	ThreadNum - Number of the thread that called this functions used for debugging

Returns: -1 on error, 0 on success

Notes:
Removed socket error checking because I was unable to isolate what
errors I was getting when getting a "rude" disconnect
*/
int SendData(SOCKET ClientSocket, BYTE *SendBuffer, int NumToSend, int ThreadNum);

/*
Function Name: Send File
Purpose: Sends file to a socket with muli-thread debugging
Parameters:
	ClientSocket - The socket to get data from
	FileHandle - Win32 handle to the file to send
	IOBuffer - A pointer to a chunk of memory to use as a buffer
	IOBufferSize - Size of buffer
	ThreadNum - Number of the thread that called this functions used for debugging

Returns: -1 on error, 0 on success

Notes:
Uses SendData(..).  Could send small packets will play with algorithm to
prevent this in future...
*/
//int SendFile(SOCKET ClientSocket, HANDLE FileHandle, BYTE *IOBuffer, int IOBufferSize, int ThreadNum);
int SendFile(SOCKET ClientSocket, char *FileName, BYTE *Header, int HeaderSize,
	BYTE *IOBuffer, int IOBufferSize, BYTE *Trailer, int TrailerSize,  int ThreadNum);
