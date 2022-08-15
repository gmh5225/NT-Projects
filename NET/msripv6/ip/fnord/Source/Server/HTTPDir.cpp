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
Implementaion Notes: Thanks go out to Steve for his help with this one...
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
#include "httplog.h"
#include "httpreq.h"
#include "httpsend.h"
#include "httpdir.h"

//Monospace Display Format
//Name(35) Date(30) Size(15)
#define NameFieldLen 35
#define DateFieldLen 30
#define SizeFieldLen 15

//Private Structures
typedef struct DirectoryDataType {
   BOOL IsDirectory;
   char *Name;         //For sorting purposes
   char *HTMLLine;     //Full line of HTML code representing this entry
	DWORD HTMLLineLen;  //Length of HTML code
	DirectoryDataType *Next;
	} DirDataNode;

//Private Function Declarations

//Node management
/*
Function Name: CreateNode
Purpose: Create a new data node to hold directory information
Parameters:
	FirstNode - The first node of the linked list
	LastNode - The last node of the linked list
*/
DirDataNode *CreateNode(DirDataNode* &FirstNode, DirDataNode* &LastNode);

/*
Function Name: DeleteNodes
Purpose: Deletes all the nodes of a linked list
Parameters:
	FirstNode - The first node of the linked list
*/
void DeleteNodes(DirDataNode *FirstNode);

//Sorting stuff
/*
Function Name: MergeSort
Purpose: Sorts a linked list
Parameters:
	FirstNode - The first node of the linked list
*/
DirDataNode *MergeSort(DirDataNode *FirstNode);

/*
Function Name: Divide
Purpose: Divides a linked list into two lists.  Used with MergeSort
Parameters:
	FirstNode - The first node of the linked list
*/
DirDataNode *Divide(DirDataNode *FirstNode);

/*
Function Name: Merge
Purpose: Merges two linked list together.  Used with MergeSort
Parameters:
	FirstNode - Pointer to the first node
	SecondNode - Pointer to the second node
*/
DirDataNode *Merge(DirDataNode *FirstNode, DirDataNode *SecondNode);

