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

//Private Data
static char ServerNameStr[REG_MAX_SERVER_NAME + 1];

static WORD PortNum;

static int InitNumThreads;
static int MaxNumThreads;
static int NumThreadsKeepFree;
static UINT ThreadCompactPeriod;
static int ThreadCompactLaziness;

static BOOL ScriptDNS;

static char IndexFileNameStr[MAX_PATH];
static char ErrorMsgDirStr[MAX_PATH];
static char TempDirStr[MAX_PATH];

static char LogDirStr[MAX_PATH];

static BOOL ComLogEnabled;
static char ComLogFileNameStr[MAX_PATH];
static BOOL ComLogConvertIP;

static BOOL CntLogEnabled;
static char CntLogFileNameStr[MAX_PATH];
static BOOL CntLogCountFiles;
static BOOL CntLogCountConnects;
static BOOL CntLogCountKBytes;

static BOOL RefLogEnabled;
static char RefLogFileNameStr[MAX_PATH];

/******************************************************************************/
int GetRegFlag(BOOL &Flag, HKEY RegKey, char *ValName) {
	char BoolStr[4];
	DWORD ValueType;
	DWORD BuffSize = 3;

	if (RegQueryValueEx(RegKey, ValName, 0, &ValueType,
		(LPBYTE)BoolStr, &BuffSize) != ERROR_SUCCESS) {
		return -1;
		}
	if (strcmp(BoolStr, "1") == 0)
		Flag = TRUE;
	else
		Flag = FALSE;
	return 0;
	}
