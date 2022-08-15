

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for vdshwprv.idl:
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

#ifndef __vdshwprv_h__
#define __vdshwprv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IEnumVdsObject_FWD_DEFINED__
#define __IEnumVdsObject_FWD_DEFINED__
typedef interface IEnumVdsObject IEnumVdsObject;
#endif 	/* __IEnumVdsObject_FWD_DEFINED__ */


#ifndef __IVdsAsync_FWD_DEFINED__
#define __IVdsAsync_FWD_DEFINED__
typedef interface IVdsAsync IVdsAsync;
#endif 	/* __IVdsAsync_FWD_DEFINED__ */


#ifndef __IVdsAdviseSink_FWD_DEFINED__
#define __IVdsAdviseSink_FWD_DEFINED__
typedef interface IVdsAdviseSink IVdsAdviseSink;
#endif 	/* __IVdsAdviseSink_FWD_DEFINED__ */


#ifndef __IVdsProvider_FWD_DEFINED__
#define __IVdsProvider_FWD_DEFINED__
typedef interface IVdsProvider IVdsProvider;
#endif 	/* __IVdsProvider_FWD_DEFINED__ */


#ifndef __IVdsProviderSupport_FWD_DEFINED__
#define __IVdsProviderSupport_FWD_DEFINED__
typedef interface IVdsProviderSupport IVdsProviderSupport;
#endif 	/* __IVdsProviderSupport_FWD_DEFINED__ */


#ifndef __IVdsProviderPrivate_FWD_DEFINED__
#define __IVdsProviderPrivate_FWD_DEFINED__
typedef interface IVdsProviderPrivate IVdsProviderPrivate;
#endif 	/* __IVdsProviderPrivate_FWD_DEFINED__ */


#ifndef __IVdsHwProvider_FWD_DEFINED__
#define __IVdsHwProvider_FWD_DEFINED__
typedef interface IVdsHwProvider IVdsHwProvider;
#endif 	/* __IVdsHwProvider_FWD_DEFINED__ */


#ifndef __IVdsHwProviderType_FWD_DEFINED__
#define __IVdsHwProviderType_FWD_DEFINED__
typedef interface IVdsHwProviderType IVdsHwProviderType;
#endif 	/* __IVdsHwProviderType_FWD_DEFINED__ */


#ifndef __IVdsSubSystem_FWD_DEFINED__
#define __IVdsSubSystem_FWD_DEFINED__
typedef interface IVdsSubSystem IVdsSubSystem;
#endif 	/* __IVdsSubSystem_FWD_DEFINED__ */


#ifndef __IVdsSubSystemNaming_FWD_DEFINED__
#define __IVdsSubSystemNaming_FWD_DEFINED__
typedef interface IVdsSubSystemNaming IVdsSubSystemNaming;
#endif 	/* __IVdsSubSystemNaming_FWD_DEFINED__ */


#ifndef __IVdsSubSystemIscsi_FWD_DEFINED__
#define __IVdsSubSystemIscsi_FWD_DEFINED__
typedef interface IVdsSubSystemIscsi IVdsSubSystemIscsi;
#endif 	/* __IVdsSubSystemIscsi_FWD_DEFINED__ */


#ifndef __IVdsControllerPort_FWD_DEFINED__
#define __IVdsControllerPort_FWD_DEFINED__
typedef interface IVdsControllerPort IVdsControllerPort;
#endif 	/* __IVdsControllerPort_FWD_DEFINED__ */


#ifndef __IVdsController_FWD_DEFINED__
#define __IVdsController_FWD_DEFINED__
typedef interface IVdsController IVdsController;
#endif 	/* __IVdsController_FWD_DEFINED__ */


#ifndef __IVdsControllerControllerPort_FWD_DEFINED__
#define __IVdsControllerControllerPort_FWD_DEFINED__
typedef interface IVdsControllerControllerPort IVdsControllerControllerPort;
#endif 	/* __IVdsControllerControllerPort_FWD_DEFINED__ */


#ifndef __IVdsDrive_FWD_DEFINED__
#define __IVdsDrive_FWD_DEFINED__
typedef interface IVdsDrive IVdsDrive;
#endif 	/* __IVdsDrive_FWD_DEFINED__ */


#ifndef __IVdsLun_FWD_DEFINED__
#define __IVdsLun_FWD_DEFINED__
typedef interface IVdsLun IVdsLun;
#endif 	/* __IVdsLun_FWD_DEFINED__ */


#ifndef __IVdsLunNaming_FWD_DEFINED__
#define __IVdsLunNaming_FWD_DEFINED__
typedef interface IVdsLunNaming IVdsLunNaming;
#endif 	/* __IVdsLunNaming_FWD_DEFINED__ */


#ifndef __IVdsLunControllerPorts_FWD_DEFINED__
#define __IVdsLunControllerPorts_FWD_DEFINED__
typedef interface IVdsLunControllerPorts IVdsLunControllerPorts;
#endif 	/* __IVdsLunControllerPorts_FWD_DEFINED__ */


#ifndef __IVdsLunMpio_FWD_DEFINED__
#define __IVdsLunMpio_FWD_DEFINED__
typedef interface IVdsLunMpio IVdsLunMpio;
#endif 	/* __IVdsLunMpio_FWD_DEFINED__ */


#ifndef __IVdsLunIscsi_FWD_DEFINED__
#define __IVdsLunIscsi_FWD_DEFINED__
typedef interface IVdsLunIscsi IVdsLunIscsi;
#endif 	/* __IVdsLunIscsi_FWD_DEFINED__ */


#ifndef __IVdsLunPlex_FWD_DEFINED__
#define __IVdsLunPlex_FWD_DEFINED__
typedef interface IVdsLunPlex IVdsLunPlex;
#endif 	/* __IVdsLunPlex_FWD_DEFINED__ */


#ifndef __IVdsIscsiPortal_FWD_DEFINED__
#define __IVdsIscsiPortal_FWD_DEFINED__
typedef interface IVdsIscsiPortal IVdsIscsiPortal;
#endif 	/* __IVdsIscsiPortal_FWD_DEFINED__ */


#ifndef __IVdsIscsiTarget_FWD_DEFINED__
#define __IVdsIscsiTarget_FWD_DEFINED__
typedef interface IVdsIscsiTarget IVdsIscsiTarget;
#endif 	/* __IVdsIscsiTarget_FWD_DEFINED__ */


#ifndef __IVdsIscsiPortalGroup_FWD_DEFINED__
#define __IVdsIscsiPortalGroup_FWD_DEFINED__
typedef interface IVdsIscsiPortalGroup IVdsIscsiPortalGroup;
#endif 	/* __IVdsIscsiPortalGroup_FWD_DEFINED__ */


#ifndef __IVdsMaintenance_FWD_DEFINED__
#define __IVdsMaintenance_FWD_DEFINED__
typedef interface IVdsMaintenance IVdsMaintenance;
#endif 	/* __IVdsMaintenance_FWD_DEFINED__ */


#ifndef __IVdsHwProviderPrivate_FWD_DEFINED__
#define __IVdsHwProviderPrivate_FWD_DEFINED__
typedef interface IVdsHwProviderPrivate IVdsHwProviderPrivate;
#endif 	/* __IVdsHwProviderPrivate_FWD_DEFINED__ */


#ifndef __IVdsHwProviderPrivateMpio_FWD_DEFINED__
#define __IVdsHwProviderPrivateMpio_FWD_DEFINED__
typedef interface IVdsHwProviderPrivateMpio IVdsHwProviderPrivateMpio;
#endif 	/* __IVdsHwProviderPrivateMpio_FWD_DEFINED__ */


#ifndef __IVdsAdmin_FWD_DEFINED__
#define __IVdsAdmin_FWD_DEFINED__
typedef interface IVdsAdmin IVdsAdmin;
#endif 	/* __IVdsAdmin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "vdserr.h"
#include "vdslun.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vdshwprv_0000_0000 */
/* [local] */ 

//+--------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (c) 2000 Microsoft Corporation.
//
//---------------------------------------------------------------





typedef GUID VDS_OBJECT_ID;

typedef 
enum _VDS_OBJECT_TYPE
    {	VDS_OT_UNKNOWN	= 0,
	VDS_OT_PROVIDER	= 1,
	VDS_OT_PACK	= 10,
	VDS_OT_VOLUME	= 11,
	VDS_OT_VOLUME_PLEX	= 12,
	VDS_OT_DISK	= 13,
	VDS_OT_SUB_SYSTEM	= 30,
	VDS_OT_CONTROLLER	= 31,
	VDS_OT_DRIVE	= 32,
	VDS_OT_LUN	= 33,
	VDS_OT_LUN_PLEX	= 34,
	VDS_OT_PORT	= 35,
	VDS_OT_PORTAL	= 36,
	VDS_OT_TARGET	= 37,
	VDS_OT_PORTAL_GROUP	= 38,
	VDS_OT_HBAPORT	= 90,
	VDS_OT_INIT_ADAPTER	= 91,
	VDS_OT_INIT_PORTAL	= 92,
	VDS_OT_ASYNC	= 100,
	VDS_OT_ENUM	= 101
    } 	VDS_OBJECT_TYPE;

typedef 
enum _VDS_PROVIDER_TYPE
    {	VDS_PT_UNKNOWN	= 0,
	VDS_PT_SOFTWARE	= 1,
	VDS_PT_HARDWARE	= 2
    } 	VDS_PROVIDER_TYPE;

typedef 
enum _VDS_PROVIDER_FLAG
    {	VDS_PF_DYNAMIC	= 0x1,
	VDS_PF_INTERNAL_HARDWARE_PROVIDER	= 0x2,
	VDS_PF_ONE_DISK_ONLY_PER_PACK	= 0x4,
	VDS_PF_ONE_PACK_ONLINE_ONLY	= 0x8,
	VDS_PF_VOLUME_SPACE_MUST_BE_CONTIGUOUS	= 0x10,
	VDS_PF_SUPPORT_DYNAMIC	= 0x80000000,
	VDS_PF_SUPPORT_FAULT_TOLERANT	= 0x40000000,
	VDS_PF_SUPPORT_DYNAMIC_1394	= 0x20000000
    } 	VDS_PROVIDER_FLAG;

typedef 
enum _VDS_RECOVER_ACTION
    {	VDS_RA_UNKNOWN	= 0,
	VDS_RA_REFRESH	= 1,
	VDS_RA_RESTART	= 2
    } 	VDS_RECOVER_ACTION;

typedef 
enum _VDS_NOTIFICATION_TARGET_TYPE
    {	VDS_NTT_UNKNOWN	= 0,
	VDS_NTT_PACK	= VDS_OT_PACK,
	VDS_NTT_VOLUME	= VDS_OT_VOLUME,
	VDS_NTT_DISK	= VDS_OT_DISK,
	VDS_NTT_PARTITION	= 60,
	VDS_NTT_DRIVE_LETTER	= 61,
	VDS_NTT_FILE_SYSTEM	= 62,
	VDS_NTT_MOUNT_POINT	= 63,
	VDS_NTT_SUB_SYSTEM	= VDS_OT_SUB_SYSTEM,
	VDS_NTT_CONTROLLER	= VDS_OT_CONTROLLER,
	VDS_NTT_DRIVE	= VDS_OT_DRIVE,
	VDS_NTT_LUN	= VDS_OT_LUN,
	VDS_NTT_PORT	= VDS_OT_PORT,
	VDS_NTT_PORTAL	= VDS_OT_PORTAL,
	VDS_NTT_TARGET	= VDS_OT_TARGET,
	VDS_NTT_PORTAL_GROUP	= VDS_OT_PORTAL_GROUP,
	VDS_NTT_SERVICE	= 200
    } 	VDS_NOTIFICATION_TARGET_TYPE;

#define	VDS_NF_PACK_ARRIVE	( 1 )

#define	VDS_NF_PACK_DEPART	( 2 )

#define	VDS_NF_PACK_MODIFY	( 3 )

#define	VDS_NF_VOLUME_ARRIVE	( 4 )

#define	VDS_NF_VOLUME_DEPART	( 5 )

#define	VDS_NF_VOLUME_MODIFY	( 6 )

#define	VDS_NF_VOLUME_REBUILDING_PROGRESS	( 7 )

#define	VDS_NF_DISK_ARRIVE	( 8 )

#define	VDS_NF_DISK_DEPART	( 9 )

#define	VDS_NF_DISK_MODIFY	( 10 )

#define	VDS_NF_PARTITION_ARRIVE	( 11 )

#define	VDS_NF_PARTITION_DEPART	( 12 )

#define	VDS_NF_PARTITION_MODIFY	( 13 )

#define	VDS_NF_SUB_SYSTEM_ARRIVE	( 101 )

#define	VDS_NF_SUB_SYSTEM_DEPART	( 102 )

#define	VDS_NF_CONTROLLER_ARRIVE	( 103 )

#define	VDS_NF_CONTROLLER_DEPART	( 104 )

#define	VDS_NF_DRIVE_ARRIVE	( 105 )

#define	VDS_NF_DRIVE_DEPART	( 106 )

#define	VDS_NF_DRIVE_MODIFY	( 107 )

#define	VDS_NF_LUN_ARRIVE	( 108 )

#define	VDS_NF_LUN_DEPART	( 109 )

#define	VDS_NF_LUN_MODIFY	( 110 )

#define	VDS_NF_PORT_ARRIVE	( 121 )

