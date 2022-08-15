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
Module Name: HTTP Send
Purpose: Functions for sending HTTP responses to 1.X requests
Public Functions:
	SendHTTPFile
	SendHTTPError
	SendHTTPNotModified
	SendHTTPRedirect
	SendHTTPBasicChallenge
Notes: Considering adding a version number parameter to these functions.  Right
	now the way people are implementing HTTP/1.1 is by adding the new stuff
	to 1.0 requests.  I don't know of any browsers sending 1.1 requests yet.
*/

/*
Function Name: Send HTTP File
Purpose: Sends a file the client.  Common, count and refenece log
			entries are written.
Parameters:
	ErrorNum - HTTP error number to send
	ErrorDescStr - String describing the error
	RequestInfo - HTTP request information (see httpreq.h)
	RequestFields - Parsed HTTP header info (see httpreq.h)
*/
void SendHTTPFile(char *FileName, RequestInfoT &RequestInfo, RequestFieldsT RequestFields);

/*
Function Name: Send HTTP Error
Purpose: Sends a given error message to the client with either the error file
			as a body or a default error message body.  Common and refenece log
			entries are written, but not to the count log.
Parameters:
	ErrorNum - HTTP error number to send
   ErrorTitleStr - Title of the error
	ErrorDescStr - String describing the error
	RequestInfo - HTTP request information (see httpreq.h)
	RequestFields - Parsed HTTP header info (see httpreq.h)
*/
void SendHTTPError(int ErrorNum, char *ErrorTitleStr, char *ErrorDescStr, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);

/*
Function Name: Send HTTP Not Modified
Purpose: Sends not modified message to the client.  This is implemeted per the
			HTTP/1.1 draft.  An entry is written to the common log but not the count
			or reference logs.
Parameters:
	RequestInfo - HTTP request information (see httpreq.h)
	RequestFields - Parsed HTTP header info (see httpreq.h)
*/
void SendHTTPNotModified(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);

/*
Function Name: Send HTTP Redirect
Purpose: Sends a moved with a new URL to the client.  An entry is written to the
			common log but not the count or reference logs.
Parameters:
	NewURL - URL to redirect to
	RequestInfo - HTTP request information (see httpreq.h)
	RequestFields - Parsed HTTP header info (see httpreq.h)
*/
void SendHTTPRedirect(char *NewURL, RequestInfoT &RequestInfo, RequestFieldsT RequestFields);

/*
Function Name: SendHTTPBasicChallenge
Purpose: Sends BASIC authentication challenge to the client.  An entry is
			written to the common log but not the count or reference logs.
Parameters:
	RequestInfo - HTTP request information (see httpreq.h)
	RequestFields - Parsed HTTP header info (see httpreq.h)
*/
void SendHTTPBasicChallenge(char *Realm, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);
