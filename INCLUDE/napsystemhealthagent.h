

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for napsystemhealthagent.idl:
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

#ifndef __napsystemhealthagent_h__
#define __napsystemhealthagent_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INapSystemHealthAgentBinding_FWD_DEFINED__
#define __INapSystemHealthAgentBinding_FWD_DEFINED__
typedef interface INapSystemHealthAgentBinding INapSystemHealthAgentBinding;
#endif 	/* __INapSystemHealthAgentBinding_FWD_DEFINED__ */


#ifndef __INapSystemHealthAgentCallback_FWD_DEFINED__
#define __INapSystemHealthAgentCallback_FWD_DEFINED__
typedef interface INapSystemHealthAgentCallback INapSystemHealthAgentCallback;
#endif 	/* __INapSystemHealthAgentCallback_FWD_DEFINED__ */


#ifndef __INapSystemHealthAgentRequest_FWD_DEFINED__
#define __INapSystemHealthAgentRequest_FWD_DEFINED__
typedef interface INapSystemHealthAgentRequest INapSystemHealthAgentRequest;
#endif 	/* __INapSystemHealthAgentRequest_FWD_DEFINED__ */


/* header files for imported files */
#include "NapTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_napsystemhealthagent_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0000_v0_0_s_ifspec;

#ifndef __INapSystemHealthAgentBinding_INTERFACE_DEFINED__
#define __INapSystemHealthAgentBinding_INTERFACE_DEFINED__

