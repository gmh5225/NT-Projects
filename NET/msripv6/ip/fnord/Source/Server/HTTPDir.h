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
Module Name: Directory Listing
Purpose: Lists a given directory
Functions:
	SendDirList

*/


/*
Function Name: Send HTTP Dir List
Purpose: Sends a directory list (with header) to the client socket.  Is
	responsible for own logging.
Parameters:
	DirStr - String describing the directory to be listed
   RealmStr - Base URI for the mapping
	ClientSocket - Socket the client is on
	ClientSockAddr - Address of client
	AddrLen - Length of address of client
	IOBuffer - Pointer to buffer allocated for IO operations
	ThreadNum - Number of thread that called this function for debugging purposes
		and possible use in the future (CGI/ISAPI)
*/
void SendHTTPDirList(char *DirStr, char *Realm, RequestInfoT &RequestInfo, RequestFieldsT &RequestFields);
