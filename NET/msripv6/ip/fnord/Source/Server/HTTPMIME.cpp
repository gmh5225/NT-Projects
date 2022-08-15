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
#include "parse.h"
#include "httpmime.h"

//Private Data
static char **MIMEExts;
static char **MIMEDescs;
static int NumMIMEMappings;


//Public Functions
/******************************************************************************/
void LoadHTTPMIMETable() {
	int i, j;
	HKEY MIMEKeyHandle;
	HKEY ExtKeyHandle;
	DWORD ValueType;
	DWORD BuffSize;
	char NumTypesStr[6];
	char MIMEExtBuff[16];
	char MIMEDescBuff[128];

	//Open MIME Key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\MIME", 0,
		KEY_ALL_ACCESS, &MIMEKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open HTTPD registry key");
		return;
		}

	//Get Number of Types
	BuffSize = 5;
	if (RegQueryValueEx(MIMEKeyHandle, "Number of Types", 0, &ValueType,
		(LPBYTE)NumTypesStr, &BuffSize) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't get number of threads from registry");
		return;
		}
	NumMIMEMappings = atoi(NumTypesStr);

	//Allocate tables
	MIMEExts = new char *[NumMIMEMappings];
	MIMEDescs = new char *[NumMIMEMappings];

	//Load the Types
	FILETIME Junk;

	for (i=0; i<NumMIMEMappings; i++) {
		BuffSize = 15;
		if (RegEnumKeyEx(MIMEKeyHandle, i, MIMEExtBuff, &BuffSize, 0, NULL, 0, &Junk)
			!= ERROR_SUCCESS) {
			LogCriticalError("Couldn't get enumed MIME type from registry");
			return;
			}
		if (RegOpenKeyEx(MIMEKeyHandle, MIMEExtBuff, 0,
			KEY_ALL_ACCESS, &ExtKeyHandle) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't open enumed MIME type registry key");
			return;
			}
		BuffSize = 127;
		if (RegQueryValueEx(ExtKeyHandle, "MIME Description", 0, &ValueType,
			(LPBYTE)MIMEDescBuff, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get number of threads from registry");
			return;
			}
		if (RegCloseKey(ExtKeyHandle) != ERROR_SUCCESS) {
			LogError("Error closeing enumed MIME type registry key");
			}

		MIMEExts[i] = new char [strlen(MIMEExtBuff) + 1];
		MIMEDescs[i] = new char [strlen(MIMEDescBuff) + 1];
		strcpy(MIMEExts[i], MIMEExtBuff);
		strcpy(MIMEDescs[i], MIMEDescBuff);
		}

	//Close MIME Key
	if (RegCloseKey(MIMEKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing MIME registry key");
		}

   //Uppercase all of them so we can use a case sensitive compare
   for (i=0; i<NumMIMEMappings; i++) {
   	CharUpper(MIMEExts[i]);
   	}

   //Sort them so we can use a binary search
   //I'm using a bubble sort since N is small and this is done only on
   //startup
	char *TempPtr;

	for (i=NumMIMEMappings-1; i>0; i--) {
		for (j=0; j<i; j++) {
			if (strcmp(MIMEExts[j], MIMEExts[j+1]) > 0) {
				//Swap Extentions
				TempPtr = MIMEExts[j];
				MIMEExts[j] = MIMEExts[j+1];
				MIMEExts[j+1] = TempPtr;
				//Swap Descriptions
				TempPtr = MIMEDescs[j];
				MIMEDescs[j] = MIMEDescs[j+1];
				MIMEDescs[j+1] = TempPtr;
				}
			}
		}
	}
/******************************************************************************/
char *GetHTTPMIMEByExt(char *Ext) {
   //Make sure there is an extention string
   if (Ext == NULL)
   	return NULL;

   //Convert the extention to canonical form (upper case a copy of it)
   char WorkingExt[20];
   strncpy(WorkingExt, Ext, 20);
   WorkingExt[19] = 0;
   CharUpper(WorkingExt);

   //Binary Search for the right mapping
   int Low = 0;
   int High = NumMIMEMappings - 1;
   int Guess;
   int CompResult;
   while (Low <= High) {
      Guess = (Low + High) / 2;
      CompResult = strcmp(WorkingExt, MIMEExts[Guess]);
      if (CompResult < 0) { //Guess was too high
      	High = Guess - 1;
      	}
      else if (CompResult > 0) { //Guess was too low
      	Low = Guess + 1;
      	}
      else {
         return MIMEDescs[Guess];
      	}
   	}
   return NULL; //No match found
	}
/******************************************************************************/
char *GetHTTPMIMEByPath(char *Path) {
	char Ext[20];
   GetExtention(Path, Ext);
	return GetHTTPMIMEByExt(Ext);
	}
/******************************************************************************/
void UnloadHTTPMIMETable() {
	int i;
	for (i=0; i<NumMIMEMappings; i++) {
		delete[] MIMEExts[i];
		delete[] MIMEDescs[i];
		}
	delete[] MIMEExts;
	delete[] MIMEDescs;
	}
/******************************************************************************/

