

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for tlogstg.idl:
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

#ifndef __tlogstg_h__
#define __tlogstg_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITravelLogEntry_FWD_DEFINED__
#define __ITravelLogEntry_FWD_DEFINED__
typedef interface ITravelLogEntry ITravelLogEntry;
#endif 	/* __ITravelLogEntry_FWD_DEFINED__ */


#ifndef __ITravelLogClient_FWD_DEFINED__
#define __ITravelLogClient_FWD_DEFINED__
typedef interface ITravelLogClient ITravelLogClient;
#endif 	/* __ITravelLogClient_FWD_DEFINED__ */


#ifndef __IEnumTravelLogEntry_FWD_DEFINED__
#define __IEnumTravelLogEntry_FWD_DEFINED__
typedef interface IEnumTravelLogEntry IEnumTravelLogEntry;
#endif 	/* __IEnumTravelLogEntry_FWD_DEFINED__ */


#ifndef __ITravelLogStg_FWD_DEFINED__
#define __ITravelLogStg_FWD_DEFINED__
typedef interface ITravelLogStg ITravelLogStg;
#endif 	/* __ITravelLogStg_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "shtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_tlogstg_0000_0000 */
/* [local] */ 

//=--------------------------------------------------------------------------=
// tlogstg.h
//=--------------------------------------------------------------------------=
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//---------------------------------------------------------------------------=
// ITravelLogStg Interface.

#define SID_STravelLogCursor IID_ITravelLogStg 
typedef struct _WINDOWDATA
    {
    DWORD dwWindowID;
    UINT uiCP;
    PIDLIST_ABSOLUTE pidl;
    LPWSTR lpszUrl;
    LPWSTR lpszUrlLocation;
    LPWSTR lpszTitle;
    } 	WINDOWDATA;

typedef WINDOWDATA *LPWINDOWDATA;

typedef const WINDOWDATA *LPCWINDOWDATA;



extern RPC_IF_HANDLE __MIDL_itf_tlogstg_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tlogstg_0000_0000_v0_0_s_ifspec;

#ifndef __ITravelLogEntry_INTERFACE_DEFINED__
#define __ITravelLogEntry_INTERFACE_DEFINED__