#define	VDS_NF_PORT_DEPART	( 122 )

#define	VDS_NF_PORTAL_ARRIVE	( 123 )

#define	VDS_NF_PORTAL_DEPART	( 124 )

#define	VDS_NF_PORTAL_MODIFY	( 125 )

#define	VDS_NF_TARGET_ARRIVE	( 126 )

#define	VDS_NF_TARGET_DEPART	( 127 )

#define	VDS_NF_TARGET_MODIFY	( 128 )

#define	VDS_NF_PORTAL_GROUP_ARRIVE	( 129 )

#define	VDS_NF_PORTAL_GROUP_DEPART	( 130 )

#define	VDS_NF_PORTAL_GROUP_MODIFY	( 131 )

#define	VDS_NF_SUB_SYSTEM_MODIFY	( 151 )

#define	VDS_NF_DRIVE_LETTER_FREE	( 201 )

#define	VDS_NF_DRIVE_LETTER_ASSIGN	( 202 )

#define	VDS_NF_FILE_SYSTEM_MODIFY	( 203 )

#define	VDS_NF_FILE_SYSTEM_FORMAT_PROGRESS	( 204 )

#define	VDS_NF_MOUNT_POINTS_CHANGE	( 205 )

#define	VDS_NF_FILE_SYSTEM_SHRINKING_PROGRESS	( 206 )

#define	VDS_NF_SERVICE_OUT_OF_SYNC	( 301 )

typedef struct _VDS_PACK_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID packId;
    } 	VDS_PACK_NOTIFICATION;

typedef struct _VDS_DISK_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID diskId;
    } 	VDS_DISK_NOTIFICATION;

typedef struct _VDS_VOLUME_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID volumeId;
    VDS_OBJECT_ID plexId;
    ULONG ulPercentCompleted;
    } 	VDS_VOLUME_NOTIFICATION;

typedef struct _VDS_PARTITION_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID diskId;
    ULONGLONG ullOffset;
    } 	VDS_PARTITION_NOTIFICATION;

typedef struct _VDS_SERVICE_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_RECOVER_ACTION action;
    } 	VDS_SERVICE_NOTIFICATION;

typedef struct _VDS_DRIVE_LETTER_NOTIFICATION
    {
    ULONG ulEvent;
    WCHAR wcLetter;
    VDS_OBJECT_ID volumeId;
    } 	VDS_DRIVE_LETTER_NOTIFICATION;

typedef struct _VDS_FILE_SYSTEM_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID volumeId;
    DWORD dwPercentCompleted;
    } 	VDS_FILE_SYSTEM_NOTIFICATION;

typedef struct _VDS_MOUNT_POINT_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID volumeId;
    } 	VDS_MOUNT_POINT_NOTIFICATION;

typedef struct _VDS_SUB_SYSTEM_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID subSystemId;
    } 	VDS_SUB_SYSTEM_NOTIFICATION;

typedef struct _VDS_CONTROLLER_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID controllerId;
    } 	VDS_CONTROLLER_NOTIFICATION;

typedef struct _VDS_DRIVE_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID driveId;
    } 	VDS_DRIVE_NOTIFICATION;

typedef struct _VDS_LUN_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID LunId;
    } 	VDS_LUN_NOTIFICATION;

typedef struct _VDS_PORT_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID portId;
    } 	VDS_PORT_NOTIFICATION;

typedef struct _VDS_PORTAL_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID portalId;
    } 	VDS_PORTAL_NOTIFICATION;

typedef struct _VDS_TARGET_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID targetId;
    } 	VDS_TARGET_NOTIFICATION;

typedef struct _VDS_PORTAL_GROUP_NOTIFICATION
    {
    ULONG ulEvent;
    VDS_OBJECT_ID portalGroupId;
    } 	VDS_PORTAL_GROUP_NOTIFICATION;

typedef struct _VDS_NOTIFICATION
    {
    VDS_NOTIFICATION_TARGET_TYPE objectType;
    /* [switch_type] */ union 
        {
        VDS_PACK_NOTIFICATION Pack;
        VDS_DISK_NOTIFICATION Disk;
        VDS_VOLUME_NOTIFICATION Volume;
        VDS_PARTITION_NOTIFICATION Partition;
        VDS_DRIVE_LETTER_NOTIFICATION Letter;
        VDS_FILE_SYSTEM_NOTIFICATION FileSystem;
        VDS_MOUNT_POINT_NOTIFICATION MountPoint;
        VDS_SUB_SYSTEM_NOTIFICATION SubSystem;
        VDS_CONTROLLER_NOTIFICATION Controller;
        VDS_DRIVE_NOTIFICATION Drive;
        VDS_LUN_NOTIFICATION Lun;
        VDS_PORT_NOTIFICATION Port;
        VDS_PORTAL_NOTIFICATION Portal;
        VDS_TARGET_NOTIFICATION Target;
        VDS_PORTAL_GROUP_NOTIFICATION PortalGroup;
        VDS_SERVICE_NOTIFICATION Service;
         /* Empty union arm */ 
        } 	;
    } 	VDS_NOTIFICATION;

typedef 
enum _VDS_ASYNC_OUTPUT_TYPE
    {	VDS_ASYNCOUT_UNKNOWN	= 0,
	VDS_ASYNCOUT_CREATEVOLUME	= 1,
	VDS_ASYNCOUT_EXTENDVOLUME	= 2,
	VDS_ASYNCOUT_SHRINKVOLUME	= 3,
	VDS_ASYNCOUT_ADDVOLUMEPLEX	= 4,
	VDS_ASYNCOUT_BREAKVOLUMEPLEX	= 5,
	VDS_ASYNCOUT_REMOVEVOLUMEPLEX	= 6,
	VDS_ASYNCOUT_REPAIRVOLUMEPLEX	= 7,
	VDS_ASYNCOUT_RECOVERPACK	= 8,
	VDS_ASYNCOUT_REPLACEDISK	= 9,
	VDS_ASYNCOUT_CREATEPARTITION	= 10,
	VDS_ASYNCOUT_CLEAN	= 11,
	VDS_ASYNCOUT_CREATELUN	= 50,
	VDS_ASYNCOUT_ADDLUNPLEX	= 52,
	VDS_ASYNCOUT_REMOVELUNPLEX	= 53,
	VDS_ASYNCOUT_EXTENDLUN	= 54,
	VDS_ASYNCOUT_SHRINKLUN	= 55,
	VDS_ASYNCOUT_RECOVERLUN	= 56,
	VDS_ASYNCOUT_LOGINTOTARGET	= 60,
	VDS_ASYNCOUT_LOGOUTFROMTARGET	= 61,
	VDS_ASYNCOUT_CREATETARGET	= 62,
	VDS_ASYNCOUT_CREATEPORTALGROUP	= 63,
	VDS_ASYNCOUT_DELETETARGET	= 64,
	VDS_ASYNCOUT_ADDPORTAL	= 65,
	VDS_ASYNCOUT_REMOVEPORTAL	= 66,
	VDS_ASYNCOUT_DELETEPORTALGROUP	= 67,
	VDS_ASYNCOUT_FORMAT	= 101
    } 	VDS_ASYNC_OUTPUT_TYPE;

typedef struct _VDS_ASYNC_OUTPUT
    {
    VDS_ASYNC_OUTPUT_TYPE type;
    /* [switch_type] */ union 
        {
        struct _cp
            {
            ULONGLONG ullOffset;
            VDS_OBJECT_ID volumeId;
            } 	cp;
        struct _cv
            {
            IUnknown *pVolumeUnk;
            } 	cv;
        struct _bvp
            {
            IUnknown *pVolumeUnk;
            } 	bvp;
        struct _sv
            {
            ULONGLONG ullReclaimedBytes;
            } 	sv;
        struct _cl
            {
            IUnknown *pLunUnk;
            } 	cl;
        struct _ct
            {
            IUnknown *pTargetUnk;
            } 	ct;
        struct _cpg
            {
            IUnknown *pPortalGroupUnk;
            } 	cpg;
         /* Empty union arm */ 
        } 	;
    } 	VDS_ASYNC_OUTPUT;

typedef USHORT VDS_ISCSI_PORTALGROUP_TAG;

typedef 
enum VDS_IPADDRESS_TYPE
    {	VDS_IPT_TEXT	= 0,
	VDS_IPT_IPV4	= 1,
	VDS_IPT_IPV6	= 2,
	VDS_IPT_EMPTY	= 3
    } 	VDS_IPADDRESS_TYPE;

typedef 
enum _VDS_HEALTH
    {	VDS_H_UNKNOWN	= 0,
	VDS_H_HEALTHY	= 1,
	VDS_H_REBUILDING	= 2,
	VDS_H_STALE	= 3,
	VDS_H_FAILING	= 4,
	VDS_H_FAILING_REDUNDANCY	= 5,
	VDS_H_FAILED_REDUNDANCY	= 6,
	VDS_H_FAILED_REDUNDANCY_FAILING	= 7,
	VDS_H_FAILED	= 8
    } 	VDS_HEALTH;

typedef 
enum _VDS_TRANSITION_STATE
    {	VDS_TS_UNKNOWN	= 0,
	VDS_TS_STABLE	= 1,
	VDS_TS_EXTENDING	= 2,
	VDS_TS_SHRINKING	= 3,
	VDS_TS_RECONFIGING	= 4
    } 	VDS_TRANSITION_STATE;

typedef 
enum _VDS_FILE_SYSTEM_TYPE
    {	VDS_FST_UNKNOWN	= 0,
	VDS_FST_RAW	= ( VDS_FST_UNKNOWN + 1 ) ,
	VDS_FST_FAT	= ( VDS_FST_RAW + 1 ) ,
	VDS_FST_FAT32	= ( VDS_FST_FAT + 1 ) ,
	VDS_FST_NTFS	= ( VDS_FST_FAT32 + 1 ) ,
	VDS_FST_CDFS	= ( VDS_FST_NTFS + 1 ) ,
	VDS_FST_UDF	= ( VDS_FST_CDFS + 1 ) 
    } 	VDS_FILE_SYSTEM_TYPE;

typedef 
enum _VDS_HBAPORT_TYPE
    {	VDS_HPT_UNKNOWN	= 1,
	VDS_HPT_OTHER	= 2,
	VDS_HPT_NOTPRESENT	= 3,
	VDS_HPT_NPORT	= 5,
	VDS_HPT_NLPORT	= 6,
	VDS_HPT_FLPORT	= 7,
	VDS_HPT_FPORT	= 8,
	VDS_HPT_EPORT	= 9,
	VDS_HPT_GPORT	= 10,
	VDS_HPT_LPORT	= 20,
	VDS_HPT_PTP	= 21
    } 	VDS_HBAPORT_TYPE;

typedef 
enum _VDS_HBAPORT_STATUS
    {	VDS_HPS_UNKNOWN	= 1,
	VDS_HPS_ONLINE	= 2,
	VDS_HPS_OFFLINE	= 3,
	VDS_HPS_BYPASSED	= 4,
	VDS_HPS_DIAGNOSTICS	= 5,
	VDS_HPS_LINKDOWN	= 6,
	VDS_HPS_ERROR	= 7,
	VDS_HPS_LOOPBACK	= 8
    } 	VDS_HBAPORT_STATUS;

typedef 
enum _VDS_HBAPORT_SPEED_FLAG
    {	VDS_HSF_UNKNOWN	= 0,
	VDS_HSF_1GBIT	= 0x1,
	VDS_HSF_2GBIT	= 0x2,
	VDS_HSF_10GBIT	= 0x4,
	VDS_HSF_4GBIT	= 0x8,
	VDS_HSF_NOT_NEGOTIATED	= ( 1 << 15 ) 
    } 	VDS_HBAPORT_SPEED_FLAG;

typedef 
enum _VDS_PATH_STATUS
    {	VDS_MPS_UNKNOWN	= 0,
	VDS_MPS_ONLINE	= 1,
	VDS_MPS_FAILED	= 5,
	VDS_MPS_STANDBY	= 7
    } 	VDS_PATH_STATUS;

typedef 
enum _VDS_LOADBALANCE_POLICY_ENUM
    {	VDS_LBP_UNKNOWN	= 0,
	VDS_LBP_FAILOVER	= 1,
	VDS_LBP_ROUND_ROBIN	= 2,
	VDS_LBP_ROUND_ROBIN_WITH_SUBSET	= 3,
	VDS_LBP_DYN_LEAST_QUEUE_DEPTH	= 4,
	VDS_LBP_WEIGHTED_PATHS	= 5,
	VDS_LBP_LEAST_BLOCKS	= 6,
	VDS_LBP_VENDOR_SPECIFIC	= 7
    } 	VDS_LOADBALANCE_POLICY_ENUM;

typedef 
enum _VDS_PROVIDER_LBSUPPORT_FLAG
    {	VDS_LBF_FAILOVER	= 0x1,
	VDS_LBF_ROUND_ROBIN	= 0x2,
	VDS_LBF_ROUND_ROBIN_WITH_SUBSET	= 0x4,
	VDS_LBF_DYN_LEAST_QUEUE_DEPTH	= 0x8,
	VDS_LBF_WEIGHTED_PATHS	= 0x10,
	VDS_LBF_LEAST_BLOCKS	= 0x20,
	VDS_LBF_VENDOR_SPECIFIC	= 0x40
    } 	VDS_PROVIDER_LBSUPPORT_FLAG;

