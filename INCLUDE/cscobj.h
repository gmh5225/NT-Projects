

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for cscobj.idl:
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

#ifndef __cscobj_h__
#define __cscobj_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOfflineFilesEvents_FWD_DEFINED__
#define __IOfflineFilesEvents_FWD_DEFINED__
typedef interface IOfflineFilesEvents IOfflineFilesEvents;
#endif 	/* __IOfflineFilesEvents_FWD_DEFINED__ */


#ifndef __IOfflineFilesEvents2_FWD_DEFINED__
#define __IOfflineFilesEvents2_FWD_DEFINED__
typedef interface IOfflineFilesEvents2 IOfflineFilesEvents2;
#endif 	/* __IOfflineFilesEvents2_FWD_DEFINED__ */


#ifndef __IOfflineFilesEventsFilter_FWD_DEFINED__
#define __IOfflineFilesEventsFilter_FWD_DEFINED__
typedef interface IOfflineFilesEventsFilter IOfflineFilesEventsFilter;
#endif 	/* __IOfflineFilesEventsFilter_FWD_DEFINED__ */


#ifndef __IOfflineFilesErrorInfo_FWD_DEFINED__
#define __IOfflineFilesErrorInfo_FWD_DEFINED__
typedef interface IOfflineFilesErrorInfo IOfflineFilesErrorInfo;
#endif 	/* __IOfflineFilesErrorInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesSyncErrorItemInfo_FWD_DEFINED__
#define __IOfflineFilesSyncErrorItemInfo_FWD_DEFINED__
typedef interface IOfflineFilesSyncErrorItemInfo IOfflineFilesSyncErrorItemInfo;
#endif 	/* __IOfflineFilesSyncErrorItemInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesSyncErrorInfo_FWD_DEFINED__
#define __IOfflineFilesSyncErrorInfo_FWD_DEFINED__
typedef interface IOfflineFilesSyncErrorInfo IOfflineFilesSyncErrorInfo;
#endif 	/* __IOfflineFilesSyncErrorInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesProgress_FWD_DEFINED__
#define __IOfflineFilesProgress_FWD_DEFINED__
typedef interface IOfflineFilesProgress IOfflineFilesProgress;
#endif 	/* __IOfflineFilesProgress_FWD_DEFINED__ */


#ifndef __IOfflineFilesSimpleProgress_FWD_DEFINED__
#define __IOfflineFilesSimpleProgress_FWD_DEFINED__
typedef interface IOfflineFilesSimpleProgress IOfflineFilesSimpleProgress;
#endif 	/* __IOfflineFilesSimpleProgress_FWD_DEFINED__ */


#ifndef __IOfflineFilesSyncProgress_FWD_DEFINED__
#define __IOfflineFilesSyncProgress_FWD_DEFINED__
typedef interface IOfflineFilesSyncProgress IOfflineFilesSyncProgress;
#endif 	/* __IOfflineFilesSyncProgress_FWD_DEFINED__ */


#ifndef __IOfflineFilesSyncConflictHandler_FWD_DEFINED__
#define __IOfflineFilesSyncConflictHandler_FWD_DEFINED__
typedef interface IOfflineFilesSyncConflictHandler IOfflineFilesSyncConflictHandler;
#endif 	/* __IOfflineFilesSyncConflictHandler_FWD_DEFINED__ */


#ifndef __IOfflineFilesItemFilter_FWD_DEFINED__
#define __IOfflineFilesItemFilter_FWD_DEFINED__
typedef interface IOfflineFilesItemFilter IOfflineFilesItemFilter;
#endif 	/* __IOfflineFilesItemFilter_FWD_DEFINED__ */


#ifndef __IOfflineFilesItem_FWD_DEFINED__
#define __IOfflineFilesItem_FWD_DEFINED__
typedef interface IOfflineFilesItem IOfflineFilesItem;
#endif 	/* __IOfflineFilesItem_FWD_DEFINED__ */


#ifndef __IOfflineFilesServerItem_FWD_DEFINED__
#define __IOfflineFilesServerItem_FWD_DEFINED__
typedef interface IOfflineFilesServerItem IOfflineFilesServerItem;
#endif 	/* __IOfflineFilesServerItem_FWD_DEFINED__ */


#ifndef __IOfflineFilesShareItem_FWD_DEFINED__
#define __IOfflineFilesShareItem_FWD_DEFINED__
typedef interface IOfflineFilesShareItem IOfflineFilesShareItem;
#endif 	/* __IOfflineFilesShareItem_FWD_DEFINED__ */


#ifndef __IOfflineFilesDirectoryItem_FWD_DEFINED__
#define __IOfflineFilesDirectoryItem_FWD_DEFINED__
typedef interface IOfflineFilesDirectoryItem IOfflineFilesDirectoryItem;
#endif 	/* __IOfflineFilesDirectoryItem_FWD_DEFINED__ */


#ifndef __IOfflineFilesFileItem_FWD_DEFINED__
#define __IOfflineFilesFileItem_FWD_DEFINED__
typedef interface IOfflineFilesFileItem IOfflineFilesFileItem;
#endif 	/* __IOfflineFilesFileItem_FWD_DEFINED__ */


#ifndef __IEnumOfflineFilesItems_FWD_DEFINED__
#define __IEnumOfflineFilesItems_FWD_DEFINED__
typedef interface IEnumOfflineFilesItems IEnumOfflineFilesItems;
#endif 	/* __IEnumOfflineFilesItems_FWD_DEFINED__ */


#ifndef __IOfflineFilesItemContainer_FWD_DEFINED__
#define __IOfflineFilesItemContainer_FWD_DEFINED__
typedef interface IOfflineFilesItemContainer IOfflineFilesItemContainer;
#endif 	/* __IOfflineFilesItemContainer_FWD_DEFINED__ */


#ifndef __IOfflineFilesChangeInfo_FWD_DEFINED__
#define __IOfflineFilesChangeInfo_FWD_DEFINED__
typedef interface IOfflineFilesChangeInfo IOfflineFilesChangeInfo;
#endif 	/* __IOfflineFilesChangeInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesFileSysInfo_FWD_DEFINED__
#define __IOfflineFilesFileSysInfo_FWD_DEFINED__
typedef interface IOfflineFilesFileSysInfo IOfflineFilesFileSysInfo;
#endif 	/* __IOfflineFilesFileSysInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesPinInfo_FWD_DEFINED__
#define __IOfflineFilesPinInfo_FWD_DEFINED__
typedef interface IOfflineFilesPinInfo IOfflineFilesPinInfo;
#endif 	/* __IOfflineFilesPinInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesConnectionInfo_FWD_DEFINED__
#define __IOfflineFilesConnectionInfo_FWD_DEFINED__
typedef interface IOfflineFilesConnectionInfo IOfflineFilesConnectionInfo;
#endif 	/* __IOfflineFilesConnectionInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesShareInfo_FWD_DEFINED__
#define __IOfflineFilesShareInfo_FWD_DEFINED__
typedef interface IOfflineFilesShareInfo IOfflineFilesShareInfo;
#endif 	/* __IOfflineFilesShareInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesSuspend_FWD_DEFINED__
#define __IOfflineFilesSuspend_FWD_DEFINED__
typedef interface IOfflineFilesSuspend IOfflineFilesSuspend;
#endif 	/* __IOfflineFilesSuspend_FWD_DEFINED__ */


#ifndef __IOfflineFilesSuspendInfo_FWD_DEFINED__
#define __IOfflineFilesSuspendInfo_FWD_DEFINED__
typedef interface IOfflineFilesSuspendInfo IOfflineFilesSuspendInfo;
#endif 	/* __IOfflineFilesSuspendInfo_FWD_DEFINED__ */


#ifndef __IOfflineFilesSetting_FWD_DEFINED__
#define __IOfflineFilesSetting_FWD_DEFINED__
typedef interface IOfflineFilesSetting IOfflineFilesSetting;
#endif 	/* __IOfflineFilesSetting_FWD_DEFINED__ */


#ifndef __IEnumOfflineFilesSettings_FWD_DEFINED__
#define __IEnumOfflineFilesSettings_FWD_DEFINED__
typedef interface IEnumOfflineFilesSettings IEnumOfflineFilesSettings;
#endif 	/* __IEnumOfflineFilesSettings_FWD_DEFINED__ */


#ifndef __IOfflineFilesCache_FWD_DEFINED__
#define __IOfflineFilesCache_FWD_DEFINED__
typedef interface IOfflineFilesCache IOfflineFilesCache;
#endif 	/* __IOfflineFilesCache_FWD_DEFINED__ */


#ifndef __OfflineFilesSetting_FWD_DEFINED__
#define __OfflineFilesSetting_FWD_DEFINED__

#ifdef __cplusplus
typedef class OfflineFilesSetting OfflineFilesSetting;
#else
typedef struct OfflineFilesSetting OfflineFilesSetting;
#endif /* __cplusplus */

#endif 	/* __OfflineFilesSetting_FWD_DEFINED__ */


#ifndef __OfflineFilesCache_FWD_DEFINED__
#define __OfflineFilesCache_FWD_DEFINED__

#ifdef __cplusplus
typedef class OfflineFilesCache OfflineFilesCache;
#else
typedef struct OfflineFilesCache OfflineFilesCache;
#endif /* __cplusplus */

#endif 	/* __OfflineFilesCache_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_cscobj_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright Microsoft Corporation. All Rights Reserved.
//
//--------------------------------------------------------------------------
//
typedef 
enum tagOFFLINEFILES_ITEM_TYPE
    {	OFFLINEFILES_ITEM_TYPE_FILE	= 0,
	OFFLINEFILES_ITEM_TYPE_DIRECTORY	= ( OFFLINEFILES_ITEM_TYPE_FILE + 1 ) ,
	OFFLINEFILES_ITEM_TYPE_SHARE	= ( OFFLINEFILES_ITEM_TYPE_DIRECTORY + 1 ) ,
	OFFLINEFILES_ITEM_TYPE_SERVER	= ( OFFLINEFILES_ITEM_TYPE_SHARE + 1 ) 
    } 	OFFLINEFILES_ITEM_TYPE;

typedef 
enum tagOFFLINEFILES_ITEM_COPY
    {	OFFLINEFILES_ITEM_COPY_LOCAL	= 0,
	OFFLINEFILES_ITEM_COPY_REMOTE	= ( OFFLINEFILES_ITEM_COPY_LOCAL + 1 ) ,
	OFFLINEFILES_ITEM_COPY_ORIGINAL	= ( OFFLINEFILES_ITEM_COPY_REMOTE + 1 ) 
    } 	OFFLINEFILES_ITEM_COPY;

typedef 
enum tagOFFLINEFILES_CONNECT_STATE
    {	OFFLINEFILES_CONNECT_STATE_UNKNOWN	= 0,
	OFFLINEFILES_CONNECT_STATE_OFFLINE	= ( OFFLINEFILES_CONNECT_STATE_UNKNOWN + 1 ) ,
	OFFLINEFILES_CONNECT_STATE_ONLINE	= ( OFFLINEFILES_CONNECT_STATE_OFFLINE + 1 ) 
    } 	OFFLINEFILES_CONNECT_STATE;

typedef 
enum tagOFFLINEFILES_OFFLINE_REASON
    {	OFFLINEFILES_OFFLINE_REASON_UNKNOWN	= 0,
	OFFLINEFILES_OFFLINE_REASON_NOT_APPLICABLE	= ( OFFLINEFILES_OFFLINE_REASON_UNKNOWN + 1 ) ,
	OFFLINEFILES_OFFLINE_REASON_CONNECTION_FORCED	= ( OFFLINEFILES_OFFLINE_REASON_NOT_APPLICABLE + 1 ) ,
	OFFLINEFILES_OFFLINE_REASON_CONNECTION_SLOW	= ( OFFLINEFILES_OFFLINE_REASON_CONNECTION_FORCED + 1 ) ,
	OFFLINEFILES_OFFLINE_REASON_CONNECTION_ERROR	= ( OFFLINEFILES_OFFLINE_REASON_CONNECTION_SLOW + 1 ) ,
	OFFLINEFILES_OFFLINE_REASON_ITEM_VERSION_CONFLICT	= ( OFFLINEFILES_OFFLINE_REASON_CONNECTION_ERROR + 1 ) ,
	OFFLINEFILES_OFFLINE_REASON_ITEM_SUSPENDED	= ( OFFLINEFILES_OFFLINE_REASON_ITEM_VERSION_CONFLICT + 1 ) 
    } 	OFFLINEFILES_OFFLINE_REASON;

typedef 
enum tagOFFLINEFILES_CACHING_MODE
    {	OFFLINEFILES_CACHING_MODE_NONE	= 0,
	OFFLINEFILES_CACHING_MODE_NOCACHING	= ( OFFLINEFILES_CACHING_MODE_NONE + 1 ) ,
	OFFLINEFILES_CACHING_MODE_MANUAL	= ( OFFLINEFILES_CACHING_MODE_NOCACHING + 1 ) ,
	OFFLINEFILES_CACHING_MODE_AUTO_DOC	= ( OFFLINEFILES_CACHING_MODE_MANUAL + 1 ) ,
	OFFLINEFILES_CACHING_MODE_AUTO_PROGANDDOC	= ( OFFLINEFILES_CACHING_MODE_AUTO_DOC + 1 ) 
    } 	OFFLINEFILES_CACHING_MODE;

typedef 
enum tagOFFLINEFILES_OP_RESPONSE
    {	OFFLINEFILES_OP_CONTINUE	= 0,
	OFFLINEFILES_OP_RETRY	= ( OFFLINEFILES_OP_CONTINUE + 1 ) ,
	OFFLINEFILES_OP_ABORT	= ( OFFLINEFILES_OP_RETRY + 1 ) 
    } 	OFFLINEFILES_OP_RESPONSE;

