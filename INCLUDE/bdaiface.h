

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for bdaiface.idl:
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

#ifndef __bdaiface_h__
#define __bdaiface_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBDA_NetworkProvider_FWD_DEFINED__
#define __IBDA_NetworkProvider_FWD_DEFINED__
typedef interface IBDA_NetworkProvider IBDA_NetworkProvider;
#endif 	/* __IBDA_NetworkProvider_FWD_DEFINED__ */


#ifndef __IBDA_EthernetFilter_FWD_DEFINED__
#define __IBDA_EthernetFilter_FWD_DEFINED__
typedef interface IBDA_EthernetFilter IBDA_EthernetFilter;
#endif 	/* __IBDA_EthernetFilter_FWD_DEFINED__ */


#ifndef __IBDA_IPV4Filter_FWD_DEFINED__
#define __IBDA_IPV4Filter_FWD_DEFINED__
typedef interface IBDA_IPV4Filter IBDA_IPV4Filter;
#endif 	/* __IBDA_IPV4Filter_FWD_DEFINED__ */


#ifndef __IBDA_IPV6Filter_FWD_DEFINED__
#define __IBDA_IPV6Filter_FWD_DEFINED__
typedef interface IBDA_IPV6Filter IBDA_IPV6Filter;
#endif 	/* __IBDA_IPV6Filter_FWD_DEFINED__ */


#ifndef __IBDA_DeviceControl_FWD_DEFINED__
#define __IBDA_DeviceControl_FWD_DEFINED__
typedef interface IBDA_DeviceControl IBDA_DeviceControl;
#endif 	/* __IBDA_DeviceControl_FWD_DEFINED__ */


#ifndef __IBDA_PinControl_FWD_DEFINED__
#define __IBDA_PinControl_FWD_DEFINED__
typedef interface IBDA_PinControl IBDA_PinControl;
#endif 	/* __IBDA_PinControl_FWD_DEFINED__ */


#ifndef __IBDA_SignalProperties_FWD_DEFINED__
#define __IBDA_SignalProperties_FWD_DEFINED__
typedef interface IBDA_SignalProperties IBDA_SignalProperties;
#endif 	/* __IBDA_SignalProperties_FWD_DEFINED__ */


#ifndef __IBDA_SignalStatistics_FWD_DEFINED__
#define __IBDA_SignalStatistics_FWD_DEFINED__
typedef interface IBDA_SignalStatistics IBDA_SignalStatistics;
#endif 	/* __IBDA_SignalStatistics_FWD_DEFINED__ */


#ifndef __IBDA_Topology_FWD_DEFINED__
#define __IBDA_Topology_FWD_DEFINED__
typedef interface IBDA_Topology IBDA_Topology;
#endif 	/* __IBDA_Topology_FWD_DEFINED__ */


#ifndef __IBDA_VoidTransform_FWD_DEFINED__
#define __IBDA_VoidTransform_FWD_DEFINED__
typedef interface IBDA_VoidTransform IBDA_VoidTransform;
#endif 	/* __IBDA_VoidTransform_FWD_DEFINED__ */


#ifndef __IBDA_NullTransform_FWD_DEFINED__
#define __IBDA_NullTransform_FWD_DEFINED__
typedef interface IBDA_NullTransform IBDA_NullTransform;
#endif 	/* __IBDA_NullTransform_FWD_DEFINED__ */


#ifndef __IBDA_FrequencyFilter_FWD_DEFINED__
#define __IBDA_FrequencyFilter_FWD_DEFINED__
typedef interface IBDA_FrequencyFilter IBDA_FrequencyFilter;
#endif 	/* __IBDA_FrequencyFilter_FWD_DEFINED__ */


#ifndef __IBDA_LNBInfo_FWD_DEFINED__
#define __IBDA_LNBInfo_FWD_DEFINED__
typedef interface IBDA_LNBInfo IBDA_LNBInfo;
#endif 	/* __IBDA_LNBInfo_FWD_DEFINED__ */


#ifndef __IBDA_AutoDemodulate_FWD_DEFINED__
#define __IBDA_AutoDemodulate_FWD_DEFINED__
typedef interface IBDA_AutoDemodulate IBDA_AutoDemodulate;
#endif 	/* __IBDA_AutoDemodulate_FWD_DEFINED__ */


#ifndef __IBDA_AutoDemodulateEx_FWD_DEFINED__
#define __IBDA_AutoDemodulateEx_FWD_DEFINED__
typedef interface IBDA_AutoDemodulateEx IBDA_AutoDemodulateEx;
#endif 	/* __IBDA_AutoDemodulateEx_FWD_DEFINED__ */


#ifndef __IBDA_DigitalDemodulator_FWD_DEFINED__
#define __IBDA_DigitalDemodulator_FWD_DEFINED__
typedef interface IBDA_DigitalDemodulator IBDA_DigitalDemodulator;
#endif 	/* __IBDA_DigitalDemodulator_FWD_DEFINED__ */


#ifndef __ICCSubStreamFiltering_FWD_DEFINED__
#define __ICCSubStreamFiltering_FWD_DEFINED__
typedef interface ICCSubStreamFiltering ICCSubStreamFiltering;
#endif 	/* __ICCSubStreamFiltering_FWD_DEFINED__ */


#ifndef __IBDA_IPSinkControl_FWD_DEFINED__
#define __IBDA_IPSinkControl_FWD_DEFINED__
typedef interface IBDA_IPSinkControl IBDA_IPSinkControl;
#endif 	/* __IBDA_IPSinkControl_FWD_DEFINED__ */


#ifndef __IBDA_IPSinkInfo_FWD_DEFINED__
#define __IBDA_IPSinkInfo_FWD_DEFINED__
typedef interface IBDA_IPSinkInfo IBDA_IPSinkInfo;
#endif 	/* __IBDA_IPSinkInfo_FWD_DEFINED__ */


#ifndef __IEnumPIDMap_FWD_DEFINED__
#define __IEnumPIDMap_FWD_DEFINED__
typedef interface IEnumPIDMap IEnumPIDMap;
#endif 	/* __IEnumPIDMap_FWD_DEFINED__ */


#ifndef __IMPEG2PIDMap_FWD_DEFINED__
#define __IMPEG2PIDMap_FWD_DEFINED__
typedef interface IMPEG2PIDMap IMPEG2PIDMap;
#endif 	/* __IMPEG2PIDMap_FWD_DEFINED__ */


#ifndef __IFrequencyMap_FWD_DEFINED__
#define __IFrequencyMap_FWD_DEFINED__
typedef interface IFrequencyMap IFrequencyMap;
#endif 	/* __IFrequencyMap_FWD_DEFINED__ */


#ifndef __IBDA_EasMessage_FWD_DEFINED__
#define __IBDA_EasMessage_FWD_DEFINED__
typedef interface IBDA_EasMessage IBDA_EasMessage;
#endif 	/* __IBDA_EasMessage_FWD_DEFINED__ */


#ifndef __IBDA_TransportStreamInfo_FWD_DEFINED__
#define __IBDA_TransportStreamInfo_FWD_DEFINED__
typedef interface IBDA_TransportStreamInfo IBDA_TransportStreamInfo;
#endif 	/* __IBDA_TransportStreamInfo_FWD_DEFINED__ */


#ifndef __IBDA_ConditionalAccess_FWD_DEFINED__
#define __IBDA_ConditionalAccess_FWD_DEFINED__
typedef interface IBDA_ConditionalAccess IBDA_ConditionalAccess;
#endif 	/* __IBDA_ConditionalAccess_FWD_DEFINED__ */


#ifndef __IBDA_DiagnosticProperties_FWD_DEFINED__
#define __IBDA_DiagnosticProperties_FWD_DEFINED__
typedef interface IBDA_DiagnosticProperties IBDA_DiagnosticProperties;
#endif 	/* __IBDA_DiagnosticProperties_FWD_DEFINED__ */


#ifndef __IBDA_DRM_FWD_DEFINED__
#define __IBDA_DRM_FWD_DEFINED__
typedef interface IBDA_DRM IBDA_DRM;
#endif 	/* __IBDA_DRM_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "strmif.h"
#include "BdaTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IBDA_NetworkProvider_INTERFACE_DEFINED__
#define __IBDA_NetworkProvider_INTERFACE_DEFINED__

