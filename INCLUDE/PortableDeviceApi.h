

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for PortableDeviceApi.idl:
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

#ifndef __PortableDeviceApi_h__
#define __PortableDeviceApi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPortableDeviceManager_FWD_DEFINED__
#define __IPortableDeviceManager_FWD_DEFINED__
typedef interface IPortableDeviceManager IPortableDeviceManager;
#endif 	/* __IPortableDeviceManager_FWD_DEFINED__ */


#ifndef __IPortableDevice_FWD_DEFINED__
#define __IPortableDevice_FWD_DEFINED__
typedef interface IPortableDevice IPortableDevice;
#endif 	/* __IPortableDevice_FWD_DEFINED__ */


#ifndef __IPortableDeviceContent_FWD_DEFINED__
#define __IPortableDeviceContent_FWD_DEFINED__
typedef interface IPortableDeviceContent IPortableDeviceContent;
#endif 	/* __IPortableDeviceContent_FWD_DEFINED__ */


#ifndef __IEnumPortableDeviceObjectIDs_FWD_DEFINED__
#define __IEnumPortableDeviceObjectIDs_FWD_DEFINED__
typedef interface IEnumPortableDeviceObjectIDs IEnumPortableDeviceObjectIDs;
#endif 	/* __IEnumPortableDeviceObjectIDs_FWD_DEFINED__ */


#ifndef __IPortableDeviceProperties_FWD_DEFINED__
#define __IPortableDeviceProperties_FWD_DEFINED__
typedef interface IPortableDeviceProperties IPortableDeviceProperties;
#endif 	/* __IPortableDeviceProperties_FWD_DEFINED__ */


#ifndef __IPortableDeviceResources_FWD_DEFINED__
#define __IPortableDeviceResources_FWD_DEFINED__
typedef interface IPortableDeviceResources IPortableDeviceResources;
#endif 	/* __IPortableDeviceResources_FWD_DEFINED__ */


#ifndef __IPortableDeviceCapabilities_FWD_DEFINED__
#define __IPortableDeviceCapabilities_FWD_DEFINED__
typedef interface IPortableDeviceCapabilities IPortableDeviceCapabilities;
#endif 	/* __IPortableDeviceCapabilities_FWD_DEFINED__ */


#ifndef __IPortableDeviceEventCallback_FWD_DEFINED__
#define __IPortableDeviceEventCallback_FWD_DEFINED__
typedef interface IPortableDeviceEventCallback IPortableDeviceEventCallback;
#endif 	/* __IPortableDeviceEventCallback_FWD_DEFINED__ */


#ifndef __IPortableDeviceDataStream_FWD_DEFINED__
#define __IPortableDeviceDataStream_FWD_DEFINED__
typedef interface IPortableDeviceDataStream IPortableDeviceDataStream;
#endif 	/* __IPortableDeviceDataStream_FWD_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulk_FWD_DEFINED__
#define __IPortableDevicePropertiesBulk_FWD_DEFINED__
typedef interface IPortableDevicePropertiesBulk IPortableDevicePropertiesBulk;
#endif 	/* __IPortableDevicePropertiesBulk_FWD_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__
#define __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__
typedef interface IPortableDevicePropertiesBulkCallback IPortableDevicePropertiesBulkCallback;
#endif 	/* __IPortableDevicePropertiesBulkCallback_FWD_DEFINED__ */


#ifndef __PortableDevice_FWD_DEFINED__
#define __PortableDevice_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDevice PortableDevice;
#else
typedef struct PortableDevice PortableDevice;
#endif /* __cplusplus */

#endif 	/* __PortableDevice_FWD_DEFINED__ */


#ifndef __PortableDeviceManager_FWD_DEFINED__
#define __PortableDeviceManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PortableDeviceManager PortableDeviceManager;
#else
typedef struct PortableDeviceManager PortableDeviceManager;
#endif /* __cplusplus */

#endif 	/* __PortableDeviceManager_FWD_DEFINED__ */


/* header files for imported files */
#include "propidl.h"
#include "PortableDeviceTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_PortableDeviceApi_0000_0000 */
/* [local] */ 

#if (_WIN32_WINNT >= 0x0501) // XP and later













extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceApi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceApi_0000_0000_v0_0_s_ifspec;

#ifndef __IPortableDeviceManager_INTERFACE_DEFINED__
#define __IPortableDeviceManager_INTERFACE_DEFINED__

