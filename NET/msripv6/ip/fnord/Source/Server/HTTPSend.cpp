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
#include "httpmime.h"
#include "httplog.h"
#include "httpreq.h"
#include "httpmap.h"
#include "httpsend.h"

//Private Function Declarations
/*
Function Name: Check IMS Date
Purpose: Checks the string date of an "If Modified Since" header against
	a file date stamp.
Parameters:
	FileTime - Time stamp on file
	IMSStr - "If Modified Since" date string
Returns: TRUE if the file has been modified since the given date or
	the data can not be resolved (the string to date function will log
	any errors)
*/
BOOL CheckIMSDate(SYSTEMTIME &FileTime, char *IMSStr);

//Public Functions
/******************************************************************************/
void SendHTTPFile(char *FileName, RequestInfoT &RequestInfo, RequestFieldsT RequestFields) {
	char Header[512];

	char *ContentType;
	char ContentLength[34];

	SYSTEMTIME CurTime;
	char CurDateStr[100];

	HANDLE FileHandle;
	DWORD FileSize;
	DWORD FileSizeLo;
	DWORD FileSizeHi;
	FILETIME LastWriteFTime;
	SYSTEMTIME LastWriteDate;
	char FileDateStr[100];

	//Current Date
	GetSystemTime(&CurTime);
	DateToOffsetFormatStr(&CurTime, CurDateStr);

	//Open the file for querry (no read or write) access
	FileHandle = CreateFile(FileName, 0, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL,
		OPEN_EXISTING, 0, NULL);
	if (FileHandle == INVALID_HANDLE_VALUE) {
		//FileIO Error
		LogError("File IO Error");
		SendHTTPError(500, "Internal Server Error", "Failure to open requested file", RequestInfo, RequestFields);
		return;
		}
	FileSizeLo = GetFileSize(FileHandle, &FileSizeHi);
	FileSize = FileSizeLo; //I think we're safe for size...

	//FileDate
	if (GetFileTime(FileHandle, NULL, NULL, &LastWriteFTime) != TRUE) {
		LogError("Couldn't get file time");
		CloseHandle(FileHandle);
		SendHTTPError(500, "Internal Server Error", "Failure to get requested file date", RequestInfo, RequestFields);
		return;
		}

   CloseHandle(FileHandle);

	if (FileTimeToSystemTime(&LastWriteFTime, &LastWriteDate) != TRUE) {
		LogError("Failure to convert file time to system time");
		CloseHandle(FileHandle);
		SendHTTPError(500, "Internal Server Error", "Failure to convert file time to system time", RequestInfo, RequestFields);
		return;
		}

	if ((RequestFields.IfModSinceStr[0] != 0) &&
		CheckIMSDate(LastWriteDate, RequestFields.IfModSinceStr) == FALSE) {
		SendHTTPNotModified(RequestInfo, RequestFields);
		return;
		}

	DateToRFCFormatStr(&LastWriteDate, FileDateStr);

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 200 OK\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//Connection
	if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
		strcat(Header, "Connection: Keep-Alive\r\n");
		strcat(Header, "Keep-Alive: timeout=180\r\n");
		ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
	 	RequestInfo.KeepAlive = TRUE;
		}
	else {
		RequestInfo.KeepAlive = FALSE;
		}
	//Last-Modified
	strcat(Header, "Last-Modified: ");
	strcat(Header, FileDateStr);
	strcat(Header, "\r\n");
	//Content Type
	ContentType = GetHTTPMIMEByPath(FileName);
	strcat(Header, "Content-Type: ");
	if (ContentType == NULL) {
		//No match found for type, use HTTP default
		strcat(Header, "application/octet-stream");
		}
	else {
		strcat(Header, ContentType);
		}
	strcat(Header, "\r\n");
	//Content Length
	ltoa(FileSize, ContentLength, 10);
	strcat(Header, "Content-Length: ");
	strcat(Header, ContentLength);
	strcat(Header, "\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");

   //Send the file (if it's not a HEAD request)
   if (strcmp(RequestFields.MethodStr, "HEAD") != 0) {
      ThreadDebugMessage(RequestInfo.ThreadNum, "Sending File");
      SendFile(RequestInfo.ClientSocket, FileName,
      	(BYTE *) Header, strlen(Header),
         RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
         NULL, 0,
         RequestInfo.ThreadNum);
      }
   else {
		//Send header
   	ThreadDebugMessage(RequestInfo.ThreadNum, "Sending HEAD of requested file");
		SendData(RequestInfo.ClientSocket, (BYTE *) Header, strlen(Header), RequestInfo.ThreadNum);
   	}

   //Current Date
	SYSTEMTIME CurLocalTime;
	char CurLocalTimeStr[100];
	GetLocalTime(&CurLocalTime);
	DateToOffsetFormatStr(&CurLocalTime, CurLocalTimeStr);

	//Log the transfer
	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurLocalTimeStr, RequestFields.MethodStr,
		RequestFields.URIStr, "200", FileSize);
	HTTPLogCountEntry(RequestFields.URIStr, CurLocalTimeStr, FileSize);
	HTTPLogRefEntry(RequestFields.URIStr, RequestFields.RefererStr, CurLocalTimeStr);
	}
