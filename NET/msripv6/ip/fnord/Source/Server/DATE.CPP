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
#include "date.h"

//Public Functions
/******************************************************************************/
void DateToRFCFormatStr(SYSTEMTIME *CurTime, char *CurTimeStr) {
	char WorkStr[17];

	//Day of Week
	switch(CurTime->wDayOfWeek) {
		case 0: {
			CurTimeStr[0] = 'S';
			CurTimeStr[1] = 'u';
			CurTimeStr[2] = 'n';
			break;
			}
		case 1: {
			CurTimeStr[0] = 'M';
			CurTimeStr[1] = 'o';
			CurTimeStr[2] = 'n';
			break;
			}
		case 2: {
			CurTimeStr[0] = 'T';
			CurTimeStr[1] = 'u';
			CurTimeStr[2] = 'e';
			break;
			}
		case 3: {
			CurTimeStr[0] = 'W';
			CurTimeStr[1] = 'e';
			CurTimeStr[2] = 'd';
			break;
			}
		case 4: {
			CurTimeStr[0] = 'T';
			CurTimeStr[1] = 'h';
			CurTimeStr[2] = 'u';
			break;
			}
		case 5: {
			CurTimeStr[0] = 'F';
			CurTimeStr[1] = 'r';
			CurTimeStr[2] = 'i';
			break;
			}
		case 6: {
			CurTimeStr[0] = 'S';
			CurTimeStr[1] = 'a';
			CurTimeStr[2] = 't';
			break;
			}
		}
	CurTimeStr[3] = ',';
	CurTimeStr[4] = ' ';
	CurTimeStr[5] = 0;

	//Day
	if (CurTime->wDay < 10) {
		CurTimeStr[5] = '0';
		CurTimeStr[6] = 0;
		}

	itoa(CurTime->wDay, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

	CurTimeStr[7] = ' ';

	//Month
	switch(CurTime->wMonth) {
		case 1: {
			CurTimeStr[ 8] = 'J';
			CurTimeStr[ 9] = 'a';
			CurTimeStr[10] = 'n';
			break;
			}
		case 2: {
			CurTimeStr[ 8] = 'F';
			CurTimeStr[ 9] = 'e';
			CurTimeStr[10] = 'b';
			break;
			}
		case 3: {
			CurTimeStr[ 8] = 'M';
			CurTimeStr[ 9] = 'a';
			CurTimeStr[10] = 'r';
			break;
			}
		case 4: {
			CurTimeStr[ 8] = 'A';
			CurTimeStr[ 9] = 'p';
			CurTimeStr[10] = 'r';
			break;
			}
		case 5: {
			CurTimeStr[ 8] = 'M';
			CurTimeStr[ 9] = 'a';
			CurTimeStr[10] = 'y';
			break;
			}
		case 6: {
			CurTimeStr[ 8] = 'J';
			CurTimeStr[ 9] = 'u';
			CurTimeStr[10] = 'n';
			break;
			}
		case 7: {
			CurTimeStr[ 8] = 'J';
			CurTimeStr[ 9] = 'u';
			CurTimeStr[10] = 'l';
			break;
			}
		case 8: {
			CurTimeStr[ 8] = 'A';
			CurTimeStr[ 9] = 'u';
			CurTimeStr[10] = 'g';
			break;
			}
		case 9: {
			CurTimeStr[ 8] = 'S';
			CurTimeStr[ 9] = 'e';
			CurTimeStr[10] = 'p';
			break;
			}
		case 10: {
			CurTimeStr[ 8] = 'O';
			CurTimeStr[ 9] = 'c';
			CurTimeStr[10] = 't';
			break;
			}
		case 11: {
			CurTimeStr[ 8] = 'N';
			CurTimeStr[ 9] = 'o';
			CurTimeStr[10] = 'v';
			break;
			}
		case 12: {
			CurTimeStr[ 8] = 'D';
			CurTimeStr[ 9] = 'e';
			CurTimeStr[10] = 'c';
			break;
			}
		}

	CurTimeStr[11] = ' ';
	CurTimeStr[12] = 0;

	//Year
	itoa(CurTime->wYear, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

	CurTimeStr[16] = ' ';
	CurTimeStr[17] = 0;

	//Hour
	if (CurTime->wHour == 0) {
		CurTimeStr[17] = '0';
		CurTimeStr[18] = '0';
		CurTimeStr[19] = 0;
		}
	else if (CurTime->wHour < 10) {
		CurTimeStr[17] = '0';
		CurTimeStr[18] = 0;
		itoa(CurTime->wHour, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wHour, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	CurTimeStr[19] = ':';
	CurTimeStr[20] = 0;

	//Min
	if (CurTime->wMinute == 0) {
		CurTimeStr[20] = '0';
		CurTimeStr[21] = '0';
		CurTimeStr[22] = 0;
		}
	else if (CurTime->wMinute < 10) {
		CurTimeStr[20] = '0';
		CurTimeStr[21] = 0;
		itoa(CurTime->wMinute, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wMinute, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	itoa(CurTime->wMinute, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);
	CurTimeStr[22] = ':';
	CurTimeStr[23] = 0;

	//Sec
	if (CurTime->wSecond == 0) {
		CurTimeStr[23] = '0';
		CurTimeStr[24] = '0';
		CurTimeStr[25] = 0;
		}
	else if (CurTime->wSecond < 10) {
		CurTimeStr[23] = '0';
		CurTimeStr[24] = 0;
		itoa(CurTime->wSecond, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wSecond, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	itoa(CurTime->wSecond, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

	CurTimeStr[25] = ' ';
	CurTimeStr[26] = 'G';
	CurTimeStr[27] = 'M';
	CurTimeStr[28] = 'T';
	CurTimeStr[29] = 0;
	}
/******************************************************************************/
void DateToOffsetFormatStr(SYSTEMTIME *CurTime, char *CurTimeStr) {
	char WorkStr[33];

   CurTimeStr[0] = 0;

	//Day
	if (CurTime->wDay < 10) {
		CurTimeStr[0] = '0';
		CurTimeStr[1] = 0;
		}

	itoa(CurTime->wDay, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

   //Slash
   CurTimeStr[2] = '/';

	//Month
	switch(CurTime->wMonth) {
		case 1: {
			CurTimeStr[3] = 'J';
			CurTimeStr[4] = 'a';
			CurTimeStr[5] = 'n';
			break;
			}
		case 2: {
			CurTimeStr[3] = 'F';
			CurTimeStr[4] = 'e';
			CurTimeStr[5] = 'b';
			break;
			}
		case 3: {
			CurTimeStr[3] = 'M';
			CurTimeStr[4] = 'a';
			CurTimeStr[5] = 'r';
			break;
			}
		case 4: {
			CurTimeStr[3] = 'A';
			CurTimeStr[4] = 'p';
			CurTimeStr[5] = 'r';
			break;
			}
		case 5: {
			CurTimeStr[3] = 'M';
			CurTimeStr[4] = 'a';
			CurTimeStr[5] = 'y';
			break;
			}
		case 6: {
			CurTimeStr[3] = 'J';
			CurTimeStr[4] = 'u';
			CurTimeStr[5] = 'n';
			break;
			}
		case 7: {
			CurTimeStr[3] = 'J';
			CurTimeStr[4] = 'u';
			CurTimeStr[5] = 'l';
			break;
			}
		case 8: {
			CurTimeStr[3] = 'A';
			CurTimeStr[4] = 'u';
			CurTimeStr[5] = 'g';
			break;
			}
		case 9: {
			CurTimeStr[3] = 'S';
			CurTimeStr[4] = 'e';
			CurTimeStr[5] = 'p';
			break;
			}
		case 10: {
			CurTimeStr[3] = 'O';
			CurTimeStr[4] = 'c';
			CurTimeStr[5] = 't';
			break;
			}
		case 11: {
			CurTimeStr[3] = 'N';
			CurTimeStr[4] = 'o';
			CurTimeStr[5] = 'v';
			break;
			}
		case 12: {
			CurTimeStr[3] = 'D';
			CurTimeStr[4] = 'e';
			CurTimeStr[5] = 'c';
			break;
			}
		}

   //Slash
   CurTimeStr[6] = '/';
   CurTimeStr[7] = 0;

   //Slash

	//Year
	itoa(CurTime->wYear, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

   //Colon
   CurTimeStr[11] = ':';
   CurTimeStr[12] = 0;

	//Hour
	if (CurTime->wHour == 0) {
		CurTimeStr[12] = '0';
		CurTimeStr[13] = '0';
		CurTimeStr[14] = 0;
		}
	else if (CurTime->wHour < 10) {
		CurTimeStr[12] = '0';
		CurTimeStr[13] = 0;
		itoa(CurTime->wHour, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wHour, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}

   //Colon
	CurTimeStr[14] = ':';
	CurTimeStr[15] = 0;

	//Min
	if (CurTime->wMinute == 0) {
		CurTimeStr[15] = '0';
		CurTimeStr[16] = '0';
		CurTimeStr[17] = 0;
		}
	else if (CurTime->wMinute < 10) {
		CurTimeStr[15] = '0';
		CurTimeStr[16] = 0;
		itoa(CurTime->wMinute, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wMinute, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	itoa(CurTime->wMinute, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);


   //Colon
	CurTimeStr[17] = ':';
	CurTimeStr[18] = 0;

	//Sec
	if (CurTime->wSecond == 0) {
		CurTimeStr[18] = '0';
		CurTimeStr[19] = '0';
		CurTimeStr[20] = 0;
		}
	else if (CurTime->wSecond < 10) {
		CurTimeStr[18] = '0';
		CurTimeStr[19] = 0;
		itoa(CurTime->wSecond, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	else {
		itoa(CurTime->wSecond, WorkStr, 10);
		strcat(CurTimeStr, WorkStr);
		}
	itoa(CurTime->wSecond, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

   //Space
   CurTimeStr[20] = ' ';
   CurTimeStr[21] = 0;

   //Zone Offset
   TIME_ZONE_INFORMATION TimeZoneInfo;
   GetTimeZoneInformation(&TimeZoneInfo);

   //Sign
   if (TimeZoneInfo.Bias >= 0) {
   	//Offset is positive
		CurTimeStr[21] = '+';
   	}
   else {
   	//Offset it negative
		CurTimeStr[21] = '-';
   	}

   int OffsetMin;
   int OffsetSec;

   OffsetMin = abs(TimeZoneInfo.Bias / 60);
   OffsetSec = abs(TimeZoneInfo.Bias % 60);

   //Minutes
   if (OffsetMin < 10) {
   	//Need a 0 in the tens place...
      CurTimeStr[22] = '0';
      CurTimeStr[23] = 0;
   	}
   else {
   	CurTimeStr[22] = 0;
   	}
   itoa(OffsetMin, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);

   //Seconds
   if (OffsetSec < 10) {
   	//Need a 0 in the tens place...
      CurTimeStr[24] = '0';
      CurTimeStr[25] = 0;
   	}
   else {
      CurTimeStr[24] = 0;
   	}
   itoa(OffsetSec, WorkStr, 10);
	strcat(CurTimeStr, WorkStr);
	}
/******************************************************************************/
int StrToDate(char *PassedCurTimeStr, SYSTEMTIME *CurTime) {
	char CurTimeStr[200];
	char WorkStr[17];

   //Make a copy and uppercase it so we do no insensitive comparisons
   strcpy(CurTimeStr, PassedCurTimeStr);
   CharUpper(CurTimeStr);

	//Time strings don't include ms, so zero it out
	CurTime->wMilliseconds = 0;

	//Figure out what kind of format it is based on the 4th charactor
	//(lame, but should work)
	if(CurTimeStr[3] == ',') {
		//RFC 822, updated by RFC 1123
		//Day of Week
		WorkStr[0] = CurTimeStr[0];
		WorkStr[1] = CurTimeStr[1];
		WorkStr[2] = CurTimeStr[2];
		WorkStr[3] = 0;
		if (strcmp(WorkStr, "SUN") == 0) {
			CurTime->wDayOfWeek = 0;
			}
		else if (strcmp(WorkStr, "MON") == 0) {
			CurTime->wDayOfWeek = 1;
			}
		else if (strcmp(WorkStr, "TUE") == 0) {
			CurTime->wDayOfWeek = 2;
			}
		else if (strcmp(WorkStr, "WED") == 0) {
			CurTime->wDayOfWeek = 3;
			}
		else if (strcmp(WorkStr, "THU") == 0) {
			CurTime->wDayOfWeek = 4;
			}
		else if (strcmp(WorkStr, "FRI") == 0) {
			CurTime->wDayOfWeek = 5;
			}
		else if (strcmp(WorkStr, "SAT") == 0) {
			CurTime->wDayOfWeek = 6;
			}
		else {
			LogError("Failure to convert RFC 822 time string, bad day of week");
			return -1; //Error
			}
		//Day
		if ((CurTimeStr[5] == '0') || (CurTimeStr[5] == ' ')) {
			WorkStr[0] = CurTimeStr[6];
			WorkStr[1] = 0;
			}
		else {
			WorkStr[0] = CurTimeStr[5];
			WorkStr[1] = CurTimeStr[6];
			WorkStr[2] = 0;
			}
		if ((CurTime->wDay = (WORD) atoi(WorkStr)) == 0) {
			LogError("Failure to convert RFC 822 time string, bad day number 1");
			return -1; //Error
			}
		else if (CurTime->wDay >= 34) {
			LogError("Failure to convert RFC 822 time string, bad day number 2");
			return -1; //Error
			}

		//Month
		WorkStr[0] = CurTimeStr[ 8];
		WorkStr[1] = CurTimeStr[ 9];
		WorkStr[2] = CurTimeStr[10];
		WorkStr[3] = 0;
		if (strcmp(WorkStr, "JAN") == 0) {
			CurTime->wMonth = 1;
			}
		else if (strcmp(WorkStr, "FEB") == 0) {
			CurTime->wMonth = 2;
			}
		else if (strcmp(WorkStr, "MAR") == 0) {
			CurTime->wMonth = 3;
			}
		else if (strcmp(WorkStr, "APR") == 0) {
			CurTime->wMonth = 4;
			}
		else if (strcmp(WorkStr, "MAY") == 0) {
			CurTime->wMonth = 5;
			}
		else if (strcmp(WorkStr, "JUN") == 0) {
			CurTime->wMonth = 6;
			}
		else if (strcmp(WorkStr, "JUL") == 0) {
			CurTime->wMonth = 7;
			}
		else if (strcmp(WorkStr, "AUG") == 0) {
			CurTime->wMonth = 8;
			}
		else if (strcmp(WorkStr, "SEP") == 0) {
			CurTime->wMonth = 9;
			}
		else if (strcmp(WorkStr, "OCT") == 0) {
			CurTime->wMonth = 10;
			}
		else if (strcmp(WorkStr, "NOV") == 0) {
			CurTime->wMonth = 11;
			}
		else if (strcmp(WorkStr, "DEC") == 0) {
			CurTime->wMonth = 12;
			}
		else {
			LogError("Failure to convert RFC 822 time string, bad month string");
			return -1; //Error
			}

		//Year
		WorkStr[0] = CurTimeStr[12];
		WorkStr[1] = CurTimeStr[13];
		WorkStr[2] = CurTimeStr[14];
		WorkStr[3] = CurTimeStr[15];
		WorkStr[4] = 0;
		if ((CurTime->wYear = (WORD) atoi(WorkStr)) == 0) {
			LogError("Failure to convert RFC 822 time string, bad year number 1");
			return -1; //Error
			}
		else if ((CurTime->wYear < 1950) || (CurTime->wYear > 2500)) {
			LogError("Failure to convert RFC 822 time string, bad year number 2");
			return -1; //Error
			}

		//Hour
		WorkStr[0] = CurTimeStr[17];
		WorkStr[1] = CurTimeStr[18];
		WorkStr[2] = 0;
		CurTime->wHour = (WORD) atoi(WorkStr);
		if (CurTime->wHour >= 24) {
			LogError("Failure to convert RFC 822 time string, bad hour number");
			return -1; //Error
			}

		//Minute
		WorkStr[0] = CurTimeStr[20];
		WorkStr[1] = CurTimeStr[21];
		WorkStr[2] = 0;
		CurTime->wMinute = (WORD) atoi(WorkStr);
		if (CurTime->wMinute >= 60) {
			LogError("Failure to convert RFC 822 time string, bad minute number");
			return -1; //Error
			}

		//Second
		WorkStr[0] = CurTimeStr[23];
		WorkStr[1] = CurTimeStr[24];
		WorkStr[2] = 0;
		CurTime->wSecond = (WORD) atoi(WorkStr);
		if (CurTime->wSecond >= 60) {
			LogError("Failure to convert RFC 822 time string, bad second number");
			return -1; //Error
			}

		//Varify the GMT
		WorkStr[0] = CurTimeStr[26];
		WorkStr[1] = CurTimeStr[27];
		WorkStr[2] = CurTimeStr[28];
		WorkStr[3] = 0;
		if (strcmpi(WorkStr, "GMT") != 0) {
			LogError("Failure to convert RFC 822 time string, GMT missing");
			return -1; //Error
			}
		}


	else if (CurTimeStr[3] == ' ') {
		//ANSI C's asctime() format
		//Day of Week
		WorkStr[0] = CurTimeStr[0];
		WorkStr[1] = CurTimeStr[1];
		WorkStr[2] = CurTimeStr[2];
		WorkStr[3] = 0;
		if (strcmp(WorkStr, "SUN") == 0) {
			CurTime->wDayOfWeek = 0;
			}
		else if (strcmp(WorkStr, "MON") == 0) {
			CurTime->wDayOfWeek = 1;
			}
		else if (strcmp(WorkStr, "TUE") == 0) {
			CurTime->wDayOfWeek = 2;
			}
		else if (strcmp(WorkStr, "WED") == 0) {
			CurTime->wDayOfWeek = 3;
			}
		else if (strcmp(WorkStr, "THU") == 0) {
			CurTime->wDayOfWeek = 4;
			}
		else if (strcmp(WorkStr, "FRI") == 0) {
			CurTime->wDayOfWeek = 5;
			}
		else if (strcmp(WorkStr, "SAT") == 0) {
			CurTime->wDayOfWeek = 6;
			}
		else {
			LogError("Failure to convert asctime time string, bad day of week");
			return -1; //Error
			}

		//Month
		WorkStr[0] = CurTimeStr[4];
		WorkStr[1] = CurTimeStr[5];
		WorkStr[2] = CurTimeStr[6];
		WorkStr[3] = 0;
		if (strcmp(WorkStr, "JAN") == 0) {
			CurTime->wMonth = 1;
			}
		else if (strcmp(WorkStr, "FEB") == 0) {
			CurTime->wMonth = 2;
			}
		else if (strcmp(WorkStr, "MAR") == 0) {
			CurTime->wMonth = 3;
			}
		else if (strcmp(WorkStr, "APR") == 0) {
			CurTime->wMonth = 4;
			}
		else if (strcmp(WorkStr, "MAY") == 0) {
			CurTime->wMonth = 5;
			}
		else if (strcmp(WorkStr, "JUN") == 0) {
			CurTime->wMonth = 6;
			}
		else if (strcmp(WorkStr, "JUL") == 0) {
			CurTime->wMonth = 7;
			}
		else if (strcmp(WorkStr, "AUG") == 0) {
			CurTime->wMonth = 8;
			}
		else if (strcmp(WorkStr, "SEP") == 0) {
			CurTime->wMonth = 9;
			}
		else if (strcmp(WorkStr, "OCT") == 0) {
			CurTime->wMonth = 10;
			}
		else if (strcmp(WorkStr, "NOV") == 0) {
			CurTime->wMonth = 11;
			}
		else if (strcmp(WorkStr, "DEC") == 0) {
			CurTime->wMonth = 12;
			}
		else {
			LogError("Failure to convert asctime time string, bad month string");
			return -1; //Error
			}

		//Day
		if ((CurTimeStr[7] == '0') || (CurTimeStr[5] == ' ')) {
			WorkStr[0] = CurTimeStr[8];
			WorkStr[1] = 0;
			}
		else {
			WorkStr[0] = CurTimeStr[7];
			WorkStr[1] = CurTimeStr[8];
			WorkStr[2] = 0;
			}
		if ((CurTime->wDay = (WORD) atoi(WorkStr)) == 0) {
			LogError("Failure to convert asctime time string, bad day number 1");
			return -1; //Error
			}
		else if (CurTime->wDay >= 34) {
			LogError("Failure to convert asctime time string, bad day number 2");
			return -1; //Error
			}

		//Hour
		WorkStr[0] = CurTimeStr[11];
		WorkStr[1] = CurTimeStr[12];
		WorkStr[2] = 0;
		CurTime->wHour = (WORD) atoi(WorkStr);
		if (CurTime->wHour >= 24) {
			LogError("Failure to convert asctime time string, bad hour number");
			return -1; //Error
			}

		//Minute
		WorkStr[0] = CurTimeStr[14];
		WorkStr[1] = CurTimeStr[15];
		WorkStr[2] = 0;
		CurTime->wMinute = (WORD) atoi(WorkStr);
		if (CurTime->wMinute >= 60) {
			LogError("Failure to convert asctime time string, bad minute number");
			return -1; //Error
			}

		//Second
		WorkStr[0] = CurTimeStr[17];
		WorkStr[1] = CurTimeStr[18];
		WorkStr[2] = 0;
		CurTime->wSecond = (WORD) atoi(WorkStr);
		if (CurTime->wSecond >= 60) {
			LogError("Failure to convert asctime time string, bad second number");
			return -1; //Error
			}

		//Year
		WorkStr[0] = CurTimeStr[20];
		WorkStr[1] = CurTimeStr[21];
		WorkStr[2] = CurTimeStr[22];
		WorkStr[3] = CurTimeStr[23];
		WorkStr[4] = 0;
		if ((CurTime->wYear = (WORD) atoi(WorkStr)) == 0) {
			LogError("Failure to convert asctime time string, bad year number 1");
			return -1; //Error
			}
		else if ((CurTime->wYear < 1950) || (CurTime->wYear > 2500)) {
			LogError("Failure to convert asctime time string, bad year number 2");
			return -1; //Error
			}
		}


	else {
		//Assume RFC 850, obsoleted by RFC 1036
		int Offset = 0;//Offset from day of week


		//Day of Week
		while ((Offset < 17) && (CurTimeStr[Offset] != ',')) {
			WorkStr[Offset] = CurTimeStr[Offset];
			Offset++;
			}
		if (Offset == 17) {
			LogError("Failure to convert RFC 850 time string, failure to get day of week");
			return -1;
			}
	  WorkStr[Offset] = 0;

		if (strcmp(WorkStr, "SUNDAY") == 0) {
			CurTime->wDayOfWeek = 0;
			}
		else if (strcmp(WorkStr, "MONDAY") == 0) {
			CurTime->wDayOfWeek = 1;
			}
		else if (strcmp(WorkStr, "TUESDAY") == 0) {
			CurTime->wDayOfWeek = 2;
			}
		else if (strcmp(WorkStr, "WEDNESDAY") == 0) {
			CurTime->wDayOfWeek = 3;
			}
		else if (strcmp(WorkStr, "THURSDAY") == 0) {
			CurTime->wDayOfWeek = 4;
			}
		else if (strcmp(WorkStr, "FRIDAY") == 0) {
			CurTime->wDayOfWeek = 5;
			}
		else if (strcmp(WorkStr, "SATURDAY") == 0) {
			CurTime->wDayOfWeek = 6;
			}
		else {
			LogError("Failure to convert RFC 850 time string, bad day of week");
			return -1; //Error
			}

		//Day
		if ((CurTimeStr[Offset+2] == '0') || (CurTimeStr[Offset+2] == ' ')) {
			WorkStr[0] = CurTimeStr[Offset+3];
			WorkStr[1] = 0;
			}
		else {
			WorkStr[0] = CurTimeStr[Offset+2];
			WorkStr[1] = CurTimeStr[Offset+3];
			WorkStr[2] = 0;
			}
		if ((CurTime->wDay = (WORD) atoi(WorkStr)) == 0) {
			LogError("Failure to convert RFC 850 time string, bad day number 1");
			return -1; //Error
			}
		else if (CurTime->wDay >= 34) {
			LogError("Failure to convert RFC 850 time string, bad day number 2");
			return -1; //Error
			}

		//Month
		WorkStr[0] = CurTimeStr[Offset+5];
		WorkStr[1] = CurTimeStr[Offset+6];
		WorkStr[2] = CurTimeStr[Offset+7];
		WorkStr[3] = 0;
		if (strcmp(WorkStr, "JAN") == 0) {
			CurTime->wMonth = 1;
			}
		else if (strcmp(WorkStr, "FEB") == 0) {
			CurTime->wMonth = 2;
			}
		else if (strcmp(WorkStr, "MAR") == 0) {
			CurTime->wMonth = 3;
			}
		else if (strcmp(WorkStr, "APR") == 0) {
			CurTime->wMonth = 4;
			}
		else if (strcmp(WorkStr, "MAY") == 0) {
			CurTime->wMonth = 5;
			}
		else if (strcmp(WorkStr, "JUN") == 0) {
			CurTime->wMonth = 6;
			}
		else if (strcmp(WorkStr, "JUL") == 0) {
			CurTime->wMonth = 7;
			}
		else if (strcmp(WorkStr, "AUG") == 0) {
			CurTime->wMonth = 8;
			}
		else if (strcmp(WorkStr, "SEP") == 0) {
			CurTime->wMonth = 9;
			}
		else if (strcmp(WorkStr, "OCT") == 0) {
			CurTime->wMonth = 10;
			}
		else if (strcmp(WorkStr, "NOV") == 0) {
			CurTime->wMonth = 11;
			}
		else if (strcmp(WorkStr, "DEC") == 0) {
			CurTime->wMonth = 12;
			}
		else {
			LogError("Failure to convert RFC 850 time string, bad month string");
			return -1; //Error
			}

		//Year
		WorkStr[0] = CurTimeStr[Offset+9];
		WorkStr[1] = CurTimeStr[Offset+10];
		WorkStr[4] = 0;
		CurTime->wYear = (WORD) atoi(WorkStr);
		if (CurTime->wYear > 70)   //Cover years from 1970-2069
			CurTime->wYear += (WORD) 1900;
		else
			CurTime->wYear += (WORD) 2000;

		//Hour
		WorkStr[0] = CurTimeStr[Offset+12];
		WorkStr[1] = CurTimeStr[Offset+13];
		WorkStr[2] = 0;
		CurTime->wHour = (WORD) atoi(WorkStr);
		if (CurTime->wHour >= 24) {
			LogError("Failure to convert RFC 850 time string, bad hour number");
			return -1; //Error
			}

		//Minute
		WorkStr[0] = CurTimeStr[Offset+15];
		WorkStr[1] = CurTimeStr[Offset+16];
		WorkStr[2] = 0;
		CurTime->wMinute = (WORD) atoi(WorkStr);
		if (CurTime->wMinute >= 60) {
			LogError("Failure to convert RFC 850 time string, bad minute number");
			return -1; //Error
			}

		//Second
		WorkStr[0] = CurTimeStr[Offset+18];
		WorkStr[1] = CurTimeStr[Offset+19];
		WorkStr[2] = 0;
		CurTime->wSecond = (WORD) atoi(WorkStr);
		if (CurTime->wSecond >= 60) {
			LogError("Failure to convert RFC 850 time string, bad second number");
			return -1; //Error
			}

		//Varify the GMT
		WorkStr[0] = CurTimeStr[Offset+21];
		WorkStr[1] = CurTimeStr[Offset+22];
		WorkStr[2] = CurTimeStr[Offset+23];
		WorkStr[3] = 0;
		if (strcmpi(WorkStr, "GMT") != 0) {
			LogError("Failure to convert RFC 850 time string, GMT missing");
			return -1; //Error
			}
		}

	return 0; //Success
	}
/******************************************************************************/
