

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for certmod.idl:
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

#ifndef __certmod_h__
#define __certmod_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICertManageModule_FWD_DEFINED__
#define __ICertManageModule_FWD_DEFINED__
typedef interface ICertManageModule ICertManageModule;
#endif 	/* __ICertManageModule_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_certmod_0000_0000 */
/* [local] */ 

#define	CMM_REFRESHONLY	( 0x1 )

#define	CMM_READONLY	( 0x2 )

const WCHAR wszCMM_PROP_NAME[  ]	=	L"Name";

const WCHAR wszCMM_PROP_DESCRIPTION[  ]	=	L"Description";

const WCHAR wszCMM_PROP_COPYRIGHT[  ]	=	L"Copyright";

const WCHAR wszCMM_PROP_FILEVER[  ]	=	L"File Version";

const WCHAR wszCMM_PROP_PRODUCTVER[  ]	=	L"Product Version";

const WCHAR wszCMM_PROP_DISPLAY_HWND[  ]	=	L"HWND";

const WCHAR wszCMM_PROP_ISMULTITHREADED[  ]	=	L"IsMultiThreaded";



extern RPC_IF_HANDLE __MIDL_itf_certmod_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_certmod_0000_0000_v0_0_s_ifspec;

#ifndef __ICertManageModule_INTERFACE_DEFINED__
#define __ICertManageModule_INTERFACE_DEFINED__

/* interface ICertManageModule */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICertManageModule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e7d7ad42-bd3d-11d1-9a4d-00c04fc297eb")
    ICertManageModule : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ __RPC__in BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [retval][out] */ __RPC__out VARIANT *pvarProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ __RPC__in BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [in] */ __RPC__in const VARIANT *pvarProperty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Configure( 
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ LONG Flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICertManageModuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICertManageModule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICertManageModule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICertManageModule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICertManageModule * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICertManageModule * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICertManageModule * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICertManageModule * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            ICertManageModule * This,
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ __RPC__in BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [retval][out] */ __RPC__out VARIANT *pvarProperty);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            ICertManageModule * This,
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ __RPC__in BSTR strPropertyName,
            /* [in] */ LONG Flags,
            /* [in] */ __RPC__in const VARIANT *pvarProperty);
        
        HRESULT ( STDMETHODCALLTYPE *Configure )( 
            ICertManageModule * This,
            /* [in] */ __RPC__in const BSTR strConfig,
            /* [in] */ __RPC__in BSTR strStorageLocation,
            /* [in] */ LONG Flags);
        
        END_INTERFACE
    } ICertManageModuleVtbl;

    interface ICertManageModule
    {
        CONST_VTBL struct ICertManageModuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICertManageModule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICertManageModule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICertManageModule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICertManageModule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICertManageModule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICertManageModule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICertManageModule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICertManageModule_GetProperty(This,strConfig,strStorageLocation,strPropertyName,Flags,pvarProperty)	\
    ( (This)->lpVtbl -> GetProperty(This,strConfig,strStorageLocation,strPropertyName,Flags,pvarProperty) ) 

#define ICertManageModule_SetProperty(This,strConfig,strStorageLocation,strPropertyName,Flags,pvarProperty)	\
    ( (This)->lpVtbl -> SetProperty(This,strConfig,strStorageLocation,strPropertyName,Flags,pvarProperty) ) 

#define ICertManageModule_Configure(This,strConfig,strStorageLocation,Flags)	\
    ( (This)->lpVtbl -> Configure(This,strConfig,strStorageLocation,Flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICertManageModule_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



