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
#include "users.h"


/*
Implentaion Notes:

This could be sped up by using hash tables or UCASEing and sorting everything
then doing binary searches, however I offseted the slow search times with a
caching mechanism.  Since a validated user will probably send several requests
with the same authorization string this should be fast enough.

There are a few magic numbers in here that should be replaced with constants
*/

//Private Data Structures
struct UserT {
	char *NameStr;
	char *PasswordStr;
	};
struct GroupT {
	char *NameStr;
	int NumMembers;
	char **Members;
	};

struct CacheEntry {
	char EncodedAuthInfo[300];
	char AuthUserStr[50];
	char UserStr[50];
	};

//Private Functions
/*
Function Name: Decode Authoriztion String
Purpose: Decodes a MIME encoded user name and password pair to a user
	name string and a password string.
Parameters:
	AuthStr - MIME Encoded name and password
	UserNameStr - Buffer to put the decoded user name into
	PasswordStr - Buffer to put the decoded password into
*/
void DecodeAuthStr(char *AuthStr, char *UserNameStr, char *PasswordStr);

/*
Function Name: Check Cache
Purpose: Checks to see if we've already validated a authorization string
	and gives information on the past validation.
Parameters:
	AuthStr - Authorization string
	AuthUserStr - User/group authorized for this resource
	UserStr - Buffer to put the name of the user name extracted from the AuthStr
Returns: True if the the cache was hit, False if no hit
*/
BOOL CheckCache(char *AuthStr, char *AuthUserStr, char *UserStr);

/*
Function Name: Add to Cache
Purpose: Adds a validated authorization string with the corresponding
	authorized user and user name that was validated. For Example, if
	XYZ caused Joe to be validated for group Users, then XYZ, Users, Joe would
	be added.
Parameters:
	AuthStr - String that is to be decoded
	AuthUserStr - The user or group that is authorized for the resource
	UserStr - User name extracted from the AuthStr
Notes: This function is designed such that cache reads can be made durring
	a write.  However, a critical section is used to allow only one write at
	a time.
*/
void AddToCache(char *AuthStr, char *AuthUserStr, char *UserStr);


//Private Data
int NumUsers;
UserT *Users;          //User data
int NumGroups;
GroupT *Groups;        //Group data

BYTE MIMETable[256]; //Lookup table for converting MIME chars to 6-bit values

#define USERS_CACHE_SIZE 10
CacheEntry Cache[USERS_CACHE_SIZE];  //Cache for quick retrival of user info
int LastCacheEntry;
CRITICAL_SECTION CacheSection;