typedef 
enum _VDS_VERSION_SUPPORT_FLAG
    {	VDS_VSF_1_0	= 0x1,
	VDS_VSF_1_1	= 0x2
    } 	VDS_VERSION_SUPPORT_FLAG;

typedef 
enum _VDS_HWPROVIDER_TYPE
    {	VDS_HWT_UNKNOWN	= 0,
	VDS_HWT_PCI_RAID	= 1,
	VDS_HWT_FIBRE_CHANNEL	= 2,
	VDS_HWT_ISCSI	= 3
    } 	VDS_HWPROVIDER_TYPE;

typedef 
enum _VDS_ISCSI_LOGIN_TYPE
    {	VDS_ILT_MANUAL	= 0,
	VDS_ILT_PERSISTENT	= 1,
	VDS_ILT_BOOT	= 2
    } 	VDS_ISCSI_LOGIN_TYPE;

typedef 
enum _VDS_ISCSI_AUTH_TYPE
    {	VDS_IAT_NONE	= 0,
	VDS_IAT_CHAP	= 1,
	VDS_IAT_MUTUAL_CHAP	= 2
    } 	VDS_ISCSI_AUTH_TYPE;

typedef 
enum _VDS_ISCSI_IPSEC_FLAG
    {	VDS_IIF_VALID	= 0x1,
	VDS_IIF_IKE	= 0x2,
	VDS_IIF_MAIN_MODE	= 0x4,
	VDS_IIF_AGGRESSIVE_MODE	= 0x8,
	VDS_IIF_PFS_ENABLE	= 0x10,
	VDS_IIF_TRANSPORT_MODE_PREFERRED	= 0x20,
	VDS_IIF_TUNNEL_MODE_PREFERRED	= 0x40
    } 	VDS_ISCSI_IPSEC_FLAG;

typedef 
enum _VDS_ISCSI_LOGIN_FLAG
    {	VDS_ILF_REQUIRE_IPSEC	= 0x1,
	VDS_ILF_MULTIPATH_ENABLED	= 0x2
    } 	VDS_ISCSI_LOGIN_FLAG;

typedef struct _VDS_PATH_ID
    {
    ULONGLONG ullSourceId;
    ULONGLONG ullPathId;
    } 	VDS_PATH_ID;

typedef struct _VDS_WWN
    {
    UCHAR rguchWwn[ 8 ];
    } 	VDS_WWN;

typedef struct _VDS_IPADDRESS
    {
    VDS_IPADDRESS_TYPE type;
    ULONG ipv4Address;
    UCHAR ipv6Address[ 16 ];
    ULONG ulIpv6FlowInfo;
    ULONG ulIpv6ScopeId;
    WCHAR wszTextAddress[ 257 ];
    ULONG ulPort;
    } 	VDS_IPADDRESS;

typedef struct _VDS_ISCSI_IPSEC_KEY
    {
    UCHAR *pKey;
    ULONG ulKeySize;
    } 	VDS_ISCSI_IPSEC_KEY;

typedef struct _VDS_ISCSI_SHARED_SECRET
    {
    UCHAR *pSharedSecret;
    ULONG ulSharedSecretSize;
    } 	VDS_ISCSI_SHARED_SECRET;

typedef struct _VDS_HBAPORT_PROP
    {
    VDS_OBJECT_ID id;
    VDS_WWN wwnNode;
    VDS_WWN wwnPort;
    VDS_HBAPORT_TYPE type;
    VDS_HBAPORT_STATUS status;
    ULONG ulPortSpeed;
    ULONG ulSupportedPortSpeed;
    } 	VDS_HBAPORT_PROP;

typedef struct _VDS_ISCSI_INITIATOR_ADAPTER_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszName;
    } 	VDS_ISCSI_INITIATOR_ADAPTER_PROP;

typedef struct _VDS_ISCSI_INITIATOR_PORTAL_PROP
    {
    VDS_OBJECT_ID id;
    VDS_IPADDRESS address;
    ULONG ulPortIndex;
    } 	VDS_ISCSI_INITIATOR_PORTAL_PROP;

typedef struct _VDS_PROVIDER_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszName;
    GUID guidVersionId;
    LPWSTR pwszVersion;
    VDS_PROVIDER_TYPE type;
    ULONG ulFlags;
    ULONG ulStripeSizeFlags;
    SHORT sRebuildPriority;
    } 	VDS_PROVIDER_PROP;

typedef struct _VDS_PATH_INFO
    {
    VDS_PATH_ID pathId;
    VDS_HWPROVIDER_TYPE type;
    VDS_PATH_STATUS status;
    /* [switch_type] */ union 
        {
        VDS_OBJECT_ID controllerPortId;
        VDS_OBJECT_ID targetPortalId;
         /* Empty union arm */ 
        } 	;
    /* [switch_type] */ union 
        {
        VDS_OBJECT_ID hbaPortId;
        VDS_OBJECT_ID initiatorAdapterId;
         /* Empty union arm */ 
        } 	;
    /* [switch_type] */ union 
        {
        VDS_HBAPORT_PROP *pHbaPortProp;
        VDS_IPADDRESS *pInitiatorPortalIpAddr;
         /* Empty union arm */ 
        } 	;
    } 	VDS_PATH_INFO;

typedef struct _VDS_PATH_POLICY
    {
    VDS_PATH_ID pathId;
    BOOL bPrimaryPath;
    ULONG ulWeight;
    } 	VDS_PATH_POLICY;



extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0000_v0_0_s_ifspec;

#ifndef __IEnumVdsObject_INTERFACE_DEFINED__
#define __IEnumVdsObject_INTERFACE_DEFINED__

/* interface IEnumVdsObject */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumVdsObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("118610b7-8d94-4030-b5b8-500889788e4e")
    IEnumVdsObject : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pcFetched) IUnknown **ppObjectArray,
            /* [out] */ __RPC__out ULONG *pcFetched) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumVdsObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumVdsObject * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumVdsObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumVdsObject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumVdsObject * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pcFetched) IUnknown **ppObjectArray,
            /* [out] */ __RPC__out ULONG *pcFetched);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumVdsObject * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumVdsObject * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumVdsObject * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        END_INTERFACE
    } IEnumVdsObjectVtbl;

    interface IEnumVdsObject
    {
        CONST_VTBL struct IEnumVdsObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumVdsObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumVdsObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumVdsObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumVdsObject_Next(This,celt,ppObjectArray,pcFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,ppObjectArray,pcFetched) ) 

#define IEnumVdsObject_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumVdsObject_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumVdsObject_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumVdsObject_INTERFACE_DEFINED__ */


#ifndef __IVdsAsync_INTERFACE_DEFINED__
#define __IVdsAsync_INTERFACE_DEFINED__

