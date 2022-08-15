/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    clusapi.h

Abstract:

    This module defines the common management and application interface to
    the Microsoft Cluster Server services.

Revision History:

--*/

#ifndef _CLUSTER_API_
#define _CLUSTER_API_

#define CLUSAPI_VERSION 0x0600

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if ( !MIDL_PASS && !__midl )
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable : 4200 ) // nonstandard extension used : zero-sized array in struct/union
#pragma warning( disable : 4201 ) // nonstandard extension used : nameless struct/union
#endif // MIDL_PASS

//
// General cluster definitions
//

#ifndef _CLUSTER_API_TYPES_
//
// Defined cluster handle types.
//
typedef struct _HCLUSTER *HCLUSTER;
typedef struct _HNODE *HNODE;
typedef struct _HRESOURCE *HRESOURCE;
typedef struct _HGROUP *HGROUP;
typedef struct _HNETWORK *HNETWORK;
typedef struct _HNETINTERFACE *HNETINTERFACE;
typedef struct _HCHANGE *HCHANGE;
typedef struct _HCLUSENUM *HCLUSENUM;
typedef struct _HGROUPENUM *HGROUPENUM;
typedef struct _HRESENUM *HRESENUM;
typedef struct _HNETWORKENUM *HNETWORKENUM;
typedef struct _HNODEENUM *HNODEENUM;
typedef struct _HRESTYPEENUM *HRESTYPEENUM;
typedef struct _HREGBATCH *HREGBATCH;

#endif // _CLUSTER_API_TYPES_

//
// Definitions used in cluster management routines.
//

#define MAX_CLUSTERNAME_LENGTH      DNS_MAX_LABEL_LENGTH

#ifndef _CLUSTER_API_TYPES_
//
// Cluster-related structures and types
//
typedef enum CLUSTER_QUORUM_TYPE {
    OperationalQuorum,
    ModifyQuorum
} CLUSTER_QUORUM_TYPE;

#if ( !MIDL_PASS && !__midl )

typedef struct CLUSTERVERSIONINFO_NT4 {
    DWORD dwVersionInfoSize;
    WORD  MajorVersion;
    WORD  MinorVersion;
    WORD  BuildNumber;
    WCHAR szVendorId[64];
    WCHAR szCSDVersion[64];
}CLUSTERVERSIONINFO_NT4, *PCLUSTERVERSIONINFO_NT4;

typedef struct CLUSTERVERSIONINFO {
    DWORD dwVersionInfoSize;
    WORD  MajorVersion;
    WORD  MinorVersion;
    WORD  BuildNumber;
    WCHAR szVendorId[64];
    WCHAR szCSDVersion[64];
    DWORD dwClusterHighestVersion;
    DWORD dwClusterLowestVersion;
    DWORD dwFlags;
    DWORD dwReserved;
} CLUSTERVERSIONINFO, *LPCLUSTERVERSIONINFO, *PCLUSTERVERSIONINFO;


typedef struct CLUS_STARTING_PARAMS {
    DWORD   dwSize;
    BOOL    bForm;
    BOOL    bFirst;
} CLUS_STARTING_PARAMS, * PCLUS_STARTING_PARAMS;




#define     CLUSTER_VERSION_FLAG_MIXED_MODE     0x00000001

#define NT4_MAJOR_VERSION           1
#define NT4SP4_MAJOR_VERSION        2
#define NT5_MAJOR_VERSION           3
#define NT51_MAJOR_VERSION          4
#define LONGHORN_MAJOR_VERSION      5

#define CLUSTER_VERSION_UNKNOWN         0xFFFFFFFF


//
// Version number macros
//

#define CLUSTER_MAKE_VERSION( _maj, _min ) ((( _maj ) << 16 ) | ( _min ))
#define CLUSTER_GET_MAJOR_VERSION( _ver ) (( _ver ) >> 16 )
#define CLUSTER_GET_MINOR_VERSION( _ver ) (( _ver ) & 0xFFFF )

#endif // MIDL_PASS

//
// Interfaces for the cluster state on a node
//
#define CLUSTER_INSTALLED   0x00000001
#define CLUSTER_CONFIGURED  0x00000002
#define CLUSTER_RUNNING     0x00000010

typedef enum NODE_CLUSTER_STATE {
    ClusterStateNotInstalled                = 0x00000000,
    ClusterStateNotConfigured               = CLUSTER_INSTALLED,
    ClusterStateNotRunning                  = CLUSTER_INSTALLED | CLUSTER_CONFIGURED,
    ClusterStateRunning                     = CLUSTER_INSTALLED | CLUSTER_CONFIGURED | CLUSTER_RUNNING
} NODE_CLUSTER_STATE;

// Quorum mode flags for SetClusterQuorumResource API

#define CLUS_HYBRID_QUORUM          1024                // 0xFFFFFFFF
#define CLUS_NODE_MAJORITY_QUORUM   0                   // 0xFFFFFFFE
#define CLUS_LEGACY_QUORUM          (4 * 1024 * 1024)   // 0xFFFFFFFD

//
//  Resource state change reason related types and defines
//
#define CLUSCTL_RESOURCE_STATE_CHANGE_REASON_VERSION_1  1

typedef enum CLUSTER_RESOURCE_STATE_CHANGE_REASON {
    eResourceStateChangeReasonUnknown,
    eResourceStateChangeReasonMove,
    eResourceStateChangeReasonFailover,
    eResourceStateChangeReasonFailedMove,
    eResourceStateChangeReasonShutdown,
    eResourceStateChangeReasonRundown
} CLUSTER_RESOURCE_STATE_CHANGE_REASON;

typedef enum _CLUSTER_REG_COMMAND
{
    CLUSREG_COMMAND_NONE = 0,

    CLUSREG_SET_VALUE = 1,
    CLUSREG_CREATE_KEY,
    CLUSREG_DELETE_KEY,
    CLUSREG_DELETE_VALUE,
    CLUSREG_SET_KEY_SECURITY,

    CLUSREG_LAST_COMMAND

} CLUSTER_REG_COMMAND;


#if ( !MIDL_PASS && !__midl )

typedef struct _CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT {
    DWORD                                   dwSize;
    DWORD                                   dwVersion;
    CLUSTER_RESOURCE_STATE_CHANGE_REASON    eReason;
} CLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT, *PCLUSCTL_RESOURCE_STATE_CHANGE_REASON_STRUCT;


#endif // MIDL_PASS

#endif // _CLUSTER_API_TYPES_


//
// Interfaces for managing clusters
//

//
// Cluster API Specific Access Rights
//
#define CLUSAPI_READ_ACCESS     0x00000001L
#define CLUSAPI_CHANGE_ACCESS   0x00000002L
#define CLUSAPI_NO_ACCESS       0x00000004L
#define CLUSAPI_ALL_ACCESS (CLUSAPI_READ_ACCESS | CLUSAPI_CHANGE_ACCESS)

//
// Return values for CLUSCTL_CLUSTER_CHECK_VOTER_DOWN and CLUSCTL_CLUSTER_CHECK_VOTER_EVICT
//
typedef enum CLUSTER_QUORUM_VALUE {
    CLUSTER_QUORUM_MAINTAINED = 0,
    CLUSTER_QUORUM_LOST = 1,
} CLUSTER_QUORUM_VALUE;

#if ( !MIDL_PASS && !__midl )

//
// Structure used to return the status of a request to set the
// password on the account used by the Cluster Service on each
// cluster node.
//
typedef struct CLUSTER_SET_PASSWORD_STATUS {
    DWORD    NodeId;
    BOOLEAN  SetAttempted;
    DWORD    ReturnStatus;
} CLUSTER_SET_PASSWORD_STATUS, *PCLUSTER_SET_PASSWORD_STATUS;

#ifndef _CLUSTER_API_TYPES_
typedef struct _CLUSTER_IP_ENTRY
{
    PCWSTR          lpszIpAddress;
    DWORD           dwPrefixLength;
} CLUSTER_IP_ENTRY, *PCLUSTER_IP_ENTRY;

typedef struct _CREATE_CLUSTER_CONFIG
{
    DWORD             dwVersion;          
    PCWSTR            lpszClusterName;    
    DWORD             cNodes;           
    PCWSTR *          ppszNodeNames;   
    DWORD             cIpEntries;       
    PCLUSTER_IP_ENTRY pIpEntries;
    PCWSTR            lpszQuorumVolume;
} CREATE_CLUSTER_CONFIG, *PCREATE_CLUSTER_CONFIG;
#endif // _CLUSTER_API_TYPES_

DWORD
WINAPI
GetNodeClusterState(
    __in_opt    LPCWSTR lpszNodeName,
    __out       LPDWORD pdwClusterState
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_NODE_CLUSTER_STATE)(
    __in_opt    LPCWSTR lpszNodeName,
    __out       LPDWORD pdwClusterState
    );

HCLUSTER
WINAPI
OpenCluster(
    __in_opt LPCWSTR lpszClusterName
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_OPEN_CLUSTER)(
    __in_opt LPCWSTR lpszClusterName
    );

BOOL
WINAPI
CloseCluster(
    __in HCLUSTER hCluster
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER)(
    __in HCLUSTER hCluster
    );

DWORD
WINAPI
SetClusterName(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNewClusterName
    );

