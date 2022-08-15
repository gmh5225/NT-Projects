

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for ndhelper.idl:
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

#ifndef __ndhelper_h__
#define __ndhelper_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INetDiagHelper_FWD_DEFINED__
#define __INetDiagHelper_FWD_DEFINED__
typedef interface INetDiagHelper INetDiagHelper;
#endif 	/* __INetDiagHelper_FWD_DEFINED__ */


#ifndef __INetDiagHelperInfo_FWD_DEFINED__
#define __INetDiagHelperInfo_FWD_DEFINED__
typedef interface INetDiagHelperInfo INetDiagHelperInfo;
#endif 	/* __INetDiagHelperInfo_FWD_DEFINED__ */


#ifndef __INetDiagExtensibleHelper_FWD_DEFINED__
#define __INetDiagExtensibleHelper_FWD_DEFINED__
typedef interface INetDiagExtensibleHelper INetDiagExtensibleHelper;
#endif 	/* __INetDiagExtensibleHelper_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ndattrib.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ndhelper_0000_0000 */
/* [local] */ 

//+--------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-2004.
//
//---------------------------------------------------------------------------
#if ( _MSC_VER >= 800 )
#pragma warning(disable:4201)
#endif


typedef /* [v1_enum] */ 
enum tagDIAGNOSIS_STATUS
    {	DS_NOT_IMPLEMENTED	= 0,
	DS_CONFIRMED	= ( DS_NOT_IMPLEMENTED + 1 ) ,
	DS_REJECTED	= ( DS_CONFIRMED + 1 ) ,
	DS_INDETERMINATE	= ( DS_REJECTED + 1 ) ,
	DS_DEFERRED	= ( DS_INDETERMINATE + 1 ) 
    } 	DIAGNOSIS_STATUS;

typedef /* [v1_enum] */ 
enum tagREPAIR_STATUS
    {	RS_NOT_IMPLEMENTED	= 0,
	RS_REPAIRED	= ( RS_NOT_IMPLEMENTED + 1 ) ,
	RS_UNREPAIRED	= ( RS_REPAIRED + 1 ) ,
	RS_DEFERRED	= ( RS_UNREPAIRED + 1 ) ,
	RS_USER_ACTION	= ( RS_DEFERRED + 1 ) 
    } 	REPAIR_STATUS;

typedef /* [v1_enum] */ 
enum tagPROBLEM_TYPE
    {	PT_INVALID	= 0,
	PT_LOW_HEALTH	= 1,
	PT_LOWER_HEALTH	= 2,
	PT_DOWN_STREAM_HEALTH	= 4,
	PT_HIGH_UTILIZATION	= 8,
	PT_HIGHER_UTILIZATION	= 16,
	PT_UP_STREAM_UTILIZATION	= 32
    } 	PROBLEM_TYPE;

typedef struct tagHYPOTHESIS
    {
    LPWSTR pwszClassName;
    LPWSTR pwszDescription;
    ULONG celt;
    PHELPER_ATTRIBUTE rgAttributes;
    } 	HYPOTHESIS;

typedef struct tagHYPOTHESIS *PHYPOTHESIS;

typedef struct tagHelperAttributeInfo
    {
    LPWSTR pwszName;
    ATTRIBUTE_TYPE type;
    } 	HelperAttributeInfo;

typedef struct tagHelperAttributeInfo *PHelperAttributeInfo;

#define DF_IMPERSONATION 0x80000000
#define DF_TRACELESS 0x40000000
typedef struct tagDiagnosticsInfo
    {
    long cost;
    ULONG flags;
    } 	DiagnosticsInfo;

typedef struct tagDiagnosticsInfo *PDiagnosticsInfo;



extern RPC_IF_HANDLE __MIDL_itf_ndhelper_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ndhelper_0000_0000_v0_0_s_ifspec;

#ifndef __INetDiagHelper_INTERFACE_DEFINED__
#define __INetDiagHelper_INTERFACE_DEFINED__

