/*++

Copyright (c) Microsoft Corporation

Module Name:

    MUILoad.h

Abstract:

    Public include file containing API declarations with Language Neutral
    resource module loading capabilities and downlevel compatibility

Author:


Revision History:

--*/


#if !defined (_MUILOAD_H_INCLUDED_)
#define _MUILOAD_H_INCLUDED_

#pragma once


#include <windows.h>

// Language convention flags
#define MUI_LANGUAGE_ID          0x4      // Use traditional language ID convention
#define MUI_LANGUAGE_NAME        0x8      // Use ISO language (culture) name convention

#ifdef  __cplusplus
extern "C" {
#endif

/*++
LoadMUILibrary

Routine Description:

    This function is meant as a replacement for existing calls to
    LoadLibrary/LoadLibraryEx for components that need to provide
    support for Language neutral scenarios on Longhorn as well
    as older versions of the OS. 
    It adds a wrapper around the actual call to LoadLibraryEx
    to search for MUI versions of the module in different
    locations depending on the language and the OS.
    The semantics are the same as for a call to LoadLibraryEx,
    including the return value and the error codes. 


Arguments:

    pszFullModuleName - file name of the module (with or without path)
        originally containing the resources, as called by LoadLibraryEx().
        This filename is used to build the appropriate Language Neutral
        filename depending on the OS version.

    dwLangConvention - used to let the API know which installation
    convention was used to setup the files.
    Possible values:
        MUI_LANGUAGE_NAME - (default) use ISO language name convention
        MUI_LANGUAGE_ID   - use traditional LCID language name convention
        
    LangID - if nonzero, the caller is looking for an arbitrary Lang ID path
               specified by this parameter

Return Value:

    Handle to the mapped resource module if found.
    Otherwise, returns NULL.

--*/

// ANSI version
HINSTANCE __stdcall LoadMUILibraryA(
    __in LPCSTR pszFullModuleName,
    IN DWORD dwLangConvention,
    IN LANGID LangID
    );

// Wide char version
HINSTANCE __stdcall LoadMUILibraryW(
    __in LPCWSTR pszFullModuleName,
    IN DWORD dwLangConvention,
    IN LANGID LangID
    );

#ifdef UNICODE
#define LoadMUILibrary LoadMUILibraryW
#else
#define LoadMUILibrary LoadMUILibraryA
#endif // !UNICODE


/*++
FreeMUILibrary

Routine Description:

    This function should be used the same way as FreeLibrary() to
    free the handle returned by LoadMUILibrary().
    It is provided in order to reproduce the LoadLibrary/FreeLibrary
    mechanism; any call to LoadMUILibrary should be
    paired with a call to FreeMUILibrary.


Arguments:

    hResModule - handle to the module loaded with LoadMUILibrary.


Return Value:

    If the function succeeds, the return value is nonzero.
    If the function fails, the return value is zero. To get extended error
    information, call GetLastError.

--*/

BOOL __stdcall FreeMUILibrary(
    IN HMODULE hResModule
    );

#ifdef  __cplusplus
}
#endif

#endif // !defined(_MUILOAD_H_INCLUDED_)

