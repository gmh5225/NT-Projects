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
Implementaion Notes:
	Had to use a watchdog thread so I can respond to both new data in the
	pipe and the ending or timeout of the CGI process without polling.  Perhaps
	a watchdog module, with its own thread could be written so I wouldn't have
	the extra thread created for each CGI process.  However, I feel this solution
   is acceptable.

	To do: HTTP Cookies, ACCEPT headers, local redirection.

Contributors:
	Cliff Kotnik - Fixed ISINDEX bug, help with extra path info and
		compatibility with VC++
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
#include "httplog.h"
#include "httpreq.h"
#include "httpsend.h"
#include "cgi.h"

//Private Data
static const DWORD CGITimeout = 5 * 60 * 1000; //5 min timeout

#define MAX_OTHER_CGI_HEADERS 10
struct CGIHTTPHeaders {
	char Status[200];
	char Location[200];
	char ContentType[200];
   char Pragma[200];
	int NumOthers;
	char Others[MAX_OTHER_CGI_HEADERS][200];
	};

struct CGIWatchdogParams {
	HANDLE ProcessToWatch;
	HANDLE ResetTimeoutEvent;
	HANDLE StdoutWriteHandle;
	HANDLE StdoutReadHandle;
	};

#define CGI_ENV_SIZE 4096

//Private Function Declarations
/*
Function Name: CGI Watchdog Thread
Purpose: Watches a CGI process, waiting for a timeout or process termination
	so it can close the Stdout pipe so the request thread knows the process
	has ended.  It also uses an event so it knows if the pipe is processing
	data.
Parameters:
	ParamMem - Handle to memory containing a CGIWatchdogParams structure which
		contains:

		ProcessToWatch - Handle of the CGI process
		ResetTimeoutEvent - Handle of event to be pulsed when the request
			thread receives data from the CGI process
		StdoutWriteHandle - Write end of the Stdout process for the CGI pipe.
			To be closed when the process is done.
*/
void CGIWatchdogThread(HGLOBAL ParamMem);

/*
Function Name: Generate CGI Enviroment
Purpose: Creates an enviroment string for a CGI process
Parameters:
	ScriptEnv - Pointer to the enviroment
	RequestInfo - Request information structure (see HTTPREQ.H)
	RequestFields - Request fields structure (see HTTPREQ.H)
	QueryString - URI Querry String
	FilePath - Local path of the script (example: c:\fnord\cgi-bin\script.exe)
*/
void GenerateCGIEnv(char *ScriptEnv, RequestInfoT &RequestInfo,
	RequestFieldsT RequestFields, char *QueryStr, char *FilePath);

/*
Function Name: Get CGI Headers
Purpose: Parses headers from CGI output "on the fly"
Parameters:
	Headers - Structure containing the headers we have extracted thus far

	Buffer - Pointer to buffer containing the data output by the script.
	NumInBuffer - Amount of data in the buffer
	NumParsed - How much data in buffer has been parsed, updated on return
	DontParse - Set to true on return if told by the output not to parse the headers
	GotHeaders - Set to true on return if we have parsed all of the headers
	ThreadNum - Request thread number, mostly used for debugging
*/
void GetCGIHeaders(CGIHTTPHeaders &Headers, BYTE *Buffer, DWORD NumInBuffer,
	DWORD &NumParsed, BOOL &DontParse, BOOL &GotHeaders, int ThreadNum);

/*
Function Name: Send CGI Headers
Purpose: Sends the CGI headers to the client
Parameters:
	Headers - Structure containing the headers we got durring parsing
	ClientSocket - Socket to the client
	NumSent - Amount of data sent, set on return
	StatusCode - String containing a HTTP status code number for the header
	ThreadNum - Request thread number, mostly used for debugging
*/
int SendCGIHeaders(CGIHTTPHeaders &Headers, SOCKET ClientSocket, DWORD &NumSent,
	char *StatusCode, int ThreadNum);