/* interface IBDA_NetworkProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_NetworkProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fd501041-8ebe-11ce-8183-00aa00577da2")
    IBDA_NetworkProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PutSignalSource( 
            /* [in] */ ULONG ulSignalSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSignalSource( 
            /* [out][in] */ __RPC__inout ULONG *pulSignalSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkType( 
            /* [out][in] */ __RPC__inout GUID *pguidNetworkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutTuningSpace( 
            /* [in] */ __RPC__in REFGUID guidTuningSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTuningSpace( 
            /* [out][in] */ __RPC__inout GUID *pguidTuingSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterDeviceFilter( 
            /* [in] */ __RPC__in_opt IUnknown *pUnkFilterControl,
            /* [out][in] */ __RPC__inout ULONG *ppvRegisitrationContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnRegisterDeviceFilter( 
            /* [in] */ ULONG pvRegistrationContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_NetworkProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_NetworkProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_NetworkProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_NetworkProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *PutSignalSource )( 
            IBDA_NetworkProvider * This,
            /* [in] */ ULONG ulSignalSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetSignalSource )( 
            IBDA_NetworkProvider * This,
            /* [out][in] */ __RPC__inout ULONG *pulSignalSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkType )( 
            IBDA_NetworkProvider * This,
            /* [out][in] */ __RPC__inout GUID *pguidNetworkType);
        
        HRESULT ( STDMETHODCALLTYPE *PutTuningSpace )( 
            IBDA_NetworkProvider * This,
            /* [in] */ __RPC__in REFGUID guidTuningSpace);
        
        HRESULT ( STDMETHODCALLTYPE *GetTuningSpace )( 
            IBDA_NetworkProvider * This,
            /* [out][in] */ __RPC__inout GUID *pguidTuingSpace);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterDeviceFilter )( 
            IBDA_NetworkProvider * This,
            /* [in] */ __RPC__in_opt IUnknown *pUnkFilterControl,
            /* [out][in] */ __RPC__inout ULONG *ppvRegisitrationContext);
        
        HRESULT ( STDMETHODCALLTYPE *UnRegisterDeviceFilter )( 
            IBDA_NetworkProvider * This,
            /* [in] */ ULONG pvRegistrationContext);
        
        END_INTERFACE
    } IBDA_NetworkProviderVtbl;

    interface IBDA_NetworkProvider
    {
        CONST_VTBL struct IBDA_NetworkProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_NetworkProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_NetworkProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_NetworkProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_NetworkProvider_PutSignalSource(This,ulSignalSource)	\
    ( (This)->lpVtbl -> PutSignalSource(This,ulSignalSource) ) 

#define IBDA_NetworkProvider_GetSignalSource(This,pulSignalSource)	\
    ( (This)->lpVtbl -> GetSignalSource(This,pulSignalSource) ) 

#define IBDA_NetworkProvider_GetNetworkType(This,pguidNetworkType)	\
    ( (This)->lpVtbl -> GetNetworkType(This,pguidNetworkType) ) 

#define IBDA_NetworkProvider_PutTuningSpace(This,guidTuningSpace)	\
    ( (This)->lpVtbl -> PutTuningSpace(This,guidTuningSpace) ) 

#define IBDA_NetworkProvider_GetTuningSpace(This,pguidTuingSpace)	\
    ( (This)->lpVtbl -> GetTuningSpace(This,pguidTuingSpace) ) 

#define IBDA_NetworkProvider_RegisterDeviceFilter(This,pUnkFilterControl,ppvRegisitrationContext)	\
    ( (This)->lpVtbl -> RegisterDeviceFilter(This,pUnkFilterControl,ppvRegisitrationContext) ) 

#define IBDA_NetworkProvider_UnRegisterDeviceFilter(This,pvRegistrationContext)	\
    ( (This)->lpVtbl -> UnRegisterDeviceFilter(This,pvRegistrationContext) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_NetworkProvider_INTERFACE_DEFINED__ */


#ifndef __IBDA_EthernetFilter_INTERFACE_DEFINED__
#define __IBDA_EthernetFilter_INTERFACE_DEFINED__

/* interface IBDA_EthernetFilter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_EthernetFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71985F43-1CA1-11d3-9CC8-00C04F7971E0")
    IBDA_EthernetFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMulticastListSize( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastList( 
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastList( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastMode( 
            /* [in] */ ULONG ulModeMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastMode( 
            /* [out] */ __RPC__out ULONG *pulModeMask) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_EthernetFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_EthernetFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_EthernetFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_EthernetFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastListSize )( 
            IBDA_EthernetFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastList )( 
            IBDA_EthernetFilter * This,
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastList )( 
            IBDA_EthernetFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastMode )( 
            IBDA_EthernetFilter * This,
            /* [in] */ ULONG ulModeMask);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastMode )( 
            IBDA_EthernetFilter * This,
            /* [out] */ __RPC__out ULONG *pulModeMask);
        
        END_INTERFACE
    } IBDA_EthernetFilterVtbl;

    interface IBDA_EthernetFilter
    {
        CONST_VTBL struct IBDA_EthernetFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_EthernetFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_EthernetFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_EthernetFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_EthernetFilter_GetMulticastListSize(This,pulcbAddresses)	\
    ( (This)->lpVtbl -> GetMulticastListSize(This,pulcbAddresses) ) 

#define IBDA_EthernetFilter_PutMulticastList(This,ulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> PutMulticastList(This,ulcbAddresses,pAddressList) ) 

#define IBDA_EthernetFilter_GetMulticastList(This,pulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> GetMulticastList(This,pulcbAddresses,pAddressList) ) 

#define IBDA_EthernetFilter_PutMulticastMode(This,ulModeMask)	\
    ( (This)->lpVtbl -> PutMulticastMode(This,ulModeMask) ) 

#define IBDA_EthernetFilter_GetMulticastMode(This,pulModeMask)	\
    ( (This)->lpVtbl -> GetMulticastMode(This,pulModeMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_EthernetFilter_INTERFACE_DEFINED__ */


#ifndef __IBDA_IPV4Filter_INTERFACE_DEFINED__
#define __IBDA_IPV4Filter_INTERFACE_DEFINED__

/* interface IBDA_IPV4Filter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_IPV4Filter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71985F44-1CA1-11d3-9CC8-00C04F7971E0")
    IBDA_IPV4Filter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMulticastListSize( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastList( 
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastList( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastMode( 
            /* [in] */ ULONG ulModeMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastMode( 
            /* [out] */ __RPC__out ULONG *pulModeMask) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_IPV4FilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_IPV4Filter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_IPV4Filter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_IPV4Filter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastListSize )( 
            IBDA_IPV4Filter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastList )( 
            IBDA_IPV4Filter * This,
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastList )( 
            IBDA_IPV4Filter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastMode )( 
            IBDA_IPV4Filter * This,
            /* [in] */ ULONG ulModeMask);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastMode )( 
            IBDA_IPV4Filter * This,
            /* [out] */ __RPC__out ULONG *pulModeMask);
        
        END_INTERFACE
    } IBDA_IPV4FilterVtbl;

    interface IBDA_IPV4Filter
    {
        CONST_VTBL struct IBDA_IPV4FilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_IPV4Filter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_IPV4Filter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_IPV4Filter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_IPV4Filter_GetMulticastListSize(This,pulcbAddresses)	\
    ( (This)->lpVtbl -> GetMulticastListSize(This,pulcbAddresses) ) 

#define IBDA_IPV4Filter_PutMulticastList(This,ulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> PutMulticastList(This,ulcbAddresses,pAddressList) ) 

#define IBDA_IPV4Filter_GetMulticastList(This,pulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> GetMulticastList(This,pulcbAddresses,pAddressList) ) 

#define IBDA_IPV4Filter_PutMulticastMode(This,ulModeMask)	\
    ( (This)->lpVtbl -> PutMulticastMode(This,ulModeMask) ) 

#define IBDA_IPV4Filter_GetMulticastMode(This,pulModeMask)	\
    ( (This)->lpVtbl -> GetMulticastMode(This,pulModeMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_IPV4Filter_INTERFACE_DEFINED__ */


#ifndef __IBDA_IPV6Filter_INTERFACE_DEFINED__
#define __IBDA_IPV6Filter_INTERFACE_DEFINED__

/* interface IBDA_IPV6Filter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_IPV6Filter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E1785A74-2A23-4fb3-9245-A8F88017EF33")
    IBDA_IPV6Filter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMulticastListSize( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastList( 
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastList( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutMulticastMode( 
            /* [in] */ ULONG ulModeMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMulticastMode( 
            /* [out] */ __RPC__out ULONG *pulModeMask) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_IPV6FilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_IPV6Filter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_IPV6Filter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_IPV6Filter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastListSize )( 
            IBDA_IPV6Filter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastList )( 
            IBDA_IPV6Filter * This,
            /* [in] */ ULONG ulcbAddresses,
            /* [size_is][in] */ __RPC__in_ecount_full(ulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastList )( 
            IBDA_IPV6Filter * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE pAddressList[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *PutMulticastMode )( 
            IBDA_IPV6Filter * This,
            /* [in] */ ULONG ulModeMask);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastMode )( 
            IBDA_IPV6Filter * This,
            /* [out] */ __RPC__out ULONG *pulModeMask);
        
        END_INTERFACE
    } IBDA_IPV6FilterVtbl;

    interface IBDA_IPV6Filter
    {
        CONST_VTBL struct IBDA_IPV6FilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_IPV6Filter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_IPV6Filter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_IPV6Filter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_IPV6Filter_GetMulticastListSize(This,pulcbAddresses)	\
    ( (This)->lpVtbl -> GetMulticastListSize(This,pulcbAddresses) ) 

#define IBDA_IPV6Filter_PutMulticastList(This,ulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> PutMulticastList(This,ulcbAddresses,pAddressList) ) 

#define IBDA_IPV6Filter_GetMulticastList(This,pulcbAddresses,pAddressList)	\
    ( (This)->lpVtbl -> GetMulticastList(This,pulcbAddresses,pAddressList) ) 

#define IBDA_IPV6Filter_PutMulticastMode(This,ulModeMask)	\
    ( (This)->lpVtbl -> PutMulticastMode(This,ulModeMask) ) 

#define IBDA_IPV6Filter_GetMulticastMode(This,pulModeMask)	\
    ( (This)->lpVtbl -> GetMulticastMode(This,pulModeMask) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_IPV6Filter_INTERFACE_DEFINED__ */


#ifndef __IBDA_DeviceControl_INTERFACE_DEFINED__
#define __IBDA_DeviceControl_INTERFACE_DEFINED__

/* interface IBDA_DeviceControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_DeviceControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FD0A5AF3-B41D-11d2-9C95-00C04F7971E0")
    IBDA_DeviceControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartChanges( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckChanges( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CommitChanges( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChangeState( 
            /* [out][in] */ __RPC__inout ULONG *pState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_DeviceControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_DeviceControl * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_DeviceControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_DeviceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartChanges )( 
            IBDA_DeviceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckChanges )( 
            IBDA_DeviceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *CommitChanges )( 
            IBDA_DeviceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetChangeState )( 
            IBDA_DeviceControl * This,
            /* [out][in] */ __RPC__inout ULONG *pState);
        
        END_INTERFACE
    } IBDA_DeviceControlVtbl;

    interface IBDA_DeviceControl
    {
        CONST_VTBL struct IBDA_DeviceControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_DeviceControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_DeviceControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_DeviceControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_DeviceControl_StartChanges(This)	\
    ( (This)->lpVtbl -> StartChanges(This) ) 

#define IBDA_DeviceControl_CheckChanges(This)	\
    ( (This)->lpVtbl -> CheckChanges(This) ) 

#define IBDA_DeviceControl_CommitChanges(This)	\
    ( (This)->lpVtbl -> CommitChanges(This) ) 

#define IBDA_DeviceControl_GetChangeState(This,pState)	\
    ( (This)->lpVtbl -> GetChangeState(This,pState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_DeviceControl_INTERFACE_DEFINED__ */


#ifndef __IBDA_PinControl_INTERFACE_DEFINED__
#define __IBDA_PinControl_INTERFACE_DEFINED__

/* interface IBDA_PinControl */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_PinControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DED49D5-A8B7-4d5d-97A1-12B0C195874D")
    IBDA_PinControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPinID( 
            /* [out][in] */ __RPC__inout ULONG *pulPinID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPinType( 
            /* [out][in] */ __RPC__inout ULONG *pulPinType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegistrationContext( 
            /* [out][in] */ __RPC__inout ULONG *pulRegistrationCtx) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_PinControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_PinControl * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_PinControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_PinControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPinID )( 
            IBDA_PinControl * This,
            /* [out][in] */ __RPC__inout ULONG *pulPinID);
        
        HRESULT ( STDMETHODCALLTYPE *GetPinType )( 
            IBDA_PinControl * This,
            /* [out][in] */ __RPC__inout ULONG *pulPinType);
        
        HRESULT ( STDMETHODCALLTYPE *RegistrationContext )( 
            IBDA_PinControl * This,
            /* [out][in] */ __RPC__inout ULONG *pulRegistrationCtx);
        
        END_INTERFACE
    } IBDA_PinControlVtbl;

    interface IBDA_PinControl
    {
        CONST_VTBL struct IBDA_PinControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_PinControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_PinControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_PinControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_PinControl_GetPinID(This,pulPinID)	\
    ( (This)->lpVtbl -> GetPinID(This,pulPinID) ) 

#define IBDA_PinControl_GetPinType(This,pulPinType)	\
    ( (This)->lpVtbl -> GetPinType(This,pulPinType) ) 

#define IBDA_PinControl_RegistrationContext(This,pulRegistrationCtx)	\
    ( (This)->lpVtbl -> RegistrationContext(This,pulRegistrationCtx) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_PinControl_INTERFACE_DEFINED__ */


#ifndef __IBDA_SignalProperties_INTERFACE_DEFINED__
#define __IBDA_SignalProperties_INTERFACE_DEFINED__

/* interface IBDA_SignalProperties */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_SignalProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2F1644B-B409-11d2-BC69-00A0C9EE9E16")
    IBDA_SignalProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PutNetworkType( 
            /* [in] */ __RPC__in REFGUID guidNetworkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkType( 
            /* [out][in] */ __RPC__inout GUID *pguidNetworkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutSignalSource( 
            /* [in] */ ULONG ulSignalSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSignalSource( 
            /* [out][in] */ __RPC__inout ULONG *pulSignalSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PutTuningSpace( 
            /* [in] */ __RPC__in REFGUID guidTuningSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTuningSpace( 
            /* [out][in] */ __RPC__inout GUID *pguidTuingSpace) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_SignalPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_SignalProperties * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_SignalProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_SignalProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *PutNetworkType )( 
            IBDA_SignalProperties * This,
            /* [in] */ __RPC__in REFGUID guidNetworkType);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkType )( 
            IBDA_SignalProperties * This,
            /* [out][in] */ __RPC__inout GUID *pguidNetworkType);
        
        HRESULT ( STDMETHODCALLTYPE *PutSignalSource )( 
            IBDA_SignalProperties * This,
            /* [in] */ ULONG ulSignalSource);
        
        HRESULT ( STDMETHODCALLTYPE *GetSignalSource )( 
            IBDA_SignalProperties * This,
            /* [out][in] */ __RPC__inout ULONG *pulSignalSource);
        
        HRESULT ( STDMETHODCALLTYPE *PutTuningSpace )( 
            IBDA_SignalProperties * This,
            /* [in] */ __RPC__in REFGUID guidTuningSpace);
        
        HRESULT ( STDMETHODCALLTYPE *GetTuningSpace )( 
            IBDA_SignalProperties * This,
            /* [out][in] */ __RPC__inout GUID *pguidTuingSpace);
        
        END_INTERFACE
    } IBDA_SignalPropertiesVtbl;

    interface IBDA_SignalProperties
    {
        CONST_VTBL struct IBDA_SignalPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_SignalProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_SignalProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_SignalProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_SignalProperties_PutNetworkType(This,guidNetworkType)	\
    ( (This)->lpVtbl -> PutNetworkType(This,guidNetworkType) ) 

#define IBDA_SignalProperties_GetNetworkType(This,pguidNetworkType)	\
    ( (This)->lpVtbl -> GetNetworkType(This,pguidNetworkType) ) 

#define IBDA_SignalProperties_PutSignalSource(This,ulSignalSource)	\
    ( (This)->lpVtbl -> PutSignalSource(This,ulSignalSource) ) 

#define IBDA_SignalProperties_GetSignalSource(This,pulSignalSource)	\
    ( (This)->lpVtbl -> GetSignalSource(This,pulSignalSource) ) 

#define IBDA_SignalProperties_PutTuningSpace(This,guidTuningSpace)	\
    ( (This)->lpVtbl -> PutTuningSpace(This,guidTuningSpace) ) 

#define IBDA_SignalProperties_GetTuningSpace(This,pguidTuingSpace)	\
    ( (This)->lpVtbl -> GetTuningSpace(This,pguidTuingSpace) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_SignalProperties_INTERFACE_DEFINED__ */


#ifndef __IBDA_SignalStatistics_INTERFACE_DEFINED__
#define __IBDA_SignalStatistics_INTERFACE_DEFINED__

/* interface IBDA_SignalStatistics */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_SignalStatistics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1347D106-CF3A-428a-A5CB-AC0D9A2A4338")
    IBDA_SignalStatistics : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_SignalStrength( 
            /* [in] */ LONG lDbStrength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SignalStrength( 
            /* [out][in] */ __RPC__inout LONG *plDbStrength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SignalQuality( 
            /* [in] */ LONG lPercentQuality) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SignalQuality( 
            /* [out][in] */ __RPC__inout LONG *plPercentQuality) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SignalPresent( 
            /* [in] */ BOOLEAN fPresent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SignalPresent( 
            /* [out][in] */ __RPC__inout BOOLEAN *pfPresent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SignalLocked( 
            /* [in] */ BOOLEAN fLocked) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SignalLocked( 
            /* [out][in] */ __RPC__inout BOOLEAN *pfLocked) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SampleTime( 
            /* [in] */ LONG lmsSampleTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SampleTime( 
            /* [out][in] */ __RPC__inout LONG *plmsSampleTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_SignalStatisticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_SignalStatistics * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_SignalStatistics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_SignalStatistics * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_SignalStrength )( 
            IBDA_SignalStatistics * This,
            /* [in] */ LONG lDbStrength);
        
        HRESULT ( STDMETHODCALLTYPE *get_SignalStrength )( 
            IBDA_SignalStatistics * This,
            /* [out][in] */ __RPC__inout LONG *plDbStrength);
        
        HRESULT ( STDMETHODCALLTYPE *put_SignalQuality )( 
            IBDA_SignalStatistics * This,
            /* [in] */ LONG lPercentQuality);
        
        HRESULT ( STDMETHODCALLTYPE *get_SignalQuality )( 
            IBDA_SignalStatistics * This,
            /* [out][in] */ __RPC__inout LONG *plPercentQuality);
        
        HRESULT ( STDMETHODCALLTYPE *put_SignalPresent )( 
            IBDA_SignalStatistics * This,
            /* [in] */ BOOLEAN fPresent);
        
        HRESULT ( STDMETHODCALLTYPE *get_SignalPresent )( 
            IBDA_SignalStatistics * This,
            /* [out][in] */ __RPC__inout BOOLEAN *pfPresent);
        
        HRESULT ( STDMETHODCALLTYPE *put_SignalLocked )( 
            IBDA_SignalStatistics * This,
            /* [in] */ BOOLEAN fLocked);
        
        HRESULT ( STDMETHODCALLTYPE *get_SignalLocked )( 
            IBDA_SignalStatistics * This,
            /* [out][in] */ __RPC__inout BOOLEAN *pfLocked);
        
        HRESULT ( STDMETHODCALLTYPE *put_SampleTime )( 
            IBDA_SignalStatistics * This,
            /* [in] */ LONG lmsSampleTime);
        
        HRESULT ( STDMETHODCALLTYPE *get_SampleTime )( 
            IBDA_SignalStatistics * This,
            /* [out][in] */ __RPC__inout LONG *plmsSampleTime);
        
        END_INTERFACE
    } IBDA_SignalStatisticsVtbl;

    interface IBDA_SignalStatistics
    {
        CONST_VTBL struct IBDA_SignalStatisticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_SignalStatistics_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_SignalStatistics_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_SignalStatistics_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_SignalStatistics_put_SignalStrength(This,lDbStrength)	\
    ( (This)->lpVtbl -> put_SignalStrength(This,lDbStrength) ) 

#define IBDA_SignalStatistics_get_SignalStrength(This,plDbStrength)	\
    ( (This)->lpVtbl -> get_SignalStrength(This,plDbStrength) ) 

#define IBDA_SignalStatistics_put_SignalQuality(This,lPercentQuality)	\
    ( (This)->lpVtbl -> put_SignalQuality(This,lPercentQuality) ) 

#define IBDA_SignalStatistics_get_SignalQuality(This,plPercentQuality)	\
    ( (This)->lpVtbl -> get_SignalQuality(This,plPercentQuality) ) 

#define IBDA_SignalStatistics_put_SignalPresent(This,fPresent)	\
    ( (This)->lpVtbl -> put_SignalPresent(This,fPresent) ) 

#define IBDA_SignalStatistics_get_SignalPresent(This,pfPresent)	\
    ( (This)->lpVtbl -> get_SignalPresent(This,pfPresent) ) 

#define IBDA_SignalStatistics_put_SignalLocked(This,fLocked)	\
    ( (This)->lpVtbl -> put_SignalLocked(This,fLocked) ) 

#define IBDA_SignalStatistics_get_SignalLocked(This,pfLocked)	\
    ( (This)->lpVtbl -> get_SignalLocked(This,pfLocked) ) 

#define IBDA_SignalStatistics_put_SampleTime(This,lmsSampleTime)	\
    ( (This)->lpVtbl -> put_SampleTime(This,lmsSampleTime) ) 

#define IBDA_SignalStatistics_get_SampleTime(This,plmsSampleTime)	\
    ( (This)->lpVtbl -> get_SampleTime(This,plmsSampleTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_SignalStatistics_INTERFACE_DEFINED__ */


#ifndef __IBDA_Topology_INTERFACE_DEFINED__
#define __IBDA_Topology_INTERFACE_DEFINED__

/* interface IBDA_Topology */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_Topology;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79B56888-7FEA-4690-B45D-38FD3C7849BE")
    IBDA_Topology : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNodeTypes( 
            /* [out][in] */ __RPC__inout ULONG *pulcNodeTypes,
            /* [in] */ ULONG ulcNodeTypesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcNodeTypesMax) ULONG rgulNodeTypes[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNodeDescriptors( 
            /* [out][in] */ __RPC__inout ULONG *ulcNodeDescriptors,
            /* [in] */ ULONG ulcNodeDescriptorsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcNodeDescriptorsMax) BDANODE_DESCRIPTOR rgNodeDescriptors[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNodeInterfaces( 
            /* [in] */ ULONG ulNodeType,
            /* [out][in] */ __RPC__inout ULONG *pulcInterfaces,
            /* [in] */ ULONG ulcInterfacesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcInterfacesMax) GUID rgguidInterfaces[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPinTypes( 
            /* [out][in] */ __RPC__inout ULONG *pulcPinTypes,
            /* [in] */ ULONG ulcPinTypesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcPinTypesMax) ULONG rgulPinTypes[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTemplateConnections( 
            /* [out][in] */ __RPC__inout ULONG *pulcConnections,
            /* [in] */ ULONG ulcConnectionsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcConnectionsMax) BDA_TEMPLATE_CONNECTION rgConnections[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePin( 
            /* [in] */ ULONG ulPinType,
            /* [out][in] */ __RPC__inout ULONG *pulPinId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePin( 
            /* [in] */ ULONG ulPinId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaType( 
            /* [in] */ ULONG ulPinId,
            /* [in] */ __RPC__in AM_MEDIA_TYPE *pMediaType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMedium( 
            /* [in] */ ULONG ulPinId,
            /* [in] */ __RPC__in REGPINMEDIUM *pMedium) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTopology( 
            /* [in] */ ULONG ulInputPinId,
            /* [in] */ ULONG ulOutputPinId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetControlNode( 
            /* [in] */ ULONG ulInputPinId,
            /* [in] */ ULONG ulOutputPinId,
            /* [in] */ ULONG ulNodeType,
            /* [out][in] */ __RPC__deref_inout_opt IUnknown **ppControlNode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_TopologyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_Topology * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_Topology * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_Topology * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNodeTypes )( 
            IBDA_Topology * This,
            /* [out][in] */ __RPC__inout ULONG *pulcNodeTypes,
            /* [in] */ ULONG ulcNodeTypesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcNodeTypesMax) ULONG rgulNodeTypes[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetNodeDescriptors )( 
            IBDA_Topology * This,
            /* [out][in] */ __RPC__inout ULONG *ulcNodeDescriptors,
            /* [in] */ ULONG ulcNodeDescriptorsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcNodeDescriptorsMax) BDANODE_DESCRIPTOR rgNodeDescriptors[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetNodeInterfaces )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulNodeType,
            /* [out][in] */ __RPC__inout ULONG *pulcInterfaces,
            /* [in] */ ULONG ulcInterfacesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcInterfacesMax) GUID rgguidInterfaces[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetPinTypes )( 
            IBDA_Topology * This,
            /* [out][in] */ __RPC__inout ULONG *pulcPinTypes,
            /* [in] */ ULONG ulcPinTypesMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcPinTypesMax) ULONG rgulPinTypes[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetTemplateConnections )( 
            IBDA_Topology * This,
            /* [out][in] */ __RPC__inout ULONG *pulcConnections,
            /* [in] */ ULONG ulcConnectionsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcConnectionsMax) BDA_TEMPLATE_CONNECTION rgConnections[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePin )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulPinType,
            /* [out][in] */ __RPC__inout ULONG *pulPinId);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePin )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulPinId);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulPinId,
            /* [in] */ __RPC__in AM_MEDIA_TYPE *pMediaType);
        
        HRESULT ( STDMETHODCALLTYPE *SetMedium )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulPinId,
            /* [in] */ __RPC__in REGPINMEDIUM *pMedium);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTopology )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulInputPinId,
            /* [in] */ ULONG ulOutputPinId);
        
        HRESULT ( STDMETHODCALLTYPE *GetControlNode )( 
            IBDA_Topology * This,
            /* [in] */ ULONG ulInputPinId,
            /* [in] */ ULONG ulOutputPinId,
            /* [in] */ ULONG ulNodeType,
            /* [out][in] */ __RPC__deref_inout_opt IUnknown **ppControlNode);
        
        END_INTERFACE
    } IBDA_TopologyVtbl;

    interface IBDA_Topology
    {
        CONST_VTBL struct IBDA_TopologyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_Topology_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_Topology_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_Topology_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_Topology_GetNodeTypes(This,pulcNodeTypes,ulcNodeTypesMax,rgulNodeTypes)	\
    ( (This)->lpVtbl -> GetNodeTypes(This,pulcNodeTypes,ulcNodeTypesMax,rgulNodeTypes) ) 

#define IBDA_Topology_GetNodeDescriptors(This,ulcNodeDescriptors,ulcNodeDescriptorsMax,rgNodeDescriptors)	\
    ( (This)->lpVtbl -> GetNodeDescriptors(This,ulcNodeDescriptors,ulcNodeDescriptorsMax,rgNodeDescriptors) ) 

#define IBDA_Topology_GetNodeInterfaces(This,ulNodeType,pulcInterfaces,ulcInterfacesMax,rgguidInterfaces)	\
    ( (This)->lpVtbl -> GetNodeInterfaces(This,ulNodeType,pulcInterfaces,ulcInterfacesMax,rgguidInterfaces) ) 

#define IBDA_Topology_GetPinTypes(This,pulcPinTypes,ulcPinTypesMax,rgulPinTypes)	\
    ( (This)->lpVtbl -> GetPinTypes(This,pulcPinTypes,ulcPinTypesMax,rgulPinTypes) ) 

#define IBDA_Topology_GetTemplateConnections(This,pulcConnections,ulcConnectionsMax,rgConnections)	\
    ( (This)->lpVtbl -> GetTemplateConnections(This,pulcConnections,ulcConnectionsMax,rgConnections) ) 

#define IBDA_Topology_CreatePin(This,ulPinType,pulPinId)	\
    ( (This)->lpVtbl -> CreatePin(This,ulPinType,pulPinId) ) 

#define IBDA_Topology_DeletePin(This,ulPinId)	\
    ( (This)->lpVtbl -> DeletePin(This,ulPinId) ) 

#define IBDA_Topology_SetMediaType(This,ulPinId,pMediaType)	\
    ( (This)->lpVtbl -> SetMediaType(This,ulPinId,pMediaType) ) 

#define IBDA_Topology_SetMedium(This,ulPinId,pMedium)	\
    ( (This)->lpVtbl -> SetMedium(This,ulPinId,pMedium) ) 

#define IBDA_Topology_CreateTopology(This,ulInputPinId,ulOutputPinId)	\
    ( (This)->lpVtbl -> CreateTopology(This,ulInputPinId,ulOutputPinId) ) 

#define IBDA_Topology_GetControlNode(This,ulInputPinId,ulOutputPinId,ulNodeType,ppControlNode)	\
    ( (This)->lpVtbl -> GetControlNode(This,ulInputPinId,ulOutputPinId,ulNodeType,ppControlNode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_Topology_INTERFACE_DEFINED__ */


#ifndef __IBDA_VoidTransform_INTERFACE_DEFINED__
#define __IBDA_VoidTransform_INTERFACE_DEFINED__

/* interface IBDA_VoidTransform */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_VoidTransform;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71985F46-1CA1-11d3-9CC8-00C04F7971E0")
    IBDA_VoidTransform : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_VoidTransformVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_VoidTransform * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_VoidTransform * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_VoidTransform * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IBDA_VoidTransform * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IBDA_VoidTransform * This);
        
        END_INTERFACE
    } IBDA_VoidTransformVtbl;

    interface IBDA_VoidTransform
    {
        CONST_VTBL struct IBDA_VoidTransformVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_VoidTransform_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_VoidTransform_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_VoidTransform_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_VoidTransform_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IBDA_VoidTransform_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_VoidTransform_INTERFACE_DEFINED__ */


#ifndef __IBDA_NullTransform_INTERFACE_DEFINED__
#define __IBDA_NullTransform_INTERFACE_DEFINED__

/* interface IBDA_NullTransform */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_NullTransform;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DDF15B0D-BD25-11d2-9CA0-00C04F7971E0")
    IBDA_NullTransform : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_NullTransformVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_NullTransform * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_NullTransform * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_NullTransform * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IBDA_NullTransform * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IBDA_NullTransform * This);
        
        END_INTERFACE
    } IBDA_NullTransformVtbl;

    interface IBDA_NullTransform
    {
        CONST_VTBL struct IBDA_NullTransformVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_NullTransform_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_NullTransform_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_NullTransform_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_NullTransform_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IBDA_NullTransform_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_NullTransform_INTERFACE_DEFINED__ */


#ifndef __IBDA_FrequencyFilter_INTERFACE_DEFINED__
#define __IBDA_FrequencyFilter_INTERFACE_DEFINED__

/* interface IBDA_FrequencyFilter */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_FrequencyFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71985F47-1CA1-11d3-9CC8-00C04F7971E0")
    IBDA_FrequencyFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_Autotune( 
            /* [in] */ ULONG ulTransponder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Autotune( 
            /* [out][in] */ __RPC__inout ULONG *pulTransponder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Frequency( 
            /* [in] */ ULONG ulFrequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Frequency( 
            /* [out][in] */ __RPC__inout ULONG *pulFrequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Polarity( 
            /* [in] */ Polarisation Polarity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Polarity( 
            /* [out][in] */ __RPC__inout Polarisation *pPolarity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Range( 
            /* [in] */ ULONG ulRange) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Range( 
            /* [out][in] */ __RPC__inout ULONG *pulRange) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Bandwidth( 
            /* [in] */ ULONG ulBandwidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Bandwidth( 
            /* [out][in] */ __RPC__inout ULONG *pulBandwidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_FrequencyMultiplier( 
            /* [in] */ ULONG ulMultiplier) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_FrequencyMultiplier( 
            /* [out][in] */ __RPC__inout ULONG *pulMultiplier) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_FrequencyFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_FrequencyFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_FrequencyFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_Autotune )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ ULONG ulTransponder);
        
        HRESULT ( STDMETHODCALLTYPE *get_Autotune )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulTransponder);
        
        HRESULT ( STDMETHODCALLTYPE *put_Frequency )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ ULONG ulFrequency);
        
        HRESULT ( STDMETHODCALLTYPE *get_Frequency )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulFrequency);
        
        HRESULT ( STDMETHODCALLTYPE *put_Polarity )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ Polarisation Polarity);
        
        HRESULT ( STDMETHODCALLTYPE *get_Polarity )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout Polarisation *pPolarity);
        
        HRESULT ( STDMETHODCALLTYPE *put_Range )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ ULONG ulRange);
        
        HRESULT ( STDMETHODCALLTYPE *get_Range )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulRange);
        
        HRESULT ( STDMETHODCALLTYPE *put_Bandwidth )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ ULONG ulBandwidth);
        
        HRESULT ( STDMETHODCALLTYPE *get_Bandwidth )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulBandwidth);
        
        HRESULT ( STDMETHODCALLTYPE *put_FrequencyMultiplier )( 
            IBDA_FrequencyFilter * This,
            /* [in] */ ULONG ulMultiplier);
        
        HRESULT ( STDMETHODCALLTYPE *get_FrequencyMultiplier )( 
            IBDA_FrequencyFilter * This,
            /* [out][in] */ __RPC__inout ULONG *pulMultiplier);
        
        END_INTERFACE
    } IBDA_FrequencyFilterVtbl;

    interface IBDA_FrequencyFilter
    {
        CONST_VTBL struct IBDA_FrequencyFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_FrequencyFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_FrequencyFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_FrequencyFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_FrequencyFilter_put_Autotune(This,ulTransponder)	\
    ( (This)->lpVtbl -> put_Autotune(This,ulTransponder) ) 

#define IBDA_FrequencyFilter_get_Autotune(This,pulTransponder)	\
    ( (This)->lpVtbl -> get_Autotune(This,pulTransponder) ) 

#define IBDA_FrequencyFilter_put_Frequency(This,ulFrequency)	\
    ( (This)->lpVtbl -> put_Frequency(This,ulFrequency) ) 

#define IBDA_FrequencyFilter_get_Frequency(This,pulFrequency)	\
    ( (This)->lpVtbl -> get_Frequency(This,pulFrequency) ) 

#define IBDA_FrequencyFilter_put_Polarity(This,Polarity)	\
    ( (This)->lpVtbl -> put_Polarity(This,Polarity) ) 

#define IBDA_FrequencyFilter_get_Polarity(This,pPolarity)	\
    ( (This)->lpVtbl -> get_Polarity(This,pPolarity) ) 

#define IBDA_FrequencyFilter_put_Range(This,ulRange)	\
    ( (This)->lpVtbl -> put_Range(This,ulRange) ) 

#define IBDA_FrequencyFilter_get_Range(This,pulRange)	\
    ( (This)->lpVtbl -> get_Range(This,pulRange) ) 

#define IBDA_FrequencyFilter_put_Bandwidth(This,ulBandwidth)	\
    ( (This)->lpVtbl -> put_Bandwidth(This,ulBandwidth) ) 

#define IBDA_FrequencyFilter_get_Bandwidth(This,pulBandwidth)	\
    ( (This)->lpVtbl -> get_Bandwidth(This,pulBandwidth) ) 

#define IBDA_FrequencyFilter_put_FrequencyMultiplier(This,ulMultiplier)	\
    ( (This)->lpVtbl -> put_FrequencyMultiplier(This,ulMultiplier) ) 

#define IBDA_FrequencyFilter_get_FrequencyMultiplier(This,pulMultiplier)	\
    ( (This)->lpVtbl -> get_FrequencyMultiplier(This,pulMultiplier) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_FrequencyFilter_INTERFACE_DEFINED__ */


#ifndef __IBDA_LNBInfo_INTERFACE_DEFINED__
#define __IBDA_LNBInfo_INTERFACE_DEFINED__

/* interface IBDA_LNBInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_LNBInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("992CF102-49F9-4719-A664-C4F23E2408F4")
    IBDA_LNBInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_LocalOscilatorFrequencyLowBand( 
            /* [in] */ ULONG ulLOFLow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LocalOscilatorFrequencyLowBand( 
            /* [out][in] */ __RPC__inout ULONG *pulLOFLow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_LocalOscilatorFrequencyHighBand( 
            /* [in] */ ULONG ulLOFHigh) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_LocalOscilatorFrequencyHighBand( 
            /* [out][in] */ __RPC__inout ULONG *pulLOFHigh) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_HighLowSwitchFrequency( 
            /* [in] */ ULONG ulSwitchFrequency) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_HighLowSwitchFrequency( 
            /* [out][in] */ __RPC__inout ULONG *pulSwitchFrequency) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_LNBInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_LNBInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_LNBInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_LNBInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_LocalOscilatorFrequencyLowBand )( 
            IBDA_LNBInfo * This,
            /* [in] */ ULONG ulLOFLow);
        
        HRESULT ( STDMETHODCALLTYPE *get_LocalOscilatorFrequencyLowBand )( 
            IBDA_LNBInfo * This,
            /* [out][in] */ __RPC__inout ULONG *pulLOFLow);
        
        HRESULT ( STDMETHODCALLTYPE *put_LocalOscilatorFrequencyHighBand )( 
            IBDA_LNBInfo * This,
            /* [in] */ ULONG ulLOFHigh);
        
        HRESULT ( STDMETHODCALLTYPE *get_LocalOscilatorFrequencyHighBand )( 
            IBDA_LNBInfo * This,
            /* [out][in] */ __RPC__inout ULONG *pulLOFHigh);
        
        HRESULT ( STDMETHODCALLTYPE *put_HighLowSwitchFrequency )( 
            IBDA_LNBInfo * This,
            /* [in] */ ULONG ulSwitchFrequency);
        
        HRESULT ( STDMETHODCALLTYPE *get_HighLowSwitchFrequency )( 
            IBDA_LNBInfo * This,
            /* [out][in] */ __RPC__inout ULONG *pulSwitchFrequency);
        
        END_INTERFACE
    } IBDA_LNBInfoVtbl;

    interface IBDA_LNBInfo
    {
        CONST_VTBL struct IBDA_LNBInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_LNBInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_LNBInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_LNBInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_LNBInfo_put_LocalOscilatorFrequencyLowBand(This,ulLOFLow)	\
    ( (This)->lpVtbl -> put_LocalOscilatorFrequencyLowBand(This,ulLOFLow) ) 

#define IBDA_LNBInfo_get_LocalOscilatorFrequencyLowBand(This,pulLOFLow)	\
    ( (This)->lpVtbl -> get_LocalOscilatorFrequencyLowBand(This,pulLOFLow) ) 

#define IBDA_LNBInfo_put_LocalOscilatorFrequencyHighBand(This,ulLOFHigh)	\
    ( (This)->lpVtbl -> put_LocalOscilatorFrequencyHighBand(This,ulLOFHigh) ) 

#define IBDA_LNBInfo_get_LocalOscilatorFrequencyHighBand(This,pulLOFHigh)	\
    ( (This)->lpVtbl -> get_LocalOscilatorFrequencyHighBand(This,pulLOFHigh) ) 

#define IBDA_LNBInfo_put_HighLowSwitchFrequency(This,ulSwitchFrequency)	\
    ( (This)->lpVtbl -> put_HighLowSwitchFrequency(This,ulSwitchFrequency) ) 

#define IBDA_LNBInfo_get_HighLowSwitchFrequency(This,pulSwitchFrequency)	\
    ( (This)->lpVtbl -> get_HighLowSwitchFrequency(This,pulSwitchFrequency) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_LNBInfo_INTERFACE_DEFINED__ */


#ifndef __IBDA_AutoDemodulate_INTERFACE_DEFINED__
#define __IBDA_AutoDemodulate_INTERFACE_DEFINED__

/* interface IBDA_AutoDemodulate */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_AutoDemodulate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DDF15B12-BD25-11d2-9CA0-00C04F7971E0")
    IBDA_AutoDemodulate : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_AutoDemodulate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_AutoDemodulateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_AutoDemodulate * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_AutoDemodulate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_AutoDemodulate * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_AutoDemodulate )( 
            IBDA_AutoDemodulate * This);
        
        END_INTERFACE
    } IBDA_AutoDemodulateVtbl;

    interface IBDA_AutoDemodulate
    {
        CONST_VTBL struct IBDA_AutoDemodulateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_AutoDemodulate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_AutoDemodulate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_AutoDemodulate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_AutoDemodulate_put_AutoDemodulate(This)	\
    ( (This)->lpVtbl -> put_AutoDemodulate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_AutoDemodulate_INTERFACE_DEFINED__ */


#ifndef __IBDA_AutoDemodulateEx_INTERFACE_DEFINED__
#define __IBDA_AutoDemodulateEx_INTERFACE_DEFINED__

/* interface IBDA_AutoDemodulateEx */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_AutoDemodulateEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34518D13-1182-48e6-B28F-B24987787326")
    IBDA_AutoDemodulateEx : public IBDA_AutoDemodulate
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_SupportedDeviceNodeTypes( 
            /* [in] */ ULONG ulcDeviceNodeTypesMax,
            /* [out] */ __RPC__out ULONG *pulcDeviceNodeTypes,
            /* [out][in] */ __RPC__inout GUID *pguidDeviceNodeTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SupportedVideoFormats( 
            /* [out] */ __RPC__out ULONG *pulAMTunerModeType,
            /* [out] */ __RPC__out ULONG *pulAnalogVideoStandard) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_AuxInputCount( 
            /* [out][in] */ __RPC__inout ULONG *pulCompositeCount,
            /* [out][in] */ __RPC__inout ULONG *pulSvideoCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_AutoDemodulateExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_AutoDemodulateEx * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_AutoDemodulateEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_AutoDemodulateEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_AutoDemodulate )( 
            IBDA_AutoDemodulateEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_SupportedDeviceNodeTypes )( 
            IBDA_AutoDemodulateEx * This,
            /* [in] */ ULONG ulcDeviceNodeTypesMax,
            /* [out] */ __RPC__out ULONG *pulcDeviceNodeTypes,
            /* [out][in] */ __RPC__inout GUID *pguidDeviceNodeTypes);
        
        HRESULT ( STDMETHODCALLTYPE *get_SupportedVideoFormats )( 
            IBDA_AutoDemodulateEx * This,
            /* [out] */ __RPC__out ULONG *pulAMTunerModeType,
            /* [out] */ __RPC__out ULONG *pulAnalogVideoStandard);
        
        HRESULT ( STDMETHODCALLTYPE *get_AuxInputCount )( 
            IBDA_AutoDemodulateEx * This,
            /* [out][in] */ __RPC__inout ULONG *pulCompositeCount,
            /* [out][in] */ __RPC__inout ULONG *pulSvideoCount);
        
        END_INTERFACE
    } IBDA_AutoDemodulateExVtbl;

    interface IBDA_AutoDemodulateEx
    {
        CONST_VTBL struct IBDA_AutoDemodulateExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_AutoDemodulateEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_AutoDemodulateEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_AutoDemodulateEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_AutoDemodulateEx_put_AutoDemodulate(This)	\
    ( (This)->lpVtbl -> put_AutoDemodulate(This) ) 


#define IBDA_AutoDemodulateEx_get_SupportedDeviceNodeTypes(This,ulcDeviceNodeTypesMax,pulcDeviceNodeTypes,pguidDeviceNodeTypes)	\
    ( (This)->lpVtbl -> get_SupportedDeviceNodeTypes(This,ulcDeviceNodeTypesMax,pulcDeviceNodeTypes,pguidDeviceNodeTypes) ) 

#define IBDA_AutoDemodulateEx_get_SupportedVideoFormats(This,pulAMTunerModeType,pulAnalogVideoStandard)	\
    ( (This)->lpVtbl -> get_SupportedVideoFormats(This,pulAMTunerModeType,pulAnalogVideoStandard) ) 

#define IBDA_AutoDemodulateEx_get_AuxInputCount(This,pulCompositeCount,pulSvideoCount)	\
    ( (This)->lpVtbl -> get_AuxInputCount(This,pulCompositeCount,pulSvideoCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_AutoDemodulateEx_INTERFACE_DEFINED__ */


#ifndef __IBDA_DigitalDemodulator_INTERFACE_DEFINED__
#define __IBDA_DigitalDemodulator_INTERFACE_DEFINED__

/* interface IBDA_DigitalDemodulator */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_DigitalDemodulator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF30F379-985B-4d10-B640-A79D5E04E1E0")
    IBDA_DigitalDemodulator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_ModulationType( 
            /* [in] */ __RPC__in ModulationType *pModulationType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ModulationType( 
            /* [out][in] */ __RPC__inout ModulationType *pModulationType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_InnerFECMethod( 
            /* [in] */ __RPC__in FECMethod *pFECMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_InnerFECMethod( 
            /* [out][in] */ __RPC__inout FECMethod *pFECMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_InnerFECRate( 
            /* [in] */ __RPC__in BinaryConvolutionCodeRate *pFECRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_InnerFECRate( 
            /* [out][in] */ __RPC__inout BinaryConvolutionCodeRate *pFECRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OuterFECMethod( 
            /* [in] */ __RPC__in FECMethod *pFECMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OuterFECMethod( 
            /* [out][in] */ __RPC__inout FECMethod *pFECMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OuterFECRate( 
            /* [in] */ __RPC__in BinaryConvolutionCodeRate *pFECRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OuterFECRate( 
            /* [out][in] */ __RPC__inout BinaryConvolutionCodeRate *pFECRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SymbolRate( 
            /* [in] */ __RPC__in ULONG *pSymbolRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SymbolRate( 
            /* [out][in] */ __RPC__inout ULONG *pSymbolRate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SpectralInversion( 
            /* [in] */ __RPC__in SpectralInversion *pSpectralInversion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SpectralInversion( 
            /* [out][in] */ __RPC__inout SpectralInversion *pSpectralInversion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_DigitalDemodulatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_DigitalDemodulator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_DigitalDemodulator * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_ModulationType )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in ModulationType *pModulationType);
        
        HRESULT ( STDMETHODCALLTYPE *get_ModulationType )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout ModulationType *pModulationType);
        
        HRESULT ( STDMETHODCALLTYPE *put_InnerFECMethod )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in FECMethod *pFECMethod);
        
        HRESULT ( STDMETHODCALLTYPE *get_InnerFECMethod )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout FECMethod *pFECMethod);
        
        HRESULT ( STDMETHODCALLTYPE *put_InnerFECRate )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in BinaryConvolutionCodeRate *pFECRate);
        
        HRESULT ( STDMETHODCALLTYPE *get_InnerFECRate )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout BinaryConvolutionCodeRate *pFECRate);
        
        HRESULT ( STDMETHODCALLTYPE *put_OuterFECMethod )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in FECMethod *pFECMethod);
        
        HRESULT ( STDMETHODCALLTYPE *get_OuterFECMethod )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout FECMethod *pFECMethod);
        
        HRESULT ( STDMETHODCALLTYPE *put_OuterFECRate )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in BinaryConvolutionCodeRate *pFECRate);
        
        HRESULT ( STDMETHODCALLTYPE *get_OuterFECRate )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout BinaryConvolutionCodeRate *pFECRate);
        
        HRESULT ( STDMETHODCALLTYPE *put_SymbolRate )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in ULONG *pSymbolRate);
        
        HRESULT ( STDMETHODCALLTYPE *get_SymbolRate )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout ULONG *pSymbolRate);
        
        HRESULT ( STDMETHODCALLTYPE *put_SpectralInversion )( 
            IBDA_DigitalDemodulator * This,
            /* [in] */ __RPC__in SpectralInversion *pSpectralInversion);
        
        HRESULT ( STDMETHODCALLTYPE *get_SpectralInversion )( 
            IBDA_DigitalDemodulator * This,
            /* [out][in] */ __RPC__inout SpectralInversion *pSpectralInversion);
        
        END_INTERFACE
    } IBDA_DigitalDemodulatorVtbl;

    interface IBDA_DigitalDemodulator
    {
        CONST_VTBL struct IBDA_DigitalDemodulatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_DigitalDemodulator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_DigitalDemodulator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_DigitalDemodulator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_DigitalDemodulator_put_ModulationType(This,pModulationType)	\
    ( (This)->lpVtbl -> put_ModulationType(This,pModulationType) ) 

#define IBDA_DigitalDemodulator_get_ModulationType(This,pModulationType)	\
    ( (This)->lpVtbl -> get_ModulationType(This,pModulationType) ) 

#define IBDA_DigitalDemodulator_put_InnerFECMethod(This,pFECMethod)	\
    ( (This)->lpVtbl -> put_InnerFECMethod(This,pFECMethod) ) 

#define IBDA_DigitalDemodulator_get_InnerFECMethod(This,pFECMethod)	\
    ( (This)->lpVtbl -> get_InnerFECMethod(This,pFECMethod) ) 

#define IBDA_DigitalDemodulator_put_InnerFECRate(This,pFECRate)	\
    ( (This)->lpVtbl -> put_InnerFECRate(This,pFECRate) ) 

#define IBDA_DigitalDemodulator_get_InnerFECRate(This,pFECRate)	\
    ( (This)->lpVtbl -> get_InnerFECRate(This,pFECRate) ) 

#define IBDA_DigitalDemodulator_put_OuterFECMethod(This,pFECMethod)	\
    ( (This)->lpVtbl -> put_OuterFECMethod(This,pFECMethod) ) 

#define IBDA_DigitalDemodulator_get_OuterFECMethod(This,pFECMethod)	\
    ( (This)->lpVtbl -> get_OuterFECMethod(This,pFECMethod) ) 

#define IBDA_DigitalDemodulator_put_OuterFECRate(This,pFECRate)	\
    ( (This)->lpVtbl -> put_OuterFECRate(This,pFECRate) ) 

#define IBDA_DigitalDemodulator_get_OuterFECRate(This,pFECRate)	\
    ( (This)->lpVtbl -> get_OuterFECRate(This,pFECRate) ) 

#define IBDA_DigitalDemodulator_put_SymbolRate(This,pSymbolRate)	\
    ( (This)->lpVtbl -> put_SymbolRate(This,pSymbolRate) ) 

#define IBDA_DigitalDemodulator_get_SymbolRate(This,pSymbolRate)	\
    ( (This)->lpVtbl -> get_SymbolRate(This,pSymbolRate) ) 

#define IBDA_DigitalDemodulator_put_SpectralInversion(This,pSpectralInversion)	\
    ( (This)->lpVtbl -> put_SpectralInversion(This,pSpectralInversion) ) 

#define IBDA_DigitalDemodulator_get_SpectralInversion(This,pSpectralInversion)	\
    ( (This)->lpVtbl -> get_SpectralInversion(This,pSpectralInversion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_DigitalDemodulator_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0016 */
/* [local] */ 

typedef /* [public] */ 
enum __MIDL___MIDL_itf_bdaiface_0000_0016_0001
    {	KSPROPERTY_IPSINK_MULTICASTLIST	= 0,
	KSPROPERTY_IPSINK_ADAPTER_DESCRIPTION	= ( KSPROPERTY_IPSINK_MULTICASTLIST + 1 ) ,
	KSPROPERTY_IPSINK_ADAPTER_ADDRESS	= ( KSPROPERTY_IPSINK_ADAPTER_DESCRIPTION + 1 ) 
    } 	KSPROPERTY_IPSINK;



extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0016_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0016_v0_0_s_ifspec;

#ifndef __ICCSubStreamFiltering_INTERFACE_DEFINED__
#define __ICCSubStreamFiltering_INTERFACE_DEFINED__

/* interface ICCSubStreamFiltering */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICCSubStreamFiltering;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B2BD7EA-8347-467b-8DBF-62F784929CC3")
    ICCSubStreamFiltering : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_SubstreamTypes( 
            /* [retval][out] */ __RPC__out long *pTypes) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_SubstreamTypes( 
            /* [in] */ long Types) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICCSubStreamFilteringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICCSubStreamFiltering * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICCSubStreamFiltering * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICCSubStreamFiltering * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubstreamTypes )( 
            ICCSubStreamFiltering * This,
            /* [retval][out] */ __RPC__out long *pTypes);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubstreamTypes )( 
            ICCSubStreamFiltering * This,
            /* [in] */ long Types);
        
        END_INTERFACE
    } ICCSubStreamFilteringVtbl;

    interface ICCSubStreamFiltering
    {
        CONST_VTBL struct ICCSubStreamFilteringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICCSubStreamFiltering_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICCSubStreamFiltering_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICCSubStreamFiltering_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICCSubStreamFiltering_get_SubstreamTypes(This,pTypes)	\
    ( (This)->lpVtbl -> get_SubstreamTypes(This,pTypes) ) 

#define ICCSubStreamFiltering_put_SubstreamTypes(This,Types)	\
    ( (This)->lpVtbl -> put_SubstreamTypes(This,Types) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICCSubStreamFiltering_INTERFACE_DEFINED__ */


#ifndef __IBDA_IPSinkControl_INTERFACE_DEFINED__
#define __IBDA_IPSinkControl_INTERFACE_DEFINED__

/* interface IBDA_IPSinkControl */
/* [helpstring][unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_IPSinkControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F4DC8E2-4050-11d3-8F4B-00C04F7971E2")
    IBDA_IPSinkControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMulticastList( 
            /* [out][in] */ __RPC__inout unsigned long *pulcbSize,
            /* [out][in] */ __RPC__deref_inout_opt BYTE **pbBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdapterIPAddress( 
            /* [out][in] */ __RPC__inout unsigned long *pulcbSize,
            /* [out][in] */ __RPC__deref_inout_opt BYTE **pbBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_IPSinkControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_IPSinkControl * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_IPSinkControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_IPSinkControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMulticastList )( 
            IBDA_IPSinkControl * This,
            /* [out][in] */ __RPC__inout unsigned long *pulcbSize,
            /* [out][in] */ __RPC__deref_inout_opt BYTE **pbBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdapterIPAddress )( 
            IBDA_IPSinkControl * This,
            /* [out][in] */ __RPC__inout unsigned long *pulcbSize,
            /* [out][in] */ __RPC__deref_inout_opt BYTE **pbBuffer);
        
        END_INTERFACE
    } IBDA_IPSinkControlVtbl;

    interface IBDA_IPSinkControl
    {
        CONST_VTBL struct IBDA_IPSinkControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_IPSinkControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_IPSinkControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_IPSinkControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_IPSinkControl_GetMulticastList(This,pulcbSize,pbBuffer)	\
    ( (This)->lpVtbl -> GetMulticastList(This,pulcbSize,pbBuffer) ) 

#define IBDA_IPSinkControl_GetAdapterIPAddress(This,pulcbSize,pbBuffer)	\
    ( (This)->lpVtbl -> GetAdapterIPAddress(This,pulcbSize,pbBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_IPSinkControl_INTERFACE_DEFINED__ */


#ifndef __IBDA_IPSinkInfo_INTERFACE_DEFINED__
#define __IBDA_IPSinkInfo_INTERFACE_DEFINED__

/* interface IBDA_IPSinkInfo */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IBDA_IPSinkInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A750108F-492E-4d51-95F7-649B23FF7AD7")
    IBDA_IPSinkInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_MulticastList( 
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE **ppbAddressList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_AdapterIPAddress( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_AdapterDescription( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_IPSinkInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_IPSinkInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_IPSinkInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_IPSinkInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_MulticastList )( 
            IBDA_IPSinkInfo * This,
            /* [out][in] */ __RPC__inout ULONG *pulcbAddresses,
            /* [size_is][out] */ __RPC__out_ecount_full(*pulcbAddresses) BYTE **ppbAddressList);
        
        HRESULT ( STDMETHODCALLTYPE *get_AdapterIPAddress )( 
            IBDA_IPSinkInfo * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *get_AdapterDescription )( 
            IBDA_IPSinkInfo * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrBuffer);
        
        END_INTERFACE
    } IBDA_IPSinkInfoVtbl;

    interface IBDA_IPSinkInfo
    {
        CONST_VTBL struct IBDA_IPSinkInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_IPSinkInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_IPSinkInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_IPSinkInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_IPSinkInfo_get_MulticastList(This,pulcbAddresses,ppbAddressList)	\
    ( (This)->lpVtbl -> get_MulticastList(This,pulcbAddresses,ppbAddressList) ) 

#define IBDA_IPSinkInfo_get_AdapterIPAddress(This,pbstrBuffer)	\
    ( (This)->lpVtbl -> get_AdapterIPAddress(This,pbstrBuffer) ) 

#define IBDA_IPSinkInfo_get_AdapterDescription(This,pbstrBuffer)	\
    ( (This)->lpVtbl -> get_AdapterDescription(This,pbstrBuffer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_IPSinkInfo_INTERFACE_DEFINED__ */


#ifndef __IEnumPIDMap_INTERFACE_DEFINED__
#define __IEnumPIDMap_INTERFACE_DEFINED__

/* interface IEnumPIDMap */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumPIDMap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("afb6c2a2-2c41-11d3-8a60-0000f81e0e4a")
    IEnumPIDMap : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cRequest,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(cRequest) PID_MAP *pPIDMap,
            /* [out] */ __RPC__out ULONG *pcReceived) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cRecords) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumPIDMap **ppIEnumPIDMap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumPIDMapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumPIDMap * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumPIDMap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumPIDMap * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumPIDMap * This,
            /* [in] */ ULONG cRequest,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(cRequest) PID_MAP *pPIDMap,
            /* [out] */ __RPC__out ULONG *pcReceived);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumPIDMap * This,
            /* [in] */ ULONG cRecords);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumPIDMap * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumPIDMap * This,
            /* [out] */ __RPC__deref_out_opt IEnumPIDMap **ppIEnumPIDMap);
        
        END_INTERFACE
    } IEnumPIDMapVtbl;

    interface IEnumPIDMap
    {
        CONST_VTBL struct IEnumPIDMapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumPIDMap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumPIDMap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumPIDMap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumPIDMap_Next(This,cRequest,pPIDMap,pcReceived)	\
    ( (This)->lpVtbl -> Next(This,cRequest,pPIDMap,pcReceived) ) 

#define IEnumPIDMap_Skip(This,cRecords)	\
    ( (This)->lpVtbl -> Skip(This,cRecords) ) 

#define IEnumPIDMap_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumPIDMap_Clone(This,ppIEnumPIDMap)	\
    ( (This)->lpVtbl -> Clone(This,ppIEnumPIDMap) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumPIDMap_INTERFACE_DEFINED__ */


#ifndef __IMPEG2PIDMap_INTERFACE_DEFINED__
#define __IMPEG2PIDMap_INTERFACE_DEFINED__

/* interface IMPEG2PIDMap */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMPEG2PIDMap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("afb6c2a1-2c41-11d3-8a60-0000f81e0e4a")
    IMPEG2PIDMap : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MapPID( 
            /* [in] */ ULONG culPID,
            /* [in] */ __RPC__in ULONG *pulPID,
            /* [in] */ MEDIA_SAMPLE_CONTENT MediaSampleContent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnmapPID( 
            /* [in] */ ULONG culPID,
            /* [in] */ __RPC__in ULONG *pulPID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPIDMap( 
            /* [out] */ __RPC__deref_out_opt IEnumPIDMap **pIEnumPIDMap) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMPEG2PIDMapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMPEG2PIDMap * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMPEG2PIDMap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMPEG2PIDMap * This);
        
        HRESULT ( STDMETHODCALLTYPE *MapPID )( 
            IMPEG2PIDMap * This,
            /* [in] */ ULONG culPID,
            /* [in] */ __RPC__in ULONG *pulPID,
            /* [in] */ MEDIA_SAMPLE_CONTENT MediaSampleContent);
        
        HRESULT ( STDMETHODCALLTYPE *UnmapPID )( 
            IMPEG2PIDMap * This,
            /* [in] */ ULONG culPID,
            /* [in] */ __RPC__in ULONG *pulPID);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPIDMap )( 
            IMPEG2PIDMap * This,
            /* [out] */ __RPC__deref_out_opt IEnumPIDMap **pIEnumPIDMap);
        
        END_INTERFACE
    } IMPEG2PIDMapVtbl;

    interface IMPEG2PIDMap
    {
        CONST_VTBL struct IMPEG2PIDMapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMPEG2PIDMap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMPEG2PIDMap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMPEG2PIDMap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMPEG2PIDMap_MapPID(This,culPID,pulPID,MediaSampleContent)	\
    ( (This)->lpVtbl -> MapPID(This,culPID,pulPID,MediaSampleContent) ) 

#define IMPEG2PIDMap_UnmapPID(This,culPID,pulPID)	\
    ( (This)->lpVtbl -> UnmapPID(This,culPID,pulPID) ) 

#define IMPEG2PIDMap_EnumPIDMap(This,pIEnumPIDMap)	\
    ( (This)->lpVtbl -> EnumPIDMap(This,pIEnumPIDMap) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMPEG2PIDMap_INTERFACE_DEFINED__ */


#ifndef __IFrequencyMap_INTERFACE_DEFINED__
#define __IFrequencyMap_INTERFACE_DEFINED__

/* interface IFrequencyMap */
/* [restricted][hidden][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFrequencyMap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06FB45C1-693C-4ea7-B79F-7A6A54D8DEF2")
    IFrequencyMap : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_FrequencyMapping( 
            /* [out] */ __RPC__out ULONG *ulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE put_FrequencyMapping( 
            /* [in] */ ULONG ulCount,
            /* [size_is][in] */ __RPC__in_ecount_full(ulCount) ULONG pList[  ]) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_CountryCode( 
            /* [out] */ __RPC__out ULONG *pulCountryCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE put_CountryCode( 
            /* [in] */ ULONG ulCountryCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_DefaultFrequencyMapping( 
            /* [in] */ ULONG ulCountryCode,
            /* [out] */ __RPC__out ULONG *pulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_CountryCodeList( 
            /* [out] */ __RPC__out ULONG *pulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFrequencyMapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFrequencyMap * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFrequencyMap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFrequencyMap * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_FrequencyMapping )( 
            IFrequencyMap * This,
            /* [out] */ __RPC__out ULONG *ulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *put_FrequencyMapping )( 
            IFrequencyMap * This,
            /* [in] */ ULONG ulCount,
            /* [size_is][in] */ __RPC__in_ecount_full(ulCount) ULONG pList[  ]);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_CountryCode )( 
            IFrequencyMap * This,
            /* [out] */ __RPC__out ULONG *pulCountryCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *put_CountryCode )( 
            IFrequencyMap * This,
            /* [in] */ ULONG ulCountryCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultFrequencyMapping )( 
            IFrequencyMap * This,
            /* [in] */ ULONG ulCountryCode,
            /* [out] */ __RPC__out ULONG *pulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_CountryCodeList )( 
            IFrequencyMap * This,
            /* [out] */ __RPC__out ULONG *pulCount,
            /* [size_is][size_is][out] */ __RPC__out_ecount_full(1) ULONG **ppulList);
        
        END_INTERFACE
    } IFrequencyMapVtbl;

    interface IFrequencyMap
    {
        CONST_VTBL struct IFrequencyMapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFrequencyMap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFrequencyMap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFrequencyMap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFrequencyMap_get_FrequencyMapping(This,ulCount,ppulList)	\
    ( (This)->lpVtbl -> get_FrequencyMapping(This,ulCount,ppulList) ) 

#define IFrequencyMap_put_FrequencyMapping(This,ulCount,pList)	\
    ( (This)->lpVtbl -> put_FrequencyMapping(This,ulCount,pList) ) 

#define IFrequencyMap_get_CountryCode(This,pulCountryCode)	\
    ( (This)->lpVtbl -> get_CountryCode(This,pulCountryCode) ) 

#define IFrequencyMap_put_CountryCode(This,ulCountryCode)	\
    ( (This)->lpVtbl -> put_CountryCode(This,ulCountryCode) ) 

#define IFrequencyMap_get_DefaultFrequencyMapping(This,ulCountryCode,pulCount,ppulList)	\
    ( (This)->lpVtbl -> get_DefaultFrequencyMapping(This,ulCountryCode,pulCount,ppulList) ) 

#define IFrequencyMap_get_CountryCodeList(This,pulCount,ppulList)	\
    ( (This)->lpVtbl -> get_CountryCodeList(This,pulCount,ppulList) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFrequencyMap_INTERFACE_DEFINED__ */


#ifndef __IBDA_EasMessage_INTERFACE_DEFINED__
#define __IBDA_EasMessage_INTERFACE_DEFINED__

/* interface IBDA_EasMessage */
/* [restricted][hidden][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBDA_EasMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D806973D-3EBE-46de-8FBB-6358FE784208")
    IBDA_EasMessage : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_EasMessage( 
            /* [in] */ ULONG ulEventID,
            /* [out][in] */ __RPC__deref_inout_opt IUnknown **ppEASObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_EasMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_EasMessage * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_EasMessage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_EasMessage * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_EasMessage )( 
            IBDA_EasMessage * This,
            /* [in] */ ULONG ulEventID,
            /* [out][in] */ __RPC__deref_inout_opt IUnknown **ppEASObject);
        
        END_INTERFACE
    } IBDA_EasMessageVtbl;

    interface IBDA_EasMessage
    {
        CONST_VTBL struct IBDA_EasMessageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_EasMessage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_EasMessage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_EasMessage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_EasMessage_get_EasMessage(This,ulEventID,ppEASObject)	\
    ( (This)->lpVtbl -> get_EasMessage(This,ulEventID,ppEASObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_EasMessage_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0023 */
/* [local] */ 

#define SID_BDA_EasMessage __uuidof(IBDA_EasMessage)


extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0023_v0_0_s_ifspec;

#ifndef __IBDA_TransportStreamInfo_INTERFACE_DEFINED__
#define __IBDA_TransportStreamInfo_INTERFACE_DEFINED__

/* interface IBDA_TransportStreamInfo */
/* [restricted][hidden][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBDA_TransportStreamInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E882535-5F86-47AB-86CF-C281A72A0549")
    IBDA_TransportStreamInfo : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_PatTableTickCount( 
            /* [out] */ __RPC__out ULONG *pPatTickCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_TransportStreamInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_TransportStreamInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_TransportStreamInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_TransportStreamInfo * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_PatTableTickCount )( 
            IBDA_TransportStreamInfo * This,
            /* [out] */ __RPC__out ULONG *pPatTickCount);
        
        END_INTERFACE
    } IBDA_TransportStreamInfoVtbl;

    interface IBDA_TransportStreamInfo
    {
        CONST_VTBL struct IBDA_TransportStreamInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_TransportStreamInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_TransportStreamInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_TransportStreamInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_TransportStreamInfo_get_PatTableTickCount(This,pPatTickCount)	\
    ( (This)->lpVtbl -> get_PatTableTickCount(This,pPatTickCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_TransportStreamInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0024 */
/* [local] */ 

#define SID_BDA_TransportStreamInfo __uuidof(IBDA_TransportStreamInfo)
typedef /* [v1_enum] */ 
enum SmartCardStatusType
    {	CardInserted	= 0,
	CardRemoved	= ( CardInserted + 1 ) ,
	CardError	= ( CardRemoved + 1 ) ,
	CardDataChanged	= ( CardError + 1 ) ,
	CardFirmwareUpgrade	= ( CardDataChanged + 1 ) 
    } 	SmartCardStatusType;

typedef /* [v1_enum] */ 
enum SmartCardAssociationType
    {	NotAssociated	= 0,
	Associated	= ( NotAssociated + 1 ) ,
	AssociationUnknown	= ( Associated + 1 ) 
    } 	SmartCardAssociationType;

typedef /* [v1_enum] */ 
enum LocationCodeSchemeType
    {	SCTE_18	= 0
    } 	LocationCodeSchemeType;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_bdaiface_0000_0024_0001
    {
    LocationCodeSchemeType LocationCodeScheme;
    BYTE state_code;
    BYTE county_subdivision;
    WORD county_code;
    } 	EALocationCodeType;

typedef /* [v1_enum] */ 
enum EntitlementType
    {	Entitled	= 0,
	NotEntitled	= ( Entitled + 1 ) ,
	TechnicalFailure	= ( NotEntitled + 1 ) 
    } 	EntitlementType;

typedef /* [v1_enum] */ 
enum UICloseReasonType
    {	NotReady	= 0,
	UserClosed	= ( NotReady + 1 ) ,
	SystemClosed	= ( UserClosed + 1 ) ,
	DeviceClosed	= ( SystemClosed + 1 ) ,
	ErrorClosed	= ( DeviceClosed + 1 ) 
    } 	UICloseReasonType;

#ifndef MANAGED_ENUMS
typedef /* [public][public] */ struct __MIDL___MIDL_itf_bdaiface_0000_0024_0002
    {
    ApplicationTypeType ApplicationType;
    USHORT ApplicationVersion;
    BSTR pbstrApplicationName;
    BSTR pbstrApplicationURL;
    } 	SmartCardApplication;

#endif


extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0024_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0024_v0_0_s_ifspec;

#ifndef __IBDA_ConditionalAccess_INTERFACE_DEFINED__
#define __IBDA_ConditionalAccess_INTERFACE_DEFINED__

/* interface IBDA_ConditionalAccess */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBDA_ConditionalAccess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CD51F1E0-7BE9-4123-8482-A2A796C0A6B0")
    IBDA_ConditionalAccess : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_SmartCardStatus( 
            /* [out] */ __RPC__out SmartCardStatusType *pCardStatus,
            /* [out] */ __RPC__out SmartCardAssociationType *pCardAssociation,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardError,
            /* [out] */ __RPC__out VARIANT_BOOL *pfOOBLocked) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_SmartCardInfo( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardName,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardManufacturer,
            /* [out] */ __RPC__out VARIANT_BOOL *pfDaylightSavings,
            /* [out] */ __RPC__out BYTE *pbyRatingRegion,
            /* [out] */ __RPC__out LONG *plTimeZoneOffsetMinutes,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrLanguage,
            /* [out] */ __RPC__out EALocationCodeType *pEALocationCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_SmartCardApplications( 
            /* [out][in] */ __RPC__inout ULONG *pulcApplications,
            /* [in] */ ULONG ulcApplicationsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcApplicationsMax) SmartCardApplication rgApplications[  ]) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_Entitlement( 
            /* [in] */ USHORT usVirtualChannel,
            /* [out] */ __RPC__out EntitlementType *pEntitlement) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE TuneByChannel( 
            /* [in] */ USHORT usVirtualChannel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProgram( 
            /* [in] */ USHORT usProgramNumber) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddProgram( 
            /* [in] */ USHORT usProgramNumber) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemoveProgram( 
            /* [in] */ USHORT usProgramNumber) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetModuleUI( 
            /* [in] */ BYTE byDialogNumber,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrURL) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InformUIClosed( 
            /* [in] */ BYTE byDialogNumber,
            /* [in] */ UICloseReasonType CloseReason) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_ConditionalAccessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_ConditionalAccess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_ConditionalAccess * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_SmartCardStatus )( 
            IBDA_ConditionalAccess * This,
            /* [out] */ __RPC__out SmartCardStatusType *pCardStatus,
            /* [out] */ __RPC__out SmartCardAssociationType *pCardAssociation,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardError,
            /* [out] */ __RPC__out VARIANT_BOOL *pfOOBLocked);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_SmartCardInfo )( 
            IBDA_ConditionalAccess * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardName,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrCardManufacturer,
            /* [out] */ __RPC__out VARIANT_BOOL *pfDaylightSavings,
            /* [out] */ __RPC__out BYTE *pbyRatingRegion,
            /* [out] */ __RPC__out LONG *plTimeZoneOffsetMinutes,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrLanguage,
            /* [out] */ __RPC__out EALocationCodeType *pEALocationCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_SmartCardApplications )( 
            IBDA_ConditionalAccess * This,
            /* [out][in] */ __RPC__inout ULONG *pulcApplications,
            /* [in] */ ULONG ulcApplicationsMax,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(ulcApplicationsMax) SmartCardApplication rgApplications[  ]);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_Entitlement )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ USHORT usVirtualChannel,
            /* [out] */ __RPC__out EntitlementType *pEntitlement);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *TuneByChannel )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ USHORT usVirtualChannel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetProgram )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ USHORT usProgramNumber);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddProgram )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ USHORT usProgramNumber);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveProgram )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ USHORT usProgramNumber);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetModuleUI )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ BYTE byDialogNumber,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrURL);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InformUIClosed )( 
            IBDA_ConditionalAccess * This,
            /* [in] */ BYTE byDialogNumber,
            /* [in] */ UICloseReasonType CloseReason);
        
        END_INTERFACE
    } IBDA_ConditionalAccessVtbl;

    interface IBDA_ConditionalAccess
    {
        CONST_VTBL struct IBDA_ConditionalAccessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_ConditionalAccess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_ConditionalAccess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_ConditionalAccess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_ConditionalAccess_get_SmartCardStatus(This,pCardStatus,pCardAssociation,pbstrCardError,pfOOBLocked)	\
    ( (This)->lpVtbl -> get_SmartCardStatus(This,pCardStatus,pCardAssociation,pbstrCardError,pfOOBLocked) ) 

#define IBDA_ConditionalAccess_get_SmartCardInfo(This,pbstrCardName,pbstrCardManufacturer,pfDaylightSavings,pbyRatingRegion,plTimeZoneOffsetMinutes,pbstrLanguage,pEALocationCode)	\
    ( (This)->lpVtbl -> get_SmartCardInfo(This,pbstrCardName,pbstrCardManufacturer,pfDaylightSavings,pbyRatingRegion,plTimeZoneOffsetMinutes,pbstrLanguage,pEALocationCode) ) 

#define IBDA_ConditionalAccess_get_SmartCardApplications(This,pulcApplications,ulcApplicationsMax,rgApplications)	\
    ( (This)->lpVtbl -> get_SmartCardApplications(This,pulcApplications,ulcApplicationsMax,rgApplications) ) 

#define IBDA_ConditionalAccess_get_Entitlement(This,usVirtualChannel,pEntitlement)	\
    ( (This)->lpVtbl -> get_Entitlement(This,usVirtualChannel,pEntitlement) ) 

#define IBDA_ConditionalAccess_TuneByChannel(This,usVirtualChannel)	\
    ( (This)->lpVtbl -> TuneByChannel(This,usVirtualChannel) ) 

#define IBDA_ConditionalAccess_SetProgram(This,usProgramNumber)	\
    ( (This)->lpVtbl -> SetProgram(This,usProgramNumber) ) 

#define IBDA_ConditionalAccess_AddProgram(This,usProgramNumber)	\
    ( (This)->lpVtbl -> AddProgram(This,usProgramNumber) ) 

#define IBDA_ConditionalAccess_RemoveProgram(This,usProgramNumber)	\
    ( (This)->lpVtbl -> RemoveProgram(This,usProgramNumber) ) 

#define IBDA_ConditionalAccess_GetModuleUI(This,byDialogNumber,pbstrURL)	\
    ( (This)->lpVtbl -> GetModuleUI(This,byDialogNumber,pbstrURL) ) 

#define IBDA_ConditionalAccess_InformUIClosed(This,byDialogNumber,CloseReason)	\
    ( (This)->lpVtbl -> InformUIClosed(This,byDialogNumber,CloseReason) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_ConditionalAccess_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0025 */
/* [local] */ 

#define SID_BDA_ConditionalAccess __uuidof(IBDA_ConditionalAccess)


extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0025_v0_0_s_ifspec;

#ifndef __IBDA_DiagnosticProperties_INTERFACE_DEFINED__
#define __IBDA_DiagnosticProperties_INTERFACE_DEFINED__

/* interface IBDA_DiagnosticProperties */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBDA_DiagnosticProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20e80cb5-c543-4c1b-8eb3-49e719eee7d4")
    IBDA_DiagnosticProperties : public IPropertyBag
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IBDA_DiagnosticPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_DiagnosticProperties * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_DiagnosticProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_DiagnosticProperties * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Read )( 
            IBDA_DiagnosticProperties * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT *pVar,
            /* [unique][in] */ IErrorLog *pErrorLog);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IBDA_DiagnosticProperties * This,
            /* [in] */ __RPC__in LPCOLESTR pszPropName,
            /* [in] */ __RPC__in VARIANT *pVar);
        
        END_INTERFACE
    } IBDA_DiagnosticPropertiesVtbl;

    interface IBDA_DiagnosticProperties
    {
        CONST_VTBL struct IBDA_DiagnosticPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_DiagnosticProperties_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_DiagnosticProperties_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_DiagnosticProperties_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_DiagnosticProperties_Read(This,pszPropName,pVar,pErrorLog)	\
    ( (This)->lpVtbl -> Read(This,pszPropName,pVar,pErrorLog) ) 

#define IBDA_DiagnosticProperties_Write(This,pszPropName,pVar)	\
    ( (This)->lpVtbl -> Write(This,pszPropName,pVar) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_DiagnosticProperties_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0026 */
/* [local] */ 

#define SID_BDA_DiagnosticProperties __uuidof(IBDA_DiagnosticProperties)
typedef 
enum BDA_DrmPairingError
    {	BDA_DrmPairing_Succeeded	= 0,
	BDA_DrmPairing_HardwareFailure	= ( BDA_DrmPairing_Succeeded + 1 ) ,
	BDA_DrmPairing_NeedRevocationData	= ( BDA_DrmPairing_HardwareFailure + 1 ) ,
	BDA_DrmPairing_NeedIndiv	= ( BDA_DrmPairing_NeedRevocationData + 1 ) ,
	BDA_DrmPairing_Other	= ( BDA_DrmPairing_NeedIndiv + 1 ) ,
	BDA_DrmPairing_DrmInitFailed	= ( BDA_DrmPairing_Other + 1 ) ,
	BDA_DrmPairing_DrmNotPaired	= ( BDA_DrmPairing_DrmInitFailed + 1 ) ,
	BDA_DrmPairing_DrmRePairSoon	= ( BDA_DrmPairing_DrmNotPaired + 1 ) 
    } 	BDA_DrmPairingError;



extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0026_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0026_v0_0_s_ifspec;

#ifndef __IBDA_DRM_INTERFACE_DEFINED__
#define __IBDA_DRM_INTERFACE_DEFINED__

/* interface IBDA_DRM */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBDA_DRM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F98D88B0-1992-4cd6-A6D9-B9AFAB99330D")
    IBDA_DRM : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDRMPairingStatus( 
            /* [out] */ __RPC__out DWORD *pdwStatus,
            /* [out] */ __RPC__out HRESULT *phError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PerformDRMPairing( 
            BOOL fSync) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBDA_DRMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBDA_DRM * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBDA_DRM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBDA_DRM * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDRMPairingStatus )( 
            IBDA_DRM * This,
            /* [out] */ __RPC__out DWORD *pdwStatus,
            /* [out] */ __RPC__out HRESULT *phError);
        
        HRESULT ( STDMETHODCALLTYPE *PerformDRMPairing )( 
            IBDA_DRM * This,
            BOOL fSync);
        
        END_INTERFACE
    } IBDA_DRMVtbl;

    interface IBDA_DRM
    {
        CONST_VTBL struct IBDA_DRMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBDA_DRM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBDA_DRM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBDA_DRM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBDA_DRM_GetDRMPairingStatus(This,pdwStatus,phError)	\
    ( (This)->lpVtbl -> GetDRMPairingStatus(This,pdwStatus,phError) ) 

#define IBDA_DRM_PerformDRMPairing(This,fSync)	\
    ( (This)->lpVtbl -> PerformDRMPairing(This,fSync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBDA_DRM_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_bdaiface_0000_0027 */
/* [local] */ 

#define SID_BDA_DRM __uuidof(IBDA_DRM)


extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_bdaiface_0000_0027_v0_0_s_ifspec;

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



