//-------------------------------------------------------------------------- 
// 
//  Copyright (c) Microsoft Corporation.  All rights reserved. 
// 
//  File: rtscom_i.c 
//      Microsoft Tablet PC API definitions 
// 
//-------------------------------------------------------------------------- 
	
 	
 	


/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for rtscom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_TPCRTSLib,0xA76A6D34,0xA06D,0x43e1,0x8C,0x05,0x0C,0x56,0xD3,0x6F,0x46,0x2E);


MIDL_DEFINE_GUID(IID, IID_IRealTimeStylus,0xA8BB5D22,0x3144,0x4a7b,0x93,0xCD,0xF3,0x4A,0x16,0xBE,0x51,0x3A);


MIDL_DEFINE_GUID(IID, IID_IRealTimeStylus2,0xB5F2A6CD,0x3179,0x4a3e,0xB9,0xC4,0xBB,0x58,0x65,0x96,0x2B,0xE2);


MIDL_DEFINE_GUID(IID, IID_IRealTimeStylusSynchronization,0xAA87EAB8,0xAB4A,0x4cea,0xB5,0xCB,0x46,0xD8,0x4C,0x6A,0x25,0x09);


MIDL_DEFINE_GUID(IID, IID_IStrokeBuilder,0xA5FD4E2D,0xC44B,0x4092,0x91,0x77,0x26,0x09,0x05,0xEB,0x67,0x2B);


MIDL_DEFINE_GUID(IID, IID_IStylusPlugin,0xA81436D8,0x4757,0x4fd1,0xA1,0x85,0x13,0x3F,0x97,0xC6,0xC5,0x45);


MIDL_DEFINE_GUID(IID, IID_IStylusSyncPlugin,0xA157B174,0x482F,0x4d71,0xA3,0xF6,0x3A,0x41,0xDD,0xD1,0x1B,0xE9);


MIDL_DEFINE_GUID(IID, IID_IStylusAsyncPlugin,0xA7CCA85A,0x31BC,0x4cd2,0xAA,0xDC,0x32,0x89,0xA3,0xAF,0x11,0xC8);


MIDL_DEFINE_GUID(IID, IID_IDynamicRenderer,0xA079468E,0x7165,0x46f9,0xB7,0xAF,0x98,0xAD,0x01,0xA9,0x30,0x09);


MIDL_DEFINE_GUID(IID, IID_IGestureRecognizer,0xAE9EF86B,0x7054,0x45e3,0xAE,0x22,0x31,0x74,0xDC,0x88,0x11,0xB7);


MIDL_DEFINE_GUID(CLSID, CLSID_RealTimeStylus,0xE26B366D,0xF998,0x43ce,0x83,0x6F,0xCB,0x6D,0x90,0x44,0x32,0xB0);


MIDL_DEFINE_GUID(CLSID, CLSID_DynamicRenderer,0xECD32AEA,0x746F,0x4dcb,0xBF,0x68,0x08,0x27,0x57,0xFA,0xFF,0x18);


MIDL_DEFINE_GUID(CLSID, CLSID_GestureRecognizer,0xEA30C654,0xC62C,0x441f,0xAC,0x00,0x95,0xF9,0xA1,0x96,0x78,0x2C);


MIDL_DEFINE_GUID(CLSID, CLSID_StrokeBuilder,0xE810CEE7,0x6E51,0x4cb0,0xAA,0x3A,0x0B,0x98,0x5B,0x70,0xDA,0xF7);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




