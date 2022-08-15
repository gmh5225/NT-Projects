///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Microsoft Corporation
//
// SYNOPSIS
//
//   Declares datastructures that are needed by eap methods on the Peer.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EAPPEERMETHODAPIS_H
#define EAPPEERMETHODAPIS_H
#pragma once

#include "objbase.h"
#include "msxml6.h"
#include "EapMethodTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines used for installation of EAP DLL
// HKLM\System\CCS\Services\Eaphost\Methods\[AuthorId]\[EapTypeId])
//
// Custom EAP DLL registry installation example:
//                     Name      =  Sample.dll, 
//                     AuthorId  =  311(Microsoft), 
//                     EapTypeId = (decimal 40) 
// HKLM\System\CCS\Services\Eaphost\Methods\311\40
//
//      PeerDllPath             (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerConfigUIPath        (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerInteractiveUIPath   (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerIdentityPath        (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerFriendlyName        (REG_SZ) Sample EAP Protocol
//      PeerRequireConfigUI     (REG_DWORD)     1

//
// Defines used for installation of EAP DLL
// HKLM\System\CCS\Services\Eaphost\Methods\[AuthorId]\254\[VendorId]\[EapTypeId])
//
// Custom Expanded EAP DLL registry installation example:
//                     Name      =  Sample.dll, 
//                     AuthorId  =  311(Microsoft),
//                     VendorId  =  311(Microsoft),
//                     EapTypeId = (decimal 40) 
// HKLM\System\CCS\Services\Eaphost\Methods\311\254\311\40
//
//      PeerDllPath             (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerConfigUIPath        (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerInteractiveUIPath   (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerIdentityPath        (REG_EXPAND_SZ) %SystemRoot%\system32\sample.dll
//      PeerFriendlyName        (REG_SZ) Sample EAP Protocol
//      PeerRequireConfigUI     (REG_DWORD)     1


#define EAP_REGISTRY_LOCATION   \
    TEXT("System\\CurrentControlSet\\Services\\EapHost\\Methods")

#define EAP_PEER_VALUENAME_DLL_PATH          TEXT("PeerDllPath")
#define EAP_PEER_VALUENAME_FRIENDLY_NAME     TEXT("PeerFriendlyName")
#define EAP_PEER_VALUENAME_CONFIGUI          TEXT("PeerConfigUIPath")
#define EAP_PEER_VALUENAME_REQUIRE_CONFIGUI  TEXT("PeerRequireConfigUI")
#define EAP_PEER_VALUENAME_IDENTITY          TEXT("PeerIdentityPath")
#define EAP_PEER_VALUENAME_INTERACTIVEUI     TEXT("PeerInteractiveUIPath")
#define EAP_PEER_VALUENAME_INVOKE_NAMEDLG    TEXT("PeerInvokeUsernameDialog")
#define EAP_PEER_VALUENAME_INVOKE_PWDDLG     TEXT("PeerInvokePasswordDialog")
#define EAP_PEER_VALUENAME_PROPERTIES        TEXT("Properties")


// ENUMERATIONS USED by EAP methods on the peer to communicate their status to
// EapHost.

typedef
#ifdef __midl
   [v1_enum]
#endif
enum tagEapPeerMethodResponseAction
{
        // Discard the request as EAP cannot use it.
        EapPeerMethodResponseActionDiscard = 0,
        // Send the packet to the authenticator
        EapPeerMethodResponseActionSend,
        // Respond to EAP by acting on the returned attributes
        EapPeerMethodResponseActionResult,
        // Invoke appropriate UI based on the context
        EapPeerMethodResponseActionInvokeUI,
        // The supplicant needs to take an action based on the context.
        EapPeerMethodResponseActionRespond,
        // The supplicant needs to take no action at all.
        EapPeerMethodResponseActionNone
} EapPeerMethodResponseAction;


typedef
#ifdef __midl
   [v1_enum]
#endif
enum tagEapPeerMethodResultReason
{
   EapPeerMethodResultUnknown = 1,
   EapPeerMethodResultSuccess,
   EapPeerMethodResultFailure
} EapPeerMethodResultReason;