/* interface INetDiagHelper */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INetDiagHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c0b35746-ebf5-11d8-bbe9-505054503030")
    INetDiagHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ULONG celt,
            /* [size_is][in] */ __RPC__in_ecount_full(celt) HELPER_ATTRIBUTE rgAttributes[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDiagnosticsInfo( 
            /* [retval][out] */ __RPC__deref_out_opt DiagnosticsInfo **ppInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeyAttributes( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **pprgAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LowHealth( 
            /* [unique][string][in] */ __RPC__in_opt LPCWSTR pwszInstanceDescription,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppwszDescription,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out DIAGNOSIS_STATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HighUtilization( 
            /* [unique][string][in] */ __RPC__in_opt LPCWSTR pwszInstanceDescription,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppwszDescription,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out DIAGNOSIS_STATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLowerHypotheses( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDownStreamHypotheses( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHigherHypotheses( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUpStreamHypotheses( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Repair( 
            /* [in] */ __RPC__in RepairInfo *pInfo,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out REPAIR_STATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ PROBLEM_TYPE problem,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out REPAIR_STATUS *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRepairInfo( 
            /* [in] */ PROBLEM_TYPE problem,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) RepairInfo **ppInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLifeTime( 
            /* [out] */ __RPC__out LIFE_TIME *pLifeTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLifeTime( 
            /* [in] */ LIFE_TIME lifeTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCacheTime( 
            /* [out] */ __RPC__out FILETIME *pCacheTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributes( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **pprgAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cleanup( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetDiagHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetDiagHelper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetDiagHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetDiagHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INetDiagHelper * This,
            /* [in] */ ULONG celt,
            /* [size_is][in] */ __RPC__in_ecount_full(celt) HELPER_ATTRIBUTE rgAttributes[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetDiagnosticsInfo )( 
            INetDiagHelper * This,
            /* [retval][out] */ __RPC__deref_out_opt DiagnosticsInfo **ppInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetKeyAttributes )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **pprgAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *LowHealth )( 
            INetDiagHelper * This,
            /* [unique][string][in] */ __RPC__in_opt LPCWSTR pwszInstanceDescription,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppwszDescription,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out DIAGNOSIS_STATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *HighUtilization )( 
            INetDiagHelper * This,
            /* [unique][string][in] */ __RPC__in_opt LPCWSTR pwszInstanceDescription,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppwszDescription,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out DIAGNOSIS_STATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetLowerHypotheses )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses);
        
        HRESULT ( STDMETHODCALLTYPE *GetDownStreamHypotheses )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses);
        
        HRESULT ( STDMETHODCALLTYPE *GetHigherHypotheses )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses);
        
        HRESULT ( STDMETHODCALLTYPE *GetUpStreamHypotheses )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HYPOTHESIS **pprgHypotheses);
        
        HRESULT ( STDMETHODCALLTYPE *Repair )( 
            INetDiagHelper * This,
            /* [in] */ __RPC__in RepairInfo *pInfo,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out REPAIR_STATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *Validate )( 
            INetDiagHelper * This,
            /* [in] */ PROBLEM_TYPE problem,
            /* [out] */ __RPC__out long *pDeferredTime,
            /* [out] */ __RPC__out REPAIR_STATUS *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetRepairInfo )( 
            INetDiagHelper * This,
            /* [in] */ PROBLEM_TYPE problem,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) RepairInfo **ppInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetLifeTime )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out LIFE_TIME *pLifeTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetLifeTime )( 
            INetDiagHelper * This,
            /* [in] */ LIFE_TIME lifeTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetCacheTime )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out FILETIME *pCacheTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributes )( 
            INetDiagHelper * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **pprgAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            INetDiagHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cleanup )( 
            INetDiagHelper * This);
        
        END_INTERFACE
    } INetDiagHelperVtbl;

    interface INetDiagHelper
    {
        CONST_VTBL struct INetDiagHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetDiagHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetDiagHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetDiagHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetDiagHelper_Initialize(This,celt,rgAttributes)	\
    ( (This)->lpVtbl -> Initialize(This,celt,rgAttributes) ) 

#define INetDiagHelper_GetDiagnosticsInfo(This,ppInfo)	\
    ( (This)->lpVtbl -> GetDiagnosticsInfo(This,ppInfo) ) 

#define INetDiagHelper_GetKeyAttributes(This,pcelt,pprgAttributes)	\
    ( (This)->lpVtbl -> GetKeyAttributes(This,pcelt,pprgAttributes) ) 

#define INetDiagHelper_LowHealth(This,pwszInstanceDescription,ppwszDescription,pDeferredTime,pStatus)	\
    ( (This)->lpVtbl -> LowHealth(This,pwszInstanceDescription,ppwszDescription,pDeferredTime,pStatus) ) 

#define INetDiagHelper_HighUtilization(This,pwszInstanceDescription,ppwszDescription,pDeferredTime,pStatus)	\
    ( (This)->lpVtbl -> HighUtilization(This,pwszInstanceDescription,ppwszDescription,pDeferredTime,pStatus) ) 

#define INetDiagHelper_GetLowerHypotheses(This,pcelt,pprgHypotheses)	\
    ( (This)->lpVtbl -> GetLowerHypotheses(This,pcelt,pprgHypotheses) ) 

#define INetDiagHelper_GetDownStreamHypotheses(This,pcelt,pprgHypotheses)	\
    ( (This)->lpVtbl -> GetDownStreamHypotheses(This,pcelt,pprgHypotheses) ) 

#define INetDiagHelper_GetHigherHypotheses(This,pcelt,pprgHypotheses)	\
    ( (This)->lpVtbl -> GetHigherHypotheses(This,pcelt,pprgHypotheses) ) 

#define INetDiagHelper_GetUpStreamHypotheses(This,pcelt,pprgHypotheses)	\
    ( (This)->lpVtbl -> GetUpStreamHypotheses(This,pcelt,pprgHypotheses) ) 

#define INetDiagHelper_Repair(This,pInfo,pDeferredTime,pStatus)	\
    ( (This)->lpVtbl -> Repair(This,pInfo,pDeferredTime,pStatus) ) 

#define INetDiagHelper_Validate(This,problem,pDeferredTime,pStatus)	\
    ( (This)->lpVtbl -> Validate(This,problem,pDeferredTime,pStatus) ) 

#define INetDiagHelper_GetRepairInfo(This,problem,pcelt,ppInfo)	\
    ( (This)->lpVtbl -> GetRepairInfo(This,problem,pcelt,ppInfo) ) 

#define INetDiagHelper_GetLifeTime(This,pLifeTime)	\
    ( (This)->lpVtbl -> GetLifeTime(This,pLifeTime) ) 

#define INetDiagHelper_SetLifeTime(This,lifeTime)	\
    ( (This)->lpVtbl -> SetLifeTime(This,lifeTime) ) 

#define INetDiagHelper_GetCacheTime(This,pCacheTime)	\
    ( (This)->lpVtbl -> GetCacheTime(This,pCacheTime) ) 

#define INetDiagHelper_GetAttributes(This,pcelt,pprgAttributes)	\
    ( (This)->lpVtbl -> GetAttributes(This,pcelt,pprgAttributes) ) 

#define INetDiagHelper_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define INetDiagHelper_Cleanup(This)	\
    ( (This)->lpVtbl -> Cleanup(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetDiagHelper_INTERFACE_DEFINED__ */


#ifndef __INetDiagHelperInfo_INTERFACE_DEFINED__
#define __INetDiagHelperInfo_INTERFACE_DEFINED__

/* interface INetDiagHelperInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INetDiagHelperInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c0b35747-ebf5-11d8-bbe9-505054503030")
    INetDiagHelperInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttributeInfo( 
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HelperAttributeInfo **pprgAttributeInfos) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetDiagHelperInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetDiagHelperInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetDiagHelperInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetDiagHelperInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributeInfo )( 
            INetDiagHelperInfo * This,
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HelperAttributeInfo **pprgAttributeInfos);
        
        END_INTERFACE
    } INetDiagHelperInfoVtbl;

    interface INetDiagHelperInfo
    {
        CONST_VTBL struct INetDiagHelperInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetDiagHelperInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetDiagHelperInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetDiagHelperInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetDiagHelperInfo_GetAttributeInfo(This,pcelt,pprgAttributeInfos)	\
    ( (This)->lpVtbl -> GetAttributeInfo(This,pcelt,pprgAttributeInfos) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetDiagHelperInfo_INTERFACE_DEFINED__ */


#ifndef __INetDiagExtensibleHelper_INTERFACE_DEFINED__
#define __INetDiagExtensibleHelper_INTERFACE_DEFINED__

/* interface INetDiagExtensibleHelper */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_INetDiagExtensibleHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c0b35748-ebf5-11d8-bbe9-505054503030")
    INetDiagExtensibleHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResolveAttributes( 
            /* [in] */ ULONG celt,
            /* [size_is][in] */ __RPC__in_ecount_full(celt) HELPER_ATTRIBUTE rgKeyAttributes[  ],
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **prgMatchValues) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetDiagExtensibleHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetDiagExtensibleHelper * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetDiagExtensibleHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetDiagExtensibleHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResolveAttributes )( 
            INetDiagExtensibleHelper * This,
            /* [in] */ ULONG celt,
            /* [size_is][in] */ __RPC__in_ecount_full(celt) HELPER_ATTRIBUTE rgKeyAttributes[  ],
            /* [out] */ __RPC__out ULONG *pcelt,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*pcelt) HELPER_ATTRIBUTE **prgMatchValues);
        
        END_INTERFACE
    } INetDiagExtensibleHelperVtbl;

    interface INetDiagExtensibleHelper
    {
        CONST_VTBL struct INetDiagExtensibleHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetDiagExtensibleHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetDiagExtensibleHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetDiagExtensibleHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetDiagExtensibleHelper_ResolveAttributes(This,celt,rgKeyAttributes,pcelt,prgMatchValues)	\
    ( (This)->lpVtbl -> ResolveAttributes(This,celt,rgKeyAttributes,pcelt,prgMatchValues) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetDiagExtensibleHelper_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



