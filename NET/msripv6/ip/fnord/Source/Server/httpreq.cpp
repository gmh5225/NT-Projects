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
#include "parse.h"
#include "date.h"
#include "netio.h"
#include "registry.h"
#include "users.h"
#include "tray.h"
#include "httpmime.h"
#include "httplog.h"
#include "httpreq.h" //Had to put myself here because of the global types...
#include "httpsrv.h"
#include "httpmap.h"
#include "httpsend.h"
#include "httpdir.h"
#include "imagemap.h"
#include "cgi.h"
#include "isapi.h"

/*
Implementation Notes:

	HTTP field names, method and version strings are converted to upper case
right after being read from the client in order to allow case insensitive
string comparisons to be done on them.  Since these fields are worked with a
lot, this should help performance.
*/

//Private Data and declarations
#define IO_BUFFER_SIZE 16384        //16K IO Buffer
#define MAX_HTTP_LINE_LEN 1024      //Max length of line in a header of 1024
#define MAX_HTTP_FIELD_NAME_LEN 128 //Max length of name field in line
#define MAX_HTTP_FIELD_LEN 1024     //Max length of data in line

//Private Function Declarations with Return Contstants

/*
Function Name: DispatchRequest
Purpose: Manages having the request parsed, then sent to the right function
	to send a response or handle an error.
Parameters:
	ClientSocket - Socket the client is on
	ClientSockAddr - Address of client
	AddrLen - Length of address of client
	IOBuffer - Pointer to buffer allocated for IO operations
	ThreadNum - Number of thread that called this function for debugging purposes
Notes: I'm still playing with the keep alive support.  I commented out
	the stuff for giving a client a timeout because I was unable to detect
	disconnects.
More Notes: Not sure if this organization will allow me to easily add support
	for ISAPI filter DLLs.
*/
void DispatchRequest(SOCKET ClientSocket,
#ifdef MSRIPv6
SOCKADDR_IN6
#else
SOCKADDR_IN
#endif // MSRIPv6
ClientSockAddr, int AddrLen, BYTE *IOBuffer, int ThreadNum);

/*
Function Name: Get HTTP Headers
Purpose: Manages having the request parsed, then sent to the right function
	to send a response or handle an error.
Parameters:
	RequestInfo - Request information structure (see httpreq.h)
	RequestFields - HTTP request fields structure (see httpreq.h)
Returns: GH_ERROR on error (diconnect, bad data, Windows in a bad mood, etc.)
			GH_UNKNOWN_VERSION if the version number is not HTTP/0.9 or HTTP/1.x
			GH_SIMPLE_REQUEST on a properly formated HTTP/0.9 request
			GH_10_REQUEST on a properly formated HTTP/1.x request
*/
int GetHTTPHeaders(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);
#define GH_ERROR           -1
#define GH_UNKNOWN_VERSION  0
#define GH_SIMPLE_REQUEST   1
#define GH_10_REQUEST       2

/*
Function Name: Clean Up HTTP Headers
Purpose: Cleans up memory dynamicly allocated for headers
Parameters:
	RequestInfo - Request information structure (see httpreq.h)
	RequestFields - HTTP request fields structure (see httpreq.h)
Returns: Nothing
*/
void CleanUpHTTPHeaders(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);

/*
Function Name: Split Query
Purpose: Splits the file and query part of a URI.  In other words, it
	puts the parts before and after the "?" in differnet strings.
Parameters:
	URIStr - The requested URI
	FileStr - String to contain the name of the path + file part of the URI
	QueryStr - String to contain the query part of the URI
Returns: TRUE if there is a query, else FALSE
*/
BOOL SplitQuery(char *URIStr, char *FileStr, char *QueryStr, int ThreadNum);

/*
Function Name: Get File
Purpose: Attemps to find a given file, including looking for index.html.
	Updates the given URI string so it points to the true document location
Parameters:
	FilePath - Path of file, may be modified to best reflect the retrived file
				  or directory
	URIStr - URI string, minus the querry
Returns: GF_ERROR on error
			GF_FILE_FOUND on success
			GF_INDEX_FOUND if file is a directory with an index.html file in it
			GF_DIRECTORY if file is a directory
			GF_FILE_NOT_FOUND if file was found
*/

