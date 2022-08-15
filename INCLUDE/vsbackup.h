/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    vsbackup.h

Abstract:

    Declaration of backup interfaces.

--*/

#ifndef _VSBACKUP_H_
#define _VSBACKUP_H_


const IID IID_IVssExamineWriterMetadata      =   // 902fcf7f-b7fd-42f8-81f1-b2e400b1e5bd 
                     {
                     0x902fcf7f,
                     0xb7fd,
                     0x42f8,
                     {0x81, 0xf1, 0xb2, 0xe4, 0x00, 0xb1, 0xe5, 0xbd }
                     };


const IID IID_IVssExamineWriterMetadataEx  =  // 0c0e5ec0-ca44-472b-b702-e652db1c0451 
                    {
                    0x0c0e5ec0,
                    0xca44,
                    0x472b,
                    { 0xb7, 0x02, 0xe6, 0x52, 0xdb, 0x1c, 0x04, 0x51  }
                    };

const IID IID_IVssExamineWriterMetadataEx2 = // ce115780-a611-431b-b57f-c38303ab6aee
                    {
                    0xce115780,
                    0xa611,
                    0x431b,
                    { 0xb5, 0x7f, 0xc3, 0x83, 0x03, 0xab, 0x6a, 0xee }
                    };
                    
const IID IID_IVssBackupComponents            =  // 665c1d5f-c218-414d-a05d-7fef5f9d5c86 
                    {
                    0x665c1d5f,
                    0xc218,
                    0x414d,
                    { 0xa0, 0x5d, 0x7f, 0xef, 0x5f, 0x9d, 0x5c, 0x86 }
                    };

const IID IID_IVssBackupComponentsEx         = // 963f03ad-9e4c-4a34-ac15-e4b6174e5036 
                    {
                    0x963f03ad,
                    0x9e4c,
                    0x4a34,
                    { 0xac, 0x15, 0xe4, 0xb6, 0x17, 0x4e, 0x50, 0x36 }
                    };

const IID IID_IVssBackupComponentsEx2       = // acfe2b3a-22c9-4ef8-bd03-2f9ca230084e
                    {
                    0xacfe2b3a,
                    0x22c9,
                    0x4ef8,
                    { 0xbd, 0x03, 0x2f, 0x9c, 0xa2, 0x30, 0x08, 0x4e }
                    };
                    
// description of a component
typedef struct _VSS_COMPONENTINFO
    {
    VSS_COMPONENT_TYPE type;    // either VSS_CT_DATABASE or VSS_CT_FILEGROUP
    BSTR bstrLogicalPath;        // logical path to component
    BSTR bstrComponentName;        // component name
    BSTR bstrCaption;        // description of component
    BYTE *pbIcon;            // icon
    UINT cbIcon;            // icon
    bool bRestoreMetadata;        // whether component supplies restore metadata
    bool bNotifyOnBackupComplete;    // whether component needs to be informed if backup was successful
    bool bSelectable;        // is component selectable    
    bool bSelectableForRestore; // is component selectable for restore
    DWORD dwComponentFlags;    // extra attribute flags for the component
    UINT cFileCount;        // # of files in file group
    UINT cDatabases;        // # of database files
    UINT cLogFiles;            // # of log files
    UINT cDependencies;        // # of components that this component depends on
    } VSS_COMPONENTINFO;

typedef const VSS_COMPONENTINFO *PVSSCOMPONENTINFO;


