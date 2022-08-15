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
Module Name: HTTP MIME
Purpose: Managing file type to MIME description mappings for HTTP.
Public Functions:
	LoadHTTPMIMETable
	UnloadHTTPMIMETable
	GetHTTPMIMEByExt
	GetHTTPMIMEByPath
*/

/*
Function Name: Load MIME Table
Purpose: Loads the MIME information from the registry and does other
	initalization for this module.
*/
void LoadHTTPMIMETable();

/*
Function Name: Unload MIME Table
Purpose: Removes the MIME information from memory, and does other module
	cleanup.
*/
void UnloadHTTPMIMETable();

/*
Function Name: Get MIME By Extention
Purpose: Gets a MIME description string given a file extention
Parameters:
	Ext - File extention, for example, "txt", "jpg", "jpeg", etc.
Returns:
	A string containing the MIME description for the file type, or NULL if
	there was no match.
*/
char *GetHTTPMIMEByExt(char *Ext);

/*
Function Name: Get MIME By Path
Purpose: Gets a MIME description string given a file path
Parameters:
	Path - Path of the file, for example, "file.txt", "c:\dir\file.txt", etc.
Returns:
	A string containing the MIME description for the file type, or NULL if
	there was no match.
*/
char *GetHTTPMIMEByPath(char *Path);