//Public Functions
/******************************************************************************/
void ProcessCGIScript(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields,
	char *QueryStr, char *FilePath) {

	DWORD TotalSent = 0;
	char StatusCode[10];
	strcpy(StatusCode, "200");

	//Varify the file exits
	DWORD FileAttr;
	FileAttr = GetFileAttributes(FilePath);
	if (FileAttr == 0xFFFFFFFF) {
		//Can't find it
		SendHTTPError(404, "File Not Found", "Could not find CGI script", RequestInfo, RequestFields);
		return;
		}
	else if ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
		//It's a directory, we can't run directories <grin>
		SendHTTPError(405, "Method Not Supported", "This resource does not support query", RequestInfo, RequestFields);
		return;
		}

	char ScriptEnv[CGI_ENV_SIZE];
	GenerateCGIEnv(ScriptEnv, RequestInfo,RequestFields, QueryStr, FilePath);

   //Setup security attributes we can inherit
   SECURITY_ATTRIBUTES InheritSA;

   InheritSA.nLength = sizeof(SECURITY_ATTRIBUTES);
   InheritSA.bInheritHandle = TRUE;
   InheritSA.lpSecurityDescriptor = NULL;

   //Make a string out of the thread number
   char ThreadNumStr[17];
   itoa(RequestInfo.ThreadNum, ThreadNumStr, 10);

   //Create a file for stderr
	HANDLE ScriptStderrHandle;
	char CGIStderrFileName[MAX_PATH];

	//Name the stderr file
	strcpy(CGIStderrFileName, GetServerTempDir());
	strcat(CGIStderrFileName, "CSE");
	strcat(CGIStderrFileName, ThreadNumStr);
	strcat(CGIStderrFileName, ".TXT");

   ScriptStderrHandle = CreateFile(CGIStderrFileName, GENERIC_WRITE,
      FILE_SHARE_READ, &InheritSA, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
 	if (ScriptStderrHandle == INVALID_HANDLE_VALUE) {
 		LogError("Failure to create CGI Stderr file");
 		SendHTTPError(501, "Internal Server Error", "Failure to create CGI Stderr file",  RequestInfo, RequestFields);
 		return;
 		}
   SetFilePointer( ScriptStderrHandle, 0, 0, FILE_END ); //Append to end of file

	//Create a file for stdin
	HANDLE ScriptStdinHandle;
	char CGIStdinFileName[MAX_PATH];

	//Name the stdin file
	strcpy(CGIStdinFileName, GetServerTempDir());
	strcat(CGIStdinFileName, "CSI");
	strcat(CGIStdinFileName, ThreadNumStr);
	strcat(CGIStdinFileName, ".TXT");

	//Write the stdin file
	ScriptStdinHandle = CreateFile(CGIStdinFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ScriptStdinHandle == INVALID_HANDLE_VALUE) {
		LogError("Failure to create CGI Stdin file");
		SendHTTPError(501, "Internal Server Error", "Failure to create CGI Stdin file",  RequestInfo, RequestFields);
		return;
		}
	DWORD TotalNumWritten = 0;
	DWORD NumWritten;
	while (TotalNumWritten < RequestFields.ContentLength) {
		WriteFile(ScriptStdinHandle, RequestFields.Content + TotalNumWritten,
			RequestFields.ContentLength - TotalNumWritten, &NumWritten, NULL);
		TotalNumWritten += NumWritten;
		}
	CloseHandle(ScriptStdinHandle);

	//Reopen it for read access
	ScriptStdinHandle = CreateFile(CGIStdinFileName, GENERIC_READ, 0, &InheritSA,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);


	//Create a pipe for stdout
	HANDLE ScriptStdoutReadHandle;
	HANDLE ScriptStdoutWriteHandle;
	if (CreatePipe(&ScriptStdoutReadHandle, &ScriptStdoutWriteHandle,
		&InheritSA, 4096) == FALSE) {
		LogError("Failure to create CGI Stdout pipe");
		SendHTTPError(501, "Internal Server Error", "Failure to create CGI Stdout pipe", RequestInfo, RequestFields);
		return;
		}

	//Split path to get filename
	char FileName[MAX_PATH];
	char Dir[MAX_PATH];
	char Ext[20];
	SplitPath(FilePath, Dir, FileName);
	GetExtention(FileName, Ext);

	//Execute the program
	STARTUPINFO StartUpInfo;
	PROCESS_INFORMATION ProcessInfo;
	char CommandLine[MAX_PATH];
	char DefDir[MAX_PATH];

	if ((strcmpi("EXE", Ext) == 0) || (strcmpi("BAT", Ext) == 0)) {
		//No executable needed
		CommandLine[0] = 0;
		}
	else {
		//Its an interputed script? find it's executable
		FindExecutable(FilePath, DefDir, CommandLine);
		strcat(CommandLine, " ");
		}

	strcat(CommandLine, FilePath);
	// c.kotnik...only pass QueryStr on command line if it is ISINDEX
	//     ISINDEX contains no = in it
	if (strchr(QueryStr,'=') == NULL) {
		strcat(CommandLine, " ");
		strcat(CommandLine, QueryStr);
		}

	GetStartupInfo(&StartUpInfo);
	StartUpInfo.dwFlags = STARTF_USESHOWWINDOW |  STARTF_USESTDHANDLES;
	StartUpInfo.wShowWindow = SW_HIDE;
	StartUpInfo.hStdInput = ScriptStdinHandle;
	StartUpInfo.hStdOutput = ScriptStdoutWriteHandle;
   StartUpInfo.hStdError = ScriptStderrHandle;
	if (CreateProcess(NULL, CommandLine, &InheritSA, &InheritSA, TRUE, CREATE_NEW_CONSOLE,
		ScriptEnv/*NULL*/, Dir, &StartUpInfo, &ProcessInfo) == FALSE) {
		LogError("Failure to create CGI Process");
		SendHTTPError(501, "Internal Server Error", "Failure to create CGI Process", RequestInfo, RequestFields);
		CloseHandle(ScriptStdinHandle);
		CloseHandle(ScriptStdoutReadHandle);
		CloseHandle(ScriptStdoutWriteHandle);
      CloseHandle(ScriptStderrHandle);
		return;
		}

	//Create reset timeout event
	HANDLE ResetTimeoutEvent;
	ResetTimeoutEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	//Start a watchdog thread
	HANDLE WatchdogParamMem;
	CGIWatchdogParams *WatchdogParams;

	WatchdogParamMem = GlobalAlloc(0, sizeof(CGIWatchdogParams));
	WatchdogParams = (CGIWatchdogParams *) GlobalLock(WatchdogParamMem);
	WatchdogParams->ProcessToWatch = ProcessInfo.hProcess;
	WatchdogParams->ResetTimeoutEvent = ResetTimeoutEvent;
	WatchdogParams->StdoutWriteHandle = ScriptStdoutWriteHandle;
	WatchdogParams->StdoutReadHandle = ScriptStdoutReadHandle;
	GlobalUnlock(WatchdogParamMem);

	#ifdef __BORLANDC__ //Start thread code for Borland C++
	unsigned long ThreadID; //discard 4096
	_beginthreadNT(CGIWatchdogThread, 4096, (void *)WatchdogParamMem, &InheritSA, 0, &ThreadID);
	#else //Start thread code for Visual C++, c.kotnik
	_beginthread(CGIWatchdogThread, 4096, (void *)WatchdogParamMem);
	#endif

	BOOL IOError = FALSE;
	DWORD NumRead;

	if (strnicmp("nph-", FileName, 4) == 0) { //Are we parsing headers?
		//Headers are not parsed.  Dump the data as we get it.
		while(ReadFile(ScriptStdoutReadHandle, RequestInfo.IOBuffer,
			RequestInfo.IOBufferSize, &NumRead, NULL) == TRUE) {

			PulseEvent(ResetTimeoutEvent); //Reset the watchdog timeout
			if (!IOError) {
				if (SendData(RequestInfo.ClientSocket, RequestInfo.IOBuffer, NumRead,
					RequestInfo.ThreadNum) == -1) {
					//Stop sending to client, but continue script on error
					IOError = TRUE;
					}
				TotalSent += NumRead;
				}
			}
		}
	else {
		//Headers are parsed
		CGIHTTPHeaders Headers;
		BOOL SentHeaders = FALSE;
		BOOL GotHeaders = FALSE;
		BOOL DontParse = FALSE;
		DWORD NumInBuffer = 0;
		DWORD NumParsed = 0;

		memset(&Headers, 0, sizeof(CGIHTTPHeaders));

		while(ReadFile(ScriptStdoutReadHandle, RequestInfo.IOBuffer + NumInBuffer,
			RequestInfo.IOBufferSize - NumInBuffer, &NumRead, NULL) == TRUE) {

			PulseEvent(ResetTimeoutEvent); //Reset the watchdog timeout

			NumInBuffer += NumRead;

			if (!GotHeaders) {
				GetCGIHeaders(Headers, RequestInfo.IOBuffer, NumInBuffer,
					NumParsed, DontParse, GotHeaders, RequestInfo.ThreadNum);
				}
			if (GotHeaders && (!SentHeaders)) {
				if (!DontParse) SendCGIHeaders(Headers, RequestInfo.ClientSocket,
					TotalSent, StatusCode, RequestInfo.ThreadNum);
				SentHeaders = TRUE;
				}
			if (SentHeaders) {
				if (!IOError) {
					//All headers parsed, send unparsed data
					if (SendData(RequestInfo.ClientSocket, RequestInfo.IOBuffer+ NumParsed, NumInBuffer - NumParsed,
						RequestInfo.ThreadNum) == -1) {
						//Stop sending to client, but continue script on error
						IOError = TRUE;
						}
					TotalSent += NumInBuffer - NumParsed;
					}
				}
         NumInBuffer = 0;
         NumParsed = 0;
			}

		}

	//Cleanup the handles
   ThreadDebugMessage(RequestInfo.ThreadNum, "Closing stdin & stdout read");
	CloseHandle(ScriptStdinHandle);
	CloseHandle(ScriptStdoutReadHandle);
	//ScriptStdoutReadHandle is closed by the watchdog
   CloseHandle(ScriptStderrHandle);

	//I don't wanna mess with Keep alive in CGI
	RequestInfo.KeepAlive = FALSE;

	//Current Date
	SYSTEMTIME CurDate;
	char CurDateStr[100];
	GetSystemTime(&CurDate);
	DateToOffsetFormatStr(&CurDate, CurDateStr);

	//Log the transaction
	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurDateStr, RequestFields.MethodStr,
		RequestFields.URIStr, StatusCode, TotalSent);
	HTTPLogCountEntry(RequestFields.URIStr, CurDateStr, TotalSent);
	HTTPLogRefEntry(RequestFields.URIStr, RequestFields.RefererStr, CurDateStr);

	}