// component information
class IVssWMComponent : public IUnknown
    {
public:
    // get component information
    STDMETHOD(GetComponentInfo)(PVSSCOMPONENTINFO *ppInfo) = 0;

    // free component information
    STDMETHOD(FreeComponentInfo)(PVSSCOMPONENTINFO pInfo) = 0;

    // obtain a specific file in a file group
    STDMETHOD(GetFile)
        (
        IN UINT iFile,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    // obtain a specific physical database file for a database
    STDMETHOD(GetDatabaseFile)
        (
        IN UINT iDBFile,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    // obtain a specific physical log file for a database
    STDMETHOD(GetDatabaseLogFile)
        (
        IN UINT iDbLogFile,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    STDMETHOD(GetDependency)
        (
        IN UINT iDependency,
        OUT IVssWMDependency **ppDependency
        ) = 0;
    };


// interface to examine writer metadata
class __declspec(uuid("902fcf7f-b7fd-42f8-81f1-b2e400b1e5bd")) IVssExamineWriterMetadata : public IUnknown
    {
public:
    // obtain identity of the writer
    STDMETHOD(GetIdentity)
        (
        OUT VSS_ID *pidInstance,
        OUT VSS_ID *pidWriter,
        OUT BSTR *pbstrWriterName,
        OUT VSS_USAGE_TYPE *pUsage,
        OUT VSS_SOURCE_TYPE *pSource
        ) = 0;

    // obtain number of include files, exclude files, and components
    STDMETHOD(GetFileCounts)
        (
        OUT UINT *pcIncludeFiles,
        OUT UINT *pcExcludeFiles,
        OUT UINT *pcComponents
        ) = 0;

    // obtain specific include files
    STDMETHOD(GetIncludeFile)
        (
        IN UINT iFile,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    // obtain specific exclude files
    STDMETHOD(GetExcludeFile)
        (
        IN UINT iFile,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    // obtain specific component
    STDMETHOD(GetComponent)
        (
        IN UINT iComponent,
        OUT IVssWMComponent **ppComponent
        ) = 0;

    // obtain restoration method
    STDMETHOD(GetRestoreMethod)
        (
        OUT VSS_RESTOREMETHOD_ENUM *pMethod,
        OUT BSTR *pbstrService,
        OUT BSTR *pbstrUserProcedure,
        OUT VSS_WRITERRESTORE_ENUM *pwriterRestore,
        OUT bool *pbRebootRequired,
        UINT *pcMappings
        ) = 0;

    // obtain a specific alternative location mapping
    STDMETHOD(GetAlternateLocationMapping)
        (
        IN UINT iMapping,
        OUT IVssWMFiledesc **ppFiledesc
        ) = 0;

    // get the backup schema
    STDMETHOD(GetBackupSchema)
        (
        OUT DWORD *pdwSchemaMask
        ) = 0;

    // obtain reference to actual XML document
    STDMETHOD(GetDocument)(IXMLDOMDocument **pDoc) = 0;

    // convert document to a XML string
    STDMETHOD(SaveAsXML)(BSTR *pbstrXML) = 0;

    // load document from an XML string
    STDMETHOD(LoadFromXML)(BSTR bstrXML) = 0;
    };

class __declspec(uuid("0c0e5ec0-ca44-472b-b702-e652db1c0451")) IVssExamineWriterMetadataEx : public IVssExamineWriterMetadata
        {
public:
        // obtain identity of the writer
        STDMETHOD(GetIdentityEx)
            (
              OUT VSS_ID *pidInstance,
              OUT VSS_ID *pidWriter,
              OUT BSTR *pbstrWriterName,
              OUT BSTR* pbstrInstanceName,
              OUT VSS_USAGE_TYPE *pUsage,
              OUT VSS_SOURCE_TYPE *pSource
              ) = 0;
        };

class __declspec(uuid("ce115780-a611-431b-b57f-c38303ab6aee")) IVssExamineWriterMetadataEx2 : public IVssExamineWriterMetadataEx
    {
public:
    STDMETHOD(GetVersion)
        (
        __out DWORD* pdwMajorVersion,
        __out DWORD* pdwMinorVersion
        ) = 0;
    STDMETHOD(GetExcludeFromSnapshotCount)
        (
        __out UINT* pcExcludedFromSnapshot
        ) = 0;
        
    // obtain specific exclude files
    STDMETHOD(GetExcludeFromSnapshotFile)
        (
        __in UINT iFile,
        __out IVssWMFiledesc **ppFiledesc
        ) = 0;        
    };

class IVssWriterComponentsExt :
    public IVssWriterComponents,
    public IUnknown
    {
    };


// backup components interface
class __declspec(uuid("665c1d5f-c218-414d-a05d-7fef5f9d5c86")) IVssBackupComponents : public IUnknown
    {
public:
    // get count of writer components
    STDMETHOD(GetWriterComponentsCount)(OUT UINT *pcComponents) = 0;

    // obtain a specific writer component
    STDMETHOD(GetWriterComponents)
        (
        IN UINT iWriter,
        OUT IVssWriterComponentsExt **ppWriter
        ) = 0;

    // initialize and create BACKUP_COMPONENTS document
    STDMETHOD(InitializeForBackup)(IN BSTR bstrXML = NULL) = 0;

    // set state describing backup
    STDMETHOD(SetBackupState)
        (
        IN bool bSelectComponents,
        IN bool bBackupBootableSystemState,
        IN VSS_BACKUP_TYPE backupType,
        IN bool bPartialFileSupport = false
        ) = 0;

    STDMETHOD(InitializeForRestore)(IN BSTR bstrXML) = 0;

       // set state describing restore
       STDMETHOD(SetRestoreState)
           (
           VSS_RESTORE_TYPE restoreType
           ) = 0;
           
    // gather writer metadata
    STDMETHOD(GatherWriterMetadata)
        (
        OUT IVssAsync **pAsync
        ) = 0;

    // get count of writers with metadata
    STDMETHOD(GetWriterMetadataCount)
        (
        OUT UINT *pcWriters
        ) = 0;

    // get writer metadata for a specific writer
    STDMETHOD(GetWriterMetadata)
        (
        IN UINT iWriter,
        OUT VSS_ID *pidInstance,
        OUT IVssExamineWriterMetadata **ppMetadata
        ) = 0;

    // free writer metadata
    STDMETHOD(FreeWriterMetadata)() = 0;

    // add a component to the BACKUP_COMPONENTS document
    STDMETHOD(AddComponent)
        (
        IN VSS_ID instanceId,
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName
        ) = 0;

    // dispatch PrepareForBackup event to writers
    STDMETHOD(PrepareForBackup)
        (
        OUT IVssAsync **ppAsync
        ) = 0;

    // abort the backup
    STDMETHOD(AbortBackup)() = 0;

    // dispatch the Identify event so writers can expose their metadata
    STDMETHOD(GatherWriterStatus)
        (
        OUT IVssAsync **pAsync
        ) = 0;


    // get count of writers with status
    STDMETHOD(GetWriterStatusCount)
        (
        OUT UINT *pcWriters
        ) = 0;

    STDMETHOD(FreeWriterStatus)() = 0;

    STDMETHOD(GetWriterStatus)
        (
        IN UINT iWriter,
        OUT VSS_ID *pidInstance,
        OUT VSS_ID *pidWriter,
        OUT BSTR *pbstrWriter,
        OUT VSS_WRITER_STATE *pnStatus,
        OUT HRESULT *phResultFailure
        ) = 0;

    // indicate whether backup succeeded on a component
    STDMETHOD(SetBackupSucceeded)
        (
        IN VSS_ID instanceId,
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN bool bSucceded
        ) = 0;

    // set backup options for the writer
    STDMETHOD(SetBackupOptions)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszBackupOptions
        ) = 0;

    // indicate that a given component is selected to be restored
    STDMETHOD(SetSelectedForRestore)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN bool bSelectedForRestore
        ) = 0;


    // set restore options for the writer
    STDMETHOD(SetRestoreOptions)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszRestoreOptions
        ) = 0;

    // indicate that additional restores will follow
    STDMETHOD(SetAdditionalRestores)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN bool bAdditionalRestores
        ) = 0;


    // set the backup stamp that the differential or incremental
    // backup is based on
    STDMETHOD(SetPreviousBackupStamp)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszPreviousBackupStamp
        ) = 0;



    // save BACKUP_COMPONENTS document as XML string
    STDMETHOD(SaveAsXML)(BSTR *pbstrXML) = 0;

    // signal BackupComplete event to the writers
    STDMETHOD(BackupComplete)(OUT IVssAsync **ppAsync) = 0;

    // add an alternate mapping on restore
    STDMETHOD(AddAlternativeLocationMapping)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE componentType,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszPath,
        IN LPCWSTR wszFilespec,
        IN bool bRecursive,
        IN LPCWSTR wszDestination
        ) = 0;

    // add a subcomponent to be restored
    STDMETHOD(AddRestoreSubcomponent)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE componentType,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszSubComponentLogicalPath,
        IN LPCWSTR wszSubComponentName,
        IN bool bRepair
        ) = 0;

    // requestor indicates whether files were successfully restored
    STDMETHOD(SetFileRestoreStatus)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN VSS_FILE_RESTORE_STATUS status
        ) = 0;

    // add a new location target for a file to be restored
    STDMETHOD(AddNewTarget)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN LPCWSTR wszPath,
        IN LPCWSTR wszFileName,    
        IN bool bRecursive,
        IN LPCWSTR wszAlternatePath
        ) = 0;

     // add a new location for the ranges file in case it was restored to
    // a different location
    STDMETHOD(SetRangesFilePath)
            (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,            
            IN UINT iPartialFile,
            IN LPCWSTR wszRangesFile
            ) = 0;

    // signal PreRestore event to the writers
    STDMETHOD(PreRestore)(OUT IVssAsync **ppAsync) = 0;

    // signal PostRestore event to the writers
    STDMETHOD(PostRestore)(OUT IVssAsync **ppAsync) = 0;

    // Called to set the context for subsequent snapshot-related operations
    STDMETHOD(SetContext)
        (
        IN LONG lContext
        ) = 0;
    
    // start a snapshot set
    STDMETHOD(StartSnapshotSet)
        (
        OUT VSS_ID *pSnapshotSetId
        ) = 0;

    // add a volume to a snapshot set
    STDMETHOD(AddToSnapshotSet)
        (                            
        IN VSS_PWSZ        pwszVolumeName,             
        IN VSS_ID        ProviderId,
        OUT VSS_ID        *pidSnapshot
        ) = 0;                                                

    // create the snapshot set
    STDMETHOD(DoSnapshotSet)
        (                                
        OUT IVssAsync**     ppAsync                     
        ) = 0;

       STDMETHOD(DeleteSnapshots)
        (                            
        IN VSS_ID        SourceObjectId,         
        IN VSS_OBJECT_TYPE     eSourceObjectType,        
        IN BOOL            bForceDelete,            
        IN LONG*        plDeletedSnapshots,        
        IN VSS_ID*        pNondeletedSnapshotID    
        ) = 0;

    STDMETHOD(ImportSnapshots)
        (
        OUT IVssAsync**        ppAsync
        ) = 0;

    STDMETHOD(BreakSnapshotSet)
        (
        IN VSS_ID            SnapshotSetId
        ) = 0;

    STDMETHOD(GetSnapshotProperties)
        (                                
        IN VSS_ID        SnapshotId,             
        OUT VSS_SNAPSHOT_PROP    *pProp
        ) = 0;                                                
        
    STDMETHOD(Query)
        (                                        
        IN VSS_ID        QueriedObjectId,        
        IN VSS_OBJECT_TYPE    eQueriedObjectType,     
        IN VSS_OBJECT_TYPE    eReturnedObjectsType,    
        IN IVssEnumObject     **ppEnum                 
        ) = 0;                                                
    
    STDMETHOD(IsVolumeSupported)
        (                                        
        IN VSS_ID ProviderId,        
        IN VSS_PWSZ pwszVolumeName,
        IN BOOL * pbSupportedByThisProvider
        ) = 0;

    STDMETHOD(DisableWriterClasses)
        (
        IN const VSS_ID *rgWriterClassId,
        IN UINT cClassId
        ) = 0;

    STDMETHOD(EnableWriterClasses)
        (
        IN const VSS_ID *rgWriterClassId,
        IN UINT cClassId
        ) = 0;

    STDMETHOD(DisableWriterInstances)
        (
        IN const VSS_ID *rgWriterInstanceId,
        IN UINT cInstanceId
        ) = 0;

    // called to expose a snapshot 
    STDMETHOD(ExposeSnapshot)
        (
        IN VSS_ID SnapshotId,
        IN VSS_PWSZ wszPathFromRoot,
        IN LONG lAttributes,
        IN VSS_PWSZ wszExpose,
        OUT VSS_PWSZ *pwszExposed
        ) = 0;

    STDMETHOD(RevertToSnapshot)
        (
        IN VSS_ID SnapshotId,
        IN BOOL bForceDismount
        ) = 0;

    STDMETHOD(QueryRevertStatus)
        (
        IN VSS_PWSZ pwszVolume,
        OUT IVssAsync **ppAsync
        ) = 0;
    
    };

