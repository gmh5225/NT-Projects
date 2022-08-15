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
#include "error.h"
#include "debug.h"
#pragma hdrstop
#include "parse.h"

/*
Implementaion Notes: Depends on DebugMessage to output results, needs
	work.
*/

//Public Functions
/******************************************************************************/
void StartTimer(DWORD &StartTime) {
	StartTime = GetTickCount();
	}
/******************************************************************************/
void StopTimer(DWORD StartTime, const char *Name) {
	DWORD StopTime;
	DWORD TotalTime;
	char OutMessage[300];
	char NumStr[33];

	StopTime = GetTickCount();
	TotalTime = StopTime - StartTime;

	ultoa(TotalTime, NumStr, 10);
	strcpy(OutMessage, Name);
	strcat(OutMessage, " finished in ");
	strcat(OutMessage, NumStr);
	strcat(OutMessage, "ms");

	DebugMessage(OutMessage);
	}
/******************************************************************************/
