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
#include "parse.h"
#include "netio.h"
#include "users.h"
#include "registry.h"
#include "httpreq.h"
#include "httpmap.h"

/*
Implementaion Notes:
Escape sequence decoding code contributed by Miguel
*/

//Private Data Structures
struct DirInfo {
	char *LocalDirStr;
	BOOL AllowDirList;
	int Scripting;
	char *AuthUserStr;
	int AuthLoc;
	};

//Private Data
static int NumDirs;
static char **Dirs;
static int *DirLens;
static DirInfo **DirInfos;

//Public Functions
/******************************************************************************/
void LoadHTTPPathMap() {
	DWORD ValueType;
	DWORD BuffSize;
	HKEY DirMapKeyHandle;
	HKEY DirKeyHandle;
	char NumDirsStr[6];
	int i, j;
	FILETIME Junk;

	char DirStr[MAX_PATH];
	char LocalDirStr[MAX_PATH];
	BOOL AllowDirList;
	char AuthUserStr[101];
	char AuthLocStr[101];
	int AuthLoc;
	char ScriptingStr[101];
	int Scripting;

	//Open DirMap Key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\Directory Mappings",
		0, KEY_ALL_ACCESS, &DirMapKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Directory Map registry key");
		return;
		}

	//Get the number of Dirs
	BuffSize = 5;
	if (RegQueryValueEx(DirMapKeyHandle, "Number of Directories", 0, &ValueType,
		(LPBYTE)NumDirsStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get number of dirs from registry");
		return;
		}
	NumDirs = atoi(NumDirsStr);

	//Create the arrays
	Dirs = new char *[NumDirs];
	DirLens = new int[NumDirs];
	DirInfos = new DirInfo *[NumDirs];

	//Get the Dirs
	for (i=0; i<NumDirs; i++) {
		//Get a dir
		BuffSize = MAX_PATH;
		if (RegEnumKeyEx(DirMapKeyHandle, i, DirStr, &BuffSize, 0, NULL, 0, &Junk)
			!= ERROR_SUCCESS) {
			LogCriticalError("Couldn't get enumed Directory from registry");
			return;
			}
		//Open it
		if (RegOpenKeyEx(DirMapKeyHandle, DirStr, 0,
			KEY_ALL_ACCESS, &DirKeyHandle) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't open enumed Directory registry key");
			return;
			}
		//Trim the last slash
		if (DirStr[strlen(DirStr) - 1] == '/')
			DirStr[strlen(DirStr) - 1] = '\0';
		//Get Local Dir
		BuffSize = MAX_PATH;
		if (RegQueryValueEx(DirKeyHandle, "Local Directory", 0, &ValueType,
			(LPBYTE)LocalDirStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Local Directory from registry");
			return;
			}
		//Get Allow Dir List Flag
		if (GetRegFlag(AllowDirList, DirKeyHandle, "Allow Directory Listings") != 0) {
			LogCriticalError("Couldn't get Allow Directory Listings flag from registry");
			return;
			}
		//Get Scripting Type
		BuffSize = 100;
		if (RegQueryValueEx(DirKeyHandle, "Scripting", 0, &ValueType,
			(LPBYTE)ScriptingStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Scripting from registry");
			return;
			}
		if (strcmpi(ScriptingStr, "None") == 0) {
			Scripting = SCRIPTING_NONE;
			}
		else 	if (strcmpi(ScriptingStr, "ReDirect") == 0) {
			Scripting = SCRIPTING_REDIR;
			}
		else 	if (strcmpi(ScriptingStr, "WinCGI") == 0) {
			Scripting = SCRIPTING_WINCGI;
			}
		else 	if (strcmpi(ScriptingStr, "CGI") == 0) {
			Scripting = SCRIPTING_CGI;
			}
		else 	if (strcmpi(ScriptingStr, "ISAPI") == 0) {
			Scripting = SCRIPTING_ISAPI;
			}
		else {
			Scripting = SCRIPTING_NONE;
			}
		//Get Authorized User
		BuffSize = 100;
		if (RegQueryValueEx(DirKeyHandle, "Authorized User", 0, &ValueType,
			(LPBYTE)AuthUserStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Authorized User from registry");
			return;
			}
		//Get Authorized Location
		BuffSize = 100;
		if (RegQueryValueEx(DirKeyHandle, "Authorized Location", 0, &ValueType,
			(LPBYTE)AuthLocStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Authorized Location from registry");
			return;
			}
		if (strcmpi(AuthLocStr, "Anywhere") == 0) {
			AuthLoc = AUTH_LOC_ANYWHERE;
			}
		else if(strcmpi(AuthLocStr, "Class A Subnet") == 0) {
			AuthLoc = AUTH_LOC_CLASSA;
			}
		else if(strcmpi(AuthLocStr, "Class B Subnet") == 0) {
			AuthLoc = AUTH_LOC_CLASSB;
			}
		else if(strcmpi(AuthLocStr, "Class C Subnet") == 0) {
			AuthLoc = AUTH_LOC_CLASSC;
			}
		else if(strcmpi(AuthLocStr, "Class D Subnet") == 0) {
			AuthLoc = AUTH_LOC_CLASSD;
			}
		else {
			AuthLoc = AUTH_LOC_ANYWHERE;
			}
		//Close Enumerated Directory Key
		if (RegCloseKey(DirKeyHandle) != ERROR_SUCCESS) {
			LogError("Error closeing enumed Directory registry key");
			}
		//Add it to our arrays
		Dirs[i] = new char[strlen(DirStr)+1];
		strcpy(Dirs[i], DirStr);
		DirLens[i] = strlen(DirStr);
		DirInfos[i] = new DirInfo;
		DirInfos[i]->LocalDirStr = new char[strlen(LocalDirStr)+1];
		strcpy(DirInfos[i]->LocalDirStr, LocalDirStr);
		DirInfos[i]->AllowDirList = AllowDirList;
		DirInfos[i]->Scripting = Scripting;
		DirInfos[i]->AuthUserStr = new char[strlen(AuthUserStr)+1];
		strcpy(DirInfos[i]->AuthUserStr, AuthUserStr);
		DirInfos[i]->AuthLoc = AuthLoc;
		}

	//Sort the Dirs with the longest one first
	//I'm using a bubble sort since N is small, it's done only once
   //and I'm swaping pointers
	int TempInt;
	char *TempStr;
	DirInfo *TempDirInfoPtr;
	for (i=NumDirs-1; i>0; i--) {
		for (j=0; j<i; j++) {
			if (DirLens[j] < DirLens[j+1]) {
				//Swap Lengths
				TempInt = DirLens[j];
				DirLens[j] = DirLens[j+1];
				DirLens[j+1] = TempInt;
				//Swap Dirs
				TempStr = Dirs[j];
				Dirs[j] = Dirs[j+1];
				Dirs[j+1] = TempStr;
				//Swap DirInfos
				TempDirInfoPtr = DirInfos[j];
				DirInfos[j] = DirInfos[j+1];
				DirInfos[j+1] = TempDirInfoPtr;
				}
			}
		}

	//Close Dir Map Key
	if (RegCloseKey(DirMapKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing HTTPD registry key");
		}
	}
/******************************************************************************/
void UnloadHTTPPathMap() {
	int i;

	for (i=0; i<NumDirs; i++) {
		delete[] Dirs[i];
		delete[] DirInfos[i]->LocalDirStr;
		delete[] DirInfos[i]->AuthUserStr;
		delete DirInfos[i];
		}
	delete[] Dirs;
	delete[] DirLens;
	delete[] DirInfos;
	}
/******************************************************************************/
int MapHTTPPath(char *URIStr, RequestInfoT &RequestInfo,
	RequestFieldsT &RequestFields, char *RemoteRealm, char *LocalRealm,
   char *FilePath, BOOL &AllowDirList, int &Scripting) {
	int i, j;

	i = 0;
   #define LenOk (strlen(URIStr) >= DirLens[i])
   #define SubStrMatch (strnicmp(URIStr, Dirs[i], DirLens[i]) == 0)
   //Make sure we don't have part of an element, thus end with a slash or \0
   #define NotSubElement ((URIStr[DirLens[i]] == '\0') || (URIStr[DirLens[i]] == '/') || (URIStr[DirLens[i]] == '\\'))

	while ((i < NumDirs) && !(LenOk && SubStrMatch && NotSubElement)) {
		i++;
		}
	if (i == NumDirs) {
		return MP_ERROR;
		}
	strcpy(RemoteRealm, Dirs[i]);
   strcpy(LocalRealm, DirInfos[i]->LocalDirStr);

	//Set Base File Path
	strcpy(FilePath, DirInfos[i]->LocalDirStr);
	//Set security flags
	AllowDirList = DirInfos[i]->AllowDirList;
	Scripting = DirInfos[i]->Scripting;

#if MSRIPv6
    // Expediency: don't support this feature, always allow anywhere.
#else
	//Check location
	if (DirInfos[i]->AuthLoc != AUTH_LOC_ANYWHERE) {
		DWORD LocalIP;
		DWORD RemoteIP;
		DWORD Mask;

      const DWORD     AMask = 0x000000FF;
      const DWORD     BMask = 0x0000FFFF;
      const DWORD     CMask = 0x00FFFFFF;
      const DWORD     DMask = 0xFFFFFFFF;

		LocalIP = GetLocalIP();
		RemoteIP = RequestInfo.ClientSockAddr.sin_addr.s_addr;

		switch(DirInfos[i]->AuthLoc) {
			case AUTH_LOC_CLASSA:
				Mask = AMask;
				break;
			case AUTH_LOC_CLASSB:
				Mask = BMask;
				break;
			case AUTH_LOC_CLASSC:
				Mask = CMask;
				break;
			case AUTH_LOC_CLASSD:
				Mask = DMask;
				break;
			}

		if ((LocalIP & Mask) != (RemoteIP & Mask))
         return MP_FORBIDDEN;
		}
#endif

	//Check User Name and Password
	if (strcmpi(DirInfos[i]->AuthUserStr, "Anyone") != 0) {
		//Check to see if user is valid
		if (RequestFields.AuthorizationStr[0] == 0) {
			//No Authorization info
			return MP_NO_ACCESS;
			}
		else {
			if (HTTPCheckUser(RequestFields.AuthorizationStr, DirInfos[i]->AuthUserStr,
				RequestFields.AuthorizedUserStr) == FALSE) {
				//Authorization failed
				return MP_NO_ACCESS;
				}
			}
		}

   // Check for Redirection
   if ( Scripting == SCRIPTING_REDIR )  {
	   //Append the URI to it
	   j = DirLens[i];
	   i = strlen(FilePath);
	   if (FilePath[i - 1] == '/') //Trim the extra /, we'll pick it back up in the URI
		   i--;
	   while (URIStr[j] != 0) {
		   if ((URIStr[j] == '%') && (URIStr[j+1] != 0) && (URIStr[j+2] != 0)) {
      	   //Escaped value (did checking to make sure there are 2 more chars)
            #pragma warn -sig //Suppress significant digit loss warning (BC++)
			   FilePath[i] = 16 * HexVal(URIStr[j+1]) + HexVal(URIStr[j+2]);
            #pragma warn +sig   //Restore significant digit loss warning (BC++)
			   j += 2;
			   }
		   else
			   FilePath[i] = URIStr[j];
		   i++;
		   j++;
         }
      FilePath[i] = 0;

      return MP_REDIRECT;
      }
   else {
      //Append the URI to it, converting slashes
	   j = DirLens[i];
	   i = strlen(FilePath);
	   if (FilePath[i - 1] == '\\') //Trim the extra \, we'll pick it back up in the URI
		   i--;
	   while (URIStr[j] != 0) {
		   if (URIStr[j] == '/')
			   FilePath[i] = '\\'; //Convert the slashes
         else if ((URIStr[j] == '%') && (URIStr[j+1] != 0) && (URIStr[j+2] != 0)) {
      	   //Escaped value (did checking to make sure there are 2 more chars)
            #pragma warn -sig //Suppress significant digit loss warning (BC++)
			   FilePath[i] = 16 * HexVal(URIStr[j+1]) + HexVal(URIStr[j+2]);
            #pragma warn +sig   //Restore significant digit loss warning (BC++)
			   j += 2;
			   }
		   else
			   FilePath[i] = URIStr[j];
		   i++;
		   j++;
         }
	   FilePath[i] = 0;

	   //Check for stuff like "/.." and "/." in the file path and
	   //deny access
	   if (strstr(FilePath, "\\.") != 0) {
		   return MP_FORBIDDEN;
		   }
	   return MP_PATH_FOUND;
      }
	}