class __declspec(uuid("963f03ad-9e4c-4a34-ac15-e4b6174e5036")) IVssBackupComponentsEx : public IVssBackupComponents
        {
public:
        // get writer metadata for a specific writer
        STDMETHOD(GetWriterMetadataEx)
            (
            IN UINT iWriter,
            OUT VSS_ID *pidInstance,
            OUT IVssExamineWriterMetadataEx **ppMetadata
            ) = 0;

    // indicate that a given component is selected to be restored
    STDMETHOD(SetSelectedForRestoreEx)
        (
        IN VSS_ID writerId,
        IN VSS_COMPONENT_TYPE ct,
        IN LPCWSTR wszLogicalPath,
        IN LPCWSTR wszComponentName,
        IN bool bSelectedForRestore,
        IN VSS_ID instanceId = GUID_NULL
        ) = 0;

        };

class __declspec(uuid("acfe2b3a-22c9-4ef8-bd03-2f9ca230084e")) IVssBackupComponentsEx2 : public IVssBackupComponentsEx
    {
public:
    STDMETHOD(UnexposeSnapshot)
        (
        __in VSS_ID snapshotId
        ) = 0;

    STDMETHOD(SetAuthoritativeRestore)
        (
        __in VSS_ID writerId, 
        __in VSS_COMPONENT_TYPE ct, 
        __in LPCWSTR wszLogicalPath, 
        __in LPCWSTR wszComponentName, 
        __in bool bAuth
        )= 0;

    STDMETHOD(SetRollForward)
        (
        __in VSS_ID writerId,
        __in VSS_COMPONENT_TYPE ct,
        __in LPCWSTR wszLogicalPath,
        __in LPCWSTR wszComponentName,
        __in VSS_ROLLFORWARD_TYPE rollType,
        __in LPCWSTR wszRollForwardPoint
        )= 0;

    STDMETHOD(SetRestoreName)
        (
        __in VSS_ID writerId,
        __in VSS_COMPONENT_TYPE ct,
        __in LPCWSTR wszLogicalPath,
        __in LPCWSTR wszComponentName,
        __in LPCWSTR wszRestoreName) = 0;

    STDMETHOD(BreakSnapshotSetEx)
        (
        __in VSS_ID SnapshotSetID,
        __in DWORD dwBreakFlags,
        __out IVssAsync** ppAsync) = 0;
 
    STDMETHOD(PreFastRecovery)
        (
        __in VSS_ID SnapshotSetID,
        __in DWORD dwPreFastRecoveryFlags,
        __out IVssAsync** ppAsync) = 0;
 
    STDMETHOD(FastRecovery)
        (
        __in VSS_ID SnapshotSetID,
        __in DWORD dwFastRecoveryFlags,
        __out IVssAsync** ppAsync) = 0;
 
    };

