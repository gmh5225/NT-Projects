///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) Microsoft Corporation
//
// SYNOPSIS
//
//   Declares methods that are used to configure EAP methods.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef EAPHOSTPEERCONFIGAPIS_H
#define EAPHOSTPEERCONFIGAPIS_H
#pragma once

#include "objbase.h"    //Required by msxml2.h
#include "msxml6.h"

#include "EapTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


DWORD WINAPI EapHostPeerGetMethods(
                EAP_METHOD_INFO_ARRAY* pEapMethodInfoArray,
                EAP_ERROR** ppEapError
                );


DWORD WINAPI EapHostPeerInvokeConfigUI(
                HWND hwndParent,
                DWORD dwFlags,
                EAP_METHOD_TYPE eapMethodType,
                DWORD dwSizeOfConfigIn,
                __in_ecount_opt(dwSizeOfConfigIn) const BYTE* pConfigIn,
                DWORD* pdwSizeOfConfigOut,
                BYTE** ppConfigOut,
                EAP_ERROR** pEapError
                );


DWORD WINAPI EapHostPeerQueryCredentialInputFields(
                HANDLE hUserImpersonationToken,
                EAP_METHOD_TYPE eapMethodType,
                DWORD dwFlags,
                DWORD dwEapConnDataSize,
                PBYTE pbEapConnData,
                EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigFieldsArray,
                EAP_ERROR** pEapError
                );


DWORD WINAPI EapHostPeerQueryUserBlobFromCredentialInputFields(
                HANDLE hUserImpersonationToken,
                EAP_METHOD_TYPE eapMethodType,
                DWORD dwFlags,
                DWORD dwEapConnDataSize,
                PBYTE pbEapConnData,
                EAP_CONFIG_INPUT_FIELD_ARRAY *pEapConfigInputFieldArray,
                DWORD *pdwUserBlobSize,
                PBYTE *ppbUserBlob,
                EAP_ERROR** pEapError
                );


DWORD WINAPI EapHostPeerInvokeInteractiveUI(
                HWND hwndParent,
                DWORD dwSizeofUIContextData,
                __in_ecount_opt(dwSizeofUIContextData) const BYTE* pUIContextData,
                DWORD* pdwSizeOfDataFromInteractiveUI,
                __deref_out_ecount(*pdwSizeOfDataFromInteractiveUI) BYTE** ppDataFromInteractiveUI,
                EAP_ERROR** pEapError
                );


DWORD WINAPI EapHostPeerConfigXml2Blob(
                IN DWORD dwFlags,
                IN IXMLDOMNode* pConfigDoc,
                OUT DWORD* pdwSizeOfConfigOut,
                OUT __deref_out_ecount(*pdwSizeOfConfigOut) BYTE** ppConfigOut,
                OUT EAP_METHOD_TYPE* pEapMethodType,
                OUT EAP_ERROR** ppEapError
                );


DWORD WINAPI EapHostPeerCredentialsXml2Blob(
                IN DWORD dwFlags,
                IN IXMLDOMNode* pCredentialsDoc,
                IN DWORD dwSizeOfConfigIn,
                IN __in_ecount(dwSizeOfConfigIn) BYTE* pConfigIn,
                OUT  DWORD* pdwSizeOfCredentialsOut,
                OUT __deref_out_ecount(*pdwSizeOfCredentialsOut) BYTE** ppCredentialsOut,
                OUT EAP_METHOD_TYPE* pEapMethodType,
                OUT EAP_ERROR** ppEapError
                );


DWORD WINAPI EapHostPeerConfigBlob2Xml(
                IN DWORD dwFlags,
                IN EAP_METHOD_TYPE eapMethodType,
                IN DWORD dwSizeOfConfigIn,
                IN __in_ecount(dwSizeOfConfigDataIn) BYTE* pConfigIn,
                // TODO: Move to IXMLDOMDocument
                OUT IXMLDOMDocument2** ppConfigDoc,
                OUT EAP_ERROR** ppEapError
                );


VOID WINAPI EapHostPeerFreeMemory(BYTE* pData);


VOID WINAPI EapHostPeerFreeErrorMemory(EAP_ERROR* pEapError);


#ifdef __cplusplus
}
#endif

#endif // EAPHOSTPEERCONFIGAPIS_H