/* interface IPortableDeviceManager */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a1567595-4c2f-4574-a6fa-ecef917b9a40")
    IPortableDeviceManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDevices( 
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *pPnPDeviceIDs,
            /* [out][in] */ __RPC__inout DWORD *pcPnPDeviceIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshDeviceList( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceFriendlyName( 
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceFriendlyName,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceDescription( 
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceDescription,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceManufacturer( 
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceManufacturer,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceManufacturer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceProperty( 
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [in] */ __RPC__in LPCWSTR pszDevicePropertyName,
            /* [unique][out][in] */ __RPC__inout_opt BYTE *pData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pcbData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateDevices( 
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *pPnPDeviceIDs,
            /* [out][in] */ __RPC__inout DWORD *pcPnPDeviceIDs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDevices )( 
            IPortableDeviceManager * This,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *pPnPDeviceIDs,
            /* [out][in] */ __RPC__inout DWORD *pcPnPDeviceIDs);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshDeviceList )( 
            IPortableDeviceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceFriendlyName )( 
            IPortableDeviceManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceFriendlyName,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceDescription )( 
            IPortableDeviceManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceDescription,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceManufacturer )( 
            IPortableDeviceManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [unique][out][in] */ __RPC__inout_opt WCHAR *pDeviceManufacturer,
            /* [out][in] */ __RPC__inout DWORD *pcchDeviceManufacturer);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceProperty )( 
            IPortableDeviceManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [in] */ __RPC__in LPCWSTR pszDevicePropertyName,
            /* [unique][out][in] */ __RPC__inout_opt BYTE *pData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pcbData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateDevices )( 
            IPortableDeviceManager * This,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *pPnPDeviceIDs,
            /* [out][in] */ __RPC__inout DWORD *pcPnPDeviceIDs);
        
        END_INTERFACE
    } IPortableDeviceManagerVtbl;

    interface IPortableDeviceManager
    {
        CONST_VTBL struct IPortableDeviceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceManager_GetDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs)	\
    ( (This)->lpVtbl -> GetDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs) ) 

#define IPortableDeviceManager_RefreshDeviceList(This)	\
    ( (This)->lpVtbl -> RefreshDeviceList(This) ) 

#define IPortableDeviceManager_GetDeviceFriendlyName(This,pszPnPDeviceID,pDeviceFriendlyName,pcchDeviceFriendlyName)	\
    ( (This)->lpVtbl -> GetDeviceFriendlyName(This,pszPnPDeviceID,pDeviceFriendlyName,pcchDeviceFriendlyName) ) 

#define IPortableDeviceManager_GetDeviceDescription(This,pszPnPDeviceID,pDeviceDescription,pcchDeviceDescription)	\
    ( (This)->lpVtbl -> GetDeviceDescription(This,pszPnPDeviceID,pDeviceDescription,pcchDeviceDescription) ) 

#define IPortableDeviceManager_GetDeviceManufacturer(This,pszPnPDeviceID,pDeviceManufacturer,pcchDeviceManufacturer)	\
    ( (This)->lpVtbl -> GetDeviceManufacturer(This,pszPnPDeviceID,pDeviceManufacturer,pcchDeviceManufacturer) ) 

#define IPortableDeviceManager_GetDeviceProperty(This,pszPnPDeviceID,pszDevicePropertyName,pData,pcbData,pdwType)	\
    ( (This)->lpVtbl -> GetDeviceProperty(This,pszPnPDeviceID,pszDevicePropertyName,pData,pcbData,pdwType) ) 

#define IPortableDeviceManager_GetPrivateDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs)	\
    ( (This)->lpVtbl -> GetPrivateDevices(This,pPnPDeviceIDs,pcPnPDeviceIDs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceManager_INTERFACE_DEFINED__ */


#ifndef __IPortableDevice_INTERFACE_DEFINED__
#define __IPortableDevice_INTERFACE_DEFINED__

/* interface IPortableDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("625e2df8-6392-4cf0-9ad1-3cfa5f17775c")
    IPortableDevice : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pClientInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pParameters,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Content( 
            /* [out] */ __RPC__deref_out_opt IPortableDeviceContent **ppContent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Capabilities( 
            /* [out] */ __RPC__deref_out_opt IPortableDeviceCapabilities **ppCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in_opt IPortableDeviceEventCallback *pCallback,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceValues *pParameters,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [in] */ __RPC__in LPCWSTR pszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPnPDeviceID( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPnPDeviceID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IPortableDevice * This,
            /* [in] */ __RPC__in LPCWSTR pszPnPDeviceID,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pClientInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IPortableDevice * This,
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pParameters,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Content )( 
            IPortableDevice * This,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceContent **ppContent);
        
        HRESULT ( STDMETHODCALLTYPE *Capabilities )( 
            IPortableDevice * This,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceCapabilities **ppCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IPortableDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IPortableDevice * This,
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in_opt IPortableDeviceEventCallback *pCallback,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceValues *pParameters,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            IPortableDevice * This,
            /* [in] */ __RPC__in LPCWSTR pszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetPnPDeviceID )( 
            IPortableDevice * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPnPDeviceID);
        
        END_INTERFACE
    } IPortableDeviceVtbl;

    interface IPortableDevice
    {
        CONST_VTBL struct IPortableDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevice_Open(This,pszPnPDeviceID,pClientInfo)	\
    ( (This)->lpVtbl -> Open(This,pszPnPDeviceID,pClientInfo) ) 

#define IPortableDevice_SendCommand(This,dwFlags,pParameters,ppResults)	\
    ( (This)->lpVtbl -> SendCommand(This,dwFlags,pParameters,ppResults) ) 

#define IPortableDevice_Content(This,ppContent)	\
    ( (This)->lpVtbl -> Content(This,ppContent) ) 

#define IPortableDevice_Capabilities(This,ppCapabilities)	\
    ( (This)->lpVtbl -> Capabilities(This,ppCapabilities) ) 

#define IPortableDevice_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDevice_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IPortableDevice_Advise(This,dwFlags,pCallback,pParameters,ppszCookie)	\
    ( (This)->lpVtbl -> Advise(This,dwFlags,pCallback,pParameters,ppszCookie) ) 

#define IPortableDevice_Unadvise(This,pszCookie)	\
    ( (This)->lpVtbl -> Unadvise(This,pszCookie) ) 

#define IPortableDevice_GetPnPDeviceID(This,ppszPnPDeviceID)	\
    ( (This)->lpVtbl -> GetPnPDeviceID(This,ppszPnPDeviceID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevice_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceContent_INTERFACE_DEFINED__
#define __IPortableDeviceContent_INTERFACE_DEFINED__

/* interface IPortableDeviceContent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceContent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6a96ed84-7c73-4480-9938-bf5af477d426")
    IPortableDeviceContent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in LPCWSTR pszParentObjectID,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceValues *pFilter,
            /* [out] */ __RPC__deref_out_opt IEnumPortableDeviceObjectIDs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Properties( 
            /* [out] */ __RPC__deref_out_opt IPortableDeviceProperties **ppProperties) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Transfer( 
            /* [out] */ __RPC__deref_out_opt IPortableDeviceResources **ppResources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObjectWithPropertiesOnly( 
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObjectWithPropertiesAndData( 
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [out] */ __RPC__deref_out_opt IStream **ppData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalWriteBufferSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ const DWORD dwOptions,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectIDsFromPersistentUniqueIDs( 
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pPersistentUniqueIDs,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppObjectIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in LPCWSTR pszDestinationFolderObjectID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in LPCWSTR pszDestinationFolderObjectID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceContentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceContent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            IPortableDeviceContent * This,
            /* [in] */ const DWORD dwFlags,
            /* [in] */ __RPC__in LPCWSTR pszParentObjectID,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceValues *pFilter,
            /* [out] */ __RPC__deref_out_opt IEnumPortableDeviceObjectIDs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Properties )( 
            IPortableDeviceContent * This,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceProperties **ppProperties);
        
        HRESULT ( STDMETHODCALLTYPE *Transfer )( 
            IPortableDeviceContent * This,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceResources **ppResources);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesOnly )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObjectWithPropertiesAndData )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [out] */ __RPC__deref_out_opt IStream **ppData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalWriteBufferSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IPortableDeviceContent * This,
            /* [in] */ const DWORD dwOptions,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectIDsFromPersistentUniqueIDs )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pPersistentUniqueIDs,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppObjectIDs);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDeviceContent * This);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in LPCWSTR pszDestinationFolderObjectID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IPortableDeviceContent * This,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in LPCWSTR pszDestinationFolderObjectID,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt IPortableDevicePropVariantCollection **ppResults);
        
        END_INTERFACE
    } IPortableDeviceContentVtbl;

    interface IPortableDeviceContent
    {
        CONST_VTBL struct IPortableDeviceContentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceContent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceContent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceContent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceContent_EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum)	\
    ( (This)->lpVtbl -> EnumObjects(This,dwFlags,pszParentObjectID,pFilter,ppEnum) ) 

#define IPortableDeviceContent_Properties(This,ppProperties)	\
    ( (This)->lpVtbl -> Properties(This,ppProperties) ) 

#define IPortableDeviceContent_Transfer(This,ppResources)	\
    ( (This)->lpVtbl -> Transfer(This,ppResources) ) 

#define IPortableDeviceContent_CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesOnly(This,pValues,ppszObjectID) ) 

#define IPortableDeviceContent_CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie)	\
    ( (This)->lpVtbl -> CreateObjectWithPropertiesAndData(This,pValues,ppData,pdwOptimalWriteBufferSize,ppszCookie) ) 

#define IPortableDeviceContent_Delete(This,dwOptions,pObjectIDs,ppResults)	\
    ( (This)->lpVtbl -> Delete(This,dwOptions,pObjectIDs,ppResults) ) 

#define IPortableDeviceContent_GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs)	\
    ( (This)->lpVtbl -> GetObjectIDsFromPersistentUniqueIDs(This,pPersistentUniqueIDs,ppObjectIDs) ) 

#define IPortableDeviceContent_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceContent_Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Move(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 

#define IPortableDeviceContent_Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults)	\
    ( (This)->lpVtbl -> Copy(This,pObjectIDs,pszDestinationFolderObjectID,ppResults) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceContent_INTERFACE_DEFINED__ */


#ifndef __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__
#define __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__

/* interface IEnumPortableDeviceObjectIDs */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumPortableDeviceObjectIDs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10ece955-cf41-4728-bfa0-41eedf1bbf19")
    IEnumPortableDeviceObjectIDs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cObjects,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cObjects, *pcFetched) LPWSTR *pObjIDs,
            /* [unique][out][in] */ __RPC__inout_opt ULONG *pcFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cObjects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumPortableDeviceObjectIDs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPortableDeviceObjectIDsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPortableDeviceObjectIDs * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPortableDeviceObjectIDs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPortableDeviceObjectIDs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPortableDeviceObjectIDs * This,
            /* [in] */ ULONG cObjects,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cObjects, *pcFetched) LPWSTR *pObjIDs,
            /* [unique][out][in] */ __RPC__inout_opt ULONG *pcFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPortableDeviceObjectIDs * This,
            /* [in] */ ULONG cObjects);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPortableDeviceObjectIDs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPortableDeviceObjectIDs * This,
            /* [out] */ __RPC__deref_out_opt IEnumPortableDeviceObjectIDs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IEnumPortableDeviceObjectIDs * This);
        
        END_INTERFACE
    } IEnumPortableDeviceObjectIDsVtbl;

    interface IEnumPortableDeviceObjectIDs
    {
        CONST_VTBL struct IEnumPortableDeviceObjectIDsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPortableDeviceObjectIDs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumPortableDeviceObjectIDs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumPortableDeviceObjectIDs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumPortableDeviceObjectIDs_Next(This,cObjects,pObjIDs,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,cObjects,pObjIDs,pcFetched) ) 

