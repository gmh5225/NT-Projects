

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for ahadmin.idl:
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

#ifndef __ahadmin_h__
#define __ahadmin_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAppHostMappingExtension_FWD_DEFINED__
#define __IAppHostMappingExtension_FWD_DEFINED__
typedef interface IAppHostMappingExtension IAppHostMappingExtension;
#endif 	/* __IAppHostMappingExtension_FWD_DEFINED__ */


#ifndef __IAppHostChildElementCollection_FWD_DEFINED__
#define __IAppHostChildElementCollection_FWD_DEFINED__
typedef interface IAppHostChildElementCollection IAppHostChildElementCollection;
#endif 	/* __IAppHostChildElementCollection_FWD_DEFINED__ */


#ifndef __IAppHostPropertyCollection_FWD_DEFINED__
#define __IAppHostPropertyCollection_FWD_DEFINED__
typedef interface IAppHostPropertyCollection IAppHostPropertyCollection;
#endif 	/* __IAppHostPropertyCollection_FWD_DEFINED__ */


#ifndef __IAppHostConfigLocationCollection_FWD_DEFINED__
#define __IAppHostConfigLocationCollection_FWD_DEFINED__
typedef interface IAppHostConfigLocationCollection IAppHostConfigLocationCollection;
#endif 	/* __IAppHostConfigLocationCollection_FWD_DEFINED__ */


#ifndef __IAppHostPropertySchema_FWD_DEFINED__
#define __IAppHostPropertySchema_FWD_DEFINED__
typedef interface IAppHostPropertySchema IAppHostPropertySchema;
#endif 	/* __IAppHostPropertySchema_FWD_DEFINED__ */


#ifndef __IAppHostCollectionSchema_FWD_DEFINED__
#define __IAppHostCollectionSchema_FWD_DEFINED__
typedef interface IAppHostCollectionSchema IAppHostCollectionSchema;
#endif 	/* __IAppHostCollectionSchema_FWD_DEFINED__ */


#ifndef __IAppHostElementSchema_FWD_DEFINED__
#define __IAppHostElementSchema_FWD_DEFINED__
typedef interface IAppHostElementSchema IAppHostElementSchema;
#endif 	/* __IAppHostElementSchema_FWD_DEFINED__ */


#ifndef __IAppHostConfigException_FWD_DEFINED__
#define __IAppHostConfigException_FWD_DEFINED__
typedef interface IAppHostConfigException IAppHostConfigException;
#endif 	/* __IAppHostConfigException_FWD_DEFINED__ */


#ifndef __IAppHostPropertyException_FWD_DEFINED__
#define __IAppHostPropertyException_FWD_DEFINED__
typedef interface IAppHostPropertyException IAppHostPropertyException;
#endif 	/* __IAppHostPropertyException_FWD_DEFINED__ */


#ifndef __IAppHostElementCollection_FWD_DEFINED__
#define __IAppHostElementCollection_FWD_DEFINED__
typedef interface IAppHostElementCollection IAppHostElementCollection;
#endif 	/* __IAppHostElementCollection_FWD_DEFINED__ */


#ifndef __IAppHostElement_FWD_DEFINED__
#define __IAppHostElement_FWD_DEFINED__
typedef interface IAppHostElement IAppHostElement;
#endif 	/* __IAppHostElement_FWD_DEFINED__ */


#ifndef __IAppHostProperty_FWD_DEFINED__
#define __IAppHostProperty_FWD_DEFINED__
typedef interface IAppHostProperty IAppHostProperty;
#endif 	/* __IAppHostProperty_FWD_DEFINED__ */


#ifndef __IAppHostConfigLocation_FWD_DEFINED__
#define __IAppHostConfigLocation_FWD_DEFINED__
typedef interface IAppHostConfigLocation IAppHostConfigLocation;
#endif 	/* __IAppHostConfigLocation_FWD_DEFINED__ */


#ifndef __IAppHostSectionDefinition_FWD_DEFINED__
#define __IAppHostSectionDefinition_FWD_DEFINED__
typedef interface IAppHostSectionDefinition IAppHostSectionDefinition;
#endif 	/* __IAppHostSectionDefinition_FWD_DEFINED__ */


#ifndef __IAppHostSectionDefinitionCollection_FWD_DEFINED__
#define __IAppHostSectionDefinitionCollection_FWD_DEFINED__
typedef interface IAppHostSectionDefinitionCollection IAppHostSectionDefinitionCollection;
#endif 	/* __IAppHostSectionDefinitionCollection_FWD_DEFINED__ */


#ifndef __IAppHostSectionGroup_FWD_DEFINED__
#define __IAppHostSectionGroup_FWD_DEFINED__
typedef interface IAppHostSectionGroup IAppHostSectionGroup;
#endif 	/* __IAppHostSectionGroup_FWD_DEFINED__ */


#ifndef __IAppHostConfigFile_FWD_DEFINED__
#define __IAppHostConfigFile_FWD_DEFINED__
typedef interface IAppHostConfigFile IAppHostConfigFile;
#endif 	/* __IAppHostConfigFile_FWD_DEFINED__ */


#ifndef __IAppHostPathMapper_FWD_DEFINED__
#define __IAppHostPathMapper_FWD_DEFINED__
typedef interface IAppHostPathMapper IAppHostPathMapper;
#endif 	/* __IAppHostPathMapper_FWD_DEFINED__ */


#ifndef __IAppHostChangeHandler_FWD_DEFINED__
#define __IAppHostChangeHandler_FWD_DEFINED__
typedef interface IAppHostChangeHandler IAppHostChangeHandler;
#endif 	/* __IAppHostChangeHandler_FWD_DEFINED__ */


#ifndef __IAppHostAdminManager_FWD_DEFINED__
#define __IAppHostAdminManager_FWD_DEFINED__
typedef interface IAppHostAdminManager IAppHostAdminManager;
#endif 	/* __IAppHostAdminManager_FWD_DEFINED__ */


#ifndef __IAppHostWritableAdminManager_FWD_DEFINED__
#define __IAppHostWritableAdminManager_FWD_DEFINED__
typedef interface IAppHostWritableAdminManager IAppHostWritableAdminManager;
#endif 	/* __IAppHostWritableAdminManager_FWD_DEFINED__ */


#ifndef __IAppHostConfigManager_FWD_DEFINED__
#define __IAppHostConfigManager_FWD_DEFINED__
typedef interface IAppHostConfigManager IAppHostConfigManager;
#endif 	/* __IAppHostConfigManager_FWD_DEFINED__ */


#ifndef __AppHostAdminManager_FWD_DEFINED__
#define __AppHostAdminManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class AppHostAdminManager AppHostAdminManager;
#else
typedef struct AppHostAdminManager AppHostAdminManager;
#endif /* __cplusplus */

#endif 	/* __AppHostAdminManager_FWD_DEFINED__ */


#ifndef __AppHostWritableAdminManager_FWD_DEFINED__
#define __AppHostWritableAdminManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class AppHostWritableAdminManager AppHostWritableAdminManager;
#else
typedef struct AppHostWritableAdminManager AppHostWritableAdminManager;
#endif /* __cplusplus */

#endif 	/* __AppHostWritableAdminManager_FWD_DEFINED__ */


#ifndef __IAppHostConfigException_FWD_DEFINED__
#define __IAppHostConfigException_FWD_DEFINED__
typedef interface IAppHostConfigException IAppHostConfigException;
#endif 	/* __IAppHostConfigException_FWD_DEFINED__ */


#ifndef __IAppHostPropertyException_FWD_DEFINED__
#define __IAppHostPropertyException_FWD_DEFINED__
typedef interface IAppHostPropertyException IAppHostPropertyException;
#endif 	/* __IAppHostPropertyException_FWD_DEFINED__ */


