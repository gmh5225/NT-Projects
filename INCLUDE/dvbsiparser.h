

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for dvbsiparser.idl:
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

#ifndef __dvbsiparser_h__
#define __dvbsiparser_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDvbSiParser_FWD_DEFINED__
#define __IDvbSiParser_FWD_DEFINED__
typedef interface IDvbSiParser IDvbSiParser;
#endif 	/* __IDvbSiParser_FWD_DEFINED__ */


#ifndef __IDVB_NIT_FWD_DEFINED__
#define __IDVB_NIT_FWD_DEFINED__
typedef interface IDVB_NIT IDVB_NIT;
#endif 	/* __IDVB_NIT_FWD_DEFINED__ */


#ifndef __IDVB_SDT_FWD_DEFINED__
#define __IDVB_SDT_FWD_DEFINED__
typedef interface IDVB_SDT IDVB_SDT;
#endif 	/* __IDVB_SDT_FWD_DEFINED__ */


#ifndef __IDVB_EIT_FWD_DEFINED__
#define __IDVB_EIT_FWD_DEFINED__
typedef interface IDVB_EIT IDVB_EIT;
#endif 	/* __IDVB_EIT_FWD_DEFINED__ */


#ifndef __IDVB_BAT_FWD_DEFINED__
#define __IDVB_BAT_FWD_DEFINED__
typedef interface IDVB_BAT IDVB_BAT;
#endif 	/* __IDVB_BAT_FWD_DEFINED__ */


#ifndef __IDVB_RST_FWD_DEFINED__
#define __IDVB_RST_FWD_DEFINED__
typedef interface IDVB_RST IDVB_RST;
#endif 	/* __IDVB_RST_FWD_DEFINED__ */


#ifndef __IDVB_ST_FWD_DEFINED__
#define __IDVB_ST_FWD_DEFINED__
typedef interface IDVB_ST IDVB_ST;
#endif 	/* __IDVB_ST_FWD_DEFINED__ */


#ifndef __IDVB_TDT_FWD_DEFINED__
#define __IDVB_TDT_FWD_DEFINED__
typedef interface IDVB_TDT IDVB_TDT;
#endif 	/* __IDVB_TDT_FWD_DEFINED__ */


#ifndef __IDVB_TOT_FWD_DEFINED__
#define __IDVB_TOT_FWD_DEFINED__
typedef interface IDVB_TOT IDVB_TOT;
#endif 	/* __IDVB_TOT_FWD_DEFINED__ */


#ifndef __IDVB_DIT_FWD_DEFINED__
#define __IDVB_DIT_FWD_DEFINED__
typedef interface IDVB_DIT IDVB_DIT;
#endif 	/* __IDVB_DIT_FWD_DEFINED__ */


#ifndef __IDVB_SIT_FWD_DEFINED__
#define __IDVB_SIT_FWD_DEFINED__
typedef interface IDVB_SIT IDVB_SIT;
#endif 	/* __IDVB_SIT_FWD_DEFINED__ */


#ifndef __IDvbSatelliteDeliverySystemDescriptor_FWD_DEFINED__
#define __IDvbSatelliteDeliverySystemDescriptor_FWD_DEFINED__
typedef interface IDvbSatelliteDeliverySystemDescriptor IDvbSatelliteDeliverySystemDescriptor;
#endif 	/* __IDvbSatelliteDeliverySystemDescriptor_FWD_DEFINED__ */


#ifndef __IDvbCableDeliverySystemDescriptor_FWD_DEFINED__
#define __IDvbCableDeliverySystemDescriptor_FWD_DEFINED__
typedef interface IDvbCableDeliverySystemDescriptor IDvbCableDeliverySystemDescriptor;
#endif 	/* __IDvbCableDeliverySystemDescriptor_FWD_DEFINED__ */


#ifndef __IDvbTerrestrialDeliverySystemDescriptor_FWD_DEFINED__
#define __IDvbTerrestrialDeliverySystemDescriptor_FWD_DEFINED__
typedef interface IDvbTerrestrialDeliverySystemDescriptor IDvbTerrestrialDeliverySystemDescriptor;
#endif 	/* __IDvbTerrestrialDeliverySystemDescriptor_FWD_DEFINED__ */


#ifndef __IDvbFrequencyListDescriptor_FWD_DEFINED__
#define __IDvbFrequencyListDescriptor_FWD_DEFINED__
typedef interface IDvbFrequencyListDescriptor IDvbFrequencyListDescriptor;
#endif 	/* __IDvbFrequencyListDescriptor_FWD_DEFINED__ */


#ifndef __IDvbLogicalChannelDescriptor_FWD_DEFINED__
#define __IDvbLogicalChannelDescriptor_FWD_DEFINED__
typedef interface IDvbLogicalChannelDescriptor IDvbLogicalChannelDescriptor;
#endif 	/* __IDvbLogicalChannelDescriptor_FWD_DEFINED__ */


#ifndef __IDvbServiceDescriptor_FWD_DEFINED__
#define __IDvbServiceDescriptor_FWD_DEFINED__
typedef interface IDvbServiceDescriptor IDvbServiceDescriptor;
#endif 	/* __IDvbServiceDescriptor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mpeg2structs.h"
#include "mpeg2data.h"
#include "mpeg2psiparser.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dvbsiparser_0000_0000 */
/* [local] */ 

















extern RPC_IF_HANDLE __MIDL_itf_dvbsiparser_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dvbsiparser_0000_0000_v0_0_s_ifspec;

#ifndef __IDvbSiParser_INTERFACE_DEFINED__
#define __IDvbSiParser_INTERFACE_DEFINED__

