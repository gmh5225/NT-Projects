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
Implementaion Notes: Code for testing if a point is in a region taken, with
	modification, from Kevin Hughes (kevinh@pulua.hcc.hawaii.edu) CGI program.
   The polygon code in that program (and this one) is by Eric Haines
   (erich@eye.com)
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
#include "date.h"
#include "netio.h"
#include "registry.h"
#include "httplog.h"
#include "httpreq.h"
#include "httpsend.h"
#include "imagemap.h"

//Private Declarations and Types

#define MAXNUMSTR 33
#define MAXLINE 500
#define MAXVERTS 100
#define X 0
#define Y 1

enum RegionType { RectRgn, CircleRgn, PolyRgn, DefaultRgn, PointRgn};


//Private Function Declarations

/*
Function Name: String To Points
Purpose: Converts a string consisting of 2 numbers with a comma between
	them (no spaces) to a pair of floating point numbers
Parameters:
	WorkStr - String containing the numbers
   Point - 2 eletment array to store the output numbers
*/
void StrToPoints(char *WorkStr, double Point[2]);

/*
Funciton Name: Get Image Map Line
Purpose: Gets a line as a null terminated string from an open text file
Parameters:
	InFileHnd - Win32 handle of input file
   Buffer - Buffer for IO
   BufferLen - Size of Buffer
   DataInBuffer - Managed internaly, amount of data in buffer
   BufferIndex - Managed internaly, current position in buffer
   LineBuffer - Buffer to output line string to
   LineBufferLen - Size of line buffer
Returns: TRUE on success, FALSE on failure or end of file
*/
BOOL GetImageMapLine(HANDLE InFileHnd, BYTE *Buffer, int BufferLen,
	int &DataInBuffer, int &BufferIndex, char *LineBuffer, int LineBufferLen);


/*
Function Name: Parse Image Map Line
Purpose: Interputs the data from a line from an image map file storing the
	results in variables we can work with.  Errors are logged to the error
   log.
Parameters:
	LineBuffer - String holding the line to parse
   RegionType - Region type is output here
   URI - Associated URI is output here
   Coords - Associated coordinates are stored here
   NumCoords - Number of coordinated output
   MapFileNameStr - File name of map file (for error reporting)
   LineNum - Line number being parsed (for error reporting)
Returns: True if the line contains a region and associated information, False
	if there is no information on the line (comment) or on error
*/
BOOL ParseImageMapLine(char *LineBuf, enum RegionType &Region, char *URI,
	double Coords[MAXVERTS][2], int &NumCoords, char *MapFileNameStr, int LineNum);

/*
Function Name: LogImageMapParseError
Purpose: Logs an error with the name of the map file and the line number that
	caused the error.
Parameters:
	ErrorDescStr - Description of the error
   MapFileNameStr - File name of the map file
   LineNum - Line number in the map file
*/
void LogImageMapParseError(char *ErrorDescStr, char *MapFileNameStr, int LineNum);

/*
Function Name: Point In Rectangle
Purpose: Determines if a given point is in a rectangle
Parameters:
	Point - Point to test
   Coords - Array of points describing the rectangle, must be
   	at least 2
*/
BOOL PointInRect(double Point[2], double Coords[MAXVERTS][2]);

/*
Function Name: Point In Circle
Purpose: Determines if a given point is in a circle
Parameters:
	Point - Point to test
   Coords - Array of points describing the circle, must be
   	at least 2
*/
BOOL PointInCircle(double Point[2], double Coords[MAXVERTS][2]);

/*
Function Name: Point In Polygon
Purpose: Determines if a given point is in a polygon
Parameters:
	point - Point to test
   pgon - Array of points describing the polygon, must be
   	at least 3
   numverts - Number of verticies in the pgon array
*/
BOOL PointInPoly(double point[2], double pgon[MAXVERTS][2], int numverts);


//Public Functions

