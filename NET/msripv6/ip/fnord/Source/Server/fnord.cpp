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
#include "users.h"
#include "tray.h"
#include "httpsrv.h"
#include "fnordsrv.h"
#include "fnord.h"

static HWND MainWindow;
static UINT ReloadConfigMsg;

long __stdcall WndProc(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam);


#ifdef BUILD_SRV

void main(int argc, char *argv[]) {
   SrvProcessCommand(argc, argv);
   }

#endif

/*
Function Name: WinMain
Purpose: Entry point for the tray version of the server server, starts the
         server and sets up a message loop.
*/
int __stdcall WinMain (HINSTANCE Instance, HINSTANCE /*PrevInstance*/, LPSTR /*CmdLineStr*/, int /*CmdShow*/) {
MSG Message;
WNDCLASS MainClass;
HICON TrayIcon;

//Create the tray Icon resource
TrayIcon = LoadIcon(Instance, "TRAY_ICON");

//Create a window class
MainClass.style = CS_HREDRAW | CS_VREDRAW;
MainClass.lpfnWndProc = WndProc;
MainClass.cbClsExtra = 0;
MainClass.cbWndExtra = 0;
MainClass.hInstance = Instance;
MainClass.hIcon     = 0;
MainClass.hCursor   = LoadCursor(NULL, IDC_ARROW);
MainClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
MainClass.lpszMenuName = NULL;
MainClass.lpszClassName = "Fnord Status";
if (!RegisterClass(&MainClass))
	return 0;

//Create the main window
MainWindow = CreateWindow("Fnord Status", "Fnord!", WS_OVERLAPPEDWINDOW, 10, 10,
	200, 100, NULL, NULL, Instance, NULL);
ShowWindow(MainWindow, SW_HIDE);

//Register/get the reload message
ReloadConfigMsg = RegisterWindowMessage("Fnord Server Reload");

//Init Error handling and debugging
OpenErrorLog(MainWindow);
OpenDebugLog();

//Add tray icon to system tray
AddFnordToTray(MainWindow, TrayIcon);

//Init NetIO, Registry and Users
InitNetIO();
LoadRegistryVars();
LoadUsers();


//Start the HTTP Server
if (!GotCriticalError()) {
	StartHTTPServer(MainWindow);
	}

//Message loop
while(GetMessage(&Message, NULL, NULL, NULL)) {
	DispatchMessage(&Message);
	}

return Message.wParam;
}


/*
Function Name: WndProc
Purpose: Windows message processing function.  Only needs to handle
			Winsock WSASelect and shutdown messages.
*/
long __stdcall WndProc(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam) {
switch(Message) {
	//Constant Messages
	case HTTP_SERVER_MSG:
		ProcessHTTPServerMsg(WParam, LParam);
		break;
   case WM_TIMER:
      if (WParam == HTTP_TIMER_ID) {
         ProcessHTTPTimerMsg();
         }
      break;
	case TrayMsg:
		return ProcessTrayMsg(Window, WParam, LParam);
	case WM_DESTROY:
   	//Shutdown the HTTP server
		EndHTTPServer();
      //Shutdow the main server modules
      UnloadUsers();
      UnloadRegistryVars();
      CleanUpNetIO();
		CloseDebugLog();
		CloseErrorLog();
      RemoveFnordFromTray();
      //Shutdown the main window
		PostQuitMessage(0);
		break;
	default:
   	//Variable Messages
   	if (Message == ReloadConfigMsg) {
   		//Shutdown the HTTP server
      	EndHTTPServer();

      	//Reload the main server modules
         ResetNetIO();
         ReloadRegistryVars();
         ReloadUsers();

      	//Restart the HTTP server
      	StartHTTPServer(Window);
      	}
      //Unhandled Messages end up here (DefWindowProc)
      else {
			return DefWindowProc(Window, Message, WParam, LParam);
         }
	}
return(0);
}

HWND GetFnordMainWindow() {
   return MainWindow;
   }