typedef 
enum tagOFFLINEFILES_EVENTS
    {	OFFLINEFILES_EVENT_CACHEMOVED	= 0,
	OFFLINEFILES_EVENT_CACHEISFULL	= ( OFFLINEFILES_EVENT_CACHEMOVED + 1 ) ,
	OFFLINEFILES_EVENT_CACHEISCORRUPTED	= ( OFFLINEFILES_EVENT_CACHEISFULL + 1 ) ,
	OFFLINEFILES_EVENT_ENABLED	= ( OFFLINEFILES_EVENT_CACHEISCORRUPTED + 1 ) ,
	OFFLINEFILES_EVENT_ENCRYPTIONCHANGED	= ( OFFLINEFILES_EVENT_ENABLED + 1 ) ,
	OFFLINEFILES_EVENT_SYNCBEGIN	= ( OFFLINEFILES_EVENT_ENCRYPTIONCHANGED + 1 ) ,
	OFFLINEFILES_EVENT_SYNCFILERESULT	= ( OFFLINEFILES_EVENT_SYNCBEGIN + 1 ) ,
	OFFLINEFILES_EVENT_SYNCCONFLICTRECADDED	= ( OFFLINEFILES_EVENT_SYNCFILERESULT + 1 ) ,
	OFFLINEFILES_EVENT_SYNCCONFLICTRECUPDATED	= ( OFFLINEFILES_EVENT_SYNCCONFLICTRECADDED + 1 ) ,
	OFFLINEFILES_EVENT_SYNCCONFLICTRECREMOVED	= ( OFFLINEFILES_EVENT_SYNCCONFLICTRECUPDATED + 1 ) ,
	OFFLINEFILES_EVENT_SYNCEND	= ( OFFLINEFILES_EVENT_SYNCCONFLICTRECREMOVED + 1 ) ,
	OFFLINEFILES_EVENT_BACKGROUNDSYNCBEGIN	= ( OFFLINEFILES_EVENT_SYNCEND + 1 ) ,
	OFFLINEFILES_EVENT_BACKGROUNDSYNCEND	= ( OFFLINEFILES_EVENT_BACKGROUNDSYNCBEGIN + 1 ) ,
	OFFLINEFILES_EVENT_NETTRANSPORTARRIVED	= ( OFFLINEFILES_EVENT_BACKGROUNDSYNCEND + 1 ) ,
	OFFLINEFILES_EVENT_NONETTRANSPORTS	= ( OFFLINEFILES_EVENT_NETTRANSPORTARRIVED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMDISCONNECTED	= ( OFFLINEFILES_EVENT_NONETTRANSPORTS + 1 ) ,
	OFFLINEFILES_EVENT_ITEMRECONNECTED	= ( OFFLINEFILES_EVENT_ITEMDISCONNECTED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMAVAILABLEOFFLINE	= ( OFFLINEFILES_EVENT_ITEMRECONNECTED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMNOTAVAILABLEOFFLINE	= ( OFFLINEFILES_EVENT_ITEMAVAILABLEOFFLINE + 1 ) ,
	OFFLINEFILES_EVENT_ITEMPINNED	= ( OFFLINEFILES_EVENT_ITEMNOTAVAILABLEOFFLINE + 1 ) ,
	OFFLINEFILES_EVENT_ITEMNOTPINNED	= ( OFFLINEFILES_EVENT_ITEMPINNED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMMODIFIED	= ( OFFLINEFILES_EVENT_ITEMNOTPINNED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMADDEDTOCACHE	= ( OFFLINEFILES_EVENT_ITEMMODIFIED + 1 ) ,
	OFFLINEFILES_EVENT_ITEMDELETEDFROMCACHE	= ( OFFLINEFILES_EVENT_ITEMADDEDTOCACHE + 1 ) ,
	OFFLINEFILES_EVENT_ITEMRENAMED	= ( OFFLINEFILES_EVENT_ITEMDELETEDFROMCACHE + 1 ) ,
	OFFLINEFILES_EVENT_DATALOST	= ( OFFLINEFILES_EVENT_ITEMRENAMED + 1 ) ,
	OFFLINEFILES_EVENT_PING	= ( OFFLINEFILES_EVENT_DATALOST + 1 ) ,
	OFFLINEFILES_EVENT_ITEMRECONNECTBEGIN	= ( OFFLINEFILES_EVENT_PING + 1 ) ,
	OFFLINEFILES_EVENT_ITEMRECONNECTEND	= ( OFFLINEFILES_EVENT_ITEMRECONNECTBEGIN + 1 ) ,
	OFFLINEFILES_EVENT_CACHEEVICTBEGIN	= ( OFFLINEFILES_EVENT_ITEMRECONNECTEND + 1 ) ,
	OFFLINEFILES_EVENT_CACHEEVICTEND	= ( OFFLINEFILES_EVENT_CACHEEVICTBEGIN + 1 ) ,
	OFFLINEFILES_EVENT_POLICYCHANGEDETECTED	= ( OFFLINEFILES_EVENT_CACHEEVICTEND + 1 ) ,
	OFFLINEFILES_EVENT_PREFERENCECHANGEDETECTED	= ( OFFLINEFILES_EVENT_POLICYCHANGEDETECTED + 1 ) ,
	OFFLINEFILES_EVENT_SETTINGSCHANGESAPPLIED	= ( OFFLINEFILES_EVENT_PREFERENCECHANGEDETECTED + 1 ) ,
	OFFLINEFILES_NUM_EVENTS	= ( OFFLINEFILES_EVENT_SETTINGSCHANGESAPPLIED + 1 ) 
    } 	OFFLINEFILES_EVENTS;

typedef 
enum tagOFFLINEFILES_PATHFILTER_MATCH
    {	OFFLINEFILES_PATHFILTER_SELF	= 0,
	OFFLINEFILES_PATHFILTER_CHILD	= ( OFFLINEFILES_PATHFILTER_SELF + 1 ) ,
	OFFLINEFILES_PATHFILTER_DESCENDENT	= ( OFFLINEFILES_PATHFILTER_CHILD + 1 ) ,
	OFFLINEFILES_PATHFILTER_SELFORCHILD	= ( OFFLINEFILES_PATHFILTER_DESCENDENT + 1 ) ,
	OFFLINEFILES_PATHFILTER_SELFORDESCENDENT	= ( OFFLINEFILES_PATHFILTER_SELFORCHILD + 1 ) 
    } 	OFFLINEFILES_PATHFILTER_MATCH;

#define	OFFLINEFILES_SYNC_STATE_LOCAL_KNOWN	( 0x1 )

#define	OFFLINEFILES_SYNC_STATE_REMOTE_KNOWN	( 0x2 )

#define	OFFLINEFILES_CHANGES_NONE	( 0 )

#define	OFFLINEFILES_CHANGES_LOCAL_SIZE	( 0x1 )

#define	OFFLINEFILES_CHANGES_LOCAL_ATTRIBUTES	( 0x2 )

#define	OFFLINEFILES_CHANGES_LOCAL_TIME	( 0x4 )

#define	OFFLINEFILES_CHANGES_REMOTE_SIZE	( 0x8 )

#define	OFFLINEFILES_CHANGES_REMOTE_ATTRIBUTES	( 0x10 )

#define	OFFLINEFILES_CHANGES_REMOTE_TIME	( 0x20 )

typedef 
enum tagOFFLINEFILES_SYNC_CONFLICT_RESOLVE
    {	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NONE	= 0,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLOCAL	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NONE + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPREMOTE	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLOCAL + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPREMOTE + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLATEST	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPALLCHANGES + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LOG	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_KEEPLATEST + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_SKIP	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LOG + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_ABORT	= ( OFFLINEFILES_SYNC_CONFLICT_RESOLVE_SKIP + 1 ) ,
	OFFLINEFILES_SYNC_CONFLICT_RESOLVE_NUMCODES	= ( OFFLINEFILES_SYNC_CONFLICT_ABORT + 1 ) 
    } 	OFFLINEFILES_SYNC_CONFLICT_RESOLVE;

#define OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LATER OFFLINEFILES_SYNC_CONFLICT_RESOLVE_LOG
#define	OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_DATA	( 0x1 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_ATTRIBUTES	( 0x2 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED	( 0x4 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_CREATED	( 0x8 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_DELETED	( 0x10 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_DIRTY	( 0x20 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_SPARSE	( 0x40 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_FILE	( 0x80 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_DIRECTORY	( 0x100 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_USER	( 0x200 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_OTHERS	( 0x400 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_COMPUTER	( 0x800 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_PINNED	( 0x1000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_GHOST	( 0x2000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_SUSPENDED	( 0x4000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_OFFLINE	( 0x8000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_ONLINE	( 0x10000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_USER_WRITE	( 0x20000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_USER_READ	( 0x40000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_USER_ANYACCESS	( 0x80000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_WRITE	( 0x100000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_READ	( 0x200000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_ANYACCESS	( 0x400000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_WRITE	( 0x800000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_READ	( 0x1000000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_ANYACCESS	( 0x2000000 )

#define	OFFLINEFILES_ITEM_FILTER_FLAGS	( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_DATA | OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_ATTRIBUTES )  | OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED )  | OFFLINEFILES_ITEM_FILTER_FLAG_CREATED )  | OFFLINEFILES_ITEM_FILTER_FLAG_DELETED )  | OFFLINEFILES_ITEM_FILTER_FLAG_DIRTY )  | OFFLINEFILES_ITEM_FILTER_FLAG_SPARSE )  | OFFLINEFILES_ITEM_FILTER_FLAG_FILE )  | OFFLINEFILES_ITEM_FILTER_FLAG_DIRECTORY )  | OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_USER )  | OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_OTHERS )  | OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_COMPUTER )  | OFFLINEFILES_ITEM_FILTER_FLAG_PINNED )  | OFFLINEFILES_ITEM_FILTER_FLAG_GHOST )  | OFFLINEFILES_ITEM_FILTER_FLAG_SUSPENDED )  | OFFLINEFILES_ITEM_FILTER_FLAG_OFFLINE )  | OFFLINEFILES_ITEM_FILTER_FLAG_ONLINE )  | OFFLINEFILES_ITEM_FILTER_FLAG_USER_WRITE )  | OFFLINEFILES_ITEM_FILTER_FLAG_USER_READ )  | OFFLINEFILES_ITEM_FILTER_FLAG_USER_ANYACCESS )  | OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_WRITE )  | OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_READ )  | OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_ANYACCESS )  | OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_WRITE )  | OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_READ )  | OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_ANYACCESS )  )

typedef 
enum tagOFFLINEFILES_ITEM_TIME
    {	OFFLINEFILES_ITEM_TIME_CREATION	= 0,
	OFFLINEFILES_ITEM_TIME_LASTACCESS	= ( OFFLINEFILES_ITEM_TIME_CREATION + 1 ) ,
	OFFLINEFILES_ITEM_TIME_LASTWRITE	= ( OFFLINEFILES_ITEM_TIME_LASTACCESS + 1 ) 
    } 	OFFLINEFILES_ITEM_TIME;

typedef 
enum tagOFFLINEFILES_COMPARE
    {	OFFLINEFILES_COMPARE_EQ	= 0,
	OFFLINEFILES_COMPARE_NEQ	= ( OFFLINEFILES_COMPARE_EQ + 1 ) ,
	OFFLINEFILES_COMPARE_LT	= ( OFFLINEFILES_COMPARE_NEQ + 1 ) ,
	OFFLINEFILES_COMPARE_GT	= ( OFFLINEFILES_COMPARE_LT + 1 ) ,
	OFFLINEFILES_COMPARE_LTE	= ( OFFLINEFILES_COMPARE_GT + 1 ) ,
	OFFLINEFILES_COMPARE_GTE	= ( OFFLINEFILES_COMPARE_LTE + 1 ) 
    } 	OFFLINEFILES_COMPARE;

#define	OFFLINEFILES_ITEM_QUERY_REMOTEINFO	( 0x1 )

#define	OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE	( 0x2 )

#define	OFFLINEFILES_ITEM_QUERY_ADMIN	( 0x80000000 )

#define	OFFLINEFILES_ITEM_QUERY_FLAGS	( ( ( OFFLINEFILES_ITEM_QUERY_REMOTEINFO | OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE )  | OFFLINEFILES_ITEM_QUERY_ADMIN )  )

#define	OFFLINEFILES_ENUM_FLAT	( 0x1 )

#define	OFFLINEFILES_ENUM_FLAT_FILESONLY	( 0x2 )

#define	OFFLINEFILES_ENUM_FLAGS	( ( OFFLINEFILES_ENUM_FLAT | OFFLINEFILES_ENUM_FLAT_FILESONLY )  )

#define	OFFLINEFILES_SETTING_SCOPE_USER	( 0x1 )

#define	OFFLINEFILES_SETTING_SCOPE_COMPUTER	( 0x2 )

typedef 
enum tagOFFLINEFILES_SETTING_VALUE_TYPE
    {	OFFLINEFILES_SETTING_VALUE_UI4	= 0,
	OFFLINEFILES_SETTING_VALUE_BSTR	= ( OFFLINEFILES_SETTING_VALUE_UI4 + 1 ) ,
	OFFLINEFILES_SETTING_VALUE_BSTR_DBLNULTERM	= ( OFFLINEFILES_SETTING_VALUE_BSTR + 1 ) ,
	OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_UI4	= ( OFFLINEFILES_SETTING_VALUE_BSTR_DBLNULTERM + 1 ) ,
	OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_BSTR	= ( OFFLINEFILES_SETTING_VALUE_2DIM_ARRAY_BSTR_UI4 + 1 ) 
    } 	OFFLINEFILES_SETTING_VALUE_TYPE;

#define OFFLINEFILES_SETTING_PinLinkTargets   L"PinLinkTargets"
#define	OFFLINEFILES_PINLINKTARGETS_NEVER	( 0 )

#define	OFFLINEFILES_PINLINKTARGETS_EXPLICIT	( 1 )

#define	OFFLINEFILES_PINLINKTARGETS_ALWAYS	( 2 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE	( 0x1 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCIN	( 0x2 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT	( 0x4 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES	( 0x8 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINLINKTARGETS	( 0x10 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER	( 0x20 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER_POLICY	( 0x40 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORALL	( 0x80 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORREDIR	( 0x100 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY	( 0x200 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS	( 0x400 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE	( 0x800 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE	( 0x1000 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_SKIPSUSPENDEDDIRS	( 0x2000 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND	( 0x10000 )

#define	OFFLINEFILES_SYNC_CONTROL_CR_MASK	( 0xf0000000 )

#define	OFFLINEFILES_SYNC_CONTROL_CR_DEFAULT	( 0 )

#define	OFFLINEFILES_SYNC_CONTROL_CR_KEEPLOCAL	( 0x10000000 )

#define	OFFLINEFILES_SYNC_CONTROL_CR_KEEPREMOTE	( 0x20000000 )

#define	OFFLINEFILES_SYNC_CONTROL_CR_KEEPLATEST	( 0x30000000 )

#define	OFFLINEFILES_SYNC_CONTROL_FLAGS	( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE | OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCIN )  | OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINLINKTARGETS )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER_POLICY )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORALL )  | OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORREDIR )  | OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY )  | OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS )  | OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE )  | OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE )  | OFFLINEFILES_SYNC_CONTROL_FLAG_SKIPSUSPENDEDDIRS )  | OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND )  | OFFLINEFILES_SYNC_CONTROL_CR_KEEPLOCAL )  | OFFLINEFILES_SYNC_CONTROL_CR_KEEPREMOTE )  | OFFLINEFILES_SYNC_CONTROL_CR_KEEPLATEST )  )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER	( OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER_POLICY	( OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER_POLICY )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_FORALL	( OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORALL )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_FORREDIR	( OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORREDIR )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_FILL	( OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_LOWPRIORITY	( OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_ASYNCPROGRESS	( OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_INTERACTIVE	( OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_CONSOLE	( OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_PINLINKTARGETS	( OFFLINEFILES_SYNC_CONTROL_FLAG_PINLINKTARGETS )

#define	OFFLINEFILES_PIN_CONTROL_FLAG_BACKGROUND	( OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND )

#define	OFFLINEFILES_PIN_CONTROL_FLAGS	( ( ( ( ( ( ( ( ( ( ( OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER | OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER_POLICY )  | OFFLINEFILES_PIN_CONTROL_FLAG_FORALL )  | OFFLINEFILES_PIN_CONTROL_FLAG_FORREDIR )  | OFFLINEFILES_PIN_CONTROL_FLAG_FILL )  | OFFLINEFILES_PIN_CONTROL_FLAG_LOWPRIORITY )  | OFFLINEFILES_PIN_CONTROL_FLAG_ASYNCPROGRESS )  | OFFLINEFILES_PIN_CONTROL_FLAG_INTERACTIVE )  | OFFLINEFILES_PIN_CONTROL_FLAG_CONSOLE )  | OFFLINEFILES_PIN_CONTROL_FLAG_PINLINKTARGETS )  | OFFLINEFILES_PIN_CONTROL_FLAG_BACKGROUND )  )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_LOWPRIORITY	( OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_ASYNCPROGRESS	( OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE	( OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_CONSOLE	( OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_BACKGROUND	( OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND )

#define	OFFLINEFILES_ENCRYPTION_CONTROL_FLAGS	( ( ( ( ( OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_LOWPRIORITY | OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_ASYNCPROGRESS )  | OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_INTERACTIVE )  | OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_CONSOLE )  | OFFLINEFILES_ENCRYPTION_CONTROL_FLAG_BACKGROUND )  )

#define	OFFLINEFILES_DELETE_FLAG_NOAUTOCACHED	( 0x1 )

#define	OFFLINEFILES_DELETE_FLAG_NOPINNED	( 0x2 )

#define	OFFLINEFILES_DELETE_FLAG_DELMODIFIED	( 0x4 )

#define	OFFLINEFILES_DELETE_FLAG_ADMIN	( 0x80000000 )

#define	OFFLINEFILES_DELETE_FLAGS	( ( ( ( OFFLINEFILES_DELETE_FLAG_NOAUTOCACHED | OFFLINEFILES_DELETE_FLAG_NOPINNED )  | OFFLINEFILES_DELETE_FLAG_DELMODIFIED )  | OFFLINEFILES_DELETE_FLAG_ADMIN )  )

#define	OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE	( 0x1 )

#define	OFFLINEFILES_TRANSITION_FLAG_CONSOLE	( 0x2 )

#define	OFFLINEFILES_TRANSITION_FLAGS	( ( OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE | OFFLINEFILES_TRANSITION_FLAG_CONSOLE )  )

typedef 
enum tagOFFLINEFILES_SYNC_OPERATION
    {	OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_SERVER	= 0,
	OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_CLIENT	= ( OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_SERVER + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_SYNC_TO_SERVER	= ( OFFLINEFILES_SYNC_OPERATION_CREATE_COPY_ON_CLIENT + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_SYNC_TO_CLIENT	= ( OFFLINEFILES_SYNC_OPERATION_SYNC_TO_SERVER + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_DELETE_SERVER_COPY	= ( OFFLINEFILES_SYNC_OPERATION_SYNC_TO_CLIENT + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_DELETE_CLIENT_COPY	= ( OFFLINEFILES_SYNC_OPERATION_DELETE_SERVER_COPY + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_PIN	= ( OFFLINEFILES_SYNC_OPERATION_DELETE_CLIENT_COPY + 1 ) ,
	OFFLINEFILES_SYNC_OPERATION_PREPARE	= ( OFFLINEFILES_SYNC_OPERATION_PIN + 1 ) 
    } 	OFFLINEFILES_SYNC_OPERATION;

#define	OFFLINEFILES_SYNC_ITEM_CHANGE_NONE	( 0 )

#define	OFFLINEFILES_SYNC_ITEM_CHANGE_CHANGETIME	( 0x1 )

#define	OFFLINEFILES_SYNC_ITEM_CHANGE_WRITETIME	( 0x2 )

#define	OFFLINEFILES_SYNC_ITEM_CHANGE_FILESIZE	( 0x4 )

#define	OFFLINEFILES_SYNC_ITEM_CHANGE_ATTRIBUTES	( 0x8 )

typedef 
enum tagOFFLINEFILES_SYNC_STATE
    {	OFFLINEFILES_SYNC_STATE_Stable	= 0,
	OFFLINEFILES_SYNC_STATE_FileOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_Stable + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileOnClient_NoServerCopy	= ( OFFLINEFILES_SYNC_STATE_FileOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_FileOnClient_NoServerCopy + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirOnClient_NoServerCopy	= ( OFFLINEFILES_SYNC_STATE_DirOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_NoServerCopy	= ( OFFLINEFILES_SYNC_STATE_DirOnClient_NoServerCopy + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_NoServerCopy + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileCreatedOnClient_DeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnClient_ChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileSparseOnClient_ChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnClient_DeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileSparseOnClient_ChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_NoServerCopy	= ( OFFLINEFILES_SYNC_STATE_FileSparseOnClient_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_NoServerCopy + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_DirCreatedOnClient_DeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnClient_ChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnClient_DeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnClient_ChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_NoClientCopy_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnClient_DeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_NoClientCopy_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_NoClientCopy_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_NoClientCopy_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_NoClientCopy_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_NoClientCopy_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_NoClientCopy_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_NoClientCopy_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DeletedOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileSparseOnClient	= ( OFFLINEFILES_SYNC_STATE_DeletedOnClient_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnClient	= ( OFFLINEFILES_SYNC_STATE_FileSparseOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileRenamedOnClient	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirSparseOnClient	= ( OFFLINEFILES_SYNC_STATE_FileRenamedOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnClient	= ( OFFLINEFILES_SYNC_STATE_DirSparseOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirRenamedOnClient	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirRenamedOnClient + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileRenamedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileDeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileRenamedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileDeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirRenamedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_DirDeletedOnServer	= ( OFFLINEFILES_SYNC_STATE_DirRenamedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileOnServer	= ( OFFLINEFILES_SYNC_STATE_DirDeletedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirOnServer	= ( OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_FileChangedOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirChangedOnServer	= ( OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirOnServer + 1 ) ,
	OFFLINEFILES_SYNC_STATE_NUMSTATES	= ( OFFLINEFILES_SYNC_STATE_FileReplacedAndDeletedOnClient_DirChangedOnServer + 1 ) 
    } 	OFFLINEFILES_SYNC_STATE;



extern RPC_IF_HANDLE __MIDL_itf_cscobj_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_cscobj_0000_0000_v0_0_s_ifspec;

#ifndef __IOfflineFilesEvents_INTERFACE_DEFINED__
#define __IOfflineFilesEvents_INTERFACE_DEFINED__

/* interface IOfflineFilesEvents */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E25585C1-0CAA-4eb1-873B-1CAE5B77C314")
    IOfflineFilesEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CacheMoved( 
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CacheIsFull( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CacheIsCorrupted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enabled( 
            /* [in] */ BOOL bEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EncryptionChanged( 
            /* [in] */ BOOL bWasEncrypted,
            /* [in] */ BOOL bWasPartial,
            /* [in] */ BOOL bIsEncrypted,
            /* [in] */ BOOL bIsPartial) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncBegin( 
            /* [in] */ __RPC__in REFGUID rSyncId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncFileResult( 
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncConflictRecAdded( 
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncConflictRecUpdated( 
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncConflictRecRemoved( 
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncEnd( 
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [in] */ HRESULT hrResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NetTransportArrived( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NoNetTransports( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemDisconnected( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemReconnected( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemAvailableOffline( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemNotAvailableOffline( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemPinned( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemNotPinned( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemModified( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType,
            /* [in] */ BOOL bModifiedData,
            /* [in] */ BOOL bModifiedAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemAddedToCache( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemDeletedFromCache( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemRenamed( 
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataLost( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Ping( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheMoved )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath);
        
        HRESULT ( STDMETHODCALLTYPE *CacheIsFull )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheIsCorrupted )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Enabled )( 
            IOfflineFilesEvents * This,
            /* [in] */ BOOL bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *EncryptionChanged )( 
            IOfflineFilesEvents * This,
            /* [in] */ BOOL bWasEncrypted,
            /* [in] */ BOOL bWasPartial,
            /* [in] */ BOOL bIsEncrypted,
            /* [in] */ BOOL bIsPartial);
        
        HRESULT ( STDMETHODCALLTYPE *SyncBegin )( 
            IOfflineFilesEvents * This,
            /* [in] */ __RPC__in REFGUID rSyncId);
        
        HRESULT ( STDMETHODCALLTYPE *SyncFileResult )( 
            IOfflineFilesEvents * This,
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecAdded )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecUpdated )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecRemoved )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncEnd )( 
            IOfflineFilesEvents * This,
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *NetTransportArrived )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *NoNetTransports )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *ItemDisconnected )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemReconnected )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemAvailableOffline )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemNotAvailableOffline )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemPinned )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemNotPinned )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemModified )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType,
            /* [in] */ BOOL bModifiedData,
            /* [in] */ BOOL bModifiedAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *ItemAddedToCache )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemDeletedFromCache )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemRenamed )( 
            IOfflineFilesEvents * This,
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *DataLost )( 
            IOfflineFilesEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *Ping )( 
            IOfflineFilesEvents * This);
        
        END_INTERFACE
    } IOfflineFilesEventsVtbl;

    interface IOfflineFilesEvents
    {
        CONST_VTBL struct IOfflineFilesEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesEvents_CacheMoved(This,pszOldPath,pszNewPath)	\
    ( (This)->lpVtbl -> CacheMoved(This,pszOldPath,pszNewPath) ) 

#define IOfflineFilesEvents_CacheIsFull(This)	\
    ( (This)->lpVtbl -> CacheIsFull(This) ) 

#define IOfflineFilesEvents_CacheIsCorrupted(This)	\
    ( (This)->lpVtbl -> CacheIsCorrupted(This) ) 

#define IOfflineFilesEvents_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> Enabled(This,bEnabled) ) 

#define IOfflineFilesEvents_EncryptionChanged(This,bWasEncrypted,bWasPartial,bIsEncrypted,bIsPartial)	\
    ( (This)->lpVtbl -> EncryptionChanged(This,bWasEncrypted,bWasPartial,bIsEncrypted,bIsPartial) ) 

#define IOfflineFilesEvents_SyncBegin(This,rSyncId)	\
    ( (This)->lpVtbl -> SyncBegin(This,rSyncId) ) 

#define IOfflineFilesEvents_SyncFileResult(This,rSyncId,pszFile,hrResult)	\
    ( (This)->lpVtbl -> SyncFileResult(This,rSyncId,pszFile,hrResult) ) 

#define IOfflineFilesEvents_SyncConflictRecAdded(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecAdded(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents_SyncConflictRecUpdated(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecUpdated(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents_SyncConflictRecRemoved(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecRemoved(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents_SyncEnd(This,rSyncId,hrResult)	\
    ( (This)->lpVtbl -> SyncEnd(This,rSyncId,hrResult) ) 

#define IOfflineFilesEvents_NetTransportArrived(This)	\
    ( (This)->lpVtbl -> NetTransportArrived(This) ) 

#define IOfflineFilesEvents_NoNetTransports(This)	\
    ( (This)->lpVtbl -> NoNetTransports(This) ) 

#define IOfflineFilesEvents_ItemDisconnected(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemDisconnected(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemReconnected(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemReconnected(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemAvailableOffline(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemAvailableOffline(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemNotAvailableOffline(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemNotAvailableOffline(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemPinned(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemPinned(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemNotPinned(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemNotPinned(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemModified(This,pszPath,ItemType,bModifiedData,bModifiedAttributes)	\
    ( (This)->lpVtbl -> ItemModified(This,pszPath,ItemType,bModifiedData,bModifiedAttributes) ) 

#define IOfflineFilesEvents_ItemAddedToCache(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemAddedToCache(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemDeletedFromCache(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemDeletedFromCache(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents_ItemRenamed(This,pszOldPath,pszNewPath,ItemType)	\
    ( (This)->lpVtbl -> ItemRenamed(This,pszOldPath,pszNewPath,ItemType) ) 

#define IOfflineFilesEvents_DataLost(This)	\
    ( (This)->lpVtbl -> DataLost(This) ) 

#define IOfflineFilesEvents_Ping(This)	\
    ( (This)->lpVtbl -> Ping(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesEvents_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesEvents2_INTERFACE_DEFINED__
#define __IOfflineFilesEvents2_INTERFACE_DEFINED__

/* interface IOfflineFilesEvents2 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesEvents2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1EAD8F56-FF76-4faa-A795-6F6EF792498B")
    IOfflineFilesEvents2 : public IOfflineFilesEvents
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ItemReconnectBegin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemReconnectEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CacheEvictBegin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CacheEvictEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSyncBegin( 
            /* [in] */ DWORD dwSyncControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackgroundSyncEnd( 
            /* [in] */ DWORD dwSyncControlFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PolicyChangeDetected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PreferenceChangeDetected( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SettingsChangesApplied( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesEvents2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesEvents2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheMoved )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath);
        
        HRESULT ( STDMETHODCALLTYPE *CacheIsFull )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheIsCorrupted )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Enabled )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ BOOL bEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *EncryptionChanged )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ BOOL bWasEncrypted,
            /* [in] */ BOOL bWasPartial,
            /* [in] */ BOOL bIsEncrypted,
            /* [in] */ BOOL bIsPartial);
        
        HRESULT ( STDMETHODCALLTYPE *SyncBegin )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ __RPC__in REFGUID rSyncId);
        
        HRESULT ( STDMETHODCALLTYPE *SyncFileResult )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecAdded )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecUpdated )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncConflictRecRemoved )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszConflictPath,
            /* [in] */ __RPC__in const FILETIME *pftConflictDateTime,
            /* [in] */ OFFLINEFILES_SYNC_STATE ConflictSyncState);
        
        HRESULT ( STDMETHODCALLTYPE *SyncEnd )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ __RPC__in REFGUID rSyncId,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *NetTransportArrived )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *NoNetTransports )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ItemDisconnected )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemReconnected )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemAvailableOffline )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemNotAvailableOffline )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemPinned )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemNotPinned )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemModified )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType,
            /* [in] */ BOOL bModifiedData,
            /* [in] */ BOOL bModifiedAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *ItemAddedToCache )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemDeletedFromCache )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *ItemRenamed )( 
            IOfflineFilesEvents2 * This,
            /* [string][in] */ __RPC__in LPCWSTR pszOldPath,
            /* [string][in] */ __RPC__in LPCWSTR pszNewPath,
            /* [in] */ OFFLINEFILES_ITEM_TYPE ItemType);
        
        HRESULT ( STDMETHODCALLTYPE *DataLost )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Ping )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ItemReconnectBegin )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ItemReconnectEnd )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheEvictBegin )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CacheEvictEnd )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSyncBegin )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ DWORD dwSyncControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *BackgroundSyncEnd )( 
            IOfflineFilesEvents2 * This,
            /* [in] */ DWORD dwSyncControlFlags);
        
        HRESULT ( STDMETHODCALLTYPE *PolicyChangeDetected )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreferenceChangeDetected )( 
            IOfflineFilesEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SettingsChangesApplied )( 
            IOfflineFilesEvents2 * This);
        
        END_INTERFACE
    } IOfflineFilesEvents2Vtbl;

    interface IOfflineFilesEvents2
    {
        CONST_VTBL struct IOfflineFilesEvents2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesEvents2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesEvents2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesEvents2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesEvents2_CacheMoved(This,pszOldPath,pszNewPath)	\
    ( (This)->lpVtbl -> CacheMoved(This,pszOldPath,pszNewPath) ) 

#define IOfflineFilesEvents2_CacheIsFull(This)	\
    ( (This)->lpVtbl -> CacheIsFull(This) ) 

#define IOfflineFilesEvents2_CacheIsCorrupted(This)	\
    ( (This)->lpVtbl -> CacheIsCorrupted(This) ) 

#define IOfflineFilesEvents2_Enabled(This,bEnabled)	\
    ( (This)->lpVtbl -> Enabled(This,bEnabled) ) 

#define IOfflineFilesEvents2_EncryptionChanged(This,bWasEncrypted,bWasPartial,bIsEncrypted,bIsPartial)	\
    ( (This)->lpVtbl -> EncryptionChanged(This,bWasEncrypted,bWasPartial,bIsEncrypted,bIsPartial) ) 

#define IOfflineFilesEvents2_SyncBegin(This,rSyncId)	\
    ( (This)->lpVtbl -> SyncBegin(This,rSyncId) ) 

#define IOfflineFilesEvents2_SyncFileResult(This,rSyncId,pszFile,hrResult)	\
    ( (This)->lpVtbl -> SyncFileResult(This,rSyncId,pszFile,hrResult) ) 

#define IOfflineFilesEvents2_SyncConflictRecAdded(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecAdded(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents2_SyncConflictRecUpdated(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecUpdated(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents2_SyncConflictRecRemoved(This,pszConflictPath,pftConflictDateTime,ConflictSyncState)	\
    ( (This)->lpVtbl -> SyncConflictRecRemoved(This,pszConflictPath,pftConflictDateTime,ConflictSyncState) ) 

#define IOfflineFilesEvents2_SyncEnd(This,rSyncId,hrResult)	\
    ( (This)->lpVtbl -> SyncEnd(This,rSyncId,hrResult) ) 

#define IOfflineFilesEvents2_NetTransportArrived(This)	\
    ( (This)->lpVtbl -> NetTransportArrived(This) ) 

#define IOfflineFilesEvents2_NoNetTransports(This)	\
    ( (This)->lpVtbl -> NoNetTransports(This) ) 

#define IOfflineFilesEvents2_ItemDisconnected(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemDisconnected(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemReconnected(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemReconnected(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemAvailableOffline(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemAvailableOffline(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemNotAvailableOffline(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemNotAvailableOffline(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemPinned(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemPinned(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemNotPinned(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemNotPinned(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemModified(This,pszPath,ItemType,bModifiedData,bModifiedAttributes)	\
    ( (This)->lpVtbl -> ItemModified(This,pszPath,ItemType,bModifiedData,bModifiedAttributes) ) 

#define IOfflineFilesEvents2_ItemAddedToCache(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemAddedToCache(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemDeletedFromCache(This,pszPath,ItemType)	\
    ( (This)->lpVtbl -> ItemDeletedFromCache(This,pszPath,ItemType) ) 

#define IOfflineFilesEvents2_ItemRenamed(This,pszOldPath,pszNewPath,ItemType)	\
    ( (This)->lpVtbl -> ItemRenamed(This,pszOldPath,pszNewPath,ItemType) ) 

#define IOfflineFilesEvents2_DataLost(This)	\
    ( (This)->lpVtbl -> DataLost(This) ) 

#define IOfflineFilesEvents2_Ping(This)	\
    ( (This)->lpVtbl -> Ping(This) ) 


#define IOfflineFilesEvents2_ItemReconnectBegin(This)	\
    ( (This)->lpVtbl -> ItemReconnectBegin(This) ) 

#define IOfflineFilesEvents2_ItemReconnectEnd(This)	\
    ( (This)->lpVtbl -> ItemReconnectEnd(This) ) 

#define IOfflineFilesEvents2_CacheEvictBegin(This)	\
    ( (This)->lpVtbl -> CacheEvictBegin(This) ) 

#define IOfflineFilesEvents2_CacheEvictEnd(This)	\
    ( (This)->lpVtbl -> CacheEvictEnd(This) ) 

#define IOfflineFilesEvents2_BackgroundSyncBegin(This,dwSyncControlFlags)	\
    ( (This)->lpVtbl -> BackgroundSyncBegin(This,dwSyncControlFlags) ) 

#define IOfflineFilesEvents2_BackgroundSyncEnd(This,dwSyncControlFlags)	\
    ( (This)->lpVtbl -> BackgroundSyncEnd(This,dwSyncControlFlags) ) 

#define IOfflineFilesEvents2_PolicyChangeDetected(This)	\
    ( (This)->lpVtbl -> PolicyChangeDetected(This) ) 

#define IOfflineFilesEvents2_PreferenceChangeDetected(This)	\
    ( (This)->lpVtbl -> PreferenceChangeDetected(This) ) 

#define IOfflineFilesEvents2_SettingsChangesApplied(This)	\
    ( (This)->lpVtbl -> SettingsChangesApplied(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesEvents2_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesEventsFilter_INTERFACE_DEFINED__
#define __IOfflineFilesEventsFilter_INTERFACE_DEFINED__

/* interface IOfflineFilesEventsFilter */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesEventsFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33FC4E1B-0716-40fa-BA65-6E62A84A846F")
    IOfflineFilesEventsFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPathFilter( 
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszFilter,
            /* [out] */ __RPC__out OFFLINEFILES_PATHFILTER_MATCH *pMatch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIncludedEvents( 
            /* [in] */ ULONG cElements,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElements, *pcEvents) OFFLINEFILES_EVENTS *prgEvents,
            /* [out] */ __RPC__out ULONG *pcEvents) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExcludedEvents( 
            /* [in] */ ULONG cElements,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElements, *pcEvents) OFFLINEFILES_EVENTS *prgEvents,
            /* [out] */ __RPC__out ULONG *pcEvents) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesEventsFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesEventsFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesEventsFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesEventsFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPathFilter )( 
            IOfflineFilesEventsFilter * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszFilter,
            /* [out] */ __RPC__out OFFLINEFILES_PATHFILTER_MATCH *pMatch);
        
        HRESULT ( STDMETHODCALLTYPE *GetIncludedEvents )( 
            IOfflineFilesEventsFilter * This,
            /* [in] */ ULONG cElements,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElements, *pcEvents) OFFLINEFILES_EVENTS *prgEvents,
            /* [out] */ __RPC__out ULONG *pcEvents);
        
        HRESULT ( STDMETHODCALLTYPE *GetExcludedEvents )( 
            IOfflineFilesEventsFilter * This,
            /* [in] */ ULONG cElements,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElements, *pcEvents) OFFLINEFILES_EVENTS *prgEvents,
            /* [out] */ __RPC__out ULONG *pcEvents);
        
        END_INTERFACE
    } IOfflineFilesEventsFilterVtbl;

    interface IOfflineFilesEventsFilter
    {
        CONST_VTBL struct IOfflineFilesEventsFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesEventsFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesEventsFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesEventsFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesEventsFilter_GetPathFilter(This,ppszFilter,pMatch)	\
    ( (This)->lpVtbl -> GetPathFilter(This,ppszFilter,pMatch) ) 

#define IOfflineFilesEventsFilter_GetIncludedEvents(This,cElements,prgEvents,pcEvents)	\
    ( (This)->lpVtbl -> GetIncludedEvents(This,cElements,prgEvents,pcEvents) ) 

#define IOfflineFilesEventsFilter_GetExcludedEvents(This,cElements,prgEvents,pcEvents)	\
    ( (This)->lpVtbl -> GetExcludedEvents(This,cElements,prgEvents,pcEvents) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesEventsFilter_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesErrorInfo_INTERFACE_DEFINED__
#define __IOfflineFilesErrorInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesErrorInfo */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7112FA5F-7571-435a-8EB7-195C7C1429BC")
    IOfflineFilesErrorInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRawData( 
            /* [out] */ __RPC__deref_out_opt BYTE_BLOB **ppBlob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesErrorInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesErrorInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesErrorInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRawData )( 
            IOfflineFilesErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt BYTE_BLOB **ppBlob);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IOfflineFilesErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription);
        
        END_INTERFACE
    } IOfflineFilesErrorInfoVtbl;

    interface IOfflineFilesErrorInfo
    {
        CONST_VTBL struct IOfflineFilesErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesErrorInfo_GetRawData(This,ppBlob)	\
    ( (This)->lpVtbl -> GetRawData(This,ppBlob) ) 

#define IOfflineFilesErrorInfo_GetDescription(This,ppszDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,ppszDescription) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSyncErrorItemInfo_INTERFACE_DEFINED__
#define __IOfflineFilesSyncErrorItemInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesSyncErrorItemInfo */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSyncErrorItemInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECDBAF0D-6A18-4d55-8017-108F7660BA44")
    IOfflineFilesSyncErrorItemInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileAttributes( 
            /* [out] */ __RPC__out DWORD *pdwAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileTimes( 
            /* [out] */ __RPC__out FILETIME *pftLastWrite,
            /* [out] */ __RPC__out FILETIME *pftChange) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [out] */ __RPC__out LARGE_INTEGER *pSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSyncErrorItemInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSyncErrorItemInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSyncErrorItemInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSyncErrorItemInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileAttributes )( 
            IOfflineFilesSyncErrorItemInfo * This,
            /* [out] */ __RPC__out DWORD *pdwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileTimes )( 
            IOfflineFilesSyncErrorItemInfo * This,
            /* [out] */ __RPC__out FILETIME *pftLastWrite,
            /* [out] */ __RPC__out FILETIME *pftChange);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IOfflineFilesSyncErrorItemInfo * This,
            /* [out] */ __RPC__out LARGE_INTEGER *pSize);
        
        END_INTERFACE
    } IOfflineFilesSyncErrorItemInfoVtbl;

    interface IOfflineFilesSyncErrorItemInfo
    {
        CONST_VTBL struct IOfflineFilesSyncErrorItemInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSyncErrorItemInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSyncErrorItemInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSyncErrorItemInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSyncErrorItemInfo_GetFileAttributes(This,pdwAttributes)	\
    ( (This)->lpVtbl -> GetFileAttributes(This,pdwAttributes) ) 

#define IOfflineFilesSyncErrorItemInfo_GetFileTimes(This,pftLastWrite,pftChange)	\
    ( (This)->lpVtbl -> GetFileTimes(This,pftLastWrite,pftChange) ) 

#define IOfflineFilesSyncErrorItemInfo_GetFileSize(This,pSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,pSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSyncErrorItemInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSyncErrorInfo_INTERFACE_DEFINED__
#define __IOfflineFilesSyncErrorInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesSyncErrorInfo */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSyncErrorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59F95E46-EB54-49d1-BE76-DE95458D01B0")
    IOfflineFilesSyncErrorInfo : public IOfflineFilesErrorInfo
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSyncOperation( 
            /* [out] */ __RPC__out OFFLINEFILES_SYNC_OPERATION *pSyncOp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemChangeFlags( 
            /* [out] */ __RPC__out DWORD *pdwItemChangeFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InfoEnumerated( 
            /* [out] */ __RPC__out BOOL *pbLocalEnumerated,
            /* [out] */ __RPC__out BOOL *pbRemoteEnumerated,
            /* [out] */ __RPC__out BOOL *pbOriginalEnumerated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InfoAvailable( 
            /* [out] */ __RPC__out BOOL *pbLocalInfo,
            /* [out] */ __RPC__out BOOL *pbRemoteInfo,
            /* [out] */ __RPC__out BOOL *pbOriginalInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocalInfo( 
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRemoteInfo( 
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalInfo( 
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSyncErrorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSyncErrorInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSyncErrorInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRawData )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt BYTE_BLOB **ppBlob);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetSyncOperation )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__out OFFLINEFILES_SYNC_OPERATION *pSyncOp);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemChangeFlags )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__out DWORD *pdwItemChangeFlags);
        
        HRESULT ( STDMETHODCALLTYPE *InfoEnumerated )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__out BOOL *pbLocalEnumerated,
            /* [out] */ __RPC__out BOOL *pbRemoteEnumerated,
            /* [out] */ __RPC__out BOOL *pbOriginalEnumerated);
        
        HRESULT ( STDMETHODCALLTYPE *InfoAvailable )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__out BOOL *pbLocalInfo,
            /* [out] */ __RPC__out BOOL *pbRemoteInfo,
            /* [out] */ __RPC__out BOOL *pbOriginalInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocalInfo )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemoteInfo )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetOriginalInfo )( 
            IOfflineFilesSyncErrorInfo * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSyncErrorItemInfo **ppInfo);
        
        END_INTERFACE
    } IOfflineFilesSyncErrorInfoVtbl;

    interface IOfflineFilesSyncErrorInfo
    {
        CONST_VTBL struct IOfflineFilesSyncErrorInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSyncErrorInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSyncErrorInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSyncErrorInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSyncErrorInfo_GetRawData(This,ppBlob)	\
    ( (This)->lpVtbl -> GetRawData(This,ppBlob) ) 

#define IOfflineFilesSyncErrorInfo_GetDescription(This,ppszDescription)	\
    ( (This)->lpVtbl -> GetDescription(This,ppszDescription) ) 


#define IOfflineFilesSyncErrorInfo_GetSyncOperation(This,pSyncOp)	\
    ( (This)->lpVtbl -> GetSyncOperation(This,pSyncOp) ) 

#define IOfflineFilesSyncErrorInfo_GetItemChangeFlags(This,pdwItemChangeFlags)	\
    ( (This)->lpVtbl -> GetItemChangeFlags(This,pdwItemChangeFlags) ) 

#define IOfflineFilesSyncErrorInfo_InfoEnumerated(This,pbLocalEnumerated,pbRemoteEnumerated,pbOriginalEnumerated)	\
    ( (This)->lpVtbl -> InfoEnumerated(This,pbLocalEnumerated,pbRemoteEnumerated,pbOriginalEnumerated) ) 

#define IOfflineFilesSyncErrorInfo_InfoAvailable(This,pbLocalInfo,pbRemoteInfo,pbOriginalInfo)	\
    ( (This)->lpVtbl -> InfoAvailable(This,pbLocalInfo,pbRemoteInfo,pbOriginalInfo) ) 

#define IOfflineFilesSyncErrorInfo_GetLocalInfo(This,ppInfo)	\
    ( (This)->lpVtbl -> GetLocalInfo(This,ppInfo) ) 

#define IOfflineFilesSyncErrorInfo_GetRemoteInfo(This,ppInfo)	\
    ( (This)->lpVtbl -> GetRemoteInfo(This,ppInfo) ) 

#define IOfflineFilesSyncErrorInfo_GetOriginalInfo(This,ppInfo)	\
    ( (This)->lpVtbl -> GetOriginalInfo(This,ppInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSyncErrorInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesProgress_INTERFACE_DEFINED__
#define __IOfflineFilesProgress_INTERFACE_DEFINED__

/* interface IOfflineFilesProgress */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FAD63237-C55B-4911-9850-BCF96D4C979E")
    IOfflineFilesProgress : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin( 
            /* [out] */ __RPC__out BOOL *pbAbort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryAbort( 
            /* [out] */ __RPC__out BOOL *pbAbort) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE End( 
            /* [in] */ HRESULT hrResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesProgress * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IOfflineFilesProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *QueryAbort )( 
            IOfflineFilesProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *End )( 
            IOfflineFilesProgress * This,
            /* [in] */ HRESULT hrResult);
        
        END_INTERFACE
    } IOfflineFilesProgressVtbl;

    interface IOfflineFilesProgress
    {
        CONST_VTBL struct IOfflineFilesProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesProgress_Begin(This,pbAbort)	\
    ( (This)->lpVtbl -> Begin(This,pbAbort) ) 

#define IOfflineFilesProgress_QueryAbort(This,pbAbort)	\
    ( (This)->lpVtbl -> QueryAbort(This,pbAbort) ) 

#define IOfflineFilesProgress_End(This,hrResult)	\
    ( (This)->lpVtbl -> End(This,hrResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesProgress_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSimpleProgress_INTERFACE_DEFINED__
#define __IOfflineFilesSimpleProgress_INTERFACE_DEFINED__

/* interface IOfflineFilesSimpleProgress */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSimpleProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C34F7F9B-C43D-4f9d-A776-C0EB6DE5D401")
    IOfflineFilesSimpleProgress : public IOfflineFilesProgress
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ItemBegin( 
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemResult( 
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSimpleProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSimpleProgress * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSimpleProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSimpleProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IOfflineFilesSimpleProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *QueryAbort )( 
            IOfflineFilesSimpleProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *End )( 
            IOfflineFilesSimpleProgress * This,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *ItemBegin )( 
            IOfflineFilesSimpleProgress * This,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse);
        
        HRESULT ( STDMETHODCALLTYPE *ItemResult )( 
            IOfflineFilesSimpleProgress * This,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse);
        
        END_INTERFACE
    } IOfflineFilesSimpleProgressVtbl;

    interface IOfflineFilesSimpleProgress
    {
        CONST_VTBL struct IOfflineFilesSimpleProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSimpleProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSimpleProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSimpleProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSimpleProgress_Begin(This,pbAbort)	\
    ( (This)->lpVtbl -> Begin(This,pbAbort) ) 

#define IOfflineFilesSimpleProgress_QueryAbort(This,pbAbort)	\
    ( (This)->lpVtbl -> QueryAbort(This,pbAbort) ) 

#define IOfflineFilesSimpleProgress_End(This,hrResult)	\
    ( (This)->lpVtbl -> End(This,hrResult) ) 


#define IOfflineFilesSimpleProgress_ItemBegin(This,pszFile,pResponse)	\
    ( (This)->lpVtbl -> ItemBegin(This,pszFile,pResponse) ) 

#define IOfflineFilesSimpleProgress_ItemResult(This,pszFile,hrResult,pResponse)	\
    ( (This)->lpVtbl -> ItemResult(This,pszFile,hrResult,pResponse) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSimpleProgress_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSyncProgress_INTERFACE_DEFINED__
#define __IOfflineFilesSyncProgress_INTERFACE_DEFINED__

/* interface IOfflineFilesSyncProgress */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSyncProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6931F49A-6FC7-4c1b-B265-56793FC451B7")
    IOfflineFilesSyncProgress : public IOfflineFilesProgress
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SyncItemBegin( 
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SyncItemResult( 
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult,
            /* [in] */ __RPC__in_opt IOfflineFilesSyncErrorInfo *pErrorInfo,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSyncProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSyncProgress * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSyncProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSyncProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IOfflineFilesSyncProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *QueryAbort )( 
            IOfflineFilesSyncProgress * This,
            /* [out] */ __RPC__out BOOL *pbAbort);
        
        HRESULT ( STDMETHODCALLTYPE *End )( 
            IOfflineFilesSyncProgress * This,
            /* [in] */ HRESULT hrResult);
        
        HRESULT ( STDMETHODCALLTYPE *SyncItemBegin )( 
            IOfflineFilesSyncProgress * This,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse);
        
        HRESULT ( STDMETHODCALLTYPE *SyncItemResult )( 
            IOfflineFilesSyncProgress * This,
            /* [string][in] */ __RPC__in LPCWSTR pszFile,
            /* [in] */ HRESULT hrResult,
            /* [in] */ __RPC__in_opt IOfflineFilesSyncErrorInfo *pErrorInfo,
            /* [out] */ __RPC__out OFFLINEFILES_OP_RESPONSE *pResponse);
        
        END_INTERFACE
    } IOfflineFilesSyncProgressVtbl;

    interface IOfflineFilesSyncProgress
    {
        CONST_VTBL struct IOfflineFilesSyncProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSyncProgress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSyncProgress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSyncProgress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSyncProgress_Begin(This,pbAbort)	\
    ( (This)->lpVtbl -> Begin(This,pbAbort) ) 

#define IOfflineFilesSyncProgress_QueryAbort(This,pbAbort)	\
    ( (This)->lpVtbl -> QueryAbort(This,pbAbort) ) 

#define IOfflineFilesSyncProgress_End(This,hrResult)	\
    ( (This)->lpVtbl -> End(This,hrResult) ) 


#define IOfflineFilesSyncProgress_SyncItemBegin(This,pszFile,pResponse)	\
    ( (This)->lpVtbl -> SyncItemBegin(This,pszFile,pResponse) ) 

#define IOfflineFilesSyncProgress_SyncItemResult(This,pszFile,hrResult,pErrorInfo,pResponse)	\
    ( (This)->lpVtbl -> SyncItemResult(This,pszFile,hrResult,pErrorInfo,pResponse) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSyncProgress_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSyncConflictHandler_INTERFACE_DEFINED__
#define __IOfflineFilesSyncConflictHandler_INTERFACE_DEFINED__

/* interface IOfflineFilesSyncConflictHandler */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSyncConflictHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6DD5092-C65C-46b6-97B8-FADD08E7E1BE")
    IOfflineFilesSyncConflictHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResolveConflict( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ DWORD fStateKnown,
            /* [in] */ OFFLINEFILES_SYNC_STATE state,
            /* [in] */ DWORD fChangeDetails,
            /* [out] */ __RPC__out OFFLINEFILES_SYNC_CONFLICT_RESOLVE *pConflictResolution,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszNewName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSyncConflictHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSyncConflictHandler * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSyncConflictHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSyncConflictHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResolveConflict )( 
            IOfflineFilesSyncConflictHandler * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ DWORD fStateKnown,
            /* [in] */ OFFLINEFILES_SYNC_STATE state,
            /* [in] */ DWORD fChangeDetails,
            /* [out] */ __RPC__out OFFLINEFILES_SYNC_CONFLICT_RESOLVE *pConflictResolution,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszNewName);
        
        END_INTERFACE
    } IOfflineFilesSyncConflictHandlerVtbl;

    interface IOfflineFilesSyncConflictHandler
    {
        CONST_VTBL struct IOfflineFilesSyncConflictHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSyncConflictHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSyncConflictHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSyncConflictHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSyncConflictHandler_ResolveConflict(This,pszPath,fStateKnown,state,fChangeDetails,pConflictResolution,ppszNewName)	\
    ( (This)->lpVtbl -> ResolveConflict(This,pszPath,fStateKnown,state,fChangeDetails,pConflictResolution,ppszNewName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSyncConflictHandler_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesItemFilter_INTERFACE_DEFINED__
#define __IOfflineFilesItemFilter_INTERFACE_DEFINED__

/* interface IOfflineFilesItemFilter */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesItemFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F4B5A26C-DC05-4f20-ADA4-551F1077BE5C")
    IOfflineFilesItemFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFilterFlags( 
            /* [out] */ __RPC__out ULONGLONG *pullFlags,
            /* [out] */ __RPC__out ULONGLONG *pullMask) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimeFilter( 
            /* [out] */ __RPC__out FILETIME *pftTime,
            /* [out] */ __RPC__out BOOL *pbEvalTimeOfDay,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TIME *pTimeType,
            /* [out] */ __RPC__out OFFLINEFILES_COMPARE *pCompare) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPatternFilter( 
            /* [size_is][string][out] */ __RPC__out_ecount_full_string(cchPattern) LPWSTR pszPattern,
            /* [in] */ ULONG cchPattern) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesItemFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesItemFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesItemFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesItemFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilterFlags )( 
            IOfflineFilesItemFilter * This,
            /* [out] */ __RPC__out ULONGLONG *pullFlags,
            /* [out] */ __RPC__out ULONGLONG *pullMask);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimeFilter )( 
            IOfflineFilesItemFilter * This,
            /* [out] */ __RPC__out FILETIME *pftTime,
            /* [out] */ __RPC__out BOOL *pbEvalTimeOfDay,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TIME *pTimeType,
            /* [out] */ __RPC__out OFFLINEFILES_COMPARE *pCompare);
        
        HRESULT ( STDMETHODCALLTYPE *GetPatternFilter )( 
            IOfflineFilesItemFilter * This,
            /* [size_is][string][out] */ __RPC__out_ecount_full_string(cchPattern) LPWSTR pszPattern,
            /* [in] */ ULONG cchPattern);
        
        END_INTERFACE
    } IOfflineFilesItemFilterVtbl;

    interface IOfflineFilesItemFilter
    {
        CONST_VTBL struct IOfflineFilesItemFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesItemFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesItemFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesItemFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesItemFilter_GetFilterFlags(This,pullFlags,pullMask)	\
    ( (This)->lpVtbl -> GetFilterFlags(This,pullFlags,pullMask) ) 

#define IOfflineFilesItemFilter_GetTimeFilter(This,pftTime,pbEvalTimeOfDay,pTimeType,pCompare)	\
    ( (This)->lpVtbl -> GetTimeFilter(This,pftTime,pbEvalTimeOfDay,pTimeType,pCompare) ) 

#define IOfflineFilesItemFilter_GetPatternFilter(This,pszPattern,cchPattern)	\
    ( (This)->lpVtbl -> GetPatternFilter(This,pszPattern,cchPattern) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesItemFilter_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesItem_INTERFACE_DEFINED__
#define __IOfflineFilesItem_INTERFACE_DEFINED__

/* interface IOfflineFilesItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4a753da6-e044-4f12-a718-5d14d079a906")
    IOfflineFilesItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemType( 
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParentItem( 
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ DWORD dwQueryFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMarkedForDeletion( 
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IOfflineFilesItem * This,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IOfflineFilesItem * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentItem )( 
            IOfflineFilesItem * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IOfflineFilesItem * This,
            /* [in] */ DWORD dwQueryFlags);
        
        HRESULT ( STDMETHODCALLTYPE *IsMarkedForDeletion )( 
            IOfflineFilesItem * This,
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion);
        
        END_INTERFACE
    } IOfflineFilesItemVtbl;

    interface IOfflineFilesItem
    {
        CONST_VTBL struct IOfflineFilesItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesItem_GetItemType(This,pItemType)	\
    ( (This)->lpVtbl -> GetItemType(This,pItemType) ) 

#define IOfflineFilesItem_GetPath(This,ppszPath)	\
    ( (This)->lpVtbl -> GetPath(This,ppszPath) ) 

#define IOfflineFilesItem_GetParentItem(This,ppItem)	\
    ( (This)->lpVtbl -> GetParentItem(This,ppItem) ) 

#define IOfflineFilesItem_Refresh(This,dwQueryFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwQueryFlags) ) 

#define IOfflineFilesItem_IsMarkedForDeletion(This,pbMarkedForDeletion)	\
    ( (This)->lpVtbl -> IsMarkedForDeletion(This,pbMarkedForDeletion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesItem_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesServerItem_INTERFACE_DEFINED__
#define __IOfflineFilesServerItem_INTERFACE_DEFINED__

/* interface IOfflineFilesServerItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesServerItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B1C9576-A92B-4151-8E9E-7C7B3EC2E016")
    IOfflineFilesServerItem : public IOfflineFilesItem
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesServerItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesServerItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesServerItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesServerItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IOfflineFilesServerItem * This,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IOfflineFilesServerItem * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentItem )( 
            IOfflineFilesServerItem * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IOfflineFilesServerItem * This,
            /* [in] */ DWORD dwQueryFlags);
        
        HRESULT ( STDMETHODCALLTYPE *IsMarkedForDeletion )( 
            IOfflineFilesServerItem * This,
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion);
        
        END_INTERFACE
    } IOfflineFilesServerItemVtbl;

    interface IOfflineFilesServerItem
    {
        CONST_VTBL struct IOfflineFilesServerItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesServerItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesServerItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesServerItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesServerItem_GetItemType(This,pItemType)	\
    ( (This)->lpVtbl -> GetItemType(This,pItemType) ) 

#define IOfflineFilesServerItem_GetPath(This,ppszPath)	\
    ( (This)->lpVtbl -> GetPath(This,ppszPath) ) 

#define IOfflineFilesServerItem_GetParentItem(This,ppItem)	\
    ( (This)->lpVtbl -> GetParentItem(This,ppItem) ) 

#define IOfflineFilesServerItem_Refresh(This,dwQueryFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwQueryFlags) ) 

#define IOfflineFilesServerItem_IsMarkedForDeletion(This,pbMarkedForDeletion)	\
    ( (This)->lpVtbl -> IsMarkedForDeletion(This,pbMarkedForDeletion) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesServerItem_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesShareItem_INTERFACE_DEFINED__
#define __IOfflineFilesShareItem_INTERFACE_DEFINED__

/* interface IOfflineFilesShareItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesShareItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BAB7E48D-4804-41b5-A44D-0F199B06B145")
    IOfflineFilesShareItem : public IOfflineFilesItem
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesShareItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesShareItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesShareItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesShareItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IOfflineFilesShareItem * This,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IOfflineFilesShareItem * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentItem )( 
            IOfflineFilesShareItem * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IOfflineFilesShareItem * This,
            /* [in] */ DWORD dwQueryFlags);
        
        HRESULT ( STDMETHODCALLTYPE *IsMarkedForDeletion )( 
            IOfflineFilesShareItem * This,
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion);
        
        END_INTERFACE
    } IOfflineFilesShareItemVtbl;

    interface IOfflineFilesShareItem
    {
        CONST_VTBL struct IOfflineFilesShareItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesShareItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesShareItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesShareItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesShareItem_GetItemType(This,pItemType)	\
    ( (This)->lpVtbl -> GetItemType(This,pItemType) ) 

#define IOfflineFilesShareItem_GetPath(This,ppszPath)	\
    ( (This)->lpVtbl -> GetPath(This,ppszPath) ) 

#define IOfflineFilesShareItem_GetParentItem(This,ppItem)	\
    ( (This)->lpVtbl -> GetParentItem(This,ppItem) ) 

#define IOfflineFilesShareItem_Refresh(This,dwQueryFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwQueryFlags) ) 

#define IOfflineFilesShareItem_IsMarkedForDeletion(This,pbMarkedForDeletion)	\
    ( (This)->lpVtbl -> IsMarkedForDeletion(This,pbMarkedForDeletion) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesShareItem_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesDirectoryItem_INTERFACE_DEFINED__
#define __IOfflineFilesDirectoryItem_INTERFACE_DEFINED__

/* interface IOfflineFilesDirectoryItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesDirectoryItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2273597A-A08C-4a00-A37A-C1AE4E9A1CFD")
    IOfflineFilesDirectoryItem : public IOfflineFilesItem
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesDirectoryItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesDirectoryItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesDirectoryItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesDirectoryItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IOfflineFilesDirectoryItem * This,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IOfflineFilesDirectoryItem * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentItem )( 
            IOfflineFilesDirectoryItem * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IOfflineFilesDirectoryItem * This,
            /* [in] */ DWORD dwQueryFlags);
        
        HRESULT ( STDMETHODCALLTYPE *IsMarkedForDeletion )( 
            IOfflineFilesDirectoryItem * This,
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion);
        
        END_INTERFACE
    } IOfflineFilesDirectoryItemVtbl;

    interface IOfflineFilesDirectoryItem
    {
        CONST_VTBL struct IOfflineFilesDirectoryItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesDirectoryItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesDirectoryItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesDirectoryItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesDirectoryItem_GetItemType(This,pItemType)	\
    ( (This)->lpVtbl -> GetItemType(This,pItemType) ) 

#define IOfflineFilesDirectoryItem_GetPath(This,ppszPath)	\
    ( (This)->lpVtbl -> GetPath(This,ppszPath) ) 

#define IOfflineFilesDirectoryItem_GetParentItem(This,ppItem)	\
    ( (This)->lpVtbl -> GetParentItem(This,ppItem) ) 

#define IOfflineFilesDirectoryItem_Refresh(This,dwQueryFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwQueryFlags) ) 

#define IOfflineFilesDirectoryItem_IsMarkedForDeletion(This,pbMarkedForDeletion)	\
    ( (This)->lpVtbl -> IsMarkedForDeletion(This,pbMarkedForDeletion) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesDirectoryItem_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesFileItem_INTERFACE_DEFINED__
#define __IOfflineFilesFileItem_INTERFACE_DEFINED__

/* interface IOfflineFilesFileItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesFileItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8dfadead-26c2-4eff-8a72-6b50723d9a00")
    IOfflineFilesFileItem : public IOfflineFilesItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsSparse( 
            /* [out] */ __RPC__out BOOL *pbIsSparse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEncrypted( 
            /* [out] */ __RPC__out BOOL *pbIsEncrypted) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesFileItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesFileItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesFileItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesFileItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemType )( 
            IOfflineFilesFileItem * This,
            /* [out] */ __RPC__out OFFLINEFILES_ITEM_TYPE *pItemType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IOfflineFilesFileItem * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetParentItem )( 
            IOfflineFilesFileItem * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IOfflineFilesFileItem * This,
            /* [in] */ DWORD dwQueryFlags);
        
        HRESULT ( STDMETHODCALLTYPE *IsMarkedForDeletion )( 
            IOfflineFilesFileItem * This,
            /* [out] */ __RPC__out BOOL *pbMarkedForDeletion);
        
        HRESULT ( STDMETHODCALLTYPE *IsSparse )( 
            IOfflineFilesFileItem * This,
            /* [out] */ __RPC__out BOOL *pbIsSparse);
        
        HRESULT ( STDMETHODCALLTYPE *IsEncrypted )( 
            IOfflineFilesFileItem * This,
            /* [out] */ __RPC__out BOOL *pbIsEncrypted);
        
        END_INTERFACE
    } IOfflineFilesFileItemVtbl;

    interface IOfflineFilesFileItem
    {
        CONST_VTBL struct IOfflineFilesFileItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesFileItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesFileItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesFileItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesFileItem_GetItemType(This,pItemType)	\
    ( (This)->lpVtbl -> GetItemType(This,pItemType) ) 

#define IOfflineFilesFileItem_GetPath(This,ppszPath)	\
    ( (This)->lpVtbl -> GetPath(This,ppszPath) ) 

#define IOfflineFilesFileItem_GetParentItem(This,ppItem)	\
    ( (This)->lpVtbl -> GetParentItem(This,ppItem) ) 

#define IOfflineFilesFileItem_Refresh(This,dwQueryFlags)	\
    ( (This)->lpVtbl -> Refresh(This,dwQueryFlags) ) 

#define IOfflineFilesFileItem_IsMarkedForDeletion(This,pbMarkedForDeletion)	\
    ( (This)->lpVtbl -> IsMarkedForDeletion(This,pbMarkedForDeletion) ) 


#define IOfflineFilesFileItem_IsSparse(This,pbIsSparse)	\
    ( (This)->lpVtbl -> IsSparse(This,pbIsSparse) ) 

#define IOfflineFilesFileItem_IsEncrypted(This,pbIsEncrypted)	\
    ( (This)->lpVtbl -> IsEncrypted(This,pbIsEncrypted) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesFileItem_INTERFACE_DEFINED__ */


#ifndef __IEnumOfflineFilesItems_INTERFACE_DEFINED__
#define __IEnumOfflineFilesItems_INTERFACE_DEFINED__

/* interface IEnumOfflineFilesItems */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumOfflineFilesItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DA70E815-C361-4407-BC0B-0D7046E5F2CD")
    IEnumOfflineFilesItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IOfflineFilesItem **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumOfflineFilesItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumOfflineFilesItems * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumOfflineFilesItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumOfflineFilesItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumOfflineFilesItems * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IOfflineFilesItem **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumOfflineFilesItems * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumOfflineFilesItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumOfflineFilesItems * This,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum);
        
        END_INTERFACE
    } IEnumOfflineFilesItemsVtbl;

    interface IEnumOfflineFilesItems
    {
        CONST_VTBL struct IEnumOfflineFilesItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOfflineFilesItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumOfflineFilesItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumOfflineFilesItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumOfflineFilesItems_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumOfflineFilesItems_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumOfflineFilesItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumOfflineFilesItems_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumOfflineFilesItems_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesItemContainer_INTERFACE_DEFINED__
#define __IOfflineFilesItemContainer_INTERFACE_DEFINED__

/* interface IOfflineFilesItemContainer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesItemContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3836F049-9413-45dd-BF46-B5AAA82DC310")
    IOfflineFilesItemContainer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumItems( 
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumItemsEx( 
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeDirFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeDirFilter,
            /* [in] */ DWORD dwEnumFlags,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesItemContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesItemContainer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesItemContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesItemContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IOfflineFilesItemContainer * This,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItemsEx )( 
            IOfflineFilesItemContainer * This,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeDirFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeDirFilter,
            /* [in] */ DWORD dwEnumFlags,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesItems **ppenum);
        
        END_INTERFACE
    } IOfflineFilesItemContainerVtbl;

    interface IOfflineFilesItemContainer
    {
        CONST_VTBL struct IOfflineFilesItemContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesItemContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesItemContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesItemContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesItemContainer_EnumItems(This,dwQueryFlags,ppenum)	\
    ( (This)->lpVtbl -> EnumItems(This,dwQueryFlags,ppenum) ) 

#define IOfflineFilesItemContainer_EnumItemsEx(This,pIncludeFileFilter,pIncludeDirFilter,pExcludeFileFilter,pExcludeDirFilter,dwEnumFlags,dwQueryFlags,ppenum)	\
    ( (This)->lpVtbl -> EnumItemsEx(This,pIncludeFileFilter,pIncludeDirFilter,pExcludeFileFilter,pExcludeDirFilter,dwEnumFlags,dwQueryFlags,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesItemContainer_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesChangeInfo_INTERFACE_DEFINED__
#define __IOfflineFilesChangeInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesChangeInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesChangeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A96E6FA4-E0D1-4c29-960B-EE508FE68C72")
    IOfflineFilesChangeInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsDirty( 
            /* [out] */ __RPC__out BOOL *pbDirty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDeletedOffline( 
            /* [out] */ __RPC__out BOOL *pbDeletedOffline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCreatedOffline( 
            /* [out] */ __RPC__out BOOL *pbCreatedOffline) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLocallyModifiedData( 
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLocallyModifiedAttributes( 
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLocallyModifiedTime( 
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesChangeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesChangeInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesChangeInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesChangeInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbDirty);
        
        HRESULT ( STDMETHODCALLTYPE *IsDeletedOffline )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbDeletedOffline);
        
        HRESULT ( STDMETHODCALLTYPE *IsCreatedOffline )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbCreatedOffline);
        
        HRESULT ( STDMETHODCALLTYPE *IsLocallyModifiedData )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedData);
        
        HRESULT ( STDMETHODCALLTYPE *IsLocallyModifiedAttributes )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *IsLocallyModifiedTime )( 
            IOfflineFilesChangeInfo * This,
            /* [out] */ __RPC__out BOOL *pbLocallyModifiedTime);
        
        END_INTERFACE
    } IOfflineFilesChangeInfoVtbl;

    interface IOfflineFilesChangeInfo
    {
        CONST_VTBL struct IOfflineFilesChangeInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesChangeInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesChangeInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesChangeInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesChangeInfo_IsDirty(This,pbDirty)	\
    ( (This)->lpVtbl -> IsDirty(This,pbDirty) ) 

#define IOfflineFilesChangeInfo_IsDeletedOffline(This,pbDeletedOffline)	\
    ( (This)->lpVtbl -> IsDeletedOffline(This,pbDeletedOffline) ) 

#define IOfflineFilesChangeInfo_IsCreatedOffline(This,pbCreatedOffline)	\
    ( (This)->lpVtbl -> IsCreatedOffline(This,pbCreatedOffline) ) 

#define IOfflineFilesChangeInfo_IsLocallyModifiedData(This,pbLocallyModifiedData)	\
    ( (This)->lpVtbl -> IsLocallyModifiedData(This,pbLocallyModifiedData) ) 

#define IOfflineFilesChangeInfo_IsLocallyModifiedAttributes(This,pbLocallyModifiedAttributes)	\
    ( (This)->lpVtbl -> IsLocallyModifiedAttributes(This,pbLocallyModifiedAttributes) ) 

#define IOfflineFilesChangeInfo_IsLocallyModifiedTime(This,pbLocallyModifiedTime)	\
    ( (This)->lpVtbl -> IsLocallyModifiedTime(This,pbLocallyModifiedTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesChangeInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesFileSysInfo_INTERFACE_DEFINED__
#define __IOfflineFilesFileSysInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesFileSysInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesFileSysInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC1A163F-7BFD-4d88-9C66-96EA9A6A3D6B")
    IOfflineFilesFileSysInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAttributes( 
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out DWORD *pdwAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimes( 
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out FILETIME *pftCreationTime,
            /* [out] */ __RPC__out FILETIME *pftLastWriteTime,
            /* [out] */ __RPC__out FILETIME *pftChangeTime,
            /* [out] */ __RPC__out FILETIME *pftLastAccessTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileSize( 
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out LARGE_INTEGER *pSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesFileSysInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesFileSysInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesFileSysInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesFileSysInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributes )( 
            IOfflineFilesFileSysInfo * This,
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out DWORD *pdwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimes )( 
            IOfflineFilesFileSysInfo * This,
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out FILETIME *pftCreationTime,
            /* [out] */ __RPC__out FILETIME *pftLastWriteTime,
            /* [out] */ __RPC__out FILETIME *pftChangeTime,
            /* [out] */ __RPC__out FILETIME *pftLastAccessTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileSize )( 
            IOfflineFilesFileSysInfo * This,
            /* [in] */ OFFLINEFILES_ITEM_COPY copy,
            /* [out] */ __RPC__out LARGE_INTEGER *pSize);
        
        END_INTERFACE
    } IOfflineFilesFileSysInfoVtbl;

    interface IOfflineFilesFileSysInfo
    {
        CONST_VTBL struct IOfflineFilesFileSysInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesFileSysInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesFileSysInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesFileSysInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesFileSysInfo_GetAttributes(This,copy,pdwAttributes)	\
    ( (This)->lpVtbl -> GetAttributes(This,copy,pdwAttributes) ) 

#define IOfflineFilesFileSysInfo_GetTimes(This,copy,pftCreationTime,pftLastWriteTime,pftChangeTime,pftLastAccessTime)	\
    ( (This)->lpVtbl -> GetTimes(This,copy,pftCreationTime,pftLastWriteTime,pftChangeTime,pftLastAccessTime) ) 

#define IOfflineFilesFileSysInfo_GetFileSize(This,copy,pSize)	\
    ( (This)->lpVtbl -> GetFileSize(This,copy,pSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesFileSysInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesPinInfo_INTERFACE_DEFINED__
#define __IOfflineFilesPinInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesPinInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesPinInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B2B0655-B3FD-497d-ADEB-BD156BC8355B")
    IOfflineFilesPinInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsPinned( 
            /* [out] */ __RPC__out BOOL *pbPinned) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPinnedForUser( 
            /* [out] */ __RPC__out BOOL *pbPinnedForUser,
            /* [out] */ __RPC__out BOOL *pbInherit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPinnedForUserByPolicy( 
            /* [out] */ __RPC__out BOOL *pbPinnedForUser,
            /* [out] */ __RPC__out BOOL *pbInherit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPinnedForComputer( 
            /* [out] */ __RPC__out BOOL *pbPinnedForComputer,
            /* [out] */ __RPC__out BOOL *pbInherit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPinnedForFolderRedirection( 
            /* [out] */ __RPC__out BOOL *pbPinnedForFolderRedirection,
            /* [out] */ __RPC__out BOOL *pbInherit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesPinInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesPinInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesPinInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesPinInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsPinned )( 
            IOfflineFilesPinInfo * This,
            /* [out] */ __RPC__out BOOL *pbPinned);
        
        HRESULT ( STDMETHODCALLTYPE *IsPinnedForUser )( 
            IOfflineFilesPinInfo * This,
            /* [out] */ __RPC__out BOOL *pbPinnedForUser,
            /* [out] */ __RPC__out BOOL *pbInherit);
        
        HRESULT ( STDMETHODCALLTYPE *IsPinnedForUserByPolicy )( 
            IOfflineFilesPinInfo * This,
            /* [out] */ __RPC__out BOOL *pbPinnedForUser,
            /* [out] */ __RPC__out BOOL *pbInherit);
        
        HRESULT ( STDMETHODCALLTYPE *IsPinnedForComputer )( 
            IOfflineFilesPinInfo * This,
            /* [out] */ __RPC__out BOOL *pbPinnedForComputer,
            /* [out] */ __RPC__out BOOL *pbInherit);
        
        HRESULT ( STDMETHODCALLTYPE *IsPinnedForFolderRedirection )( 
            IOfflineFilesPinInfo * This,
            /* [out] */ __RPC__out BOOL *pbPinnedForFolderRedirection,
            /* [out] */ __RPC__out BOOL *pbInherit);
        
        END_INTERFACE
    } IOfflineFilesPinInfoVtbl;

    interface IOfflineFilesPinInfo
    {
        CONST_VTBL struct IOfflineFilesPinInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesPinInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesPinInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesPinInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesPinInfo_IsPinned(This,pbPinned)	\
    ( (This)->lpVtbl -> IsPinned(This,pbPinned) ) 

#define IOfflineFilesPinInfo_IsPinnedForUser(This,pbPinnedForUser,pbInherit)	\
    ( (This)->lpVtbl -> IsPinnedForUser(This,pbPinnedForUser,pbInherit) ) 

#define IOfflineFilesPinInfo_IsPinnedForUserByPolicy(This,pbPinnedForUser,pbInherit)	\
    ( (This)->lpVtbl -> IsPinnedForUserByPolicy(This,pbPinnedForUser,pbInherit) ) 

#define IOfflineFilesPinInfo_IsPinnedForComputer(This,pbPinnedForComputer,pbInherit)	\
    ( (This)->lpVtbl -> IsPinnedForComputer(This,pbPinnedForComputer,pbInherit) ) 

#define IOfflineFilesPinInfo_IsPinnedForFolderRedirection(This,pbPinnedForFolderRedirection,pbInherit)	\
    ( (This)->lpVtbl -> IsPinnedForFolderRedirection(This,pbPinnedForFolderRedirection,pbInherit) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesPinInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesConnectionInfo_INTERFACE_DEFINED__
#define __IOfflineFilesConnectionInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesConnectionInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesConnectionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFB23A09-A867-4be8-83A6-86969A7D0856")
    IOfflineFilesConnectionInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetConnectState( 
            /* [out] */ __RPC__out OFFLINEFILES_CONNECT_STATE *pConnectState,
            /* [out] */ __RPC__out OFFLINEFILES_OFFLINE_REASON *pOfflineReason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetConnectState( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags,
            /* [in] */ OFFLINEFILES_CONNECT_STATE ConnectState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransitionOnline( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransitionOffline( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bForceOpenFilesClosed,
            /* [out] */ __RPC__out BOOL *pbOpenFilesPreventedTransition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesConnectionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesConnectionInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesConnectionInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesConnectionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectState )( 
            IOfflineFilesConnectionInfo * This,
            /* [out] */ __RPC__out OFFLINEFILES_CONNECT_STATE *pConnectState,
            /* [out] */ __RPC__out OFFLINEFILES_OFFLINE_REASON *pOfflineReason);
        
        HRESULT ( STDMETHODCALLTYPE *SetConnectState )( 
            IOfflineFilesConnectionInfo * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags,
            /* [in] */ OFFLINEFILES_CONNECT_STATE ConnectState);
        
        HRESULT ( STDMETHODCALLTYPE *TransitionOnline )( 
            IOfflineFilesConnectionInfo * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *TransitionOffline )( 
            IOfflineFilesConnectionInfo * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bForceOpenFilesClosed,
            /* [out] */ __RPC__out BOOL *pbOpenFilesPreventedTransition);
        
        END_INTERFACE
    } IOfflineFilesConnectionInfoVtbl;

    interface IOfflineFilesConnectionInfo
    {
        CONST_VTBL struct IOfflineFilesConnectionInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesConnectionInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesConnectionInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesConnectionInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesConnectionInfo_GetConnectState(This,pConnectState,pOfflineReason)	\
    ( (This)->lpVtbl -> GetConnectState(This,pConnectState,pOfflineReason) ) 

#define IOfflineFilesConnectionInfo_SetConnectState(This,hwndParent,dwFlags,ConnectState)	\
    ( (This)->lpVtbl -> SetConnectState(This,hwndParent,dwFlags,ConnectState) ) 

#define IOfflineFilesConnectionInfo_TransitionOnline(This,hwndParent,dwFlags)	\
    ( (This)->lpVtbl -> TransitionOnline(This,hwndParent,dwFlags) ) 

#define IOfflineFilesConnectionInfo_TransitionOffline(This,hwndParent,dwFlags,bForceOpenFilesClosed,pbOpenFilesPreventedTransition)	\
    ( (This)->lpVtbl -> TransitionOffline(This,hwndParent,dwFlags,bForceOpenFilesClosed,pbOpenFilesPreventedTransition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesConnectionInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesShareInfo_INTERFACE_DEFINED__
#define __IOfflineFilesShareInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesShareInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesShareInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7BCC43E7-31CE-4ca4-8CCD-1CFF2DC494DA")
    IOfflineFilesShareInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetShareItem( 
            /* [out] */ __RPC__deref_out_opt IOfflineFilesShareItem **ppShareItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShareCachingMode( 
            /* [out] */ __RPC__out OFFLINEFILES_CACHING_MODE *pCachingMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsShareDfsJunction( 
            /* [out] */ __RPC__out BOOL *pbIsDfsJunction) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesShareInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesShareInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesShareInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesShareInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetShareItem )( 
            IOfflineFilesShareInfo * This,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesShareItem **ppShareItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetShareCachingMode )( 
            IOfflineFilesShareInfo * This,
            /* [out] */ __RPC__out OFFLINEFILES_CACHING_MODE *pCachingMode);
        
        HRESULT ( STDMETHODCALLTYPE *IsShareDfsJunction )( 
            IOfflineFilesShareInfo * This,
            /* [out] */ __RPC__out BOOL *pbIsDfsJunction);
        
        END_INTERFACE
    } IOfflineFilesShareInfoVtbl;

    interface IOfflineFilesShareInfo
    {
        CONST_VTBL struct IOfflineFilesShareInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesShareInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesShareInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesShareInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesShareInfo_GetShareItem(This,ppShareItem)	\
    ( (This)->lpVtbl -> GetShareItem(This,ppShareItem) ) 

#define IOfflineFilesShareInfo_GetShareCachingMode(This,pCachingMode)	\
    ( (This)->lpVtbl -> GetShareCachingMode(This,pCachingMode) ) 

#define IOfflineFilesShareInfo_IsShareDfsJunction(This,pbIsDfsJunction)	\
    ( (This)->lpVtbl -> IsShareDfsJunction(This,pbIsDfsJunction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesShareInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSuspend_INTERFACE_DEFINED__
#define __IOfflineFilesSuspend_INTERFACE_DEFINED__

/* interface IOfflineFilesSuspend */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSuspend;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62c4560f-bc0b-48ca-ad9d-34cb528d99a9")
    IOfflineFilesSuspend : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SuspendRoot( 
            /* [in] */ BOOL bSuspend) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSuspendVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSuspend * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSuspend * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSuspend * This);
        
        HRESULT ( STDMETHODCALLTYPE *SuspendRoot )( 
            IOfflineFilesSuspend * This,
            /* [in] */ BOOL bSuspend);
        
        END_INTERFACE
    } IOfflineFilesSuspendVtbl;

    interface IOfflineFilesSuspend
    {
        CONST_VTBL struct IOfflineFilesSuspendVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSuspend_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSuspend_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSuspend_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSuspend_SuspendRoot(This,bSuspend)	\
    ( (This)->lpVtbl -> SuspendRoot(This,bSuspend) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSuspend_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSuspendInfo_INTERFACE_DEFINED__
#define __IOfflineFilesSuspendInfo_INTERFACE_DEFINED__

/* interface IOfflineFilesSuspendInfo */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSuspendInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a457c25b-4e9c-4b04-85af-8932ccd97889")
    IOfflineFilesSuspendInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsSuspended( 
            /* [out] */ __RPC__out BOOL *pbSuspended,
            /* [out] */ __RPC__out BOOL *pbSuspendedRoot) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSuspendInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSuspendInfo * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSuspendInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSuspendInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsSuspended )( 
            IOfflineFilesSuspendInfo * This,
            /* [out] */ __RPC__out BOOL *pbSuspended,
            /* [out] */ __RPC__out BOOL *pbSuspendedRoot);
        
        END_INTERFACE
    } IOfflineFilesSuspendInfoVtbl;

    interface IOfflineFilesSuspendInfo
    {
        CONST_VTBL struct IOfflineFilesSuspendInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSuspendInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSuspendInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSuspendInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSuspendInfo_IsSuspended(This,pbSuspended,pbSuspendedRoot)	\
    ( (This)->lpVtbl -> IsSuspended(This,pbSuspended,pbSuspendedRoot) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSuspendInfo_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesSetting_INTERFACE_DEFINED__
#define __IOfflineFilesSetting_INTERFACE_DEFINED__

/* interface IOfflineFilesSetting */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesSetting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D871D3F7-F613-48a1-827E-7A34E560FFF6")
    IOfflineFilesSetting : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValueType( 
            /* [out] */ __RPC__out OFFLINEFILES_SETTING_VALUE_TYPE *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreference( 
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [in] */ DWORD dwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreferenceScope( 
            /* [out] */ __RPC__out DWORD *pdwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPreference( 
            /* [in] */ __RPC__in const VARIANT *pvarValue,
            /* [in] */ DWORD dwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePreference( 
            /* [in] */ DWORD dwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolicy( 
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [in] */ DWORD dwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolicyScope( 
            /* [out] */ __RPC__out DWORD *pdwScope) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [out] */ __RPC__out BOOL *pbSetByPolicy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesSettingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesSetting * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesSetting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesSetting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IOfflineFilesSetting * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetValueType )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out OFFLINEFILES_SETTING_VALUE_TYPE *pType);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreference )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [in] */ DWORD dwScope);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreferenceScope )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out DWORD *pdwScope);
        
        HRESULT ( STDMETHODCALLTYPE *SetPreference )( 
            IOfflineFilesSetting * This,
            /* [in] */ __RPC__in const VARIANT *pvarValue,
            /* [in] */ DWORD dwScope);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePreference )( 
            IOfflineFilesSetting * This,
            /* [in] */ DWORD dwScope);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolicy )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [in] */ DWORD dwScope);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolicyScope )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out DWORD *pdwScope);
        
        HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IOfflineFilesSetting * This,
            /* [out] */ __RPC__out VARIANT *pvarValue,
            /* [out] */ __RPC__out BOOL *pbSetByPolicy);
        
        END_INTERFACE
    } IOfflineFilesSettingVtbl;

    interface IOfflineFilesSetting
    {
        CONST_VTBL struct IOfflineFilesSettingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesSetting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesSetting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesSetting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesSetting_GetName(This,ppszName)	\
    ( (This)->lpVtbl -> GetName(This,ppszName) ) 

#define IOfflineFilesSetting_GetValueType(This,pType)	\
    ( (This)->lpVtbl -> GetValueType(This,pType) ) 

#define IOfflineFilesSetting_GetPreference(This,pvarValue,dwScope)	\
    ( (This)->lpVtbl -> GetPreference(This,pvarValue,dwScope) ) 

#define IOfflineFilesSetting_GetPreferenceScope(This,pdwScope)	\
    ( (This)->lpVtbl -> GetPreferenceScope(This,pdwScope) ) 

#define IOfflineFilesSetting_SetPreference(This,pvarValue,dwScope)	\
    ( (This)->lpVtbl -> SetPreference(This,pvarValue,dwScope) ) 

#define IOfflineFilesSetting_DeletePreference(This,dwScope)	\
    ( (This)->lpVtbl -> DeletePreference(This,dwScope) ) 

#define IOfflineFilesSetting_GetPolicy(This,pvarValue,dwScope)	\
    ( (This)->lpVtbl -> GetPolicy(This,pvarValue,dwScope) ) 

#define IOfflineFilesSetting_GetPolicyScope(This,pdwScope)	\
    ( (This)->lpVtbl -> GetPolicyScope(This,pdwScope) ) 

#define IOfflineFilesSetting_GetValue(This,pvarValue,pbSetByPolicy)	\
    ( (This)->lpVtbl -> GetValue(This,pvarValue,pbSetByPolicy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesSetting_INTERFACE_DEFINED__ */


#ifndef __IEnumOfflineFilesSettings_INTERFACE_DEFINED__
#define __IEnumOfflineFilesSettings_INTERFACE_DEFINED__

/* interface IEnumOfflineFilesSettings */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumOfflineFilesSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("729680C4-1A38-47bc-9E5C-02C51562AC30")
    IEnumOfflineFilesSettings : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IOfflineFilesSetting **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesSettings **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumOfflineFilesSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumOfflineFilesSettings * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumOfflineFilesSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumOfflineFilesSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumOfflineFilesSettings * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IOfflineFilesSetting **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumOfflineFilesSettings * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumOfflineFilesSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumOfflineFilesSettings * This,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesSettings **ppenum);
        
        END_INTERFACE
    } IEnumOfflineFilesSettingsVtbl;

    interface IEnumOfflineFilesSettings
    {
        CONST_VTBL struct IEnumOfflineFilesSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOfflineFilesSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumOfflineFilesSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumOfflineFilesSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumOfflineFilesSettings_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumOfflineFilesSettings_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumOfflineFilesSettings_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumOfflineFilesSettings_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumOfflineFilesSettings_INTERFACE_DEFINED__ */


#ifndef __IOfflineFilesCache_INTERFACE_DEFINED__
#define __IOfflineFilesCache_INTERFACE_DEFINED__

/* interface IOfflineFilesCache */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IOfflineFilesCache;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("855d6203-7914-48b9-8d40-4c56f5acffc5")
    IOfflineFilesCache : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Synchronize( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwSyncControl,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncConflictHandler *pISyncConflictHandler,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress,
            /* [unique][in] */ __RPC__in_opt GUID *pSyncId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteItems( 
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSimpleProgress *pIProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteItemsForUser( 
            /* [string][in] */ __RPC__in LPCWSTR pszUser,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSimpleProgress *pIProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pin( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bDeep,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwPinControlFlags,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unpin( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bDeep,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwPinControlFlags,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEncryptionStatus( 
            /* [out] */ __RPC__out BOOL *pbEncrypted,
            /* [out] */ __RPC__out BOOL *pbPartial) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Encrypt( 
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ BOOL bEncrypt,
            /* [in] */ DWORD dwEncryptionControlFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindItem( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindItemEx( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeDirFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeDirFilter,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RenameItem( 
            /* [string][in] */ __RPC__in LPCWSTR pszPathOriginal,
            /* [string][in] */ __RPC__in LPCWSTR pszPathNew,
            /* [in] */ BOOL bReplaceIfExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDiskSpaceInformation( 
            /* [out] */ __RPC__out ULONGLONG *pcbVolumeTotal,
            /* [out] */ __RPC__out ULONGLONG *pcbLimit,
            /* [out] */ __RPC__out ULONGLONG *pcbUsed,
            /* [out] */ __RPC__out ULONGLONG *pcbUnpinnedLimit,
            /* [out] */ __RPC__out ULONGLONG *pcbUnpinnedUsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDiskSpaceLimits( 
            /* [in] */ ULONGLONG cbLimit,
            /* [in] */ ULONGLONG cbUnpinnedLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessAdminPinPolicy( 
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pPinProgress,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pUnpinProgress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingObject( 
            /* [string][in] */ __RPC__in LPCWSTR pszSettingName,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSetting **ppSetting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSettingObjects( 
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesSettings **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPathCacheable( 
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbCacheable,
            /* [out] */ __RPC__out OFFLINEFILES_CACHING_MODE *pShareCachingMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOfflineFilesCacheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfflineFilesCache * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfflineFilesCache * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfflineFilesCache * This);
        
        HRESULT ( STDMETHODCALLTYPE *Synchronize )( 
            IOfflineFilesCache * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwSyncControl,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncConflictHandler *pISyncConflictHandler,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress,
            /* [unique][in] */ __RPC__in_opt GUID *pSyncId);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteItems )( 
            IOfflineFilesCache * This,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSimpleProgress *pIProgress);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteItemsForUser )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszUser,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ DWORD dwFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSimpleProgress *pIProgress);
        
        HRESULT ( STDMETHODCALLTYPE *Pin )( 
            IOfflineFilesCache * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bDeep,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwPinControlFlags,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress);
        
        HRESULT ( STDMETHODCALLTYPE *Unpin )( 
            IOfflineFilesCache * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [string][size_is][in] */ __RPC__in_ecount_full(cPaths) LPCWSTR *rgpszPaths,
            /* [in] */ ULONG cPaths,
            /* [in] */ BOOL bDeep,
            /* [in] */ BOOL bAsync,
            /* [in] */ DWORD dwPinControlFlags,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress);
        
        HRESULT ( STDMETHODCALLTYPE *GetEncryptionStatus )( 
            IOfflineFilesCache * This,
            /* [out] */ __RPC__out BOOL *pbEncrypted,
            /* [out] */ __RPC__out BOOL *pbPartial);
        
        HRESULT ( STDMETHODCALLTYPE *Encrypt )( 
            IOfflineFilesCache * This,
            /* [unique][in] */ __RPC__in_opt HWND hwndParent,
            /* [in] */ BOOL bEncrypt,
            /* [in] */ DWORD dwEncryptionControlFlags,
            /* [in] */ BOOL bAsync,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pIProgress);
        
        HRESULT ( STDMETHODCALLTYPE *FindItem )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindItemEx )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pIncludeDirFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeFileFilter,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesItemFilter *pExcludeDirFilter,
            /* [in] */ DWORD dwQueryFlags,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *RenameItem )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPathOriginal,
            /* [string][in] */ __RPC__in LPCWSTR pszPathNew,
            /* [in] */ BOOL bReplaceIfExists);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IOfflineFilesCache * This,
            /* [string][out] */ __RPC__deref_out_opt_string LPWSTR *ppszPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetDiskSpaceInformation )( 
            IOfflineFilesCache * This,
            /* [out] */ __RPC__out ULONGLONG *pcbVolumeTotal,
            /* [out] */ __RPC__out ULONGLONG *pcbLimit,
            /* [out] */ __RPC__out ULONGLONG *pcbUsed,
            /* [out] */ __RPC__out ULONGLONG *pcbUnpinnedLimit,
            /* [out] */ __RPC__out ULONGLONG *pcbUnpinnedUsed);
        
        HRESULT ( STDMETHODCALLTYPE *SetDiskSpaceLimits )( 
            IOfflineFilesCache * This,
            /* [in] */ ULONGLONG cbLimit,
            /* [in] */ ULONGLONG cbUnpinnedLimit);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessAdminPinPolicy )( 
            IOfflineFilesCache * This,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pPinProgress,
            /* [unique][in] */ __RPC__in_opt IOfflineFilesSyncProgress *pUnpinProgress);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingObject )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszSettingName,
            /* [out] */ __RPC__deref_out_opt IOfflineFilesSetting **ppSetting);
        
        HRESULT ( STDMETHODCALLTYPE *EnumSettingObjects )( 
            IOfflineFilesCache * This,
            /* [out] */ __RPC__deref_out_opt IEnumOfflineFilesSettings **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *IsPathCacheable )( 
            IOfflineFilesCache * This,
            /* [string][in] */ __RPC__in LPCWSTR pszPath,
            /* [out] */ __RPC__out BOOL *pbCacheable,
            /* [out] */ __RPC__out OFFLINEFILES_CACHING_MODE *pShareCachingMode);
        
        END_INTERFACE
    } IOfflineFilesCacheVtbl;

    interface IOfflineFilesCache
    {
        CONST_VTBL struct IOfflineFilesCacheVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfflineFilesCache_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfflineFilesCache_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfflineFilesCache_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfflineFilesCache_Synchronize(This,hwndParent,rgpszPaths,cPaths,bAsync,dwSyncControl,pISyncConflictHandler,pIProgress,pSyncId)	\
    ( (This)->lpVtbl -> Synchronize(This,hwndParent,rgpszPaths,cPaths,bAsync,dwSyncControl,pISyncConflictHandler,pIProgress,pSyncId) ) 

#define IOfflineFilesCache_DeleteItems(This,rgpszPaths,cPaths,dwFlags,bAsync,pIProgress)	\
    ( (This)->lpVtbl -> DeleteItems(This,rgpszPaths,cPaths,dwFlags,bAsync,pIProgress) ) 

#define IOfflineFilesCache_DeleteItemsForUser(This,pszUser,rgpszPaths,cPaths,dwFlags,bAsync,pIProgress)	\
    ( (This)->lpVtbl -> DeleteItemsForUser(This,pszUser,rgpszPaths,cPaths,dwFlags,bAsync,pIProgress) ) 

#define IOfflineFilesCache_Pin(This,hwndParent,rgpszPaths,cPaths,bDeep,bAsync,dwPinControlFlags,pIProgress)	\
    ( (This)->lpVtbl -> Pin(This,hwndParent,rgpszPaths,cPaths,bDeep,bAsync,dwPinControlFlags,pIProgress) ) 

#define IOfflineFilesCache_Unpin(This,hwndParent,rgpszPaths,cPaths,bDeep,bAsync,dwPinControlFlags,pIProgress)	\
    ( (This)->lpVtbl -> Unpin(This,hwndParent,rgpszPaths,cPaths,bDeep,bAsync,dwPinControlFlags,pIProgress) ) 

#define IOfflineFilesCache_GetEncryptionStatus(This,pbEncrypted,pbPartial)	\
    ( (This)->lpVtbl -> GetEncryptionStatus(This,pbEncrypted,pbPartial) ) 

#define IOfflineFilesCache_Encrypt(This,hwndParent,bEncrypt,dwEncryptionControlFlags,bAsync,pIProgress)	\
    ( (This)->lpVtbl -> Encrypt(This,hwndParent,bEncrypt,dwEncryptionControlFlags,bAsync,pIProgress) ) 

#define IOfflineFilesCache_FindItem(This,pszPath,dwQueryFlags,ppItem)	\
    ( (This)->lpVtbl -> FindItem(This,pszPath,dwQueryFlags,ppItem) ) 

#define IOfflineFilesCache_FindItemEx(This,pszPath,pIncludeFileFilter,pIncludeDirFilter,pExcludeFileFilter,pExcludeDirFilter,dwQueryFlags,ppItem)	\
    ( (This)->lpVtbl -> FindItemEx(This,pszPath,pIncludeFileFilter,pIncludeDirFilter,pExcludeFileFilter,pExcludeDirFilter,dwQueryFlags,ppItem) ) 

#define IOfflineFilesCache_RenameItem(This,pszPathOriginal,pszPathNew,bReplaceIfExists)	\
    ( (This)->lpVtbl -> RenameItem(This,pszPathOriginal,pszPathNew,bReplaceIfExists) ) 

#define IOfflineFilesCache_GetLocation(This,ppszPath)	\
    ( (This)->lpVtbl -> GetLocation(This,ppszPath) ) 

#define IOfflineFilesCache_GetDiskSpaceInformation(This,pcbVolumeTotal,pcbLimit,pcbUsed,pcbUnpinnedLimit,pcbUnpinnedUsed)	\
    ( (This)->lpVtbl -> GetDiskSpaceInformation(This,pcbVolumeTotal,pcbLimit,pcbUsed,pcbUnpinnedLimit,pcbUnpinnedUsed) ) 

#define IOfflineFilesCache_SetDiskSpaceLimits(This,cbLimit,cbUnpinnedLimit)	\
    ( (This)->lpVtbl -> SetDiskSpaceLimits(This,cbLimit,cbUnpinnedLimit) ) 

#define IOfflineFilesCache_ProcessAdminPinPolicy(This,pPinProgress,pUnpinProgress)	\
    ( (This)->lpVtbl -> ProcessAdminPinPolicy(This,pPinProgress,pUnpinProgress) ) 

#define IOfflineFilesCache_GetSettingObject(This,pszSettingName,ppSetting)	\
    ( (This)->lpVtbl -> GetSettingObject(This,pszSettingName,ppSetting) ) 

#define IOfflineFilesCache_EnumSettingObjects(This,ppEnum)	\
    ( (This)->lpVtbl -> EnumSettingObjects(This,ppEnum) ) 

#define IOfflineFilesCache_IsPathCacheable(This,pszPath,pbCacheable,pShareCachingMode)	\
    ( (This)->lpVtbl -> IsPathCacheable(This,pszPath,pbCacheable,pShareCachingMode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfflineFilesCache_INTERFACE_DEFINED__ */



#ifndef __OfflineFilesObjects_LIBRARY_DEFINED__
#define __OfflineFilesObjects_LIBRARY_DEFINED__

/* library OfflineFilesObjects */
/* [version][lcid][helpstring][uuid] */ 


EXTERN_C const IID LIBID_OfflineFilesObjects;

EXTERN_C const CLSID CLSID_OfflineFilesSetting;

#ifdef __cplusplus

class DECLSPEC_UUID("FD3659E9-A920-4123-AD64-7FC76C7AACDF")
OfflineFilesSetting;
#endif

EXTERN_C const CLSID CLSID_OfflineFilesCache;

#ifdef __cplusplus

class DECLSPEC_UUID("48C6BE7C-3871-43cc-B46F-1449A1BB2FF3")
OfflineFilesCache;
#endif
#endif /* __OfflineFilesObjects_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



