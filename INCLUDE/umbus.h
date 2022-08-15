

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for umbus.idl:
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

#ifndef __umbus_h__
#define __umbus_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUMBusDriver_FWD_DEFINED__
#define __IUMBusDriver_FWD_DEFINED__
typedef interface IUMBusDriver IUMBusDriver;
#endif 	/* __IUMBusDriver_FWD_DEFINED__ */


#ifndef __IUMBusPDO_FWD_DEFINED__
#define __IUMBusPDO_FWD_DEFINED__
typedef interface IUMBusPDO IUMBusPDO;
#endif 	/* __IUMBusPDO_FWD_DEFINED__ */


#ifndef __UMBusDriver_FWD_DEFINED__
#define __UMBusDriver_FWD_DEFINED__

#ifdef __cplusplus
typedef class UMBusDriver UMBusDriver;
#else
typedef struct UMBusDriver UMBusDriver;
#endif /* __cplusplus */

#endif 	/* __UMBusDriver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "propsys.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_umbus_0000_0000 */
/* [local] */ 




enum AddChildFlags
    {	UMBUS_CREATEBUSCHILD	= ( 1 << 0 ) 
    } ;


extern RPC_IF_HANDLE __MIDL_itf_umbus_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_umbus_0000_0000_v0_0_s_ifspec;

#ifndef __IUMBusDriver_INTERFACE_DEFINED__
#define __IUMBusDriver_INTERFACE_DEFINED__