// Structures used by EAP methods on the peer to communicate with the host.

typedef struct tagEapPeerMethodOuput 
{
        //EapPeerMethodDecision decision;
        //EapPeerMethodState state;
        EapPeerMethodResponseAction action;
        BOOL fAllowNotifications;
} EapPeerMethodOutput;


typedef struct tagEapPeerMethodResult
{
        BOOL fIsSuccess;
   DWORD dwFailureReasonCode;
        BOOL fSaveConnectionData;
        DWORD dwSizeofConnectionData;
   __field_bcount(dwSizeofConnectionData) BYTE* pConnectionData;
        BOOL fSaveUserData;
        DWORD dwSizeofUserData;
   __field_bcount(dwSizeofUserData) BYTE* pUserData;
   EAP_ATTRIBUTES* pAttribArray;
    EAP_ERROR* pEapError;
} EapPeerMethodResult;


// List of functions corresponding to the particular EAP method 
typedef struct _EAP_PEER_METHOD_ROUTINES 
{  
   DWORD dwVersion;
   EAP_TYPE* pEapType;

   DWORD (APIENTRY * EapPeerInitialize) (EAP_ERROR** pEapError);

   DWORD (APIENTRY * EapPeerGetIdentity) (
                        IN DWORD flags,
                        IN DWORD dwSizeofConnectionData,
                        IN const BYTE* pConnectionData,
                        IN DWORD dwSizeofUserData,
                        IN const BYTE* pUserData,
                        IN HANDLE hTokenImpersonateUser,
                        OUT BOOL* pfInvokeUI,
                        IN OUT DWORD* pdwSizeOfUserDataOut,
                        OUT BYTE** ppUserDataOut,
                        OUT WCHAR** ppwszIdentity,
                        OUT EAP_ERROR** ppEapError
                        );

   DWORD (APIENTRY * EapPeerBeginSession) (
                        IN DWORD dwFlags,
                        IN const EapAttributes* const pAttributeArray,
                        IN HANDLE hTokenImpersonateUser,
                        IN DWORD dwSizeofConnectionData,
                        IN BYTE* pConnectionData,
                        IN DWORD dwSizeofUserData,
                        IN BYTE* pUserData,
                        IN DWORD dwMaxSendPacketSize,
                        OUT EAP_SESSION_HANDLE* pSessionHandle,
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerSetCredentials) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN WCHAR* pwszIdentity,
                        IN WCHAR* pwszPassword,         
                        OUT EAP_ERROR** pEapError
                        );
   DWORD (APIENTRY * EapPeerProcessRequestPacket) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN DWORD cbReceivePacket,
                        IN EapPacket* pReceivePacket,
                        OUT EapPeerMethodOutput* pEapOutput,
                        OUT EAP_ERROR** pEapError
                        );
         
   DWORD (APIENTRY * EapPeerGetResponsePacket) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN OUT DWORD* pcbSendPacket,
                        OUT EapPacket* pSendPacket,
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerGetResult) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN EapPeerMethodResultReason reason,
                        OUT EapPeerMethodResult* ppResult, 
                        OUT EAP_ERROR** pEapError         
                        );

   DWORD (APIENTRY * EapPeerGetUIContext) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        OUT DWORD* dwSizeOfUIContextData,
                        OUT BYTE** pUIContextData, 
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerSetUIContext) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN DWORD dwSizeOfUIContextData,
                        IN const BYTE* pUIContextData,
                        OUT EapPeerMethodOutput* pEapOutput,
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerGetResponseAttributes) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        OUT EapAttributes* pAttribs,
                        OUT EAP_ERROR** pEapError         
                        );

   DWORD (APIENTRY * EapPeerSetResponseAttributes) (
                        IN EAP_SESSION_HANDLE sessionHandle,
                        IN EapAttributes* pAttribs,
                        OUT EapPeerMethodOutput* pEapOutput,
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerEndSession) (
                        IN EAP_SESSION_HANDLE sessionHandle, 
                        OUT EAP_ERROR** pEapError
                        );

   DWORD (APIENTRY * EapPeerShutdown) (OUT EAP_ERROR** pEapError);
} EAP_PEER_METHOD_ROUTINES;