/******************************************************************************/
void SendHTTPError(int ErrorNum, char *ErrorTitleStr, char *ErrorDescStr, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	char ErrorFileName[MAX_PATH];
	HANDLE FileHandle;
	BOOL FileFound;

	char Header[512];
	char Body[512];

	char ErrorNumStr[17];

	DWORD BodyLength;
	char BodyLengthStr[17];

	int HeaderLength;

	itoa(ErrorNum, ErrorNumStr, 10);

	//Build Data (so we can determine length for the header)
	//Build the error messgae file name
	strcpy(ErrorFileName, GetErrorMsgPath());
	strcat(ErrorFileName, ErrorNumStr);
	strcat(ErrorFileName, ".HTML");

	//Look for the error message file
	FileHandle = CreateFile(ErrorFileName, 0, FILE_SHARE_WRITE | FILE_SHARE_READ,
   	NULL, OPEN_EXISTING, 0, NULL);
	if (FileHandle == INVALID_HANDLE_VALUE) {
		FileFound = FALSE;
		}
	else {
		FileFound = TRUE;
		}

	//Get the size and build message if we have to
	if (FileFound == TRUE) {
		DWORD FileSizeLo;
		DWORD FileSizeHi;

		FileSizeLo = GetFileSize(FileHandle, &FileSizeHi);
		BodyLength = FileSizeLo; //I think we're safe for size...
      CloseHandle(FileHandle);
		}
	else {
		//Didn't find it, build the message manualry
		Body[0] = 0;
		strcat(Body, "<HTML><HEAD><TITLE>Server Error</TITLE></HEAD><BODY>\n");
		strcat(Body, "<H1>Error ");
		strcat(Body, ErrorNumStr);
		strcat(Body, ": ");
		strcat(Body, ErrorTitleStr);
		strcat(Body, "</H1>\n");
		strcat(Body, ErrorDescStr);
		strcat(Body, "\n</BODY></HTML>");
		BodyLength = (DWORD) strlen(Body);
		}

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 ");
	strcat(Header, ErrorNumStr);
	strcat(Header, " ");
	strcat(Header, ErrorDescStr);
	strcat(Header, "\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//Connection
	//Had to comment out persistant connection stuff to work around bug in
	//MS Internet Explorer
	//if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
	//	strcat(Header, "Connection: Keep-Alive\n");
	//	strcat(Header, "Keep-Alive: timeout=180\n");
	//	ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
	//	RequestInfo.KeepAlive = TRUE;
	//	}
	//else {
		RequestInfo.KeepAlive = FALSE;
	//	}
	//Content Type (assume HTML)
	strcat(Header, "Content-Type: text/html\r\n");
	//Content Length
	itoa(BodyLength, BodyLengthStr, 10);
	strcat(Header, "Content-Length: ");
	strcat(Header, BodyLengthStr);
	strcat(Header, "\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");

	HeaderLength = strlen(Header);

   //Send the file if we have one (and if it's not a HEAD request)
   if ((FileFound == TRUE) && (strcmpi(RequestFields.MethodStr, "HEAD") != 0)) {
      ThreadDebugMessage(RequestInfo.ThreadNum, "Sending Error File");
      SendFile(RequestInfo.ClientSocket, ErrorFileName,
      	(BYTE *) Header, strlen(Header),
         RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
         NULL, 0,
         RequestInfo.ThreadNum);
      }
   else {
		//Send header
   	ThreadDebugMessage(RequestInfo.ThreadNum, "Sending Error Message or Header");
		SendData(RequestInfo.ClientSocket, (BYTE *) Header, strlen(Header), RequestInfo.ThreadNum);
   	}
   if ((FileFound == FALSE) && (strcmpi(RequestFields.MethodStr, "HEAD") != 0)) {
   	//Send generated data
   	SendData(RequestInfo.ClientSocket, (BYTE *) Body, BodyLength, RequestInfo.ThreadNum);
   	}

	//Log it
	//Current Date
	SYSTEMTIME CurLocalTime;
	char CurLocalTimeStr[100];
	GetLocalTime(&CurLocalTime);
	DateToOffsetFormatStr(&CurLocalTime, CurLocalTimeStr);

	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurLocalTimeStr, RequestFields.MethodStr,
		RequestFields.URIStr, ErrorNumStr, HeaderLength + BodyLength);
	HTTPLogRefEntry(RequestFields.URIStr, RequestFields.RefererStr, CurLocalTimeStr);
    }
