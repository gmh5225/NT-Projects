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
#include "parse.h"
#include "registry.h"

//Private Data
//Registry Vars
static BOOL ComLogEnabled;
static char *ComLogFileNameStr;
static BOOL ComLogLookupIP;

static BOOL CntLogEnabled;
static char *CntLogFileNameStr;
static BOOL CntLogCountConnects;
static BOOL CntLogCountFiles;
static BOOL CntLogCountKBytes;

static BOOL RefLogEnabled;
static char *RefLogFileNameStr;

//LogPaths
static char ComLogPath[MAX_PATH];
static char CntLogPath[MAX_PATH];
static char RefLogPath[MAX_PATH];

//Log Critical Sections
static CRITICAL_SECTION CommonLogCritSec;
static CRITICAL_SECTION CountLogCritSec;
static CRITICAL_SECTION ReferenceLogCritSec;


//Public Functions
/******************************************************************************/
void InitHTTPLogs() {
	char *LogDir;

   //Get Registry info
	LogDir = GetLogPath();

	GetCommonLogFlags(ComLogEnabled, ComLogFileNameStr, ComLogLookupIP);
	GetCountLogFlags(CntLogEnabled, CntLogFileNameStr, CntLogCountFiles, CntLogCountConnects, CntLogCountKBytes);
	GetReferenceFlags(RefLogEnabled, RefLogFileNameStr);

   //Set file paths
   strcpy(ComLogPath, LogDir);
	strcat(ComLogPath, ComLogFileNameStr);
	strcpy(CntLogPath, LogDir);
	strcat(CntLogPath, CntLogFileNameStr);
	strcpy(RefLogPath, LogDir);
	strcat(RefLogPath, RefLogFileNameStr);

   //Init critial sections to prevent multiple entries messing things up
	InitializeCriticalSection(&CommonLogCritSec);
	InitializeCriticalSection(&CountLogCritSec);
	InitializeCriticalSection(&ReferenceLogCritSec);
	}
/******************************************************************************/
void CleanUpHTTPLogs() {
	DeleteCriticalSection(&CommonLogCritSec);
	DeleteCriticalSection(&CountLogCritSec);
	DeleteCriticalSection(&ReferenceLogCritSec);
	}
