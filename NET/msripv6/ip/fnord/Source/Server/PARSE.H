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
Module Name: Parse
Purpose: General string parsing.  These are functions that are not in string.h,
	but are found in many other libraries and high level languages.
Public Functions:
	Left
	Right

	Trim
	TrimLeft
	TrimRight

	GetWord
	GetLastWord

   Split Path
   GetExtention
*/

/*
Function Name: Left
Purpose: Copies the leftmost x number of charactors of a string to a buffer
Parameters:
	DestStr - Destination buffer for substring
	SourceStr - Source string to make substing from
	Len - Length of substring

Notes: If Len is greater than strlen(SourceStr) a memory error may occur.
*/
void Left(char *DestStr, const char *SourceStr, const int Len);

/*
Function Name: Right
Purpose: Copies the rightmost x number of charactors of a string to a buffer
Parameters:
	DestStr - Destination buffer for substring
	SourceStr - Source string to make substing from
	Len - Length of substring

Notes: If Len is greater than strlen(SourceStr) then a memory error may
		 occur.
*/
void Right(char *DestStr, const char *SourceStr, const int Len);

/*
Function Name: TrimLeft
Purpose: Removes spaces and tabs from the left end of a string.
Parameters:
	TargetString - String to be trimmed
*/
void TrimLeft(char *TargetStr);

/*
Function Name: TrimRight
Purpose: Removes spaces and tabs from the right end of a string.
Parameters:
	TargetString - String to be trimmed
*/
void TrimRight(char *TargetStr);

/*
Function Name: Trim
Purpose: Removes spaces and tabs from both ends of a string.
Parameters:
	TargetString - String to be trimmed
*/
void Trim(char *TargetStr);

/*
Function Name: GetWord
Purpose: Gets leftmost substring without a space, starts at any position at
	the start string and sets End to be the next non-space charactor in the
	string.  ' ' and '\t' and considered spaces
Parameters:
	DestString - Destination buffer for substring
	SourceString - Source string to make substing from
	Start - 0 based string index to start at
	End - At end of function call is set to the location of next non-space
			charactor

Notes: If Start is greater than strlen(SourceStr) then a memory error may
		 occur.
*/
void GetWord(char *DestStr, const char *SourceStr, const int Start, int &End);

/*
Function Name: GetLastWord
Purpose: Gets rightmost substring without a space sets Start to be the 0 based
	index of where the substring starts in the original string.
Parameters:
	DestString - Destination buffer for substring
	SourceString - Source string to make substing from
	Start - 0 based string index where the DestString starts at
*/
void GetLastWord(char *DestString, const char *SourceStr, int &Start);


/*
Function Name: Split Path
Purpose: Splits a path string into directory and file name
Parameters:
	Path - Path string (example "c:\Fnord\SomeFile.Ext")
	Dir - Directory part of the Path (example "c:\Fnord\")
	FileName - File name part of the path (example "SomeFile.Ext")
*/
void SplitPath(char *Path, char *Dir, char *FileName);

/*
Function Name: Get Extention
Purpose: Splits a path string into directory and file name
Parameters:
	Path - Path string or file name (example "c:\Fnord\SomeFile.Ext")
	Extention - Extention part of the path (example "Ext")
*/
void GetExtention(char *Path, char *Extention);

/*
Function Name: Translate Escape String
Purpose: Translates all URL escape sequences, such as "%20" where "20" is
	the resulting charactor in hexidecimal
Parameters:
	TargetStr - String that may contain URL escape sequences.  All sequences
   	are decoded on return.
*/
void TranslateEscapeString(char *TargetStr);

/*
Function Name: Hex Value
Purpose: Returns the value of a hexidecimal digit character as an integer
Parameters:
	c - Charactor to translate
*/
int HexVal(char c);