/*
Function Name: Process Simple Request
Purpose: Sends a reply to a HTTP 0.9 "simple" request
Parameters:
	ClientSocket - Socket the client is on
	RequestInfo - Structure storing the parsed headers
	IOBuffer - Pointer to buffer allocated for IO operations
	TheadNum - Number of calling thread for debugging
Notes: I should really test this and see if it works...
*/
void ProcessSimpleRequest(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);

//Public Functions
/******************************************************************************/
void RequestThread(HGLOBAL ParamMem) {
	RequestThreadMessageT *Parameters;
#ifdef MSRIPv6
	SOCKADDR_IN6 ClientSockAddr;
#else
	SOCKADDR_IN ClientSockAddr;
#endif
	SOCKET ClientSocket;
	int AddrLen;
	HANDLE GoEventHnd;
	HANDLE FreeEventHnd;
	BOOL Shutdown;
   BOOL CloseHandles;
	int ThreadNum;

   //Allocate an IO buffer for this thread
	BYTE *IOBuffer = new BYTE[IO_BUFFER_SIZE];

	//Get thread parameters
	Parameters = (RequestThreadMessageT *)GlobalLock(ParamMem);
	GoEventHnd = Parameters->GoEventHnd;
	FreeEventHnd = Parameters->FreeEventHnd;
	ThreadNum = Parameters->ThreadId;
	GlobalUnlock(ParamMem);

	ThreadDebugMessage(ThreadNum, "Thread started");

	//Handle Messages
	do {
      //Set the thread as avaible
      SetEvent(FreeEventHnd);
      IncNumFreeThreads();

		//Wait til we have the go
		WaitForSingleObject(GoEventHnd, INFINITE);

      //Set the thread as not avaible
      DecNumFreeThreads();

      //Get the parameters for the request
		Parameters = (RequestThreadMessageT *)GlobalLock(ParamMem);
		ClientSocket = Parameters->ClientSocket;
		ClientSockAddr = Parameters->ClientSockAddr;
		AddrLen = Parameters->AddrLen;
		Shutdown = Parameters->Shutdown;
      CloseHandles = Parameters->CloseHandles;
		GlobalUnlock(ParamMem);

		if (Shutdown != TRUE) {
      	if (ClientSocket != INVALID_SOCKET)  {
            DispatchRequest(ClientSocket, ClientSockAddr, AddrLen, IOBuffer, ThreadNum);
				}
         else {
            LogError("Request thread got invalid socket");
            }
			}
		else { //Shutdown == TRUE
			ThreadDebugMessage(ThreadNum, "Got shutdown message");
			//Cleanup Memory, main thread should wait for this
			GlobalFree(ParamMem);
			delete[] IOBuffer;
			}
		} while (!Shutdown);

   if (CloseHandles) {
   	//Clean up our handles
   	CloseHandle(FreeEventHnd);
   	CloseHandle(GoEventHnd);
      }
   else {
   	//Tell the server we're done cleaning up
   	SetEvent(FreeEventHnd);
   	}
	_endthread();
	}
/******************************************************************************/

//Private Functions

/******************************************************************************/
void DispatchRequest(SOCKET ClientSocket,
#ifdef MSRIPv6
SOCKADDR_IN6
#else
SOCKADDR_IN
#endif // MSRIPv6
ClientSockAddr, int AddrLen,  BYTE *IOBuffer, int ThreadNum) {
	RequestInfoT RequestInfo;
	RequestFieldsT RequestFields;

	ThreadDebugMessage(ThreadNum, "-------------Dispatch Request()-------------");

	TrayAddConnection();

	//Setup the RequestInfo structure
	memset(&RequestInfo, 0, sizeof(RequestInfoT));
	RequestInfo.ThreadNum = ThreadNum;
	RequestInfo.IOBuffer = IOBuffer;
	RequestInfo.IOBufferSize = IO_BUFFER_SIZE;
	RequestInfo.ClientSocket = ClientSocket;
	RequestInfo.ClientSockAddr = ClientSockAddr;
	RequestInfo.AddrLen = AddrLen;
	RequestInfo.KeepAlive = FALSE;

	int GetHeadersResult;
	do {
		//Get Headers
		GetHeadersResult = GetHTTPHeaders(RequestInfo, RequestFields);

		//Figure out what version we're dealing with and deal with it
		switch (GetHeadersResult) {
			case GH_SIMPLE_REQUEST :
				ProcessSimpleRequest(RequestInfo, RequestFields);
				TrayIncNumServed();
				RequestInfo.KeepAlive = FALSE;
				break;
			case GH_10_REQUEST :
				Process10Request(RequestInfo, RequestFields);
				TrayIncNumServed();
				break;
			case GH_UNKNOWN_VERSION :
				SendHTTPError(400, "HTTP Version not supported", "Only 0.9 and 1.X requests supported", RequestInfo, RequestFields);
				TrayIncNumServed();
				break;
			case GH_ERROR:
				//Disconnect
				RequestInfo.KeepAlive = FALSE;
				break;
			}
      CleanUpHTTPHeaders(RequestInfo, RequestFields);
		} while (RequestInfo.KeepAlive == TRUE);

   //Close connection
	ThreadDebugMessage(ThreadNum, "===============Disconnect====================");
	CloseSocket(RequestInfo.ClientSocket);
	TrayRemoveConnection();
	}
