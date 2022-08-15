

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for uiautomationcore.idl:
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


#ifndef __uiautomationcore_h__
#define __uiautomationcore_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRawElementProviderSimple_FWD_DEFINED__
#define __IRawElementProviderSimple_FWD_DEFINED__
typedef interface IRawElementProviderSimple IRawElementProviderSimple;
#endif 	/* __IRawElementProviderSimple_FWD_DEFINED__ */


#ifndef __IRawElementProviderFragmentRoot_FWD_DEFINED__
#define __IRawElementProviderFragmentRoot_FWD_DEFINED__
typedef interface IRawElementProviderFragmentRoot IRawElementProviderFragmentRoot;
#endif 	/* __IRawElementProviderFragmentRoot_FWD_DEFINED__ */


#ifndef __IRawElementProviderFragment_FWD_DEFINED__
#define __IRawElementProviderFragment_FWD_DEFINED__
typedef interface IRawElementProviderFragment IRawElementProviderFragment;
#endif 	/* __IRawElementProviderFragment_FWD_DEFINED__ */


#ifndef __IRawElementProviderAdviseEvents_FWD_DEFINED__
#define __IRawElementProviderAdviseEvents_FWD_DEFINED__
typedef interface IRawElementProviderAdviseEvents IRawElementProviderAdviseEvents;
#endif 	/* __IRawElementProviderAdviseEvents_FWD_DEFINED__ */


#ifndef __IRawElementProviderHwndOverride_FWD_DEFINED__
#define __IRawElementProviderHwndOverride_FWD_DEFINED__
typedef interface IRawElementProviderHwndOverride IRawElementProviderHwndOverride;
#endif 	/* __IRawElementProviderHwndOverride_FWD_DEFINED__ */


#ifndef __IDockProvider_FWD_DEFINED__
#define __IDockProvider_FWD_DEFINED__
typedef interface IDockProvider IDockProvider;
#endif 	/* __IDockProvider_FWD_DEFINED__ */


#ifndef __IExpandCollapseProvider_FWD_DEFINED__
#define __IExpandCollapseProvider_FWD_DEFINED__
typedef interface IExpandCollapseProvider IExpandCollapseProvider;
#endif 	/* __IExpandCollapseProvider_FWD_DEFINED__ */


#ifndef __IGridProvider_FWD_DEFINED__
#define __IGridProvider_FWD_DEFINED__
typedef interface IGridProvider IGridProvider;
#endif 	/* __IGridProvider_FWD_DEFINED__ */


#ifndef __IGridItemProvider_FWD_DEFINED__
#define __IGridItemProvider_FWD_DEFINED__
typedef interface IGridItemProvider IGridItemProvider;
#endif 	/* __IGridItemProvider_FWD_DEFINED__ */


#ifndef __IInvokeProvider_FWD_DEFINED__
#define __IInvokeProvider_FWD_DEFINED__
typedef interface IInvokeProvider IInvokeProvider;
#endif 	/* __IInvokeProvider_FWD_DEFINED__ */


#ifndef __IMultipleViewProvider_FWD_DEFINED__
#define __IMultipleViewProvider_FWD_DEFINED__
typedef interface IMultipleViewProvider IMultipleViewProvider;
#endif 	/* __IMultipleViewProvider_FWD_DEFINED__ */


#ifndef __IRangeValueProvider_FWD_DEFINED__
#define __IRangeValueProvider_FWD_DEFINED__
typedef interface IRangeValueProvider IRangeValueProvider;
#endif 	/* __IRangeValueProvider_FWD_DEFINED__ */


#ifndef __IScrollItemProvider_FWD_DEFINED__
#define __IScrollItemProvider_FWD_DEFINED__
typedef interface IScrollItemProvider IScrollItemProvider;
#endif 	/* __IScrollItemProvider_FWD_DEFINED__ */


#ifndef __ISelectionProvider_FWD_DEFINED__
#define __ISelectionProvider_FWD_DEFINED__
typedef interface ISelectionProvider ISelectionProvider;
#endif 	/* __ISelectionProvider_FWD_DEFINED__ */


#ifndef __IScrollProvider_FWD_DEFINED__
#define __IScrollProvider_FWD_DEFINED__
typedef interface IScrollProvider IScrollProvider;
#endif 	/* __IScrollProvider_FWD_DEFINED__ */


#ifndef __ISelectionItemProvider_FWD_DEFINED__
#define __ISelectionItemProvider_FWD_DEFINED__
typedef interface ISelectionItemProvider ISelectionItemProvider;
#endif 	/* __ISelectionItemProvider_FWD_DEFINED__ */


#ifndef __ITableProvider_FWD_DEFINED__
#define __ITableProvider_FWD_DEFINED__
typedef interface ITableProvider ITableProvider;
#endif 	/* __ITableProvider_FWD_DEFINED__ */


#ifndef __ITableItemProvider_FWD_DEFINED__
#define __ITableItemProvider_FWD_DEFINED__
typedef interface ITableItemProvider ITableItemProvider;
#endif 	/* __ITableItemProvider_FWD_DEFINED__ */


#ifndef __IToggleProvider_FWD_DEFINED__
#define __IToggleProvider_FWD_DEFINED__
typedef interface IToggleProvider IToggleProvider;
#endif 	/* __IToggleProvider_FWD_DEFINED__ */


#ifndef __ITransformProvider_FWD_DEFINED__
#define __ITransformProvider_FWD_DEFINED__
typedef interface ITransformProvider ITransformProvider;
#endif 	/* __ITransformProvider_FWD_DEFINED__ */


#ifndef __IValueProvider_FWD_DEFINED__
#define __IValueProvider_FWD_DEFINED__
typedef interface IValueProvider IValueProvider;
#endif 	/* __IValueProvider_FWD_DEFINED__ */


#ifndef __IWindowProvider_FWD_DEFINED__
#define __IWindowProvider_FWD_DEFINED__
typedef interface IWindowProvider IWindowProvider;
#endif 	/* __IWindowProvider_FWD_DEFINED__ */


#ifndef __ITextRangeProvider_FWD_DEFINED__
#define __ITextRangeProvider_FWD_DEFINED__
typedef interface ITextRangeProvider ITextRangeProvider;
#endif 	/* __ITextRangeProvider_FWD_DEFINED__ */


#ifndef __ITextProvider_FWD_DEFINED__
#define __ITextProvider_FWD_DEFINED__
typedef interface ITextProvider ITextProvider;
#endif 	/* __ITextProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_uiautomationcore_0000_0000 */
/* [local] */ 

// -------------------------------------------------------------
// UIAutomationCore.H
//
// UIAutomation interface definitions and related types and enums
// (Generated from UIAutomationCore.idl)
//
// Copyright (c) Microsoft Corporation. All rights reserved.
// -------------------------------------------------------------

enum NavigateDirection
    {	NavigateDirection_Parent	= 0,
	NavigateDirection_NextSibling	= 1,
	NavigateDirection_PreviousSibling	= 2,
	NavigateDirection_FirstChild	= 3,
	NavigateDirection_LastChild	= 4
    } ;

enum ProviderOptions
    {	ProviderOptions_ClientSideProvider	= 0x1,
	ProviderOptions_ServerSideProvider	= 0x2,
	ProviderOptions_NonClientAreaProvider	= 0x4,
	ProviderOptions_OverrideProvider	= 0x8,
	ProviderOptions_ProviderOwnsSetFocus	= 0x10
    } ;