/* interface IUMBusDriver */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUMBusDriver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("712f2e95-9b00-4c34-b049-bd3c9c1402cc")
    IUMBusDriver : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ __RPC__out DWORD *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ DWORD index,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindEnumByIdentity( 
            /* [in] */ __RPC__in WCHAR *identity,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddBusEnumerator( 
            /* [in] */ __RPC__in WCHAR *identity,
            /* [in] */ __RPC__in_opt IPropertyStore *pPersistentPropStore,
            /* [in] */ __RPC__in_opt IPropertyStore *pDynamicPropStore,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveBusEnumerator( 
            /* [in] */ __RPC__in_opt IUMBusPDO *ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteBusEnumerator( 
            /* [in] */ __RPC__in_opt IUMBusPDO *ppBusPDO) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUMBusDriverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUMBusDriver * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUMBusDriver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUMBusDriver * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IUMBusDriver * This,
            /* [retval][out] */ __RPC__out DWORD *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IUMBusDriver * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *FindEnumByIdentity )( 
            IUMBusDriver * This,
            /* [in] */ __RPC__in WCHAR *identity,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *AddBusEnumerator )( 
            IUMBusDriver * This,
            /* [in] */ __RPC__in WCHAR *identity,
            /* [in] */ __RPC__in_opt IPropertyStore *pPersistentPropStore,
            /* [in] */ __RPC__in_opt IPropertyStore *pDynamicPropStore,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveBusEnumerator )( 
            IUMBusDriver * This,
            /* [in] */ __RPC__in_opt IUMBusPDO *ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteBusEnumerator )( 
            IUMBusDriver * This,
            /* [in] */ __RPC__in_opt IUMBusPDO *ppBusPDO);
        
        END_INTERFACE
    } IUMBusDriverVtbl;

    interface IUMBusDriver
    {
        CONST_VTBL struct IUMBusDriverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUMBusDriver_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUMBusDriver_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUMBusDriver_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUMBusDriver_GetCount(This,pCount)	\
    ( (This)->lpVtbl -> GetCount(This,pCount) ) 

#define IUMBusDriver_Item(This,index,ppBusPDO)	\
    ( (This)->lpVtbl -> Item(This,index,ppBusPDO) ) 

#define IUMBusDriver_FindEnumByIdentity(This,identity,ppBusPDO)	\
    ( (This)->lpVtbl -> FindEnumByIdentity(This,identity,ppBusPDO) ) 

#define IUMBusDriver_AddBusEnumerator(This,identity,pPersistentPropStore,pDynamicPropStore,ppBusPDO)	\
    ( (This)->lpVtbl -> AddBusEnumerator(This,identity,pPersistentPropStore,pDynamicPropStore,ppBusPDO) ) 

#define IUMBusDriver_RemoveBusEnumerator(This,ppBusPDO)	\
    ( (This)->lpVtbl -> RemoveBusEnumerator(This,ppBusPDO) ) 

#define IUMBusDriver_DeleteBusEnumerator(This,ppBusPDO)	\
    ( (This)->lpVtbl -> DeleteBusEnumerator(This,ppBusPDO) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUMBusDriver_INTERFACE_DEFINED__ */


#ifndef __IUMBusPDO_INTERFACE_DEFINED__
#define __IUMBusPDO_INTERFACE_DEFINED__

/* interface IUMBusPDO */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IUMBusPDO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d0c06d7f-1f31-4ca9-87f9-c62600f2ca5f")
    IUMBusPDO : public IPropertyStore
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetChildCount( 
            /* [retval][out] */ __RPC__out DWORD *pNumBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ DWORD index,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindChildByIdentity( 
            /* [in] */ __RPC__in WCHAR *identity,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddChild( 
            /* [in] */ __RPC__in WCHAR *identity,
            /* [in] */ __RPC__in_opt IPropertyStore *pPersistentPropStore,
            /* [in] */ __RPC__in_opt IPropertyStore *pDynamicPropStore,
            /* [in] */ ULONG CreateOptions,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveChild( 
            /* [in] */ __RPC__in_opt IUMBusPDO *pBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteChild( 
            /* [in] */ __RPC__in_opt IUMBusPDO *pBusPDO) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDynamicPropertyStore( 
            /* [retval][out] */ __RPC__deref_out_opt IPropertyStore **ppPropertyStore) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUMBusPDOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUMBusPDO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUMBusPDO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IUMBusPDO * This,
            /* [out] */ __RPC__out DWORD *cProps);
        
        HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            IUMBusPDO * This,
            /* [in] */ DWORD iProp,
            /* [out] */ __RPC__out PROPERTYKEY *pkey);
        
        HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [out] */ __RPC__out PROPVARIANT *pv);
        
        HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [in] */ __RPC__in REFPROPVARIANT propvar);
        
        HRESULT ( STDMETHODCALLTYPE *Commit )( 
            IUMBusPDO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetChildCount )( 
            IUMBusPDO * This,
            /* [retval][out] */ __RPC__out DWORD *pNumBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IUMBusPDO * This,
            /* [in] */ DWORD index,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *FindChildByIdentity )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in WCHAR *identity,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *AddChild )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in WCHAR *identity,
            /* [in] */ __RPC__in_opt IPropertyStore *pPersistentPropStore,
            /* [in] */ __RPC__in_opt IPropertyStore *pDynamicPropStore,
            /* [in] */ ULONG CreateOptions,
            /* [retval][out] */ __RPC__deref_out_opt IUMBusPDO **ppBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveChild )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in_opt IUMBusPDO *pBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteChild )( 
            IUMBusPDO * This,
            /* [in] */ __RPC__in_opt IUMBusPDO *pBusPDO);
        
        HRESULT ( STDMETHODCALLTYPE *GetDynamicPropertyStore )( 
            IUMBusPDO * This,
            /* [retval][out] */ __RPC__deref_out_opt IPropertyStore **ppPropertyStore);
        
        END_INTERFACE
    } IUMBusPDOVtbl;

    interface IUMBusPDO
    {
        CONST_VTBL struct IUMBusPDOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUMBusPDO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUMBusPDO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUMBusPDO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUMBusPDO_GetCount(This,cProps)	\
    ( (This)->lpVtbl -> GetCount(This,cProps) ) 

#define IUMBusPDO_GetAt(This,iProp,pkey)	\
    ( (This)->lpVtbl -> GetAt(This,iProp,pkey) ) 

#define IUMBusPDO_GetValue(This,key,pv)	\
    ( (This)->lpVtbl -> GetValue(This,key,pv) ) 

#define IUMBusPDO_SetValue(This,key,propvar)	\
    ( (This)->lpVtbl -> SetValue(This,key,propvar) ) 

#define IUMBusPDO_Commit(This)	\
    ( (This)->lpVtbl -> Commit(This) ) 


#define IUMBusPDO_GetChildCount(This,pNumBusPDO)	\
    ( (This)->lpVtbl -> GetChildCount(This,pNumBusPDO) ) 

#define IUMBusPDO_Item(This,index,ppBusPDO)	\
    ( (This)->lpVtbl -> Item(This,index,ppBusPDO) ) 

#define IUMBusPDO_FindChildByIdentity(This,identity,ppBusPDO)	\
    ( (This)->lpVtbl -> FindChildByIdentity(This,identity,ppBusPDO) ) 

#define IUMBusPDO_AddChild(This,identity,pPersistentPropStore,pDynamicPropStore,CreateOptions,ppBusPDO)	\
    ( (This)->lpVtbl -> AddChild(This,identity,pPersistentPropStore,pDynamicPropStore,CreateOptions,ppBusPDO) ) 

#define IUMBusPDO_RemoveChild(This,pBusPDO)	\
    ( (This)->lpVtbl -> RemoveChild(This,pBusPDO) ) 

#define IUMBusPDO_DeleteChild(This,pBusPDO)	\
    ( (This)->lpVtbl -> DeleteChild(This,pBusPDO) ) 

#define IUMBusPDO_GetDynamicPropertyStore(This,ppPropertyStore)	\
    ( (This)->lpVtbl -> GetDynamicPropertyStore(This,ppPropertyStore) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUMBusPDO_INTERFACE_DEFINED__ */



#ifndef __UMBusLib_LIBRARY_DEFINED__
#define __UMBusLib_LIBRARY_DEFINED__

/* library UMBusLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_UMBusLib;

EXTERN_C const CLSID CLSID_UMBusDriver;

#ifdef __cplusplus

class DECLSPEC_UUID("9197e04d-2b9f-4849-8bf7-75294eb5c043")
UMBusDriver;
#endif
#endif /* __UMBusLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