#ifndef __IAppHostMappingExtension_FWD_DEFINED__
#define __IAppHostMappingExtension_FWD_DEFINED__
typedef interface IAppHostMappingExtension IAppHostMappingExtension;
#endif 	/* __IAppHostMappingExtension_FWD_DEFINED__ */


#ifndef __IAppHostPathMapper_FWD_DEFINED__
#define __IAppHostPathMapper_FWD_DEFINED__
typedef interface IAppHostPathMapper IAppHostPathMapper;
#endif 	/* __IAppHostPathMapper_FWD_DEFINED__ */


#ifndef __IAppHostChangeHandler_FWD_DEFINED__
#define __IAppHostChangeHandler_FWD_DEFINED__
typedef interface IAppHostChangeHandler IAppHostChangeHandler;
#endif 	/* __IAppHostChangeHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ahadmin_0000_0000 */
/* [local] */ 



















extern RPC_IF_HANDLE __MIDL_itf_ahadmin_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ahadmin_0000_0000_v0_0_s_ifspec;

#ifndef __IAppHostMappingExtension_INTERFACE_DEFINED__
#define __IAppHostMappingExtension_INTERFACE_DEFINED__

/* interface IAppHostMappingExtension */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostMappingExtension;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31a83ea0-c0e4-4a2c-8a01-353cc2a4c60a")
    IAppHostMappingExtension : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSiteNameFromSiteId( 
            /* [in] */ DWORD dwSiteId,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrSiteName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSiteIdFromSiteName( 
            /* [string][in] */ __RPC__in BSTR bstrSiteName,
            /* [retval][out] */ __RPC__out DWORD *pdwSiteId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSiteElementFromSiteId( 
            /* [in] */ DWORD dwSiteId,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppSiteElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapPath( 
            /* [string][in] */ __RPC__in BSTR bstrSiteName,
            /* [string][in] */ __RPC__in BSTR bstrVirtualPath,
            /* [string][out] */ __RPC__deref_out_opt_string BSTR *pbstrPhysicalPath,
            /* [out] */ __RPC__deref_out_opt IAppHostElement **ppVirtualDirectoryElement,
            /* [out] */ __RPC__deref_out_opt IAppHostElement **ppApplicationElement) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostMappingExtensionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostMappingExtension * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostMappingExtension * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostMappingExtension * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSiteNameFromSiteId )( 
            IAppHostMappingExtension * This,
            /* [in] */ DWORD dwSiteId,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrSiteName);
        
        HRESULT ( STDMETHODCALLTYPE *GetSiteIdFromSiteName )( 
            IAppHostMappingExtension * This,
            /* [string][in] */ __RPC__in BSTR bstrSiteName,
            /* [retval][out] */ __RPC__out DWORD *pdwSiteId);
        
        HRESULT ( STDMETHODCALLTYPE *GetSiteElementFromSiteId )( 
            IAppHostMappingExtension * This,
            /* [in] */ DWORD dwSiteId,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppSiteElement);
        
        HRESULT ( STDMETHODCALLTYPE *MapPath )( 
            IAppHostMappingExtension * This,
            /* [string][in] */ __RPC__in BSTR bstrSiteName,
            /* [string][in] */ __RPC__in BSTR bstrVirtualPath,
            /* [string][out] */ __RPC__deref_out_opt_string BSTR *pbstrPhysicalPath,
            /* [out] */ __RPC__deref_out_opt IAppHostElement **ppVirtualDirectoryElement,
            /* [out] */ __RPC__deref_out_opt IAppHostElement **ppApplicationElement);
        
        END_INTERFACE
    } IAppHostMappingExtensionVtbl;

    interface IAppHostMappingExtension
    {
        CONST_VTBL struct IAppHostMappingExtensionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostMappingExtension_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostMappingExtension_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostMappingExtension_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostMappingExtension_GetSiteNameFromSiteId(This,dwSiteId,pbstrSiteName)	\
    ( (This)->lpVtbl -> GetSiteNameFromSiteId(This,dwSiteId,pbstrSiteName) ) 

#define IAppHostMappingExtension_GetSiteIdFromSiteName(This,bstrSiteName,pdwSiteId)	\
    ( (This)->lpVtbl -> GetSiteIdFromSiteName(This,bstrSiteName,pdwSiteId) ) 

#define IAppHostMappingExtension_GetSiteElementFromSiteId(This,dwSiteId,ppSiteElement)	\
    ( (This)->lpVtbl -> GetSiteElementFromSiteId(This,dwSiteId,ppSiteElement) ) 

#define IAppHostMappingExtension_MapPath(This,bstrSiteName,bstrVirtualPath,pbstrPhysicalPath,ppVirtualDirectoryElement,ppApplicationElement)	\
    ( (This)->lpVtbl -> MapPath(This,bstrSiteName,bstrVirtualPath,pbstrPhysicalPath,ppVirtualDirectoryElement,ppApplicationElement) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostMappingExtension_INTERFACE_DEFINED__ */


#ifndef __IAppHostChildElementCollection_INTERFACE_DEFINED__
#define __IAppHostChildElementCollection_INTERFACE_DEFINED__

/* interface IAppHostChildElementCollection */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostChildElementCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08a90f5f-0702-48d6-b45f-02a9885a9768")
    IAppHostChildElementCollection : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out DWORD *pcCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostChildElementCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostChildElementCollection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostChildElementCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostChildElementCollection * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostChildElementCollection * This,
            /* [retval][out] */ __RPC__out DWORD *pcCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostChildElementCollection * This,
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement);
        
        END_INTERFACE
    } IAppHostChildElementCollectionVtbl;

    interface IAppHostChildElementCollection
    {
        CONST_VTBL struct IAppHostChildElementCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostChildElementCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostChildElementCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostChildElementCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostChildElementCollection_get_Count(This,pcCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcCount) ) 

#define IAppHostChildElementCollection_get_Item(This,cIndex,ppElement)	\
    ( (This)->lpVtbl -> get_Item(This,cIndex,ppElement) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostChildElementCollection_INTERFACE_DEFINED__ */


#ifndef __IAppHostPropertyCollection_INTERFACE_DEFINED__
#define __IAppHostPropertyCollection_INTERFACE_DEFINED__

/* interface IAppHostPropertyCollection */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostPropertyCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0191775e-bcff-445a-b4f4-3bdda54e2816")
    IAppHostPropertyCollection : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out DWORD *pcCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostProperty **ppProperty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostPropertyCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostPropertyCollection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostPropertyCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostPropertyCollection * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostPropertyCollection * This,
            /* [retval][out] */ __RPC__out DWORD *pcCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostPropertyCollection * This,
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostProperty **ppProperty);
        
        END_INTERFACE
    } IAppHostPropertyCollectionVtbl;

    interface IAppHostPropertyCollection
    {
        CONST_VTBL struct IAppHostPropertyCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostPropertyCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostPropertyCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostPropertyCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostPropertyCollection_get_Count(This,pcCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcCount) ) 