/******************************************************************************/
int GetHTTPHeaders(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	//Parsing and IO buffers
	char CurLine[NETIO_MAX_LINE];
	char NextLine[NETIO_MAX_LINE];
	char FieldNameStr[MAX_HTTP_FIELD_NAME_LEN];
	char FieldValStr[MAX_HTTP_FIELD_LEN];

   //Parsing and IO working vars
	int ReadBufferIndex;
	int DataInBuffer;
	int Start;
	int End;
	int Len;

	ThreadDebugMessage(RequestInfo.ThreadNum, "Get HTTP Headers()");

	//Clear all the fields
	memset(&RequestFields, 0, sizeof(RequestFieldsT));

	ReadBufferIndex = 0;
	DataInBuffer = 0;

	//Get First Line
	if (GetLine(CurLine, RequestInfo.ClientSocket, RequestInfo.IOBuffer,
		RequestInfo.IOBufferSize, ReadBufferIndex, DataInBuffer,
		RequestInfo.ThreadNum) != 0) return GH_ERROR;

	do {//Get Next Line, append it if the first charactor is space
		if(GetLine(NextLine, RequestInfo.ClientSocket, RequestInfo.IOBuffer,
			RequestInfo.IOBufferSize, ReadBufferIndex, DataInBuffer,
			RequestInfo.ThreadNum) != 0) return GH_ERROR;
		if ((NextLine[0] == ' ') || (NextLine[0] == '\t'))
			strcat(CurLine, NextLine);
		} while ((NextLine[0] == ' ') || (NextLine[0] == '\t'));

	//Method String (first word)
	Start = 0;
	GetWord(RequestFields.MethodStr, CurLine, Start, End);
   CharUpper(RequestFields.MethodStr);
	ThreadDebugMessage(RequestInfo.ThreadNum, "Got method string");
	ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.MethodStr);

	//Version String (last word)
	GetLastWord(RequestFields.VersionStr, CurLine, Start);
   CharUpper(RequestFields.VersionStr);
	ThreadDebugMessage(RequestInfo.ThreadNum, "Got Version string");
	ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.VersionStr);

	if (strncmp(RequestFields.VersionStr, "HTTP/", 5) != 0) {
		//No version, assume simple request
		//part after method is URI
		memcpy(RequestFields.URIStr, CurLine + End, strlen(CurLine) + 1 - End);
		return GH_SIMPLE_REQUEST;
		}

	//URI String (in between End of first and Start of last)
	//<Method> <WhiteSpace> <URI> <WhiteSpace> <Version> <CRLF>
	//                  End^             Start^
	memcpy(RequestFields.URIStr, CurLine + End, Start - End);
	RequestFields.URIStr[Start - End] = 0;
	TrimRight(RequestFields.URIStr); //Remove trailing space
	ThreadDebugMessage(RequestInfo.ThreadNum, "Got URI string");
	ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.URIStr);

	//Only accept requests from HTTP/0.9 or HTTP/1.X clients, we'll
	//assume that anything else will require an upgrade or patch
	if (strncmp(RequestFields.VersionStr, "HTTP/1.", 7) != 0)
		return GH_UNKNOWN_VERSION;

	//Get the rest of the lines

	strcpy(CurLine, NextLine);

	while (CurLine[0] != 0) {//Blank Line, we're done
		do {//Get Next Line, append it if the first charactor is space
			if (GetLine(NextLine, RequestInfo.ClientSocket, RequestInfo.IOBuffer,
				RequestInfo.IOBufferSize, ReadBufferIndex, DataInBuffer,
				RequestInfo.ThreadNum) != 0)
				return GH_ERROR;
			if ((NextLine[0] == ' ') || (NextLine[0] == '\t'))
				strcat(CurLine, NextLine);
			} while ((NextLine[0] == ' ') || (NextLine[0] == '\t'));

		Start = 0;
		GetWord(FieldNameStr, CurLine, Start, End);
      CharUpper(FieldNameStr);

		ThreadDebugMessage(RequestInfo.ThreadNum, "Got field name");
		ThreadDebugMessage(RequestInfo.ThreadNum, FieldNameStr);

		Len = strlen(CurLine) - End;
		memcpy(FieldValStr, CurLine + End, Len);
		FieldValStr[Len] = 0;

		ThreadDebugMessage(RequestInfo.ThreadNum, "Got Field");
		ThreadDebugMessage(RequestInfo.ThreadNum, FieldValStr);

		//Process it
		//In order of expected commonality
      //All constants are in canonized, thus in upper case and case sensitive
      //comparisons are used
      //--Just About Always--
		if (strcmp("ACCEPT:", FieldNameStr) == 0) {
         if (RequestFields.AcceptStr[0] == '\0') {
            strncpy(RequestFields.AcceptStr, FieldValStr, ReqAcceptStrLen - 1);
				if (Len >= ReqAcceptStrLen) LogError("Accept field truncated");
         	}
         else {
         	//Append it with a comma
            int AcceptStrLen = strlen(RequestFields.AcceptStr);
            if ((ReqAcceptStrLen - AcceptStrLen) >= 10) {
               strncat(RequestFields.AcceptStr, ", ", ReqAcceptStrLen - AcceptStrLen - 1);
               strncat(RequestFields.AcceptStr, FieldValStr, ReqAcceptStrLen - AcceptStrLen - 3);
               if ((Len + 3 + AcceptStrLen)  > ReqAcceptStrLen) {
               	LogError("Accept field truncated");
                  }
               }
            else {
            	LogError("Accept field truncated");
            	}
         	}
			}
		else if (strcmp("DATE:", FieldNameStr) == 0) {
			strncpy(RequestFields.DateStr, FieldValStr, ReqDateStrLen - 1);
			if (Len >= ReqDateStrLen) LogError("Date field truncated");
			}
		else if (strcmp("USER-AGENT:", FieldNameStr) == 0) {
			strncpy(RequestFields.UserAgentStr, FieldValStr, ReqUserAgentStrLen - 1);
			if (Len >= ReqUserAgentStrLen) {
         	LogError("User Agent field truncated, value follows");
            LogError(RequestFields.UserAgentStr);
            }
			}
		else if (strcmp("CONNECTION:", FieldNameStr) == 0) {
			strncpy(RequestFields.ConnectionStr, FieldValStr, ReqConnectionStrLen - 1);
			if (Len >= ReqConnectionStrLen) LogError("Connection field truncated");
			}
      //--Sometimes--
      else if (strcmp("ACCEPT-LANGUAGE:", FieldNameStr) == 0) {
			strncpy(RequestFields.AcceptLangStr, FieldValStr, ReqAcceptLangStrLen - 1);
			if (Len >= ReqAcceptLangStrLen) LogError("Accept-Language field truncated");
			}
		else if (strcmp("REFERER:", FieldNameStr) == 0) {
			strncpy(RequestFields.RefererStr, FieldValStr, ReqRefererStrLen - 1);
			if (Len >= ReqRefererStrLen) LogError("Referer field truncated");
			}
		else if (strcmp("IF-MODIFIED-SINCE:", FieldNameStr) == 0) {
			strncpy(RequestFields.IfModSinceStr, FieldValStr, ReqIfModSinceStrLen - 1);
			if (Len >= ReqIfModSinceStrLen) LogError("If Modified Since field truncated");
			}
      //--Uncommon--
		else if (strcmp("FROM:", FieldNameStr) == 0) {
			strncpy(RequestFields.FromStr, FieldValStr, ReqFromStrLen - 1);
			if (Len >= ReqFromStrLen) LogError("From field truncated");
			}
		else if (strcmp("MIME-VERSION:", FieldNameStr) == 0) {
			strncpy(RequestFields.MIMEVerStr, FieldValStr, ReqMIMEVerStrLen - 1);
			if (Len >= ReqMIMEVerStrLen) LogError("MIME Version field truncated");
			}
		else if (strcmp("PRAGMA:", FieldNameStr) == 0) {
			strncpy(RequestFields.PragmaStr, FieldValStr, ReqPragmaStrLen - 1);
			if (Len >= ReqPragmaStrLen) LogError("Pragma field truncated");
			}
      //--Special case--
		else if (strcmp("AUTHORIZATION:", FieldNameStr) == 0) {
			strncpy(RequestFields.AuthorizationStr, FieldValStr, ReqAuthorizationStrLen - 1);
			if (Len >= ReqAuthorizationStrLen) LogError("Authorization field truncated");
			}
		else if (strcmp("CONTENT-LENGTH:", FieldNameStr) == 0) {
			strncpy(RequestFields.ContentLengthStr, FieldValStr, ReqContentLengthStrLen - 1);
			if (Len >= ReqContentLengthStrLen) LogError("Content Length field truncated");
			}
		else if (strcmp("CONTENT-TYPE:", FieldNameStr) == 0) {
			strncpy(RequestFields.ContentTypeStr, FieldValStr, ReqContentTypeStrLen - 1);
			if (Len >= ReqContentTypeStrLen) LogError("Content Type field truncated");
			}
		else if (strcmp("CONTENT-ENCODING:", FieldNameStr) == 0) {
			strncpy(RequestFields.ContentEncodingStr, FieldValStr, ReqContentEncodingStrLen - 1);
			if (Len >= ReqContentEncodingStrLen) LogError("Content Encoding field truncated");
			}
      else {
      	//Add it to the other headers
         int VarLen = strlen(FieldNameStr);
         if (FieldNameStr[VarLen - 1] == ':') {
            //Remove the colon
            FieldNameStr[VarLen - 1] = '\0';
            VarLen--;
         	}
         RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Var = new char[VarLen + 1];
         RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Val = new char[Len + 1];
         strcpy(RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Var, FieldNameStr);
         strcpy(RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Val, FieldValStr);
         RequestFields.NumOtherHeaders++;
      	}
		strcpy(CurLine, NextLine);
		}


	if (RequestFields.ContentLengthStr[0] != 0) { //Do we have attached data?
		int NumRecv;

		RequestFields.ContentLength = atol(RequestFields.ContentLengthStr);
		if (RequestFields.ContentLength > 0) {
			ThreadDebugMessage(RequestInfo.ThreadNum, "Getting content");

         //Allocate memory
			RequestFields.Content = new BYTE[RequestFields.ContentLength];

			//Get rest of data from get lines
         NumRecv = DataInBuffer - ReadBufferIndex;

         if (NumRecv > RequestFields.ContentLength) {
         	//Overflow, only read what they said they'd send
            NumRecv = RequestFields.ContentLength;
         	}
			memcpy(RequestFields.Content, RequestInfo.IOBuffer + ReadBufferIndex,
				NumRecv);

			while (NumRecv < RequestFields.ContentLength) {
				NumRecv += GetData(RequestInfo.ClientSocket,
					RequestFields.Content + NumRecv,
					RequestFields.ContentLength - NumRecv,
					RequestInfo.ThreadNum);
				if (NumRecv < 0) return GH_ERROR;
				}
			}
		else {
			RequestFields.Content = NULL;
			RequestFields.ContentLength = 0;
			}
		}
	else {
		RequestFields.Content = NULL;
		RequestFields.ContentLength = 0;
		}

	ThreadDebugMessage(RequestInfo.ThreadNum, "--Got all headers--");
	return GH_10_REQUEST;
	}
