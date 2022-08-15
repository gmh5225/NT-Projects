/*++

Copyright (c) 2005  Microsoft Corporation

Module Name  : NDF.h

Abstract:

This file contains declaration for Network Diagnostics Framework (NDF) client API

Author:

Tin Qian (tinqian) 07-08-2005

Revision history:

--*/
#pragma once

#include <specstrings.h>
#include <ndattrib.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef PVOID NDFHANDLE; 

STDAPI
NdfCreateIncident(
    __in LPCWSTR helperClassName,
    ULONG celt,
    __in_ecount(celt) HELPER_ATTRIBUTE *attributes,
    __deref_out NDFHANDLE *handle);

STDAPI
NdfCreateWinSockIncident(  
    SOCKET sock,
    __in_opt LPCWSTR host,
    USHORT port,
    __in_opt LPCWSTR appId,
    __in_opt SID *userId,
    __deref_out NDFHANDLE *handle);
    
STDAPI
NdfCreateWebIncident(
    __in LPCWSTR url,
    __deref_out NDFHANDLE *handle);    
    
STDAPI
NdfCreateWebIncidentEx(
       __in LPCWSTR url,
       BOOL useWinHTTP,
       __in_opt LPWSTR moduleName, 
       __deref_out NDFHANDLE *handle);

STDAPI NdfCreateSharingIncident(  
    __in LPCWSTR UNCPath,
    __deref_out NDFHANDLE *handle);

STDAPI NdfCreateDNSIncident(  
    __in LPCWSTR hostname,
    WORD queryType,
    __deref_out NDFHANDLE *handle);

STDAPI NdfCreateConnectivityIncident(  
    __deref_out NDFHANDLE *handle);

STDAPI
NdfExecuteDiagnosis(       
    __in NDFHANDLE handle,
    __in_opt HWND hwnd
    );

STDAPI
NdfCloseIncident(
    NDFHANDLE handle);

#ifdef __cplusplus
}
#endif // defined(__cplusplus)


