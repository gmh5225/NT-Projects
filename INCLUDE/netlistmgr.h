

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for netlistmgr.idl:
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

#ifndef __netlistmgr_h__
#define __netlistmgr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INetworkListManager_FWD_DEFINED__
#define __INetworkListManager_FWD_DEFINED__
typedef interface INetworkListManager INetworkListManager;
#endif 	/* __INetworkListManager_FWD_DEFINED__ */


#ifndef __INetworkListManagerEvents_FWD_DEFINED__
#define __INetworkListManagerEvents_FWD_DEFINED__
typedef interface INetworkListManagerEvents INetworkListManagerEvents;
#endif 	/* __INetworkListManagerEvents_FWD_DEFINED__ */


#ifndef __INetwork_FWD_DEFINED__
#define __INetwork_FWD_DEFINED__
typedef interface INetwork INetwork;
#endif 	/* __INetwork_FWD_DEFINED__ */


#ifndef __IEnumNetworks_FWD_DEFINED__
#define __IEnumNetworks_FWD_DEFINED__
typedef interface IEnumNetworks IEnumNetworks;
#endif 	/* __IEnumNetworks_FWD_DEFINED__ */


#ifndef __INetworkEvents_FWD_DEFINED__
#define __INetworkEvents_FWD_DEFINED__
typedef interface INetworkEvents INetworkEvents;
#endif 	/* __INetworkEvents_FWD_DEFINED__ */


#ifndef __INetworkConnection_FWD_DEFINED__
#define __INetworkConnection_FWD_DEFINED__
typedef interface INetworkConnection INetworkConnection;
#endif 	/* __INetworkConnection_FWD_DEFINED__ */


#ifndef __IEnumNetworkConnections_FWD_DEFINED__
#define __IEnumNetworkConnections_FWD_DEFINED__
typedef interface IEnumNetworkConnections IEnumNetworkConnections;
#endif 	/* __IEnumNetworkConnections_FWD_DEFINED__ */


#ifndef __INetworkConnectionEvents_FWD_DEFINED__
#define __INetworkConnectionEvents_FWD_DEFINED__
typedef interface INetworkConnectionEvents INetworkConnectionEvents;
#endif 	/* __INetworkConnectionEvents_FWD_DEFINED__ */


#ifndef __NetworkListManager_FWD_DEFINED__
#define __NetworkListManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetworkListManager NetworkListManager;
#else
typedef struct NetworkListManager NetworkListManager;
#endif /* __cplusplus */

#endif 	/* __NetworkListManager_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_netlistmgr_0000_0000 */
/* [local] */ 









#define NA_DomainAuthenticationFailed  L"NA_DomainAuthenticationFailed"
#define NA_NetworkClass  L"NA_NetworkClass"
#define NA_NameSetByPolicy  L"NA_NameSetByPolicy"
#define NA_IconSetByPolicy  L"NA_IconSetByPolicy"
#define NA_DescriptionSetByPolicy  L"NA_DescriptionSetByPolicy"
#define NA_CategorySetByPolicy  L"NA_CategorySetByPolicy"
#define NA_NameReadOnly  L"NA_NameReadOnly"
#define NA_IconReadOnly  L"NA_IconReadOnly"
#define NA_DescriptionReadOnly  L"NA_DescriptionReadOnly"
#define NA_CategoryReadOnly  L"NA_CategoryReadOnly"
#define NA_AllowMerge  L"NA_AllowMerge"
typedef /* [v1_enum] */ 
enum NLM_NETWORK_CLASS
    {	NLM_NETWORK_IDENTIFYING	= 0x1,
	NLM_NETWORK_IDENTIFIED	= 0x2,
	NLM_NETWORK_UNIDENTIFIED	= 0x3
    } 	NLM_NETWORK_CLASS;

typedef /* [v1_enum] */ 
enum NLM_CONNECTIVITY
    {	NLM_CONNECTIVITY_DISCONNECTED	= 0,
	NLM_CONNECTIVITY_IPV4_NOTRAFFIC	= 0x1,
	NLM_CONNECTIVITY_IPV6_NOTRAFFIC	= 0x2,
	NLM_CONNECTIVITY_IPV4_SUBNET	= 0x10,
	NLM_CONNECTIVITY_IPV4_LOCALNETWORK	= 0x20,
	NLM_CONNECTIVITY_IPV4_INTERNET	= 0x40,
	NLM_CONNECTIVITY_IPV6_SUBNET	= 0x100,
	NLM_CONNECTIVITY_IPV6_LOCALNETWORK	= 0x200,
	NLM_CONNECTIVITY_IPV6_INTERNET	= 0x400
    } 	NLM_CONNECTIVITY;