//Public Functions
/******************************************************************************/
void LoadUsers() {
	int i, j;
	DWORD ValueType;
	DWORD BuffSize;
	FILETIME Junk;

	//------------Get User Data from registry------------
	HKEY UsersKeyHandle;
	HKEY UserKeyHandle;
	char NumUsersStr[6];
	char UserNameStr[41];
	char PasswordStr[41];

	//Open Users key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\Users", 0,
		KEY_ALL_ACCESS, &UsersKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Users registry key");
		return;
		}

	//Get number of users
	BuffSize = 5;
	if (RegQueryValueEx(UsersKeyHandle, "Number of Users", 0, &ValueType,
		(LPBYTE)NumUsersStr, &BuffSize) != ERROR_SUCCESS) {
		 LogCriticalError("Couldn't get Number of Users from registry");
		 return;
		 }
	NumUsers = atoi(NumUsersStr);

	//Allocate memory for users
	Users = new UserT[NumUsers];

	//Get each user
	for (i=0; i<NumUsers; i++) {
		BuffSize = 40;
		if (RegEnumKeyEx(UsersKeyHandle, i, UserNameStr, &BuffSize, 0, NULL, 0, &Junk)
			!= ERROR_SUCCESS) {
			LogCriticalError("Couldn't get enumed Group Name from registry");
			return;
			}
		if (RegOpenKeyEx(UsersKeyHandle, UserNameStr, 0,
			KEY_ALL_ACCESS, &UserKeyHandle) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't open enumed User registry key");
			return;
			}
		BuffSize = 40;
		if (RegQueryValueEx(UserKeyHandle, "Password", 0, &ValueType,
			(LPBYTE)PasswordStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Password from registry");
			return;
			}
		if (RegCloseKey(UserKeyHandle) != ERROR_SUCCESS) {
			LogError("Error closeing enumed User registry key");
			}
		//Create user entry
		Users[i].NameStr = new char[strlen(UserNameStr) + 1];
		Users[i].PasswordStr = new char[strlen(PasswordStr) + 1];
		strcpy(Users[i].NameStr, UserNameStr);
		strcpy(Users[i].PasswordStr, PasswordStr);
		}
	//Close Users key
	if (RegCloseKey(UsersKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Users registry key");
		}

	//------------Get Group Data from registry------------
	HKEY GroupsKeyHandle;
	HKEY GroupKeyHandle;
	HKEY MembersKeyHandle;
	char NumGroupsStr[6];
	char GroupNameStr[41];
	char NumMembersStr[6];
	char MemberStr[41];

	//Open Groups key
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Brian Morin\\Fnord Server\\Groups", 0,
		KEY_ALL_ACCESS, &GroupsKeyHandle) != ERROR_SUCCESS) {
		LogCriticalError("Couldn't open Groups registry key");
		return;
		}

	//Get number of groups
	BuffSize = 5;
	if (RegQueryValueEx(GroupsKeyHandle, "Number of Groups", 0, &ValueType,
		(LPBYTE)NumGroupsStr, &BuffSize) != ERROR_SUCCESS) {
		 LogCriticalError("Couldn't get Number of Groups from registry");
		 return;
		 }
	NumGroups = atoi(NumGroupsStr);

	//Allocate memory for groups
	Groups = new GroupT[NumGroups];

	//Get each group
	for (i=0; i<NumGroups; i++) {
		BuffSize = 40;
		if (RegEnumKeyEx(GroupsKeyHandle, i, GroupNameStr, &BuffSize, 0, NULL, 0, &Junk)
			!= ERROR_SUCCESS) {
			LogCriticalError("Couldn't get enumed Group Name from registry");
			return;
			}
		if (RegOpenKeyEx(GroupsKeyHandle, GroupNameStr, 0,
			KEY_ALL_ACCESS, &GroupKeyHandle) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't open enumed Group registry key");
			return;
			}

		//Get Number of members
		BuffSize = 5;
		if (RegQueryValueEx(GroupKeyHandle, "Number of Members", 0, &ValueType,
			(LPBYTE)NumMembersStr, &BuffSize) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't get Number of Members from registry");
			return;
			}
		Groups[i].NumMembers = atoi(NumMembersStr);

		//Create group entry
		Groups[i].NameStr = new char[strlen(GroupNameStr) + 1];
		Groups[i].Members = new char *[Groups[i].NumMembers];
		strcpy(Groups[i].NameStr, GroupNameStr);

		//Open Members key
		if (RegOpenKeyEx(GroupKeyHandle, "Members", 0,
			KEY_ALL_ACCESS, &MembersKeyHandle) != ERROR_SUCCESS) {
			LogCriticalError("Couldn't open Members registry key for enumed Group");
			return;
			}

		for (j=0; j<Groups[i].NumMembers; j++) {
			//Get a member
			BuffSize = 40;
			if (RegEnumKeyEx(MembersKeyHandle, j, MemberStr, &BuffSize, 0, NULL, 0, &Junk)
				!= ERROR_SUCCESS) {
				LogCriticalError("Couldn't get enumed Group Member from registry");
				return;
				}

			//Store member
			Groups[i].Members[j] = new char[strlen(MemberStr) + 1];
			strcpy(Groups[i].Members[j], MemberStr);
			}

		//Close Members key
		if (RegCloseKey(MembersKeyHandle) != ERROR_SUCCESS) {
			LogError("Error closeing enumed Group registry key");
			}
		//Close Group key
		if (RegCloseKey(GroupKeyHandle) != ERROR_SUCCESS) {
			LogError("Error closeing enumed Group registry key");
			}
		}
	//Close Groups key
	if (RegCloseKey(GroupsKeyHandle) != ERROR_SUCCESS) {
		LogError("Error closeing Groups registry key");
		}

	//Init cache
	LastCacheEntry = USERS_CACHE_SIZE - 1;
	for (i=0; i< USERS_CACHE_SIZE; i++) {
		Cache[i].EncodedAuthInfo[0] = 0;
		}
	InitializeCriticalSection(&CacheSection);

	//Init MIME decoding table
	#pragma warn -sig //Suppress significant digit loss warning (BC++)
	memset(MIMETable, 0, sizeof(MIMETable));
	// A - Z = 0 - 25
	for (i = 65; i<= 90; i++) {
		MIMETable[i]  =  i - 65;
		}
	// a - z = 26 - 51
	for (i = 97; i<= 122; i++) {
		MIMETable[i] = i - 97 + 26;
		}
	// 0 - 9 = 52 - 61
	for (i = 48; i<= 57; i++) {
		MIMETable[i] = i - 48 + 52;
		}
	// + = 62
	MIMETable[43] = 62;
	// / = 63
	MIMETable[47] = 63;
	#pragma warn +sig   //Restore significant digit loss warning (BC++)
	}
