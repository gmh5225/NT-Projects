

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for napenforcementclient.idl:
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

#ifndef __napenforcementclient_h__
#define __napenforcementclient_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INapEnforcementClientBinding_FWD_DEFINED__
#define __INapEnforcementClientBinding_FWD_DEFINED__
typedef interface INapEnforcementClientBinding INapEnforcementClientBinding;
#endif 	/* __INapEnforcementClientBinding_FWD_DEFINED__ */


#ifndef __INapEnforcementClientCallback_FWD_DEFINED__
#define __INapEnforcementClientCallback_FWD_DEFINED__
typedef interface INapEnforcementClientCallback INapEnforcementClientCallback;
#endif 	/* __INapEnforcementClientCallback_FWD_DEFINED__ */


#ifndef __INapEnforcementClientConnection_FWD_DEFINED__
#define __INapEnforcementClientConnection_FWD_DEFINED__
typedef interface INapEnforcementClientConnection INapEnforcementClientConnection;
#endif 	/* __INapEnforcementClientConnection_FWD_DEFINED__ */


/* header files for imported files */
#include "NapTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_napenforcementclient_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_napenforcementclient_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napenforcementclient_0000_0000_v0_0_s_ifspec;

#ifndef __INapEnforcementClientBinding_INTERFACE_DEFINED__
#define __INapEnforcementClientBinding_INTERFACE_DEFINED__

