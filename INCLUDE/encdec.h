

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for encdec.idl:
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

#ifndef __encdec_h__
#define __encdec_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IETFilterConfig_FWD_DEFINED__
#define __IETFilterConfig_FWD_DEFINED__
typedef interface IETFilterConfig IETFilterConfig;
#endif 	/* __IETFilterConfig_FWD_DEFINED__ */


#ifndef __IDTFilterConfig_FWD_DEFINED__
#define __IDTFilterConfig_FWD_DEFINED__
typedef interface IDTFilterConfig IDTFilterConfig;
#endif 	/* __IDTFilterConfig_FWD_DEFINED__ */


#ifndef __IXDSCodecConfig_FWD_DEFINED__
#define __IXDSCodecConfig_FWD_DEFINED__
typedef interface IXDSCodecConfig IXDSCodecConfig;
#endif 	/* __IXDSCodecConfig_FWD_DEFINED__ */


#ifndef __IDTFilterBlockedOverlay_FWD_DEFINED__
#define __IDTFilterBlockedOverlay_FWD_DEFINED__
typedef interface IDTFilterBlockedOverlay IDTFilterBlockedOverlay;
#endif 	/* __IDTFilterBlockedOverlay_FWD_DEFINED__ */


#ifndef __IETFilter_FWD_DEFINED__
#define __IETFilter_FWD_DEFINED__
typedef interface IETFilter IETFilter;
#endif 	/* __IETFilter_FWD_DEFINED__ */


#ifndef __IETFilterEvents_FWD_DEFINED__
#define __IETFilterEvents_FWD_DEFINED__
typedef interface IETFilterEvents IETFilterEvents;
#endif 	/* __IETFilterEvents_FWD_DEFINED__ */


#ifndef __ETFilter_FWD_DEFINED__
#define __ETFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class ETFilter ETFilter;
#else
typedef struct ETFilter ETFilter;
#endif /* __cplusplus */

#endif 	/* __ETFilter_FWD_DEFINED__ */


#ifndef __IDTFilter_FWD_DEFINED__
#define __IDTFilter_FWD_DEFINED__
typedef interface IDTFilter IDTFilter;
#endif 	/* __IDTFilter_FWD_DEFINED__ */


#ifndef __IDTFilter2_FWD_DEFINED__
#define __IDTFilter2_FWD_DEFINED__
typedef interface IDTFilter2 IDTFilter2;
#endif 	/* __IDTFilter2_FWD_DEFINED__ */


#ifndef __IDTFilter3_FWD_DEFINED__
#define __IDTFilter3_FWD_DEFINED__
typedef interface IDTFilter3 IDTFilter3;
#endif 	/* __IDTFilter3_FWD_DEFINED__ */


#ifndef __IDTFilterEvents_FWD_DEFINED__
#define __IDTFilterEvents_FWD_DEFINED__
typedef interface IDTFilterEvents IDTFilterEvents;
#endif 	/* __IDTFilterEvents_FWD_DEFINED__ */


#ifndef __DTFilter_FWD_DEFINED__
#define __DTFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DTFilter DTFilter;
#else
typedef struct DTFilter DTFilter;
#endif /* __cplusplus */

#endif 	/* __DTFilter_FWD_DEFINED__ */


#ifndef __IXDSCodec_FWD_DEFINED__
#define __IXDSCodec_FWD_DEFINED__
typedef interface IXDSCodec IXDSCodec;
#endif 	/* __IXDSCodec_FWD_DEFINED__ */


#ifndef __IXDSCodecEvents_FWD_DEFINED__
#define __IXDSCodecEvents_FWD_DEFINED__
typedef interface IXDSCodecEvents IXDSCodecEvents;
#endif 	/* __IXDSCodecEvents_FWD_DEFINED__ */


#ifndef __XDSCodec_FWD_DEFINED__
#define __XDSCodec_FWD_DEFINED__

#ifdef __cplusplus
typedef class XDSCodec XDSCodec;
#else
typedef struct XDSCodec XDSCodec;
#endif /* __cplusplus */

#endif 	/* __XDSCodec_FWD_DEFINED__ */


#ifndef __CXDSData_FWD_DEFINED__
#define __CXDSData_FWD_DEFINED__

#ifdef __cplusplus
typedef class CXDSData CXDSData;
#else
typedef struct CXDSData CXDSData;
#endif /* __cplusplus */

