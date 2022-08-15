

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for imapi2fs.idl:
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

#ifndef __imapi2fs_h__
#define __imapi2fs_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBootOptions_FWD_DEFINED__
#define __IBootOptions_FWD_DEFINED__
typedef interface IBootOptions IBootOptions;
#endif 	/* __IBootOptions_FWD_DEFINED__ */


#ifndef __IProgressItem_FWD_DEFINED__
#define __IProgressItem_FWD_DEFINED__
typedef interface IProgressItem IProgressItem;
#endif 	/* __IProgressItem_FWD_DEFINED__ */


#ifndef __IEnumProgressItems_FWD_DEFINED__
#define __IEnumProgressItems_FWD_DEFINED__
typedef interface IEnumProgressItems IEnumProgressItems;
#endif 	/* __IEnumProgressItems_FWD_DEFINED__ */


#ifndef __IProgressItems_FWD_DEFINED__
#define __IProgressItems_FWD_DEFINED__
typedef interface IProgressItems IProgressItems;
#endif 	/* __IProgressItems_FWD_DEFINED__ */


#ifndef __IFileSystemImageResult_FWD_DEFINED__
#define __IFileSystemImageResult_FWD_DEFINED__
typedef interface IFileSystemImageResult IFileSystemImageResult;
#endif 	/* __IFileSystemImageResult_FWD_DEFINED__ */


#ifndef __IFsiItem_FWD_DEFINED__
#define __IFsiItem_FWD_DEFINED__
typedef interface IFsiItem IFsiItem;
#endif 	/* __IFsiItem_FWD_DEFINED__ */


#ifndef __IEnumFsiItems_FWD_DEFINED__
#define __IEnumFsiItems_FWD_DEFINED__
typedef interface IEnumFsiItems IEnumFsiItems;
#endif 	/* __IEnumFsiItems_FWD_DEFINED__ */


#ifndef __IFsiFileItem_FWD_DEFINED__
#define __IFsiFileItem_FWD_DEFINED__
typedef interface IFsiFileItem IFsiFileItem;
#endif 	/* __IFsiFileItem_FWD_DEFINED__ */


#ifndef __IFsiDirectoryItem_FWD_DEFINED__
#define __IFsiDirectoryItem_FWD_DEFINED__
typedef interface IFsiDirectoryItem IFsiDirectoryItem;
#endif 	/* __IFsiDirectoryItem_FWD_DEFINED__ */


#ifndef __IFileSystemImage_FWD_DEFINED__
#define __IFileSystemImage_FWD_DEFINED__
typedef interface IFileSystemImage IFileSystemImage;
#endif 	/* __IFileSystemImage_FWD_DEFINED__ */


#ifndef __DFileSystemImageEvents_FWD_DEFINED__
#define __DFileSystemImageEvents_FWD_DEFINED__
typedef interface DFileSystemImageEvents DFileSystemImageEvents;
#endif 	/* __DFileSystemImageEvents_FWD_DEFINED__ */


#ifndef __DFileSystemImageEvents_FWD_DEFINED__
#define __DFileSystemImageEvents_FWD_DEFINED__
typedef interface DFileSystemImageEvents DFileSystemImageEvents;
#endif 	/* __DFileSystemImageEvents_FWD_DEFINED__ */


#ifndef __BootOptions_FWD_DEFINED__
#define __BootOptions_FWD_DEFINED__

#ifdef __cplusplus
typedef class BootOptions BootOptions;
#else
typedef struct BootOptions BootOptions;
#endif /* __cplusplus */

#endif 	/* __BootOptions_FWD_DEFINED__ */


#ifndef __FsiStream_FWD_DEFINED__
#define __FsiStream_FWD_DEFINED__

#ifdef __cplusplus
typedef class FsiStream FsiStream;
#else
typedef struct FsiStream FsiStream;
#endif /* __cplusplus */

#endif 	/* __FsiStream_FWD_DEFINED__ */


#ifndef __FileSystemImageResult_FWD_DEFINED__
#define __FileSystemImageResult_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileSystemImageResult FileSystemImageResult;
#else
typedef struct FileSystemImageResult FileSystemImageResult;
#endif /* __cplusplus */

#endif 	/* __FileSystemImageResult_FWD_DEFINED__ */


#ifndef __ProgressItem_FWD_DEFINED__
#define __ProgressItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProgressItem ProgressItem;
#else
typedef struct ProgressItem ProgressItem;
#endif /* __cplusplus */

#endif 	/* __ProgressItem_FWD_DEFINED__ */


#ifndef __EnumProgressItems_FWD_DEFINED__
#define __EnumProgressItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumProgressItems EnumProgressItems;
#else
typedef struct EnumProgressItems EnumProgressItems;
#endif /* __cplusplus */

#endif 	/* __EnumProgressItems_FWD_DEFINED__ */


#ifndef __ProgressItems_FWD_DEFINED__
#define __ProgressItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class ProgressItems ProgressItems;
#else
typedef struct ProgressItems ProgressItems;
#endif /* __cplusplus */

#endif 	/* __ProgressItems_FWD_DEFINED__ */


#ifndef __FsiDirectoryItem_FWD_DEFINED__
#define __FsiDirectoryItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class FsiDirectoryItem FsiDirectoryItem;
#else
typedef struct FsiDirectoryItem FsiDirectoryItem;
#endif /* __cplusplus */

#endif 	/* __FsiDirectoryItem_FWD_DEFINED__ */


#ifndef __FsiFileItem_FWD_DEFINED__
#define __FsiFileItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class FsiFileItem FsiFileItem;
#else
typedef struct FsiFileItem FsiFileItem;
#endif /* __cplusplus */

#endif 	/* __FsiFileItem_FWD_DEFINED__ */


#ifndef __EnumFsiItems_FWD_DEFINED__
#define __EnumFsiItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumFsiItems EnumFsiItems;
#else
typedef struct EnumFsiItems EnumFsiItems;
#endif /* __cplusplus */

#endif 	/* __EnumFsiItems_FWD_DEFINED__ */


#ifndef __MsftFileSystemImage_FWD_DEFINED__
#define __MsftFileSystemImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class MsftFileSystemImage MsftFileSystemImage;
#else
typedef struct MsftFileSystemImage MsftFileSystemImage;
#endif /* __cplusplus */

#endif 	/* __MsftFileSystemImage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "imapi2.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_imapi2fs_0000_0000 */
/* [local] */ 

typedef /* [helpstring][public][v1_enum] */ 
enum FsiItemType
    {	FsiItemNotFound	= 0,
	FsiItemDirectory	= 1,
	FsiItemFile	= 2
    } 	FsiItemType;