/******************************************************************************/
void UnloadUsers() {
	int i, j;
	//Delete User Data
	for (i=0; i<NumUsers; i++) {
		delete[] Users[i].NameStr;
		delete[] Users[i].PasswordStr;
		}
	delete[] Users;

	//Delete Group Data
	for (i=0; i<NumGroups; i++) {
		delete[] Groups[i].NameStr;
		for (j=0; j<Groups[i].NumMembers; j++) {
			delete[] Groups[i].Members[j];
			}
		delete[] Groups[i].Members;
		}
	delete[] Groups;

	DeleteCriticalSection(&CacheSection);
	}
/******************************************************************************/
void ReloadUsers() {
	UnloadUsers();
   LoadUsers();
	}
/******************************************************************************/
BOOL HTTPCheckUser(char *AuthStr, char *AuthUser, char *UserStr) {
	char PasswordStr[50];

	//Check to see if we've seen this before
	if (CheckCache(AuthStr, AuthUser, UserStr) == TRUE)
		return TRUE;

	//Extract the user name and password
	DecodeAuthStr(AuthStr, UserStr, PasswordStr);

	//Check for valid password
	if (CheckUserPassword(UserStr, PasswordStr) == FALSE)
		return FALSE;

	//Check to see if they are authorized at the user level
	if (strcmpi(UserStr, AuthUser) == 0) {
		AddToCache(AuthStr, AuthUser, UserStr);
		return TRUE;
		}

	//Check to see if they are authorized at the group level
	if (UserInGroup(UserStr, AuthUser) == TRUE) {
		AddToCache(AuthStr, AuthUser, UserStr);
		return TRUE;
		}
	else
		return FALSE;
	}
/******************************************************************************/
BOOL CheckUserPassword(char *UserNameStr, char *PasswordStr) {
	int i = 0;

	while ((i < NumUsers) && (strcmpi(Users[i].NameStr, UserNameStr) != 0)) {
		i++;
		}
	if (i == NumUsers) return FALSE; //Didn't find user
	//Found user, check password
	if (strcmpi(Users[i].PasswordStr, PasswordStr) == 0) return TRUE;
	else return FALSE;
	}
/******************************************************************************/
BOOL UserInGroup(char *UserNameStr, char *GroupNameStr) {
	int i = 0;
	//Find the group
	while ((i < NumGroups) && (strcmpi(Groups[i].NameStr, GroupNameStr) != 0 ) ) {
		i++;
		}
	if (i == NumGroups) return FALSE; //Group not found

	//See if the user is a member
	int j = 0;
	while ((j < Groups[i].NumMembers) && (strcmpi(Groups[i].Members[j], UserNameStr) != 0)) {
		j ++;
		}
	if (j == Groups[i].NumMembers) return FALSE; //User not found in Members
	else return TRUE;
	}
/******************************************************************************/

//Private Functions

