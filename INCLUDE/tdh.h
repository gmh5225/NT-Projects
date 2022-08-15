/*++

Copyright (c) Microsoft Corporation

Module Name:

    Tdh.h

Abstract:

    ETW Event payload parsing API && ETW trace providers browsing API


--*/

#ifndef __TDH_H__
#define __TDH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <evntrace.h>
#include <evntcons.h>

typedef ULONG  TDHSTATUS;
#define TDHAPI  TDHSTATUS __stdcall

#define TDHCACHE_LINE  8
#define TDHCACHE_ALIGN __declspec(align(TDHCACHE_LINE))

typedef TDHCACHE_ALIGN struct _EVENT_MAP_ENTRY {
    ULONG OutputOffset;
    union {
        ULONG Value;  // For ULONG value (valuemap and bitmap)
        ULONG InputOffset;  // For String value (patternmap or valuemap in WBEM)
    };
} EVENT_MAP_ENTRY;
typedef EVENT_MAP_ENTRY *PEVENT_MAP_ENTRY;

typedef enum _MAP_FLAGS {
    EVENTMAP_INFO_FLAG_MANIFEST_VALUEMAP = 0x1,
    EVENTMAP_INFO_FLAG_MANIFEST_BITMAP = 0x2,
    EVENTMAP_INFO_FLAG_MANIFEST_PATTERNMAP = 0x4,
    EVENTMAP_INFO_FLAG_WBEM_VALUEMAP = 0x8,
    EVENTMAP_INFO_FLAG_WBEM_BITMAP = 0x10,
    EVENTMAP_INFO_FLAG_WBEM_FLAG = 0x20,
    EVENTMAP_INFO_FLAG_WBEM_NO_MAP = 0x40
} MAP_FLAGS;

typedef enum _MAP_VALUETYPE {
    EVENTMAP_ENTRY_VALUETYPE_ULONG,
    EVENTMAP_ENTRY_VALUETYPE_STRING
}  MAP_VALUETYPE;

typedef TDHCACHE_ALIGN struct _EVENT_MAP_INFO {
    ULONG NameOffset;
    MAP_FLAGS Flag;
    ULONG EntryCount;
    union {
        MAP_VALUETYPE MapEntryValueType; 
        ULONG FormatStringOffset;
    };
    __field_ecount(EntryCount) EVENT_MAP_ENTRY MapEntryArray[ANYSIZE_ARRAY];
} EVENT_MAP_INFO;
typedef EVENT_MAP_INFO *PEVENT_MAP_INFO;

// Intypes and outtypes are defined in winmeta.xml

enum _TDH_IN_TYPE {
    TDH_INTYPE_NULL,
    TDH_INTYPE_UNICODESTRING,
    TDH_INTYPE_ANSISTRING,
    TDH_INTYPE_INT8,
    TDH_INTYPE_UINT8,
    TDH_INTYPE_INT16,
    TDH_INTYPE_UINT16,
    TDH_INTYPE_INT32,
    TDH_INTYPE_UINT32,
    TDH_INTYPE_INT64,
    TDH_INTYPE_UINT64,
    TDH_INTYPE_FLOAT,
    TDH_INTYPE_DOUBLE,
    TDH_INTYPE_BOOLEAN,
    TDH_INTYPE_BINARY,
    TDH_INTYPE_GUID,
    TDH_INTYPE_POINTER,
    TDH_INTYPE_FILETIME,
    TDH_INTYPE_SYSTEMTIME,
    TDH_INTYPE_SID, 
    TDH_INTYPE_HEXINT32,
    TDH_INTYPE_HEXINT64,  // end of winmeta intypes
    TDH_INTYPE_COUNTEDSTRING = 300, // start of TDH intypes for WBEM 
    TDH_INTYPE_COUNTEDANSISTRING,
    TDH_INTYPE_REVERSEDCOUNTEDSTRING,
    TDH_INTYPE_REVERSEDCOUNTEDANSISTRING,
    TDH_INTYPE_NONNULLTERMINATEDSTRING,
    TDH_INTYPE_NONNULLTERMINATEDANSISTRING,
    TDH_INTYPE_UNICODECHAR,
    TDH_INTYPE_ANSICHAR,
    TDH_INTYPE_SIZET,
    TDH_INTYPE_HEXDUMP,
    TDH_INTYPE_WBEMSID
};

