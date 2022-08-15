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
Module Name: Image Map
Purpose: Handle server side image maps
Public Functions:
	Process Image Map
*/

/*
Function Name: Process Image Map
Purpose: Process server side image maps.  Sends out either an error message or
	redirects to the appropriate link (via the httpsend module)
Parameters:
   RequetInfo - Request info structure (see httpreq.h)
   RequestFields - HTTP request fields structure (see httpreq.h)
   QueryStr - Querry string from the URI
   MapFilePath - Location of map file
*/
void ProcessImageMap(RequestInfoT &RequestInfo, RequestFieldsT RequestFields,
	char *QueryStr, char *MapFilePath);