/******************************************************************************/
void CleanUpHTTPHeaders(RequestInfoT &/*RequestInfo*/, RequestFieldsT &RequestFields) {
	//Clean up memory allocated for the Content
	if (RequestFields.Content != NULL)
   	delete[] RequestFields.Content;
   while (RequestFields.NumOtherHeaders > 0) {
   	RequestFields.NumOtherHeaders--;
      delete[] RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Var;
      delete[] RequestFields.OtherHeaders[RequestFields.NumOtherHeaders].Val;
   	}
	}

/******************************************************************************/
BOOL SplitQuery(char *URIStr, char *FileStr, char *QueryStr) {
	int QuestionMarkPos;
	int i, j;

	i=0;
	while ((URIStr[i] != '?') && (URIStr[i] != 0)) {
		i++;
		}
	if (URIStr[i] == '?') {
		QuestionMarkPos = i;

		for (i=0; i<QuestionMarkPos; i++) {
			FileStr[i] = URIStr[i];
			}
		FileStr[QuestionMarkPos] = 0;

		i = QuestionMarkPos + 1;
		j = 0;
		while (URIStr[i] != 0) {
			QueryStr[j] = URIStr[i];
			i++;
			j++;
			}
		QueryStr[j] = 0;
      return TRUE;
		}
	else {
		strcpy(FileStr, URIStr);
		QueryStr[0] = 0;
		return FALSE;
		}
	}
