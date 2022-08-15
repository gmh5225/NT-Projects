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
Module Name: Debug
Purpose: Debuging.
Public Functions:
	OpenDebugLog
   CloseDebugLog

	DebugMessage
	ThreadDebugMessage

	Assert
*/

#ifdef BUILD_DEBUG //Defined in build.h
/*
Function Name: Open Debug Log
Purpose: Open the log for debugging messages and set up module vars
*/
void OpenDebugLog();

/*
Function Name: Close Debug Log
Purpose: Closes the log for debugging messages and cleans up module vars
*/
void CloseDebugLog();

/*
Function Name: Debug Message
Purpose: Writes a message to the debuging log (DEBUG.TXT) adding a CRLF after it
Parameters:
	Msg - Message to write to log
*/
void DebugMessage(char *Msg);

/*
Function Name: Thread Debug Message
Purpose: Writes a debug message to a log containing messages only from one
			thread.  Does not work for more than 6 threads.
Parameters:
	ThreadNum - Number of current thread
	Msg - Message to write to log
*/
void ThreadDebugMessage(int ThreadNum, char *Msg);

/*
Function Name: Assert
Purpose: If a given condition fails (is false), it writes a given message to
			the debug log
Parameters:
	Cond - Condition expected to be true
	Msg - Message to write to log on fail
Notes: Haven't used this yet, but it was quick to write and might come in
		 handy....
*/
void Assert(BOOL Cond, char *FailMsg);

#else
//Blank eqivelents of debug functions
#define OpenDebugLog()
#define CloseDebugLog()
#define DebugMessage(Msg)
#define ThreadDebugMessage(ThreadNum, Msg)
#define Assert(Cond, FailMsg)
#endif