#endif 	/* __CXDSData_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "TvRatings.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_encdec_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 2002.
//
//--------------------------------------------------------------------------
#pragma once
// {C4C4C4C4-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(SID_DRMSecureServiceChannel,
0xC4C4C4C4, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C481-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_ETFilterEncProperties,
0xC4C4C481, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C491-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_ETFilterTagProperties,
0xC4C4C491, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C482-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_DTFilterEncProperties,
0xC4C4C482, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C492-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_DTFilterTagProperties,
0xC4C4C492, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C483-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_XDSCodecProperties,
0xC4C4C483, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C493-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_XDSCodecTagProperties,
0xC4C4C493, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4FC-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(CLSID_CPCAFiltersCategory,
0xC4C4C4FC, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E0-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_XDSCodecNewXDSRating,
0xC4C4C4E0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4DF-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_XDSCodecDuplicateXDSRating,
0xC4C4C4DF, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E1-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_XDSCodecNewXDSPacket,
0xC4C4C4E1, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E2-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterRatingChange,
0xC4C4C4E2, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E3-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterRatingsBlock,
0xC4C4C4E3, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E4-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterRatingsUnblock,
0xC4C4C4E4, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E5-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterXDSPacket,
0xC4C4C4E5, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E6-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETFilterEncryptionOn,
0xC4C4C4E6, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E7-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETFilterEncryptionOff,
0xC4C4C4E7, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E8-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterCOPPUnblock,
0xC4C4C4E8, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4E9-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_EncDecFilterError,
0xC4C4C4E9, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4EA-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterCOPPBlock ,
0xC4C4C4EA, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4EB-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETFilterCopyOnce,
0xC4C4C4EB, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4F0-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETFilterCopyNever,
0xC4C4C4F0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4EC-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterDataFormatOK,
0xC4C4C4EC, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4ED-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_DTFilterDataFormatFailure,
0xC4C4C4ED, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4EE-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETDTFilterLicenseOK,
0xC4C4C4EE, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4EF-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(EVENTID_ETDTFilterLicenseFailure,
0xC4C4C4EF, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4D0-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(MEDIASUBTYPE_ETDTFilter_Tagged,
0xC4C4C4D0, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {C4C4C4D1-0049-4E2B-98FB-9537F6CE516D}
DEFINE_GUID(FORMATTYPE_ETDTFilter_Tagged,
0xC4C4C4D1, 0x0049, 0x4E2B, 0x98, 0xFB, 0x95, 0x37, 0xF6, 0xCE, 0x51, 0x6D);
// {4A1B465B-0FB9-4159-AFBD-E33006A0F9F4}
DEFINE_GUID(EVENTID_EncDecFilterEvent, 
0x4a1b465b, 0xfb9, 0x4159, 0xaf, 0xbd, 0xe3, 0x30, 0x6, 0xa0, 0xf9, 0xf4);
// {16155770-AED5-475c-BB98-95A33070DF0C}
DEFINE_GUID(EVENTID_DemultiplexerFilterDiscontinuity, 
0x16155770, 0xaed5, 0x475c, 0xbb, 0x98, 0x95, 0xa3, 0x30, 0x70, 0xdf, 0xc);
typedef LONGLONG REFERENCE_TIME;

typedef LONG PackedTvRating;


enum EncDecEvents
    {	ENCDEC_CPEVENT	= 0,
	ENCDEC_RECORDING_STATUS	= ( ENCDEC_CPEVENT + 1 ) 
    } ;

enum CPRecordingStatus
    {	RECORDING_STOPPED	= 0,
	RECORDING_STARTED	= 1
    } ;

enum CPEventBitShift
    {	CPEVENT_BITSHIFT_RATINGS	= 0,
	CPEVENT_BITSHIFT_COPP	= ( CPEVENT_BITSHIFT_RATINGS + 1 ) ,
	CPEVENT_BITSHIFT_LICENSE	= ( CPEVENT_BITSHIFT_COPP + 1 ) ,
	CPEVENT_BITSHIFT_ROLLBACK	= ( CPEVENT_BITSHIFT_LICENSE + 1 ) ,
	CPEVENT_BITSHIFT_SAC	= ( CPEVENT_BITSHIFT_ROLLBACK + 1 ) ,
	CPEVENT_BITSHIFT_DOWNRES	= ( CPEVENT_BITSHIFT_SAC + 1 ) ,
	CPEVENT_BITSHIFT_STUBLIB	= ( CPEVENT_BITSHIFT_DOWNRES + 1 ) ,
	CPEVENT_BITSHIFT_UNTRUSTEDGRAPH	= ( CPEVENT_BITSHIFT_STUBLIB + 1 ) 
    } ;

enum CPEvents
    {	CPEVENT_NONE	= 0,
	CPEVENT_RATINGS	= ( CPEVENT_NONE + 1 ) ,
	CPEVENT_COPP	= ( CPEVENT_RATINGS + 1 ) ,
	CPEVENT_LICENSE	= ( CPEVENT_COPP + 1 ) ,
	CPEVENT_ROLLBACK	= ( CPEVENT_LICENSE + 1 ) ,
	CPEVENT_SAC	= ( CPEVENT_ROLLBACK + 1 ) ,
	CPEVENT_DOWNRES	= ( CPEVENT_SAC + 1 ) ,
	CPEVENT_STUBLIB	= ( CPEVENT_DOWNRES + 1 ) ,
	CPEVENT_UNTRUSTEDGRAPH	= ( CPEVENT_STUBLIB + 1 ) 
    } ;

enum RevokedComponent
    {	REVOKED_COPP	= 0,
	REVOKED_SAC	= ( REVOKED_COPP + 1 ) ,
	REVOKED_APP_STUB	= ( REVOKED_SAC + 1 ) ,
	REVOKED_SECURE_PIPELINE	= ( REVOKED_APP_STUB + 1 ) ,
	REVOKED_MAX_TYPES	= ( REVOKED_SECURE_PIPELINE + 1 ) 
    } ;
typedef 
enum EnTag_Mode
    {	EnTag_Remove	= 0,
	EnTag_Once	= 0x1,
	EnTag_Repeat	= 0x2
    } 	EnTag_Mode;

typedef /* [public][public][public][public][public][v1_enum][uuid] */  DECLSPEC_UUID("25AEE876-3D61-4486-917E-7C0CB3D9983C") 
enum __MIDL___MIDL_itf_encdec_0000_0000_0001
    {	PROT_COPY_FREE	= 1,
	PROT_COPY_ONCE	= 2,
	PROT_COPY_NEVER	= 3,
	PROT_COPY_NEVER_REALLY	= 4,
	PROT_COPY_NO_MORE	= 5,
	PROT_COPY_FREE_CIT	= 6,
	PROT_COPY_BF	= 7,
	PROT_COPY_CN_RECORDING_STOP	= 8,
	PROT_COPY_FREE_SECURE	= 9,
	PROT_COPY_INVALID	= 50
    } 	ProtType;

typedef /* [public][v1_enum][uuid] */  DECLSPEC_UUID("6F8C2442-2BFB-4180-9EE5-EA1FB47AE35C") 
enum __MIDL___MIDL_itf_encdec_0000_0000_0002
    {	COPP_BadDriver	= 0,
	COPP_NoCardHDCPSupport	= 1,
	COPP_NoMonitorHDCPSupport	= 2,
	COPP_BadCertificate	= 3
    } 	COPPEventBlockReason;

typedef /* [public][v1_enum][uuid] */  DECLSPEC_UUID("57BCA1BE-DF7A-434e-8B89-26D6A0541FDA") 
enum __MIDL___MIDL_itf_encdec_0000_0000_0003
    {	LIC_BadLicense	= 0,
	LIC_NeedIndiv	= 1
    } 	LicenseEventBlockReason;

typedef /* [public][v1_enum][uuid] */  DECLSPEC_UUID("D5CC1CDC-EF31-48dc-95B8-AFD34C08036B") 
enum __MIDL___MIDL_itf_encdec_0000_0000_0004
    {	DOWNRES_Always	= 0,
	DOWNRES_InWindowOnly	= 1,
	DOWNRES_Undefined	= 2
    } 	DownResEventParam;



extern RPC_IF_HANDLE __MIDL_itf_encdec_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_encdec_0000_0000_v0_0_s_ifspec;

#ifndef __IETFilterConfig_INTERFACE_DEFINED__
#define __IETFilterConfig_INTERFACE_DEFINED__

/* interface IETFilterConfig */
/* [unique][helpstring][uuid][object][restricted] */ 


EXTERN_C const IID IID_IETFilterConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4D1-0049-4E2B-98FB-9537F6CE516D")
    IETFilterConfig : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitLicense( 
            /* [in] */ int LicenseId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSecureChannelObject( 
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IETFilterConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IETFilterConfig * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IETFilterConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IETFilterConfig * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitLicense )( 
            IETFilterConfig * This,
            /* [in] */ int LicenseId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSecureChannelObject )( 
            IETFilterConfig * This,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel);
        
        END_INTERFACE
    } IETFilterConfigVtbl;

    interface IETFilterConfig
    {
        CONST_VTBL struct IETFilterConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IETFilterConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IETFilterConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IETFilterConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IETFilterConfig_InitLicense(This,LicenseId)	\
    ( (This)->lpVtbl -> InitLicense(This,LicenseId) ) 

#define IETFilterConfig_GetSecureChannelObject(This,ppUnkDRMSecureChannel)	\
    ( (This)->lpVtbl -> GetSecureChannelObject(This,ppUnkDRMSecureChannel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IETFilterConfig_INTERFACE_DEFINED__ */


#ifndef __IDTFilterConfig_INTERFACE_DEFINED__
#define __IDTFilterConfig_INTERFACE_DEFINED__

/* interface IDTFilterConfig */
/* [unique][helpstring][uuid][object][restricted] */ 


EXTERN_C const IID IID_IDTFilterConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4D2-0049-4E2B-98FB-9537F6CE516D")
    IDTFilterConfig : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSecureChannelObject( 
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTFilterConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilterConfig * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilterConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilterConfig * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSecureChannelObject )( 
            IDTFilterConfig * This,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel);
        
        END_INTERFACE
    } IDTFilterConfigVtbl;

    interface IDTFilterConfig
    {
        CONST_VTBL struct IDTFilterConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilterConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilterConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilterConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilterConfig_GetSecureChannelObject(This,ppUnkDRMSecureChannel)	\
    ( (This)->lpVtbl -> GetSecureChannelObject(This,ppUnkDRMSecureChannel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTFilterConfig_INTERFACE_DEFINED__ */


#ifndef __IXDSCodecConfig_INTERFACE_DEFINED__
#define __IXDSCodecConfig_INTERFACE_DEFINED__

/* interface IXDSCodecConfig */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXDSCodecConfig;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4D3-0049-4E2B-98FB-9537F6CE516D")
    IXDSCodecConfig : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSecureChannelObject( 
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPauseBufferTime( 
            /* [in] */ DWORD dwPauseBufferTime) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXDSCodecConfigVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXDSCodecConfig * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXDSCodecConfig * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXDSCodecConfig * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSecureChannelObject )( 
            IXDSCodecConfig * This,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppUnkDRMSecureChannel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPauseBufferTime )( 
            IXDSCodecConfig * This,
            /* [in] */ DWORD dwPauseBufferTime);
        
        END_INTERFACE
    } IXDSCodecConfigVtbl;

    interface IXDSCodecConfig
    {
        CONST_VTBL struct IXDSCodecConfigVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXDSCodecConfig_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXDSCodecConfig_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXDSCodecConfig_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXDSCodecConfig_GetSecureChannelObject(This,ppUnkDRMSecureChannel)	\
    ( (This)->lpVtbl -> GetSecureChannelObject(This,ppUnkDRMSecureChannel) ) 

#define IXDSCodecConfig_SetPauseBufferTime(This,dwPauseBufferTime)	\
    ( (This)->lpVtbl -> SetPauseBufferTime(This,dwPauseBufferTime) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXDSCodecConfig_INTERFACE_DEFINED__ */


#ifndef __IDTFilterBlockedOverlay_INTERFACE_DEFINED__
#define __IDTFilterBlockedOverlay_INTERFACE_DEFINED__

/* interface IDTFilterBlockedOverlay */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDTFilterBlockedOverlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FAF37694-909C-49cd-886F-C7382E5DB596")
    IDTFilterBlockedOverlay : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetOverlay( 
            /* [in] */ DWORD dwOverlayCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearOverlay( 
            /* [in] */ DWORD dwOverlayCause) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOverlay( 
            /* [out] */ __RPC__out DWORD *pdwOverlayCause) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTFilterBlockedOverlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilterBlockedOverlay * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilterBlockedOverlay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilterBlockedOverlay * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOverlay )( 
            IDTFilterBlockedOverlay * This,
            /* [in] */ DWORD dwOverlayCause);
        
        HRESULT ( STDMETHODCALLTYPE *ClearOverlay )( 
            IDTFilterBlockedOverlay * This,
            /* [in] */ DWORD dwOverlayCause);
        
        HRESULT ( STDMETHODCALLTYPE *GetOverlay )( 
            IDTFilterBlockedOverlay * This,
            /* [out] */ __RPC__out DWORD *pdwOverlayCause);
        
        END_INTERFACE
    } IDTFilterBlockedOverlayVtbl;

    interface IDTFilterBlockedOverlay
    {
        CONST_VTBL struct IDTFilterBlockedOverlayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilterBlockedOverlay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilterBlockedOverlay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilterBlockedOverlay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilterBlockedOverlay_SetOverlay(This,dwOverlayCause)	\
    ( (This)->lpVtbl -> SetOverlay(This,dwOverlayCause) ) 

#define IDTFilterBlockedOverlay_ClearOverlay(This,dwOverlayCause)	\
    ( (This)->lpVtbl -> ClearOverlay(This,dwOverlayCause) ) 

#define IDTFilterBlockedOverlay_GetOverlay(This,pdwOverlayCause)	\
    ( (This)->lpVtbl -> GetOverlay(This,pdwOverlayCause) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTFilterBlockedOverlay_INTERFACE_DEFINED__ */



#ifndef __EncDec_LIBRARY_DEFINED__
#define __EncDec_LIBRARY_DEFINED__

/* library EncDec */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_EncDec;

#ifndef __IETFilter_INTERFACE_DEFINED__
#define __IETFilter_INTERFACE_DEFINED__

/* interface IETFilter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IETFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4B1-0049-4E2B-98FB-9537F6CE516D")
    IETFilter : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EvalRatObjOK( 
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrRating( 
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrLicenseExpDate( 
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastErrorCode( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRecordingOn( 
            BOOL fRecState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IETFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IETFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IETFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IETFilter * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EvalRatObjOK )( 
            IETFilter * This,
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrRating )( 
            IETFilter * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrLicenseExpDate )( 
            IETFilter * This,
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastErrorCode )( 
            IETFilter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRecordingOn )( 
            IETFilter * This,
            BOOL fRecState);
        
        END_INTERFACE
    } IETFilterVtbl;

    interface IETFilter
    {
        CONST_VTBL struct IETFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IETFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IETFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IETFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IETFilter_get_EvalRatObjOK(This,pHrCoCreateRetVal)	\
    ( (This)->lpVtbl -> get_EvalRatObjOK(This,pHrCoCreateRetVal) ) 

#define IETFilter_GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr)	\
    ( (This)->lpVtbl -> GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr) ) 

#define IETFilter_GetCurrLicenseExpDate(This,protType,lpDateTime)	\
    ( (This)->lpVtbl -> GetCurrLicenseExpDate(This,protType,lpDateTime) ) 

#define IETFilter_GetLastErrorCode(This)	\
    ( (This)->lpVtbl -> GetLastErrorCode(This) ) 

#define IETFilter_SetRecordingOn(This,fRecState)	\
    ( (This)->lpVtbl -> SetRecordingOn(This,fRecState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IETFilter_INTERFACE_DEFINED__ */


#ifndef __IETFilterEvents_DISPINTERFACE_DEFINED__
#define __IETFilterEvents_DISPINTERFACE_DEFINED__

/* dispinterface IETFilterEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IETFilterEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C4C4C4C1-0049-4E2B-98FB-9537F6CE516D")
    IETFilterEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IETFilterEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IETFilterEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IETFilterEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IETFilterEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IETFilterEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IETFilterEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IETFilterEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IETFilterEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IETFilterEventsVtbl;

    interface IETFilterEvents
    {
        CONST_VTBL struct IETFilterEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IETFilterEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IETFilterEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IETFilterEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IETFilterEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IETFilterEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IETFilterEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IETFilterEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IETFilterEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ETFilter;

#ifdef __cplusplus

class DECLSPEC_UUID("C4C4C4F1-0049-4E2B-98FB-9537F6CE516D")
ETFilter;
#endif

#ifndef __IDTFilter_INTERFACE_DEFINED__
#define __IDTFilter_INTERFACE_DEFINED__

/* interface IDTFilter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDTFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4B2-0049-4E2B-98FB-9537F6CE516D")
    IDTFilter : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EvalRatObjOK( 
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrRating( 
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockedRatingAttributes( 
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [retval][out] */ __RPC__out LONG *plbfEnAttr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockedRatingAttributes( 
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [in] */ LONG lbfAttrs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockUnRated( 
            /* [retval][out] */ __RPC__out BOOL *pfBlockUnRatedShows) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockUnRated( 
            /* [in] */ BOOL fBlockUnRatedShows) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockUnRatedDelay( 
            /* [retval][out] */ __RPC__out LONG *pmsecsDelayBeforeBlock) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockUnRatedDelay( 
            /* [in] */ LONG msecsDelayBeforeBlock) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilter * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilter * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EvalRatObjOK )( 
            IDTFilter * This,
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrRating )( 
            IDTFilter * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedRatingAttributes )( 
            IDTFilter * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [retval][out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedRatingAttributes )( 
            IDTFilter * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [in] */ LONG lbfAttrs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRated )( 
            IDTFilter * This,
            /* [retval][out] */ __RPC__out BOOL *pfBlockUnRatedShows);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRated )( 
            IDTFilter * This,
            /* [in] */ BOOL fBlockUnRatedShows);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRatedDelay )( 
            IDTFilter * This,
            /* [retval][out] */ __RPC__out LONG *pmsecsDelayBeforeBlock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRatedDelay )( 
            IDTFilter * This,
            /* [in] */ LONG msecsDelayBeforeBlock);
        
        END_INTERFACE
    } IDTFilterVtbl;

    interface IDTFilter
    {
        CONST_VTBL struct IDTFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilter_get_EvalRatObjOK(This,pHrCoCreateRetVal)	\
    ( (This)->lpVtbl -> get_EvalRatObjOK(This,pHrCoCreateRetVal) ) 

#define IDTFilter_GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr)	\
    ( (This)->lpVtbl -> GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr) ) 

#define IDTFilter_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr)	\
    ( (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr) ) 

#define IDTFilter_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    ( (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs) ) 

#define IDTFilter_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    ( (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows) ) 

#define IDTFilter_put_BlockUnRated(This,fBlockUnRatedShows)	\
    ( (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows) ) 

#define IDTFilter_get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock) ) 

#define IDTFilter_put_BlockUnRatedDelay(This,msecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> put_BlockUnRatedDelay(This,msecsDelayBeforeBlock) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTFilter_INTERFACE_DEFINED__ */


#ifndef __IDTFilter2_INTERFACE_DEFINED__
#define __IDTFilter2_INTERFACE_DEFINED__

/* interface IDTFilter2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDTFilter2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4B4-0049-4E2B-98FB-9537F6CE516D")
    IDTFilter2 : public IDTFilter
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChallengeUrl( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrChallengeUrl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrLicenseExpDate( 
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastErrorCode( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTFilter2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilter2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilter2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilter2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EvalRatObjOK )( 
            IDTFilter2 * This,
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrRating )( 
            IDTFilter2 * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedRatingAttributes )( 
            IDTFilter2 * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [retval][out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedRatingAttributes )( 
            IDTFilter2 * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [in] */ LONG lbfAttrs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRated )( 
            IDTFilter2 * This,
            /* [retval][out] */ __RPC__out BOOL *pfBlockUnRatedShows);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRated )( 
            IDTFilter2 * This,
            /* [in] */ BOOL fBlockUnRatedShows);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRatedDelay )( 
            IDTFilter2 * This,
            /* [retval][out] */ __RPC__out LONG *pmsecsDelayBeforeBlock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRatedDelay )( 
            IDTFilter2 * This,
            /* [in] */ LONG msecsDelayBeforeBlock);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChallengeUrl )( 
            IDTFilter2 * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrChallengeUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrLicenseExpDate )( 
            IDTFilter2 * This,
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastErrorCode )( 
            IDTFilter2 * This);
        
        END_INTERFACE
    } IDTFilter2Vtbl;

    interface IDTFilter2
    {
        CONST_VTBL struct IDTFilter2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilter2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilter2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilter2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilter2_get_EvalRatObjOK(This,pHrCoCreateRetVal)	\
    ( (This)->lpVtbl -> get_EvalRatObjOK(This,pHrCoCreateRetVal) ) 

#define IDTFilter2_GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr)	\
    ( (This)->lpVtbl -> GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr) ) 

#define IDTFilter2_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr)	\
    ( (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr) ) 

#define IDTFilter2_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    ( (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs) ) 

#define IDTFilter2_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    ( (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows) ) 

#define IDTFilter2_put_BlockUnRated(This,fBlockUnRatedShows)	\
    ( (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows) ) 

#define IDTFilter2_get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock) ) 

#define IDTFilter2_put_BlockUnRatedDelay(This,msecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> put_BlockUnRatedDelay(This,msecsDelayBeforeBlock) ) 


#define IDTFilter2_get_ChallengeUrl(This,pbstrChallengeUrl)	\
    ( (This)->lpVtbl -> get_ChallengeUrl(This,pbstrChallengeUrl) ) 

#define IDTFilter2_GetCurrLicenseExpDate(This,protType,lpDateTime)	\
    ( (This)->lpVtbl -> GetCurrLicenseExpDate(This,protType,lpDateTime) ) 

#define IDTFilter2_GetLastErrorCode(This)	\
    ( (This)->lpVtbl -> GetLastErrorCode(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTFilter2_INTERFACE_DEFINED__ */


#ifndef __IDTFilter3_INTERFACE_DEFINED__
#define __IDTFilter3_INTERFACE_DEFINED__

/* interface IDTFilter3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDTFilter3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("513998cc-e929-4cdf-9fbd-bad1e0314866")
    IDTFilter3 : public IDTFilter2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProtectionType( 
            /* [out] */ __RPC__out ProtType *pProtectionType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LicenseHasExpirationDate( 
            /* [out] */ __RPC__out BOOL *pfLicenseHasExpirationDate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRights( 
            /* [in] */ __RPC__in BSTR bstrRights) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDTFilter3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilter3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilter3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilter3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EvalRatObjOK )( 
            IDTFilter3 * This,
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrRating )( 
            IDTFilter3 * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedRatingAttributes )( 
            IDTFilter3 * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [retval][out] */ __RPC__out LONG *plbfEnAttr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockedRatingAttributes )( 
            IDTFilter3 * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enLevel,
            /* [in] */ LONG lbfAttrs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRated )( 
            IDTFilter3 * This,
            /* [retval][out] */ __RPC__out BOOL *pfBlockUnRatedShows);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRated )( 
            IDTFilter3 * This,
            /* [in] */ BOOL fBlockUnRatedShows);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockUnRatedDelay )( 
            IDTFilter3 * This,
            /* [retval][out] */ __RPC__out LONG *pmsecsDelayBeforeBlock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnRatedDelay )( 
            IDTFilter3 * This,
            /* [in] */ LONG msecsDelayBeforeBlock);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChallengeUrl )( 
            IDTFilter3 * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrChallengeUrl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrLicenseExpDate )( 
            IDTFilter3 * This,
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastErrorCode )( 
            IDTFilter3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProtectionType )( 
            IDTFilter3 * This,
            /* [out] */ __RPC__out ProtType *pProtectionType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LicenseHasExpirationDate )( 
            IDTFilter3 * This,
            /* [out] */ __RPC__out BOOL *pfLicenseHasExpirationDate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRights )( 
            IDTFilter3 * This,
            /* [in] */ __RPC__in BSTR bstrRights);
        
        END_INTERFACE
    } IDTFilter3Vtbl;

    interface IDTFilter3
    {
        CONST_VTBL struct IDTFilter3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilter3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilter3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilter3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilter3_get_EvalRatObjOK(This,pHrCoCreateRetVal)	\
    ( (This)->lpVtbl -> get_EvalRatObjOK(This,pHrCoCreateRetVal) ) 

#define IDTFilter3_GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr)	\
    ( (This)->lpVtbl -> GetCurrRating(This,pEnSystem,pEnRating,plbfEnAttr) ) 

#define IDTFilter3_get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr)	\
    ( (This)->lpVtbl -> get_BlockedRatingAttributes(This,enSystem,enLevel,plbfEnAttr) ) 

#define IDTFilter3_put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs)	\
    ( (This)->lpVtbl -> put_BlockedRatingAttributes(This,enSystem,enLevel,lbfAttrs) ) 

#define IDTFilter3_get_BlockUnRated(This,pfBlockUnRatedShows)	\
    ( (This)->lpVtbl -> get_BlockUnRated(This,pfBlockUnRatedShows) ) 

#define IDTFilter3_put_BlockUnRated(This,fBlockUnRatedShows)	\
    ( (This)->lpVtbl -> put_BlockUnRated(This,fBlockUnRatedShows) ) 

#define IDTFilter3_get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> get_BlockUnRatedDelay(This,pmsecsDelayBeforeBlock) ) 

#define IDTFilter3_put_BlockUnRatedDelay(This,msecsDelayBeforeBlock)	\
    ( (This)->lpVtbl -> put_BlockUnRatedDelay(This,msecsDelayBeforeBlock) ) 


#define IDTFilter3_get_ChallengeUrl(This,pbstrChallengeUrl)	\
    ( (This)->lpVtbl -> get_ChallengeUrl(This,pbstrChallengeUrl) ) 

#define IDTFilter3_GetCurrLicenseExpDate(This,protType,lpDateTime)	\
    ( (This)->lpVtbl -> GetCurrLicenseExpDate(This,protType,lpDateTime) ) 

#define IDTFilter3_GetLastErrorCode(This)	\
    ( (This)->lpVtbl -> GetLastErrorCode(This) ) 


#define IDTFilter3_GetProtectionType(This,pProtectionType)	\
    ( (This)->lpVtbl -> GetProtectionType(This,pProtectionType) ) 

#define IDTFilter3_LicenseHasExpirationDate(This,pfLicenseHasExpirationDate)	\
    ( (This)->lpVtbl -> LicenseHasExpirationDate(This,pfLicenseHasExpirationDate) ) 

#define IDTFilter3_SetRights(This,bstrRights)	\
    ( (This)->lpVtbl -> SetRights(This,bstrRights) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDTFilter3_INTERFACE_DEFINED__ */


#ifndef __IDTFilterEvents_DISPINTERFACE_DEFINED__
#define __IDTFilterEvents_DISPINTERFACE_DEFINED__

/* dispinterface IDTFilterEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IDTFilterEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C4C4C4C2-0049-4E2B-98FB-9537F6CE516D")
    IDTFilterEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDTFilterEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDTFilterEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDTFilterEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDTFilterEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDTFilterEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDTFilterEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDTFilterEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDTFilterEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IDTFilterEventsVtbl;

    interface IDTFilterEvents
    {
        CONST_VTBL struct IDTFilterEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDTFilterEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDTFilterEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDTFilterEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDTFilterEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDTFilterEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDTFilterEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDTFilterEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDTFilterEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_DTFilter;

#ifdef __cplusplus

class DECLSPEC_UUID("C4C4C4F2-0049-4E2B-98FB-9537F6CE516D")
DTFilter;
#endif

#ifndef __IXDSCodec_INTERFACE_DEFINED__
#define __IXDSCodec_INTERFACE_DEFINED__

/* interface IXDSCodec */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXDSCodec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4C4C4B3-0049-4E2B-98FB-9537F6CE516D")
    IXDSCodec : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XDSToRatObjOK( 
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CCSubstreamService( 
            /* [in] */ long SubstreamMask) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CCSubstreamService( 
            /* [retval][out] */ __RPC__out long *pSubstreamMask) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetContentAdvisoryRating( 
            /* [out] */ __RPC__out PackedTvRating *pRat,
            /* [out] */ __RPC__out long *pPktSeqID,
            /* [out] */ __RPC__out long *pCallSeqID,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeStart,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeEnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXDSPacket( 
            /* [out] */ __RPC__out long *pXDSClassPkt,
            /* [out] */ __RPC__out long *pXDSTypePkt,
            /* [out] */ __RPC__deref_out_opt BSTR *pBstrXDSPkt,
            /* [out] */ __RPC__out long *pPktSeqID,
            /* [out] */ __RPC__out long *pCallSeqID,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeStart,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeEnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrLicenseExpDate( 
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastErrorCode( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXDSCodecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXDSCodec * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXDSCodec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXDSCodec * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XDSToRatObjOK )( 
            IXDSCodec * This,
            /* [retval][out] */ __RPC__out HRESULT *pHrCoCreateRetVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CCSubstreamService )( 
            IXDSCodec * This,
            /* [in] */ long SubstreamMask);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CCSubstreamService )( 
            IXDSCodec * This,
            /* [retval][out] */ __RPC__out long *pSubstreamMask);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetContentAdvisoryRating )( 
            IXDSCodec * This,
            /* [out] */ __RPC__out PackedTvRating *pRat,
            /* [out] */ __RPC__out long *pPktSeqID,
            /* [out] */ __RPC__out long *pCallSeqID,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeStart,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeEnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXDSPacket )( 
            IXDSCodec * This,
            /* [out] */ __RPC__out long *pXDSClassPkt,
            /* [out] */ __RPC__out long *pXDSTypePkt,
            /* [out] */ __RPC__deref_out_opt BSTR *pBstrXDSPkt,
            /* [out] */ __RPC__out long *pPktSeqID,
            /* [out] */ __RPC__out long *pCallSeqID,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeStart,
            /* [out] */ __RPC__out REFERENCE_TIME *pTimeEnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrLicenseExpDate )( 
            IXDSCodec * This,
            /* [in] */ __RPC__in ProtType *protType,
            /* [out] */ __RPC__out long *lpDateTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastErrorCode )( 
            IXDSCodec * This);
        
        END_INTERFACE
    } IXDSCodecVtbl;

    interface IXDSCodec
    {
        CONST_VTBL struct IXDSCodecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXDSCodec_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXDSCodec_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXDSCodec_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXDSCodec_get_XDSToRatObjOK(This,pHrCoCreateRetVal)	\
    ( (This)->lpVtbl -> get_XDSToRatObjOK(This,pHrCoCreateRetVal) ) 

#define IXDSCodec_put_CCSubstreamService(This,SubstreamMask)	\
    ( (This)->lpVtbl -> put_CCSubstreamService(This,SubstreamMask) ) 

#define IXDSCodec_get_CCSubstreamService(This,pSubstreamMask)	\
    ( (This)->lpVtbl -> get_CCSubstreamService(This,pSubstreamMask) ) 

#define IXDSCodec_GetContentAdvisoryRating(This,pRat,pPktSeqID,pCallSeqID,pTimeStart,pTimeEnd)	\
    ( (This)->lpVtbl -> GetContentAdvisoryRating(This,pRat,pPktSeqID,pCallSeqID,pTimeStart,pTimeEnd) ) 

#define IXDSCodec_GetXDSPacket(This,pXDSClassPkt,pXDSTypePkt,pBstrXDSPkt,pPktSeqID,pCallSeqID,pTimeStart,pTimeEnd)	\
    ( (This)->lpVtbl -> GetXDSPacket(This,pXDSClassPkt,pXDSTypePkt,pBstrXDSPkt,pPktSeqID,pCallSeqID,pTimeStart,pTimeEnd) ) 

#define IXDSCodec_GetCurrLicenseExpDate(This,protType,lpDateTime)	\
    ( (This)->lpVtbl -> GetCurrLicenseExpDate(This,protType,lpDateTime) ) 

#define IXDSCodec_GetLastErrorCode(This)	\
    ( (This)->lpVtbl -> GetLastErrorCode(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXDSCodec_INTERFACE_DEFINED__ */


#ifndef __IXDSCodecEvents_DISPINTERFACE_DEFINED__
#define __IXDSCodecEvents_DISPINTERFACE_DEFINED__

/* dispinterface IXDSCodecEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_IXDSCodecEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C4C4C4C3-0049-4E2B-98FB-9537F6CE516D")
    IXDSCodecEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IXDSCodecEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXDSCodecEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXDSCodecEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXDSCodecEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXDSCodecEvents * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXDSCodecEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXDSCodecEvents * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXDSCodecEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IXDSCodecEventsVtbl;

    interface IXDSCodecEvents
    {
        CONST_VTBL struct IXDSCodecEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXDSCodecEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXDSCodecEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXDSCodecEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXDSCodecEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXDSCodecEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXDSCodecEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXDSCodecEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IXDSCodecEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_XDSCodec;

#ifdef __cplusplus

class DECLSPEC_UUID("C4C4C4F3-0049-4E2B-98FB-9537F6CE516D")
XDSCodec;
#endif

EXTERN_C const CLSID CLSID_CXDSData;

#ifdef __cplusplus

class DECLSPEC_UUID("C4C4C4F4-0049-4E2B-98FB-9537F6CE516D")
CXDSData;
#endif
#endif /* __EncDec_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