/* interface ITravelLogEntry */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_ITravelLogEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7EBFDD87-AD18-11d3-A4C5-00C04F72D6B8")
    ITravelLogEntry : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetTitle( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetURL( 
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITravelLogEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITravelLogEntry * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITravelLogEntry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITravelLogEntry * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetTitle )( 
            ITravelLogEntry * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszTitle);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetURL )( 
            ITravelLogEntry * This,
            /* [out] */ __RPC__deref_out_opt LPWSTR *ppszURL);
        
        END_INTERFACE
    } ITravelLogEntryVtbl;

    interface ITravelLogEntry
    {
        CONST_VTBL struct ITravelLogEntryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITravelLogEntry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITravelLogEntry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITravelLogEntry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITravelLogEntry_GetTitle(This,ppszTitle)	\
    ( (This)->lpVtbl -> GetTitle(This,ppszTitle) ) 

#define ITravelLogEntry_GetURL(This,ppszURL)	\
    ( (This)->lpVtbl -> GetURL(This,ppszURL) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITravelLogEntry_INTERFACE_DEFINED__ */


#ifndef __ITravelLogClient_INTERFACE_DEFINED__
#define __ITravelLogClient_INTERFACE_DEFINED__

/* interface ITravelLogClient */
/* [helpcontext][helpstring][object][uuid] */ 


EXTERN_C const IID IID_ITravelLogClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("241c033e-e659-43da-aa4d-4086dbc4758d")
    ITravelLogClient : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE FindWindowByIndex( 
            /* [in] */ DWORD dwID,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppunk) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetWindowData( 
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [out] */ __RPC__out LPWINDOWDATA pWinData) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE LoadHistoryPosition( 
            /* [in] */ __RPC__in LPWSTR pszUrlLocation,
            /* [in] */ DWORD dwPosition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITravelLogClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITravelLogClient * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITravelLogClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITravelLogClient * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindWindowByIndex )( 
            ITravelLogClient * This,
            /* [in] */ DWORD dwID,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppunk);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetWindowData )( 
            ITravelLogClient * This,
            /* [in] */ __RPC__in_opt IStream *pStream,
            /* [out] */ __RPC__out LPWINDOWDATA pWinData);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *LoadHistoryPosition )( 
            ITravelLogClient * This,
            /* [in] */ __RPC__in LPWSTR pszUrlLocation,
            /* [in] */ DWORD dwPosition);
        
        END_INTERFACE
    } ITravelLogClientVtbl;

    interface ITravelLogClient
    {
        CONST_VTBL struct ITravelLogClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITravelLogClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITravelLogClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITravelLogClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITravelLogClient_FindWindowByIndex(This,dwID,ppunk)	\
    ( (This)->lpVtbl -> FindWindowByIndex(This,dwID,ppunk) ) 

#define ITravelLogClient_GetWindowData(This,pStream,pWinData)	\
    ( (This)->lpVtbl -> GetWindowData(This,pStream,pWinData) ) 

#define ITravelLogClient_LoadHistoryPosition(This,pszUrlLocation,dwPosition)	\
    ( (This)->lpVtbl -> LoadHistoryPosition(This,pszUrlLocation,dwPosition) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITravelLogClient_INTERFACE_DEFINED__ */


#ifndef __IEnumTravelLogEntry_INTERFACE_DEFINED__
#define __IEnumTravelLogEntry_INTERFACE_DEFINED__

/* interface IEnumTravelLogEntry */
/* [helpcontext][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumTravelLogEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7EBFDD85-AD18-11d3-A4C5-00C04F72D6B8")
    IEnumTravelLogEntry : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG cElt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElt, *pcEltFetched) ITravelLogEntry **rgElt,
            /* [out] */ __RPC__out ULONG *pcEltFetched) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG cElt) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumTravelLogEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumTravelLogEntry * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumTravelLogEntry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumTravelLogEntry * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumTravelLogEntry * This,
            /* [in] */ ULONG cElt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(cElt, *pcEltFetched) ITravelLogEntry **rgElt,
            /* [out] */ __RPC__out ULONG *pcEltFetched);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumTravelLogEntry * This,
            /* [in] */ ULONG cElt);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumTravelLogEntry * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumTravelLogEntry * This,
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppEnum);
        
        END_INTERFACE
    } IEnumTravelLogEntryVtbl;

    interface IEnumTravelLogEntry
    {
        CONST_VTBL struct IEnumTravelLogEntryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumTravelLogEntry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumTravelLogEntry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumTravelLogEntry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumTravelLogEntry_Next(This,cElt,rgElt,pcEltFetched)	\
    ( (This)->lpVtbl -> Next(This,cElt,rgElt,pcEltFetched) ) 

#define IEnumTravelLogEntry_Skip(This,cElt)	\
    ( (This)->lpVtbl -> Skip(This,cElt) ) 

#define IEnumTravelLogEntry_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumTravelLogEntry_Clone(This,ppEnum)	\
    ( (This)->lpVtbl -> Clone(This,ppEnum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumTravelLogEntry_INTERFACE_DEFINED__ */


#ifndef __ITravelLogStg_INTERFACE_DEFINED__
#define __ITravelLogStg_INTERFACE_DEFINED__

/* interface ITravelLogStg */
/* [unique][object][uuid] */ 


enum tagTLENUMF
    {	TLEF_RELATIVE_INCLUDE_CURRENT	= 0x1,
	TLEF_RELATIVE_BACK	= 0x10,
	TLEF_RELATIVE_FORE	= 0x20,
	TLEF_INCLUDE_UNINVOKEABLE	= 0x40,
	TLEF_ABSOLUTE	= 0x31
    } ;
typedef DWORD TLENUMF;


EXTERN_C const IID IID_ITravelLogStg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7EBFDD80-AD18-11d3-A4C5-00C04F72D6B8")
    ITravelLogStg : public IUnknown
    {
    public:
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE CreateEntry( 
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in LPCWSTR pszTitle,
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptleRelativeTo,
            /* [in] */ BOOL fPrepend,
            /* [out] */ __RPC__deref_out_opt ITravelLogEntry **pptle) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE TravelTo( 
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptle) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE EnumEntries( 
            /* [in] */ TLENUMF flags,
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppenum) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE FindEntries( 
            /* [in] */ TLENUMF flags,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppenum) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [in] */ TLENUMF flags,
            /* [out] */ __RPC__out DWORD *pcEntries) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE RemoveEntry( 
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptle) = 0;
        
        virtual /* [helpcontext][helpstring] */ HRESULT STDMETHODCALLTYPE GetRelativeEntry( 
            /* [in] */ int iOffset,
            /* [out] */ __RPC__deref_out_opt ITravelLogEntry **ptle) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITravelLogStgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITravelLogStg * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITravelLogStg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITravelLogStg * This);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateEntry )( 
            ITravelLogStg * This,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [in] */ __RPC__in LPCWSTR pszTitle,
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptleRelativeTo,
            /* [in] */ BOOL fPrepend,
            /* [out] */ __RPC__deref_out_opt ITravelLogEntry **pptle);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *TravelTo )( 
            ITravelLogStg * This,
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptle);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumEntries )( 
            ITravelLogStg * This,
            /* [in] */ TLENUMF flags,
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppenum);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindEntries )( 
            ITravelLogStg * This,
            /* [in] */ TLENUMF flags,
            /* [in] */ __RPC__in LPCWSTR pszUrl,
            /* [out] */ __RPC__deref_out_opt IEnumTravelLogEntry **ppenum);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ITravelLogStg * This,
            /* [in] */ TLENUMF flags,
            /* [out] */ __RPC__out DWORD *pcEntries);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *RemoveEntry )( 
            ITravelLogStg * This,
            /* [in] */ __RPC__in_opt ITravelLogEntry *ptle);
        
        /* [helpcontext][helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetRelativeEntry )( 
            ITravelLogStg * This,
            /* [in] */ int iOffset,
            /* [out] */ __RPC__deref_out_opt ITravelLogEntry **ptle);
        
        END_INTERFACE
    } ITravelLogStgVtbl;

    interface ITravelLogStg
    {
        CONST_VTBL struct ITravelLogStgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITravelLogStg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITravelLogStg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITravelLogStg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITravelLogStg_CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle)	\
    ( (This)->lpVtbl -> CreateEntry(This,pszUrl,pszTitle,ptleRelativeTo,fPrepend,pptle) ) 