enum _TDH_OUT_TYPE {
    TDH_OUTTYPE_NULL,
    TDH_OUTTYPE_STRING,
    TDH_OUTTYPE_DATETIME,
    TDH_OUTTYPE_BYTE,
    TDH_OUTTYPE_UNSIGNEDBYTE,
    TDH_OUTTYPE_SHORT,
    TDH_OUTTYPE_UNSIGNEDSHORT,
    TDH_OUTTYPE_INT,
    TDH_OUTTYPE_UNSIGNEDINT,
    TDH_OUTTYPE_LONG,
    TDH_OUTTYPE_UNSIGNEDLONG,
    TDH_OUTTYPE_FLOAT,
    TDH_OUTTYPE_DOUBLE,
    TDH_OUTTYPE_BOOLEAN,
    TDH_OUTTYPE_GUID,
    TDH_OUTTYPE_HEXBINARY,
    TDH_OUTTYPE_HEXINT8,
    TDH_OUTTYPE_HEXINT16,
    TDH_OUTTYPE_HEXINT32,
    TDH_OUTTYPE_HEXINT64,
    TDH_OUTTYPE_PID,
    TDH_OUTTYPE_TID,
    TDH_OUTTYPE_PORT,
    TDH_OUTTYPE_IPV4,
    TDH_OUTTYPE_IPV6,
    TDH_OUTTYPE_SOCKETADDRESS,
    TDH_OUTTYPE_CIMDATETIME,
    TDH_OUTTYPE_ETWTIME,
    TDH_OUTTYPE_XML, 
    TDH_OUTYTPE_ERRORCODE,  // end of winmeta outtypes
    TDH_OUTTYPE_REDUCEDSTRING = 300, // start of TDH outtypes for WBEM 
    TDH_OUTTYPE_NOPRINT 
};

typedef enum _PROPERTY_FLAGS
{
   PropertyStruct        = 0x1,      // type is struct.  
   PropertyParamLength   = 0x2,      // length field is index of param with length
   PropertyParamCount    = 0x4,      // count file is index of param with count 
   PropertyWBEMXmlFragment = 0x8,    // WBEM extension flag for property  
   PropertyParamFixedLength = 0x10   // length of the parameter is fixed.
} PROPERTY_FLAGS;

typedef TDHCACHE_ALIGN struct _EVENT_PROPERTY_INFO {
    PROPERTY_FLAGS Flags;
    ULONG NameOffset;
    union {
        struct _nonStructType {
            USHORT InType;
            USHORT OutType;
            ULONG MapNameOffset;
        } nonStructType;
        struct _structType {
            USHORT StructStartIndex;
            USHORT NumOfStructMembers;
            ULONG padding;
        } structType;
    };
    union {
        USHORT count;
        USHORT countPropertyIndex;
    };
    union {
        USHORT length;
        USHORT lengthPropertyIndex;
    };    
    ULONG Reserved;
} EVENT_PROPERTY_INFO;
typedef EVENT_PROPERTY_INFO *PEVENT_PROPERTY_INFO;

typedef enum _DECODING_SOURCE {
    DecodingSourceXMLFile,
    DecodingSourceWbem,
    DecodingSourceWPP
} DECODING_SOURCE;

// Copy from Binres.h
typedef enum _TEMPLATE_FLAGS
{
    TEMPLATE_EVENT_DATA = 1, // used when custom xml is not specified 
    TEMPLATE_USER_DATA = 2  // used when custom xml is specified 
} TEMPLATE_FLAGS;

typedef TDHCACHE_ALIGN struct _TRACE_EVENT_INFO {
    GUID ProviderGuid;
    GUID EventGuid;
    EVENT_DESCRIPTOR EventDescriptor; // Loghorn 128 bits event description
    DECODING_SOURCE DecodingSource;
    ULONG ProviderNameOffset;
    ULONG LevelNameOffset;
    ULONG ChannelNameOffset;
    ULONG KeywordsNameOffset;
    ULONG TaskNameOffset;
    ULONG OpcodeNameOffset;
    ULONG EventMessageOffset;
    ULONG ProviderMessageOffset;
    ULONG BinaryXMLOffset;
    ULONG BinaryXMLSize;
    ULONG ActivityIDNameOffset;
    ULONG RelatedActivityIDNameOffset;
    ULONG PropertyCount;
    ULONG TopLevelPropertyCount;
    TEMPLATE_FLAGS Flags;
    __field_ecount(PropertyCount) EVENT_PROPERTY_INFO EventPropertyInfoArray[ANYSIZE_ARRAY];
} TRACE_EVENT_INFO;
typedef TRACE_EVENT_INFO *PTRACE_EVENT_INFO;

typedef TDHCACHE_ALIGN struct _PROPERTY_DATA_DESCRIPTOR {
    ULONGLONG PropertyName;         // Pointer to property name
    ULONG ArrayIndex;                      //  Array Index
    ULONG Reserved;
} PROPERTY_DATA_DESCRIPTOR; 
typedef PROPERTY_DATA_DESCRIPTOR *PPROPERTY_DATA_DESCRIPTOR;

// Provider Enumeration

typedef enum _EVENT_FIELD_TYPE {
    EventKeywordInformation = 0,
    EventLevelInformation,
    EventChannelInformation,
    EventTaskInformation,
    EventOpcodeInformation,
    EventInformationMax
} EVENT_FIELD_TYPE;