/******************************************************************************/
void ProcessImageMap(RequestInfoT &RequestInfo, RequestFieldsT RequestFields,
	char *QueryStr, char *MapFilePath) {

   double TestPoint[2];

   //Parse the querry string
   if (QueryStr[0] == 0) {
   	SendHTTPError(501, "Parameters expected", "Expected parameters for imagemap",  RequestInfo, RequestFields);
      return;
   	}

   StrToPoints(QueryStr, TestPoint);

   //Open the map file
   HANDLE MapFileHnd;

   MapFileHnd = CreateFile(MapFilePath, GENERIC_READ, FILE_SHARE_WRITE | FILE_SHARE_READ,
      NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
   if (MapFileHnd == INVALID_HANDLE_VALUE) {
   	SendHTTPError(404, "File Not Found", "Image map not found",  RequestInfo, RequestFields);
		return;
   	}

   char LineBuffer [MAXLINE + 1];
   int LineNum = 0;
   int IOBufferIndex = 0;
   int DataInIOBuffer = 0;

   enum RegionType Region;
   double Coords[MAXVERTS][2];
   int NumCoords;
   char URIBuffer[MAX_PATH];
   double Dist;

   BOOL Match = FALSE;
   char BestURI[MAX_PATH];
   double BestURIDist;

   BestURI[0] = 0;  //No default found yet
   BestURIDist = 0;

   //Get a line
   while((!Match) &&
         (GetImageMapLine(MapFileHnd, RequestInfo.IOBuffer, RequestInfo.IOBufferSize,
         	DataInIOBuffer, IOBufferIndex, LineBuffer, MAXLINE + 1)
         )) {
      LineNum++;

      //Parse the line (assume error is reported by ParseImageMapLine)
      if (ParseImageMapLine(LineBuffer, Region, URIBuffer, Coords, NumCoords,
      	MapFilePath, LineNum)) {

      	switch (Region) {
      		case RectRgn:
					if (NumCoords < 2) {
   					LogImageMapParseError("rectangle expected 2 points",
      					MapFilePath, LineNum);
      				return;
   					}
         		if (PointInRect(TestPoint, Coords)) {
            		Match = TRUE;
               	strcpy(BestURI, URIBuffer);
            		}
         		break;
         	case CircleRgn:
   				if (NumCoords < 2) {
   					LogImageMapParseError("circle expected 2 points",
                  	MapFilePath, LineNum);
   					return;
   					}
         		if (PointInCircle(TestPoint, Coords)) {
            		Match = TRUE;
               	strcpy(BestURI, URIBuffer);
            		}
					break;
         	case PolyRgn:
    				if (NumCoords < 3) {
   					LogImageMapParseError("polygon expected at least 3 points",
      					MapFilePath, LineNum);
   					return;
   					}
         		if (PointInPoly(TestPoint, Coords, NumCoords)) {
            		Match = TRUE;
               	strcpy(BestURI, URIBuffer);
            		}
         		break;
         	case DefaultRgn:
         		strcpy(BestURI, URIBuffer);
            	BestURIDist = 0;
         		break;
				case PointRgn:
    				if (NumCoords < 1) {
   					LogImageMapParseError("point expected at least 1 point",
      					MapFilePath, LineNum);
   					return;
                  }
            	Dist = ((TestPoint[X] - Coords[0][X]) *
            		(TestPoint[X] - Coords[0][X])) + ((TestPoint[Y] - Coords[0][Y]) *
            		(TestPoint[Y] - Coords[0][Y]));
               if ((BestURI[0] == 0) || (Dist < BestURIDist)) {
         			strcpy(BestURI, URIBuffer);
            		BestURIDist = Dist;
               	}
         		break;
         	default:
         		LogError("ParseImageMapLine returned an unexpected region value");
      		}
         }
   	}

   if (BestURI[0] == 0) {
   	//No match, default or point, send error
      SendHTTPError(404, "No URL", "No URL was associated with the selected point",  RequestInfo, RequestFields);
   	}
   else {
   	//See if it's a URL
      int i;
      i = 0;
      while ((BestURI[i] != 0) && (BestURI[i] != ':') && (BestURI[i] != '/')) {
      	i++;
      	}
      char NewURL[MAX_PATH];
      if (BestURI[i] == ':') {
      	//Redirect to the associated URL
         //strcpy(NewURL, BestURI);
         //SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
         SendHTTPRedirect(BestURI, RequestInfo, RequestFields);
      	}
      else {
   		//Redirect to the associated URI
			strcpy(NewURL, "http://");
      	strcat(NewURL, GetServerName());
         if (BestURI[0] != '/') {
         	//Make sure there is a slash to seperate location and URI
         	strcat(NewURL, "/");
         	}
      	strcat(NewURL, BestURI);
      	SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
      	}
   	}

   //Close the map file
   CloseHandle(MapFileHnd);
	}
/******************************************************************************/
//Private Functions
/******************************************************************************/
void StrToPoints(char *WorkStr, double Point[2]) {
	int i, j;
   char NumStr[MAXNUMSTR];

   i = 0;
   j = 0;
   while ((WorkStr[i] != ',') && (WorkStr[i] != 0) && (j < MAXNUMSTR)) {
   	NumStr[j] = WorkStr[i];
      i++;
      j++;
   	}
   NumStr[j] = 0;
   Point[X] = (double) atol(NumStr);

   if (WorkStr[i] == ',') {
   	i++;
      }

   j = 0;
   while ((WorkStr[i] != ',') && (WorkStr[i] != 0) && (j < MAXNUMSTR)) {
   	NumStr[j] = WorkStr[i];
      i++;
      j++;
   	}
   NumStr[j] = 0;
   Point[Y] = (double) atol(NumStr);
	}
/******************************************************************************/
BOOL GetImageMapLine(HANDLE InFileHnd, BYTE *Buffer, int BufferLen,
	int &DataInBuffer, int &BufferIndex, char *LineBuffer, int LineBufferLen) {

	int i;
   DWORD NumRead;
	char CurChar;

	i = 0;
	do {
		if (BufferIndex >= DataInBuffer) { //Need more data
      	if (ReadFile(InFileHnd, Buffer, BufferLen, &NumRead, NULL) != TRUE) {
         	if (i == 0) {
            	//Done, nothing to send back
            	return FALSE;
            	}
            else {
            	//Send the last line
            	LineBuffer[i] = 0;
					return TRUE;
               }
         	}
			DataInBuffer = NumRead;
         BufferIndex = 0;
			if (DataInBuffer == 0) {
         	if (i == 0) {
            	//Done, nothing to send back
            	return FALSE;
            	}
            else {
            	//Send the last line
            	LineBuffer[i] = 0;
					return TRUE;
               }
				}
			}
		CurChar = Buffer[BufferIndex];
		BufferIndex++;
		if ((CurChar != 10) && (CurChar != 13))  {
			LineBuffer[i] = CurChar;
			i++;
			}
		} while ((CurChar != 10) && (i < LineBufferLen));
	if (i == LineBufferLen) {
		LogError("GetImageMapLine() Overflow");
		return FALSE;
		}
	LineBuffer[i] = 0;
	return TRUE;
	}
/******************************************************************************/
BOOL ParseImageMapLine(char *LineBuf, enum RegionType &Region, char *URI,
	double Coords[MAXVERTS][2], int &NumCoords, char *MapFileNameStr, int LineNum) {
   char WorkStr[MAXLINE];
   int LineIndex = 0;
   int NextLineIndex = 0;

   Trim(LineBuf); //Eliminate any trailing or leading spaces

   //Get the region type
   GetWord(WorkStr, LineBuf, LineIndex, NextLineIndex);
   LineIndex = NextLineIndex;

   if ((WorkStr[0] == 0) || (WorkStr[0] == '#') || (WorkStr[0] == '/') ||
   	(WorkStr[0] == '\'')) {
   	//Comment (blank or begins with #, / or ' )
      return FALSE;
   	}
   else if ((strcmpi("rect", WorkStr) == 0) ||
   	(strcmpi("rectangle", WorkStr) == 0)) {
   	//rectangle
      Region = RectRgn;
   	}
   else if (strcmpi("circle", WorkStr) == 0) {
   	//circle
      Region = CircleRgn;
   	}
   else if ((strcmpi("poly", WorkStr) == 0) ||
   	(strcmpi("polygon", WorkStr) == 0)) {
   	//polygon
      Region = PolyRgn;
   	}
   else if (strcmpi("default", WorkStr) == 0) {
   	//default
      Region = DefaultRgn;
   	}
   else if (strcmpi("point", WorkStr) == 0) {
   	//point
      Region = PointRgn;
   	}
   else {
   	//parse error
		LogImageMapParseError("Unexpected region type", MapFileNameStr, LineNum);
      return FALSE;
   	}

   //Get the associated URI
   GetWord(URI, LineBuf, LineIndex, NextLineIndex);
   LineIndex = NextLineIndex;

   if (URI[0] == 0) {
		LogImageMapParseError("Expected URI to associate with region", MapFileNameStr, LineNum);
      return FALSE;
   	}

   //Read in the point(s) for the region
   NumCoords = 0;

   GetWord(WorkStr, LineBuf, LineIndex, NextLineIndex);
   LineIndex = NextLineIndex;

   while (WorkStr[0] != 0) {
   	StrToPoints(WorkStr, Coords[NumCoords]);
      NumCoords++;

   	GetWord(WorkStr, LineBuf, LineIndex, NextLineIndex);
   	LineIndex = NextLineIndex;
   	}

   return TRUE;
	}
/******************************************************************************/
void LogImageMapParseError(char *ErrorDescStr, char *MapFileNameStr, int LineNum) {
	char ErrorStr[MAX_PATH + MAX_PATH];
   char NumStr[17];

   strcpy(ErrorStr, "Parse error in imagemap ");
   strcat(ErrorStr, MapFileNameStr);
   strcat(ErrorStr, " line number ");
   itoa(LineNum, NumStr, 10);
   strcat(ErrorStr, NumStr);
   strcat(ErrorStr, " ");
   strcat(ErrorStr, ErrorDescStr);
   LogError(ErrorStr);
	}
/******************************************************************************/
BOOL PointInRect(double Point[2], double Coords[MAXVERTS][2]) {

   //Move lower numbers to index 0
   double Temp;
   if (Coords[0][X] > Coords[1][X]) {
   	Temp = Coords[0][X];
      Coords[0][X] = Coords[1][X];
      Coords[1][X] = Temp;
   	}
  if (Coords[0][Y] > Coords[1][Y]) {
   	Temp = Coords[0][Y];
      Coords[0][Y] = Coords[1][Y];
      Coords[1][Y] = Temp;
   	}

	return (((Point[X] >= Coords[0][X]) && (Point[X] <= Coords[1][X])) &&
           ((Point[Y] >= Coords[0][Y]) && (Point[Y] <= Coords[1][Y])));
	}
/******************************************************************************/
BOOL PointInCircle(double Point[2], double Coords[MAXVERTS][2]) {
	double Radius1, Radius2;

   Radius1 = ((Coords[0][Y] - Coords[1][Y]) * (Coords[0][Y] - Coords[1][Y])) +
   	((Coords[0][X] - Coords[1][X]) * (Coords[0][X] - Coords[1][X]));

   Radius2 = ((Coords[0][Y] - Point[Y]) * (Coords[0][Y] - Point[Y])) +
		((Coords[0][X] - Point[X]) * (Coords[0][X] - Point[X]));

   return (Radius2 <= Radius1);
	}
/******************************************************************************/
BOOL PointInPoly(double point[2], double pgon[MAXVERTS][2], int numverts) {
	int inside_flag, xflag0;
   int crossings;
   double *p, *stop;
   double tx, ty, y;

   crossings = 0;

   tx = point[X];
   ty = point[Y];
   y = pgon[numverts - 1][Y];

   p = (double *) pgon + 1;
   if ((y >= ty) != (*p >= ty)) {
   	if ((xflag0 = (pgon[numverts - 1][X] >= tx)) == (*(double *) pgon >= tx)) {
      	if (xflag0)
         	crossings++;
         }
      else {
      	crossings += (pgon[numverts - 1][X] - (y - ty) *
         	(*(double *) pgon - pgon[numverts - 1][X]) /
            (*p - y)) >= tx;
         }
      }

   stop = pgon[numverts];

   for (y = *p, p += 2; p < stop; y = *p, p += 2) {
   	if (y >= ty) {
      	while ((p < stop) && (*p >= ty))
         	p += 2;
         if (p >= stop)
         	break;
         if ((xflag0 = (*(p - 3) >= tx)) == (*(p - 1) >= tx)) {
         	if (xflag0)
            	crossings++;
            }
         else {
         	crossings += (*(p - 3) - (*(p - 2) - ty) *
            	(*(p - 1) - *(p - 3)) / (*p - *(p - 2))) >= tx;
            }
         }
      else {
      	while ((p < stop) && (*p < ty))
         	p += 2;
         if (p >= stop)
         	break;
         if ((xflag0 = (*(p - 3) >= tx)) == (*(p - 1) >= tx)) {
         	if (xflag0)
            	crossings++;
            }
         else {
         	crossings += (*(p - 3) - (*(p - 2) - ty) *
            	(*(p - 1) - *(p - 3)) / (*p - *(p - 2))) >= tx;
            }
         }
      }
   inside_flag = crossings & 0x01;
   return (inside_flag);
   }
/******************************************************************************/