#define ITravelLogStg_TravelTo(This,ptle)	\
    ( (This)->lpVtbl -> TravelTo(This,ptle) ) 

#define ITravelLogStg_EnumEntries(This,flags,ppenum)	\
    ( (This)->lpVtbl -> EnumEntries(This,flags,ppenum) ) 

#define ITravelLogStg_FindEntries(This,flags,pszUrl,ppenum)	\
    ( (This)->lpVtbl -> FindEntries(This,flags,pszUrl,ppenum) ) 

#define ITravelLogStg_GetCount(This,flags,pcEntries)	\
    ( (This)->lpVtbl -> GetCount(This,flags,pcEntries) ) 

#define ITravelLogStg_RemoveEntry(This,ptle)	\
    ( (This)->lpVtbl -> RemoveEntry(This,ptle) ) 

#define ITravelLogStg_GetRelativeEntry(This,iOffset,ptle)	\
    ( (This)->lpVtbl -> GetRelativeEntry(This,iOffset,ptle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITravelLogStg_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  PIDLIST_ABSOLUTE_UserSize(     unsigned long *, unsigned long            , PIDLIST_ABSOLUTE * ); 
unsigned char * __RPC_USER  PIDLIST_ABSOLUTE_UserMarshal(  unsigned long *, unsigned char *, PIDLIST_ABSOLUTE * ); 
unsigned char * __RPC_USER  PIDLIST_ABSOLUTE_UserUnmarshal(unsigned long *, unsigned char *, PIDLIST_ABSOLUTE * ); 
void                      __RPC_USER  PIDLIST_ABSOLUTE_UserFree(     unsigned long *, PIDLIST_ABSOLUTE * ); 

unsigned long             __RPC_USER  PIDLIST_ABSOLUTE_UserSize64(     unsigned long *, unsigned long            , PIDLIST_ABSOLUTE * ); 
unsigned char * __RPC_USER  PIDLIST_ABSOLUTE_UserMarshal64(  unsigned long *, unsigned char *, PIDLIST_ABSOLUTE * ); 
unsigned char * __RPC_USER  PIDLIST_ABSOLUTE_UserUnmarshal64(unsigned long *, unsigned char *, PIDLIST_ABSOLUTE * ); 
void                      __RPC_USER  PIDLIST_ABSOLUTE_UserFree64(     unsigned long *, PIDLIST_ABSOLUTE * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