/******************************************************************************/
void DecodeAuthStr(char *AuthStr, char *UserNameStr, char *PasswordStr) {
	char InChars[4];
	BYTE InData[4];

	BYTE OutData[3];
	char OutStr[100];
	int OutStrLen;

	char BasicStr[20];
	int AuthStrLen;
	int i, j, Start;

	AuthStrLen = strlen(AuthStr);

	//Varify the Basic part and find out where it ends
	GetWord(BasicStr, AuthStr, 0, Start);
	if (strcmpi(BasicStr, "Basic") != 0) { //Unknown authorization method
		UserNameStr[0] = 0;
		PasswordStr[0] = 0;
		return;
		}
	AuthStr += Start;

	for(i=0; i<AuthStrLen; i+= 4) {
		//Copy to inchars
		memcpy(InChars, AuthStr + i, 4);

		//InChars -> InData and calculate length (translate from chars to 6 bit values)
		for (j=0; j<4; j++) {
			if ( (i + j == AuthStrLen) || (InChars[j] == '=')) {
				//Since a string is terminated by a 0 extra 0s don't matter
				InData[j] = 0;
				}
			else {
				InData[j] = MIMETable[InChars[j]];
				}
			}
		//InData -> Outdata (pack to 3 bytes)
		#pragma warn -sig //Suppress significant digit loss warning (BC++)
		OutData[0] = (InData[0] << 2) + (InData[1] >> 4);
		OutData[1] = (InData[1] << 4) + (InData[2] >> 2);
		OutData[2] = (InData[2] << 6) + InData[3];
      #pragma warn +sig //Restore significant digit loss warning (BC++)

		//Copy OutData to its position in OutString
		memcpy(OutStr + ((i / 4) * 3), OutData, 3);
		}
	//Add the NULL (possibly redundant)
	OutStr[((i / 4) * 3)] = 0;
	OutStrLen = strlen(OutStr);

	//Seperate the user name and password at the ":"
	i = 0;
	while ((i < OutStrLen) && (OutStr[i] != ':')) {
		UserNameStr[i] = OutStr[i];
		i++;
		}
	UserNameStr[i] = 0;
	j = 0;
	if (OutStr[i] == ':') i++;  //Skip the colon
	while (i < OutStrLen) {
		PasswordStr[j] = OutStr[i];
		i++;
		j++;
		}
	PasswordStr[j] = 0;
	}
/******************************************************************************/
BOOL CheckCache(char *AuthStr, char *AuthUserStr, char *UserStr) {
	int i;

	//Start at last cache entry and go down
	i = LastCacheEntry;

	//Is there a match?
	if ((strcmpi(Cache[i].EncodedAuthInfo, AuthStr) == 0) &&
				(strcmpi(Cache[i].AuthUserStr, AuthUserStr) == 0)) {
		//Hit
		strcpy(UserStr, Cache[i].UserStr);
		return TRUE;
		}
	//Miss, decriment i
	i--;
	if (i < 0) i = USERS_CACHE_SIZE - 1;

	while((i != LastCacheEntry) && ((strcmpi(Cache[i].EncodedAuthInfo, AuthStr) != 0) ||
				(strcmpi(Cache[i].AuthUserStr, AuthUserStr) != 0))) {
		//Miss, decriment i
		i--;
		if (i < 0) i = USERS_CACHE_SIZE - 1;
		}
	if (i != LastCacheEntry) {
		strcpy(UserStr, Cache[i].UserStr);
		return TRUE;
		}
	else {
		return FALSE;
		}
	}
/******************************************************************************/
void AddToCache(char *AuthStr, char *AuthUserStr, char *UserStr) {
	int NewCacheEntry;

	EnterCriticalSection(&CacheSection);

	NewCacheEntry = LastCacheEntry + 1;

	if (NewCacheEntry == USERS_CACHE_SIZE)
		NewCacheEntry = 0;

	Cache[NewCacheEntry].EncodedAuthInfo[0] = 0; //Kill the old entry

	//AuthStr is copied last, so the entry can't be hit until we copy everything
	strcpy(Cache[NewCacheEntry].AuthUserStr, AuthUserStr);
	strcpy(Cache[NewCacheEntry].UserStr, UserStr);
	strcpy(Cache[NewCacheEntry].EncodedAuthInfo, AuthStr);

	LastCacheEntry = NewCacheEntry;

	LeaveCriticalSection(&CacheSection);
	}
/******************************************************************************/
