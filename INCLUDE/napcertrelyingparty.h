

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for napcertrelyingparty.idl:
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

#ifndef __napcertrelyingparty_h__
#define __napcertrelyingparty_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INapCertRelyingParty_FWD_DEFINED__
#define __INapCertRelyingParty_FWD_DEFINED__
typedef interface INapCertRelyingParty INapCertRelyingParty;
#endif 	/* __INapCertRelyingParty_FWD_DEFINED__ */


/* header files for imported files */
#include "NapTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_napcertrelyingparty_0000_0000 */
/* [local] */ 

#include <wincrypt.h>
static const UINT32 NapAfwZonePropId = CERT_FIRST_USER_PROP_ID;
static const UINT32 NapAfwProtectionLevelPropId = CERT_FIRST_USER_PROP_ID + 1;


extern RPC_IF_HANDLE __MIDL_itf_napcertrelyingparty_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napcertrelyingparty_0000_0000_v0_0_s_ifspec;

#ifndef __INapCertRelyingParty_INTERFACE_DEFINED__
#define __INapCertRelyingParty_INTERFACE_DEFINED__

/* interface INapCertRelyingParty */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_INapCertRelyingParty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62c02ffc-4c77-4158-8754-782d5b4ee66e")
    INapCertRelyingParty : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SubscribeCertByGroup( 
            /* [in] */ EnforcementEntityId id,
            /* [in] */ __RPC__in const BSTR subscriberName,
            /* [unique][in] */ __RPC__in_opt const VARIANT *reserved,
            /* [out] */ __RPC__out BOOL *certExists) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnSubscribeCertByGroup( 
            /* [unique][in] */ __RPC__in_opt const VARIANT *reserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INapCertRelyingPartyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INapCertRelyingParty * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INapCertRelyingParty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INapCertRelyingParty * This);
        
        HRESULT ( STDMETHODCALLTYPE *SubscribeCertByGroup )( 
            INapCertRelyingParty * This,
            /* [in] */ EnforcementEntityId id,
            /* [in] */ __RPC__in const BSTR subscriberName,
            /* [unique][in] */ __RPC__in_opt const VARIANT *reserved,
            /* [out] */ __RPC__out BOOL *certExists);
        
        HRESULT ( STDMETHODCALLTYPE *UnSubscribeCertByGroup )( 
            INapCertRelyingParty * This,
            /* [unique][in] */ __RPC__in_opt const VARIANT *reserved);
        
        END_INTERFACE
    } INapCertRelyingPartyVtbl;

    interface INapCertRelyingParty
    {
        CONST_VTBL struct INapCertRelyingPartyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INapCertRelyingParty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INapCertRelyingParty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INapCertRelyingParty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INapCertRelyingParty_SubscribeCertByGroup(This,id,subscriberName,reserved,certExists)	\
    ( (This)->lpVtbl -> SubscribeCertByGroup(This,id,subscriberName,reserved,certExists) ) 

#define INapCertRelyingParty_UnSubscribeCertByGroup(This,reserved)	\
    ( (This)->lpVtbl -> UnSubscribeCertByGroup(This,reserved) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INapCertRelyingParty_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_napcertrelyingparty_0000_0001 */
/* [local] */ 

// Declarations of CLSIDs of objects provided  
// by the system. Link to uuid.lib to get them 
// defined.                                    
EXTERN_C const CLSID 
   CLSID_NapCertRelyingParty;


extern RPC_IF_HANDLE __MIDL_itf_napcertrelyingparty_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_napcertrelyingparty_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



