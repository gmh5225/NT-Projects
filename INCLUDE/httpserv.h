#ifndef _HTTPSERV_H_
#define _HTTPSERV_H_

#if (!defined(_WIN64) && !defined(WIN32))
#error httpserv.h is only supported on WIN32 or WIN64 platforms
#endif

#include <ahadmin.h>
#include <http.h>

//
// Request triggered notifications
//

//
// Request deterministic notifications
//

// request is beginning
#define RQ_BEGIN_REQUEST               0x00000001
// request is being authenticated
#define RQ_AUTHENTICATE_REQUEST        0x00000002
// request is being authorized
#define RQ_AUTHORIZE_REQUEST           0x00000004
// satisfy request from cache
#define RQ_RESOLVE_REQUEST_CACHE       0x00000008
// map handler for request
#define RQ_MAP_REQUEST_HANDLER         0x00000010
// acquire request state
#define RQ_ACQUIRE_REQUEST_STATE       0x00000020
// pre-execute handler
#define RQ_PRE_EXECUTE_REQUEST_HANDLER 0x00000040 
// execute handler
#define RQ_EXECUTE_REQUEST_HANDLER     0x00000080
// release request state
#define RQ_RELEASE_REQUEST_STATE       0x00000100
// update cache
#define RQ_UPDATE_REQUEST_CACHE        0x00000200
// log request
#define RQ_LOG_REQUEST                 0x00000400
// end request
#define RQ_END_REQUEST                 0x00000800

//
// Request non-deterministic notifications
//

// custom notification
#define RQ_CUSTOM_NOTIFICATION         0x10000000
// send response
#define RQ_SEND_RESPONSE               0x20000000
// read entity
#define RQ_READ_ENTITY                 0x40000000
// map a url to a physical path
#define RQ_MAP_PATH                    0x80000000

// 
// Global notifications
//

// stop accepting new requests
#define GL_STOP_LISTENING               0x00000002
// cache cleanup before termination
#define GL_CACHE_CLEANUP                0x00000004
// cache operation
#define GL_CACHE_OPERATION              0x00000010
// health check
#define GL_HEALTH_CHECK                 0x00000020
// configuration changed
#define GL_CONFIGURATION_CHANGE         0x00000040
// file changed
#define GL_FILE_CHANGE                  0x00000080
// before request pipeline has started
#define GL_PRE_BEGIN_REQUEST            0x00000100
// application start
#define GL_APPLICATION_START            0x00000200
// resolve modules for an application
#define GL_APPLICATION_RESOLVE_MODULES  0x00000400
// application end
#define GL_APPLICATION_STOP             0x00000800
// RSCA query
#define GL_RSCA_QUERY                   0x00001000
// trace event was raised
#define GL_TRACE_EVENT                  0x00002000
// custom notification
#define GL_CUSTOM_NOTIFICATION          0x00004000
// thread cleanup notification
#define GL_THREAD_CLEANUP               0x00008000

//
// Request notification return status
//

typedef enum REQUEST_NOTIFICATION_STATUS
{
    RQ_NOTIFICATION_CONTINUE,                   // continue processing
                                                // for notification
    RQ_NOTIFICATION_PENDING,                    // suspend processing
                                                // for notification
    RQ_NOTIFICATION_FINISH_REQUEST              // finish request
                                                // processing
};

//
// Out of band return codes
//

typedef enum GLOBAL_NOTIFICATION_STATUS
{
    GL_NOTIFICATION_CONTINUE,                  // continue processing
                                               // for notification
    GL_NOTIFICATION_HANDLED                    // finish processing for
                                               // notification
};

// 
// Priority class aliases
//

#define PRIORITY_ALIAS_FIRST              L"FIRST"
#define PRIORITY_ALIAS_HIGH               L"HIGH"
#define PRIORITY_ALIAS_MEDIUM             L"MEDIUM"
#define PRIORITY_ALIAS_LOW                L"LOW"
#define PRIORITY_ALIAS_LAST               L"LAST"

//
// Cache operations
//

typedef enum CACHE_OPERATION
{
    CACHE_OPERATION_RETRIEVE,
    CACHE_OPERATION_ADD,
    CACHE_OPERATION_DELETE,
    CACHE_OPERATION_FLUSH_PREFIX,
    CACHE_OPERATION_ENUM
};

//
// Module identifier
//

typedef VOID*            HTTP_MODULE_ID;

//
// Flags for IHttpContext->CloneContext()
//

#define CLONE_FLAG_BASICS              0x01 
#define CLONE_FLAG_HEADERS             0x02 
#define CLONE_FLAG_ENTITY              0x04 
#define CLONE_FLAG_NO_PRECONDITION     0x08 
#define CLONE_FLAG_NO_DAV              0x10

//
// Flags for IHttpContext->ExecuteRequest()
//

#define EXECUTE_FLAG_NO_HEADERS                     0x01
#define EXECUTE_FLAG_IGNORE_CURRENT_INTERCEPTOR     0x02
#define EXECUTE_FLAG_IGNORE_APPPOOL                 0x04
#define EXECUTE_FLAG_DISABLE_CUSTOM_ERROR           0x08
#define EXECUTE_FLAG_SAME_URL                       0x10
// do not flush the child response but copy it back to the parent
#define EXECUTE_FLAG_BUFFER_RESPONSE                0x20
// child response is still eligible for http.sys caching
#define EXECUTE_FLAG_HTTP_CACHE_ELIGIBLE            0x40


//
// forward declarations
//
struct HTTP_TRACE_CONFIGURATION;
struct HTTP_TRACE_EVENT;

class  IWpfSettings;
class  IHttpTraceContext;

//
// Module-specific context descriptor
//
class IHttpStoredContext
{
 public:
    virtual
    VOID
    CleanupStoredContext(
        VOID
    ) = 0;
};

//
// Context container
//
class IHttpModuleContextContainer
{
 public:
    virtual
    IHttpStoredContext *
    GetModuleContext(
        IN HTTP_MODULE_ID       moduleId
    ) = 0;

    virtual
    HRESULT
    SetModuleContext(
        IN IHttpStoredContext * ppStoredContext,
        IN HTTP_MODULE_ID       moduleId
    ) = 0;  
};

//
// Dispensed context container
//
class IDispensedHttpModuleContextContainer : public IHttpModuleContextContainer
{
public:
    virtual
    VOID
    ReleaseContainer(
        VOID
    ) = 0;
};