/******************************************************************************/

void CGIWatchdogThread(HGLOBAL ParamMem) {
	CGIWatchdogParams *Parameters;
	HANDLE ProcessToWatch;
	HANDLE ResetTimeoutEvent;
	HANDLE StdoutWriteHandle;
	//HANDLE StdoutReadHandle;
	HANDLE WaitObjects[2];
	DWORD WaitResult;

	//Get the events from the parameter memory
	Parameters = (CGIWatchdogParams *)GlobalLock(ParamMem);

	ProcessToWatch = Parameters->ProcessToWatch;
	ResetTimeoutEvent = Parameters->ResetTimeoutEvent;
	StdoutWriteHandle = Parameters->StdoutWriteHandle;
	//StdoutReadHandle = Parameters->StdoutReadHandle;

	GlobalUnlock(ParamMem);

	//Free parameter memory
	GlobalFree(ParamMem);

	//Set up the wait objects array
	WaitObjects[0] = ResetTimeoutEvent;
	WaitObjects[1] = ProcessToWatch;

	//Wait for process termination with a timeout and a timeout reset event
	do {
		WaitResult = WaitForMultipleObjects(2, WaitObjects, FALSE, CGITimeout);
		} while(WaitResult == WAIT_OBJECT_0); //While we just reset the timeout

	//If we timed out, kill the process
	if (WaitResult == WAIT_TIMEOUT) {
   	DebugMessage("Watchdog killing process");
		//Send the termination request
		TerminateProcess(ProcessToWatch, -1);
		//Wait for the process to end
		WaitForSingleObject(ProcessToWatch, CGITimeout);
		}

	//Wait for pipe to empty
   //This code didn't work under NT 4.0, not sure if it's nessisary,
   //depends on how you interput the gospel in the Win32 help file, so
   //commenting it out and just gonna sleep a bit...
   //BTW: the PeekNamedPipe call BLOCKED under NT 4!!!  :(
   Sleep(1000); //Sleep for 1 sec
	//DWORD NumToRead;
	//PeekNamedPipe(StdoutReadHandle, NULL, 0, NULL, &NumToRead, NULL);
	//while(NumToRead > 0) {
	//	Sleep(0);
	// 	PeekNamedPipe(StdoutReadHandle, NULL, 0, NULL, &NumToRead, NULL);
	//	}

	//Close the write end of the pipe
	CloseHandle(StdoutWriteHandle);

	_endthread();
	}


