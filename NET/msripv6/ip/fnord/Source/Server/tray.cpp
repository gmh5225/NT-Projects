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
#include "tray.h"

//Private Data
//#ifndef BUILD_SRV //Don't bother if we're building a service

#define TrayID 1006

NOTIFYICONDATA nid;

//Counters
int NumConnects;
long NumServed;

CRITICAL_SECTION NewToolTipSection;

//Private Function Declarations
void DisplayTrayMenu(HWND MainWindow);
void SetFnordToolTip();

//Menu Options
void LoadFnordControl(HWND MainWindow);
void ShutdownFnord(HWND MainWindow);

//Public Functions
/******************************************************************************/
void AddFnordToTray(HWND MainWindow, HICON TrayIcon) {
	//Init Counters
	NumConnects = 0;
	NumServed = 0;

	InitializeCriticalSection(&NewToolTipSection);

	//Set Notify Icon Data
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = MainWindow;
	nid.uID = TrayID;
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;                                   //  and tooltip text
	nid.uCallbackMessage = TrayMsg;
	nid.hIcon = TrayIcon;
	strcpy(nid.szTip, "Fnord! 0 Active 0 Served");

	//Add Icon to Tray
	Shell_NotifyIcon( NIM_ADD, &nid );
	}
/******************************************************************************/
void RemoveFnordFromTray() {

	DeleteCriticalSection(&NewToolTipSection);

	Shell_NotifyIcon( NIM_DELETE, &nid );
	}
/******************************************************************************/
int ProcessTrayMsg(HWND Window, WPARAM WParam, LPARAM LParam) {
	if (WParam == TrayID) {
		if (LParam == WM_RBUTTONDOWN) {
			DisplayTrayMenu(Window);
			return TRUE;
			}
      else if (LParam == WM_LBUTTONDBLCLK) {
         LoadFnordControl(Window);
         return TRUE;
      	}
		}
	return FALSE;
	}
/******************************************************************************/
void TrayAddConnection() {
	NumConnects++;
	SetFnordToolTip();
	}
/******************************************************************************/
void TrayRemoveConnection() {
	NumConnects--;
	SetFnordToolTip();
	}
/******************************************************************************/
void TrayIncNumServed() {
	NumServed++;
	SetFnordToolTip();
	}
/******************************************************************************/

//Private Functions

/******************************************************************************/
void SetFnordToolTip() {
	char NumStr[33];

	EnterCriticalSection(&NewToolTipSection);

	strcpy(nid.szTip, "Fnord! ");

	itoa(NumConnects, NumStr, 10);
	strcat(nid.szTip, NumStr);
	strcat(nid.szTip, " Active ");

	ltoa(NumServed, NumStr, 10);
	strcat(nid.szTip, NumStr);
	strcat(nid.szTip, " Served");

	Shell_NotifyIcon( NIM_MODIFY, &nid );

	LeaveCriticalSection(&NewToolTipSection);
	}
/******************************************************************************/
void DisplayTrayMenu(HWND MainWindow) {
	HMENU MenuHnd;
	POINT MousePos;  // x y
   int ScreenWidth;
	int ScreenHeight;
	int SelItem;

	MenuHnd = CreatePopupMenu();
	AppendMenu(MenuHnd, MF_ENABLED, 1, "Control");
	AppendMenu(MenuHnd, MF_ENABLED, 2, "Shutdown");
	//Get Mouse Pos
	GetCursorPos(&MousePos);
	//Get Screen Metrics
   ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	SetForegroundWindow(MainWindow); //To fix tray menu quirks, per the MS suggestion
   //Handle the different possible task bar locations
   //Bottom or Right
   if ((MousePos.x >= (ScreenWidth / 2)) && (MousePos.y >= (ScreenHeight / 2))) {
	   SelItem = TrackPopupMenu(MenuHnd,
         TPM_BOTTOMALIGN | TPM_RIGHTALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON,
         MousePos.x, ScreenHeight, 0, MainWindow, NULL);
      }
   //Top
   else if (MousePos.y < (ScreenHeight / 2)) {
	   SelItem = TrackPopupMenu(MenuHnd,
         TPM_TOPALIGN | TPM_RIGHTALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON,
         MousePos.x, MousePos.y, 0, MainWindow, NULL);
      }
   //Left
   else {
	   SelItem = TrackPopupMenu(MenuHnd,
         TPM_BOTTOMALIGN | TPM_LEFTALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON,
         MousePos.x, ScreenHeight, 0, MainWindow, NULL);
      }
	SetForegroundWindow(MainWindow); //To fix tray menu quirks, per the MS suggestion
	DestroyMenu(MenuHnd);

   if (SelItem == 1)
   	LoadFnordControl(MainWindow);
	else if (SelItem == 2)
		ShutdownFnord(MainWindow);
	}
/******************************************************************************/
void LoadFnordControl(HWND MainWindow) {
	STARTUPINFO FCStartupInfo;
   PROCESS_INFORMATION FCProcessInfo;
   BOOL Result;

   GetStartupInfo(&FCStartupInfo);  //Use fnord.exe's start info
	DebugMessage("Calling FNORDCTL");
   Result = CreateProcess("FNORDCTL.EXE", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &FCStartupInfo, &FCProcessInfo);
   if(!Result) {
   	DebugMessage("Failed to load FNORDCTL");
   	//Tell the user we failed so they aren't waiting for something that
      //is not gonna happen
      MessageBox(MainWindow,
         "Could not load Fnord Control.\nfnordctl.exe must be in the same directory as fnord.exe for this feature to work.",
      	"Fnord! Server", MB_OK | MB_ICONERROR);
      }
	}
/******************************************************************************/
void ShutdownFnord(HWND MainWindow) {
	int Answer;

	//Make sure the user means it
   Answer = MessageBox(MainWindow, "Are you sure you want to shutdown Fnord Server?",
      	"Fnord! Server", MB_YESNO | MB_ICONQUESTION);
   //If they do destroy the main window and let the the rest fall in place...
   if (Answer == IDYES	) {
   	DestroyWindow(MainWindow);
      }
	}
//#endif
