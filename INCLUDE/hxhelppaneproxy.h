

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for hxhelppaneproxy.idl:
    Oicf, W0, Zp8, env=Win32 (32b run)
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

#ifndef __hxhelppaneproxy_h__
#define __hxhelppaneproxy_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHxHelpPane_FWD_DEFINED__
#define __IHxHelpPane_FWD_DEFINED__
typedef interface IHxHelpPane IHxHelpPane;
#endif 	/* __IHxHelpPane_FWD_DEFINED__ */


#ifndef __HxHelpPane_FWD_DEFINED__
#define __HxHelpPane_FWD_DEFINED__

#ifdef __cplusplus
typedef class HxHelpPane HxHelpPane;
#else
typedef struct HxHelpPane HxHelpPane;
#endif /* __cplusplus */

#endif 	/* __HxHelpPane_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_hxhelppaneproxy_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_hxhelppaneproxy_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hxhelppaneproxy_0000_0000_v0_0_s_ifspec;

#ifndef __IHxHelpPane_INTERFACE_DEFINED__
#define __IHxHelpPane_INTERFACE_DEFINED__

/* interface IHxHelpPane */
/* [hidden][oleautomation][helpstring][uuid][unique][object] */ 


EXTERN_C const IID IID_IHxHelpPane;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8cec5884-07a1-11d9-b15e-000d56bfe6ee")
    IHxHelpPane : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DisplayTask( 
            /* [in] */ __RPC__in BSTR bstrUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisplayContents( 
            /* [in] */ __RPC__in BSTR bstrUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisplaySearchResults( 
            /* [in] */ __RPC__in BSTR bstrSearchQuery) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHxHelpPaneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHxHelpPane * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHxHelpPane * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHxHelpPane * This);
        
        HRESULT ( STDMETHODCALLTYPE *DisplayTask )( 
            IHxHelpPane * This,
            /* [in] */ __RPC__in BSTR bstrUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DisplayContents )( 
            IHxHelpPane * This,
            /* [in] */ __RPC__in BSTR bstrUrl);
        
        HRESULT ( STDMETHODCALLTYPE *DisplaySearchResults )( 
            IHxHelpPane * This,
            /* [in] */ __RPC__in BSTR bstrSearchQuery);
        
        END_INTERFACE
    } IHxHelpPaneVtbl;

    interface IHxHelpPane
    {
        CONST_VTBL struct IHxHelpPaneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHxHelpPane_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHxHelpPane_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHxHelpPane_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHxHelpPane_DisplayTask(This,bstrUrl)	\
    ( (This)->lpVtbl -> DisplayTask(This,bstrUrl) ) 

#define IHxHelpPane_DisplayContents(This,bstrUrl)	\
    ( (This)->lpVtbl -> DisplayContents(This,bstrUrl) ) 

#define IHxHelpPane_DisplaySearchResults(This,bstrSearchQuery)	\
    ( (This)->lpVtbl -> DisplaySearchResults(This,bstrSearchQuery) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHxHelpPane_INTERFACE_DEFINED__ */



#ifndef __HelpPane_LIBRARY_DEFINED__
#define __HelpPane_LIBRARY_DEFINED__

/* library HelpPane */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_HelpPane;

EXTERN_C const CLSID CLSID_HxHelpPane;

#ifdef __cplusplus

class DECLSPEC_UUID("8cec58e7-07a1-11d9-b15e-000d56bfe6ee")
HxHelpPane;
#endif
#endif /* __HelpPane_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_hxhelppaneproxy_0000_0001 */
/* [local] */ 

#ifdef _INC_COMDEF
    _COM_SMARTPTR_TYPEDEF(IHxHelpPane,__uuidof(IHxHelpPane)) ;
#endif


extern RPC_IF_HANDLE __MIDL_itf_hxhelppaneproxy_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hxhelppaneproxy_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



