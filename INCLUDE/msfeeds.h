

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for msfeeds.idl:
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
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __msfeeds_h__
#define __msfeeds_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IXFeedsManager_FWD_DEFINED__
#define __IXFeedsManager_FWD_DEFINED__
typedef interface IXFeedsManager IXFeedsManager;
#endif 	/* __IXFeedsManager_FWD_DEFINED__ */


#ifndef __IXFeedsEnum_FWD_DEFINED__
#define __IXFeedsEnum_FWD_DEFINED__
typedef interface IXFeedsEnum IXFeedsEnum;
#endif 	/* __IXFeedsEnum_FWD_DEFINED__ */


#ifndef __IXFeedFolder_FWD_DEFINED__
#define __IXFeedFolder_FWD_DEFINED__
typedef interface IXFeedFolder IXFeedFolder;
#endif 	/* __IXFeedFolder_FWD_DEFINED__ */


#ifndef __IXFeedFolderEvents_FWD_DEFINED__
#define __IXFeedFolderEvents_FWD_DEFINED__
typedef interface IXFeedFolderEvents IXFeedFolderEvents;
#endif 	/* __IXFeedFolderEvents_FWD_DEFINED__ */


#ifndef __IXFeed_FWD_DEFINED__
#define __IXFeed_FWD_DEFINED__
typedef interface IXFeed IXFeed;
#endif 	/* __IXFeed_FWD_DEFINED__ */


#ifndef __IXFeedEvents_FWD_DEFINED__
#define __IXFeedEvents_FWD_DEFINED__
typedef interface IXFeedEvents IXFeedEvents;
#endif 	/* __IXFeedEvents_FWD_DEFINED__ */


#ifndef __IXFeedItem_FWD_DEFINED__
#define __IXFeedItem_FWD_DEFINED__
typedef interface IXFeedItem IXFeedItem;
#endif 	/* __IXFeedItem_FWD_DEFINED__ */


#ifndef __IXFeedEnclosure_FWD_DEFINED__
#define __IXFeedEnclosure_FWD_DEFINED__
typedef interface IXFeedEnclosure IXFeedEnclosure;
#endif 	/* __IXFeedEnclosure_FWD_DEFINED__ */


#ifndef __IFeedsManager_FWD_DEFINED__
#define __IFeedsManager_FWD_DEFINED__
typedef interface IFeedsManager IFeedsManager;
#endif 	/* __IFeedsManager_FWD_DEFINED__ */


#ifndef __IFeedsEnum_FWD_DEFINED__
#define __IFeedsEnum_FWD_DEFINED__
typedef interface IFeedsEnum IFeedsEnum;
#endif 	/* __IFeedsEnum_FWD_DEFINED__ */


#ifndef __IFeedFolder_FWD_DEFINED__
#define __IFeedFolder_FWD_DEFINED__
typedef interface IFeedFolder IFeedFolder;
#endif 	/* __IFeedFolder_FWD_DEFINED__ */


#ifndef __IFeedFolderEvents_FWD_DEFINED__
#define __IFeedFolderEvents_FWD_DEFINED__
typedef interface IFeedFolderEvents IFeedFolderEvents;
#endif 	/* __IFeedFolderEvents_FWD_DEFINED__ */


#ifndef __IFeed_FWD_DEFINED__
#define __IFeed_FWD_DEFINED__
typedef interface IFeed IFeed;
#endif 	/* __IFeed_FWD_DEFINED__ */


#ifndef __IFeedEvents_FWD_DEFINED__
#define __IFeedEvents_FWD_DEFINED__
typedef interface IFeedEvents IFeedEvents;
#endif 	/* __IFeedEvents_FWD_DEFINED__ */


#ifndef __IFeedItem_FWD_DEFINED__
#define __IFeedItem_FWD_DEFINED__
typedef interface IFeedItem IFeedItem;
#endif 	/* __IFeedItem_FWD_DEFINED__ */


#ifndef __IFeedEnclosure_FWD_DEFINED__
#define __IFeedEnclosure_FWD_DEFINED__
typedef interface IFeedEnclosure IFeedEnclosure;
#endif 	/* __IFeedEnclosure_FWD_DEFINED__ */


#ifndef __FeedsManager_FWD_DEFINED__
#define __FeedsManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedsManager FeedsManager;
#else
typedef struct FeedsManager FeedsManager;
#endif /* __cplusplus */

#endif 	/* __FeedsManager_FWD_DEFINED__ */


#ifndef __FeedFolderWatcher_FWD_DEFINED__
#define __FeedFolderWatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedFolderWatcher FeedFolderWatcher;
#else
typedef struct FeedFolderWatcher FeedFolderWatcher;
#endif /* __cplusplus */

#endif 	/* __FeedFolderWatcher_FWD_DEFINED__ */


#ifndef __FeedWatcher_FWD_DEFINED__
#define __FeedWatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class FeedWatcher FeedWatcher;
#else
typedef struct FeedWatcher FeedWatcher;
#endif /* __cplusplus */

#endif 	/* __FeedWatcher_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_msfeeds_0000_0000 */
/* [local] */ 

// {FE6B11C3-C72E-4061-86C6-9D163121F229}
DEFINE_GUID(CLSID_XFeedsManager, 0xfe6b11c3, 0xc72e, 0x4061, 0x86, 0xc6, 0x9d, 0x16, 0x31, 0x21, 0xf2, 0x29);
typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0001
    {	FBSA_DISABLE	= 0,
	FBSA_ENABLE	= 1,
	FBSA_RUNNOW	= 2
    } 	FEEDS_BACKGROUNDSYNC_ACTION;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0002
    {	FBSS_DISABLED	= 0,
	FBSS_ENABLED	= 1
    } 	FEEDS_BACKGROUNDSYNC_STATUS;

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0003
    {	FES_ALL	= 0,
	FES_SELF_ONLY	= 1,
	FES_SELF_AND_CHILDREN_ONLY	= 2
    } 	FEEDS_EVENTS_SCOPE;

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0004
    {	FEM_FOLDEREVENTS	= 0x1,
	FEM_FEEDEVENTS	= 0x2
    } 	FEEDS_EVENTS_MASK;


#define FEEDS_XML_COUNT_MAX ((UINT)-1)

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0005
    {	FXSP_NONE	= 0,
	FXSP_PUBDATE	= 1,
	FXSP_DOWNLOADTIME	= 2
    } 	FEEDS_XML_SORT_PROPERTY;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0006
    {	FXSO_NONE	= 0,
	FXSO_ASCENDING	= 1,
	FXSO_DESCENDING	= 2
    } 	FEEDS_XML_SORT_ORDER;

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0007
    {	FXFF_ALL	= 0,
	FXFF_UNREAD	= 0x1,
	FXFF_READ	= 0x2
    } 	FEEDS_XML_FILTER_FLAGS;

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0008
    {	FXIF_NONE	= 0,
	FXIF_CF_EXTENSIONS	= 0x1
    } 	FEEDS_XML_INCLUDE_FLAGS;

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0009
    {	FDS_NONE	= 0,
	FDS_PENDING	= 1,
	FDS_DOWNLOADING	= 2,
	FDS_DOWNLOADED	= 3,
	FDS_DOWNLOAD_FAILED	= 4
    } 	FEEDS_DOWNLOAD_STATUS;

