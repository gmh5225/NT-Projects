/*++

Copyright (C) Microsoft Corporation, 2006

Module Name:

    slpublic.h

Abstract:

    Software Licensing and Geniune Advantage Client public API
   
--*/
#pragma once

#ifndef _SLPUBLIC_H_
#define _SLPUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SLFreeMemory(p) LocalFree(p)
    
#define SLWGAFreeMemory(p) LocalFree(p)
    
typedef GUID SLID;
    
typedef enum _tagSLDATATYPE
{
    SL_DATA_NONE        = REG_NONE,
    SL_DATA_SZ          = REG_SZ,
    SL_DATA_DWORD       = REG_DWORD,
    SL_DATA_BINARY      = REG_BINARY,
    SL_DATA_MULTI_SZ    = REG_MULTI_SZ,
    SL_DATA_SUM         = 100,
} SLDATATYPE;

typedef enum _SL_GENUINE_STATE
{
    SL_GEN_STATE_IS_GENUINE         = 0,
    SL_GEN_STATE_INVALID_LICENSE,
    SL_GEN_STATE_TAMPERED,
    SL_GEN_STATE_LAST, 
} SL_GENUINE_STATE;

typedef struct _tagSL_NONGENUINE_UI_OPTIONS
{
    DWORD                       cbSize;
    CONST SLID*                 pComponentId;
    HRESULT                     hResultUI;

} SL_NONGENUINE_UI_OPTIONS;


__control_entrypoint(DllExport)
HRESULT 
WINAPI
SLGetWindowsInformation(
    __in PCWSTR pwszValueName,
    __out_opt SLDATATYPE* peDataType,
    __out UINT* pcbValue,
    __deref_out_bcount(*pcbValue) PBYTE* ppbValue
    );
/*++
Routine Description:

    This function is used to for Windows components to get 
    component policy value.
    
Arguments:

    pwszValueName
        The name of the requested value.
        
    peDataType
        Data type. Following types are supported:
            SL_DATA_SZ     - UNICODE string
            SL_DATA_DWORD  - DWORD
            SL_DATA_BINARY - Binary blob
        
    pcbValue
        Size of the allocated buffer.
        
    ppbValue
        The value. If successful, the data is returned in the buffer 
        allocated by SLC.
        The caller has to call SLFreeMemory to free the memory. 
        
Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_RIGHT_NOT_GRANTED
    
--*/

__control_entrypoint(DllExport)
HRESULT 
WINAPI
SLGetWindowsInformationDWORD(
    __in PCWSTR pwszValueName,
    __out DWORD* pdwValue
    );
