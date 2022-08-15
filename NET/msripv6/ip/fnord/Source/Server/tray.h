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
Contributors:
	Jason Formo - Added mechanism for loading FnordCtl from the tray
*/

//Public Definitions
#define TrayMsg        WM_USER+69

/*
Function Name: Add Fnord to Tray
Purpose: Adds the Fnord icon to the Win95/Shellnew system tray
Parameters:
	MainWindow - Handle to window that handles tray messages
	HICON - Handle for icon to display in the system tray
*/
void AddFnordToTray(HWND MainWindow, HICON TrayIcon);

/*
Function Name: Remove Fnord from Tray
Purpose: Removes the Fnord icon to the Win95/Shellnew system tray
*/
void RemoveFnordFromTray();

/*
Function Name: Process Tray Message
Purpose: Should be called by the message processing function receiving
	tray messages (see AddFnordToTray) when receiving TrayMsg (defined
	above.)
Parameters:
	Window - Handle of the window processing tray messages
	WPARAM - WParam of message
	LPARAM - LParam of message
Returns: The value that should be returned by the message processing
	function.
*/
int ProcessTrayMsg(HWND Window, WPARAM WParam, LPARAM LParam);

/*
Function Name: Tray Add Connection
Purpose: Updates the tray icon tool tip to indicate a new connection
*/
void TrayAddConnection();

/*
Function Name: Tray Remove Connection
Purpose: Updates the tray icon tool tip to indicate a connection was
	disconnected.
*/
void TrayRemoveConnection();

/*
Function Name: Tray Inc Num Served
Purpose: Updates the tray icon tool tip to indicate a request was processed
*/
void TrayIncNumServed();
