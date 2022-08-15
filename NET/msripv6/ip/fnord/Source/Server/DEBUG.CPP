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
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "build.h"
#include "error.h"
#include "debug.h"
#pragma hdrstop

/*
Implementation Notes: I used direct Win32 functions for file IO so I
	wouldn't have the link in the ANSI file stuff.
*/

#ifdef BUILD_DEBUG

//Private Data
static char LogDir[MAX_PATH];
static char DebugLogPath[MAX_PATH];
static CRITICAL_SECTION DebugLogCritSec;

//Public Functions
/******************************************************************************/
void OpenDebugLog() {
   InitializeCriticalSection(&DebugLogCritSec);

	GetCurrentDirectory(MAX_PATH, LogDir);

	strcpy(DebugLogPath, LogDir);
	strcat(DebugLogPath, "\\DEBUG.TXT");
	}
/******************************************************************************/
void CloseDebugLog() {
	HANDLE DebugLog;
	DWORD NumWritten;

	DebugLog = CreateFile(DebugLogPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
	SetFilePointer(DebugLog, 0, 0, FILE_END); //Append to end

	WriteFile(DebugLog, "-\r\n", 1, &NumWritten, NULL);
	CloseHandle(DebugLog);

   DeleteCriticalSection(&DebugLogCritSec);
	}
/******************************************************************************/
void DebugMessage(char *Msg) {
	HANDLE DebugLog;
	DWORD NumWritten;

   EnterCriticalSection(&DebugLogCritSec);

	DebugLog = CreateFile(DebugLogPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
	SetFilePointer(DebugLog, 0, 0, FILE_END); //Append to end

	WriteFile(DebugLog, Msg, strlen(Msg), &NumWritten, NULL);
	WriteFile(DebugLog, "\r\n", 2, &NumWritten, NULL);
	CloseHandle(DebugLog);

   LeaveCriticalSection(&DebugLogCritSec);
	}
/******************************************************************************/
void ThreadDebugMessage(int ThreadNum, char *Msg) {
	HANDLE DebugLog;
	DWORD NumWritten;
   char ThreadDebugLogPath[MAX_PATH];
   char NumStr[17];

   //Build the file name
   strcpy(ThreadDebugLogPath, LogDir);
	strcat(ThreadDebugLogPath, "\\DEBUG");
   itoa(ThreadNum, NumStr, 10);
   strcat(ThreadDebugLogPath, NumStr);
   strcat(ThreadDebugLogPath, ".TXT");

   DebugLog = CreateFile(ThreadDebugLogPath, GENERIC_WRITE, FILE_SHARE_READ,
   	NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
   SetFilePointer(DebugLog, 0, 0, FILE_END); //Append to end of file

   WriteFile(DebugLog, Msg, strlen(Msg), &NumWritten, NULL);
   WriteFile(DebugLog, "\r\n", 2, &NumWritten, NULL);
   CloseHandle(DebugLog);
	}
/******************************************************************************/
void Assert(BOOL Cond, char *FailMsg) {
	if (Cond != TRUE) {
		HANDLE DebugLog;
		DWORD NumWritten;

		DebugLog = CreateFile(DebugLogPath, GENERIC_WRITE, FILE_SHARE_READ,
			NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
		SetFilePointer(DebugLog, 0, 0, FILE_END); //Append to end of file

		WriteFile(DebugLog, FailMsg, strlen(FailMsg), &NumWritten, NULL);
		WriteFile(DebugLog, "\r\n", 2, &NumWritten, NULL);
		CloseHandle(DebugLog);
		}
	}
/******************************************************************************/
#endif //#ifdef BUILD_DEBUG