typedef DWORD
(WINAPI * PCLUSAPI_SetClusterName)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNewClusterName
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterInformation(
    __in HCLUSTER hCluster,
    __out_ecount_part(*lpcchClusterName, *lpcchClusterName + 1) LPWSTR lpszClusterName,
    __inout LPDWORD lpcchClusterName,
    __out_opt LPCLUSTERVERSIONINFO lpClusterInfo
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_INFORMATION)(
    __in HCLUSTER hCluster,
    __out_ecount_part(*lpcchClusterName, *lpcchClusterName + 1) LPWSTR lpszClusterName,
    __inout LPDWORD lpcchClusterName,
    __out_opt LPCLUSTERVERSIONINFO lpClusterInfo
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterQuorumResource(
    __in HCLUSTER hCluster,
    __out_ecount_part(*lpcchResourceName, *lpcchResourceName + 1) LPWSTR lpszResourceName,
    __inout LPDWORD lpcchResourceName,
    __out_ecount_part(*lpcchDeviceName, *lpcchDeviceName + 1) LPWSTR lpszDeviceName,
    __inout LPDWORD lpcchDeviceName,
    __out LPDWORD lpdwMaxQuorumLogSize
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_QUORUM_RESOURCE)(
    __in HCLUSTER hCluster,
    __out_ecount_part(*lpcchResourceName, *lpcchResourceName + 1) LPWSTR lpszResourceName,
    __inout LPDWORD lpcchResourceName,
    __out_ecount_part(*lpcchDeviceName, *lpcchDeviceName + 1) LPWSTR lpszDeviceName,
    __inout LPDWORD lpcchDeviceName,
    __out LPDWORD lpdwMaxQuorumLogSize
    );

DWORD
WINAPI
SetClusterQuorumResource(
    __in     HRESOURCE hResource,
    __in_opt LPCWSTR   lpszDeviceName,
    __in     DWORD     dwMaxQuoLogSize
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_QUORUM_RESOURCE)(
    __in     HRESOURCE hResource,
    __in_opt LPCWSTR   lpszDeviceName,
    __in     DWORD     dwMaxQuoLogSize
    );

DWORD
WINAPI
BackupClusterDatabase(
    __in HCLUSTER hCluster,
    __in LPCWSTR  lpszPathName
    );

typedef DWORD
(WINAPI * PCLUSAPI_BACKUP_CLUSTER_DATABASE)(
    __in HCLUSTER hCluster,
    __in LPCWSTR  lpszPathName
    );

DWORD
WINAPI
RestoreClusterDatabase(
    __in LPCWSTR  lpszPathName,
    __in BOOL     bForce,
    __in_opt LPCWSTR  lpszQuorumDriveLetter
    );

typedef DWORD
(WINAPI * PCLUSAPI_RESTORE_CLUSTER_DATABASE)(
    __in LPCWSTR  lpszPathName,
    __in BOOL     bForce,
    __in_opt LPCWSTR  lpszQuorumDriveLetter
    );

DWORD
WINAPI
SetClusterNetworkPriorityOrder(
    __in HCLUSTER hCluster,
    __in DWORD NetworkCount,
    __in_ecount( NetworkCount ) HNETWORK NetworkList[]
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_NETWORK_PRIORITY_ORDER)(
    __in HCLUSTER hCluster,
    __in DWORD NetworkCount,
    __in_ecount( NetworkCount ) HNETWORK NetworkList[]
    );

DWORD
WINAPI
SetClusterServiceAccountPassword(
    __in LPCWSTR lpszClusterName,
    __in LPCWSTR lpszNewPassword,
    __in DWORD dwFlags,
    __out_bcount_part_opt(*lpcbReturnStatusBufferSize, *lpcbReturnStatusBufferSize) PCLUSTER_SET_PASSWORD_STATUS lpReturnStatusBuffer,
    __inout LPDWORD lpcbReturnStatusBufferSize
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_SERVICE_ACCOUNT_PASSWORD)(
    __in LPCWSTR lpszClusterName,
    __in LPCWSTR lpszNewPassword,
    __in DWORD dwFlags,
    __out_bcount_part_opt(*lpcbReturnStatusBufferSize, *lpcbReturnStatusBufferSize) PCLUSTER_SET_PASSWORD_STATUS lpReturnStatusBuffer,
    __inout LPDWORD lpcbReturnStatusBufferSize
    );

DWORD
WINAPI
ClusterControl(
    __in HCLUSTER hCluster,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_CONTROL)(
    __in HCLUSTER hCluster,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

#endif // MIDL_PASS

//
// Cluster Event Notification API
//

#ifndef _CLUSTER_API_TYPES_
//
// Cluster event filter flags.
//
typedef enum CLUSTER_CHANGE {
    CLUSTER_CHANGE_NODE_STATE               = 0x00000001,
    CLUSTER_CHANGE_NODE_DELETED             = 0x00000002,
    CLUSTER_CHANGE_NODE_ADDED               = 0x00000004,
    CLUSTER_CHANGE_NODE_PROPERTY            = 0x00000008,

    CLUSTER_CHANGE_REGISTRY_NAME            = 0x00000010,
    CLUSTER_CHANGE_REGISTRY_ATTRIBUTES      = 0x00000020,
    CLUSTER_CHANGE_REGISTRY_VALUE           = 0x00000040,
    CLUSTER_CHANGE_REGISTRY_SUBTREE         = 0x00000080,

    CLUSTER_CHANGE_RESOURCE_STATE           = 0x00000100,
    CLUSTER_CHANGE_RESOURCE_DELETED         = 0x00000200,
    CLUSTER_CHANGE_RESOURCE_ADDED           = 0x00000400,
    CLUSTER_CHANGE_RESOURCE_PROPERTY        = 0x00000800,

    CLUSTER_CHANGE_GROUP_STATE              = 0x00001000,
    CLUSTER_CHANGE_GROUP_DELETED            = 0x00002000,
    CLUSTER_CHANGE_GROUP_ADDED              = 0x00004000,
    CLUSTER_CHANGE_GROUP_PROPERTY           = 0x00008000,

    CLUSTER_CHANGE_RESOURCE_TYPE_DELETED    = 0x00010000,
    CLUSTER_CHANGE_RESOURCE_TYPE_ADDED      = 0x00020000,
    CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY   = 0x00040000,

    CLUSTER_CHANGE_CLUSTER_RECONNECT        = 0x00080000,

    CLUSTER_CHANGE_NETWORK_STATE            = 0x00100000,
    CLUSTER_CHANGE_NETWORK_DELETED          = 0x00200000,
    CLUSTER_CHANGE_NETWORK_ADDED            = 0x00400000,
    CLUSTER_CHANGE_NETWORK_PROPERTY         = 0x00800000,

    CLUSTER_CHANGE_NETINTERFACE_STATE       = 0x01000000,
    CLUSTER_CHANGE_NETINTERFACE_DELETED     = 0x02000000,
    CLUSTER_CHANGE_NETINTERFACE_ADDED       = 0x04000000,
    CLUSTER_CHANGE_NETINTERFACE_PROPERTY    = 0x08000000,

    CLUSTER_CHANGE_QUORUM_STATE             = 0x10000000,
    CLUSTER_CHANGE_CLUSTER_STATE            = 0x20000000,
    CLUSTER_CHANGE_CLUSTER_PROPERTY         = 0x40000000,


    CLUSTER_CHANGE_HANDLE_CLOSE             = 0x80000000,

    CLUSTER_CHANGE_ALL                      = (CLUSTER_CHANGE_NODE_STATE                |
                                               CLUSTER_CHANGE_NODE_DELETED              |
                                               CLUSTER_CHANGE_NODE_ADDED                |
                                               CLUSTER_CHANGE_NODE_PROPERTY             |
                                               CLUSTER_CHANGE_REGISTRY_NAME             |
                                               CLUSTER_CHANGE_REGISTRY_ATTRIBUTES       |
                                               CLUSTER_CHANGE_REGISTRY_VALUE            |
                                               CLUSTER_CHANGE_REGISTRY_SUBTREE          |
                                               CLUSTER_CHANGE_RESOURCE_STATE            |
                                               CLUSTER_CHANGE_RESOURCE_DELETED          |
                                               CLUSTER_CHANGE_RESOURCE_ADDED            |
                                               CLUSTER_CHANGE_RESOURCE_PROPERTY         |
                                               CLUSTER_CHANGE_GROUP_STATE               |
                                               CLUSTER_CHANGE_GROUP_DELETED             |
                                               CLUSTER_CHANGE_GROUP_ADDED               |
                                               CLUSTER_CHANGE_GROUP_PROPERTY            |
                                               CLUSTER_CHANGE_RESOURCE_TYPE_DELETED     |
                                               CLUSTER_CHANGE_RESOURCE_TYPE_ADDED       |
                                               CLUSTER_CHANGE_RESOURCE_TYPE_PROPERTY    |
                                               CLUSTER_CHANGE_NETWORK_STATE             |
                                               CLUSTER_CHANGE_NETWORK_DELETED           |
                                               CLUSTER_CHANGE_NETWORK_ADDED             |
                                               CLUSTER_CHANGE_NETWORK_PROPERTY          |
                                               CLUSTER_CHANGE_NETINTERFACE_STATE        |
                                               CLUSTER_CHANGE_NETINTERFACE_DELETED      |
                                               CLUSTER_CHANGE_NETINTERFACE_ADDED        |
                                               CLUSTER_CHANGE_NETINTERFACE_PROPERTY     |
                                               CLUSTER_CHANGE_QUORUM_STATE              |
                                               CLUSTER_CHANGE_CLUSTER_STATE             |
                                               CLUSTER_CHANGE_CLUSTER_PROPERTY          |
                                               CLUSTER_CHANGE_CLUSTER_RECONNECT         |
                                               CLUSTER_CHANGE_HANDLE_CLOSE)

} CLUSTER_CHANGE;

#endif // _CLUSTER_API_TYPES_

#if ( !MIDL_PASS && !__midl )
HCHANGE
WINAPI
CreateClusterNotifyPort(
    __in HCHANGE hChange,
    __in HCLUSTER hCluster,
    __in DWORD dwFilter,
    __in DWORD_PTR dwNotifyKey
    );

typedef HCHANGE
(WINAPI * PCLUSAPI_CREATE_CLUSTER_NOTIFY_PORT)(
    __in HCHANGE hChange,
    __in HCLUSTER hCluster,
    __in DWORD dwFilter,
    __in DWORD_PTR dwNotifyKey
    );

DWORD
WINAPI
RegisterClusterNotify(
    __in HCHANGE hChange,
    __in DWORD dwFilterType,
    __in HANDLE hObject,
    __in DWORD_PTR dwNotifyKey
    );

typedef DWORD
(WINAPI * PCLUSAPI_REGISTER_CLUSTER_NOTIFY)(
    __in HCHANGE hChange,
    __in DWORD dwFilterType,
    __in HANDLE hObject,
    __in DWORD_PTR dwNotifyKey
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterNotify(
    __in HCHANGE hChange,
    __out DWORD_PTR *lpdwNotifyKey,
    __out LPDWORD lpdwFilterType,
    __out_ecount(*lpcchName) LPWSTR lpszName,
    __inout LPDWORD lpcchName,
    __in DWORD dwMilliseconds
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_NOTIFY)(
    __in HCHANGE hChange,
    __out DWORD_PTR *lpdwNotifyKey,
    __out LPDWORD lpdwFilterType,
    __out_ecount_part_opt(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName,
    __in DWORD dwMilliseconds
    );

BOOL
WINAPI
CloseClusterNotifyPort(
    __in HCHANGE hChange
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_NOTIFY_PORT)(
    __in HCHANGE hChange
    );

#endif // MIDL_PASS

//
// Enumeration routines
//

#ifndef _CLUSTER_API_TYPES_
//
// Define enumerable types
//
typedef enum CLUSTER_ENUM {
    CLUSTER_ENUM_NODE               = 0x00000001,
    CLUSTER_ENUM_RESTYPE            = 0x00000002,
    CLUSTER_ENUM_RESOURCE           = 0x00000004,
    CLUSTER_ENUM_GROUP              = 0x00000008,
    CLUSTER_ENUM_NETWORK            = 0x00000010,
    CLUSTER_ENUM_NETINTERFACE       = 0x00000020,
    CLUSTER_ENUM_INTERNAL_NETWORK   = 0x80000000,

    CLUSTER_ENUM_ALL                = (CLUSTER_ENUM_NODE      |
                                       CLUSTER_ENUM_RESTYPE   |
                                       CLUSTER_ENUM_RESOURCE  |
                                       CLUSTER_ENUM_GROUP     |
                                       CLUSTER_ENUM_NETWORK   |
                                       CLUSTER_ENUM_NETINTERFACE)

} CLUSTER_ENUM;

#endif // _CLUSTER_API_TYPES_

#if ( !MIDL_PASS && !__midl )
HCLUSENUM
WINAPI
ClusterOpenEnum(
    __in HCLUSTER hCluster,
    __in DWORD dwType
    );

typedef HCLUSENUM
(WINAPI * PCLUSAPI_CLUSTER_OPEN_ENUM)(
    __in HCLUSTER hCluster,
    __in DWORD dwType
    );

DWORD
WINAPI
ClusterGetEnumCount(
    __in HCLUSENUM hEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_GET_ENUM_COUNT)(
    __in HCLUSENUM hEnum
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterEnum(
    __in HCLUSENUM hEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_ENUM)(
    __in HCLUSENUM hEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterCloseEnum(
    __in HCLUSENUM hEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_CLOSE_ENUM)(
    __in HCLUSENUM hEnum
    );

#endif // MIDL_PASS


#ifndef _CLUSTER_API_TYPES_
//
// Define enumerable node types
//
typedef enum CLUSTER_NODE_ENUM {
    CLUSTER_NODE_ENUM_NETINTERFACES = 0x00000001,

    CLUSTER_NODE_ENUM_ALL           = (CLUSTER_NODE_ENUM_NETINTERFACES)

} CLUSTER_NODE_ENUM;

//
// Node-related structures and types.
//
typedef enum CLUSTER_NODE_STATE {
    ClusterNodeStateUnknown = -1,
    ClusterNodeUp,
    ClusterNodeDown,
    ClusterNodePaused,
    ClusterNodeJoining
} CLUSTER_NODE_STATE;

#endif // _CLUSTER_API_TYPES_

//
// Interfaces for managing the nodes of a cluster.
//

#if ( !MIDL_PASS && !__midl )
HNODE
WINAPI
OpenClusterNode(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNodeName
    );

typedef HNODE
(WINAPI * PCLUSAPI_OPEN_CLUSTER_NODE)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNodeName
    );

BOOL
WINAPI
CloseClusterNode(
    __in HNODE hNode
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_NODE)(
    __in HNODE hNode
    );

CLUSTER_NODE_STATE
WINAPI
GetClusterNodeState(
    __in HNODE hNode
    );

typedef CLUSTER_NODE_STATE
(WINAPI * PCLUSAPI_GET_CLUSTER_NODE_STATE)(
    __in HNODE hNode
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterNodeId(
    __in HNODE hNode,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszNodeId,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_NODE_ID)(
    __in HNODE hNode,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszNodeId,
    __inout LPDWORD lpcchName
    );

#define GetCurrentClusterNodeId(_lpszNodeId_, _lpcchName_) \
    GetClusterNodeId(NULL, (_lpszNodeId_), (_lpcchName_))

HCLUSTER
WINAPI
GetClusterFromNode(
    __in HNODE hNode
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_GET_CLUSTER_FROM_NODE)(
    __in HNODE hNode
    );

DWORD
WINAPI
PauseClusterNode(
    __in HNODE hNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_PAUSE_CLUSTER_NODE)(
    __in HNODE hNode
    );

DWORD
WINAPI
ResumeClusterNode(
    __in HNODE hNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_RESUME_CLUSTER_NODE)(
    __in HNODE hNode
    );

DWORD
WINAPI
EvictClusterNode(
    __in HNODE hNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_EVICT_CLUSTER_NODE)(
    __in HNODE hNode
    );

HNODEENUM
WINAPI
ClusterNodeOpenEnum(
    __in HNODE hNode,
    __in DWORD dwType
    );

typedef HNODEENUM
(WINAPI * PCLUSAPI_CLUSTER_NODE_OPEN_ENUM)(
    __in HNODE hNode,
    __in DWORD dwType
    );

DWORD
WINAPI
ClusterNodeGetEnumCount(
    __in HNODEENUM hNodeEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NODE_GET_ENUM_COUNT)(
    __in HNODEENUM hNodeEnum
    );

DWORD
WINAPI
ClusterNodeCloseEnum(
    __in HNODEENUM hNodeEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NODE_CLOSE_ENUM)(
    __in HNODEENUM hNodeEnum
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterNodeEnum(
    __in HNODEENUM hNodeEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NODE_ENUM)(
    __in HNODEENUM hNodeEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
EvictClusterNodeEx(
    __in HNODE hNode,
    __in DWORD dwTimeOut,
    __out HRESULT * phrCleanupStatus
    );

typedef DWORD
(WINAPI * PCLUSAPI_EVICT_CLUSTER_NODE_EX)(
    __in HNODE hNode,
    __in DWORD dwTimeOut,
    __out HRESULT * phrCleanupStatus
    );

#endif // MIDL_PASS


//
// Interfaces for managing the resource types in a cluster
//

#if ( !MIDL_PASS && !__midl )
HKEY
WINAPI
GetClusterResourceTypeKey(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszTypeName,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_RESOURCE_TYPE_KEY)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszTypeName,
    __in REGSAM samDesired
    );

#endif // MIDL_PASS

#ifndef _CLUSTER_API_TYPES_
//
// Define enumerable group types
//
typedef enum CLUSTER_GROUP_ENUM {
    CLUSTER_GROUP_ENUM_CONTAINS     = 0x00000001,
    CLUSTER_GROUP_ENUM_NODES        = 0x00000002,

    CLUSTER_GROUP_ENUM_ALL          = (CLUSTER_GROUP_ENUM_CONTAINS |
                                       CLUSTER_GROUP_ENUM_NODES)
} CLUSTER_GROUP_ENUM;

//
// Interfaces for managing the failover groups in a cluster.
//
typedef enum CLUSTER_GROUP_STATE {
    ClusterGroupStateUnknown = -1,
    ClusterGroupOnline,
    ClusterGroupOffline,
    ClusterGroupFailed,
    ClusterGroupPartialOnline,
    ClusterGroupPending
} CLUSTER_GROUP_STATE;

typedef enum CLUSTER_GROUP_AUTOFAILBACK_TYPE
{
    ClusterGroupPreventFailback = 0,
    ClusterGroupAllowFailback,
    ClusterGroupFailbackTypeCount
} CLUSTER_GROUP_AUTOFAILBACK_TYPE, CGAFT;

#endif // _CLUSTER_API_TYPES_

#if ( !MIDL_PASS && !__midl )
HGROUP
WINAPI
CreateClusterGroup(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszGroupName
    );

typedef HGROUP
(WINAPI * PCLUSAPI_CREATE_CLUSTER_GROUP)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszGroupName
    );

HGROUP
WINAPI
OpenClusterGroup(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszGroupName
    );

typedef HGROUP
(WINAPI * PCLUSAPI_OPEN_CLUSTER_GROUP)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszGroupName
    );

BOOL
WINAPI
CloseClusterGroup(
    __in HGROUP hGroup
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_GROUP)(
    __in HGROUP hGroup
    );

HCLUSTER
WINAPI
GetClusterFromGroup(
    __in HGROUP hGroup
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_GET_CLUSTER_FROM_GROUP)(
    __in HGROUP hGroup
    );

__success(return >= 0) //!= ClusterGroupStateUnknown
CLUSTER_GROUP_STATE
WINAPI
GetClusterGroupState(
    __in HGROUP hGroup,
    __out_ecount_part_opt(*lpcchNodeName, *lpcchNodeName + 1) LPWSTR lpszNodeName,
    __inout_opt LPDWORD lpcchNodeName
    );

typedef CLUSTER_GROUP_STATE
(WINAPI * PCLUSAPI_GET_CLUSTER_GROUP_STATE)(
    __in HGROUP hGroup,
    __out_ecount_part_opt(*lpcchNodeName, *lpcchNodeName + 1) LPWSTR lpszNodeName,
    __inout_opt LPDWORD lpcchNodeName
    );

DWORD
WINAPI
SetClusterGroupName(
    __in HGROUP hGroup,
    __in LPCWSTR lpszGroupName
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_GROUP_NAME)(
    HGROUP hGroup,
    LPCWSTR lpszGroupName
    );

DWORD
WINAPI
SetClusterGroupNodeList(
    __in HGROUP hGroup,
    __in DWORD NodeCount,
    __in_ecount( NodeCount ) HNODE NodeList[]
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_GROUP_NODE_LIST)(
    __in HGROUP hGroup,
    __in DWORD NodeCount,
    __in_ecount( NodeCount ) HNODE NodeList[]
    );

DWORD
WINAPI
OnlineClusterGroup(
    __in HGROUP hGroup,
    __in_opt HNODE hDestinationNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_ONLINE_CLUSTER_GROUP)(
    __in HGROUP hGroup,
    __in_opt HNODE hDestinationNode
    );

DWORD
WINAPI
MoveClusterGroup(
    __in HGROUP hGroup,
    __in_opt HNODE hDestinationNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_MOVE_CLUSTER_GROUP)(
    __in HGROUP hGroup,
    __in_opt HNODE hDestinationNode
    );

DWORD
WINAPI
OfflineClusterGroup(
    __in HGROUP hGroup
    );

typedef DWORD
(WINAPI * PCLUSAPI_OFFLINE_CLUSTER_GROUP)(
    HGROUP hGroup
    );

DWORD
WINAPI
DeleteClusterGroup(
    __in HGROUP hGroup
    );

typedef DWORD
(WINAPI * PCLUSAPI_DELETE_CLUSTER_GROUP)(
    HGROUP hGroup
    );

HGROUPENUM
WINAPI
ClusterGroupOpenEnum(
    __in HGROUP hGroup,
    __in DWORD dwType
    );

typedef HGROUPENUM
(WINAPI * PCLUSAPI_CLUSTER_GROUP_OPEN_ENUM)(
    HGROUP hGroup,
    DWORD dwType
    );

DWORD
WINAPI
ClusterGroupGetEnumCount(
    __in HGROUPENUM hGroupEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_GROUP_GET_ENUM_COUNT)(
    __in HGROUPENUM hGroupEnum
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterGroupEnum(
    __in HGROUPENUM hGroupEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszResourceName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_GROUP_ENUM)(
    __in HGROUPENUM hGroupEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszResourceName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterGroupCloseEnum(
    __in HGROUPENUM hGroupEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_GROUP_CLOSE_ENUM)(
    HGROUPENUM hGroupEnum
    );

#endif // MIDL_PASS


//
// Definitions used in resource management routines.
//

#ifndef _CLUSTER_API_TYPES_
//
// Resource-related structures and types
//
typedef enum CLUSTER_RESOURCE_STATE {
    ClusterResourceStateUnknown = -1,
    ClusterResourceInherited,
    ClusterResourceInitializing,
    ClusterResourceOnline,
    ClusterResourceOffline,
    ClusterResourceFailed,
    ClusterResourcePending = 128,
    ClusterResourceOnlinePending,
    ClusterResourceOfflinePending
} CLUSTER_RESOURCE_STATE;

typedef enum CLUSTER_RESOURCE_RESTART_ACTION {
    ClusterResourceDontRestart = 0,
    ClusterResourceRestartNoNotify,
    ClusterResourceRestartNotify,
    ClusterResourceRestartNotifyIfNotInORexpression,
    ClusterResourceRestartActionCount
} CLUSTER_RESOURCE_RESTART_ACTION, CRRA;

//
// Flags for resource creation
//
typedef enum CLUSTER_RESOURCE_CREATE_FLAGS {
    CLUSTER_RESOURCE_DEFAULT_MONITOR   = 0,
    CLUSTER_RESOURCE_SEPARATE_MONITOR  = 1,
    CLUSTER_RESOURCE_VALID_FLAGS       = CLUSTER_RESOURCE_SEPARATE_MONITOR
} CLUSTER_RESOURCE_CREATE_FLAGS;

#endif // _CLUSTER_API_TYPES_

//
// Interfaces for managing the resources in a cluster
//

#if ( !MIDL_PASS && !__midl )
HRESOURCE
WINAPI
CreateClusterResource(
    __in HGROUP hGroup,
    __in LPCWSTR lpszResourceName,
    __in LPCWSTR lpszResourceType,
    __in DWORD dwFlags
    );

typedef HRESOURCE
(WINAPI * PCLUSAPI_CREATE_CLUSTER_RESOURCE)(
    HGROUP hGroup,
    LPCWSTR lpszResourceName,
    LPCWSTR lpszResourceType,
    DWORD dwFlags
    );

HRESOURCE
WINAPI
OpenClusterResource(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceName
    );

typedef HRESOURCE
(WINAPI * PCLUSAPI_OPEN_CLUSTER_RESOURCE)(
    HCLUSTER hCluster,
    LPCWSTR lpszResourceName
    );

BOOL
WINAPI
CloseClusterResource(
    __in HRESOURCE hResource
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_RESOURCE)(
    HRESOURCE hResource
    );

HCLUSTER
WINAPI
GetClusterFromResource(
    __in HRESOURCE hResource
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_GET_CLUSTER_FROM_RESOURCE)(
    __in HRESOURCE hResource
    );

DWORD
WINAPI
DeleteClusterResource(
    __in HRESOURCE hResource
    );

typedef DWORD
(WINAPI * PCLUSAPI_DELETE_CLUSTER_RESOURCE)(
    HRESOURCE hResource
    );

__success(return >= 0) // != ClusterResourceStateUnknown
CLUSTER_RESOURCE_STATE
WINAPI
GetClusterResourceState(
    __in HRESOURCE hResource,
    __out_ecount_part_opt(*lpcchNodeName, *lpcchNodeName + 1) LPWSTR lpszNodeName,
    __inout_opt LPDWORD lpcchNodeName,
    __out_ecount_part_opt(*lpcchGroupName, *lpcchGroupName + 1) LPWSTR lpszGroupName,
    __inout_opt LPDWORD lpcchGroupName
    );

typedef CLUSTER_RESOURCE_STATE
(WINAPI * PCLUSAPI_GET_CLUSTER_RESOURCE_STATE)(
    __in HRESOURCE hResource,
    __out_ecount_part_opt(*lpcchNodeName, *lpcchNodeName + 1) LPWSTR lpszNodeName,
    __inout_opt LPDWORD lpcchNodeName,
    __out_ecount_part_opt(*lpcchGroupName, *lpcchGroupName + 1) LPWSTR lpszGroupName,
    __inout_opt LPDWORD lpcchGroupName
    );

DWORD
WINAPI
SetClusterResourceName(
    __in HRESOURCE hResource,
    __in LPCWSTR lpszResourceName
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_RESOURCE_NAME)(
    HRESOURCE hResource,
    LPCWSTR lpszResourceName
    );

DWORD
WINAPI
FailClusterResource(
    __in HRESOURCE hResource
    );

typedef DWORD
(WINAPI * PCLUSAPI_FAIL_CLUSTER_RESOURCE)(
    HRESOURCE hResource
    );

DWORD
WINAPI
OnlineClusterResource(
    __in HRESOURCE hResource
    );

typedef DWORD
(WINAPI * PCLUSAPI_ONLINE_CLUSTER_RESOURCE)(
    HRESOURCE hResource
    );

DWORD
WINAPI
OfflineClusterResource(
    __in HRESOURCE hResource
    );

typedef DWORD
(WINAPI * PCLUSAPI_OFFLINE_CLUSTER_RESOURCE)(
    HRESOURCE hResource
    );

DWORD
WINAPI
ChangeClusterResourceGroup(
    __in HRESOURCE hResource,
    __in HGROUP hGroup
    );

typedef DWORD
(WINAPI * PCLUSAPI_CHANGE_CLUSTER_RESOURCE_GROUP)(
    HRESOURCE hResource,
    HGROUP hGroup
    );

DWORD
WINAPI
AddClusterResourceNode(
    __in HRESOURCE hResource,
    __in HNODE hNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_ADD_CLUSTER_RESOURCE_NODE)(
    HRESOURCE hResource,
    HNODE hNode
    );

DWORD
WINAPI
RemoveClusterResourceNode(
    __in HRESOURCE hResource,
    __in HNODE hNode
    );

typedef DWORD
(WINAPI * PCLUSAPI_REMOVE_CLUSTER_RESOURCE_NODE)(
    HRESOURCE hResource,
    HNODE hNode
    );

DWORD
WINAPI
AddClusterResourceDependency(
    __in HRESOURCE hResource,
    __in HRESOURCE hDependsOn
    );

typedef DWORD
(WINAPI * PCLUSAPI_ADD_CLUSTER_RESOURCE_DEPENDENCY)(
    HRESOURCE hResource,
    HRESOURCE hDependsOn
    );

DWORD
WINAPI
RemoveClusterResourceDependency(
    __in HRESOURCE hResource,
    __in HRESOURCE hDependsOn
    );

typedef DWORD
(WINAPI * PCLUSAPI_REMOVE_CLUSTER_RESOURCE_DEPENDENCY)(
    HRESOURCE hResource,
    HRESOURCE hDependsOn
    );

DWORD
WINAPI
SetClusterResourceDependencyExpression(
    __in HRESOURCE hResource,
    __in LPCWSTR lpszDependencyExpression
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_RESOURCE_DEPENDENCY_EXPRESSION)(
    __in HRESOURCE hResource,
    __in LPCWSTR lpszDependencyExpression
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterResourceDependencyExpression(
    __in HRESOURCE hResource,
    __out_ecount_part_opt(*lpcchDependencyExpression, *lpcchDependencyExpression + 1)
        LPWSTR lpszDependencyExpression,
    __inout LPDWORD lpcchDependencyExpression
    );

typedef DWORD
(WINAPI  * PCLUSAPI_GET_CLUSTER_RESOURCE_DEPENDENCY_EXPRESSION)(
    __in HRESOURCE hResource,
    __out_ecount_part_opt(*lpcchDependencyExpression, *lpcchDependencyExpression + 1)
        LPWSTR lpszDependencyExpression,
    __inout LPDWORD lpcchDependencyExpression
    );

BOOL
WINAPI
CanResourceBeDependent(
    __in HRESOURCE hResource,
    __in HRESOURCE hResourceDependent
    );

typedef BOOL
(WINAPI * PCLUSAPI_CAN_RESOURCE_BE_DEPENDENT)(
    HRESOURCE hResource,
    HRESOURCE hResourceDependent
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterResourceControl(
    __in HRESOURCE hResource,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(cbInBufferSize) LPVOID lpInBuffer,
    __in DWORD cbInBufferSize,
    __out_bcount_part_opt(cbOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD cbOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_CONTROL)(
    __in HRESOURCE hResource,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(cbInBufferSize) LPVOID lpInBuffer,
    __in DWORD cbInBufferSize,
    __out_bcount_part_opt(cbOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD cbOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterResourceTypeControl(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_TYPE_CONTROL)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterGroupControl(
    __in HGROUP hGroup,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_GROUP_CONTROL)(
    __in HGROUP hGroup,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterNodeControl(
    __in HNODE hNode,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NODE_CONTROL)(
    __in HNODE hNode,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

BOOL
WINAPI
GetClusterResourceNetworkName(
    __in HRESOURCE hResource,
    __out_ecount_part(*nSize, *nSize + 1) LPWSTR lpBuffer,
    __inout LPDWORD nSize
    );

typedef BOOL
(WINAPI * PCLUSAPI_GET_CLUSTER_RESOURCE_NETWORK_NAME)(
    __in HRESOURCE hResource,
    __out_ecount_part(*nSize, *nSize + 1) LPWSTR lpBuffer,
    __inout LPDWORD nSize
    );

#endif // MIDL_PASS


//
// Cluster control properties
//

#ifndef _CLUSTER_API_TYPES_
//
// Cluster Control Property Data - Types (a WORD)
//
typedef enum CLUSTER_PROPERTY_TYPE {
    CLUSPROP_TYPE_UNKNOWN = -1,
    CLUSPROP_TYPE_ENDMARK = 0,
    CLUSPROP_TYPE_LIST_VALUE,
    CLUSPROP_TYPE_RESCLASS,
    CLUSPROP_TYPE_RESERVED1,
    CLUSPROP_TYPE_NAME,
    CLUSPROP_TYPE_SIGNATURE,
    CLUSPROP_TYPE_SCSI_ADDRESS,
    CLUSPROP_TYPE_DISK_NUMBER,
    CLUSPROP_TYPE_PARTITION_INFO,
    CLUSPROP_TYPE_FTSET_INFO,
    CLUSPROP_TYPE_DISK_SERIALNUMBER,
    CLUSPROP_TYPE_DISK_GUID,
    CLUSPROP_TYPE_DISK_SIZE,
    CLUSPROP_TYPE_PARTITION_INFO_EX,
    CLUSPROP_TYPE_USER=32768
} CLUSTER_PROPERTY_TYPE;

//
// Cluster Control Property Data - Formats (a WORD)
//
typedef enum CLUSTER_PROPERTY_FORMAT {
    CLUSPROP_FORMAT_UNKNOWN = 0,
    CLUSPROP_FORMAT_BINARY,
    CLUSPROP_FORMAT_DWORD,
    CLUSPROP_FORMAT_SZ,
    CLUSPROP_FORMAT_EXPAND_SZ,
    CLUSPROP_FORMAT_MULTI_SZ,
    CLUSPROP_FORMAT_ULARGE_INTEGER,
    CLUSPROP_FORMAT_LONG,
    CLUSPROP_FORMAT_EXPANDED_SZ,
    CLUSPROP_FORMAT_SECURITY_DESCRIPTOR,
    CLUSPROP_FORMAT_LARGE_INTEGER,
    CLUSPROP_FORMAT_WORD,
    CLUSPROP_FORMAT_FILETIME,
    CLUSPROP_FORMAT_USER=32768
} CLUSTER_PROPERTY_FORMAT;

#endif // _CLUSTER_API_TYPES_

//
// Cluster Control Property Data - Syntax
//
#define CLUSPROP_SYNTAX_VALUE( type, format ) ((DWORD) ((type << 16) | format))

#ifndef _CLUSTER_API_TYPES_

typedef enum CLUSTER_PROPERTY_SYNTAX {

    CLUSPROP_SYNTAX_ENDMARK         = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_ENDMARK, CLUSPROP_FORMAT_UNKNOWN ),
    CLUSPROP_SYNTAX_NAME            = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_NAME, CLUSPROP_FORMAT_SZ ),
    CLUSPROP_SYNTAX_RESCLASS        = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_RESCLASS, CLUSPROP_FORMAT_DWORD ),

    CLUSPROP_SYNTAX_LIST_VALUE_SZ                   = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_SZ ),
    CLUSPROP_SYNTAX_LIST_VALUE_EXPAND_SZ            = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_EXPAND_SZ ),
    CLUSPROP_SYNTAX_LIST_VALUE_DWORD                = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_DWORD ),
    CLUSPROP_SYNTAX_LIST_VALUE_BINARY               = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_BINARY ),
    CLUSPROP_SYNTAX_LIST_VALUE_MULTI_SZ             = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_MULTI_SZ ),
    CLUSPROP_SYNTAX_LIST_VALUE_LONG                 = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_LONG ),
    CLUSPROP_SYNTAX_LIST_VALUE_EXPANDED_SZ          = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_EXPANDED_SZ ),
    CLUSPROP_SYNTAX_LIST_VALUE_SECURITY_DESCRIPTOR  = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_SECURITY_DESCRIPTOR ),
    CLUSPROP_SYNTAX_LIST_VALUE_LARGE_INTEGER        = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_LARGE_INTEGER ),
    CLUSPROP_SYNTAX_LIST_VALUE_ULARGE_INTEGER       = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_ULARGE_INTEGER ),
    CLUSPROP_SYNTAX_LIST_VALUE_WORD                 = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_WORD ),

    // Storage syntax values

    CLUSPROP_SYNTAX_DISK_SIGNATURE      = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_SIGNATURE, CLUSPROP_FORMAT_DWORD ),
    CLUSPROP_SYNTAX_SCSI_ADDRESS        = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_SCSI_ADDRESS, CLUSPROP_FORMAT_DWORD ),
    CLUSPROP_SYNTAX_DISK_NUMBER         = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_DISK_NUMBER, CLUSPROP_FORMAT_DWORD ),
    CLUSPROP_SYNTAX_PARTITION_INFO      = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_PARTITION_INFO, CLUSPROP_FORMAT_BINARY ),
    CLUSPROP_SYNTAX_FTSET_INFO          = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_FTSET_INFO, CLUSPROP_FORMAT_BINARY ),
    CLUSPROP_SYNTAX_DISK_SERIALNUMBER   = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_DISK_SERIALNUMBER, CLUSPROP_FORMAT_SZ ),
    CLUSPROP_SYNTAX_DISK_GUID           = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_DISK_GUID, CLUSPROP_FORMAT_SZ ),
    CLUSPROP_SYNTAX_DISK_SIZE           = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_DISK_SIZE, CLUSPROP_FORMAT_ULARGE_INTEGER ),
    CLUSPROP_SYNTAX_PARTITION_INFO_EX   = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_PARTITION_INFO_EX, CLUSPROP_FORMAT_BINARY ),
    CLUSPROP_SYNTAX_LIST_VALUE_FILETIME = CLUSPROP_SYNTAX_VALUE( CLUSPROP_TYPE_LIST_VALUE, CLUSPROP_FORMAT_FILETIME ),

} CLUSTER_PROPERTY_SYNTAX;