/* interface IVdsAsync */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d5d23b6d-5a55-4492-9889-397a3c2d2dbc")
    IVdsAsync : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Wait( 
            /* [out] */ __RPC__out HRESULT *pHrResult,
            /* [out] */ __RPC__out VDS_ASYNC_OUTPUT *pAsyncOut) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [out] */ __RPC__out HRESULT *pHrResult,
            /* [out] */ __RPC__out ULONG *pulPercentCompleted) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsAsync * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsAsync * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IVdsAsync * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVdsAsync * This,
            /* [out] */ __RPC__out HRESULT *pHrResult,
            /* [out] */ __RPC__out VDS_ASYNC_OUTPUT *pAsyncOut);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVdsAsync * This,
            /* [out] */ __RPC__out HRESULT *pHrResult,
            /* [out] */ __RPC__out ULONG *pulPercentCompleted);
        
        END_INTERFACE
    } IVdsAsyncVtbl;

    interface IVdsAsync
    {
        CONST_VTBL struct IVdsAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsAsync_Cancel(This)	\
    ( (This)->lpVtbl -> Cancel(This) ) 

#define IVdsAsync_Wait(This,pHrResult,pAsyncOut)	\
    ( (This)->lpVtbl -> Wait(This,pHrResult,pAsyncOut) ) 

#define IVdsAsync_QueryStatus(This,pHrResult,pulPercentCompleted)	\
    ( (This)->lpVtbl -> QueryStatus(This,pHrResult,pulPercentCompleted) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsAsync_INTERFACE_DEFINED__ */


#ifndef __IVdsAdviseSink_INTERFACE_DEFINED__
#define __IVdsAdviseSink_INTERFACE_DEFINED__

/* interface IVdsAdviseSink */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8326cd1d-cf59-4936-b786-5efc08798e25")
    IVdsAdviseSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnNotify( 
            /* [range][in] */ LONG lNumberOfNotifications,
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfNotifications) VDS_NOTIFICATION *pNotificationArray) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsAdviseSink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsAdviseSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsAdviseSink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnNotify )( 
            IVdsAdviseSink * This,
            /* [range][in] */ LONG lNumberOfNotifications,
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfNotifications) VDS_NOTIFICATION *pNotificationArray);
        
        END_INTERFACE
    } IVdsAdviseSinkVtbl;

    interface IVdsAdviseSink
    {
        CONST_VTBL struct IVdsAdviseSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsAdviseSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsAdviseSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsAdviseSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsAdviseSink_OnNotify(This,lNumberOfNotifications,pNotificationArray)	\
    ( (This)->lpVtbl -> OnNotify(This,lNumberOfNotifications,pNotificationArray) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IVdsProvider_INTERFACE_DEFINED__
#define __IVdsProvider_INTERFACE_DEFINED__

/* interface IVdsProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10c5e575-7984-4e81-a56b-431f5f92ae42")
    IVdsProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_PROVIDER_PROP *pProviderProp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsProvider * This,
            /* [out] */ __RPC__out VDS_PROVIDER_PROP *pProviderProp);
        
        END_INTERFACE
    } IVdsProviderVtbl;

    interface IVdsProvider
    {
        CONST_VTBL struct IVdsProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsProvider_GetProperties(This,pProviderProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pProviderProp) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsProvider_INTERFACE_DEFINED__ */


#ifndef __IVdsProviderSupport_INTERFACE_DEFINED__
#define __IVdsProviderSupport_INTERFACE_DEFINED__

/* interface IVdsProviderSupport */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsProviderSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1732be13-e8f9-4a03-bfbc-5f616aa66ce1")
    IVdsProviderSupport : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVersionSupport( 
            /* [out] */ __RPC__out ULONG *ulVersionSupport) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsProviderSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsProviderSupport * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsProviderSupport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsProviderSupport * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVersionSupport )( 
            IVdsProviderSupport * This,
            /* [out] */ __RPC__out ULONG *ulVersionSupport);
        
        END_INTERFACE
    } IVdsProviderSupportVtbl;

    interface IVdsProviderSupport
    {
        CONST_VTBL struct IVdsProviderSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsProviderSupport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsProviderSupport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsProviderSupport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsProviderSupport_GetVersionSupport(This,ulVersionSupport)	\
    ( (This)->lpVtbl -> GetVersionSupport(This,ulVersionSupport) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsProviderSupport_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vdshwprv_0000_0005 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0005_v0_0_s_ifspec;

#ifndef __IVdsProviderPrivate_INTERFACE_DEFINED__
#define __IVdsProviderPrivate_INTERFACE_DEFINED__

/* interface IVdsProviderPrivate */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsProviderPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11f3cd41-b7e8-48ff-9472-9dff018aa292")
    IVdsProviderPrivate : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetObject( 
            /* [in] */ VDS_OBJECT_ID ObjectId,
            /* [in] */ VDS_OBJECT_TYPE type,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppObjectUnk) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLoad( 
            /* [string][in] */ __RPC__in LPWSTR pwszMachineName,
            /* [in] */ __RPC__in_opt IUnknown *pCallbackObject) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUnload( 
            /* [in] */ BOOL bForceUnload) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsProviderPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsProviderPrivate * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsProviderPrivate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsProviderPrivate * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetObject )( 
            IVdsProviderPrivate * This,
            /* [in] */ VDS_OBJECT_ID ObjectId,
            /* [in] */ VDS_OBJECT_TYPE type,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppObjectUnk);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnLoad )( 
            IVdsProviderPrivate * This,
            /* [string][in] */ __RPC__in LPWSTR pwszMachineName,
            /* [in] */ __RPC__in_opt IUnknown *pCallbackObject);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnUnload )( 
            IVdsProviderPrivate * This,
            /* [in] */ BOOL bForceUnload);
        
        END_INTERFACE
    } IVdsProviderPrivateVtbl;

    interface IVdsProviderPrivate
    {
        CONST_VTBL struct IVdsProviderPrivateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsProviderPrivate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsProviderPrivate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsProviderPrivate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsProviderPrivate_GetObject(This,ObjectId,type,ppObjectUnk)	\
    ( (This)->lpVtbl -> GetObject(This,ObjectId,type,ppObjectUnk) ) 

#define IVdsProviderPrivate_OnLoad(This,pwszMachineName,pCallbackObject)	\
    ( (This)->lpVtbl -> OnLoad(This,pwszMachineName,pCallbackObject) ) 

#define IVdsProviderPrivate_OnUnload(This,bForceUnload)	\
    ( (This)->lpVtbl -> OnUnload(This,bForceUnload) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsProviderPrivate_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vdshwprv_0000_0006 */
/* [local] */ 



















typedef 
enum _VDS_SUB_SYSTEM_STATUS
    {	VDS_SSS_UNKNOWN	= 0,
	VDS_SSS_ONLINE	= 1,
	VDS_SSS_NOT_READY	= 2,
	VDS_SSS_OFFLINE	= 4,
	VDS_SSS_FAILED	= 5
    } 	VDS_SUB_SYSTEM_STATUS;

typedef 
enum _VDS_SUB_SYSTEM_FLAG
    {	VDS_SF_LUN_MASKING_CAPABLE	= 0x1,
	VDS_SF_LUN_PLEXING_CAPABLE	= 0x2,
	VDS_SF_LUN_REMAPPING_CAPABLE	= 0x4,
	VDS_SF_DRIVE_EXTENT_CAPABLE	= 0x8,
	VDS_SF_HARDWARE_CHECKSUM_CAPABLE	= 0x10,
	VDS_SF_RADIUS_CAPABLE	= 0x20,
	VDS_SF_READ_BACK_VERIFY_CAPABLE	= 0x40,
	VDS_SF_WRITE_THROUGH_CACHING_CAPABLE	= 0x80,
	VDS_SF_SUPPORTS_FAULT_TOLERANT_LUNS	= 0x200,
	VDS_SF_SUPPORTS_NON_FAULT_TOLERANT_LUNS	= 0x400,
	VDS_SF_SUPPORTS_SIMPLE_LUNS	= 0x800,
	VDS_SF_SUPPORTS_SPAN_LUNS	= 0x1000,
	VDS_SF_SUPPORTS_STRIPE_LUNS	= 0x2000,
	VDS_SF_SUPPORTS_MIRROR_LUNS	= 0x4000,
	VDS_SF_SUPPORTS_PARITY_LUNS	= 0x8000,
	VDS_SF_SUPPORTS_AUTH_CHAP	= 0x10000,
	VDS_SF_SUPPORTS_AUTH_MUTUAL_CHAP	= 0x20000,
	VDS_SF_SUPPORTS_SIMPLE_TARGET_CONFIG	= 0x40000
    } 	VDS_SUB_SYSTEM_FLAG;

typedef 
enum _VDS_CONTROLLER_STATUS
    {	VDS_CS_UNKNOWN	= 0,
	VDS_CS_ONLINE	= 1,
	VDS_CS_NOT_READY	= 2,
	VDS_CS_OFFLINE	= 4,
	VDS_CS_FAILED	= 5
    } 	VDS_CONTROLLER_STATUS;

typedef 
enum _VDS_PORT_STATUS
    {	VDS_PRS_UNKNOWN	= 0,
	VDS_PRS_ONLINE	= 1,
	VDS_PRS_NOT_READY	= 2,
	VDS_PRS_OFFLINE	= 4,
	VDS_PRS_FAILED	= 5
    } 	VDS_PORT_STATUS;

typedef 
enum _VDS_DRIVE_STATUS
    {	VDS_DRS_UNKNOWN	= 0,
	VDS_DRS_ONLINE	= 1,
	VDS_DRS_NOT_READY	= 2,
	VDS_DRS_OFFLINE	= 4,
	VDS_DRS_FAILED	= 5
    } 	VDS_DRIVE_STATUS;

typedef 
enum _VDS_DRIVE_FLAG
    {	VDS_DRF_HOTSPARE	= 0x1
    } 	VDS_DRIVE_FLAG;

typedef 
enum _VDS_LUN_TYPE
    {	VDS_LT_UNKNOWN	= 0,
	VDS_LT_DEFAULT	= 1,
	VDS_LT_FAULT_TOLERANT	= 2,
	VDS_LT_NON_FAULT_TOLERANT	= 3,
	VDS_LT_SIMPLE	= 10,
	VDS_LT_SPAN	= 11,
	VDS_LT_STRIPE	= 12,
	VDS_LT_MIRROR	= 13,
	VDS_LT_PARITY	= 14
    } 	VDS_LUN_TYPE;

typedef 
enum _VDS_LUN_STATUS
    {	VDS_LS_UNKNOWN	= 0,
	VDS_LS_ONLINE	= 1,
	VDS_LS_NOT_READY	= 2,
	VDS_LS_OFFLINE	= 4,
	VDS_LS_FAILED	= 5
    } 	VDS_LUN_STATUS;

typedef 
enum _VDS_LUN_FLAG
    {	VDS_LF_LBN_REMAP_ENABLED	= 0x1,
	VDS_LF_READ_BACK_VERIFY_ENABLED	= 0x2,
	VDS_LF_WRITE_THROUGH_CACHING_ENABLED	= 0x4,
	VDS_LF_HARDWARE_CHECKSUM_ENABLED	= 0x8
    } 	VDS_LUN_FLAG;

typedef 
enum _VDS_LUN_PLEX_TYPE
    {	VDS_LPT_UNKNOWN	= 0,
	VDS_LPT_SIMPLE	= VDS_LT_SIMPLE,
	VDS_LPT_SPAN	= VDS_LT_SPAN,
	VDS_LPT_STRIPE	= VDS_LT_STRIPE,
	VDS_LPT_PARITY	= VDS_LT_PARITY
    } 	VDS_LUN_PLEX_TYPE;

typedef 
enum _VDS_LUN_PLEX_STATUS
    {	VDS_LPS_UNKNOWN	= 0,
	VDS_LPS_ONLINE	= 1,
	VDS_LPS_NOT_READY	= 2,
	VDS_LPS_OFFLINE	= 4,
	VDS_LPS_FAILED	= 5
    } 	VDS_LUN_PLEX_STATUS;

typedef 
enum _VDS_LUN_PLEX_FLAG
    {	VDS_LPF_LBN_REMAP_ENABLED	= VDS_LF_LBN_REMAP_ENABLED
    } 	VDS_LUN_PLEX_FLAG;

typedef 
enum _VDS_ISCSI_PORTAL_STATUS
    {	VDS_IPS_UNKNOWN	= 0,
	VDS_IPS_ONLINE	= 1,
	VDS_IPS_NOT_READY	= 2,
	VDS_IPS_OFFLINE	= 4,
	VDS_IPS_FAILED	= 5
    } 	VDS_ISCSI_PORTAL_STATUS;

typedef 
enum _VDS_MAINTENANCE_OPERATION
    {	BlinkLight	= 1,
	BeepAlarm	= 2,
	SpinDown	= 3,
	SpinUp	= 4,
	Ping	= 5
    } 	VDS_MAINTENANCE_OPERATION;

typedef struct _VDS_HINTS
    {
    ULONGLONG ullHintMask;
    ULONGLONG ullExpectedMaximumSize;
    ULONG ulOptimalReadSize;
    ULONG ulOptimalReadAlignment;
    ULONG ulOptimalWriteSize;
    ULONG ulOptimalWriteAlignment;
    ULONG ulMaximumDriveCount;
    ULONG ulStripeSize;
    BOOL bFastCrashRecoveryRequired;
    BOOL bMostlyReads;
    BOOL bOptimizeForSequentialReads;
    BOOL bOptimizeForSequentialWrites;
    BOOL bRemapEnabled;
    BOOL bReadBackVerifyEnabled;
    BOOL bWriteThroughCachingEnabled;
    BOOL bHardwareChecksumEnabled;
    BOOL bIsYankable;
    SHORT sRebuildPriority;
    } 	VDS_HINTS;

typedef struct _VDS_HINTS *PVDS_HINTS;

#define	VDS_HINT_FASTCRASHRECOVERYREQUIRED	( 0x1L )

#define	VDS_HINT_MOSTLYREADS	( 0x2L )

#define	VDS_HINT_OPTIMIZEFORSEQUENTIALREADS	( 0x4L )

#define	VDS_HINT_OPTIMIZEFORSEQUENTIALWRITES	( 0x8L )

#define	VDS_HINT_READBACKVERIFYENABLED	( 0x10L )

#define	VDS_HINT_REMAPENABLED	( 0x20L )

#define	VDS_HINT_WRITETHROUGHCACHINGENABLED	( 0x40L )

#define	VDS_HINT_HARDWARECHECKSUMENABLED	( 0x80L )

#define	VDS_HINT_ISYANKABLE	( 0x100L )

typedef struct _VDS_SUB_SYSTEM_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszFriendlyName;
    LPWSTR pwszIdentification;
    ULONG ulFlags;
    ULONG ulStripeSizeFlags;
    VDS_SUB_SYSTEM_STATUS status;
    VDS_HEALTH health;
    SHORT sNumberOfInternalBuses;
    SHORT sMaxNumberOfSlotsEachBus;
    SHORT sMaxNumberOfControllers;
    SHORT sRebuildPriority;
    } 	VDS_SUB_SYSTEM_PROP;

typedef struct _VDS_CONTROLLER_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszFriendlyName;
    LPWSTR pwszIdentification;
    VDS_CONTROLLER_STATUS status;
    VDS_HEALTH health;
    SHORT sNumberOfPorts;
    } 	VDS_CONTROLLER_PROP;

typedef struct _VDS_DRIVE_PROP
    {
    VDS_OBJECT_ID id;
    ULONGLONG ullSize;
    LPWSTR pwszFriendlyName;
    LPWSTR pwszIdentification;
    ULONG ulFlags;
    VDS_DRIVE_STATUS status;
    VDS_HEALTH health;
    SHORT sInternalBusNumber;
    SHORT sSlotNumber;
    } 	VDS_DRIVE_PROP;

typedef struct _VDS_DRIVE_EXTENT
    {
    VDS_OBJECT_ID id;
    VDS_OBJECT_ID LunId;
    ULONGLONG ullSize;
    BOOL bUsed;
    } 	VDS_DRIVE_EXTENT;

#define VDS_REBUILD_PRIORITY_MIN        0
#define VDS_REBUILD_PRIORITY_MAX        16
typedef struct _VDS_LUN_PROP
    {
    VDS_OBJECT_ID id;
    ULONGLONG ullSize;
    LPWSTR pwszFriendlyName;
    LPWSTR pwszIdentification;
    LPWSTR pwszUnmaskingList;
    ULONG ulFlags;
    VDS_LUN_TYPE type;
    VDS_LUN_STATUS status;
    VDS_HEALTH health;
    VDS_TRANSITION_STATE TransitionState;
    SHORT sRebuildPriority;
    } 	VDS_LUN_PROP;

typedef struct _VDS_LUN_PROP *PVDS_LUN_PROP;

typedef struct _VDS_LUN_PLEX_PROP
    {
    VDS_OBJECT_ID id;
    ULONGLONG ullSize;
    VDS_LUN_PLEX_TYPE type;
    VDS_LUN_PLEX_STATUS status;
    VDS_HEALTH health;
    VDS_TRANSITION_STATE TransitionState;
    ULONG ulFlags;
    ULONG ulStripeSize;
    SHORT sRebuildPriority;
    } 	VDS_LUN_PLEX_PROP;

typedef struct _VDS_PORT_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszFriendlyName;
    LPWSTR pwszIdentification;
    VDS_PORT_STATUS status;
    } 	VDS_PORT_PROP;

typedef struct _VDS_ISCSI_PORTAL_PROP
    {
    VDS_OBJECT_ID id;
    VDS_IPADDRESS address;
    VDS_ISCSI_PORTAL_STATUS status;
    } 	VDS_ISCSI_PORTAL_PROP;

typedef struct _VDS_ISCSI_TARGET_PROP
    {
    VDS_OBJECT_ID id;
    LPWSTR pwszIscsiName;
    LPWSTR pwszFriendlyName;
    BOOL bChapEnabled;
    } 	VDS_ISCSI_TARGET_PROP;

typedef struct _VDS_ISCSI_PORTALGROUP_PROP
    {
    VDS_OBJECT_ID id;
    VDS_ISCSI_PORTALGROUP_TAG tag;
    } 	VDS_ISCSI_PORTALGROUP_PROP;



extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0006_v0_0_s_ifspec;

#ifndef __IVdsHwProvider_INTERFACE_DEFINED__
#define __IVdsHwProvider_INTERFACE_DEFINED__

/* interface IVdsHwProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsHwProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d99bdaae-b13a-4178-9fdb-e27f16b4603e")
    IVdsHwProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QuerySubSystems( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reenumerate( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsHwProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsHwProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsHwProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsHwProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QuerySubSystems )( 
            IVdsHwProvider * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reenumerate )( 
            IVdsHwProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IVdsHwProvider * This);
        
        END_INTERFACE
    } IVdsHwProviderVtbl;

    interface IVdsHwProvider
    {
        CONST_VTBL struct IVdsHwProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsHwProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsHwProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsHwProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsHwProvider_QuerySubSystems(This,ppEnum)	\
    ( (This)->lpVtbl -> QuerySubSystems(This,ppEnum) ) 

#define IVdsHwProvider_Reenumerate(This)	\
    ( (This)->lpVtbl -> Reenumerate(This) ) 

#define IVdsHwProvider_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsHwProvider_INTERFACE_DEFINED__ */


#ifndef __IVdsHwProviderType_INTERFACE_DEFINED__
#define __IVdsHwProviderType_INTERFACE_DEFINED__