typedef 
enum NLM_DOMAIN_TYPE
    {	NLM_DOMAIN_TYPE_NON_DOMAIN_NETWORK	= 0,
	NLM_DOMAIN_TYPE_DOMAIN_NETWORK	= 0x1,
	NLM_DOMAIN_TYPE_DOMAIN_AUTHENTICATED	= 0x2
    } 	NLM_DOMAIN_TYPE;



extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netlistmgr_0000_0000_v0_0_s_ifspec;

#ifndef __INetworkListManager_INTERFACE_DEFINED__
#define __INetworkListManager_INTERFACE_DEFINED__

/* interface INetworkListManager */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 

typedef /* [v1_enum] */ 
enum NLM_ENUM_NETWORK
    {	NLM_ENUM_NETWORK_CONNECTED	= 0x1,
	NLM_ENUM_NETWORK_DISCONNECTED	= 0x2,
	NLM_ENUM_NETWORK_ALL	= 0x3
    } 	NLM_ENUM_NETWORK;


EXTERN_C const IID IID_INetworkListManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00000-570F-4A9B-8D69-199FDBA5723B")
    INetworkListManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworks( 
            /* [in] */ NLM_ENUM_NETWORK Flags,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworks **ppEnumNetwork) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetwork( 
            /* [in] */ GUID gdNetworkId,
            /* [retval][out] */ __RPC__deref_out_opt INetwork **ppNetwork) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnections( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnection( 
            /* [in] */ GUID gdNetworkConnectionId,
            /* [retval][out] */ __RPC__deref_out_opt INetworkConnection **ppNetworkConnection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkListManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkListManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkListManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkListManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetworkListManager * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetworkListManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetworkListManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetworkListManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworks )( 
            INetworkListManager * This,
            /* [in] */ NLM_ENUM_NETWORK Flags,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworks **ppEnumNetwork);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetwork )( 
            INetworkListManager * This,
            /* [in] */ GUID gdNetworkId,
            /* [retval][out] */ __RPC__deref_out_opt INetwork **ppNetwork);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnections )( 
            INetworkListManager * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnection )( 
            INetworkListManager * This,
            /* [in] */ GUID gdNetworkConnectionId,
            /* [retval][out] */ __RPC__deref_out_opt INetworkConnection **ppNetworkConnection);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            INetworkListManager * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            INetworkListManager * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            INetworkListManager * This,
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity);
        
        END_INTERFACE
    } INetworkListManagerVtbl;

    interface INetworkListManager
    {
        CONST_VTBL struct INetworkListManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkListManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkListManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkListManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkListManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetworkListManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetworkListManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetworkListManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetworkListManager_GetNetworks(This,Flags,ppEnumNetwork)	\
    ( (This)->lpVtbl -> GetNetworks(This,Flags,ppEnumNetwork) ) 

#define INetworkListManager_GetNetwork(This,gdNetworkId,ppNetwork)	\
    ( (This)->lpVtbl -> GetNetwork(This,gdNetworkId,ppNetwork) ) 

#define INetworkListManager_GetNetworkConnections(This,ppEnum)	\
    ( (This)->lpVtbl -> GetNetworkConnections(This,ppEnum) ) 

#define INetworkListManager_GetNetworkConnection(This,gdNetworkConnectionId,ppNetworkConnection)	\
    ( (This)->lpVtbl -> GetNetworkConnection(This,gdNetworkConnectionId,ppNetworkConnection) ) 

#define INetworkListManager_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetworkListManager_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetworkListManager_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkListManager_INTERFACE_DEFINED__ */


#ifndef __INetworkListManagerEvents_INTERFACE_DEFINED__
#define __INetworkListManagerEvents_INTERFACE_DEFINED__

/* interface INetworkListManagerEvents */
/* [unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkListManagerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00001-570F-4A9B-8D69-199FDBA5723B")
    INetworkListManagerEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ConnectivityChanged( 
            /* [in] */ NLM_CONNECTIVITY newConnectivity) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkListManagerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkListManagerEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkListManagerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkListManagerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *ConnectivityChanged )( 
            INetworkListManagerEvents * This,
            /* [in] */ NLM_CONNECTIVITY newConnectivity);
        
        END_INTERFACE
    } INetworkListManagerEventsVtbl;

    interface INetworkListManagerEvents
    {
        CONST_VTBL struct INetworkListManagerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkListManagerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkListManagerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkListManagerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkListManagerEvents_ConnectivityChanged(This,newConnectivity)	\
    ( (This)->lpVtbl -> ConnectivityChanged(This,newConnectivity) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkListManagerEvents_INTERFACE_DEFINED__ */


#ifndef __INetwork_INTERFACE_DEFINED__
#define __INetwork_INTERFACE_DEFINED__

/* interface INetwork */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 

typedef 
enum NLM_NETWORK_CATEGORY
    {	NLM_NETWORK_CATEGORY_PUBLIC	= 0,
	NLM_NETWORK_CATEGORY_PRIVATE	= 0x1,
	NLM_NETWORK_CATEGORY_DOMAIN_AUTHENTICATED	= 0x2
    } 	NLM_NETWORK_CATEGORY;


EXTERN_C const IID IID_INetwork;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00002-570F-4A9B-8D69-199FDBA5723B")
    INetwork : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pszNetworkName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ __RPC__in BSTR szNetworkNewName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pszDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [string][in] */ __RPC__in BSTR szDescription) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkId( 
            /* [retval][out] */ __RPC__out GUID *pgdGuidNetworkId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDomainType( 
            /* [retval][out] */ __RPC__out NLM_DOMAIN_TYPE *pNetworkType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetworkConnections( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnumNetworkConnection) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTimeCreatedAndConnected( 
            /* [out] */ __RPC__out DWORD *pdwLowDateTimeCreated,
            /* [out] */ __RPC__out DWORD *pdwHighDateTimeCreated,
            /* [out] */ __RPC__out DWORD *pdwLowDateTimeConnected,
            /* [out] */ __RPC__out DWORD *pdwHighDateTimeConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [retval][out] */ __RPC__out NLM_NETWORK_CATEGORY *pCategory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCategory( 
            /* [in] */ NLM_NETWORK_CATEGORY NewCategory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetwork * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetwork * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetwork * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetwork * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetwork * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetwork * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetwork * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            INetwork * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pszNetworkName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            INetwork * This,
            /* [string][in] */ __RPC__in BSTR szNetworkNewName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            INetwork * This,
            /* [retval][string][out] */ __RPC__deref_out_opt_string BSTR *pszDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            INetwork * This,
            /* [string][in] */ __RPC__in BSTR szDescription);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkId )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out GUID *pgdGuidNetworkId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDomainType )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out NLM_DOMAIN_TYPE *pNetworkType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetworkConnections )( 
            INetwork * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnumNetworkConnection);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTimeCreatedAndConnected )( 
            INetwork * This,
            /* [out] */ __RPC__out DWORD *pdwLowDateTimeCreated,
            /* [out] */ __RPC__out DWORD *pdwHighDateTimeCreated,
            /* [out] */ __RPC__out DWORD *pdwLowDateTimeConnected,
            /* [out] */ __RPC__out DWORD *pdwHighDateTimeConnected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            INetwork * This,
            /* [retval][out] */ __RPC__out NLM_NETWORK_CATEGORY *pCategory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCategory )( 
            INetwork * This,
            /* [in] */ NLM_NETWORK_CATEGORY NewCategory);
        
        END_INTERFACE
    } INetworkVtbl;

    interface INetwork
    {
        CONST_VTBL struct INetworkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetwork_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetwork_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetwork_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetwork_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetwork_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetwork_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetwork_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetwork_GetName(This,pszNetworkName)	\
    ( (This)->lpVtbl -> GetName(This,pszNetworkName) ) 

#define INetwork_SetName(This,szNetworkNewName)	\
    ( (This)->lpVtbl -> SetName(This,szNetworkNewName) ) 

#define INetwork_GetDescription(This,pszDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,pszDescription) ) 

#define INetwork_SetDescription(This,szDescription)	\
    ( (This)->lpVtbl -> SetDescription(This,szDescription) ) 

#define INetwork_GetNetworkId(This,pgdGuidNetworkId)	\
    ( (This)->lpVtbl -> GetNetworkId(This,pgdGuidNetworkId) ) 

#define INetwork_GetDomainType(This,pNetworkType)	\
    ( (This)->lpVtbl -> GetDomainType(This,pNetworkType) ) 

#define INetwork_GetNetworkConnections(This,ppEnumNetworkConnection)	\
    ( (This)->lpVtbl -> GetNetworkConnections(This,ppEnumNetworkConnection) ) 

#define INetwork_GetTimeCreatedAndConnected(This,pdwLowDateTimeCreated,pdwHighDateTimeCreated,pdwLowDateTimeConnected,pdwHighDateTimeConnected)	\
    ( (This)->lpVtbl -> GetTimeCreatedAndConnected(This,pdwLowDateTimeCreated,pdwHighDateTimeCreated,pdwLowDateTimeConnected,pdwHighDateTimeConnected) ) 

#define INetwork_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetwork_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetwork_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#define INetwork_GetCategory(This,pCategory)	\
    ( (This)->lpVtbl -> GetCategory(This,pCategory) ) 

#define INetwork_SetCategory(This,NewCategory)	\
    ( (This)->lpVtbl -> SetCategory(This,NewCategory) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetwork_INTERFACE_DEFINED__ */


#ifndef __IEnumNetworks_INTERFACE_DEFINED__
#define __IEnumNetworks_INTERFACE_DEFINED__

/* interface IEnumNetworks */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumNetworks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00003-570F-4A9B-8D69-199FDBA5723B")
    IEnumNetworks : public IDispatch
    {
    public:
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **ppEnumVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) INetwork **rgelt,
            /* [full][ref][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworks **ppEnumNetwork) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetworksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetworks * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetworks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetworks * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumNetworks * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumNetworks * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumNetworks * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumNetworks * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEnumNetworks * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **ppEnumVar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetworks * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) INetwork **rgelt,
            /* [full][ref][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetworks * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetworks * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetworks * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworks **ppEnumNetwork);
        
        END_INTERFACE
    } IEnumNetworksVtbl;

    interface IEnumNetworks
    {
        CONST_VTBL struct IEnumNetworksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetworks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetworks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetworks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetworks_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumNetworks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumNetworks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumNetworks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumNetworks_get__NewEnum(This,ppEnumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVar) ) 

#define IEnumNetworks_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumNetworks_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetworks_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetworks_Clone(This,ppEnumNetwork)	\
    ( (This)->lpVtbl -> Clone(This,ppEnumNetwork) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetworks_INTERFACE_DEFINED__ */


#ifndef __INetworkEvents_INTERFACE_DEFINED__
#define __INetworkEvents_INTERFACE_DEFINED__

/* interface INetworkEvents */
/* [unique][oleautomation][object][helpstring][uuid] */ 

typedef 
enum NLM_NETWORK_PROPERTY_CHANGE
    {	NLM_NETWORK_PROPERTY_CHANGE_CONNECTION	= 0x1,
	NLM_NETWORK_PROPERTY_CHANGE_DESCRIPTION	= 0x2,
	NLM_NETWORK_PROPERTY_CHANGE_NAME	= 0x4,
	NLM_NETWORK_PROPERTY_CHANGE_CATEGORY_VALUE	= 0x10
    } 	NLM_NETWORK_PROPERTY_CHANGE;


EXTERN_C const IID IID_INetworkEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00004-570F-4A9B-8D69-199FDBA5723B")
    INetworkEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NetworkAdded( 
            /* [in] */ GUID networkId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkDeleted( 
            /* [in] */ GUID networkId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectivityChanged( 
            /* [in] */ GUID networkId,
            /* [in] */ NLM_CONNECTIVITY newConnectivity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkPropertyChanged( 
            /* [in] */ GUID networkId,
            /* [in] */ NLM_NETWORK_PROPERTY_CHANGE flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkAdded )( 
            INetworkEvents * This,
            /* [in] */ GUID networkId);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkDeleted )( 
            INetworkEvents * This,
            /* [in] */ GUID networkId);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectivityChanged )( 
            INetworkEvents * This,
            /* [in] */ GUID networkId,
            /* [in] */ NLM_CONNECTIVITY newConnectivity);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkPropertyChanged )( 
            INetworkEvents * This,
            /* [in] */ GUID networkId,
            /* [in] */ NLM_NETWORK_PROPERTY_CHANGE flags);
        
        END_INTERFACE
    } INetworkEventsVtbl;

    interface INetworkEvents
    {
        CONST_VTBL struct INetworkEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkEvents_NetworkAdded(This,networkId)	\
    ( (This)->lpVtbl -> NetworkAdded(This,networkId) ) 

#define INetworkEvents_NetworkDeleted(This,networkId)	\
    ( (This)->lpVtbl -> NetworkDeleted(This,networkId) ) 

#define INetworkEvents_NetworkConnectivityChanged(This,networkId,newConnectivity)	\
    ( (This)->lpVtbl -> NetworkConnectivityChanged(This,networkId,newConnectivity) ) 

#define INetworkEvents_NetworkPropertyChanged(This,networkId,flags)	\
    ( (This)->lpVtbl -> NetworkPropertyChanged(This,networkId,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkEvents_INTERFACE_DEFINED__ */


#ifndef __INetworkConnection_INTERFACE_DEFINED__
#define __INetworkConnection_INTERFACE_DEFINED__

/* interface INetworkConnection */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_INetworkConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00005-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNetwork( 
            /* [retval][out] */ __RPC__deref_out_opt INetwork **ppNetwork) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnectedToInternet( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectivity( 
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectionId( 
            /* [retval][out] */ __RPC__out GUID *pgdConnectionId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAdapterId( 
            /* [retval][out] */ __RPC__out GUID *pgdAdapterId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDomainType( 
            /* [retval][out] */ __RPC__out NLM_DOMAIN_TYPE *pDomainType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkConnection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkConnection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkConnection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INetworkConnection * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INetworkConnection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INetworkConnection * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INetworkConnection * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNetwork )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__deref_out_opt INetwork **ppNetwork);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnectedToInternet )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIsConnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectivity )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out NLM_CONNECTIVITY *pConnectivity);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectionId )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out GUID *pgdConnectionId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAdapterId )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out GUID *pgdAdapterId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDomainType )( 
            INetworkConnection * This,
            /* [retval][out] */ __RPC__out NLM_DOMAIN_TYPE *pDomainType);
        
        END_INTERFACE
    } INetworkConnectionVtbl;

    interface INetworkConnection
    {
        CONST_VTBL struct INetworkConnectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INetworkConnection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INetworkConnection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INetworkConnection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INetworkConnection_GetNetwork(This,ppNetwork)	\
    ( (This)->lpVtbl -> GetNetwork(This,ppNetwork) ) 

#define INetworkConnection_get_IsConnectedToInternet(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnectedToInternet(This,pbIsConnected) ) 

#define INetworkConnection_get_IsConnected(This,pbIsConnected)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pbIsConnected) ) 

#define INetworkConnection_GetConnectivity(This,pConnectivity)	\
    ( (This)->lpVtbl -> GetConnectivity(This,pConnectivity) ) 

#define INetworkConnection_GetConnectionId(This,pgdConnectionId)	\
    ( (This)->lpVtbl -> GetConnectionId(This,pgdConnectionId) ) 

#define INetworkConnection_GetAdapterId(This,pgdAdapterId)	\
    ( (This)->lpVtbl -> GetAdapterId(This,pgdAdapterId) ) 

#define INetworkConnection_GetDomainType(This,pDomainType)	\
    ( (This)->lpVtbl -> GetDomainType(This,pDomainType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnection_INTERFACE_DEFINED__ */


#ifndef __IEnumNetworkConnections_INTERFACE_DEFINED__
#define __IEnumNetworkConnections_INTERFACE_DEFINED__

/* interface IEnumNetworkConnections */
/* [dual][unique][oleautomation][object][helpstring][uuid] */ 


EXTERN_C const IID IID_IEnumNetworkConnections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00006-570F-4A9B-8D69-199FDBA5723B")
    IEnumNetworkConnections : public IDispatch
    {
    public:
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **ppEnumVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) INetworkConnection **rgelt,
            /* [full][ref][out][in] */ __RPC__inout_opt ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnumNetwork) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumNetworkConnectionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumNetworkConnections * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumNetworkConnections * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumNetworkConnections * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEnumNetworkConnections * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEnumNetworkConnections * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEnumNetworkConnections * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEnumNetworkConnections * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IEnumNetworkConnections * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **ppEnumVar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumNetworkConnections * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) INetworkConnection **rgelt,
            /* [full][ref][out][in] */ __RPC__inout_opt ULONG *pceltFetched);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumNetworkConnections * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumNetworkConnections * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumNetworkConnections * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumNetworkConnections **ppEnumNetwork);
        
        END_INTERFACE
    } IEnumNetworkConnectionsVtbl;

    interface IEnumNetworkConnections
    {
        CONST_VTBL struct IEnumNetworkConnectionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumNetworkConnections_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumNetworkConnections_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumNetworkConnections_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumNetworkConnections_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEnumNetworkConnections_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEnumNetworkConnections_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEnumNetworkConnections_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEnumNetworkConnections_get__NewEnum(This,ppEnumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppEnumVar) ) 