/******************************************************************************/
void HTTPLogCommonEntry(
#ifdef MSRIPv6
    SOCKADDR_IN6
#else
    SOCKADDR_IN
#endif // MSRIPv6
    *Address, int AddressLength ,char *AuthNameStr,
	char *DateStr, char *MethodStr, char *URIStr, char *StatusCodeStr, long Size) {
	char LogEntryStr[500];
	char NumStr[33];
	HANDLE FileHandle;

	if (ComLogEnabled == FALSE)
		return;

	LogEntryStr[0] = 0;

	//Address
	if (ComLogLookupIP == FALSE) {
#ifdef MSRIPv6
		strcat(LogEntryStr, inet6_ntoa(&Address->sin6_addr));
#else
		strcat(LogEntryStr, inet_ntoa(Address->sin_addr));
#endif // MSRIPv6
		}
	else {
		hostent *DNSResult;
#ifdef MSRIPv6
        DNSResult = getipnodebyaddr((char *)&(Address->sin6_addr),
                                    AddressLength, AF_INET6, NULL);
#else
		DNSResult = gethostbyaddr((char *)&(Address->sin_addr), AddressLength, PF_INET);
#endif // MSRIPv6
		if (DNSResult == NULL)
#ifdef MSRIPv6
			strcat(LogEntryStr, inet6_ntoa(&Address->sin6_addr));
#else
			strcat(LogEntryStr, inet_ntoa(Address->sin_addr));
#endif // MSRIPv6
		else
			strcat(LogEntryStr, DNSResult->h_name);
		}

	//Log Name (blank)
	strcat(LogEntryStr, " -");

	//Authorized Name
	if ((AuthNameStr == NULL) || (AuthNameStr[0] == 0)) {
		strcat(LogEntryStr, " -");
		}
	else {
		//Since we support spaces in the user name, we need to conver to undescore
		char ConvAuthNameStr[100];
		int i = 0;
		while (AuthNameStr[i] != 0) {
			if ((AuthNameStr[i] == ' ') || (AuthNameStr[i] == '\t') ) {
				ConvAuthNameStr[i] = '_';
				}
			else {
				ConvAuthNameStr[i] = AuthNameStr[i];
				}
			i++;
			}
		ConvAuthNameStr[i] = 0;
      strcat(LogEntryStr, " ");
		strcat(LogEntryStr, ConvAuthNameStr);
		}

	//Date
	strcat(LogEntryStr, " [");
	strcat(LogEntryStr, DateStr);
	strcat(LogEntryStr, "]");

	//Request
	strcat(LogEntryStr, " \"");
	strcat(LogEntryStr, MethodStr);
	strcat(LogEntryStr, " ");
	strcat(LogEntryStr, URIStr);
	strcat(LogEntryStr, "\" ");

	//Status
	strcat(LogEntryStr, StatusCodeStr);
	strcat(LogEntryStr, " ");

	//Bytes Sent
	ltoa(Size, NumStr, 10);
	strcat(LogEntryStr, NumStr);
	char crlf[3];

	crlf[0]=13;
	crlf[1]=10;
	crlf[2]=0;
	strcat(LogEntryStr, crlf);

	//Write to file
	EnterCriticalSection(&CommonLogCritSec);

	FileHandle = CreateFile(ComLogPath, GENERIC_WRITE, 0, NULL,
									OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	SetFilePointer(FileHandle, 0, NULL, FILE_END);
	DWORD Junk;
	WriteFile(FileHandle, LogEntryStr, strlen(LogEntryStr), &Junk, NULL);
	CloseHandle(FileHandle);

	LeaveCriticalSection(&CommonLogCritSec);
	}
/******************************************************************************/
void HTTPLogCountConnect() {
	char CountStr[33];
	long Count;

	if ((CntLogEnabled == FALSE) || (CntLogCountConnects == FALSE))
		return;

	EnterCriticalSection(&CountLogCritSec);

	GetPrivateProfileString("Totals", "Connects", "0", CountStr, 33, CntLogPath);
	Count = atol(CountStr);
	Count++;
	ltoa(Count, CountStr, 10);
	WritePrivateProfileString("Totals", "Connects", CountStr, CntLogPath);

	LeaveCriticalSection(&CountLogCritSec);
	}
/******************************************************************************/
void HTTPLogCountEntry(char *URIStr, char *DateStr, long Size) {
	char EntryStr[100];
	long Count;
	long KSent;

	if (CntLogEnabled == FALSE)
		return;

	EnterCriticalSection(&CountLogCritSec);

	//Set the file entry
	GetPrivateProfileString("Commands", URIStr, "0", EntryStr, 100, CntLogPath);
	Count = atol(EntryStr);
	Count++;
	ltoa(Count, EntryStr, 10);
	strcat(EntryStr, " ");
	strcat(EntryStr, DateStr);
	WritePrivateProfileString("Commands", URIStr, EntryStr, CntLogPath);

	//Incriment number of files sent
	if (CntLogCountFiles == TRUE) {
		GetPrivateProfileString("Totals", "FilesSentOK", "0", EntryStr, 100, CntLogPath);
		Count = atol(EntryStr);
		Count++;
		ltoa(Count, EntryStr, 10);
		WritePrivateProfileString("Totals", "FilesSentOK", EntryStr, CntLogPath);
		}

	//Incriment number of kbytes sent
	if (CntLogCountKBytes == TRUE) {
		GetPrivateProfileString("Totals", "KBytesSent", "0", EntryStr, 100, CntLogPath);
		Count = atol(EntryStr);
		KSent = Size / 1024;
		if (KSent == 0)
			KSent = 1;
		Count += KSent;
		ltoa(Count, EntryStr, 10);
		WritePrivateProfileString("Totals", "KBytesSent", EntryStr, CntLogPath);
		}

	LeaveCriticalSection(&CountLogCritSec);
	}
/******************************************************************************/
void HTTPLogRefEntry(char *URIStr, char *RefStr, char *DateStr) {
	char EntryStr[100];
	long Count;

	if (RefLogEnabled == FALSE)
		return;

	EntryStr[0] = 0;

	if ((RefStr == NULL) || (RefStr[0] == 0))
		RefStr = "Direct";

	EnterCriticalSection(&ReferenceLogCritSec);

	GetPrivateProfileString(URIStr, RefStr, "0", EntryStr, 100, RefLogPath);
	Count = atol(EntryStr);
	Count++;
	ltoa(Count, EntryStr, 10);
	strcat(EntryStr, " ");
	strcat(EntryStr, DateStr);
	WritePrivateProfileString(URIStr, RefStr, EntryStr, RefLogPath);

	LeaveCriticalSection(&ReferenceLogCritSec);
	}
/******************************************************************************/