void GenerateCGIEnv(char *ScriptEnv, RequestInfoT &RequestInfo,
	RequestFieldsT RequestFields, char *QueryStr, char * /*FilePath*/) {

	int ScriptEnvIndex = 0;
	int Length;
	char NumStr[33];

   //Copy the parent process's enviroment
   int i;
   char *ParentEnv;

   ParentEnv = (char *) GetEnvironmentStrings();
   i = 0;
   while ((ParentEnv[i] != '\0') || (ParentEnv[i+1] != '\0')) {
      ScriptEnv[i] = ParentEnv[i];
      ScriptEnvIndex++;
      i++;
      }
   ScriptEnv[i] = '\0';
   ScriptEnvIndex++;

   //Generate the enviroment string fields

	//The NULL part of the string is included, since the enviroment is a buffer
	//containing null terminted strings.  The block is ended with a NULL.
   //CONTENT_ENCODING
	if (RequestFields.ContentEncodingStr[0] != '\0') {
		memcpy(ScriptEnv + ScriptEnvIndex, "CONTENT_ENCODING=", 13);
		ScriptEnvIndex += 13;
		Length = strlen(RequestFields.ContentEncodingStr) + 1;
		memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.ContentEncodingStr, Length);
		ScriptEnvIndex += Length;
		}
	//CONTENT_TYPE
	if (RequestFields.ContentTypeStr[0] != '\0') {
		memcpy(ScriptEnv + ScriptEnvIndex, "CONTENT_TYPE=", 13);
		ScriptEnvIndex += 13;
		Length = strlen(RequestFields.ContentTypeStr) + 1;
		memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.ContentTypeStr, Length);
		ScriptEnvIndex += Length;
		}
	//CONTENT_LENGTH
	if (RequestFields.ContentLengthStr[0] == '\0') {
		memcpy(ScriptEnv + ScriptEnvIndex, "CONTENT_LENGTH=0", 17);
		ScriptEnvIndex += 17;
		}
	else {
		memcpy(ScriptEnv + ScriptEnvIndex, "CONTENT_LENGTH=", 15);
		ScriptEnvIndex += 15;
		Length = strlen(RequestFields.ContentLengthStr) + 1;
		memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.ContentLengthStr, Length);
		ScriptEnvIndex += Length;
		}

	//SERVER_SOFTWARE
	memcpy(ScriptEnv + ScriptEnvIndex, "SERVER_SOFTWARE=Fnord", 22);
	ScriptEnvIndex += 22;

	//SERVER_NAME
	memcpy(ScriptEnv + ScriptEnvIndex, "SERVER_NAME=", 12);
	ScriptEnvIndex += 12;
	Length = strlen(GetServerName()) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, GetServerName(), Length);
	ScriptEnvIndex += Length;

	//GATEWAY_INTERFACE
	memcpy(ScriptEnv + ScriptEnvIndex, "GATEWAY_INTERFACE=CGI/1.1", 26);
	ScriptEnvIndex += 26;

	//REQUEST_METHOD
	memcpy(ScriptEnv + ScriptEnvIndex, "REQUEST_METHOD=", 15);
	ScriptEnvIndex += 15;
	Length = strlen(RequestFields.MethodStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.MethodStr, Length);
	ScriptEnvIndex += Length;

	//SERVER_PROTOCOL
	memcpy(ScriptEnv + ScriptEnvIndex, "SERVER_PROTOCOL=", 16);
	ScriptEnvIndex += 16;
	Length = strlen(RequestFields.VersionStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.VersionStr, Length);
	ScriptEnvIndex += Length;

	//SERVER_PORT
	itoa(GetPortNum(), NumStr, 10);
	memcpy(ScriptEnv + ScriptEnvIndex, "SERVER_PORT=", 12);
	ScriptEnvIndex += 12;
	Length = strlen(NumStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, NumStr, Length);
	ScriptEnvIndex += Length;

	//REMOTE_USER
	//AUTH_TYPE
	if (RequestFields.AuthorizedUserStr[0] != '\0') {
		memcpy(ScriptEnv + ScriptEnvIndex, "REMOTE_USER=", 12);
		ScriptEnvIndex += 12;
		Length = strlen(RequestFields.AuthorizedUserStr) + 1;
		memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.AuthorizedUserStr, Length);
		ScriptEnvIndex += Length;
		memcpy(ScriptEnv + ScriptEnvIndex, "AUTH_TYPE=Basic", 16);
		ScriptEnvIndex += 16;
		}

	//REMOTE_HOST
	hostent *DNSResult;
	char HostName[200];

	memcpy(ScriptEnv + ScriptEnvIndex, "REMOTE_HOST=", 12);
	ScriptEnvIndex += 12;
   if (GetScriptDNS() == TRUE) { //Do a reverse DNS lookup
#if MSRIPv6

       DNSResult = getipnodebyaddr((char *)
                                   &(RequestInfo.ClientSockAddr.sin6_addr),
                                   RequestInfo.AddrLen, AF_INET6, NULL);       
#else
       DNSResult = gethostbyaddr((char *)&(RequestInfo.ClientSockAddr.sin_addr), RequestInfo.AddrLen, PF_INET);
#endif // MSRIPv6
      }
   else {                        //Don't bother
      DNSResult = NULL;
      }
	if (DNSResult == NULL) {
#if MSRIPv6
		strcpy(HostName, inet6_ntoa(&RequestInfo.ClientSockAddr.sin6_addr));
#else
		strcpy(HostName, inet_ntoa(RequestInfo.ClientSockAddr.sin_addr));
#endif // MSRIPv6
      }
	else {
		strcpy(HostName, DNSResult->h_name);
      }
	Length = strlen(HostName) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, HostName, Length);
	ScriptEnvIndex += Length;

	//REMOTE_ADDR
	char *AddrStr;
