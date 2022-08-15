

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for WpcApi.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WpcApi_h__
#define __WpcApi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWPCSettings_FWD_DEFINED__
#define __IWPCSettings_FWD_DEFINED__
typedef interface IWPCSettings IWPCSettings;
#endif 	/* __IWPCSettings_FWD_DEFINED__ */


#ifndef __IWPCGamesSettings_FWD_DEFINED__
#define __IWPCGamesSettings_FWD_DEFINED__
typedef interface IWPCGamesSettings IWPCGamesSettings;
#endif 	/* __IWPCGamesSettings_FWD_DEFINED__ */


#ifndef __IWPCWebSettings_FWD_DEFINED__
#define __IWPCWebSettings_FWD_DEFINED__
typedef interface IWPCWebSettings IWPCWebSettings;
#endif 	/* __IWPCWebSettings_FWD_DEFINED__ */


#ifndef __IWindowsParentalControlsCore_FWD_DEFINED__
#define __IWindowsParentalControlsCore_FWD_DEFINED__
typedef interface IWindowsParentalControlsCore IWindowsParentalControlsCore;
#endif 	/* __IWindowsParentalControlsCore_FWD_DEFINED__ */


#ifndef __IWindowsParentalControls_FWD_DEFINED__
#define __IWindowsParentalControls_FWD_DEFINED__
typedef interface IWindowsParentalControls IWindowsParentalControls;
#endif 	/* __IWindowsParentalControls_FWD_DEFINED__ */


#ifndef __WpcSettingsProvider_FWD_DEFINED__
#define __WpcSettingsProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class WpcSettingsProvider WpcSettingsProvider;
#else
typedef struct WpcSettingsProvider WpcSettingsProvider;
#endif /* __cplusplus */

#endif 	/* __WpcSettingsProvider_FWD_DEFINED__ */


#ifndef __WindowsParentalControls_FWD_DEFINED__
#define __WindowsParentalControls_FWD_DEFINED__

#ifdef __cplusplus
typedef class WindowsParentalControls WindowsParentalControls;
#else
typedef struct WindowsParentalControls WindowsParentalControls;
#endif /* __cplusplus */

#endif 	/* __WindowsParentalControls_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_WpcApi_0000_0000 */
/* [local] */ 

/*******************************************************************************/
/*                                                                             */
/*    Copyright (C) Microsoft Corporation.  All rights reserved.                 */
/*                                                                             */
/*    Interfaces for Windows Parental Controls clients.                        */
/*                                                                             */
/*******************************************************************************/
typedef /* [v1_enum] */ 
enum tagWPCFLAG_RESTRICTION
    {	WPCFLAG_NO_RESTRICTION	= 0,
	WPCFLAG_LOGGING_REQUIRED	= 0x1,
	WPCFLAG_WEB_FILTERED	= 0x2,
	WPCFLAG_HOURS_RESTRICTED	= 0x4,
	WPCFLAG_GAMES_BLOCKED	= 0x8,
	WPCFLAG_APPS_RESTRICTED	= 0x10
    } 	WPCFLAG_RESTRICTION;



extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0000_v0_0_s_ifspec;

#ifndef __IWPCSettings_INTERFACE_DEFINED__
#define __IWPCSettings_INTERFACE_DEFINED__