#define VSS_SW_BOOTABLE_STATE   (1 << 0)
    
extern "C"  {
HRESULT STDAPICALLTYPE CreateVssBackupComponentsInternal(
    __out IVssBackupComponents **ppBackup
    );

HRESULT STDAPICALLTYPE CreateVssExamineWriterMetadataInternal(
    __in BSTR bstrXML,
    __out IVssExamineWriterMetadata **ppMetadata
    );


HRESULT APIENTRY IsVolumeSnapshottedInternal(
    __in VSS_PWSZ  pwszVolumeName,
    __out BOOL    *pbSnapshotsPresent,
    __out LONG    *plSnapshotCapability
    );

/////////////////////////////////////////////////////////////////////
// Life-management methods for structure members 

void APIENTRY VssFreeSnapshotPropertiesInternal(
    __in VSS_SNAPSHOT_PROP*  pProp
    );


HRESULT APIENTRY GetProviderMgmtInterfaceInternal(
	__in VSS_ID ProviderId, 
	__in IID InterfaceId, 
	__out IUnknown** ppItf);

HRESULT APIENTRY ShouldBlockRevertInternal(
    __in LPCWSTR wszVolumeName, 
    __out bool* pbBlock
    );

}

inline HRESULT  CreateVssBackupComponents(
    __out IVssBackupComponents **ppBackup
    )
{
    return CreateVssBackupComponentsInternal(ppBackup);
}

