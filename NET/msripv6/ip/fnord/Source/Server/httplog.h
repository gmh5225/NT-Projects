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
Module Name: Log
Purpose: Manages all of the request (not error or debug) logs for the server
Public Functions:
	InitHTTPLogs
	CleanUpHTTPLogs

	HTTPLogCommonEntry
	HTTPLogCountConnect
	HTTPLogCountEntry
	HTTPLogRefEntry
*/
/*
Function Name: Initialize HTTP Logs
Pupose: Initializes the HTTP log module
*/
void InitHTTPLogs();

/*
Function Name: Clean Up HTTP Logs
Pupose: Cleans up the log module
*/
void CleanUpHTTPLogs();

/*
Function Name: HTTP Log Common Entry
Pupose: Puts an entry in the HTTP common log
Parameters:
	Address - Address of the client
	AddressLength - Length of the address of the client
	AuthNameStr - Authorized user name, blank or NULL if no user was authorized
	DateStr - Date of the request
	MethodStr - Method of the request
	URIStr - Requested URI
	StatusCodeStr - Status code of the response
	Size - Size of the response
*/
void HTTPLogCommonEntry(
#ifdef MSRIPv6
SOCKADDR_IN6
#else
SOCKADDR_IN
#endif // MSRIPv6
*Address, int AddressLength, char *AuthNameStr,
	char *DateStr, char *MethodStr, char *URIStr, char *StatusCodeStr, long Size);

/*
Function Name: Log Count Connect
Pupose: Logs a successful connect
*/
void HTTPLogCountConnect();

/*
Function Name: Log Count Entry
Pupose: Logs a successful transfer
Parameters:
	URIStr - Requested URI
	DateStr - Date of the request
	Size - Size of the response
*/
void HTTPLogCountEntry(char *URIStr, char *DateStr, long Size);

/*
Function Name: Log Reference Entry
Pupose: Logs the reference for a request
Parameters:
	URIStr - Requested URI
	RefStr - Reference header, blank or NULL if there was none
	DateStr - Date of the request
*/
void HTTPLogRefEntry(char *URIStr, char *RefStr, char *DateStr);