typedef /* [helpstring][public][v1_enum] */ 
enum FsiFileSystems
    {	FsiFileSystemNone	= 0,
	FsiFileSystemISO9660	= 1,
	FsiFileSystemJoliet	= 2,
	FsiFileSystemUDF	= 4,
	FsiFileSystemUnknown	= 0x40000000
    } 	FsiFileSystems;

typedef /* [helpstring][public][v1_enum] */ 
enum EmulationType
    {	EmulationNone	= 0,
	Emulation12MFloppy	= 1,
	Emulation144MFloppy	= 2,
	Emulation288MFloppy	= 3,
	EmulationHardDisk	= 4
    } 	EmulationType;

typedef /* [helpstring][public][v1_enum] */ 
enum PlatformId
    {	PlatformX86	= 0,
	PlatformPowerPC	= 1,
	PlatformMac	= 2
    } 	PlatformId;



extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0000_v0_0_s_ifspec;

#ifndef __IBootOptions_INTERFACE_DEFINED__
#define __IBootOptions_INTERFACE_DEFINED__

/* interface IBootOptions */
/* [helpstring][uuid][oleautomation][nonextensible][dual][unique][object] */ 


EXTERN_C const IID IID_IBootOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD4-975B-59BE-A960-9A2A262853A5")
    IBootOptions : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BootImage( 
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Manufacturer( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Manufacturer( 
            /* [in] */ __RPC__in BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlatformId( 
            /* [retval][out] */ __RPC__out PlatformId *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlatformId( 
            /* [in] */ PlatformId newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Emulation( 
            /* [retval][out] */ __RPC__out EmulationType *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Emulation( 
            /* [in] */ EmulationType newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageSize( 
            /* [retval][out] */ __RPC__out ULONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AssignBootImage( 
            /* [in] */ __RPC__in_opt IStream *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBootOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBootOptions * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBootOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBootOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBootOptions * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBootOptions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBootOptions * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBootOptions * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BootImage )( 
            IBootOptions * This,
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Manufacturer )( 
            IBootOptions * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Manufacturer )( 
            IBootOptions * This,
            /* [in] */ __RPC__in BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformId )( 
            IBootOptions * This,
            /* [retval][out] */ __RPC__out PlatformId *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformId )( 
            IBootOptions * This,
            /* [in] */ PlatformId newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Emulation )( 
            IBootOptions * This,
            /* [retval][out] */ __RPC__out EmulationType *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Emulation )( 
            IBootOptions * This,
            /* [in] */ EmulationType newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageSize )( 
            IBootOptions * This,
            /* [retval][out] */ __RPC__out ULONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AssignBootImage )( 
            IBootOptions * This,
            /* [in] */ __RPC__in_opt IStream *newVal);
        
        END_INTERFACE
    } IBootOptionsVtbl;

    interface IBootOptions
    {
        CONST_VTBL struct IBootOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBootOptions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBootOptions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBootOptions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBootOptions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBootOptions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBootOptions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBootOptions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBootOptions_get_BootImage(This,pVal)	\
    ( (This)->lpVtbl -> get_BootImage(This,pVal) ) 

#define IBootOptions_get_Manufacturer(This,pVal)	\
    ( (This)->lpVtbl -> get_Manufacturer(This,pVal) ) 

#define IBootOptions_put_Manufacturer(This,newVal)	\
    ( (This)->lpVtbl -> put_Manufacturer(This,newVal) ) 

#define IBootOptions_get_PlatformId(This,pVal)	\
    ( (This)->lpVtbl -> get_PlatformId(This,pVal) ) 

#define IBootOptions_put_PlatformId(This,newVal)	\
    ( (This)->lpVtbl -> put_PlatformId(This,newVal) ) 

#define IBootOptions_get_Emulation(This,pVal)	\
    ( (This)->lpVtbl -> get_Emulation(This,pVal) ) 

#define IBootOptions_put_Emulation(This,newVal)	\
    ( (This)->lpVtbl -> put_Emulation(This,newVal) ) 

#define IBootOptions_get_ImageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageSize(This,pVal) ) 

#define IBootOptions_AssignBootImage(This,newVal)	\
    ( (This)->lpVtbl -> AssignBootImage(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBootOptions_INTERFACE_DEFINED__ */


#ifndef __IProgressItem_INTERFACE_DEFINED__
#define __IProgressItem_INTERFACE_DEFINED__

/* interface IProgressItem */
/* [helpstring][uuid][oleautomation][nonextensible][dual][unique][object] */ 


EXTERN_C const IID IID_IProgressItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD5-975B-59BE-A960-9A2A262853A5")
    IProgressItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *desc) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstBlock( 
            /* [retval][out] */ __RPC__out ULONG *block) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastBlock( 
            /* [retval][out] */ __RPC__out ULONG *block) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockCount( 
            /* [retval][out] */ __RPC__out ULONG *blocks) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProgressItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProgressItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProgressItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProgressItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProgressItem * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProgressItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProgressItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProgressItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IProgressItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *desc);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstBlock )( 
            IProgressItem * This,
            /* [retval][out] */ __RPC__out ULONG *block);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastBlock )( 
            IProgressItem * This,
            /* [retval][out] */ __RPC__out ULONG *block);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockCount )( 
            IProgressItem * This,
            /* [retval][out] */ __RPC__out ULONG *blocks);
        
        END_INTERFACE
    } IProgressItemVtbl;

    interface IProgressItem
    {
        CONST_VTBL struct IProgressItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProgressItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProgressItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProgressItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProgressItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProgressItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProgressItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProgressItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProgressItem_get_Description(This,desc)	\
    ( (This)->lpVtbl -> get_Description(This,desc) ) 

#define IProgressItem_get_FirstBlock(This,block)	\
    ( (This)->lpVtbl -> get_FirstBlock(This,block) ) 

#define IProgressItem_get_LastBlock(This,block)	\
    ( (This)->lpVtbl -> get_LastBlock(This,block) ) 

#define IProgressItem_get_BlockCount(This,blocks)	\
    ( (This)->lpVtbl -> get_BlockCount(This,blocks) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProgressItem_INTERFACE_DEFINED__ */


#ifndef __IEnumProgressItems_INTERFACE_DEFINED__
#define __IEnumProgressItems_INTERFACE_DEFINED__

/* interface IEnumProgressItems */
/* [helpstring][uuid][unique][object] */ 


EXTERN_C const IID IID_IEnumProgressItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD6-975B-59BE-A960-9A2A262853A5")
    IEnumProgressItems : public IUnknown
    {
    public:
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProgressItem **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumProgressItems **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumProgressItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumProgressItems * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumProgressItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumProgressItems * This);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumProgressItems * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IProgressItem **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumProgressItems * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumProgressItems * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumProgressItems * This,
            /* [out] */ __RPC__deref_out_opt IEnumProgressItems **ppEnum);
        
        END_INTERFACE
    } IEnumProgressItemsVtbl;

    interface IEnumProgressItems
    {
        CONST_VTBL struct IEnumProgressItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumProgressItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumProgressItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumProgressItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumProgressItems_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumProgressItems_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumProgressItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumProgressItems_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][call_as] */ HRESULT STDMETHODCALLTYPE IEnumProgressItems_RemoteNext_Proxy( 
    IEnumProgressItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IProgressItem **rgelt,
    /* [out] */ __RPC__out ULONG *pceltFetched);


void __RPC_STUB IEnumProgressItems_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumProgressItems_INTERFACE_DEFINED__ */


#ifndef __IProgressItems_INTERFACE_DEFINED__
#define __IProgressItems_INTERFACE_DEFINED__

/* interface IProgressItems */
/* [helpstring][uuid][oleautomation][nonextensible][dual][unique][object] */ 


EXTERN_C const IID IID_IProgressItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD7-975B-59BE-A960-9A2A262853A5")
    IProgressItems : public IDispatch
    {
    public:
        virtual /* [helpstring][restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **NewEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *Count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProgressItemFromBlock( 
            /* [in] */ ULONG block,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProgressItemFromDescription( 
            /* [in] */ __RPC__in BSTR description,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item) = 0;
        
        virtual /* [helpstring][restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumProgressItems( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumProgressItems **NewEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProgressItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProgressItems * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProgressItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProgressItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IProgressItems * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IProgressItems * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IProgressItems * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IProgressItems * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IProgressItems * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **NewEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IProgressItems * This,
            /* [in] */ long Index,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IProgressItems * This,
            /* [retval][out] */ __RPC__out long *Count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProgressItemFromBlock )( 
            IProgressItems * This,
            /* [in] */ ULONG block,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProgressItemFromDescription )( 
            IProgressItems * This,
            /* [in] */ __RPC__in BSTR description,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItem **item);
        
        /* [helpstring][restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumProgressItems )( 
            IProgressItems * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumProgressItems **NewEnum);
        
        END_INTERFACE
    } IProgressItemsVtbl;

    interface IProgressItems
    {
        CONST_VTBL struct IProgressItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProgressItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProgressItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProgressItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProgressItems_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IProgressItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IProgressItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IProgressItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IProgressItems_get__NewEnum(This,NewEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,NewEnum) ) 

#define IProgressItems_get_Item(This,Index,item)	\
    ( (This)->lpVtbl -> get_Item(This,Index,item) ) 

#define IProgressItems_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IProgressItems_ProgressItemFromBlock(This,block,item)	\
    ( (This)->lpVtbl -> ProgressItemFromBlock(This,block,item) ) 

#define IProgressItems_ProgressItemFromDescription(This,description,item)	\
    ( (This)->lpVtbl -> ProgressItemFromDescription(This,description,item) ) 

#define IProgressItems_get_EnumProgressItems(This,NewEnum)	\
    ( (This)->lpVtbl -> get_EnumProgressItems(This,NewEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProgressItems_INTERFACE_DEFINED__ */


#ifndef __IFileSystemImageResult_INTERFACE_DEFINED__
#define __IFileSystemImageResult_INTERFACE_DEFINED__

/* interface IFileSystemImageResult */
/* [helpstring][uuid][nonextensible][oleautomation][dual][unique][object] */ 


EXTERN_C const IID IID_IFileSystemImageResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD8-975B-59BE-A960-9A2A262853A5")
    IFileSystemImageResult : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageStream( 
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgressItems( 
            /* [retval][out] */ __RPC__deref_out_opt IProgressItems **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalBlocks( 
            /* [retval][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSize( 
            /* [retval][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DiscId( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileSystemImageResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileSystemImageResult * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileSystemImageResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileSystemImageResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileSystemImageResult * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileSystemImageResult * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileSystemImageResult * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileSystemImageResult * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageStream )( 
            IFileSystemImageResult * This,
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgressItems )( 
            IFileSystemImageResult * This,
            /* [retval][out] */ __RPC__deref_out_opt IProgressItems **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalBlocks )( 
            IFileSystemImageResult * This,
            /* [retval][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSize )( 
            IFileSystemImageResult * This,
            /* [retval][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DiscId )( 
            IFileSystemImageResult * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        END_INTERFACE
    } IFileSystemImageResultVtbl;

    interface IFileSystemImageResult
    {
        CONST_VTBL struct IFileSystemImageResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileSystemImageResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileSystemImageResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileSystemImageResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileSystemImageResult_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileSystemImageResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileSystemImageResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileSystemImageResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileSystemImageResult_get_ImageStream(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageStream(This,pVal) ) 

#define IFileSystemImageResult_get_ProgressItems(This,pVal)	\
    ( (This)->lpVtbl -> get_ProgressItems(This,pVal) ) 

#define IFileSystemImageResult_get_TotalBlocks(This,pVal)	\
    ( (This)->lpVtbl -> get_TotalBlocks(This,pVal) ) 

#define IFileSystemImageResult_get_BlockSize(This,pVal)	\
    ( (This)->lpVtbl -> get_BlockSize(This,pVal) ) 

#define IFileSystemImageResult_get_DiscId(This,pVal)	\
    ( (This)->lpVtbl -> get_DiscId(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileSystemImageResult_INTERFACE_DEFINED__ */


#ifndef __IFsiItem_INTERFACE_DEFINED__
#define __IFsiItem_INTERFACE_DEFINED__

/* interface IFsiItem */
/* [helpstring][uuid][nonextensible][oleautomation][dual][unique][object] */ 


EXTERN_C const IID IID_IFsiItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FD9-975B-59BE-A960-9A2A262853A5")
    IFsiItem : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FullPath( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [retval][out] */ __RPC__out DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CreationTime( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastAccessedTime( 
            /* [retval][out] */ __RPC__out DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastAccessedTime( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastModifiedTime( 
            /* [retval][out] */ __RPC__out DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastModifiedTime( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsHidden( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsHidden( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileSystemName( 
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FileSystemPath( 
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsiItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsiItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsiItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsiItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFsiItem * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFsiItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFsiItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsiItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CreationTime )( 
            IFsiItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastAccessedTime )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastAccessedTime )( 
            IFsiItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModifiedTime )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastModifiedTime )( 
            IFsiItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IFsiItem * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IFsiItem * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemName )( 
            IFsiItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemPath )( 
            IFsiItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        END_INTERFACE
    } IFsiItemVtbl;

    interface IFsiItem
    {
        CONST_VTBL struct IFsiItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsiItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsiItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsiItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsiItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsiItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsiItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsiItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsiItem_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IFsiItem_get_FullPath(This,pVal)	\
    ( (This)->lpVtbl -> get_FullPath(This,pVal) ) 

#define IFsiItem_get_CreationTime(This,pVal)	\
    ( (This)->lpVtbl -> get_CreationTime(This,pVal) ) 

#define IFsiItem_put_CreationTime(This,newVal)	\
    ( (This)->lpVtbl -> put_CreationTime(This,newVal) ) 

#define IFsiItem_get_LastAccessedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastAccessedTime(This,pVal) ) 

#define IFsiItem_put_LastAccessedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastAccessedTime(This,newVal) ) 

#define IFsiItem_get_LastModifiedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastModifiedTime(This,pVal) ) 

#define IFsiItem_put_LastModifiedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastModifiedTime(This,newVal) ) 

#define IFsiItem_get_IsHidden(This,pVal)	\
    ( (This)->lpVtbl -> get_IsHidden(This,pVal) ) 

#define IFsiItem_put_IsHidden(This,newVal)	\
    ( (This)->lpVtbl -> put_IsHidden(This,newVal) ) 

#define IFsiItem_FileSystemName(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemName(This,fileSystem,pVal) ) 

#define IFsiItem_FileSystemPath(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemPath(This,fileSystem,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsiItem_INTERFACE_DEFINED__ */


#ifndef __IEnumFsiItems_INTERFACE_DEFINED__
#define __IEnumFsiItems_INTERFACE_DEFINED__

/* interface IEnumFsiItems */
/* [helpstring][uuid][unique][object] */ 


EXTERN_C const IID IID_IEnumFsiItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FDA-975B-59BE-A960-9A2A262853A5")
    IEnumFsiItems : public IUnknown
    {
    public:
        virtual /* [helpstring][local] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IFsiItem **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumFsiItems **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumFsiItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumFsiItems * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumFsiItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumFsiItems * This);
        
        /* [helpstring][local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumFsiItems * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IFsiItem **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumFsiItems * This,
            /* [in] */ ULONG celt);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumFsiItems * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumFsiItems * This,
            /* [out] */ __RPC__deref_out_opt IEnumFsiItems **ppEnum);
        
        END_INTERFACE
    } IEnumFsiItemsVtbl;

    interface IEnumFsiItems
    {
        CONST_VTBL struct IEnumFsiItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumFsiItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumFsiItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumFsiItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumFsiItems_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumFsiItems_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumFsiItems_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumFsiItems_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][call_as] */ HRESULT STDMETHODCALLTYPE IEnumFsiItems_RemoteNext_Proxy( 
    IEnumFsiItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IFsiItem **rgelt,
    /* [out] */ __RPC__out ULONG *pceltFetched);


void __RPC_STUB IEnumFsiItems_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumFsiItems_INTERFACE_DEFINED__ */


#ifndef __IFsiFileItem_INTERFACE_DEFINED__
#define __IFsiFileItem_INTERFACE_DEFINED__

/* interface IFsiFileItem */
/* [helpstring][uuid][nonextensible][oleautomation][dual][unique][object] */ 


EXTERN_C const IID IID_IFsiFileItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FDB-975B-59BE-A960-9A2A262853A5")
    IFsiFileItem : public IFsiItem
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataSize( 
            /* [retval][out] */ __RPC__out LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataSize32BitLow( 
            /* [retval][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataSize32BitHigh( 
            /* [retval][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Data( 
            /* [in] */ __RPC__in_opt IStream *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsiFileItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsiFileItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsiFileItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsiFileItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFsiFileItem * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFsiFileItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFsiFileItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsiFileItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CreationTime )( 
            IFsiFileItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastAccessedTime )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastAccessedTime )( 
            IFsiFileItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModifiedTime )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastModifiedTime )( 
            IFsiFileItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IFsiFileItem * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemName )( 
            IFsiFileItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemPath )( 
            IFsiFileItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataSize )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataSize32BitLow )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataSize32BitHigh )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Data )( 
            IFsiFileItem * This,
            /* [retval][out] */ __RPC__deref_out_opt IStream **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Data )( 
            IFsiFileItem * This,
            /* [in] */ __RPC__in_opt IStream *newVal);
        
        END_INTERFACE
    } IFsiFileItemVtbl;

    interface IFsiFileItem
    {
        CONST_VTBL struct IFsiFileItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsiFileItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsiFileItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsiFileItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsiFileItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsiFileItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsiFileItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsiFileItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsiFileItem_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IFsiFileItem_get_FullPath(This,pVal)	\
    ( (This)->lpVtbl -> get_FullPath(This,pVal) ) 

#define IFsiFileItem_get_CreationTime(This,pVal)	\
    ( (This)->lpVtbl -> get_CreationTime(This,pVal) ) 

#define IFsiFileItem_put_CreationTime(This,newVal)	\
    ( (This)->lpVtbl -> put_CreationTime(This,newVal) ) 

#define IFsiFileItem_get_LastAccessedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastAccessedTime(This,pVal) ) 

#define IFsiFileItem_put_LastAccessedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastAccessedTime(This,newVal) ) 

#define IFsiFileItem_get_LastModifiedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastModifiedTime(This,pVal) ) 

#define IFsiFileItem_put_LastModifiedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastModifiedTime(This,newVal) ) 

#define IFsiFileItem_get_IsHidden(This,pVal)	\
    ( (This)->lpVtbl -> get_IsHidden(This,pVal) ) 

#define IFsiFileItem_put_IsHidden(This,newVal)	\
    ( (This)->lpVtbl -> put_IsHidden(This,newVal) ) 

#define IFsiFileItem_FileSystemName(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemName(This,fileSystem,pVal) ) 

#define IFsiFileItem_FileSystemPath(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemPath(This,fileSystem,pVal) ) 


#define IFsiFileItem_get_DataSize(This,pVal)	\
    ( (This)->lpVtbl -> get_DataSize(This,pVal) ) 

#define IFsiFileItem_get_DataSize32BitLow(This,pVal)	\
    ( (This)->lpVtbl -> get_DataSize32BitLow(This,pVal) ) 

#define IFsiFileItem_get_DataSize32BitHigh(This,pVal)	\
    ( (This)->lpVtbl -> get_DataSize32BitHigh(This,pVal) ) 

#define IFsiFileItem_get_Data(This,pVal)	\
    ( (This)->lpVtbl -> get_Data(This,pVal) ) 

#define IFsiFileItem_put_Data(This,newVal)	\
    ( (This)->lpVtbl -> put_Data(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsiFileItem_INTERFACE_DEFINED__ */


#ifndef __IFsiDirectoryItem_INTERFACE_DEFINED__
#define __IFsiDirectoryItem_INTERFACE_DEFINED__

/* interface IFsiDirectoryItem */
/* [helpstring][uuid][nonextensible][oleautomation][dual][unique][object] */ 


EXTERN_C const IID IID_IFsiDirectoryItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FDC-975B-59BE-A960-9A2A262853A5")
    IFsiDirectoryItem : public IFsiItem
    {
    public:
        virtual /* [helpstring][restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **NewEnum) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ __RPC__in BSTR path,
            /* [retval][out] */ __RPC__deref_out_opt IFsiItem **item) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out LONG *Count) = 0;
        
        virtual /* [helpstring][restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnumFsiItems( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumFsiItems **NewEnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDirectory( 
            /* [in] */ __RPC__in BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddFile( 
            /* [in] */ __RPC__in BSTR path,
            /* [in] */ __RPC__in_opt IStream *fileData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTree( 
            /* [in] */ __RPC__in BSTR sourceDirectory,
            /* [in] */ VARIANT_BOOL includeBaseDirectory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IFsiItem *item) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ __RPC__in BSTR path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveTree( 
            /* [in] */ __RPC__in BSTR path) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsiDirectoryItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsiDirectoryItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsiDirectoryItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFsiDirectoryItem * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFsiDirectoryItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFsiDirectoryItem * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CreationTime )( 
            IFsiDirectoryItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastAccessedTime )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastAccessedTime )( 
            IFsiDirectoryItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastModifiedTime )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__out DATE *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LastModifiedTime )( 
            IFsiDirectoryItem * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsHidden )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsHidden )( 
            IFsiDirectoryItem * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemName )( 
            IFsiDirectoryItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileSystemPath )( 
            IFsiDirectoryItem * This,
            /* [in] */ FsiFileSystems fileSystem,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **NewEnum);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR path,
            /* [retval][out] */ __RPC__deref_out_opt IFsiItem **item);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__out LONG *Count);
        
        /* [helpstring][restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnumFsiItems )( 
            IFsiDirectoryItem * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumFsiItems **NewEnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddDirectory )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddFile )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR path,
            /* [in] */ __RPC__in_opt IStream *fileData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTree )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR sourceDirectory,
            /* [in] */ VARIANT_BOOL includeBaseDirectory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in_opt IFsiItem *item);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveTree )( 
            IFsiDirectoryItem * This,
            /* [in] */ __RPC__in BSTR path);
        
        END_INTERFACE
    } IFsiDirectoryItemVtbl;

    interface IFsiDirectoryItem
    {
        CONST_VTBL struct IFsiDirectoryItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsiDirectoryItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFsiDirectoryItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFsiDirectoryItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFsiDirectoryItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFsiDirectoryItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFsiDirectoryItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFsiDirectoryItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFsiDirectoryItem_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IFsiDirectoryItem_get_FullPath(This,pVal)	\
    ( (This)->lpVtbl -> get_FullPath(This,pVal) ) 

#define IFsiDirectoryItem_get_CreationTime(This,pVal)	\
    ( (This)->lpVtbl -> get_CreationTime(This,pVal) ) 

#define IFsiDirectoryItem_put_CreationTime(This,newVal)	\
    ( (This)->lpVtbl -> put_CreationTime(This,newVal) ) 

#define IFsiDirectoryItem_get_LastAccessedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastAccessedTime(This,pVal) ) 

#define IFsiDirectoryItem_put_LastAccessedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastAccessedTime(This,newVal) ) 

#define IFsiDirectoryItem_get_LastModifiedTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastModifiedTime(This,pVal) ) 

#define IFsiDirectoryItem_put_LastModifiedTime(This,newVal)	\
    ( (This)->lpVtbl -> put_LastModifiedTime(This,newVal) ) 

#define IFsiDirectoryItem_get_IsHidden(This,pVal)	\
    ( (This)->lpVtbl -> get_IsHidden(This,pVal) ) 

#define IFsiDirectoryItem_put_IsHidden(This,newVal)	\
    ( (This)->lpVtbl -> put_IsHidden(This,newVal) ) 

#define IFsiDirectoryItem_FileSystemName(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemName(This,fileSystem,pVal) ) 

#define IFsiDirectoryItem_FileSystemPath(This,fileSystem,pVal)	\
    ( (This)->lpVtbl -> FileSystemPath(This,fileSystem,pVal) ) 


#define IFsiDirectoryItem_get__NewEnum(This,NewEnum)	\
    ( (This)->lpVtbl -> get__NewEnum(This,NewEnum) ) 

#define IFsiDirectoryItem_get_Item(This,path,item)	\
    ( (This)->lpVtbl -> get_Item(This,path,item) ) 

#define IFsiDirectoryItem_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IFsiDirectoryItem_get_EnumFsiItems(This,NewEnum)	\
    ( (This)->lpVtbl -> get_EnumFsiItems(This,NewEnum) ) 

#define IFsiDirectoryItem_AddDirectory(This,path)	\
    ( (This)->lpVtbl -> AddDirectory(This,path) ) 

#define IFsiDirectoryItem_AddFile(This,path,fileData)	\
    ( (This)->lpVtbl -> AddFile(This,path,fileData) ) 

#define IFsiDirectoryItem_AddTree(This,sourceDirectory,includeBaseDirectory)	\
    ( (This)->lpVtbl -> AddTree(This,sourceDirectory,includeBaseDirectory) ) 

#define IFsiDirectoryItem_Add(This,item)	\
    ( (This)->lpVtbl -> Add(This,item) ) 

#define IFsiDirectoryItem_Remove(This,path)	\
    ( (This)->lpVtbl -> Remove(This,path) ) 

#define IFsiDirectoryItem_RemoveTree(This,path)	\
    ( (This)->lpVtbl -> RemoveTree(This,path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFsiDirectoryItem_INTERFACE_DEFINED__ */


#ifndef __IFileSystemImage_INTERFACE_DEFINED__
#define __IFileSystemImage_INTERFACE_DEFINED__

/* interface IFileSystemImage */
/* [helpstring][uuid][nonextensible][oleautomation][dual][unique][object] */ 


EXTERN_C const IID IID_IFileSystemImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FE1-975B-59BE-A960-9A2A262853A5")
    IFileSystemImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiDirectoryItem **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SessionStartBlock( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SessionStartBlock( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FreeMediaBlocks( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FreeMediaBlocks( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxMediaBlocksFromDevice( 
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsedBlocks( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeName( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VolumeName( 
            /* [in] */ __RPC__in BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImportedVolumeName( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BootImageOptions( 
            /* [retval][ref][out] */ __RPC__deref_out_opt IBootOptions **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BootImageOptions( 
            /* [in] */ __RPC__in_opt IBootOptions *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileCount( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DirectoryCount( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WorkingDirectory( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WorkingDirectory( 
            /* [in] */ __RPC__in BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChangePoint( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StrictFileSystemCompliance( 
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StrictFileSystemCompliance( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseRestrictedCharacterSet( 
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseRestrictedCharacterSet( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSystemsToCreate( 
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FileSystemsToCreate( 
            /* [in] */ FsiFileSystems newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FileSystemsSupported( 
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UDFRevision( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UDFRevision( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UDFRevisionsSupported( 
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseImageDefaults( 
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseImageDefaultsForMediaType( 
            /* [in] */ IMAPI_MEDIA_PHYSICAL_TYPE value) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ISO9660InterchangeLevel( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISO9660InterchangeLevel( 
            /* [retval][ref][out] */ __RPC__out LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ISO9660InterchangeLevelsSupported( 
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateResultImage( 
            /* [retval][ref][out] */ __RPC__deref_out_opt IFileSystemImageResult **resultStream) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exists( 
            /* [in] */ __RPC__in BSTR fullPath,
            /* [retval][ref][out] */ __RPC__out FsiItemType *itemType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalculateDiscIdentifier( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *discIdentifier) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IdentifyFileSystemsOnDisc( 
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *fileSystems) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDefaultFileSystemForImport( 
            /* [in] */ FsiFileSystems fileSystems,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *importDefault) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportFileSystem( 
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *importedFileSystem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportSpecificFileSystem( 
            /* [in] */ FsiFileSystems fileSystemToUse) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RollbackToChangePoint( 
            /* [in] */ LONG changePoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockInChangePoint( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateDirectoryItem( 
            /* [in] */ __RPC__in BSTR name,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiDirectoryItem **newItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFileItem( 
            /* [in] */ __RPC__in BSTR name,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiFileItem **newItem) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeNameUDF( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeNameJoliet( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumeNameISO9660( 
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StageFiles( 
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StageFiles( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MultisessionInterfaces( 
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MultisessionInterfaces( 
            /* [in] */ __RPC__in SAFEARRAY * newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileSystemImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileSystemImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileSystemImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileSystemImage * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileSystemImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileSystemImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Root )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiDirectoryItem **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionStartBlock )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SessionStartBlock )( 
            IFileSystemImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FreeMediaBlocks )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FreeMediaBlocks )( 
            IFileSystemImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxMediaBlocksFromDevice )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsedBlocks )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeName )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VolumeName )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImportedVolumeName )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BootImageOptions )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt IBootOptions **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BootImageOptions )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in_opt IBootOptions *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileCount )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DirectoryCount )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WorkingDirectory )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WorkingDirectory )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChangePoint )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StrictFileSystemCompliance )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StrictFileSystemCompliance )( 
            IFileSystemImage * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseRestrictedCharacterSet )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseRestrictedCharacterSet )( 
            IFileSystemImage * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSystemsToCreate )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileSystemsToCreate )( 
            IFileSystemImage * This,
            /* [in] */ FsiFileSystems newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileSystemsSupported )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UDFRevision )( 
            IFileSystemImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UDFRevision )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UDFRevisionsSupported )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseImageDefaults )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseImageDefaultsForMediaType )( 
            IFileSystemImage * This,
            /* [in] */ IMAPI_MEDIA_PHYSICAL_TYPE value);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ISO9660InterchangeLevel )( 
            IFileSystemImage * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISO9660InterchangeLevel )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ISO9660InterchangeLevelsSupported )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateResultImage )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFileSystemImageResult **resultStream);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exists )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in BSTR fullPath,
            /* [retval][ref][out] */ __RPC__out FsiItemType *itemType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CalculateDiscIdentifier )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *discIdentifier);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IdentifyFileSystemsOnDisc )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in_opt IDiscRecorder2 *discRecorder,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *fileSystems);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDefaultFileSystemForImport )( 
            IFileSystemImage * This,
            /* [in] */ FsiFileSystems fileSystems,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *importDefault);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportFileSystem )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out FsiFileSystems *importedFileSystem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportSpecificFileSystem )( 
            IFileSystemImage * This,
            /* [in] */ FsiFileSystems fileSystemToUse);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RollbackToChangePoint )( 
            IFileSystemImage * This,
            /* [in] */ LONG changePoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockInChangePoint )( 
            IFileSystemImage * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateDirectoryItem )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in BSTR name,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiDirectoryItem **newItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFileItem )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in BSTR name,
            /* [retval][ref][out] */ __RPC__deref_out_opt IFsiFileItem **newItem);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeNameUDF )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeNameJoliet )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumeNameISO9660 )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StageFiles )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StageFiles )( 
            IFileSystemImage * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MultisessionInterfaces )( 
            IFileSystemImage * This,
            /* [retval][ref][out] */ __RPC__deref_out_opt SAFEARRAY * *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MultisessionInterfaces )( 
            IFileSystemImage * This,
            /* [in] */ __RPC__in SAFEARRAY * newVal);
        
        END_INTERFACE
    } IFileSystemImageVtbl;

    interface IFileSystemImage
    {
        CONST_VTBL struct IFileSystemImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileSystemImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileSystemImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileSystemImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileSystemImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileSystemImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileSystemImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileSystemImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileSystemImage_get_Root(This,pVal)	\
    ( (This)->lpVtbl -> get_Root(This,pVal) ) 

#define IFileSystemImage_get_SessionStartBlock(This,pVal)	\
    ( (This)->lpVtbl -> get_SessionStartBlock(This,pVal) ) 

#define IFileSystemImage_put_SessionStartBlock(This,newVal)	\
    ( (This)->lpVtbl -> put_SessionStartBlock(This,newVal) ) 

#define IFileSystemImage_get_FreeMediaBlocks(This,pVal)	\
    ( (This)->lpVtbl -> get_FreeMediaBlocks(This,pVal) ) 

#define IFileSystemImage_put_FreeMediaBlocks(This,newVal)	\
    ( (This)->lpVtbl -> put_FreeMediaBlocks(This,newVal) ) 

#define IFileSystemImage_SetMaxMediaBlocksFromDevice(This,discRecorder)	\
    ( (This)->lpVtbl -> SetMaxMediaBlocksFromDevice(This,discRecorder) ) 

#define IFileSystemImage_get_UsedBlocks(This,pVal)	\
    ( (This)->lpVtbl -> get_UsedBlocks(This,pVal) ) 

#define IFileSystemImage_get_VolumeName(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumeName(This,pVal) ) 

#define IFileSystemImage_put_VolumeName(This,newVal)	\
    ( (This)->lpVtbl -> put_VolumeName(This,newVal) ) 

#define IFileSystemImage_get_ImportedVolumeName(This,pVal)	\
    ( (This)->lpVtbl -> get_ImportedVolumeName(This,pVal) ) 

#define IFileSystemImage_get_BootImageOptions(This,pVal)	\
    ( (This)->lpVtbl -> get_BootImageOptions(This,pVal) ) 

#define IFileSystemImage_put_BootImageOptions(This,newVal)	\
    ( (This)->lpVtbl -> put_BootImageOptions(This,newVal) ) 

#define IFileSystemImage_get_FileCount(This,pVal)	\
    ( (This)->lpVtbl -> get_FileCount(This,pVal) ) 

#define IFileSystemImage_get_DirectoryCount(This,pVal)	\
    ( (This)->lpVtbl -> get_DirectoryCount(This,pVal) ) 

#define IFileSystemImage_get_WorkingDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_WorkingDirectory(This,pVal) ) 

#define IFileSystemImage_put_WorkingDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_WorkingDirectory(This,newVal) ) 

#define IFileSystemImage_get_ChangePoint(This,pVal)	\
    ( (This)->lpVtbl -> get_ChangePoint(This,pVal) ) 

#define IFileSystemImage_get_StrictFileSystemCompliance(This,pVal)	\
    ( (This)->lpVtbl -> get_StrictFileSystemCompliance(This,pVal) ) 

#define IFileSystemImage_put_StrictFileSystemCompliance(This,newVal)	\
    ( (This)->lpVtbl -> put_StrictFileSystemCompliance(This,newVal) ) 

#define IFileSystemImage_get_UseRestrictedCharacterSet(This,pVal)	\
    ( (This)->lpVtbl -> get_UseRestrictedCharacterSet(This,pVal) ) 

#define IFileSystemImage_put_UseRestrictedCharacterSet(This,newVal)	\
    ( (This)->lpVtbl -> put_UseRestrictedCharacterSet(This,newVal) ) 

#define IFileSystemImage_get_FileSystemsToCreate(This,pVal)	\
    ( (This)->lpVtbl -> get_FileSystemsToCreate(This,pVal) ) 

#define IFileSystemImage_put_FileSystemsToCreate(This,newVal)	\
    ( (This)->lpVtbl -> put_FileSystemsToCreate(This,newVal) ) 

#define IFileSystemImage_get_FileSystemsSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_FileSystemsSupported(This,pVal) ) 

#define IFileSystemImage_put_UDFRevision(This,newVal)	\
    ( (This)->lpVtbl -> put_UDFRevision(This,newVal) ) 

#define IFileSystemImage_get_UDFRevision(This,pVal)	\
    ( (This)->lpVtbl -> get_UDFRevision(This,pVal) ) 

#define IFileSystemImage_get_UDFRevisionsSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_UDFRevisionsSupported(This,pVal) ) 

#define IFileSystemImage_ChooseImageDefaults(This,discRecorder)	\
    ( (This)->lpVtbl -> ChooseImageDefaults(This,discRecorder) ) 

#define IFileSystemImage_ChooseImageDefaultsForMediaType(This,value)	\
    ( (This)->lpVtbl -> ChooseImageDefaultsForMediaType(This,value) ) 

#define IFileSystemImage_put_ISO9660InterchangeLevel(This,newVal)	\
    ( (This)->lpVtbl -> put_ISO9660InterchangeLevel(This,newVal) ) 

#define IFileSystemImage_get_ISO9660InterchangeLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_ISO9660InterchangeLevel(This,pVal) ) 

#define IFileSystemImage_get_ISO9660InterchangeLevelsSupported(This,pVal)	\
    ( (This)->lpVtbl -> get_ISO9660InterchangeLevelsSupported(This,pVal) ) 

#define IFileSystemImage_CreateResultImage(This,resultStream)	\
    ( (This)->lpVtbl -> CreateResultImage(This,resultStream) ) 

#define IFileSystemImage_Exists(This,fullPath,itemType)	\
    ( (This)->lpVtbl -> Exists(This,fullPath,itemType) ) 

#define IFileSystemImage_CalculateDiscIdentifier(This,discIdentifier)	\
    ( (This)->lpVtbl -> CalculateDiscIdentifier(This,discIdentifier) ) 

#define IFileSystemImage_IdentifyFileSystemsOnDisc(This,discRecorder,fileSystems)	\
    ( (This)->lpVtbl -> IdentifyFileSystemsOnDisc(This,discRecorder,fileSystems) ) 

#define IFileSystemImage_GetDefaultFileSystemForImport(This,fileSystems,importDefault)	\
    ( (This)->lpVtbl -> GetDefaultFileSystemForImport(This,fileSystems,importDefault) ) 

#define IFileSystemImage_ImportFileSystem(This,importedFileSystem)	\
    ( (This)->lpVtbl -> ImportFileSystem(This,importedFileSystem) ) 

#define IFileSystemImage_ImportSpecificFileSystem(This,fileSystemToUse)	\
    ( (This)->lpVtbl -> ImportSpecificFileSystem(This,fileSystemToUse) ) 

#define IFileSystemImage_RollbackToChangePoint(This,changePoint)	\
    ( (This)->lpVtbl -> RollbackToChangePoint(This,changePoint) ) 

#define IFileSystemImage_LockInChangePoint(This)	\
    ( (This)->lpVtbl -> LockInChangePoint(This) ) 

#define IFileSystemImage_CreateDirectoryItem(This,name,newItem)	\
    ( (This)->lpVtbl -> CreateDirectoryItem(This,name,newItem) ) 

#define IFileSystemImage_CreateFileItem(This,name,newItem)	\
    ( (This)->lpVtbl -> CreateFileItem(This,name,newItem) ) 

#define IFileSystemImage_get_VolumeNameUDF(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumeNameUDF(This,pVal) ) 

#define IFileSystemImage_get_VolumeNameJoliet(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumeNameJoliet(This,pVal) ) 

#define IFileSystemImage_get_VolumeNameISO9660(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumeNameISO9660(This,pVal) ) 

#define IFileSystemImage_get_StageFiles(This,pVal)	\
    ( (This)->lpVtbl -> get_StageFiles(This,pVal) ) 

#define IFileSystemImage_put_StageFiles(This,newVal)	\
    ( (This)->lpVtbl -> put_StageFiles(This,newVal) ) 

#define IFileSystemImage_get_MultisessionInterfaces(This,pVal)	\
    ( (This)->lpVtbl -> get_MultisessionInterfaces(This,pVal) ) 

#define IFileSystemImage_put_MultisessionInterfaces(This,newVal)	\
    ( (This)->lpVtbl -> put_MultisessionInterfaces(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileSystemImage_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_imapi2fs_0000_0010 */
/* [local] */ 

#define DISPID_DFILESYSTEMIMAGEEVENTS_UPDATE 0x100


extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0010_v0_0_s_ifspec;

#ifndef __DFileSystemImageEvents_INTERFACE_DEFINED__
#define __DFileSystemImageEvents_INTERFACE_DEFINED__

/* interface DFileSystemImageEvents */
/* [helpstring][unique][uuid][oleautomation][nonextensible][object] */ 


EXTERN_C const IID IID_DFileSystemImageEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C941FDF-975B-59BE-A960-9A2A262853A5")
    DFileSystemImageEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ __RPC__in_opt IDispatch *object,
            /* [in] */ __RPC__in BSTR currentFile,
            /* [in] */ LONG copiedSectors,
            /* [in] */ LONG totalSectors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct DFileSystemImageEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            DFileSystemImageEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            DFileSystemImageEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            DFileSystemImageEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            DFileSystemImageEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            DFileSystemImageEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            DFileSystemImageEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            DFileSystemImageEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            DFileSystemImageEvents * This,
            /* [in] */ __RPC__in_opt IDispatch *object,
            /* [in] */ __RPC__in BSTR currentFile,
            /* [in] */ LONG copiedSectors,
            /* [in] */ LONG totalSectors);
        
        END_INTERFACE
    } DFileSystemImageEventsVtbl;

    interface DFileSystemImageEvents
    {
        CONST_VTBL struct DFileSystemImageEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DFileSystemImageEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define DFileSystemImageEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define DFileSystemImageEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define DFileSystemImageEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define DFileSystemImageEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define DFileSystemImageEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define DFileSystemImageEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define DFileSystemImageEvents_Update(This,object,currentFile,copiedSectors,totalSectors)	\
    ( (This)->lpVtbl -> Update(This,object,currentFile,copiedSectors,totalSectors) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __DFileSystemImageEvents_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_imapi2fs_0000_0011 */
/* [local] */ 


//
// IMAPIv2 FileSystemImaging version information for TYPELib loading
//
#define IMAPI2FS_MajorVersion          1  
#define IMAPI2FS_MajorVersion_STR     "1"
#define IMAPI2FS_MajorVersion_WSTR   L"1"
#define IMAPI2FS_MinorVersion          0  
#define IMAPI2FS_MinorVersion_STR     "0"
#define IMAPI2FS_MinorVersion_WSTR   L"0"
#define IMAPI2FS_FullVersion_STR    "1.0"
#define IMAPI2FS_FullVersion_WSTR  L"1.0"


extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0011_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_imapi2fs_0000_0011_v0_0_s_ifspec;


#ifndef __IMAPI2FS_LIBRARY_DEFINED__
#define __IMAPI2FS_LIBRARY_DEFINED__

/* library IMAPI2FS */
/* [helpfile][helpstring][uuid][version] */ 




EXTERN_C const IID LIBID_IMAPI2FS;

EXTERN_C const CLSID CLSID_BootOptions;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FCE-975B-59BE-A960-9A2A262853A5")
BootOptions;
#endif

EXTERN_C const CLSID CLSID_FsiStream;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FCD-975B-59BE-A960-9A2A262853A5")
FsiStream;
#endif

EXTERN_C const CLSID CLSID_FileSystemImageResult;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FCC-975B-59BE-A960-9A2A262853A5")
FileSystemImageResult;
#endif

EXTERN_C const CLSID CLSID_ProgressItem;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FCB-975B-59BE-A960-9A2A262853A5")
ProgressItem;
#endif

EXTERN_C const CLSID CLSID_EnumProgressItems;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FCA-975B-59BE-A960-9A2A262853A5")
EnumProgressItems;
#endif

EXTERN_C const CLSID CLSID_ProgressItems;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FC9-975B-59BE-A960-9A2A262853A5")
ProgressItems;
#endif

EXTERN_C const CLSID CLSID_FsiDirectoryItem;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FC8-975B-59BE-A960-9A2A262853A5")
FsiDirectoryItem;
#endif

EXTERN_C const CLSID CLSID_FsiFileItem;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FC7-975B-59BE-A960-9A2A262853A5")
FsiFileItem;
#endif

EXTERN_C const CLSID CLSID_EnumFsiItems;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FC6-975B-59BE-A960-9A2A262853A5")
EnumFsiItems;
#endif

EXTERN_C const CLSID CLSID_MsftFileSystemImage;

#ifdef __cplusplus

class DECLSPEC_UUID("2C941FC5-975B-59BE-A960-9A2A262853A5")
MsftFileSystemImage;
#endif
#endif /* __IMAPI2FS_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE IEnumProgressItems_Next_Proxy( 
    IEnumProgressItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IProgressItem **rgelt,
    /* [out] */ ULONG *pceltFetched);


/* [helpstring][call_as] */ HRESULT STDMETHODCALLTYPE IEnumProgressItems_Next_Stub( 
    IEnumProgressItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IProgressItem **rgelt,
    /* [out] */ __RPC__out ULONG *pceltFetched);

/* [helpstring][local] */ HRESULT STDMETHODCALLTYPE IEnumFsiItems_Next_Proxy( 
    IEnumFsiItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IFsiItem **rgelt,
    /* [out] */ ULONG *pceltFetched);


/* [helpstring][call_as] */ HRESULT STDMETHODCALLTYPE IEnumFsiItems_Next_Stub( 
    IEnumFsiItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) IFsiItem **rgelt,
    /* [out] */ __RPC__out ULONG *pceltFetched);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