/* interface INapSystemHealthAgentBinding */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapSystemHealthAgentBinding;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6894F43-9CC7-44c9-A23F-19DBF36BAD28")
    INapSystemHealthAgentBinding : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ SystemHealthEntityId id,
            /* [in] */ __RPC__in_opt INapSystemHealthAgentCallback *callback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifySoHChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSystemIsolationInfo( 
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo,
            /* [out] */ __RPC__out BOOL *unknownConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushCache( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapSystemHealthAgentBindingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapSystemHealthAgentBinding * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapSystemHealthAgentBinding * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapSystemHealthAgentBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INapSystemHealthAgentBinding * This,
            /* [in] */ SystemHealthEntityId id,
            /* [in] */ __RPC__in_opt INapSystemHealthAgentCallback *callback);
        
        HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            INapSystemHealthAgentBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *NotifySoHChange )( 
            INapSystemHealthAgentBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSystemIsolationInfo )( 
            INapSystemHealthAgentBinding * This,
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo,
            /* [out] */ __RPC__out BOOL *unknownConnections);
        
        HRESULT ( STDMETHODCALLTYPE *FlushCache )( 
            INapSystemHealthAgentBinding * This);
        
        END_INTERFACE
    } INapSystemHealthAgentBindingVtbl;

    interface INapSystemHealthAgentBinding
    {
        CONST_VTBL struct INapSystemHealthAgentBindingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapSystemHealthAgentBinding_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapSystemHealthAgentBinding_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapSystemHealthAgentBinding_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapSystemHealthAgentBinding_Initialize(This,id,callback)	\
    ( (This)->lpVtbl -> Initialize(This,id,callback) ) 

#define INapSystemHealthAgentBinding_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define INapSystemHealthAgentBinding_NotifySoHChange(This)	\
    ( (This)->lpVtbl -> NotifySoHChange(This) ) 

#define INapSystemHealthAgentBinding_GetSystemIsolationInfo(This,isolationInfo,unknownConnections)	\
    ( (This)->lpVtbl -> GetSystemIsolationInfo(This,isolationInfo,unknownConnections) ) 

#define INapSystemHealthAgentBinding_FlushCache(This)	\
    ( (This)->lpVtbl -> FlushCache(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapSystemHealthAgentBinding_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_napsystemhealthagent_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0001_v0_0_s_ifspec;

#ifndef __INapSystemHealthAgentCallback_INTERFACE_DEFINED__
#define __INapSystemHealthAgentCallback_INTERFACE_DEFINED__

/* interface INapSystemHealthAgentCallback */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapSystemHealthAgentCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1072A57-214F-4ee2-8377-14EF140CD9F3")
    INapSystemHealthAgentCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSoHRequest( 
            /* [in] */ __RPC__in_opt INapSystemHealthAgentRequest *request) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessSoHResponse( 
            /* [in] */ __RPC__in_opt INapSystemHealthAgentRequest *request) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifySystemIsolationStateChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFixupInfo( 
            /* [out] */ __RPC__deref_out_opt FixupInfo **info) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareSoHRequests( 
            /* [in] */ __RPC__in const SoHRequest *lhs,
            /* [in] */ __RPC__in const SoHRequest *rhs,
            /* [out] */ __RPC__out BOOL *isEqual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyOrphanedSoHRequest( 
            /* [in] */ __RPC__in const CorrelationId *correlationId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapSystemHealthAgentCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapSystemHealthAgentCallback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapSystemHealthAgentCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapSystemHealthAgentCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHRequest )( 
            INapSystemHealthAgentCallback * This,
            /* [in] */ __RPC__in_opt INapSystemHealthAgentRequest *request);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSoHResponse )( 
            INapSystemHealthAgentCallback * This,
            /* [in] */ __RPC__in_opt INapSystemHealthAgentRequest *request);
        
        HRESULT ( STDMETHODCALLTYPE *NotifySystemIsolationStateChange )( 
            INapSystemHealthAgentCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFixupInfo )( 
            INapSystemHealthAgentCallback * This,
            /* [out] */ __RPC__deref_out_opt FixupInfo **info);
        
        HRESULT ( STDMETHODCALLTYPE *CompareSoHRequests )( 
            INapSystemHealthAgentCallback * This,
            /* [in] */ __RPC__in const SoHRequest *lhs,
            /* [in] */ __RPC__in const SoHRequest *rhs,
            /* [out] */ __RPC__out BOOL *isEqual);
        
        HRESULT ( STDMETHODCALLTYPE *NotifyOrphanedSoHRequest )( 
            INapSystemHealthAgentCallback * This,
            /* [in] */ __RPC__in const CorrelationId *correlationId);
        
        END_INTERFACE
    } INapSystemHealthAgentCallbackVtbl;

    interface INapSystemHealthAgentCallback
    {
        CONST_VTBL struct INapSystemHealthAgentCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapSystemHealthAgentCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapSystemHealthAgentCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapSystemHealthAgentCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapSystemHealthAgentCallback_GetSoHRequest(This,request)	\
    ( (This)->lpVtbl -> GetSoHRequest(This,request) ) 

#define INapSystemHealthAgentCallback_ProcessSoHResponse(This,request)	\
    ( (This)->lpVtbl -> ProcessSoHResponse(This,request) ) 

#define INapSystemHealthAgentCallback_NotifySystemIsolationStateChange(This)	\
    ( (This)->lpVtbl -> NotifySystemIsolationStateChange(This) ) 

#define INapSystemHealthAgentCallback_GetFixupInfo(This,info)	\
    ( (This)->lpVtbl -> GetFixupInfo(This,info) ) 

#define INapSystemHealthAgentCallback_CompareSoHRequests(This,lhs,rhs,isEqual)	\
    ( (This)->lpVtbl -> CompareSoHRequests(This,lhs,rhs,isEqual) ) 

#define INapSystemHealthAgentCallback_NotifyOrphanedSoHRequest(This,correlationId)	\
    ( (This)->lpVtbl -> NotifyOrphanedSoHRequest(This,correlationId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapSystemHealthAgentCallback_INTERFACE_DEFINED__ */


#ifndef __INapSystemHealthAgentRequest_INTERFACE_DEFINED__
#define __INapSystemHealthAgentRequest_INTERFACE_DEFINED__

/* interface INapSystemHealthAgentRequest */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapSystemHealthAgentRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B360A69-212D-440d-B398-7EEFD497853A")
    INapSystemHealthAgentRequest : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCorrelationId( 
            /* [out] */ __RPC__out CorrelationId *correlationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringCorrelationId( 
            /* [out] */ __RPC__deref_out_opt StringCorrelationId **correlationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSoHRequest( 
            /* [in] */ __RPC__in const SoHRequest *sohRequest,
            /* [in] */ BOOL cacheSohForLaterUse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoHRequest( 
            /* [out] */ __RPC__deref_out_opt SoHRequest **sohRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoHResponse( 
            /* [out] */ __RPC__deref_out_opt SoHResponse **sohResponse,
            /* [out] */ __RPC__out UINT8 *flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCacheSoHFlag( 
            __RPC__in BOOL *cacheSohForLaterUse) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapSystemHealthAgentRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapSystemHealthAgentRequest * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapSystemHealthAgentRequest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapSystemHealthAgentRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCorrelationId )( 
            INapSystemHealthAgentRequest * This,
            /* [out] */ __RPC__out CorrelationId *correlationId);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringCorrelationId )( 
            INapSystemHealthAgentRequest * This,
            /* [out] */ __RPC__deref_out_opt StringCorrelationId **correlationId);
        
        HRESULT ( STDMETHODCALLTYPE *SetSoHRequest )( 
            INapSystemHealthAgentRequest * This,
            /* [in] */ __RPC__in const SoHRequest *sohRequest,
            /* [in] */ BOOL cacheSohForLaterUse);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHRequest )( 
            INapSystemHealthAgentRequest * This,
            /* [out] */ __RPC__deref_out_opt SoHRequest **sohRequest);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHResponse )( 
            INapSystemHealthAgentRequest * This,
            /* [out] */ __RPC__deref_out_opt SoHResponse **sohResponse,
            /* [out] */ __RPC__out UINT8 *flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetCacheSoHFlag )( 
            INapSystemHealthAgentRequest * This,
            __RPC__in BOOL *cacheSohForLaterUse);
        
        END_INTERFACE
    } INapSystemHealthAgentRequestVtbl;

    interface INapSystemHealthAgentRequest
    {
        CONST_VTBL struct INapSystemHealthAgentRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapSystemHealthAgentRequest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapSystemHealthAgentRequest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapSystemHealthAgentRequest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapSystemHealthAgentRequest_GetCorrelationId(This,correlationId)	\
    ( (This)->lpVtbl -> GetCorrelationId(This,correlationId) ) 

#define INapSystemHealthAgentRequest_GetStringCorrelationId(This,correlationId)	\
    ( (This)->lpVtbl -> GetStringCorrelationId(This,correlationId) ) 

#define INapSystemHealthAgentRequest_SetSoHRequest(This,sohRequest,cacheSohForLaterUse)	\
    ( (This)->lpVtbl -> SetSoHRequest(This,sohRequest,cacheSohForLaterUse) ) 

#define INapSystemHealthAgentRequest_GetSoHRequest(This,sohRequest)	\
    ( (This)->lpVtbl -> GetSoHRequest(This,sohRequest) ) 

#define INapSystemHealthAgentRequest_GetSoHResponse(This,sohResponse,flags)	\
    ( (This)->lpVtbl -> GetSoHResponse(This,sohResponse,flags) ) 

#define INapSystemHealthAgentRequest_GetCacheSoHFlag(This,cacheSohForLaterUse)	\
    ( (This)->lpVtbl -> GetCacheSoHFlag(This,cacheSohForLaterUse) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapSystemHealthAgentRequest_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_napsystemhealthagent_0000_0003 */
/* [local] */ 

// Declarations of CLSIDs of objects provided  
// by the system. Link to uuid.lib to get them 
// defined.                                    
EXTERN_C const CLSID 
   CLSID_NapSystemHealthAgentBinding;


extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napsystemhealthagent_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