//Public Functions
/******************************************************************************/
void SendHTTPDirList(char *DirStr, char *Realm, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields) {
	char LengthStr[17];
	int i, j;
	int Length;


	//Current Date
	SYSTEMTIME CurTime;
	char CurDateStr[100];
	GetSystemTime(&CurTime);
	DateToOffsetFormatStr(&CurTime, CurDateStr);

	//Directory Data as empty
	DirDataNode *FirstNode = NULL;
	DirDataNode *LastNode = NULL;
	DirDataNode *CurNode;

   //Parts of the final data
	char HeaderStr[512];
	char TrailerStr[512];
	DWORD HeaderLength;   //Header Length
	DWORD TrailerLength;  //Trailer Length
   DWORD DataLength = 0; //Total Length (including Header and Trailer, not
                         //counting HTTP headers)

	//Start HTML Data
	strcpy(HeaderStr, "<HTML><HEAD><TITLE>Directory of ");
	strcat(HeaderStr, RequestFields.URIStr);
	strcat(HeaderStr, "</TITLE></HEAD>\r\n");

	strcat(HeaderStr, "<BODY><H2>Directory of ");

   //Decode escape sequence....
   char TranslatedURIStr[ReqURIStrLen];
   strcpy(TranslatedURIStr, RequestFields.URIStr);
   TranslateEscapeString(TranslatedURIStr);

	strcat(HeaderStr, TranslatedURIStr);
	strcat(HeaderStr, "</H2><PRE>Name                                ");
	strcat(HeaderStr, "Last Modified                  ");
	strcat(HeaderStr, "Size</PRE><HR>\r\n");
	strcat(HeaderStr, "<PRE>");

   //Link to go up one directory should be here if allowed..
   //Figure out what it might be
   char UpLink[ReqURIStrLen];
   strcpy(UpLink, RequestFields.URIStr);
   Length = strlen(UpLink);

   if (Length - 2 > 0) { //Skip the trailing slash, but check bounds...
   	i = Length - 2;
      }
   else {
   	i = 0;
   	}
   while ((i > 0) && (UpLink[i] != '/')) {
   	i--;
   	}
   UpLink[i + 1] = 0;

   if ((strlen(UpLink) > strlen(Realm)) &&
   	 (strlen(UpLink) != strlen(RequestFields.URIStr)) ) {
   	//We're not going past our base and we're not linked to ourselves...
      strcat(HeaderStr, "<A HREF=\"");
      strcat(HeaderStr, UpLink);
      strcat(HeaderStr, "\">Previous Directory<br></A>\r\n");
   	}

	HeaderLength = strlen(HeaderStr);
	DataLength += HeaderLength;

	//Setup the search string, Path + *.*
   char SearchStr[MAX_PATH];
	strcpy(SearchStr, DirStr);
	strcat(SearchStr, "\\*.*");

   //Get first file
	WIN32_FIND_DATA FileInfo;
	HANDLE FileFindHandle;
	FileFindHandle = FindFirstFile(SearchStr, &FileInfo);
	if (FileFindHandle == INVALID_HANDLE_VALUE) {
		LogError("Failure to create FindFirstFile object for directory listing");
		SendHTTPError(500, "Internal Server Error", "Failure to create FindFirstFile object for directory listing", RequestInfo, RequestFields);
		}

   //Handle files
   BOOL IsDirectory;
   char HTMLLine[1024];
   int HTMLLineIndex;
	SYSTEMTIME FileDate;
	char FileDateStr[50];
   DWORD FileSize;
	char FileSizeStr[50];

	do {
		if (! ( (strcmp(FileInfo.cFileName, ".") == 0) ||
				  (strcmp(FileInfo.cFileName, "..") == 0) ) ) {
			//Not . or ..
			IsDirectory = (FileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;

			CurNode = CreateNode(FirstNode, LastNode);

         //--Set Directory flag--
			if(IsDirectory)
				CurNode->IsDirectory = TRUE;
			else
				CurNode->IsDirectory = FALSE;

			//--Set Name--
         CurNode->Name = new char[strlen(FileInfo.cFileName) + 2];
         strcpy(CurNode->Name, FileInfo.cFileName);
         if (CurNode->IsDirectory == TRUE) {
            strcat(CurNode->Name, "/");
         }

         //--Build HTML Line--
         //Prefix
         memcpy(HTMLLine, "<A HREF=\"", 9);
         HTMLLineIndex = 9;

         //Refererence
         i = 0;
         while (FileInfo.cFileName[i] != '\0') {
            //Escape out special charactors
	       	if (((FileInfo.cFileName[i] >= 'a') && (FileInfo.cFileName[i] <= 'z')) || //Lower Case Alpha
            	((FileInfo.cFileName[i] >= 'A') && (FileInfo.cFileName[i] <= 'Z')) || //Upper Case Alpha
               ((FileInfo.cFileName[i] >= '0') && (FileInfo.cFileName[i] <= '9')) || //Numbers
               (FileInfo.cFileName[i] == '.') || (FileInfo.cFileName[i] == '/')) {   // . or /
               //Use the exact charactor
               HTMLLine[HTMLLineIndex] = FileInfo.cFileName[i];
               HTMLLineIndex++;
               }
            else {
           		//Replace the charactor with an escape code
            	#pragma warn -sig //Suppress significant digit loss warning (BC++)
               int Digit;

               HTMLLine[HTMLLineIndex] = '%';
               HTMLLineIndex++;

               Digit = FileInfo.cFileName[i] / 16;
               if (Digit <= 9) {
               	HTMLLine[HTMLLineIndex] = '0' + Digit;
	              	}
               else {
              		HTMLLine[HTMLLineIndex] = 'A' + (Digit - 10);
	              	}
               HTMLLineIndex++;

               Digit = FileInfo.cFileName[i] % 16;
            	if (Digit <= 9) {
               	HTMLLine[HTMLLineIndex] = '0' + Digit;
            		}
            	else {
              		HTMLLine[HTMLLineIndex] = 'A' + (Digit - 10);
              		}
         		HTMLLineIndex++;
               #pragma warn +sig   //Restore significant digit loss warning (BC++)
               }
            i++;
        		}

         //Add a trailing / for directory links
         if (IsDirectory) {
            HTMLLine[HTMLLineIndex] = '/';
            HTMLLineIndex++;
         	}

         //Stuff between the reference and displayed Name
         memcpy(HTMLLine + HTMLLineIndex, "\">", 2);
         HTMLLineIndex += 2;

         //Name
         j = 0;
         for (i = 0; i<NameFieldLen; i++) {
            if (FileInfo.cFileName[j] == '\0') {
               HTMLLine[HTMLLineIndex] = ' ';
            	}
            else {
               HTMLLine[HTMLLineIndex] = FileInfo.cFileName[j];
               j++;
            	}
            HTMLLineIndex++;
         	}

         HTMLLine[HTMLLineIndex] = ' ';
         HTMLLineIndex++;

         //Date
         FILETIME LocalFileTime;
         if (FileTimeToLocalFileTime(&(FileInfo.ftLastWriteTime), &LocalFileTime) != TRUE) {
				LogError("Couldn't convert GMT file time to local file time");
				CloseHandle(FileFindHandle);
				return;
				}
			if (FileTimeToSystemTime(&LocalFileTime, &FileDate) != TRUE) {
				LogError("Couldn't convert file time to system time");
				CloseHandle(FileFindHandle);
				return;
				}
			DateToOffsetFormatStr(&FileDate, FileDateStr);

         j = 0;
         for (i=0; i<DateFieldLen; i++) {
            if (FileDateStr[j] == '\0') {
               HTMLLine[HTMLLineIndex] = ' ';
            	}
            else {
               HTMLLine[HTMLLineIndex] = FileDateStr[j];
               j++;
            	}
            HTMLLineIndex++;
         	}

         HTMLLine[HTMLLineIndex] = ' ';
         HTMLLineIndex++;

         //Size
			FileSize = FileInfo.nFileSizeLow; //Assume file is less than 2 GIG
			if (IsDirectory) {
				strcpy(FileSizeStr, "Directory");
				}
			else if (FileSize < 1024) { //express size in bytes
				ultoa(FileSize, FileSizeStr, 10);
				}
			else {                      //express size in Kbytes
				FileSize = FileSize / 1024;
				ultoa(FileSize, FileSizeStr, 10);
            strcat(FileSizeStr, "k");
				}

         j = 0;
         for (i=0; i<SizeFieldLen; i++) {
            if (FileSizeStr[j] == '\0') {
               HTMLLine[HTMLLineIndex] = ' ';
            	}
            else {
               HTMLLine[HTMLLineIndex] = FileSizeStr[j];
               j++;
            	}
            HTMLLineIndex++;
         	}

         HTMLLine[HTMLLineIndex] = ' ';
         HTMLLineIndex++;

         //Suffix
         memcpy(HTMLLine + HTMLLineIndex, "</A>\r\n", 6);
         HTMLLineIndex += 6;

         HTMLLine[HTMLLineIndex] = '\0';


         //Figure out how long this entry will be
         CurNode->HTMLLineLen = HTMLLineIndex;
         DataLength += HTMLLineIndex;

         //Put the HTML Line in the node
         CurNode->HTMLLine = new char[HTMLLineIndex + 1];
         memcpy(CurNode->HTMLLine, HTMLLine, HTMLLineIndex + 1);
			}
		} while(FindNextFile(FileFindHandle, &FileInfo) == TRUE);
	FindClose(FileFindHandle);

	//End HTML Data
	strcpy(TrailerStr, "</PRE><HR></BODY></HTML>");
	TrailerLength = 24;
	DataLength += TrailerLength;

	char Header[512];

	//Build Header
	Header[0] = 0;
	//Status Line
	strcat(Header, "HTTP/1.0 200 OK\r\n");
	//Server
	strcat(Header, "Server: Fnord\r\n");
	//Connection
	if (strcmpi(RequestFields.ConnectionStr, "Keep-Alive") == 0) {
		strcat(Header, "Connection: Keep-Alive\r\n");
		strcat(Header, "Keep-Alive: timeout=180\r\n");
		ThreadDebugMessage(RequestInfo.ThreadNum, "+++Keep-Alive+++");
		RequestInfo.KeepAlive = TRUE;
		}
	else {
		RequestInfo.KeepAlive = FALSE;
		}
	//Content Type (HTML)
	strcat(Header, "Content-Type: text/html\r\n");
	//Content Length
	itoa(DataLength, LengthStr, 10);
	strcat(Header, "Content-Length: ");
	strcat(Header, LengthStr);
	strcat(Header, "\r\n");
	//Single CRLF to end header
	strcat(Header, "\r\n");

	//Send header
	if (SendData(RequestInfo.ClientSocket, (BYTE *) Header, strlen(Header), RequestInfo.ThreadNum) == -1) {
		return;
		}

	//Send the data, head info first
	if (SendData(RequestInfo.ClientSocket, (BYTE *) HeaderStr, HeaderLength, RequestInfo.ThreadNum) == -1) {
		return;
		}

	//Sort the body
   FirstNode = MergeSort(FirstNode);

	//Next, send the body
	DirDataNode *LoopNode;
	long DataInBuffer;

	LoopNode = FirstNode;
	while(LoopNode != NULL) {
		//Put data into IOBuffer
		DataInBuffer = 0;
		while((LoopNode != NULL) &&
			(DataInBuffer + LoopNode->HTMLLineLen < RequestInfo.IOBufferSize)) {
         memcpy(RequestInfo.IOBuffer + DataInBuffer, LoopNode->HTMLLine,  LoopNode->HTMLLineLen);
         DataInBuffer += LoopNode->HTMLLineLen;
			LoopNode = LoopNode->Next;
			}
		//Send IOBuffer
		if (SendData(RequestInfo.ClientSocket, RequestInfo.IOBuffer, DataInBuffer, RequestInfo.ThreadNum) == -1) {
			return;
			}
		}

   //Send the ending info last
	if (SendData(RequestInfo.ClientSocket, (BYTE *) TrailerStr, TrailerLength, RequestInfo.ThreadNum) == -1) {
		return;
		}

   //Log it
	HTTPLogCommonEntry(&(RequestInfo.ClientSockAddr), RequestInfo.AddrLen,
		RequestFields.AuthorizedUserStr, CurDateStr, RequestFields.MethodStr,
		RequestFields.URIStr, "200", strlen(Header) + DataLength);
	HTTPLogCountEntry(RequestFields.URIStr, CurDateStr, strlen(Header) + DataLength);
	HTTPLogRefEntry(RequestFields.URIStr, RequestFields.RefererStr, CurDateStr);
	//Clean up
	DeleteNodes(FirstNode);
	}
/******************************************************************************/
//Private Functions
/******************************************************************************/
DirDataNode *CreateNode(DirDataNode* &FirstNode, DirDataNode* &LastNode){
	DirDataNode *NewNode;

	NewNode = new DirDataNode;
   NewNode->IsDirectory = FALSE;
   NewNode->Name = NULL;
   NewNode->HTMLLine = NULL;
	NewNode->HTMLLineLen = 0;
	NewNode->Next = NULL;

	if (FirstNode == NULL) {
		FirstNode = NewNode;
		LastNode = NewNode;
		}
	else {
		LastNode->Next = NewNode;
		LastNode = NewNode;
		}

	return NewNode;
	}
/******************************************************************************/
void DeleteNodes(DirDataNode *FirstNode) {
	DirDataNode *LoopNode;
	DirDataNode *TargetNode;

	LoopNode = FirstNode;
	while (LoopNode != NULL) {
		TargetNode = LoopNode;
		LoopNode = LoopNode->Next;
      delete[] TargetNode->Name;
      delete[] TargetNode->HTMLLine;
		delete TargetNode;
		}
	}
/******************************************************************************/
DirDataNode *MergeSort(DirDataNode *FirstNode) {
	DirDataNode *FirstHalf;
	DirDataNode *SecondHalf;
	DirDataNode *Whole;

	Whole = FirstNode;
	FirstHalf = FirstNode;

	if((Whole != NULL) && (Whole->Next != NULL)) {
		SecondHalf = Divide(Whole);
		FirstHalf = MergeSort(FirstHalf);
		SecondHalf = MergeSort(SecondHalf);
		Whole = Merge(FirstHalf, SecondHalf);
		}

	return Whole;
	}
/******************************************************************************/
DirDataNode *Divide(DirDataNode *FirstNode) {
	DirDataNode *OneStepNode;
	DirDataNode *TwoStepNode;
	DirDataNode *HalfNode;

	//Make Inital steps
	OneStepNode = FirstNode;
	if (FirstNode->Next != NULL) {
		TwoStepNode = FirstNode->Next->Next;
		}
	else {
		TwoStepNode = FirstNode->Next;
		}

	while(TwoStepNode != NULL) {
		//Make the first step
		OneStepNode = OneStepNode->Next;
		TwoStepNode = TwoStepNode->Next;
		//Make the second step if we can
		if(TwoStepNode != NULL) {
			TwoStepNode = TwoStepNode->Next;
			}
		}

	//Set us at half
	HalfNode = OneStepNode->Next;

	//Seperate the lists
	OneStepNode->Next = NULL;

	return HalfNode;
	}
/******************************************************************************/
DirDataNode *Merge(DirDataNode *FirstHalf, DirDataNode *SecondHalf) {
	DirDataNode *NewHeadNode;
	DirDataNode *NewLastNode;

	//New list is empty
	NewHeadNode = NULL;
	NewLastNode = NULL;

	while ((FirstHalf != NULL) && (SecondHalf != NULL)) {
		//Remove an element from one of the lists and add it to the new one
		//Figure out which element is lower
		int CompResult;

		//Set CompResult based on what is and isn't a directory
		if ((FirstHalf->IsDirectory) && (!SecondHalf->IsDirectory)) {
			CompResult = -1;
			}
		else if ((!FirstHalf->IsDirectory) && (SecondHalf->IsDirectory)) {
			CompResult = 1;
			}
		else {
			CompResult = strcmpi(FirstHalf->Name, SecondHalf->Name);
			}

		//Take the lesser on the comp
		if (CompResult <= 0) {
			if (NewHeadNode == NULL) {
				NewHeadNode = FirstHalf;
				NewLastNode = FirstHalf;
				}
			else {
				NewLastNode->Next = FirstHalf;
				NewLastNode = FirstHalf;
				}
			FirstHalf = FirstHalf->Next;
			NewLastNode->Next = NULL;
			}
		else {
			if (NewHeadNode == NULL) {
				NewHeadNode = SecondHalf;
				NewLastNode = SecondHalf;
				}
			else {
				NewLastNode->Next = SecondHalf;
				NewLastNode = SecondHalf;
				}
			SecondHalf = SecondHalf->Next;
			NewLastNode->Next = NULL;
			}
		}

	if (FirstHalf != NULL) {
		//Add the first half to the end of the new one
		if (NewHeadNode == NULL) {
			NewHeadNode = FirstHalf;
			}
		else {
			NewLastNode->Next = FirstHalf;
			}
		}

	if (SecondHalf != NULL) {
		//Add the second half to the end of the new one
		if (NewHeadNode == NULL) {
			NewHeadNode = SecondHalf;
			}
		else {
			NewLastNode->Next = SecondHalf;
			}
		}

	return NewHeadNode;
	}
/******************************************************************************/