//
// Performance counter descriptor
//
class IHttpPerfCounterInfo
{
 public:
    virtual
    VOID
    IncrementCounter(
        DWORD               dwCounterIndex,
        DWORD               dwValue = 1
    ) = 0;

    virtual
    VOID
    DecrementCounter(
        DWORD               dwCounterIndex,
        DWORD               dwValue = 1
    ) = 0;
};

//
// Application descriptor
//
class IHttpApplication
{
 public:
    virtual
    PCWSTR
    GetApplicationPhysicalPath(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetApplicationId(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetAppConfigPath(
        VOID
    ) const = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;
};

class IScriptMapInfo;

// 
// URI cache entry descriptor
// 
class IHttpUrlInfo
{
 public:
    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;

    virtual
    BOOL
    IsFrequentlyHit(
        VOID
    ) const = 0;
};

// 
// Script map descriptor
// 
class IScriptMapInfo
{
 public:
    virtual
    PCWSTR
    GetPath(
        VOID
    ) const = 0;

    virtual
    PCSTR
    GetAllowedVerbs(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetModules(
        OUT DWORD *         pcchModules = NULL
    ) const = 0;

    virtual
    PCWSTR
    GetScriptProcessor(
        OUT DWORD *         pcchScriptProcessor = NULL
    ) const = 0;

    virtual
    PCWSTR
    GetManagedType(
        OUT DWORD *         pcchManagedType = NULL
    ) const = 0;

    virtual
    BOOL
    GetAllowPathInfoForScriptMappings(
        VOID
    ) const = 0;

    virtual
    DWORD
    GetRequiredAccess(
        VOID
    ) const = 0;

    virtual
    DWORD
    GetResourceType(
        VOID
    ) const = 0;

    virtual
    BOOL
    GetIsStarScriptMap(
        VOID
    ) const = 0;

    virtual
    DWORD
    GetResponseBufferLimit(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetName(
        VOID
    ) const = 0;
};

class IHttpTokenEntry;

// 
// Metadata descriptor
// 
class IMetadataInfo
{
 public:
    virtual
    PCWSTR
    GetMetaPath(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetVrPath(
        VOID
    ) const = 0;

    virtual
    IHttpTokenEntry *
    GetVrToken(
        VOID
    ) = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;
};

// 
// Provides an inteface to an http request object.  The methods on this
// class can be used to inspect and modify request data.
// 
class IHttpRequest
{
 public:
    virtual
    HTTP_REQUEST *
    GetRawHttpRequest(
        VOID
    ) = 0;

    virtual
    const HTTP_REQUEST *
    GetRawHttpRequest(
        VOID
    ) const = 0;

    virtual
    PCSTR
    GetHeader(
        IN PCSTR                pszHeaderName,
        OUT USHORT *            pcchHeaderValue = NULL
    ) const = 0;

    virtual
    PCSTR
    GetHeader(
        IN  HTTP_HEADER_ID      ulHeaderIndex,
        OUT USHORT *            pcchHeaderValue = NULL
    ) const = 0;

    virtual
    HRESULT
    SetHeader(
        IN PCSTR                pszHeaderName,
        IN PCSTR                pszHeaderValue,
        IN USHORT               cchHeaderValue,
        IN BOOL                 fReplace
    ) = 0;

    virtual
    HRESULT
    SetHeader(
        IN HTTP_HEADER_ID       ulHeaderIndex,
        IN PCSTR                pszHeaderValue,
        IN USHORT               cchHeaderValue,
        IN BOOL                 fReplace
    ) = 0;

    virtual
    HRESULT
    DeleteHeader(
        IN PCSTR                pszHeaderName
    ) = 0;

    virtual
    HRESULT
    DeleteHeader(
        IN HTTP_HEADER_ID       ulHeaderIndex
    ) = 0;

    virtual
    PCSTR
    GetHttpMethod(
        VOID
    ) const = 0;

    virtual
    HRESULT
    SetHttpMethod(
        IN PCSTR                pszHttpMethod
    ) = 0;

    virtual
    HRESULT
    SetUrl(
        IN PCWSTR               pszUrl,
        IN DWORD                cchUrl,
        IN BOOL                 fResetQueryString
    ) = 0;

    virtual
    HRESULT
    SetUrl(
        IN PCSTR                pszUrl,
        IN DWORD                cchUrl,
        IN BOOL                 fResetQueryString
    ) = 0;

    virtual
    BOOL
    GetUrlChanged(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetForwardedUrl(
        VOID
    ) const = 0;

    virtual
    PSOCKADDR
    GetLocalAddress(
        VOID
    ) const = 0;

    virtual
    PSOCKADDR
    GetRemoteAddress(
        VOID
    ) const = 0;

    virtual
    HRESULT
    ReadEntityBody(
        OUT VOID *              pvBuffer,
        IN  DWORD               cbBuffer,
        IN  BOOL                fAsync,
        OUT DWORD *             pcbBytesReceived,
        OUT BOOL *              pfCompletionPending = NULL
    ) = 0;

    virtual
    HRESULT
    InsertEntityBody(
        IN VOID *               pvBuffer,
        IN DWORD                cbBuffer
    ) = 0;

    virtual
    DWORD
    GetRemainingEntityBytes(
        VOID
    ) = 0;

    virtual
    VOID
    GetHttpVersion(
        OUT USHORT *            pMajorVersion,
        OUT USHORT *            pMinorVersion
    ) const = 0;

    virtual
    HRESULT
    GetClientCertificate(
        OUT HTTP_SSL_CLIENT_CERT_INFO **    ppClientCertInfo,
        OUT BOOL *                          pfClientCertNegotiated
    ) = 0;

    virtual
    HRESULT
    NegotiateClientCertificate(
        IN BOOL                 fAsync,
        OUT BOOL *              pfCompletionPending = NULL
    ) = 0;

    virtual
    DWORD
    GetSiteId(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetHeaderChanges(
        IN      DWORD   dwOldChangeNumber,
        OUT     DWORD * pdwNewChangeNumber,
        IN OUT  PCSTR   knownHeaderSnapshot[HttpHeaderRequestMaximum],
        IN OUT  DWORD * pdwUnknownHeaderSnapShot,
        IN OUT  PCSTR **ppUnknownHeaderNameSnapShot,
        IN OUT  PCSTR **ppUnknownHeaderValueSnapShot,
        __out_ecount(HttpHeaderRequestMaximum+1)
                DWORD   diffedKnownHeaderIndices[HttpHeaderRequestMaximum+1],
        OUT     DWORD * pdwDiffedUnknownHeaders,
        OUT     DWORD **ppDiffedUnknownHeaderIndices
    ) = 0;
};

class IHttpCachePolicy
{
 public:
    virtual
    HTTP_CACHE_POLICY *
    GetKernelCachePolicy(
        VOID
    ) = 0;

    virtual
    VOID
    SetKernelCacheInvalidatorSet(
        VOID
    ) = 0;

    virtual
    HTTP_CACHE_POLICY *
    GetUserCachePolicy(
        VOID
    ) = 0;

    virtual
    HRESULT
    AppendVaryByHeader(
        PCSTR   pszHeader
    ) = 0;

    virtual
    PCSTR
    GetVaryByHeaders(
        VOID
    ) const = 0;

    virtual
    HRESULT
    AppendVaryByQueryString(
        PCSTR   pszParam
    ) = 0;

    virtual
    PCSTR
    GetVaryByQueryStrings(
        VOID
    ) const = 0;

    virtual
    HRESULT
    SetVaryByValue(
        PCSTR   pszValue
    ) = 0;

    virtual
    PCSTR
    GetVaryByValue(
        VOID
    ) const = 0;

    virtual
    BOOL
    IsUserCacheEnabled(
        VOID
    ) const = 0;

    virtual
    VOID
    DisableUserCache(
        VOID
    ) = 0;

    virtual
    BOOL
    IsCached(
        VOID
    ) const = 0;

    virtual
    VOID
    SetIsCached(
        VOID
    ) = 0;
};

// 
// Response descriptor
// 
class IHttpResponse
{
 public:
    virtual
    HTTP_RESPONSE *
    GetRawHttpResponse(
        VOID
    ) = 0;

    virtual
    const HTTP_RESPONSE *
    GetRawHttpResponse(
        VOID
    ) const = 0;

    virtual
    IHttpCachePolicy *
    GetCachePolicy(
        VOID
    ) = 0;

    virtual
    HRESULT
    SetStatus(
        IN USHORT                   statusCode,
        IN PCSTR                    pszReason,
        IN USHORT                   uSubStatus = 0,
        IN HRESULT                  hrErrorToReport = S_OK,
        IN IAppHostConfigException *pException = NULL,
        IN BOOL                     fTrySkipCustomErrors = FALSE
    ) = 0;

    virtual
    HRESULT
    SetHeader(
        IN PCSTR                pszHeaderName,
        IN PCSTR                pszHeaderValue,
        IN USHORT               cchHeaderValue,
        IN BOOL                 fReplace
    ) = 0;

    virtual
    HRESULT
    SetHeader(
        IN HTTP_HEADER_ID       ulHeaderIndex,
        IN PCSTR                pszHeaderValue,
        IN USHORT               cchHeaderValue,
        IN BOOL                 fReplace
    ) = 0;

    virtual
    HRESULT
    DeleteHeader(
        IN PCSTR                pszHeaderName
    ) = 0;

    virtual
    HRESULT
    DeleteHeader(
        IN HTTP_HEADER_ID       ulHeaderIndex
    ) = 0;

    virtual
    PCSTR
    GetHeader(
        IN PCSTR                pszHeaderName,
        OUT USHORT *            pcchHeaderValue = NULL
    ) const = 0;

    virtual
    PCSTR
    GetHeader(
        IN  HTTP_HEADER_ID      ulHeaderIndex,
        OUT USHORT *            pcchHeaderValue = NULL
    ) const = 0;

    virtual
    VOID
    Clear(
        VOID
    ) = 0;

    virtual
    VOID
    ClearHeaders(
        VOID
    ) = 0;

    virtual
    VOID
    SetNeedDisconnect(
        VOID
    ) = 0;

    virtual
    VOID
    ResetConnection(
        VOID
    ) = 0;

    virtual
    VOID
    DisableKernelCache(
        ULONG reason = 9
    ) = 0;

    virtual
    BOOL
    GetKernelCacheEnabled(
        VOID
    ) const = 0;

    virtual
    VOID
    SuppressHeaders(
        VOID
    ) = 0;

    virtual
    BOOL
    GetHeadersSuppressed(
        VOID
    ) const = 0;

    virtual
    HRESULT
    Flush(
        IN BOOL                 fAsync,
        IN BOOL                 fMoreData,
        OUT DWORD *             pcbSent,
        OUT BOOL *              pfCompletionExpected = NULL
    ) = 0;

    virtual
    HRESULT
    Redirect(
        IN PCSTR                pszUrl,
        IN BOOL                 fResetStatusCode = TRUE,
        IN BOOL                 fIncludeParameters = FALSE
    ) = 0;

    virtual
    HRESULT
    WriteEntityChunkByReference(
        IN HTTP_DATA_CHUNK *    pDataChunk,
        IN LONG                 lInsertPosition = -1
    ) = 0;

    virtual
    HRESULT
    WriteEntityChunks(
        IN  HTTP_DATA_CHUNK *   pDataChunks,
        IN  DWORD               nChunks,
        IN  BOOL                fAsync,
        IN  BOOL                fMoreData,
        OUT DWORD *             pcbSent,
        OUT BOOL *              pfCompletionExpected = NULL
    ) = 0;

    virtual
    VOID
    DisableBuffering(
        VOID
    ) = 0;

    virtual
    VOID
    GetStatus(
        OUT USHORT *                    pStatusCode,
        OUT USHORT *                    pSubStatus = NULL,
        OUT PCSTR *                     ppszReason = NULL,
        OUT USHORT *                    pcchReason = NULL,
        OUT HRESULT *                   phrErrorToReport = NULL,
        OUT PCWSTR *                    ppszModule = NULL,
        OUT DWORD *                     pdwNotification = NULL,
        OUT IAppHostConfigException **  ppException = NULL,
        OUT BOOL *                      pfTrySkipCustomErrors = NULL
    ) = 0;

    virtual
    HRESULT
    SetErrorDescription(
        IN PCWSTR                       pszDescription,
        IN DWORD                        cchDescription,
        IN BOOL                         fHtmlEncode = TRUE
    ) = 0;

    virtual
    PCWSTR
    GetErrorDescription(
        OUT DWORD *                     pcchDescription = NULL
    ) = 0;

    virtual
    HRESULT
    GetHeaderChanges(
        IN      DWORD   dwOldChangeNumber,
        OUT     DWORD * pdwNewChangeNumber,
        IN OUT  PCSTR   knownHeaderSnapshot[HttpHeaderResponseMaximum],
        IN OUT  DWORD * pdwUnknownHeaderSnapShot,
        IN OUT  PCSTR **ppUnknownHeaderNameSnapShot,
        IN OUT  PCSTR **ppUnknownHeaderValueSnapShot,
        __out_ecount(HttpHeaderResponseMaximum+1)
                DWORD   diffedKnownHeaderIndices[HttpHeaderResponseMaximum+1],
        OUT     DWORD * pdwDiffedUnknownHeaders,
        OUT     DWORD **ppDiffedUnknownHeaderIndices
    ) = 0;
};

// 
// User descriptor
// 
class IHttpUser
{
 public:
    virtual
    PCWSTR
    GetRemoteUserName(
        VOID
    ) = 0;

    virtual
    PCWSTR
    GetUserName(
        VOID
    ) = 0;

    virtual 
    PCWSTR
    GetAuthenticationType(
        VOID
    ) = 0;

    virtual
    PCWSTR
    GetPassword(
        VOID
    ) = 0;  

    virtual
    HANDLE
    GetImpersonationToken(
        VOID
    ) = 0;

    virtual
    HANDLE
    GetPrimaryToken(
        VOID
    ) = 0;

    virtual
    VOID
    ReferenceUser(
        VOID
    ) = 0;

    virtual
    VOID
    DereferenceUser(
        VOID
    ) = 0;

    virtual
    BOOL
    SupportsIsInRole(
        VOID
    ) = 0;

    virtual
    HRESULT
    IsInRole(
        IN  PCWSTR  pszRoleName,
        OUT BOOL *  pfInRole
    ) = 0;

    virtual
    PVOID
    GetUserVariable(
        IN PCSTR    pszVariableName
    ) = 0;
};

#define HTTP_USER_VARIABLE_SID      "SID"

// 
// Connection descriptor
// 
class IHttpConnection
{
 public:
    virtual
    BOOL
    IsConnected(
        VOID
    ) const = 0;

    virtual
    VOID *
    AllocateMemory(
        DWORD               cbAllocation
    ) = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;
};

// 
// Forward declarations
// 
class IHttpFileInfo;
class IHttpSite;
class ICustomNotificationProvider;
class IHttpEventProvider;
class CHttpModule;

//
// IHttpContext extended interface versions (no extended versions
// exist currently)
//
enum HTTP_CONTEXT_INTERFACE_VERSION
{
};

// 
// Context object representing the processing of an HTTP request
// 
class IHttpContext
{
 public:
    virtual
    IHttpSite *
    GetSite(
        VOID
    ) = 0;

    virtual
    IHttpApplication *
    GetApplication(
        VOID
    ) = 0;

    virtual
    IHttpConnection *
    GetConnection(
        VOID
    ) = 0;

    virtual
    IHttpRequest *
    GetRequest(
        VOID
    ) = 0;

    virtual
    IHttpResponse *
    GetResponse(
        VOID
    ) = 0;

    virtual
    BOOL
    GetResponseHeadersSent(
        VOID
    ) const = 0;

    virtual
    IHttpUser *
    GetUser(
        VOID
    ) const = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;

    virtual
    VOID
    IndicateCompletion(
        IN REQUEST_NOTIFICATION_STATUS     notificationStatus
    ) = 0;

    virtual
    HRESULT
    PostCompletion(
        IN DWORD                cbBytes
    ) = 0;

    virtual
    VOID
    DisableNotifications(
        IN DWORD                dwNotifications,
        IN DWORD                dwPostNotifications
    ) = 0;

    virtual
    BOOL
    GetNextNotification(
        IN  REQUEST_NOTIFICATION_STATUS status,
        OUT DWORD *                     pdwNotification,
        OUT BOOL *                      pfIsPostNotification,
        OUT CHttpModule **              ppModuleInfo,
        OUT IHttpEventProvider **       ppRequestOutput
    ) = 0;

    virtual
    BOOL
    GetIsLastNotification(
        IN  REQUEST_NOTIFICATION_STATUS status
    ) = 0;    

    virtual
    HRESULT
    ExecuteRequest(
        IN BOOL                 fAsync,
        IN IHttpContext *       pHttpContext,
        IN DWORD                dwExecuteFlags,
        IN IHttpUser *          pHttpUser,
        OUT BOOL *              pfCompletionExpected = NULL
    ) = 0;                      

    virtual
    DWORD
    GetExecuteFlags(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetServerVariable(
        PCSTR               pszVariableName,
        __deref_out_ecount(*pcchValueLength) PCWSTR * ppszValue,
        __out DWORD *       pcchValueLength
    ) = 0;

    virtual
    HRESULT
    GetServerVariable(
        PCSTR               pszVariableName,
        __deref_out_ecount(*pcchValueLength) PCSTR * ppszValue,
        __out DWORD *       pcchValueLength
    ) = 0;

    virtual
    HRESULT
    SetServerVariable(
        PCSTR               pszVariableName,
        PCWSTR              pszVariableValue
    ) = 0;

    virtual
    VOID *
    AllocateRequestMemory(
        IN DWORD                cbAllocation
    ) = 0;

    virtual
    IHttpUrlInfo *
    GetUrlInfo(
        VOID
    ) = 0;

    virtual
    IMetadataInfo *
    GetMetadata(
        VOID
    ) = 0;

    virtual
    PCWSTR
    GetPhysicalPath(
        OUT DWORD *         pcchPhysicalPath = NULL
    ) = 0;

    virtual
    PCWSTR
    GetScriptName(
        OUT DWORD *         pcchScriptName = NULL
    ) const = 0;

    virtual
    PCWSTR
    GetScriptTranslated(
        OUT DWORD *         pcchScriptTranslated = NULL
    ) = 0;

    virtual
    IScriptMapInfo *
    GetScriptMap(
        VOID
    ) const = 0;

    virtual
    VOID
    SetRequestHandled(
        VOID
    ) = 0;

    virtual
    IHttpFileInfo *
    GetFileInfo(
        VOID
    ) const = 0;

    virtual
    HRESULT
    MapPath(
                                           PCWSTR   pszUrl,
        __out_bcount_opt(*pcbPhysicalPath) PWSTR    pszPhysicalPath,
                                    IN OUT DWORD *  pcbPhysicalPath
    ) = 0;

    virtual
    HRESULT
    NotifyCustomNotification(
        ICustomNotificationProvider *   pCustomOutput,
        OUT BOOL *                      pfCompletionExpected
    ) = 0;

    virtual
    IHttpContext *
    GetParentContext(
        VOID
    ) const = 0;

    virtual
    IHttpContext *
    GetRootContext(
        VOID
    ) const = 0;

    virtual
    HRESULT
    CloneContext(
        IN DWORD                dwCloneFlags,
        OUT IHttpContext **     ppHttpContext
    ) = 0;

    virtual
    HRESULT
    ReleaseClonedContext(
        VOID
    ) = 0;

    virtual
    HRESULT
    GetCurrentExecutionStats(
        OUT DWORD * pdwNotification,
        OUT DWORD * pdwNotificationStartTickCount = NULL,
        OUT PCWSTR *  ppszModule = NULL,
        OUT DWORD * pdwModuleStartTickCount = NULL,
        OUT DWORD * pdwAsyncNotification = NULL,
        OUT DWORD * pdwAsyncNotificationStartTickCount = NULL
    ) const = 0;

    virtual
    IHttpTraceContext *
    GetTraceContext(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetServerVarChanges(
        IN      DWORD       dwOldChangeNumber,
        OUT     DWORD *     pdwNewChangeNumber,
        IN OUT  DWORD *     pdwVariableSnapShot,
        IN OUT  PCSTR **    ppVariableNameSnapShot,
        IN OUT  PCWSTR **   ppVariableValueSnapShot,
        OUT     DWORD *     pdwDiffedVariables,
        OUT     DWORD **    ppDiffedVariableIndices
    ) = 0;

    virtual
    HRESULT
    CancelIo(
        VOID
    ) = 0;

    virtual
    HRESULT
    MapHandler(
        IN      DWORD               dwSiteId,
        IN      PCWSTR              pszSiteName,
        IN      PCWSTR              pszUrl,
        IN      PCSTR               pszVerb,
        OUT     IScriptMapInfo **   ppScriptMap,
        IN      BOOL                fIgnoreWildcardMappings = FALSE
    ) = 0;

    virtual
    HRESULT
    GetExtendedInterface(
        IN  HTTP_CONTEXT_INTERFACE_VERSION  version,
        OUT PVOID *                         ppInterface
    ) = 0;
};


class IHttpTraceContext
{
public:
    virtual
    HRESULT
    GetTraceConfiguration(
        IN OUT HTTP_TRACE_CONFIGURATION *  pHttpTraceConfiguration
    ) = 0;
    
    virtual    
    HRESULT
    SetTraceConfiguration(
        IN HTTP_MODULE_ID              moduleId,
        IN HTTP_TRACE_CONFIGURATION *  pHttpTraceConfiguration,
        IN DWORD                       cHttpTraceConfiguration = 1
    ) = 0;

    virtual
    HRESULT
    RaiseTraceEvent(
        IN HTTP_TRACE_EVENT * pTraceEvent 
    ) = 0;

    virtual
    LPCGUID
    GetTraceActivityId(
    ) = 0;
};

class IHttpCacheSpecificData;

//
// Cache helpers
//

class IHttpCacheKey
{
 public:
    virtual
    DWORD
    GetHash(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetCacheName(
        VOID
    ) const = 0;

    virtual
    bool
    GetIsEqual(
        IHttpCacheKey *         pCacheCompareKey
    ) const = 0;

    virtual
    bool
    GetIsPrefix(
        IHttpCacheKey *         pCacheCompareKey
    ) const = 0;

    virtual
    VOID
    Enum(
        IHttpCacheSpecificData *
    ) = 0;
};

class IHttpCacheSpecificData
{
 public:
    virtual
    IHttpCacheKey *
    GetCacheKey(
        VOID
    ) const = 0;

    virtual
    VOID
    ReferenceCacheData(
        VOID
    ) = 0;

    virtual
    VOID
    DereferenceCacheData(
        VOID
    ) = 0;

    virtual
    VOID
    ResetTTL(
        VOID
    ) = 0;

    virtual
    VOID
    DecrementTTL(
        OUT BOOL    *pfTTLExpired
    ) = 0;

    virtual
    VOID
    SetFlushed(
        VOID
    ) = 0;

    virtual
    BOOL
    GetFlushed(
        VOID
    ) const = 0;
};

// 
// Site descriptor
// 
class IHttpSite
{
 public:
    virtual
    DWORD
    GetSiteId(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetSiteName(
        VOID
    ) const = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;

    virtual
    IHttpPerfCounterInfo *
    GetPerfCounterInfo(
        VOID
    ) = 0;
};

//
// File change monitor
//
//
class IHttpFileMonitor
{
 public:
    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;

    virtual
    VOID
    DereferenceFileMonitor(
        VOID
    ) = 0;
};

//
// File descriptor
// 
// 
class IHttpFileInfo : public IHttpCacheSpecificData
{
 public:
    virtual
    DWORD
    GetAttributes(
        VOID
    ) const = 0;

    virtual
    VOID
    GetSize(
        OUT ULARGE_INTEGER *        pliSize
    ) const = 0;

    virtual
    const BYTE *
    GetFileBuffer(
        VOID
    ) const = 0;

    virtual
    HANDLE
    GetFileHandle(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetFilePath(
        VOID
    ) const = 0;

    virtual
    PCSTR
    GetETag(
        OUT USHORT *                pcchETag = NULL
    ) const = 0;

    virtual
    VOID
    GetLastModifiedTime(
        OUT FILETIME *              pFileTime
    ) const = 0;

    virtual
    PCSTR
    GetLastModifiedString(
        VOID
    ) const = 0;

    virtual
    BOOL
    GetHttpCacheAllowed(
        OUT DWORD *     pSecondsToLive
    ) const = 0;

    virtual
    HRESULT
    AccessCheck(
        IN HANDLE                   hUserToken,
        IN PSID                     pUserSid
    ) = 0;

    virtual
    HANDLE
    GetVrToken(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetVrPath(
        VOID
    ) const = 0;

    virtual
    IHttpModuleContextContainer *
    GetModuleContextContainer(
        VOID
    ) = 0;

    virtual
    BOOL
    CheckIfFileHasChanged(
        IN HANDLE                   hUserToken
    ) = 0;
};


// 
// Token-cache entry
// 
class IHttpTokenEntry : public IHttpCacheSpecificData
{
 public:
    virtual
    HANDLE
    GetImpersonationToken(
        VOID
    ) = 0;

    virtual
    HANDLE
    GetPrimaryToken(
        VOID
    ) = 0;

    virtual
    PSID
    GetSid(
        VOID
    ) = 0;
};


//
// IHttpServer extended interface versions (no extended versions
// exist currently)
//
enum HTTP_SERVER_INTERFACE_VERSION
{
};


//
// Global utility descriptor
//
class IHttpServer
{
 public:
    virtual
    BOOL
    IsCommandLineLaunch(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetAppPoolName(
        VOID
    ) const = 0;

    virtual
    HRESULT
    AssociateWithThreadPool(
        IN HANDLE                              hHandle,
        IN LPOVERLAPPED_COMPLETION_ROUTINE     completionRoutine
    ) = 0;

    virtual
    VOID
    IncrementThreadCount(
        VOID
    ) = 0;

    virtual
    VOID
    DecrementThreadCount(
        VOID
    ) = 0;

    virtual
    VOID
    ReportUnhealthy(
        IN PCWSTR               pszReasonString,
        IN HRESULT              hrReason
    ) = 0;

    virtual
    VOID
    RecycleProcess(
        PCWSTR                  pszReason
    ) = 0;

    virtual
    IAppHostAdminManager *
    GetAdminManager(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetFileInfo(
        IN  PCWSTR               pszPhysicalPath,
        IN  HANDLE               hUserToken,
        IN  PSID                 pSid,
        IN  PCWSTR               pszChangeNotificationPath,
        IN  HANDLE               hChangeNotificationToken,
        IN  BOOL                 fCache,
        OUT IHttpFileInfo **     ppFileInfo,
        IN  IHttpTraceContext *  pHttpTraceContext = NULL
    ) = 0;

    virtual
    HRESULT
    FlushKernelCache(
        IN PCWSTR               pszUrl
    ) = 0;

    virtual
    HRESULT
    DoCacheOperation(
        IN CACHE_OPERATION              cacheOperation,
        IN IHttpCacheKey *              pCacheKey,
        OUT IHttpCacheSpecificData **   ppCacheSpecificData,
        IN  IHttpTraceContext *         pHttpTraceContext = NULL
    ) = 0;

    virtual
    GLOBAL_NOTIFICATION_STATUS
    NotifyCustomNotification(
        ICustomNotificationProvider * pCustomOutput
    ) = 0;

    virtual
    IHttpPerfCounterInfo *
    GetPerfCounterInfo(
        VOID
    ) = 0;

    virtual
    VOID
    RecycleApplication(
        PCWSTR                  pszAppConfigPath
    ) = 0;

    virtual
    VOID
    NotifyConfigurationChange(
        PCWSTR                  pszPath
    ) = 0;

    virtual
    VOID
    NotifyFileChange(
        PCWSTR                  pszFileName
    ) = 0;

    virtual
    IDispensedHttpModuleContextContainer *
    DispenseContainer(
        VOID
    ) = 0;

    virtual
    HRESULT
    AddFragmentToCache(
        IN HTTP_DATA_CHUNK *    pDataChunk,
        PCWSTR                  pszFragmentName
    ) = 0;

    virtual
    HRESULT
    ReadFragmentFromCache(
        PCWSTR          pszFragmentName,
        OUT BYTE *      pvBuffer,
        DWORD           cbSize,
        OUT DWORD *     pcbCopied
    ) = 0;

    virtual
    HRESULT
    RemoveFragmentFromCache(
        PCWSTR          pszFragmentName
    ) = 0;

    virtual
    HRESULT
    GetWorkerProcessSettings(
        OUT IWpfSettings ** ppWorkerProcessSettings
    ) = 0;

    virtual
    HRESULT
    GetProtocolManagerCustomInterface(
        IN PCWSTR       pProtocolManagerDll,
        IN PCWSTR       pProtocolManagerDllInitFunction,
        IN DWORD        dwCustomInterfaceId,
        OUT PVOID*      ppCustomInterface
    ) = 0;

    virtual
    BOOL
    SatisfiesPrecondition(
        PCWSTR          pszPrecondition,
        BOOL *          pfUnknownPrecondition = NULL
    ) const = 0;

    virtual
    IHttpTraceContext *
    GetTraceContext(
        VOID
    ) const = 0;

    virtual
    HRESULT
    RegisterFileChangeMonitor(
        PCWSTR                  pszPath,
        HANDLE                  hToken,
        IHttpFileMonitor **     ppFileMonitor
    ) = 0;

    virtual
    HRESULT
    GetExtendedInterface(
        IN  HTTP_SERVER_INTERFACE_VERSION   version,
        OUT PVOID *                         ppInterface
    ) = 0;
};

//
// Notification specific output for notifications
//
class IHttpEventProvider
{
 public:
    virtual
    VOID
    SetErrorStatus(
        HRESULT             hrError
    ) = 0;

};

//
// Completion information for notifications
//
class IHttpCompletionInfo
{
 public:
    virtual
    DWORD
    GetCompletionBytes(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetCompletionStatus(
        VOID
    ) const = 0;
};


//
// RQ_ and GL_ CUSTOM_NOTIFICATION outputs
//

class ICustomNotificationProvider : public IHttpEventProvider
{
 public:
    virtual
    PCWSTR
    QueryNotificationType(
        VOID
    ) = 0;
};

//
// RQ_REQUEST_AUTHENTICATE descriptor
//
class IAuthenticationProvider : public IHttpEventProvider
{
 public:
    virtual
    VOID
    SetUser(
        IN IHttpUser *          pUser
    ) = 0;
};

//
// RQ_MAP_REQUEST_HANDLER
//
class IMapHandlerProvider : public IHttpEventProvider
{
 public:
    virtual
    HRESULT
    SetScriptName(
        PCWSTR                  pszScriptName,
        DWORD                   cchScriptName
    ) = 0;

    virtual
    VOID
    SetScriptMap(
        IN IScriptMapInfo *     pScriptMap
    ) = 0;

    virtual
    VOID
    SetFileInfo(
        IN IHttpFileInfo *      pFileInfo
    ) = 0;
};

//
// RQ_MAP_PATH
//
class IMapPathProvider : public IHttpEventProvider
{
 public:
    virtual
    PCWSTR
    GetUrl(
    ) const = 0;

    virtual
    PCWSTR
    GetPhysicalPath(
    ) const = 0;

    virtual
    HRESULT
    SetPhysicalPath(
        PCWSTR pszPhysicalPath,
        DWORD  cchPhysicalPath
    ) = 0;
};


//
// RQ_SEND_RESPONSE
//
class ISendResponseProvider : public IHttpEventProvider
{
 public:
    virtual
    BOOL
    GetHeadersBeingSent(
        VOID
    ) const = 0;

    virtual
    DWORD
    GetFlags(
        VOID
    ) const = 0;

    virtual
    VOID
    SetFlags(
        DWORD dwFlags
    ) = 0;

    virtual
    HTTP_LOG_DATA *
    GetLogData(
        VOID
    ) const = 0;

    virtual
    HRESULT
    SetLogData(
        IN HTTP_LOG_DATA *pLogData
    ) = 0;

    virtual
    BOOL
    GetReadyToLogData(
        VOID
    ) const = 0;
};

//
// RQ_READ_ENTITY
//
class IReadEntityProvider : public IHttpEventProvider
{
 public:
    virtual
    VOID
    GetEntity(
        OUT PVOID *             ppBuffer,
        OUT DWORD *             pcbData,
        OUT DWORD *             pcbBuffer
    ) = 0;

    virtual
    VOID
    SetEntity(
        IN PVOID            pBuffer,
        DWORD               cbData,
        DWORD               cbBuffer
    ) = 0;
};

//
// GL_PRE_BEGIN_REQUEST provider
//
class IPreBeginRequestProvider : public IHttpEventProvider
{
 public:
    virtual
    IHttpContext *
    GetHttpContext(
        VOID
    ) = 0;
};

//
// GL_APPLICATION_START provider
//
class IHttpApplicationProvider : public IHttpEventProvider
{
 public:
    virtual
    IHttpApplication *
    GetApplication(
        VOID
    ) = 0;
};

typedef IHttpApplicationProvider    IHttpApplicationStartProvider;

class IHttpModuleFactory;

//
// GL_APPLICATION_RESOLVE_MODULES provider
//
class IHttpApplicationResolveModulesProvider : public IHttpApplicationProvider
{
 public:
    virtual 
    HRESULT
    RegisterModule(
        IN HTTP_MODULE_ID       parentModuleId,
        IN IHttpModuleFactory * pModuleFactory,
        IN PCWSTR               pszModuleName,
        IN PCWSTR               pszModuleType,
        IN PCWSTR               pszModulePreCondition,
        IN DWORD                dwRequestNotifications,
        IN DWORD                dwPostRequestNotifications
    ) = 0;

    virtual
    HRESULT
    SetPriorityForRequestNotification(
        IN PCWSTR               pszModuleName,
        IN DWORD                dwRequestNotification,
        IN PCWSTR               pszPriorityAlias
    ) = 0;
};

//
// GL_APPLICATION_STOP provider
//
typedef IHttpApplicationProvider   IHttpApplicationStopProvider;

//
// GL_RSCA_QUERY provider
//
class IGlobalRSCAQueryProvider : public IHttpEventProvider
{
 public:
    virtual
    PCWSTR
    GetFunctionName(
        VOID
    ) const = 0;

    virtual
    PCWSTR
    GetFunctionParameters(
        VOID
    ) const = 0;

    virtual
    HRESULT
    GetOutputBuffer(
        DWORD       cbBuffer,
        OUT BYTE ** ppbBuffer
    ) = 0;

    virtual
    HRESULT
    ResizeOutputBuffer(
        DWORD          cbNewBuffer,
        DWORD          cbBytesToCopy,
        IN OUT BYTE ** ppbBuffer
    ) = 0;

    virtual
    VOID
    SetResult(
        DWORD       cbData,
        HRESULT     hr
    ) = 0;
};


//
// GL_STOP_LISTENING
//
class IGlobalStopListeningProvider : public IHttpEventProvider
{
 public:
    virtual
    BOOL
    DrainRequestsGracefully(
        VOID
    ) const = 0;
};

//
// GL_CACHE_OPERATION
//
class ICacheProvider : public IHttpEventProvider
{
 public:
    virtual
    CACHE_OPERATION
    GetCacheOperation(
        VOID
    ) const = 0;

    virtual
    IHttpCacheKey *
    GetCacheKey(
        VOID
    ) const = 0;

    virtual
    IHttpCacheSpecificData *
    GetCacheRecord(
        VOID
    ) const = 0;

    virtual
    VOID
    SetCacheRecord(
        IHttpCacheSpecificData *    pCacheRecord
    ) = 0;

    virtual
    IHttpTraceContext *
    GetTraceContext(
        VOID
    ) const = 0;
};

//
// GL_CONFIGURATION_CHANGE
//
class IGlobalConfigurationChangeProvider : public IHttpEventProvider
{
 public:
    virtual
    PCWSTR
    GetChangePath(
        VOID
    ) const = 0;
};

//
// GL_FILE_CHANGE
//
class IGlobalFileChangeProvider : public IHttpEventProvider
{
public:
    virtual
    PCWSTR
    GetFileName(
        VOID
    ) const = 0;

    virtual
    IHttpFileMonitor *
    GetFileMonitor(
        VOID
    ) = 0;
};


//
// GL_TRACE_EVENT
//
class IGlobalTraceEventProvider : public IHttpEventProvider
{
 public:
    virtual
    HRESULT
    GetTraceEvent(
        OUT HTTP_TRACE_EVENT ** ppTraceEvent
    ) = 0;

    virtual
    BOOL
    CheckSubscription(
        IN HTTP_MODULE_ID   ModuleId    
    ) = 0;     

    virtual
    HRESULT 
    GetCurrentHttpRequestContext(
        OUT IHttpContext ** ppHttpContext
    ) = 0;
};


//
// GL_THREAD_CLEANUP
//
class IGlobalThreadCleanupProvider : public IHttpEventProvider
{
public:
    virtual
    IHttpApplication *
    GetApplication(
        VOID
    ) = 0;
};


class CHttpModule
{
public:
    // RQ_BEGIN_REQUEST

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnBeginRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostBeginRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_AUTHENTICATE_REQUEST

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnAuthenticateRequest(
        IN IHttpContext *                       pHttpContext,
        IN IAuthenticationProvider *            pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostAuthenticateRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_AUTHORIZE_REQUEST

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnAuthorizeRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostAuthorizeRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_RESOLVE_REQUEST_CACHE

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnResolveRequestCache(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostResolveRequestCache(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_MAP_REQUEST_HANDLER

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnMapRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IMapHandlerProvider *                pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostMapRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_ACQUIRE_REQUEST_STATE

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnAcquireRequestState(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostAcquireRequestState(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_PRE_EXECUTE_REQUEST_HANDLER

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPreExecuteRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostPreExecuteRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_EXECUTE_REQUEST_HANDLER

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnExecuteRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostExecuteRequestHandler(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )    
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_RELEASE_REQUEST_STATE

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnReleaseRequestState(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostReleaseRequestState(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    // RQ_UPDATE_REQUEST_CACHE

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnUpdateRequestCache(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }


    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostUpdateRequestCache(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_LOG_REQUEST

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnLogRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostLogRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_END_REQUEST

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnEndRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return RQ_NOTIFICATION_CONTINUE;
    }

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnPostEndRequest(
        IN IHttpContext *                       pHttpContext,
        IN IHttpEventProvider *                 pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_SEND_RESPONSE

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnSendResponse(
        IN IHttpContext *                       pHttpContext,
        IN ISendResponseProvider *              pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_MAP_PATH

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnMapPath(
        IN IHttpContext *                       pHttpContext,
        IN IMapPathProvider *                   pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_READ_ENTITY

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnReadEntity(
        IN IHttpContext *                       pHttpContext,
        IN IReadEntityProvider *                pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // RQ_CUSTOM_NOTIFICATION

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnCustomRequestNotification(
        IN IHttpContext *                       pHttpContext,
        IN ICustomNotificationProvider *        pProvider
    )
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    // completion

    virtual 
    REQUEST_NOTIFICATION_STATUS
    OnAsyncCompletion(
        IN IHttpContext *                       pHttpContext,
        IN DWORD                                dwNotification,
        IN BOOL                                 fPostNotification,
        IN IHttpEventProvider *                 pProvider,
        IN IHttpCompletionInfo *                pCompletionInfo        
    )    
    {
        UNREFERENCED_PARAMETER( pHttpContext );
        UNREFERENCED_PARAMETER( dwNotification );
        UNREFERENCED_PARAMETER( fPostNotification );
        UNREFERENCED_PARAMETER( pProvider );
        UNREFERENCED_PARAMETER( pCompletionInfo );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CHttpModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();
        
        return RQ_NOTIFICATION_CONTINUE;
    }

    virtual
    VOID
    Dispose(
        VOID
    )
    {
        delete this;
    }

 protected:

    CHttpModule()
    {}

    virtual
    ~CHttpModule()
    {}
};

class CGlobalModule
{
 public:

    // GL_STOP_LISTENING 

    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalStopListening(
        IN IGlobalStopListeningProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_CACHE_CLEANUP
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalCacheCleanup(
        VOID
    )
    {
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_CACHE_OPERATION
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalCacheOperation(
        IN ICacheProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_HEALTH_CHECK
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalHealthCheck(
        VOID
    )
    {
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_CONFIGURATION_CHANGE
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalConfigurationChange(
        IN IGlobalConfigurationChangeProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_FILE_CHANGE 
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalFileChange(
        IN IGlobalFileChangeProvider *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_PRE_BEGIN_REQUEST 
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalPreBeginRequest(
        IN IPreBeginRequestProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_APPLICATION_START 
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalApplicationStart(
        IN IHttpApplicationStartProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_APPLICATION_RESOLVE_MODULES
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalApplicationResolveModules(
        IN IHttpApplicationResolveModulesProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_APPLICATION_STOP

    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalApplicationStop(
        IN IHttpApplicationStopProvider *   pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_RSCA_QUERY
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalRSCAQuery(
        IN IGlobalRSCAQueryProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_TRACE_EVENT
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalTraceEvent(
        IN IGlobalTraceEventProvider  *  pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    // GL_CUSTOM_NOTIFICATION
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalCustomNotification(
        IN ICustomNotificationProvider *    pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }

    virtual
    VOID
    Terminate(
        VOID
    ) = 0;

    // GL_THREAD_CLEANUP
    
    virtual 
    GLOBAL_NOTIFICATION_STATUS
    OnGlobalThreadCleanup(
        IN IGlobalThreadCleanupProvider *    pProvider
    )
    {
        UNREFERENCED_PARAMETER( pProvider );
        OutputDebugStringA(
            "This module subscribed to event "
            __FUNCTION__
            " but did not override the method in its CGlobalModule implementation."
            "  Please check the method signature to make sure it matches the corresponding method.\n");
        DebugBreak();

        return GL_NOTIFICATION_CONTINUE;
    }
};


class IModuleAllocator
{
 public:
    virtual
    VOID *
    AllocateMemory(
        IN DWORD                    cbAllocation
    ) = 0;
};


class IHttpModuleFactory
{
 public:
    virtual
    HRESULT
    GetHttpModule(
        OUT CHttpModule **          ppModule, 
        IN  IModuleAllocator *      pAllocator
    ) = 0;

    virtual
    VOID
    Terminate(
        VOID
    ) = 0;
};


//
// Register-module desriptor
//
class IHttpModuleRegistrationInfo
{
 public:
    virtual 
    PCWSTR 
    GetName(
        VOID
    ) const = 0;

    virtual 
    HTTP_MODULE_ID
    GetId(
        VOID
    ) const = 0;

    virtual 
    HRESULT
    SetRequestNotifications(
        IN IHttpModuleFactory * pModuleFactory,
        IN DWORD                dwRequestNotifications,
        IN DWORD                dwPostRequestNotifications
    ) = 0;

    virtual 
    HRESULT
    SetGlobalNotifications(
        IN CGlobalModule *      pGlobalModule,
        IN DWORD                dwGlobalNotifications
    ) = 0;

    virtual
    HRESULT
    SetPriorityForRequestNotification(
        IN DWORD                dwRequestNotification, 
        IN PCWSTR               pszPriority
    ) = 0;

    virtual
    HRESULT
    SetPriorityForGlobalNotification(
        IN DWORD                dwGlobalNotification, 
        IN PCWSTR               pszPriority
    ) = 0;
};


//
// Register Module entrypoint
// 

typedef
HRESULT
(WINAPI * PFN_REGISTERMODULE)(
    DWORD                           dwServerVersion,
    IHttpModuleRegistrationInfo *   pModuleInfo,
    IHttpServer *                   pGlobalInfo
);

#define MODULE_REGISTERMODULE   "RegisterModule"

#endif