//
// EAP Functions
//
VOID WINAPI EapPeerFreeErrorMemory(IN EAP_ERROR* pEapError);

DWORD WINAPI EapPeerGetInfo(
         IN EAP_TYPE* pEapType, 
         OUT EAP_PEER_METHOD_ROUTINES* pEapInfo, 
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerInitialize(OUT EAP_ERROR** pEapError);

DWORD WINAPI EapPeerGetIdentity (
                IN DWORD flags,
                IN DWORD dwSizeofConnectionData,
                IN const BYTE* pConnectionData,
                IN DWORD dwSizeofUserData,
                IN const BYTE* pUserData,
                IN HANDLE hTokenImpersonateUser,
                OUT BOOL* pfInvokeUI,
                IN OUT DWORD* pdwSizeOfUserDataOut,
                OUT BYTE** ppUserDataOut,
                OUT __out LPWSTR* ppwszIdentity,
                OUT EAP_ERROR** ppEapError
                );

DWORD WINAPI EapPeerBeginSession(
         IN DWORD dwFlags,
         IN const EapAttributes* const pAttributeArray,
         IN HANDLE hTokenImpersonateUser,
         IN DWORD dwSizeofConnectionData,
         IN BYTE* pConnectionData,
         IN DWORD dwSizeofUserData,
         IN BYTE* pUserData,
         IN DWORD dwMaxSendPacketSize,
         OUT EAP_SESSION_HANDLE* pSessionHandle,
         OUT EAP_ERROR** pEapError
         );

// A method exports either EapPeerGetIdentity (and EapPeerInvokeIdentityUI) or
// exports EapPeerSetCredentials (and sets the InvokeUserNameDlg regkey). The 
// registry key controls which of the two apis will get called.
DWORD WINAPI EapPeerSetCredentials(
         IN EAP_SESSION_HANDLE sessionHandle,
         IN __in LPWSTR pwszIdentity,
         IN __in LPWSTR pwszPassword,         
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerProcessRequestPacket(
         IN EAP_SESSION_HANDLE sessionHandle,
         IN DWORD cbReceivePacket,
         IN EapPacket* pReceivePacket,
         OUT EapPeerMethodOutput* pEapOutput,
         OUT EAP_ERROR** pEapError
         );


DWORD WINAPI EapPeerGetResponsePacket(
         IN EAP_SESSION_HANDLE sessionHandle,
         IN OUT DWORD* pcbSendPacket,
         OUT EapPacket* pSendPacket,
         OUT EAP_ERROR** pEapError
         );

// This will get called either when a method says that it has completed auth.
// or when the lower layer receives an alternative result.
DWORD WINAPI EapPeerGetResult(
         IN EAP_SESSION_HANDLE sessionHandle,
         IN EapPeerMethodResultReason reason,
         OUT EapPeerMethodResult* ppResult, 
         OUT EAP_ERROR** pEapError         
         );

DWORD WINAPI EapPeerGetUIContext(
         IN EAP_SESSION_HANDLE sessionHandle,
         OUT DWORD* dwSizeOfUIContextData,         
         OUT BYTE** pUIContextData,
         OUT EAP_ERROR** pEapError
      );

DWORD WINAPI EapPeerSetUIContext(
        IN EAP_SESSION_HANDLE sessionHandle,
        IN DWORD dwSizeOfUIContextData,
        IN const BYTE* pUIContextData,
        OUT EapPeerMethodOutput* pEapOutput,
        OUT EAP_ERROR** pEapError
     );

DWORD WINAPI EapPeerGetResponseAttributes(
        IN EAP_SESSION_HANDLE sessionHandle,
        OUT EapAttributes* pAttribs,
        OUT EAP_ERROR** pEapError         
     );

DWORD WINAPI EapPeerSetResponseAttributes(
         IN EAP_SESSION_HANDLE sessionHandle,
         IN EapAttributes* pAttribs,
         OUT EapPeerMethodOutput* pEapOutput,
         OUT EAP_ERROR** pEapError
      );

DWORD WINAPI EapPeerEndSession(
         IN EAP_SESSION_HANDLE sessionHandle, 
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerShutdown(OUT EAP_ERROR** pEapError);

DWORD WINAPI EapPeerInvokeConfigUI(
         IN EAP_METHOD_TYPE* pEapType,
         IN HWND hwndParent,
         IN DWORD dwFlags,
         IN DWORD dwSizeOfConnectionDataIn,
         IN BYTE* pConnectionDataIn,
         OUT DWORD* dwSizeOfConnectionDataOut,
         OUT BYTE** ppConnectionDataOut,
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerInvokeInteractiveUI(
         IN EAP_METHOD_TYPE* pEapType,
         IN HWND hwndParent,
         IN DWORD dwSizeofUIContextData,
         IN BYTE* pUIContextData,
         OUT DWORD* pdwSizeOfDataFromInteractiveUI,
         OUT BYTE** ppDataFromInteractiveUI,
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerInvokeIdentityUI(
         IN EAP_METHOD_TYPE* pEapType,
         IN DWORD dwFlags,
         IN HWND hwndParent,
         IN DWORD dwSizeOfConnectionData,
         IN const BYTE* pConnectionData,
         IN DWORD dwSizeOfUserData,
         IN const BYTE* pUserData,
         OUT DWORD* pdwSizeOfUserDataOut,
         OUT BYTE** ppUserDataOut,
         OUT __out LPWSTR* ppwszIdentity,
         OUT EAP_ERROR** pEapError
         );


// TODO: Rename functions to be inline with EapPeerConfigXml2Blob format
DWORD WINAPI EapPeerQueryCredentialInputFields(
         IN HANDLE hUserImpersonationToken,
         IN EAP_METHOD_TYPE eapMethodType,
         IN DWORD dwFlags,
         IN DWORD dwEapConnDataSize,
         IN PBYTE pbEapConnData,
         OUT EAP_CONFIG_INPUT_FIELD_ARRAY* pEapConfigFieldsArray,
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerQueryUserBlobFromCredentialInputFields(
         IN HANDLE hUserImpersonationToken,
         IN EAP_METHOD_TYPE eapMethodType,
         IN DWORD dwFlags,
         IN DWORD dwEapConnDataSize,
         IN PBYTE pbEapConnData,
         IN EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
         OUT DWORD *pdwUserBlobSize,
         OUT PBYTE *ppbUserBlob,
         OUT EAP_ERROR** pEapError
         );

DWORD WINAPI EapPeerConfigXml2Blob(
                IN DWORD dwFlags,
                IN EAP_METHOD_TYPE eapMethodType,
                IN IXMLDOMDocument2* pConfigDoc,
                OUT __out_ecount(*pdwSizeOfConfigOut) BYTE** ppConfigOut,
                OUT DWORD* pdwSizeOfConfigOut,
                OUT EAP_ERROR** pEapError
                );


DWORD WINAPI EapPeerCredentialsXml2Blob(
                IN DWORD dwFlags,
                IN EAP_METHOD_TYPE eapMethodType,
                IN IXMLDOMDocument2* pCredentialsDoc,
                IN __in_ecount(dwSizeOfConfigIn) const BYTE* pConfigIn,
                IN DWORD dwSizeOfConfigIn,
                OUT __out_ecount(*pdwSizeOfCredentialsOut) BYTE** ppCredentialsOut,
                OUT DWORD* pdwSizeOfCredentialsOut,
                OUT EAP_ERROR** pEapError
                );


DWORD WINAPI EapPeerConfigBlob2Xml(
                IN DWORD dwFlags,
                IN EAP_METHOD_TYPE eapMethodType,
                IN __in_ecount(dwSizeOfConfigIn) const BYTE* pConfigIn,
                IN DWORD dwSizeOfConfigIn,
                OUT IXMLDOMDocument2** ppConfigDoc,
                OUT EAP_ERROR** pEapError
                );


VOID WINAPI EapPeerFreeMemory(
        IN void* pUIContextData
        );

#ifdef __cplusplus
}
#endif

#endif // EAP_PEER_METHOD_APIS_H


