

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for qedit.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


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

MIDL_DEFINE_GUID(IID, IID_IPropertySetter,0xAE9472BD,0xB0C3,0x11D2,0x8D,0x24,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IDxtCompositor,0xBB44391E,0x6ABD,0x422f,0x9E,0x2E,0x38,0x5C,0x9D,0xFF,0x51,0xFC);


MIDL_DEFINE_GUID(IID, IID_IDxtAlphaSetter,0x4EE9EAD9,0xDA4D,0x43d0,0x93,0x83,0x06,0xB9,0x0C,0x08,0xB1,0x2B);


MIDL_DEFINE_GUID(IID, IID_IDxtJpeg,0xDE75D011,0x7A65,0x11D2,0x8C,0xEA,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IDxtKey,0x3255de56,0x38fb,0x4901,0xb9,0x80,0x94,0xb4,0x38,0x01,0x0d,0x7b);


MIDL_DEFINE_GUID(IID, IID_IMediaLocator,0x288581E0,0x66CE,0x11d2,0x91,0x8F,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IMediaDet,0x65BD0710,0x24D2,0x4ff7,0x93,0x24,0xED,0x2E,0x5D,0x3A,0xBA,0xFA);


MIDL_DEFINE_GUID(IID, IID_IGrfCache,0xAE9472BE,0xB0C3,0x11D2,0x8D,0x24,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IRenderEngine,0x6BEE3A81,0x66C9,0x11d2,0x91,0x8F,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IFindCompressorCB,0xF03FA8DE,0x879A,0x4d59,0x9B,0x2C,0x26,0xBB,0x1C,0xF8,0x34,0x61);


MIDL_DEFINE_GUID(IID, IID_ISmartRenderEngine,0xF03FA8CE,0x879A,0x4d59,0x9B,0x2C,0x26,0xBB,0x1C,0xF8,0x34,0x61);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineObj,0x78530B77,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineEffectable,0xEAE58537,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineEffect,0xBCE0C264,0x622D,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTransable,0x378FA386,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineSplittable,0xA0F840A0,0xD590,0x11d2,0x8D,0x55,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTrans,0xBCE0C265,0x622D,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineSrc,0x78530B79,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTrack,0xEAE58538,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineVirtualTrack,0xA8ED5F80,0xC2C7,0x11d2,0x8D,0x39,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineComp,0xEAE58536,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineGroup,0x9EED4F00,0xB8A6,0x11d2,0x80,0x23,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IAMTimeline,0x78530B74,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IXml2Dex,0x18C628ED,0x962A,0x11D2,0x8D,0x08,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMErrorLog,0xE43E73A2,0x0EFA,0x11d3,0x96,0x01,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMSetErrorLog,0x963566DA,0xBE21,0x4eaf,0x88,0xE9,0x35,0x70,0x4F,0x8F,0x52,0xA1);


MIDL_DEFINE_GUID(IID, IID_ISampleGrabberCB,0x0579154A,0x2B53,0x4994,0xB0,0xD0,0xE7,0x73,0x14,0x8E,0xFF,0x85);


MIDL_DEFINE_GUID(IID, IID_ISampleGrabber,0x6B652FFF,0x11FE,0x4fce,0x92,0xAD,0x02,0x66,0xB5,0xD7,0xC7,0x8F);


MIDL_DEFINE_GUID(IID, LIBID_DexterLib,0x78530B68,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimeline,0x78530B75,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineObj,0x78530B78,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineSrc,0x78530B7A,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineTrack,0x8F6C3C50,0x897B,0x11d2,0x8C,0xFB,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineComp,0x74D2EC80,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineGroup,0xF6D371E1,0xB8A6,0x11d2,0x80,0x23,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineTrans,0x74D2EC81,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineEffect,0x74D2EC82,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_RenderEngine,0x64D8A8E0,0x80A2,0x11d2,0x8C,0xF3,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_SmartRenderEngine,0x498B0949,0xBBE9,0x4072,0x98,0xBE,0x6C,0xCA,0xEB,0x79,0xDC,0x6F);