#endif // _CLUSTER_API_TYPES_

//
// Define Cluster Control Code access methods
//
#define CLUS_ACCESS_ANY        0
#define CLUS_ACCESS_READ    0x01
#define CLUS_ACCESS_WRITE   0x02

//
// Define Cluster Control Code modification actions
//
#define CLUS_NO_MODIFY      0
#define CLUS_MODIFY         0x01

//
// Define Cluster Control Code Global actions
//
#define CLUS_NOT_GLOBAL     0
#define CLUS_GLOBAL         0x01

#ifndef _CLUSTER_API_TYPES_
//
// Define Cluster Control Code target objects
//
typedef enum CLUSTER_CONTROL_OBJECT {
    CLUS_OBJECT_INVALID=0,
    CLUS_OBJECT_RESOURCE,
    CLUS_OBJECT_RESOURCE_TYPE,
    CLUS_OBJECT_GROUP,
    CLUS_OBJECT_NODE,
    CLUS_OBJECT_NETWORK,
    CLUS_OBJECT_NETINTERFACE,
    CLUS_OBJECT_CLUSTER,
    CLUS_OBJECT_USER=128
} CLUSTER_CONTROL_OBJECT;

#endif // _CLUSTER_API_TYPES_

//
// Macro to generate full cluster control codes
//
//  31      24 23 22 21 20 19       16 15                    2 1    0
// +----------+--+--+--+--+-----------+-----------------------+------+
// |  OBJECT  |G |M |U |I       CLUSTER CONTROL CODES         |ACCESS|
// +----------+--+--+--+--+-----------+-----------------------+------+
//
// OBJECT - Object identifier (8 bits)
// G - Global bit (operation must be performed on all nodes of cluster)
// M - Modify bit (code causes a modification, may cause event notification)
// U - User code bit (splits the control codes into 2 spaces each 2^^19 in size)
// I - Internal code bit (only for non-user control codes)
// CLUSTER CONTROL CODES - 2^^18 (256 thousand possible control codes)
// ACCESS - Access mode (2 bits)
//

//
// Define control code shifts
//
#define CLUSCTL_ACCESS_SHIFT         0
#define CLUSCTL_FUNCTION_SHIFT       2
#define CLCTL_INTERNAL_SHIFT        20
#define CLCTL_USER_SHIFT            21
#define CLCTL_MODIFY_SHIFT          22
#define CLCTL_GLOBAL_SHIFT          23
#define CLUSCTL_OBJECT_SHIFT        24

//
// Define control code masks
//
#define CLCTL_INTERNAL_MASK             (1<<CLCTL_INTERNAL_SHIFT)
#define CLCTL_USER_MASK                 (1<<CLCTL_USER_SHIFT)
#define CLCTL_MODIFY_MASK               (1<<CLCTL_MODIFY_SHIFT)
#define CLCTL_GLOBAL_MASK               (1<<CLCTL_GLOBAL_SHIFT)
#define CLUSCTL_CONTROL_CODE_MASK       0x3FFFFF // Includes access mask
#define CLUSCTL_OBJECT_MASK             0xFF
#define CLUSCTL_ACCESS_MODE_MASK        0x03

//
// Cluster Control function codes (a DWORD)
//
#define CLCTL_CLUSTER_BASE  0           // Start of cluster defined functions
#define CLCTL_USER_BASE     (1<<CLCTL_USER_SHIFT) // Start of user functions

#define CLCTL_EXTERNAL_CODE( Function, Access, Modify ) ( \
    ((Access) << CLUSCTL_ACCESS_SHIFT) | \
    ((CLCTL_CLUSTER_BASE + Function) << CLUSCTL_FUNCTION_SHIFT) | \
    ((Modify) << CLCTL_MODIFY_SHIFT) )

#define CLCTL_INTERNAL_CODE( Function, Access, Modify ) ( \
    ((Access) << CLUSCTL_ACCESS_SHIFT) | \
    CLCTL_INTERNAL_MASK | \
    ((CLCTL_CLUSTER_BASE + Function) << CLUSCTL_FUNCTION_SHIFT) | \
    ((Modify) << CLCTL_MODIFY_SHIFT) )