/* interface IWPCSettings */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWPCSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FDF6CA1-0189-47e4-B670-1A8A4636E340")
    IWPCSettings : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLoggingRequired( 
            /* [out] */ __RPC__out BOOL *pfRequired) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastSettingsChangeTime( 
            /* [out] */ __RPC__out SYSTEMTIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRestrictions( 
            /* [out] */ __RPC__out DWORD *pdwRestrictions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWPCSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWPCSettings * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWPCSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWPCSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLoggingRequired )( 
            IWPCSettings * This,
            /* [out] */ __RPC__out BOOL *pfRequired);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastSettingsChangeTime )( 
            IWPCSettings * This,
            /* [out] */ __RPC__out SYSTEMTIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetRestrictions )( 
            IWPCSettings * This,
            /* [out] */ __RPC__out DWORD *pdwRestrictions);
        
        END_INTERFACE
    } IWPCSettingsVtbl;

    interface IWPCSettings
    {
        CONST_VTBL struct IWPCSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWPCSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWPCSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWPCSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWPCSettings_IsLoggingRequired(This,pfRequired)	\
    ( (This)->lpVtbl -> IsLoggingRequired(This,pfRequired) ) 

#define IWPCSettings_GetLastSettingsChangeTime(This,pTime)	\
    ( (This)->lpVtbl -> GetLastSettingsChangeTime(This,pTime) ) 

#define IWPCSettings_GetRestrictions(This,pdwRestrictions)	\
    ( (This)->lpVtbl -> GetRestrictions(This,pdwRestrictions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWPCSettings_INTERFACE_DEFINED__ */


#ifndef __IWPCGamesSettings_INTERFACE_DEFINED__
#define __IWPCGamesSettings_INTERFACE_DEFINED__

/* interface IWPCGamesSettings */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWPCGamesSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95E87780-E158-489e-B452-BBB850790715")
    IWPCGamesSettings : public IWPCSettings
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsBlocked( 
            /* [in] */ GUID guidAppID,
            /* [out] */ __RPC__out DWORD *pdwReasons) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWPCGamesSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWPCGamesSettings * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWPCGamesSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWPCGamesSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLoggingRequired )( 
            IWPCGamesSettings * This,
            /* [out] */ __RPC__out BOOL *pfRequired);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastSettingsChangeTime )( 
            IWPCGamesSettings * This,
            /* [out] */ __RPC__out SYSTEMTIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetRestrictions )( 
            IWPCGamesSettings * This,
            /* [out] */ __RPC__out DWORD *pdwRestrictions);
        
        HRESULT ( STDMETHODCALLTYPE *IsBlocked )( 
            IWPCGamesSettings * This,
            /* [in] */ GUID guidAppID,
            /* [out] */ __RPC__out DWORD *pdwReasons);
        
        END_INTERFACE
    } IWPCGamesSettingsVtbl;

    interface IWPCGamesSettings
    {
        CONST_VTBL struct IWPCGamesSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWPCGamesSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWPCGamesSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWPCGamesSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWPCGamesSettings_IsLoggingRequired(This,pfRequired)	\
    ( (This)->lpVtbl -> IsLoggingRequired(This,pfRequired) ) 

#define IWPCGamesSettings_GetLastSettingsChangeTime(This,pTime)	\
    ( (This)->lpVtbl -> GetLastSettingsChangeTime(This,pTime) ) 

#define IWPCGamesSettings_GetRestrictions(This,pdwRestrictions)	\
    ( (This)->lpVtbl -> GetRestrictions(This,pdwRestrictions) ) 


#define IWPCGamesSettings_IsBlocked(This,guidAppID,pdwReasons)	\
    ( (This)->lpVtbl -> IsBlocked(This,guidAppID,pdwReasons) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWPCGamesSettings_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WpcApi_0000_0002 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum tagWPCFLAG_WEB_SETTING
    {	WPCFLAG_WEB_SETTING_NOTBLOCKED	= 0,
	WPCFLAG_WEB_SETTING_DOWNLOADSBLOCKED	= 0x1
    } 	WPCFLAG_WEB_SETTING;



extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0002_v0_0_s_ifspec;

#ifndef __IWPCWebSettings_INTERFACE_DEFINED__
#define __IWPCWebSettings_INTERFACE_DEFINED__

/* interface IWPCWebSettings */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWPCWebSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FFCCBDB8-0992-4c30-B0F1-1CBB09C240AA")
    IWPCWebSettings : public IWPCSettings
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSettings( 
            /* [out] */ __RPC__out DWORD *pdwSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestURLOverride( 
            /* [in] */ __RPC__in HWND hWnd,
            /* [in] */ __RPC__in LPCWSTR pcszURL,
            /* [in] */ DWORD cURLs,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(cURLs) LPCWSTR *ppcszSubURLs,
            /* [unique][out][in] */ __RPC__inout_opt BOOL *pfChanged) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWPCWebSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWPCWebSettings * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWPCWebSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWPCWebSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLoggingRequired )( 
            IWPCWebSettings * This,
            /* [out] */ __RPC__out BOOL *pfRequired);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastSettingsChangeTime )( 
            IWPCWebSettings * This,
            /* [out] */ __RPC__out SYSTEMTIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetRestrictions )( 
            IWPCWebSettings * This,
            /* [out] */ __RPC__out DWORD *pdwRestrictions);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettings )( 
            IWPCWebSettings * This,
            /* [out] */ __RPC__out DWORD *pdwSettings);
        
        HRESULT ( STDMETHODCALLTYPE *RequestURLOverride )( 
            IWPCWebSettings * This,
            /* [in] */ __RPC__in HWND hWnd,
            /* [in] */ __RPC__in LPCWSTR pcszURL,
            /* [in] */ DWORD cURLs,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(cURLs) LPCWSTR *ppcszSubURLs,
            /* [unique][out][in] */ __RPC__inout_opt BOOL *pfChanged);
        
        END_INTERFACE
    } IWPCWebSettingsVtbl;

    interface IWPCWebSettings
    {
        CONST_VTBL struct IWPCWebSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWPCWebSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWPCWebSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWPCWebSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWPCWebSettings_IsLoggingRequired(This,pfRequired)	\
    ( (This)->lpVtbl -> IsLoggingRequired(This,pfRequired) ) 

#define IWPCWebSettings_GetLastSettingsChangeTime(This,pTime)	\
    ( (This)->lpVtbl -> GetLastSettingsChangeTime(This,pTime) ) 

#define IWPCWebSettings_GetRestrictions(This,pdwRestrictions)	\
    ( (This)->lpVtbl -> GetRestrictions(This,pdwRestrictions) ) 


#define IWPCWebSettings_GetSettings(This,pdwSettings)	\
    ( (This)->lpVtbl -> GetSettings(This,pdwSettings) ) 

#define IWPCWebSettings_RequestURLOverride(This,hWnd,pcszURL,cURLs,ppcszSubURLs,pfChanged)	\
    ( (This)->lpVtbl -> RequestURLOverride(This,hWnd,pcszURL,cURLs,ppcszSubURLs,pfChanged) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWPCWebSettings_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_WpcApi_0000_0003 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum tagWPCFLAG_VISIBILITY
    {	WPCFLAG_WPC_VISIBLE	= 0,
	WPCFLAG_WPC_HIDDEN	= 0x1
    } 	WPCFLAG_VISIBILITY;



extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WpcApi_0000_0003_v0_0_s_ifspec;

#ifndef __IWindowsParentalControlsCore_INTERFACE_DEFINED__
#define __IWindowsParentalControlsCore_INTERFACE_DEFINED__

/* interface IWindowsParentalControlsCore */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWindowsParentalControlsCore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4FF40A0F-3F3B-4d7c-A41B-4F39D7B44D05")
    IWindowsParentalControlsCore : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVisibility( 
            /* [out] */ __RPC__out WPCFLAG_VISIBILITY *peVisibility) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserSettings( 
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCSettings **ppSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWebSettings( 
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCWebSettings **ppSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWebFilterInfo( 
            /* [out] */ __RPC__out GUID *pguidID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWindowsParentalControlsCoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsParentalControlsCore * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsParentalControlsCore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsParentalControlsCore * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVisibility )( 
            IWindowsParentalControlsCore * This,
            /* [out] */ __RPC__out WPCFLAG_VISIBILITY *peVisibility);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserSettings )( 
            IWindowsParentalControlsCore * This,
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCSettings **ppSettings);
        
        HRESULT ( STDMETHODCALLTYPE *GetWebSettings )( 
            IWindowsParentalControlsCore * This,
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCWebSettings **ppSettings);
        
        HRESULT ( STDMETHODCALLTYPE *GetWebFilterInfo )( 
            IWindowsParentalControlsCore * This,
            /* [out] */ __RPC__out GUID *pguidID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszName);
        
        END_INTERFACE
    } IWindowsParentalControlsCoreVtbl;

    interface IWindowsParentalControlsCore
    {
        CONST_VTBL struct IWindowsParentalControlsCoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsParentalControlsCore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsParentalControlsCore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsParentalControlsCore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsParentalControlsCore_GetVisibility(This,peVisibility)	\
    ( (This)->lpVtbl -> GetVisibility(This,peVisibility) ) 

#define IWindowsParentalControlsCore_GetUserSettings(This,pcszSID,ppSettings)	\
    ( (This)->lpVtbl -> GetUserSettings(This,pcszSID,ppSettings) ) 

#define IWindowsParentalControlsCore_GetWebSettings(This,pcszSID,ppSettings)	\
    ( (This)->lpVtbl -> GetWebSettings(This,pcszSID,ppSettings) ) 

#define IWindowsParentalControlsCore_GetWebFilterInfo(This,pguidID,ppszName)	\
    ( (This)->lpVtbl -> GetWebFilterInfo(This,pguidID,ppszName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsParentalControlsCore_INTERFACE_DEFINED__ */


#ifndef __IWindowsParentalControls_INTERFACE_DEFINED__
#define __IWindowsParentalControls_INTERFACE_DEFINED__

/* interface IWindowsParentalControls */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWindowsParentalControls;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28B4D88B-E072-49e6-804D-26EDBE21A7B9")
    IWindowsParentalControls : public IWindowsParentalControlsCore
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetGamesSettings( 
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCGamesSettings **ppSettings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWindowsParentalControlsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowsParentalControls * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowsParentalControls * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowsParentalControls * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVisibility )( 
            IWindowsParentalControls * This,
            /* [out] */ __RPC__out WPCFLAG_VISIBILITY *peVisibility);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserSettings )( 
            IWindowsParentalControls * This,
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCSettings **ppSettings);
        
        HRESULT ( STDMETHODCALLTYPE *GetWebSettings )( 
            IWindowsParentalControls * This,
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCWebSettings **ppSettings);
        
        HRESULT ( STDMETHODCALLTYPE *GetWebFilterInfo )( 
            IWindowsParentalControls * This,
            /* [out] */ __RPC__out GUID *pguidID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetGamesSettings )( 
            IWindowsParentalControls * This,
            /* [string][unique][in] */ __RPC__in_opt LPCWSTR pcszSID,
            /* [out] */ __RPC__deref_out_opt IWPCGamesSettings **ppSettings);
        
        END_INTERFACE
    } IWindowsParentalControlsVtbl;

    interface IWindowsParentalControls
    {
        CONST_VTBL struct IWindowsParentalControlsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowsParentalControls_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowsParentalControls_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowsParentalControls_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowsParentalControls_GetVisibility(This,peVisibility)	\
    ( (This)->lpVtbl -> GetVisibility(This,peVisibility) ) 

#define IWindowsParentalControls_GetUserSettings(This,pcszSID,ppSettings)	\
    ( (This)->lpVtbl -> GetUserSettings(This,pcszSID,ppSettings) ) 

#define IWindowsParentalControls_GetWebSettings(This,pcszSID,ppSettings)	\
    ( (This)->lpVtbl -> GetWebSettings(This,pcszSID,ppSettings) ) 

#define IWindowsParentalControls_GetWebFilterInfo(This,pguidID,ppszName)	\
    ( (This)->lpVtbl -> GetWebFilterInfo(This,pguidID,ppszName) ) 


#define IWindowsParentalControls_GetGamesSettings(This,pcszSID,ppSettings)	\
    ( (This)->lpVtbl -> GetGamesSettings(This,pcszSID,ppSettings) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowsParentalControls_INTERFACE_DEFINED__ */



#ifndef __WPCAPILib_LIBRARY_DEFINED__
#define __WPCAPILib_LIBRARY_DEFINED__

/* library WPCAPILib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WPCAPILib;

EXTERN_C const CLSID CLSID_WpcSettingsProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("355DFFAA-3B9F-435c-B428-5D44290BC5F2")
WpcSettingsProvider;
#endif

EXTERN_C const CLSID CLSID_WindowsParentalControls;

#ifdef __cplusplus

class DECLSPEC_UUID("E77CC89B-7401-4c04-8CED-149DB35ADD04")
WindowsParentalControls;
#endif
#endif /* __WPCAPILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