enum OrientationType
    {	OrientationType_None	= 0,
	OrientationType_Horizontal	= 1,
	OrientationType_Vertical	= 2
    } ;

enum DockPosition
    {	DockPosition_Top	= 0,
	DockPosition_Left	= 1,
	DockPosition_Bottom	= 2,
	DockPosition_Right	= 3,
	DockPosition_Fill	= 4,
	DockPosition_None	= 5
    } ;

enum ExpandCollapseState
    {	ExpandCollapseState_Collapsed	= 0,
	ExpandCollapseState_Expanded	= 1,
	ExpandCollapseState_PartiallyExpanded	= 2,
	ExpandCollapseState_LeafNode	= 3
    } ;

enum ScrollAmount
    {	ScrollAmount_LargeDecrement	= 0,
	ScrollAmount_SmallDecrement	= 1,
	ScrollAmount_NoAmount	= 2,
	ScrollAmount_LargeIncrement	= 3,
	ScrollAmount_SmallIncrement	= 4
    } ;

enum RowOrColumnMajor
    {	RowOrColumnMajor_RowMajor	= 0,
	RowOrColumnMajor_ColumnMajor	= 1,
	RowOrColumnMajor_Indeterminate	= 2
    } ;

enum ToggleState
    {	ToggleState_Off	= 0,
	ToggleState_On	= 1,
	ToggleState_Indeterminate	= 2
    } ;

enum WindowVisualState
    {	WindowVisualState_Normal	= 0,
	WindowVisualState_Maximized	= 1,
	WindowVisualState_Minimized	= 2
    } ;

enum WindowInteractionState
    {	WindowInteractionState_Running	= 0,
	WindowInteractionState_Closing	= 1,
	WindowInteractionState_ReadyForUserInteraction	= 2,
	WindowInteractionState_BlockedByModalWindow	= 3,
	WindowInteractionState_NotResponding	= 4
    } ;

enum TextUnit
    {	TextUnit_Character	= 0,
	TextUnit_Format	= 1,
	TextUnit_Word	= 2,
	TextUnit_Line	= 3,
	TextUnit_Paragraph	= 4,
	TextUnit_Page	= 5,
	TextUnit_Document	= 6
    } ;

enum TextPatternRangeEndpoint
    {	TextPatternRangeEndpoint_Start	= 0,
	TextPatternRangeEndpoint_End	= 1
    } ;

enum SupportedTextSelection
    {	SupportedTextSelection_None	= 0,
	SupportedTextSelection_Single	= 1,
	SupportedTextSelection_Multiple	= 2
    } ;

enum AnimationStyle
    {	AnimationStyle_None	= 0,
	AnimationStyle_LasVegasLights	= 1,
	AnimationStyle_BlinkingBackground	= 2,
	AnimationStyle_SparkleText	= 3,
	AnimationStyle_MarchingBlackAnts	= 4,
	AnimationStyle_MarchingRedAnts	= 5,
	AnimationStyle_Shimmer	= 6,
	AnimationStyle_Other	= -1
    } ;

enum BulletStyle
    {	BulletStyle_None	= 0,
	BulletStyle_HollowRoundBullet	= 1,
	BulletStyle_FilledRoundBullet	= 2,
	BulletStyle_HollowSquareBullet	= 3,
	BulletStyle_FilledSquareBullet	= 4,
	BulletStyle_DashBullet	= 5,
	BulletStyle_Other	= -1
    } ;

enum CapStyle
    {	CapStyle_None	= 0,
	CapStyle_SmallCap	= 1,
	CapStyle_AllCap	= 2,
	CapStyle_AllPetiteCaps	= 3,
	CapStyle_PetiteCaps	= 4,
	CapStyle_Unicase	= 5,
	CapStyle_Titling	= 6,
	CapStyle_Other	= -1
    } ;

enum FlowDirections
    {	FlowDirections_Default	= 0,
	FlowDirections_RightToLeft	= 1,
	FlowDirections_BottomToTop	= 2,
	FlowDirections_Vertical	= 4
    } ;

enum HorizontalTextAlignment
    {	HorizontalTextAlignment_Left	= 0,
	HorizontalTextAlignment_Centered	= 1,
	HorizontalTextAlignment_Right	= 2,
	HorizontalTextAlignment_Justified	= 3
    } ;

enum OutlineStyles
    {	OutlineStyles_None	= 0,
	OutlineStyles_Outline	= 1,
	OutlineStyles_Shadow	= 2,
	OutlineStyles_Engraved	= 4,
	OutlineStyles_Embossed	= 8
    } ;

enum TextDecorationLineStyle
    {	TextDecorationLineStyle_None	= 0,
	TextDecorationLineStyle_Single	= 1,
	TextDecorationLineStyle_WordsOnly	= 2,
	TextDecorationLineStyle_Double	= 3,
	TextDecorationLineStyle_Dot	= 4,
	TextDecorationLineStyle_Dash	= 5,
	TextDecorationLineStyle_DashDot	= 6,
	TextDecorationLineStyle_DashDotDot	= 7,
	TextDecorationLineStyle_Wavy	= 8,
	TextDecorationLineStyle_ThickSingle	= 9,
	TextDecorationLineStyle_DoubleWavy	= 11,
	TextDecorationLineStyle_ThickWavy	= 12,
	TextDecorationLineStyle_LongDash	= 13,
	TextDecorationLineStyle_ThickDash	= 14,
	TextDecorationLineStyle_ThickDashDot	= 15,
	TextDecorationLineStyle_ThickDashDotDot	= 16,
	TextDecorationLineStyle_ThickDot	= 17,
	TextDecorationLineStyle_ThickLongDash	= 18,
	TextDecorationLineStyle_Other	= -1
    } ;
typedef int PROPERTYID;

typedef int PATTERNID;

typedef int EVENTID;

typedef int TEXTATTRIBUTEID;

typedef int CONTROLTYPEID;

struct UiaRect
    {
    double left;
    double top;
    double width;
    double height;
    } ;
struct UiaPoint
    {
    double x;
    double y;
    } ;


extern RPC_IF_HANDLE __MIDL_itf_uiautomationcore_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_uiautomationcore_0000_0000_v0_0_s_ifspec;


#ifndef __UIA_LIBRARY_DEFINED__
#define __UIA_LIBRARY_DEFINED__

/* library UIA */
/* [hidden][version][lcid][uuid] */ 




EXTERN_C const IID LIBID_UIA;

#ifndef __IRawElementProviderSimple_INTERFACE_DEFINED__
#define __IRawElementProviderSimple_INTERFACE_DEFINED__

