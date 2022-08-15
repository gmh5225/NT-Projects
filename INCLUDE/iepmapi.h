//+-------------------------------------------------------------------------
//
//  iepmapi.h -- This module defines the IE Protected Mode APIs
// 
//  Copyright (c) Microsoft Corp. All rights reserved.
//
//--------------------------------------------------------------------------
#ifndef _IEPMAPI_
#define _IEPMAPI_


#if _MSC_VER > 1000
#pragma once
#endif

// Remap old API names to new ones.
#define IEGetWriteableHKCU      IEGetWriteableLowHKCU

//+-------------------------------------------------------------------------
//
// Structure:   IELAUNCHURLINFO
//
// Members:
//              cbSize - Size of the structure, in bytes.
//              dwCreationFlags - Process Creation flags used by CreateProcess 
//                                and CreateProcessAsUser functions.
//
//--------------------------------------------------------------------------
typedef struct _IELAUNCHURLINFO {
    DWORD cbSize;
    DWORD dwCreationFlags;
} IELAUNCHURLINFO, *LPIELAUNCHURLINFO;

//+-------------------------------------------------------------------------
//
//  Method:     IESaveFile
// 
//  Synopsis:   Saves the file to the location selected by the user in a 
//              previous call to IEShowSaveFileDialog
//
//--------------------------------------------------------------------------
STDAPI IESaveFile(                                   
    __in HANDLE    hState,                           
    __in LPCWSTR   lpwstrSourceFile                  
    );                          


//+-------------------------------------------------------------------------
//
//  Method:     IECancelSaveFile
// 
//  Synopsis:   Cancels the save operation and releases the resources 
//              allocated for the previous call to IEShowSaveFileDialog
//
//--------------------------------------------------------------------------
STDAPI IECancelSaveFile(
    __in HANDLE    hState
    );


//+-------------------------------------------------------------------------
//
//  Method:     IEShowSaveFileDialog
// 
//  Synopsis:   Shows the standard SaveFile dialog from a higher integrity 
//              user context
//
//  Remarks:    When no longer needed, call CoTaskMemFree to release
//              lppwstrDestinationFilePath 
//
//--------------------------------------------------------------------------
STDAPI IEShowSaveFileDialog(                         
    __in        HWND     hwnd,                       
    __in        LPCWSTR  lpwstrInitialFileName,      
    __in_opt    LPCWSTR  lpwstrInitialDir,           
    __in_opt    LPCWSTR  lpwstrFilter,               
    __in_opt    LPCWSTR  lpwstrDefExt,               
    __in        DWORD    dwFilterIndex,              
    __in        DWORD    dwFlags,                    
    __deref_out LPWSTR   *lppwstrDestinationFilePath,
    __out       HANDLE   *phState                    
    );                                               


//+-------------------------------------------------------------------------
//
//  Method:     IEGetWriteableLowHKCU
// 
//  Synopsis:   Returns a handle to a write accessible location under 
//              HKEY_CURRENT_USER for MIC Low process
//
//  Remarks:    When no longer needed, call RegCloseKey function to close 
//              the HKEY
//
//--------------------------------------------------------------------------
STDAPI IEGetWriteableLowHKCU(                           
    __out HKEY    *pHKey                             
    );                                               


//+-------------------------------------------------------------------------
//
//  Method:     IEGetWriteableFolderPath
// 
//  Synopsis:   Returns the current location of the specified folder. 
//              In protected mode, the path points to a location where 
//              the user has write permissions
//
//  Remarks:    When no longer needed, call CoTaskMemFree to release the
//              lppwstrPath
//
//--------------------------------------------------------------------------
STDAPI IEGetWriteableFolderPath(                     
    __in        REFGUID clsidFolderID,               
    __deref_out LPWSTR   *lppwstrPath                
    );                                               


//+-------------------------------------------------------------------------
//
//  Method:     IEIsProtectedModeProcess
// 
//  Synopsis:   Determines if Internet Explorer is running in protected mode
//
//--------------------------------------------------------------------------
STDAPI IEIsProtectedModeProcess(                     
    __out BOOL     *pbResult                         
    );                                               


//+-------------------------------------------------------------------------
//
//  Method:     IEIsProtectedModeURL
// 
//  Synopsis:   Determines if the URL runs in Protected Mode or not
//
//--------------------------------------------------------------------------
STDAPI IEIsProtectedModeURL(                     
    __in LPCWSTR lpwstrUrl
    );

//+-------------------------------------------------------------------------
//
//  Method:     IELaunchURL
// 
//  Synopsis:   Launches the appropriate IE to handle the navigation to 
//              the URL
//
//--------------------------------------------------------------------------
STDAPI IELaunchURL(                     
    __in        LPCWSTR lpwstrUrl,
    __inout     PROCESS_INFORMATION *lpProcInfo,
    __in_opt    VOID *lpInfo
    );

#endif //_IEPMAPI_