typedef /* [public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0010
    {	FSS_DEFAULT	= 0,
	FSS_INTERVAL	= 1,
	FSS_MANUAL	= 2
    } 	FEEDS_SYNC_SETTING;

typedef /* [public][public][public][public][public][public][public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0011
    {	FDE_NONE	= 0,
	FDE_DOWNLOAD_FAILED	= 1,
	FDE_INVALID_FEED_FORMAT	= 2,
	FDE_NORMALIZATION_FAILED	= 3,
	FDE_PERSISTENCE_FAILED	= 4,
	FDE_DOWNLOAD_BLOCKED	= 5,
	FDE_CANCELED	= 6,
	FDE_UNSUPPORTED_AUTH	= 7,
	FDE_BACKGROUND_DOWNLOAD_DISABLED	= 8,
	FDE_NOT_EXIST	= 9,
	FDE_UNSUPPORTED_MSXML	= 10,
	FDE_UNSUPPORTED_DTD	= 11,
	FDE_DOWNLOAD_SIZE_LIMIT_EXCEEDED	= 12
    } 	FEEDS_DOWNLOAD_ERROR;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0012
    {	FEICF_READ_ITEM_COUNT_CHANGED	= 0x1,
	FEICF_UNREAD_ITEM_COUNT_CHANGED	= 0x2
    } 	FEEDS_EVENTS_ITEM_COUNT_FLAGS;

typedef int FEICF;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_msfeeds_0000_0000_0013
    {	FEC_E_ERRORBASE	= 0xc0040200L,
	FEC_E_INVALIDMSXMLPROPERTY	= FEC_E_ERRORBASE,
	FEC_E_DOWNLOADSIZELIMITEXCEEDED	= ( FEC_E_INVALIDMSXMLPROPERTY + 1 ) 
    } 	FEEDS_ERROR_CODE;



extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_msfeeds_0000_0000_v0_0_s_ifspec;

#ifndef __IXFeedsManager_INTERFACE_DEFINED__
#define __IXFeedsManager_INTERFACE_DEFINED__

/* interface IXFeedsManager */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedsManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5357e238-fb12-4aca-a930-cab7832b84bf")
    IXFeedsManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RootFolder( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSubscribed( 
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [out] */ __RPC__out BOOL *pbSubscribed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbFeedExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeedByUrl( 
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFolder( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbFolderExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFolder( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFeed( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteFolder( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSync( 
            /* [in] */ FEEDS_BACKGROUNDSYNC_ACTION fbsa) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSyncStatus( 
            /* [out] */ __RPC__out FEEDS_BACKGROUNDSYNC_STATUS *pfbss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DefaultInterval( 
            /* [out] */ __RPC__out UINT *puiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultInterval( 
            /* [in] */ UINT uiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncSyncAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Normalize( 
            /* [in] */ __RPC__in_opt IStream *pStreamIn,
            /* [out] */ __RPC__deref_out_opt IStream **ppStreamOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemCountLimit( 
            /* [out] */ __RPC__out UINT *puiItemCountLimit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedsManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedsManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *RootFolder )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsSubscribed )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [out] */ __RPC__out BOOL *pbSubscribed);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbFeedExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeedByUrl )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFolder )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbFolderExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFolder )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFeed )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteFolder )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSync )( 
            IXFeedsManager * This,
            /* [in] */ FEEDS_BACKGROUNDSYNC_ACTION fbsa);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSyncStatus )( 
            IXFeedsManager * This,
            /* [out] */ __RPC__out FEEDS_BACKGROUNDSYNC_STATUS *pfbss);
        
        HRESULT ( STDMETHODCALLTYPE *DefaultInterval )( 
            IXFeedsManager * This,
            /* [out] */ __RPC__out UINT *puiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultInterval )( 
            IXFeedsManager * This,
            /* [in] */ UINT uiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncSyncAll )( 
            IXFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            IXFeedsManager * This,
            /* [in] */ __RPC__in_opt IStream *pStreamIn,
            /* [out] */ __RPC__deref_out_opt IStream **ppStreamOut);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCountLimit )( 
            IXFeedsManager * This,
            /* [out] */ __RPC__out UINT *puiItemCountLimit);
        
        END_INTERFACE
    } IXFeedsManagerVtbl;

    interface IXFeedsManager
    {
        CONST_VTBL struct IXFeedsManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedsManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedsManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedsManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedsManager_RootFolder(This,riid,ppv)	\
    ( (This)->lpVtbl -> RootFolder(This,riid,ppv) ) 

#define IXFeedsManager_IsSubscribed(This,pszUrl,pbSubscribed)	\
    ( (This)->lpVtbl -> IsSubscribed(This,pszUrl,pbSubscribed) ) 

#define IXFeedsManager_ExistsFeed(This,pszPath,pbFeedExists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,pszPath,pbFeedExists) ) 

#define IXFeedsManager_GetFeed(This,pszPath,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeed(This,pszPath,riid,ppv) ) 

#define IXFeedsManager_GetFeedByUrl(This,pszUrl,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeedByUrl(This,pszUrl,riid,ppv) ) 

#define IXFeedsManager_ExistsFolder(This,pszPath,pbFolderExists)	\
    ( (This)->lpVtbl -> ExistsFolder(This,pszPath,pbFolderExists) ) 

#define IXFeedsManager_GetFolder(This,pszPath,riid,ppv)	\
    ( (This)->lpVtbl -> GetFolder(This,pszPath,riid,ppv) ) 

#define IXFeedsManager_DeleteFeed(This,pszPath)	\
    ( (This)->lpVtbl -> DeleteFeed(This,pszPath) ) 

#define IXFeedsManager_DeleteFolder(This,pszPath)	\
    ( (This)->lpVtbl -> DeleteFolder(This,pszPath) ) 

#define IXFeedsManager_BackgroundSync(This,fbsa)	\
    ( (This)->lpVtbl -> BackgroundSync(This,fbsa) ) 

#define IXFeedsManager_BackgroundSyncStatus(This,pfbss)	\
    ( (This)->lpVtbl -> BackgroundSyncStatus(This,pfbss) ) 

#define IXFeedsManager_DefaultInterval(This,puiInterval)	\
    ( (This)->lpVtbl -> DefaultInterval(This,puiInterval) ) 

#define IXFeedsManager_SetDefaultInterval(This,uiInterval)	\
    ( (This)->lpVtbl -> SetDefaultInterval(This,uiInterval) ) 

#define IXFeedsManager_AsyncSyncAll(This)	\
    ( (This)->lpVtbl -> AsyncSyncAll(This) ) 

#define IXFeedsManager_Normalize(This,pStreamIn,ppStreamOut)	\
    ( (This)->lpVtbl -> Normalize(This,pStreamIn,ppStreamOut) ) 

#define IXFeedsManager_ItemCountLimit(This,puiItemCountLimit)	\
    ( (This)->lpVtbl -> ItemCountLimit(This,puiItemCountLimit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedsManager_INTERFACE_DEFINED__ */


#ifndef __IXFeedsEnum_INTERFACE_DEFINED__
#define __IXFeedsEnum_INTERFACE_DEFINED__

/* interface IXFeedsEnum */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedsEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("dc43a9d5-5015-4301-8c96-a47434b4d658")
    IXFeedsEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Count( 
            /* [out] */ __RPC__out UINT *puiCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ UINT uiIndex,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedsEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedsEnum * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedsEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedsEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *Count )( 
            IXFeedsEnum * This,
            /* [out] */ __RPC__out UINT *puiCount);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IXFeedsEnum * This,
            /* [in] */ UINT uiIndex,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        END_INTERFACE
    } IXFeedsEnumVtbl;

    interface IXFeedsEnum
    {
        CONST_VTBL struct IXFeedsEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedsEnum_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedsEnum_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedsEnum_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedsEnum_Count(This,puiCount)	\
    ( (This)->lpVtbl -> Count(This,puiCount) ) 

#define IXFeedsEnum_Item(This,uiIndex,riid,ppv)	\
    ( (This)->lpVtbl -> Item(This,uiIndex,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedsEnum_INTERFACE_DEFINED__ */


#ifndef __IXFeedFolder_INTERFACE_DEFINED__
#define __IXFeedFolder_INTERFACE_DEFINED__

/* interface IXFeedFolder */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4c963678-3a51-4b88-8531-98b90b6508f2")
    IXFeedFolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Feeds( 
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Subfolders( 
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateFeed( 
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSubfolder( 
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsFeed( 
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbFeedExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExistsSubfolder( 
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbSubfolderExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubfolder( 
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Name( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ __RPC__in LPCWSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Path( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRoot( 
            /* [out] */ __RPC__out BOOL *pbIsRootFeedFolder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TotalUnreadItemCount( 
            /* [out] */ __RPC__out UINT *puiTotalUnreadItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TotalItemCount( 
            /* [out] */ __RPC__out UINT *puiTotalItemCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Feeds )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *Subfolders )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *CreateFeed )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSubfolder )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            IXFeedFolder * This,
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbFeedExists);
        
        HRESULT ( STDMETHODCALLTYPE *ExistsSubfolder )( 
            IXFeedFolder * This,
            __RPC__in LPCWSTR pszName,
            __RPC__in BOOL *pbSubfolderExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubfolder )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszName,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IXFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *Name )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *Path )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            IXFeedFolder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsRoot )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__out BOOL *pbIsRootFeedFolder);
        
        HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            IXFeedFolder * This,
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *TotalUnreadItemCount )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__out UINT *puiTotalUnreadItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *TotalItemCount )( 
            IXFeedFolder * This,
            /* [out] */ __RPC__out UINT *puiTotalItemCount);
        
        END_INTERFACE
    } IXFeedFolderVtbl;

    interface IXFeedFolder
    {
        CONST_VTBL struct IXFeedFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedFolder_Feeds(This,ppfe)	\
    ( (This)->lpVtbl -> Feeds(This,ppfe) ) 

#define IXFeedFolder_Subfolders(This,ppfe)	\
    ( (This)->lpVtbl -> Subfolders(This,ppfe) ) 

#define IXFeedFolder_CreateFeed(This,pszName,pszUrl,riid,ppv)	\
    ( (This)->lpVtbl -> CreateFeed(This,pszName,pszUrl,riid,ppv) ) 

#define IXFeedFolder_CreateSubfolder(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> CreateSubfolder(This,pszName,riid,ppv) ) 

#define IXFeedFolder_ExistsFeed(This,pszName,pbFeedExists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,pszName,pbFeedExists) ) 

#define IXFeedFolder_ExistsSubfolder(This,pszName,pbSubfolderExists)	\
    ( (This)->lpVtbl -> ExistsSubfolder(This,pszName,pbSubfolderExists) ) 

#define IXFeedFolder_GetFeed(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> GetFeed(This,pszName,riid,ppv) ) 

#define IXFeedFolder_GetSubfolder(This,pszName,riid,ppv)	\
    ( (This)->lpVtbl -> GetSubfolder(This,pszName,riid,ppv) ) 

#define IXFeedFolder_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeedFolder_Name(This,ppszName)	\
    ( (This)->lpVtbl -> Name(This,ppszName) ) 

#define IXFeedFolder_Rename(This,pszName)	\
    ( (This)->lpVtbl -> Rename(This,pszName) ) 

#define IXFeedFolder_Path(This,ppszPath)	\
    ( (This)->lpVtbl -> Path(This,ppszPath) ) 

#define IXFeedFolder_Move(This,pszPath)	\
    ( (This)->lpVtbl -> Move(This,pszPath) ) 

#define IXFeedFolder_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedFolder_IsRoot(This,pbIsRootFeedFolder)	\
    ( (This)->lpVtbl -> IsRoot(This,pbIsRootFeedFolder) ) 

#define IXFeedFolder_GetWatcher(This,scope,mask,riid,ppv)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,riid,ppv) ) 

#define IXFeedFolder_TotalUnreadItemCount(This,puiTotalUnreadItemCount)	\
    ( (This)->lpVtbl -> TotalUnreadItemCount(This,puiTotalUnreadItemCount) ) 

#define IXFeedFolder_TotalItemCount(This,puiTotalItemCount)	\
    ( (This)->lpVtbl -> TotalItemCount(This,puiTotalItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedFolder_INTERFACE_DEFINED__ */


#ifndef __IXFeedFolderEvents_INTERFACE_DEFINED__
#define __IXFeedFolderEvents_INTERFACE_DEFINED__

/* interface IXFeedFolderEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedFolderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7964b769-234a-4bb1-a5f4-90454c8ad07e")
    IXFeedFolderEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderAdded( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderDeleted( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderRenamed( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderMovedFrom( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderMovedTo( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FolderItemCountChanged( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedAdded( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMovedFrom( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMovedTo( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEEDS_DOWNLOAD_ERROR fde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedFolderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedFolderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Error )( 
            IXFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *FolderAdded )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderDeleted )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderRenamed )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderMovedFrom )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderMovedTo )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FolderItemCountChanged )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FeedAdded )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMovedFrom )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMovedTo )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEEDS_DOWNLOAD_ERROR fde);
        
        HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            IXFeedFolderEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags);
        
        END_INTERFACE
    } IXFeedFolderEventsVtbl;

    interface IXFeedFolderEvents
    {
        CONST_VTBL struct IXFeedFolderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedFolderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedFolderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedFolderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedFolderEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IXFeedFolderEvents_FolderAdded(This,pszPath)	\
    ( (This)->lpVtbl -> FolderAdded(This,pszPath) ) 

#define IXFeedFolderEvents_FolderDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FolderDeleted(This,pszPath) ) 

#define IXFeedFolderEvents_FolderRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderMovedFrom(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderMovedFrom(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderMovedTo(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FolderMovedTo(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FolderItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FolderItemCountChanged(This,pszPath,feicfFlags) ) 

#define IXFeedFolderEvents_FeedAdded(This,pszPath)	\
    ( (This)->lpVtbl -> FeedAdded(This,pszPath) ) 

#define IXFeedFolderEvents_FeedDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDeleted(This,pszPath) ) 

#define IXFeedFolderEvents_FeedRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedUrlChanged(This,pszPath)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,pszPath) ) 

#define IXFeedFolderEvents_FeedMovedFrom(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMovedFrom(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedMovedTo(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMovedTo(This,pszPath,pszOldPath) ) 

#define IXFeedFolderEvents_FeedDownloading(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDownloading(This,pszPath) ) 

#define IXFeedFolderEvents_FeedDownloadCompleted(This,pszPath,fde)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,pszPath,fde) ) 

#define IXFeedFolderEvents_FeedItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,pszPath,feicfFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedFolderEvents_INTERFACE_DEFINED__ */


#ifndef __IXFeed_INTERFACE_DEFINED__
#define __IXFeed_INTERFACE_DEFINED__

/* interface IXFeed */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeed;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a44179a4-e0f6-403b-af8d-d080f425a451")
    IXFeed : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Xml( 
            /* [in] */ UINT uiItemCount,
            /* [in] */ FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [in] */ FEEDS_XML_SORT_ORDER sortOrder,
            /* [in] */ FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [out] */ __RPC__deref_out_opt IStream **pps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Name( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ __RPC__in LPCWSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Url( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUrl( 
            /* [in] */ __RPC__in LPCWSTR pszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalId( 
            /* [out] */ __RPC__out GUID *pguid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Path( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastWriteTime( 
            /* [out] */ __RPC__out SYSTEMTIME *pstLastWriteTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncSetting( 
            /* [out] */ __RPC__out FEEDS_SYNC_SETTING *pfss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSyncSetting( 
            /* [in] */ FEEDS_SYNC_SETTING fss) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Interval( 
            /* [out] */ __RPC__out UINT *puiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInterval( 
            /* [in] */ UINT uiInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadTime( 
            /* [out] */ __RPC__out SYSTEMTIME *pstLastDownloadTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalEnclosurePath( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Items( 
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ UINT uiId,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MarkAllItemsRead( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MaxItemCount( 
            /* [out] */ __RPC__out UINT *puiMaxItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxItemCount( 
            /* [in] */ UINT uiMaxItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadEnclosuresAutomatically( 
            /* [out] */ __RPC__out BOOL *pbDownloadEnclosuresAutomatically) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDownloadEnclosuresAutomatically( 
            /* [in] */ BOOL bDownloadEnclosuresAutomatically) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadStatus( 
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *pfds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadError( 
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *pfde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [in] */ __RPC__in LPCWSTR pszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Title( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Description( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Link( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszHomePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Image( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszImageUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastBuildDate( 
            /* [out] */ __RPC__out SYSTEMTIME *pstLastBuildDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PubDate( 
            /* [out] */ __RPC__out SYSTEMTIME *pstPubDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Ttl( 
            /* [out] */ __RPC__out UINT *puiTtl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Language( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszLanguage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copyright( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszCopyright) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsList( 
            /* [out] */ __RPC__out BOOL *pbIsList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnreadItemCount( 
            /* [out] */ __RPC__out UINT *puiUnreadItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemCount( 
            /* [out] */ __RPC__out UINT *puiItemCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeed * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeed * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            IXFeed * This,
            /* [in] */ UINT uiItemCount,
            /* [in] */ FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [in] */ FEEDS_XML_SORT_ORDER sortOrder,
            /* [in] */ FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [out] */ __RPC__deref_out_opt IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Name )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IXFeed * This,
            /* [in] */ __RPC__in LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *Url )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *SetUrl )( 
            IXFeed * This,
            /* [in] */ __RPC__in LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            IXFeed * This,
            /* [out] */ __RPC__out GUID *pguid);
        
        HRESULT ( STDMETHODCALLTYPE *Path )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            IXFeed * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            IXFeed * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *LastWriteTime )( 
            IXFeed * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstLastWriteTime);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *Download )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *SyncSetting )( 
            IXFeed * This,
            /* [out] */ __RPC__out FEEDS_SYNC_SETTING *pfss);
        
        HRESULT ( STDMETHODCALLTYPE *SetSyncSetting )( 
            IXFeed * This,
            /* [in] */ FEEDS_SYNC_SETTING fss);
        
        HRESULT ( STDMETHODCALLTYPE *Interval )( 
            IXFeed * This,
            /* [out] */ __RPC__out UINT *puiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetInterval )( 
            IXFeed * This,
            /* [in] */ UINT uiInterval);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            IXFeed * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *LocalEnclosurePath )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Items )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt IXFeedsEnum **ppfe);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IXFeed * This,
            /* [in] */ UINT uiId,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            IXFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *MaxItemCount )( 
            IXFeed * This,
            /* [out] */ __RPC__out UINT *puiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxItemCount )( 
            IXFeed * This,
            /* [in] */ UINT uiMaxItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadEnclosuresAutomatically )( 
            IXFeed * This,
            /* [out] */ __RPC__out BOOL *pbDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *SetDownloadEnclosuresAutomatically )( 
            IXFeed * This,
            /* [in] */ BOOL bDownloadEnclosuresAutomatically);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadStatus )( 
            IXFeed * This,
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *pfds);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadError )( 
            IXFeed * This,
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *pfde);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IXFeed * This,
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [in] */ __RPC__in LPCWSTR pszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszHomePage);
        
        HRESULT ( STDMETHODCALLTYPE *Image )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszImageUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastBuildDate )( 
            IXFeed * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstLastBuildDate);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            IXFeed * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Ttl )( 
            IXFeed * This,
            /* [out] */ __RPC__out UINT *puiTtl);
        
        HRESULT ( STDMETHODCALLTYPE *Language )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszLanguage);
        
        HRESULT ( STDMETHODCALLTYPE *Copyright )( 
            IXFeed * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszCopyright);
        
        HRESULT ( STDMETHODCALLTYPE *IsList )( 
            IXFeed * This,
            /* [out] */ __RPC__out BOOL *pbIsList);
        
        HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            IXFeed * This,
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *UnreadItemCount )( 
            IXFeed * This,
            /* [out] */ __RPC__out UINT *puiUnreadItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCount )( 
            IXFeed * This,
            /* [out] */ __RPC__out UINT *puiItemCount);
        
        END_INTERFACE
    } IXFeedVtbl;

    interface IXFeed
    {
        CONST_VTBL struct IXFeedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeed_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeed_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeed_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeed_Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps)	\
    ( (This)->lpVtbl -> Xml(This,uiItemCount,sortProperty,sortOrder,filterFlags,includeFlags,pps) ) 

#define IXFeed_Name(This,ppszName)	\
    ( (This)->lpVtbl -> Name(This,ppszName) ) 

#define IXFeed_Rename(This,pszName)	\
    ( (This)->lpVtbl -> Rename(This,pszName) ) 

#define IXFeed_Url(This,ppszUrl)	\
    ( (This)->lpVtbl -> Url(This,ppszUrl) ) 

#define IXFeed_SetUrl(This,pszUrl)	\
    ( (This)->lpVtbl -> SetUrl(This,pszUrl) ) 

#define IXFeed_LocalId(This,pguid)	\
    ( (This)->lpVtbl -> LocalId(This,pguid) ) 

#define IXFeed_Path(This,ppszPath)	\
    ( (This)->lpVtbl -> Path(This,ppszPath) ) 

#define IXFeed_Move(This,pszPath)	\
    ( (This)->lpVtbl -> Move(This,pszPath) ) 

#define IXFeed_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeed_LastWriteTime(This,pstLastWriteTime)	\
    ( (This)->lpVtbl -> LastWriteTime(This,pstLastWriteTime) ) 

#define IXFeed_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeed_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IXFeed_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IXFeed_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IXFeed_SyncSetting(This,pfss)	\
    ( (This)->lpVtbl -> SyncSetting(This,pfss) ) 

#define IXFeed_SetSyncSetting(This,fss)	\
    ( (This)->lpVtbl -> SetSyncSetting(This,fss) ) 

#define IXFeed_Interval(This,puiInterval)	\
    ( (This)->lpVtbl -> Interval(This,puiInterval) ) 

#define IXFeed_SetInterval(This,uiInterval)	\
    ( (This)->lpVtbl -> SetInterval(This,uiInterval) ) 

#define IXFeed_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeed_LocalEnclosurePath(This,ppszPath)	\
    ( (This)->lpVtbl -> LocalEnclosurePath(This,ppszPath) ) 

#define IXFeed_Items(This,ppfe)	\
    ( (This)->lpVtbl -> Items(This,ppfe) ) 

#define IXFeed_GetItem(This,uiId,riid,ppv)	\
    ( (This)->lpVtbl -> GetItem(This,uiId,riid,ppv) ) 

#define IXFeed_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IXFeed_MaxItemCount(This,puiMaxItemCount)	\
    ( (This)->lpVtbl -> MaxItemCount(This,puiMaxItemCount) ) 

#define IXFeed_SetMaxItemCount(This,uiMaxItemCount)	\
    ( (This)->lpVtbl -> SetMaxItemCount(This,uiMaxItemCount) ) 

#define IXFeed_DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> DownloadEnclosuresAutomatically(This,pbDownloadEnclosuresAutomatically) ) 

#define IXFeed_SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> SetDownloadEnclosuresAutomatically(This,bDownloadEnclosuresAutomatically) ) 

#define IXFeed_DownloadStatus(This,pfds)	\
    ( (This)->lpVtbl -> DownloadStatus(This,pfds) ) 

#define IXFeed_LastDownloadError(This,pfde)	\
    ( (This)->lpVtbl -> LastDownloadError(This,pfde) ) 

#define IXFeed_Merge(This,pStream,pszUrl)	\
    ( (This)->lpVtbl -> Merge(This,pStream,pszUrl) ) 

#define IXFeed_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeed_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeed_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeed_Link(This,ppszHomePage)	\
    ( (This)->lpVtbl -> Link(This,ppszHomePage) ) 

#define IXFeed_Image(This,ppszImageUrl)	\
    ( (This)->lpVtbl -> Image(This,ppszImageUrl) ) 

#define IXFeed_LastBuildDate(This,pstLastBuildDate)	\
    ( (This)->lpVtbl -> LastBuildDate(This,pstLastBuildDate) ) 

#define IXFeed_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeed_Ttl(This,puiTtl)	\
    ( (This)->lpVtbl -> Ttl(This,puiTtl) ) 

#define IXFeed_Language(This,ppszLanguage)	\
    ( (This)->lpVtbl -> Language(This,ppszLanguage) ) 

#define IXFeed_Copyright(This,ppszCopyright)	\
    ( (This)->lpVtbl -> Copyright(This,ppszCopyright) ) 

#define IXFeed_IsList(This,pbIsList)	\
    ( (This)->lpVtbl -> IsList(This,pbIsList) ) 

#define IXFeed_GetWatcher(This,scope,mask,riid,ppv)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,riid,ppv) ) 

#define IXFeed_UnreadItemCount(This,puiUnreadItemCount)	\
    ( (This)->lpVtbl -> UnreadItemCount(This,puiUnreadItemCount) ) 

#define IXFeed_ItemCount(This,puiItemCount)	\
    ( (This)->lpVtbl -> ItemCount(This,puiItemCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeed_INTERFACE_DEFINED__ */


#ifndef __IXFeedEvents_INTERFACE_DEFINED__
#define __IXFeedEvents_INTERFACE_DEFINED__

/* interface IXFeedEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1630852e-1263-465b-98e5-fe60ffec4ac2")
    IXFeedEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedMoved( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [in] */ __RPC__in LPCWSTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEEDS_DOWNLOAD_ERROR fde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Error )( 
            IXFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedMoved )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ __RPC__in LPCWSTR pszOldPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEEDS_DOWNLOAD_ERROR fde);
        
        HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            IXFeedEvents * This,
            /* [in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ FEICF feicfFlags);
        
        END_INTERFACE
    } IXFeedEventsVtbl;

    interface IXFeedEvents
    {
        CONST_VTBL struct IXFeedEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IXFeedEvents_FeedDeleted(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDeleted(This,pszPath) ) 

#define IXFeedEvents_FeedRenamed(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,pszPath,pszOldPath) ) 

#define IXFeedEvents_FeedUrlChanged(This,pszPath)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,pszPath) ) 

#define IXFeedEvents_FeedMoved(This,pszPath,pszOldPath)	\
    ( (This)->lpVtbl -> FeedMoved(This,pszPath,pszOldPath) ) 

#define IXFeedEvents_FeedDownloading(This,pszPath)	\
    ( (This)->lpVtbl -> FeedDownloading(This,pszPath) ) 

#define IXFeedEvents_FeedDownloadCompleted(This,pszPath,fde)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,pszPath,fde) ) 

#define IXFeedEvents_FeedItemCountChanged(This,pszPath,feicfFlags)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,pszPath,feicfFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedEvents_INTERFACE_DEFINED__ */


#ifndef __IXFeedItem_INTERFACE_DEFINED__
#define __IXFeedItem_INTERFACE_DEFINED__

/* interface IXFeedItem */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e757b2f5-e73e-434e-a1bf-2bd7c3e60fcb")
    IXFeedItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Xml( 
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS fxif,
            /* [out] */ __RPC__deref_out_opt IStream **pps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Title( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Link( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Guid( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Description( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PubDate( 
            /* [out] */ __RPC__out SYSTEMTIME *pstPubDate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Comments( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Author( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszAuthor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enclosure( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRead( 
            /* [out] */ __RPC__out BOOL *pbIsRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsRead( 
            /* [in] */ BOOL bIsRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalId( 
            /* [out] */ __RPC__out UINT *puiId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadTime( 
            /* [out] */ __RPC__out SYSTEMTIME *pstLastDownloadTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Modified( 
            /* [out] */ __RPC__out SYSTEMTIME *pstModifiedTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *Xml )( 
            IXFeedItem * This,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS fxif,
            /* [out] */ __RPC__deref_out_opt IStream **pps);
        
        HRESULT ( STDMETHODCALLTYPE *Title )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *Link )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Guid )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Description )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *PubDate )( 
            IXFeedItem * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstPubDate);
        
        HRESULT ( STDMETHODCALLTYPE *Comments )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Author )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszAuthor);
        
        HRESULT ( STDMETHODCALLTYPE *Enclosure )( 
            IXFeedItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *IsRead )( 
            IXFeedItem * This,
            /* [out] */ __RPC__out BOOL *pbIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsRead )( 
            IXFeedItem * This,
            /* [in] */ BOOL bIsRead);
        
        HRESULT ( STDMETHODCALLTYPE *LocalId )( 
            IXFeedItem * This,
            /* [out] */ __RPC__out UINT *puiId);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            IXFeedItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IXFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            IXFeedItem * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadTime )( 
            IXFeedItem * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstLastDownloadTime);
        
        HRESULT ( STDMETHODCALLTYPE *Modified )( 
            IXFeedItem * This,
            /* [out] */ __RPC__out SYSTEMTIME *pstModifiedTime);
        
        END_INTERFACE
    } IXFeedItemVtbl;

    interface IXFeedItem
    {
        CONST_VTBL struct IXFeedItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedItem_Xml(This,fxif,pps)	\
    ( (This)->lpVtbl -> Xml(This,fxif,pps) ) 

#define IXFeedItem_Title(This,ppszTitle)	\
    ( (This)->lpVtbl -> Title(This,ppszTitle) ) 

#define IXFeedItem_Link(This,ppszUrl)	\
    ( (This)->lpVtbl -> Link(This,ppszUrl) ) 

#define IXFeedItem_Guid(This,ppszGuid)	\
    ( (This)->lpVtbl -> Guid(This,ppszGuid) ) 

#define IXFeedItem_Description(This,ppszDescription)	\
    ( (This)->lpVtbl -> Description(This,ppszDescription) ) 

#define IXFeedItem_PubDate(This,pstPubDate)	\
    ( (This)->lpVtbl -> PubDate(This,pstPubDate) ) 

#define IXFeedItem_Comments(This,ppszUrl)	\
    ( (This)->lpVtbl -> Comments(This,ppszUrl) ) 

#define IXFeedItem_Author(This,ppszAuthor)	\
    ( (This)->lpVtbl -> Author(This,ppszAuthor) ) 

#define IXFeedItem_Enclosure(This,riid,ppv)	\
    ( (This)->lpVtbl -> Enclosure(This,riid,ppv) ) 

#define IXFeedItem_IsRead(This,pbIsRead)	\
    ( (This)->lpVtbl -> IsRead(This,pbIsRead) ) 

#define IXFeedItem_SetIsRead(This,bIsRead)	\
    ( (This)->lpVtbl -> SetIsRead(This,bIsRead) ) 

#define IXFeedItem_LocalId(This,puiId)	\
    ( (This)->lpVtbl -> LocalId(This,puiId) ) 

#define IXFeedItem_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IXFeedItem_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeedItem_LastDownloadTime(This,pstLastDownloadTime)	\
    ( (This)->lpVtbl -> LastDownloadTime(This,pstLastDownloadTime) ) 

#define IXFeedItem_Modified(This,pstModifiedTime)	\
    ( (This)->lpVtbl -> Modified(This,pstModifiedTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedItem_INTERFACE_DEFINED__ */


#ifndef __IXFeedEnclosure_INTERFACE_DEFINED__
#define __IXFeedEnclosure_INTERFACE_DEFINED__

/* interface IXFeedEnclosure */
/* [object][uuid] */ 


EXTERN_C const IID IID_IXFeedEnclosure;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFBFB953-644F-4792-B69C-DFACA4CBF89A")
    IXFeedEnclosure : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Url( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Type( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszMimeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Length( 
            /* [out] */ __RPC__out UINT *puiLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadStatus( 
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *pfds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LastDownloadError( 
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *pfde) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocalPath( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Parent( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadUrl( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DownloadMimeType( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszMimeType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFile( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFile( 
            /* [in] */ __RPC__in LPCWSTR pszDownloadUrl,
            /* [in] */ __RPC__in LPCWSTR pszDownloadFilePath,
            /* [in] */ __RPC__in LPCWSTR pszDownloadMimeType,
            /* [in] */ __RPC__in LPCWSTR pszEnclosureFilename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXFeedEnclosureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXFeedEnclosure * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXFeedEnclosure * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *Url )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *Type )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszMimeType);
        
        HRESULT ( STDMETHODCALLTYPE *Length )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__out UINT *puiLength);
        
        HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadStatus )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *pfds);
        
        HRESULT ( STDMETHODCALLTYPE *LastDownloadError )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *pfde);
        
        HRESULT ( STDMETHODCALLTYPE *LocalPath )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *Parent )( 
            IXFeedEnclosure * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadUrl )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DownloadMimeType )( 
            IXFeedEnclosure * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszMimeType);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFile )( 
            IXFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            IXFeedEnclosure * This,
            /* [in] */ __RPC__in LPCWSTR pszDownloadUrl,
            /* [in] */ __RPC__in LPCWSTR pszDownloadFilePath,
            /* [in] */ __RPC__in LPCWSTR pszDownloadMimeType,
            /* [in] */ __RPC__in LPCWSTR pszEnclosureFilename);
        
        END_INTERFACE
    } IXFeedEnclosureVtbl;

    interface IXFeedEnclosure
    {
        CONST_VTBL struct IXFeedEnclosureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXFeedEnclosure_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXFeedEnclosure_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXFeedEnclosure_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXFeedEnclosure_Url(This,ppszUrl)	\
    ( (This)->lpVtbl -> Url(This,ppszUrl) ) 

#define IXFeedEnclosure_Type(This,ppszMimeType)	\
    ( (This)->lpVtbl -> Type(This,ppszMimeType) ) 

#define IXFeedEnclosure_Length(This,puiLength)	\
    ( (This)->lpVtbl -> Length(This,puiLength) ) 

#define IXFeedEnclosure_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IXFeedEnclosure_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IXFeedEnclosure_DownloadStatus(This,pfds)	\
    ( (This)->lpVtbl -> DownloadStatus(This,pfds) ) 

#define IXFeedEnclosure_LastDownloadError(This,pfde)	\
    ( (This)->lpVtbl -> LastDownloadError(This,pfde) ) 

#define IXFeedEnclosure_LocalPath(This,ppszPath)	\
    ( (This)->lpVtbl -> LocalPath(This,ppszPath) ) 

#define IXFeedEnclosure_Parent(This,riid,ppv)	\
    ( (This)->lpVtbl -> Parent(This,riid,ppv) ) 

#define IXFeedEnclosure_DownloadUrl(This,ppszUrl)	\
    ( (This)->lpVtbl -> DownloadUrl(This,ppszUrl) ) 

#define IXFeedEnclosure_DownloadMimeType(This,ppszMimeType)	\
    ( (This)->lpVtbl -> DownloadMimeType(This,ppszMimeType) ) 

#define IXFeedEnclosure_RemoveFile(This)	\
    ( (This)->lpVtbl -> RemoveFile(This) ) 

#define IXFeedEnclosure_SetFile(This,pszDownloadUrl,pszDownloadFilePath,pszDownloadMimeType,pszEnclosureFilename)	\
    ( (This)->lpVtbl -> SetFile(This,pszDownloadUrl,pszDownloadFilePath,pszDownloadMimeType,pszEnclosureFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXFeedEnclosure_INTERFACE_DEFINED__ */



#ifndef __Feeds_LIBRARY_DEFINED__
#define __Feeds_LIBRARY_DEFINED__

/* library Feeds */
/* [custom][version][lcid][helpstring][uuid] */ 


EXTERN_C const IID LIBID_Feeds;

#ifndef __IFeedsManager_INTERFACE_DEFINED__
#define __IFeedsManager_INTERFACE_DEFINED__

/* interface IFeedsManager */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedsManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a74029cc-1f1a-4906-88f0-810638d86591")
    IFeedsManager : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RootFolder( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSubscribed( 
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *subscribed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [in] */ __RPC__in BSTR feedPath,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [in] */ __RPC__in BSTR feedPath,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeedByUrl( 
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFolder( 
            /* [in] */ __RPC__in BSTR folderPath,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFolder( 
            /* [in] */ __RPC__in BSTR folderPath,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFeed( 
            /* [in] */ __RPC__in BSTR feedPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteFolder( 
            /* [in] */ __RPC__in BSTR folderPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BackgroundSync( 
            /* [in] */ FEEDS_BACKGROUNDSYNC_ACTION action) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BackgroundSyncStatus( 
            /* [retval][out] */ __RPC__out FEEDS_BACKGROUNDSYNC_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultInterval( 
            /* [retval][out] */ __RPC__out LONG *minutes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultInterval( 
            /* [in] */ LONG minutes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncSyncAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Normalize( 
            /* [in] */ __RPC__in BSTR feedXmlIn,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedXmlOut) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ItemCountLimit( 
            /* [retval][out] */ __RPC__out LONG *itemCountLimit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedsManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedsManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedsManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedsManager * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedsManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedsManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RootFolder )( 
            IFeedsManager * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSubscribed )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *subscribed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedPath,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedPath,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeedByUrl )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFolder )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR folderPath,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFolder )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR folderPath,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFeed )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteFolder )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR folderPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BackgroundSync )( 
            IFeedsManager * This,
            /* [in] */ FEEDS_BACKGROUNDSYNC_ACTION action);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BackgroundSyncStatus )( 
            IFeedsManager * This,
            /* [retval][out] */ __RPC__out FEEDS_BACKGROUNDSYNC_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInterval )( 
            IFeedsManager * This,
            /* [retval][out] */ __RPC__out LONG *minutes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultInterval )( 
            IFeedsManager * This,
            /* [in] */ LONG minutes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncSyncAll )( 
            IFeedsManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Normalize )( 
            IFeedsManager * This,
            /* [in] */ __RPC__in BSTR feedXmlIn,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedXmlOut);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ItemCountLimit )( 
            IFeedsManager * This,
            /* [retval][out] */ __RPC__out LONG *itemCountLimit);
        
        END_INTERFACE
    } IFeedsManagerVtbl;

    interface IFeedsManager
    {
        CONST_VTBL struct IFeedsManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedsManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedsManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedsManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedsManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedsManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedsManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedsManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedsManager_get_RootFolder(This,disp)	\
    ( (This)->lpVtbl -> get_RootFolder(This,disp) ) 

#define IFeedsManager_IsSubscribed(This,feedUrl,subscribed)	\
    ( (This)->lpVtbl -> IsSubscribed(This,feedUrl,subscribed) ) 

#define IFeedsManager_ExistsFeed(This,feedPath,exists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,feedPath,exists) ) 

#define IFeedsManager_GetFeed(This,feedPath,disp)	\
    ( (This)->lpVtbl -> GetFeed(This,feedPath,disp) ) 

#define IFeedsManager_GetFeedByUrl(This,feedUrl,disp)	\
    ( (This)->lpVtbl -> GetFeedByUrl(This,feedUrl,disp) ) 

#define IFeedsManager_ExistsFolder(This,folderPath,exists)	\
    ( (This)->lpVtbl -> ExistsFolder(This,folderPath,exists) ) 

#define IFeedsManager_GetFolder(This,folderPath,disp)	\
    ( (This)->lpVtbl -> GetFolder(This,folderPath,disp) ) 

#define IFeedsManager_DeleteFeed(This,feedPath)	\
    ( (This)->lpVtbl -> DeleteFeed(This,feedPath) ) 

#define IFeedsManager_DeleteFolder(This,folderPath)	\
    ( (This)->lpVtbl -> DeleteFolder(This,folderPath) ) 

#define IFeedsManager_BackgroundSync(This,action)	\
    ( (This)->lpVtbl -> BackgroundSync(This,action) ) 

#define IFeedsManager_get_BackgroundSyncStatus(This,status)	\
    ( (This)->lpVtbl -> get_BackgroundSyncStatus(This,status) ) 

#define IFeedsManager_get_DefaultInterval(This,minutes)	\
    ( (This)->lpVtbl -> get_DefaultInterval(This,minutes) ) 

#define IFeedsManager_put_DefaultInterval(This,minutes)	\
    ( (This)->lpVtbl -> put_DefaultInterval(This,minutes) ) 

#define IFeedsManager_AsyncSyncAll(This)	\
    ( (This)->lpVtbl -> AsyncSyncAll(This) ) 

#define IFeedsManager_Normalize(This,feedXmlIn,feedXmlOut)	\
    ( (This)->lpVtbl -> Normalize(This,feedXmlIn,feedXmlOut) ) 

#define IFeedsManager_get_ItemCountLimit(This,itemCountLimit)	\
    ( (This)->lpVtbl -> get_ItemCountLimit(This,itemCountLimit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedsManager_INTERFACE_DEFINED__ */


#ifndef __IFeedsEnum_INTERFACE_DEFINED__
#define __IFeedsEnum_INTERFACE_DEFINED__

/* interface IFeedsEnum */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedsEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e3cd0028-2eed-4c60-8fae-a3225309a836")
    IFeedsEnum : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ LONG index,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [restricted][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **enumVar) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedsEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedsEnum * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedsEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedsEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedsEnum * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedsEnum * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedsEnum * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedsEnum * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IFeedsEnum * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IFeedsEnum * This,
            /* [in] */ LONG index,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [restricted][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IFeedsEnum * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **enumVar);
        
        END_INTERFACE
    } IFeedsEnumVtbl;

    interface IFeedsEnum
    {
        CONST_VTBL struct IFeedsEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedsEnum_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedsEnum_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedsEnum_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedsEnum_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedsEnum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedsEnum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedsEnum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedsEnum_get_Count(This,count)	\
    ( (This)->lpVtbl -> get_Count(This,count) ) 

#define IFeedsEnum_Item(This,index,disp)	\
    ( (This)->lpVtbl -> Item(This,index,disp) ) 

#define IFeedsEnum_get__NewEnum(This,enumVar)	\
    ( (This)->lpVtbl -> get__NewEnum(This,enumVar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedsEnum_INTERFACE_DEFINED__ */


#ifndef __IFeedFolder_INTERFACE_DEFINED__
#define __IFeedFolder_INTERFACE_DEFINED__

/* interface IFeedFolder */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81f04ad1-4194-4d7d-86d6-11813cec163c")
    IFeedFolder : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Feeds( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Subfolders( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFeed( 
            /* [in] */ __RPC__in BSTR feedName,
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateSubfolder( 
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsFeed( 
            /* [in] */ __RPC__in BSTR feedName,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFeed( 
            /* [in] */ __RPC__in BSTR feedName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExistsSubfolder( 
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSubfolder( 
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *folderName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ __RPC__in BSTR folderName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *folderPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ __RPC__in BSTR newParentPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsRoot( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isRoot) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalUnreadItemCount( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalItemCount( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedFolder * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedFolder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedFolder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Feeds )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Subfolders )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFeed )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR feedName,
            /* [in] */ __RPC__in BSTR feedUrl,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateSubfolder )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsFeed )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR feedName,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFeed )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR feedName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExistsSubfolder )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *exists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSubfolder )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR folderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFeedFolder * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *folderName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR folderName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *folderPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IFeedFolder * This,
            /* [in] */ __RPC__in BSTR newParentPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsRoot )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isRoot);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TotalUnreadItemCount )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TotalItemCount )( 
            IFeedFolder * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            IFeedFolder * This,
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        END_INTERFACE
    } IFeedFolderVtbl;

    interface IFeedFolder
    {
        CONST_VTBL struct IFeedFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedFolder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedFolder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedFolder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedFolder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedFolder_get_Feeds(This,disp)	\
    ( (This)->lpVtbl -> get_Feeds(This,disp) ) 

#define IFeedFolder_get_Subfolders(This,disp)	\
    ( (This)->lpVtbl -> get_Subfolders(This,disp) ) 

#define IFeedFolder_CreateFeed(This,feedName,feedUrl,disp)	\
    ( (This)->lpVtbl -> CreateFeed(This,feedName,feedUrl,disp) ) 

#define IFeedFolder_CreateSubfolder(This,folderName,disp)	\
    ( (This)->lpVtbl -> CreateSubfolder(This,folderName,disp) ) 

#define IFeedFolder_ExistsFeed(This,feedName,exists)	\
    ( (This)->lpVtbl -> ExistsFeed(This,feedName,exists) ) 

#define IFeedFolder_GetFeed(This,feedName,disp)	\
    ( (This)->lpVtbl -> GetFeed(This,feedName,disp) ) 

#define IFeedFolder_ExistsSubfolder(This,folderName,exists)	\
    ( (This)->lpVtbl -> ExistsSubfolder(This,folderName,exists) ) 

#define IFeedFolder_GetSubfolder(This,folderName,disp)	\
    ( (This)->lpVtbl -> GetSubfolder(This,folderName,disp) ) 

#define IFeedFolder_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeedFolder_get_Name(This,folderName)	\
    ( (This)->lpVtbl -> get_Name(This,folderName) ) 

#define IFeedFolder_Rename(This,folderName)	\
    ( (This)->lpVtbl -> Rename(This,folderName) ) 

#define IFeedFolder_get_Path(This,folderPath)	\
    ( (This)->lpVtbl -> get_Path(This,folderPath) ) 

#define IFeedFolder_Move(This,newParentPath)	\
    ( (This)->lpVtbl -> Move(This,newParentPath) ) 

#define IFeedFolder_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedFolder_get_IsRoot(This,isRoot)	\
    ( (This)->lpVtbl -> get_IsRoot(This,isRoot) ) 

#define IFeedFolder_get_TotalUnreadItemCount(This,count)	\
    ( (This)->lpVtbl -> get_TotalUnreadItemCount(This,count) ) 

#define IFeedFolder_get_TotalItemCount(This,count)	\
    ( (This)->lpVtbl -> get_TotalItemCount(This,count) ) 

#define IFeedFolder_GetWatcher(This,scope,mask,disp)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,disp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedFolder_INTERFACE_DEFINED__ */


#ifndef __IFeedFolderEvents_INTERFACE_DEFINED__
#define __IFeedFolderEvents_INTERFACE_DEFINED__

/* interface IFeedFolderEvents */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedFolderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20a59fa6-a844-4630-9e98-175f70b4d55b")
    IFeedFolderEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderAdded( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderDeleted( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderRenamed( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderMovedFrom( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderMovedTo( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FolderItemCountChanged( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedAdded( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMovedFrom( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMovedTo( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ FEEDS_DOWNLOAD_ERROR error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedFolderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedFolderEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedFolderEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedFolderEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedFolderEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedFolderEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Error )( 
            IFeedFolderEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderAdded )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderDeleted )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderRenamed )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderMovedFrom )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderMovedTo )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FolderItemCountChanged )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedAdded )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMovedFrom )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMovedTo )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ FEEDS_DOWNLOAD_ERROR error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            IFeedFolderEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType);
        
        END_INTERFACE
    } IFeedFolderEventsVtbl;

    interface IFeedFolderEvents
    {
        CONST_VTBL struct IFeedFolderEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedFolderEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedFolderEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedFolderEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedFolderEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedFolderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedFolderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedFolderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedFolderEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IFeedFolderEvents_FolderAdded(This,path)	\
    ( (This)->lpVtbl -> FolderAdded(This,path) ) 

#define IFeedFolderEvents_FolderDeleted(This,path)	\
    ( (This)->lpVtbl -> FolderDeleted(This,path) ) 

#define IFeedFolderEvents_FolderRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderRenamed(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderMovedFrom(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderMovedFrom(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderMovedTo(This,path,oldPath)	\
    ( (This)->lpVtbl -> FolderMovedTo(This,path,oldPath) ) 

#define IFeedFolderEvents_FolderItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FolderItemCountChanged(This,path,itemCountType) ) 

#define IFeedFolderEvents_FeedAdded(This,path)	\
    ( (This)->lpVtbl -> FeedAdded(This,path) ) 

#define IFeedFolderEvents_FeedDeleted(This,path)	\
    ( (This)->lpVtbl -> FeedDeleted(This,path) ) 

#define IFeedFolderEvents_FeedRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedUrlChanged(This,path)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,path) ) 

#define IFeedFolderEvents_FeedMovedFrom(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMovedFrom(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedMovedTo(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMovedTo(This,path,oldPath) ) 

#define IFeedFolderEvents_FeedDownloading(This,path)	\
    ( (This)->lpVtbl -> FeedDownloading(This,path) ) 

#define IFeedFolderEvents_FeedDownloadCompleted(This,path,error)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,path,error) ) 

#define IFeedFolderEvents_FeedItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,path,itemCountType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedFolderEvents_INTERFACE_DEFINED__ */


#ifndef __IFeed_INTERFACE_DEFINED__
#define __IFeed_INTERFACE_DEFINED__

/* interface IFeed */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeed;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f7f915d8-2ede-42bc-98e7-a5d05063a757")
    IFeed : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Xml( 
            /* [in] */ LONG count,
            /* [in] */ FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [in] */ FEEDS_XML_SORT_ORDER sortOrder,
            /* [in] */ FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *xml) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ __RPC__in BSTR name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedUrl) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Url( 
            /* [in] */ __RPC__in BSTR feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalId( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedGuid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ __RPC__in BSTR newParentPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastWriteTime( 
            /* [retval][out] */ __RPC__out DATE *lastWrite) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SyncSetting( 
            /* [retval][out] */ __RPC__out FEEDS_SYNC_SETTING *syncSetting) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SyncSetting( 
            /* [in] */ FEEDS_SYNC_SETTING syncSetting) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Interval( 
            /* [retval][out] */ __RPC__out LONG *minutes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Interval( 
            /* [in] */ LONG minutes) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadTime( 
            /* [retval][out] */ __RPC__out DATE *lastDownload) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalEnclosurePath( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Items( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ LONG itemId,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *description) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Link( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *homePage) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Image( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *imageUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastBuildDate( 
            /* [retval][out] */ __RPC__out DATE *lastBuildDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PubDate( 
            /* [retval][out] */ __RPC__out DATE *lastPopulateDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Ttl( 
            /* [retval][out] */ __RPC__out LONG *ttl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *language) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *copyright) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxItemCount( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxItemCount( 
            /* [in] */ LONG count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadEnclosuresAutomatically( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *downloadEnclosuresAutomatically) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DownloadEnclosuresAutomatically( 
            /* [in] */ VARIANT_BOOL downloadEnclosuresAutomatically) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadStatus( 
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadError( 
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ __RPC__in BSTR feedXml,
            /* [in] */ __RPC__in BSTR feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsList( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MarkAllItemsRead( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWatcher( 
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UnreadItemCount( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ItemCount( 
            /* [retval][out] */ __RPC__out LONG *count) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeed * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeed * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeed * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeed * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeed * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeed * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeed * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            IFeed * This,
            /* [in] */ LONG count,
            /* [in] */ FEEDS_XML_SORT_PROPERTY sortProperty,
            /* [in] */ FEEDS_XML_SORT_ORDER sortOrder,
            /* [in] */ FEEDS_XML_FILTER_FLAGS filterFlags,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IFeed * This,
            /* [in] */ __RPC__in BSTR name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedUrl);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            IFeed * This,
            /* [in] */ __RPC__in BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IFeed * This,
            /* [in] */ __RPC__in BSTR newParentPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastWriteTime )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out DATE *lastWrite);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            IFeed * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SyncSetting )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out FEEDS_SYNC_SETTING *syncSetting);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SyncSetting )( 
            IFeed * This,
            /* [in] */ FEEDS_SYNC_SETTING syncSetting);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Interval )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out LONG *minutes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Interval )( 
            IFeed * This,
            /* [in] */ LONG minutes);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalEnclosurePath )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Items )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IFeed * This,
            /* [in] */ LONG itemId,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *homePage);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Image )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *imageUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastBuildDate )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out DATE *lastBuildDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out DATE *lastPopulateDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Ttl )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out LONG *ttl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *language);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *copyright);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxItemCount )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxItemCount )( 
            IFeed * This,
            /* [in] */ LONG count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadEnclosuresAutomatically )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *downloadEnclosuresAutomatically);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DownloadEnclosuresAutomatically )( 
            IFeed * This,
            /* [in] */ VARIANT_BOOL downloadEnclosuresAutomatically);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadStatus )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadError )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IFeed * This,
            /* [in] */ __RPC__in BSTR feedXml,
            /* [in] */ __RPC__in BSTR feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            IFeed * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *feedUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsList )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MarkAllItemsRead )( 
            IFeed * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWatcher )( 
            IFeed * This,
            /* [in] */ FEEDS_EVENTS_SCOPE scope,
            /* [in] */ FEEDS_EVENTS_MASK mask,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnreadItemCount )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ItemCount )( 
            IFeed * This,
            /* [retval][out] */ __RPC__out LONG *count);
        
        END_INTERFACE
    } IFeedVtbl;

    interface IFeed
    {
        CONST_VTBL struct IFeedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeed_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeed_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeed_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeed_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeed_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeed_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeed_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeed_Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,count,sortProperty,sortOrder,filterFlags,includeFlags,xml) ) 

#define IFeed_get_Name(This,name)	\
    ( (This)->lpVtbl -> get_Name(This,name) ) 

#define IFeed_Rename(This,name)	\
    ( (This)->lpVtbl -> Rename(This,name) ) 

#define IFeed_get_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> get_Url(This,feedUrl) ) 

#define IFeed_put_Url(This,feedUrl)	\
    ( (This)->lpVtbl -> put_Url(This,feedUrl) ) 

#define IFeed_get_LocalId(This,feedGuid)	\
    ( (This)->lpVtbl -> get_LocalId(This,feedGuid) ) 

#define IFeed_get_Path(This,path)	\
    ( (This)->lpVtbl -> get_Path(This,path) ) 

#define IFeed_Move(This,newParentPath)	\
    ( (This)->lpVtbl -> Move(This,newParentPath) ) 

#define IFeed_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeed_get_LastWriteTime(This,lastWrite)	\
    ( (This)->lpVtbl -> get_LastWriteTime(This,lastWrite) ) 

#define IFeed_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeed_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IFeed_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IFeed_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IFeed_get_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> get_SyncSetting(This,syncSetting) ) 

#define IFeed_put_SyncSetting(This,syncSetting)	\
    ( (This)->lpVtbl -> put_SyncSetting(This,syncSetting) ) 

#define IFeed_get_Interval(This,minutes)	\
    ( (This)->lpVtbl -> get_Interval(This,minutes) ) 

#define IFeed_put_Interval(This,minutes)	\
    ( (This)->lpVtbl -> put_Interval(This,minutes) ) 

#define IFeed_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeed_get_LocalEnclosurePath(This,path)	\
    ( (This)->lpVtbl -> get_LocalEnclosurePath(This,path) ) 

#define IFeed_get_Items(This,disp)	\
    ( (This)->lpVtbl -> get_Items(This,disp) ) 

#define IFeed_GetItem(This,itemId,disp)	\
    ( (This)->lpVtbl -> GetItem(This,itemId,disp) ) 

#define IFeed_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeed_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeed_get_Link(This,homePage)	\
    ( (This)->lpVtbl -> get_Link(This,homePage) ) 

#define IFeed_get_Image(This,imageUrl)	\
    ( (This)->lpVtbl -> get_Image(This,imageUrl) ) 

#define IFeed_get_LastBuildDate(This,lastBuildDate)	\
    ( (This)->lpVtbl -> get_LastBuildDate(This,lastBuildDate) ) 

#define IFeed_get_PubDate(This,lastPopulateDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,lastPopulateDate) ) 

#define IFeed_get_Ttl(This,ttl)	\
    ( (This)->lpVtbl -> get_Ttl(This,ttl) ) 

#define IFeed_get_Language(This,language)	\
    ( (This)->lpVtbl -> get_Language(This,language) ) 

#define IFeed_get_Copyright(This,copyright)	\
    ( (This)->lpVtbl -> get_Copyright(This,copyright) ) 

#define IFeed_get_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> get_MaxItemCount(This,count) ) 

#define IFeed_put_MaxItemCount(This,count)	\
    ( (This)->lpVtbl -> put_MaxItemCount(This,count) ) 

#define IFeed_get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> get_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed_put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically)	\
    ( (This)->lpVtbl -> put_DownloadEnclosuresAutomatically(This,downloadEnclosuresAutomatically) ) 

#define IFeed_get_DownloadStatus(This,status)	\
    ( (This)->lpVtbl -> get_DownloadStatus(This,status) ) 

#define IFeed_get_LastDownloadError(This,error)	\
    ( (This)->lpVtbl -> get_LastDownloadError(This,error) ) 

#define IFeed_Merge(This,feedXml,feedUrl)	\
    ( (This)->lpVtbl -> Merge(This,feedXml,feedUrl) ) 

#define IFeed_get_DownloadUrl(This,feedUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,feedUrl) ) 

#define IFeed_get_IsList(This,isList)	\
    ( (This)->lpVtbl -> get_IsList(This,isList) ) 

#define IFeed_MarkAllItemsRead(This)	\
    ( (This)->lpVtbl -> MarkAllItemsRead(This) ) 

#define IFeed_GetWatcher(This,scope,mask,disp)	\
    ( (This)->lpVtbl -> GetWatcher(This,scope,mask,disp) ) 

#define IFeed_get_UnreadItemCount(This,count)	\
    ( (This)->lpVtbl -> get_UnreadItemCount(This,count) ) 

#define IFeed_get_ItemCount(This,count)	\
    ( (This)->lpVtbl -> get_ItemCount(This,count) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeed_INTERFACE_DEFINED__ */


#ifndef __IFeedEvents_INTERFACE_DEFINED__
#define __IFeedEvents_INTERFACE_DEFINED__

/* interface IFeedEvents */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("abf35c99-0681-47ea-9a8c-1436a375a99e")
    IFeedEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Error( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDeleted( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedRenamed( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedUrlChanged( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedMoved( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloading( 
            /* [in] */ __RPC__in const BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedDownloadCompleted( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ FEEDS_DOWNLOAD_ERROR error) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FeedItemCountChanged( 
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Error )( 
            IFeedEvents * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDeleted )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedRenamed )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedUrlChanged )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedMoved )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ __RPC__in const BSTR oldPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloading )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedDownloadCompleted )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ FEEDS_DOWNLOAD_ERROR error);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FeedItemCountChanged )( 
            IFeedEvents * This,
            /* [in] */ __RPC__in const BSTR path,
            /* [in] */ LONG itemCountType);
        
        END_INTERFACE
    } IFeedEventsVtbl;

    interface IFeedEvents
    {
        CONST_VTBL struct IFeedEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedEvents_Error(This)	\
    ( (This)->lpVtbl -> Error(This) ) 

#define IFeedEvents_FeedDeleted(This,path)	\
    ( (This)->lpVtbl -> FeedDeleted(This,path) ) 

#define IFeedEvents_FeedRenamed(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedRenamed(This,path,oldPath) ) 

#define IFeedEvents_FeedUrlChanged(This,path)	\
    ( (This)->lpVtbl -> FeedUrlChanged(This,path) ) 

#define IFeedEvents_FeedMoved(This,path,oldPath)	\
    ( (This)->lpVtbl -> FeedMoved(This,path,oldPath) ) 

#define IFeedEvents_FeedDownloading(This,path)	\
    ( (This)->lpVtbl -> FeedDownloading(This,path) ) 

#define IFeedEvents_FeedDownloadCompleted(This,path,error)	\
    ( (This)->lpVtbl -> FeedDownloadCompleted(This,path,error) ) 

#define IFeedEvents_FeedItemCountChanged(This,path,itemCountType)	\
    ( (This)->lpVtbl -> FeedItemCountChanged(This,path,itemCountType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedEvents_INTERFACE_DEFINED__ */


#ifndef __IFeedItem_INTERFACE_DEFINED__
#define __IFeedItem_INTERFACE_DEFINED__

/* interface IFeedItem */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0a1e6cad-0a47-4da2-a13d-5baaa5c8bd4f")
    IFeedItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Xml( 
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *xml) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Link( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *linkUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Guid( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *itemGuid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *description) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PubDate( 
            /* [retval][out] */ __RPC__out DATE *pubDate) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Comments( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *comments) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Author( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *author) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enclosure( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsRead( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isRead) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_IsRead( 
            /* [in] */ VARIANT_BOOL isRead) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalId( 
            /* [retval][out] */ __RPC__out LONG *itemId) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *itemUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadTime( 
            /* [retval][out] */ __RPC__out DATE *lastDownload) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Modified( 
            /* [retval][out] */ __RPC__out DATE *modified) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedItem * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Xml )( 
            IFeedItem * This,
            /* [in] */ FEEDS_XML_INCLUDE_FLAGS includeFlags,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *xml);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Link )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *linkUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Guid )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *itemGuid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PubDate )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__out DATE *pubDate);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Comments )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *comments);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *author);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enclosure )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsRead )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *isRead);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_IsRead )( 
            IFeedItem * This,
            /* [in] */ VARIANT_BOOL isRead);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalId )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__out LONG *itemId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFeedItem * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *itemUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadTime )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__out DATE *lastDownload);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Modified )( 
            IFeedItem * This,
            /* [retval][out] */ __RPC__out DATE *modified);
        
        END_INTERFACE
    } IFeedItemVtbl;

    interface IFeedItem
    {
        CONST_VTBL struct IFeedItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedItem_Xml(This,includeFlags,xml)	\
    ( (This)->lpVtbl -> Xml(This,includeFlags,xml) ) 

#define IFeedItem_get_Title(This,title)	\
    ( (This)->lpVtbl -> get_Title(This,title) ) 

#define IFeedItem_get_Link(This,linkUrl)	\
    ( (This)->lpVtbl -> get_Link(This,linkUrl) ) 

#define IFeedItem_get_Guid(This,itemGuid)	\
    ( (This)->lpVtbl -> get_Guid(This,itemGuid) ) 

#define IFeedItem_get_Description(This,description)	\
    ( (This)->lpVtbl -> get_Description(This,description) ) 

#define IFeedItem_get_PubDate(This,pubDate)	\
    ( (This)->lpVtbl -> get_PubDate(This,pubDate) ) 

#define IFeedItem_get_Comments(This,comments)	\
    ( (This)->lpVtbl -> get_Comments(This,comments) ) 

#define IFeedItem_get_Author(This,author)	\
    ( (This)->lpVtbl -> get_Author(This,author) ) 

#define IFeedItem_get_Enclosure(This,disp)	\
    ( (This)->lpVtbl -> get_Enclosure(This,disp) ) 

#define IFeedItem_get_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> get_IsRead(This,isRead) ) 

#define IFeedItem_put_IsRead(This,isRead)	\
    ( (This)->lpVtbl -> put_IsRead(This,isRead) ) 

#define IFeedItem_get_LocalId(This,itemId)	\
    ( (This)->lpVtbl -> get_LocalId(This,itemId) ) 

#define IFeedItem_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IFeedItem_get_DownloadUrl(This,itemUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,itemUrl) ) 

#define IFeedItem_get_LastDownloadTime(This,lastDownload)	\
    ( (This)->lpVtbl -> get_LastDownloadTime(This,lastDownload) ) 

#define IFeedItem_get_Modified(This,modified)	\
    ( (This)->lpVtbl -> get_Modified(This,modified) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedItem_INTERFACE_DEFINED__ */


#ifndef __IFeedEnclosure_INTERFACE_DEFINED__
#define __IFeedEnclosure_INTERFACE_DEFINED__

/* interface IFeedEnclosure */
/* [object][oleautomation][dual][uuid] */ 


EXTERN_C const IID IID_IFeedEnclosure;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("361C26F7-90A4-4e67-AE09-3A36A546436A")
    IFeedEnclosure : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *enclosureUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *mimeType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ __RPC__out LONG *length) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AsyncDownload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CancelAsyncDownload( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadStatus( 
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *status) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LastDownloadError( 
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *error) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocalPath( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *localPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadUrl( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *enclosureUrl) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DownloadMimeType( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *mimeType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFile( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFile( 
            /* [in] */ __RPC__in BSTR downloadUrl,
            /* [in] */ __RPC__in BSTR downloadFilePath,
            /* [in] */ __RPC__in BSTR downloadMimeType,
            /* [in] */ __RPC__in BSTR enclosureFilename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFeedEnclosureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFeedEnclosure * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFeedEnclosure * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFeedEnclosure * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFeedEnclosure * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFeedEnclosure * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFeedEnclosure * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFeedEnclosure * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *enclosureUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *mimeType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__out LONG *length);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AsyncDownload )( 
            IFeedEnclosure * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CancelAsyncDownload )( 
            IFeedEnclosure * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadStatus )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_STATUS *status);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LastDownloadError )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__out FEEDS_DOWNLOAD_ERROR *error);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *localPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **disp);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadUrl )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *enclosureUrl);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadMimeType )( 
            IFeedEnclosure * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *mimeType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFile )( 
            IFeedEnclosure * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            IFeedEnclosure * This,
            /* [in] */ __RPC__in BSTR downloadUrl,
            /* [in] */ __RPC__in BSTR downloadFilePath,
            /* [in] */ __RPC__in BSTR downloadMimeType,
            /* [in] */ __RPC__in BSTR enclosureFilename);
        
        END_INTERFACE
    } IFeedEnclosureVtbl;

    interface IFeedEnclosure
    {
        CONST_VTBL struct IFeedEnclosureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFeedEnclosure_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFeedEnclosure_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFeedEnclosure_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFeedEnclosure_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFeedEnclosure_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFeedEnclosure_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFeedEnclosure_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFeedEnclosure_get_Url(This,enclosureUrl)	\
    ( (This)->lpVtbl -> get_Url(This,enclosureUrl) ) 

#define IFeedEnclosure_get_Type(This,mimeType)	\
    ( (This)->lpVtbl -> get_Type(This,mimeType) ) 

#define IFeedEnclosure_get_Length(This,length)	\
    ( (This)->lpVtbl -> get_Length(This,length) ) 

#define IFeedEnclosure_AsyncDownload(This)	\
    ( (This)->lpVtbl -> AsyncDownload(This) ) 

#define IFeedEnclosure_CancelAsyncDownload(This)	\
    ( (This)->lpVtbl -> CancelAsyncDownload(This) ) 

#define IFeedEnclosure_get_DownloadStatus(This,status)	\
    ( (This)->lpVtbl -> get_DownloadStatus(This,status) ) 

#define IFeedEnclosure_get_LastDownloadError(This,error)	\
    ( (This)->lpVtbl -> get_LastDownloadError(This,error) ) 

#define IFeedEnclosure_get_LocalPath(This,localPath)	\
    ( (This)->lpVtbl -> get_LocalPath(This,localPath) ) 

#define IFeedEnclosure_get_Parent(This,disp)	\
    ( (This)->lpVtbl -> get_Parent(This,disp) ) 

#define IFeedEnclosure_get_DownloadUrl(This,enclosureUrl)	\
    ( (This)->lpVtbl -> get_DownloadUrl(This,enclosureUrl) ) 

#define IFeedEnclosure_get_DownloadMimeType(This,mimeType)	\
    ( (This)->lpVtbl -> get_DownloadMimeType(This,mimeType) ) 

#define IFeedEnclosure_RemoveFile(This)	\
    ( (This)->lpVtbl -> RemoveFile(This) ) 

#define IFeedEnclosure_SetFile(This,downloadUrl,downloadFilePath,downloadMimeType,enclosureFilename)	\
    ( (This)->lpVtbl -> SetFile(This,downloadUrl,downloadFilePath,downloadMimeType,enclosureFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFeedEnclosure_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FeedsManager;

#ifdef __cplusplus

class DECLSPEC_UUID("faeb54c4-f66f-4806-83a0-805299f5e3ad")
FeedsManager;
#endif

EXTERN_C const CLSID CLSID_FeedFolderWatcher;

#ifdef __cplusplus

class DECLSPEC_UUID("281001ed-7765-4cb0-84af-e9b387af01ff")
FeedFolderWatcher;
#endif

EXTERN_C const CLSID CLSID_FeedWatcher;

#ifdef __cplusplus

class DECLSPEC_UUID("18a6737b-f433-4687-89bc-a1b4dfb9f123")
FeedWatcher;
#endif
#endif /* __Feeds_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



