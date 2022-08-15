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
Module Name: HTTP Path Map
Purpose: Manage path mappings
Public Functions:
	LoadHTTPPathMap
	UnloadHTTPPathMap
	MapHTTPPath
*/


//Public Functions
/*
Function Name: Load HTTP Path Map
Purpose: Loads the path mappings into memory and does other module intialization
*/
void LoadHTTPPathMap();

/*
Function Name: Unload HTTP Path Map
Purpose: Loads the path mappings into memory and does other module intialization
*/
void UnloadHTTPPathMap();

/*
Function Name: Map HTTP Path
Purpose: Given a URI (without a query string), it then replaces the remote
	directory with a local directory + filename and fetches access information
Parameters:
	URIStr - The requested URI (no query)
	RequestInfo - HTTP request information (see httpreq.h) for location based
                 access.
	RequestFields - Parsed HTTP header info (see httpreq.h) for user based
	                access.
	RemoteRealm - Remote Realm the file was mapped to
   LocalRealm - Remote Realm the file was mapped to
	FilePath - String to contain the localy mapped file + dir
	AllowDirList - TRUE if a directory listing is allowed in the mapped path
	Scripting - Kind of scripting allowed in the mapped area (see constants)
Returns: MP_ERROR on error
			MP_PATH_FOUND on success
			MP_NO_ACCESS if access was denied
			MP_FORBIDEN if access is strictly forbiden
			MP_REDIRECT if redirected to another URL
*/
int MapHTTPPath(char *URIStr, RequestInfoT &RequestInfo,
	RequestFieldsT &RequestFields, char *RemoteRealm, char *LocalRealm,
   char *FilePath, BOOL &AllowDirList, int &Scripting);

//Should consider replacing these with enums....

//Return constants for MapPath
#define MP_ERROR       -1
#define MP_PATH_FOUND   0
#define MP_NO_ACCESS    1
#define MP_FORBIDDEN    2
#define MP_REDIRECT     3

//Scripting constants
#define SCRIPTING_NONE    0
#define SCRIPTING_REDIR   1
#define SCRIPTING_WINCGI  2
#define SCRIPTING_CGI     3
#define SCRIPTING_ISAPI   4

//Location based authorization constants
#define AUTH_LOC_ANYWHERE 0
#define AUTH_LOC_CLASSA   1
#define AUTH_LOC_CLASSB   2
#define AUTH_LOC_CLASSC   3
#define AUTH_LOC_CLASSD   4