#ifndef _CLUSTER_API_TYPES_
typedef enum CLCTL_CODES {
    //
    // External control codes
    //
    CLCTL_UNKNOWN                           = CLCTL_EXTERNAL_CODE( 0, CLUS_ACCESS_ANY, CLUS_NO_MODIFY ),
    CLCTL_GET_CHARACTERISTICS               = CLCTL_EXTERNAL_CODE( 1, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_FLAGS                         = CLCTL_EXTERNAL_CODE( 2, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_CLASS_INFO                    = CLCTL_EXTERNAL_CODE( 3, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_REQUIRED_DEPENDENCIES         = CLCTL_EXTERNAL_CODE( 4, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_ARB_TIMEOUT                   = CLCTL_EXTERNAL_CODE( 5, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_GET_NAME                          = CLCTL_EXTERNAL_CODE( 10, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_RESOURCE_TYPE                 = CLCTL_EXTERNAL_CODE( 11, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_NODE                          = CLCTL_EXTERNAL_CODE( 12, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_NETWORK                       = CLCTL_EXTERNAL_CODE( 13, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_ID                            = CLCTL_EXTERNAL_CODE( 14, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_FQDN                          = CLCTL_EXTERNAL_CODE( 15, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_CLUSTER_SERVICE_ACCOUNT_NAME  = CLCTL_EXTERNAL_CODE( 16, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_CHECK_VOTER_EVICT                 = CLCTL_EXTERNAL_CODE( 17, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_CHECK_VOTER_DOWN                  = CLCTL_EXTERNAL_CODE( 18, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_SHUTDOWN                          = CLCTL_EXTERNAL_CODE( 19, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_ENUM_COMMON_PROPERTIES            = CLCTL_EXTERNAL_CODE( 20, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_RO_COMMON_PROPERTIES          = CLCTL_EXTERNAL_CODE( 21, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_COMMON_PROPERTIES             = CLCTL_EXTERNAL_CODE( 22, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_SET_COMMON_PROPERTIES             = CLCTL_EXTERNAL_CODE( 23, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_VALIDATE_COMMON_PROPERTIES        = CLCTL_EXTERNAL_CODE( 24, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_COMMON_PROPERTY_FMTS          = CLCTL_EXTERNAL_CODE( 25, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_COMMON_RESOURCE_PROPERTY_FMTS = CLCTL_EXTERNAL_CODE( 26, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_ENUM_PRIVATE_PROPERTIES           = CLCTL_EXTERNAL_CODE( 30, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_RO_PRIVATE_PROPERTIES         = CLCTL_EXTERNAL_CODE( 31, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_PRIVATE_PROPERTIES            = CLCTL_EXTERNAL_CODE( 32, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_SET_PRIVATE_PROPERTIES            = CLCTL_EXTERNAL_CODE( 33, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_VALIDATE_PRIVATE_PROPERTIES       = CLCTL_EXTERNAL_CODE( 34, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_PRIVATE_PROPERTY_FMTS         = CLCTL_EXTERNAL_CODE( 35, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_GET_PRIVATE_RESOURCE_PROPERTY_FMTS= CLCTL_EXTERNAL_CODE( 36, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_ADD_REGISTRY_CHECKPOINT           = CLCTL_EXTERNAL_CODE( 40, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_DELETE_REGISTRY_CHECKPOINT        = CLCTL_EXTERNAL_CODE( 41, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_GET_REGISTRY_CHECKPOINTS          = CLCTL_EXTERNAL_CODE( 42, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_ADD_CRYPTO_CHECKPOINT             = CLCTL_EXTERNAL_CODE( 43, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_DELETE_CRYPTO_CHECKPOINT          = CLCTL_EXTERNAL_CODE( 44, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_GET_CRYPTO_CHECKPOINTS            = CLCTL_EXTERNAL_CODE( 45, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_RESOURCE_UPGRADE_DLL              = CLCTL_EXTERNAL_CODE( 46, CLUS_ACCESS_WRITE, CLUS_MODIFY ),

    CLCTL_ADD_REGISTRY_CHECKPOINT_64BIT     = CLCTL_EXTERNAL_CODE( 47, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_ADD_REGISTRY_CHECKPOINT_32BIT     = CLCTL_EXTERNAL_CODE( 48, CLUS_ACCESS_WRITE, CLUS_MODIFY ),

    CLCTL_GET_LOADBAL_PROCESS_LIST          = CLCTL_EXTERNAL_CODE( 50, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_GET_NETWORK_NAME                  = CLCTL_EXTERNAL_CODE( 90, CLUS_ACCESS_READ,  CLUS_NO_MODIFY ),
    CLCTL_NETNAME_GET_VIRTUAL_SERVER_TOKEN  = CLCTL_EXTERNAL_CODE( 91, CLUS_ACCESS_READ,  CLUS_NO_MODIFY ),
    CLCTL_NETNAME_REGISTER_DNS_RECORDS      = CLCTL_EXTERNAL_CODE( 92, CLUS_ACCESS_WRITE, CLUS_NO_MODIFY ),
    CLCTL_GET_DNS_NAME                      = CLCTL_EXTERNAL_CODE( 93, CLUS_ACCESS_READ,  CLUS_NO_MODIFY ),
    CLCTL_NETNAME_SET_PWD_INFO              = CLCTL_EXTERNAL_CODE( 94, CLUS_ACCESS_WRITE, CLUS_NO_MODIFY ),
    CLCTL_NETNAME_DELETE_CO                 = CLCTL_EXTERNAL_CODE( 95, CLUS_ACCESS_WRITE, CLUS_NO_MODIFY ),
    CLCTL_NETNAME_VALIDATE_VCO              = CLCTL_EXTERNAL_CODE( 96, CLUS_ACCESS_READ,  CLUS_NO_MODIFY ),
    
    CLCTL_STORAGE_GET_DISK_INFO             = CLCTL_EXTERNAL_CODE( 100, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_GET_AVAILABLE_DISKS       = CLCTL_EXTERNAL_CODE( 101, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_IS_PATH_VALID             = CLCTL_EXTERNAL_CODE( 102, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_GET_ALL_AVAILABLE_DISKS   = CLCTL_EXTERNAL_CODE( 103, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_SYNC_CLUSDISK_DB          = (CLCTL_EXTERNAL_CODE( 103, CLUS_ACCESS_WRITE, CLUS_MODIFY ) | CLCTL_GLOBAL_MASK),

    CLCTL_QUERY_DELETE                      = CLCTL_EXTERNAL_CODE( 110, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    CLCTL_IPADDRESS_RENEW_LEASE             = CLCTL_EXTERNAL_CODE( 111, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_IPADDRESS_RELEASE_LEASE           = CLCTL_EXTERNAL_CODE( 112, CLUS_ACCESS_WRITE, CLUS_MODIFY ),

    CLCTL_QUERY_MAINTENANCE_MODE            = CLCTL_EXTERNAL_CODE( 120, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_SET_MAINTENANCE_MODE              = CLCTL_EXTERNAL_CODE( 121, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_STORAGE_SET_DRIVELETTER           = CLCTL_EXTERNAL_CODE( 122, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_STORAGE_GET_DRIVELETTERS          = CLCTL_EXTERNAL_CODE( 123, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_GET_DISK_INFO_EX          = CLCTL_EXTERNAL_CODE( 124, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_GET_AVAILABLE_DISKS_EX    = CLCTL_EXTERNAL_CODE( 125, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),
    CLCTL_STORAGE_REMAP_DRIVELETTER         = CLCTL_EXTERNAL_CODE( 128, CLUS_ACCESS_READ, CLUS_NO_MODIFY ),

    //
    // Internal control codes
    //
    CLCTL_DELETE                            = CLCTL_INTERNAL_CODE( 1, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_INSTALL_NODE                      = CLCTL_INTERNAL_CODE( 2, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_EVICT_NODE                        = CLCTL_INTERNAL_CODE( 3, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_ADD_DEPENDENCY                    = CLCTL_INTERNAL_CODE( 4, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_REMOVE_DEPENDENCY                 = CLCTL_INTERNAL_CODE( 5, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_ADD_OWNER                         = CLCTL_INTERNAL_CODE( 6, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_REMOVE_OWNER                      = CLCTL_INTERNAL_CODE( 7, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    //************ Hole here at 8
    CLCTL_SET_NAME                          = CLCTL_INTERNAL_CODE( 9, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_CLUSTER_NAME_CHANGED              = CLCTL_INTERNAL_CODE( 10, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_CLUSTER_VERSION_CHANGED           = CLCTL_INTERNAL_CODE( 11, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_FIXUP_ON_UPGRADE                  = CLCTL_INTERNAL_CODE( 12, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_STARTING_PHASE1                   = CLCTL_INTERNAL_CODE( 13, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_STARTING_PHASE2                   = CLCTL_INTERNAL_CODE( 14, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_HOLD_IO                           = CLCTL_INTERNAL_CODE( 15, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_RESUME_IO                         = CLCTL_INTERNAL_CODE( 16, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_FORCE_QUORUM                      = CLCTL_INTERNAL_CODE( 17, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_INITIALIZE                        = CLCTL_INTERNAL_CODE( 18, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_STATE_CHANGE_REASON               = CLCTL_INTERNAL_CODE( 19, CLUS_ACCESS_WRITE, CLUS_MODIFY ),
    CLCTL_PROVIDER_STATE_CHANGE             = CLCTL_INTERNAL_CODE( 20, CLUS_ACCESS_WRITE, CLUS_MODIFY ),

} CLCTL_CODES;

#endif // _CLUSTER_API_TYPES_

//
// Define macros to generate object specific control codes
//
#define CLUSCTL_RESOURCE_CODE( Function ) ( \
    ((CLUS_OBJECT_RESOURCE << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_RESOURCE_TYPE_CODE( Function ) ( \
    ((CLUS_OBJECT_RESOURCE_TYPE << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_GROUP_CODE( Function ) ( \
    ((CLUS_OBJECT_GROUP << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_NODE_CODE( Function ) ( \
    ((CLUS_OBJECT_NODE << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_NETWORK_CODE( Function ) ( \
    ((CLUS_OBJECT_NETWORK << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_NETINTERFACE_CODE( Function ) ( \
    ((CLUS_OBJECT_NETINTERFACE << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_CLUSTER_CODE( Function ) ( \
    ((CLUS_OBJECT_CLUSTER << CLUSCTL_OBJECT_SHIFT) | Function) )

#define CLUSCTL_USER_CODE( Function, Object ) ( \
     ((Object) << CLUSCTL_OBJECT_SHIFT) | ((CLCTL_USER_BASE + Function) << CLUSCTL_FUNCTION_SHIFT) )

//
// Define macros to get the function or access mode out of a control code
//
#define CLUSCTL_GET_CONTROL_FUNCTION( ControlCode ) \
    ((ControlCode >> CLUSCTL_ACCESS_SHIFT) & CLUSCTL_CONTROL_CODE_MASK)

#define CLUSCTL_GET_ACCESS_MODE( ControlCode ) \
    ((ControlCode >> CLUSCTL_ACCESS_SHIFT) & CLUSCTL_ACCESS_MODE_MASK)

#define CLUSCTL_GET_CONTROL_OBJECT( ControlCode ) \
    ((ControlCode >> CLUSCTL_OBJECT_SHIFT) & CLUSCTL_OBJECT_MASK)

#ifndef _CLUSTER_API_TYPES_
//
// Cluster Control Codes for Resources
//
typedef enum CLUSCTL_RESOURCE_CODES {

    // External
    CLUSCTL_RESOURCE_UNKNOWN =
        CLUSCTL_RESOURCE_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_RESOURCE_GET_CHARACTERISTICS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_RESOURCE_GET_FLAGS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_RESOURCE_GET_CLASS_INFO =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_CLASS_INFO ),

    CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_REQUIRED_DEPENDENCIES ),

    CLUSCTL_RESOURCE_GET_NAME =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_NAME ),

    CLUSCTL_RESOURCE_GET_ID =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_ID ),

    CLUSCTL_RESOURCE_GET_RESOURCE_TYPE =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_RESOURCE_TYPE ),

    CLUSCTL_RESOURCE_ENUM_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_COMMON_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_REGISTRY_CHECKPOINT ),

    CLUSCTL_RESOURCE_DELETE_REGISTRY_CHECKPOINT =
        CLUSCTL_RESOURCE_CODE( CLCTL_DELETE_REGISTRY_CHECKPOINT ),

    CLUSCTL_RESOURCE_GET_REGISTRY_CHECKPOINTS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_REGISTRY_CHECKPOINTS ),

    CLUSCTL_RESOURCE_ADD_CRYPTO_CHECKPOINT =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_CRYPTO_CHECKPOINT ),

    CLUSCTL_RESOURCE_DELETE_CRYPTO_CHECKPOINT =
        CLUSCTL_RESOURCE_CODE( CLCTL_DELETE_CRYPTO_CHECKPOINT ),

    CLUSCTL_RESOURCE_GET_CRYPTO_CHECKPOINTS =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_CRYPTO_CHECKPOINTS ),

    CLUSCTL_RESOURCE_GET_LOADBAL_PROCESS_LIST =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_LOADBAL_PROCESS_LIST ),

    CLUSCTL_RESOURCE_GET_NETWORK_NAME =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_NETWORK_NAME ),

    CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN =
        CLUSCTL_RESOURCE_CODE( CLCTL_NETNAME_GET_VIRTUAL_SERVER_TOKEN ),
        
    CLUSCTL_RESOURCE_NETNAME_SET_PWD_INFO =
        CLUSCTL_RESOURCE_CODE( CLCTL_NETNAME_SET_PWD_INFO ),
        
    CLUSCTL_RESOURCE_NETNAME_DELETE_CO =
        CLUSCTL_RESOURCE_CODE( CLCTL_NETNAME_DELETE_CO ),

    CLUSCTL_RESOURCE_NETNAME_VALIDATE_VCO =
        CLUSCTL_RESOURCE_CODE( CLCTL_NETNAME_VALIDATE_VCO ),

    CLUSCTL_RESOURCE_NETNAME_REGISTER_DNS_RECORDS =
        CLUSCTL_RESOURCE_CODE( CLCTL_NETNAME_REGISTER_DNS_RECORDS ),

    CLUSCTL_RESOURCE_GET_DNS_NAME =
        CLUSCTL_RESOURCE_CODE( CLCTL_GET_DNS_NAME ),

    CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO =
        CLUSCTL_RESOURCE_CODE( CLCTL_STORAGE_GET_DISK_INFO ),

    CLUSCTL_RESOURCE_STORAGE_IS_PATH_VALID =
        CLUSCTL_RESOURCE_CODE( CLCTL_STORAGE_IS_PATH_VALID ),

    CLUSCTL_RESOURCE_QUERY_DELETE =
        CLUSCTL_RESOURCE_CODE( CLCTL_QUERY_DELETE ),

    CLUSCTL_RESOURCE_UPGRADE_DLL =
        CLUSCTL_RESOURCE_CODE( CLCTL_RESOURCE_UPGRADE_DLL ),

    CLUSCTL_RESOURCE_IPADDRESS_RENEW_LEASE =
        CLUSCTL_RESOURCE_CODE( CLCTL_IPADDRESS_RENEW_LEASE ),

    CLUSCTL_RESOURCE_IPADDRESS_RELEASE_LEASE =
        CLUSCTL_RESOURCE_CODE( CLCTL_IPADDRESS_RELEASE_LEASE ),

    CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_64BIT =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_REGISTRY_CHECKPOINT_64BIT ),

    CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_32BIT =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_REGISTRY_CHECKPOINT_32BIT ),

    CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE =
        CLUSCTL_RESOURCE_CODE( CLCTL_QUERY_MAINTENANCE_MODE ),

    CLUSCTL_RESOURCE_SET_MAINTENANCE_MODE =
        CLUSCTL_RESOURCE_CODE( CLCTL_SET_MAINTENANCE_MODE ),

    CLUSCTL_RESOURCE_STORAGE_SET_DRIVELETTER =
        CLUSCTL_RESOURCE_CODE( CLCTL_STORAGE_SET_DRIVELETTER ),

    CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX =
        CLUSCTL_RESOURCE_CODE( CLCTL_STORAGE_GET_DISK_INFO_EX ),

    // Internal
    CLUSCTL_RESOURCE_DELETE =
        CLUSCTL_RESOURCE_CODE( CLCTL_DELETE ),

    CLUSCTL_RESOURCE_INSTALL_NODE =
        CLUSCTL_RESOURCE_CODE( CLCTL_INSTALL_NODE ),

    CLUSCTL_RESOURCE_EVICT_NODE =
        CLUSCTL_RESOURCE_CODE( CLCTL_EVICT_NODE ),

    CLUSCTL_RESOURCE_ADD_DEPENDENCY =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_DEPENDENCY ),

    CLUSCTL_RESOURCE_REMOVE_DEPENDENCY =
        CLUSCTL_RESOURCE_CODE( CLCTL_REMOVE_DEPENDENCY ),

    CLUSCTL_RESOURCE_ADD_OWNER =
        CLUSCTL_RESOURCE_CODE( CLCTL_ADD_OWNER ),

    CLUSCTL_RESOURCE_REMOVE_OWNER =
        CLUSCTL_RESOURCE_CODE( CLCTL_REMOVE_OWNER ),

    CLUSCTL_RESOURCE_SET_NAME =
        CLUSCTL_RESOURCE_CODE( CLCTL_SET_NAME ),

    CLUSCTL_RESOURCE_CLUSTER_NAME_CHANGED =
        CLUSCTL_RESOURCE_CODE( CLCTL_CLUSTER_NAME_CHANGED ),

    CLUSCTL_RESOURCE_CLUSTER_VERSION_CHANGED =
        CLUSCTL_RESOURCE_CODE( CLCTL_CLUSTER_VERSION_CHANGED ),

    CLUSCTL_RESOURCE_FORCE_QUORUM =
        CLUSCTL_RESOURCE_CODE( CLCTL_FORCE_QUORUM ),

    CLUSCTL_RESOURCE_INITIALIZE =
        CLUSCTL_RESOURCE_CODE( CLCTL_INITIALIZE ),

    CLUSCTL_RESOURCE_STATE_CHANGE_REASON =
        CLUSCTL_RESOURCE_CODE( CLCTL_STATE_CHANGE_REASON ),

    CLUSCTL_RESOURCE_PROVIDER_STATE_CHANGE =
        CLUSCTL_RESOURCE_CODE( CLCTL_PROVIDER_STATE_CHANGE ),
        
} CLUSCTL_RESOURCE_CODES;

//
// Cluster Control Codes for Resource Types
//
typedef enum CLUSCTL_RESOURCE_TYPE_CODES {

    // External
    CLUSCTL_RESOURCE_TYPE_UNKNOWN =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_RESOURCE_TYPE_GET_CHARACTERISTICS  =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_RESOURCE_TYPE_GET_FLAGS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_CLASS_INFO ),

    CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_REQUIRED_DEPENDENCIES ),

    CLUSCTL_RESOURCE_TYPE_GET_ARB_TIMEOUT =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_ARB_TIMEOUT ),

    CLUSCTL_RESOURCE_TYPE_ENUM_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_SET_COMMON_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_TYPE_GET_COMMON_RESOURCE_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_COMMON_RESOURCE_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_TYPE_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_SET_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_RESOURCE_PROPERTY_FMTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_PRIVATE_RESOURCE_PROPERTY_FMTS ),

    CLUSCTL_RESOURCE_TYPE_GET_REGISTRY_CHECKPOINTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_REGISTRY_CHECKPOINTS ),

    CLUSCTL_RESOURCE_TYPE_GET_CRYPTO_CHECKPOINTS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_GET_CRYPTO_CHECKPOINTS ),

    CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STORAGE_GET_AVAILABLE_DISKS ),

    CLUSCTL_RESOURCE_TYPE_STORAGE_SYNC_CLUSDISK_DB =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STORAGE_SYNC_CLUSDISK_DB ),

    CLUSCTL_RESOURCE_TYPE_QUERY_DELETE =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_QUERY_DELETE ),

    CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DRIVELETTERS =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STORAGE_GET_DRIVELETTERS ),

    CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STORAGE_GET_AVAILABLE_DISKS_EX ),

    CLUSCTL_RESOURCE_TYPE_STORAGE_REMAP_DRIVELETTER =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STORAGE_REMAP_DRIVELETTER ),

    // Internal
    CLUSCTL_RESOURCE_TYPE_INSTALL_NODE =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_INSTALL_NODE ),

    CLUSCTL_RESOURCE_TYPE_EVICT_NODE =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_EVICT_NODE ),

    CLUSCTL_RESOURCE_TYPE_CLUSTER_VERSION_CHANGED =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_CLUSTER_VERSION_CHANGED ),

    CLUSCTL_RESOURCE_TYPE_FIXUP_ON_UPGRADE =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_FIXUP_ON_UPGRADE ),

    CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1 =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STARTING_PHASE1 ),

    CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2 =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_STARTING_PHASE2 ),

    CLUSCTL_RESOURCE_TYPE_HOLD_IO =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_HOLD_IO ),

    CLUSCTL_RESOURCE_TYPE_RESUME_IO =
        CLUSCTL_RESOURCE_TYPE_CODE( CLCTL_RESUME_IO )


} CLUSCTL_RESOURCE_TYPE_CODES;

//
// Cluster Control Codes for Groups
//
typedef enum CLUSCTL_GROUP_CODES {

    // External
    CLUSCTL_GROUP_UNKNOWN =
        CLUSCTL_GROUP_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_GROUP_GET_CHARACTERISTICS =
        CLUSCTL_GROUP_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_GROUP_GET_FLAGS =
        CLUSCTL_GROUP_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_GROUP_GET_NAME =
        CLUSCTL_GROUP_CODE( CLCTL_GET_NAME ),

    CLUSCTL_GROUP_GET_ID =
        CLUSCTL_GROUP_CODE( CLCTL_GET_ID ),

    CLUSCTL_GROUP_ENUM_COMMON_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_GROUP_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_GROUP_GET_COMMON_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_GROUP_SET_COMMON_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_GROUP_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_GROUP_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_GROUP_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_GROUP_GET_PRIVATE_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_GROUP_SET_PRIVATE_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_GROUP_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_GROUP_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_GROUP_QUERY_DELETE =
        CLUSCTL_GROUP_CODE( CLCTL_QUERY_DELETE ),

    CLUSCTL_GROUP_GET_COMMON_PROPERTY_FMTS=
        CLUSCTL_GROUP_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_GROUP_GET_PRIVATE_PROPERTY_FMTS=
        CLUSCTL_GROUP_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS )

    // Internal

} CLUSCTL_GROUP_CODES;

//
// Cluster Control Codes for Nodes
//
typedef enum CLUSCTL_NODE_CODES {

    // External
    CLUSCTL_NODE_UNKNOWN =
        CLUSCTL_NODE_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_NODE_GET_CHARACTERISTICS =
        CLUSCTL_NODE_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_NODE_GET_FLAGS =
        CLUSCTL_NODE_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_NODE_GET_NAME =
        CLUSCTL_NODE_CODE( CLCTL_GET_NAME ),

    CLUSCTL_NODE_GET_ID =
        CLUSCTL_NODE_CODE( CLCTL_GET_ID ),

    CLUSCTL_NODE_ENUM_COMMON_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_NODE_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_NODE_GET_COMMON_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_NODE_SET_COMMON_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_NODE_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_NODE_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_NODE_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_NODE_GET_PRIVATE_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_NODE_SET_PRIVATE_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_NODE_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_NODE_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_NODE_GET_COMMON_PROPERTY_FMTS=
        CLUSCTL_NODE_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_NODE_GET_PRIVATE_PROPERTY_FMTS=
        CLUSCTL_NODE_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS ),

    CLUSCTL_NODE_GET_CLUSTER_SERVICE_ACCOUNT_NAME =
        CLUSCTL_NODE_CODE( CLCTL_GET_CLUSTER_SERVICE_ACCOUNT_NAME )


} CLUSCTL_NODE_CODES;

//
// Cluster Control Codes for Networks
//
typedef enum CLUSCTL_NETWORK_CODES {

    // External
    CLUSCTL_NETWORK_UNKNOWN =
        CLUSCTL_NETWORK_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_NETWORK_GET_CHARACTERISTICS =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_NETWORK_GET_FLAGS =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_NETWORK_GET_NAME =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_NAME ),

    CLUSCTL_NETWORK_GET_ID =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_ID ),

    CLUSCTL_NETWORK_ENUM_COMMON_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_NETWORK_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_NETWORK_GET_COMMON_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_NETWORK_SET_COMMON_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_NETWORK_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_NETWORK_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_NETWORK_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_NETWORK_GET_PRIVATE_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_NETWORK_SET_PRIVATE_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_NETWORK_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_NETWORK_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_NETWORK_GET_COMMON_PROPERTY_FMTS=
        CLUSCTL_NETWORK_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_NETWORK_GET_PRIVATE_PROPERTY_FMTS=
        CLUSCTL_NETWORK_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS )

} CLUSCTL_NETWORK_CODES;

//
// Cluster Control Codes for Network Interfaces
//
typedef enum CLUSCTL_NETINTERFACE_CODES {

    // External
    CLUSCTL_NETINTERFACE_UNKNOWN =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_NETINTERFACE_GET_CHARACTERISTICS =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_CHARACTERISTICS ),

    CLUSCTL_NETINTERFACE_GET_FLAGS =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_FLAGS ),

    CLUSCTL_NETINTERFACE_GET_NAME =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_NAME ),

    CLUSCTL_NETINTERFACE_GET_ID =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_ID ),

    CLUSCTL_NETINTERFACE_GET_NODE =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_NODE ),

    CLUSCTL_NETINTERFACE_GET_NETWORK =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_NETWORK ),

    CLUSCTL_NETINTERFACE_ENUM_COMMON_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_NETINTERFACE_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_NETINTERFACE_SET_COMMON_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_NETINTERFACE_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_NETINTERFACE_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_NETINTERFACE_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_NETINTERFACE_SET_PRIVATE_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_NETINTERFACE_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_NETINTERFACE_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_NETINTERFACE_GET_COMMON_PROPERTY_FMTS=
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_NETINTERFACE_GET_PRIVATE_PROPERTY_FMTS=
        CLUSCTL_NETINTERFACE_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS )

} CLUSCTL_NETINTERFACE_CODES;

//
// Cluster Control Codes for Nodes
//
typedef enum CLUSCTL_CLUSTER_CODES {

    // External
    CLUSCTL_CLUSTER_UNKNOWN =
        CLUSCTL_CLUSTER_CODE( CLCTL_UNKNOWN ),

    CLUSCTL_CLUSTER_GET_FQDN =
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_FQDN ),

    CLUSCTL_CLUSTER_ENUM_COMMON_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_ENUM_COMMON_PROPERTIES ),

    CLUSCTL_CLUSTER_GET_RO_COMMON_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_RO_COMMON_PROPERTIES ),

    CLUSCTL_CLUSTER_GET_COMMON_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_COMMON_PROPERTIES ),

    CLUSCTL_CLUSTER_SET_COMMON_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_SET_COMMON_PROPERTIES ),

    CLUSCTL_CLUSTER_VALIDATE_COMMON_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_VALIDATE_COMMON_PROPERTIES ),

    CLUSCTL_CLUSTER_ENUM_PRIVATE_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_ENUM_PRIVATE_PROPERTIES ),

    CLUSCTL_CLUSTER_GET_RO_PRIVATE_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_RO_PRIVATE_PROPERTIES ),

    CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_PRIVATE_PROPERTIES ),

    CLUSCTL_CLUSTER_SET_PRIVATE_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_SET_PRIVATE_PROPERTIES ),

    CLUSCTL_CLUSTER_VALIDATE_PRIVATE_PROPERTIES =
        CLUSCTL_CLUSTER_CODE( CLCTL_VALIDATE_PRIVATE_PROPERTIES ),

    CLUSCTL_CLUSTER_GET_COMMON_PROPERTY_FMTS=
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_COMMON_PROPERTY_FMTS ),

    CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTY_FMTS=
        CLUSCTL_CLUSTER_CODE( CLCTL_GET_PRIVATE_PROPERTY_FMTS ),

    CLUSCTL_CLUSTER_CHECK_VOTER_EVICT=
        CLUSCTL_CLUSTER_CODE( CLCTL_CHECK_VOTER_EVICT ),

    CLUSCTL_CLUSTER_CHECK_VOTER_DOWN=
        CLUSCTL_CLUSTER_CODE( CLCTL_CHECK_VOTER_DOWN ),

    CLUSCTL_CLUSTER_SHUTDOWN=
        CLUSCTL_CLUSTER_CODE( CLCTL_SHUTDOWN ),

} CLUSCTL_CLUSTER_CODES;

//
// Cluster Resource Class types
//
typedef enum CLUSTER_RESOURCE_CLASS {
    CLUS_RESCLASS_UNKNOWN = 0,
    CLUS_RESCLASS_STORAGE,
    CLUS_RESCLASS_NETWORK,
    CLUS_RESCLASS_USER = 32768
} CLUSTER_RESOURCE_CLASS;

//
// Define Resource SubClass bits
//
// legacy subclass struct
//
typedef enum CLUS_RESSUBCLASS {
    CLUS_RESSUBCLASS_SHARED =                       0x80000000
} CLUS_RESSUBCLASS;

typedef enum CLUS_RESSUBCLASS_STORAGE {
    CLUS_RESSUBCLASS_STORAGE_SHARED_BUS =           0x80000000
} CLUS_RESSUBCLASS_STORAGE;

typedef enum CLUS_RESSUBCLASS_NETWORK {
    CLUS_RESSUBCLASS_NETWORK_INTERNET_PROTOCOL =    0x80000000    // Identifies IP address providers
} CLUS_RESSUBCLASS_NETWORK;

//
// Cluster Characteristics
//
typedef enum CLUS_CHARACTERISTICS {
    CLUS_CHAR_UNKNOWN                       = 0x00000000,
    CLUS_CHAR_QUORUM                        = 0x00000001,
    CLUS_CHAR_DELETE_REQUIRES_ALL_NODES     = 0x00000002,
    CLUS_CHAR_LOCAL_QUORUM                  = 0x00000004,
    CLUS_CHAR_LOCAL_QUORUM_DEBUG            = 0x00000008,
    CLUS_CHAR_REQUIRES_STATE_CHANGE_REASON  = 0x00000010
} CLUS_CHARACTERISTICS;

//
// Cluster Flags
//
typedef enum CLUS_FLAGS {
    CLUS_FLAG_CORE          = 0x00000001
}  CLUS_FLAGS;


//
// Cluster Resource Property Helper Structures
//

#if ( !MIDL_PASS && !__midl )

// Property syntax.  Used for property names and values.
typedef union CLUSPROP_SYNTAX {
    DWORD dw;
    struct {
        WORD wFormat;
        WORD wType;
    };
} CLUSPROP_SYNTAX, *PCLUSPROP_SYNTAX;

// Property value.
typedef struct CLUSPROP_VALUE {
    CLUSPROP_SYNTAX Syntax;
    DWORD           cbLength;
} CLUSPROP_VALUE, *PCLUSPROP_VALUE;

// Binary property value.
#ifdef __cplusplus
typedef struct CLUSPROP_BINARY : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_BINARY {
    CLUSPROP_VALUE;
#endif
    BYTE            rgb[];
} CLUSPROP_BINARY, *PCLUSPROP_BINARY;

// WORD property value.
#ifdef __cplusplus
typedef struct CLUSPROP_WORD : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_WORD {
    CLUSPROP_VALUE;
#endif
    WORD            w;
} CLUSPROP_WORD, *PCLUSPROP_WORD;

// DWORD property value.
#ifdef __cplusplus
typedef struct CLUSPROP_DWORD : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_DWORD {
    CLUSPROP_VALUE;
#endif
    DWORD           dw;
} CLUSPROP_DWORD, *PCLUSPROP_DWORD;

// LONG property value.
#ifdef __cplusplus
typedef struct CLUSPROP_LONG : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_LONG {
    CLUSPROP_VALUE;
#endif
    LONG           l;
} CLUSPROP_LONG, *PCLUSPROP_LONG;

// String property value.
#ifdef __cplusplus
typedef struct CLUSPROP_SZ : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_SZ {
    CLUSPROP_VALUE;
#endif
    WCHAR           sz[];
} CLUSPROP_SZ, *PCLUSPROP_SZ;

// Multiple string property value.
typedef CLUSPROP_SZ CLUSPROP_MULTI_SZ, *PCLUSPROP_MULTI_SZ;

// Property name.
typedef CLUSPROP_SZ CLUSPROP_PROPERTY_NAME, *PCLUSPROP_PROPERTY_NAME;

// Unsigned large Integer property value.
#ifdef __cplusplus
typedef struct CLUSPROP_ULARGE_INTEGER
    : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_ULARGE_INTEGER {
    CLUSPROP_VALUE;
#endif
    ULARGE_INTEGER li;
} CLUSPROP_ULARGE_INTEGER;

typedef CLUSPROP_ULARGE_INTEGER UNALIGNED *PCLUSPROP_ULARGE_INTEGER;

// Signed large Integer property value.
#ifdef __cplusplus
typedef struct CLUSPROP_LARGE_INTEGER
    : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_LARGE_INTEGER {
    CLUSPROP_VALUE;
#endif
    LARGE_INTEGER li;
} CLUSPROP_LARGE_INTEGER;

typedef CLUSPROP_LARGE_INTEGER UNALIGNED *PCLUSPROP_LARGE_INTEGER;

// Security Descriptor property value.
#ifdef __cplusplus
typedef struct CLUSPROP_SECURITY_DESCRIPTOR : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_SECURITY_DESCRIPTOR {
    CLUSPROP_VALUE;
#endif
    union {
        SECURITY_DESCRIPTOR_RELATIVE    sd;
        BYTE                            rgbSecurityDescriptor[];
    };
} CLUSPROP_SECURITY_DESCRIPTOR, *PCLUSPROP_SECURITY_DESCRIPTOR;

// FILETIME Time property value.
#ifdef __cplusplus
typedef struct CLUSPROP_FILETIME 
    : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_FILETIME {
    CLUSPROP_VALUE;
#endif
    FILETIME ft;
} CLUSPROP_FILETIME, *PCLUSPROP_FILETIME;

// Resource class info returned by CLCTL_GET_CLASS_INFO control functions.
typedef struct CLUS_RESOURCE_CLASS_INFO {
    union {
        struct {
            union {
                DWORD                   dw;
                CLUSTER_RESOURCE_CLASS  rc;
                };
            DWORD           SubClass;
        };
        ULARGE_INTEGER      li;
    };
} CLUS_RESOURCE_CLASS_INFO, *PCLUS_RESOURCE_CLASS_INFO;

// Resource class property value.
#ifdef __cplusplus
typedef struct CLUSPROP_RESOURCE_CLASS
    : public CLUSPROP_VALUE {
#else
typedef struct CLUSPROP_RESOURCE_CLASS {
    CLUSPROP_VALUE;
#endif
    CLUSTER_RESOURCE_CLASS rc;
} CLUSPROP_RESOURCE_CLASS, *PCLUSPROP_RESOURCE_CLASS;

// Resource class info property value.
#ifdef __cplusplus
typedef struct CLUSPROP_RESOURCE_CLASS_INFO
    : public CLUSPROP_VALUE
    , public CLUS_RESOURCE_CLASS_INFO {
#else
typedef struct CLUSPROP_RESOURCE_CLASS_INFO {
    CLUSPROP_VALUE;
    CLUS_RESOURCE_CLASS_INFO;
#endif
} CLUSPROP_RESOURCE_CLASS_INFO, *PCLUSPROP_RESOURCE_CLASS_INFO;

// One entry from list returned by CLCTL_GET_REQUIRED_DEPENDENCIES control functions.
typedef union CLUSPROP_REQUIRED_DEPENDENCY {
    CLUSPROP_VALUE          Value;
    CLUSPROP_RESOURCE_CLASS ResClass;
    CLUSPROP_SZ             ResTypeName;
} CLUSPROP_REQUIRED_DEPENDENCY, *PCLUSPROP_REQUIRED_DEPENDENCY;

typedef CLUSPROP_DWORD CLUSPROP_DISK_NUMBER, *PCLUSPROP_DISK_NUMBER;

#endif // MIDL_PASS
#endif // _CLUSTER_API_TYPES_

#ifndef _CLUSTER_API_TYPES_

// Disk partition information flags.
typedef enum CLUSPROP_PIFLAGS {
    CLUSPROP_PIFLAG_STICKY          = 0x00000001,
    CLUSPROP_PIFLAG_REMOVABLE       = 0x00000002,
    CLUSPROP_PIFLAG_USABLE          = 0x00000004,
    CLUSPROP_PIFLAG_DEFAULT_QUORUM  = 0x00000008
} CLUSPROP_PIFLAGS;

#if ( !MIDL_PASS && !__midl )
//force quorum information, useful for QON type resources
//to be able to continue operation without the quorum
typedef struct CLUS_FORCE_QUORUM_INFO {
    DWORD           dwSize;             // size of this struct including the nodes list.
    DWORD           dwNodeBitMask;      // a bit mask representing the max assumed node set
    DWORD           dwMaxNumberofNodes; // the number of bits set in the mask
    WCHAR           multiszNodeList[1]; // Multi sz list of nodes
} CLUS_FORCE_QUORUM_INFO, *PCLUS_FORCE_QUORUM_INFO;

// Disk partition information.
typedef struct CLUS_PARTITION_INFO {
    DWORD           dwFlags;
    WCHAR           szDeviceName[MAX_PATH];
    WCHAR           szVolumeLabel[MAX_PATH];
    DWORD           dwSerialNumber;
    DWORD           rgdwMaximumComponentLength;
    DWORD           dwFileSystemFlags;
    WCHAR           szFileSystem[32];
} CLUS_PARTITION_INFO, *PCLUS_PARTITION_INFO;

// Disk partition information ex
typedef struct CLUS_PARTITION_INFO_EX {
    DWORD           dwFlags;
    WCHAR           szDeviceName[MAX_PATH];
    WCHAR           szVolumeLabel[MAX_PATH];
    DWORD           dwSerialNumber;
    DWORD           rgdwMaximumComponentLength;
    DWORD           dwFileSystemFlags;
    WCHAR           szFileSystem[32];
    ULARGE_INTEGER  TotalSizeInBytes;
    ULARGE_INTEGER  FreeSizeInBytes;
    DWORD           DeviceNumber;
    DWORD           PartitionNumber;
    GUID            VolumeGuid;
} CLUS_PARTITION_INFO_EX, *PCLUS_PARTITION_INFO_EX;

// Disk partition information property value.
#ifdef __cplusplus
typedef struct CLUSPROP_PARTITION_INFO
    : public CLUSPROP_VALUE
    , public CLUS_PARTITION_INFO {
#else
typedef struct CLUSPROP_PARTITION_INFO {
    CLUSPROP_VALUE;
    CLUS_PARTITION_INFO;
#endif
} CLUSPROP_PARTITION_INFO, *PCLUSPROP_PARTITION_INFO;

// Disk partition information ex property value.
#ifdef __cplusplus
typedef struct CLUSPROP_PARTITION_INFO_EX
    : public CLUSPROP_VALUE
    , public CLUS_PARTITION_INFO_EX {
#else
typedef struct CLUSPROP_PARTITION_INFO_EX {
    CLUSPROP_VALUE;
    CLUS_PARTITION_INFO_EX;
#endif
} CLUSPROP_PARTITION_INFO_EX;

typedef CLUSPROP_PARTITION_INFO_EX UNALIGNED *PCLUSPROP_PARTITION_INFO_EX;
//
// FT set information.
//
typedef struct CLUS_FTSET_INFO {
    DWORD           dwRootSignature;
    DWORD           dwFtType;
} CLUS_FTSET_INFO, *PCLUS_FTSET_INFO;

// Disk partition information property value.
#ifdef __cplusplus
typedef struct CLUSPROP_FTSET_INFO
    : public CLUSPROP_VALUE
    , public CLUS_FTSET_INFO {
#else
typedef struct CLUSPROP_FTSET_INFO {
    CLUSPROP_VALUE;
    CLUS_FTSET_INFO;
#endif
} CLUSPROP_FTSET_INFO, *PCLUSPROP_FTSET_INFO;

// Disk Signature property value.
typedef CLUSPROP_DWORD CLUSPROP_DISK_SIGNATURE, *PCLUSPROP_DISK_SIGNATURE;

// SCSI Address.
typedef struct CLUS_SCSI_ADDRESS {
    union {
        struct {
            UCHAR PortNumber;
            UCHAR PathId;
            UCHAR TargetId;
            UCHAR Lun;
        };
        DWORD   dw;
    };
} CLUS_SCSI_ADDRESS, *PCLUS_SCSI_ADDRESS;

// SCSI Address property value.
#ifdef __cplusplus
typedef struct CLUSPROP_SCSI_ADDRESS
    : public CLUSPROP_VALUE
    , public CLUS_SCSI_ADDRESS {
#else
typedef struct CLUSPROP_SCSI_ADDRESS {
    CLUSPROP_VALUE;
    CLUS_SCSI_ADDRESS;
#endif
} CLUSPROP_SCSI_ADDRESS, *PCLUSPROP_SCSI_ADDRESS;

//
// input structure for CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN
//
typedef struct CLUS_NETNAME_VS_TOKEN_INFO {
    DWORD ProcessID;
    DWORD DesiredAccess;
    BOOL  InheritHandle;
} CLUS_NETNAME_VS_TOKEN_INFO, *PCLUS_NETNAME_VS_TOKEN_INFO;


//
// input structure for CLUSCTL_RESOURCE_NETNAME_SET_PWD
//
#define MAX_OBJECTID 64
#define MAX_CO_PASSWORD_LENGTH 16
#define GUID_PRESENT 0x1
#define CREATEDC_PRESENT 0x2

#define MAX_CREATINGDC_LENGTH 256

typedef struct CLUS_NETNAME_PWD_INFO {
    DWORD Flags;
    WCHAR Password[MAX_CO_PASSWORD_LENGTH];
    WCHAR CreatingDC[MAX_CREATINGDC_LENGTH+2];  // including the '\\' prefix
    WCHAR ObjectGuid[MAX_OBJECTID];                          //
} CLUS_NETNAME_PWD_INFO, *PCLUS_NETNAME_PWD_INFO;



//
// input/output structure associated with Maintenance Mode
//
typedef struct CLUS_MAINTENANCE_MODE_INFO {
    BOOL  InMaintenance;
} CLUS_MAINTENANCE_MODE_INFO, *PCLUS_MAINTENANCE_MODE_INFO;

#define MAINTENANCE_MODE_V2_SIG 0xabbaf00f

typedef enum _MAINTENANCE_MODE_TYPE_ENUM {
    MaintenanceModeTypeDisableIsAliveCheck=1,
    MaintenanceModeTypeOfflineResource=2,
    MaintenanceModeTypeUnclusterResource=3,
} MAINTENANCE_MODE_TYPE_ENUM, *PMAINTENANCE_MODE_TYPE_ENUM;

typedef struct _CLUS_MAINTENANCE_MODE_INFOEX {
    BOOL                        InMaintenance;
    MAINTENANCE_MODE_TYPE_ENUM  MaintainenceModeType;
    CLUSTER_RESOURCE_STATE      InternalState;
    DWORD                       Signature;
} CLUS_MAINTENANCE_MODE_INFOEX, *PCLUS_MAINTENANCE_MODE_INFOEX;

typedef struct _CLUS_STORAGE_SET_DRIVELETTER {
    DWORD    PartitionNumber;
    DWORD    DriveLetterMask;
} CLUS_STORAGE_SET_DRIVELETTER, *PCLUS_STORAGE_SET_DRIVELETTER;

typedef struct _CLUS_STORAGE_GET_AVAILABLE_DRIVELETTERS {
    DWORD    AvailDrivelettersMask;
} CLUS_STORAGE_GET_AVAILABLE_DRIVELETTERS, *PCLUS_STORAGE_GET_AVAILABLE_DRIVELETTERS;

typedef struct _CLUS_STORAGE_REMAP_DRIVELETTER {
    DWORD    CurrentDriveLetterMask;
    DWORD    TargetDriveLetterMask;
} CLUS_STORAGE_REMAP_DRIVELETTER, *PCLUS_STORAGE_REMAP_DRIVELETTER;

typedef struct _CLUS_PROVIDER_STATE_CHANGE_INFO {
    DWORD                   dwSize;             // size of this struct including the provider name.
    CLUSTER_RESOURCE_STATE  resourceState;
    WCHAR                   szProviderId[1];
} CLUS_PROVIDER_STATE_CHANGE_INFO, *PCLUS_PROVIDER_STATE_CHANGE_INFO;

// Beginning of a property list.
typedef struct CLUSPROP_LIST {
    DWORD                   nPropertyCount;
    CLUSPROP_PROPERTY_NAME  PropertyName;
} CLUSPROP_LIST, *PCLUSPROP_LIST;

//
// values for IP Address' EnableNetbios property
//
typedef enum CLUSPROP_IPADDR_ENABLENETBIOS {
    CLUSPROP_IPADDR_ENABLENETBIOS_DISABLED = 0,
    CLUSPROP_IPADDR_ENABLENETBIOS_ENABLED,
    CLUSPROP_IPADDR_ENABLENETBIOS_TRACK_NIC
} CLUSPROP_IPADDR_ENABLENETBIOS;

// Helper for building or parsing a property list buffer.
typedef union CLUSPROP_BUFFER_HELPER {
    BYTE *                          pb;
    WORD *                          pw;
    DWORD *                         pdw;
    LONG *                          pl;
    LPWSTR                          psz;
    PCLUSPROP_LIST                  pList;
    PCLUSPROP_SYNTAX                pSyntax;
    PCLUSPROP_PROPERTY_NAME         pName;
    PCLUSPROP_VALUE                 pValue;
    PCLUSPROP_BINARY                pBinaryValue;
    PCLUSPROP_WORD                  pWordValue;
    PCLUSPROP_DWORD                 pDwordValue;
    PCLUSPROP_LONG                  pLongValue;
    PCLUSPROP_ULARGE_INTEGER        pULargeIntegerValue;
    PCLUSPROP_LARGE_INTEGER         pLargeIntegerValue;
    PCLUSPROP_SZ                    pStringValue;
    PCLUSPROP_MULTI_SZ              pMultiSzValue;
    PCLUSPROP_SECURITY_DESCRIPTOR   pSecurityDescriptor;
    PCLUSPROP_RESOURCE_CLASS        pResourceClassValue;
    PCLUSPROP_RESOURCE_CLASS_INFO   pResourceClassInfoValue;
    PCLUSPROP_DISK_SIGNATURE        pDiskSignatureValue;
    PCLUSPROP_SCSI_ADDRESS          pScsiAddressValue;
    PCLUSPROP_DISK_NUMBER           pDiskNumberValue;
    PCLUSPROP_PARTITION_INFO        pPartitionInfoValue;
    PCLUSPROP_REQUIRED_DEPENDENCY   pRequiredDependencyValue;
    PCLUSPROP_PARTITION_INFO_EX     pPartitionInfoValueEx;
    PCLUSPROP_FILETIME              pFileTimeValue;
} CLUSPROP_BUFFER_HELPER, *PCLUSPROP_BUFFER_HELPER;

#endif // MIDL_PASS

#endif // _CLUSTER_API_TYPES_

// Macro for aligning CLUSPROP buffers on a DWORD boundary.
#define ALIGN_CLUSPROP( count ) ((count + 3) & ~3)

// Macros for declaring array format values
#define CLUSPROP_BINARY_DECLARE( name, cb ) \
    struct {                                \
        CLUSPROP_SYNTAX Syntax;             \
        DWORD           cbLength;           \
        BYTE            rgb[(cb + 3) & ~3]; \
    } name

#define CLUSPROP_SZ_DECLARE( name, cch )    \
    struct {                                \
        CLUSPROP_SYNTAX Syntax;             \
        DWORD           cbLength;           \
        WCHAR           sz[(cch + 1) & ~1]; \
    } name

#define CLUSPROP_PROPERTY_NAME_DECLARE( name, cch ) CLUSPROP_SZ_DECLARE( name, cch )



//
// Cluster resource property enumeration.
//

#ifndef _CLUSTER_API_TYPES_
//
// Define enumerable types
//
typedef enum CLUSTER_RESOURCE_ENUM {
    CLUSTER_RESOURCE_ENUM_DEPENDS   = 0x00000001,
    CLUSTER_RESOURCE_ENUM_PROVIDES  = 0x00000002,
    CLUSTER_RESOURCE_ENUM_NODES     = 0x00000004,

    CLUSTER_RESOURCE_ENUM_ALL       = (CLUSTER_RESOURCE_ENUM_DEPENDS  |
                                         CLUSTER_RESOURCE_ENUM_PROVIDES |
                                         CLUSTER_RESOURCE_ENUM_NODES)
} CLUSTER_RESOURCE_ENUM;

typedef enum CLUSTER_RESOURCE_TYPE_ENUM {
    CLUSTER_RESOURCE_TYPE_ENUM_NODES = 0x00000001,

    CLUSTER_RESOURCE_TYPE_ENUM_ALL   = (CLUSTER_RESOURCE_TYPE_ENUM_NODES)
} CLUSTER_RESOURCE_TYPE_ENUM;

#endif // _CLUSTER_API_TYPES_

#if ( !MIDL_PASS && !__midl )
HRESENUM
WINAPI
ClusterResourceOpenEnum(
    __in HRESOURCE hResource,
    __in DWORD dwType
    );

typedef HRESENUM
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_OPEN_ENUM)(
    HRESOURCE hResource,
    DWORD dwType
    );

DWORD
WINAPI
ClusterResourceGetEnumCount(
    __in HRESENUM hResEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_GET_ENUM_COUNT)(
    __in HRESENUM hResEnum
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterResourceEnum(
    __in HRESENUM hResEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_ENUM)(
    __in HRESENUM hResEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterResourceCloseEnum(
    __in HRESENUM hResEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_CLOSE_ENUM)(
    HRESENUM hResEnum
    );

DWORD
WINAPI
CreateClusterResourceType(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in LPCWSTR lpszDisplayName,
    __in LPCWSTR lpszResourceTypeDll,
    __in DWORD dwLooksAlivePollInterval,
    __in DWORD dwIsAlivePollInterval
    );

typedef DWORD
(WINAPI * PCLUSAPI_CREATE_CLUSTER_RESOURCE_TYPE)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in LPCWSTR lpszDisplayName,
    __in LPCWSTR lpszResourceTypeDll,
    __in DWORD dwLooksAlivePollInterval,
    __in DWORD dwIsAlivePollInterval
    );

DWORD
WINAPI
DeleteClusterResourceType(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName
    );

typedef DWORD
(WINAPI * PCLUSAPI_DELETE_CLUSTER_RESOURCE_TYPE)(
    HCLUSTER hCluster,
    LPCWSTR lpszResourceTypeName
    );

HRESTYPEENUM
WINAPI
ClusterResourceTypeOpenEnum(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in DWORD dwType
    );

typedef HRESTYPEENUM
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_TYPE_OPEN_ENUM)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszResourceTypeName,
    __in DWORD dwType
    );

DWORD
WINAPI
ClusterResourceTypeGetEnumCount(
    __in HRESTYPEENUM hResTypeEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_TYPE_GET_ENUM_COUNT)(
    __in HRESTYPEENUM hResTypeEnum
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterResourceTypeEnum(
    __in HRESTYPEENUM hResTypeEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_TYPE_ENUM)(
    __in HRESTYPEENUM hResTypeEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterResourceTypeCloseEnum(
    __in HRESTYPEENUM hResTypeEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_RESOURCE_TYPE_CLOSE_ENUM)(
    __in HRESTYPEENUM hResTypeEnum
    );

#endif // MIDL_PASS



//
// Network-related structures and types.
//

#ifndef _CLUSTER_API_TYPES_
//
// Define enumerable group types
//
typedef enum CLUSTER_NETWORK_ENUM {
    CLUSTER_NETWORK_ENUM_NETINTERFACES  = 0x00000001,

    CLUSTER_NETWORK_ENUM_ALL            = CLUSTER_NETWORK_ENUM_NETINTERFACES
} CLUSTER_NETWORK_ENUM;

typedef enum CLUSTER_NETWORK_STATE {
    ClusterNetworkStateUnknown = -1,
    ClusterNetworkUnavailable,
    ClusterNetworkDown,
    ClusterNetworkPartitioned,
    ClusterNetworkUp
} CLUSTER_NETWORK_STATE;

// Role the network plays in the cluster.  This is a bitmask.
typedef enum CLUSTER_NETWORK_ROLE {
    ClusterNetworkRoleNone              = 0,
    ClusterNetworkRoleInternalUse       = 0x00000001,
    ClusterNetworkRoleClientAccess      = 0x00000002,
    ClusterNetworkRoleInternalAndClient = 0x00000003
} CLUSTER_NETWORK_ROLE;

#endif // _CLUSTER_API_TYPES_

//
// Interfaces for managing the networks of a cluster.
//

#if ( !MIDL_PASS && !__midl )
HNETWORK
WINAPI
OpenClusterNetwork(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNetworkName
    );

typedef HNETWORK
(WINAPI * PCLUSAPI_OPEN_CLUSTER_NETWORK)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNetworkName
    );

BOOL
WINAPI
CloseClusterNetwork(
    __in HNETWORK hNetwork
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_NETWORK)(
    __in HNETWORK hNetwork
    );

HCLUSTER
WINAPI
GetClusterFromNetwork(
    __in HNETWORK hNetwork
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_GET_CLUSTER_FROM_NETWORK)(
    __in HNETWORK hNetwork
    );

HNETWORKENUM
WINAPI
ClusterNetworkOpenEnum(
    __in HNETWORK hNetwork,
    __in DWORD dwType
    );

typedef HNETWORKENUM
(WINAPI * PCLUSAPI_CLUSTER_NETWORK_OPEN_ENUM)(
    __in HNETWORK hNetwork,
    __in DWORD dwType
    );

DWORD
WINAPI
ClusterNetworkGetEnumCount(
    __in HNETWORKENUM hNetworkEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NETWORK_GET_ENUM_COUNT)(
    __in HNETWORKENUM hNetworkEnum
    );

__success (return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterNetworkEnum(
    __in HNETWORKENUM hNetworkEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NETWORK_ENUM)(
    __in HNETWORKENUM hNetworkEnum,
    __in DWORD dwIndex,
    __out LPDWORD lpdwType,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterNetworkCloseEnum(
    __in HNETWORKENUM hNetworkEnum
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NETWORK_CLOSE_ENUM)(
    __in HNETWORKENUM hNetworkEnum
    );

CLUSTER_NETWORK_STATE
WINAPI
GetClusterNetworkState(
    __in HNETWORK hNetwork
    );

typedef CLUSTER_NETWORK_STATE
(WINAPI * PCLUSAPI_GET_CLUSTER_NETWORK_STATE)(
    __in HNETWORK hNetwork
    );

DWORD
WINAPI
SetClusterNetworkName(
    __in HNETWORK hNetwork,
    __in LPCWSTR lpszName
    );

typedef DWORD
(WINAPI * PCLUSAPI_SET_CLUSTER_NETWORK_NAME)(
    __in HNETWORK hNetwork,
    __in LPCWSTR lpszName
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterNetworkId(
    __in HNETWORK hNetwork,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszNetworkId,
    __inout LPDWORD lpcchName
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_NETWORK_ID)(
    __in HNETWORK hNetwork,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszNetworkId,
    __inout LPDWORD lpcchName
    );

DWORD
WINAPI
ClusterNetworkControl(
    __in HNETWORK hNetwork,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NETWORK_CONTROL)(
    __in HNETWORK hNetwork,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

#endif // MIDL_PASS


#ifndef _CLUSTER_API_TYPES_
//
// Network interface-related structures and types.
//
typedef enum CLUSTER_NETINTERFACE_STATE {
    ClusterNetInterfaceStateUnknown = -1,
    ClusterNetInterfaceUnavailable,
    ClusterNetInterfaceFailed,
    ClusterNetInterfaceUnreachable,
    ClusterNetInterfaceUp
} CLUSTER_NETINTERFACE_STATE;

#endif // _CLUSTER_API_TYPES_

//
// Interfaces for managing the network interfaces of a cluster.
//

#if ( !MIDL_PASS && !__midl )
HNETINTERFACE
WINAPI
OpenClusterNetInterface(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszInterfaceName
    );

typedef HNETINTERFACE
(WINAPI * PCLUSAPI_OPEN_CLUSTER_NET_INTERFACE)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszInterfaceName
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
GetClusterNetInterface(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNodeName,
    __in LPCWSTR lpszNetworkName,
    __out_ecount_part(*lpcchInterfaceName, *lpcchInterfaceName + 1) LPWSTR lpszInterfaceName,
    __inout LPDWORD lpcchInterfaceName
    );

typedef DWORD
(WINAPI * PCLUSAPI_GET_CLUSTER_NET_INTERFACE)(
    __in HCLUSTER hCluster,
    __in LPCWSTR lpszNodeName,
    __in LPCWSTR lpszNetworkName,
    __out_ecount_part_opt(*lpcchInterfaceName, *lpcchInterfaceName + 1) LPWSTR lpszInterfaceName,
    __inout LPDWORD lpcchInterfaceName
    );

BOOL
WINAPI
CloseClusterNetInterface(
    __in HNETINTERFACE hNetInterface
    );

typedef BOOL
(WINAPI * PCLUSAPI_CLOSE_CLUSTER_NET_INTERFACE)(
    __in HNETINTERFACE hNetInterface
    );

HCLUSTER
WINAPI
GetClusterFromNetInterface(
    __in HNETINTERFACE hNetInterface
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_GET_CLUSTER_FROM_NET_INTERFACE)(
    __in HNETINTERFACE hNetInterface
    );

CLUSTER_NETINTERFACE_STATE
WINAPI
GetClusterNetInterfaceState(
    __in HNETINTERFACE hNetInterface
    );

typedef CLUSTER_NETINTERFACE_STATE
(WINAPI * PCLUSAPI_GET_CLUSTER_NET_INTERFACE_STATE)(
    __in HNETINTERFACE hNetInterface
    );

DWORD
WINAPI
ClusterNetInterfaceControl(
    __in HNETINTERFACE hNetInterface,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_NET_INTERFACE_CONTROL)(
    __in HNETINTERFACE hNetInterface,
    __in_opt HNODE hHostNode,
    __in DWORD dwControlCode,
    __in_bcount_opt(nInBufferSize) LPVOID lpInBuffer,
    __in DWORD nInBufferSize,
    __out_bcount_part_opt(nOutBufferSize, *lpBytesReturned) LPVOID lpOutBuffer,
    __in DWORD nOutBufferSize,
    __out_opt LPDWORD lpBytesReturned
    );
#endif // MIDL_PASS


//
// Cluster registry update and access routines
//

#if ( !MIDL_PASS && !__midl )
HKEY
WINAPI
GetClusterKey(
    __in HCLUSTER hCluster,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_KEY)(
     HCLUSTER hCluster,
     REGSAM samDesired
     );

HKEY
WINAPI
GetClusterGroupKey(
    __in HGROUP hGroup,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_GROUP_KEY)(
    HGROUP hGroup,
    REGSAM samDesired
    );

HKEY
WINAPI
GetClusterResourceKey(
    __in HRESOURCE hResource,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_RESOURCE_KEY)(
    HRESOURCE hResource,
    REGSAM samDesired
    );

HKEY
WINAPI
GetClusterNodeKey(
    __in HNODE hNode,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_NODE_KEY)(
    HNODE hNode,
    REGSAM samDesired
    );

HKEY
WINAPI
GetClusterNetworkKey(
    __in HNETWORK hNetwork,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_NETWORK_KEY)(
    __in HNETWORK hNetwork,
    __in REGSAM samDesired
    );

HKEY
WINAPI
GetClusterNetInterfaceKey(
    __in HNETINTERFACE hNetInterface,
    __in REGSAM samDesired
    );

typedef HKEY
(WINAPI * PCLUSAPI_GET_CLUSTER_NET_INTERFACE_KEY)(
    __in HNETINTERFACE hNetInterface,
    __in REGSAM samDesired
    );

LONG
WINAPI
ClusterRegCreateKey(
    __in HKEY hKey,
    __in LPCWSTR lpszSubKey,
    __in DWORD dwOptions,
    __in REGSAM samDesired,
    __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    __out PHKEY phkResult,
    __out_opt LPDWORD lpdwDisposition
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_CREATE_KEY)(
    __in HKEY hKey,
    __in LPCWSTR lpszSubKey,
    __in DWORD dwOptions,
    __in REGSAM samDesired,
    __in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    __out PHKEY phkResult,
    __out_opt LPDWORD lpdwDisposition
    );

LONG
WINAPI
ClusterRegOpenKey(
    __in HKEY hKey,
    __in LPCWSTR lpszSubKey,
    __in REGSAM samDesired,
    __out PHKEY phkResult
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_OPEN_KEY)(
    HKEY hKey,
    LPCWSTR lpszSubKey,
    REGSAM samDesired,
    PHKEY phkResult
    );

LONG
WINAPI
ClusterRegDeleteKey(
    __in HKEY hKey,
    __in LPCWSTR lpszSubKey
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_DELETE_KEY)(
    HKEY hKey,
    LPCWSTR lpszSubKey
    );

LONG
WINAPI
ClusterRegCloseKey(
    __in HKEY hKey
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_CLOSE_KEY)(
    HKEY hKey
    );

__success(return == ERROR_SUCCESS)
LONG
WINAPI
ClusterRegEnumKey(
    __in HKEY hKey,
    __in DWORD dwIndex,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName,
    __out_opt PFILETIME lpftLastWriteTime
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_ENUM_KEY)(
    __in HKEY hKey,
    __in DWORD dwIndex,
    __out_ecount_part(*lpcchName, *lpcchName + 1) LPWSTR lpszName,
    __inout LPDWORD lpcchName,
    __out PFILETIME lpftLastWriteTime
    );

DWORD
WINAPI
ClusterRegSetValue(
    __in HKEY hKey,
    __in LPCWSTR lpszValueName,
    __in DWORD dwType,
    __in CONST BYTE* lpData,
    __in DWORD cbData
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_REG_SET_VALUE)(
    HKEY hKey,
    LPCWSTR lpszValueName,
    DWORD dwType,
    CONST BYTE* lpData,
    DWORD cbData
    );

DWORD
WINAPI
ClusterRegDeleteValue(
    __in HKEY hKey,
    __in LPCWSTR lpszValueName
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_REG_DELETE_VALUE)(
    HKEY hKey,
    LPCWSTR lpszValueName
    );

LONG
WINAPI
ClusterRegQueryValue(
    __in HKEY hKey,
    __in LPCWSTR lpszValueName,
    __out_opt LPDWORD lpdwValueType,
    __out_bcount_part_opt(*lpcbData, *lpcbData) LPBYTE lpData,
    __inout_opt LPDWORD lpcbData
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_QUERY_VALUE)(
    __in HKEY hKey,
    __in LPCWSTR lpszValueName,
    __out_opt LPDWORD lpdwValueType,
    __out_bcount_part_opt(*lpcbData, *lpcbData) LPBYTE lpData,
    __inout_opt LPDWORD lpcbData
    );

__success(return == ERROR_SUCCESS)
DWORD
WINAPI
ClusterRegEnumValue(
    __in HKEY hKey,
    __in DWORD dwIndex,
    __out_ecount_part(*lpcchValueName, *lpcchValueName + 1) LPWSTR lpszValueName,
    __inout LPDWORD lpcchValueName,
    __out_opt LPDWORD lpdwType,
    __out_bcount_part_opt(*lpcbData, *lpcbData) LPBYTE lpData,
    __inout_opt LPDWORD lpcbData
    );

typedef DWORD
(WINAPI * PCLUSAPI_CLUSTER_REG_ENUM_VALUE)(
    __in HKEY hKey,
    __in DWORD dwIndex,
    __out_ecount_part(*lpcchValueName, *lpcchValueName + 1) LPWSTR lpszValueName,
    __inout LPDWORD lpcchValueName,
    __out LPDWORD lpdwType,
    __out_bcount_part_opt(*lpcbData, *lpcbData) LPBYTE lpData,
    __inout_opt LPDWORD lpcbData
    );

LONG
WINAPI
ClusterRegQueryInfoKey(
    __in HKEY hKey,
    __in LPDWORD lpcSubKeys,
    __in LPDWORD lpcchMaxSubKeyLen,
    __in LPDWORD lpcValues,
    __in LPDWORD lpcchMaxValueNameLen,
    __in LPDWORD lpcbMaxValueLen,
    __in LPDWORD lpcbSecurityDescriptor,
    __in PFILETIME lpftLastWriteTime
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_QUERY_INFO_KEY)(
    HKEY hKey,
    LPDWORD lpcSubKeys,
    LPDWORD lpcbMaxSubKeyLen,
    LPDWORD lpcValues,
    LPDWORD lpcbMaxValueNameLen,
    LPDWORD lpcbMaxValueLen,
    LPDWORD lpcbSecurityDescriptor,
    PFILETIME lpftLastWriteTime
    );

LONG
WINAPI
ClusterRegGetKeySecurity (
    __in HKEY hKey,
    __in SECURITY_INFORMATION RequestedInformation,
    __out_bcount_part(*lpcbSecurityDescriptor, *lpcbSecurityDescriptor) PSECURITY_DESCRIPTOR pSecurityDescriptor,
    __inout LPDWORD lpcbSecurityDescriptor
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_GET_KEY_SECURITY)(
    __in HKEY hKey,
    __in SECURITY_INFORMATION RequestedInformation,
    __out_bcount_part(*lpcbSecurityDescriptor, *lpcbSecurityDescriptor) PSECURITY_DESCRIPTOR pSecurityDescriptor,
    __inout LPDWORD lpcbSecurityDescriptor
    );

LONG
WINAPI
ClusterRegSetKeySecurity(
    __in HKEY hKey,
    __in SECURITY_INFORMATION SecurityInformation,
    __in PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

typedef LONG
(WINAPI * PCLUSAPI_CLUSTER_REG_SET_KEY_SECURITY)(
    HKEY hKey,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

LONG WINAPI ClusterRegCreateBatch(
    __in_opt HKEY hKey,
    __out HREGBATCH* pHREGBATCH
    );

typedef LONG 
(WINAPI *PCLUSAPI_CLUSTER_REG_CREATE_BATCH)(
    __in_opt HKEY hKey,
    __out HREGBATCH* pHREGBATCH
    );

LONG WINAPI ClusterRegAddCommand(
    __in HREGBATCH HREGBATCH,
    __in CLUSTER_REG_COMMAND dwCommand,
    __in_opt LPCWSTR wzName,
    __in DWORD dwOptions,
    __in VOID CONST * lpData,
    __in DWORD cbData
    );

typedef LONG 
(WINAPI *PCLUSTER_REG_ADD_COMMAND)(
    __in HREGBATCH HREGBATCH,
    __in CLUSTER_REG_COMMAND dwCommand,
    __in DWORD dwOptions,
    __in_opt LPWSTR wzName,
    __in VOID CONST * lpData,
    __in DWORD cbData
    );

LONG WINAPI ClusterRegCloseBatch(
    __in HREGBATCH HREGBATCH,
    __in BOOL bCommit,
    __out_opt INT * failedCommandNumber
    );

typedef LONG 
(WINAPI *PCLUSTER_REG_CLOSE_BATCH)(
    __in HREGBATCH HREGBATCH,
    __in BOOL bCommit,
    __out_opt INT * failedCommandNumber
    );


//
// Cluster Create, Add Node and Destroy Cluster
//

//
// Phases that changes in cluster persistent membership will go through.
// Phase numbers may arrive in any order via the callback function.
//

typedef enum _CLUSTER_MEMBERSHIP_CHANGE_PHASE {

    MembershipChangePhaseValidateNodeState              = 1,
    MembershipChangePhaseNodeInitialize                 = 3,
    MembershipChangePhaseValidateNetft                  = 4,
    MembershipChangePhaseValidateClusDisk               = 5,
    MembershipChangePhaseConfigureClusSvc               = 6,
    MembershipChangePhaseStartingClusSvc                = 7,
    MembershipChangePhaseInitialize                     = 8,
    MembershipChangePhaseWaitForServiceStart            = 9,
    MembershipChangePhaseNodeUp                         = 10,
    MembershipChangePhaseAddClusterProperties           = 11,
    MembershipChangePhaseCreateResourceTypes            = 12,
    MembershipChangePhaseCreateClusterGroup             = 13,
    MembershipChangePhaseCreateQuorumResource           = 14,
    MembershipChangePhaseCreateIPAddressResources       = 15,
    MembershipChangePhaseCreateNetworkName              = 16,
    MembershipChangePhaseClusterGroupOnline             = 17,
    MembershipChangePhaseGettingCurrentMembership       = 18,
    MembershipChangePhaseAddNodeToCluster               = 19,
    MembershipChangePhaseOfflineGroup                   = 20,
    MembershipChangePhaseEvictNode                      = 21,
    MembershipChangePhaseFailureCleanup                 = 22

} CLUSTER_MEMBERSHIP_CHANGE_PHASE;

typedef BOOL
(WINAPI *PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS)(
    PVOID                           pvCallbackArg,
    CLUSTER_MEMBERSHIP_CHANGE_PHASE eMembershipPhase,
    DWORD                           dwPercentComplete,
    __in PCWSTR                     lpszObjectName,
    DWORD                           dwStatus );

HCLUSTER
WINAPI
CreateCluster(
    __in PCREATE_CLUSTER_CONFIG pConfig,
    __in BOOL                   fAcceptPartialFailure,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID              pvCallbackArg
    );

typedef HCLUSTER
(WINAPI * PCLUSAPI_CREATE_CLUSTER)(
    __in PCREATE_CLUSTER_CONFIG pConfig,
    __in BOOL                   fAcceptPartialFailure,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID              pvCallbackArg
    );

HNODE
WINAPI
AddClusterNode(
    __in HCLUSTER    hCluster,
    __in PCWSTR      lpszNodeName,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID   pvCallbackArg
    );

typedef HNODE
(WINAPI * PCLUSAPI_ADD_CLUSTER_NODE)(
    __in HCLUSTER    hCluster,
    __in PCWSTR      lpszNodeName,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID   pvCallbackArg
    );

DWORD
WINAPI
DestroyCluster(
    __in HCLUSTER    hCluster,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID   pvCallbackArg
    );

typedef DWORD
(WINAPI * PCLUSAPI_DESTROY_CLUSTER)(
    __in HCLUSTER    hCluster,
    __in_opt PCLUSTER_MEMBERSHIP_CHANGE_PROGRESS    pfnProgressCallback,
    __in_opt PVOID   pvCallbackArg
    );

//
// Standard Resource Type Names
//

#define CLUS_RESTYPE_NAME_GENAPP            L"Generic Application"
#define CLUS_RESTYPE_NAME_GENSVC            L"Generic Service"
#define CLUS_RESTYPE_NAME_GENSCRIPT         L"Generic Script"
#define CLUS_RESTYPE_NAME_IPADDR            L"IP Address"
#define CLUS_RESTYPE_NAME_NETNAME           L"Network Name"
#define CLUS_RESTYPE_NAME_FILESHR           L"File Share"
#define CLUS_RESTYPE_NAME_PRTSPLR           L"Print Spooler"
#define CLUS_RESTYPE_NAME_LKQUORUM          L"Local Quorum"
#define CLUS_RESTYPE_NAME_IPV6_NATIVE       L"IPv6 Address"
#define CLUS_RESTYPE_NAME_IPV6_TUNNEL       L"IPv6 Tunnel Address"

#define CLUS_RESTYPE_NAME_VSSTASK           L"Volume Shadow Copy Service Task"

#define CLUS_RESTYPE_NAME_WINS              L"WINS Service"
#define CLUS_RESTYPE_NAME_DHCP              L"DHCP Service"

#define CLUS_RESTYPE_NAME_MSMQ              L"Microsoft Message Queue Server"
#define CLUS_RESTYPE_NAME_NEW_MSMQ          L"MSMQ"
#define CLUS_RESTYPE_NAME_MSMQ_TRIGGER      L"MSMQTriggers"

#define CLUS_RESTYPE_NAME_MSDTC             L"Distributed Transaction Coordinator"

#define CLUS_RESTYPE_NAME_NFS               L"NFS Share"

#define CLUS_RESTYPE_NAME_ISNS              L"Microsoft iSNS"

#define CLUS_RESTYPE_NAME_HARDDISK          L"Physical Disk"
#define CLUS_RESTYPE_NAME_PHYS_DISK         CLUS_RESTYPE_NAME_HARDDISK


//
// Cluster common property names
//
#define CLUSREG_NAME_ADMIN_EXT  L"AdminExtensions"
#define CLUSREG_NAME_CLUS_DESC  L"Description"
#define CLUSREG_NAME_CLUS_SD    L"Security Descriptor"

#define CLUSREG_NAME_CLUS_DEFAULT_NETWORK_ROLE    L"DefaultNetworkRole"
#define CLUSREG_NAME_QUORUM_ARBITRATION_TIMEOUT   L"QuorumArbitrationTimeMax"
#define CLUSREG_NAME_QUORUM_ARBITRATION_EQUALIZER L"QuorumArbitrationTimeMin"
#define CLUSTER_HEARTBEAT_TIMEOUT_KEYNAME         L"ClusSvcHeartbeatTimeout"
#define CLUSTER_HANG_RECOVERY_ACTION_KEYNAME      L"HangRecoveryAction"
#define CLUSTER_CSA_VSS_STATE                     L"BackupInProgress"

#define CLUSREG_NAME_DISABLE_GROUP_PREFERRED_OWNER_RANDOMIZATION    L"DisableGroupPreferredOwnerRandomization"

//
// Properties and defaults for single and multi subnet delays and thresholds.
//
#define CLUSREG_NAME_SAME_SUBNET_DELAY      L"SameSubnetDelay"
#define CLUSREG_NAME_CROSS_SUBNET_DELAY     L"CrossSubnetDelay"
#define CLUSREG_NAME_SAME_SUBNET_THRESHOLD  L"SameSubnetThreshold"
#define CLUSREG_NAME_CROSS_SUBNET_THRESHOLD L"CrossSubnetThreshold"


//
// Node common property names
//

#define CLUSREG_NAME_NODE_NAME              L"NodeName"
#define CLUSREG_NAME_NODE_HIGHEST_VERSION   L"NodeHighestVersion"
#define CLUSREG_NAME_NODE_LOWEST_VERSION    L"NodeLowestVersion"
#define CLUSREG_NAME_NODE_DESC              L"Description"
#define CLUSREG_NAME_NODE_MAJOR_VERSION     L"MajorVersion"
#define CLUSREG_NAME_NODE_MINOR_VERSION     L"MinorVersion"
#define CLUSREG_NAME_NODE_BUILD_NUMBER      L"BuildNumber"
#define CLUSREG_NAME_NODE_CSDVERSION        L"CSDVersion"


//
// Group common property names
//

#define CLUSREG_NAME_GRP_NAME               L"Name"
#define CLUSREG_NAME_GRP_DESC               L"Description"
#define CLUSREG_NAME_GRP_PERSISTENT_STATE   L"PersistentState"
#define CLUSREG_NAME_GRP_FAILBACK_TYPE      L"AutoFailbackType"
#define CLUSREG_NAME_GRP_FAILBACK_WIN_START L"FailbackWindowStart"
#define CLUSREG_NAME_GRP_FAILBACK_WIN_END   L"FailbackWindowEnd"
#define CLUSREG_NAME_GRP_FAILOVER_THRESHOLD L"FailoverThreshold"
#define CLUSREG_NAME_GRP_FAILOVER_PERIOD    L"FailoverPeriod"

#define CLUSREG_NAME_GRP_ANTI_AFFINITY_CLASS_NAME L"AntiAffinityClassNames"


//
// Resource common property names
//

#define CLUSREG_NAME_RES_NAME                       L"Name"
#define CLUSREG_NAME_RES_TYPE                       L"Type"
#define CLUSREG_NAME_RES_DESC                       L"Description"
#define CLUSREG_NAME_RES_SEPARATE_MONITOR           L"SeparateMonitor"
#define CLUSREG_NAME_RES_PERSISTENT_STATE           L"PersistentState"
#define CLUSREG_NAME_RES_LOOKS_ALIVE                L"LooksAlivePollInterval"
#define CLUSREG_NAME_RES_IS_ALIVE                   L"IsAlivePollInterval"
#define CLUSREG_NAME_RES_RESTART_ACTION             L"RestartAction"
#define CLUSREG_NAME_RES_RESTART_THRESHOLD          L"RestartThreshold"
#define CLUSREG_NAME_RES_RESTART_PERIOD             L"RestartPeriod"
#define CLUSREG_NAME_RES_RETRY_PERIOD_ON_FAILURE    L"RetryPeriodOnFailure"
#define CLUSREG_NAME_RES_PENDING_TIMEOUT            L"PendingTimeout"
#define CLUSREG_NAME_RES_DEADLOCK_TIMEOUT           L"DeadlockTimeout"
#define CLUSREG_NAME_RES_MONITOR_PID                L"MonitorProcessId"
#define CLUSREG_NAME_RES_INTERNAL_STATE             L"InternalState"


//
// Resource Type common property names
//

#define CLUSREG_NAME_RESTYPE_NAME               L"Name"
#define CLUSREG_NAME_RESTYPE_DESC               L"Description"
#define CLUSREG_NAME_RESTYPE_DLL_NAME           L"DllName"
#define CLUSREG_NAME_RESTYPE_ADMIN_EXTENSIONS   L"AdminExtensions"
#define CLUSREG_NAME_RESTYPE_LOOKS_ALIVE        CLUSREG_NAME_RES_LOOKS_ALIVE
#define CLUSREG_NAME_RESTYPE_IS_ALIVE           CLUSREG_NAME_RES_IS_ALIVE
#define CLUSREG_NAME_RESTYPE_PENDING_TIMEOUT    CLUSREG_NAME_RES_PENDING_TIMEOUT
#define CLUSREG_NAME_RESTYPE_DEADLOCK_TIMEOUT   CLUSREG_NAME_RES_DEADLOCK_TIMEOUT

//
// Network common property names
//

#define CLUSREG_NAME_NET_NAME               L"Name"
#define CLUSREG_NAME_NET_IPV6_ADDRESSES     L"IPv6Addresses"
#define CLUSREG_NAME_NET_IPV6_PREFIXLENGTHS L"IPv6PrefixLengths"
#define CLUSREG_NAME_NET_IPV4_ADDRESSES     L"IPv4Addresses"
#define CLUSREG_NAME_NET_IPV4_PREFIXLENGTHS L"IPv4PrefixLengths"
#define CLUSREG_NAME_NET_ADDRESS            L"Address"
#define CLUSREG_NAME_NET_ADDRESS_MASK       L"AddressMask"
#define CLUSREG_NAME_NET_DESC               L"Description"
#define CLUSREG_NAME_NET_ROLE               L"Role"


//
// Network Interface common property names
//

#define CLUSREG_NAME_NETIFACE_NAME              L"Name"
#define CLUSREG_NAME_NETIFACE_NODE              L"Node"
#define CLUSREG_NAME_NETIFACE_NETWORK           L"Network"
#define CLUSREG_NAME_NETIFACE_ADAPTER_NAME      L"Adapter"
#define CLUSREG_NAME_NETIFACE_ADAPTER_ID        L"AdapterId"
#define CLUSREG_NAME_NETIFACE_DHCP_ENABLED      L"DhcpEnabled"
#define CLUSREG_NAME_NETIFACE_IPV6_ADDRESSES    L"IPv6Addresses"
#define CLUSREG_NAME_NETIFACE_IPV4_ADDRESSES    L"IPv4Addresses"
#define CLUSREG_NAME_NETIFACE_ADDRESS           L"Address"
#define CLUSREG_NAME_NETIFACE_DESC              L"Description"

//
// Resource private property names
//

//
// Physical Disk
//

#define CLUSREG_NAME_PHYSDISK_DISKIDTYPE       L"DiskIdType"
#define CLUSREG_NAME_PHYSDISK_DISKSIGNATURE    L"DiskSignature"
#define CLUSREG_NAME_PHYSDISK_DISKIDGUID       L"DiskIdGuid"
#define CLUSREG_NAME_PHYSDISK_DISKRUNCHKDSK    L"DiskRunChkDsk"
#define CLUSREG_NAME_PHYSDISK_DISKUNIQUEIDS    L"DiskUniqueIds"
#define CLUSREG_NAME_PHYSDISK_DISKVOLUMEINFO   L"DiskVolumeInfo"
#define CLUSREG_NAME_PHYSDISK_DISKARBTYPE      L"DiskArbType"
#define CLUSREG_NAME_PHYSDISK_DISKARBINTERVAL  L"DiskArbInterval"
#define CLUSREG_NAME_PHYSDISK_DISKPATH         L"DiskPath"
#define CLUSREG_NAME_PHYSDISK_DISKRELOAD       L"DiskReload"
#define CLUSREG_NAME_PHYSDISK_MAINTMODE        L"MainteanceMode"
#define CLUSREG_NAME_PHYSDISK_DISKIODELAY      L"MaxIoLatency"
#define CLUSREG_NAME_PHYSDISK_MIGRATEFIXUP     L"MigrateDriveLetters"


//
// Generic Application
//

#define CLUSREG_NAME_GENAPP_COMMAND_LINE            L"CommandLine"
#define CLUSREG_NAME_GENAPP_CURRENT_DIRECTORY       L"CurrentDirectory"
#define CLUSREG_NAME_GENAPP_INTERACT_WITH_DESKTOP   L"InteractWithDesktop"
#define CLUSREG_NAME_GENAPP_USE_NETWORK_NAME        L"UseNetworkName"

//
// Generic Script
//

#define CLUSREG_NAME_GENSCRIPT_SCRIPT_FILEPATH      L"ScriptFilepath"


//
// Generic Service
//

#define CLUSREG_NAME_GENSVC_SERVICE_NAME            L"ServiceName"
#define CLUSREG_NAME_GENSVC_STARTUP_PARAMS          L"StartupParameters"
#define CLUSREG_NAME_GENSVC_USE_NETWORK_NAME        L"UseNetworkName"


//
// IPv4 Address
//

#define CLUSREG_NAME_IPADDR_NETWORK                 L"Network"
#define CLUSREG_NAME_IPADDR_ADDRESS                 L"Address"
#define CLUSREG_NAME_IPADDR_SUBNET_MASK             L"SubnetMask"
#define CLUSREG_NAME_IPADDR_ENABLE_NETBIOS          L"EnableNetBIOS"
#define CLUSREG_NAME_IPADDR_OVERRIDE_ADDRMATCH      L"OverrideAddressMatch"
#define CLUSREG_NAME_IPADDR_ENABLE_DHCP             L"EnableDhcp"
#define CLUSREG_NAME_IPADDR_LEASE_OBTAINED_TIME     L"LeaseObtainedTime"
#define CLUSREG_NAME_IPADDR_LEASE_TERMINATES_TIME   L"LeaseExpiresTime"
#define CLUSREG_NAME_IPADDR_T1                      L"T1"
#define CLUSREG_NAME_IPADDR_T2                      L"T2"
#define CLUSREG_NAME_IPADDR_DHCP_SERVER             L"DhcpServer"
#define CLUSREG_NAME_IPADDR_DHCP_ADDRESS            L"DhcpAddress"
#define CLUSREG_NAME_IPADDR_DHCP_SUBNET_MASK        L"DhcpSubnetMask"


//
// IPv6 Address
//

#define CLUSREG_NAME_IPV6_NATIVE_NETWORK            L"Network"
#define CLUSREG_NAME_IPV6_NATIVE_ADDRESS            L"Address"
#define CLUSREG_NAME_IPV6_NATIVE_PREFIX_LENGTH      L"PrefixLength"

#define CLUSREG_NAME_IPV6_TUNNEL_ADDRESS            L"Address"
#define CLUSREG_NAME_IPV6_TUNNEL_TUNNELTYPE         L"TunnelType"


//
// Network Name
//

#define CLUSREG_NAME_NETNAME_NAME                   L"Name"
#define CLUSREG_NAME_NETNAME_CREATING_DC            L"CreatingDC"
#define CLUSREG_NAME_NETNAME_OBJECT_ID              L"ObjectGUID"
#define CLUSREG_NAME_NETNAME_DNS_NAME               L"DnsName"
#define CLUSREG_NAME_NETNAME_REMAP_PIPE_NAMES       L"RemapPipeNames"
#define CLUSREG_NAME_NETNAME_RESOURCE_DATA          L"ResourceData"
#define CLUSREG_NAME_NETNAME_REQUIRE_DNS            L"RequireDNS"
#define CLUSREG_NAME_NETNAME_REQUIRE_KERBEROS       L"RequireKerberos"
#define CLUSREG_NAME_NETNAME_SCOPED_NAME            L"ScopedName"
#define CLUSREG_NAME_NETNAME_STATUS_NETBIOS         L"StatusNetBIOS"
#define CLUSREG_NAME_NETNAME_STATUS_DNS             L"StatusDNS"
#define CLUSREG_NAME_NETNAME_STATUS_KERBEROS        L"StatusKerberos"
#define CLUSREG_NAME_NETNAME_VCO_CONTAINER          L"VcoContainer"
#define CLUSREG_NAME_NETNAME_LAST_DNS_UPDATE        L"LastDNSUpdateTime"
#define CLUSREG_NAME_NETNAME_CONTAINERGUID          L"CryptoContainerGUID"
#define CLUSREG_NAME_NETNAME_HOST_TTL               L"HostRecordTTL"
#define CLUSREG_NAME_NETNAME_PUBLISH_PTR            L"PublishPTRRecords"


//
// Print Spooler
//

#define CLUSREG_NAME_PRTSPOOL_DEFAULT_SPOOL_DIR     L"DefaultSpoolDirectory"
#define CLUSREG_NAME_PRTSPOOL_TIMEOUT               L"JobCompletionTimeout"

//
// File Share
//

#define CLUSREG_NAME_FILESHR_SHARE_NAME             L"ShareName"
#define CLUSREG_NAME_FILESHR_PATH                   L"Path"
#define CLUSREG_NAME_FILESHR_REMARK                 L"Remark"
#define CLUSREG_NAME_FILESHR_MAX_USERS              L"MaxUsers"
#define CLUSREG_NAME_FILESHR_SD                     L"Security Descriptor"
#define CLUSREG_NAME_FILESHR_SHARE_SUBDIRS          L"ShareSubDirs"
#define CLUSREG_NAME_FILESHR_HIDE_SUBDIR_SHARES     L"HideSubDirShares"
#define CLUSREG_NAME_FILESHR_IS_DFS_ROOT            L"IsDfsRoot"
#define CLUSREG_NAME_FILESHR_SHARE_FLAGS            L"ShareFlags"

//
// DHCP Service
//

#define CLUSREG_NAME_DHCP_DATABASE_PATH             L"DatabasePath"
#define CLUSREG_NAME_DHCP_BACKUP_PATH               L"BackupPath"
#define CLUSREG_NAME_LOG_FILE_PATH                  L"LogFilePath"


//
// WINS Service
//

#define CLUSREG_NAME_WINS_DATABASE_PATH             L"DatabasePath"
#define CLUSREG_NAME_WINS_BACKUP_PATH               L"BackupPath"

//
// Local Quorum
//

#define CLUSREG_NAME_LKQUORUM_PATH                  L"Path"
#define CLUSREG_NAME_LKQUORUM_DEBUG                 L"Debug"


//
// Volume Shadow Copy Service Task
//

#define CLUSREG_NAME_VSSTASK_CURRENTDIRECTORY       L"CurrentDirectory"
#define CLUSREG_NAME_VSSTASK_APPNAME                L"ApplicationName"
#define CLUSREG_NAME_VSSTASK_APPPARAMS              L"ApplicationParams"
#define CLUSREG_NAME_VSSTASK_TRIGGERARRAY           L"TriggerArray"




#if _MSC_VER >= 1200
#pragma warning(pop)              // restore 4200/4201
#else
#pragma warning( default : 4200 ) // nonstandard extension used : zero-sized array in struct/union
#pragma warning( default : 4201 ) // nonstandard extension used : nameless struct/union
#endif
#endif // MIDL_PASS

#ifdef __cplusplus
} // extern "C"
#endif

#ifndef _CLUSTER_API_TYPES_
#define _CLUSTER_API_TYPES_
#endif // _CLUSTER_API_TYPES_

#endif // _CLUSTER_API_

