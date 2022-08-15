

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for photoacquire.idl:
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

#ifndef __photoacquire_h__
#define __photoacquire_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPhotoAcquireItem_FWD_DEFINED__
#define __IPhotoAcquireItem_FWD_DEFINED__
typedef interface IPhotoAcquireItem IPhotoAcquireItem;
#endif 	/* __IPhotoAcquireItem_FWD_DEFINED__ */


#ifndef __IUserInputString_FWD_DEFINED__
#define __IUserInputString_FWD_DEFINED__
typedef interface IUserInputString IUserInputString;
#endif 	/* __IUserInputString_FWD_DEFINED__ */


#ifndef __IPhotoAcquireProgressCB_FWD_DEFINED__
#define __IPhotoAcquireProgressCB_FWD_DEFINED__
typedef interface IPhotoAcquireProgressCB IPhotoAcquireProgressCB;
#endif 	/* __IPhotoAcquireProgressCB_FWD_DEFINED__ */


#ifndef __IPhotoProgressActionCB_FWD_DEFINED__
#define __IPhotoProgressActionCB_FWD_DEFINED__
typedef interface IPhotoProgressActionCB IPhotoProgressActionCB;
#endif 	/* __IPhotoProgressActionCB_FWD_DEFINED__ */


#ifndef __IPhotoProgressDialog_FWD_DEFINED__
#define __IPhotoProgressDialog_FWD_DEFINED__
typedef interface IPhotoProgressDialog IPhotoProgressDialog;
#endif 	/* __IPhotoProgressDialog_FWD_DEFINED__ */


#ifndef __IPhotoAcquireSource_FWD_DEFINED__
#define __IPhotoAcquireSource_FWD_DEFINED__
typedef interface IPhotoAcquireSource IPhotoAcquireSource;
#endif 	/* __IPhotoAcquireSource_FWD_DEFINED__ */


#ifndef __IPhotoAcquire_FWD_DEFINED__
#define __IPhotoAcquire_FWD_DEFINED__
typedef interface IPhotoAcquire IPhotoAcquire;
#endif 	/* __IPhotoAcquire_FWD_DEFINED__ */


#ifndef __IPhotoAcquireSettings_FWD_DEFINED__
#define __IPhotoAcquireSettings_FWD_DEFINED__
typedef interface IPhotoAcquireSettings IPhotoAcquireSettings;
#endif 	/* __IPhotoAcquireSettings_FWD_DEFINED__ */


#ifndef __IPhotoAcquireOptionsDialog_FWD_DEFINED__
#define __IPhotoAcquireOptionsDialog_FWD_DEFINED__
typedef interface IPhotoAcquireOptionsDialog IPhotoAcquireOptionsDialog;
#endif 	/* __IPhotoAcquireOptionsDialog_FWD_DEFINED__ */


#ifndef __IPhotoAcquireDeviceSelectionDialog_FWD_DEFINED__
#define __IPhotoAcquireDeviceSelectionDialog_FWD_DEFINED__
typedef interface IPhotoAcquireDeviceSelectionDialog IPhotoAcquireDeviceSelectionDialog;
#endif 	/* __IPhotoAcquireDeviceSelectionDialog_FWD_DEFINED__ */


#ifndef __IPhotoAcquirePlugin_FWD_DEFINED__
#define __IPhotoAcquirePlugin_FWD_DEFINED__
typedef interface IPhotoAcquirePlugin IPhotoAcquirePlugin;
#endif 	/* __IPhotoAcquirePlugin_FWD_DEFINED__ */


#ifndef __PhotoAcquire_FWD_DEFINED__
#define __PhotoAcquire_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoAcquire PhotoAcquire;
#else
typedef struct PhotoAcquire PhotoAcquire;
#endif /* __cplusplus */

#endif 	/* __PhotoAcquire_FWD_DEFINED__ */


#ifndef __PhotoAcquireAutoPlayDropTarget_FWD_DEFINED__
#define __PhotoAcquireAutoPlayDropTarget_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoAcquireAutoPlayDropTarget PhotoAcquireAutoPlayDropTarget;
#else
typedef struct PhotoAcquireAutoPlayDropTarget PhotoAcquireAutoPlayDropTarget;
#endif /* __cplusplus */

#endif 	/* __PhotoAcquireAutoPlayDropTarget_FWD_DEFINED__ */


#ifndef __PhotoAcquireAutoPlayHWEventHandler_FWD_DEFINED__
#define __PhotoAcquireAutoPlayHWEventHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoAcquireAutoPlayHWEventHandler PhotoAcquireAutoPlayHWEventHandler;
#else
typedef struct PhotoAcquireAutoPlayHWEventHandler PhotoAcquireAutoPlayHWEventHandler;
#endif /* __cplusplus */

#endif 	/* __PhotoAcquireAutoPlayHWEventHandler_FWD_DEFINED__ */


#ifndef __PhotoAcquireOptionsDialog_FWD_DEFINED__
#define __PhotoAcquireOptionsDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoAcquireOptionsDialog PhotoAcquireOptionsDialog;
#else
typedef struct PhotoAcquireOptionsDialog PhotoAcquireOptionsDialog;
#endif /* __cplusplus */

#endif 	/* __PhotoAcquireOptionsDialog_FWD_DEFINED__ */


#ifndef __PhotoProgressDialog_FWD_DEFINED__
#define __PhotoProgressDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoProgressDialog PhotoProgressDialog;
#else
typedef struct PhotoProgressDialog PhotoProgressDialog;
#endif /* __cplusplus */

#endif 	/* __PhotoProgressDialog_FWD_DEFINED__ */


#ifndef __PhotoAcquireDeviceSelectionDialog_FWD_DEFINED__
#define __PhotoAcquireDeviceSelectionDialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class PhotoAcquireDeviceSelectionDialog PhotoAcquireDeviceSelectionDialog;
#else
typedef struct PhotoAcquireDeviceSelectionDialog PhotoAcquireDeviceSelectionDialog;
#endif /* __cplusplus */

#endif 	/* __PhotoAcquireDeviceSelectionDialog_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "propidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_photoacquire_0000_0000 */
/* [local] */ 



#include <PhotoAcquireProperties.h>


extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0000_v0_0_s_ifspec;

#ifndef __IPhotoAcquireItem_INTERFACE_DEFINED__
#define __IPhotoAcquireItem_INTERFACE_DEFINED__