/******************************************************************************/
void ProcessSimpleRequest(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	char FilePath[MAX_PATH];
	char RemoteRealmStr[MAX_PATH];
   char LocalRealmStr[MAX_PATH];
	int Result;
	HANDLE FileHandle;
	BOOL AllowDirList;
	int Scripting;
	DWORD FileAttr;

	ThreadDebugMessage(RequestInfo.ThreadNum, "!!!!!ProcessSimpleRequest()!!!!!");

	//Map virtual path (check access)
	Result = MapHTTPPath(RequestFields.URIStr, RequestInfo, RequestFields,
      RemoteRealmStr, LocalRealmStr, FilePath, AllowDirList, Scripting);
	if (Result !=  MP_PATH_FOUND) {
		SendData(RequestInfo.ClientSocket, (BYTE *) "File not found", 14, RequestInfo.ThreadNum);
		return;
		}
	FileAttr = GetFileAttributes(FilePath);
	if (FileAttr == 0xFFFFFFFF) {
		//Doesn't exist
		SendData(RequestInfo.ClientSocket, (BYTE *) "File not found", 14, RequestInfo.ThreadNum);
		return;
		}
	//Open the file
	FileHandle = CreateFile(FilePath, 0, FILE_SHARE_READ, NULL,
									OPEN_EXISTING, 0, NULL);
	if (FileHandle == INVALID_HANDLE_VALUE) {
		//FileIO Error
		SendData(RequestInfo.ClientSocket, (BYTE *) "File IO Error", 14, RequestInfo.ThreadNum);
		return;
		}
   CloseHandle(FileHandle);
	//Send the data
	SendFile(RequestInfo.ClientSocket, FilePath,
   	NULL, 0,
   	RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
   	NULL, 0,
   	RequestInfo.ThreadNum);
	}