#ifdef MSRIPv6
	AddrStr = inet6_ntoa(&RequestInfo.ClientSockAddr.sin6_addr);
#else
	AddrStr = inet_ntoa(RequestInfo.ClientSockAddr.sin_addr);
#endif // MSRIPv6
	memcpy(ScriptEnv + ScriptEnvIndex, "REMOTE_ADDR=", 12);
	ScriptEnvIndex += 12;
	Length = strlen(AddrStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, AddrStr, Length);
	ScriptEnvIndex += Length;

	//QUERY_STRING
   memcpy(ScriptEnv + ScriptEnvIndex, "QUERY_STRING=", 13);
   ScriptEnvIndex += 13;
   Length = strlen(QueryStr) + 1;
   memcpy(ScriptEnv + ScriptEnvIndex, QueryStr, Length);
   ScriptEnvIndex += Length;

	//PATH_INFO
   memcpy(ScriptEnv + ScriptEnvIndex, "PATH_INFO=", 10);
   ScriptEnvIndex += 10;
	Length = strlen(RequestFields.PathInfoStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.PathInfoStr, Length);
	ScriptEnvIndex += Length;

	//PATH_TRANSLATED
	memcpy(ScriptEnv + ScriptEnvIndex, "PATH_TRANSLATED=", 16);
	ScriptEnvIndex += 16;
	Length = strlen(RequestFields.PathTranslatedStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.PathTranslatedStr, Length);
	ScriptEnvIndex += Length;

	//SCRIPT_NAME
	memcpy(ScriptEnv + ScriptEnvIndex, "SCRIPT_NAME=", 12);
	ScriptEnvIndex += 12;
	Length = strlen(RequestFields.ScriptNameStr) + 1;
	memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.ScriptNameStr, Length);
	ScriptEnvIndex += Length;

	//HTTP_USER_AGENT
   if (RequestFields.UserAgentStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_USER_AGENT=", 16);
	   ScriptEnvIndex += 16;
	   Length = strlen(RequestFields.UserAgentStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.UserAgentStr, Length);
	   ScriptEnvIndex += Length;
      }

	//HTTP_ACCEPT
   if (RequestFields.AcceptStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_ACCEPT=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.AcceptStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.AcceptStr, Length);
	   ScriptEnvIndex += Length;
      }
	//HTTP_ACCEPT_LANGUAGE
   if (RequestFields.AcceptLangStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_ACCEPT_LANGUAGE=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.AcceptLangStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.AcceptLangStr, Length);
	   ScriptEnvIndex += Length;
      }

   //HTTP_REFERER
   if (RequestFields.RefererStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_REFERER=", 13);
	   ScriptEnvIndex += 13;
	   Length = strlen(RequestFields.RefererStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.RefererStr, Length);
	   ScriptEnvIndex += Length;
      }
   //HTTP_IF_MODIFIED_SINCE
   if (RequestFields.IfModSinceStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_PRAGMA=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.IfModSinceStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.IfModSinceStr, Length);
	   ScriptEnvIndex += Length;
      }
	//HTTP_PRAGMA
   if (RequestFields.PragmaStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_PRAGMA=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.PragmaStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.PragmaStr, Length);
	   ScriptEnvIndex += Length;
      }
	//HTTP_FROM
   if (RequestFields.FromStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_FROM=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.FromStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.FromStr, Length);
	   ScriptEnvIndex += Length;
      }
	//HTTP_DATE
   if (RequestFields.DateStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_DATE=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.DateStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.DateStr, Length);
	   ScriptEnvIndex += Length;
      }
	//HTTP_MIME_VERSION
   if (RequestFields.MIMEVerStr[0] != '\0') {
	   memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_MIME_VERSION=", 12);
	   ScriptEnvIndex += 12;
	   Length = strlen(RequestFields.MIMEVerStr) + 1;
	   memcpy(ScriptEnv + ScriptEnvIndex, RequestFields.MIMEVerStr, Length);
	   ScriptEnvIndex += Length;
      }

   //HTTP_*   (other headers)
   RequestHeaderT OtherHeader;
   for (i=0; i<RequestFields.NumOtherHeaders; i++) {
   	OtherHeader = RequestFields.OtherHeaders[i];

      memcpy(ScriptEnv + ScriptEnvIndex, "HTTP_", 5);
	   ScriptEnvIndex += 5;

		Length = strlen(OtherHeader.Var);
		memcpy(ScriptEnv + ScriptEnvIndex, OtherHeader.Var, Length);
		ScriptEnvIndex += Length;

      memcpy(ScriptEnv + ScriptEnvIndex, "=", 1);
	   ScriptEnvIndex += 1;

		Length = strlen(OtherHeader.Val) + 1; //Include the '\0'
		memcpy(ScriptEnv + ScriptEnvIndex, OtherHeader.Val, Length);
		ScriptEnvIndex += Length;
   	}
	//Terminate the Enviroment Block
	ScriptEnv[ScriptEnvIndex] = 0;
	}