typedef TDHCACHE_ALIGN struct _PROVIDER_FIELD_INFO {
    ULONG NameOffset; // English only
    ULONG DescriptionOffset; // Localization String
    ULONGLONG Value;
} PROVIDER_FIELD_INFO;  
typedef PROVIDER_FIELD_INFO *PPROVIDER_FIELD_INFO;

typedef TDHCACHE_ALIGN struct _PROVIDER_FIELD_INFOARRAY {
    ULONG NumberOfElements;
    EVENT_FIELD_TYPE FieldType;
    PROVIDER_FIELD_INFO FieldInfoArray[ANYSIZE_ARRAY];
} PROVIDER_FIELD_INFOARRAY;
typedef PROVIDER_FIELD_INFOARRAY *PPROVIDER_FIELD_INFOARRAY;

typedef TDHCACHE_ALIGN struct _TRACE_PROVIDER_INFO {
    GUID ProviderGuid;
    ULONG SchemaSource;
    ULONG ProviderNameOffset;
} TRACE_PROVIDER_INFO;
typedef TRACE_PROVIDER_INFO *PTRACE_PROVIDER_INFO;

typedef TDHCACHE_ALIGN struct _PROVIDER_ENUMERATION_INFO {
    ULONG NumberOfProviders;
    ULONG Padding; // for 8 bytes alignment
    __field_ecount(NumberOfProviders) TRACE_PROVIDER_INFO TraceProviderInfoArray[ANYSIZE_ARRAY];
} PROVIDER_ENUMERATION_INFO;
typedef PROVIDER_ENUMERATION_INFO *PPROVIDER_ENUMERATION_INFO;

typedef enum _TDH_CONTEXT_TYPE {
    TDH_CONTEXT_WPP_TMFFILE = 0,
    TDH_CONTEXT_WPP_TMFSEARCHPATH,
    TDH_CONTEXT_WPP_GMT,
    TDH_CONTEXT_POINTERSIZE,
    TDH_CONTEXT_MAXIMUM
} TDH_CONTEXT_TYPE;

typedef  TDHCACHE_ALIGN struct _TDH_CONTEXT {
    ULONGLONG ParameterValue;    // Pointer to Data                      
    TDH_CONTEXT_TYPE ParameterType;         
    ULONG ParameterSize;         
} TDH_CONTEXT;
typedef TDH_CONTEXT *PTDH_CONTEXT;

TDHAPI
TdhGetEventInformation(
    __in PEVENT_RECORD pEvent,
    __in ULONG TdhContextCount,
    __in_ecount_opt(TdhContextCount) PTDH_CONTEXT pTdhContext,
    __out_bcount_opt(*pBufferSize) PTRACE_EVENT_INFO pBuffer,
    __inout ULONG *pBufferSize
    );

TDHAPI
TdhGetEventMapInformation(
    __in PEVENT_RECORD pEvent,
    __in LPWSTR pMapName,
    __out_bcount_opt(*pBufferSize) PEVENT_MAP_INFO pBuffer,
    __inout ULONG *pBufferSize
    );

TDHAPI
TdhGetPropertySize(
    __in PEVENT_RECORD pEvent,
    __in ULONG TdhContextCount,
    __in_ecount_opt(TdhContextCount) PTDH_CONTEXT pTdhContext,
    __in ULONG PropertyDataCount,
    __in_ecount(PropertyDataCount) PPROPERTY_DATA_DESCRIPTOR pPropertyData,
    __out ULONG *pPropertySize
    );

TDHAPI
TdhGetProperty(
    __in PEVENT_RECORD pEvent,
    __in ULONG TdhContextCount,
    __in_ecount_opt(TdhContextCount) PTDH_CONTEXT pTdhContext,
    __in ULONG PropertyDataCount,
    __in_ecount(PropertyDataCount) PPROPERTY_DATA_DESCRIPTOR pPropertyData,
    __in ULONG BufferSize,
    __out_bcount(BufferSize) PBYTE pBuffer
    );

TDHAPI
TdhEnumerateProviders(
    __out_bcount_opt(*pBufferSize) PPROVIDER_ENUMERATION_INFO pBuffer,
    __inout ULONG *pBufferSize
    );

__success(return == ERROR_SUCCESS)
TDHAPI
TdhQueryProviderFieldInformation(
    __in LPGUID pGuid,
    __in ULONGLONG EventFieldValue,
    __in EVENT_FIELD_TYPE EventFieldType,
    __out_bcount_opt(*pBufferSize) PPROVIDER_FIELD_INFOARRAY pBuffer,
    __inout ULONG *pBufferSize
    );

TDHAPI
TdhEnumerateProviderFieldInformation(
    __in LPGUID pGuid,
    __in EVENT_FIELD_TYPE EventFieldType,
    __out_bcount_opt(*pBufferSize) PPROVIDER_FIELD_INFOARRAY pBuffer,
    __inout ULONG *pBufferSize
    );

#ifdef __cplusplus
}
#endif

#endif  // __TDH_H__


