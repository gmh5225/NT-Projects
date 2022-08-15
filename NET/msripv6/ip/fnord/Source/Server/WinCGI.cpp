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
#include "registry.h"
#include "httplog.h"
#include "httpreq.h"
#include "httpsend.h"
#include "wincgi.h"

//Public Functions
/******************************************************************************/
void ProcessWinCGIScript(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields,
	char *QueryStr, char *FilePath) {

	char ThreadNumStr[17];
	char CGIDataFilePath[MAX_PATH];
	char CGIConFilePath[MAX_PATH];
	char CGIOutFilePath[MAX_PATH];
	DWORD NumWritten;
	DWORD TotalNumWritten;

	//Varify that the file name exits
	DWORD FileAttr;
	FileAttr = GetFileAttributes(FilePath);
	if (FileAttr == 0xFFFFFFFF) {
		//Can't find it
		SendHTTPError(404, "File not found", "Could not find WinCGI script", RequestInfo, RequestFields);
		return;
		}
	else if ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
		//It's a directory, we can't run directories <grin>
		SendHTTPError(400, "Querry not supported", "This resource does not support query", RequestInfo, RequestFields);
		return;
		}

	//Generate the 3 file names
	itoa(RequestInfo.ThreadNum, ThreadNumStr, 10);
	//CGIDataFileName = "W_" + "DAT" + Thread Number . "INI"
	strcpy(CGIDataFilePath, GetServerTempDir());
	strcat(CGIDataFilePath, "W_DAT");
	strcat(CGIDataFilePath, ThreadNumStr);
	strcat(CGIDataFilePath, ".INI");

	//CGIConFileName = "W_" + "CON" + Thread Number . "TXT"
	strcpy(CGIConFilePath, GetServerTempDir());
	strcat(CGIConFilePath, "W_CON");
	strcat(CGIConFilePath, ThreadNumStr);
	strcat(CGIConFilePath, ".TXT");

	//CGIOutFileName = "W_" + "OUT" + Thread Number . No Exention
	strcpy(CGIOutFilePath, GetServerTempDir());
	strcat(CGIOutFilePath, "W_OUT");
	strcat(CGIOutFilePath, ThreadNumStr);

	//Create the content file
	HANDLE ConFileHandle;

	ConFileHandle = CreateFile(CGIConFilePath, GENERIC_WRITE, 0, NULL,
										CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (ConFileHandle == INVALID_HANDLE_VALUE) {
		LogError("Failure to create WinCGI Content file");
		SendHTTPError(501, "Internal WinCGI Server Error", "Failure to create WinCGI Content file", RequestInfo, RequestFields);
		return;
		}
	TotalNumWritten = 0;
	while (TotalNumWritten < RequestFields.ContentLength) {
		WriteFile(ConFileHandle, RequestFields.Content + TotalNumWritten,
			RequestFields.ContentLength - TotalNumWritten, &NumWritten, NULL);
		TotalNumWritten += NumWritten;
		}
	CloseHandle(ConFileHandle);

	//Create the INI file
	//We'll dump the CGI and system sections to the IOBuffer since I don't
	//expect them to get very big and I don't wanna waste our time with
	//wimpy calls to WritePrivateProfileString (try saying that 3x fast)
	int BufferIndex = 0;
	int Length;
	char NumStr[33];
	char CRLF[3];
	CRLF[0] = 13;
	CRLF[1] = 10;
	CRLF[2] = 0;

	//[CGI]
	memcpy(RequestInfo.IOBuffer + BufferIndex, "[CGI]", 5);
	BufferIndex += 5;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Request Protocol
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Request Protocol=", 17);
	BufferIndex += 17;
	Length = strlen(RequestFields.VersionStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.VersionStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Request Method
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Request Method=", 15);
	BufferIndex += 15;
	Length = strlen(RequestFields.MethodStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.MethodStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Executable Path
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Executable Path=", 16);
	BufferIndex += 16;
	Length = strlen(FilePath);
	memcpy(RequestInfo.IOBuffer + BufferIndex, FilePath, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Query String
	if (QueryStr[0] != 0) {
		memcpy(RequestInfo.IOBuffer + BufferIndex, "Query String=", 13);
		BufferIndex += 13;
		Length = strlen(QueryStr);
		memcpy(RequestInfo.IOBuffer + BufferIndex, QueryStr, Length);
		BufferIndex += Length;
		memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
		BufferIndex += 2;
		}

	//Referer
	if (RequestFields.RefererStr[0] != 0) {
		memcpy(RequestInfo.IOBuffer + BufferIndex, "Referer=", 8);
		BufferIndex += 8;
		Length = strlen(RequestFields.RefererStr);
		memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.RefererStr, Length);
		BufferIndex += Length;
		memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
		BufferIndex += 2;
		}

	//User Agent
	memcpy(RequestInfo.IOBuffer + BufferIndex, "User Agent=", 11);
	BufferIndex +=11;
	Length = strlen(RequestFields.UserAgentStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.UserAgentStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Content Type
	if (RequestFields.ContentTypeStr[0] != 0) {
		memcpy(RequestInfo.IOBuffer + BufferIndex, "Content Type=", 13);
		BufferIndex += 13;
		Length = strlen(RequestFields.ContentTypeStr);
		memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.ContentTypeStr, Length);
		BufferIndex += Length;
		memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
		BufferIndex += 2;
		}

	//Content Length
	if (RequestFields.ContentLengthStr[0] == 0) {
		memcpy(RequestInfo.IOBuffer + BufferIndex, "Content Length=0", 16);
		BufferIndex += 16;
		}
	else {
		memcpy(RequestInfo.IOBuffer + BufferIndex, "Content Length=", 15);
		BufferIndex += 15;
		Length = strlen(RequestFields.ContentLengthStr);
		memcpy(RequestInfo.IOBuffer + BufferIndex, RequestFields.ContentLengthStr, Length);
		BufferIndex += Length;
		}
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Content File
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Content File=", 13);
	BufferIndex += 13;
	Length = strlen(CGIConFilePath);
	memcpy(RequestInfo.IOBuffer + BufferIndex, CGIConFilePath, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;


	//Server Software
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Server Software=Fnord", 21);
	BufferIndex += 21;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Server Name
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Server Name=", 12);
	BufferIndex += 12;
	Length = strlen(GetServerTempDir());
	memcpy(RequestInfo.IOBuffer + BufferIndex, GetServerTempDir(), Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Server Port
	itoa(GetPortNum(), NumStr, 10);
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Server Port=", 12);
	BufferIndex += 12;
	Length = strlen(NumStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, NumStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//CGI Version
	memcpy(RequestInfo.IOBuffer + BufferIndex, "CGI Version=CGI/1.3 WIN", 23);
	BufferIndex += 23;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Remote Address (I'll do a DNS lookup later...)
	char *AddrStr;
#ifdef MSRIPv6
	AddrStr = inet6_ntoa(&RequestInfo.ClientSockAddr.sin6_addr);
#else
	AddrStr = inet_ntoa(RequestInfo.ClientSockAddr.sin_addr);
#endif // MSRIPv6
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Remote Address=", 15);
	BufferIndex += 15;
	Length = strlen(AddrStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, AddrStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//[System]
	memcpy(RequestInfo.IOBuffer + BufferIndex, "[System]", 8);
	BufferIndex += 8;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Output File
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Output File=", 12);
	BufferIndex += 12;
	Length = strlen(CGIOutFilePath);
	memcpy(RequestInfo.IOBuffer + BufferIndex, CGIOutFilePath, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Content File
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Content File=", 13);
	BufferIndex += 13;
	Length = strlen(CGIConFilePath);
	memcpy(RequestInfo.IOBuffer + BufferIndex, CGIConFilePath, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//GMT Offset
	TIME_ZONE_INFORMATION TZInfo;
	LONG TZBias;
	GetTimeZoneInformation(&TZInfo);
	TZBias = TZInfo.Bias * -60;  //Convert from min to sec and make it GMT + Bias
	ltoa(TZBias, NumStr, 10);
	memcpy(RequestInfo.IOBuffer + BufferIndex, "GMT Offset=", 11);
	BufferIndex += 11;
	Length = strlen(NumStr);
	memcpy(RequestInfo.IOBuffer + BufferIndex, NumStr, Length);
	BufferIndex += Length;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Debug Mode
	memcpy(RequestInfo.IOBuffer + BufferIndex, "Debug Mode=No", 13);
	BufferIndex += 13;
	memcpy(RequestInfo.IOBuffer + BufferIndex, CRLF, 2);
	BufferIndex += 2;

	//Create the content file
	HANDLE DataFileHandle;

	DataFileHandle = CreateFile(CGIDataFilePath, GENERIC_WRITE, 0, NULL,
										CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (DataFileHandle == INVALID_HANDLE_VALUE) {
		LogError("Failure to create WinCGI Data file");
		SendHTTPError(501, "Internal WinCGI Server Error", "Failure to create WinCGI Data file", RequestInfo, RequestFields);
		return;
		}
	TotalNumWritten = 0;
	while (TotalNumWritten < BufferIndex) {
		WriteFile(DataFileHandle, RequestInfo.IOBuffer + NumWritten,
			BufferIndex - TotalNumWritten, &NumWritten, NULL);
		TotalNumWritten += NumWritten;
		}

	//Write Content Data to INI file

	CloseHandle(DataFileHandle);

	//Create the Output file (0 length)
	HANDLE OutFileHandle;

	OutFileHandle = CreateFile(CGIOutFilePath, GENERIC_WRITE, 0, NULL,
										CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (DataFileHandle == INVALID_HANDLE_VALUE) {
		LogError("Failure to create WinCGI Output file");
		SendHTTPError(501, "Internal WinCGI Server Error", "Failure to create WinCGI Output file", RequestInfo, RequestFields);
		return;
		}
	CloseHandle(OutFileHandle);

	//Launch the application (Process)
	STARTUPINFO StartUpInfo;
	PROCESS_INFORMATION ProcessInfo;
	char CommandLine[MAX_PATH];

	strcpy(CommandLine, FilePath);
	strcat(CommandLine, " ");
	strcat(CommandLine, CGIDataFilePath);

	GetStartupInfo(&StartUpInfo);
	StartUpInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartUpInfo.wShowWindow = SW_SHOWMINNOACTIVE;
	if (CreateProcess(0, CommandLine, NULL, NULL, FALSE, DETACHED_PROCESS,
		 NULL, NULL, &StartUpInfo, &ProcessInfo) == FALSE) {
		 LogError("Failure to create WinCGI Process");
		 SendHTTPError(501, "Internal WinCGI Server Error", "Failure to create WinCGI Process", RequestInfo, RequestFields);
		 return;
		 }

	//Wait for it to finish
	if (WaitForSingleObject(ProcessInfo.hProcess, 5 * 60 * 1000) != WAIT_OBJECT_0) {
		//5 min timeout expired
		TerminateProcess(ProcessInfo.hProcess , -1);
		LogError("WinCGI script timed out");
		SendHTTPError(501, "Internal Server Error", "WinCGI Script Timed Out", RequestInfo, RequestFields);
		return;
		}


	//Do we have to add HTTP headers?

	//If we do add them

	//Else just send it
	SendFile(RequestInfo.ClientSocket, CGIOutFilePath,
   	NULL, 0,
   	RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
      NULL, 0,
      RequestInfo.ThreadNum);

	RequestInfo.KeepAlive = FALSE; //Keep alive is experimental, I don't wanna mess with it in CGI

	//Log the transaction
	}
/******************************************************************************/
