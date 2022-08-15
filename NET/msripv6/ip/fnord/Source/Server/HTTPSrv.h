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
#define HTTP_SERVER_MSG WM_USER + 23
#define HTTP_TIMER_ID 23


/*
Function Name: Start HTTP Server
Purpose: Starts the HTTP server.  Inits Winsock, MIME, loads registry stuff,
			etc.
Parameters:
	PassedMsgWindow - The handle of the window that handles messages.  Needed
							to setup WSASelect notification of socket events and
							to send a shutdown message on error.
*/
void StartHTTPServer(HWND MsgWindow);

/*
Function Name: End HTTP Server
Purpose: Ends the HTTP server.  Cleans up MIME, users, etc.
*/
void EndHTTPServer();

/*
Function Name: Process HTTP Server Message
Purpose: Processes HTTP_SERVER_MSG messages.
Parameters:
	Socket - The socket the message is regarding (WPARAM)
	MsgInfo - The messsage (LPARAM)
*/
void ProcessHTTPServerMsg(WPARAM Socket, LPARAM MsgInfo);

/*
Function Name: Process HTTP TimerMsg
Purpose: Processes WM_TIMER messages with the WParam set to HTTP_TIMER_ID.
*/
void ProcessHTTPTimerMsg();

/*
Function Name: Inc Num Free Threads
Purpose: Incriments the number of free threads, which is stored in this module
   for book keeping purposes.  Called by the request handling threads when they
   are finished with a request.
*/
void IncNumFreeThreads();

/*
Function Name: Dec Num Free Threads
Purpose: Decriments the number of free threads, which is stored in this module
   for book keeping purposes.  Called by the request handling threads when they
   start handling a request..
*/
void DecNumFreeThreads();