MIDL_DEFINE_GUID(CLSID, CLSID_AudMixer,0x036A9790,0xC153,0x11d2,0x9E,0xF7,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_Xml2Dex,0x18C628EE,0x962A,0x11D2,0x8D,0x08,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_MediaLocator,0xCC1101F2,0x79DC,0x11D2,0x8C,0xE6,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_PropertySetter,0xADF95821,0xDED7,0x11d2,0xAC,0xBE,0x00,0x80,0xC7,0x5E,0x24,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_MediaDet,0x65BD0711,0x24D2,0x4ff7,0x93,0x24,0xED,0x2E,0x5D,0x3A,0xBA,0xFA);


MIDL_DEFINE_GUID(CLSID, CLSID_SampleGrabber,0xC1F400A0,0x3F08,0x11d3,0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_NullRenderer,0xC1F400A4,0x3F08,0x11d3,0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtCompositor,0xBB44391D,0x6ABD,0x422f,0x9E,0x2E,0x38,0x5C,0x9D,0xFF,0x51,0xFC);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtAlphaSetter,0x506D89AE,0x909A,0x44f7,0x94,0x44,0xAB,0xD5,0x75,0x89,0x6E,0x35);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtJpeg,0xDE75D012,0x7A65,0x11D2,0x8C,0xEA,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_ColorSource,0x0cfdd070,0x581a,0x11d2,0x9e,0xe6,0x00,0x60,0x08,0x03,0x9e,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtKey,0xC5B19592,0x145E,0x11d3,0x9F,0x04,0x00,0x60,0x08,0x03,0x9E,0x37);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for qedit.idl:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AMD64)


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

MIDL_DEFINE_GUID(IID, IID_IPropertySetter,0xAE9472BD,0xB0C3,0x11D2,0x8D,0x24,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IDxtCompositor,0xBB44391E,0x6ABD,0x422f,0x9E,0x2E,0x38,0x5C,0x9D,0xFF,0x51,0xFC);


MIDL_DEFINE_GUID(IID, IID_IDxtAlphaSetter,0x4EE9EAD9,0xDA4D,0x43d0,0x93,0x83,0x06,0xB9,0x0C,0x08,0xB1,0x2B);


MIDL_DEFINE_GUID(IID, IID_IDxtJpeg,0xDE75D011,0x7A65,0x11D2,0x8C,0xEA,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IDxtKey,0x3255de56,0x38fb,0x4901,0xb9,0x80,0x94,0xb4,0x38,0x01,0x0d,0x7b);


MIDL_DEFINE_GUID(IID, IID_IMediaLocator,0x288581E0,0x66CE,0x11d2,0x91,0x8F,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IMediaDet,0x65BD0710,0x24D2,0x4ff7,0x93,0x24,0xED,0x2E,0x5D,0x3A,0xBA,0xFA);


MIDL_DEFINE_GUID(IID, IID_IGrfCache,0xAE9472BE,0xB0C3,0x11D2,0x8D,0x24,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IRenderEngine,0x6BEE3A81,0x66C9,0x11d2,0x91,0x8F,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IFindCompressorCB,0xF03FA8DE,0x879A,0x4d59,0x9B,0x2C,0x26,0xBB,0x1C,0xF8,0x34,0x61);