inline HRESULT CreateVssExamineWriterMetadata (
    __in BSTR bstrXML,
    __out IVssExamineWriterMetadata **ppMetadata
    )
{
    return CreateVssExamineWriterMetadataInternal(bstrXML, ppMetadata);
}

inline HRESULT IsVolumeSnapshotted(
    __in VSS_PWSZ  pwszVolumeName,
    __out BOOL    *pbSnapshotsPresent,
    __out LONG    *plSnapshotCapability
    )
{
    return IsVolumeSnapshottedInternal(pwszVolumeName, pbSnapshotsPresent, plSnapshotCapability);
}

inline void VssFreeSnapshotProperties(
    __in VSS_SNAPSHOT_PROP* pProp
    )
{
    return VssFreeSnapshotPropertiesInternal(pProp);
}

inline HRESULT GetProviderMgmtInterface(
    __in VSS_ID ProviderId, 
    __in IID InterfaceId, 
    __out IUnknown** ppItf
    )
{
    return GetProviderMgmtInterfaceInternal(ProviderId, InterfaceId, ppItf);
}

inline HRESULT ShouldBlockRevert(
    __in LPCWSTR wszVolumeName, 
    __out bool* pbBlock)
{
    return ShouldBlockRevertInternal(wszVolumeName, pbBlock);
}

///
#endif // _VSBACKUP_H_