/* interface IVdsHwProviderType */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsHwProviderType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3e0f5166-542d-4fc6-947a-012174240b7e")
    IVdsHwProviderType : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProviderType( 
            /* [out] */ __RPC__out VDS_HWPROVIDER_TYPE *pType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsHwProviderTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsHwProviderType * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsHwProviderType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsHwProviderType * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProviderType )( 
            IVdsHwProviderType * This,
            /* [out] */ __RPC__out VDS_HWPROVIDER_TYPE *pType);
        
        END_INTERFACE
    } IVdsHwProviderTypeVtbl;

    interface IVdsHwProviderType
    {
        CONST_VTBL struct IVdsHwProviderTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsHwProviderType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsHwProviderType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsHwProviderType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsHwProviderType_GetProviderType(This,pType)	\
    ( (This)->lpVtbl -> GetProviderType(This,pType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsHwProviderType_INTERFACE_DEFINED__ */


#ifndef __IVdsSubSystem_INTERFACE_DEFINED__
#define __IVdsSubSystem_INTERFACE_DEFINED__

/* interface IVdsSubSystem */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsSubSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6fcee2d3-6d90-4f91-80e2-a5c7caaca9d8")
    IVdsSubSystem : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_SUB_SYSTEM_PROP *pSubSystemProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProvider( 
            /* [out] */ __RPC__deref_out_opt IVdsProvider **ppProvider) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryControllers( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryLuns( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryDrives( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDrive( 
            /* [in] */ SHORT sBusNumber,
            /* [in] */ SHORT sSlotNumber,
            /* [out] */ __RPC__deref_out_opt IVdsDrive **ppDrive) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reenumerate( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetControllerStatus( 
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfOnlineControllers) VDS_OBJECT_ID *pOnlineControllerIdArray,
            /* [in] */ LONG lNumberOfOnlineControllers,
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfOfflineControllers) VDS_OBJECT_ID *pOfflineControllerIdArray,
            /* [in] */ LONG lNumberOfOfflineControllers) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateLun( 
            /* [in] */ VDS_LUN_TYPE type,
            /* [in] */ ULONGLONG ullSizeInBytes,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [string][in] */ __RPC__in LPWSTR pwszUnmaskingList,
            /* [unique][in] */ __RPC__in_opt VDS_HINTS *pHints,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReplaceDrive( 
            /* [in] */ VDS_OBJECT_ID DriveToBeReplaced,
            /* [in] */ VDS_OBJECT_ID ReplacementDrive) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_SUB_SYSTEM_STATUS status) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryMaxLunCreateSize( 
            /* [in] */ VDS_LUN_TYPE type,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [unique][in] */ __RPC__in_opt VDS_HINTS *pHints,
            /* [out] */ __RPC__out ULONGLONG *pullMaxLunSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsSubSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsSubSystem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsSubSystem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsSubSystem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsSubSystem * This,
            /* [out] */ __RPC__out VDS_SUB_SYSTEM_PROP *pSubSystemProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProvider )( 
            IVdsSubSystem * This,
            /* [out] */ __RPC__deref_out_opt IVdsProvider **ppProvider);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryControllers )( 
            IVdsSubSystem * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryLuns )( 
            IVdsSubSystem * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryDrives )( 
            IVdsSubSystem * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDrive )( 
            IVdsSubSystem * This,
            /* [in] */ SHORT sBusNumber,
            /* [in] */ SHORT sSlotNumber,
            /* [out] */ __RPC__deref_out_opt IVdsDrive **ppDrive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reenumerate )( 
            IVdsSubSystem * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetControllerStatus )( 
            IVdsSubSystem * This,
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfOnlineControllers) VDS_OBJECT_ID *pOnlineControllerIdArray,
            /* [in] */ LONG lNumberOfOnlineControllers,
            /* [size_is][in] */ __RPC__in_ecount_full(lNumberOfOfflineControllers) VDS_OBJECT_ID *pOfflineControllerIdArray,
            /* [in] */ LONG lNumberOfOfflineControllers);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateLun )( 
            IVdsSubSystem * This,
            /* [in] */ VDS_LUN_TYPE type,
            /* [in] */ ULONGLONG ullSizeInBytes,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [string][in] */ __RPC__in LPWSTR pwszUnmaskingList,
            /* [unique][in] */ __RPC__in_opt VDS_HINTS *pHints,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReplaceDrive )( 
            IVdsSubSystem * This,
            /* [in] */ VDS_OBJECT_ID DriveToBeReplaced,
            /* [in] */ VDS_OBJECT_ID ReplacementDrive);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsSubSystem * This,
            /* [in] */ VDS_SUB_SYSTEM_STATUS status);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryMaxLunCreateSize )( 
            IVdsSubSystem * This,
            /* [in] */ VDS_LUN_TYPE type,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [unique][in] */ __RPC__in_opt VDS_HINTS *pHints,
            /* [out] */ __RPC__out ULONGLONG *pullMaxLunSize);
        
        END_INTERFACE
    } IVdsSubSystemVtbl;

    interface IVdsSubSystem
    {
        CONST_VTBL struct IVdsSubSystemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsSubSystem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsSubSystem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsSubSystem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsSubSystem_GetProperties(This,pSubSystemProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pSubSystemProp) ) 

#define IVdsSubSystem_GetProvider(This,ppProvider)	\
    ( (This)->lpVtbl -> GetProvider(This,ppProvider) ) 

#define IVdsSubSystem_QueryControllers(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryControllers(This,ppEnum) ) 

#define IVdsSubSystem_QueryLuns(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryLuns(This,ppEnum) ) 

#define IVdsSubSystem_QueryDrives(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryDrives(This,ppEnum) ) 

#define IVdsSubSystem_GetDrive(This,sBusNumber,sSlotNumber,ppDrive)	\
    ( (This)->lpVtbl -> GetDrive(This,sBusNumber,sSlotNumber,ppDrive) ) 

#define IVdsSubSystem_Reenumerate(This)	\
    ( (This)->lpVtbl -> Reenumerate(This) ) 

#define IVdsSubSystem_SetControllerStatus(This,pOnlineControllerIdArray,lNumberOfOnlineControllers,pOfflineControllerIdArray,lNumberOfOfflineControllers)	\
    ( (This)->lpVtbl -> SetControllerStatus(This,pOnlineControllerIdArray,lNumberOfOnlineControllers,pOfflineControllerIdArray,lNumberOfOfflineControllers) ) 

#define IVdsSubSystem_CreateLun(This,type,ullSizeInBytes,pDriveIdArray,lNumberOfDrives,pwszUnmaskingList,pHints,ppAsync)	\
    ( (This)->lpVtbl -> CreateLun(This,type,ullSizeInBytes,pDriveIdArray,lNumberOfDrives,pwszUnmaskingList,pHints,ppAsync) ) 

#define IVdsSubSystem_ReplaceDrive(This,DriveToBeReplaced,ReplacementDrive)	\
    ( (This)->lpVtbl -> ReplaceDrive(This,DriveToBeReplaced,ReplacementDrive) ) 

