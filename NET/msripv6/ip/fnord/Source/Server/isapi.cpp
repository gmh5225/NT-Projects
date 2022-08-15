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
#include "netio.h"
#include "registry.h"
#include "httplog.h"
#include "httpreq.h"
#include "httpsend.h"
#include "httpext.h"
#include "isapi.h"

#define MAX_VAR_STR_LEN 256
#define ISAPI_PENDING_TIMEOUT 60 * 60 * 1000 //1 Hour

struct ConnTableEntry {
	BOOL Allocated;
   RequestInfoT *RequestInfo;
   RequestFieldsT *RequestFields;
   char *QueryStr;
   HANDLE ISAPIDoneEvent;
	};

static ConnTableEntry *ConnTable;
static int MaxNumConn;
static CRITICAL_SECTION GetTableEntryCritSec;

//Exported Functions
BOOL WINAPI GetServerVariableExport(HCONN hConn, LPSTR lpszVariableName,
	LPVOID lpvBuffer, LPDWORD lpdwSize);
BOOL WINAPI WriteClientExport(HCONN hConn, LPVOID Buffer, LPDWORD lpdwBytes,
	DWORD /*dwReserved*/);
BOOL WINAPI ReadClientExport(HCONN hConn, LPVOID lpvBuffer, LPDWORD lpdwSize );
BOOL WINAPI ServerSupportFunctionExport(HCONN hConn, DWORD dwHSERRequest,
	LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType );

//Private Function Prototypes

/*
Function Name: HConnToConnTableEntry
Purpose: Translates the HCONN passed to exported functions into a pointer to
   the connections ConnTable entry.  Traps illegal HCONN values
Parameters:
   hConn - The connection handle to translate
Returns:
   A pointer to the connection table entry.  NULL on error.  Caller is
   responsible for logging the error and setting LastError
*/
ConnTableEntry *HConnToConnTableEntry(HCONN hConn);

/*
Function Name: ISAPI Redirect
Purpose: Handles redirection to a new URL from ServerSupportFunction
   HSE_REQ_SEND_URL_REDIRECT_RESP
Parameters:
   URL - URL or URI to redirect to
   RequestInfo - Request information structure
   RequestFields - Request fields structure
Notes: If the URL is a URI, the server name is added, resulting in a redirection
   to the same server
*/
void ISAPIRedirect(char *URL, RequestInfoT &RequestInfo,
   RequestFieldsT &RequestFields);

/*
Function Name: ISAPI Send URI
Purpose: Handles send URI from ServerSupportFunction HSE_REQ_SEND_URL
Parameters:
   URI - URI to send to client
   RequestInfo - Request information structure
   RequestFields - Request fields structure
Notes:
   Header information is sent along with the URI.  Docs were unclear, not sure
   if this is how MS does it...
*/
void ISAPISendURI(char *URI, RequestInfoT &RequestInfo,
   RequestFieldsT &RequestFields);

/*
Function Name: ISAPI Send Headers
Purpose: Sends the request headers from ServerSupportFunction
   HSE_REQ_SEND_RESPONSE_HEADER
Parameters:
   Status - Status line of the response, NULL for default ("200 OK")
   OtherHeaders - Other headers for the response, NULL for default
   OtherHeadersLen - Length of the other headers
   RequestInfo - Request information structure
   RequestFields - Request fields structure
Notes:
   The header "Server: Fnord" is always sent.
   The header "Content-Type: text/html" is sent if OtherHeaders is NULL.
*/
void ISAPISendHeaders(char *Status, char *OtherHeaders, DWORD OtherHeadersLen,
   RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);

/*
Function Name: ISAPI Build ALL_HTTP
Purpose: Builds the ALL_HTTP server variable.  This variable lists the avaible
   variables of the form HTTP_*
Parameters:
   ValStr - Buffer to hold the ALL_HTTP value
   lpdwSize - Pointer to the size of lpvBuffer
   RequestInfo - Request information structure
   RequestFields - Request fields structure
*/
void ISAPIBuildAllHTTP(char *ValStr, LPDWORD lpdwSize,
   RequestInfoT *RequestInfo, RequestFieldsT *RequestFields);