void GetCGIHeaders(CGIHTTPHeaders &Headers, BYTE *Buffer, DWORD NumInBuffer,
	DWORD &NumParsed, BOOL &DontParse, BOOL &GotHeaders, int /*ThreadNum*/) {

	int BufferIndex;
	char LineBuffer[1024];
   char NumStr[17];
	int i;

	BufferIndex = NumParsed;

	BOOL Done = FALSE;

	GotHeaders = FALSE;
	DontParse = FALSE;

	do {
		//Get a line
		i = 0;
		while( (BufferIndex < NumInBuffer) && (Buffer[BufferIndex] != 10)) {
			if ((Buffer[BufferIndex] != 10) && (Buffer[BufferIndex] != 13)) {
				LineBuffer[i] = Buffer[BufferIndex];
				i++;
				}
			BufferIndex++;
			}

		if (BufferIndex == NumInBuffer) {
			//Didn't stop at a line
			//Done = TRUE;
         return;
			}
		else {
			LineBuffer[i] = 0;
			BufferIndex++;
			NumParsed = BufferIndex;
			}

		//Figure out what the line is

		//Is it blank?
		if (LineBuffer[0] == 0) {
			//We're done
			Done = TRUE;
			GotHeaders = TRUE;
			}
		//Is it a HTTP/ status?
		else if (strnicmp(LineBuffer, "HTTP/", 5) == 0) {
			//We don't parse this stuff
			Done = TRUE;
			NumParsed = 0;
			GotHeaders = TRUE;
			DontParse = TRUE;
			}
		//Is it a status header?
		else if (strnicmp(LineBuffer, "Status:", 7) == 0) {
			//Find first non-whitespace
			i = 8;
			while ((LineBuffer[i] != 0) && ((LineBuffer[i] == ' ') || (LineBuffer[i] == '\t'))){
				i++;
				}
			strcpy(Headers.Status, LineBuffer + i);
			}
		//Is it a location header?
		else if (strnicmp(LineBuffer, "Location:", 9) == 0) {
			//Find first non-whitespace
			i = 9;
			while ((LineBuffer[i] != 0) && ((LineBuffer[i] == ' ') || (LineBuffer[i] == '\t'))){
				i++;
				}
			if (LineBuffer[i] == '/') { //Location is a URI, send the given URI
				//We're just redirect to it...
				strcpy(Headers.Location, "Location: http://");
				strcat(Headers.Location, GetServerName());
            if (GetPortNum() != 80) {
               itoa(GetPortNum(), NumStr, 10);
               strcat(Headers.Location, ":");
               strcat(Headers.Location, NumStr);
               }
				strcat(Headers.Location, LineBuffer + i);
				}
			else {
				strcpy(Headers.Location, LineBuffer);
				}
			}
		//Is it a content-type?
		else if (strnicmp(LineBuffer, "Content-type:", 13) == 0) {
			strcpy(Headers.ContentType, LineBuffer);
			}
      //Is it a pragma?
		else if (strnicmp(LineBuffer, "Pragma:", 7) == 0) {
			strcpy(Headers.Pragma, LineBuffer);
			}
		else {
			//Put it as with the Others
			if (Headers.NumOthers < MAX_OTHER_CGI_HEADERS) {
				strcpy(Headers.Others[Headers.NumOthers], LineBuffer);
				Headers.NumOthers++;
				}
			}
		} while (!Done);
	}

