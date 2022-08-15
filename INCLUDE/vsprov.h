

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for vsprov.idl:
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

#ifndef __vsprov_h__
#define __vsprov_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVssSoftwareSnapshotProvider_FWD_DEFINED__
#define __IVssSoftwareSnapshotProvider_FWD_DEFINED__
typedef interface IVssSoftwareSnapshotProvider IVssSoftwareSnapshotProvider;
#endif 	/* __IVssSoftwareSnapshotProvider_FWD_DEFINED__ */


#ifndef __IVssProviderCreateSnapshotSet_FWD_DEFINED__
#define __IVssProviderCreateSnapshotSet_FWD_DEFINED__
typedef interface IVssProviderCreateSnapshotSet IVssProviderCreateSnapshotSet;
#endif 	/* __IVssProviderCreateSnapshotSet_FWD_DEFINED__ */


#ifndef __IVssProviderNotifications_FWD_DEFINED__
#define __IVssProviderNotifications_FWD_DEFINED__
typedef interface IVssProviderNotifications IVssProviderNotifications;
#endif 	/* __IVssProviderNotifications_FWD_DEFINED__ */


#ifndef __IVssHardwareSnapshotProvider_FWD_DEFINED__
#define __IVssHardwareSnapshotProvider_FWD_DEFINED__
typedef interface IVssHardwareSnapshotProvider IVssHardwareSnapshotProvider;
#endif 	/* __IVssHardwareSnapshotProvider_FWD_DEFINED__ */


#ifndef __IVssHardwareSnapshotProviderEx_FWD_DEFINED__
#define __IVssHardwareSnapshotProviderEx_FWD_DEFINED__
typedef interface IVssHardwareSnapshotProviderEx IVssHardwareSnapshotProviderEx;
#endif 	/* __IVssHardwareSnapshotProviderEx_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vss.h"
#include "vdslun.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vsprov_0000_0000 */
/* [local] */ 



typedef VSS_PWSZ *PVSS_PWSZ;



extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsprov_0000_0000_v0_0_s_ifspec;

#ifndef __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__
#define __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__

/* interface IVssSoftwareSnapshotProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssSoftwareSnapshotProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("609e123e-2c5a-44d3-8f01-0b1d9a47d1ff")
    IVssSoftwareSnapshotProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetContext( 
            /* [in] */ LONG lContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSnapshotProperties( 
            /* [in] */ VSS_ID SnapshotId,
            /* [out] */ __RPC__out VSS_SNAPSHOT_PROP *pProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Query( 
            /* [in] */ VSS_ID QueriedObjectId,
            /* [in] */ VSS_OBJECT_TYPE eQueriedObjectType,
            /* [in] */ VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [out] */ __RPC__deref_out_opt IVssEnumObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteSnapshots( 
            /* [in] */ VSS_ID SourceObjectId,
            /* [in] */ VSS_OBJECT_TYPE eSourceObjectType,
            /* [in] */ BOOL bForceDelete,
            /* [out] */ __RPC__out LONG *plDeletedSnapshots,
            /* [out] */ __RPC__out VSS_ID *pNondeletedSnapshotID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginPrepareSnapshot( 
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [in] */ LONG lNewContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsVolumeSupported( 
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [out] */ __RPC__out BOOL *pbSupportedByThisProvider) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsVolumeSnapshotted( 
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [out] */ __RPC__out BOOL *pbSnapshotsPresent,
            /* [out] */ __RPC__out LONG *plSnapshotCompatibility) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSnapshotProperty( 
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [in] */ VARIANT vProperty) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RevertToSnapshot( 
            /* [in] */ VSS_ID SnapshotId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryRevertStatus( 
            /* [in] */ __RPC__in VSS_PWSZ pwszVolume,
            /* [out] */ __RPC__deref_out_opt IVssAsync **ppAsync) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVssSoftwareSnapshotProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVssSoftwareSnapshotProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVssSoftwareSnapshotProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetContext )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ LONG lContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSnapshotProperties )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID SnapshotId,
            /* [out] */ __RPC__out VSS_SNAPSHOT_PROP *pProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Query )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID QueriedObjectId,
            /* [in] */ VSS_OBJECT_TYPE eQueriedObjectType,
            /* [in] */ VSS_OBJECT_TYPE eReturnedObjectsType,
            /* [out] */ __RPC__deref_out_opt IVssEnumObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DeleteSnapshots )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID SourceObjectId,
            /* [in] */ VSS_OBJECT_TYPE eSourceObjectType,
            /* [in] */ BOOL bForceDelete,
            /* [out] */ __RPC__out LONG *plDeletedSnapshots,
            /* [out] */ __RPC__out VSS_ID *pNondeletedSnapshotID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [in] */ LONG lNewContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsVolumeSupported )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [out] */ __RPC__out BOOL *pbSupportedByThisProvider);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsVolumeSnapshotted )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ __RPC__in VSS_PWSZ pwszVolumeName,
            /* [out] */ __RPC__out BOOL *pbSnapshotsPresent,
            /* [out] */ __RPC__out LONG *plSnapshotCompatibility);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSnapshotProperty )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ VSS_SNAPSHOT_PROPERTY_ID eSnapshotPropertyId,
            /* [in] */ VARIANT vProperty);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RevertToSnapshot )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ VSS_ID SnapshotId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryRevertStatus )( 
            IVssSoftwareSnapshotProvider * This,
            /* [in] */ __RPC__in VSS_PWSZ pwszVolume,
            /* [out] */ __RPC__deref_out_opt IVssAsync **ppAsync);
        
        END_INTERFACE
    } IVssSoftwareSnapshotProviderVtbl;

    interface IVssSoftwareSnapshotProvider
    {
        CONST_VTBL struct IVssSoftwareSnapshotProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssSoftwareSnapshotProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssSoftwareSnapshotProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssSoftwareSnapshotProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssSoftwareSnapshotProvider_SetContext(This,lContext)	\
    ( (This)->lpVtbl -> SetContext(This,lContext) ) 

#define IVssSoftwareSnapshotProvider_GetSnapshotProperties(This,SnapshotId,pProp)	\
    ( (This)->lpVtbl -> GetSnapshotProperties(This,SnapshotId,pProp) ) 

#define IVssSoftwareSnapshotProvider_Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum)	\
    ( (This)->lpVtbl -> Query(This,QueriedObjectId,eQueriedObjectType,eReturnedObjectsType,ppEnum) ) 

#define IVssSoftwareSnapshotProvider_DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID)	\
    ( (This)->lpVtbl -> DeleteSnapshots(This,SourceObjectId,eSourceObjectType,bForceDelete,plDeletedSnapshots,pNondeletedSnapshotID) ) 

#define IVssSoftwareSnapshotProvider_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszVolumeName,lNewContext)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,pwszVolumeName,lNewContext) ) 

#define IVssSoftwareSnapshotProvider_IsVolumeSupported(This,pwszVolumeName,pbSupportedByThisProvider)	\
    ( (This)->lpVtbl -> IsVolumeSupported(This,pwszVolumeName,pbSupportedByThisProvider) ) 

#define IVssSoftwareSnapshotProvider_IsVolumeSnapshotted(This,pwszVolumeName,pbSnapshotsPresent,plSnapshotCompatibility)	\
    ( (This)->lpVtbl -> IsVolumeSnapshotted(This,pwszVolumeName,pbSnapshotsPresent,plSnapshotCompatibility) ) 

#define IVssSoftwareSnapshotProvider_SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty)	\
    ( (This)->lpVtbl -> SetSnapshotProperty(This,SnapshotId,eSnapshotPropertyId,vProperty) ) 

#define IVssSoftwareSnapshotProvider_RevertToSnapshot(This,SnapshotId)	\
    ( (This)->lpVtbl -> RevertToSnapshot(This,SnapshotId) ) 

#define IVssSoftwareSnapshotProvider_QueryRevertStatus(This,pwszVolume,ppAsync)	\
    ( (This)->lpVtbl -> QueryRevertStatus(This,pwszVolume,ppAsync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssSoftwareSnapshotProvider_INTERFACE_DEFINED__ */


#ifndef __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__
#define __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__

/* interface IVssProviderCreateSnapshotSet */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssProviderCreateSnapshotSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F894E5B-1E39-4778-8E23-9ABAD9F0E08C")
    IVssProviderCreateSnapshotSet : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EndPrepareSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PreCommitSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommitSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PostCommitSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ LONG lSnapshotsCount) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PreFinalCommitSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PostFinalCommitSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortSnapshots( 
            /* [in] */ VSS_ID SnapshotSetId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVssProviderCreateSnapshotSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVssProviderCreateSnapshotSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVssProviderCreateSnapshotSet * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EndPrepareSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreCommitSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CommitSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PostCommitSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ LONG lSnapshotsCount);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PreFinalCommitSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PostFinalCommitSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AbortSnapshots )( 
            IVssProviderCreateSnapshotSet * This,
            /* [in] */ VSS_ID SnapshotSetId);
        
        END_INTERFACE
    } IVssProviderCreateSnapshotSetVtbl;

    interface IVssProviderCreateSnapshotSet
    {
        CONST_VTBL struct IVssProviderCreateSnapshotSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssProviderCreateSnapshotSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssProviderCreateSnapshotSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssProviderCreateSnapshotSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssProviderCreateSnapshotSet_EndPrepareSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> EndPrepareSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PreCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PreCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_CommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> CommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PostCommitSnapshots(This,SnapshotSetId,lSnapshotsCount)	\
    ( (This)->lpVtbl -> PostCommitSnapshots(This,SnapshotSetId,lSnapshotsCount) ) 

#define IVssProviderCreateSnapshotSet_PreFinalCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PreFinalCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_PostFinalCommitSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> PostFinalCommitSnapshots(This,SnapshotSetId) ) 

#define IVssProviderCreateSnapshotSet_AbortSnapshots(This,SnapshotSetId)	\
    ( (This)->lpVtbl -> AbortSnapshots(This,SnapshotSetId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssProviderCreateSnapshotSet_INTERFACE_DEFINED__ */


#ifndef __IVssProviderNotifications_INTERFACE_DEFINED__
#define __IVssProviderNotifications_INTERFACE_DEFINED__

/* interface IVssProviderNotifications */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssProviderNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E561901F-03A5-4afe-86D0-72BAEECE7004")
    IVssProviderNotifications : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLoad( 
            /* [unique][in] */ __RPC__in_opt IUnknown *pCallback) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUnload( 
            /* [in] */ BOOL bForceUnload) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVssProviderNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVssProviderNotifications * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVssProviderNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVssProviderNotifications * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            IVssProviderNotifications * This,
            /* [unique][in] */ __RPC__in_opt IUnknown *pCallback);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            IVssProviderNotifications * This,
            /* [in] */ BOOL bForceUnload);
        
        END_INTERFACE
    } IVssProviderNotificationsVtbl;

    interface IVssProviderNotifications
    {
        CONST_VTBL struct IVssProviderNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssProviderNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssProviderNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssProviderNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssProviderNotifications_OnLoad(This,pCallback)	\
    ( (This)->lpVtbl -> OnLoad(This,pCallback) ) 

#define IVssProviderNotifications_OnUnload(This,bForceUnload)	\
    ( (This)->lpVtbl -> OnUnload(This,bForceUnload) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssProviderNotifications_INTERFACE_DEFINED__ */


#ifndef __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__
#define __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__

/* interface IVssHardwareSnapshotProvider */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssHardwareSnapshotProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9593A157-44E9-4344-BBEB-44FBF9B06B10")
    IVssHardwareSnapshotProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AreLunsSupported( 
            /* [in] */ LONG lLunCount,
            /* [in] */ LONG lContext,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgwszDevices,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *pLunInformation,
            /* [out] */ __RPC__out BOOL *pbIsSupported) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FillInLunInfo( 
            /* [in] */ __RPC__in VSS_PWSZ wszDeviceName,
            /* [out][in] */ __RPC__inout VDS_LUN_INFORMATION *pLunInfo,
            /* [out] */ __RPC__out BOOL *pbIsSupported) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BeginPrepareSnapshot( 
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ LONG lContext,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgLunInformation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTargetLuns( 
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgDestinationLuns) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LocateLuns( 
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLunEmpty( 
            /* [unique][in] */ __RPC__in_opt VSS_PWSZ wszDeviceName,
            /* [unique][in] */ __RPC__in_opt VDS_LUN_INFORMATION *pInformation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVssHardwareSnapshotProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVssHardwareSnapshotProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVssHardwareSnapshotProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AreLunsSupported )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ LONG lLunCount,
            /* [in] */ LONG lContext,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgwszDevices,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *pLunInformation,
            /* [out] */ __RPC__out BOOL *pbIsSupported);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FillInLunInfo )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ __RPC__in VSS_PWSZ wszDeviceName,
            /* [out][in] */ __RPC__inout VDS_LUN_INFORMATION *pLunInfo,
            /* [out] */ __RPC__out BOOL *pbIsSupported);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ LONG lContext,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgLunInformation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTargetLuns )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgDestinationLuns);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LocateLuns )( 
            IVssHardwareSnapshotProvider * This,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunEmpty )( 
            IVssHardwareSnapshotProvider * This,
            /* [unique][in] */ __RPC__in_opt VSS_PWSZ wszDeviceName,
            /* [unique][in] */ __RPC__in_opt VDS_LUN_INFORMATION *pInformation);
        
        END_INTERFACE
    } IVssHardwareSnapshotProviderVtbl;

    interface IVssHardwareSnapshotProvider
    {
        CONST_VTBL struct IVssHardwareSnapshotProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssHardwareSnapshotProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssHardwareSnapshotProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssHardwareSnapshotProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssHardwareSnapshotProvider_AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported)	\
    ( (This)->lpVtbl -> AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported) ) 