//Public Functions
/******************************************************************************/
void InitISAPI() {
	//Init the critical section
   InitializeCriticalSection(&GetTableEntryCritSec);

   //Get registry vars
   MaxNumConn = GetMaxNumThreads();

	//Allocate the connection table
   ConnTable = new ConnTableEntry[MaxNumConn];

   //Set all of the entries as free
   int i;
   for (i=0; i<MaxNumConn; i++) {
   	ConnTable[i].Allocated = FALSE;
   	}
	}
/******************************************************************************/
void CleanUpISAPI() {
	//Free the critical section
   DeleteCriticalSection(&GetTableEntryCritSec);
	//Deallocate the connection table
   delete[] ConnTable;
	}
/******************************************************************************/
void ProcessISAPIScript(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields,
	char *QueryStr, char *FilePath){
   ThreadDebugMessage(RequestInfo.ThreadNum, "ProcessISAPIScript()");

   //Varify the file exits
   ThreadDebugMessage(RequestInfo.ThreadNum, "Varify the file exists");
	DWORD FileAttr;
	FileAttr = GetFileAttributes(FilePath);
	if (FileAttr == 0xFFFFFFFF) {
		//Can't find it
		SendHTTPError(404, "File Not Found", "Could not find ISAPI Application module", RequestInfo, RequestFields);
		return;
		}
	else if ((FileAttr & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY) {
		//It's a directory, we can't run directories <grin>
		SendHTTPError(405, "Method Not Supported", "This resource does not support query", RequestInfo, RequestFields);
		return;
		}

   int ConnIndex; //hConn will be ConnIndex + 1  (don't want 0 to be a valid hConn)

   //Find an empty entry in the connection table
   ThreadDebugMessage(RequestInfo.ThreadNum, "Find an empty entry in the connection table");
   EnterCriticalSection(&GetTableEntryCritSec); //So 2 threads don't get the same entry
   ConnIndex = 0;
   while ((ConnTable[ConnIndex].Allocated != FALSE) && (ConnIndex < MaxNumConn)) {
   	ConnIndex++;
   	}
   LeaveCriticalSection(&GetTableEntryCritSec);
   if (ConnIndex == MaxNumConn) {
   	LogError("Unable to find free space in ISAPI Connection Table");
      SendHTTPError(501, "Internal Server Error",
      	"Unable to find free space in ISAPI Connection Table",
         RequestInfo, RequestFields);
      return;
   	}

   //Fill in the entry
   ThreadDebugMessage(RequestInfo.ThreadNum, "Fill in the entry");
   ConnTable[ConnIndex].Allocated = TRUE;
   ConnTable[ConnIndex].RequestInfo = &RequestInfo;
   ConnTable[ConnIndex].RequestFields = &RequestFields;
   ConnTable[ConnIndex].QueryStr = QueryStr;
   ConnTable[ConnIndex].ISAPIDoneEvent = CreateEvent(NULL, TRUE, FALSE, NULL);  //Off, ManualReset;

   //Load the module (I'm depending on the OS to suppress exessive reloads)
   ThreadDebugMessage(RequestInfo.ThreadNum, "Load the module");
   HMODULE AppHnd;
   AppHnd = LoadLibrary(FilePath);
   if (AppHnd == NULL) {
   	LogError("Failure to load IAPI application module");
      SendHTTPError(501, "Internal Server Error",
      	"Failure to load IAPI application module",
         RequestInfo, RequestFields);
      return;
   	}

   //Check the version number
   ThreadDebugMessage(RequestInfo.ThreadNum, "Check the version number");
   PFN_GETEXTENSIONVERSION GetExtensionVersion;
   HSE_VERSION_INFO Ver;


   GetExtensionVersion = (PFN_GETEXTENSIONVERSION) GetProcAddress(AppHnd, "GetExtensionVersion");

   if (GetExtensionVersion == NULL) {
   	LogError("Failure to get pointer to GetExtensionVersion() in IAPI application module");
      SendHTTPError(501, "Internal Server Error",
      	"Failure to get pointer to GetExtensionVersion() in IAPI application module",
         RequestInfo, RequestFields);
      return;
   	}

   _try {
      if(!GetExtensionVersion(&Ver)) {
   	   LogError("IAPI GetExtensionVersion() returned FALSE");
         SendHTTPError(501, "Internal Server Error",
      	   "IAPI GetExtensionVersion() returned FALSE",
            RequestInfo, RequestFields);
   	   }
	   }
   _except (TRUE) {
   	LogError("Unhandled exception in GetExtensionVersion() in IAPI application module");
      SendHTTPError(501, "Internal Server Error",
      	"Unhandled exception in GetExtensionVersion() in IAPI application module",
         RequestInfo, RequestFields);
      return;
	   }

   if (Ver.dwExtensionVersion > MAKELONG(HSE_VERSION_MINOR, HSE_VERSION_MAJOR)) {
   	LogError("IAPI version not supported");
      SendHTTPError(501, "Internal Server Error",
      	"IAPI version not supported",
         RequestInfo, RequestFields);
      return;
   	}

   //Fill in the control block
   ThreadDebugMessage(RequestInfo.ThreadNum, "Fill in the control block");
   EXTENSION_CONTROL_BLOCK ExtCtrlBlk;
   memset(&ExtCtrlBlk, 0, sizeof(ExtCtrlBlk));

   ExtCtrlBlk.cbSize = sizeof(ExtCtrlBlk);
   ExtCtrlBlk.dwVersion = MAKELONG(HSE_VERSION_MINOR, HSE_VERSION_MAJOR);

   ExtCtrlBlk.GetServerVariable = GetServerVariableExport;
	ExtCtrlBlk.ReadClient  = ReadClientExport;
	ExtCtrlBlk.WriteClient = WriteClientExport;
	ExtCtrlBlk.ServerSupportFunction = ServerSupportFunctionExport;

   ExtCtrlBlk.ConnID = (HCONN) (ConnIndex + 1);
   ExtCtrlBlk.dwHttpStatusCode = 200; //default to 200 Ok
   ExtCtrlBlk.lpszLogData[0] = '\0';  //default to empty string
   ExtCtrlBlk.lpszMethod = RequestFields.MethodStr;
   ExtCtrlBlk.lpszQueryString = QueryStr;
   ExtCtrlBlk.lpszPathInfo = RequestFields.PathInfoStr;
   ExtCtrlBlk.lpszPathTranslated = RequestFields.PathTranslatedStr;
   ExtCtrlBlk.cbTotalBytes = RequestFields.ContentLength;
   ExtCtrlBlk.cbAvailable = RequestFields.ContentLength;
   ExtCtrlBlk.lpbData = RequestFields.Content;
   ExtCtrlBlk.lpszContentType = RequestFields.ContentTypeStr;


   //Call the entry procedure
   ThreadDebugMessage(RequestInfo.ThreadNum, "Call the entry procedure");
   PFN_HTTPEXTENSIONPROC HttpExtensionProc;

   HttpExtensionProc = (PFN_HTTPEXTENSIONPROC) GetProcAddress(AppHnd, "HttpExtensionProc");
   if (HttpExtensionProc == NULL) {
   	LogError("Failure to get pointer to HttpExtensionProc() in IAPI application module");
      SendHTTPError(501, "Internal Server Error",
      	"Failure to get pointer to HttpExtensionProc() in IAPI application module",
         RequestInfo, RequestFields);
      return;
   	}

   DWORD Ret;

	_try {
		Ret = HttpExtensionProc(&ExtCtrlBlk);
	   }
   _except(TRUE) {
   	LogError("Unhandled exception in HttpExtensionProc() in IAPI application module");
      SendHTTPError(501, "Internal Server Error",
      	"Unhandled exception in HttpExtensionProc() in IAPI application module",
         RequestInfo, RequestFields);
      return;
	   }

   if (Ret == HSE_STATUS_PENDING) {
   	//Wait for the app to finish
      WaitForSingleObject(ConnTable[ConnIndex].ISAPIDoneEvent, ISAPI_PENDING_TIMEOUT);
   	}

   switch(Ret) {
      case HSE_STATUS_SUCCESS_AND_KEEP_CONN:
      RequestInfo.KeepAlive = TRUE;

      case HSE_STATUS_SUCCESS:
      case HSE_STATUS_ERROR:
      default:
      RequestInfo.KeepAlive = FALSE;
      }

   //Unload the module
   ThreadDebugMessage(RequestInfo.ThreadNum, "Unload the module");
   FreeLibrary(AppHnd);

   //We're done, remove it from the connection table
   ThreadDebugMessage(RequestInfo.ThreadNum, "Remove it from the connection table");
   ConnTable[ConnIndex].Allocated = FALSE;

   //Log the transaction
   ThreadDebugMessage(RequestInfo.ThreadNum, "Log the transaction");
	}
/******************************************************************************/
//Functions to be called from ISAPI Apps
/******************************************************************************/
BOOL WINAPI GetServerVariableExport(HCONN hConn, LPSTR lpszVariableName,
	LPVOID lpvBuffer, LPDWORD lpdwSize) {
   ConnTableEntry *ConnInfo;
   RequestFieldsT *RequestFields;
   RequestInfoT *RequestInfo;

   ConnInfo = HConnToConnTableEntry(hConn);
   if (ConnInfo == NULL) {
   	LogError("ISAPI exported funciton GetServerVariable got invalid hConn");
      SetLastError(ERROR_INVALID_PARAMETER);
   	return FALSE;
   	}
   RequestFields = ConnInfo->RequestFields;
   RequestInfo = ConnInfo->RequestInfo;

   //Convert the Variable name to uppercase so we can do case sensitive compares
   char VarStr[MAX_VAR_STR_LEN];

   strncpy(VarStr, lpszVariableName, MAX_VAR_STR_LEN);
   VarStr[MAX_VAR_STR_LEN] = '\0';
   CharUpper(VarStr);

   //Look for a match
   char NumStr[33];

   //Simple request line info v0.9
   if (strcmp("REQUEST_METHOD", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->MethodStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //added v1.0
	else if (strcmp("SERVER_PROTOCOL", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->VersionStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //General Header
   else if (strcmp("HTTP_DATE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->DateStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("HTTP_MIME_VERSION", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->MIMEVerStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("HTTP_PRAGMA", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->PragmaStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //Request Header
   else if (strcmp("HTTP_FROM", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->FromStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
      }
   else if (strcmp("HTTP_IF_MODIFIED_SINCE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->IfModSinceStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
      }
   else if (strcmp("HTTP_REFERER", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->RefererStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("HTTP_USER_AGENT", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->UserAgentStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //Entity Header (POST stuff)
   else if (strcmp("CONTENT_ENCODING", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->ContentEncodingStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("CONTENT_TYPE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->ContentTypeStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("CONTENT_LENGTH", VarStr) == 0) {
      if (RequestFields->ContentLengthStr[0] == '\0') {
         strncpy((char *) lpvBuffer, "0", *lpdwSize);
         }
      else {
         strncpy((char *) lpvBuffer, RequestFields->ContentLengthStr, *lpdwSize);
         }
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //v1.0 Optional (the more common ones)
   else if (strcmp("HTTP_ACCEPT", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->AcceptStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("HTTP_ACCEPT_LANGUAGE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->AcceptLangStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //v1.1 Exentions
   else if (strcmp("HTTP_CONNECTION", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->ConnectionStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //Authorization fields
   else if (strcmp("AUTH_TYPE", VarStr) == 0) {
   	if (RequestFields->AuthorizedUserStr[0] != 0) {
         strncpy((char *) lpvBuffer, "Basic", *lpdwSize);
         ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
         }
      else {
         ((char *) lpvBuffer)[0] = '\0';
      	}
   	}
      //Auth Pass *Not Supported*
   else if (strcmp("REMOTE_USER", VarStr) == 0) {
   	if (RequestFields->AuthorizedUserStr[0] != 0) {
         strncpy((char *) lpvBuffer, RequestFields->AuthorizedUserStr, *lpdwSize);
         ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
         }
      else {
         ((char *) lpvBuffer)[0] = '\0';
      	}
   	}
   //CGI style fields
	else if (strcmp("GATEWAY_INTERFACE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, "CGI/1.1", *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("REMOTE_HOST", VarStr) == 0) {
	   hostent *DNSResult;
	   char HostName[200];

      if (GetScriptDNS() == TRUE) { //Do a reverse DNS lookup
#ifdef MSRIPv6
	      DNSResult = getipnodebyaddr((char *)
                                      &(RequestInfo->ClientSockAddr.sin6_addr),
                                      RequestInfo->AddrLen, AF_INET6, NULL);
#else
	      DNSResult = gethostbyaddr((char *)&(RequestInfo->ClientSockAddr.sin_addr), RequestInfo->AddrLen, PF_INET);
#endif // MSRIPv6
         }
      else {                        //Don't bother
         DNSResult = NULL;
         }
	   if (DNSResult == NULL) {
#ifdef MSRIPv6
		   strcpy(HostName,
                  inet6_ntoa(&RequestInfo->ClientSockAddr.sin6_addr));
#else
		   strcpy(HostName, inet_ntoa(RequestInfo->ClientSockAddr.sin_addr));
#endif // MSRIPv6
         }
	   else {
		   strcpy(HostName, DNSResult->h_name);
         }
      strncpy((char *) lpvBuffer, HostName, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   else if (strcmp("REMOTE_ADDR", VarStr) == 0) {
	   char *AddrStr;
#ifdef MSRIPv6
	   AddrStr = inet6_ntoa(&RequestInfo->ClientSockAddr.sin6_addr);
#else
	   AddrStr = inet_ntoa(RequestInfo->ClientSockAddr.sin_addr);
#endif // MSRIPv6
      strncpy((char *) lpvBuffer, AddrStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("SERVER_NAME", VarStr) == 0) {
      strncpy((char *) lpvBuffer, GetServerName(), *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("SERVER_PORT", VarStr) == 0) {
      itoa(GetPortNum(), NumStr, 10);
      strncpy((char *) lpvBuffer, NumStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("SERVER_SOFTWARE", VarStr) == 0) {
      strncpy((char *) lpvBuffer, "Fnord", *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("QUERY_STRING", VarStr) == 0) {
      strncpy((char *) lpvBuffer, ConnInfo->QueryStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("PATH_INFO", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->PathInfoStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("PATH_TRANSLATED", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->PathTranslatedStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
	else if (strcmp("SCRIPT_NAME", VarStr) == 0) {
      strncpy((char *) lpvBuffer, RequestFields->ScriptNameStr, *lpdwSize);
      ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
   	}
   //ISAPI
   else if (strcmp("ALL_HTTP", VarStr) == 0) {
      ISAPIBuildAllHTTP((char *) lpvBuffer, lpdwSize, RequestInfo, RequestFields);
   	}
   //Other Headers
   else if (strncmp("HTTP_", VarStr, 5) == 0) { //Prefixed by HTTP_?
      int i;
      char *HTTPVarStr;

      HTTPVarStr = VarStr + 5; //Create a pointer past the "HTTP_" prefix
      i = 0;
      while ((i<RequestFields->NumOtherHeaders) &&
         (strcmp(RequestFields->OtherHeaders[i].Var, HTTPVarStr) != 0 ) ) {
         i++;
         }
      if (i < RequestFields->NumOtherHeaders) {
         strncpy((char *) lpvBuffer, RequestFields->OtherHeaders[i].Val, *lpdwSize);
         ((char *)lpvBuffer)[*lpdwSize - 1] = '\0';
         }
      else {
         //Could not find
         *lpdwSize = 0;
         SetLastError(ERROR_NO_DATA	);
         return FALSE;
         }
   	}
   else {
      //Could not find
      *lpdwSize = 0;
      SetLastError(ERROR_INVALID_INDEX);
      return FALSE;
   	}
   *lpdwSize = strlen((char *) lpvBuffer) + 1;
   return TRUE;
   };
/******************************************************************************/
BOOL WINAPI WriteClientExport(HCONN hConn, LPVOID Buffer, LPDWORD lpdwBytes,
	DWORD /*dwReserved*/) {
   ConnTableEntry *ConnInfo;
   RequestInfoT *RequestInfo;

   ConnInfo = HConnToConnTableEntry(hConn);
   if (ConnInfo == NULL) {
   	LogError("ISAPI exported funciton WriteClientExport got invalid hConn");
      SetLastError(ERROR_INVALID_PARAMETER);
   	return FALSE;
   	}

   RequestInfo = ConnInfo->RequestInfo;

   int Ret;
   Ret = SendData(RequestInfo->ClientSocket, (BYTE *) Buffer, *lpdwBytes,
       RequestInfo->ThreadNum);

   if (Ret == -1) { //Failure to send data
      *lpdwBytes = 0;
      return FALSE;
   	}
   else {
      //*lpdwBytes = *lpdwBytes  (everything sent)
	   return TRUE;
      }
   };
/******************************************************************************/
BOOL WINAPI ReadClientExport(HCONN hConn, LPVOID lpvBuffer, LPDWORD lpdwSize ) {
   ConnTableEntry *ConnInfo;
   RequestInfoT *RequestInfo;

   ConnInfo = HConnToConnTableEntry(hConn);
   if (ConnInfo == NULL) {
      LogError("ISAPI exported funciton ReadClientExport got invalid hConn");
      SetLastError(ERROR_INVALID_PARAMETER);
   	return FALSE;
   	}

   RequestInfo = ConnInfo->RequestInfo;

   int NumRead;

   NumRead = GetData(RequestInfo->ClientSocket, (BYTE *) lpvBuffer, *lpdwSize,
       RequestInfo->ThreadNum);

   if (NumRead == -1) {
      *lpdwSize = 0;
      return FALSE;
   	}
   else {
      *lpdwSize = NumRead;
	   return TRUE;
      }
	};
/******************************************************************************/
BOOL WINAPI ServerSupportFunctionExport(HCONN hConn, DWORD dwHSERRequest,
	LPVOID lpvBuffer, LPDWORD lpdwSize, LPDWORD lpdwDataType ) {
   ConnTableEntry *ConnInfo;

   ConnInfo = HConnToConnTableEntry(hConn);
   if (ConnInfo == NULL) {
   	LogError("ISAPI exported funciton ServerSupportFunctionExport got invalid hConn");
      SetLastError(ERROR_INVALID_PARAMETER);
   	return FALSE;
   	}

   switch (dwHSERRequest) {
   	case HSE_REQ_SEND_URL_REDIRECT_RESP:
        ISAPIRedirect((char *)lpvBuffer, *(ConnInfo->RequestInfo),
           *(ConnInfo->RequestFields));
        break;
      case HSE_REQ_SEND_URL:
        ISAPISendURI((char*)lpvBuffer, *(ConnInfo->RequestInfo),
           *(ConnInfo->RequestFields));
        break;
      case HSE_REQ_SEND_RESPONSE_HEADER:
        ISAPISendHeaders((char*)lpvBuffer, (char*)lpdwDataType, *lpdwSize,
            *(ConnInfo->RequestInfo), *(ConnInfo->RequestFields));
        break;
      case HSE_REQ_DONE_WITH_SESSION:
        //Signal event to request thread so it can finish if hung up...
        SetEvent(ConnInfo->ISAPIDoneEvent);
        break;
      default:
         //Unsupported request
      	return FALSE;
   	}
   return TRUE;
   };
/******************************************************************************/
//Private Functions
/******************************************************************************/
ConnTableEntry *HConnToConnTableEntry(HCONN hConn) {
   int ConnIndex = ((int) hConn) - 1;
   ConnTableEntry *ConnInfo;

   //Make sure we got a ConnIndex within range
   if ((ConnIndex < 0) || (ConnIndex >= MaxNumConn)) {
   	return NULL;
   	}

   //Make sure the table entry is allocated
   ConnInfo = &(ConnTable[ConnIndex]); //ConnIndex is hConn - 1
   if (ConnInfo->Allocated == FALSE) {
   	return NULL;
   	}

   return ConnInfo;
	}
/******************************************************************************/
void ISAPIRedirect(char *URL, RequestInfoT &RequestInfo,
   RequestFieldsT &RequestFields) {
   //See if it's a URL
   int i;
   i = 0;
   while ((URL[i] != 0) && (URL[i] != ':') && (URL[i] != '/')) {
      i++;
      }
   if (URL[i] == ':') {
      //Redirect to the associated URL
      SendHTTPRedirect(URL, RequestInfo, RequestFields);
      }
   else {
      //Redirect to the associated URI
      char NewURL[MAX_PATH];

      strcpy(NewURL, "http://");
      strcat(NewURL, GetServerName());
      if (URL[0] != '/') {
         //Make sure there is a slash to seperate location and URI
         strcat(NewURL, "/");
         }
      strcat(NewURL, URL);
      SendHTTPRedirect(NewURL, RequestInfo, RequestFields);
      }
	}
/******************************************************************************/
void ISAPISendURI(char *URI, RequestInfoT &RequestInfo,
   RequestFieldsT &RequestFields) {
   //Replace the URI related headers and go back to HTTPreq
   strcpy(RequestFields.URIStr, URI);
   RequestFields.PathInfoStr[0] = '\0';
   RequestFields.PathTranslatedStr[0] = '\0';
   RequestFields.ScriptNameStr[0] = '\0';
   Process10Request(RequestInfo, RequestFields);
	}
/******************************************************************************/
void ISAPISendHeaders(char *Status, char *OtherHeaders, DWORD OtherHeadersLen,
   RequestInfoT &RequestInfo, RequestFieldsT &/*RequestFields*/) {

   //Send Status Line and server header
   char StatusLine[200];

   if (Status == NULL) {
      strcpy(StatusLine, "HTTP/1.0 200 OK\r\n");
   	}
   else {
      strcpy(StatusLine, "HTTP/1.0 ");
   	strcat(StatusLine, Status);
      strcat(StatusLine, "\r\n");
   	}
   strcat(StatusLine, "Server: Fnord\r\n");

   if (SendData(RequestInfo.ClientSocket, (BYTE *) StatusLine,
      strlen(StatusLine), RequestInfo.ThreadNum) == -1) {
      return;
      }

   if (OtherHeaders == NULL) {
   	//Send our headers
      char Headers[200];
      strcpy(Headers, "Content-Type: text/html\r\n\r\n");   //Assume HTML output
      SendData(RequestInfo.ClientSocket, (BYTE *) Headers,
      strlen(Headers), RequestInfo.ThreadNum);
   	}
   else {
      //Send their headers
      SendData(RequestInfo.ClientSocket, (BYTE *) OtherHeaders,
      OtherHeadersLen, RequestInfo.ThreadNum);
   	}
	}
/******************************************************************************/
void ISAPIBuildAllHTTP(char *ValStr, LPDWORD lpdwSize,
   RequestInfoT * /*RequestInfo*/, RequestFieldsT *RequestFields) {
   int ValMaxLen;
   int ValLen;

   //Init to empty string
   ValStr[0] = '\0';
   ValLen = 0;
   ValMaxLen = *lpdwSize - 1; //Leave room for the '/0'

   //Add the vars
   //General Header
   if (RequestFields->DateStr[0] != '\0') {
      strncat(ValStr, "HTTP_DATE ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_DATE ");
   	}
   if (RequestFields->MIMEVerStr[0] != '\0') {
      strncat(ValStr, "HTTP_MIME_VERSION ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_MIME_VERSION ");
   	}
   if (RequestFields->PragmaStr[0] != '\0') {
      strncat(ValStr, "HTTP_PRAGMA ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_PRAGMA ");
   	}
   //Request Header
   if (RequestFields->FromStr[0] != '\0') {
      strncat(ValStr, "HTTP_FROM ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_FROM ");
   	}
   if (RequestFields->IfModSinceStr[0] != '\0') {
      strncat(ValStr, "HTTP_IF_MODIFIED_SINCE ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_IF_MODIFIED_SINCE ");
   	}
   if (RequestFields->RefererStr[0] != '\0') {
      strncat(ValStr, "HTTP_REFERER ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_REFERER ");
   	}
   if (RequestFields->UserAgentStr[0] != '\0') {
      strncat(ValStr, "HTTP_USER_AGENT ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_USER_AGENT ");
   	}
   //v1.0 Optional (the more common ones)
   if (RequestFields->AcceptStr[0] != '\0') {
      strncat(ValStr, "HTTP_ACCEPT ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_ACCEPT ");
   	}
   if (RequestFields->UserAgentStr[0] != '\0') {
      strncat(ValStr, "HTTP_ACCEPT_LANGUAGE ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_ACCEPT_LANGUAGE ");
   	}
   //v1.1 Exentions
   if (RequestFields->ConnectionStr[0] != '\0') {
      strncat(ValStr, "HTTP_CONNECTION ", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_CONNECTION ");
   	}
   //Other Headers
   int i;
   for(i=0; i<RequestFields->NumOtherHeaders; i++) {
      strncat(ValStr, "HTTP_", ValMaxLen - ValLen);
      ValLen += strlen("HTTP_");

   	strncat(ValStr, RequestFields->OtherHeaders[i].Val, ValMaxLen - ValLen);
      ValLen += strlen(RequestFields->OtherHeaders[i].Val);

      strncat(ValStr, " ", ValMaxLen - ValLen);
      ValLen += strlen(" ");
   	}

	}
/******************************************************************************/
