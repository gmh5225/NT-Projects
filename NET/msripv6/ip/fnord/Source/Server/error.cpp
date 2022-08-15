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
Implementation Notes: I used direct Win32 functions for file IO so I
	wouldn't have the link in the ANSI file stuff.
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


//Private Data
char ErrorLogPath[MAX_PATH];
BOOL CriticalErrorFlag = FALSE;
HWND ErrorMainWindow;

//Public Functions
/******************************************************************************/
void OpenErrorLog(HWND MainWindow) {
	char LogDir[MAX_PATH];

	ErrorMainWindow = MainWindow;

	GetCurrentDirectory(MAX_PATH, LogDir);
	strcpy(ErrorLogPath, LogDir);
	strcat(ErrorLogPath, "\\ERROR.TXT");
	}
/******************************************************************************/
void LogError(char *Msg) {
	HANDLE ErrorLog;
	DWORD NumWritten;

	ErrorLog = CreateFile(ErrorLogPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
	SetFilePointer(ErrorLog, 0, 0, FILE_END); //Append to end

	WriteFile(ErrorLog, "Error: ", 7, &NumWritten, NULL);
	WriteFile(ErrorLog, Msg, strlen(Msg), &NumWritten, NULL);
	WriteFile(ErrorLog, "\r\n", 2, &NumWritten, NULL);
	CloseHandle(ErrorLog);
	}
/******************************************************************************/
void LogCriticalError(char *Msg) {

	HANDLE ErrorLog;
	DWORD NumWritten;
   DWORD LastError;
   char LastErrorStr[33];
	char MsgBoxStr[200];

   LastError = GetLastError();

	ErrorLog = CreateFile(ErrorLogPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
	SetFilePointer(ErrorLog, 0, 0, FILE_END); //Append to end

	WriteFile(ErrorLog, "Critical Error: ", 16, &NumWritten, NULL);
	WriteFile(ErrorLog, Msg, strlen(Msg), &NumWritten, NULL);
	WriteFile(ErrorLog, "\r\n", 2, &NumWritten, NULL);

   ultoa(LastError, LastErrorStr, 16);

	WriteFile(ErrorLog, "Last Error = 0x", 15, &NumWritten, NULL);
	WriteFile(ErrorLog, LastErrorStr, strlen(LastErrorStr), &NumWritten, NULL);
	WriteFile(ErrorLog, "\r\n", 2, &NumWritten, NULL);

	CloseHandle(ErrorLog);

	strcpy(MsgBoxStr, "Critical Error: ");
	strcat(MsgBoxStr, Msg);
	strcat(MsgBoxStr, "\nFnord will be shut down.");
	MessageBox(ErrorMainWindow, MsgBoxStr, "Fnord! Server",
		MB_OK | MB_ICONERROR);

	PostMessage(ErrorMainWindow, WM_DESTROY, 0, 0);
	CriticalErrorFlag = TRUE;
	}
/******************************************************************************/
BOOL GotCriticalError() {
	return CriticalErrorFlag;
	}
/******************************************************************************/
void CloseErrorLog() {
	HANDLE ErrorLog;
	DWORD NumWritten;

	ErrorLog = CreateFile(ErrorLogPath, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL,	NULL);
	SetFilePointer(ErrorLog, 0, 0, FILE_END); //Append to end

	WriteFile(ErrorLog, "-\r\n", 3, &NumWritten, NULL);
	CloseHandle(ErrorLog);
	}