/******************************************************************************/
void SendHTTPRedirect(char *NewURL, RequestInfoT &RequestInfo, RequestFieldsT RequestFields) {

	char Header[500];
	int HeaderLength;

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 301 Moved\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//Location
	strcat(Header, "Location: ");
	strcat(Header, NewURL);
	strcat(Header, "\r\n");
	//Connection
	if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
		strcat(Header, "Connection: Keep-Alive\n");
		strcat(Header, "Keep-Alive: timeout=180\n");
		ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
		RequestInfo.KeepAlive = TRUE;
		}
	else {
		RequestInfo.KeepAlive = FALSE;
		}
	//Content Length
	strcat(Header, "Content-Length: 0\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");
	HeaderLength = strlen(Header);

	//Send header
	SendData(RequestInfo.ClientSocket, (BYTE *) Header, HeaderLength, RequestInfo.ThreadNum);
	//No Data to Send

	//Log it
	//Current Date
	SYSTEMTIME CurLocalTime;
	char CurLocalTimeStr[100];
	GetLocalTime(&CurLocalTime);
	DateToOffsetFormatStr(&CurLocalTime, CurLocalTimeStr);

	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurLocalTimeStr, RequestFields.MethodStr,
		RequestFields.URIStr, "301", HeaderLength);
	}
/******************************************************************************/
void SendHTTPNotModified(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	char Header[500];
	int HeaderLength;

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 304 Not Modified\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//Connection
	if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
		strcat(Header, "Connection: Keep-Alive\r\n");
		strcat(Header, "Keep-Alive: timeout=180\r\n");
		ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
		RequestInfo.KeepAlive = TRUE;
		}
	else {
		RequestInfo.KeepAlive = FALSE;
		}
	//Content Length
	strcat(Header, "Content-Length: 0\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");
	HeaderLength = strlen(Header);

	//Send header
	SendData(RequestInfo.ClientSocket, (BYTE *) Header, HeaderLength, RequestInfo.ThreadNum);
	//No Data to Send

	//Log it
   //Current Date
	SYSTEMTIME CurLocalTime;
	char CurLocalTimeStr[100];
	GetLocalTime(&CurLocalTime);
	DateToOffsetFormatStr(&CurLocalTime, CurLocalTimeStr);

	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurLocalTimeStr, RequestFields.MethodStr,
		RequestFields.URIStr, "304", HeaderLength);
	}