/******************************************************************************/
void Process10Request(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {

	ThreadDebugMessage(RequestInfo.ThreadNum, "Process10Request()");

	//Split off the query string
	char URIStr[MAX_PATH];
	char QueryStr[MAX_PATH];

	SplitQuery(RequestFields.URIStr, URIStr, QueryStr);

	//Map virtual path (check access)
	int MapResult;

	char RemoteRealmStr[MAX_PATH];
   char LocalRealmStr[MAX_PATH];
	char FilePath[MAX_PATH];

	BOOL AllowDirList;
	int Scripting;

	MapResult = MapHTTPPath(URIStr, RequestInfo, RequestFields, RemoteRealmStr,
      LocalRealmStr, FilePath, AllowDirList, Scripting);
	ThreadDebugMessage(RequestInfo.ThreadNum, "Path Mapped");

	//Handle unusual cases
	switch(MapResult) {
		case MP_FORBIDDEN: //Access denied, no hope of this changing
			SendHTTPError(403, "Forbidden", "You do not have permission to access this resource", RequestInfo, RequestFields);
			return;
		case MP_NO_ACCESS: //Access denied, send a challenge
			SendHTTPBasicChallenge(RemoteRealmStr, RequestInfo, RequestFields);
			return;
		case MP_REDIRECT:
			SendHTTPRedirect( FilePath, RequestInfo, RequestFields );
			return;
		case MP_ERROR:
			SendHTTPError(500, "Internal Server Error", "Error mapping path", RequestInfo, RequestFields);
			return;
		}

	//Check for a valid method (if we're not scripting)
	if (Scripting == SCRIPTING_NONE) {
		if (!((strcmp(RequestFields.MethodStr, "GET" ) == 0) ||
			   (strcmp(RequestFields.MethodStr, "HEAD") == 0)))  {
			SendHTTPError(405, "Method Not Allowed", "Only GET and HEAD requests supported for this resource", RequestInfo, RequestFields);
			return;
			}
		}

	int FilePathLen;
	DWORD FileAttr;

	FilePathLen = strlen(FilePath);

	if (Scripting == SCRIPTING_NONE) {

		char IndexPath[MAX_PATH];
		DWORD IndexAttr;

		char NewURL[MAX_PATH];
      char NumStr[17];

		//If there is a \ at the end of the file path
		if (FilePath[FilePathLen - 1] == '\\') {
			//Remove the \ from file path
			FilePath[FilePathLen - 1] = 0;

			//Check if it exists
			FileAttr = GetFileAttributes(FilePath);
			if (FileAttr == 0xFFFFFFFF) {
				//Doesn't exist
				SendHTTPError(404, "File Not Found", "Could not find the requested element", RequestInfo, RequestFields);
				}
			else if ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
				//Is there an index?
				strcpy(IndexPath, FilePath);
				strcat(IndexPath, "\\");
            strcat(IndexPath, GetIndexFileName());
				IndexAttr = GetFileAttributes(IndexPath);

				if (IndexAttr == 0xFFFFFFFF) { //Nope
					if (AllowDirList) {
						//Send a dir listing
						SendHTTPDirList(FilePath, RemoteRealmStr, RequestInfo, RequestFields);
						}
					else {
						//File Not found
						SendHTTPError(404, "File Not Found", "Could not find the requested element", RequestInfo, RequestFields);
						}
					}
				else { //there is an index
					//Redirect to index
					strcpy(NewURL, "http://");
					strcat(NewURL, GetServerName());
               if (GetPortNum() != 80) {
                  itoa(GetPortNum(), NumStr, 10);
                  strcat(NewURL, ":");
                  strcat(NewURL, NumStr);
                  }
					strcat(NewURL, URIStr);
					strcat(NewURL, GetIndexFileName());
					SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
					}
				}
			else {
				//File exists, why did they put a slash at the end of it?????
				//Redirect to the file without the slash
				strcpy(NewURL, "http://");
				strcat(NewURL, GetServerName());
            if (GetPortNum() != 80) {
               itoa(GetPortNum(), NumStr, 10);
               strcat(NewURL, ":");
               strcat(NewURL, NumStr);
               }
				strcat(NewURL, URIStr);
				NewURL[strlen(NewURL) - 1] = 0; //remove the /
				SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
				}
			}
		//There is not a \ at the end of the file path
		else {
			FileAttr = GetFileAttributes(FilePath);

			if (FileAttr == 0xFFFFFFFF) {
				//Doesn't exist
				SendHTTPError(404, "File Not Found", "Could not find the requested element", RequestInfo, RequestFields);
				}
			else if ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
				//Is there an index?
				strcat(FilePath, "\\");
            strcat(FilePath, GetIndexFileName());
				FileAttr = GetFileAttributes(FilePath);
				if (FileAttr == 0xFFFFFFFF) { //Nope
					if (AllowDirList) {
						//Redirect to directory with slash
						strcpy(NewURL, "http://");
						strcat(NewURL, GetServerName());
                  if (GetPortNum() != 80) {
                     itoa(GetPortNum(), NumStr, 10);
                     strcat(NewURL, ":");
                     strcat(NewURL, NumStr);
                     }
						strcat(NewURL, URIStr);
						strcat(NewURL, "/");
						SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
						}
					else {
						//File Not found
						SendHTTPError(404, "File Not Found", "Could not find the requested element", RequestInfo, RequestFields);
						}
					}
				else { //there is an index
					//Redirect to index
					strcpy(NewURL, "http://");
					strcat(NewURL, GetServerName());
               if (GetPortNum() != 80) {
                  itoa(GetPortNum(), NumStr, 10);
                  strcat(NewURL, ":");
                  strcat(NewURL, NumStr);
                  }
					strcat(NewURL, URIStr);
					strcat(NewURL, "/");
               strcat(NewURL, GetIndexFileName());
					SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
					}
				}
			else {
				//Send it
				ThreadDebugMessage(RequestInfo.ThreadNum, "Sending object");

            char Extention[20];

            GetExtention(FilePath, Extention);
            if (strcmpi("map", Extention) == 0) {
            	//Handle .MAP Files
               ProcessImageMap(RequestInfo, RequestFields, QueryStr, FilePath);
            	}
            else {
					//Handle all other types
					SendHTTPFile(FilePath, RequestInfo, RequestFields);
            	}
				}
			}
		}
	else { //We're doing a script
		//Figure out CGI style path info
      char ExtraPath[MAX_PATH]; //Hold the biggest possible extra path and move
      char *ExtraPathWorkPtr;   //the working pointer down as we check
      char ScriptFilePath[MAX_PATH]; //The location of the script w/o extra stuff
      int i;

      //Set Extra Path to everything extra
      int LocalRealmStrLen = strlen(LocalRealmStr);
      strcpy(ExtraPath, FilePath + LocalRealmStrLen);

      //Set the script file path to the core mapping
      strcpy(ScriptFilePath, LocalRealmStr);

      //Try to find the file until we run out of path
      int ScriptFilePathStrLen = strlen(ScriptFilePath);
      ExtraPathWorkPtr = ExtraPath;
      FileAttr = GetFileAttributes(ScriptFilePath);
      #define IS_NOT_FILE ((FileAttr == 0xFFFFFFFF) || ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY))
      while (IS_NOT_FILE && (ExtraPathWorkPtr[0] != '\0')) {
         //Move one block of the form "\element" from something like
         //"\element\element", from the extra path to the ScriptFilePath

         //Get the first slash
         ScriptFilePath[ScriptFilePathStrLen] = ExtraPathWorkPtr[0];
         ScriptFilePathStrLen++;
         ExtraPathWorkPtr++;
         //Get the rest
         while((ExtraPathWorkPtr[0] != 0) && (ExtraPathWorkPtr[0] != '\\')) {
            ScriptFilePath[ScriptFilePathStrLen] = ExtraPathWorkPtr[0];
            ScriptFilePathStrLen++;
         	ExtraPathWorkPtr++;
         	}
         ScriptFilePath[ScriptFilePathStrLen] = '\0';
         FileAttr = GetFileAttributes(ScriptFilePath);
      	}
      strcpy(RequestFields.PathInfoStr, ExtraPathWorkPtr);


      //The script file path, minus the script name, plus the extra path
      //is the translated path, do this before we convert the slashes in the
      //extra path
      strcpy(RequestFields.PathTranslatedStr, ScriptFilePath);
      i = strlen(RequestFields.PathTranslatedStr) + 1; //We can skip the NULL
      while ((i > 0) && (RequestFields.PathTranslatedStr[i] != '\\') &&
         (RequestFields.PathTranslatedStr[i] != '/') ) {
         i--;
         }
      RequestFields.PathTranslatedStr[i] = '\0';
      strcat(RequestFields.PathTranslatedStr, RequestFields.PathInfoStr);

      ThreadDebugMessage(RequestInfo.ThreadNum, "Got Translated Path");
		ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.PathTranslatedStr);

      //Convert the slashes in the extra path info
      i = 0;
      while(RequestFields.PathInfoStr[i] != '\0') {
      	if (RequestFields.PathInfoStr[i] == '\\') {
         	RequestFields.PathInfoStr[i] = '/';
         	}
         i++;
      	}
      ThreadDebugMessage(RequestInfo.ThreadNum, "Got PathInfo");
		ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.PathInfoStr);

      //Script Name is the URI minus the extra path info
      int ScriptNameStrLen;
      ScriptNameStrLen = strlen(URIStr) - strlen(RequestFields.PathInfoStr);
      strncpy(RequestFields.ScriptNameStr, URIStr, ScriptNameStrLen);
      RequestFields.ScriptNameStr[ScriptNameStrLen] = '\0';
      ThreadDebugMessage(RequestInfo.ThreadNum, "Got ScriptName");
		ThreadDebugMessage(RequestInfo.ThreadNum, RequestFields.ScriptNameStr);

      //If we didn't find it send a 404
      if ((FileAttr == 0xFFFFFFFF) ||
          ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)) {
         SendHTTPError(404, "File Not Found", "Could not find the requested element", RequestInfo, RequestFields);
      	}
      else {
		   switch(Scripting) {
			   case SCRIPTING_CGI:
				   ProcessCGIScript(RequestInfo, RequestFields, QueryStr, ScriptFilePath);
				   break;
			   case SCRIPTING_WINCGI:
				   //ProcessWinCGIScript(RequestInfo, RequestFields, QueryStr, ScriptFilePath);
               SendHTTPError(500, "Internal Server Error", "WinCGI no longer supported", RequestInfo, RequestFields);
				   break;
			   case SCRIPTING_ISAPI:
				   ProcessISAPIScript(RequestInfo, RequestFields, QueryStr, ScriptFilePath);
				   break;
			   default:
				   SendHTTPError(500, "Internal Server Error", "Unknown scripting value", RequestInfo, RequestFields);
				   break;
				   }
		   }
      }
	}
/******************************************************************************/