/* interface INapEnforcementClientBinding */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapEnforcementClientBinding;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92B93223-7487-42d9-9A91-5B8507720384")
    INapEnforcementClientBinding : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ EnforcementEntityId id,
            /* [in] */ __RPC__in_opt INapEnforcementClientCallback *callback) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uninitialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateConnection( 
            /* [out] */ __RPC__deref_out_opt INapEnforcementClientConnection **connection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoHRequest( 
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *connection,
            /* [out] */ __RPC__out BOOL *retriggerHint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessSoHResponse( 
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *connection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifyConnectionStateDown( 
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *downCxn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NotifySoHChangeFailure( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapEnforcementClientBindingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapEnforcementClientBinding * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapEnforcementClientBinding * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapEnforcementClientBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INapEnforcementClientBinding * This,
            /* [in] */ EnforcementEntityId id,
            /* [in] */ __RPC__in_opt INapEnforcementClientCallback *callback);
        
        HRESULT ( STDMETHODCALLTYPE *Uninitialize )( 
            INapEnforcementClientBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateConnection )( 
            INapEnforcementClientBinding * This,
            /* [out] */ __RPC__deref_out_opt INapEnforcementClientConnection **connection);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHRequest )( 
            INapEnforcementClientBinding * This,
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *connection,
            /* [out] */ __RPC__out BOOL *retriggerHint);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSoHResponse )( 
            INapEnforcementClientBinding * This,
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *connection);
        
        HRESULT ( STDMETHODCALLTYPE *NotifyConnectionStateDown )( 
            INapEnforcementClientBinding * This,
            /* [in] */ __RPC__in_opt INapEnforcementClientConnection *downCxn);
        
        HRESULT ( STDMETHODCALLTYPE *NotifySoHChangeFailure )( 
            INapEnforcementClientBinding * This);
        
        END_INTERFACE
    } INapEnforcementClientBindingVtbl;

    interface INapEnforcementClientBinding
    {
        CONST_VTBL struct INapEnforcementClientBindingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapEnforcementClientBinding_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapEnforcementClientBinding_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapEnforcementClientBinding_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapEnforcementClientBinding_Initialize(This,id,callback)	\
    ( (This)->lpVtbl -> Initialize(This,id,callback) ) 

#define INapEnforcementClientBinding_Uninitialize(This)	\
    ( (This)->lpVtbl -> Uninitialize(This) ) 

#define INapEnforcementClientBinding_CreateConnection(This,connection)	\
    ( (This)->lpVtbl -> CreateConnection(This,connection) ) 

#define INapEnforcementClientBinding_GetSoHRequest(This,connection,retriggerHint)	\
    ( (This)->lpVtbl -> GetSoHRequest(This,connection,retriggerHint) ) 

#define INapEnforcementClientBinding_ProcessSoHResponse(This,connection)	\
    ( (This)->lpVtbl -> ProcessSoHResponse(This,connection) ) 

#define INapEnforcementClientBinding_NotifyConnectionStateDown(This,downCxn)	\
    ( (This)->lpVtbl -> NotifyConnectionStateDown(This,downCxn) ) 

#define INapEnforcementClientBinding_NotifySoHChangeFailure(This)	\
    ( (This)->lpVtbl -> NotifySoHChangeFailure(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapEnforcementClientBinding_INTERFACE_DEFINED__ */


#ifndef __INapEnforcementClientCallback_INTERFACE_DEFINED__
#define __INapEnforcementClientCallback_INTERFACE_DEFINED__

/* interface INapEnforcementClientCallback */
/* [unique][uuid][object] */ 

typedef struct tagConnections
    {
    UINT16 count;
    INapEnforcementClientConnection **connections;
    } 	Connections;


EXTERN_C const IID IID_INapEnforcementClientCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5A0B90A-83A1-4f76-BA3F-025418682814")
    INapEnforcementClientCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NotifySoHChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnections( 
            /* [out] */ __RPC__deref_out_opt Connections **connections) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapEnforcementClientCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapEnforcementClientCallback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapEnforcementClientCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapEnforcementClientCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *NotifySoHChange )( 
            INapEnforcementClientCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnections )( 
            INapEnforcementClientCallback * This,
            /* [out] */ __RPC__deref_out_opt Connections **connections);
        
        END_INTERFACE
    } INapEnforcementClientCallbackVtbl;

    interface INapEnforcementClientCallback
    {
        CONST_VTBL struct INapEnforcementClientCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapEnforcementClientCallback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapEnforcementClientCallback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapEnforcementClientCallback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapEnforcementClientCallback_NotifySoHChange(This)	\
    ( (This)->lpVtbl -> NotifySoHChange(This) ) 

#define INapEnforcementClientCallback_GetConnections(This,connections)	\
    ( (This)->lpVtbl -> GetConnections(This,connections) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapEnforcementClientCallback_INTERFACE_DEFINED__ */


#ifndef __INapEnforcementClientConnection_INTERFACE_DEFINED__
#define __INapEnforcementClientConnection_INTERFACE_DEFINED__

/* interface INapEnforcementClientConnection */
/* [unique][uuid][object] */ 

#define	defaultProtocolMaxSize	( 4096 )

#define	minProtocolMaxSize	( 300 )

#define	maxProtocolMaxSize	( 0xffff )

typedef /* [range] */ UINT32 ProtocolMaxSize;


EXTERN_C const IID IID_INapEnforcementClientConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB3A3505-DDB1-468a-B307-F328A57419D8")
    INapEnforcementClientConnection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ EnforcementEntityId id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSize( 
            /* [in] */ ProtocolMaxSize maxSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxSize( 
            /* [out] */ __RPC__out ProtocolMaxSize *maxSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFlags( 
            /* [in] */ UINT8 flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [out] */ __RPC__out UINT8 *flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConnectionId( 
            /* [in] */ __RPC__in const ConnectionId *connectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectionId( 
            /* [out] */ __RPC__deref_out_opt ConnectionId **connectionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCorrelationId( 
            /* [out] */ __RPC__out CorrelationId *correlationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringCorrelationId( 
            /* [out] */ __RPC__deref_out_opt StringCorrelationId **correlationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCorrelationId( 
            /* [in] */ CorrelationId correlationId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSoHRequest( 
            /* [unique][in] */ __RPC__in_opt const NetworkSoHRequest *sohRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoHRequest( 
            /* [out] */ __RPC__deref_out_opt NetworkSoHRequest **sohRequest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSoHResponse( 
            /* [in] */ __RPC__in const NetworkSoHResponse *sohResponse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSoHResponse( 
            /* [out] */ __RPC__deref_out_opt NetworkSoHResponse **sohResponse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsolationInfo( 
            /* [in] */ __RPC__in const IsolationInfo *isolationInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIsolationInfo( 
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrivateData( 
            /* [in] */ __RPC__in const PrivateData *privateData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrivateData( 
            /* [out] */ __RPC__deref_out_opt PrivateData **privateData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnforcerPrivateData( 
            /* [in] */ __RPC__in const PrivateData *privateData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnforcerPrivateData( 
            /* [out] */ __RPC__deref_out_opt PrivateData **privateData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapEnforcementClientConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapEnforcementClientConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapEnforcementClientConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            INapEnforcementClientConnection * This,
            /* [in] */ EnforcementEntityId id);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxSize )( 
            INapEnforcementClientConnection * This,
            /* [in] */ ProtocolMaxSize maxSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxSize )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__out ProtocolMaxSize *maxSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetFlags )( 
            INapEnforcementClientConnection * This,
            /* [in] */ UINT8 flags);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__out UINT8 *flags);
        
        HRESULT ( STDMETHODCALLTYPE *SetConnectionId )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in const ConnectionId *connectionId);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectionId )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt ConnectionId **connectionId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCorrelationId )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__out CorrelationId *correlationId);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringCorrelationId )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt StringCorrelationId **correlationId);
        
        HRESULT ( STDMETHODCALLTYPE *SetCorrelationId )( 
            INapEnforcementClientConnection * This,
            /* [in] */ CorrelationId correlationId);
        
        HRESULT ( STDMETHODCALLTYPE *SetSoHRequest )( 
            INapEnforcementClientConnection * This,
            /* [unique][in] */ __RPC__in_opt const NetworkSoHRequest *sohRequest);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHRequest )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt NetworkSoHRequest **sohRequest);
        
        HRESULT ( STDMETHODCALLTYPE *SetSoHResponse )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in const NetworkSoHResponse *sohResponse);
        
        HRESULT ( STDMETHODCALLTYPE *GetSoHResponse )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt NetworkSoHResponse **sohResponse);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsolationInfo )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in const IsolationInfo *isolationInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIsolationInfo )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrivateData )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in const PrivateData *privateData);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrivateData )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt PrivateData **privateData);
        
        HRESULT ( STDMETHODCALLTYPE *SetEnforcerPrivateData )( 
            INapEnforcementClientConnection * This,
            /* [in] */ __RPC__in const PrivateData *privateData);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnforcerPrivateData )( 
            INapEnforcementClientConnection * This,
            /* [out] */ __RPC__deref_out_opt PrivateData **privateData);
        
        END_INTERFACE
    } INapEnforcementClientConnectionVtbl;

    interface INapEnforcementClientConnection
    {
        CONST_VTBL struct INapEnforcementClientConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapEnforcementClientConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapEnforcementClientConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapEnforcementClientConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapEnforcementClientConnection_Initialize(This,id)	\
    ( (This)->lpVtbl -> Initialize(This,id) ) 

#define INapEnforcementClientConnection_SetMaxSize(This,maxSize)	\
    ( (This)->lpVtbl -> SetMaxSize(This,maxSize) ) 

#define INapEnforcementClientConnection_GetMaxSize(This,maxSize)	\
    ( (This)->lpVtbl -> GetMaxSize(This,maxSize) ) 

#define INapEnforcementClientConnection_SetFlags(This,flags)	\
    ( (This)->lpVtbl -> SetFlags(This,flags) ) 

#define INapEnforcementClientConnection_GetFlags(This,flags)	\
    ( (This)->lpVtbl -> GetFlags(This,flags) ) 

#define INapEnforcementClientConnection_SetConnectionId(This,connectionId)	\
    ( (This)->lpVtbl -> SetConnectionId(This,connectionId) ) 

#define INapEnforcementClientConnection_GetConnectionId(This,connectionId)	\
    ( (This)->lpVtbl -> GetConnectionId(This,connectionId) ) 

#define INapEnforcementClientConnection_GetCorrelationId(This,correlationId)	\
    ( (This)->lpVtbl -> GetCorrelationId(This,correlationId) ) 

#define INapEnforcementClientConnection_GetStringCorrelationId(This,correlationId)	\
    ( (This)->lpVtbl -> GetStringCorrelationId(This,correlationId) ) 

#define INapEnforcementClientConnection_SetCorrelationId(This,correlationId)	\
    ( (This)->lpVtbl -> SetCorrelationId(This,correlationId) ) 

#define INapEnforcementClientConnection_SetSoHRequest(This,sohRequest)	\
    ( (This)->lpVtbl -> SetSoHRequest(This,sohRequest) ) 

#define INapEnforcementClientConnection_GetSoHRequest(This,sohRequest)	\
    ( (This)->lpVtbl -> GetSoHRequest(This,sohRequest) ) 

#define INapEnforcementClientConnection_SetSoHResponse(This,sohResponse)	\
    ( (This)->lpVtbl -> SetSoHResponse(This,sohResponse) ) 

#define INapEnforcementClientConnection_GetSoHResponse(This,sohResponse)	\
    ( (This)->lpVtbl -> GetSoHResponse(This,sohResponse) ) 

#define INapEnforcementClientConnection_SetIsolationInfo(This,isolationInfo)	\
    ( (This)->lpVtbl -> SetIsolationInfo(This,isolationInfo) ) 

#define INapEnforcementClientConnection_GetIsolationInfo(This,isolationInfo)	\
    ( (This)->lpVtbl -> GetIsolationInfo(This,isolationInfo) ) 

#define INapEnforcementClientConnection_SetPrivateData(This,privateData)	\
    ( (This)->lpVtbl -> SetPrivateData(This,privateData) ) 

#define INapEnforcementClientConnection_GetPrivateData(This,privateData)	\
    ( (This)->lpVtbl -> GetPrivateData(This,privateData) ) 

#define INapEnforcementClientConnection_SetEnforcerPrivateData(This,privateData)	\
    ( (This)->lpVtbl -> SetEnforcerPrivateData(This,privateData) ) 

#define INapEnforcementClientConnection_GetEnforcerPrivateData(This,privateData)	\
    ( (This)->lpVtbl -> GetEnforcerPrivateData(This,privateData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapEnforcementClientConnection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_napenforcementclient_0000_0003 */
/* [local] */ 

// Declarations of CLSIDs of objects provided  
// by the system. Link to uuid.lib to get them 
// defined.                                    
EXTERN_C const CLSID 
   CLSID_NapEnforcementClientBinding;


extern RPC_IF_HANDLE __MIDL_itf_napenforcementclient_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napenforcementclient_0000_0003_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



