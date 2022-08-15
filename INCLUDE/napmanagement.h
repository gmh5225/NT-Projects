

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for napmanagement.idl:
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

#ifndef __napmanagement_h__
#define __napmanagement_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INapClientManagement_FWD_DEFINED__
#define __INapClientManagement_FWD_DEFINED__
typedef interface INapClientManagement INapClientManagement;
#endif 	/* __INapClientManagement_FWD_DEFINED__ */


/* header files for imported files */
#include "NapTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __INapClientManagement_INTERFACE_DEFINED__
#define __INapClientManagement_INTERFACE_DEFINED__

/* interface INapClientManagement */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapClientManagement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("432a1da5-3888-4b9a-a734-cff1e448c5b9")
    INapClientManagement : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNapClientInfo( 
            /* [out] */ __RPC__out BOOL *isNapEnabled,
            /* [out] */ __RPC__deref_out_opt CountedString **clientName,
            /* [out] */ __RPC__deref_out_opt CountedString **clientDescription,
            /* [out] */ __RPC__deref_out_opt CountedString **protocolVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSystemIsolationInfo( 
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo,
            /* [out] */ __RPC__out BOOL *unknownConnections) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterSystemHealthAgent( 
            /* [in] */ __RPC__in const NapComponentRegistrationInfo *agent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterSystemHealthAgent( 
            /* [in] */ SystemHealthEntityId id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterEnforcementClient( 
            /* [in] */ __RPC__in const NapComponentRegistrationInfo *enforcer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterEnforcementClient( 
            /* [in] */ EnforcementEntityId id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisteredSystemHealthAgents( 
            /* [out] */ __RPC__out SystemHealthEntityCount *count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*count) NapComponentRegistrationInfo **agents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisteredEnforcementClients( 
            /* [out] */ __RPC__out EnforcementEntityCount *count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*count) NapComponentRegistrationInfo **enforcers) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapClientManagementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapClientManagement * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapClientManagement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapClientManagement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNapClientInfo )( 
            INapClientManagement * This,
            /* [out] */ __RPC__out BOOL *isNapEnabled,
            /* [out] */ __RPC__deref_out_opt CountedString **clientName,
            /* [out] */ __RPC__deref_out_opt CountedString **clientDescription,
            /* [out] */ __RPC__deref_out_opt CountedString **protocolVersion);
        
        HRESULT ( STDMETHODCALLTYPE *GetSystemIsolationInfo )( 
            INapClientManagement * This,
            /* [out] */ __RPC__deref_out_opt IsolationInfo **isolationInfo,
            /* [out] */ __RPC__out BOOL *unknownConnections);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterSystemHealthAgent )( 
            INapClientManagement * This,
            /* [in] */ __RPC__in const NapComponentRegistrationInfo *agent);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterSystemHealthAgent )( 
            INapClientManagement * This,
            /* [in] */ SystemHealthEntityId id);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterEnforcementClient )( 
            INapClientManagement * This,
            /* [in] */ __RPC__in const NapComponentRegistrationInfo *enforcer);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterEnforcementClient )( 
            INapClientManagement * This,
            /* [in] */ EnforcementEntityId id);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisteredSystemHealthAgents )( 
            INapClientManagement * This,
            /* [out] */ __RPC__out SystemHealthEntityCount *count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*count) NapComponentRegistrationInfo **agents);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisteredEnforcementClients )( 
            INapClientManagement * This,
            /* [out] */ __RPC__out EnforcementEntityCount *count,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*count) NapComponentRegistrationInfo **enforcers);
        
        END_INTERFACE
    } INapClientManagementVtbl;

    interface INapClientManagement
    {
        CONST_VTBL struct INapClientManagementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapClientManagement_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapClientManagement_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapClientManagement_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapClientManagement_GetNapClientInfo(This,isNapEnabled,clientName,clientDescription,protocolVersion)	\
    ( (This)->lpVtbl -> GetNapClientInfo(This,isNapEnabled,clientName,clientDescription,protocolVersion) ) 

#define INapClientManagement_GetSystemIsolationInfo(This,isolationInfo,unknownConnections)	\
    ( (This)->lpVtbl -> GetSystemIsolationInfo(This,isolationInfo,unknownConnections) ) 

#define INapClientManagement_RegisterSystemHealthAgent(This,agent)	\
    ( (This)->lpVtbl -> RegisterSystemHealthAgent(This,agent) ) 

#define INapClientManagement_UnregisterSystemHealthAgent(This,id)	\
    ( (This)->lpVtbl -> UnregisterSystemHealthAgent(This,id) ) 

#define INapClientManagement_RegisterEnforcementClient(This,enforcer)	\
    ( (This)->lpVtbl -> RegisterEnforcementClient(This,enforcer) ) 

#define INapClientManagement_UnregisterEnforcementClient(This,id)	\
    ( (This)->lpVtbl -> UnregisterEnforcementClient(This,id) ) 

#define INapClientManagement_GetRegisteredSystemHealthAgents(This,count,agents)	\
    ( (This)->lpVtbl -> GetRegisteredSystemHealthAgents(This,count,agents) ) 

#define INapClientManagement_GetRegisteredEnforcementClients(This,count,enforcers)	\
    ( (This)->lpVtbl -> GetRegisteredEnforcementClients(This,count,enforcers) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapClientManagement_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_napmanagement_0000_0001 */
/* [local] */ 

// Declarations of CLSIDs of objects provided  
// by the system. Link to uuid.lib to get them 
// defined.                                    
EXTERN_C const CLSID 
   CLSID_NapClientManagement;


extern RPC_IF_HANDLE __MIDL_itf_napmanagement_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napmanagement_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