#define IAppHostPropertyCollection_get_Item(This,cIndex,ppProperty)	\
    ( (This)->lpVtbl -> get_Item(This,cIndex,ppProperty) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostPropertyCollection_INTERFACE_DEFINED__ */


#ifndef __IAppHostConfigLocationCollection_INTERFACE_DEFINED__
#define __IAppHostConfigLocationCollection_INTERFACE_DEFINED__

/* interface IAppHostConfigLocationCollection */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostConfigLocationCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("832a32f7-b3ea-4b8c-b260-9a2923001184")
    IAppHostConfigLocationCollection : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out DWORD *pcCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocation **ppLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddLocation( 
            /* [string][in] */ __RPC__in BSTR bstrLocationPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocation **ppNewLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteLocation( 
            /* [in] */ VARIANT cIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostConfigLocationCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostConfigLocationCollection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostConfigLocationCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostConfigLocationCollection * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostConfigLocationCollection * This,
            /* [retval][out] */ __RPC__out DWORD *pcCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostConfigLocationCollection * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocation **ppLocation);
        
        HRESULT ( STDMETHODCALLTYPE *AddLocation )( 
            IAppHostConfigLocationCollection * This,
            /* [string][in] */ __RPC__in BSTR bstrLocationPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocation **ppNewLocation);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteLocation )( 
            IAppHostConfigLocationCollection * This,
            /* [in] */ VARIANT cIndex);
        
        END_INTERFACE
    } IAppHostConfigLocationCollectionVtbl;

    interface IAppHostConfigLocationCollection
    {
        CONST_VTBL struct IAppHostConfigLocationCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostConfigLocationCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostConfigLocationCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostConfigLocationCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostConfigLocationCollection_get_Count(This,pcCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcCount) ) 

#define IAppHostConfigLocationCollection_get_Item(This,varIndex,ppLocation)	\
    ( (This)->lpVtbl -> get_Item(This,varIndex,ppLocation) ) 

#define IAppHostConfigLocationCollection_AddLocation(This,bstrLocationPath,ppNewLocation)	\
    ( (This)->lpVtbl -> AddLocation(This,bstrLocationPath,ppNewLocation) ) 