/* interface IPhotoAcquireItem */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquireItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f21c97-28bf-4c02-b842-5e4e90139a30")
    IPhotoAcquireItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemName( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrItemName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThumbnail( 
            /* [in] */ SIZE sizeThumbnail,
            /* [out] */ __RPC__deref_out_opt HBITMAP *phbmpThumbnail) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [out] */ __RPC__out PROPVARIANT *pv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [in] */ __RPC__in const PROPVARIANT *pv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [out] */ __RPC__deref_out_opt IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanDelete( 
            /* [out] */ __RPC__out BOOL *pfCanDelete) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubItemCount( 
            /* [out] */ __RPC__out UINT *pnCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubItemAt( 
            /* [in] */ UINT nItemIndex,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireItem **ppPhotoAcquireItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireItem * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemName )( 
            IPhotoAcquireItem * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrItemName);
        
        HRESULT ( STDMETHODCALLTYPE *GetThumbnail )( 
            IPhotoAcquireItem * This,
            /* [in] */ SIZE sizeThumbnail,
            /* [out] */ __RPC__deref_out_opt HBITMAP *phbmpThumbnail);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IPhotoAcquireItem * This,
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [out] */ __RPC__out PROPVARIANT *pv);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IPhotoAcquireItem * This,
            /* [in] */ __RPC__in REFPROPERTYKEY key,
            /* [in] */ __RPC__in const PROPVARIANT *pv);
        
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IPhotoAcquireItem * This,
            /* [out] */ __RPC__deref_out_opt IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CanDelete )( 
            IPhotoAcquireItem * This,
            /* [out] */ __RPC__out BOOL *pfCanDelete);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IPhotoAcquireItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubItemCount )( 
            IPhotoAcquireItem * This,
            /* [out] */ __RPC__out UINT *pnCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubItemAt )( 
            IPhotoAcquireItem * This,
            /* [in] */ UINT nItemIndex,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireItem **ppPhotoAcquireItem);
        
        END_INTERFACE
    } IPhotoAcquireItemVtbl;

    interface IPhotoAcquireItem
    {
        CONST_VTBL struct IPhotoAcquireItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireItem_GetItemName(This,pbstrItemName)	\
    ( (This)->lpVtbl -> GetItemName(This,pbstrItemName) ) 

#define IPhotoAcquireItem_GetThumbnail(This,sizeThumbnail,phbmpThumbnail)	\
    ( (This)->lpVtbl -> GetThumbnail(This,sizeThumbnail,phbmpThumbnail) ) 

#define IPhotoAcquireItem_GetProperty(This,key,pv)	\
    ( (This)->lpVtbl -> GetProperty(This,key,pv) ) 

#define IPhotoAcquireItem_SetProperty(This,key,pv)	\
    ( (This)->lpVtbl -> SetProperty(This,key,pv) ) 

#define IPhotoAcquireItem_GetStream(This,ppStream)	\
    ( (This)->lpVtbl -> GetStream(This,ppStream) ) 

#define IPhotoAcquireItem_CanDelete(This,pfCanDelete)	\
    ( (This)->lpVtbl -> CanDelete(This,pfCanDelete) ) 

#define IPhotoAcquireItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IPhotoAcquireItem_GetSubItemCount(This,pnCount)	\
    ( (This)->lpVtbl -> GetSubItemCount(This,pnCount) ) 

#define IPhotoAcquireItem_GetSubItemAt(This,nItemIndex,ppPhotoAcquireItem)	\
    ( (This)->lpVtbl -> GetSubItemAt(This,nItemIndex,ppPhotoAcquireItem) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireItem_INTERFACE_DEFINED__ */


#ifndef __IUserInputString_INTERFACE_DEFINED__
#define __IUserInputString_INTERFACE_DEFINED__

/* interface IUserInputString */
/* [unique][uuid][object][helpstring] */ 

typedef /* [v1_enum] */ 
enum tagUSER_INPUT_STRING_TYPE
    {	USER_INPUT_DEFAULT	= 0,
	USER_INPUT_PATH_ELEMENT	= 0x1
    } 	USER_INPUT_STRING_TYPE;


EXTERN_C const IID IID_IUserInputString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f243a1-205b-45ba-ae26-abbc53aa7a6f")
    IUserInputString : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSubmitButtonText( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrSubmitButtonText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrompt( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrPromptTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringId( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrStringId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringType( 
            /* [out] */ __RPC__out USER_INPUT_STRING_TYPE *pnStringType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTooltipText( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrTooltipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxLength( 
            /* [out] */ __RPC__out UINT *pcchMaxLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefault( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrDefault) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMruCount( 
            /* [out] */ __RPC__out UINT *pnMruCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMruEntryAt( 
            /* [in] */ UINT nIndex,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrMruEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetImage( 
            /* [in] */ UINT nSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HBITMAP *phBitmap,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phIcon) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUserInputStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserInputString * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserInputString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserInputString * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubmitButtonText )( 
            IUserInputString * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrSubmitButtonText);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrompt )( 
            IUserInputString * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrPromptTitle);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringId )( 
            IUserInputString * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrStringId);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringType )( 
            IUserInputString * This,
            /* [out] */ __RPC__out USER_INPUT_STRING_TYPE *pnStringType);
        
        HRESULT ( STDMETHODCALLTYPE *GetTooltipText )( 
            IUserInputString * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrTooltipText);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            IUserInputString * This,
            /* [out] */ __RPC__out UINT *pcchMaxLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefault )( 
            IUserInputString * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrDefault);
        
        HRESULT ( STDMETHODCALLTYPE *GetMruCount )( 
            IUserInputString * This,
            /* [out] */ __RPC__out UINT *pnMruCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetMruEntryAt )( 
            IUserInputString * This,
            /* [in] */ UINT nIndex,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrMruEntry);
        
        HRESULT ( STDMETHODCALLTYPE *GetImage )( 
            IUserInputString * This,
            /* [in] */ UINT nSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HBITMAP *phBitmap,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phIcon);
        
        END_INTERFACE
    } IUserInputStringVtbl;

    interface IUserInputString
    {
        CONST_VTBL struct IUserInputStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserInputString_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUserInputString_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUserInputString_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUserInputString_GetSubmitButtonText(This,pbstrSubmitButtonText)	\
    ( (This)->lpVtbl -> GetSubmitButtonText(This,pbstrSubmitButtonText) ) 

#define IUserInputString_GetPrompt(This,pbstrPromptTitle)	\
    ( (This)->lpVtbl -> GetPrompt(This,pbstrPromptTitle) ) 

#define IUserInputString_GetStringId(This,pbstrStringId)	\
    ( (This)->lpVtbl -> GetStringId(This,pbstrStringId) ) 

#define IUserInputString_GetStringType(This,pnStringType)	\
    ( (This)->lpVtbl -> GetStringType(This,pnStringType) ) 

#define IUserInputString_GetTooltipText(This,pbstrTooltipText)	\
    ( (This)->lpVtbl -> GetTooltipText(This,pbstrTooltipText) ) 

#define IUserInputString_GetMaxLength(This,pcchMaxLength)	\
    ( (This)->lpVtbl -> GetMaxLength(This,pcchMaxLength) ) 

#define IUserInputString_GetDefault(This,pbstrDefault)	\
    ( (This)->lpVtbl -> GetDefault(This,pbstrDefault) ) 

#define IUserInputString_GetMruCount(This,pnMruCount)	\
    ( (This)->lpVtbl -> GetMruCount(This,pnMruCount) ) 

#define IUserInputString_GetMruEntryAt(This,nIndex,pbstrMruEntry)	\
    ( (This)->lpVtbl -> GetMruEntryAt(This,nIndex,pbstrMruEntry) ) 

#define IUserInputString_GetImage(This,nSize,phBitmap,phIcon)	\
    ( (This)->lpVtbl -> GetImage(This,nSize,phBitmap,phIcon) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUserInputString_INTERFACE_DEFINED__ */


#ifndef __IPhotoAcquireProgressCB_INTERFACE_DEFINED__
#define __IPhotoAcquireProgressCB_INTERFACE_DEFINED__

/* interface IPhotoAcquireProgressCB */
/* [unique][uuid][object][helpstring] */ 

typedef /* [v1_enum] */ 
enum tagERROR_ADVISE_MESSAGE_TYPE
    {	PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL	= 0,
	PHOTOACQUIRE_ERROR_RETRYCANCEL	= 1,
	PHOTOACQUIRE_ERROR_YESNO	= 2,
	PHOTOACQUIRE_ERROR_OK	= 3
    } 	ERROR_ADVISE_MESSAGE_TYPE;

typedef /* [v1_enum] */ 
enum tagERROR_ADVISE_RESULT
    {	PHOTOACQUIRE_RESULT_YES	= 0,
	PHOTOACQUIRE_RESULT_NO	= 1,
	PHOTOACQUIRE_RESULT_OK	= 2,
	PHOTOACQUIRE_RESULT_SKIP	= 3,
	PHOTOACQUIRE_RESULT_SKIP_ALL	= 4,
	PHOTOACQUIRE_RESULT_RETRY	= 5,
	PHOTOACQUIRE_RESULT_ABORT	= 6
    } 	ERROR_ADVISE_RESULT;


EXTERN_C const IID IID_IPhotoAcquireProgressCB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f2ce1e-935e-4248-892c-130f32c45cb4")
    IPhotoAcquireProgressCB : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancelled( 
            /* [out] */ __RPC__out BOOL *pfCancelled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartEnumeration( 
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FoundItem( 
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndEnumeration( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartTransfer( 
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartItemTransfer( 
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DirectoryCreated( 
            /* [in] */ __RPC__in LPCWSTR pszDirectory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateTransferPercent( 
            /* [in] */ BOOL fOverall,
            /* [in] */ UINT nPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndItemTransfer( 
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndTransfer( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartDelete( 
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartItemDelete( 
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateDeletePercent( 
            /* [in] */ UINT nPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndItemDelete( 
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndDelete( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSession( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeleteAfterAcquire( 
            /* [out] */ __RPC__out BOOL *pfDeleteAfterAcquire) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ErrorAdvise( 
            /* [in] */ HRESULT hr,
            /* [in] */ __RPC__in LPCWSTR pszErrorMessage,
            /* [in] */ ERROR_ADVISE_MESSAGE_TYPE nMessageType,
            /* [out] */ __RPC__out ERROR_ADVISE_RESULT *pnErrorAdviseResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserInput( 
            /* [in] */ __RPC__in REFIID riidType,
            /* [in] */ __RPC__in_opt IUnknown *pUnknown,
            /* [out] */ __RPC__out PROPVARIANT *pPropVarResult,
            /* [unique][in] */ __RPC__in_opt const PROPVARIANT *pPropVarDefault) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireProgressCBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireProgressCB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireProgressCB * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancelled )( 
            IPhotoAcquireProgressCB * This,
            /* [out] */ __RPC__out BOOL *pfCancelled);
        
        HRESULT ( STDMETHODCALLTYPE *StartEnumeration )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource);
        
        HRESULT ( STDMETHODCALLTYPE *FoundItem )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem);
        
        HRESULT ( STDMETHODCALLTYPE *EndEnumeration )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *StartTransfer )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource);
        
        HRESULT ( STDMETHODCALLTYPE *StartItemTransfer )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem);
        
        HRESULT ( STDMETHODCALLTYPE *DirectoryCreated )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in LPCWSTR pszDirectory);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateTransferPercent )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ BOOL fOverall,
            /* [in] */ UINT nPercent);
        
        HRESULT ( STDMETHODCALLTYPE *EndItemTransfer )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *EndTransfer )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *StartDelete )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource);
        
        HRESULT ( STDMETHODCALLTYPE *StartItemDelete )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateDeletePercent )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ UINT nPercent);
        
        HRESULT ( STDMETHODCALLTYPE *EndItemDelete )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ UINT nItemIndex,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *EndDelete )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *EndSession )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeleteAfterAcquire )( 
            IPhotoAcquireProgressCB * This,
            /* [out] */ __RPC__out BOOL *pfDeleteAfterAcquire);
        
        HRESULT ( STDMETHODCALLTYPE *ErrorAdvise )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ HRESULT hr,
            /* [in] */ __RPC__in LPCWSTR pszErrorMessage,
            /* [in] */ ERROR_ADVISE_MESSAGE_TYPE nMessageType,
            /* [out] */ __RPC__out ERROR_ADVISE_RESULT *pnErrorAdviseResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserInput )( 
            IPhotoAcquireProgressCB * This,
            /* [in] */ __RPC__in REFIID riidType,
            /* [in] */ __RPC__in_opt IUnknown *pUnknown,
            /* [out] */ __RPC__out PROPVARIANT *pPropVarResult,
            /* [unique][in] */ __RPC__in_opt const PROPVARIANT *pPropVarDefault);
        
        END_INTERFACE
    } IPhotoAcquireProgressCBVtbl;

    interface IPhotoAcquireProgressCB
    {
        CONST_VTBL struct IPhotoAcquireProgressCBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireProgressCB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireProgressCB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireProgressCB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireProgressCB_Cancelled(This,pfCancelled)	\
    ( (This)->lpVtbl -> Cancelled(This,pfCancelled) ) 

#define IPhotoAcquireProgressCB_StartEnumeration(This,pPhotoAcquireSource)	\
    ( (This)->lpVtbl -> StartEnumeration(This,pPhotoAcquireSource) ) 

#define IPhotoAcquireProgressCB_FoundItem(This,pPhotoAcquireItem)	\
    ( (This)->lpVtbl -> FoundItem(This,pPhotoAcquireItem) ) 

#define IPhotoAcquireProgressCB_EndEnumeration(This,hr)	\
    ( (This)->lpVtbl -> EndEnumeration(This,hr) ) 

#define IPhotoAcquireProgressCB_StartTransfer(This,pPhotoAcquireSource)	\
    ( (This)->lpVtbl -> StartTransfer(This,pPhotoAcquireSource) ) 

#define IPhotoAcquireProgressCB_StartItemTransfer(This,nItemIndex,pPhotoAcquireItem)	\
    ( (This)->lpVtbl -> StartItemTransfer(This,nItemIndex,pPhotoAcquireItem) ) 

#define IPhotoAcquireProgressCB_DirectoryCreated(This,pszDirectory)	\
    ( (This)->lpVtbl -> DirectoryCreated(This,pszDirectory) ) 

#define IPhotoAcquireProgressCB_UpdateTransferPercent(This,fOverall,nPercent)	\
    ( (This)->lpVtbl -> UpdateTransferPercent(This,fOverall,nPercent) ) 

#define IPhotoAcquireProgressCB_EndItemTransfer(This,nItemIndex,pPhotoAcquireItem,hr)	\
    ( (This)->lpVtbl -> EndItemTransfer(This,nItemIndex,pPhotoAcquireItem,hr) ) 

#define IPhotoAcquireProgressCB_EndTransfer(This,hr)	\
    ( (This)->lpVtbl -> EndTransfer(This,hr) ) 

#define IPhotoAcquireProgressCB_StartDelete(This,pPhotoAcquireSource)	\
    ( (This)->lpVtbl -> StartDelete(This,pPhotoAcquireSource) ) 

#define IPhotoAcquireProgressCB_StartItemDelete(This,nItemIndex,pPhotoAcquireItem)	\
    ( (This)->lpVtbl -> StartItemDelete(This,nItemIndex,pPhotoAcquireItem) ) 

#define IPhotoAcquireProgressCB_UpdateDeletePercent(This,nPercent)	\
    ( (This)->lpVtbl -> UpdateDeletePercent(This,nPercent) ) 

#define IPhotoAcquireProgressCB_EndItemDelete(This,nItemIndex,pPhotoAcquireItem,hr)	\
    ( (This)->lpVtbl -> EndItemDelete(This,nItemIndex,pPhotoAcquireItem,hr) ) 

#define IPhotoAcquireProgressCB_EndDelete(This,hr)	\
    ( (This)->lpVtbl -> EndDelete(This,hr) ) 

#define IPhotoAcquireProgressCB_EndSession(This,hr)	\
    ( (This)->lpVtbl -> EndSession(This,hr) ) 

#define IPhotoAcquireProgressCB_GetDeleteAfterAcquire(This,pfDeleteAfterAcquire)	\
    ( (This)->lpVtbl -> GetDeleteAfterAcquire(This,pfDeleteAfterAcquire) ) 

#define IPhotoAcquireProgressCB_ErrorAdvise(This,hr,pszErrorMessage,nMessageType,pnErrorAdviseResult)	\
    ( (This)->lpVtbl -> ErrorAdvise(This,hr,pszErrorMessage,nMessageType,pnErrorAdviseResult) ) 

#define IPhotoAcquireProgressCB_GetUserInput(This,riidType,pUnknown,pPropVarResult,pPropVarDefault)	\
    ( (This)->lpVtbl -> GetUserInput(This,riidType,pUnknown,pPropVarResult,pPropVarDefault) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireProgressCB_INTERFACE_DEFINED__ */


#ifndef __IPhotoProgressActionCB_INTERFACE_DEFINED__
#define __IPhotoProgressActionCB_INTERFACE_DEFINED__

/* interface IPhotoProgressActionCB */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoProgressActionCB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f242d0-b206-4e7d-b4c1-4755bcbb9c9f")
    IPhotoProgressActionCB : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoAction( 
            __RPC__in HWND hWndParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoProgressActionCBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoProgressActionCB * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoProgressActionCB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoProgressActionCB * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoAction )( 
            IPhotoProgressActionCB * This,
            __RPC__in HWND hWndParent);
        
        END_INTERFACE
    } IPhotoProgressActionCBVtbl;

    interface IPhotoProgressActionCB
    {
        CONST_VTBL struct IPhotoProgressActionCBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoProgressActionCB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoProgressActionCB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoProgressActionCB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoProgressActionCB_DoAction(This,hWndParent)	\
    ( (This)->lpVtbl -> DoAction(This,hWndParent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoProgressActionCB_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_photoacquire_0000_0004 */
/* [local] */ 

#define PROGRESS_INDETERMINATE (-1)


extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0004_v0_0_s_ifspec;

#ifndef __IPhotoProgressDialog_INTERFACE_DEFINED__
#define __IPhotoProgressDialog_INTERFACE_DEFINED__

/* interface IPhotoProgressDialog */
/* [unique][uuid][object][helpstring] */ 

typedef /* [v1_enum] */ 
enum tagPROGRESS_DIALOG_IMAGE_TYPE
    {	PROGRESS_DIALOG_ICON_SMALL	= 0,
	PROGRESS_DIALOG_ICON_LARGE	= 0x1,
	PROGRESS_DIALOG_ICON_THUMBNAIL	= 0x2,
	PROGRESS_DIALOG_BITMAP_THUMBNAIL	= 0x3
    } 	PROGRESS_DIALOG_IMAGE_TYPE;

typedef /* [v1_enum] */ 
enum tagPROGRESS_DIALOG_CHECKBOX_ID
    {	PROGRESS_DIALOG_CHECKBOX_ID_DEFAULT	= 0
    } 	PROGRESS_DIALOG_CHECKBOX_ID;


EXTERN_C const IID IID_IPhotoProgressDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f246f9-0750-4f08-9381-2cd8e906a4ae")
    IPhotoProgressDialog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ __RPC__in HWND hwndParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWindow( 
            /* [out] */ __RPC__deref_out_opt HWND *phwndProgressDialog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTitle( 
            /* [string][in] */ __RPC__in LPCWSTR pszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowCheckbox( 
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [in] */ BOOL fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCheckboxText( 
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [string][in] */ __RPC__in LPCWSTR pszCheckboxText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCheckboxCheck( 
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [in] */ BOOL fChecked) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCheckboxTooltip( 
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [string][in] */ __RPC__in LPCWSTR pszCheckboxTooltipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCheckboxChecked( 
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [out] */ __RPC__out BOOL *pfChecked) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [string][in] */ __RPC__in LPCWSTR pszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetImage( 
            /* [in] */ PROGRESS_DIALOG_IMAGE_TYPE nImageType,
            /* [unique][in] */ __RPC__in_opt HICON hIcon,
            /* [unique][in] */ __RPC__in_opt HBITMAP hBitmap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPercentComplete( 
            /* [in] */ int nPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProgressText( 
            /* [string][in] */ __RPC__in LPCWSTR pszProgressText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActionLinkCallback( 
            /* [in] */ __RPC__in_opt IPhotoProgressActionCB *pPhotoProgressActionCB) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActionLinkText( 
            /* [in] */ __RPC__in LPCWSTR pszCaption) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowActionLink( 
            /* [in] */ BOOL fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCancelled( 
            /* [out] */ __RPC__out BOOL *pfCancelled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserInput( 
            /* [in] */ __RPC__in REFIID riidType,
            /* [in] */ __RPC__in_opt IUnknown *pUnknown,
            /* [out] */ __RPC__out PROPVARIANT *pPropVarResult,
            /* [unique][in] */ __RPC__in_opt const PROPVARIANT *pPropVarDefault) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoProgressDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoProgressDialog * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoProgressDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoProgressDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IPhotoProgressDialog * This,
            /* [in] */ __RPC__in HWND hwndParent);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IPhotoProgressDialog * This,
            /* [out] */ __RPC__deref_out_opt HWND *phwndProgressDialog);
        
        HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IPhotoProgressDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTitle )( 
            IPhotoProgressDialog * This,
            /* [string][in] */ __RPC__in LPCWSTR pszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *ShowCheckbox )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [in] */ BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *SetCheckboxText )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [string][in] */ __RPC__in LPCWSTR pszCheckboxText);
        
        HRESULT ( STDMETHODCALLTYPE *SetCheckboxCheck )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [in] */ BOOL fChecked);
        
        HRESULT ( STDMETHODCALLTYPE *SetCheckboxTooltip )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [string][in] */ __RPC__in LPCWSTR pszCheckboxTooltipText);
        
        HRESULT ( STDMETHODCALLTYPE *IsCheckboxChecked )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_CHECKBOX_ID nCheckboxId,
            /* [out] */ __RPC__out BOOL *pfChecked);
        
        HRESULT ( STDMETHODCALLTYPE *SetCaption )( 
            IPhotoProgressDialog * This,
            /* [string][in] */ __RPC__in LPCWSTR pszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *SetImage )( 
            IPhotoProgressDialog * This,
            /* [in] */ PROGRESS_DIALOG_IMAGE_TYPE nImageType,
            /* [unique][in] */ __RPC__in_opt HICON hIcon,
            /* [unique][in] */ __RPC__in_opt HBITMAP hBitmap);
        
        HRESULT ( STDMETHODCALLTYPE *SetPercentComplete )( 
            IPhotoProgressDialog * This,
            /* [in] */ int nPercent);
        
        HRESULT ( STDMETHODCALLTYPE *SetProgressText )( 
            IPhotoProgressDialog * This,
            /* [string][in] */ __RPC__in LPCWSTR pszProgressText);
        
        HRESULT ( STDMETHODCALLTYPE *SetActionLinkCallback )( 
            IPhotoProgressDialog * This,
            /* [in] */ __RPC__in_opt IPhotoProgressActionCB *pPhotoProgressActionCB);
        
        HRESULT ( STDMETHODCALLTYPE *SetActionLinkText )( 
            IPhotoProgressDialog * This,
            /* [in] */ __RPC__in LPCWSTR pszCaption);
        
        HRESULT ( STDMETHODCALLTYPE *ShowActionLink )( 
            IPhotoProgressDialog * This,
            /* [in] */ BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *IsCancelled )( 
            IPhotoProgressDialog * This,
            /* [out] */ __RPC__out BOOL *pfCancelled);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserInput )( 
            IPhotoProgressDialog * This,
            /* [in] */ __RPC__in REFIID riidType,
            /* [in] */ __RPC__in_opt IUnknown *pUnknown,
            /* [out] */ __RPC__out PROPVARIANT *pPropVarResult,
            /* [unique][in] */ __RPC__in_opt const PROPVARIANT *pPropVarDefault);
        
        END_INTERFACE
    } IPhotoProgressDialogVtbl;

    interface IPhotoProgressDialog
    {
        CONST_VTBL struct IPhotoProgressDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoProgressDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoProgressDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoProgressDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoProgressDialog_Create(This,hwndParent)	\
    ( (This)->lpVtbl -> Create(This,hwndParent) ) 

#define IPhotoProgressDialog_GetWindow(This,phwndProgressDialog)	\
    ( (This)->lpVtbl -> GetWindow(This,phwndProgressDialog) ) 

#define IPhotoProgressDialog_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IPhotoProgressDialog_SetTitle(This,pszTitle)	\
    ( (This)->lpVtbl -> SetTitle(This,pszTitle) ) 

#define IPhotoProgressDialog_ShowCheckbox(This,nCheckboxId,fShow)	\
    ( (This)->lpVtbl -> ShowCheckbox(This,nCheckboxId,fShow) ) 

#define IPhotoProgressDialog_SetCheckboxText(This,nCheckboxId,pszCheckboxText)	\
    ( (This)->lpVtbl -> SetCheckboxText(This,nCheckboxId,pszCheckboxText) ) 

#define IPhotoProgressDialog_SetCheckboxCheck(This,nCheckboxId,fChecked)	\
    ( (This)->lpVtbl -> SetCheckboxCheck(This,nCheckboxId,fChecked) ) 

#define IPhotoProgressDialog_SetCheckboxTooltip(This,nCheckboxId,pszCheckboxTooltipText)	\
    ( (This)->lpVtbl -> SetCheckboxTooltip(This,nCheckboxId,pszCheckboxTooltipText) ) 

#define IPhotoProgressDialog_IsCheckboxChecked(This,nCheckboxId,pfChecked)	\
    ( (This)->lpVtbl -> IsCheckboxChecked(This,nCheckboxId,pfChecked) ) 

#define IPhotoProgressDialog_SetCaption(This,pszTitle)	\
    ( (This)->lpVtbl -> SetCaption(This,pszTitle) ) 

#define IPhotoProgressDialog_SetImage(This,nImageType,hIcon,hBitmap)	\
    ( (This)->lpVtbl -> SetImage(This,nImageType,hIcon,hBitmap) ) 

#define IPhotoProgressDialog_SetPercentComplete(This,nPercent)	\
    ( (This)->lpVtbl -> SetPercentComplete(This,nPercent) ) 

#define IPhotoProgressDialog_SetProgressText(This,pszProgressText)	\
    ( (This)->lpVtbl -> SetProgressText(This,pszProgressText) ) 

#define IPhotoProgressDialog_SetActionLinkCallback(This,pPhotoProgressActionCB)	\
    ( (This)->lpVtbl -> SetActionLinkCallback(This,pPhotoProgressActionCB) ) 

#define IPhotoProgressDialog_SetActionLinkText(This,pszCaption)	\
    ( (This)->lpVtbl -> SetActionLinkText(This,pszCaption) ) 

#define IPhotoProgressDialog_ShowActionLink(This,fShow)	\
    ( (This)->lpVtbl -> ShowActionLink(This,fShow) ) 

#define IPhotoProgressDialog_IsCancelled(This,pfCancelled)	\
    ( (This)->lpVtbl -> IsCancelled(This,pfCancelled) ) 

#define IPhotoProgressDialog_GetUserInput(This,riidType,pUnknown,pPropVarResult,pPropVarDefault)	\
    ( (This)->lpVtbl -> GetUserInput(This,riidType,pUnknown,pPropVarResult,pPropVarDefault) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoProgressDialog_INTERFACE_DEFINED__ */


#ifndef __IPhotoAcquireSource_INTERFACE_DEFINED__
#define __IPhotoAcquireSource_INTERFACE_DEFINED__

/* interface IPhotoAcquireSource */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquireSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f2c703-8613-4282-a53b-6ec59c5883ac")
    IPhotoAcquireSource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFriendlyName( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceIcons( 
            /* [in] */ UINT nSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phLargeIcon,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phSmallIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeItemList( 
            /* [in] */ BOOL fForceEnumeration,
            /* [unique][in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB,
            /* [unique][out][in] */ __RPC__inout_opt UINT *pnItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [out] */ __RPC__out UINT *pnItemCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemAt( 
            /* [in] */ UINT nIndex,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireItem **ppPhotoAcquireItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhotoAcquireSettings( 
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireSettings **ppPhotoAcquireSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceId( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrDeviceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToObject( 
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireSource * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFriendlyName )( 
            IPhotoAcquireSource * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceIcons )( 
            IPhotoAcquireSource * This,
            /* [in] */ UINT nSize,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phLargeIcon,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt HICON *phSmallIcon);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeItemList )( 
            IPhotoAcquireSource * This,
            /* [in] */ BOOL fForceEnumeration,
            /* [unique][in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB,
            /* [unique][out][in] */ __RPC__inout_opt UINT *pnItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IPhotoAcquireSource * This,
            /* [out] */ __RPC__out UINT *pnItemCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemAt )( 
            IPhotoAcquireSource * This,
            /* [in] */ UINT nIndex,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireItem **ppPhotoAcquireItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhotoAcquireSettings )( 
            IPhotoAcquireSource * This,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireSettings **ppPhotoAcquireSettings);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceId )( 
            IPhotoAcquireSource * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrDeviceId);
        
        HRESULT ( STDMETHODCALLTYPE *BindToObject )( 
            IPhotoAcquireSource * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ __RPC__deref_out_opt void **ppv);
        
        END_INTERFACE
    } IPhotoAcquireSourceVtbl;

    interface IPhotoAcquireSource
    {
        CONST_VTBL struct IPhotoAcquireSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireSource_GetFriendlyName(This,pbstrFriendlyName)	\
    ( (This)->lpVtbl -> GetFriendlyName(This,pbstrFriendlyName) ) 

#define IPhotoAcquireSource_GetDeviceIcons(This,nSize,phLargeIcon,phSmallIcon)	\
    ( (This)->lpVtbl -> GetDeviceIcons(This,nSize,phLargeIcon,phSmallIcon) ) 

#define IPhotoAcquireSource_InitializeItemList(This,fForceEnumeration,pPhotoAcquireProgressCB,pnItemCount)	\
    ( (This)->lpVtbl -> InitializeItemList(This,fForceEnumeration,pPhotoAcquireProgressCB,pnItemCount) ) 

#define IPhotoAcquireSource_GetItemCount(This,pnItemCount)	\
    ( (This)->lpVtbl -> GetItemCount(This,pnItemCount) ) 

#define IPhotoAcquireSource_GetItemAt(This,nIndex,ppPhotoAcquireItem)	\
    ( (This)->lpVtbl -> GetItemAt(This,nIndex,ppPhotoAcquireItem) ) 

#define IPhotoAcquireSource_GetPhotoAcquireSettings(This,ppPhotoAcquireSettings)	\
    ( (This)->lpVtbl -> GetPhotoAcquireSettings(This,ppPhotoAcquireSettings) ) 

#define IPhotoAcquireSource_GetDeviceId(This,pbstrDeviceId)	\
    ( (This)->lpVtbl -> GetDeviceId(This,pbstrDeviceId) ) 

#define IPhotoAcquireSource_BindToObject(This,riid,ppv)	\
    ( (This)->lpVtbl -> BindToObject(This,riid,ppv) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireSource_INTERFACE_DEFINED__ */


#ifndef __IPhotoAcquire_INTERFACE_DEFINED__
#define __IPhotoAcquire_INTERFACE_DEFINED__

/* interface IPhotoAcquire */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquire;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f23353-e31b-4955-a8ad-ca5ebf31e2ce")
    IPhotoAcquire : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreatePhotoSource( 
            /* [string][in] */ __RPC__in LPCWSTR pszDevice,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireSource **ppPhotoAcquireSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Acquire( 
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource,
            /* [in] */ BOOL fShowProgress,
            /* [unique][in] */ __RPC__in_opt HWND hWndParent,
            /* [unique][in] */ __RPC__in_opt LPCWSTR pszApplicationName,
            /* [unique][in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumResults( 
            /* [out] */ __RPC__deref_out_opt IEnumString **ppEnumFilePaths) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquire * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquire * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquire * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePhotoSource )( 
            IPhotoAcquire * This,
            /* [string][in] */ __RPC__in LPCWSTR pszDevice,
            /* [out] */ __RPC__deref_out_opt IPhotoAcquireSource **ppPhotoAcquireSource);
        
        HRESULT ( STDMETHODCALLTYPE *Acquire )( 
            IPhotoAcquire * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource,
            /* [in] */ BOOL fShowProgress,
            /* [unique][in] */ __RPC__in_opt HWND hWndParent,
            /* [unique][in] */ __RPC__in_opt LPCWSTR pszApplicationName,
            /* [unique][in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB);
        
        HRESULT ( STDMETHODCALLTYPE *EnumResults )( 
            IPhotoAcquire * This,
            /* [out] */ __RPC__deref_out_opt IEnumString **ppEnumFilePaths);
        
        END_INTERFACE
    } IPhotoAcquireVtbl;

    interface IPhotoAcquire
    {
        CONST_VTBL struct IPhotoAcquireVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquire_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquire_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquire_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquire_CreatePhotoSource(This,pszDevice,ppPhotoAcquireSource)	\
    ( (This)->lpVtbl -> CreatePhotoSource(This,pszDevice,ppPhotoAcquireSource) ) 

#define IPhotoAcquire_Acquire(This,pPhotoAcquireSource,fShowProgress,hWndParent,pszApplicationName,pPhotoAcquireProgressCB)	\
    ( (This)->lpVtbl -> Acquire(This,pPhotoAcquireSource,fShowProgress,hWndParent,pszApplicationName,pPhotoAcquireProgressCB) ) 

#define IPhotoAcquire_EnumResults(This,ppEnumFilePaths)	\
    ( (This)->lpVtbl -> EnumResults(This,ppEnumFilePaths) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquire_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_photoacquire_0000_0007 */
/* [local] */ 

// IPhotoAcquire::Acquire will return this value if a user operation requires a restart.
// If you receive this, you should discard all interfaces and restart completely.
// You can only receive this if you specify the PHOTOACQ_ABORT_ON_SETTINGS_UPDATE flag.
#define PHOTOACQ_ERROR_RESTART_REQUIRED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xA001)
#define PHOTOACQ_RUN_DEFAULT                      0x00000000
#define PHOTOACQ_NO_GALLERY_LAUNCH                0x00000001
#define PHOTOACQ_DISABLE_AUTO_ROTATE              0x00000002
#define PHOTOACQ_DISABLE_PLUGINS                  0x00000004
#define PHOTOACQ_DISABLE_GROUP_TAG_PROMPT         0x00000008
#define PHOTOACQ_DISABLE_DB_INTEGRATION           0x00000010
#define PHOTOACQ_DELETE_AFTER_ACQUIRE             0x00000020
#define PHOTOACQ_DISABLE_DUPLICATE_DETECTION      0x00000040
#define PHOTOACQ_ENABLE_THUMBNAIL_CACHING         0x00000080
#define PHOTOACQ_DISABLE_METADATA_WRITE           0x00000100
#define PHOTOACQ_DISABLE_THUMBNAIL_PROGRESS       0x00000200
#define PHOTOACQ_DISABLE_SETTINGS_LINK            0x00000400
#define PHOTOACQ_ABORT_ON_SETTINGS_UPDATE         0x00000800


extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0007_v0_0_s_ifspec;

#ifndef __IPhotoAcquireSettings_INTERFACE_DEFINED__
#define __IPhotoAcquireSettings_INTERFACE_DEFINED__

/* interface IPhotoAcquireSettings */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquireSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f2b868-dd67-487c-9553-049240767e91")
    IPhotoAcquireSettings : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitializeFromRegistry( 
            /* [in] */ __RPC__in LPCWSTR pszRegistryKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFlags( 
            /* [in] */ DWORD dwPhotoAcquireFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputFilenameTemplate( 
            /* [string][in] */ __RPC__in LPCWSTR pszTemplate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSequencePaddingWidth( 
            /* [in] */ DWORD dwWidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSequenceZeroPadding( 
            /* [in] */ BOOL fZeroPad) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGroupTag( 
            /* [string][in] */ __RPC__in LPCWSTR pszGroupTag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAcquisitionTime( 
            /* [in] */ __RPC__in const FILETIME *pftAcquisitionTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [out] */ __RPC__out DWORD *pdwPhotoAcquireFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFilenameTemplate( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrTemplate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSequencePaddingWidth( 
            /* [out] */ __RPC__out DWORD *pdwWidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSequenceZeroPadding( 
            /* [out] */ __RPC__out BOOL *pfZeroPad) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroupTag( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrGroupTag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAcquisitionTime( 
            /* [out] */ __RPC__out FILETIME *pftAcquisitionTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireSettings * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeFromRegistry )( 
            IPhotoAcquireSettings * This,
            /* [in] */ __RPC__in LPCWSTR pszRegistryKey);
        
        HRESULT ( STDMETHODCALLTYPE *SetFlags )( 
            IPhotoAcquireSettings * This,
            /* [in] */ DWORD dwPhotoAcquireFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputFilenameTemplate )( 
            IPhotoAcquireSettings * This,
            /* [string][in] */ __RPC__in LPCWSTR pszTemplate);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequencePaddingWidth )( 
            IPhotoAcquireSettings * This,
            /* [in] */ DWORD dwWidth);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequenceZeroPadding )( 
            IPhotoAcquireSettings * This,
            /* [in] */ BOOL fZeroPad);
        
        HRESULT ( STDMETHODCALLTYPE *SetGroupTag )( 
            IPhotoAcquireSettings * This,
            /* [string][in] */ __RPC__in LPCWSTR pszGroupTag);
        
        HRESULT ( STDMETHODCALLTYPE *SetAcquisitionTime )( 
            IPhotoAcquireSettings * This,
            /* [in] */ __RPC__in const FILETIME *pftAcquisitionTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__out DWORD *pdwPhotoAcquireFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputFilenameTemplate )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrTemplate);
        
        HRESULT ( STDMETHODCALLTYPE *GetSequencePaddingWidth )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__out DWORD *pdwWidth);
        
        HRESULT ( STDMETHODCALLTYPE *GetSequenceZeroPadding )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__out BOOL *pfZeroPad);
        
        HRESULT ( STDMETHODCALLTYPE *GetGroupTag )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrGroupTag);
        
        HRESULT ( STDMETHODCALLTYPE *GetAcquisitionTime )( 
            IPhotoAcquireSettings * This,
            /* [out] */ __RPC__out FILETIME *pftAcquisitionTime);
        
        END_INTERFACE
    } IPhotoAcquireSettingsVtbl;

    interface IPhotoAcquireSettings
    {
        CONST_VTBL struct IPhotoAcquireSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireSettings_InitializeFromRegistry(This,pszRegistryKey)	\
    ( (This)->lpVtbl -> InitializeFromRegistry(This,pszRegistryKey) ) 

#define IPhotoAcquireSettings_SetFlags(This,dwPhotoAcquireFlags)	\
    ( (This)->lpVtbl -> SetFlags(This,dwPhotoAcquireFlags) ) 

#define IPhotoAcquireSettings_SetOutputFilenameTemplate(This,pszTemplate)	\
    ( (This)->lpVtbl -> SetOutputFilenameTemplate(This,pszTemplate) ) 

#define IPhotoAcquireSettings_SetSequencePaddingWidth(This,dwWidth)	\
    ( (This)->lpVtbl -> SetSequencePaddingWidth(This,dwWidth) ) 

#define IPhotoAcquireSettings_SetSequenceZeroPadding(This,fZeroPad)	\
    ( (This)->lpVtbl -> SetSequenceZeroPadding(This,fZeroPad) ) 

#define IPhotoAcquireSettings_SetGroupTag(This,pszGroupTag)	\
    ( (This)->lpVtbl -> SetGroupTag(This,pszGroupTag) ) 

#define IPhotoAcquireSettings_SetAcquisitionTime(This,pftAcquisitionTime)	\
    ( (This)->lpVtbl -> SetAcquisitionTime(This,pftAcquisitionTime) ) 

#define IPhotoAcquireSettings_GetFlags(This,pdwPhotoAcquireFlags)	\
    ( (This)->lpVtbl -> GetFlags(This,pdwPhotoAcquireFlags) ) 

#define IPhotoAcquireSettings_GetOutputFilenameTemplate(This,pbstrTemplate)	\
    ( (This)->lpVtbl -> GetOutputFilenameTemplate(This,pbstrTemplate) ) 

#define IPhotoAcquireSettings_GetSequencePaddingWidth(This,pdwWidth)	\
    ( (This)->lpVtbl -> GetSequencePaddingWidth(This,pdwWidth) ) 

#define IPhotoAcquireSettings_GetSequenceZeroPadding(This,pfZeroPad)	\
    ( (This)->lpVtbl -> GetSequenceZeroPadding(This,pfZeroPad) ) 

#define IPhotoAcquireSettings_GetGroupTag(This,pbstrGroupTag)	\
    ( (This)->lpVtbl -> GetGroupTag(This,pbstrGroupTag) ) 

#define IPhotoAcquireSettings_GetAcquisitionTime(This,pftAcquisitionTime)	\
    ( (This)->lpVtbl -> GetAcquisitionTime(This,pftAcquisitionTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireSettings_INTERFACE_DEFINED__ */


#ifndef __IPhotoAcquireOptionsDialog_INTERFACE_DEFINED__
#define __IPhotoAcquireOptionsDialog_INTERFACE_DEFINED__

/* interface IPhotoAcquireOptionsDialog */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquireOptionsDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f2b3ee-bf64-47ee-89f4-4dedd79643f2")
    IPhotoAcquireOptionsDialog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [unique][in] */ __RPC__in_opt LPCWSTR pszRegistryRoot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ __RPC__in HWND hWndParent,
            /* [out] */ __RPC__deref_out_opt HWND *phWndDialog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoModal( 
            /* [in] */ __RPC__in HWND hWndParent,
            /* [unique][out][in] */ __RPC__inout_opt INT_PTR *ppnReturnCode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveData( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireOptionsDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireOptionsDialog * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireOptionsDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireOptionsDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPhotoAcquireOptionsDialog * This,
            /* [unique][in] */ __RPC__in_opt LPCWSTR pszRegistryRoot);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IPhotoAcquireOptionsDialog * This,
            /* [in] */ __RPC__in HWND hWndParent,
            /* [out] */ __RPC__deref_out_opt HWND *phWndDialog);
        
        HRESULT ( STDMETHODCALLTYPE *Destroy )( 
            IPhotoAcquireOptionsDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoModal )( 
            IPhotoAcquireOptionsDialog * This,
            /* [in] */ __RPC__in HWND hWndParent,
            /* [unique][out][in] */ __RPC__inout_opt INT_PTR *ppnReturnCode);
        
        HRESULT ( STDMETHODCALLTYPE *SaveData )( 
            IPhotoAcquireOptionsDialog * This);
        
        END_INTERFACE
    } IPhotoAcquireOptionsDialogVtbl;

    interface IPhotoAcquireOptionsDialog
    {
        CONST_VTBL struct IPhotoAcquireOptionsDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireOptionsDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireOptionsDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireOptionsDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireOptionsDialog_Initialize(This,pszRegistryRoot)	\
    ( (This)->lpVtbl -> Initialize(This,pszRegistryRoot) ) 

#define IPhotoAcquireOptionsDialog_Create(This,hWndParent,phWndDialog)	\
    ( (This)->lpVtbl -> Create(This,hWndParent,phWndDialog) ) 

#define IPhotoAcquireOptionsDialog_Destroy(This)	\
    ( (This)->lpVtbl -> Destroy(This) ) 

#define IPhotoAcquireOptionsDialog_DoModal(This,hWndParent,ppnReturnCode)	\
    ( (This)->lpVtbl -> DoModal(This,hWndParent,ppnReturnCode) ) 

#define IPhotoAcquireOptionsDialog_SaveData(This)	\
    ( (This)->lpVtbl -> SaveData(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireOptionsDialog_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_photoacquire_0000_0009 */
/* [local] */ 

#define DSF_WPD_DEVICES    0x00000001
#define DSF_WIA_CAMERAS    0x00000002
#define DSF_WIA_SCANNERS   0x00000004
#define DSF_STI_DEVICES    0x00000008
#define DSF_TWAIN_DEVICES  0x00000010
#define DSF_FS_DEVICES     0x00000020
#define DSF_DV_DEVICES     0x00000040
#define DSF_ALL_DEVICES    0x0000FFFF
#define DSF_CPL_MODE       0x00010000
#define DSF_SHOW_OFFLINE   0x00020000


extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0009_v0_0_s_ifspec;

#ifndef __IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED__
#define __IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED__

/* interface IPhotoAcquireDeviceSelectionDialog */
/* [unique][uuid][object][helpstring] */ 

typedef /* [v1_enum] */ 
enum tagDEVICE_SELECTION_DEVICE_TYPE
    {	DST_UNKNOWN_DEVICE	= 0,
	DST_WPD_DEVICE	= 0x1,
	DST_WIA_DEVICE	= 0x2,
	DST_STI_DEVICE	= 0x3,
	DSF_TWAIN_DEVICE	= 0x4,
	DST_FS_DEVICE	= 0x5,
	DST_DV_DEVICE	= 0x6
    } 	DEVICE_SELECTION_DEVICE_TYPE;


EXTERN_C const IID IID_IPhotoAcquireDeviceSelectionDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f28837-55dd-4f37-aaf5-6855a9640467")
    IPhotoAcquireDeviceSelectionDialog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetTitle( 
            /* [string][in] */ __RPC__in LPCWSTR pszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubmitButtonText( 
            /* [string][in] */ __RPC__in LPCWSTR pszSubmitButtonText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoModal( 
            /* [in] */ __RPC__in HWND hWndParent,
            /* [in] */ DWORD dwDeviceFlags,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt BSTR *pbstrDeviceId,
            /* [unique][out][in] */ __RPC__inout_opt DEVICE_SELECTION_DEVICE_TYPE *pnDeviceType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquireDeviceSelectionDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquireDeviceSelectionDialog * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquireDeviceSelectionDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquireDeviceSelectionDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTitle )( 
            IPhotoAcquireDeviceSelectionDialog * This,
            /* [string][in] */ __RPC__in LPCWSTR pszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubmitButtonText )( 
            IPhotoAcquireDeviceSelectionDialog * This,
            /* [string][in] */ __RPC__in LPCWSTR pszSubmitButtonText);
        
        HRESULT ( STDMETHODCALLTYPE *DoModal )( 
            IPhotoAcquireDeviceSelectionDialog * This,
            /* [in] */ __RPC__in HWND hWndParent,
            /* [in] */ DWORD dwDeviceFlags,
            /* [unique][out][in] */ __RPC__deref_opt_inout_opt BSTR *pbstrDeviceId,
            /* [unique][out][in] */ __RPC__inout_opt DEVICE_SELECTION_DEVICE_TYPE *pnDeviceType);
        
        END_INTERFACE
    } IPhotoAcquireDeviceSelectionDialogVtbl;

    interface IPhotoAcquireDeviceSelectionDialog
    {
        CONST_VTBL struct IPhotoAcquireDeviceSelectionDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquireDeviceSelectionDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquireDeviceSelectionDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquireDeviceSelectionDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquireDeviceSelectionDialog_SetTitle(This,pszTitle)	\
    ( (This)->lpVtbl -> SetTitle(This,pszTitle) ) 

#define IPhotoAcquireDeviceSelectionDialog_SetSubmitButtonText(This,pszSubmitButtonText)	\
    ( (This)->lpVtbl -> SetSubmitButtonText(This,pszSubmitButtonText) ) 

#define IPhotoAcquireDeviceSelectionDialog_DoModal(This,hWndParent,dwDeviceFlags,pbstrDeviceId,pnDeviceType)	\
    ( (This)->lpVtbl -> DoModal(This,hWndParent,dwDeviceFlags,pbstrDeviceId,pnDeviceType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquireDeviceSelectionDialog_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_photoacquire_0000_0010 */
/* [local] */ 

#define PAPS_PRESAVE   0x00000000
#define PAPS_POSTSAVE  0x00000001
#define PAPS_CLEANUP   0x00000002


extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0010_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_photoacquire_0000_0010_v0_0_s_ifspec;

#ifndef __IPhotoAcquirePlugin_INTERFACE_DEFINED__
#define __IPhotoAcquirePlugin_INTERFACE_DEFINED__

/* interface IPhotoAcquirePlugin */
/* [unique][uuid][object][helpstring] */ 


EXTERN_C const IID IID_IPhotoAcquirePlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00f2dceb-ecb8-4f77-8e47-e7a987c83dd0")
    IPhotoAcquirePlugin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource,
            /* [in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessItem( 
            /* [in] */ DWORD dwAcquireStage,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ __RPC__in_opt IStream *pOriginalItemStream,
            /* [in] */ __RPC__in LPCWSTR pszFinalFilename,
            /* [in] */ __RPC__in_opt IPropertyStore *pPropertyStore) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransferComplete( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisplayConfigureDialog( 
            __RPC__in HWND hWndParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPhotoAcquirePluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPhotoAcquirePlugin * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPhotoAcquirePlugin * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPhotoAcquirePlugin * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPhotoAcquirePlugin * This,
            /* [in] */ __RPC__in_opt IPhotoAcquireSource *pPhotoAcquireSource,
            /* [in] */ __RPC__in_opt IPhotoAcquireProgressCB *pPhotoAcquireProgressCB);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessItem )( 
            IPhotoAcquirePlugin * This,
            /* [in] */ DWORD dwAcquireStage,
            /* [in] */ __RPC__in_opt IPhotoAcquireItem *pPhotoAcquireItem,
            /* [in] */ __RPC__in_opt IStream *pOriginalItemStream,
            /* [in] */ __RPC__in LPCWSTR pszFinalFilename,
            /* [in] */ __RPC__in_opt IPropertyStore *pPropertyStore);
        
        HRESULT ( STDMETHODCALLTYPE *TransferComplete )( 
            IPhotoAcquirePlugin * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *DisplayConfigureDialog )( 
            IPhotoAcquirePlugin * This,
            __RPC__in HWND hWndParent);
        
        END_INTERFACE
    } IPhotoAcquirePluginVtbl;

    interface IPhotoAcquirePlugin
    {
        CONST_VTBL struct IPhotoAcquirePluginVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPhotoAcquirePlugin_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPhotoAcquirePlugin_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPhotoAcquirePlugin_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPhotoAcquirePlugin_Initialize(This,pPhotoAcquireSource,pPhotoAcquireProgressCB)	\
    ( (This)->lpVtbl -> Initialize(This,pPhotoAcquireSource,pPhotoAcquireProgressCB) ) 

#define IPhotoAcquirePlugin_ProcessItem(This,dwAcquireStage,pPhotoAcquireItem,pOriginalItemStream,pszFinalFilename,pPropertyStore)	\
    ( (This)->lpVtbl -> ProcessItem(This,dwAcquireStage,pPhotoAcquireItem,pOriginalItemStream,pszFinalFilename,pPropertyStore) ) 

#define IPhotoAcquirePlugin_TransferComplete(This,hr)	\
    ( (This)->lpVtbl -> TransferComplete(This,hr) ) 

#define IPhotoAcquirePlugin_DisplayConfigureDialog(This,hWndParent)	\
    ( (This)->lpVtbl -> DisplayConfigureDialog(This,hWndParent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPhotoAcquirePlugin_INTERFACE_DEFINED__ */



#ifndef __PhotoAcquireObjects_LIBRARY_DEFINED__
#define __PhotoAcquireObjects_LIBRARY_DEFINED__

/* library PhotoAcquireObjects */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PhotoAcquireObjects;

EXTERN_C const CLSID CLSID_PhotoAcquire;

#ifdef __cplusplus

class DECLSPEC_UUID("00f26e02-e9f2-4a9f-9fdd-5a962fb26a98")
PhotoAcquire;
#endif

EXTERN_C const CLSID CLSID_PhotoAcquireAutoPlayDropTarget;

#ifdef __cplusplus

class DECLSPEC_UUID("00f20eb5-8fd6-4d9d-b75e-36801766c8f1")
PhotoAcquireAutoPlayDropTarget;
#endif

EXTERN_C const CLSID CLSID_PhotoAcquireAutoPlayHWEventHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("00f2b433-44e4-4d88-b2b0-2698a0a91dba")
PhotoAcquireAutoPlayHWEventHandler;
#endif

EXTERN_C const CLSID CLSID_PhotoAcquireOptionsDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("00f210a1-62f0-438b-9f7e-9618d72a1831")
PhotoAcquireOptionsDialog;
#endif

EXTERN_C const CLSID CLSID_PhotoProgressDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("00f24ca0-748f-4e8a-894f-0e0357c6799f")
PhotoProgressDialog;
#endif

EXTERN_C const CLSID CLSID_PhotoAcquireDeviceSelectionDialog;

#ifdef __cplusplus

class DECLSPEC_UUID("00f29a34-b8a1-482c-bcf8-3ac7b0fe8f62")
PhotoAcquireDeviceSelectionDialog;
#endif
#endif /* __PhotoAcquireObjects_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HICON_UserSize(     unsigned long *, unsigned long            , HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal(  unsigned long *, unsigned char *, HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal(unsigned long *, unsigned char *, HICON * ); 
void                      __RPC_USER  HICON_UserFree(     unsigned long *, HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize64(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal64(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal64(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree64(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HICON_UserSize64(     unsigned long *, unsigned long            , HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal64(  unsigned long *, unsigned char *, HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal64(unsigned long *, unsigned char *, HICON * ); 
void                      __RPC_USER  HICON_UserFree64(     unsigned long *, HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