/* interface IRawElementProviderSimple */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRawElementProviderSimple;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d6dd68d1-86fd-4332-8666-9abedea2d24c")
    IRawElementProviderSimple : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProviderOptions( 
            /* [retval][out] */ __RPC__out enum ProviderOptions *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPatternProvider( 
            /* [in] */ PATTERNID patternId,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyValue( 
            /* [in] */ PROPERTYID propertyId,
            /* [retval][out] */ __RPC__out VARIANT *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HostRawElementProvider( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRawElementProviderSimpleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRawElementProviderSimple * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRawElementProviderSimple * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRawElementProviderSimple * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderOptions )( 
            IRawElementProviderSimple * This,
            /* [retval][out] */ __RPC__out enum ProviderOptions *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetPatternProvider )( 
            IRawElementProviderSimple * This,
            /* [in] */ PATTERNID patternId,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyValue )( 
            IRawElementProviderSimple * This,
            /* [in] */ PROPERTYID propertyId,
            /* [retval][out] */ __RPC__out VARIANT *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostRawElementProvider )( 
            IRawElementProviderSimple * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        END_INTERFACE
    } IRawElementProviderSimpleVtbl;

    interface IRawElementProviderSimple
    {
        CONST_VTBL struct IRawElementProviderSimpleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRawElementProviderSimple_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRawElementProviderSimple_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRawElementProviderSimple_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRawElementProviderSimple_get_ProviderOptions(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ProviderOptions(This,pRetVal) ) 

#define IRawElementProviderSimple_GetPatternProvider(This,patternId,pRetVal)	\
    ( (This)->lpVtbl -> GetPatternProvider(This,patternId,pRetVal) ) 

#define IRawElementProviderSimple_GetPropertyValue(This,propertyId,pRetVal)	\
    ( (This)->lpVtbl -> GetPropertyValue(This,propertyId,pRetVal) ) 

#define IRawElementProviderSimple_get_HostRawElementProvider(This,pRetVal)	\
    ( (This)->lpVtbl -> get_HostRawElementProvider(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRawElementProviderSimple_INTERFACE_DEFINED__ */


#ifndef __IRawElementProviderFragmentRoot_INTERFACE_DEFINED__
#define __IRawElementProviderFragmentRoot_INTERFACE_DEFINED__

/* interface IRawElementProviderFragmentRoot */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRawElementProviderFragmentRoot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("620ce2a5-ab8f-40a9-86cb-de3c75599b58")
    IRawElementProviderFragmentRoot : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ElementProviderFromPoint( 
            /* [in] */ double x,
            /* [in] */ double y,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFocus( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRawElementProviderFragmentRootVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRawElementProviderFragmentRoot * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRawElementProviderFragmentRoot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRawElementProviderFragmentRoot * This);
        
        HRESULT ( STDMETHODCALLTYPE *ElementProviderFromPoint )( 
            IRawElementProviderFragmentRoot * This,
            /* [in] */ double x,
            /* [in] */ double y,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFocus )( 
            IRawElementProviderFragmentRoot * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal);
        
        END_INTERFACE
    } IRawElementProviderFragmentRootVtbl;

    interface IRawElementProviderFragmentRoot
    {
        CONST_VTBL struct IRawElementProviderFragmentRootVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRawElementProviderFragmentRoot_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRawElementProviderFragmentRoot_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRawElementProviderFragmentRoot_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRawElementProviderFragmentRoot_ElementProviderFromPoint(This,x,y,pRetVal)	\
    ( (This)->lpVtbl -> ElementProviderFromPoint(This,x,y,pRetVal) ) 

#define IRawElementProviderFragmentRoot_GetFocus(This,pRetVal)	\
    ( (This)->lpVtbl -> GetFocus(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRawElementProviderFragmentRoot_INTERFACE_DEFINED__ */


#ifndef __IRawElementProviderFragment_INTERFACE_DEFINED__
#define __IRawElementProviderFragment_INTERFACE_DEFINED__

/* interface IRawElementProviderFragment */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRawElementProviderFragment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f7063da8-8359-439c-9297-bbc5299a7d87")
    IRawElementProviderFragment : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Navigate( 
            /* [in] */ enum NavigateDirection direction,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRuntimeId( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_BoundingRectangle( 
            /* [retval][out] */ __RPC__out struct UiaRect *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEmbeddedFragmentRoots( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFocus( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FragmentRoot( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragmentRoot **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRawElementProviderFragmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRawElementProviderFragment * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRawElementProviderFragment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRawElementProviderFragment * This);
        
        HRESULT ( STDMETHODCALLTYPE *Navigate )( 
            IRawElementProviderFragment * This,
            /* [in] */ enum NavigateDirection direction,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeId )( 
            IRawElementProviderFragment * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *get_BoundingRectangle )( 
            IRawElementProviderFragment * This,
            /* [retval][out] */ __RPC__out struct UiaRect *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetEmbeddedFragmentRoots )( 
            IRawElementProviderFragment * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetFocus )( 
            IRawElementProviderFragment * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_FragmentRoot )( 
            IRawElementProviderFragment * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragmentRoot **pRetVal);
        
        END_INTERFACE
    } IRawElementProviderFragmentVtbl;

    interface IRawElementProviderFragment
    {
        CONST_VTBL struct IRawElementProviderFragmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRawElementProviderFragment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRawElementProviderFragment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRawElementProviderFragment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRawElementProviderFragment_Navigate(This,direction,pRetVal)	\
    ( (This)->lpVtbl -> Navigate(This,direction,pRetVal) ) 

#define IRawElementProviderFragment_GetRuntimeId(This,pRetVal)	\
    ( (This)->lpVtbl -> GetRuntimeId(This,pRetVal) ) 

#define IRawElementProviderFragment_get_BoundingRectangle(This,pRetVal)	\
    ( (This)->lpVtbl -> get_BoundingRectangle(This,pRetVal) ) 

#define IRawElementProviderFragment_GetEmbeddedFragmentRoots(This,pRetVal)	\
    ( (This)->lpVtbl -> GetEmbeddedFragmentRoots(This,pRetVal) ) 

#define IRawElementProviderFragment_SetFocus(This)	\
    ( (This)->lpVtbl -> SetFocus(This) ) 

#define IRawElementProviderFragment_get_FragmentRoot(This,pRetVal)	\
    ( (This)->lpVtbl -> get_FragmentRoot(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRawElementProviderFragment_INTERFACE_DEFINED__ */


#ifndef __IRawElementProviderAdviseEvents_INTERFACE_DEFINED__
#define __IRawElementProviderAdviseEvents_INTERFACE_DEFINED__

/* interface IRawElementProviderAdviseEvents */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRawElementProviderAdviseEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a407b27b-0f6d-4427-9292-473c7bf93258")
    IRawElementProviderAdviseEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseEventAdded( 
            /* [in] */ EVENTID eventId,
            /* [in] */ __RPC__in SAFEARRAY * propertyIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdviseEventRemoved( 
            /* [in] */ EVENTID eventId,
            /* [in] */ __RPC__in SAFEARRAY * propertyIDs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRawElementProviderAdviseEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRawElementProviderAdviseEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRawElementProviderAdviseEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRawElementProviderAdviseEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseEventAdded )( 
            IRawElementProviderAdviseEvents * This,
            /* [in] */ EVENTID eventId,
            /* [in] */ __RPC__in SAFEARRAY * propertyIDs);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseEventRemoved )( 
            IRawElementProviderAdviseEvents * This,
            /* [in] */ EVENTID eventId,
            /* [in] */ __RPC__in SAFEARRAY * propertyIDs);
        
        END_INTERFACE
    } IRawElementProviderAdviseEventsVtbl;

    interface IRawElementProviderAdviseEvents
    {
        CONST_VTBL struct IRawElementProviderAdviseEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRawElementProviderAdviseEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRawElementProviderAdviseEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRawElementProviderAdviseEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRawElementProviderAdviseEvents_AdviseEventAdded(This,eventId,propertyIDs)	\
    ( (This)->lpVtbl -> AdviseEventAdded(This,eventId,propertyIDs) ) 

#define IRawElementProviderAdviseEvents_AdviseEventRemoved(This,eventId,propertyIDs)	\
    ( (This)->lpVtbl -> AdviseEventRemoved(This,eventId,propertyIDs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRawElementProviderAdviseEvents_INTERFACE_DEFINED__ */


#ifndef __IRawElementProviderHwndOverride_INTERFACE_DEFINED__
#define __IRawElementProviderHwndOverride_INTERFACE_DEFINED__

/* interface IRawElementProviderHwndOverride */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRawElementProviderHwndOverride;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1d5df27c-8947-4425-b8d9-79787bb460b8")
    IRawElementProviderHwndOverride : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOverrideProviderForHwnd( 
            /* [in] */ __RPC__in HWND hwnd,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRawElementProviderHwndOverrideVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRawElementProviderHwndOverride * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRawElementProviderHwndOverride * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRawElementProviderHwndOverride * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetOverrideProviderForHwnd )( 
            IRawElementProviderHwndOverride * This,
            /* [in] */ __RPC__in HWND hwnd,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        END_INTERFACE
    } IRawElementProviderHwndOverrideVtbl;

    interface IRawElementProviderHwndOverride
    {
        CONST_VTBL struct IRawElementProviderHwndOverrideVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRawElementProviderHwndOverride_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRawElementProviderHwndOverride_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRawElementProviderHwndOverride_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRawElementProviderHwndOverride_GetOverrideProviderForHwnd(This,hwnd,pRetVal)	\
    ( (This)->lpVtbl -> GetOverrideProviderForHwnd(This,hwnd,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRawElementProviderHwndOverride_INTERFACE_DEFINED__ */


#ifndef __IDockProvider_INTERFACE_DEFINED__
#define __IDockProvider_INTERFACE_DEFINED__

/* interface IDockProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDockProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("159bc72c-4ad3-485e-9637-d7052edf0146")
    IDockProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetDockPosition( 
            /* [in] */ enum DockPosition dockPosition) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DockPosition( 
            /* [retval][out] */ __RPC__out enum DockPosition *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDockProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDockProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDockProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDockProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDockPosition )( 
            IDockProvider * This,
            /* [in] */ enum DockPosition dockPosition);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DockPosition )( 
            IDockProvider * This,
            /* [retval][out] */ __RPC__out enum DockPosition *pRetVal);
        
        END_INTERFACE
    } IDockProviderVtbl;

    interface IDockProvider
    {
        CONST_VTBL struct IDockProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDockProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDockProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDockProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDockProvider_SetDockPosition(This,dockPosition)	\
    ( (This)->lpVtbl -> SetDockPosition(This,dockPosition) ) 

#define IDockProvider_get_DockPosition(This,pRetVal)	\
    ( (This)->lpVtbl -> get_DockPosition(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDockProvider_INTERFACE_DEFINED__ */


#ifndef __IExpandCollapseProvider_INTERFACE_DEFINED__
#define __IExpandCollapseProvider_INTERFACE_DEFINED__

/* interface IExpandCollapseProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IExpandCollapseProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d847d3a5-cab0-4a98-8c32-ecb45c59ad24")
    IExpandCollapseProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Expand( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Collapse( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ExpandCollapseState( 
            /* [retval][out] */ __RPC__out enum ExpandCollapseState *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExpandCollapseProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExpandCollapseProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExpandCollapseProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExpandCollapseProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Expand )( 
            IExpandCollapseProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Collapse )( 
            IExpandCollapseProvider * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExpandCollapseState )( 
            IExpandCollapseProvider * This,
            /* [retval][out] */ __RPC__out enum ExpandCollapseState *pRetVal);
        
        END_INTERFACE
    } IExpandCollapseProviderVtbl;

    interface IExpandCollapseProvider
    {
        CONST_VTBL struct IExpandCollapseProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExpandCollapseProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExpandCollapseProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExpandCollapseProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExpandCollapseProvider_Expand(This)	\
    ( (This)->lpVtbl -> Expand(This) ) 

#define IExpandCollapseProvider_Collapse(This)	\
    ( (This)->lpVtbl -> Collapse(This) ) 

#define IExpandCollapseProvider_get_ExpandCollapseState(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ExpandCollapseState(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExpandCollapseProvider_INTERFACE_DEFINED__ */


#ifndef __IGridProvider_INTERFACE_DEFINED__
#define __IGridProvider_INTERFACE_DEFINED__

/* interface IGridProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IGridProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b17d6187-0907-464b-a168-0ef17a1572b1")
    IGridProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ int row,
            /* [in] */ int column,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RowCount( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ColumnCount( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGridProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGridProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGridProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGridProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IGridProvider * This,
            /* [in] */ int row,
            /* [in] */ int column,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowCount )( 
            IGridProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnCount )( 
            IGridProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        END_INTERFACE
    } IGridProviderVtbl;

    interface IGridProvider
    {
        CONST_VTBL struct IGridProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGridProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGridProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGridProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGridProvider_GetItem(This,row,column,pRetVal)	\
    ( (This)->lpVtbl -> GetItem(This,row,column,pRetVal) ) 

#define IGridProvider_get_RowCount(This,pRetVal)	\
    ( (This)->lpVtbl -> get_RowCount(This,pRetVal) ) 

#define IGridProvider_get_ColumnCount(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ColumnCount(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGridProvider_INTERFACE_DEFINED__ */


#ifndef __IGridItemProvider_INTERFACE_DEFINED__
#define __IGridItemProvider_INTERFACE_DEFINED__

/* interface IGridItemProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IGridItemProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("d02541f1-fb81-4d64-ae32-f520f8a6dbd1")
    IGridItemProvider : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Column( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RowSpan( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ColumnSpan( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContainingGrid( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGridItemProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGridItemProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGridItemProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGridItemProvider * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Row )( 
            IGridItemProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Column )( 
            IGridItemProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowSpan )( 
            IGridItemProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColumnSpan )( 
            IGridItemProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContainingGrid )( 
            IGridItemProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        END_INTERFACE
    } IGridItemProviderVtbl;

    interface IGridItemProvider
    {
        CONST_VTBL struct IGridItemProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGridItemProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGridItemProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGridItemProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGridItemProvider_get_Row(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Row(This,pRetVal) ) 

#define IGridItemProvider_get_Column(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Column(This,pRetVal) ) 

#define IGridItemProvider_get_RowSpan(This,pRetVal)	\
    ( (This)->lpVtbl -> get_RowSpan(This,pRetVal) ) 

#define IGridItemProvider_get_ColumnSpan(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ColumnSpan(This,pRetVal) ) 

#define IGridItemProvider_get_ContainingGrid(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ContainingGrid(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGridItemProvider_INTERFACE_DEFINED__ */


#ifndef __IInvokeProvider_INTERFACE_DEFINED__
#define __IInvokeProvider_INTERFACE_DEFINED__

/* interface IInvokeProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IInvokeProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54fcb24b-e18e-47a2-b4d3-eccbe77599a2")
    IInvokeProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Invoke( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInvokeProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInvokeProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInvokeProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInvokeProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInvokeProvider * This);
        
        END_INTERFACE
    } IInvokeProviderVtbl;

    interface IInvokeProvider
    {
        CONST_VTBL struct IInvokeProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInvokeProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInvokeProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInvokeProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInvokeProvider_Invoke(This)	\
    ( (This)->lpVtbl -> Invoke(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInvokeProvider_INTERFACE_DEFINED__ */


#ifndef __IMultipleViewProvider_INTERFACE_DEFINED__
#define __IMultipleViewProvider_INTERFACE_DEFINED__

/* interface IMultipleViewProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMultipleViewProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6278cab1-b556-4a1a-b4e0-418acc523201")
    IMultipleViewProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetViewName( 
            /* [in] */ int viewId,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCurrentView( 
            /* [in] */ int viewId) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentView( 
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSupportedViews( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMultipleViewProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMultipleViewProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMultipleViewProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMultipleViewProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetViewName )( 
            IMultipleViewProvider * This,
            /* [in] */ int viewId,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *SetCurrentView )( 
            IMultipleViewProvider * This,
            /* [in] */ int viewId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentView )( 
            IMultipleViewProvider * This,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedViews )( 
            IMultipleViewProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        END_INTERFACE
    } IMultipleViewProviderVtbl;

    interface IMultipleViewProvider
    {
        CONST_VTBL struct IMultipleViewProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMultipleViewProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMultipleViewProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMultipleViewProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMultipleViewProvider_GetViewName(This,viewId,pRetVal)	\
    ( (This)->lpVtbl -> GetViewName(This,viewId,pRetVal) ) 

#define IMultipleViewProvider_SetCurrentView(This,viewId)	\
    ( (This)->lpVtbl -> SetCurrentView(This,viewId) ) 

#define IMultipleViewProvider_get_CurrentView(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CurrentView(This,pRetVal) ) 

#define IMultipleViewProvider_GetSupportedViews(This,pRetVal)	\
    ( (This)->lpVtbl -> GetSupportedViews(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMultipleViewProvider_INTERFACE_DEFINED__ */


#ifndef __IRangeValueProvider_INTERFACE_DEFINED__
#define __IRangeValueProvider_INTERFACE_DEFINED__

/* interface IRangeValueProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IRangeValueProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36dc7aef-33e6-4691-afe1-2be7274b3d33")
    IRangeValueProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ double val) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Maximum( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Minimum( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LargeChange( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SmallChange( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRangeValueProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRangeValueProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRangeValueProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRangeValueProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IRangeValueProvider * This,
            /* [in] */ double val);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Maximum )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Minimum )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LargeChange )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SmallChange )( 
            IRangeValueProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        END_INTERFACE
    } IRangeValueProviderVtbl;

    interface IRangeValueProvider
    {
        CONST_VTBL struct IRangeValueProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRangeValueProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRangeValueProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRangeValueProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRangeValueProvider_SetValue(This,val)	\
    ( (This)->lpVtbl -> SetValue(This,val) ) 

#define IRangeValueProvider_get_Value(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Value(This,pRetVal) ) 

#define IRangeValueProvider_get_IsReadOnly(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsReadOnly(This,pRetVal) ) 

#define IRangeValueProvider_get_Maximum(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Maximum(This,pRetVal) ) 

#define IRangeValueProvider_get_Minimum(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Minimum(This,pRetVal) ) 

#define IRangeValueProvider_get_LargeChange(This,pRetVal)	\
    ( (This)->lpVtbl -> get_LargeChange(This,pRetVal) ) 

#define IRangeValueProvider_get_SmallChange(This,pRetVal)	\
    ( (This)->lpVtbl -> get_SmallChange(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRangeValueProvider_INTERFACE_DEFINED__ */


#ifndef __IScrollItemProvider_INTERFACE_DEFINED__
#define __IScrollItemProvider_INTERFACE_DEFINED__

/* interface IScrollItemProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IScrollItemProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2360c714-4bf1-4b26-ba65-9b21316127eb")
    IScrollItemProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ScrollIntoView( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScrollItemProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScrollItemProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScrollItemProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScrollItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            IScrollItemProvider * This);
        
        END_INTERFACE
    } IScrollItemProviderVtbl;

    interface IScrollItemProvider
    {
        CONST_VTBL struct IScrollItemProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScrollItemProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScrollItemProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScrollItemProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScrollItemProvider_ScrollIntoView(This)	\
    ( (This)->lpVtbl -> ScrollIntoView(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScrollItemProvider_INTERFACE_DEFINED__ */


#ifndef __ISelectionProvider_INTERFACE_DEFINED__
#define __ISelectionProvider_INTERFACE_DEFINED__

/* interface ISelectionProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISelectionProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fb8b03af-3bdf-48d4-bd36-1a65793be168")
    ISelectionProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSelection( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanSelectMultiple( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsSelectionRequired( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISelectionProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISelectionProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISelectionProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISelectionProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelection )( 
            ISelectionProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanSelectMultiple )( 
            ISelectionProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsSelectionRequired )( 
            ISelectionProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        END_INTERFACE
    } ISelectionProviderVtbl;

    interface ISelectionProvider
    {
        CONST_VTBL struct ISelectionProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISelectionProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISelectionProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISelectionProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISelectionProvider_GetSelection(This,pRetVal)	\
    ( (This)->lpVtbl -> GetSelection(This,pRetVal) ) 

#define ISelectionProvider_get_CanSelectMultiple(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanSelectMultiple(This,pRetVal) ) 

#define ISelectionProvider_get_IsSelectionRequired(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsSelectionRequired(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISelectionProvider_INTERFACE_DEFINED__ */


#ifndef __IScrollProvider_INTERFACE_DEFINED__
#define __IScrollProvider_INTERFACE_DEFINED__

/* interface IScrollProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IScrollProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b38b8077-1fc3-42a5-8cae-d40c2215055a")
    IScrollProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Scroll( 
            /* [in] */ enum ScrollAmount horizontalAmount,
            /* [in] */ enum ScrollAmount verticalAmount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetScrollPercent( 
            /* [in] */ double horizontalPercent,
            /* [in] */ double verticalPercent) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalScrollPercent( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_VerticalScrollPercent( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HorizontalViewSize( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_VerticalViewSize( 
            /* [retval][out] */ __RPC__out double *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HorizontallyScrollable( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_VerticallyScrollable( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IScrollProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IScrollProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IScrollProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IScrollProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Scroll )( 
            IScrollProvider * This,
            /* [in] */ enum ScrollAmount horizontalAmount,
            /* [in] */ enum ScrollAmount verticalAmount);
        
        HRESULT ( STDMETHODCALLTYPE *SetScrollPercent )( 
            IScrollProvider * This,
            /* [in] */ double horizontalPercent,
            /* [in] */ double verticalPercent);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalScrollPercent )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalScrollPercent )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontalViewSize )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticalViewSize )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out double *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_HorizontallyScrollable )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_VerticallyScrollable )( 
            IScrollProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        END_INTERFACE
    } IScrollProviderVtbl;

    interface IScrollProvider
    {
        CONST_VTBL struct IScrollProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IScrollProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IScrollProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IScrollProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IScrollProvider_Scroll(This,horizontalAmount,verticalAmount)	\
    ( (This)->lpVtbl -> Scroll(This,horizontalAmount,verticalAmount) ) 

#define IScrollProvider_SetScrollPercent(This,horizontalPercent,verticalPercent)	\
    ( (This)->lpVtbl -> SetScrollPercent(This,horizontalPercent,verticalPercent) ) 

#define IScrollProvider_get_HorizontalScrollPercent(This,pRetVal)	\
    ( (This)->lpVtbl -> get_HorizontalScrollPercent(This,pRetVal) ) 

#define IScrollProvider_get_VerticalScrollPercent(This,pRetVal)	\
    ( (This)->lpVtbl -> get_VerticalScrollPercent(This,pRetVal) ) 

#define IScrollProvider_get_HorizontalViewSize(This,pRetVal)	\
    ( (This)->lpVtbl -> get_HorizontalViewSize(This,pRetVal) ) 

#define IScrollProvider_get_VerticalViewSize(This,pRetVal)	\
    ( (This)->lpVtbl -> get_VerticalViewSize(This,pRetVal) ) 

#define IScrollProvider_get_HorizontallyScrollable(This,pRetVal)	\
    ( (This)->lpVtbl -> get_HorizontallyScrollable(This,pRetVal) ) 

#define IScrollProvider_get_VerticallyScrollable(This,pRetVal)	\
    ( (This)->lpVtbl -> get_VerticallyScrollable(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IScrollProvider_INTERFACE_DEFINED__ */


#ifndef __ISelectionItemProvider_INTERFACE_DEFINED__
#define __ISelectionItemProvider_INTERFACE_DEFINED__

/* interface ISelectionItemProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISelectionItemProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2acad808-b2d4-452d-a407-91ff1ad167b2")
    ISelectionItemProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Select( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToSelection( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromSelection( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsSelected( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SelectionContainer( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISelectionItemProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISelectionItemProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISelectionItemProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISelectionItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Select )( 
            ISelectionItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddToSelection )( 
            ISelectionItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFromSelection )( 
            ISelectionItemProvider * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsSelected )( 
            ISelectionItemProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SelectionContainer )( 
            ISelectionItemProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        END_INTERFACE
    } ISelectionItemProviderVtbl;

    interface ISelectionItemProvider
    {
        CONST_VTBL struct ISelectionItemProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISelectionItemProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISelectionItemProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISelectionItemProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISelectionItemProvider_Select(This)	\
    ( (This)->lpVtbl -> Select(This) ) 

#define ISelectionItemProvider_AddToSelection(This)	\
    ( (This)->lpVtbl -> AddToSelection(This) ) 

#define ISelectionItemProvider_RemoveFromSelection(This)	\
    ( (This)->lpVtbl -> RemoveFromSelection(This) ) 

#define ISelectionItemProvider_get_IsSelected(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsSelected(This,pRetVal) ) 

#define ISelectionItemProvider_get_SelectionContainer(This,pRetVal)	\
    ( (This)->lpVtbl -> get_SelectionContainer(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISelectionItemProvider_INTERFACE_DEFINED__ */


#ifndef __ITableProvider_INTERFACE_DEFINED__
#define __ITableProvider_INTERFACE_DEFINED__

/* interface ITableProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITableProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9c860395-97b3-490a-b52a-858cc22af166")
    ITableProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRowHeaders( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnHeaders( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RowOrColumnMajor( 
            /* [retval][out] */ __RPC__out enum RowOrColumnMajor *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITableProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITableProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITableProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITableProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRowHeaders )( 
            ITableProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetColumnHeaders )( 
            ITableProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_RowOrColumnMajor )( 
            ITableProvider * This,
            /* [retval][out] */ __RPC__out enum RowOrColumnMajor *pRetVal);
        
        END_INTERFACE
    } ITableProviderVtbl;

    interface ITableProvider
    {
        CONST_VTBL struct ITableProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITableProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITableProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITableProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITableProvider_GetRowHeaders(This,pRetVal)	\
    ( (This)->lpVtbl -> GetRowHeaders(This,pRetVal) ) 

#define ITableProvider_GetColumnHeaders(This,pRetVal)	\
    ( (This)->lpVtbl -> GetColumnHeaders(This,pRetVal) ) 

#define ITableProvider_get_RowOrColumnMajor(This,pRetVal)	\
    ( (This)->lpVtbl -> get_RowOrColumnMajor(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITableProvider_INTERFACE_DEFINED__ */


#ifndef __ITableItemProvider_INTERFACE_DEFINED__
#define __ITableItemProvider_INTERFACE_DEFINED__

/* interface ITableItemProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITableItemProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b9734fa6-771f-4d78-9c90-2517999349cd")
    ITableItemProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRowHeaderItems( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnHeaderItems( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITableItemProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITableItemProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITableItemProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITableItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRowHeaderItems )( 
            ITableItemProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetColumnHeaderItems )( 
            ITableItemProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        END_INTERFACE
    } ITableItemProviderVtbl;

    interface ITableItemProvider
    {
        CONST_VTBL struct ITableItemProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITableItemProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITableItemProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITableItemProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITableItemProvider_GetRowHeaderItems(This,pRetVal)	\
    ( (This)->lpVtbl -> GetRowHeaderItems(This,pRetVal) ) 

#define ITableItemProvider_GetColumnHeaderItems(This,pRetVal)	\
    ( (This)->lpVtbl -> GetColumnHeaderItems(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITableItemProvider_INTERFACE_DEFINED__ */


#ifndef __IToggleProvider_INTERFACE_DEFINED__
#define __IToggleProvider_INTERFACE_DEFINED__

/* interface IToggleProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IToggleProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56d00bd0-c4f4-433c-a836-1a52a57e0892")
    IToggleProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Toggle( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ToggleState( 
            /* [retval][out] */ __RPC__out enum ToggleState *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IToggleProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IToggleProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IToggleProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IToggleProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Toggle )( 
            IToggleProvider * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToggleState )( 
            IToggleProvider * This,
            /* [retval][out] */ __RPC__out enum ToggleState *pRetVal);
        
        END_INTERFACE
    } IToggleProviderVtbl;

    interface IToggleProvider
    {
        CONST_VTBL struct IToggleProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IToggleProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IToggleProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IToggleProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IToggleProvider_Toggle(This)	\
    ( (This)->lpVtbl -> Toggle(This) ) 

#define IToggleProvider_get_ToggleState(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ToggleState(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IToggleProvider_INTERFACE_DEFINED__ */


#ifndef __ITransformProvider_INTERFACE_DEFINED__
#define __ITransformProvider_INTERFACE_DEFINED__

/* interface ITransformProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITransformProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6829ddc4-4f91-4ffa-b86f-bd3e2987cb4c")
    ITransformProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ double x,
            /* [in] */ double y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resize( 
            /* [in] */ double width,
            /* [in] */ double height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ double degrees) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanMove( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanResize( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanRotate( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITransformProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITransformProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITransformProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITransformProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            ITransformProvider * This,
            /* [in] */ double x,
            /* [in] */ double y);
        
        HRESULT ( STDMETHODCALLTYPE *Resize )( 
            ITransformProvider * This,
            /* [in] */ double width,
            /* [in] */ double height);
        
        HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            ITransformProvider * This,
            /* [in] */ double degrees);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanMove )( 
            ITransformProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanResize )( 
            ITransformProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanRotate )( 
            ITransformProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        END_INTERFACE
    } ITransformProviderVtbl;

    interface ITransformProvider
    {
        CONST_VTBL struct ITransformProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITransformProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITransformProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITransformProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITransformProvider_Move(This,x,y)	\
    ( (This)->lpVtbl -> Move(This,x,y) ) 

#define ITransformProvider_Resize(This,width,height)	\
    ( (This)->lpVtbl -> Resize(This,width,height) ) 

#define ITransformProvider_Rotate(This,degrees)	\
    ( (This)->lpVtbl -> Rotate(This,degrees) ) 

#define ITransformProvider_get_CanMove(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanMove(This,pRetVal) ) 

#define ITransformProvider_get_CanResize(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanResize(This,pRetVal) ) 

#define ITransformProvider_get_CanRotate(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanRotate(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITransformProvider_INTERFACE_DEFINED__ */


#ifndef __IValueProvider_INTERFACE_DEFINED__
#define __IValueProvider_INTERFACE_DEFINED__

/* interface IValueProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IValueProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c7935180-6fb3-4201-b174-7df73adbf64a")
    IValueProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ __RPC__in LPCWSTR val) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsReadOnly( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IValueProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IValueProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IValueProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IValueProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IValueProvider * This,
            /* [in] */ __RPC__in LPCWSTR val);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IValueProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsReadOnly )( 
            IValueProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        END_INTERFACE
    } IValueProviderVtbl;

    interface IValueProvider
    {
        CONST_VTBL struct IValueProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IValueProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IValueProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IValueProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IValueProvider_SetValue(This,val)	\
    ( (This)->lpVtbl -> SetValue(This,val) ) 

#define IValueProvider_get_Value(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Value(This,pRetVal) ) 

#define IValueProvider_get_IsReadOnly(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsReadOnly(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IValueProvider_INTERFACE_DEFINED__ */


#ifndef __IWindowProvider_INTERFACE_DEFINED__
#define __IWindowProvider_INTERFACE_DEFINED__

/* interface IWindowProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IWindowProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("987df77b-db06-4d77-8f8a-86a9c3bb90b9")
    IWindowProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetVisualState( 
            /* [in] */ enum WindowVisualState state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForInputIdle( 
            /* [in] */ int milliseconds,
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanMaximize( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CanMinimize( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsModal( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_WindowVisualState( 
            /* [retval][out] */ __RPC__out enum WindowVisualState *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_WindowInteractionState( 
            /* [retval][out] */ __RPC__out enum WindowInteractionState *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsTopmost( 
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWindowProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWindowProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWindowProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWindowProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetVisualState )( 
            IWindowProvider * This,
            /* [in] */ enum WindowVisualState state);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWindowProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForInputIdle )( 
            IWindowProvider * This,
            /* [in] */ int milliseconds,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanMaximize )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanMinimize )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsModal )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_WindowVisualState )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out enum WindowVisualState *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_WindowInteractionState )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out enum WindowInteractionState *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsTopmost )( 
            IWindowProvider * This,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        END_INTERFACE
    } IWindowProviderVtbl;

    interface IWindowProvider
    {
        CONST_VTBL struct IWindowProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWindowProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWindowProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWindowProvider_SetVisualState(This,state)	\
    ( (This)->lpVtbl -> SetVisualState(This,state) ) 

#define IWindowProvider_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWindowProvider_WaitForInputIdle(This,milliseconds,pRetVal)	\
    ( (This)->lpVtbl -> WaitForInputIdle(This,milliseconds,pRetVal) ) 

#define IWindowProvider_get_CanMaximize(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanMaximize(This,pRetVal) ) 

#define IWindowProvider_get_CanMinimize(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CanMinimize(This,pRetVal) ) 

#define IWindowProvider_get_IsModal(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsModal(This,pRetVal) ) 

#define IWindowProvider_get_WindowVisualState(This,pRetVal)	\
    ( (This)->lpVtbl -> get_WindowVisualState(This,pRetVal) ) 

#define IWindowProvider_get_WindowInteractionState(This,pRetVal)	\
    ( (This)->lpVtbl -> get_WindowInteractionState(This,pRetVal) ) 

#define IWindowProvider_get_IsTopmost(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsTopmost(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWindowProvider_INTERFACE_DEFINED__ */


#ifndef __ITextRangeProvider_INTERFACE_DEFINED__
#define __ITextRangeProvider_INTERFACE_DEFINED__

/* interface ITextRangeProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITextRangeProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5347ad7b-c355-46f8-aff5-909033582f63")
    ITextRangeProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Compare( 
            /* [in] */ __RPC__in_opt ITextRangeProvider *range,
            /* [retval][out] */ __RPC__out BOOL *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareEndpoints( 
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ __RPC__in_opt ITextRangeProvider *targetRange,
            /* [in] */ enum TextPatternRangeEndpoint targetEndpoint,
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExpandToEnclosingUnit( 
            /* [in] */ enum TextUnit unit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindAttribute( 
            /* [in] */ TEXTATTRIBUTEID attributeId,
            /* [in] */ VARIANT val,
            /* [in] */ BOOL backward,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindText( 
            /* [in] */ __RPC__in BSTR text,
            /* [in] */ BOOL backward,
            /* [in] */ BOOL ignoreCase,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributeValue( 
            /* [in] */ TEXTATTRIBUTEID attributeId,
            /* [retval][out] */ __RPC__out VARIANT *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBoundingRectangles( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnclosingElement( 
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [in] */ int maxLength,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ enum TextUnit unit,
            /* [in] */ int count,
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveEndpointByUnit( 
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ enum TextUnit unit,
            /* [in] */ int count,
            /* [retval][out] */ __RPC__out int *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveEndpointByRange( 
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ __RPC__in_opt ITextRangeProvider *targetRange,
            /* [in] */ enum TextPatternRangeEndpoint targetEndpoint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Select( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddToSelection( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFromSelection( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScrollIntoView( 
            /* [in] */ BOOL alignToTop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChildren( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITextRangeProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextRangeProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextRangeProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextRangeProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ITextRangeProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *Compare )( 
            ITextRangeProvider * This,
            /* [in] */ __RPC__in_opt ITextRangeProvider *range,
            /* [retval][out] */ __RPC__out BOOL *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *CompareEndpoints )( 
            ITextRangeProvider * This,
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ __RPC__in_opt ITextRangeProvider *targetRange,
            /* [in] */ enum TextPatternRangeEndpoint targetEndpoint,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *ExpandToEnclosingUnit )( 
            ITextRangeProvider * This,
            /* [in] */ enum TextUnit unit);
        
        HRESULT ( STDMETHODCALLTYPE *FindAttribute )( 
            ITextRangeProvider * This,
            /* [in] */ TEXTATTRIBUTEID attributeId,
            /* [in] */ VARIANT val,
            /* [in] */ BOOL backward,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *FindText )( 
            ITextRangeProvider * This,
            /* [in] */ __RPC__in BSTR text,
            /* [in] */ BOOL backward,
            /* [in] */ BOOL ignoreCase,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributeValue )( 
            ITextRangeProvider * This,
            /* [in] */ TEXTATTRIBUTEID attributeId,
            /* [retval][out] */ __RPC__out VARIANT *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBoundingRectangles )( 
            ITextRangeProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnclosingElement )( 
            ITextRangeProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            ITextRangeProvider * This,
            /* [in] */ int maxLength,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            ITextRangeProvider * This,
            /* [in] */ enum TextUnit unit,
            /* [in] */ int count,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *MoveEndpointByUnit )( 
            ITextRangeProvider * This,
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ enum TextUnit unit,
            /* [in] */ int count,
            /* [retval][out] */ __RPC__out int *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *MoveEndpointByRange )( 
            ITextRangeProvider * This,
            /* [in] */ enum TextPatternRangeEndpoint endpoint,
            /* [in] */ __RPC__in_opt ITextRangeProvider *targetRange,
            /* [in] */ enum TextPatternRangeEndpoint targetEndpoint);
        
        HRESULT ( STDMETHODCALLTYPE *Select )( 
            ITextRangeProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddToSelection )( 
            ITextRangeProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFromSelection )( 
            ITextRangeProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScrollIntoView )( 
            ITextRangeProvider * This,
            /* [in] */ BOOL alignToTop);
        
        HRESULT ( STDMETHODCALLTYPE *GetChildren )( 
            ITextRangeProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        END_INTERFACE
    } ITextRangeProviderVtbl;

    interface ITextRangeProvider
    {
        CONST_VTBL struct ITextRangeProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextRangeProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextRangeProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextRangeProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextRangeProvider_Clone(This,pRetVal)	\
    ( (This)->lpVtbl -> Clone(This,pRetVal) ) 

#define ITextRangeProvider_Compare(This,range,pRetVal)	\
    ( (This)->lpVtbl -> Compare(This,range,pRetVal) ) 

#define ITextRangeProvider_CompareEndpoints(This,endpoint,targetRange,targetEndpoint,pRetVal)	\
    ( (This)->lpVtbl -> CompareEndpoints(This,endpoint,targetRange,targetEndpoint,pRetVal) ) 

#define ITextRangeProvider_ExpandToEnclosingUnit(This,unit)	\
    ( (This)->lpVtbl -> ExpandToEnclosingUnit(This,unit) ) 

#define ITextRangeProvider_FindAttribute(This,attributeId,val,backward,pRetVal)	\
    ( (This)->lpVtbl -> FindAttribute(This,attributeId,val,backward,pRetVal) ) 

#define ITextRangeProvider_FindText(This,text,backward,ignoreCase,pRetVal)	\
    ( (This)->lpVtbl -> FindText(This,text,backward,ignoreCase,pRetVal) ) 

#define ITextRangeProvider_GetAttributeValue(This,attributeId,pRetVal)	\
    ( (This)->lpVtbl -> GetAttributeValue(This,attributeId,pRetVal) ) 

#define ITextRangeProvider_GetBoundingRectangles(This,pRetVal)	\
    ( (This)->lpVtbl -> GetBoundingRectangles(This,pRetVal) ) 

#define ITextRangeProvider_GetEnclosingElement(This,pRetVal)	\
    ( (This)->lpVtbl -> GetEnclosingElement(This,pRetVal) ) 

#define ITextRangeProvider_GetText(This,maxLength,pRetVal)	\
    ( (This)->lpVtbl -> GetText(This,maxLength,pRetVal) ) 

#define ITextRangeProvider_Move(This,unit,count,pRetVal)	\
    ( (This)->lpVtbl -> Move(This,unit,count,pRetVal) ) 

#define ITextRangeProvider_MoveEndpointByUnit(This,endpoint,unit,count,pRetVal)	\
    ( (This)->lpVtbl -> MoveEndpointByUnit(This,endpoint,unit,count,pRetVal) ) 

#define ITextRangeProvider_MoveEndpointByRange(This,endpoint,targetRange,targetEndpoint)	\
    ( (This)->lpVtbl -> MoveEndpointByRange(This,endpoint,targetRange,targetEndpoint) ) 

#define ITextRangeProvider_Select(This)	\
    ( (This)->lpVtbl -> Select(This) ) 

#define ITextRangeProvider_AddToSelection(This)	\
    ( (This)->lpVtbl -> AddToSelection(This) ) 

#define ITextRangeProvider_RemoveFromSelection(This)	\
    ( (This)->lpVtbl -> RemoveFromSelection(This) ) 

#define ITextRangeProvider_ScrollIntoView(This,alignToTop)	\
    ( (This)->lpVtbl -> ScrollIntoView(This,alignToTop) ) 

#define ITextRangeProvider_GetChildren(This,pRetVal)	\
    ( (This)->lpVtbl -> GetChildren(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextRangeProvider_INTERFACE_DEFINED__ */


#ifndef __ITextProvider_INTERFACE_DEFINED__
#define __ITextProvider_INTERFACE_DEFINED__

/* interface ITextProvider */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ITextProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3589c92c-63f3-4367-99bb-ada653b77cf2")
    ITextProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSelection( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisibleRanges( 
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RangeFromChild( 
            /* [in] */ __RPC__in_opt IRawElementProviderSimple *childElement,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RangeFromPoint( 
            /* [in] */ struct UiaPoint point,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_DocumentRange( 
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SupportedTextSelection( 
            /* [retval][out] */ __RPC__out enum SupportedTextSelection *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITextProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextProvider * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelection )( 
            ITextProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetVisibleRanges )( 
            ITextProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *RangeFromChild )( 
            ITextProvider * This,
            /* [in] */ __RPC__in_opt IRawElementProviderSimple *childElement,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *RangeFromPoint )( 
            ITextProvider * This,
            /* [in] */ struct UiaPoint point,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentRange )( 
            ITextProvider * This,
            /* [retval][out] */ __RPC__deref_out_opt ITextRangeProvider **pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportedTextSelection )( 
            ITextProvider * This,
            /* [retval][out] */ __RPC__out enum SupportedTextSelection *pRetVal);
        
        END_INTERFACE
    } ITextProviderVtbl;

    interface ITextProvider
    {
        CONST_VTBL struct ITextProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextProvider_GetSelection(This,pRetVal)	\
    ( (This)->lpVtbl -> GetSelection(This,pRetVal) ) 

#define ITextProvider_GetVisibleRanges(This,pRetVal)	\
    ( (This)->lpVtbl -> GetVisibleRanges(This,pRetVal) ) 

#define ITextProvider_RangeFromChild(This,childElement,pRetVal)	\
    ( (This)->lpVtbl -> RangeFromChild(This,childElement,pRetVal) ) 

#define ITextProvider_RangeFromPoint(This,point,pRetVal)	\
    ( (This)->lpVtbl -> RangeFromPoint(This,point,pRetVal) ) 

#define ITextProvider_get_DocumentRange(This,pRetVal)	\
    ( (This)->lpVtbl -> get_DocumentRange(This,pRetVal) ) 

#define ITextProvider_get_SupportedTextSelection(This,pRetVal)	\
    ( (This)->lpVtbl -> get_SupportedTextSelection(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextProvider_INTERFACE_DEFINED__ */

#endif /* __UIA_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