#define IEnumPortableDeviceObjectIDs_Skip(This,cObjects)	\
    ( (This)->lpVtbl -> Skip(This,cObjects) ) 

#define IEnumPortableDeviceObjectIDs_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumPortableDeviceObjectIDs_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#define IEnumPortableDeviceObjectIDs_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceProperties_INTERFACE_DEFINED__
#define __IPortableDeviceProperties_INTERFACE_DEFINED__

/* interface IPortableDeviceProperties */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7f6d695c-03df-4439-a809-59266beee3a6")
    IPortableDeviceProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedProperties( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyAttributes( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValues( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppValues) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValues( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedProperties )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyAttributes )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetValues )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [unique][in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppValues);
        
        HRESULT ( STDMETHODCALLTYPE *SetValues )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pValues,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResults);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IPortableDeviceProperties * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDeviceProperties * This);
        
        END_INTERFACE
    } IPortableDevicePropertiesVtbl;

    interface IPortableDeviceProperties
    {
        CONST_VTBL struct IPortableDevicePropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceProperties_GetSupportedProperties(This,pszObjectID,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedProperties(This,pszObjectID,ppKeys) ) 

#define IPortableDeviceProperties_GetPropertyAttributes(This,pszObjectID,Key,ppAttributes)	\
    ( (This)->lpVtbl -> GetPropertyAttributes(This,pszObjectID,Key,ppAttributes) ) 

#define IPortableDeviceProperties_GetValues(This,pszObjectID,pKeys,ppValues)	\
    ( (This)->lpVtbl -> GetValues(This,pszObjectID,pKeys,ppValues) ) 

#define IPortableDeviceProperties_SetValues(This,pszObjectID,pValues,ppResults)	\
    ( (This)->lpVtbl -> SetValues(This,pszObjectID,pValues,ppResults) ) 

#define IPortableDeviceProperties_Delete(This,pszObjectID,pKeys)	\
    ( (This)->lpVtbl -> Delete(This,pszObjectID,pKeys) ) 

#define IPortableDeviceProperties_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceProperties_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceResources_INTERFACE_DEFINED__
#define __IPortableDeviceResources_INTERFACE_DEFINED__

/* interface IPortableDeviceResources */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceResources;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fd8878ac-d841-4d17-891c-e6829cdb6934")
    IPortableDeviceResources : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedResources( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceAttributes( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResourceAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [in] */ const DWORD dwMode,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalBufferSize,
            /* [out] */ __RPC__deref_out_opt IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateResource( 
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pResourceAttributes,
            /* [out] */ __RPC__deref_out_opt IStream **ppData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalWriteBufferSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceResourcesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceResources * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedResources )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceAttributes )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppResourceAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [in] */ const DWORD dwMode,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalBufferSize,
            /* [out] */ __RPC__deref_out_opt IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in LPCWSTR pszObjectID,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDeviceResources * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateResource )( 
            IPortableDeviceResources * This,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pResourceAttributes,
            /* [out] */ __RPC__deref_out_opt IStream **ppData,
            /* [unique][out][in] */ __RPC__inout_opt DWORD *pdwOptimalWriteBufferSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt LPWSTR *ppszCookie);
        
        END_INTERFACE
    } IPortableDeviceResourcesVtbl;

    interface IPortableDeviceResources
    {
        CONST_VTBL struct IPortableDeviceResourcesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceResources_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceResources_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceResources_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceResources_GetSupportedResources(This,pszObjectID,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedResources(This,pszObjectID,ppKeys) ) 

#define IPortableDeviceResources_GetResourceAttributes(This,pszObjectID,Key,ppResourceAttributes)	\
    ( (This)->lpVtbl -> GetResourceAttributes(This,pszObjectID,Key,ppResourceAttributes) ) 

#define IPortableDeviceResources_GetStream(This,pszObjectID,Key,dwMode,pdwOptimalBufferSize,ppStream)	\
    ( (This)->lpVtbl -> GetStream(This,pszObjectID,Key,dwMode,pdwOptimalBufferSize,ppStream) ) 

#define IPortableDeviceResources_Delete(This,pszObjectID,pKeys)	\
    ( (This)->lpVtbl -> Delete(This,pszObjectID,pKeys) ) 

#define IPortableDeviceResources_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceResources_CreateResource(This,pResourceAttributes,ppData,pdwOptimalWriteBufferSize,ppszCookie)	\
    ( (This)->lpVtbl -> CreateResource(This,pResourceAttributes,ppData,pdwOptimalWriteBufferSize,ppszCookie) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceResources_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceCapabilities_INTERFACE_DEFINED__
#define __IPortableDeviceCapabilities_INTERFACE_DEFINED__

/* interface IPortableDeviceCapabilities */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceCapabilities;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2c8c6dbf-e3dc-4061-becc-8542e810d126")
    IPortableDeviceCapabilities : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedCommands( 
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppCommands) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandOptions( 
            /* [in] */ __RPC__in REFPROPERTYKEY Command,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFunctionalCategories( 
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppCategories) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFunctionalObjects( 
            /* [in] */ __RPC__in REFGUID Category,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppObjectIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedContentTypes( 
            /* [in] */ __RPC__in REFGUID Category,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppContentTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormats( 
            /* [in] */ __RPC__in REFGUID ContentType,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppFormats) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedFormatProperties( 
            /* [in] */ __RPC__in REFGUID Format,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFixedPropertyAttributes( 
            /* [in] */ __RPC__in REFGUID Format,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedEvents( 
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventOptions( 
            /* [in] */ __RPC__in REFGUID Event,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceCapabilitiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceCapabilities * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedCommands )( 
            IPortableDeviceCapabilities * This,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppCommands);
        
        HRESULT ( STDMETHODCALLTYPE *GetCommandOptions )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFPROPERTYKEY Command,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppOptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetFunctionalCategories )( 
            IPortableDeviceCapabilities * This,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppCategories);
        
        HRESULT ( STDMETHODCALLTYPE *GetFunctionalObjects )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID Category,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppObjectIDs);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedContentTypes )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID Category,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppContentTypes);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormats )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID ContentType,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppFormats);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedFormatProperties )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID Format,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceKeyCollection **ppKeys);
        
        HRESULT ( STDMETHODCALLTYPE *GetFixedPropertyAttributes )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID Format,
            /* [in] */ __RPC__in REFPROPERTYKEY Key,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDeviceCapabilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedEvents )( 
            IPortableDeviceCapabilities * This,
            /* [out] */ __RPC__deref_out_opt IPortableDevicePropVariantCollection **ppEvents);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventOptions )( 
            IPortableDeviceCapabilities * This,
            /* [in] */ __RPC__in REFGUID Event,
            /* [out] */ __RPC__deref_out_opt IPortableDeviceValues **ppOptions);
        
        END_INTERFACE
    } IPortableDeviceCapabilitiesVtbl;

    interface IPortableDeviceCapabilities
    {
        CONST_VTBL struct IPortableDeviceCapabilitiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceCapabilities_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceCapabilities_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceCapabilities_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceCapabilities_GetSupportedCommands(This,ppCommands)	\
    ( (This)->lpVtbl -> GetSupportedCommands(This,ppCommands) ) 

#define IPortableDeviceCapabilities_GetCommandOptions(This,Command,ppOptions)	\
    ( (This)->lpVtbl -> GetCommandOptions(This,Command,ppOptions) ) 

#define IPortableDeviceCapabilities_GetFunctionalCategories(This,ppCategories)	\
    ( (This)->lpVtbl -> GetFunctionalCategories(This,ppCategories) ) 

#define IPortableDeviceCapabilities_GetFunctionalObjects(This,Category,ppObjectIDs)	\
    ( (This)->lpVtbl -> GetFunctionalObjects(This,Category,ppObjectIDs) ) 

#define IPortableDeviceCapabilities_GetSupportedContentTypes(This,Category,ppContentTypes)	\
    ( (This)->lpVtbl -> GetSupportedContentTypes(This,Category,ppContentTypes) ) 

#define IPortableDeviceCapabilities_GetSupportedFormats(This,ContentType,ppFormats)	\
    ( (This)->lpVtbl -> GetSupportedFormats(This,ContentType,ppFormats) ) 

#define IPortableDeviceCapabilities_GetSupportedFormatProperties(This,Format,ppKeys)	\
    ( (This)->lpVtbl -> GetSupportedFormatProperties(This,Format,ppKeys) ) 

#define IPortableDeviceCapabilities_GetFixedPropertyAttributes(This,Format,Key,ppAttributes)	\
    ( (This)->lpVtbl -> GetFixedPropertyAttributes(This,Format,Key,ppAttributes) ) 

#define IPortableDeviceCapabilities_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IPortableDeviceCapabilities_GetSupportedEvents(This,ppEvents)	\
    ( (This)->lpVtbl -> GetSupportedEvents(This,ppEvents) ) 

#define IPortableDeviceCapabilities_GetEventOptions(This,Event,ppOptions)	\
    ( (This)->lpVtbl -> GetEventOptions(This,Event,ppOptions) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceCapabilities_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceEventCallback_INTERFACE_DEFINED__
#define __IPortableDeviceEventCallback_INTERFACE_DEFINED__

/* interface IPortableDeviceEventCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceEventCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a8792a31-f385-493c-a893-40f64eb45f6e")
    IPortableDeviceEventCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnEvent( 
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pEventParameters) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceEventCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceEventCallback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceEventCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceEventCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnEvent )( 
            IPortableDeviceEventCallback * This,
            /* [in] */ __RPC__in_opt IPortableDeviceValues *pEventParameters);
        
        END_INTERFACE
    } IPortableDeviceEventCallbackVtbl;

    interface IPortableDeviceEventCallback
    {
        CONST_VTBL struct IPortableDeviceEventCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceEventCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceEventCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceEventCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceEventCallback_OnEvent(This,pEventParameters)	\
    ( (This)->lpVtbl -> OnEvent(This,pEventParameters) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceEventCallback_INTERFACE_DEFINED__ */


#ifndef __IPortableDeviceDataStream_INTERFACE_DEFINED__
#define __IPortableDeviceDataStream_INTERFACE_DEFINED__

/* interface IPortableDeviceDataStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDeviceDataStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88e04db3-1012-4d64-9996-f703a950d3f4")
    IPortableDeviceDataStream : public IStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectID( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDeviceDataStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDeviceDataStream * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDeviceDataStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDeviceDataStream * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IPortableDeviceDataStream * This,
            /* [length_is][size_is][out] */ void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbRead);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IPortableDeviceDataStream * This,
            /* [size_is][in] */ const void *pv,
            /* [in] */ ULONG cb,
            /* [out] */ ULONG *pcbWritten);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IPortableDeviceDataStream * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ DWORD dwOrigin,
            /* [out] */ ULARGE_INTEGER *plibNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            IPortableDeviceDataStream * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IPortableDeviceDataStream * This,
            /* [unique][in] */ IStream *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [out] */ ULARGE_INTEGER *pcbRead,
            /* [out] */ ULARGE_INTEGER *pcbWritten);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IPortableDeviceDataStream * This,
            /* [in] */ DWORD grfCommitFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Revert )( 
            IPortableDeviceDataStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *LockRegion )( 
            IPortableDeviceDataStream * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockRegion )( 
            IPortableDeviceDataStream * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ DWORD dwLockType);
        
        HRESULT ( STDMETHODCALLTYPE *Stat )( 
            IPortableDeviceDataStream * This,
            /* [out] */ __RPC__out STATSTG *pstatstg,
            /* [in] */ DWORD grfStatFlag);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IPortableDeviceDataStream * This,
            /* [out] */ __RPC__deref_out_opt IStream **ppstm);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectID )( 
            IPortableDeviceDataStream * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDeviceDataStream * This);
        
        END_INTERFACE
    } IPortableDeviceDataStreamVtbl;

    interface IPortableDeviceDataStream
    {
        CONST_VTBL struct IPortableDeviceDataStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDeviceDataStream_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDeviceDataStream_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDeviceDataStream_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDeviceDataStream_Read(This,pv,cb,pcbRead)	\
    ( (This)->lpVtbl -> Read(This,pv,cb,pcbRead) ) 

#define IPortableDeviceDataStream_Write(This,pv,cb,pcbWritten)	\
    ( (This)->lpVtbl -> Write(This,pv,cb,pcbWritten) ) 


#define IPortableDeviceDataStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    ( (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition) ) 

#define IPortableDeviceDataStream_SetSize(This,libNewSize)	\
    ( (This)->lpVtbl -> SetSize(This,libNewSize) ) 

#define IPortableDeviceDataStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    ( (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten) ) 

#define IPortableDeviceDataStream_Commit(This,grfCommitFlags)	\
    ( (This)->lpVtbl -> Commit(This,grfCommitFlags) ) 

#define IPortableDeviceDataStream_Revert(This)	\
    ( (This)->lpVtbl -> Revert(This) ) 

#define IPortableDeviceDataStream_LockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType) ) 

#define IPortableDeviceDataStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    ( (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType) ) 

#define IPortableDeviceDataStream_Stat(This,pstatstg,grfStatFlag)	\
    ( (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag) ) 

#define IPortableDeviceDataStream_Clone(This,ppstm)	\
    ( (This)->lpVtbl -> Clone(This,ppstm) ) 


#define IPortableDeviceDataStream_GetObjectID(This,ppszObjectID)	\
    ( (This)->lpVtbl -> GetObjectID(This,ppszObjectID) ) 

#define IPortableDeviceDataStream_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDeviceDataStream_INTERFACE_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__
#define __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__

/* interface IPortableDevicePropertiesBulk */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevicePropertiesBulk;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("482b05c0-4056-44ed-9e0f-5e23b009da93")
    IPortableDevicePropertiesBulk : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueueGetValuesByObjectList( 
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueGetValuesByObjectFormat( 
            /* [in] */ __RPC__in REFGUID pguidObjectFormat,
            /* [in] */ __RPC__in LPCWSTR pszParentObjectID,
            /* [in] */ const DWORD dwDepth,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueueSetValuesByObjectList( 
            /* [in] */ __RPC__in_opt IPortableDeviceValuesCollection *pObjectValues,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [in] */ __RPC__in REFGUID pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [in] */ __RPC__in REFGUID pContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesBulkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDevicePropertiesBulk * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDevicePropertiesBulk * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueueGetValuesByObjectList )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in_opt IPortableDevicePropVariantCollection *pObjectIDs,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *QueueGetValuesByObjectFormat )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in REFGUID pguidObjectFormat,
            /* [in] */ __RPC__in LPCWSTR pszParentObjectID,
            /* [in] */ const DWORD dwDepth,
            /* [in] */ __RPC__in_opt IPortableDeviceKeyCollection *pKeys,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *QueueSetValuesByObjectList )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in_opt IPortableDeviceValuesCollection *pObjectValues,
            /* [in] */ __RPC__in_opt IPortableDevicePropertiesBulkCallback *pCallback,
            /* [out] */ __RPC__out GUID *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in REFGUID pContext);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IPortableDevicePropertiesBulk * This,
            /* [in] */ __RPC__in REFGUID pContext);
        
        END_INTERFACE
    } IPortableDevicePropertiesBulkVtbl;

    interface IPortableDevicePropertiesBulk
    {
        CONST_VTBL struct IPortableDevicePropertiesBulkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevicePropertiesBulk_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevicePropertiesBulk_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevicePropertiesBulk_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevicePropertiesBulk_QueueGetValuesByObjectList(This,pObjectIDs,pKeys,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueGetValuesByObjectList(This,pObjectIDs,pKeys,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_QueueGetValuesByObjectFormat(This,pguidObjectFormat,pszParentObjectID,dwDepth,pKeys,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueGetValuesByObjectFormat(This,pguidObjectFormat,pszParentObjectID,dwDepth,pKeys,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_QueueSetValuesByObjectList(This,pObjectValues,pCallback,pContext)	\
    ( (This)->lpVtbl -> QueueSetValuesByObjectList(This,pObjectValues,pCallback,pContext) ) 

#define IPortableDevicePropertiesBulk_Start(This,pContext)	\
    ( (This)->lpVtbl -> Start(This,pContext) ) 

#define IPortableDevicePropertiesBulk_Cancel(This,pContext)	\
    ( (This)->lpVtbl -> Cancel(This,pContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__ */


#ifndef __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__
#define __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__

/* interface IPortableDevicePropertiesBulkCallback */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IPortableDevicePropertiesBulkCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9deacb80-11e8-40e3-a9f3-f557986a7845")
    IPortableDevicePropertiesBulkCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStart( 
            /* [in] */ __RPC__in REFGUID pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnProgress( 
            /* [in] */ __RPC__in REFGUID pContext,
            /* [in] */ __RPC__in_opt IPortableDeviceValuesCollection *pResults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEnd( 
            /* [in] */ __RPC__in REFGUID pContext,
            /* [in] */ HRESULT hrStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPortableDevicePropertiesBulkCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPortableDevicePropertiesBulkCallback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPortableDevicePropertiesBulkCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPortableDevicePropertiesBulkCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnStart )( 
            IPortableDevicePropertiesBulkCallback * This,
            /* [in] */ __RPC__in REFGUID pContext);
        
        HRESULT ( STDMETHODCALLTYPE *OnProgress )( 
            IPortableDevicePropertiesBulkCallback * This,
            /* [in] */ __RPC__in REFGUID pContext,
            /* [in] */ __RPC__in_opt IPortableDeviceValuesCollection *pResults);
        
        HRESULT ( STDMETHODCALLTYPE *OnEnd )( 
            IPortableDevicePropertiesBulkCallback * This,
            /* [in] */ __RPC__in REFGUID pContext,
            /* [in] */ HRESULT hrStatus);
        
        END_INTERFACE
    } IPortableDevicePropertiesBulkCallbackVtbl;

    interface IPortableDevicePropertiesBulkCallback
    {
        CONST_VTBL struct IPortableDevicePropertiesBulkCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPortableDevicePropertiesBulkCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPortableDevicePropertiesBulkCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPortableDevicePropertiesBulkCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPortableDevicePropertiesBulkCallback_OnStart(This,pContext)	\
    ( (This)->lpVtbl -> OnStart(This,pContext) ) 

#define IPortableDevicePropertiesBulkCallback_OnProgress(This,pContext,pResults)	\
    ( (This)->lpVtbl -> OnProgress(This,pContext,pResults) ) 

#define IPortableDevicePropertiesBulkCallback_OnEnd(This,pContext,hrStatus)	\
    ( (This)->lpVtbl -> OnEnd(This,pContext,hrStatus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__ */



#ifndef __PortableDeviceApiLib_LIBRARY_DEFINED__
#define __PortableDeviceApiLib_LIBRARY_DEFINED__

/* library PortableDeviceApiLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PortableDeviceApiLib;

EXTERN_C const CLSID CLSID_PortableDevice;

#ifdef __cplusplus

class DECLSPEC_UUID("728a21c5-3d9e-48d7-9810-864848f0f404")
PortableDevice;
#endif

EXTERN_C const CLSID CLSID_PortableDeviceManager;

#ifdef __cplusplus

class DECLSPEC_UUID("0af10cec-2ecd-4b92-9581-34f6ae0637f3")
PortableDeviceManager;
#endif
#endif /* __PortableDeviceApiLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_PortableDeviceApi_0000_0011 */
/* [local] */ 

#endif  // (_WIN32_WINNT >= 0x0501)


extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceApi_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PortableDeviceApi_0000_0011_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