#define IAppHostConfigLocationCollection_DeleteLocation(This,cIndex)	\
    ( (This)->lpVtbl -> DeleteLocation(This,cIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostConfigLocationCollection_INTERFACE_DEFINED__ */


#ifndef __IAppHostPropertySchema_INTERFACE_DEFINED__
#define __IAppHostPropertySchema_INTERFACE_DEFINED__

/* interface IAppHostPropertySchema */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostPropertySchema;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("450386db-7409-4667-935e-384dbbee2a9e")
    IAppHostPropertySchema : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DefaultValue( 
            /* [retval][out] */ __RPC__out VARIANT *pDefaultValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsRequired( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsRequired) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsUniqueKey( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsUniqueKey) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsCombinedKey( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsCombinedKey) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsExpanded( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsExpanded) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ValidationType( 
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ValidationParameter( 
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationParameter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsCaseSensitive( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsCaseSensitive) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostPropertySchemaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostPropertySchema * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostPropertySchema * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostPropertySchema * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostPropertySchema * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAppHostPropertySchema * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT *pDefaultValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsRequired )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsRequired);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsUniqueKey )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsUniqueKey);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsCombinedKey )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsCombinedKey);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsExpanded )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsExpanded);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValidationType )( 
            IAppHostPropertySchema * This,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValidationParameter )( 
            IAppHostPropertySchema * This,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationParameter);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostPropertySchema * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsCaseSensitive )( 
            IAppHostPropertySchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsCaseSensitive);
        
        END_INTERFACE
    } IAppHostPropertySchemaVtbl;

    interface IAppHostPropertySchema
    {
        CONST_VTBL struct IAppHostPropertySchemaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostPropertySchema_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostPropertySchema_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostPropertySchema_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostPropertySchema_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostPropertySchema_get_Type(This,pbstrType)	\
    ( (This)->lpVtbl -> get_Type(This,pbstrType) ) 

#define IAppHostPropertySchema_get_DefaultValue(This,pDefaultValue)	\
    ( (This)->lpVtbl -> get_DefaultValue(This,pDefaultValue) ) 

#define IAppHostPropertySchema_get_IsRequired(This,pfIsRequired)	\
    ( (This)->lpVtbl -> get_IsRequired(This,pfIsRequired) ) 

#define IAppHostPropertySchema_get_IsUniqueKey(This,pfIsUniqueKey)	\
    ( (This)->lpVtbl -> get_IsUniqueKey(This,pfIsUniqueKey) ) 

#define IAppHostPropertySchema_get_IsCombinedKey(This,pfIsCombinedKey)	\
    ( (This)->lpVtbl -> get_IsCombinedKey(This,pfIsCombinedKey) ) 

#define IAppHostPropertySchema_get_IsExpanded(This,pfIsExpanded)	\
    ( (This)->lpVtbl -> get_IsExpanded(This,pfIsExpanded) ) 

#define IAppHostPropertySchema_get_ValidationType(This,pbstrValidationType)	\
    ( (This)->lpVtbl -> get_ValidationType(This,pbstrValidationType) ) 

#define IAppHostPropertySchema_get_ValidationParameter(This,pbstrValidationParameter)	\
    ( (This)->lpVtbl -> get_ValidationParameter(This,pbstrValidationParameter) ) 

#define IAppHostPropertySchema_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostPropertySchema_get_IsCaseSensitive(This,pfIsCaseSensitive)	\
    ( (This)->lpVtbl -> get_IsCaseSensitive(This,pfIsCaseSensitive) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostPropertySchema_INTERFACE_DEFINED__ */


#ifndef __IAppHostCollectionSchema_INTERFACE_DEFINED__
#define __IAppHostCollectionSchema_INTERFACE_DEFINED__

/* interface IAppHostCollectionSchema */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostCollectionSchema;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("de095db1-5368-4d11-81f6-efef619b7bcf")
    IAppHostCollectionSchema : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AddElementNames( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrElementName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAddElementSchema( 
            /* [string][in] */ __RPC__in BSTR bstrElementName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RemoveElementSchema( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ClearElementSchema( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsMergeAppend( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsMergeAppend) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DoesAllowDuplicates( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfAllowDuplicates) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostCollectionSchemaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostCollectionSchema * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostCollectionSchema * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostCollectionSchema * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddElementNames )( 
            IAppHostCollectionSchema * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrElementName);
        
        HRESULT ( STDMETHODCALLTYPE *GetAddElementSchema )( 
            IAppHostCollectionSchema * This,
            /* [string][in] */ __RPC__in BSTR bstrElementName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveElementSchema )( 
            IAppHostCollectionSchema * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClearElementSchema )( 
            IAppHostCollectionSchema * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsMergeAppend )( 
            IAppHostCollectionSchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfIsMergeAppend);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostCollectionSchema * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoesAllowDuplicates )( 
            IAppHostCollectionSchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfAllowDuplicates);
        
        END_INTERFACE
    } IAppHostCollectionSchemaVtbl;

    interface IAppHostCollectionSchema
    {
        CONST_VTBL struct IAppHostCollectionSchemaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostCollectionSchema_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostCollectionSchema_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostCollectionSchema_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostCollectionSchema_get_AddElementNames(This,pbstrElementName)	\
    ( (This)->lpVtbl -> get_AddElementNames(This,pbstrElementName) ) 

#define IAppHostCollectionSchema_GetAddElementSchema(This,bstrElementName,ppSchema)	\
    ( (This)->lpVtbl -> GetAddElementSchema(This,bstrElementName,ppSchema) ) 

#define IAppHostCollectionSchema_get_RemoveElementSchema(This,ppSchema)	\
    ( (This)->lpVtbl -> get_RemoveElementSchema(This,ppSchema) ) 

#define IAppHostCollectionSchema_get_ClearElementSchema(This,ppSchema)	\
    ( (This)->lpVtbl -> get_ClearElementSchema(This,ppSchema) ) 

#define IAppHostCollectionSchema_get_IsMergeAppend(This,pfIsMergeAppend)	\
    ( (This)->lpVtbl -> get_IsMergeAppend(This,pfIsMergeAppend) ) 

#define IAppHostCollectionSchema_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostCollectionSchema_get_DoesAllowDuplicates(This,pfAllowDuplicates)	\
    ( (This)->lpVtbl -> get_DoesAllowDuplicates(This,pfAllowDuplicates) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostCollectionSchema_INTERFACE_DEFINED__ */


#ifndef __IAppHostElementSchema_INTERFACE_DEFINED__
#define __IAppHostElementSchema_INTERFACE_DEFINED__

/* interface IAppHostElementSchema */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostElementSchema;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ef13d885-642c-4709-99ec-b89561c6bc69")
    IAppHostElementSchema : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DoesAllowUnschematizedProperties( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfAllowUnschematized) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostElementSchemaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostElementSchema * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostElementSchema * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostElementSchema * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostElementSchema * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoesAllowUnschematizedProperties )( 
            IAppHostElementSchema * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfAllowUnschematized);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostElementSchema * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        END_INTERFACE
    } IAppHostElementSchemaVtbl;

    interface IAppHostElementSchema
    {
        CONST_VTBL struct IAppHostElementSchemaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostElementSchema_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostElementSchema_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostElementSchema_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostElementSchema_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostElementSchema_get_DoesAllowUnschematizedProperties(This,pfAllowUnschematized)	\
    ( (This)->lpVtbl -> get_DoesAllowUnschematizedProperties(This,pfAllowUnschematized) ) 

#define IAppHostElementSchema_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostElementSchema_INTERFACE_DEFINED__ */


#ifndef __IAppHostConfigException_INTERFACE_DEFINED__
#define __IAppHostConfigException_INTERFACE_DEFINED__

/* interface IAppHostConfigException */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostConfigException;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4dfa1df3-8900-4bc7-bbb5-d1a458c52410")
    IAppHostConfigException : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LineNumber( 
            /* [retval][out] */ __RPC__out ULONG *pcLineNumber) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrFileName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ConfigPath( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrConfigPath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ErrorLine( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorLine) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PreErrorLine( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPreErrorLine) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PostErrorLine( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPostErrorLine) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ErrorString( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorString) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostConfigExceptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostConfigException * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostConfigException * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostConfigException * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineNumber )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__out ULONG *pcLineNumber);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrFileName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigPath )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrConfigPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorLine )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreErrorLine )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPreErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostErrorLine )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPostErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorString )( 
            IAppHostConfigException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorString);
        
        END_INTERFACE
    } IAppHostConfigExceptionVtbl;

    interface IAppHostConfigException
    {
        CONST_VTBL struct IAppHostConfigExceptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostConfigException_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostConfigException_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostConfigException_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostConfigException_get_LineNumber(This,pcLineNumber)	\
    ( (This)->lpVtbl -> get_LineNumber(This,pcLineNumber) ) 

#define IAppHostConfigException_get_FileName(This,pbstrFileName)	\
    ( (This)->lpVtbl -> get_FileName(This,pbstrFileName) ) 

#define IAppHostConfigException_get_ConfigPath(This,pbstrConfigPath)	\
    ( (This)->lpVtbl -> get_ConfigPath(This,pbstrConfigPath) ) 

#define IAppHostConfigException_get_ErrorLine(This,pbstrErrorLine)	\
    ( (This)->lpVtbl -> get_ErrorLine(This,pbstrErrorLine) ) 

#define IAppHostConfigException_get_PreErrorLine(This,pbstrPreErrorLine)	\
    ( (This)->lpVtbl -> get_PreErrorLine(This,pbstrPreErrorLine) ) 

#define IAppHostConfigException_get_PostErrorLine(This,pbstrPostErrorLine)	\
    ( (This)->lpVtbl -> get_PostErrorLine(This,pbstrPostErrorLine) ) 

#define IAppHostConfigException_get_ErrorString(This,pbstrErrorString)	\
    ( (This)->lpVtbl -> get_ErrorString(This,pbstrErrorString) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostConfigException_INTERFACE_DEFINED__ */


#ifndef __IAppHostPropertyException_INTERFACE_DEFINED__
#define __IAppHostPropertyException_INTERFACE_DEFINED__

/* interface IAppHostPropertyException */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostPropertyException;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("eafe4895-a929-41ea-b14d-613e23f62b71")
    IAppHostPropertyException : public IAppHostConfigException
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_InvalidValue( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ValidationFailureReason( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationReason) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ValidationFailureParameters( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pParameterArray) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostPropertyExceptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostPropertyException * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostPropertyException * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostPropertyException * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LineNumber )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__out ULONG *pcLineNumber);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrFileName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigPath )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrConfigPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorLine )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreErrorLine )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPreErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostErrorLine )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrPostErrorLine);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorString )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrErrorString);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_InvalidValue )( 
            IAppHostPropertyException * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValidationFailureReason )( 
            IAppHostPropertyException * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrValidationReason);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValidationFailureParameters )( 
            IAppHostPropertyException * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pParameterArray);
        
        END_INTERFACE
    } IAppHostPropertyExceptionVtbl;

    interface IAppHostPropertyException
    {
        CONST_VTBL struct IAppHostPropertyExceptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostPropertyException_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostPropertyException_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostPropertyException_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostPropertyException_get_LineNumber(This,pcLineNumber)	\
    ( (This)->lpVtbl -> get_LineNumber(This,pcLineNumber) ) 

#define IAppHostPropertyException_get_FileName(This,pbstrFileName)	\
    ( (This)->lpVtbl -> get_FileName(This,pbstrFileName) ) 

#define IAppHostPropertyException_get_ConfigPath(This,pbstrConfigPath)	\
    ( (This)->lpVtbl -> get_ConfigPath(This,pbstrConfigPath) ) 

#define IAppHostPropertyException_get_ErrorLine(This,pbstrErrorLine)	\
    ( (This)->lpVtbl -> get_ErrorLine(This,pbstrErrorLine) ) 

#define IAppHostPropertyException_get_PreErrorLine(This,pbstrPreErrorLine)	\
    ( (This)->lpVtbl -> get_PreErrorLine(This,pbstrPreErrorLine) ) 

#define IAppHostPropertyException_get_PostErrorLine(This,pbstrPostErrorLine)	\
    ( (This)->lpVtbl -> get_PostErrorLine(This,pbstrPostErrorLine) ) 

#define IAppHostPropertyException_get_ErrorString(This,pbstrErrorString)	\
    ( (This)->lpVtbl -> get_ErrorString(This,pbstrErrorString) ) 


#define IAppHostPropertyException_get_InvalidValue(This,pbstrValue)	\
    ( (This)->lpVtbl -> get_InvalidValue(This,pbstrValue) ) 

#define IAppHostPropertyException_get_ValidationFailureReason(This,pbstrValidationReason)	\
    ( (This)->lpVtbl -> get_ValidationFailureReason(This,pbstrValidationReason) ) 

#define IAppHostPropertyException_get_ValidationFailureParameters(This,pParameterArray)	\
    ( (This)->lpVtbl -> get_ValidationFailureParameters(This,pParameterArray) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostPropertyException_INTERFACE_DEFINED__ */


#ifndef __IAppHostElementCollection_INTERFACE_DEFINED__
#define __IAppHostElementCollection_INTERFACE_DEFINED__

/* interface IAppHostElementCollection */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostElementCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c8550bff-5281-4b1e-ac34-99b6fa38464d")
    IAppHostElementCollection : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out DWORD *pcElementCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddElement( 
            /* [in] */ __RPC__in_opt IAppHostElement *pElement,
            /* [defaultvalue][in] */ INT cPosition = -1) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteElement( 
            /* [in] */ VARIANT cIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewElement( 
            /* [defaultvalue][string][in] */ __RPC__in BSTR bstrElementName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Schema( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostCollectionSchema **ppSchema) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostElementCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostElementCollection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostElementCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostElementCollection * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostElementCollection * This,
            /* [retval][out] */ __RPC__out DWORD *pcElementCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostElementCollection * This,
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *AddElement )( 
            IAppHostElementCollection * This,
            /* [in] */ __RPC__in_opt IAppHostElement *pElement,
            /* [defaultvalue][in] */ INT cPosition);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteElement )( 
            IAppHostElementCollection * This,
            /* [in] */ VARIANT cIndex);
        
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAppHostElementCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewElement )( 
            IAppHostElementCollection * This,
            /* [defaultvalue][string][in] */ __RPC__in BSTR bstrElementName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Schema )( 
            IAppHostElementCollection * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostCollectionSchema **ppSchema);
        
        END_INTERFACE
    } IAppHostElementCollectionVtbl;

    interface IAppHostElementCollection
    {
        CONST_VTBL struct IAppHostElementCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostElementCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostElementCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostElementCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostElementCollection_get_Count(This,pcElementCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcElementCount) ) 

