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

//Public Functions
/******************************************************************************/
void Left(char *DestStr, const char *SourceStr, const int Len) {
	memcpy(DestStr, SourceStr, Len);
	DestStr[Len] = 0;
	}
/******************************************************************************/
void Right(char *DestStr, const char *SourceStr, const int Len) {
	int SourceLen, Offset;

	SourceLen = strlen(SourceStr);
	Offset = SourceLen - Len;

	memcpy(DestStr, SourceStr + Offset, Len + 1);
	//The null is already copied
	}
/******************************************************************************/
void TrimLeft(char *TargetStr) {
	int i, NewStrSize;

	i = 0;
	//Find the first non-space charactor
	while ( (TargetStr[i] == ' ') || (TargetStr[i] == '\t') ) {
		i++;
		}
	//If we have space to get rid of, move the string
	if (i > 0) {
		NewStrSize = strlen(TargetStr) - i + 1; //Include the NULL in the size
		memmove(TargetStr, TargetStr + i, NewStrSize);
		}
	}
/******************************************************************************/
void TrimRight(char *TargetStr) {
	int i;

	//Find the last non-space charactor (index i)
	i = strlen(TargetStr) - 1;
	while ((i >= 0) && ((TargetStr[i] == ' ') || (TargetStr[i] == '\t')) ) {
		i--;
		}
	//Set the NULL 1 after the last non-space charactor
	TargetStr[i+1] = 0;
	}
/******************************************************************************/
void Trim(char *TargetStr) {
	TrimRight(TargetStr);
	TrimLeft(TargetStr);
	}
/******************************************************************************/
void GetWord(char *DestStr, const char *SourceStr, const int Start, int &End) {
	int i, Len;

	Len = 0;
	i = Start;
	while ((SourceStr[i] != ' ') && (SourceStr[i] != '\t') && (SourceStr[i] != 0)) {
		Len++;
		i++;
		}
	//Create the substring
	memcpy(DestStr, SourceStr + Start, Len);
	DestStr[Len] = 0;
	//Set End
	while ((SourceStr[i] != 0) &&
			 ((SourceStr[i] == ' ') || (SourceStr[i] == '\t'))) {
		i ++;
		}
	End = i;
	}
/******************************************************************************/
void GetLastWord(char *DestString, const char *SourceStr, int &Start) {
	int SourceLen, i, Len;

	Len = 0;
	SourceLen = strlen(SourceStr);
	i = SourceLen - 1;
	while ((i >= 0) && (SourceStr[i] != ' ') && (SourceStr[i] != '\t')) {
		Len++;
		i--;
		}
	//Create the substring
	memcpy(DestString, SourceStr + SourceLen - Len, Len);
	DestString[Len] = 0;
	Start = i + 1;
	}
/******************************************************************************/
void SplitPath(char *Path, char *Dir, char *FileName) {
	int SplitPoint;
	SplitPoint = strlen(Path) - 1;
	while ((SplitPoint > 0) && (Path[SplitPoint] != '\\')) {
		SplitPoint--;
		}
	if ((SplitPoint == 0) && (Path[SplitPoint] != '\\')) {
		//No directory, just a file name
		Dir[0] = 0;
		strcpy(FileName, Path);
		}
	else {
		//Move past the last slash
		SplitPoint++;

		//Directory
		int i = 0;
		while (i < SplitPoint) {
			Dir[i] = Path[i];
			i++;
			}
		Dir[i] = 0;

		//File name
		int j = 0;
		while (Path[i] != 0) {
			FileName[j] = Path[i];
			j++;
			i++;
			}
		FileName[j] = 0;
		}
	}
/******************************************************************************/
void GetExtention(char *Path, char *Extention) {
	int Dot;
	int PathLen;

	PathLen = strlen(Path) - 1;
	Dot = PathLen;
	while ((Dot > 0) && (Path[Dot] != '.')) {
		Dot--;
		}
	if (Dot > 0) {
		strcpy(Extention, Path + Dot + 1);
		}
	else {
		Extention[0] = 0;
		}
	}
/******************************************************************************/
void TranslateEscapeString(char *TargetStr) {
	int i = 0;
   int j = 0;

	while (TargetStr[i] != 0) {
		if ((TargetStr[i] == '%') && (TargetStr[i+1] != 0) && (TargetStr[i+2] != 0)) {
      	//Escaped value (did checking to make sure there are 2 more chars)
         #pragma warn -sig //Suppress significant digit loss warning (BC++)
			TargetStr[j] = 16 * HexVal(TargetStr[i+1]) + HexVal(TargetStr[i+2]);
         #pragma warn +sig   //Restore significant digit loss warning (BC++)
			i += 3;
			}
		else {
			TargetStr[j] = TargetStr[i];
			i++;
			}
      j++;
      }
   TargetStr[j] = 0;
	}
/******************************************************************************/
int HexVal(char c) {
   #pragma warn -sig //Suppress significant digit loss warning (BC++)
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	else return 0;
   #pragma warn +sig   //Restore significant digit loss warning (BC++)
	}
/******************************************************************************/