/*++
Routine Description:

    This function is used to for Windows components to get 
    component policy DWORD value.

Arguments:

    pwszValueName
        The name of the requested value.
        
    pdwValue
        The buffer to receive DWORD value
        
Return Error:
    E_INVALIDARG
    SL_E_VALUE_NOT_FOUND
    SL_E_RIGHT_NOT_GRANTED
    SL_E_DATATYPE_MISMATCHED
    
--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLIsGenuineLocal(
    __in                        CONST SLID*                 pAppId,
    __out                       SL_GENUINE_STATE *          pGenuineState, 
    __inout_opt                 SL_NONGENUINE_UI_OPTIONS*   pUIOptions
    );
/*++
Routine Description:

    Determines if an installation is a Genuine Windows installation.
    It interrogates the license for pAppId and inspects the "Tampered"
    flag.  If either the license for pAppId is invalid or the "Tampered"
    flag is set, the installation is assumed to be invalid.

    pGenuineState is ONLY modified if the result is S_OK.  Otherwise, it is
    left in the state in which it was found on function entry.

Arguments:

    pAppId
        Application identifier. 

    pbGenuineState
        Output state value - one of the SL_GENUINE_STATE values

    pUIOptions
        Non genuine UI options. If NULL, no UI is displayed if 
        state is non-genuine. 

Return Error:

    S_OK
        Operation completed successfully.

    E_INVALIDARG
        pGenuineState is NULL.

--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLAcquireGenuineTicket(
    __deref_out_bcount(*pcbTicketBlob) void ** ppTicketBlob,  
    __out UINT *pcbTicketBlob,
    __in PCWSTR pwszTemplateId, 
    __in PCWSTR pwszServerUrl, 
    __in_opt PCWSTR pwszClientToken 
    );
/*++
Routine Description:

    Returns genuine ticket acquired from Software Licensing Server based
    on SLWGA template blob. 
    
    The client is responsible for freeing the buffer returned in ppGenuineBlob.
    SLWGAFreeMemory should be used to free the memory.

    The output parameters are only set if the function returns S_OK.  Otherwise,
    they are left as they were when the function was entered.

Arguments:

    ppTicketBlob
        Pointer to output pointer to be returned (XrML genuine ticket).

    pcbTicketBlob
        An output pointer that will contain the size, in bytes, of the region
        returned in ppTicketBlob.

    pwszTemplateId
        Id of genuine blob template kept on the server side. 

    pwszServerUrl
        Ticket acquisition server url. 

    pwszClientToken
        Client custom token. 

Return Error:

    S_OK
        Operation completed successfully.

--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLGetInstalledSAMLicenseApplications(
    __out UINT* pnReturnedAppIds,
    __deref_out_ecount(*pnReturnedAppIds) SLID** ppReturnedAppIds
    );
/*++
Routine Description:

    Obtains an array of Application Ids representing applications whose SAM
    licenses have been installed with SLInstallSAMLicense.

Arguments:
    pnReturnedAppIds
        Number of elements in ppReturnedAppIds array
    ppReturnedAppIds
        Array containing all installed Application Ids.
        The caller has to call SLFreeMemory to free the memory.         
        
Return Errors:

    S_OK
        Operation completed successfully
    E_INVALIDARG
        One or more arguments are invalid    
    
--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLGetSAMLicense(
    __in const SLID* pApplicationId,
    __out UINT* pcbXmlLicenseData,
    __deref_out_bcount(*pcbXmlLicenseData) PBYTE* ppbXmlLicenseData
    );
/*++
Routine Description:

    Obtain information about an installed SAM application.

Arguments:
    pApplicationId
        Id of Application for which to obtain its SAM License
    pcbXmlLicenseData
        Size of ppbXmlLicenseData in bytes
    ppbXmlLicenseData
        License file data for (SAM) application with Application Id pApplicationId.
        The caller has to call SLFreeMemory to free the memory. 
        
Return Errors:

    S_OK
        Operation completed successfully
    SL_E_LICENSE_FILE_NOT_INSTALLED
        License not installed
    E_INVALIDARG
        One or more arguments are invalid    
    
--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLInstallSAMLicense(
    __in const SLID* pApplicationId,
    __in UINT cbXmlLicenseData,
    __in_bcount(cbXmlLicenseData) CONST BYTE* pbXmlLicenseData
    );
/*++
Routine Description:

    Install SAM License

Arguments:
    pApplicationId
        Id of Application for which to install SAM License.
    cbXmlLicenseData
        Size of pbXmlLicenseData in bytes
    pbXmlLicenseData
        License file data
        
Return Errors:

    S_OK
        Operation completed successfully
    SL_E_LUA_ACCESSDENIED
        The Software Licensing Service reported that the action requires administrator privilege
    E_INVALIDARG
        One or more arguments are invalid    
--*/

__control_entrypoint(DllExport)
HRESULT
WINAPI
SLUninstallSAMLicense(
    __in const SLID* pApplicationId
    );
/*++
Routine Description:

    UnInstall SAM License

Arguments:
    pApplicationId
        Id of Application for which to uninstall SAM License.
        
Return Errors:

    S_OK
        Operation completed successfully
    SL_E_LICENSE_FILE_NOT_INSTALLED
        License not installed
    SL_E_LUA_ACCESSDENIED
        The Software Licensing Service reported that the action requires administrator privilege
    E_INVALIDARG
        One or more arguments are invalid    
    
--*/

#ifdef __cplusplus
}
#endif

#endif

