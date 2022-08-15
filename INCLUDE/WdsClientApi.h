/*++

Copyright (c) 2006 Microsoft Corporation

Module Name:

    WdsClientApi.h

Abstract:

    WDS Client API public header file.

Environment:

    User Mode

--*/
#ifndef __WDSCLIENTAPI_H__
#define __WDSCLIENTAPI_H__

#if (_MSC_VER > 1000)
#pragma once
#endif

#define WDSCLIAPI WINAPI

#ifdef __cplusplus
extern "C"
{
#endif

//
// Structures
//


// Credentials structure.
//
typedef struct tagWDS_CLI_CRED
{
    PCWSTR pwszUserName,
           pwszDomain,
           pwszPassword;
} WDS_CLI_CRED, *PWDS_CLI_CRED, *LPWDS_CLI_CRED;


//
// General functions
//
HRESULT
WDSCLIAPI
WdsCliClose( 
    __in HANDLE Handle );

//
// Image enumeration functions
//
HRESULT
WDSCLIAPI
WdsCliFindFirstImage(
    __in HANDLE hSession,
    __out PHANDLE phFindHandle );

HRESULT
WDSCLIAPI
WdsCliFindNextImage(
    __in HANDLE Handle );

HRESULT
WDSCLIAPI
WdsCliGetEnumerationFlags(
    __in HANDLE Handle,
    __out PDWORD pdwFlags );


//
// Image enumeration constants
//

enum
{
    WdsCliFlagEnumFilterVersion = 0x0001
};

//
// Session functions
//
HRESULT
WDSCLIAPI
WdsCliCreateSession(
    __in PWSTR pwszServer,
    __in_opt PWDS_CLI_CRED pCred,
    __out PHANDLE phSession );

HRESULT
WDSCLIAPI
WdsCliAuthorizeSession(
    __inout HANDLE hSession,
    __in_opt PWDS_CLI_CRED pCred );

//
// Client -> Server Logging functions
//
HRESULT
WDSCLIAPI
WdsCliInitializeLog(
    __in HANDLE hSession, 
    __in ULONG ulClientArchitecture,
    __in PWSTR pwszClientId,
    __in PWSTR pwszClientAddress );

HRESULT
WDSCLIAPI
WdsCliLog(
    __in HANDLE hSession,
    __in ULONG ulLogLevel,
    __in ULONG ulMessageCode,
    ... );

//
// Log events sent by the client to the server.
// Each one of these has a set of variables associated with it
// that must be present in the request in order for the request to be 
// considered valid.
//
typedef enum
{
    WDS_LOG_TYPE_CLIENT_ERROR = 1,
    WDS_LOG_TYPE_CLIENT_STARTED,
    WDS_LOG_TYPE_CLIENT_FINISHED,
    WDS_LOG_TYPE_CLIENT_IMAGE_SELECTED,
    WDS_LOG_TYPE_CLIENT_APPLY_STARTED,
    WDS_LOG_TYPE_CLIENT_APPLY_FINISHED,
    WDS_LOG_TYPE_CLIENT_GENERIC_MESSAGE, // Only add entries before WDS_LOG_TYPE_CLIENT_MAX_CODE.
    WDS_LOG_TYPE_CLIENT_MAX_CODE 
};

//
// Log levels.
//
typedef enum
{
    WDS_LOG_LEVEL_DISABLED = 0,
    WDS_LOG_LEVEL_ERROR = 1,
    WDS_LOG_LEVEL_WARNING = 2,
    WDS_LOG_LEVEL_INFO = 3
};

//
// Image information functions
//

HRESULT
WDSCLIAPI
WdsCliGetImageName(
    __in HANDLE hIfh, 
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImageDescription(
    __in HANDLE hIfh, 
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImageLanguage(
    __in HANDLE hIfh, 
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImageLanguages(
    __in HANDLE hIfh,
    __out_ecount(*pdwNumValues) PTSTR **pppszValues,
    __out PDWORD pdwNumValues );

HRESULT
WDSCLIAPI
WdsCliGetImageVersion(
    __in HANDLE hIfh, 
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImagePath(
    __in HANDLE hIfh,
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImageIndex(
    __in HANDLE hIfh,
    __out PDWORD pdwValue );

HRESULT
WDSCLIAPI
WdsCliGetImageArchitecture(
    __in HANDLE hIfh,
    __out PDWORD pdwValue );

HRESULT
WDSCLIAPI
WdsCliGetImageLastModifiedTime(
    __in HANDLE hIfh,
    __out PSYSTEMTIME *ppSysTimeValue );

HRESULT
WDSCLIAPI
WdsCliGetImageSize(
    __in HANDLE hIfh,
    __out PULONGLONG pullValue );

HRESULT
WDSCLIAPI
WdsCliGetImageHalName(
    __in HANDLE hIfh,
    __out PWSTR *ppwszValue );

HRESULT
WDSCLIAPI
WdsCliGetImageGroup(
    __in HANDLE hIfh,
    __out PWSTR *ppwszValue );

#ifdef __cplusplus
}
#endif

#endif  // __WDSCLIENTAPI_H__