#define IAppHostElementCollection_get_Item(This,cIndex,ppElement)	\
    ( (This)->lpVtbl -> get_Item(This,cIndex,ppElement) ) 

#define IAppHostElementCollection_AddElement(This,pElement,cPosition)	\
    ( (This)->lpVtbl -> AddElement(This,pElement,cPosition) ) 

#define IAppHostElementCollection_DeleteElement(This,cIndex)	\
    ( (This)->lpVtbl -> DeleteElement(This,cIndex) ) 

#define IAppHostElementCollection_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAppHostElementCollection_CreateNewElement(This,bstrElementName,ppElement)	\
    ( (This)->lpVtbl -> CreateNewElement(This,bstrElementName,ppElement) ) 

#define IAppHostElementCollection_get_Schema(This,ppSchema)	\
    ( (This)->lpVtbl -> get_Schema(This,ppSchema) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostElementCollection_INTERFACE_DEFINED__ */


#ifndef __IAppHostElement_INTERFACE_DEFINED__
#define __IAppHostElement_INTERFACE_DEFINED__

/* interface IAppHostElement */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64ff8ccc-b287-4dae-b08a-a72cbf45f453")
    IAppHostElement : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Collection( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementCollection **ppCollection) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Properties( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertyCollection **ppProperties) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ChildElements( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostChildElementCollection **ppElements) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Schema( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetElementByName( 
            /* [string][in] */ __RPC__in BSTR bstrSubName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyByName( 
            /* [string][in] */ __RPC__in BSTR bstrSubName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostProperty **ppProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostElement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostElement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostElement * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostElement * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Collection )( 
            IAppHostElement * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementCollection **ppCollection);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Properties )( 
            IAppHostElement * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertyCollection **ppProperties);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChildElements )( 
            IAppHostElement * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostChildElementCollection **ppElements);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostElement * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetMetadata )( 
            IAppHostElement * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Schema )( 
            IAppHostElement * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElementSchema **ppSchema);
        
        HRESULT ( STDMETHODCALLTYPE *GetElementByName )( 
            IAppHostElement * This,
            /* [string][in] */ __RPC__in BSTR bstrSubName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyByName )( 
            IAppHostElement * This,
            /* [string][in] */ __RPC__in BSTR bstrSubName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostProperty **ppProperty);
        
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAppHostElement * This);
        
        END_INTERFACE
    } IAppHostElementVtbl;

    interface IAppHostElement
    {
        CONST_VTBL struct IAppHostElementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostElement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostElement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostElement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostElement_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostElement_get_Collection(This,ppCollection)	\
    ( (This)->lpVtbl -> get_Collection(This,ppCollection) ) 

#define IAppHostElement_get_Properties(This,ppProperties)	\
    ( (This)->lpVtbl -> get_Properties(This,ppProperties) ) 

#define IAppHostElement_get_ChildElements(This,ppElements)	\
    ( (This)->lpVtbl -> get_ChildElements(This,ppElements) ) 

#define IAppHostElement_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostElement_SetMetadata(This,bstrMetadataType,value)	\
    ( (This)->lpVtbl -> SetMetadata(This,bstrMetadataType,value) ) 

#define IAppHostElement_get_Schema(This,ppSchema)	\
    ( (This)->lpVtbl -> get_Schema(This,ppSchema) ) 

#define IAppHostElement_GetElementByName(This,bstrSubName,ppElement)	\
    ( (This)->lpVtbl -> GetElementByName(This,bstrSubName,ppElement) ) 

#define IAppHostElement_GetPropertyByName(This,bstrSubName,ppProperty)	\
    ( (This)->lpVtbl -> GetPropertyByName(This,bstrSubName,ppProperty) ) 

#define IAppHostElement_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostElement_INTERFACE_DEFINED__ */


#ifndef __IAppHostProperty_INTERFACE_DEFINED__
#define __IAppHostProperty_INTERFACE_DEFINED__

/* interface IAppHostProperty */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ed35f7a1-5024-4e7b-a44d-07ddaf4b524d")
    IAppHostProperty : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ __RPC__out VARIANT *pVariant) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_StringValue( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrValue) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Exception( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertyException **ppException) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Schema( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertySchema **ppSchema) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostProperty * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostProperty * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IAppHostProperty * This,
            /* [retval][out] */ __RPC__out VARIANT *pVariant);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IAppHostProperty * This,
            /* [in] */ VARIANT value);
        
        HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAppHostProperty * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_StringValue )( 
            IAppHostProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrValue);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Exception )( 
            IAppHostProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertyException **ppException);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostProperty * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetMetadata )( 
            IAppHostProperty * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Schema )( 
            IAppHostProperty * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostPropertySchema **ppSchema);
        
        END_INTERFACE
    } IAppHostPropertyVtbl;

    interface IAppHostProperty
    {
        CONST_VTBL struct IAppHostPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostProperty_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostProperty_get_Value(This,pVariant)	\
    ( (This)->lpVtbl -> get_Value(This,pVariant) ) 

#define IAppHostProperty_put_Value(This,value)	\
    ( (This)->lpVtbl -> put_Value(This,value) ) 

#define IAppHostProperty_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IAppHostProperty_get_StringValue(This,pbstrValue)	\
    ( (This)->lpVtbl -> get_StringValue(This,pbstrValue) ) 

#define IAppHostProperty_get_Exception(This,ppException)	\
    ( (This)->lpVtbl -> get_Exception(This,ppException) ) 

#define IAppHostProperty_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostProperty_SetMetadata(This,bstrMetadataType,value)	\
    ( (This)->lpVtbl -> SetMetadata(This,bstrMetadataType,value) ) 

#define IAppHostProperty_get_Schema(This,ppSchema)	\
    ( (This)->lpVtbl -> get_Schema(This,ppSchema) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostProperty_INTERFACE_DEFINED__ */


#ifndef __IAppHostConfigLocation_INTERFACE_DEFINED__
#define __IAppHostConfigLocation_INTERFACE_DEFINED__

/* interface IAppHostConfigLocation */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostConfigLocation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("370af178-7758-4dad-8146-7391f6e18585")
    IAppHostConfigLocation : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrLocationPath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out DWORD *pcCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppSection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddConfigSection( 
            /* [in] */ __RPC__in BSTR bstrSectionName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteConfigSection( 
            /* [in] */ VARIANT cIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostConfigLocationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostConfigLocation * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostConfigLocation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostConfigLocation * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IAppHostConfigLocation * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrLocationPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostConfigLocation * This,
            /* [retval][out] */ __RPC__out DWORD *pcCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostConfigLocation * This,
            /* [in] */ VARIANT cIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppSection);
        
        HRESULT ( STDMETHODCALLTYPE *AddConfigSection )( 
            IAppHostConfigLocation * This,
            /* [in] */ __RPC__in BSTR bstrSectionName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminElement);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteConfigSection )( 
            IAppHostConfigLocation * This,
            /* [in] */ VARIANT cIndex);
        
        END_INTERFACE
    } IAppHostConfigLocationVtbl;

    interface IAppHostConfigLocation
    {
        CONST_VTBL struct IAppHostConfigLocationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostConfigLocation_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostConfigLocation_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostConfigLocation_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostConfigLocation_get_Path(This,pbstrLocationPath)	\
    ( (This)->lpVtbl -> get_Path(This,pbstrLocationPath) ) 

#define IAppHostConfigLocation_get_Count(This,pcCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcCount) ) 

#define IAppHostConfigLocation_get_Item(This,cIndex,ppSection)	\
    ( (This)->lpVtbl -> get_Item(This,cIndex,ppSection) ) 

#define IAppHostConfigLocation_AddConfigSection(This,bstrSectionName,ppAdminElement)	\
    ( (This)->lpVtbl -> AddConfigSection(This,bstrSectionName,ppAdminElement) ) 

#define IAppHostConfigLocation_DeleteConfigSection(This,cIndex)	\
    ( (This)->lpVtbl -> DeleteConfigSection(This,cIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostConfigLocation_INTERFACE_DEFINED__ */


#ifndef __IAppHostSectionDefinition_INTERFACE_DEFINED__
#define __IAppHostSectionDefinition_INTERFACE_DEFINED__

/* interface IAppHostSectionDefinition */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostSectionDefinition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c5c04795-321c-4014-8fd6-d44658799393")
    IAppHostSectionDefinition : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ __RPC__in BSTR bstrType) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_OverrideModeDefault( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrOverrideModeDefault) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_OverrideModeDefault( 
            /* [in] */ __RPC__in BSTR bstrOverrideModeDefault) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AllowDefinition( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrAllowDefinition) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_AllowDefinition( 
            /* [in] */ __RPC__in BSTR bstrAllowDefinition) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_AllowLocation( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrAllowLocation) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_AllowLocation( 
            /* [in] */ __RPC__in BSTR bstrAllowLocation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostSectionDefinitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostSectionDefinition * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostSectionDefinition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostSectionDefinition * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostSectionDefinition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAppHostSectionDefinition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrType);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IAppHostSectionDefinition * This,
            /* [in] */ __RPC__in BSTR bstrType);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverrideModeDefault )( 
            IAppHostSectionDefinition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrOverrideModeDefault);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverrideModeDefault )( 
            IAppHostSectionDefinition * This,
            /* [in] */ __RPC__in BSTR bstrOverrideModeDefault);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowDefinition )( 
            IAppHostSectionDefinition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrAllowDefinition);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowDefinition )( 
            IAppHostSectionDefinition * This,
            /* [in] */ __RPC__in BSTR bstrAllowDefinition);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowLocation )( 
            IAppHostSectionDefinition * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrAllowLocation);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowLocation )( 
            IAppHostSectionDefinition * This,
            /* [in] */ __RPC__in BSTR bstrAllowLocation);
        
        END_INTERFACE
    } IAppHostSectionDefinitionVtbl;

    interface IAppHostSectionDefinition
    {
        CONST_VTBL struct IAppHostSectionDefinitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostSectionDefinition_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostSectionDefinition_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostSectionDefinition_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostSectionDefinition_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostSectionDefinition_get_Type(This,pbstrType)	\
    ( (This)->lpVtbl -> get_Type(This,pbstrType) ) 

#define IAppHostSectionDefinition_put_Type(This,bstrType)	\
    ( (This)->lpVtbl -> put_Type(This,bstrType) ) 

#define IAppHostSectionDefinition_get_OverrideModeDefault(This,pbstrOverrideModeDefault)	\
    ( (This)->lpVtbl -> get_OverrideModeDefault(This,pbstrOverrideModeDefault) ) 

#define IAppHostSectionDefinition_put_OverrideModeDefault(This,bstrOverrideModeDefault)	\
    ( (This)->lpVtbl -> put_OverrideModeDefault(This,bstrOverrideModeDefault) ) 

#define IAppHostSectionDefinition_get_AllowDefinition(This,pbstrAllowDefinition)	\
    ( (This)->lpVtbl -> get_AllowDefinition(This,pbstrAllowDefinition) ) 

#define IAppHostSectionDefinition_put_AllowDefinition(This,bstrAllowDefinition)	\
    ( (This)->lpVtbl -> put_AllowDefinition(This,bstrAllowDefinition) ) 

#define IAppHostSectionDefinition_get_AllowLocation(This,pbstrAllowLocation)	\
    ( (This)->lpVtbl -> get_AllowLocation(This,pbstrAllowLocation) ) 

#define IAppHostSectionDefinition_put_AllowLocation(This,bstrAllowLocation)	\
    ( (This)->lpVtbl -> put_AllowLocation(This,bstrAllowLocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostSectionDefinition_INTERFACE_DEFINED__ */


#ifndef __IAppHostSectionDefinitionCollection_INTERFACE_DEFINED__
#define __IAppHostSectionDefinitionCollection_INTERFACE_DEFINED__

/* interface IAppHostSectionDefinitionCollection */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostSectionDefinitionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b7d381ee-8860-47a1-8af4-1f33b2b1f325")
    IAppHostSectionDefinitionCollection : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out ULONG *pcCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinition **ppConfigSection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSection( 
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinition **ppConfigSection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteSection( 
            /* [in] */ VARIANT varIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostSectionDefinitionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostSectionDefinitionCollection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostSectionDefinitionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostSectionDefinitionCollection * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostSectionDefinitionCollection * This,
            /* [retval][out] */ __RPC__out ULONG *pcCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostSectionDefinitionCollection * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinition **ppConfigSection);
        
        HRESULT ( STDMETHODCALLTYPE *AddSection )( 
            IAppHostSectionDefinitionCollection * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinition **ppConfigSection);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteSection )( 
            IAppHostSectionDefinitionCollection * This,
            /* [in] */ VARIANT varIndex);
        
        END_INTERFACE
    } IAppHostSectionDefinitionCollectionVtbl;

    interface IAppHostSectionDefinitionCollection
    {
        CONST_VTBL struct IAppHostSectionDefinitionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostSectionDefinitionCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostSectionDefinitionCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostSectionDefinitionCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostSectionDefinitionCollection_get_Count(This,pcCount)	\
    ( (This)->lpVtbl -> get_Count(This,pcCount) ) 

#define IAppHostSectionDefinitionCollection_get_Item(This,varIndex,ppConfigSection)	\
    ( (This)->lpVtbl -> get_Item(This,varIndex,ppConfigSection) ) 

#define IAppHostSectionDefinitionCollection_AddSection(This,bstrSectionName,ppConfigSection)	\
    ( (This)->lpVtbl -> AddSection(This,bstrSectionName,ppConfigSection) ) 

#define IAppHostSectionDefinitionCollection_DeleteSection(This,varIndex)	\
    ( (This)->lpVtbl -> DeleteSection(This,varIndex) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostSectionDefinitionCollection_INTERFACE_DEFINED__ */


#ifndef __IAppHostSectionGroup_INTERFACE_DEFINED__
#define __IAppHostSectionGroup_INTERFACE_DEFINED__

/* interface IAppHostSectionGroup */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostSectionGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0dd8a158-ebe6-4008-a1d9-b7ecc8f1104b")
    IAppHostSectionGroup : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out ULONG *pcSectionGroup) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroup) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Sections( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinitionCollection **ppSections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddSectionGroup( 
            /* [string][in] */ __RPC__in BSTR bstrSectionGroupName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroup) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteSectionGroup( 
            /* [in] */ VARIANT varIndex) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrType) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ __RPC__in BSTR bstrType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostSectionGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostSectionGroup * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostSectionGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostSectionGroup * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAppHostSectionGroup * This,
            /* [retval][out] */ __RPC__out ULONG *pcSectionGroup);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAppHostSectionGroup * This,
            /* [in] */ VARIANT varIndex,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroup);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sections )( 
            IAppHostSectionGroup * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionDefinitionCollection **ppSections);
        
        HRESULT ( STDMETHODCALLTYPE *AddSectionGroup )( 
            IAppHostSectionGroup * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionGroupName,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroup);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteSectionGroup )( 
            IAppHostSectionGroup * This,
            /* [in] */ VARIANT varIndex);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAppHostSectionGroup * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IAppHostSectionGroup * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrType);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IAppHostSectionGroup * This,
            /* [in] */ __RPC__in BSTR bstrType);
        
        END_INTERFACE
    } IAppHostSectionGroupVtbl;

    interface IAppHostSectionGroup
    {
        CONST_VTBL struct IAppHostSectionGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostSectionGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostSectionGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostSectionGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostSectionGroup_get_Count(This,pcSectionGroup)	\
    ( (This)->lpVtbl -> get_Count(This,pcSectionGroup) ) 

#define IAppHostSectionGroup_get_Item(This,varIndex,ppSectionGroup)	\
    ( (This)->lpVtbl -> get_Item(This,varIndex,ppSectionGroup) ) 

#define IAppHostSectionGroup_get_Sections(This,ppSections)	\
    ( (This)->lpVtbl -> get_Sections(This,ppSections) ) 

#define IAppHostSectionGroup_AddSectionGroup(This,bstrSectionGroupName,ppSectionGroup)	\
    ( (This)->lpVtbl -> AddSectionGroup(This,bstrSectionGroupName,ppSectionGroup) ) 

#define IAppHostSectionGroup_DeleteSectionGroup(This,varIndex)	\
    ( (This)->lpVtbl -> DeleteSectionGroup(This,varIndex) ) 

#define IAppHostSectionGroup_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define IAppHostSectionGroup_get_Type(This,pbstrType)	\
    ( (This)->lpVtbl -> get_Type(This,pbstrType) ) 

#define IAppHostSectionGroup_put_Type(This,bstrType)	\
    ( (This)->lpVtbl -> put_Type(This,bstrType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostSectionGroup_INTERFACE_DEFINED__ */


#ifndef __IAppHostConfigFile_INTERFACE_DEFINED__
#define __IAppHostConfigFile_INTERFACE_DEFINED__

/* interface IAppHostConfigFile */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostConfigFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ada4e6fb-e025-401e-a5d0-c3134a281f07")
    IAppHostConfigFile : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ConfigPath( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrConfigPath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FilePath( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrFilePath) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Locations( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocationCollection **ppLocations) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdminSection( 
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminSection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearInvalidSections( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RootSectionGroup( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroups) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostConfigFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostConfigFile * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostConfigFile * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostConfigFile * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigPath )( 
            IAppHostConfigFile * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrConfigPath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FilePath )( 
            IAppHostConfigFile * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrFilePath);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Locations )( 
            IAppHostConfigFile * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigLocationCollection **ppLocations);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdminSection )( 
            IAppHostConfigFile * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminSection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostConfigFile * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetMetadata )( 
            IAppHostConfigFile * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value);
        
        HRESULT ( STDMETHODCALLTYPE *ClearInvalidSections )( 
            IAppHostConfigFile * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootSectionGroup )( 
            IAppHostConfigFile * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostSectionGroup **ppSectionGroups);
        
        END_INTERFACE
    } IAppHostConfigFileVtbl;

    interface IAppHostConfigFile
    {
        CONST_VTBL struct IAppHostConfigFileVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostConfigFile_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostConfigFile_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostConfigFile_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostConfigFile_get_ConfigPath(This,pbstrConfigPath)	\
    ( (This)->lpVtbl -> get_ConfigPath(This,pbstrConfigPath) ) 

#define IAppHostConfigFile_get_FilePath(This,pbstrFilePath)	\
    ( (This)->lpVtbl -> get_FilePath(This,pbstrFilePath) ) 

#define IAppHostConfigFile_get_Locations(This,ppLocations)	\
    ( (This)->lpVtbl -> get_Locations(This,ppLocations) ) 

#define IAppHostConfigFile_GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection)	\
    ( (This)->lpVtbl -> GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection) ) 

#define IAppHostConfigFile_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostConfigFile_SetMetadata(This,bstrMetadataType,value)	\
    ( (This)->lpVtbl -> SetMetadata(This,bstrMetadataType,value) ) 

#define IAppHostConfigFile_ClearInvalidSections(This)	\
    ( (This)->lpVtbl -> ClearInvalidSections(This) ) 

#define IAppHostConfigFile_get_RootSectionGroup(This,ppSectionGroups)	\
    ( (This)->lpVtbl -> get_RootSectionGroup(This,ppSectionGroups) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostConfigFile_INTERFACE_DEFINED__ */


#ifndef __IAppHostPathMapper_INTERFACE_DEFINED__
#define __IAppHostPathMapper_INTERFACE_DEFINED__

/* interface IAppHostPathMapper */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostPathMapper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e7927575-5cc3-403b-822e-328a6b904bee")
    IAppHostPathMapper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MapPath( 
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [string][in] */ __RPC__in BSTR bstrMappedPhysicalPath,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrNewPhysicalPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostPathMapperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostPathMapper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostPathMapper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostPathMapper * This);
        
        HRESULT ( STDMETHODCALLTYPE *MapPath )( 
            IAppHostPathMapper * This,
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [string][in] */ __RPC__in BSTR bstrMappedPhysicalPath,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pbstrNewPhysicalPath);
        
        END_INTERFACE
    } IAppHostPathMapperVtbl;

    interface IAppHostPathMapper
    {
        CONST_VTBL struct IAppHostPathMapperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostPathMapper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostPathMapper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostPathMapper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostPathMapper_MapPath(This,bstrConfigPath,bstrMappedPhysicalPath,pbstrNewPhysicalPath)	\
    ( (This)->lpVtbl -> MapPath(This,bstrConfigPath,bstrMappedPhysicalPath,pbstrNewPhysicalPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostPathMapper_INTERFACE_DEFINED__ */


#ifndef __IAppHostChangeHandler_INTERFACE_DEFINED__
#define __IAppHostChangeHandler_INTERFACE_DEFINED__

/* interface IAppHostChangeHandler */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostChangeHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09829352-87c2-418d-8d79-4133969a489d")
    IAppHostChangeHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSectionChanges( 
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrConfigPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostChangeHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostChangeHandler * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostChangeHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostChangeHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSectionChanges )( 
            IAppHostChangeHandler * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrConfigPath);
        
        END_INTERFACE
    } IAppHostChangeHandlerVtbl;

    interface IAppHostChangeHandler
    {
        CONST_VTBL struct IAppHostChangeHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostChangeHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostChangeHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostChangeHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostChangeHandler_OnSectionChanges(This,bstrSectionName,bstrConfigPath)	\
    ( (This)->lpVtbl -> OnSectionChanges(This,bstrSectionName,bstrConfigPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostChangeHandler_INTERFACE_DEFINED__ */


#ifndef __IAppHostAdminManager_INTERFACE_DEFINED__
#define __IAppHostAdminManager_INTERFACE_DEFINED__

/* interface IAppHostAdminManager */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostAdminManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9be77978-73ed-4a9a-87fd-13f09fec1b13")
    IAppHostAdminManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAdminSection( 
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminSection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMetadata( 
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ConfigManager( 
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigManager **ppConfigManager) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostAdminManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostAdminManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostAdminManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostAdminManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdminSection )( 
            IAppHostAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminSection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetMetadata )( 
            IAppHostAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigManager )( 
            IAppHostAdminManager * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigManager **ppConfigManager);
        
        END_INTERFACE
    } IAppHostAdminManagerVtbl;

    interface IAppHostAdminManager
    {
        CONST_VTBL struct IAppHostAdminManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostAdminManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostAdminManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostAdminManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostAdminManager_GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection)	\
    ( (This)->lpVtbl -> GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection) ) 

#define IAppHostAdminManager_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostAdminManager_SetMetadata(This,bstrMetadataType,value)	\
    ( (This)->lpVtbl -> SetMetadata(This,bstrMetadataType,value) ) 

#define IAppHostAdminManager_get_ConfigManager(This,ppConfigManager)	\
    ( (This)->lpVtbl -> get_ConfigManager(This,ppConfigManager) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostAdminManager_INTERFACE_DEFINED__ */


#ifndef __IAppHostWritableAdminManager_INTERFACE_DEFINED__
#define __IAppHostWritableAdminManager_INTERFACE_DEFINED__

/* interface IAppHostWritableAdminManager */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostWritableAdminManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fa7660f6-7b3f-4237-a8bf-ed0ad0dcbbd9")
    IAppHostWritableAdminManager : public IAppHostAdminManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CommitChanges( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CommitPath( 
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrCommitPath) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_CommitPath( 
            /* [string][in] */ __RPC__in BSTR bstrCommitPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostWritableAdminManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostWritableAdminManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostWritableAdminManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostWritableAdminManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdminSection )( 
            IAppHostWritableAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrSectionName,
            /* [string][in] */ __RPC__in BSTR bstrPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostElement **ppAdminSection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMetadata )( 
            IAppHostWritableAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [retval][out] */ __RPC__out VARIANT *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetMetadata )( 
            IAppHostWritableAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrMetadataType,
            /* [in] */ VARIANT value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigManager )( 
            IAppHostWritableAdminManager * This,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigManager **ppConfigManager);
        
        HRESULT ( STDMETHODCALLTYPE *CommitChanges )( 
            IAppHostWritableAdminManager * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CommitPath )( 
            IAppHostWritableAdminManager * This,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrCommitPath);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_CommitPath )( 
            IAppHostWritableAdminManager * This,
            /* [string][in] */ __RPC__in BSTR bstrCommitPath);
        
        END_INTERFACE
    } IAppHostWritableAdminManagerVtbl;

    interface IAppHostWritableAdminManager
    {
        CONST_VTBL struct IAppHostWritableAdminManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostWritableAdminManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostWritableAdminManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostWritableAdminManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostWritableAdminManager_GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection)	\
    ( (This)->lpVtbl -> GetAdminSection(This,bstrSectionName,bstrPath,ppAdminSection) ) 

#define IAppHostWritableAdminManager_GetMetadata(This,bstrMetadataType,pValue)	\
    ( (This)->lpVtbl -> GetMetadata(This,bstrMetadataType,pValue) ) 

#define IAppHostWritableAdminManager_SetMetadata(This,bstrMetadataType,value)	\
    ( (This)->lpVtbl -> SetMetadata(This,bstrMetadataType,value) ) 

#define IAppHostWritableAdminManager_get_ConfigManager(This,ppConfigManager)	\
    ( (This)->lpVtbl -> get_ConfigManager(This,ppConfigManager) ) 


#define IAppHostWritableAdminManager_CommitChanges(This)	\
    ( (This)->lpVtbl -> CommitChanges(This) ) 

#define IAppHostWritableAdminManager_get_CommitPath(This,pbstrCommitPath)	\
    ( (This)->lpVtbl -> get_CommitPath(This,pbstrCommitPath) ) 

#define IAppHostWritableAdminManager_put_CommitPath(This,bstrCommitPath)	\
    ( (This)->lpVtbl -> put_CommitPath(This,bstrCommitPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostWritableAdminManager_INTERFACE_DEFINED__ */


#ifndef __IAppHostConfigManager_INTERFACE_DEFINED__
#define __IAppHostConfigManager_INTERFACE_DEFINED__

/* interface IAppHostConfigManager */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IAppHostConfigManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8f6d760f-f0cb-4d69-b5f6-848b33e9bdc6")
    IAppHostConfigManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConfigFile( 
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigFile **ppConfigFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUniqueConfigPath( 
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrUniquePath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAppHostConfigManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppHostConfigManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppHostConfigManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppHostConfigManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConfigFile )( 
            IAppHostConfigManager * This,
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [retval][out] */ __RPC__deref_out_opt IAppHostConfigFile **ppConfigFile);
        
        HRESULT ( STDMETHODCALLTYPE *GetUniqueConfigPath )( 
            IAppHostConfigManager * This,
            /* [string][in] */ __RPC__in BSTR bstrConfigPath,
            /* [string][retval][out] */ __RPC__deref_out_opt_string BSTR *pbstrUniquePath);
        
        END_INTERFACE
    } IAppHostConfigManagerVtbl;

    interface IAppHostConfigManager
    {
        CONST_VTBL struct IAppHostConfigManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppHostConfigManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppHostConfigManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppHostConfigManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppHostConfigManager_GetConfigFile(This,bstrConfigPath,ppConfigFile)	\
    ( (This)->lpVtbl -> GetConfigFile(This,bstrConfigPath,ppConfigFile) ) 

#define IAppHostConfigManager_GetUniqueConfigPath(This,bstrConfigPath,pbstrUniquePath)	\
    ( (This)->lpVtbl -> GetUniqueConfigPath(This,bstrConfigPath,pbstrUniquePath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppHostConfigManager_INTERFACE_DEFINED__ */



#ifndef __AppHostAdminLibrary_LIBRARY_DEFINED__
#define __AppHostAdminLibrary_LIBRARY_DEFINED__

/* library AppHostAdminLibrary */
/* [helpstring][version][uuid] */ 







EXTERN_C const IID LIBID_AppHostAdminLibrary;

EXTERN_C const CLSID CLSID_AppHostAdminManager;

#ifdef __cplusplus

class DECLSPEC_UUID("228fb8f7-fb53-4fd5-8c7b-ff59de606c5b")
AppHostAdminManager;
#endif

EXTERN_C const CLSID CLSID_AppHostWritableAdminManager;

#ifdef __cplusplus

class DECLSPEC_UUID("2b72133b-3f5b-4602-8952-803546ce3344")
AppHostWritableAdminManager;
#endif
#endif /* __AppHostAdminLibrary_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