/* interface IDvbSiParser */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbSiParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B758A7BD-14DC-449d-B828-35909ACB3B1E")
    IDvbSiParser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt IUnknown *punkMpeg2Data) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPAT( 
            /* [out] */ __RPC__deref_out_opt IPAT **ppPAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCAT( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt ICAT **ppCAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPMT( 
            /* [in] */ PID pid,
            /* [in] */ __RPC__in WORD *pwProgramNumber,
            /* [out] */ __RPC__deref_out_opt IPMT **ppPMT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTSDT( 
            /* [out] */ __RPC__deref_out_opt ITSDT **ppTSDT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNIT( 
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwNetworkId,
            /* [out] */ __RPC__deref_out_opt IDVB_NIT **ppNIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSDT( 
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwTransportStreamId,
            /* [out] */ __RPC__deref_out_opt IDVB_SDT **ppSDT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEIT( 
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwServiceId,
            /* [out] */ __RPC__deref_out_opt IDVB_EIT **ppEIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBAT( 
            /* [in] */ __RPC__in WORD *pwBouquetId,
            /* [out] */ __RPC__deref_out_opt IDVB_BAT **ppBAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRST( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_RST **ppRST) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetST( 
            /* [in] */ PID pid,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_ST **ppST) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTDT( 
            /* [out] */ __RPC__deref_out_opt IDVB_TDT **ppTDT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTOT( 
            /* [out] */ __RPC__deref_out_opt IDVB_TOT **ppTOT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDIT( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_DIT **ppDIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSIT( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_SIT **ppSIT) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbSiParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbSiParser * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbSiParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbSiParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDvbSiParser * This,
            /* [in] */ __RPC__in_opt IUnknown *punkMpeg2Data);
        
        HRESULT ( STDMETHODCALLTYPE *GetPAT )( 
            IDvbSiParser * This,
            /* [out] */ __RPC__deref_out_opt IPAT **ppPAT);
        
        HRESULT ( STDMETHODCALLTYPE *GetCAT )( 
            IDvbSiParser * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt ICAT **ppCAT);
        
        HRESULT ( STDMETHODCALLTYPE *GetPMT )( 
            IDvbSiParser * This,
            /* [in] */ PID pid,
            /* [in] */ __RPC__in WORD *pwProgramNumber,
            /* [out] */ __RPC__deref_out_opt IPMT **ppPMT);
        
        HRESULT ( STDMETHODCALLTYPE *GetTSDT )( 
            IDvbSiParser * This,
            /* [out] */ __RPC__deref_out_opt ITSDT **ppTSDT);
        
        HRESULT ( STDMETHODCALLTYPE *GetNIT )( 
            IDvbSiParser * This,
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwNetworkId,
            /* [out] */ __RPC__deref_out_opt IDVB_NIT **ppNIT);
        
        HRESULT ( STDMETHODCALLTYPE *GetSDT )( 
            IDvbSiParser * This,
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwTransportStreamId,
            /* [out] */ __RPC__deref_out_opt IDVB_SDT **ppSDT);
        
        HRESULT ( STDMETHODCALLTYPE *GetEIT )( 
            IDvbSiParser * This,
            /* [in] */ TID tableId,
            /* [in] */ __RPC__in WORD *pwServiceId,
            /* [out] */ __RPC__deref_out_opt IDVB_EIT **ppEIT);
        
        HRESULT ( STDMETHODCALLTYPE *GetBAT )( 
            IDvbSiParser * This,
            /* [in] */ __RPC__in WORD *pwBouquetId,
            /* [out] */ __RPC__deref_out_opt IDVB_BAT **ppBAT);
        
        HRESULT ( STDMETHODCALLTYPE *GetRST )( 
            IDvbSiParser * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_RST **ppRST);
        
        HRESULT ( STDMETHODCALLTYPE *GetST )( 
            IDvbSiParser * This,
            /* [in] */ PID pid,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_ST **ppST);
        
        HRESULT ( STDMETHODCALLTYPE *GetTDT )( 
            IDvbSiParser * This,
            /* [out] */ __RPC__deref_out_opt IDVB_TDT **ppTDT);
        
        HRESULT ( STDMETHODCALLTYPE *GetTOT )( 
            IDvbSiParser * This,
            /* [out] */ __RPC__deref_out_opt IDVB_TOT **ppTOT);
        
        HRESULT ( STDMETHODCALLTYPE *GetDIT )( 
            IDvbSiParser * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_DIT **ppDIT);
        
        HRESULT ( STDMETHODCALLTYPE *GetSIT )( 
            IDvbSiParser * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ __RPC__deref_out_opt IDVB_SIT **ppSIT);
        
        END_INTERFACE
    } IDvbSiParserVtbl;

    interface IDvbSiParser
    {
        CONST_VTBL struct IDvbSiParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbSiParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbSiParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbSiParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbSiParser_Initialize(This,punkMpeg2Data)	\
    ( (This)->lpVtbl -> Initialize(This,punkMpeg2Data) ) 

#define IDvbSiParser_GetPAT(This,ppPAT)	\
    ( (This)->lpVtbl -> GetPAT(This,ppPAT) ) 

#define IDvbSiParser_GetCAT(This,dwTimeout,ppCAT)	\
    ( (This)->lpVtbl -> GetCAT(This,dwTimeout,ppCAT) ) 

#define IDvbSiParser_GetPMT(This,pid,pwProgramNumber,ppPMT)	\
    ( (This)->lpVtbl -> GetPMT(This,pid,pwProgramNumber,ppPMT) ) 

#define IDvbSiParser_GetTSDT(This,ppTSDT)	\
    ( (This)->lpVtbl -> GetTSDT(This,ppTSDT) ) 

#define IDvbSiParser_GetNIT(This,tableId,pwNetworkId,ppNIT)	\
    ( (This)->lpVtbl -> GetNIT(This,tableId,pwNetworkId,ppNIT) ) 

#define IDvbSiParser_GetSDT(This,tableId,pwTransportStreamId,ppSDT)	\
    ( (This)->lpVtbl -> GetSDT(This,tableId,pwTransportStreamId,ppSDT) ) 

#define IDvbSiParser_GetEIT(This,tableId,pwServiceId,ppEIT)	\
    ( (This)->lpVtbl -> GetEIT(This,tableId,pwServiceId,ppEIT) ) 

#define IDvbSiParser_GetBAT(This,pwBouquetId,ppBAT)	\
    ( (This)->lpVtbl -> GetBAT(This,pwBouquetId,ppBAT) ) 

#define IDvbSiParser_GetRST(This,dwTimeout,ppRST)	\
    ( (This)->lpVtbl -> GetRST(This,dwTimeout,ppRST) ) 

#define IDvbSiParser_GetST(This,pid,dwTimeout,ppST)	\
    ( (This)->lpVtbl -> GetST(This,pid,dwTimeout,ppST) ) 

#define IDvbSiParser_GetTDT(This,ppTDT)	\
    ( (This)->lpVtbl -> GetTDT(This,ppTDT) ) 

#define IDvbSiParser_GetTOT(This,ppTOT)	\
    ( (This)->lpVtbl -> GetTOT(This,ppTOT) ) 

#define IDvbSiParser_GetDIT(This,dwTimeout,ppDIT)	\
    ( (This)->lpVtbl -> GetDIT(This,dwTimeout,ppDIT) ) 

#define IDvbSiParser_GetSIT(This,dwTimeout,ppSIT)	\
    ( (This)->lpVtbl -> GetSIT(This,dwTimeout,ppSIT) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbSiParser_INTERFACE_DEFINED__ */


#ifndef __IDVB_NIT_INTERFACE_DEFINED__
#define __IDVB_NIT_INTERFACE_DEFINED__

/* interface IDVB_NIT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDVB_NIT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C64935F4-29E4-4e22-911A-63F7F55CB097")
    IDVB_NIT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNetworkId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordTransportStreamId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordOriginalNetworkId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [in] */ HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [out] */ IDVB_NIT **ppNIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [in] */ HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionHash( 
            /* [out] */ DWORD *pdwVersionHash) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_NITVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_NIT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_NIT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_NIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_NIT * This,
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IDVB_NIT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetNetworkId )( 
            IDVB_NIT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            IDVB_NIT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            IDVB_NIT * This,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_NIT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordTransportStreamId )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordOriginalNetworkId )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IDVB_NIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IDVB_NIT * This,
            /* [in] */ HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IDVB_NIT * This,
            /* [out] */ IDVB_NIT **ppNIT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IDVB_NIT * This,
            /* [in] */ HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IDVB_NIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionHash )( 
            IDVB_NIT * This,
            /* [out] */ DWORD *pdwVersionHash);
        
        END_INTERFACE
    } IDVB_NITVtbl;

    interface IDVB_NIT
    {
        CONST_VTBL struct IDVB_NITVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_NIT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_NIT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_NIT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_NIT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IDVB_NIT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IDVB_NIT_GetNetworkId(This,pwVal)	\
    ( (This)->lpVtbl -> GetNetworkId(This,pwVal) ) 

#define IDVB_NIT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define IDVB_NIT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define IDVB_NIT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_NIT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_NIT_GetRecordTransportStreamId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordTransportStreamId(This,dwRecordIndex,pwVal) ) 

#define IDVB_NIT_GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal) ) 

#define IDVB_NIT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IDVB_NIT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor) ) 

#define IDVB_NIT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_NIT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IDVB_NIT_GetNextTable(This,ppNIT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppNIT) ) 

#define IDVB_NIT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IDVB_NIT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#define IDVB_NIT_GetVersionHash(This,pdwVersionHash)	\
    ( (This)->lpVtbl -> GetVersionHash(This,pdwVersionHash) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_NIT_INTERFACE_DEFINED__ */


#ifndef __IDVB_SDT_INTERFACE_DEFINED__
#define __IDVB_SDT_INTERFACE_DEFINED__

/* interface IDVB_SDT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDVB_SDT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02CAD8D3-FE43-48e2-90BD-450ED9A8A5FD")
    IDVB_SDT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransportStreamId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalNetworkId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordServiceId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordEITScheduleFlag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordEITPresentFollowingFlag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordRunningStatus( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordFreeCAMode( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [in] */ HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [out] */ IDVB_SDT **ppSDT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [in] */ HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionHash( 
            /* [out] */ DWORD *pdwVersionHash) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_SDTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_SDT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_SDT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_SDT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_SDT * This,
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IDVB_SDT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransportStreamId )( 
            IDVB_SDT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOriginalNetworkId )( 
            IDVB_SDT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_SDT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordServiceId )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordEITScheduleFlag )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordEITPresentFollowingFlag )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordRunningStatus )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordFreeCAMode )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IDVB_SDT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IDVB_SDT * This,
            /* [in] */ HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IDVB_SDT * This,
            /* [out] */ IDVB_SDT **ppSDT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IDVB_SDT * This,
            /* [in] */ HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IDVB_SDT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionHash )( 
            IDVB_SDT * This,
            /* [out] */ DWORD *pdwVersionHash);
        
        END_INTERFACE
    } IDVB_SDTVtbl;

    interface IDVB_SDT
    {
        CONST_VTBL struct IDVB_SDTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_SDT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_SDT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_SDT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_SDT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IDVB_SDT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IDVB_SDT_GetTransportStreamId(This,pwVal)	\
    ( (This)->lpVtbl -> GetTransportStreamId(This,pwVal) ) 

#define IDVB_SDT_GetOriginalNetworkId(This,pwVal)	\
    ( (This)->lpVtbl -> GetOriginalNetworkId(This,pwVal) ) 

#define IDVB_SDT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_SDT_GetRecordServiceId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordServiceId(This,dwRecordIndex,pwVal) ) 

#define IDVB_SDT_GetRecordEITScheduleFlag(This,dwRecordIndex,pfVal)	\
    ( (This)->lpVtbl -> GetRecordEITScheduleFlag(This,dwRecordIndex,pfVal) ) 

#define IDVB_SDT_GetRecordEITPresentFollowingFlag(This,dwRecordIndex,pfVal)	\
    ( (This)->lpVtbl -> GetRecordEITPresentFollowingFlag(This,dwRecordIndex,pfVal) ) 

#define IDVB_SDT_GetRecordRunningStatus(This,dwRecordIndex,pbVal)	\
    ( (This)->lpVtbl -> GetRecordRunningStatus(This,dwRecordIndex,pbVal) ) 

#define IDVB_SDT_GetRecordFreeCAMode(This,dwRecordIndex,pfVal)	\
    ( (This)->lpVtbl -> GetRecordFreeCAMode(This,dwRecordIndex,pfVal) ) 

#define IDVB_SDT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IDVB_SDT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor) ) 

#define IDVB_SDT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_SDT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IDVB_SDT_GetNextTable(This,ppSDT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppSDT) ) 

#define IDVB_SDT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IDVB_SDT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#define IDVB_SDT_GetVersionHash(This,pdwVersionHash)	\
    ( (This)->lpVtbl -> GetVersionHash(This,pdwVersionHash) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_SDT_INTERFACE_DEFINED__ */


#ifndef __IDVB_EIT_INTERFACE_DEFINED__
#define __IDVB_EIT_INTERFACE_DEFINED__

/* interface IDVB_EIT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDVB_EIT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("442DB029-02CB-4495-8B92-1C13375BCE99")
    IDVB_EIT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransportStreamId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOriginalNetworkId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSegmentLastSectionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastTableId( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordEventId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordStartTime( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ MPEG_DATE_AND_TIME *pmdtVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDuration( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ MPEG_DURATION *pmdVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordRunningStatus( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordFreeCAMode( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [in] */ HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [out] */ IDVB_EIT **ppEIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [in] */ HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionHash( 
            /* [out] */ DWORD *pdwVersionHash) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_EITVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_EIT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_EIT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_EIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_EIT * This,
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IDVB_EIT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceId )( 
            IDVB_EIT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransportStreamId )( 
            IDVB_EIT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOriginalNetworkId )( 
            IDVB_EIT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetSegmentLastSectionNumber )( 
            IDVB_EIT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastTableId )( 
            IDVB_EIT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_EIT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordEventId )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordStartTime )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ MPEG_DATE_AND_TIME *pmdtVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDuration )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ MPEG_DURATION *pmdVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordRunningStatus )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordFreeCAMode )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BOOL *pfVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IDVB_EIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IDVB_EIT * This,
            /* [in] */ HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IDVB_EIT * This,
            /* [out] */ IDVB_EIT **ppEIT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IDVB_EIT * This,
            /* [in] */ HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IDVB_EIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionHash )( 
            IDVB_EIT * This,
            /* [out] */ DWORD *pdwVersionHash);
        
        END_INTERFACE
    } IDVB_EITVtbl;

    interface IDVB_EIT
    {
        CONST_VTBL struct IDVB_EITVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_EIT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_EIT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_EIT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_EIT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IDVB_EIT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IDVB_EIT_GetServiceId(This,pwVal)	\
    ( (This)->lpVtbl -> GetServiceId(This,pwVal) ) 

#define IDVB_EIT_GetTransportStreamId(This,pwVal)	\
    ( (This)->lpVtbl -> GetTransportStreamId(This,pwVal) ) 

#define IDVB_EIT_GetOriginalNetworkId(This,pwVal)	\
    ( (This)->lpVtbl -> GetOriginalNetworkId(This,pwVal) ) 

#define IDVB_EIT_GetSegmentLastSectionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetSegmentLastSectionNumber(This,pbVal) ) 

#define IDVB_EIT_GetLastTableId(This,pbVal)	\
    ( (This)->lpVtbl -> GetLastTableId(This,pbVal) ) 

#define IDVB_EIT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_EIT_GetRecordEventId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordEventId(This,dwRecordIndex,pwVal) ) 

#define IDVB_EIT_GetRecordStartTime(This,dwRecordIndex,pmdtVal)	\
    ( (This)->lpVtbl -> GetRecordStartTime(This,dwRecordIndex,pmdtVal) ) 

#define IDVB_EIT_GetRecordDuration(This,dwRecordIndex,pmdVal)	\
    ( (This)->lpVtbl -> GetRecordDuration(This,dwRecordIndex,pmdVal) ) 

#define IDVB_EIT_GetRecordRunningStatus(This,dwRecordIndex,pbVal)	\
    ( (This)->lpVtbl -> GetRecordRunningStatus(This,dwRecordIndex,pbVal) ) 

#define IDVB_EIT_GetRecordFreeCAMode(This,dwRecordIndex,pfVal)	\
    ( (This)->lpVtbl -> GetRecordFreeCAMode(This,dwRecordIndex,pfVal) ) 

#define IDVB_EIT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IDVB_EIT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor) ) 

#define IDVB_EIT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_EIT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IDVB_EIT_GetNextTable(This,ppEIT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppEIT) ) 

#define IDVB_EIT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IDVB_EIT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#define IDVB_EIT_GetVersionHash(This,pdwVersionHash)	\
    ( (This)->lpVtbl -> GetVersionHash(This,pdwVersionHash) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_EIT_INTERFACE_DEFINED__ */


#ifndef __IDVB_BAT_INTERFACE_DEFINED__
#define __IDVB_BAT_INTERFACE_DEFINED__

/* interface IDVB_BAT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDVB_BAT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ECE9BB0C-43B6-4558-A0EC-1812C34CD6CA")
    IDVB_BAT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBouquetId( 
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [in] */ DWORD dwIndex,
            /* [in] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordTransportStreamId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordOriginalNetworkId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [in] */ HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [out] */ IDVB_BAT **ppBAT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [in] */ HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_BATVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_BAT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_BAT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_BAT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_BAT * This,
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IDVB_BAT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBouquetId )( 
            IDVB_BAT * This,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            IDVB_BAT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwIndex,
            /* [in] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            IDVB_BAT * This,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_BAT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordTransportStreamId )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordOriginalNetworkId )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IDVB_BAT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IDVB_BAT * This,
            /* [in] */ HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IDVB_BAT * This,
            /* [out] */ IDVB_BAT **ppBAT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IDVB_BAT * This,
            /* [in] */ HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IDVB_BAT * This);
        
        END_INTERFACE
    } IDVB_BATVtbl;

    interface IDVB_BAT
    {
        CONST_VTBL struct IDVB_BATVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_BAT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_BAT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_BAT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_BAT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IDVB_BAT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IDVB_BAT_GetBouquetId(This,pwVal)	\
    ( (This)->lpVtbl -> GetBouquetId(This,pwVal) ) 

#define IDVB_BAT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define IDVB_BAT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define IDVB_BAT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_BAT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_BAT_GetRecordTransportStreamId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordTransportStreamId(This,dwRecordIndex,pwVal) ) 

#define IDVB_BAT_GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal) ) 

#define IDVB_BAT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IDVB_BAT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor) ) 

#define IDVB_BAT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_BAT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IDVB_BAT_GetNextTable(This,ppBAT)	\
    ( (This)->lpVtbl -> GetNextTable(This,ppBAT) ) 

#define IDVB_BAT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IDVB_BAT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_BAT_INTERFACE_DEFINED__ */


#ifndef __IDVB_RST_INTERFACE_DEFINED__
#define __IDVB_RST_INTERFACE_DEFINED__

/* interface IDVB_RST */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDVB_RST;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F47DCD04-1E23-4fb7-9F96-B40EEAD10B2B")
    IDVB_RST : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt ISectionList *pSectionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordTransportStreamId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordOriginalNetworkId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordServiceId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordEventId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordRunningStatus( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_RSTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_RST * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_RST * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_RST * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_RST * This,
            /* [in] */ __RPC__in_opt ISectionList *pSectionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_RST * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordTransportStreamId )( 
            IDVB_RST * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordOriginalNetworkId )( 
            IDVB_RST * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordServiceId )( 
            IDVB_RST * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordEventId )( 
            IDVB_RST * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordRunningStatus )( 
            IDVB_RST * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        END_INTERFACE
    } IDVB_RSTVtbl;

    interface IDVB_RST
    {
        CONST_VTBL struct IDVB_RSTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_RST_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_RST_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_RST_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_RST_Initialize(This,pSectionList)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList) ) 

