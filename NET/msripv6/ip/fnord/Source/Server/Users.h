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
Module Name: Date
Purpose: Routines for using a simple user and group database.  Some
	functionality is also offered to simplify its use for HTTP.
Public Functions:
	LoadUsers
   UnloadUsers
   ReloadUsers

   CheckUserPassword
   UserInGroup

   HTTPCheckUser
*/

/*
Function Name: Load Users
Purpose: Load the users and groups from the registry and does other module
	initialization.
*/
void LoadUsers();

/*
Function Name: Unload Users
Purpose: Unloads the users and groups from memory and other module clean up.
*/
void UnloadUsers();

/*
Function Name: Load Users
Purpose: Updates the users based on the current registry settings
*/
void ReloadUsers();

/*
Function Name: Check User Password
Purpose: Checks a username and password to determine if they are valid
Returns: TRUE if the user and password are valid, FALSE if the user or
	password is not valid.
*/
BOOL CheckUserPassword(char *UserNameStr, char *PasswordStr);

/*
Function Name: User In Group
Purpose: Determines if a given user is in a given group
Returns: TRUE if the user is in the given group, FALSE if the user is not in
	the given group.
*/
BOOL UserInGroup(char *UserNameStr, char *GroupNameStr);

/*
Function Name: Check User
Purpose: Determines if a MIME encoded user and password allows access to a
	resource for the given user or group.
Parameters:
	AuthStr: HTTP Basic Authorizaton encoded user and password
	AuthUser: User or group authorized for this resource
	UserStr: Name of validated user is put here if TRUE is returned
Returns: TRUE if authorized, FALSE if not authorized
*/
BOOL HTTPCheckUser(char *AuthStr, char *AuthUser, char *UserStr);