MIDL_DEFINE_GUID(IID, IID_ISmartRenderEngine,0xF03FA8CE,0x879A,0x4d59,0x9B,0x2C,0x26,0xBB,0x1C,0xF8,0x34,0x61);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineObj,0x78530B77,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineEffectable,0xEAE58537,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineEffect,0xBCE0C264,0x622D,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTransable,0x378FA386,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineSplittable,0xA0F840A0,0xD590,0x11d2,0x8D,0x55,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTrans,0xBCE0C265,0x622D,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineSrc,0x78530B79,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineTrack,0xEAE58538,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineVirtualTrack,0xA8ED5F80,0xC2C7,0x11d2,0x8D,0x39,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineComp,0xEAE58536,0x622E,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IAMTimelineGroup,0x9EED4F00,0xB8A6,0x11d2,0x80,0x23,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(IID, IID_IAMTimeline,0x78530B74,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(IID, IID_IXml2Dex,0x18C628ED,0x962A,0x11D2,0x8D,0x08,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMErrorLog,0xE43E73A2,0x0EFA,0x11d3,0x96,0x01,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(IID, IID_IAMSetErrorLog,0x963566DA,0xBE21,0x4eaf,0x88,0xE9,0x35,0x70,0x4F,0x8F,0x52,0xA1);


MIDL_DEFINE_GUID(IID, IID_ISampleGrabberCB,0x0579154A,0x2B53,0x4994,0xB0,0xD0,0xE7,0x73,0x14,0x8E,0xFF,0x85);


MIDL_DEFINE_GUID(IID, IID_ISampleGrabber,0x6B652FFF,0x11FE,0x4fce,0x92,0xAD,0x02,0x66,0xB5,0xD7,0xC7,0x8F);


MIDL_DEFINE_GUID(IID, LIBID_DexterLib,0x78530B68,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimeline,0x78530B75,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineObj,0x78530B78,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineSrc,0x78530B7A,0x61F9,0x11D2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineTrack,0x8F6C3C50,0x897B,0x11d2,0x8C,0xFB,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineComp,0x74D2EC80,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineGroup,0xF6D371E1,0xB8A6,0x11d2,0x80,0x23,0x00,0xC0,0xDF,0x10,0xD4,0x34);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineTrans,0x74D2EC81,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_AMTimelineEffect,0x74D2EC82,0x6233,0x11d2,0x8C,0xAD,0x00,0xA0,0x24,0x58,0x09,0x02);


MIDL_DEFINE_GUID(CLSID, CLSID_RenderEngine,0x64D8A8E0,0x80A2,0x11d2,0x8C,0xF3,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_SmartRenderEngine,0x498B0949,0xBBE9,0x4072,0x98,0xBE,0x6C,0xCA,0xEB,0x79,0xDC,0x6F);


MIDL_DEFINE_GUID(CLSID, CLSID_AudMixer,0x036A9790,0xC153,0x11d2,0x9E,0xF7,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_Xml2Dex,0x18C628EE,0x962A,0x11D2,0x8D,0x08,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_MediaLocator,0xCC1101F2,0x79DC,0x11D2,0x8C,0xE6,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_PropertySetter,0xADF95821,0xDED7,0x11d2,0xAC,0xBE,0x00,0x80,0xC7,0x5E,0x24,0x6E);


MIDL_DEFINE_GUID(CLSID, CLSID_MediaDet,0x65BD0711,0x24D2,0x4ff7,0x93,0x24,0xED,0x2E,0x5D,0x3A,0xBA,0xFA);


MIDL_DEFINE_GUID(CLSID, CLSID_SampleGrabber,0xC1F400A0,0x3F08,0x11d3,0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_NullRenderer,0xC1F400A4,0x3F08,0x11d3,0x9F,0x0B,0x00,0x60,0x08,0x03,0x9E,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtCompositor,0xBB44391D,0x6ABD,0x422f,0x9E,0x2E,0x38,0x5C,0x9D,0xFF,0x51,0xFC);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtAlphaSetter,0x506D89AE,0x909A,0x44f7,0x94,0x44,0xAB,0xD5,0x75,0x89,0x6E,0x35);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtJpeg,0xDE75D012,0x7A65,0x11D2,0x8C,0xEA,0x00,0xA0,0xC9,0x44,0x1E,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_ColorSource,0x0cfdd070,0x581a,0x11d2,0x9e,0xe6,0x00,0x60,0x08,0x03,0x9e,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_DxtKey,0xC5B19592,0x145E,0x11d3,0x9F,0x04,0x00,0x60,0x08,0x03,0x9E,0x37);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* defined(_M_IA64) || defined(_M_AMD64)*/
