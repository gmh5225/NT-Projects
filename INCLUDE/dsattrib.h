

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for dsattrib.idl:
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

#ifndef __dsattrib_h__
#define __dsattrib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAttributeSet_FWD_DEFINED__
#define __IAttributeSet_FWD_DEFINED__
typedef interface IAttributeSet IAttributeSet;
#endif 	/* __IAttributeSet_FWD_DEFINED__ */


#ifndef __IAttributeGet_FWD_DEFINED__
#define __IAttributeGet_FWD_DEFINED__
typedef interface IAttributeGet IAttributeGet;
#endif 	/* __IAttributeGet_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "objidl.h"
#include "strmif.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_dsattrib_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_dsattrib_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dsattrib_0000_0000_v0_0_s_ifspec;

#ifndef __IAttributeSet_INTERFACE_DEFINED__
#define __IAttributeSet_INTERFACE_DEFINED__

/* interface IAttributeSet */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAttributeSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("583ec3cc-4960-4857-982b-41a33ea0a006")
    IAttributeSet : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetAttrib( 
            /* [in] */ GUID guidAttribute,
            /* [in] */ __RPC__in BYTE *pbAttribute,
            /* [in] */ DWORD dwAttributeLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttributeSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttributeSet * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttributeSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttributeSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttrib )( 
            IAttributeSet * This,
            /* [in] */ GUID guidAttribute,
            /* [in] */ __RPC__in BYTE *pbAttribute,
            /* [in] */ DWORD dwAttributeLength);
        
        END_INTERFACE
    } IAttributeSetVtbl;

    interface IAttributeSet
    {
        CONST_VTBL struct IAttributeSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttributeSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttributeSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttributeSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttributeSet_SetAttrib(This,guidAttribute,pbAttribute,dwAttributeLength)	\
    ( (This)->lpVtbl -> SetAttrib(This,guidAttribute,pbAttribute,dwAttributeLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttributeSet_INTERFACE_DEFINED__ */


#ifndef __IAttributeGet_INTERFACE_DEFINED__
#define __IAttributeGet_INTERFACE_DEFINED__

/* interface IAttributeGet */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IAttributeGet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52dbd1ec-e48f-4528-9232-f442a68f0ae1")
    IAttributeGet : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ __RPC__out LONG *plCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttribIndexed( 
            /* [in] */ LONG lIndex,
            /* [out] */ __RPC__out GUID *pguidAttribute,
            /* [out][in] */ __RPC__inout BYTE *pbAttribute,
            /* [out][in] */ __RPC__inout DWORD *pdwAttributeLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttrib( 
            /* [in] */ GUID guidAttribute,
            /* [out][in] */ __RPC__inout BYTE *pbAttribute,
            /* [out][in] */ __RPC__inout DWORD *pdwAttributeLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAttributeGetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAttributeGet * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAttributeGet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAttributeGet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IAttributeGet * This,
            /* [out] */ __RPC__out LONG *plCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttribIndexed )( 
            IAttributeGet * This,
            /* [in] */ LONG lIndex,
            /* [out] */ __RPC__out GUID *pguidAttribute,
            /* [out][in] */ __RPC__inout BYTE *pbAttribute,
            /* [out][in] */ __RPC__inout DWORD *pdwAttributeLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttrib )( 
            IAttributeGet * This,
            /* [in] */ GUID guidAttribute,
            /* [out][in] */ __RPC__inout BYTE *pbAttribute,
            /* [out][in] */ __RPC__inout DWORD *pdwAttributeLength);
        
        END_INTERFACE
    } IAttributeGetVtbl;

    interface IAttributeGet
    {
        CONST_VTBL struct IAttributeGetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAttributeGet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAttributeGet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAttributeGet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAttributeGet_GetCount(This,plCount)	\
    ( (This)->lpVtbl -> GetCount(This,plCount) ) 

#define IAttributeGet_GetAttribIndexed(This,lIndex,pguidAttribute,pbAttribute,pdwAttributeLength)	\
    ( (This)->lpVtbl -> GetAttribIndexed(This,lIndex,pguidAttribute,pbAttribute,pdwAttributeLength) ) 

#define IAttributeGet_GetAttrib(This,guidAttribute,pbAttribute,pdwAttributeLength)	\
    ( (This)->lpVtbl -> GetAttrib(This,guidAttribute,pbAttribute,pdwAttributeLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAttributeGet_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_dsattrib_0000_0002 */
/* [local] */ 

// ------------------------------------------------------
// GUID: DSATTRIB_UDCRTag
// ------------------------------------------------------
typedef struct _UDCR_TAG {
    BYTE        bVersion ;
    BYTE        KID [24 + 1] ;
    ULONGLONG   ullBaseCounter ;
    ULONGLONG   ullBaseCounterRange ;
    BOOL        fScrambled ;
    BYTE        bStreamMark ;
    DWORD       dwReserved1 ;
    DWORD       dwReserved2 ;
} UDCR_TAG ;
// ------------------------------------------------------
// GUID: DSATTRIB_PicSampleSeq
// ------------------------------------------------------
#define SAMPLE_SEQ_SEQUENCE_HEADER      1
#define SAMPLE_SEQ_GOP_HEADER           2
#define SAMPLE_SEQ_PICTURE_HEADER       3
#define SAMPLE_SEQ_CONTENT_UNKNOWN      0
#define SAMPLE_SEQ_CONTENT_I_FRAME      1
#define SAMPLE_SEQ_CONTENT_P_FRAME      2
#define SAMPLE_SEQ_CONTENT_B_FRAME      3
typedef struct _PIC_SEQ_SAMPLE {
    DWORD
      Content   : 3,    //  SAMPLE_CONTENT_*
      Start     : 1,    //  '1' if the sample is a PictureSampleSequence start
      FrameRate : 4,    //  see below (h.262, table 6-4)
      Reserved  : 20,   //  reserved; shall have value 0
      Version   : 4 ;   //  0
} PIC_SEQ_SAMPLE, *PPIC_SEQ_SAMPLE ;
//      Frame Rate
//          (see h.262, table 6-4)
//
//          0000    reserved (ignore field value)
//          0001    23.976
//          0010    24
//          0011    25
//          0100    29.97
//          0101    30
//          0110    50
//          0111    59.94
//          1000    60
typedef struct _SAMPLE_SEQ_OFFSET {
    DWORD
      Type      : 4,       //  SAMPLE_SEQ_*; 0 means not used
      Offset    : 20,      //  downstream byte offset; 0xfffff means > 2^20-1
      Reserved  : 8 ;      //  reserved; o
} SAMPLE_SEQ_OFFSET ;
#define OFFSET_MARKER_COUNT(attr_len)   \
    ((attr_len - sizeof (PIC_SEQ_SAMPLE)) / sizeof (SAMPLE_SEQ_OFFSET))
#define PIC_SEQ_SAMPLE_ATTR_LEN(cOffsets)   (sizeof (PIC_SEQ_SAMPLE) + (cOffsets) * sizeof (SAMPLE_SEQ_OFFSET))


extern RPC_IF_HANDLE __MIDL_itf_dsattrib_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_dsattrib_0000_0002_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



