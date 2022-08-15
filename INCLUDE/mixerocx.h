

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for mixerocx.idl:
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

#ifndef __mixerocx_h__
#define __mixerocx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMixerOCXNotify_FWD_DEFINED__
#define __IMixerOCXNotify_FWD_DEFINED__
typedef interface IMixerOCXNotify IMixerOCXNotify;
#endif 	/* __IMixerOCXNotify_FWD_DEFINED__ */


#ifndef __IMixerOCX_FWD_DEFINED__
#define __IMixerOCX_FWD_DEFINED__
typedef interface IMixerOCX IMixerOCX;
#endif 	/* __IMixerOCX_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_mixerocx_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_mixerocx_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mixerocx_0000_0000_v0_0_s_ifspec;

#ifndef __IMixerOCXNotify_INTERFACE_DEFINED__
#define __IMixerOCXNotify_INTERFACE_DEFINED__

/* interface IMixerOCXNotify */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMixerOCXNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81A3BD31-DEE1-11d1-8508-00A0C91F9CA0")
    IMixerOCXNotify : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnInvalidateRect( 
            /* [in] */ __RPC__in LPCRECT lpcRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnStatusChange( 
            /* [in] */ ULONG ulStatusFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataChange( 
            /* [in] */ ULONG ulDataFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMixerOCXNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMixerOCXNotify * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMixerOCXNotify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMixerOCXNotify * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnInvalidateRect )( 
            IMixerOCXNotify * This,
            /* [in] */ __RPC__in LPCRECT lpcRect);
        
        HRESULT ( STDMETHODCALLTYPE *OnStatusChange )( 
            IMixerOCXNotify * This,
            /* [in] */ ULONG ulStatusFlags);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataChange )( 
            IMixerOCXNotify * This,
            /* [in] */ ULONG ulDataFlags);
        
        END_INTERFACE
    } IMixerOCXNotifyVtbl;

    interface IMixerOCXNotify
    {
        CONST_VTBL struct IMixerOCXNotifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMixerOCXNotify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMixerOCXNotify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMixerOCXNotify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMixerOCXNotify_OnInvalidateRect(This,lpcRect)	\
    ( (This)->lpVtbl -> OnInvalidateRect(This,lpcRect) ) 

#define IMixerOCXNotify_OnStatusChange(This,ulStatusFlags)	\
    ( (This)->lpVtbl -> OnStatusChange(This,ulStatusFlags) ) 

#define IMixerOCXNotify_OnDataChange(This,ulDataFlags)	\
    ( (This)->lpVtbl -> OnDataChange(This,ulDataFlags) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMixerOCXNotify_INTERFACE_DEFINED__ */


#ifndef __IMixerOCX_INTERFACE_DEFINED__
#define __IMixerOCX_INTERFACE_DEFINED__

/* interface IMixerOCX */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMixerOCX;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81A3BD32-DEE1-11d1-8508-00A0C91F9CA0")
    IMixerOCX : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDisplayChange( 
            /* [in] */ ULONG ulBitsPerPixel,
            /* [in] */ ULONG ulScreenWidth,
            /* [in] */ ULONG ulScreenHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAspectRatio( 
            /* [out] */ __RPC__out LPDWORD pdwPictAspectRatioX,
            /* [out] */ __RPC__out LPDWORD pdwPictAspectRatioY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVideoSize( 
            /* [out] */ __RPC__out LPDWORD pdwVideoWidth,
            /* [out] */ __RPC__out LPDWORD pdwVideoHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ __RPC__deref_out_opt LPDWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDraw( 
            /* [in] */ __RPC__in HDC hdcDraw,
            /* [in] */ __RPC__in LPCRECT prcDraw) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDrawRegion( 
            /* [in] */ __RPC__in LPPOINT lpptTopLeftSC,
            /* [in] */ __RPC__in LPCRECT prcDrawCC,
            /* [in] */ __RPC__in LPCRECT lprcClip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ __RPC__in_opt IMixerOCXNotify *pmdns) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnAdvise( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMixerOCXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMixerOCX * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMixerOCX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMixerOCX * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDisplayChange )( 
            IMixerOCX * This,
            /* [in] */ ULONG ulBitsPerPixel,
            /* [in] */ ULONG ulScreenWidth,
            /* [in] */ ULONG ulScreenHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetAspectRatio )( 
            IMixerOCX * This,
            /* [out] */ __RPC__out LPDWORD pdwPictAspectRatioX,
            /* [out] */ __RPC__out LPDWORD pdwPictAspectRatioY);
        
        HRESULT ( STDMETHODCALLTYPE *GetVideoSize )( 
            IMixerOCX * This,
            /* [out] */ __RPC__out LPDWORD pdwVideoWidth,
            /* [out] */ __RPC__out LPDWORD pdwVideoHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            IMixerOCX * This,
            /* [out] */ __RPC__deref_out_opt LPDWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *OnDraw )( 
            IMixerOCX * This,
            /* [in] */ __RPC__in HDC hdcDraw,
            /* [in] */ __RPC__in LPCRECT prcDraw);
        
        HRESULT ( STDMETHODCALLTYPE *SetDrawRegion )( 
            IMixerOCX * This,
            /* [in] */ __RPC__in LPPOINT lpptTopLeftSC,
            /* [in] */ __RPC__in LPCRECT prcDrawCC,
            /* [in] */ __RPC__in LPCRECT lprcClip);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IMixerOCX * This,
            /* [in] */ __RPC__in_opt IMixerOCXNotify *pmdns);
        
        HRESULT ( STDMETHODCALLTYPE *UnAdvise )( 
            IMixerOCX * This);
        
        END_INTERFACE
    } IMixerOCXVtbl;

    interface IMixerOCX
    {
        CONST_VTBL struct IMixerOCXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMixerOCX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMixerOCX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMixerOCX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMixerOCX_OnDisplayChange(This,ulBitsPerPixel,ulScreenWidth,ulScreenHeight)	\
    ( (This)->lpVtbl -> OnDisplayChange(This,ulBitsPerPixel,ulScreenWidth,ulScreenHeight) ) 

#define IMixerOCX_GetAspectRatio(This,pdwPictAspectRatioX,pdwPictAspectRatioY)	\
    ( (This)->lpVtbl -> GetAspectRatio(This,pdwPictAspectRatioX,pdwPictAspectRatioY) ) 

#define IMixerOCX_GetVideoSize(This,pdwVideoWidth,pdwVideoHeight)	\
    ( (This)->lpVtbl -> GetVideoSize(This,pdwVideoWidth,pdwVideoHeight) ) 

#define IMixerOCX_GetStatus(This,pdwStatus)	\
    ( (This)->lpVtbl -> GetStatus(This,pdwStatus) ) 

#define IMixerOCX_OnDraw(This,hdcDraw,prcDraw)	\
    ( (This)->lpVtbl -> OnDraw(This,hdcDraw,prcDraw) ) 

#define IMixerOCX_SetDrawRegion(This,lpptTopLeftSC,prcDrawCC,lprcClip)	\
    ( (This)->lpVtbl -> SetDrawRegion(This,lpptTopLeftSC,prcDrawCC,lprcClip) ) 

#define IMixerOCX_Advise(This,pmdns)	\
    ( (This)->lpVtbl -> Advise(This,pmdns) ) 

#define IMixerOCX_UnAdvise(This)	\
    ( (This)->lpVtbl -> UnAdvise(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMixerOCX_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HDC_UserSize64(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal64(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal64(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree64(     unsigned long *, HDC * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