#define IVssHardwareSnapshotProvider_FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported)	\
    ( (This)->lpVtbl -> FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported) ) 

#define IVssHardwareSnapshotProvider_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation) ) 

#define IVssHardwareSnapshotProvider_GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns)	\
    ( (This)->lpVtbl -> GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns) ) 

#define IVssHardwareSnapshotProvider_LocateLuns(This,lLunCount,rgSourceLuns)	\
    ( (This)->lpVtbl -> LocateLuns(This,lLunCount,rgSourceLuns) ) 

#define IVssHardwareSnapshotProvider_OnLunEmpty(This,wszDeviceName,pInformation)	\
    ( (This)->lpVtbl -> OnLunEmpty(This,wszDeviceName,pInformation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssHardwareSnapshotProvider_INTERFACE_DEFINED__ */


#ifndef __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__
#define __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__

/* interface IVssHardwareSnapshotProviderEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVssHardwareSnapshotProviderEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F5BA925-CDB1-4d11-A71F-339EB7E709FD")
    IVssHardwareSnapshotProviderEx : public IVssHardwareSnapshotProvider
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProviderCapabilities( 
            /* [out] */ __RPC__out ULONGLONG *pllOriginalCapabilityMask) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLunStateChange( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pOriginalLuns,
            /* [in] */ DWORD dwCount,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResyncLuns( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSourceLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pTargetLuns,
            /* [in] */ DWORD dwCount,
            /* [out] */ __RPC__deref_out_opt IVssAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnReuseLuns( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pOriginalLuns,
            /* [in] */ DWORD dwCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVssHardwareSnapshotProviderExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVssHardwareSnapshotProviderEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVssHardwareSnapshotProviderEx * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AreLunsSupported )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ LONG lLunCount,
            /* [in] */ LONG lContext,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgwszDevices,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *pLunInformation,
            /* [out] */ __RPC__out BOOL *pbIsSupported);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FillInLunInfo )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ __RPC__in VSS_PWSZ wszDeviceName,
            /* [out][in] */ __RPC__inout VDS_LUN_INFORMATION *pLunInfo,
            /* [out] */ __RPC__out BOOL *pbIsSupported);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BeginPrepareSnapshot )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ VSS_ID SnapshotSetId,
            /* [in] */ VSS_ID SnapshotId,
            /* [in] */ LONG lContext,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgLunInformation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTargetLuns )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VSS_PWSZ *rgDeviceNames,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns,
            /* [size_is][out][in] */ __RPC__inout_ecount_full(lLunCount) VDS_LUN_INFORMATION *rgDestinationLuns);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *LocateLuns )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [in] */ LONG lLunCount,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lLunCount) VDS_LUN_INFORMATION *rgSourceLuns);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunEmpty )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [unique][in] */ __RPC__in_opt VSS_PWSZ wszDeviceName,
            /* [unique][in] */ __RPC__in_opt VDS_LUN_INFORMATION *pInformation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProviderCapabilities )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [out] */ __RPC__out ULONGLONG *pllOriginalCapabilityMask);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLunStateChange )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pOriginalLuns,
            /* [in] */ DWORD dwCount,
            /* [in] */ DWORD dwFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResyncLuns )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSourceLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pTargetLuns,
            /* [in] */ DWORD dwCount,
            /* [out] */ __RPC__deref_out_opt IVssAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnReuseLuns )( 
            IVssHardwareSnapshotProviderEx * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pSnapshotLuns,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(dwCount) VDS_LUN_INFORMATION *pOriginalLuns,
            /* [in] */ DWORD dwCount);
        
        END_INTERFACE
    } IVssHardwareSnapshotProviderExVtbl;

    interface IVssHardwareSnapshotProviderEx
    {
        CONST_VTBL struct IVssHardwareSnapshotProviderExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVssHardwareSnapshotProviderEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVssHardwareSnapshotProviderEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVssHardwareSnapshotProviderEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVssHardwareSnapshotProviderEx_AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported)	\
    ( (This)->lpVtbl -> AreLunsSupported(This,lLunCount,lContext,rgwszDevices,pLunInformation,pbIsSupported) ) 

