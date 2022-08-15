

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for napcommon.idl:
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

#ifndef __napcommon_h__
#define __napcommon_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INapComponentInfo_FWD_DEFINED__
#define __INapComponentInfo_FWD_DEFINED__
typedef interface INapComponentInfo INapComponentInfo;
#endif 	/* __INapComponentInfo_FWD_DEFINED__ */


#ifndef __INapComponentConfig_FWD_DEFINED__
#define __INapComponentConfig_FWD_DEFINED__
typedef interface INapComponentConfig INapComponentConfig;
#endif 	/* __INapComponentConfig_FWD_DEFINED__ */


/* header files for imported files */
#include "NapTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __INapComponentInfo_INTERFACE_DEFINED__
#define __INapComponentInfo_INTERFACE_DEFINED__

/* interface INapComponentInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapComponentInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B475F925-E3F7-414c-8C72-1CEE64B9D8F6")
    INapComponentInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFriendlyName( 
            /* [out] */ __RPC__out MessageId *friendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ __RPC__out MessageId *description) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVendorName( 
            /* [out] */ __RPC__out MessageId *vendorName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ __RPC__out MessageId *version) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIcon( 
            /* [out] */ __RPC__deref_out_opt CountedString **dllFilePath,
            /* [out] */ __RPC__out UINT32 *iconResourceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertErrorCodeToMessageId( 
            /* [in] */ HRESULT errorCode,
            /* [out] */ __RPC__out MessageId *msgId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalizedString( 
            /* [in] */ MessageId msgId,
            /* [out] */ __RPC__deref_out_opt CountedString **string) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapComponentInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapComponentInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapComponentInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapComponentInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFriendlyName )( 
            INapComponentInfo * This,
            /* [out] */ __RPC__out MessageId *friendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            INapComponentInfo * This,
            /* [out] */ __RPC__out MessageId *description);
        
        HRESULT ( STDMETHODCALLTYPE *GetVendorName )( 
            INapComponentInfo * This,
            /* [out] */ __RPC__out MessageId *vendorName);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            INapComponentInfo * This,
            /* [out] */ __RPC__out MessageId *version);
        
        HRESULT ( STDMETHODCALLTYPE *GetIcon )( 
            INapComponentInfo * This,
            /* [out] */ __RPC__deref_out_opt CountedString **dllFilePath,
            /* [out] */ __RPC__out UINT32 *iconResourceId);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertErrorCodeToMessageId )( 
            INapComponentInfo * This,
            /* [in] */ HRESULT errorCode,
            /* [out] */ __RPC__out MessageId *msgId);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalizedString )( 
            INapComponentInfo * This,
            /* [in] */ MessageId msgId,
            /* [out] */ __RPC__deref_out_opt CountedString **string);
        
        END_INTERFACE
    } INapComponentInfoVtbl;

    interface INapComponentInfo
    {
        CONST_VTBL struct INapComponentInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapComponentInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapComponentInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapComponentInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapComponentInfo_GetFriendlyName(This,friendlyName)	\
    ( (This)->lpVtbl -> GetFriendlyName(This,friendlyName) ) 

#define INapComponentInfo_GetDescription(This,description)	\
    ( (This)->lpVtbl -> GetDescription(This,description) ) 

#define INapComponentInfo_GetVendorName(This,vendorName)	\
    ( (This)->lpVtbl -> GetVendorName(This,vendorName) ) 

#define INapComponentInfo_GetVersion(This,version)	\
    ( (This)->lpVtbl -> GetVersion(This,version) ) 

#define INapComponentInfo_GetIcon(This,dllFilePath,iconResourceId)	\
    ( (This)->lpVtbl -> GetIcon(This,dllFilePath,iconResourceId) ) 

#define INapComponentInfo_ConvertErrorCodeToMessageId(This,errorCode,msgId)	\
    ( (This)->lpVtbl -> ConvertErrorCodeToMessageId(This,errorCode,msgId) ) 

#define INapComponentInfo_GetLocalizedString(This,msgId,string)	\
    ( (This)->lpVtbl -> GetLocalizedString(This,msgId,string) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapComponentInfo_INTERFACE_DEFINED__ */


#ifndef __INapComponentConfig_INTERFACE_DEFINED__
#define __INapComponentConfig_INTERFACE_DEFINED__

/* interface INapComponentConfig */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapComponentConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a9e0af1a-3713-478e-ae03-8edd272d21fa")
    INapComponentConfig : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsUISupported( 
            /* [out] */ __RPC__out BOOL *isSupported) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvokeUI( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfig( 
            /* [out] */ __RPC__out UINT16 *bCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*bCount) BYTE **data) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConfig( 
            /* [in] */ UINT16 bCount,
            /* [size_is][in] */ __RPC__in_ecount_full(bCount) BYTE *data) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapComponentConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapComponentConfig * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapComponentConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapComponentConfig * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsUISupported )( 
            INapComponentConfig * This,
            /* [out] */ __RPC__out BOOL *isSupported);
        
        HRESULT ( STDMETHODCALLTYPE *InvokeUI )( 
            INapComponentConfig * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetConfig )( 
            INapComponentConfig * This,
            /* [out] */ __RPC__out UINT16 *bCount,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*bCount) BYTE **data);
        
        HRESULT ( STDMETHODCALLTYPE *SetConfig )( 
            INapComponentConfig * This,
            /* [in] */ UINT16 bCount,
            /* [size_is][in] */ __RPC__in_ecount_full(bCount) BYTE *data);
        
        END_INTERFACE
    } INapComponentConfigVtbl;

    interface INapComponentConfig
    {
        CONST_VTBL struct INapComponentConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapComponentConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapComponentConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapComponentConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapComponentConfig_IsUISupported(This,isSupported)	\
    ( (This)->lpVtbl -> IsUISupported(This,isSupported) ) 

#define INapComponentConfig_InvokeUI(This,hwndParent)	\
    ( (This)->lpVtbl -> InvokeUI(This,hwndParent) ) 

#define INapComponentConfig_GetConfig(This,bCount,data)	\
    ( (This)->lpVtbl -> GetConfig(This,bCount,data) ) 

#define INapComponentConfig_SetConfig(This,bCount,data)	\
    ( (This)->lpVtbl -> SetConfig(This,bCount,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapComponentConfig_INTERFACE_DEFINED__ */


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