#define IVdsSubSystem_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#define IVdsSubSystem_QueryMaxLunCreateSize(This,type,pDriveIdArray,lNumberOfDrives,pHints,pullMaxLunSize)	\
    ( (This)->lpVtbl -> QueryMaxLunCreateSize(This,type,pDriveIdArray,lNumberOfDrives,pHints,pullMaxLunSize) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsSubSystem_INTERFACE_DEFINED__ */


#ifndef __IVdsSubSystemNaming_INTERFACE_DEFINED__
#define __IVdsSubSystemNaming_INTERFACE_DEFINED__

/* interface IVdsSubSystemNaming */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsSubSystemNaming;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0d70faa3-9cd4-4900-aa20-6981b6aafc75")
    IVdsSubSystemNaming : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFriendlyName( 
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsSubSystemNamingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsSubSystemNaming * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsSubSystemNaming * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsSubSystemNaming * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFriendlyName )( 
            IVdsSubSystemNaming * This,
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName);
        
        END_INTERFACE
    } IVdsSubSystemNamingVtbl;

    interface IVdsSubSystemNaming
    {
        CONST_VTBL struct IVdsSubSystemNamingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsSubSystemNaming_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsSubSystemNaming_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsSubSystemNaming_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsSubSystemNaming_SetFriendlyName(This,pwszFriendlyName)	\
    ( (This)->lpVtbl -> SetFriendlyName(This,pwszFriendlyName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsSubSystemNaming_INTERFACE_DEFINED__ */


#ifndef __IVdsSubSystemIscsi_INTERFACE_DEFINED__
#define __IVdsSubSystemIscsi_INTERFACE_DEFINED__

/* interface IVdsSubSystemIscsi */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsSubSystemIscsi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0027346f-40d0-4b45-8cec-5906dc0380c8")
    IVdsSubSystemIscsi : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryTargets( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryPortals( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateTarget( 
            /* [string][unique][in] */ __RPC__in_opt LPWSTR pwszIscsiName,
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIpsecGroupPresharedKey( 
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_IPSEC_KEY *pIpsecKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsSubSystemIscsiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsSubSystemIscsi * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsSubSystemIscsi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsSubSystemIscsi * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryTargets )( 
            IVdsSubSystemIscsi * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryPortals )( 
            IVdsSubSystemIscsi * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateTarget )( 
            IVdsSubSystemIscsi * This,
            /* [string][unique][in] */ __RPC__in_opt LPWSTR pwszIscsiName,
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIpsecGroupPresharedKey )( 
            IVdsSubSystemIscsi * This,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_IPSEC_KEY *pIpsecKey);
        
        END_INTERFACE
    } IVdsSubSystemIscsiVtbl;

    interface IVdsSubSystemIscsi
    {
        CONST_VTBL struct IVdsSubSystemIscsiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsSubSystemIscsi_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsSubSystemIscsi_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsSubSystemIscsi_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsSubSystemIscsi_QueryTargets(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryTargets(This,ppEnum) ) 

#define IVdsSubSystemIscsi_QueryPortals(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryPortals(This,ppEnum) ) 

#define IVdsSubSystemIscsi_CreateTarget(This,pwszIscsiName,pwszFriendlyName,ppAsync)	\
    ( (This)->lpVtbl -> CreateTarget(This,pwszIscsiName,pwszFriendlyName,ppAsync) ) 

#define IVdsSubSystemIscsi_SetIpsecGroupPresharedKey(This,pIpsecKey)	\
    ( (This)->lpVtbl -> SetIpsecGroupPresharedKey(This,pIpsecKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsSubSystemIscsi_INTERFACE_DEFINED__ */


#ifndef __IVdsControllerPort_INTERFACE_DEFINED__
#define __IVdsControllerPort_INTERFACE_DEFINED__

/* interface IVdsControllerPort */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsControllerPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18691d0d-4e7f-43e8-92e4-cf44beeed11c")
    IVdsControllerPort : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_PORT_PROP *pPortProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetController( 
            /* [out] */ __RPC__deref_out_opt IVdsController **ppController) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedLuns( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_PORT_STATUS status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsControllerPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsControllerPort * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsControllerPort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsControllerPort * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsControllerPort * This,
            /* [out] */ __RPC__out VDS_PORT_PROP *pPortProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetController )( 
            IVdsControllerPort * This,
            /* [out] */ __RPC__deref_out_opt IVdsController **ppController);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedLuns )( 
            IVdsControllerPort * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVdsControllerPort * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsControllerPort * This,
            /* [in] */ VDS_PORT_STATUS status);
        
        END_INTERFACE
    } IVdsControllerPortVtbl;

    interface IVdsControllerPort
    {
        CONST_VTBL struct IVdsControllerPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsControllerPort_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsControllerPort_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsControllerPort_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsControllerPort_GetProperties(This,pPortProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pPortProp) ) 

#define IVdsControllerPort_GetController(This,ppController)	\
    ( (This)->lpVtbl -> GetController(This,ppController) ) 

#define IVdsControllerPort_QueryAssociatedLuns(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedLuns(This,ppEnum) ) 

#define IVdsControllerPort_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IVdsControllerPort_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsControllerPort_INTERFACE_DEFINED__ */


#ifndef __IVdsController_INTERFACE_DEFINED__
#define __IVdsController_INTERFACE_DEFINED__

/* interface IVdsController */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cb53d96e-dffb-474a-a078-790d1e2bc082")
    IVdsController : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_CONTROLLER_PROP *pControllerProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubSystem( 
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPortProperties( 
            /* [in] */ SHORT sPortNumber,
            /* [out] */ __RPC__out VDS_PORT_PROP *pPortProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FlushCache( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE InvalidateCache( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedLuns( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_CONTROLLER_STATUS status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsController * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsController * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsController * This,
            /* [out] */ __RPC__out VDS_CONTROLLER_PROP *pControllerProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSubSystem )( 
            IVdsController * This,
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPortProperties )( 
            IVdsController * This,
            /* [in] */ SHORT sPortNumber,
            /* [out] */ __RPC__out VDS_PORT_PROP *pPortProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FlushCache )( 
            IVdsController * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *InvalidateCache )( 
            IVdsController * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVdsController * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedLuns )( 
            IVdsController * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsController * This,
            /* [in] */ VDS_CONTROLLER_STATUS status);
        
        END_INTERFACE
    } IVdsControllerVtbl;

    interface IVdsController
    {
        CONST_VTBL struct IVdsControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsController_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsController_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsController_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsController_GetProperties(This,pControllerProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pControllerProp) ) 

#define IVdsController_GetSubSystem(This,ppSubSystem)	\
    ( (This)->lpVtbl -> GetSubSystem(This,ppSubSystem) ) 

#define IVdsController_GetPortProperties(This,sPortNumber,pPortProp)	\
    ( (This)->lpVtbl -> GetPortProperties(This,sPortNumber,pPortProp) ) 

#define IVdsController_FlushCache(This)	\
    ( (This)->lpVtbl -> FlushCache(This) ) 

#define IVdsController_InvalidateCache(This)	\
    ( (This)->lpVtbl -> InvalidateCache(This) ) 

#define IVdsController_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IVdsController_QueryAssociatedLuns(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedLuns(This,ppEnum) ) 

#define IVdsController_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsController_INTERFACE_DEFINED__ */


#ifndef __IVdsControllerControllerPort_INTERFACE_DEFINED__
#define __IVdsControllerControllerPort_INTERFACE_DEFINED__

/* interface IVdsControllerControllerPort */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsControllerControllerPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ca5d735f-6bae-42c0-b30e-f2666045ce71")
    IVdsControllerControllerPort : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryControllerPorts( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsControllerControllerPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsControllerControllerPort * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsControllerControllerPort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsControllerControllerPort * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryControllerPorts )( 
            IVdsControllerControllerPort * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        END_INTERFACE
    } IVdsControllerControllerPortVtbl;

    interface IVdsControllerControllerPort
    {
        CONST_VTBL struct IVdsControllerControllerPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsControllerControllerPort_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsControllerControllerPort_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsControllerControllerPort_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsControllerControllerPort_QueryControllerPorts(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryControllerPorts(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsControllerControllerPort_INTERFACE_DEFINED__ */


#ifndef __IVdsDrive_INTERFACE_DEFINED__
#define __IVdsDrive_INTERFACE_DEFINED__

/* interface IVdsDrive */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsDrive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ff24efa4-aade-4b6b-898b-eaa6a20887c7")
    IVdsDrive : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_DRIVE_PROP *pDriveProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubSystem( 
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryExtents( 
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfExtents) VDS_DRIVE_EXTENT **ppExtentArray,
            /* [out] */ __RPC__out LONG *plNumberOfExtents) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFlags( 
            /* [in] */ ULONG ulFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ClearFlags( 
            /* [in] */ ULONG ulFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_DRIVE_STATUS status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsDriveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsDrive * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsDrive * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsDrive * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsDrive * This,
            /* [out] */ __RPC__out VDS_DRIVE_PROP *pDriveProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSubSystem )( 
            IVdsDrive * This,
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryExtents )( 
            IVdsDrive * This,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfExtents) VDS_DRIVE_EXTENT **ppExtentArray,
            /* [out] */ __RPC__out LONG *plNumberOfExtents);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFlags )( 
            IVdsDrive * This,
            /* [in] */ ULONG ulFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ClearFlags )( 
            IVdsDrive * This,
            /* [in] */ ULONG ulFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsDrive * This,
            /* [in] */ VDS_DRIVE_STATUS status);
        
        END_INTERFACE
    } IVdsDriveVtbl;

    interface IVdsDrive
    {
        CONST_VTBL struct IVdsDriveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsDrive_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsDrive_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsDrive_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsDrive_GetProperties(This,pDriveProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pDriveProp) ) 

#define IVdsDrive_GetSubSystem(This,ppSubSystem)	\
    ( (This)->lpVtbl -> GetSubSystem(This,ppSubSystem) ) 

#define IVdsDrive_QueryExtents(This,ppExtentArray,plNumberOfExtents)	\
    ( (This)->lpVtbl -> QueryExtents(This,ppExtentArray,plNumberOfExtents) ) 

#define IVdsDrive_SetFlags(This,ulFlags)	\
    ( (This)->lpVtbl -> SetFlags(This,ulFlags) ) 

#define IVdsDrive_ClearFlags(This,ulFlags)	\
    ( (This)->lpVtbl -> ClearFlags(This,ulFlags) ) 

#define IVdsDrive_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsDrive_INTERFACE_DEFINED__ */


#ifndef __IVdsLun_INTERFACE_DEFINED__
#define __IVdsLun_INTERFACE_DEFINED__

/* interface IVdsLun */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLun;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3540a9c7-e60f-4111-a840-8bba6c2c83d8")
    IVdsLun : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_LUN_PROP *pLunProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubSystem( 
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIdentificationData( 
            /* [out] */ __RPC__out VDS_LUN_INFORMATION *pLunInfo) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryActiveControllers( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Extend( 
            /* [in] */ ULONGLONG ullNumberOfBytesToAdd,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Shrink( 
            /* [in] */ ULONGLONG ullNumberOfBytesToRemove,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryPlexes( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddPlex( 
            /* [in] */ VDS_OBJECT_ID lunId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemovePlex( 
            /* [in] */ VDS_OBJECT_ID plexId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Recover( 
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMask( 
            /* [string][in] */ __RPC__in LPWSTR pwszUnmaskingList) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AssociateControllers( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfActiveControllers) VDS_OBJECT_ID *pActiveControllerIdArray,
            /* [in] */ LONG lNumberOfActiveControllers,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfInactiveControllers) VDS_OBJECT_ID *pInactiveControllerIdArray,
            /* [in] */ LONG lNumberOfInactiveControllers) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryHints( 
            /* [out] */ __RPC__out VDS_HINTS *pHints) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ApplyHints( 
            /* [in] */ __RPC__in VDS_HINTS *pHints) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_LUN_STATUS status) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryMaxLunExtendSize( 
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [out] */ __RPC__out ULONGLONG *pullMaxBytesToBeAdded) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLun * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLun * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLun * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsLun * This,
            /* [out] */ __RPC__out VDS_LUN_PROP *pLunProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSubSystem )( 
            IVdsLun * This,
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIdentificationData )( 
            IVdsLun * This,
            /* [out] */ __RPC__out VDS_LUN_INFORMATION *pLunInfo);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryActiveControllers )( 
            IVdsLun * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Extend )( 
            IVdsLun * This,
            /* [in] */ ULONGLONG ullNumberOfBytesToAdd,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shrink )( 
            IVdsLun * This,
            /* [in] */ ULONGLONG ullNumberOfBytesToRemove,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryPlexes )( 
            IVdsLun * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddPlex )( 
            IVdsLun * This,
            /* [in] */ VDS_OBJECT_ID lunId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemovePlex )( 
            IVdsLun * This,
            /* [in] */ VDS_OBJECT_ID plexId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Recover )( 
            IVdsLun * This,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetMask )( 
            IVdsLun * This,
            /* [string][in] */ __RPC__in LPWSTR pwszUnmaskingList);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IVdsLun * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AssociateControllers )( 
            IVdsLun * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfActiveControllers) VDS_OBJECT_ID *pActiveControllerIdArray,
            /* [in] */ LONG lNumberOfActiveControllers,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfInactiveControllers) VDS_OBJECT_ID *pInactiveControllerIdArray,
            /* [in] */ LONG lNumberOfInactiveControllers);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryHints )( 
            IVdsLun * This,
            /* [out] */ __RPC__out VDS_HINTS *pHints);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ApplyHints )( 
            IVdsLun * This,
            /* [in] */ __RPC__in VDS_HINTS *pHints);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsLun * This,
            /* [in] */ VDS_LUN_STATUS status);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryMaxLunExtendSize )( 
            IVdsLun * This,
            /* [unique][size_is][in] */ __RPC__in_ecount_full_opt(lNumberOfDrives) VDS_OBJECT_ID *pDriveIdArray,
            /* [in] */ LONG lNumberOfDrives,
            /* [out] */ __RPC__out ULONGLONG *pullMaxBytesToBeAdded);
        
        END_INTERFACE
    } IVdsLunVtbl;

    interface IVdsLun
    {
        CONST_VTBL struct IVdsLunVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLun_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLun_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLun_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLun_GetProperties(This,pLunProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pLunProp) ) 

#define IVdsLun_GetSubSystem(This,ppSubSystem)	\
    ( (This)->lpVtbl -> GetSubSystem(This,ppSubSystem) ) 

#define IVdsLun_GetIdentificationData(This,pLunInfo)	\
    ( (This)->lpVtbl -> GetIdentificationData(This,pLunInfo) ) 

#define IVdsLun_QueryActiveControllers(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryActiveControllers(This,ppEnum) ) 

#define IVdsLun_Extend(This,ullNumberOfBytesToAdd,pDriveIdArray,lNumberOfDrives,ppAsync)	\
    ( (This)->lpVtbl -> Extend(This,ullNumberOfBytesToAdd,pDriveIdArray,lNumberOfDrives,ppAsync) ) 

#define IVdsLun_Shrink(This,ullNumberOfBytesToRemove,ppAsync)	\
    ( (This)->lpVtbl -> Shrink(This,ullNumberOfBytesToRemove,ppAsync) ) 

#define IVdsLun_QueryPlexes(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryPlexes(This,ppEnum) ) 

#define IVdsLun_AddPlex(This,lunId,ppAsync)	\
    ( (This)->lpVtbl -> AddPlex(This,lunId,ppAsync) ) 

#define IVdsLun_RemovePlex(This,plexId,ppAsync)	\
    ( (This)->lpVtbl -> RemovePlex(This,plexId,ppAsync) ) 

#define IVdsLun_Recover(This,ppAsync)	\
    ( (This)->lpVtbl -> Recover(This,ppAsync) ) 

#define IVdsLun_SetMask(This,pwszUnmaskingList)	\
    ( (This)->lpVtbl -> SetMask(This,pwszUnmaskingList) ) 

#define IVdsLun_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IVdsLun_AssociateControllers(This,pActiveControllerIdArray,lNumberOfActiveControllers,pInactiveControllerIdArray,lNumberOfInactiveControllers)	\
    ( (This)->lpVtbl -> AssociateControllers(This,pActiveControllerIdArray,lNumberOfActiveControllers,pInactiveControllerIdArray,lNumberOfInactiveControllers) ) 

#define IVdsLun_QueryHints(This,pHints)	\
    ( (This)->lpVtbl -> QueryHints(This,pHints) ) 

#define IVdsLun_ApplyHints(This,pHints)	\
    ( (This)->lpVtbl -> ApplyHints(This,pHints) ) 

#define IVdsLun_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#define IVdsLun_QueryMaxLunExtendSize(This,pDriveIdArray,lNumberOfDrives,pullMaxBytesToBeAdded)	\
    ( (This)->lpVtbl -> QueryMaxLunExtendSize(This,pDriveIdArray,lNumberOfDrives,pullMaxBytesToBeAdded) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLun_INTERFACE_DEFINED__ */


#ifndef __IVdsLunNaming_INTERFACE_DEFINED__
#define __IVdsLunNaming_INTERFACE_DEFINED__

/* interface IVdsLunNaming */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLunNaming;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("907504cb-6b4e-4d88-a34d-17ba661fbb06")
    IVdsLunNaming : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFriendlyName( 
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunNamingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLunNaming * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLunNaming * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLunNaming * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFriendlyName )( 
            IVdsLunNaming * This,
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName);
        
        END_INTERFACE
    } IVdsLunNamingVtbl;

    interface IVdsLunNaming
    {
        CONST_VTBL struct IVdsLunNamingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLunNaming_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLunNaming_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLunNaming_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLunNaming_SetFriendlyName(This,pwszFriendlyName)	\
    ( (This)->lpVtbl -> SetFriendlyName(This,pwszFriendlyName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLunNaming_INTERFACE_DEFINED__ */


#ifndef __IVdsLunControllerPorts_INTERFACE_DEFINED__
#define __IVdsLunControllerPorts_INTERFACE_DEFINED__

/* interface IVdsLunControllerPorts */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLunControllerPorts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("451fe266-da6d-406a-bb60-82e534f85aeb")
    IVdsLunControllerPorts : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AssociateControllerPorts( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfActiveControllerPorts) VDS_OBJECT_ID *pActiveControllerPortIdArray,
            /* [in] */ LONG lNumberOfActiveControllerPorts,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfInactiveControllerPorts) VDS_OBJECT_ID *pInactiveControllerPortIdArray,
            /* [in] */ LONG lNumberOfInactiveControllerPorts) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryActiveControllerPorts( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunControllerPortsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLunControllerPorts * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLunControllerPorts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLunControllerPorts * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AssociateControllerPorts )( 
            IVdsLunControllerPorts * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfActiveControllerPorts) VDS_OBJECT_ID *pActiveControllerPortIdArray,
            /* [in] */ LONG lNumberOfActiveControllerPorts,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfInactiveControllerPorts) VDS_OBJECT_ID *pInactiveControllerPortIdArray,
            /* [in] */ LONG lNumberOfInactiveControllerPorts);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryActiveControllerPorts )( 
            IVdsLunControllerPorts * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        END_INTERFACE
    } IVdsLunControllerPortsVtbl;

    interface IVdsLunControllerPorts
    {
        CONST_VTBL struct IVdsLunControllerPortsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLunControllerPorts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLunControllerPorts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLunControllerPorts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLunControllerPorts_AssociateControllerPorts(This,pActiveControllerPortIdArray,lNumberOfActiveControllerPorts,pInactiveControllerPortIdArray,lNumberOfInactiveControllerPorts)	\
    ( (This)->lpVtbl -> AssociateControllerPorts(This,pActiveControllerPortIdArray,lNumberOfActiveControllerPorts,pInactiveControllerPortIdArray,lNumberOfInactiveControllerPorts) ) 

#define IVdsLunControllerPorts_QueryActiveControllerPorts(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryActiveControllerPorts(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLunControllerPorts_INTERFACE_DEFINED__ */


#ifndef __IVdsLunMpio_INTERFACE_DEFINED__
#define __IVdsLunMpio_INTERFACE_DEFINED__

/* interface IVdsLunMpio */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLunMpio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7c5fbae3-333a-48a1-a982-33c15788cde3")
    IVdsLunMpio : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPathInfo( 
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfPaths) VDS_PATH_INFO **ppPaths,
            /* [out] */ __RPC__out LONG *plNumberOfPaths) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLoadBalancePolicy( 
            /* [out] */ __RPC__out VDS_LOADBALANCE_POLICY_ENUM *pPolicy,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfPaths) VDS_PATH_POLICY **ppPaths,
            /* [out] */ __RPC__out LONG *plNumberOfPaths) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLoadBalancePolicy( 
            /* [in] */ VDS_LOADBALANCE_POLICY_ENUM policy,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfPaths) VDS_PATH_POLICY *pPaths,
            /* [in] */ LONG lNumberOfPaths) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSupportedLbPolicies( 
            /* [out] */ __RPC__out ULONG *pulLbFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunMpioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLunMpio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLunMpio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLunMpio * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPathInfo )( 
            IVdsLunMpio * This,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfPaths) VDS_PATH_INFO **ppPaths,
            /* [out] */ __RPC__out LONG *plNumberOfPaths);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLoadBalancePolicy )( 
            IVdsLunMpio * This,
            /* [out] */ __RPC__out VDS_LOADBALANCE_POLICY_ENUM *pPolicy,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfPaths) VDS_PATH_POLICY **ppPaths,
            /* [out] */ __RPC__out LONG *plNumberOfPaths);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLoadBalancePolicy )( 
            IVdsLunMpio * This,
            /* [in] */ VDS_LOADBALANCE_POLICY_ENUM policy,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfPaths) VDS_PATH_POLICY *pPaths,
            /* [in] */ LONG lNumberOfPaths);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSupportedLbPolicies )( 
            IVdsLunMpio * This,
            /* [out] */ __RPC__out ULONG *pulLbFlags);
        
        END_INTERFACE
    } IVdsLunMpioVtbl;

    interface IVdsLunMpio
    {
        CONST_VTBL struct IVdsLunMpioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLunMpio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLunMpio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLunMpio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLunMpio_GetPathInfo(This,ppPaths,plNumberOfPaths)	\
    ( (This)->lpVtbl -> GetPathInfo(This,ppPaths,plNumberOfPaths) ) 

#define IVdsLunMpio_GetLoadBalancePolicy(This,pPolicy,ppPaths,plNumberOfPaths)	\
    ( (This)->lpVtbl -> GetLoadBalancePolicy(This,pPolicy,ppPaths,plNumberOfPaths) ) 

#define IVdsLunMpio_SetLoadBalancePolicy(This,policy,pPaths,lNumberOfPaths)	\
    ( (This)->lpVtbl -> SetLoadBalancePolicy(This,policy,pPaths,lNumberOfPaths) ) 

#define IVdsLunMpio_GetSupportedLbPolicies(This,pulLbFlags)	\
    ( (This)->lpVtbl -> GetSupportedLbPolicies(This,pulLbFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLunMpio_INTERFACE_DEFINED__ */


#ifndef __IVdsLunIscsi_INTERFACE_DEFINED__
#define __IVdsLunIscsi_INTERFACE_DEFINED__

/* interface IVdsLunIscsi */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLunIscsi;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0d7c1e64-b59b-45ae-b86a-2c2cc6a42067")
    IVdsLunIscsi : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AssociateTargets( 
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfTargets) VDS_OBJECT_ID *pTargetIdArray,
            /* [in] */ LONG lNumberOfTargets) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedTargets( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunIscsiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLunIscsi * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLunIscsi * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLunIscsi * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AssociateTargets )( 
            IVdsLunIscsi * This,
            /* [size_is][unique][in] */ __RPC__in_ecount_full_opt(lNumberOfTargets) VDS_OBJECT_ID *pTargetIdArray,
            /* [in] */ LONG lNumberOfTargets);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedTargets )( 
            IVdsLunIscsi * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        END_INTERFACE
    } IVdsLunIscsiVtbl;

    interface IVdsLunIscsi
    {
        CONST_VTBL struct IVdsLunIscsiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLunIscsi_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLunIscsi_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLunIscsi_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLunIscsi_AssociateTargets(This,pTargetIdArray,lNumberOfTargets)	\
    ( (This)->lpVtbl -> AssociateTargets(This,pTargetIdArray,lNumberOfTargets) ) 

#define IVdsLunIscsi_QueryAssociatedTargets(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedTargets(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLunIscsi_INTERFACE_DEFINED__ */


#ifndef __IVdsLunPlex_INTERFACE_DEFINED__
#define __IVdsLunPlex_INTERFACE_DEFINED__

/* interface IVdsLunPlex */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsLunPlex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0ee1a790-5d2e-4abb-8c99-c481e8be2138")
    IVdsLunPlex : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_LUN_PLEX_PROP *pPlexProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLun( 
            /* [out] */ __RPC__deref_out_opt IVdsLun **ppLun) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryExtents( 
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfExtents) VDS_DRIVE_EXTENT **ppExtentArray,
            /* [out] */ __RPC__out LONG *plNumberOfExtents) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryHints( 
            /* [out] */ __RPC__out VDS_HINTS *pHints) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ApplyHints( 
            /* [in] */ __RPC__in VDS_HINTS *pHints) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsLunPlexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsLunPlex * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsLunPlex * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsLunPlex * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsLunPlex * This,
            /* [out] */ __RPC__out VDS_LUN_PLEX_PROP *pPlexProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLun )( 
            IVdsLunPlex * This,
            /* [out] */ __RPC__deref_out_opt IVdsLun **ppLun);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryExtents )( 
            IVdsLunPlex * This,
            /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*plNumberOfExtents) VDS_DRIVE_EXTENT **ppExtentArray,
            /* [out] */ __RPC__out LONG *plNumberOfExtents);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryHints )( 
            IVdsLunPlex * This,
            /* [out] */ __RPC__out VDS_HINTS *pHints);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ApplyHints )( 
            IVdsLunPlex * This,
            /* [in] */ __RPC__in VDS_HINTS *pHints);
        
        END_INTERFACE
    } IVdsLunPlexVtbl;

    interface IVdsLunPlex
    {
        CONST_VTBL struct IVdsLunPlexVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsLunPlex_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsLunPlex_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsLunPlex_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsLunPlex_GetProperties(This,pPlexProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pPlexProp) ) 

