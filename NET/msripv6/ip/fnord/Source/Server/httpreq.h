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
Module Name: HTTP Reqeust
Purpose: Parses HTTP requests and then calls the appropriate function
	to respond to the request
Public Functions:
	Request Thread
*/

// Public Data Structures

//Used for sending information to the request thread
struct RequestThreadMessageT {
	int ThreadId;

	HANDLE GoEventHnd;
	HANDLE FreeEventHnd;

	BOOL Shutdown;
   BOOL CloseHandles;

#ifdef MSRIPv6
	SOCKADDR_IN6 ClientSockAddr;
#else
	SOCKADDR_IN ClientSockAddr;
#endif // MSRIPv6
	SOCKET ClientSocket;
	int AddrLen;
	};

//Length constants for RequestFieldsT
#define ReqMethodStrLen           24
#define ReqURIStrLen             512
#define ReqVersionStrLen          24
#define ReqDateStrLen             48
#define ReqMIMEVerStrLen          24
#define ReqPragmaStrLen          128
#define ReqAuthorizationStrLen   512
#define ReqFromStrLen            128
#define ReqIfModSinceStrLen       48
#define ReqRefererStrLen         512
#define ReqUserAgentStrLen       256
#define ReqContentEncodingStrLen 128
#define ReqContentTypeStrLen     128
#define ReqContentLengthStrLen    48
#define ReqAcceptStrLen          512
#define ReqAcceptLangStrLen       48
#define ReqConnectionStrLen       24
#define ReqAuthorizedUserStrLen   48
#define ReqPathInfoStrLen        512
#define ReqPathTranslatedStrLen  512
#define ReqScriptNameStrLen      512
//                               ---
//                              4692

#define MAX_OTHER_HEADERS 50

struct RequestHeaderT {
	char *Var;
   char *Val;
	};

struct RequestFieldsT {
	//Simple request line info v0.9
	char MethodStr[ReqMethodStrLen];
	char URIStr[ReqURIStrLen];
	//added v1.0
	char VersionStr[ReqVersionStrLen];
	//General Header
	char DateStr[ReqDateStrLen];
	char MIMEVerStr[ReqMIMEVerStrLen];
	char PragmaStr[ReqPragmaStrLen];
	//Request Header
	char AuthorizationStr[ReqAuthorizationStrLen];
	char FromStr[ReqFromStrLen];
	char IfModSinceStr[ReqIfModSinceStrLen];
	char RefererStr[ReqRefererStrLen];
	char UserAgentStr[ReqUserAgentStrLen];
	//Entity Header (POST stuff)
	char ContentEncodingStr[ReqContentEncodingStrLen];
	char ContentTypeStr[ReqContentTypeStrLen];
	char ContentLengthStr[ReqContentLengthStrLen];
   //v1.0 Optional (the more common ones)
   char AcceptStr[ReqAcceptStrLen];
   char AcceptLangStr[ReqAcceptLangStrLen];
	//v1.1 Exentions
	char ConnectionStr[ReqConnectionStrLen];
	//Pointer to buffer containing the content
	DWORD ContentLength;
	BYTE *Content;

	//Authorized user, filled in if a user is authorized from Auth..Str above
	char AuthorizedUserStr[ReqAuthorizedUserStrLen];

   //CGI style fields
   char PathInfoStr[ReqPathInfoStrLen];
   char PathTranslatedStr[ReqPathTranslatedStrLen];
   char ScriptNameStr[ReqScriptNameStrLen];

   //Other Headers
   int NumOtherHeaders;
   RequestHeaderT OtherHeaders[MAX_OTHER_HEADERS];
	};

struct RequestInfoT {
	int ThreadNum;

	//Buffer for IO operations (so we're not constantly reallocating buffers)
	BYTE *IOBuffer;
   int IOBufferSize;

	//Socket the request is on and its address
	SOCKET ClientSocket;
#ifdef MSRIPv6
	SOCKADDR_IN6 ClientSockAddr;
#else
	SOCKADDR_IN ClientSockAddr;
#endif // MSRIPv6
	int AddrLen;

	//Should we keep the connection alive?
	BOOL KeepAlive;
	};


// Public Functions

/*
Function Name: RequestThread
Purpose: HTTP request processing thread
Parameters:
	ParamMem - Global handle to a Windows memory block containing its parameters
*/
void RequestThread(HGLOBAL ParamMem);

/*
Function Name: Process 1.0 Request
Purpose: Sends a HTTP 1.0 (plus some) reply to a HTTP 1.x request
Parameters:
	ClientSocket - Socket the client is on
	ClientSockAddr - Address of client
	AddrLen - Length of client address
	RequestInfo - Structure storing the parsed headers
	KeepAlive - To be set to true if we are maintainig the connection
	IOBuffer - Pointer to buffer allocated for IO operations
	TheadNum - Number of calling thread for debugging
Notes: The function uses "Connection: Keep-Alive" as written in the HTTP/1.1
	draft and implemented by Netscape and MSIE
*/
void Process10Request(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);


