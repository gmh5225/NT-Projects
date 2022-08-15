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
Module Name: Date
Purpose: Routines for string based date reading and writing
Public Functions:
	DateToRFCFormatStr
   DateToOffsetFormatStr

	StrToDate
*/

/*
Function Name: Date To RFC Format String
Purpose: Converts a Win32 date to a string in RFC 822 (updated by RFC 1123)
	format.
Parameters:
	CurTime - UNIVERSAL Time in Win32 format
	CurTimeStr - String to contain the converted date
*/
void DateToRFCFormatStr(SYSTEMTIME *CurTime, char *CurTimeStr);

/*
Function Name: Date To Offset Format String
Purpose: Converts a Win32 date to a string in the format used by common logging.
	dd/Mmm/yyyy:hh:mm:ss zone
   zone is +hhmm  or -hhmm
Parameters:
	CurTime - LOCAL Time in Win32 format
	CurTimeStr - String to contain the converted date
*/
void DateToOffsetFormatStr(SYSTEMTIME *CurTime, char *CurTimeStr);

/*
Function Name: Str to Date
Purpose: Converts a date string in one of the 3 accepted HTTP formats to a
	a Win32 format.
Parameters:
	PassedCurTimeStr - Date String in a HTTP accepted format
	CurTime - Date in Win32 format
Notes: I took advantage of the fact that the HTTP spec is very specific about
	the kind of date formats accepted to create a brute force, cheap, quick
	parser.  Not flexable and there may be bugs in the code to parse the 2
	less common formats.
*/
int StrToDate(char *PassedCurTimeStr, SYSTEMTIME *CurTime);