#define IDVB_RST_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_RST_GetRecordTransportStreamId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordTransportStreamId(This,dwRecordIndex,pwVal) ) 

#define IDVB_RST_GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordOriginalNetworkId(This,dwRecordIndex,pwVal) ) 

#define IDVB_RST_GetRecordServiceId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordServiceId(This,dwRecordIndex,pwVal) ) 

#define IDVB_RST_GetRecordEventId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordEventId(This,dwRecordIndex,pwVal) ) 

#define IDVB_RST_GetRecordRunningStatus(This,dwRecordIndex,pbVal)	\
    ( (This)->lpVtbl -> GetRecordRunningStatus(This,dwRecordIndex,pbVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_RST_INTERFACE_DEFINED__ */


#ifndef __IDVB_ST_INTERFACE_DEFINED__
#define __IDVB_ST_INTERFACE_DEFINED__

/* interface IDVB_ST */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDVB_ST;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4D5B9F23-2A02-45de-BCDA-5D5DBFBFBE62")
    IDVB_ST : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt ISectionList *pSectionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataLength( 
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetData( 
            /* [out] */ __RPC__deref_out_opt BYTE **ppData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_STVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_ST * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_ST * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_ST * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_ST * This,
            /* [in] */ __RPC__in_opt ISectionList *pSectionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataLength )( 
            IDVB_ST * This,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetData )( 
            IDVB_ST * This,
            /* [out] */ __RPC__deref_out_opt BYTE **ppData);
        
        END_INTERFACE
    } IDVB_STVtbl;

    interface IDVB_ST
    {
        CONST_VTBL struct IDVB_STVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_ST_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_ST_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_ST_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_ST_Initialize(This,pSectionList)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList) ) 

#define IDVB_ST_GetDataLength(This,pwVal)	\
    ( (This)->lpVtbl -> GetDataLength(This,pwVal) ) 

#define IDVB_ST_GetData(This,ppData)	\
    ( (This)->lpVtbl -> GetData(This,ppData) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_ST_INTERFACE_DEFINED__ */


#ifndef __IDVB_TDT_INTERFACE_DEFINED__
#define __IDVB_TDT_INTERFACE_DEFINED__

/* interface IDVB_TDT */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDVB_TDT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0780DC7D-D55C-4aef-97E6-6B75906E2796")
    IDVB_TDT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt ISectionList *pSectionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUTCTime( 
            /* [out] */ __RPC__out MPEG_DATE_AND_TIME *pmdtVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_TDTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_TDT * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_TDT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_TDT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_TDT * This,
            /* [in] */ __RPC__in_opt ISectionList *pSectionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetUTCTime )( 
            IDVB_TDT * This,
            /* [out] */ __RPC__out MPEG_DATE_AND_TIME *pmdtVal);
        
        END_INTERFACE
    } IDVB_TDTVtbl;

    interface IDVB_TDT
    {
        CONST_VTBL struct IDVB_TDTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_TDT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_TDT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_TDT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_TDT_Initialize(This,pSectionList)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList) ) 

