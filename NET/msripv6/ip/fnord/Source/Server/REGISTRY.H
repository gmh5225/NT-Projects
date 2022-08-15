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
Module Name: Registry
Purpose: Provides general program configuration information
Public Functions:
	GetRegFlag

	LoadRegistryVars
   ReloadRegistryVars
	UnloadRegistryVars

   GetServerName
	GetPortNum
	GetNumThreads
   GetIndexFileName
	GetErrorMsgPath
	GetServerTempDir

	GetLogPath
	GetCommonLogFlags
	GetCountLogFlags
	GetReferenceFlags
*/

/*
Function Name: Get Reg Flag
Purpose: Gets a boolean (true or false) value from the registry
Parameters:
	Flag: Varible to store the retrived flag
	HKEY: Key the registy varible is in
	ValName: Name of the flag in the registry
Returns: 0 on success, -1 on failure
Notes: Originaly intended for private use, however since I felt it was
best for modules with complex registry information stored to have their
own interfaces, I made it avaible for thier use.  Does not need to be
initialized.
*/
int GetRegFlag(BOOL &Flag, HKEY RegKey, char *ValName);

/*
Function Name: Load Registry Vars
Purpose: Loads most of the registry information into module variables
	to setup other functions in this module
*/
void LoadRegistryVars();

/*
Function Name: ReLoad Registry Vars
Purpose: Reloads the configuration information from the registry after
	this module has already been intialized. 
*/
void ReloadRegistryVars();

/*
Function Name: Unloads Registry Vars
Purpose: Unloads the module varibles and other housekeeping
*/
void UnloadRegistryVars();

/* Query Functions */

/* General */
#define REG_MAX_SERVER_NAME 200
char *GetServerName();

WORD GetPortNum();

int GetInitNumThreads();
int GetMaxNumThreads();
int GetNumThreadsKeepFree();
UINT GetThreadCompactPeriod();
int GetThreadCompactLaziness();

BOOL GetScriptDNS();

char *GetIndexFileName();
char *GetErrorMsgPath();
char *GetServerTempDir();

/* Log */
char *GetLogPath();
void GetCommonLogFlags(BOOL &Enabled, char* &FileName, BOOL &LookUpIP);
void GetCountLogFlags(BOOL &Enabled, char* &FileName, BOOL &CountFiles, BOOL &CountConnects,
	BOOL &CountKBytes);
void GetReferenceFlags(BOOL &Enabled, char* &FileName);