#define IVdsLunPlex_GetLun(This,ppLun)	\
    ( (This)->lpVtbl -> GetLun(This,ppLun) ) 

#define IVdsLunPlex_QueryExtents(This,ppExtentArray,plNumberOfExtents)	\
    ( (This)->lpVtbl -> QueryExtents(This,ppExtentArray,plNumberOfExtents) ) 

#define IVdsLunPlex_QueryHints(This,pHints)	\
    ( (This)->lpVtbl -> QueryHints(This,pHints) ) 

#define IVdsLunPlex_ApplyHints(This,pHints)	\
    ( (This)->lpVtbl -> ApplyHints(This,pHints) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsLunPlex_INTERFACE_DEFINED__ */


#ifndef __IVdsIscsiPortal_INTERFACE_DEFINED__
#define __IVdsIscsiPortal_INTERFACE_DEFINED__

/* interface IVdsIscsiPortal */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsIscsiPortal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7fa1499d-ec85-4a8a-a47b-ff69201fcd34")
    IVdsIscsiPortal : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_ISCSI_PORTAL_PROP *pPortalProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubSystem( 
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedPortalGroups( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ VDS_ISCSI_PORTAL_STATUS status) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIpsecTunnelAddress( 
            /* [in] */ __RPC__in VDS_IPADDRESS *pTunnelAddress,
            /* [in] */ __RPC__in VDS_IPADDRESS *pDestinationAddress) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIpsecSecurity( 
            /* [in] */ __RPC__in VDS_IPADDRESS *pInitiatorPortalAddress,
            /* [out] */ __RPC__out ULONGLONG *pullSecurityFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIpsecSecurity( 
            /* [in] */ __RPC__in VDS_IPADDRESS *pInitiatorPortalAddress,
            /* [in] */ ULONGLONG ullSecurityFlags,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_IPSEC_KEY *pIpsecKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsIscsiPortalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsIscsiPortal * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsIscsiPortal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsIscsiPortal * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsIscsiPortal * This,
            /* [out] */ __RPC__out VDS_ISCSI_PORTAL_PROP *pPortalProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSubSystem )( 
            IVdsIscsiPortal * This,
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedPortalGroups )( 
            IVdsIscsiPortal * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IVdsIscsiPortal * This,
            /* [in] */ VDS_ISCSI_PORTAL_STATUS status);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIpsecTunnelAddress )( 
            IVdsIscsiPortal * This,
            /* [in] */ __RPC__in VDS_IPADDRESS *pTunnelAddress,
            /* [in] */ __RPC__in VDS_IPADDRESS *pDestinationAddress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIpsecSecurity )( 
            IVdsIscsiPortal * This,
            /* [in] */ __RPC__in VDS_IPADDRESS *pInitiatorPortalAddress,
            /* [out] */ __RPC__out ULONGLONG *pullSecurityFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetIpsecSecurity )( 
            IVdsIscsiPortal * This,
            /* [in] */ __RPC__in VDS_IPADDRESS *pInitiatorPortalAddress,
            /* [in] */ ULONGLONG ullSecurityFlags,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_IPSEC_KEY *pIpsecKey);
        
        END_INTERFACE
    } IVdsIscsiPortalVtbl;

    interface IVdsIscsiPortal
    {
        CONST_VTBL struct IVdsIscsiPortalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsIscsiPortal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsIscsiPortal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsIscsiPortal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsIscsiPortal_GetProperties(This,pPortalProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pPortalProp) ) 

#define IVdsIscsiPortal_GetSubSystem(This,ppSubSystem)	\
    ( (This)->lpVtbl -> GetSubSystem(This,ppSubSystem) ) 

#define IVdsIscsiPortal_QueryAssociatedPortalGroups(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedPortalGroups(This,ppEnum) ) 

#define IVdsIscsiPortal_SetStatus(This,status)	\
    ( (This)->lpVtbl -> SetStatus(This,status) ) 

#define IVdsIscsiPortal_SetIpsecTunnelAddress(This,pTunnelAddress,pDestinationAddress)	\
    ( (This)->lpVtbl -> SetIpsecTunnelAddress(This,pTunnelAddress,pDestinationAddress) ) 

#define IVdsIscsiPortal_GetIpsecSecurity(This,pInitiatorPortalAddress,pullSecurityFlags)	\
    ( (This)->lpVtbl -> GetIpsecSecurity(This,pInitiatorPortalAddress,pullSecurityFlags) ) 

#define IVdsIscsiPortal_SetIpsecSecurity(This,pInitiatorPortalAddress,ullSecurityFlags,pIpsecKey)	\
    ( (This)->lpVtbl -> SetIpsecSecurity(This,pInitiatorPortalAddress,ullSecurityFlags,pIpsecKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsIscsiPortal_INTERFACE_DEFINED__ */


#ifndef __IVdsIscsiTarget_INTERFACE_DEFINED__
#define __IVdsIscsiTarget_INTERFACE_DEFINED__

/* interface IVdsIscsiTarget */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsIscsiTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("aa8f5055-83e5-4bcc-aa73-19851a36a849")
    IVdsIscsiTarget : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_ISCSI_TARGET_PROP *pTargetProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubSystem( 
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryPortalGroups( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedLuns( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreatePortalGroup( 
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFriendlyName( 
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSharedSecret( 
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_SHARED_SECRET *pTargetSharedSecret,
            /* [string][unique][in] */ __RPC__in_opt LPWSTR pwszInitiatorName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RememberInitiatorSharedSecret( 
            /* [string][in] */ __RPC__in LPWSTR pwszInitiatorName,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_SHARED_SECRET *pInitiatorSharedSecret) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetConnectedInitiators( 
            /* [size_is][size_is][string][out] */ __RPC__deref_out_ecount_full_opt_string(*plNumberOfInitiators) LPWSTR **pppwszInitiatorList,
            /* [out] */ __RPC__out LONG *plNumberOfInitiators) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsIscsiTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsIscsiTarget * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsIscsiTarget * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsIscsiTarget * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__out VDS_ISCSI_TARGET_PROP *pTargetProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSubSystem )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__deref_out_opt IVdsSubSystem **ppSubSystem);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryPortalGroups )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedLuns )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreatePortalGroup )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IVdsIscsiTarget * This,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetFriendlyName )( 
            IVdsIscsiTarget * This,
            /* [string][in] */ __RPC__in LPWSTR pwszFriendlyName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSharedSecret )( 
            IVdsIscsiTarget * This,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_SHARED_SECRET *pTargetSharedSecret,
            /* [string][unique][in] */ __RPC__in_opt LPWSTR pwszInitiatorName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RememberInitiatorSharedSecret )( 
            IVdsIscsiTarget * This,
            /* [string][in] */ __RPC__in LPWSTR pwszInitiatorName,
            /* [unique][in] */ __RPC__in_opt VDS_ISCSI_SHARED_SECRET *pInitiatorSharedSecret);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetConnectedInitiators )( 
            IVdsIscsiTarget * This,
            /* [size_is][size_is][string][out] */ __RPC__deref_out_ecount_full_opt_string(*plNumberOfInitiators) LPWSTR **pppwszInitiatorList,
            /* [out] */ __RPC__out LONG *plNumberOfInitiators);
        
        END_INTERFACE
    } IVdsIscsiTargetVtbl;

    interface IVdsIscsiTarget
    {
        CONST_VTBL struct IVdsIscsiTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsIscsiTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsIscsiTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsIscsiTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsIscsiTarget_GetProperties(This,pTargetProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pTargetProp) ) 

#define IVdsIscsiTarget_GetSubSystem(This,ppSubSystem)	\
    ( (This)->lpVtbl -> GetSubSystem(This,ppSubSystem) ) 

#define IVdsIscsiTarget_QueryPortalGroups(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryPortalGroups(This,ppEnum) ) 

#define IVdsIscsiTarget_QueryAssociatedLuns(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedLuns(This,ppEnum) ) 

#define IVdsIscsiTarget_CreatePortalGroup(This,ppAsync)	\
    ( (This)->lpVtbl -> CreatePortalGroup(This,ppAsync) ) 

#define IVdsIscsiTarget_Delete(This,ppAsync)	\
    ( (This)->lpVtbl -> Delete(This,ppAsync) ) 

#define IVdsIscsiTarget_SetFriendlyName(This,pwszFriendlyName)	\
    ( (This)->lpVtbl -> SetFriendlyName(This,pwszFriendlyName) ) 

#define IVdsIscsiTarget_SetSharedSecret(This,pTargetSharedSecret,pwszInitiatorName)	\
    ( (This)->lpVtbl -> SetSharedSecret(This,pTargetSharedSecret,pwszInitiatorName) ) 

#define IVdsIscsiTarget_RememberInitiatorSharedSecret(This,pwszInitiatorName,pInitiatorSharedSecret)	\
    ( (This)->lpVtbl -> RememberInitiatorSharedSecret(This,pwszInitiatorName,pInitiatorSharedSecret) ) 

#define IVdsIscsiTarget_GetConnectedInitiators(This,pppwszInitiatorList,plNumberOfInitiators)	\
    ( (This)->lpVtbl -> GetConnectedInitiators(This,pppwszInitiatorList,plNumberOfInitiators) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsIscsiTarget_INTERFACE_DEFINED__ */


#ifndef __IVdsIscsiPortalGroup_INTERFACE_DEFINED__
#define __IVdsIscsiPortalGroup_INTERFACE_DEFINED__

/* interface IVdsIscsiPortalGroup */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsIscsiPortalGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fef5f89d-a3dd-4b36-bf28-e7dde045c593")
    IVdsIscsiPortalGroup : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProperties( 
            /* [out] */ __RPC__out VDS_ISCSI_PORTALGROUP_PROP *pPortalGroupProp) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTarget( 
            /* [out] */ __RPC__deref_out_opt IVdsIscsiTarget **ppTarget) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryAssociatedPortals( 
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddPortal( 
            /* [in] */ VDS_OBJECT_ID portalId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RemovePortal( 
            /* [in] */ VDS_OBJECT_ID portalId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsIscsiPortalGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsIscsiPortalGroup * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsIscsiPortalGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsIscsiPortalGroup * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetProperties )( 
            IVdsIscsiPortalGroup * This,
            /* [out] */ __RPC__out VDS_ISCSI_PORTALGROUP_PROP *pPortalGroupProp);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTarget )( 
            IVdsIscsiPortalGroup * This,
            /* [out] */ __RPC__deref_out_opt IVdsIscsiTarget **ppTarget);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryAssociatedPortals )( 
            IVdsIscsiPortalGroup * This,
            /* [out] */ __RPC__deref_out_opt IEnumVdsObject **ppEnum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *AddPortal )( 
            IVdsIscsiPortalGroup * This,
            /* [in] */ VDS_OBJECT_ID portalId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemovePortal )( 
            IVdsIscsiPortalGroup * This,
            /* [in] */ VDS_OBJECT_ID portalId,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IVdsIscsiPortalGroup * This,
            /* [out] */ __RPC__deref_out_opt IVdsAsync **ppAsync);
        
        END_INTERFACE
    } IVdsIscsiPortalGroupVtbl;

    interface IVdsIscsiPortalGroup
    {
        CONST_VTBL struct IVdsIscsiPortalGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsIscsiPortalGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsIscsiPortalGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsIscsiPortalGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsIscsiPortalGroup_GetProperties(This,pPortalGroupProp)	\
    ( (This)->lpVtbl -> GetProperties(This,pPortalGroupProp) ) 

#define IVdsIscsiPortalGroup_GetTarget(This,ppTarget)	\
    ( (This)->lpVtbl -> GetTarget(This,ppTarget) ) 

#define IVdsIscsiPortalGroup_QueryAssociatedPortals(This,ppEnum)	\
    ( (This)->lpVtbl -> QueryAssociatedPortals(This,ppEnum) ) 

#define IVdsIscsiPortalGroup_AddPortal(This,portalId,ppAsync)	\
    ( (This)->lpVtbl -> AddPortal(This,portalId,ppAsync) ) 

#define IVdsIscsiPortalGroup_RemovePortal(This,portalId,ppAsync)	\
    ( (This)->lpVtbl -> RemovePortal(This,portalId,ppAsync) ) 

#define IVdsIscsiPortalGroup_Delete(This,ppAsync)	\
    ( (This)->lpVtbl -> Delete(This,ppAsync) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsIscsiPortalGroup_INTERFACE_DEFINED__ */


#ifndef __IVdsMaintenance_INTERFACE_DEFINED__
#define __IVdsMaintenance_INTERFACE_DEFINED__

/* interface IVdsMaintenance */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsMaintenance;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("daebeef3-8523-47ed-a2b9-05cecce2a1ae")
    IVdsMaintenance : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartMaintenance( 
            /* [in] */ VDS_MAINTENANCE_OPERATION operation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopMaintenance( 
            /* [in] */ VDS_MAINTENANCE_OPERATION operation) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PulseMaintenance( 
            /* [in] */ VDS_MAINTENANCE_OPERATION operation,
            /* [in] */ ULONG ulCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsMaintenanceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsMaintenance * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsMaintenance * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsMaintenance * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartMaintenance )( 
            IVdsMaintenance * This,
            /* [in] */ VDS_MAINTENANCE_OPERATION operation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopMaintenance )( 
            IVdsMaintenance * This,
            /* [in] */ VDS_MAINTENANCE_OPERATION operation);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PulseMaintenance )( 
            IVdsMaintenance * This,
            /* [in] */ VDS_MAINTENANCE_OPERATION operation,
            /* [in] */ ULONG ulCount);
        
        END_INTERFACE
    } IVdsMaintenanceVtbl;

    interface IVdsMaintenance
    {
        CONST_VTBL struct IVdsMaintenanceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsMaintenance_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsMaintenance_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsMaintenance_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsMaintenance_StartMaintenance(This,operation)	\
    ( (This)->lpVtbl -> StartMaintenance(This,operation) ) 

#define IVdsMaintenance_StopMaintenance(This,operation)	\
    ( (This)->lpVtbl -> StopMaintenance(This,operation) ) 

#define IVdsMaintenance_PulseMaintenance(This,operation,ulCount)	\
    ( (This)->lpVtbl -> PulseMaintenance(This,operation,ulCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsMaintenance_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vdshwprv_0000_0025 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0025_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0025_v0_0_s_ifspec;

#ifndef __IVdsHwProviderPrivate_INTERFACE_DEFINED__
#define __IVdsHwProviderPrivate_INTERFACE_DEFINED__

/* interface IVdsHwProviderPrivate */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsHwProviderPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98f17bf3-9f33-4f12-8714-8b4075092c2e")
    IVdsHwProviderPrivate : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryIfCreatedLun( 
            /* [string][in] */ __RPC__in LPWSTR pwszDevicePath,
            /* [in] */ __RPC__in VDS_LUN_INFORMATION *pVdsLunInformation,
            /* [out] */ __RPC__out VDS_OBJECT_ID *pLunId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsHwProviderPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsHwProviderPrivate * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsHwProviderPrivate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsHwProviderPrivate * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *QueryIfCreatedLun )( 
            IVdsHwProviderPrivate * This,
            /* [string][in] */ __RPC__in LPWSTR pwszDevicePath,
            /* [in] */ __RPC__in VDS_LUN_INFORMATION *pVdsLunInformation,
            /* [out] */ __RPC__out VDS_OBJECT_ID *pLunId);
        
        END_INTERFACE
    } IVdsHwProviderPrivateVtbl;

    interface IVdsHwProviderPrivate
    {
        CONST_VTBL struct IVdsHwProviderPrivateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsHwProviderPrivate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsHwProviderPrivate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsHwProviderPrivate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsHwProviderPrivate_QueryIfCreatedLun(This,pwszDevicePath,pVdsLunInformation,pLunId)	\
    ( (This)->lpVtbl -> QueryIfCreatedLun(This,pwszDevicePath,pVdsLunInformation,pLunId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsHwProviderPrivate_INTERFACE_DEFINED__ */


#ifndef __IVdsHwProviderPrivateMpio_INTERFACE_DEFINED__
#define __IVdsHwProviderPrivateMpio_INTERFACE_DEFINED__

/* interface IVdsHwProviderPrivateMpio */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsHwProviderPrivateMpio;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("310a7715-ac2b-4c6f-9827-3d742f351676")
    IVdsHwProviderPrivateMpio : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAllPathStatusesFromHbaPort( 
            /* [in] */ VDS_HBAPORT_PROP hbaPortProp,
            /* [in] */ VDS_PATH_STATUS status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsHwProviderPrivateMpioVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsHwProviderPrivateMpio * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsHwProviderPrivateMpio * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsHwProviderPrivateMpio * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAllPathStatusesFromHbaPort )( 
            IVdsHwProviderPrivateMpio * This,
            /* [in] */ VDS_HBAPORT_PROP hbaPortProp,
            /* [in] */ VDS_PATH_STATUS status);
        
        END_INTERFACE
    } IVdsHwProviderPrivateMpioVtbl;

    interface IVdsHwProviderPrivateMpio
    {
        CONST_VTBL struct IVdsHwProviderPrivateMpioVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsHwProviderPrivateMpio_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsHwProviderPrivateMpio_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsHwProviderPrivateMpio_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsHwProviderPrivateMpio_SetAllPathStatusesFromHbaPort(This,hbaPortProp,status)	\
    ( (This)->lpVtbl -> SetAllPathStatusesFromHbaPort(This,hbaPortProp,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsHwProviderPrivateMpio_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vdshwprv_0000_0027 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0027_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vdshwprv_0000_0027_v0_0_s_ifspec;

#ifndef __IVdsAdmin_INTERFACE_DEFINED__
#define __IVdsAdmin_INTERFACE_DEFINED__

/* interface IVdsAdmin */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVdsAdmin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d188e97d-85aa-4d33-abc6-26299a10ffc1")
    IVdsAdmin : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterProvider( 
            /* [in] */ VDS_OBJECT_ID providerId,
            /* [in] */ CLSID providerClsid,
            /* [string][max_is][in] */ __RPC__in_ecount_full_string(( 200 + 1 ) ) LPWSTR pwszName,
            /* [in] */ VDS_PROVIDER_TYPE type,
            /* [string][max_is][unique][in] */ __RPC__in_ecount_full_opt_string(( ( 15 - 1 )  + 1 ) ) LPWSTR pwszMachineName,
            /* [string][max_is][in] */ __RPC__in_ecount_full_string(( 16 + 1 ) ) LPWSTR pwszVersion,
            /* [in] */ GUID guidVersionId) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE UnregisterProvider( 
            /* [in] */ VDS_OBJECT_ID providerId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVdsAdminVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVdsAdmin * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVdsAdmin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVdsAdmin * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterProvider )( 
            IVdsAdmin * This,
            /* [in] */ VDS_OBJECT_ID providerId,
            /* [in] */ CLSID providerClsid,
            /* [string][max_is][in] */ __RPC__in_ecount_full_string(( 200 + 1 ) ) LPWSTR pwszName,
            /* [in] */ VDS_PROVIDER_TYPE type,
            /* [string][max_is][unique][in] */ __RPC__in_ecount_full_opt_string(( ( 15 - 1 )  + 1 ) ) LPWSTR pwszMachineName,
            /* [string][max_is][in] */ __RPC__in_ecount_full_string(( 16 + 1 ) ) LPWSTR pwszVersion,
            /* [in] */ GUID guidVersionId);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *UnregisterProvider )( 
            IVdsAdmin * This,
            /* [in] */ VDS_OBJECT_ID providerId);
        
        END_INTERFACE
    } IVdsAdminVtbl;

    interface IVdsAdmin
    {
        CONST_VTBL struct IVdsAdminVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVdsAdmin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVdsAdmin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVdsAdmin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVdsAdmin_RegisterProvider(This,providerId,providerClsid,pwszName,type,pwszMachineName,pwszVersion,guidVersionId)	\
    ( (This)->lpVtbl -> RegisterProvider(This,providerId,providerClsid,pwszName,type,pwszMachineName,pwszVersion,guidVersionId) ) 

#define IVdsAdmin_UnregisterProvider(This,providerId)	\
    ( (This)->lpVtbl -> UnregisterProvider(This,providerId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVdsAdmin_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