#define IDVB_TDT_GetUTCTime(This,pmdtVal)	\
    ( (This)->lpVtbl -> GetUTCTime(This,pmdtVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_TDT_INTERFACE_DEFINED__ */


#ifndef __IDVB_TOT_INTERFACE_DEFINED__
#define __IDVB_TOT_INTERFACE_DEFINED__

/* interface IDVB_TOT */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDVB_TOT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83295D6A-FABA-4ee1-9B15-8067696910AE")
    IDVB_TOT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt ISectionList *pSectionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUTCTime( 
            /* [out] */ __RPC__out MPEG_DATE_AND_TIME *pmdtVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [in] */ DWORD dwIndex,
            /* [out] */ __RPC__deref_out_opt IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [in] */ BYTE bTag,
            /* [out][in] */ __RPC__inout DWORD *pdwCookie,
            /* [out] */ __RPC__deref_out_opt IGenericDescriptor **ppDescriptor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_TOTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_TOT * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_TOT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_TOT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_TOT * This,
            /* [in] */ __RPC__in_opt ISectionList *pSectionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetUTCTime )( 
            IDVB_TOT * This,
            /* [out] */ __RPC__out MPEG_DATE_AND_TIME *pmdtVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            IDVB_TOT * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            IDVB_TOT * This,
            /* [in] */ DWORD dwIndex,
            /* [out] */ __RPC__deref_out_opt IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            IDVB_TOT * This,
            /* [in] */ BYTE bTag,
            /* [out][in] */ __RPC__inout DWORD *pdwCookie,
            /* [out] */ __RPC__deref_out_opt IGenericDescriptor **ppDescriptor);
        
        END_INTERFACE
    } IDVB_TOTVtbl;

    interface IDVB_TOT
    {
        CONST_VTBL struct IDVB_TOTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_TOT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_TOT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_TOT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_TOT_Initialize(This,pSectionList)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList) ) 

