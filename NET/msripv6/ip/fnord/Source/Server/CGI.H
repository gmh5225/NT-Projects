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
Module Name: CGI
Purpose: Handle CGI server side scripts
*/

/*
Function Name: Process CGI Script
Purpose: Processes CGI scripts, handles logging and errors
Parameters:
	RequestInfo - HTTP request info structure (see HTTPREQ.H)
	ReqeustFields - HTTP request fields structure (see HTTPREQ.H)
	ServerPath - Remote path of the script (example: /cgi-bin/script.exe)
	ExtraPathInfo - URI Extra path info
	QueryString - URI Querry String
	FilePath - Local path of the script (example: c:\fnord\cgi-bin\script.exe)
*/
void ProcessCGIScript(RequestInfoT &RequestInfo, RequestFieldsT &RequestFields,
	char *QueryStr, char *FilePath);