#define IEnumNetworkConnections_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumNetworkConnections_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumNetworkConnections_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumNetworkConnections_Clone(This,ppEnumNetwork)	\
    ( (This)->lpVtbl -> Clone(This,ppEnumNetwork) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumNetworkConnections_INTERFACE_DEFINED__ */


#ifndef __INetworkConnectionEvents_INTERFACE_DEFINED__
#define __INetworkConnectionEvents_INTERFACE_DEFINED__

/* interface INetworkConnectionEvents */
/* [unique][object][helpstring][uuid] */ 

typedef 
enum NLM_CONNECTION_PROPERTY_CHANGE
    {	NLM_CONNECTION_PROPERTY_CHANGE_AUTHENTICATION	= 0x1
    } 	NLM_CONNECTION_PROPERTY_CHANGE;


EXTERN_C const IID IID_INetworkConnectionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCB00007-570F-4A9B-8D69-199FDBA5723B")
    INetworkConnectionEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectionConnectivityChanged( 
            /* [in] */ GUID connectionId,
            /* [in] */ NLM_CONNECTIVITY newConnectivity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetworkConnectionPropertyChanged( 
            /* [in] */ GUID connectionId,
            /* [in] */ NLM_CONNECTION_PROPERTY_CHANGE flags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetworkConnectionEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetworkConnectionEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetworkConnectionEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetworkConnectionEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectionConnectivityChanged )( 
            INetworkConnectionEvents * This,
            /* [in] */ GUID connectionId,
            /* [in] */ NLM_CONNECTIVITY newConnectivity);
        
        HRESULT ( STDMETHODCALLTYPE *NetworkConnectionPropertyChanged )( 
            INetworkConnectionEvents * This,
            /* [in] */ GUID connectionId,
            /* [in] */ NLM_CONNECTION_PROPERTY_CHANGE flags);
        
        END_INTERFACE
    } INetworkConnectionEventsVtbl;

    interface INetworkConnectionEvents
    {
        CONST_VTBL struct INetworkConnectionEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetworkConnectionEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INetworkConnectionEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INetworkConnectionEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INetworkConnectionEvents_NetworkConnectionConnectivityChanged(This,connectionId,newConnectivity)	\
    ( (This)->lpVtbl -> NetworkConnectionConnectivityChanged(This,connectionId,newConnectivity) ) 

#define INetworkConnectionEvents_NetworkConnectionPropertyChanged(This,connectionId,flags)	\
    ( (This)->lpVtbl -> NetworkConnectionPropertyChanged(This,connectionId,flags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INetworkConnectionEvents_INTERFACE_DEFINED__ */



#ifndef __NETWORKLIST_LIBRARY_DEFINED__
#define __NETWORKLIST_LIBRARY_DEFINED__

/* library NETWORKLIST */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NETWORKLIST;

EXTERN_C const CLSID CLSID_NetworkListManager;

#ifdef __cplusplus

class DECLSPEC_UUID("DCB00C01-570F-4A9B-8D69-199FDBA5723B")
NetworkListManager;
#endif
#endif /* __NETWORKLIST_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