#define IDVB_TOT_GetUTCTime(This,pmdtVal)	\
    ( (This)->lpVtbl -> GetUTCTime(This,pmdtVal) ) 

#define IDVB_TOT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define IDVB_TOT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define IDVB_TOT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_TOT_INTERFACE_DEFINED__ */


#ifndef __IDVB_DIT_INTERFACE_DEFINED__
#define __IDVB_DIT_INTERFACE_DEFINED__

/* interface IDVB_DIT */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDVB_DIT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91BFFDF9-9432-410f-86EF-1C228ED0AD70")
    IDVB_DIT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ __RPC__in_opt ISectionList *pSectionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransitionFlag( 
            /* [out] */ __RPC__out BOOL *pfVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_DITVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_DIT * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_DIT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_DIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_DIT * This,
            /* [in] */ __RPC__in_opt ISectionList *pSectionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransitionFlag )( 
            IDVB_DIT * This,
            /* [out] */ __RPC__out BOOL *pfVal);
        
        END_INTERFACE
    } IDVB_DITVtbl;

    interface IDVB_DIT
    {
        CONST_VTBL struct IDVB_DITVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_DIT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_DIT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_DIT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_DIT_Initialize(This,pSectionList)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList) ) 

#define IDVB_DIT_GetTransitionFlag(This,pfVal)	\
    ( (This)->lpVtbl -> GetTransitionFlag(This,pfVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_DIT_INTERFACE_DEFINED__ */


#ifndef __IDVB_SIT_INTERFACE_DEFINED__
#define __IDVB_SIT_INTERFACE_DEFINED__

/* interface IDVB_SIT */
/* [unique][uuid][local][object] */ 


EXTERN_C const IID IID_IDVB_SIT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68CDCE53-8BEA-45c2-9D9D-ACF575A089B5")
    IDVB_SIT : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionNumber( 
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfTableDescriptors( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByIndex( 
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTableDescriptorByTag( 
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordServiceId( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordRunningStatus( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCountOfDescriptors( 
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByIndex( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordDescriptorByTag( 
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForNextTable( 
            /* [in] */ HANDLE hNextTableAvailable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextTable( 
            /* [in] */ DWORD dwTimeout,
            /* [out] */ IDVB_SIT **ppSIT) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterForWhenCurrent( 
            /* [in] */ HANDLE hNextTableIsCurrent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertNextToCurrent( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDVB_SITVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDVB_SIT * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDVB_SIT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDVB_SIT * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDVB_SIT * This,
            /* [in] */ ISectionList *pSectionList,
            /* [in] */ IMpeg2Data *pMPEGData);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionNumber )( 
            IDVB_SIT * This,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfTableDescriptors )( 
            IDVB_SIT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByIndex )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetTableDescriptorByTag )( 
            IDVB_SIT * This,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDVB_SIT * This,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordServiceId )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordRunningStatus )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCountOfDescriptors )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [out] */ DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByIndex )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ DWORD dwIndex,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordDescriptorByTag )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwRecordIndex,
            /* [in] */ BYTE bTag,
            /* [in] */ DWORD *pdwCookie,
            /* [out] */ IGenericDescriptor **ppDescriptor);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForNextTable )( 
            IDVB_SIT * This,
            /* [in] */ HANDLE hNextTableAvailable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextTable )( 
            IDVB_SIT * This,
            /* [in] */ DWORD dwTimeout,
            /* [out] */ IDVB_SIT **ppSIT);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterForWhenCurrent )( 
            IDVB_SIT * This,
            /* [in] */ HANDLE hNextTableIsCurrent);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertNextToCurrent )( 
            IDVB_SIT * This);
        
        END_INTERFACE
    } IDVB_SITVtbl;

    interface IDVB_SIT
    {
        CONST_VTBL struct IDVB_SITVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDVB_SIT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDVB_SIT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDVB_SIT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDVB_SIT_Initialize(This,pSectionList,pMPEGData)	\
    ( (This)->lpVtbl -> Initialize(This,pSectionList,pMPEGData) ) 

#define IDVB_SIT_GetVersionNumber(This,pbVal)	\
    ( (This)->lpVtbl -> GetVersionNumber(This,pbVal) ) 

#define IDVB_SIT_GetCountOfTableDescriptors(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfTableDescriptors(This,pdwVal) ) 

#define IDVB_SIT_GetTableDescriptorByIndex(This,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByIndex(This,dwIndex,ppDescriptor) ) 

#define IDVB_SIT_GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetTableDescriptorByTag(This,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_SIT_GetCountOfRecords(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pdwVal) ) 

#define IDVB_SIT_GetRecordServiceId(This,dwRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordServiceId(This,dwRecordIndex,pwVal) ) 

#define IDVB_SIT_GetRecordRunningStatus(This,dwRecordIndex,pbVal)	\
    ( (This)->lpVtbl -> GetRecordRunningStatus(This,dwRecordIndex,pbVal) ) 

#define IDVB_SIT_GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCountOfDescriptors(This,dwRecordIndex,pdwVal) ) 

#define IDVB_SIT_GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByIndex(This,dwRecordIndex,dwIndex,ppDescriptor) ) 

#define IDVB_SIT_GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor)	\
    ( (This)->lpVtbl -> GetRecordDescriptorByTag(This,dwRecordIndex,bTag,pdwCookie,ppDescriptor) ) 

#define IDVB_SIT_RegisterForNextTable(This,hNextTableAvailable)	\
    ( (This)->lpVtbl -> RegisterForNextTable(This,hNextTableAvailable) ) 

#define IDVB_SIT_GetNextTable(This,dwTimeout,ppSIT)	\
    ( (This)->lpVtbl -> GetNextTable(This,dwTimeout,ppSIT) ) 

#define IDVB_SIT_RegisterForWhenCurrent(This,hNextTableIsCurrent)	\
    ( (This)->lpVtbl -> RegisterForWhenCurrent(This,hNextTableIsCurrent) ) 

#define IDVB_SIT_ConvertNextToCurrent(This)	\
    ( (This)->lpVtbl -> ConvertNextToCurrent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDVB_SIT_INTERFACE_DEFINED__ */


#ifndef __IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED__
#define __IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED__

/* interface IDvbSatelliteDeliverySystemDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbSatelliteDeliverySystemDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02F2225A-805B-4ec5-A9A6-F9B5913CD470")
    IDvbSatelliteDeliverySystemDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrequency( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOrbitalPosition( 
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWestEastFlag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolarization( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModulation( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolRate( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFECInner( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbSatelliteDeliverySystemDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbSatelliteDeliverySystemDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbSatelliteDeliverySystemDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrequency )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOrbitalPosition )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetWestEastFlag )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolarization )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetModulation )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetSymbolRate )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFECInner )( 
            IDvbSatelliteDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        END_INTERFACE
    } IDvbSatelliteDeliverySystemDescriptorVtbl;

    interface IDvbSatelliteDeliverySystemDescriptor
    {
        CONST_VTBL struct IDvbSatelliteDeliverySystemDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbSatelliteDeliverySystemDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbSatelliteDeliverySystemDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbSatelliteDeliverySystemDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbSatelliteDeliverySystemDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetFrequency(This,pdwVal)	\
    ( (This)->lpVtbl -> GetFrequency(This,pdwVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetOrbitalPosition(This,pwVal)	\
    ( (This)->lpVtbl -> GetOrbitalPosition(This,pwVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetWestEastFlag(This,pbVal)	\
    ( (This)->lpVtbl -> GetWestEastFlag(This,pbVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetPolarization(This,pbVal)	\
    ( (This)->lpVtbl -> GetPolarization(This,pbVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetModulation(This,pbVal)	\
    ( (This)->lpVtbl -> GetModulation(This,pbVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetSymbolRate(This,pdwVal)	\
    ( (This)->lpVtbl -> GetSymbolRate(This,pdwVal) ) 

#define IDvbSatelliteDeliverySystemDescriptor_GetFECInner(This,pbVal)	\
    ( (This)->lpVtbl -> GetFECInner(This,pbVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbSatelliteDeliverySystemDescriptor_INTERFACE_DEFINED__ */


#ifndef __IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED__
#define __IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED__

/* interface IDvbCableDeliverySystemDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbCableDeliverySystemDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFB98E36-9E1A-4862-9946-993A4E59017B")
    IDvbCableDeliverySystemDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrequency( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFECOuter( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModulation( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolRate( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFECInner( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbCableDeliverySystemDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbCableDeliverySystemDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbCableDeliverySystemDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFrequency )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFECOuter )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetModulation )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetSymbolRate )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetFECInner )( 
            IDvbCableDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        END_INTERFACE
    } IDvbCableDeliverySystemDescriptorVtbl;

    interface IDvbCableDeliverySystemDescriptor
    {
        CONST_VTBL struct IDvbCableDeliverySystemDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbCableDeliverySystemDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbCableDeliverySystemDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbCableDeliverySystemDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbCableDeliverySystemDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetFrequency(This,pdwVal)	\
    ( (This)->lpVtbl -> GetFrequency(This,pdwVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetFECOuter(This,pbVal)	\
    ( (This)->lpVtbl -> GetFECOuter(This,pbVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetModulation(This,pbVal)	\
    ( (This)->lpVtbl -> GetModulation(This,pbVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetSymbolRate(This,pdwVal)	\
    ( (This)->lpVtbl -> GetSymbolRate(This,pdwVal) ) 

#define IDvbCableDeliverySystemDescriptor_GetFECInner(This,pbVal)	\
    ( (This)->lpVtbl -> GetFECInner(This,pbVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbCableDeliverySystemDescriptor_INTERFACE_DEFINED__ */


#ifndef __IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED__
#define __IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED__

/* interface IDvbTerrestrialDeliverySystemDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbTerrestrialDeliverySystemDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED7E1B91-D12E-420c-B41D-A49D84FE1823")
    IDvbTerrestrialDeliverySystemDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCentreFrequency( 
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBandwidth( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConstellation( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHierarchyInformation( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodeRateHPStream( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodeRateLPStream( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuardInterval( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransmissionMode( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOtherFrequencyFlag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbTerrestrialDeliverySystemDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbTerrestrialDeliverySystemDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbTerrestrialDeliverySystemDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCentreFrequency )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetBandwidth )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetConstellation )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetHierarchyInformation )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodeRateHPStream )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodeRateLPStream )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuardInterval )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransmissionMode )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetOtherFrequencyFlag )( 
            IDvbTerrestrialDeliverySystemDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        END_INTERFACE
    } IDvbTerrestrialDeliverySystemDescriptorVtbl;

    interface IDvbTerrestrialDeliverySystemDescriptor
    {
        CONST_VTBL struct IDvbTerrestrialDeliverySystemDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbTerrestrialDeliverySystemDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbTerrestrialDeliverySystemDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetCentreFrequency(This,pdwVal)	\
    ( (This)->lpVtbl -> GetCentreFrequency(This,pdwVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetBandwidth(This,pbVal)	\
    ( (This)->lpVtbl -> GetBandwidth(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetConstellation(This,pbVal)	\
    ( (This)->lpVtbl -> GetConstellation(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetHierarchyInformation(This,pbVal)	\
    ( (This)->lpVtbl -> GetHierarchyInformation(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetCodeRateHPStream(This,pbVal)	\
    ( (This)->lpVtbl -> GetCodeRateHPStream(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetCodeRateLPStream(This,pbVal)	\
    ( (This)->lpVtbl -> GetCodeRateLPStream(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetGuardInterval(This,pbVal)	\
    ( (This)->lpVtbl -> GetGuardInterval(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetTransmissionMode(This,pbVal)	\
    ( (This)->lpVtbl -> GetTransmissionMode(This,pbVal) ) 

#define IDvbTerrestrialDeliverySystemDescriptor_GetOtherFrequencyFlag(This,pbVal)	\
    ( (This)->lpVtbl -> GetOtherFrequencyFlag(This,pbVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbTerrestrialDeliverySystemDescriptor_INTERFACE_DEFINED__ */


#ifndef __IDvbFrequencyListDescriptor_INTERFACE_DEFINED__
#define __IDvbFrequencyListDescriptor_INTERFACE_DEFINED__

/* interface IDvbFrequencyListDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbFrequencyListDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1CADB613-E1DD-4512-AFA8-BB7A007EF8B1")
    IDvbFrequencyListDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCodingType( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordCentreFrequency( 
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out DWORD *pdwVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbFrequencyListDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbFrequencyListDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbFrequencyListDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbFrequencyListDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbFrequencyListDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbFrequencyListDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodingType )( 
            IDvbFrequencyListDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDvbFrequencyListDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordCentreFrequency )( 
            IDvbFrequencyListDescriptor * This,
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out DWORD *pdwVal);
        
        END_INTERFACE
    } IDvbFrequencyListDescriptorVtbl;

    interface IDvbFrequencyListDescriptor
    {
        CONST_VTBL struct IDvbFrequencyListDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbFrequencyListDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbFrequencyListDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbFrequencyListDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbFrequencyListDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbFrequencyListDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbFrequencyListDescriptor_GetCodingType(This,pbVal)	\
    ( (This)->lpVtbl -> GetCodingType(This,pbVal) ) 

#define IDvbFrequencyListDescriptor_GetCountOfRecords(This,pbVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pbVal) ) 

#define IDvbFrequencyListDescriptor_GetRecordCentreFrequency(This,bRecordIndex,pdwVal)	\
    ( (This)->lpVtbl -> GetRecordCentreFrequency(This,bRecordIndex,pdwVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbFrequencyListDescriptor_INTERFACE_DEFINED__ */


#ifndef __IDvbLogicalChannelDescriptor_INTERFACE_DEFINED__
#define __IDvbLogicalChannelDescriptor_INTERFACE_DEFINED__

/* interface IDvbLogicalChannelDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbLogicalChannelDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF1EDAFF-3FFD-4cf7-8201-35756ACBF85F")
    IDvbLogicalChannelDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCountOfRecords( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordServiceId( 
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecordLogicalChannelNumber( 
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbLogicalChannelDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbLogicalChannelDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbLogicalChannelDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbLogicalChannelDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbLogicalChannelDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbLogicalChannelDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetCountOfRecords )( 
            IDvbLogicalChannelDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordServiceId )( 
            IDvbLogicalChannelDescriptor * This,
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecordLogicalChannelNumber )( 
            IDvbLogicalChannelDescriptor * This,
            /* [in] */ BYTE bRecordIndex,
            /* [out] */ __RPC__out WORD *pwVal);
        
        END_INTERFACE
    } IDvbLogicalChannelDescriptorVtbl;

    interface IDvbLogicalChannelDescriptor
    {
        CONST_VTBL struct IDvbLogicalChannelDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbLogicalChannelDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbLogicalChannelDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbLogicalChannelDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbLogicalChannelDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbLogicalChannelDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbLogicalChannelDescriptor_GetCountOfRecords(This,pbVal)	\
    ( (This)->lpVtbl -> GetCountOfRecords(This,pbVal) ) 

#define IDvbLogicalChannelDescriptor_GetRecordServiceId(This,bRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordServiceId(This,bRecordIndex,pwVal) ) 

#define IDvbLogicalChannelDescriptor_GetRecordLogicalChannelNumber(This,bRecordIndex,pwVal)	\
    ( (This)->lpVtbl -> GetRecordLogicalChannelNumber(This,bRecordIndex,pwVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbLogicalChannelDescriptor_INTERFACE_DEFINED__ */


#ifndef __IDvbServiceDescriptor_INTERFACE_DEFINED__
#define __IDvbServiceDescriptor_INTERFACE_DEFINED__

/* interface IDvbServiceDescriptor */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDvbServiceDescriptor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F9C7FBCF-E2D6-464d-B32D-2EF526E49290")
    IDvbServiceDescriptor : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTag( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLength( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceType( 
            /* [out] */ __RPC__out BYTE *pbVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceProviderName( 
            /* [out] */ __RPC__deref_out_opt char **pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceProviderNameW( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceName( 
            /* [out] */ __RPC__deref_out_opt char **pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProcessedServiceName( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceNameEmphasized( 
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDvbServiceDescriptorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDvbServiceDescriptor * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDvbServiceDescriptor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDvbServiceDescriptor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTag )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceType )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__out BYTE *pbVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceProviderName )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__deref_out_opt char **pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceProviderNameW )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceName )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__deref_out_opt char **pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetProcessedServiceName )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceNameEmphasized )( 
            IDvbServiceDescriptor * This,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrName);
        
        END_INTERFACE
    } IDvbServiceDescriptorVtbl;

    interface IDvbServiceDescriptor
    {
        CONST_VTBL struct IDvbServiceDescriptorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDvbServiceDescriptor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDvbServiceDescriptor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDvbServiceDescriptor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDvbServiceDescriptor_GetTag(This,pbVal)	\
    ( (This)->lpVtbl -> GetTag(This,pbVal) ) 

#define IDvbServiceDescriptor_GetLength(This,pbVal)	\
    ( (This)->lpVtbl -> GetLength(This,pbVal) ) 

#define IDvbServiceDescriptor_GetServiceType(This,pbVal)	\
    ( (This)->lpVtbl -> GetServiceType(This,pbVal) ) 

#define IDvbServiceDescriptor_GetServiceProviderName(This,pszName)	\
    ( (This)->lpVtbl -> GetServiceProviderName(This,pszName) ) 

#define IDvbServiceDescriptor_GetServiceProviderNameW(This,pbstrName)	\
    ( (This)->lpVtbl -> GetServiceProviderNameW(This,pbstrName) ) 

#define IDvbServiceDescriptor_GetServiceName(This,pszName)	\
    ( (This)->lpVtbl -> GetServiceName(This,pszName) ) 

#define IDvbServiceDescriptor_GetProcessedServiceName(This,pbstrName)	\
    ( (This)->lpVtbl -> GetProcessedServiceName(This,pbstrName) ) 

#define IDvbServiceDescriptor_GetServiceNameEmphasized(This,pbstrName)	\
    ( (This)->lpVtbl -> GetServiceNameEmphasized(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDvbServiceDescriptor_INTERFACE_DEFINED__ */


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