/******************************************************************************/
void LoadRegistryVars() {
	DWORD ValueType;
	DWORD BuffSize;

   //----------------------------General Server---------------------
   HKEY ServerKeyHandle;

   //Open Server Key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server", 0,
		KEY_ALL_ACCESS, &ServerKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open server registry key");
		return;
		}

   //Get the server name
   BuffSize = REG_MAX_SERVER_NAME;
	if (RegQueryValueEx(ServerKeyHandle, "Server Address", 0, &ValueType,
		(LPBYTE)ServerNameStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get server address from registry");
		return;
		}

   //If it's blank get it from netio
   if (ServerNameStr[0] == 0) {
#ifdef MSRIPv6
        // Require this to be configured.
		LogCriticalError("Server address not configured");
		return;
#else
   	strcpy(ServerNameStr, GetLocalName());
#endif
   	}

   //Close Server Key
	if (RegCloseKey(ServerKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing HTTPD registry key");
		}


	//----------------------------HTTPD---------------------
	HKEY HTTPDKeyHandle;
	char InitNumThreadsStr[6];
   char MaxNumThreadsStr[6];
   char NumThreadsKeepFreeStr[6];
	char ThreadCompactPeriodStr[6];
	char ThreadCompactLazinessStr[6];
	char PortNumStr[6];

	//Open HTTPD Key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\HTTPD", 0,
		KEY_ALL_ACCESS, &HTTPDKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open HTTPD registry key");
		return;
		}

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Initial Number of Threads", 0, &ValueType,
		(LPBYTE)InitNumThreadsStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Initial Number of Threads from registry");
		return;
		}
	InitNumThreads = atoi(InitNumThreadsStr);

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Maximum Number of Threads", 0, &ValueType,
		(LPBYTE)MaxNumThreadsStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Maximum Number of Threads from registry");
		return;
		}
	MaxNumThreads = atoi(MaxNumThreadsStr);

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Number of Threads to Keep Free", 0, &ValueType,
		(LPBYTE)NumThreadsKeepFreeStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Number of Threads to Keep Free from registry");
		return;
		}
	NumThreadsKeepFree = atoi(NumThreadsKeepFreeStr);

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Thread Compact Period", 0, &ValueType,
		(LPBYTE)ThreadCompactPeriodStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Thread Compact Period from registry");
		return;
		}
	ThreadCompactPeriod = ((UINT) atoi(ThreadCompactPeriodStr)) * 1000; //Adjust to milliseconds

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Thread Compact Laziness", 0, &ValueType,
		(LPBYTE)ThreadCompactLazinessStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Thread Compact Laziness from registry");
		return;
		}
	ThreadCompactLaziness = atoi(ThreadCompactLazinessStr);

	BuffSize = 5;
	if (RegQueryValueEx(HTTPDKeyHandle, "Port Number", 0, &ValueType,
		(LPBYTE)PortNumStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get port number from registry");
		return;
		}
	PortNum = (WORD) atoi(PortNumStr);

	if (GetRegFlag(ScriptDNS, HTTPDKeyHandle, "DNS Lookups for Scripts") != 0) {
		LogCriticalError("Couldn't get Script DNS flag from registry");
		return;
		}

   BuffSize = MAX_PATH;
	if (RegQueryValueEx(HTTPDKeyHandle, "Index File Name", 0, &ValueType,
		(LPBYTE)IndexFileNameStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Index File Name from registry");
		return;
		}

	BuffSize = MAX_PATH;
	if (RegQueryValueEx(HTTPDKeyHandle, "Error Message Path", 0, &ValueType,
		(LPBYTE)ErrorMsgDirStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Error Message Path from registry");
		return;
		}
	//Put the \ at the end if it's not there already
	if (ErrorMsgDirStr[strlen(ErrorMsgDirStr) - 1] != '\\') {
		ErrorMsgDirStr[strlen(ErrorMsgDirStr)] = '\\';
		ErrorMsgDirStr[strlen(ErrorMsgDirStr) + 1] = 0;
		}

	BuffSize = MAX_PATH;
	if (RegQueryValueEx(HTTPDKeyHandle, "Temp Directory", 0, &ValueType,
		(LPBYTE)TempDirStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Temp Directory from registry");
		return;
		}
	//Put the \ at the end if it's not there already
	if (TempDirStr[strlen(TempDirStr) - 1] != '\\') {
		TempDirStr[strlen(TempDirStr)] = '\\';
		TempDirStr[strlen(TempDirStr) + 1] = 0;
		}

	//Close HTTPD Key
	if (RegCloseKey(HTTPDKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing HTTPD registry key");
		}

	//-----------------------Logging----------------------
	HKEY LogsKeyHandle;
	HKEY ComLogKeyHandle;
	HKEY CntLogKeyHandle;
	HKEY RefLogKeyHandle;

	//Open Logs Key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\Logs", 0,
		KEY_ALL_ACCESS, &LogsKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Logs registry key");
		return;
		}

	BuffSize = 300;
	if (RegQueryValueEx(LogsKeyHandle, "Log Path", 0, &ValueType,
		(LPBYTE)LogDirStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Log Path from registry");
		return;
		}
	//Put the \ at the end if it's not there already
	if (LogDirStr[strlen(LogDirStr) - 1] != '\\') {
		LogDirStr[strlen(LogDirStr)] = '\\';
		LogDirStr[strlen(LogDirStr) + 1] = 0;
		}

	//Open the common log key
	if (RegOpenKeyEx(LogsKeyHandle, "HTTPD Common", 0,
		KEY_ALL_ACCESS, &ComLogKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Common Log registry key");
		return;
		}

	//Get common log flags
	if (GetRegFlag(ComLogEnabled, ComLogKeyHandle, "Enabled") != 0) {
		LogCriticalError("Couldn't get Common Log Enabled flag from registry");
		return;
		}

   BuffSize = MAX_PATH;
	if (RegQueryValueEx(ComLogKeyHandle, "File Name", 0, &ValueType,
		(LPBYTE)ComLogFileNameStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Common Log File Name from registry");
		return;
		}

	if (GetRegFlag(ComLogConvertIP, ComLogKeyHandle, "Convert IP") != 0) {
		LogCriticalError("Couldn't get Common Log Convert IP flag from registry");
		return;
		}

	//Close the common log key
	if (RegCloseKey(ComLogKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Common Log registry key");
		}

	//Open the count log key
	if (RegOpenKeyEx(LogsKeyHandle, "HTTPD Count", 0,
		KEY_ALL_ACCESS, &CntLogKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Count Log registry key");
		return;
		}

	//Get count log flags
	if (GetRegFlag(CntLogEnabled, CntLogKeyHandle, "Enabled") != 0) {
		LogCriticalError("Couldn't get Count Log Enabled flag from registry");
		return;
		}

	BuffSize = MAX_PATH;
	if (RegQueryValueEx(CntLogKeyHandle, "File Name", 0, &ValueType,
		(LPBYTE)CntLogFileNameStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Count Log File Name from registry");
		return;
		}

	if (GetRegFlag(CntLogCountFiles, CntLogKeyHandle, "Count Files") != 0) {
		LogCriticalError("Couldn't get Count Log Count Files flag from registry");
		return;
		}

	if (GetRegFlag(CntLogCountConnects, CntLogKeyHandle, "Count Connects") != 0) {
		LogCriticalError("Couldn't get Count Log Count Connects flag from registry");
		return;
		}

	if (GetRegFlag(CntLogCountKBytes, CntLogKeyHandle, "Count KBytes") != 0) {
		LogCriticalError("Couldn't get Count Log Count KBytes flag from registry");
		return;
		}

	//Close the count log key
	if (RegCloseKey(CntLogKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Count Log registry key");
		}

	//Open the refernce log key
	if (RegOpenKeyEx(LogsKeyHandle, "HTTPD Reference", 0,
		KEY_ALL_ACCESS, &RefLogKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Reference Log registry key");
		return;
		}

	//Get reference log flags
	if (GetRegFlag(RefLogEnabled, RefLogKeyHandle, "Enabled") != 0) {
		LogCriticalError("Couldn't get Reference Log Enabled flag from registry");
		return;
		}

	BuffSize = MAX_PATH;
	if (RegQueryValueEx(RefLogKeyHandle, "File Name", 0, &ValueType,
		(LPBYTE)RefLogFileNameStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get Reference Log File Name from registry");
		return;
		}

	//Close the reference log key
	if (RegCloseKey(RefLogKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Reference Log registry key");
		}

	//Close Log Key
	if (RegCloseKey(LogsKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Logs registry key");
		}
	}
/******************************************************************************/
void ReloadRegistryVars() {
	UnloadRegistryVars();
	LoadRegistryVars();
	}
/******************************************************************************/
void UnloadRegistryVars() {
	//No cleanup needed
	}
/******************************************************************************/

/* Query Functions */
char *GetServerName() { return ServerNameStr; }

WORD GetPortNum() { return PortNum; }

int GetInitNumThreads() { return InitNumThreads; }
int GetMaxNumThreads() { return MaxNumThreads; }
int GetNumThreadsKeepFree() { return NumThreadsKeepFree; }
UINT GetThreadCompactPeriod() { return ThreadCompactPeriod; }
int GetThreadCompactLaziness() { return ThreadCompactLaziness; }

BOOL GetScriptDNS() { return ScriptDNS; }

char *GetIndexFileName() { return IndexFileNameStr; }
char *GetErrorMsgPath() { return ErrorMsgDirStr; }
char *GetServerTempDir() { return TempDirStr; }

char *GetLogPath() { return LogDirStr; }
void GetCommonLogFlags(BOOL &Enabled, char* &FileName, BOOL &LookUpIP) {
	Enabled = ComLogEnabled;
   FileName = ComLogFileNameStr;
	LookUpIP = ComLogConvertIP;
	}
void GetCountLogFlags(BOOL &Enabled, char* &FileName, BOOL &CountFiles, BOOL &CountConnects,
	BOOL &CountKBytes) {
	Enabled = CntLogEnabled;
   FileName = CntLogFileNameStr;
	CountFiles = CntLogCountFiles;
	CountConnects = CntLogCountConnects;
	CountKBytes = CntLogCountKBytes;
	}
void GetReferenceFlags(BOOL &Enabled, char* &FileName) {
	Enabled = RefLogEnabled;
   FileName = RefLogFileNameStr;
	}
/******************************************************************************/

