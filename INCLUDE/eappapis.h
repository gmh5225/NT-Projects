//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Microsoft Corporation
//
// SYNOPSIS
//
//   Declares apis to invoke peer apis on eaphost.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EAPPAPIS_H
#define EAPPAPIS_H
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void (CALLBACK *NotificationHandler) (
                 IN GUID connectionId,
                 IN void* pContextData
                 );


// General note about the memory allocated for the OUT parameters:
//
// If memory is dynamically allocated for the OUT parameters, the memory
// will be available until the caller makes the next call. If the caller
// want to keep the content cross multiple calls, the caller must keep its
// own copy.
// To have all the allocated memory (allocated by this DLL) reclaimed,
// the caller finally must call either EapHostPeerEndSession() or
// EapHostPeerClearConnection().
//
// EAP_ERROR** OUT parameter is an exception. The caller must call
// EapHostPeerFreeEapError() to free the memory.
//
//
// Thread safety:
// EapHostPeerInitialize() and EapHostPeerUninitialize() are always thread
// safe.
//
// EapHostPeerFreeEapError() is not thread safe. There should be only one
// thread being called to free the same EAP_ERROR*. And obviously it should
// not be called more than once for the same EAP_ERROR*.
//
// For all the other functions, there should only be one thread calling them
// for the same session. However, it is safe for multiple threads to call them
// for different sessions.


// Must call this before it starts to call any other fucntion.
// If this function fails, no other EapHostPeer... functions can be called.
//
// Inside this function, it calls CoInitializeEx(NULL, COINIT_MULTITHREADED)
// So the client should not initialize a conflicting COM environment.
// If the client really needs a different COM environment, it should use the
// COM APIs directly instead of using this C style APIs.
DWORD APIENTRY EapHostPeerInitialize();

// Must call this after it is done calling any other EapHostPeer...
// functions.
// Inside this function it calls CoUninitialize().
void APIENTRY EapHostPeerUninitialize();

// If this function succeeds, no matter the calls to other functions
// succeed or fail, the caller MUST call EapHostPeerEndSession() to end
// the authentication session and then call EapHostPeerClearConnection()
// at the very end to remove the connection, if EapHostPeerEndSession()
// provides a valid GUID to register the connection. Connection can keep
// alive cross multiple sessions.
//
// However, if this function fails, the caller can not proceed with
// other calls. It should NOT call EapHostPeerEndSession() or 
// EapHostPeerClearConnection() if this function fails. 
//
// For the same pConnectionId, EapHostPeerEndSession() must be called
// before EapHostPeerBeginSession() can be called again.
DWORD APIENTRY
EapHostPeerBeginSession(
   IN DWORD dwFlags,
   IN EAP_METHOD_TYPE eapType,
   IN const EapAttributes* const pAttributeArray,
   IN HANDLE hTokenImpersonateUser,
   IN DWORD dwSizeofConnectionData,
   IN const BYTE* const pConnectionData,
   IN DWORD dwSizeofUserData,
   IN const BYTE* const pUserData,
   IN DWORD dwMaxSendPacketSize,
   // If the supplicant is intrested in re-auth caused by NAP health change,
   // it should provide a unique GUID.
   // When this function is called by PEAP inner method, it will be NULL.
   // 
   // When pConnectionId is NULL, func and pContextData will be ignored.
   IN const GUID* const pConnectionId,
   // if the function handler is NULL, pContextData will be ignored,
   // and it means the caller is not interested in SoH change notification
   // from EapQec.
   IN NotificationHandler func,
   // a pointer to some data that the supplicant want to associate with
   // the connection when NotificationHandler call back is called.
   // When NotificationHandler is called, it will be called as:
   // func(*pCOnnectionId, pContextData).
   IN void* pContextData,
   OUT EAP_SESSIONID* pSessionId,
   OUT EAP_ERROR** ppEapError
   );


   
DWORD APIENTRY
EapHostPeerProcessReceivedPacket(
   IN EAP_SESSIONID sessionHandle,
   IN DWORD cbReceivePacket,
   IN const BYTE* const pReceivePacket,
   OUT EapHostPeerResponseAction* pEapOutput,
   OUT EAP_ERROR** ppEapError
   );


DWORD APIENTRY
EapHostPeerGetSendPacket(
   IN EAP_SESSIONID sessionHandle,
	OUT DWORD* pcbSendPacket,
	OUT BYTE** ppSendPacket,
	OUT EAP_ERROR** ppEapError
	);
   

DWORD APIENTRY
EapHostPeerGetResult(
   IN EAP_SESSIONID sessionHandle,
	IN EapHostPeerMethodResultReason reason,
	OUT EapHostPeerMethodResult* ppResult, 
	OUT EAP_ERROR** ppEapError         
	   );


DWORD APIENTRY
EapHostPeerGetUIContext(
   IN EAP_SESSIONID sessionHandle,
   OUT DWORD* pdwSizeOfUIContextData,
   OUT BYTE** ppUIContextData,
	OUT EAP_ERROR** ppEapError
   );


DWORD APIENTRY
EapHostPeerSetUIContext(
   IN EAP_SESSIONID sessionHandle,
   IN DWORD dwSizeOfUIContextData,
   IN const BYTE* const pUIContextData,
   OUT EapHostPeerResponseAction* pEapOutput,
	OUT EAP_ERROR** ppEapError
	);


DWORD APIENTRY
EapHostPeerGetResponseAttributes(
   IN EAP_SESSIONID sessionHandle,
   OUT EapAttributes* pAttribs,
	OUT EAP_ERROR** ppEapError
   );


DWORD APIENTRY
EapHostPeerSetResponseAttributes(
   IN EAP_SESSIONID sessionHandle,
   IN const EapAttributes* const pAttribs,
   OUT EapHostPeerResponseAction* pEapOutput,
	OUT EAP_ERROR** ppEapError
   );


DWORD APIENTRY
EapHostPeerGetAuthStatus(
   IN EAP_SESSIONID sessionHandle,
   IN EapHostPeerAuthParams authParam,
   OUT DWORD* pcbAuthData,
   OUT BYTE** ppAuthData,
   OUT EAP_ERROR** ppEapError   
   );


DWORD APIENTRY
EapHostPeerEndSession(
   IN EAP_SESSIONID sessionHandle,
   OUT EAP_ERROR** ppEapError
   );


DWORD APIENTRY
EapHostPeerClearConnection(
   IN GUID* pConnectionId,
   OUT EAP_ERROR** ppEapError
   );


// If any of the previous function is called, and an EAP_ERROR is returned,
// this function must be called to free the memory.
void APIENTRY EapHostPeerFreeEapError(IN EAP_ERROR* pEapError);

#ifdef __cplusplus
}
#endif

#endif // EAPPAPIS_H



