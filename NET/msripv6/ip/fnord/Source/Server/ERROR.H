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
Module Name: Error
Purpose: Logging errors and shutting down the program in an emergency.
Public Functions:
	OpenErrorLog
   CloseErrorLog

	LogError
	LogCriticalError

	GotCriticalError
*/

/*
Function Name: Open Error Log
Purpose: Open the log for error messages and set up module vars
*/
void OpenErrorLog(HWND MainWindow);

/*
Function Name: Close Error Log
Purpose: Closes the log for error messages and cleans up module vars
*/
void CloseErrorLog();

/*
Function Name: Log Error
Purpose: Writes a message to the error log (ERROR.TXT) adding "Error: " before
			it and a CRLF after it
Parameters:
	Msg - Message to write to log
*/
void LogError(char *Msg);

/*
Function Name: Log Critical Error
Purpose: Writes a message to the error log (ERROR.TXT) adding
			"Critical Error: " before it and a CRLF after it.  Then it shuts
			down the program.
Parameters:
	Msg - Message to write to log
*/
void LogCriticalError(char *Msg);

/*
Function Name: Got Critical Error?
Purpose: Returns TRUE if Log Critical Error was called
*/
BOOL GotCriticalError();