int SendCGIHeaders(CGIHTTPHeaders &Headers, SOCKET ClientSocket, DWORD &NumSent,
	char *StatusCode, int ThreadNum) {
	char Header[2048];
	int HeaderLength;

	//Status header
	if (Headers.Status[0] != 0) {
		//Use the given status info
		strcpy(Header, "HTTP/1.0 ");
		strcat(Header, Headers.Status);
      strcat(Header, "\r\n");

		int Junk;
		GetWord(StatusCode, Headers.Status, 0, Junk);
		}
	else if (Headers.Location[0] != 0) {
		//Since we have a location field, then the status is 302, moved temp.
		strcpy(Header, "HTTP/1.0 302 MOVED\r\n");
		strcpy(StatusCode, "302");
		}
	else {
		//Send the usual 200 OK
		strcpy(Header, "HTTP/1.0 200 OK\r\n");
		strcpy(StatusCode, "200");
		}

	//Location Header
	if (Headers.Location[0] != 0) {
		strcat(Header, Headers.Location);
		strcat(Header, "\r\n");
		}

	//Pragma Header
	if (Headers.Pragma[0] != 0) {
		strcat(Header, Headers.Pragma);
		strcat(Header, "\r\n");
		}
    else {
   	//Default to no-cache to be nice to proxies
      strcat(Header, "Pragma: no-cache\r\n");
   	}

	//Content Type
	if (Headers.ContentType[0] != 0) {
		strcat(Header, Headers.ContentType);
		strcat(Header, "\r\n");
		}
   else {
   	//Default to text/html (so .exe or .cgi or whatever doesn't mess up
      //browsers, like MSIE 3, that figure out via extention if no MIME is
      //given
      strcat(Header, "Content-type: text/html\r\n");
   	}

	//Other headers
	int i;
	for (i=0; i<Headers.NumOthers; i++) {
		strcat(Header, Headers.Others[i]);
		strcat(Header, "\r\n");
		}
	strcat(Header, "Server: Fnord\r\n");

	//Send a trailing CRLF
   strcat(Header, "\r\n");

	HeaderLength = strlen(Header);

	//Send the headers
	NumSent = HeaderLength;
	return SendData(ClientSocket, (BYTE *) Header, HeaderLength, ThreadNum);
	}