#define IVssHardwareSnapshotProviderEx_FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported)	\
    ( (This)->lpVtbl -> FillInLunInfo(This,wszDeviceName,pLunInfo,pbIsSupported) ) 

#define IVssHardwareSnapshotProviderEx_BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation)	\
    ( (This)->lpVtbl -> BeginPrepareSnapshot(This,SnapshotSetId,SnapshotId,lContext,lLunCount,rgDeviceNames,rgLunInformation) ) 

#define IVssHardwareSnapshotProviderEx_GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns)	\
    ( (This)->lpVtbl -> GetTargetLuns(This,lLunCount,rgDeviceNames,rgSourceLuns,rgDestinationLuns) ) 

#define IVssHardwareSnapshotProviderEx_LocateLuns(This,lLunCount,rgSourceLuns)	\
    ( (This)->lpVtbl -> LocateLuns(This,lLunCount,rgSourceLuns) ) 

#define IVssHardwareSnapshotProviderEx_OnLunEmpty(This,wszDeviceName,pInformation)	\
    ( (This)->lpVtbl -> OnLunEmpty(This,wszDeviceName,pInformation) ) 


#define IVssHardwareSnapshotProviderEx_GetProviderCapabilities(This,pllOriginalCapabilityMask)	\
    ( (This)->lpVtbl -> GetProviderCapabilities(This,pllOriginalCapabilityMask) ) 

#define IVssHardwareSnapshotProviderEx_OnLunStateChange(This,pSnapshotLuns,pOriginalLuns,dwCount,dwFlags)	\
    ( (This)->lpVtbl -> OnLunStateChange(This,pSnapshotLuns,pOriginalLuns,dwCount,dwFlags) ) 

#define IVssHardwareSnapshotProviderEx_ResyncLuns(This,pSourceLuns,pTargetLuns,dwCount,ppAsync)	\
    ( (This)->lpVtbl -> ResyncLuns(This,pSourceLuns,pTargetLuns,dwCount,ppAsync) ) 

#define IVssHardwareSnapshotProviderEx_OnReuseLuns(This,pSnapshotLuns,pOriginalLuns,dwCount)	\
    ( (This)->lpVtbl -> OnReuseLuns(This,pSnapshotLuns,pOriginalLuns,dwCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVssHardwareSnapshotProviderEx_INTERFACE_DEFINED__ */



#ifndef __VSSProvider_LIBRARY_DEFINED__
#define __VSSProvider_LIBRARY_DEFINED__

/* library VSSProvider */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_VSSProvider;
#endif /* __VSSProvider_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