/******************************************************************************/
void SendHTTPBasicChallenge(char *Realm, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	char ErrorFileName[MAX_PATH];
	HANDLE FileHandle;
	BOOL FileFound;

	char Header[512];
	char Body[512];

	DWORD BodyLength;
	char BodyLengthStr[33];

	int HeaderLength;

	//Build Data (so we can determine length for the header)
	//Build the error messgae file name
	strcpy(ErrorFileName, GetErrorMsgPath());
	strcat(ErrorFileName, "401.HTML");

	//Look for the error message file
	FileHandle = CreateFile(ErrorFileName, GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL,
									OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (FileHandle == INVALID_HANDLE_VALUE) {
		FileFound = FALSE;
		}
	else {
		FileFound = TRUE;
		}

	//Get the size and build message if we have to
	if (FileFound == TRUE) {
		DWORD FileSizeLo;
		DWORD FileSizeHi;

		FileSizeLo = GetFileSize(FileHandle, &FileSizeHi);
		BodyLength = FileSizeLo; //I think we're safe for size...
      CloseHandle(FileHandle);
		}
	else {
		//Didn't find it, build the message manualry
		strcpy(Body, "<HTML><HEAD><TITLE>Access Denied</TITLE></HEAD><BODY>\n");
		strcat(Body, "<H1>ACCESS DENIED</H1>\n");
		strcat(Body, "You do not have access to ");
		strcat(Body, Realm);
		strcat(Body, "\n</BODY></HTML>");
		BodyLength = strlen(Body);
		}

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 401 Access Denied\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//WWW-Authenticate: Basic realm=".."
	strcat(Header, "WWW-Authenticate: Basic realm=\"");
	strcat(Header, Realm);
	strcat(Header, "\"\r\n");
	//Connection
	//Had to comment out persistant connection stuff to work around bug in
	//MS Internet Explorer 2
	//if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
	//	strcat(Header, "Connection: Keep-Alive\n");
	//	strcat(Header, "Keep-Alive: timeout=180\n");
	//	ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
	//	RequestInfo.KeepAlive = TRUE;
	//	}
	//else {
		RequestInfo.KeepAlive = FALSE;
	//	}   
	//Content Type (assume HTML)
	strcat(Header, "Content-Type: text/html\n");
	//Content Length
	ultoa(BodyLength, BodyLengthStr, 10);
	strcat(Header, "Content-Length: ");
	strcat(Header, BodyLengthStr);
	strcat(Header, "\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");

	HeaderLength = strlen(Header);

   //Send the file if we have one (and if it's not a HEAD request)
   if ((FileFound == TRUE) && (strcmpi(RequestFields.MethodStr, "HEAD") != 0)) {
      ThreadDebugMessage(RequestInfo.ThreadNum, "Sending Error File");
      SendFile(RequestInfo.ClientSocket, ErrorFileName,
      	(BYTE *) Header, strlen(Header),
         RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
         NULL, 0,
         RequestInfo.ThreadNum);
      }
   else {
		//Send header
   	ThreadDebugMessage(RequestInfo.ThreadNum, "Sending Error Message or Header");
		SendData(RequestInfo.ClientSocket, (BYTE *) Header, strlen(Header), RequestInfo.ThreadNum);
   	}
   if ((FileFound == FALSE) && (strcmpi(RequestFields.MethodStr, "HEAD") != 0)) {
   	//Send generated data
   	SendData(RequestInfo.ClientSocket, (BYTE *) Body, BodyLength, RequestInfo.ThreadNum);
   	}

	//Log it
	//Current Date
	SYSTEMTIME CurLocalTime;
	char CurLocalTimeStr[100];
	GetLocalTime(&CurLocalTime);
	DateToOffsetFormatStr(&CurLocalTime, CurLocalTimeStr);

	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurLocalTimeStr, RequestFields.MethodStr,
		RequestFields.URIStr, "401", HeaderLength + BodyLength);
	}
/******************************************************************************/

//Private Functions

BOOL CheckIMSDate(SYSTEMTIME &FileTime, char *IMSStr) {
	SYSTEMTIME IMSTime;

	if (StrToDate(IMSStr, &IMSTime) != 0)
		return TRUE;

	if(FileTime.wYear > IMSTime.wYear)
		return TRUE;
	if(FileTime.wYear < IMSTime.wYear)
		return FALSE;

	if(FileTime.wMonth > IMSTime.wMonth)
		return TRUE;
	if(FileTime.wMonth < IMSTime.wMonth)
		return FALSE;

	if(FileTime.wDay > IMSTime.wDay)
		return TRUE;
	if(FileTime.wDay < IMSTime.wDay)
		return FALSE;

	if(FileTime.wHour > IMSTime.wHour)
		return TRUE;
	if(FileTime.wHour < IMSTime.wHour)
		return FALSE;

	if(FileTime.wMinute > IMSTime.wMinute)
		return TRUE;
	if(FileTime.wMinute < IMSTime.wMinute)
		return FALSE;

	if(FileTime.wSecond > IMSTime.wSecond)
		return TRUE;
	if(FileTime.wSecond < IMSTime.wSecond)
		return FALSE;

	return FALSE;
	}
