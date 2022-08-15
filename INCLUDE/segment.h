

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for segment.idl:
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

#ifndef __segment_h__
#define __segment_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMSVidRect_FWD_DEFINED__
#define __IMSVidRect_FWD_DEFINED__
typedef interface IMSVidRect IMSVidRect;
#endif 	/* __IMSVidRect_FWD_DEFINED__ */


#ifndef __IMSVidGraphSegmentContainer_FWD_DEFINED__
#define __IMSVidGraphSegmentContainer_FWD_DEFINED__
typedef interface IMSVidGraphSegmentContainer IMSVidGraphSegmentContainer;
#endif 	/* __IMSVidGraphSegmentContainer_FWD_DEFINED__ */


#ifndef __IMSVidGraphSegment_FWD_DEFINED__
#define __IMSVidGraphSegment_FWD_DEFINED__
typedef interface IMSVidGraphSegment IMSVidGraphSegment;
#endif 	/* __IMSVidGraphSegment_FWD_DEFINED__ */


#ifndef __IMSVidGraphSegmentUserInput_FWD_DEFINED__
#define __IMSVidGraphSegmentUserInput_FWD_DEFINED__
typedef interface IMSVidGraphSegmentUserInput IMSVidGraphSegmentUserInput;
#endif 	/* __IMSVidGraphSegmentUserInput_FWD_DEFINED__ */


#ifndef __IMSVidCompositionSegment_FWD_DEFINED__
#define __IMSVidCompositionSegment_FWD_DEFINED__
typedef interface IMSVidCompositionSegment IMSVidCompositionSegment;
#endif 	/* __IMSVidCompositionSegment_FWD_DEFINED__ */


#ifndef __IEnumMSVidGraphSegment_FWD_DEFINED__
#define __IEnumMSVidGraphSegment_FWD_DEFINED__
typedef interface IEnumMSVidGraphSegment IEnumMSVidGraphSegment;
#endif 	/* __IEnumMSVidGraphSegment_FWD_DEFINED__ */


#ifndef __IMSVidVRGraphSegment_FWD_DEFINED__
#define __IMSVidVRGraphSegment_FWD_DEFINED__
typedef interface IMSVidVRGraphSegment IMSVidVRGraphSegment;
#endif 	/* __IMSVidVRGraphSegment_FWD_DEFINED__ */


#ifndef __IMSVidDevice_FWD_DEFINED__
#define __IMSVidDevice_FWD_DEFINED__
typedef interface IMSVidDevice IMSVidDevice;
#endif 	/* __IMSVidDevice_FWD_DEFINED__ */


#ifndef __IMSVidDevice2_FWD_DEFINED__
#define __IMSVidDevice2_FWD_DEFINED__
typedef interface IMSVidDevice2 IMSVidDevice2;
#endif 	/* __IMSVidDevice2_FWD_DEFINED__ */


#ifndef __IMSVidInputDevice_FWD_DEFINED__
#define __IMSVidInputDevice_FWD_DEFINED__
typedef interface IMSVidInputDevice IMSVidInputDevice;
#endif 	/* __IMSVidInputDevice_FWD_DEFINED__ */


#ifndef __IMSVidDeviceEvent_FWD_DEFINED__
#define __IMSVidDeviceEvent_FWD_DEFINED__
typedef interface IMSVidDeviceEvent IMSVidDeviceEvent;
#endif 	/* __IMSVidDeviceEvent_FWD_DEFINED__ */


#ifndef __IMSVidInputDeviceEvent_FWD_DEFINED__
#define __IMSVidInputDeviceEvent_FWD_DEFINED__
typedef interface IMSVidInputDeviceEvent IMSVidInputDeviceEvent;
#endif 	/* __IMSVidInputDeviceEvent_FWD_DEFINED__ */


#ifndef __IMSVidVideoInputDevice_FWD_DEFINED__
#define __IMSVidVideoInputDevice_FWD_DEFINED__
typedef interface IMSVidVideoInputDevice IMSVidVideoInputDevice;
#endif 	/* __IMSVidVideoInputDevice_FWD_DEFINED__ */


#ifndef __IMSVidPlayback_FWD_DEFINED__
#define __IMSVidPlayback_FWD_DEFINED__
typedef interface IMSVidPlayback IMSVidPlayback;
#endif 	/* __IMSVidPlayback_FWD_DEFINED__ */


#ifndef __IMSVidPlaybackEvent_FWD_DEFINED__
#define __IMSVidPlaybackEvent_FWD_DEFINED__
typedef interface IMSVidPlaybackEvent IMSVidPlaybackEvent;
#endif 	/* __IMSVidPlaybackEvent_FWD_DEFINED__ */


#ifndef __IMSVidTuner_FWD_DEFINED__
#define __IMSVidTuner_FWD_DEFINED__
typedef interface IMSVidTuner IMSVidTuner;
#endif 	/* __IMSVidTuner_FWD_DEFINED__ */


#ifndef __IMSVidTunerEvent_FWD_DEFINED__
#define __IMSVidTunerEvent_FWD_DEFINED__
typedef interface IMSVidTunerEvent IMSVidTunerEvent;
#endif 	/* __IMSVidTunerEvent_FWD_DEFINED__ */


#ifndef __IMSVidAnalogTuner_FWD_DEFINED__
#define __IMSVidAnalogTuner_FWD_DEFINED__
typedef interface IMSVidAnalogTuner IMSVidAnalogTuner;
#endif 	/* __IMSVidAnalogTuner_FWD_DEFINED__ */


#ifndef __IMSVidAnalogTuner2_FWD_DEFINED__
#define __IMSVidAnalogTuner2_FWD_DEFINED__
typedef interface IMSVidAnalogTuner2 IMSVidAnalogTuner2;
#endif 	/* __IMSVidAnalogTuner2_FWD_DEFINED__ */


#ifndef __IMSVidAnalogTunerEvent_FWD_DEFINED__
#define __IMSVidAnalogTunerEvent_FWD_DEFINED__
typedef interface IMSVidAnalogTunerEvent IMSVidAnalogTunerEvent;
#endif 	/* __IMSVidAnalogTunerEvent_FWD_DEFINED__ */


#ifndef __IMSVidFilePlayback_FWD_DEFINED__
#define __IMSVidFilePlayback_FWD_DEFINED__
typedef interface IMSVidFilePlayback IMSVidFilePlayback;
#endif 	/* __IMSVidFilePlayback_FWD_DEFINED__ */


#ifndef __IMSVidFilePlayback2_FWD_DEFINED__
#define __IMSVidFilePlayback2_FWD_DEFINED__
typedef interface IMSVidFilePlayback2 IMSVidFilePlayback2;
#endif 	/* __IMSVidFilePlayback2_FWD_DEFINED__ */


#ifndef __IMSVidFilePlaybackEvent_FWD_DEFINED__
#define __IMSVidFilePlaybackEvent_FWD_DEFINED__
typedef interface IMSVidFilePlaybackEvent IMSVidFilePlaybackEvent;
#endif 	/* __IMSVidFilePlaybackEvent_FWD_DEFINED__ */


#ifndef __IMSVidWebDVD_FWD_DEFINED__
#define __IMSVidWebDVD_FWD_DEFINED__
typedef interface IMSVidWebDVD IMSVidWebDVD;
#endif 	/* __IMSVidWebDVD_FWD_DEFINED__ */


#ifndef __IMSVidWebDVDEvent_FWD_DEFINED__
#define __IMSVidWebDVDEvent_FWD_DEFINED__
typedef interface IMSVidWebDVDEvent IMSVidWebDVDEvent;
#endif 	/* __IMSVidWebDVDEvent_FWD_DEFINED__ */


#ifndef __IMSVidWebDVDAdm_FWD_DEFINED__
#define __IMSVidWebDVDAdm_FWD_DEFINED__
typedef interface IMSVidWebDVDAdm IMSVidWebDVDAdm;
#endif 	/* __IMSVidWebDVDAdm_FWD_DEFINED__ */


#ifndef __IMSVidOutputDevice_FWD_DEFINED__
#define __IMSVidOutputDevice_FWD_DEFINED__
typedef interface IMSVidOutputDevice IMSVidOutputDevice;
#endif 	/* __IMSVidOutputDevice_FWD_DEFINED__ */


#ifndef __IMSVidOutputDeviceEvent_FWD_DEFINED__
#define __IMSVidOutputDeviceEvent_FWD_DEFINED__
typedef interface IMSVidOutputDeviceEvent IMSVidOutputDeviceEvent;
#endif 	/* __IMSVidOutputDeviceEvent_FWD_DEFINED__ */


#ifndef __IMSVidFeature_FWD_DEFINED__
#define __IMSVidFeature_FWD_DEFINED__
typedef interface IMSVidFeature IMSVidFeature;
#endif 	/* __IMSVidFeature_FWD_DEFINED__ */


#ifndef __IMSVidFeatureEvent_FWD_DEFINED__
#define __IMSVidFeatureEvent_FWD_DEFINED__
typedef interface IMSVidFeatureEvent IMSVidFeatureEvent;
#endif 	/* __IMSVidFeatureEvent_FWD_DEFINED__ */


#ifndef __IMSVidEncoder_FWD_DEFINED__
#define __IMSVidEncoder_FWD_DEFINED__
typedef interface IMSVidEncoder IMSVidEncoder;
#endif 	/* __IMSVidEncoder_FWD_DEFINED__ */


#ifndef __IMSVidXDS_FWD_DEFINED__
#define __IMSVidXDS_FWD_DEFINED__
typedef interface IMSVidXDS IMSVidXDS;
#endif 	/* __IMSVidXDS_FWD_DEFINED__ */


#ifndef __IMSVidXDSEvent_FWD_DEFINED__
#define __IMSVidXDSEvent_FWD_DEFINED__
typedef interface IMSVidXDSEvent IMSVidXDSEvent;
#endif 	/* __IMSVidXDSEvent_FWD_DEFINED__ */


#ifndef __IMSVidDataServices_FWD_DEFINED__
#define __IMSVidDataServices_FWD_DEFINED__
typedef interface IMSVidDataServices IMSVidDataServices;
#endif 	/* __IMSVidDataServices_FWD_DEFINED__ */


#ifndef __IMSVidDataServicesEvent_FWD_DEFINED__
#define __IMSVidDataServicesEvent_FWD_DEFINED__
typedef interface IMSVidDataServicesEvent IMSVidDataServicesEvent;
#endif 	/* __IMSVidDataServicesEvent_FWD_DEFINED__ */


#ifndef __IMSVidClosedCaptioning_FWD_DEFINED__
#define __IMSVidClosedCaptioning_FWD_DEFINED__
typedef interface IMSVidClosedCaptioning IMSVidClosedCaptioning;
#endif 	/* __IMSVidClosedCaptioning_FWD_DEFINED__ */


#ifndef __IMSVidClosedCaptioning2_FWD_DEFINED__
#define __IMSVidClosedCaptioning2_FWD_DEFINED__
typedef interface IMSVidClosedCaptioning2 IMSVidClosedCaptioning2;
#endif 	/* __IMSVidClosedCaptioning2_FWD_DEFINED__ */


#ifndef __IMSVidClosedCaptioning3_FWD_DEFINED__
#define __IMSVidClosedCaptioning3_FWD_DEFINED__
typedef interface IMSVidClosedCaptioning3 IMSVidClosedCaptioning3;
#endif 	/* __IMSVidClosedCaptioning3_FWD_DEFINED__ */


#ifndef __IMSVidVideoRenderer_FWD_DEFINED__
#define __IMSVidVideoRenderer_FWD_DEFINED__
typedef interface IMSVidVideoRenderer IMSVidVideoRenderer;
#endif 	/* __IMSVidVideoRenderer_FWD_DEFINED__ */


#ifndef __IMSVidVideoRendererEvent_FWD_DEFINED__
#define __IMSVidVideoRendererEvent_FWD_DEFINED__
typedef interface IMSVidVideoRendererEvent IMSVidVideoRendererEvent;
#endif 	/* __IMSVidVideoRendererEvent_FWD_DEFINED__ */


#ifndef __IMSVidGenericSink_FWD_DEFINED__
#define __IMSVidGenericSink_FWD_DEFINED__
typedef interface IMSVidGenericSink IMSVidGenericSink;
#endif 	/* __IMSVidGenericSink_FWD_DEFINED__ */


#ifndef __IMSVidGenericSink2_FWD_DEFINED__
#define __IMSVidGenericSink2_FWD_DEFINED__
typedef interface IMSVidGenericSink2 IMSVidGenericSink2;
#endif 	/* __IMSVidGenericSink2_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferRecordingControl_FWD_DEFINED__
#define __IMSVidStreamBufferRecordingControl_FWD_DEFINED__
typedef interface IMSVidStreamBufferRecordingControl IMSVidStreamBufferRecordingControl;
#endif 	/* __IMSVidStreamBufferRecordingControl_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSink_FWD_DEFINED__
#define __IMSVidStreamBufferSink_FWD_DEFINED__
typedef interface IMSVidStreamBufferSink IMSVidStreamBufferSink;
#endif 	/* __IMSVidStreamBufferSink_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSink2_FWD_DEFINED__
#define __IMSVidStreamBufferSink2_FWD_DEFINED__
typedef interface IMSVidStreamBufferSink2 IMSVidStreamBufferSink2;
#endif 	/* __IMSVidStreamBufferSink2_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSink3_FWD_DEFINED__
#define __IMSVidStreamBufferSink3_FWD_DEFINED__
typedef interface IMSVidStreamBufferSink3 IMSVidStreamBufferSink3;
#endif 	/* __IMSVidStreamBufferSink3_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent_FWD_DEFINED__
#define __IMSVidStreamBufferSinkEvent_FWD_DEFINED__
typedef interface IMSVidStreamBufferSinkEvent IMSVidStreamBufferSinkEvent;
#endif 	/* __IMSVidStreamBufferSinkEvent_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent2_FWD_DEFINED__
#define __IMSVidStreamBufferSinkEvent2_FWD_DEFINED__
typedef interface IMSVidStreamBufferSinkEvent2 IMSVidStreamBufferSinkEvent2;
#endif 	/* __IMSVidStreamBufferSinkEvent2_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent3_FWD_DEFINED__
#define __IMSVidStreamBufferSinkEvent3_FWD_DEFINED__
typedef interface IMSVidStreamBufferSinkEvent3 IMSVidStreamBufferSinkEvent3;
#endif 	/* __IMSVidStreamBufferSinkEvent3_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSource_FWD_DEFINED__
#define __IMSVidStreamBufferSource_FWD_DEFINED__
typedef interface IMSVidStreamBufferSource IMSVidStreamBufferSource;
#endif 	/* __IMSVidStreamBufferSource_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSource2_FWD_DEFINED__
#define __IMSVidStreamBufferSource2_FWD_DEFINED__
typedef interface IMSVidStreamBufferSource2 IMSVidStreamBufferSource2;
#endif 	/* __IMSVidStreamBufferSource2_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent_FWD_DEFINED__
#define __IMSVidStreamBufferSourceEvent_FWD_DEFINED__
typedef interface IMSVidStreamBufferSourceEvent IMSVidStreamBufferSourceEvent;
#endif 	/* __IMSVidStreamBufferSourceEvent_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent2_FWD_DEFINED__
#define __IMSVidStreamBufferSourceEvent2_FWD_DEFINED__
typedef interface IMSVidStreamBufferSourceEvent2 IMSVidStreamBufferSourceEvent2;
#endif 	/* __IMSVidStreamBufferSourceEvent2_FWD_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent3_FWD_DEFINED__
#define __IMSVidStreamBufferSourceEvent3_FWD_DEFINED__
typedef interface IMSVidStreamBufferSourceEvent3 IMSVidStreamBufferSourceEvent3;
#endif 	/* __IMSVidStreamBufferSourceEvent3_FWD_DEFINED__ */


#ifndef __IMSVidVideoRenderer2_FWD_DEFINED__
#define __IMSVidVideoRenderer2_FWD_DEFINED__
typedef interface IMSVidVideoRenderer2 IMSVidVideoRenderer2;
#endif 	/* __IMSVidVideoRenderer2_FWD_DEFINED__ */


#ifndef __IMSVidVideoRendererEvent2_FWD_DEFINED__
#define __IMSVidVideoRendererEvent2_FWD_DEFINED__
typedef interface IMSVidVideoRendererEvent2 IMSVidVideoRendererEvent2;
#endif 	/* __IMSVidVideoRendererEvent2_FWD_DEFINED__ */


#ifndef __IMSVidVMR9_FWD_DEFINED__
#define __IMSVidVMR9_FWD_DEFINED__
typedef interface IMSVidVMR9 IMSVidVMR9;
#endif 	/* __IMSVidVMR9_FWD_DEFINED__ */


#ifndef __IMSVidEVR_FWD_DEFINED__
#define __IMSVidEVR_FWD_DEFINED__
typedef interface IMSVidEVR IMSVidEVR;
#endif 	/* __IMSVidEVR_FWD_DEFINED__ */


#ifndef __IMSVidEVREvent_FWD_DEFINED__
#define __IMSVidEVREvent_FWD_DEFINED__
typedef interface IMSVidEVREvent IMSVidEVREvent;
#endif 	/* __IMSVidEVREvent_FWD_DEFINED__ */


#ifndef __IMSVidAudioRenderer_FWD_DEFINED__
#define __IMSVidAudioRenderer_FWD_DEFINED__
typedef interface IMSVidAudioRenderer IMSVidAudioRenderer;
#endif 	/* __IMSVidAudioRenderer_FWD_DEFINED__ */


#ifndef __IMSVidAudioRendererEvent_FWD_DEFINED__
#define __IMSVidAudioRendererEvent_FWD_DEFINED__
typedef interface IMSVidAudioRendererEvent IMSVidAudioRendererEvent;
#endif 	/* __IMSVidAudioRendererEvent_FWD_DEFINED__ */


#ifndef __IMSVidInputDevices_FWD_DEFINED__
#define __IMSVidInputDevices_FWD_DEFINED__
typedef interface IMSVidInputDevices IMSVidInputDevices;
#endif 	/* __IMSVidInputDevices_FWD_DEFINED__ */


#ifndef __IMSVidOutputDevices_FWD_DEFINED__
#define __IMSVidOutputDevices_FWD_DEFINED__
typedef interface IMSVidOutputDevices IMSVidOutputDevices;
#endif 	/* __IMSVidOutputDevices_FWD_DEFINED__ */


#ifndef __IMSVidVideoRendererDevices_FWD_DEFINED__
#define __IMSVidVideoRendererDevices_FWD_DEFINED__
typedef interface IMSVidVideoRendererDevices IMSVidVideoRendererDevices;
#endif 	/* __IMSVidVideoRendererDevices_FWD_DEFINED__ */


#ifndef __IMSVidAudioRendererDevices_FWD_DEFINED__
#define __IMSVidAudioRendererDevices_FWD_DEFINED__
typedef interface IMSVidAudioRendererDevices IMSVidAudioRendererDevices;
#endif 	/* __IMSVidAudioRendererDevices_FWD_DEFINED__ */


#ifndef __IMSVidFeatures_FWD_DEFINED__
#define __IMSVidFeatures_FWD_DEFINED__
typedef interface IMSVidFeatures IMSVidFeatures;
#endif 	/* __IMSVidFeatures_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "strmif.h"
#include "tuner.h"
#include "tvratings.h"
#include "evr.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_segment_0000_0000 */
/* [local] */ 

//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1999-2000.
//
//--------------------------------------------------------------------------
#pragma once
#include <olectl.h>
typedef /* [public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0001
    {	dispidName	= 0,
	dispidStatus	= ( dispidName + 1 ) ,
	dispidDevImageSourceWidth	= ( dispidStatus + 1 ) ,
	dispidDevImageSourceHeight	= ( dispidDevImageSourceWidth + 1 ) ,
	dispidDevCountryCode	= ( dispidDevImageSourceHeight + 1 ) ,
	dispidDevOverScan	= ( dispidDevCountryCode + 1 ) ,
	dispidSegment	= ( dispidDevOverScan + 1 ) ,
	dispidDevVolume	= ( dispidSegment + 1 ) ,
	dispidDevBalance	= ( dispidDevVolume + 1 ) ,
	dispidDevPower	= ( dispidDevBalance + 1 ) ,
	dispidTuneChan	= ( dispidDevPower + 1 ) ,
	dispidDevVideoSubchannel	= ( dispidTuneChan + 1 ) ,
	dispidDevAudioSubchannel	= ( dispidDevVideoSubchannel + 1 ) ,
	dispidChannelAvailable	= ( dispidDevAudioSubchannel + 1 ) ,
	dispidDevVideoFrequency	= ( dispidChannelAvailable + 1 ) ,
	dispidDevAudioFrequency	= ( dispidDevVideoFrequency + 1 ) ,
	dispidCount	= ( dispidDevAudioFrequency + 1 ) ,
	dispidDevFileName	= ( dispidCount + 1 ) ,
	dispidVisible	= ( dispidDevFileName + 1 ) ,
	dispidOwner	= ( dispidVisible + 1 ) ,
	dispidMessageDrain	= ( dispidOwner + 1 ) ,
	dispidViewable	= ( dispidMessageDrain + 1 ) ,
	dispidDevView	= ( dispidViewable + 1 ) ,
	dispidKSCat	= ( dispidDevView + 1 ) ,
	dispidCLSID	= ( dispidKSCat + 1 ) ,
	dispid_KSCat	= ( dispidCLSID + 1 ) ,
	dispid_CLSID	= ( dispid_KSCat + 1 ) ,
	dispidTune	= ( dispid_CLSID + 1 ) ,
	dispidTS	= ( dispidTune + 1 ) ,
	dispidDevSAP	= ( dispidTS + 1 ) ,
	dispidClip	= ( dispidDevSAP + 1 ) ,
	dispidRequestedClipRect	= ( dispidClip + 1 ) ,
	dispidClippedSourceRect	= ( dispidRequestedClipRect + 1 ) ,
	dispidAvailableSourceRect	= ( dispidClippedSourceRect + 1 ) ,
	dispidMediaPosition	= ( dispidAvailableSourceRect + 1 ) ,
	dispidDevRun	= ( dispidMediaPosition + 1 ) ,
	dispidDevPause	= ( dispidDevRun + 1 ) ,
	dispidDevStop	= ( dispidDevPause + 1 ) ,
	dispidCCEnable	= ( dispidDevStop + 1 ) ,
	dispidDevStep	= ( dispidCCEnable + 1 ) ,
	dispidDevCanStep	= ( dispidDevStep + 1 ) ,
	dispidSourceSize	= ( dispidDevCanStep + 1 ) ,
	dispid_playtitle	= ( dispidSourceSize + 1 ) ,
	dispid_playchapterintitle	= ( dispid_playtitle + 1 ) ,
	dispid_playchapter	= ( dispid_playchapterintitle + 1 ) ,
	dispid_playchaptersautostop	= ( dispid_playchapter + 1 ) ,
	dispid_playattime	= ( dispid_playchaptersautostop + 1 ) ,
	dispid_playattimeintitle	= ( dispid_playattime + 1 ) ,
	dispid_playperiodintitleautostop	= ( dispid_playattimeintitle + 1 ) ,
	dispid_replaychapter	= ( dispid_playperiodintitleautostop + 1 ) ,
	dispid_playprevchapter	= ( dispid_replaychapter + 1 ) ,
	dispid_playnextchapter	= ( dispid_playprevchapter + 1 ) ,
	dispid_playforwards	= ( dispid_playnextchapter + 1 ) ,
	dispid_playbackwards	= ( dispid_playforwards + 1 ) ,
	dispid_stilloff	= ( dispid_playbackwards + 1 ) ,
	dispid_audiolanguage	= ( dispid_stilloff + 1 ) ,
	dispid_showmenu	= ( dispid_audiolanguage + 1 ) ,
	dispid_resume	= ( dispid_showmenu + 1 ) ,
	dispid_returnfromsubmenu	= ( dispid_resume + 1 ) ,
	dispid_buttonsavailable	= ( dispid_returnfromsubmenu + 1 ) ,
	dispid_currentbutton	= ( dispid_buttonsavailable + 1 ) ,
	dispid_SelectAndActivateButton	= ( dispid_currentbutton + 1 ) ,
	dispid_ActivateButton	= ( dispid_SelectAndActivateButton + 1 ) ,
	dispid_SelectRightButton	= ( dispid_ActivateButton + 1 ) ,
	dispid_SelectLeftButton	= ( dispid_SelectRightButton + 1 ) ,
	dispid_SelectLowerButton	= ( dispid_SelectLeftButton + 1 ) ,
	dispid_SelectUpperButton	= ( dispid_SelectLowerButton + 1 ) ,
	dispid_ActivateAtPosition	= ( dispid_SelectUpperButton + 1 ) ,
	dispid_SelectAtPosition	= ( dispid_ActivateAtPosition + 1 ) ,
	dispid_ButtonAtPosition	= ( dispid_SelectAtPosition + 1 ) ,
	dispid_NumberOfChapters	= ( dispid_ButtonAtPosition + 1 ) ,
	dispid_TotalTitleTime	= ( dispid_NumberOfChapters + 1 ) ,
	dispid_TitlesAvailable	= ( dispid_TotalTitleTime + 1 ) ,
	dispid_VolumesAvailable	= ( dispid_TitlesAvailable + 1 ) ,
	dispid_CurrentVolume	= ( dispid_VolumesAvailable + 1 ) ,
	dispid_CurrentDiscSide	= ( dispid_CurrentVolume + 1 ) ,
	dispid_CurrentDomain	= ( dispid_CurrentDiscSide + 1 ) ,
	dispid_CurrentChapter	= ( dispid_CurrentDomain + 1 ) ,
	dispid_CurrentTitle	= ( dispid_CurrentChapter + 1 ) ,
	dispid_CurrentTime	= ( dispid_CurrentTitle + 1 ) ,
	dispid_FramesPerSecond	= ( dispid_CurrentTime + 1 ) ,
	dispid_DVDTimeCode2bstr	= ( dispid_FramesPerSecond + 1 ) ,
	dispid_DVDDirectory	= ( dispid_DVDTimeCode2bstr + 1 ) ,
	dispid_IsSubpictureStreamEnabled	= ( dispid_DVDDirectory + 1 ) ,
	dispid_IsAudioStreamEnabled	= ( dispid_IsSubpictureStreamEnabled + 1 ) ,
	dispid_CurrentSubpictureStream	= ( dispid_IsAudioStreamEnabled + 1 ) ,
	dispid_SubpictureLanguage	= ( dispid_CurrentSubpictureStream + 1 ) ,
	dispid_CurrentAudioStream	= ( dispid_SubpictureLanguage + 1 ) ,
	dispid_AudioStreamsAvailable	= ( dispid_CurrentAudioStream + 1 ) ,
	dispid_AnglesAvailable	= ( dispid_AudioStreamsAvailable + 1 ) ,
	dispid_CurrentAngle	= ( dispid_AnglesAvailable + 1 ) ,
	dispid_CCActive	= ( dispid_CurrentAngle + 1 ) ,
	dispid_CurrentCCService	= ( dispid_CCActive + 1 ) ,
	dispid_SubpictureStreamsAvailable	= ( dispid_CurrentCCService + 1 ) ,
	dispid_SubpictureOn	= ( dispid_SubpictureStreamsAvailable + 1 ) ,
	dispid_DVDUniqueID	= ( dispid_SubpictureOn + 1 ) ,
	dispid_EnableResetOnStop	= ( dispid_DVDUniqueID + 1 ) ,
	dispid_AcceptParentalLevelChange	= ( dispid_EnableResetOnStop + 1 ) ,
	dispid_NotifyParentalLevelChange	= ( dispid_AcceptParentalLevelChange + 1 ) ,
	dispid_SelectParentalCountry	= ( dispid_NotifyParentalLevelChange + 1 ) ,
	dispid_SelectParentalLevel	= ( dispid_SelectParentalCountry + 1 ) ,
	dispid_TitleParentalLevels	= ( dispid_SelectParentalLevel + 1 ) ,
	dispid_PlayerParentalCountry	= ( dispid_TitleParentalLevels + 1 ) ,
	dispid_PlayerParentalLevel	= ( dispid_PlayerParentalCountry + 1 ) ,
	dispid_Eject	= ( dispid_PlayerParentalLevel + 1 ) ,
	dispid_UOPValid	= ( dispid_Eject + 1 ) ,
	dispid_SPRM	= ( dispid_UOPValid + 1 ) ,
	dispid_GPRM	= ( dispid_SPRM + 1 ) ,
	dispid_DVDTextStringType	= ( dispid_GPRM + 1 ) ,
	dispid_DVDTextString	= ( dispid_DVDTextStringType + 1 ) ,
	dispid_DVDTextNumberOfStrings	= ( dispid_DVDTextString + 1 ) ,
	dispid_DVDTextNumberOfLanguages	= ( dispid_DVDTextNumberOfStrings + 1 ) ,
	dispid_DVDTextLanguageLCID	= ( dispid_DVDTextNumberOfLanguages + 1 ) ,
	dispid_RegionChange	= ( dispid_DVDTextLanguageLCID + 1 ) ,
	dispid_DVDAdm	= ( dispid_RegionChange + 1 ) ,
	dispid_DeleteBookmark	= ( dispid_DVDAdm + 1 ) ,
	dispid_RestoreBookmark	= ( dispid_DeleteBookmark + 1 ) ,
	dispid_SaveBookmark	= ( dispid_RestoreBookmark + 1 ) ,
	dispid_SelectDefaultAudioLanguage	= ( dispid_SaveBookmark + 1 ) ,
	dispid_SelectDefaultSubpictureLanguage	= ( dispid_SelectDefaultAudioLanguage + 1 ) ,
	dispid_PreferredSubpictureStream	= ( dispid_SelectDefaultSubpictureLanguage + 1 ) ,
	dispid_DefaultMenuLanguage	= ( dispid_PreferredSubpictureStream + 1 ) ,
	dispid_DefaultSubpictureLanguage	= ( dispid_DefaultMenuLanguage + 1 ) ,
	dispid_DefaultAudioLanguage	= ( dispid_DefaultSubpictureLanguage + 1 ) ,
	dispid_DefaultSubpictureLanguageExt	= ( dispid_DefaultAudioLanguage + 1 ) ,
	dispid_DefaultAudioLanguageExt	= ( dispid_DefaultSubpictureLanguageExt + 1 ) ,
	dispid_LanguageFromLCID	= ( dispid_DefaultAudioLanguageExt + 1 ) ,
	dispid_KaraokeAudioPresentationMode	= ( dispid_LanguageFromLCID + 1 ) ,
	dispid_KaraokeChannelContent	= ( dispid_KaraokeAudioPresentationMode + 1 ) ,
	dispid_KaraokeChannelAssignment	= ( dispid_KaraokeChannelContent + 1 ) ,
	dispid_RestorePreferredSettings	= ( dispid_KaraokeChannelAssignment + 1 ) ,
	dispid_ButtonRect	= ( dispid_RestorePreferredSettings + 1 ) ,
	dispid_DVDScreenInMouseCoordinates	= ( dispid_ButtonRect + 1 ) ,
	dispid_CustomCompositorClass	= ( dispid_DVDScreenInMouseCoordinates + 1 ) ,
	dispidCustomCompositorClass	= ( dispid_CustomCompositorClass + 1 ) ,
	dispid_CustomCompositor	= ( dispidCustomCompositorClass + 1 ) ,
	dispidMixerBitmap	= ( dispid_CustomCompositor + 1 ) ,
	dispid_MixerBitmap	= ( dispidMixerBitmap + 1 ) ,
	dispidMixerBitmapOpacity	= ( dispid_MixerBitmap + 1 ) ,
	dispidMixerBitmapRect	= ( dispidMixerBitmapOpacity + 1 ) ,
	dispidSetupMixerBitmap	= ( dispidMixerBitmapRect + 1 ) ,
	dispidUsingOverlay	= ( dispidSetupMixerBitmap + 1 ) ,
	dispidDisplayChange	= ( dispidUsingOverlay + 1 ) ,
	dispidRePaint	= ( dispidDisplayChange + 1 ) ,
	dispid_IsEqualDevice	= ( dispidRePaint + 1 ) ,
	dispidrate	= ( dispid_IsEqualDevice + 1 ) ,
	dispidposition	= ( dispidrate + 1 ) ,
	dispidpositionmode	= ( dispidposition + 1 ) ,
	dispidlength	= ( dispidpositionmode + 1 ) ,
	dispidChangePassword	= ( dispidlength + 1 ) ,
	dispidSaveParentalLevel	= ( dispidChangePassword + 1 ) ,
	dispidSaveParentalCountry	= ( dispidSaveParentalLevel + 1 ) ,
	dispidConfirmPassword	= ( dispidSaveParentalCountry + 1 ) ,
	dispidGetParentalLevel	= ( dispidConfirmPassword + 1 ) ,
	dispidGetParentalCountry	= ( dispidGetParentalLevel + 1 ) ,
	dispidDefaultAudioLCID	= ( dispidGetParentalCountry + 1 ) ,
	dispidDefaultSubpictureLCID	= ( dispidDefaultAudioLCID + 1 ) ,
	dispidDefaultMenuLCID	= ( dispidDefaultSubpictureLCID + 1 ) ,
	dispidBookmarkOnStop	= ( dispidDefaultMenuLCID + 1 ) ,
	dispidMaxVidRect	= ( dispidBookmarkOnStop + 1 ) ,
	dispidMinVidRect	= ( dispidMaxVidRect + 1 ) ,
	dispidCapture	= ( dispidMinVidRect + 1 ) ,
	dispid_DecimateInput	= ( dispidCapture + 1 ) ,
	dispidAlloctor	= ( dispid_DecimateInput + 1 ) ,
	dispid_Allocator	= ( dispidAlloctor + 1 ) ,
	dispidAllocPresentID	= ( dispid_Allocator + 1 ) ,
	dispidSetAllocator	= ( dispidAllocPresentID + 1 ) ,
	dispid_SetAllocator	= ( dispidSetAllocator + 1 ) ,
	dispidStreamBufferSinkName	= ( dispid_SetAllocator + 1 ) ,
	dispidStreamBufferSourceName	= ( dispidStreamBufferSinkName + 1 ) ,
	dispidStreamBufferContentRecording	= ( dispidStreamBufferSourceName + 1 ) ,
	dispidStreamBufferReferenceRecording	= ( dispidStreamBufferContentRecording + 1 ) ,
	dispidstarttime	= ( dispidStreamBufferReferenceRecording + 1 ) ,
	dispidstoptime	= ( dispidstarttime + 1 ) ,
	dispidrecordingstopped	= ( dispidstoptime + 1 ) ,
	dispidrecordingstarted	= ( dispidrecordingstopped + 1 ) ,
	dispidNameSetLock	= ( dispidrecordingstarted + 1 ) ,
	dispidrecordingtype	= ( dispidNameSetLock + 1 ) ,
	dispidstart	= ( dispidrecordingtype + 1 ) ,
	dispidRecordingAttribute	= ( dispidstart + 1 ) ,
	dispid_RecordingAttribute	= ( dispidRecordingAttribute + 1 ) ,
	dispidSBEConfigure	= ( dispid_RecordingAttribute + 1 ) ,
	dispid_CurrentRatings	= ( dispidSBEConfigure + 1 ) ,
	dispid_MaxRatingsLevel	= ( dispid_CurrentRatings + 1 ) ,
	dispid_audioencoderint	= ( dispid_MaxRatingsLevel + 1 ) ,
	dispid_videoencoderint	= ( dispid_audioencoderint + 1 ) ,
	dispidService	= ( dispid_videoencoderint + 1 ) ,
	dispid_BlockUnrated	= ( dispidService + 1 ) ,
	dispid_UnratedDelay	= ( dispid_BlockUnrated + 1 ) ,
	dispid_SuppressEffects	= ( dispid_UnratedDelay + 1 ) ,
	dispidsbesource	= ( dispid_SuppressEffects + 1 ) ,
	dispidSetSinkFilter	= ( dispidsbesource + 1 ) ,
	dispid_SinkStreams	= ( dispidSetSinkFilter + 1 ) ,
	dispidTVFormats	= ( dispid_SinkStreams + 1 ) ,
	dispidModes	= ( dispidTVFormats + 1 ) ,
	dispidAuxInputs	= ( dispidModes + 1 ) ,
	dispidTeleTextFilter	= ( dispidAuxInputs + 1 ) ,
	dispid_channelchangeint	= ( dispidTeleTextFilter + 1 ) ,
	dispidUnlockProfile	= ( dispid_channelchangeint + 1 ) ,
	dispid_AddFilter	= ( dispidUnlockProfile + 1 ) ,
	dispidSetMinSeek	= ( dispid_AddFilter + 1 ) ,
	dispidRateEx	= ( dispidSetMinSeek + 1 ) ,
	dispidaudiocounter	= ( dispidRateEx + 1 ) ,
	dispidvideocounter	= ( dispidaudiocounter + 1 ) ,
	dispidcccounter	= ( dispidvideocounter + 1 ) ,
	dispidwstcounter	= ( dispidcccounter + 1 ) ,
	dispid_audiocounter	= ( dispidwstcounter + 1 ) ,
	dispid_videocounter	= ( dispid_audiocounter + 1 ) ,
	dispid_cccounter	= ( dispid_videocounter + 1 ) ,
	dispid_wstcounter	= ( dispid_cccounter + 1 ) ,
	dispidaudioanalysis	= ( dispid_wstcounter + 1 ) ,
	dispidvideoanalysis	= ( dispidaudioanalysis + 1 ) ,
	dispiddataanalysis	= ( dispidvideoanalysis + 1 ) ,
	dispidaudio_analysis	= ( dispiddataanalysis + 1 ) ,
	dispidvideo_analysis	= ( dispidaudio_analysis + 1 ) ,
	dispiddata_analysis	= ( dispidvideo_analysis + 1 ) ,
	dispid_resetFilterList	= ( dispiddata_analysis + 1 ) ,
	dispidDevicePath	= ( dispid_resetFilterList + 1 ) ,
	dispid_SourceFilter	= ( dispidDevicePath + 1 ) ,
	dispid__SourceFilter	= ( dispid_SourceFilter + 1 ) ,
	dispidUserEvent	= ( dispid__SourceFilter + 1 ) ,
	LastReservedDeviceDispid	= 0x3fff
    } 	SegDispidList;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0002
    {	eventidStateChange	= 0,
	eventidOnTuneChanged	= ( eventidStateChange + 1 ) ,
	eventidEndOfMedia	= ( eventidOnTuneChanged + 1 ) ,
	eventidDVDNotify	= ( eventidEndOfMedia + 1 ) ,
	eventidPlayForwards	= ( eventidDVDNotify + 1 ) ,
	eventidPlayBackwards	= ( eventidPlayForwards + 1 ) ,
	eventidShowMenu	= ( eventidPlayBackwards + 1 ) ,
	eventidResume	= ( eventidShowMenu + 1 ) ,
	eventidSelectOrActivateButton	= ( eventidResume + 1 ) ,
	eventidStillOff	= ( eventidSelectOrActivateButton + 1 ) ,
	eventidPauseOn	= ( eventidStillOff + 1 ) ,
	eventidChangeCurrentAudioStream	= ( eventidPauseOn + 1 ) ,
	eventidChangeCurrentSubpictureStream	= ( eventidChangeCurrentAudioStream + 1 ) ,
	eventidChangeCurrentAngle	= ( eventidChangeCurrentSubpictureStream + 1 ) ,
	eventidPlayAtTimeInTitle	= ( eventidChangeCurrentAngle + 1 ) ,
	eventidPlayAtTime	= ( eventidPlayAtTimeInTitle + 1 ) ,
	eventidPlayChapterInTitle	= ( eventidPlayAtTime + 1 ) ,
	eventidPlayChapter	= ( eventidPlayChapterInTitle + 1 ) ,
	eventidReplayChapter	= ( eventidPlayChapter + 1 ) ,
	eventidPlayNextChapter	= ( eventidReplayChapter + 1 ) ,
	eventidStop	= ( eventidPlayNextChapter + 1 ) ,
	eventidReturnFromSubmenu	= ( eventidStop + 1 ) ,
	eventidPlayTitle	= ( eventidReturnFromSubmenu + 1 ) ,
	eventidPlayPrevChapter	= ( eventidPlayTitle + 1 ) ,
	eventidChangeKaraokePresMode	= ( eventidPlayPrevChapter + 1 ) ,
	eventidChangeVideoPresMode	= ( eventidChangeKaraokePresMode + 1 ) ,
	eventidOverlayUnavailable	= ( eventidChangeVideoPresMode + 1 ) ,
	eventidSinkCertificateFailure	= ( eventidOverlayUnavailable + 1 ) ,
	eventidSinkCertificateSuccess	= ( eventidSinkCertificateFailure + 1 ) ,
	eventidSourceCertificateFailure	= ( eventidSinkCertificateSuccess + 1 ) ,
	eventidSourceCertificateSuccess	= ( eventidSourceCertificateFailure + 1 ) ,
	eventidRatingsBlocked	= ( eventidSourceCertificateSuccess + 1 ) ,
	eventidRatingsUnlocked	= ( eventidRatingsBlocked + 1 ) ,
	eventidRatingsChanged	= ( eventidRatingsUnlocked + 1 ) ,
	eventidWriteFailure	= ( eventidRatingsChanged + 1 ) ,
	eventidTimeHole	= ( eventidWriteFailure + 1 ) ,
	eventidStaleDataRead	= ( eventidTimeHole + 1 ) ,
	eventidContentBecomingStale	= ( eventidStaleDataRead + 1 ) ,
	eventidStaleFileDeleted	= ( eventidContentBecomingStale + 1 ) ,
	eventidEncryptionOn	= ( eventidStaleFileDeleted + 1 ) ,
	eventidEncryptionOff	= ( eventidEncryptionOn + 1 ) ,
	eventidRateChange	= ( eventidEncryptionOff + 1 ) ,
	eventidLicenseChange	= ( eventidRateChange + 1 ) ,
	eventidCOPPBlocked	= ( eventidLicenseChange + 1 ) ,
	eventidCOPPUnblocked	= ( eventidCOPPBlocked + 1 ) ,
	dispidlicenseerrorcode	= ( eventidCOPPUnblocked + 1 ) ,
	eventidBroadcastEvent	= ( dispidlicenseerrorcode + 1 ) ,
	eventidBroadcastEventEx	= ( eventidBroadcastEvent + 1 ) ,
	eventidContentPrimarilyAudio	= ( eventidBroadcastEventEx + 1 ) ,
	LastReservedDeviceEvent	= 0x3fff
    } 	SegEventidList;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0003
    {	FrameMode	= 0,
	TenthsSecondsMode	= ( FrameMode + 1 ) 
    } 	PositionModeList;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0004
    {	CONTENT	= 0,
	REFERENCE	= ( CONTENT + 1 ) 
    } 	RecordingType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0005
    {	None	= 0,
	Caption1	= ( None + 1 ) ,
	Caption2	= ( Caption1 + 1 ) ,
	Text1	= ( Caption2 + 1 ) ,
	Text2	= ( Text1 + 1 ) ,
	XDS	= ( Text2 + 1 ) 
    } 	MSVidCCService;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0000_0006
    {	MSVidSink_Video	= 1,
	MSVidSink_Audio	= 2,
	MSVidSink_Other	= 4
    } 	MSVidSinkStreams;




extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0000_v0_0_s_ifspec;

#ifndef __IMSVidRect_INTERFACE_DEFINED__
#define __IMSVidRect_INTERFACE_DEFINED__

/* interface IMSVidRect */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidRect;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F5000A6-A440-47ca-8ACC-C0E75531A2C2")
    IMSVidRect : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Top( 
            /* [retval][out] */ __RPC__out LONG *TopVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Top( 
            /* [in] */ LONG TopVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Left( 
            /* [retval][out] */ __RPC__out LONG *LeftVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Left( 
            /* [in] */ LONG LeftVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ __RPC__out LONG *WidthVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ LONG WidthVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ __RPC__out LONG *HeightVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ LONG HeightVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_HWnd( 
            /* [retval][out] */ __RPC__deref_out_opt HWND *HWndVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_HWnd( 
            /* [in] */ __RPC__in HWND HWndVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Rect( 
            /* [in] */ __RPC__in_opt IMSVidRect *RectVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidRectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidRect * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidRect * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidRect * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidRect * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidRect * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidRect * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidRect * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Top )( 
            IMSVidRect * This,
            /* [retval][out] */ __RPC__out LONG *TopVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Top )( 
            IMSVidRect * This,
            /* [in] */ LONG TopVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Left )( 
            IMSVidRect * This,
            /* [retval][out] */ __RPC__out LONG *LeftVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Left )( 
            IMSVidRect * This,
            /* [in] */ LONG LeftVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IMSVidRect * This,
            /* [retval][out] */ __RPC__out LONG *WidthVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IMSVidRect * This,
            /* [in] */ LONG WidthVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IMSVidRect * This,
            /* [retval][out] */ __RPC__out LONG *HeightVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IMSVidRect * This,
            /* [in] */ LONG HeightVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWnd )( 
            IMSVidRect * This,
            /* [retval][out] */ __RPC__deref_out_opt HWND *HWndVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HWnd )( 
            IMSVidRect * This,
            /* [in] */ __RPC__in HWND HWndVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rect )( 
            IMSVidRect * This,
            /* [in] */ __RPC__in_opt IMSVidRect *RectVal);
        
        END_INTERFACE
    } IMSVidRectVtbl;

    interface IMSVidRect
    {
        CONST_VTBL struct IMSVidRectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidRect_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidRect_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidRect_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidRect_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidRect_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidRect_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidRect_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidRect_get_Top(This,TopVal)	\
    ( (This)->lpVtbl -> get_Top(This,TopVal) ) 

#define IMSVidRect_put_Top(This,TopVal)	\
    ( (This)->lpVtbl -> put_Top(This,TopVal) ) 

#define IMSVidRect_get_Left(This,LeftVal)	\
    ( (This)->lpVtbl -> get_Left(This,LeftVal) ) 

#define IMSVidRect_put_Left(This,LeftVal)	\
    ( (This)->lpVtbl -> put_Left(This,LeftVal) ) 

#define IMSVidRect_get_Width(This,WidthVal)	\
    ( (This)->lpVtbl -> get_Width(This,WidthVal) ) 

#define IMSVidRect_put_Width(This,WidthVal)	\
    ( (This)->lpVtbl -> put_Width(This,WidthVal) ) 

#define IMSVidRect_get_Height(This,HeightVal)	\
    ( (This)->lpVtbl -> get_Height(This,HeightVal) ) 

#define IMSVidRect_put_Height(This,HeightVal)	\
    ( (This)->lpVtbl -> put_Height(This,HeightVal) ) 

#define IMSVidRect_get_HWnd(This,HWndVal)	\
    ( (This)->lpVtbl -> get_HWnd(This,HWndVal) ) 

#define IMSVidRect_put_HWnd(This,HWndVal)	\
    ( (This)->lpVtbl -> put_HWnd(This,HWndVal) ) 

#define IMSVidRect_put_Rect(This,RectVal)	\
    ( (This)->lpVtbl -> put_Rect(This,RectVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidRect_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_segment_0000_0001 */
/* [local] */ 






extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0001_v0_0_s_ifspec;

#ifndef __IMSVidGraphSegmentContainer_INTERFACE_DEFINED__
#define __IMSVidGraphSegmentContainer_INTERFACE_DEFINED__

/* interface IMSVidGraphSegmentContainer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidGraphSegmentContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DD2903D-E0AA-11d2-B63A-00C04F79498E")
    IMSVidGraphSegmentContainer : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Graph( 
            /* [out] */ __RPC__deref_out_opt IGraphBuilder **ppGraph) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Input( 
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppInput) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Outputs( 
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppOutputs) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_VideoRenderer( 
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppVR) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_AudioRenderer( 
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppAR) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Features( 
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppFeatures) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Composites( 
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppComposites) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ParentContainer( 
            /* [out] */ __RPC__deref_out_opt IUnknown **ppContainer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Decompose( 
            __RPC__in_opt IMSVidGraphSegment *pSegment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWindowless( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFocus( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidGraphSegmentContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidGraphSegmentContainer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidGraphSegmentContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidGraphSegmentContainer * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Graph )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IGraphBuilder **ppGraph);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Input )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppInput);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Outputs )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppOutputs);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoRenderer )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppVR);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioRenderer )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **ppAR);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Features )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppFeatures);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Composites )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppComposites);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentContainer )( 
            IMSVidGraphSegmentContainer * This,
            /* [out] */ __RPC__deref_out_opt IUnknown **ppContainer);
        
        HRESULT ( STDMETHODCALLTYPE *Decompose )( 
            IMSVidGraphSegmentContainer * This,
            __RPC__in_opt IMSVidGraphSegment *pSegment);
        
        HRESULT ( STDMETHODCALLTYPE *IsWindowless )( 
            IMSVidGraphSegmentContainer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFocus )( 
            IMSVidGraphSegmentContainer * This);
        
        END_INTERFACE
    } IMSVidGraphSegmentContainerVtbl;

    interface IMSVidGraphSegmentContainer
    {
        CONST_VTBL struct IMSVidGraphSegmentContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidGraphSegmentContainer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidGraphSegmentContainer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidGraphSegmentContainer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidGraphSegmentContainer_get_Graph(This,ppGraph)	\
    ( (This)->lpVtbl -> get_Graph(This,ppGraph) ) 

#define IMSVidGraphSegmentContainer_get_Input(This,ppInput)	\
    ( (This)->lpVtbl -> get_Input(This,ppInput) ) 

#define IMSVidGraphSegmentContainer_get_Outputs(This,ppOutputs)	\
    ( (This)->lpVtbl -> get_Outputs(This,ppOutputs) ) 

#define IMSVidGraphSegmentContainer_get_VideoRenderer(This,ppVR)	\
    ( (This)->lpVtbl -> get_VideoRenderer(This,ppVR) ) 

#define IMSVidGraphSegmentContainer_get_AudioRenderer(This,ppAR)	\
    ( (This)->lpVtbl -> get_AudioRenderer(This,ppAR) ) 

#define IMSVidGraphSegmentContainer_get_Features(This,ppFeatures)	\
    ( (This)->lpVtbl -> get_Features(This,ppFeatures) ) 

#define IMSVidGraphSegmentContainer_get_Composites(This,ppComposites)	\
    ( (This)->lpVtbl -> get_Composites(This,ppComposites) ) 

#define IMSVidGraphSegmentContainer_get_ParentContainer(This,ppContainer)	\
    ( (This)->lpVtbl -> get_ParentContainer(This,ppContainer) ) 

#define IMSVidGraphSegmentContainer_Decompose(This,pSegment)	\
    ( (This)->lpVtbl -> Decompose(This,pSegment) ) 

#define IMSVidGraphSegmentContainer_IsWindowless(This)	\
    ( (This)->lpVtbl -> IsWindowless(This) ) 

#define IMSVidGraphSegmentContainer_GetFocus(This)	\
    ( (This)->lpVtbl -> GetFocus(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidGraphSegmentContainer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_segment_0000_0002 */
/* [local] */ 

typedef 
enum MSVidSegmentType
    {	MSVidSEG_SOURCE	= 0,
	MSVidSEG_XFORM	= ( MSVidSEG_SOURCE + 1 ) ,
	MSVidSEG_DEST	= ( MSVidSEG_XFORM + 1 ) 
    } 	MSVidSegmentType;



extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0002_v0_0_s_ifspec;

#ifndef __IMSVidGraphSegment_INTERFACE_DEFINED__
#define __IMSVidGraphSegment_INTERFACE_DEFINED__

/* interface IMSVidGraphSegment */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidGraphSegment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("238DEC54-ADEB-4005-A349-F772B9AFEBC4")
    IMSVidGraphSegment : public IPersist
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Init( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pInit) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Init( 
            /* [in] */ __RPC__in_opt IUnknown *pInit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumFilters( 
            /* [out] */ __RPC__deref_out_opt IEnumFilters **pNewEnum) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Container( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidGraphSegmentContainer **ppCtl) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Container( 
            /* [in] */ __RPC__in_opt IMSVidGraphSegmentContainer *pCtl) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ __RPC__out MSVidSegmentType *pType) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Category( 
            /* [retval][out] */ __RPC__out GUID *pGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Build( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostBuild( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PreRun( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostRun( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PreStop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PostStop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEventNotify( 
            LONG lEventCode,
            LONG_PTR lEventParm1,
            LONG_PTR lEventParm2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Decompose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidGraphSegmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidGraphSegment * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidGraphSegment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IMSVidGraphSegment * This,
            /* [out] */ __RPC__out CLSID *pClassID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Init )( 
            IMSVidGraphSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pInit);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Init )( 
            IMSVidGraphSegment * This,
            /* [in] */ __RPC__in_opt IUnknown *pInit);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilters )( 
            IMSVidGraphSegment * This,
            /* [out] */ __RPC__deref_out_opt IEnumFilters **pNewEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Container )( 
            IMSVidGraphSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidGraphSegmentContainer **ppCtl);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Container )( 
            IMSVidGraphSegment * This,
            /* [in] */ __RPC__in_opt IMSVidGraphSegmentContainer *pCtl);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IMSVidGraphSegment * This,
            /* [retval][out] */ __RPC__out MSVidSegmentType *pType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidGraphSegment * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Build )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostBuild )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreRun )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostRun )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreStop )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostStop )( 
            IMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnEventNotify )( 
            IMSVidGraphSegment * This,
            LONG lEventCode,
            LONG_PTR lEventParm1,
            LONG_PTR lEventParm2);
        
        HRESULT ( STDMETHODCALLTYPE *Decompose )( 
            IMSVidGraphSegment * This);
        
        END_INTERFACE
    } IMSVidGraphSegmentVtbl;

    interface IMSVidGraphSegment
    {
        CONST_VTBL struct IMSVidGraphSegmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidGraphSegment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidGraphSegment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidGraphSegment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidGraphSegment_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IMSVidGraphSegment_get_Init(This,pInit)	\
    ( (This)->lpVtbl -> get_Init(This,pInit) ) 

#define IMSVidGraphSegment_put_Init(This,pInit)	\
    ( (This)->lpVtbl -> put_Init(This,pInit) ) 

#define IMSVidGraphSegment_EnumFilters(This,pNewEnum)	\
    ( (This)->lpVtbl -> EnumFilters(This,pNewEnum) ) 

#define IMSVidGraphSegment_get_Container(This,ppCtl)	\
    ( (This)->lpVtbl -> get_Container(This,ppCtl) ) 

#define IMSVidGraphSegment_put_Container(This,pCtl)	\
    ( (This)->lpVtbl -> put_Container(This,pCtl) ) 

#define IMSVidGraphSegment_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IMSVidGraphSegment_get_Category(This,pGuid)	\
    ( (This)->lpVtbl -> get_Category(This,pGuid) ) 

#define IMSVidGraphSegment_Build(This)	\
    ( (This)->lpVtbl -> Build(This) ) 

#define IMSVidGraphSegment_PostBuild(This)	\
    ( (This)->lpVtbl -> PostBuild(This) ) 

#define IMSVidGraphSegment_PreRun(This)	\
    ( (This)->lpVtbl -> PreRun(This) ) 

#define IMSVidGraphSegment_PostRun(This)	\
    ( (This)->lpVtbl -> PostRun(This) ) 

#define IMSVidGraphSegment_PreStop(This)	\
    ( (This)->lpVtbl -> PreStop(This) ) 

#define IMSVidGraphSegment_PostStop(This)	\
    ( (This)->lpVtbl -> PostStop(This) ) 

#define IMSVidGraphSegment_OnEventNotify(This,lEventCode,lEventParm1,lEventParm2)	\
    ( (This)->lpVtbl -> OnEventNotify(This,lEventCode,lEventParm1,lEventParm2) ) 

#define IMSVidGraphSegment_Decompose(This)	\
    ( (This)->lpVtbl -> Decompose(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidGraphSegment_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_segment_0000_0003 */
/* [local] */ 


enum __MIDL___MIDL_itf_segment_0000_0003_0001
    {	MSVIDCTL_LEFT_BUTTON	= 0x1,
	MSVIDCTL_RIGHT_BUTTON	= 0x2,
	MSVIDCTL_MIDDLE_BUTTON	= 0x4,
	MSVIDCTL_X_BUTTON1	= 0x8,
	MSVIDCTL_X_BUTTON2	= 0x10,
	MSVIDCTL_SHIFT	= 0x1,
	MSVIDCTL_CTRL	= 0x2,
	MSVIDCTL_ALT	= 0x4
    } ;


extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0003_v0_0_s_ifspec;

#ifndef __IMSVidGraphSegmentUserInput_INTERFACE_DEFINED__
#define __IMSVidGraphSegmentUserInput_INTERFACE_DEFINED__

/* interface IMSVidGraphSegmentUserInput */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidGraphSegmentUserInput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("301C060E-20D9-4587-9B03-F82ED9A9943C")
    IMSVidGraphSegmentUserInput : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Click( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DblClick( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeyDown( 
            __RPC__in short *KeyCode,
            short ShiftState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeyPress( 
            __RPC__in short *KeyAscii) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KeyUp( 
            __RPC__in short *KeyCode,
            short ShiftState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MouseDown( 
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MouseMove( 
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MouseUp( 
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidGraphSegmentUserInputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidGraphSegmentUserInput * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidGraphSegmentUserInput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidGraphSegmentUserInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *Click )( 
            IMSVidGraphSegmentUserInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *DblClick )( 
            IMSVidGraphSegmentUserInput * This);
        
        HRESULT ( STDMETHODCALLTYPE *KeyDown )( 
            IMSVidGraphSegmentUserInput * This,
            __RPC__in short *KeyCode,
            short ShiftState);
        
        HRESULT ( STDMETHODCALLTYPE *KeyPress )( 
            IMSVidGraphSegmentUserInput * This,
            __RPC__in short *KeyAscii);
        
        HRESULT ( STDMETHODCALLTYPE *KeyUp )( 
            IMSVidGraphSegmentUserInput * This,
            __RPC__in short *KeyCode,
            short ShiftState);
        
        HRESULT ( STDMETHODCALLTYPE *MouseDown )( 
            IMSVidGraphSegmentUserInput * This,
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y);
        
        HRESULT ( STDMETHODCALLTYPE *MouseMove )( 
            IMSVidGraphSegmentUserInput * This,
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y);
        
        HRESULT ( STDMETHODCALLTYPE *MouseUp )( 
            IMSVidGraphSegmentUserInput * This,
            short ButtonState,
            short ShiftState,
            /* external definition not present */ OLE_XPOS_PIXELS x,
            /* external definition not present */ OLE_YPOS_PIXELS y);
        
        END_INTERFACE
    } IMSVidGraphSegmentUserInputVtbl;

    interface IMSVidGraphSegmentUserInput
    {
        CONST_VTBL struct IMSVidGraphSegmentUserInputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidGraphSegmentUserInput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidGraphSegmentUserInput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidGraphSegmentUserInput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidGraphSegmentUserInput_Click(This)	\
    ( (This)->lpVtbl -> Click(This) ) 

#define IMSVidGraphSegmentUserInput_DblClick(This)	\
    ( (This)->lpVtbl -> DblClick(This) ) 

#define IMSVidGraphSegmentUserInput_KeyDown(This,KeyCode,ShiftState)	\
    ( (This)->lpVtbl -> KeyDown(This,KeyCode,ShiftState) ) 

#define IMSVidGraphSegmentUserInput_KeyPress(This,KeyAscii)	\
    ( (This)->lpVtbl -> KeyPress(This,KeyAscii) ) 

#define IMSVidGraphSegmentUserInput_KeyUp(This,KeyCode,ShiftState)	\
    ( (This)->lpVtbl -> KeyUp(This,KeyCode,ShiftState) ) 

#define IMSVidGraphSegmentUserInput_MouseDown(This,ButtonState,ShiftState,x,y)	\
    ( (This)->lpVtbl -> MouseDown(This,ButtonState,ShiftState,x,y) ) 

#define IMSVidGraphSegmentUserInput_MouseMove(This,ButtonState,ShiftState,x,y)	\
    ( (This)->lpVtbl -> MouseMove(This,ButtonState,ShiftState,x,y) ) 

#define IMSVidGraphSegmentUserInput_MouseUp(This,ButtonState,ShiftState,x,y)	\
    ( (This)->lpVtbl -> MouseUp(This,ButtonState,ShiftState,x,y) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidGraphSegmentUserInput_INTERFACE_DEFINED__ */


#ifndef __IMSVidCompositionSegment_INTERFACE_DEFINED__
#define __IMSVidCompositionSegment_INTERFACE_DEFINED__

/* interface IMSVidCompositionSegment */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidCompositionSegment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D483-911D-11d2-B632-00C04F79498E")
    IMSVidCompositionSegment : public IMSVidGraphSegment
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Compose( 
            /* [in] */ __RPC__in_opt IMSVidGraphSegment *upstream,
            /* [in] */ __RPC__in_opt IMSVidGraphSegment *downstream) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Up( 
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **upstream) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Down( 
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **downstream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidCompositionSegmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidCompositionSegment * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidCompositionSegment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IMSVidCompositionSegment * This,
            /* [out] */ __RPC__out CLSID *pClassID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Init )( 
            IMSVidCompositionSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pInit);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Init )( 
            IMSVidCompositionSegment * This,
            /* [in] */ __RPC__in_opt IUnknown *pInit);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilters )( 
            IMSVidCompositionSegment * This,
            /* [out] */ __RPC__deref_out_opt IEnumFilters **pNewEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Container )( 
            IMSVidCompositionSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidGraphSegmentContainer **ppCtl);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Container )( 
            IMSVidCompositionSegment * This,
            /* [in] */ __RPC__in_opt IMSVidGraphSegmentContainer *pCtl);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IMSVidCompositionSegment * This,
            /* [retval][out] */ __RPC__out MSVidSegmentType *pType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidCompositionSegment * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Build )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostBuild )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreRun )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostRun )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreStop )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostStop )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnEventNotify )( 
            IMSVidCompositionSegment * This,
            LONG lEventCode,
            LONG_PTR lEventParm1,
            LONG_PTR lEventParm2);
        
        HRESULT ( STDMETHODCALLTYPE *Decompose )( 
            IMSVidCompositionSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *Compose )( 
            IMSVidCompositionSegment * This,
            /* [in] */ __RPC__in_opt IMSVidGraphSegment *upstream,
            /* [in] */ __RPC__in_opt IMSVidGraphSegment *downstream);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Up )( 
            IMSVidCompositionSegment * This,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **upstream);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Down )( 
            IMSVidCompositionSegment * This,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **downstream);
        
        END_INTERFACE
    } IMSVidCompositionSegmentVtbl;

    interface IMSVidCompositionSegment
    {
        CONST_VTBL struct IMSVidCompositionSegmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidCompositionSegment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidCompositionSegment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidCompositionSegment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidCompositionSegment_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IMSVidCompositionSegment_get_Init(This,pInit)	\
    ( (This)->lpVtbl -> get_Init(This,pInit) ) 

#define IMSVidCompositionSegment_put_Init(This,pInit)	\
    ( (This)->lpVtbl -> put_Init(This,pInit) ) 

#define IMSVidCompositionSegment_EnumFilters(This,pNewEnum)	\
    ( (This)->lpVtbl -> EnumFilters(This,pNewEnum) ) 

#define IMSVidCompositionSegment_get_Container(This,ppCtl)	\
    ( (This)->lpVtbl -> get_Container(This,ppCtl) ) 

#define IMSVidCompositionSegment_put_Container(This,pCtl)	\
    ( (This)->lpVtbl -> put_Container(This,pCtl) ) 

#define IMSVidCompositionSegment_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IMSVidCompositionSegment_get_Category(This,pGuid)	\
    ( (This)->lpVtbl -> get_Category(This,pGuid) ) 

#define IMSVidCompositionSegment_Build(This)	\
    ( (This)->lpVtbl -> Build(This) ) 

#define IMSVidCompositionSegment_PostBuild(This)	\
    ( (This)->lpVtbl -> PostBuild(This) ) 

#define IMSVidCompositionSegment_PreRun(This)	\
    ( (This)->lpVtbl -> PreRun(This) ) 

#define IMSVidCompositionSegment_PostRun(This)	\
    ( (This)->lpVtbl -> PostRun(This) ) 

#define IMSVidCompositionSegment_PreStop(This)	\
    ( (This)->lpVtbl -> PreStop(This) ) 

#define IMSVidCompositionSegment_PostStop(This)	\
    ( (This)->lpVtbl -> PostStop(This) ) 

#define IMSVidCompositionSegment_OnEventNotify(This,lEventCode,lEventParm1,lEventParm2)	\
    ( (This)->lpVtbl -> OnEventNotify(This,lEventCode,lEventParm1,lEventParm2) ) 

#define IMSVidCompositionSegment_Decompose(This)	\
    ( (This)->lpVtbl -> Decompose(This) ) 


#define IMSVidCompositionSegment_Compose(This,upstream,downstream)	\
    ( (This)->lpVtbl -> Compose(This,upstream,downstream) ) 

#define IMSVidCompositionSegment_get_Up(This,upstream)	\
    ( (This)->lpVtbl -> get_Up(This,upstream) ) 

#define IMSVidCompositionSegment_get_Down(This,downstream)	\
    ( (This)->lpVtbl -> get_Down(This,downstream) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidCompositionSegment_INTERFACE_DEFINED__ */


#ifndef __IEnumMSVidGraphSegment_INTERFACE_DEFINED__
#define __IEnumMSVidGraphSegment_INTERFACE_DEFINED__

/* interface IEnumMSVidGraphSegment */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEnumMSVidGraphSegment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DD2903E-E0AA-11d2-B63A-00C04F79498E")
    IEnumMSVidGraphSegment : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumMSVidGraphSegmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumMSVidGraphSegment * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumMSVidGraphSegment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumMSVidGraphSegment * This,
            /* [in] */ ULONG celt,
            /* [out] */ __RPC__deref_out_opt IMSVidGraphSegment **rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumMSVidGraphSegment * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumMSVidGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumMSVidGraphSegment * This,
            /* [out] */ __RPC__deref_out_opt IEnumMSVidGraphSegment **ppenum);
        
        END_INTERFACE
    } IEnumMSVidGraphSegmentVtbl;

    interface IEnumMSVidGraphSegment
    {
        CONST_VTBL struct IEnumMSVidGraphSegmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumMSVidGraphSegment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEnumMSVidGraphSegment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEnumMSVidGraphSegment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEnumMSVidGraphSegment_Next(This,celt,rgelt,pceltFetched)	\
    ( (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched) ) 

#define IEnumMSVidGraphSegment_Skip(This,celt)	\
    ( (This)->lpVtbl -> Skip(This,celt) ) 

#define IEnumMSVidGraphSegment_Reset(This)	\
    ( (This)->lpVtbl -> Reset(This) ) 

#define IEnumMSVidGraphSegment_Clone(This,ppenum)	\
    ( (This)->lpVtbl -> Clone(This,ppenum) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEnumMSVidGraphSegment_INTERFACE_DEFINED__ */


#ifndef __IMSVidVRGraphSegment_INTERFACE_DEFINED__
#define __IMSVidVRGraphSegment_INTERFACE_DEFINED__

/* interface IMSVidVRGraphSegment */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMSVidVRGraphSegment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD47DE3F-9874-4f7b-8B22-7CB2688461E7")
    IMSVidVRGraphSegment : public IMSVidGraphSegment
    {
    public:
        virtual /* [propput][restricted][hidden] */ HRESULT STDMETHODCALLTYPE put__VMRendererMode( 
            /* [in] */ LONG dwMode) = 0;
        
        virtual /* [propput][restricted][hidden] */ HRESULT STDMETHODCALLTYPE put_Owner( 
            /* [in] */ __RPC__in HWND Window) = 0;
        
        virtual /* [propget][restricted][hidden] */ HRESULT STDMETHODCALLTYPE get_Owner( 
            /* [retval][out] */ __RPC__deref_out_opt HWND *Window) = 0;
        
        virtual /* [propget][restricted][hidden] */ HRESULT STDMETHODCALLTYPE get_UseOverlay( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal) = 0;
        
        virtual /* [propput][restricted][hidden] */ HRESULT STDMETHODCALLTYPE put_UseOverlay( 
            /* [in] */ VARIANT_BOOL UseOverlayVal) = 0;
        
        virtual /* [propget][restricted][hidden] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Visible) = 0;
        
        virtual /* [propput][restricted][hidden] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_ColorKey( 
            /* [retval][out] */ __RPC__out OLE_COLOR *ColorKey) = 0;
        
        virtual /* [restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_ColorKey( 
            /* [in] */ OLE_COLOR ColorKey) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_Source( 
            /* [retval][out] */ __RPC__out LPRECT r) = 0;
        
        virtual /* [restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_Source( 
            /* [in] */ RECT r) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ __RPC__out LPRECT r) = 0;
        
        virtual /* [restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_Destination( 
            /* [in] */ RECT r) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_NativeSize( 
            /* [out] */ __RPC__out LPSIZE sizeval,
            /* [out] */ __RPC__out LPSIZE aspectratio) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_BorderColor( 
            /* [retval][out] */ __RPC__out OLE_COLOR *color) = 0;
        
        virtual /* [restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_BorderColor( 
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get_MaintainAspectRatio( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fMaintain) = 0;
        
        virtual /* [restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put_MaintainAspectRatio( 
            /* [in] */ VARIANT_BOOL fMaintain) = 0;
        
        virtual /* [restricted][hidden] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [restricted][hidden] */ HRESULT STDMETHODCALLTYPE DisplayChange( void) = 0;
        
        virtual /* [restricted][hidden] */ HRESULT STDMETHODCALLTYPE RePaint( 
            /* [in] */ __RPC__in HDC hdc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVRGraphSegmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVRGraphSegment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IMSVidVRGraphSegment * This,
            /* [out] */ __RPC__out CLSID *pClassID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Init )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pInit);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE *put_Init )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ __RPC__in_opt IUnknown *pInit);
        
        HRESULT ( STDMETHODCALLTYPE *EnumFilters )( 
            IMSVidVRGraphSegment * This,
            /* [out] */ __RPC__deref_out_opt IEnumFilters **pNewEnum);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Container )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidGraphSegmentContainer **ppCtl);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Container )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ __RPC__in_opt IMSVidGraphSegmentContainer *pCtl);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out MSVidSegmentType *pType);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE *Build )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostBuild )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreRun )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostRun )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreStop )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *PostStop )( 
            IMSVidVRGraphSegment * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnEventNotify )( 
            IMSVidVRGraphSegment * This,
            LONG lEventCode,
            LONG_PTR lEventParm1,
            LONG_PTR lEventParm2);
        
        HRESULT ( STDMETHODCALLTYPE *Decompose )( 
            IMSVidVRGraphSegment * This);
        
        /* [propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put__VMRendererMode )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ LONG dwMode);
        
        /* [propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_Owner )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ __RPC__in HWND Window);
        
        /* [propget][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *get_Owner )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__deref_out_opt HWND *Window);
        
        /* [propget][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *get_UseOverlay )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal);
        
        /* [propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_UseOverlay )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ VARIANT_BOOL UseOverlayVal);
        
        /* [propget][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *Visible);
        
        /* [propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColorKey )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out OLE_COLOR *ColorKey);
        
        /* [restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ColorKey )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ OLE_COLOR ColorKey);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Source )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out LPRECT r);
        
        /* [restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Source )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ RECT r);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out LPRECT r);
        
        /* [restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ RECT r);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NativeSize )( 
            IMSVidVRGraphSegment * This,
            /* [out] */ __RPC__out LPSIZE sizeval,
            /* [out] */ __RPC__out LPSIZE aspectratio);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderColor )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out OLE_COLOR *color);
        
        /* [restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderColor )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ OLE_COLOR color);
        
        /* [restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAspectRatio )( 
            IMSVidVRGraphSegment * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fMaintain);
        
        /* [restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAspectRatio )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ VARIANT_BOOL fMaintain);
        
        /* [restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IMSVidVRGraphSegment * This);
        
        /* [restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *DisplayChange )( 
            IMSVidVRGraphSegment * This);
        
        /* [restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *RePaint )( 
            IMSVidVRGraphSegment * This,
            /* [in] */ __RPC__in HDC hdc);
        
        END_INTERFACE
    } IMSVidVRGraphSegmentVtbl;

    interface IMSVidVRGraphSegment
    {
        CONST_VTBL struct IMSVidVRGraphSegmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVRGraphSegment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVRGraphSegment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVRGraphSegment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVRGraphSegment_GetClassID(This,pClassID)	\
    ( (This)->lpVtbl -> GetClassID(This,pClassID) ) 


#define IMSVidVRGraphSegment_get_Init(This,pInit)	\
    ( (This)->lpVtbl -> get_Init(This,pInit) ) 

#define IMSVidVRGraphSegment_put_Init(This,pInit)	\
    ( (This)->lpVtbl -> put_Init(This,pInit) ) 

#define IMSVidVRGraphSegment_EnumFilters(This,pNewEnum)	\
    ( (This)->lpVtbl -> EnumFilters(This,pNewEnum) ) 

#define IMSVidVRGraphSegment_get_Container(This,ppCtl)	\
    ( (This)->lpVtbl -> get_Container(This,ppCtl) ) 

#define IMSVidVRGraphSegment_put_Container(This,pCtl)	\
    ( (This)->lpVtbl -> put_Container(This,pCtl) ) 

#define IMSVidVRGraphSegment_get_Type(This,pType)	\
    ( (This)->lpVtbl -> get_Type(This,pType) ) 

#define IMSVidVRGraphSegment_get_Category(This,pGuid)	\
    ( (This)->lpVtbl -> get_Category(This,pGuid) ) 

#define IMSVidVRGraphSegment_Build(This)	\
    ( (This)->lpVtbl -> Build(This) ) 

#define IMSVidVRGraphSegment_PostBuild(This)	\
    ( (This)->lpVtbl -> PostBuild(This) ) 

#define IMSVidVRGraphSegment_PreRun(This)	\
    ( (This)->lpVtbl -> PreRun(This) ) 

#define IMSVidVRGraphSegment_PostRun(This)	\
    ( (This)->lpVtbl -> PostRun(This) ) 

#define IMSVidVRGraphSegment_PreStop(This)	\
    ( (This)->lpVtbl -> PreStop(This) ) 

#define IMSVidVRGraphSegment_PostStop(This)	\
    ( (This)->lpVtbl -> PostStop(This) ) 

#define IMSVidVRGraphSegment_OnEventNotify(This,lEventCode,lEventParm1,lEventParm2)	\
    ( (This)->lpVtbl -> OnEventNotify(This,lEventCode,lEventParm1,lEventParm2) ) 

#define IMSVidVRGraphSegment_Decompose(This)	\
    ( (This)->lpVtbl -> Decompose(This) ) 


#define IMSVidVRGraphSegment_put__VMRendererMode(This,dwMode)	\
    ( (This)->lpVtbl -> put__VMRendererMode(This,dwMode) ) 

#define IMSVidVRGraphSegment_put_Owner(This,Window)	\
    ( (This)->lpVtbl -> put_Owner(This,Window) ) 

#define IMSVidVRGraphSegment_get_Owner(This,Window)	\
    ( (This)->lpVtbl -> get_Owner(This,Window) ) 

#define IMSVidVRGraphSegment_get_UseOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> get_UseOverlay(This,UseOverlayVal) ) 

#define IMSVidVRGraphSegment_put_UseOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> put_UseOverlay(This,UseOverlayVal) ) 

#define IMSVidVRGraphSegment_get_Visible(This,Visible)	\
    ( (This)->lpVtbl -> get_Visible(This,Visible) ) 

#define IMSVidVRGraphSegment_put_Visible(This,Visible)	\
    ( (This)->lpVtbl -> put_Visible(This,Visible) ) 

#define IMSVidVRGraphSegment_get_ColorKey(This,ColorKey)	\
    ( (This)->lpVtbl -> get_ColorKey(This,ColorKey) ) 

#define IMSVidVRGraphSegment_put_ColorKey(This,ColorKey)	\
    ( (This)->lpVtbl -> put_ColorKey(This,ColorKey) ) 

#define IMSVidVRGraphSegment_get_Source(This,r)	\
    ( (This)->lpVtbl -> get_Source(This,r) ) 

#define IMSVidVRGraphSegment_put_Source(This,r)	\
    ( (This)->lpVtbl -> put_Source(This,r) ) 

#define IMSVidVRGraphSegment_get_Destination(This,r)	\
    ( (This)->lpVtbl -> get_Destination(This,r) ) 

#define IMSVidVRGraphSegment_put_Destination(This,r)	\
    ( (This)->lpVtbl -> put_Destination(This,r) ) 

#define IMSVidVRGraphSegment_get_NativeSize(This,sizeval,aspectratio)	\
    ( (This)->lpVtbl -> get_NativeSize(This,sizeval,aspectratio) ) 

#define IMSVidVRGraphSegment_get_BorderColor(This,color)	\
    ( (This)->lpVtbl -> get_BorderColor(This,color) ) 

#define IMSVidVRGraphSegment_put_BorderColor(This,color)	\
    ( (This)->lpVtbl -> put_BorderColor(This,color) ) 

#define IMSVidVRGraphSegment_get_MaintainAspectRatio(This,fMaintain)	\
    ( (This)->lpVtbl -> get_MaintainAspectRatio(This,fMaintain) ) 

#define IMSVidVRGraphSegment_put_MaintainAspectRatio(This,fMaintain)	\
    ( (This)->lpVtbl -> put_MaintainAspectRatio(This,fMaintain) ) 

#define IMSVidVRGraphSegment_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IMSVidVRGraphSegment_DisplayChange(This)	\
    ( (This)->lpVtbl -> DisplayChange(This) ) 

#define IMSVidVRGraphSegment_RePaint(This,hdc)	\
    ( (This)->lpVtbl -> RePaint(This,hdc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVRGraphSegment_INTERFACE_DEFINED__ */


#ifndef __IMSVidDevice_INTERFACE_DEFINED__
#define __IMSVidDevice_INTERFACE_DEFINED__

/* interface IMSVidDevice */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D47C-911D-11d2-B632-00C04F79498E")
    IMSVidDevice : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ __RPC__out long *Status) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Power( 
            /* [in] */ VARIANT_BOOL Power) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Power( 
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Category( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ClassID( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__Category( 
            /* [retval][out] */ __RPC__out GUID *Guid) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__ClassID( 
            /* [retval][out] */ __RPC__out GUID *Clsid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEqualDevice( 
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidDevice * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidDevice * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidDevice * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidDevice * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        END_INTERFACE
    } IMSVidDeviceVtbl;

    interface IMSVidDevice
    {
        CONST_VTBL struct IMSVidDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidDevice_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidDevice_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidDevice_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidDevice_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidDevice_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidDevice_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidDevice_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidDevice_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidDevice_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidDevice_INTERFACE_DEFINED__ */


#ifndef __IMSVidDevice2_INTERFACE_DEFINED__
#define __IMSVidDevice2_INTERFACE_DEFINED__

/* interface IMSVidDevice2 */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidDevice2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87BD2783-EBC0-478C-B4A0-E8E7F43AB78E")
    IMSVidDevice2 : public IUnknown
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DevicePath( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *DevPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidDevice2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidDevice2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidDevice2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidDevice2 * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DevicePath )( 
            IMSVidDevice2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *DevPath);
        
        END_INTERFACE
    } IMSVidDevice2Vtbl;

    interface IMSVidDevice2
    {
        CONST_VTBL struct IMSVidDevice2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidDevice2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidDevice2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidDevice2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidDevice2_get_DevicePath(This,DevPath)	\
    ( (This)->lpVtbl -> get_DevicePath(This,DevPath) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidDevice2_INTERFACE_DEFINED__ */


#ifndef __IMSVidInputDevice_INTERFACE_DEFINED__
#define __IMSVidInputDevice_INTERFACE_DEFINED__

/* interface IMSVidInputDevice */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidInputDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B0353D-A4C8-11d2-B634-00C04F79498E")
    IMSVidInputDevice : public IMSVidDevice
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsViewable( 
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE View( 
            /* [in] */ __RPC__in VARIANT *v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidInputDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidInputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidInputDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidInputDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidInputDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidInputDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidInputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidInputDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidInputDevice * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidInputDevice * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidInputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidInputDevice * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidInputDevice * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidInputDevice * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        END_INTERFACE
    } IMSVidInputDeviceVtbl;

    interface IMSVidInputDevice
    {
        CONST_VTBL struct IMSVidInputDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidInputDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidInputDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidInputDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidInputDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidInputDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidInputDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidInputDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidInputDevice_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidInputDevice_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidInputDevice_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidInputDevice_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidInputDevice_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidInputDevice_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidInputDevice_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidInputDevice_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidInputDevice_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidInputDevice_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidInputDevice_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidInputDevice_INTERFACE_DEFINED__ */


#ifndef __IMSVidDeviceEvent_INTERFACE_DEFINED__
#define __IMSVidDeviceEvent_INTERFACE_DEFINED__

/* interface IMSVidDeviceEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidDeviceEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D480-911D-11d2-B632-00C04F79498E")
    IMSVidDeviceEvent : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StateChange( 
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidDeviceEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidDeviceEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidDeviceEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidDeviceEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidDeviceEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidDeviceEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidDeviceEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        END_INTERFACE
    } IMSVidDeviceEventVtbl;

    interface IMSVidDeviceEvent
    {
        CONST_VTBL struct IMSVidDeviceEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidDeviceEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidDeviceEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidDeviceEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidDeviceEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidDeviceEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidDeviceEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidDeviceEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidDeviceEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidDeviceEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidInputDeviceEvent_INTERFACE_DEFINED__
#define __IMSVidInputDeviceEvent_INTERFACE_DEFINED__

/* interface IMSVidInputDeviceEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidInputDeviceEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B0353E-A4C8-11d2-B634-00C04F79498E")
    IMSVidInputDeviceEvent : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidInputDeviceEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidInputDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidInputDeviceEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidInputDeviceEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidInputDeviceEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidInputDeviceEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidInputDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidInputDeviceEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMSVidInputDeviceEventVtbl;

    interface IMSVidInputDeviceEvent
    {
        CONST_VTBL struct IMSVidInputDeviceEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidInputDeviceEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidInputDeviceEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidInputDeviceEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidInputDeviceEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidInputDeviceEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidInputDeviceEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidInputDeviceEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidInputDeviceEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidVideoInputDevice_INTERFACE_DEFINED__
#define __IMSVidVideoInputDevice_INTERFACE_DEFINED__

/* interface IMSVidVideoInputDevice */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidVideoInputDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D47F-911D-11d2-B632-00C04F79498E")
    IMSVidVideoInputDevice : public IMSVidInputDevice
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoInputDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoInputDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoInputDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoInputDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidVideoInputDevice * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidVideoInputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidVideoInputDevice * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        END_INTERFACE
    } IMSVidVideoInputDeviceVtbl;

    interface IMSVidVideoInputDevice
    {
        CONST_VTBL struct IMSVidVideoInputDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoInputDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoInputDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoInputDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoInputDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoInputDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoInputDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoInputDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoInputDevice_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidVideoInputDevice_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidVideoInputDevice_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidVideoInputDevice_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidVideoInputDevice_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidVideoInputDevice_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidVideoInputDevice_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidVideoInputDevice_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidVideoInputDevice_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidVideoInputDevice_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidVideoInputDevice_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoInputDevice_INTERFACE_DEFINED__ */


#ifndef __IMSVidPlayback_INTERFACE_DEFINED__
#define __IMSVidPlayback_INTERFACE_DEFINED__

/* interface IMSVidPlayback */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidPlayback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03538-A4C8-11d2-B634-00C04F79498E")
    IMSVidPlayback : public IMSVidInputDevice
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableResetOnStop( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableResetOnStop( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CanStep( 
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Step( 
            /* [in] */ long lStep) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Rate( 
            /* [in] */ double plRate) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rate( 
            /* [retval][out] */ __RPC__out double *plRate) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentPosition( 
            /* [in] */ long lPosition) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentPosition( 
            /* [retval][out] */ __RPC__out long *lPosition) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PositionMode( 
            /* [in] */ PositionModeList lPositionMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PositionMode( 
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ __RPC__out long *lLength) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidPlaybackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidPlayback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidPlayback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidPlayback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidPlayback * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidPlayback * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidPlayback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidPlayback * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidPlayback * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidPlayback * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidPlayback * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidPlayback * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidPlayback * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidPlayback * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidPlayback * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidPlayback * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidPlayback * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidPlayback * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidPlayback * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidPlayback * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidPlayback * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidPlayback * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidPlayback * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        END_INTERFACE
    } IMSVidPlaybackVtbl;

    interface IMSVidPlayback
    {
        CONST_VTBL struct IMSVidPlaybackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidPlayback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidPlayback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidPlayback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidPlayback_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidPlayback_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidPlayback_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidPlayback_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidPlayback_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidPlayback_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidPlayback_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidPlayback_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidPlayback_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidPlayback_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidPlayback_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidPlayback_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidPlayback_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidPlayback_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidPlayback_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidPlayback_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidPlayback_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidPlayback_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidPlayback_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidPlayback_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidPlayback_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidPlayback_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidPlayback_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidPlayback_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidPlayback_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidPlayback_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidPlayback_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidPlayback_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidPlayback_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidPlayback_INTERFACE_DEFINED__ */


#ifndef __IMSVidPlaybackEvent_INTERFACE_DEFINED__
#define __IMSVidPlaybackEvent_INTERFACE_DEFINED__

/* interface IMSVidPlaybackEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidPlaybackEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B0353B-A4C8-11d2-B634-00C04F79498E")
    IMSVidPlaybackEvent : public IMSVidInputDeviceEvent
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndOfMedia( 
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidPlaybackEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidPlaybackEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidPlaybackEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidPlaybackEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidPlaybackEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidPlaybackEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidPlaybackEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidPlaybackEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidPlaybackEvent * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        END_INTERFACE
    } IMSVidPlaybackEventVtbl;

    interface IMSVidPlaybackEvent
    {
        CONST_VTBL struct IMSVidPlaybackEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidPlaybackEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidPlaybackEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidPlaybackEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidPlaybackEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidPlaybackEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidPlaybackEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidPlaybackEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidPlaybackEvent_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidPlaybackEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidTuner_INTERFACE_DEFINED__
#define __IMSVidTuner_INTERFACE_DEFINED__

/* interface IMSVidTuner */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidTuner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D47D-911D-11d2-B632-00C04F79498E")
    IMSVidTuner : public IMSVidVideoInputDevice
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Tune( 
            /* [retval][out] */ __RPC__deref_out_opt ITuneRequest **ppTR) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Tune( 
            /* [in] */ __RPC__in_opt ITuneRequest *pTR) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TuningSpace( 
            /* [retval][out] */ __RPC__deref_out_opt ITuningSpace **plTS) = 0;
        
        virtual /* [id][propput][restricted][hidden] */ HRESULT STDMETHODCALLTYPE put_TuningSpace( 
            /* [in] */ __RPC__in_opt ITuningSpace *plTS) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidTunerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidTuner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidTuner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidTuner * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidTuner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidTuner * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidTuner * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidTuner * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tune )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuneRequest **ppTR);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tune )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in_opt ITuneRequest *pTR);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TuningSpace )( 
            IMSVidTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuningSpace **plTS);
        
        /* [id][propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_TuningSpace )( 
            IMSVidTuner * This,
            /* [in] */ __RPC__in_opt ITuningSpace *plTS);
        
        END_INTERFACE
    } IMSVidTunerVtbl;

    interface IMSVidTuner
    {
        CONST_VTBL struct IMSVidTunerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidTuner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidTuner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidTuner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidTuner_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidTuner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidTuner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidTuner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidTuner_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidTuner_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidTuner_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidTuner_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidTuner_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidTuner_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidTuner_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidTuner_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidTuner_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidTuner_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidTuner_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 



#define IMSVidTuner_get_Tune(This,ppTR)	\
    ( (This)->lpVtbl -> get_Tune(This,ppTR) ) 

#define IMSVidTuner_put_Tune(This,pTR)	\
    ( (This)->lpVtbl -> put_Tune(This,pTR) ) 

#define IMSVidTuner_get_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> get_TuningSpace(This,plTS) ) 

#define IMSVidTuner_put_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> put_TuningSpace(This,plTS) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidTuner_INTERFACE_DEFINED__ */


#ifndef __IMSVidTunerEvent_INTERFACE_DEFINED__
#define __IMSVidTunerEvent_INTERFACE_DEFINED__

/* interface IMSVidTunerEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidTunerEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D485-911D-11d2-B632-00C04F79498E")
    IMSVidTunerEvent : public IMSVidInputDeviceEvent
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TuneChanged( 
            /* [in] */ __RPC__in_opt IMSVidTuner *lpd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidTunerEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidTunerEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidTunerEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidTunerEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidTunerEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidTunerEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidTunerEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidTunerEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TuneChanged )( 
            IMSVidTunerEvent * This,
            /* [in] */ __RPC__in_opt IMSVidTuner *lpd);
        
        END_INTERFACE
    } IMSVidTunerEventVtbl;

    interface IMSVidTunerEvent
    {
        CONST_VTBL struct IMSVidTunerEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidTunerEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidTunerEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidTunerEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidTunerEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidTunerEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidTunerEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidTunerEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidTunerEvent_TuneChanged(This,lpd)	\
    ( (This)->lpVtbl -> TuneChanged(This,lpd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidTunerEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidAnalogTuner_INTERFACE_DEFINED__
#define __IMSVidAnalogTuner_INTERFACE_DEFINED__

/* interface IMSVidAnalogTuner */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidAnalogTuner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D47E-911D-11d2-B632-00C04F79498E")
    IMSVidAnalogTuner : public IMSVidTuner
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Channel( 
            /* [retval][out] */ __RPC__out long *Channel) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Channel( 
            /* [in] */ long Channel) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoFrequency( 
            /* [out][retval] */ __RPC__out long *lcc) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioFrequency( 
            /* [out][retval] */ __RPC__out long *lcc) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CountryCode( 
            /* [out][retval] */ __RPC__out long *lcc) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CountryCode( 
            /* [in] */ long lcc) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SAP( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfSapOn) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SAP( 
            /* [in] */ VARIANT_BOOL fSapOn) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChannelAvailable( 
            /* [in] */ long nChannel,
            /* [out] */ __RPC__out long *SignalStrength,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *fSignalPresent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAnalogTunerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAnalogTuner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAnalogTuner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAnalogTuner * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAnalogTuner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAnalogTuner * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidAnalogTuner * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidAnalogTuner * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tune )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuneRequest **ppTR);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tune )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in_opt ITuneRequest *pTR);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TuningSpace )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuningSpace **plTS);
        
        /* [id][propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_TuningSpace )( 
            IMSVidAnalogTuner * This,
            /* [in] */ __RPC__in_opt ITuningSpace *plTS);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channel )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__out long *Channel);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Channel )( 
            IMSVidAnalogTuner * This,
            /* [in] */ long Channel);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFrequency )( 
            IMSVidAnalogTuner * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioFrequency )( 
            IMSVidAnalogTuner * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CountryCode )( 
            IMSVidAnalogTuner * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CountryCode )( 
            IMSVidAnalogTuner * This,
            /* [in] */ long lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SAP )( 
            IMSVidAnalogTuner * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfSapOn);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SAP )( 
            IMSVidAnalogTuner * This,
            /* [in] */ VARIANT_BOOL fSapOn);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ChannelAvailable )( 
            IMSVidAnalogTuner * This,
            /* [in] */ long nChannel,
            /* [out] */ __RPC__out long *SignalStrength,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *fSignalPresent);
        
        END_INTERFACE
    } IMSVidAnalogTunerVtbl;

    interface IMSVidAnalogTuner
    {
        CONST_VTBL struct IMSVidAnalogTunerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAnalogTuner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAnalogTuner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAnalogTuner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAnalogTuner_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAnalogTuner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAnalogTuner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAnalogTuner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidAnalogTuner_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidAnalogTuner_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidAnalogTuner_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidAnalogTuner_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidAnalogTuner_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidAnalogTuner_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidAnalogTuner_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidAnalogTuner_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidAnalogTuner_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidAnalogTuner_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidAnalogTuner_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 



#define IMSVidAnalogTuner_get_Tune(This,ppTR)	\
    ( (This)->lpVtbl -> get_Tune(This,ppTR) ) 

#define IMSVidAnalogTuner_put_Tune(This,pTR)	\
    ( (This)->lpVtbl -> put_Tune(This,pTR) ) 

#define IMSVidAnalogTuner_get_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> get_TuningSpace(This,plTS) ) 

#define IMSVidAnalogTuner_put_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> put_TuningSpace(This,plTS) ) 


#define IMSVidAnalogTuner_get_Channel(This,Channel)	\
    ( (This)->lpVtbl -> get_Channel(This,Channel) ) 

#define IMSVidAnalogTuner_put_Channel(This,Channel)	\
    ( (This)->lpVtbl -> put_Channel(This,Channel) ) 

#define IMSVidAnalogTuner_get_VideoFrequency(This,lcc)	\
    ( (This)->lpVtbl -> get_VideoFrequency(This,lcc) ) 

#define IMSVidAnalogTuner_get_AudioFrequency(This,lcc)	\
    ( (This)->lpVtbl -> get_AudioFrequency(This,lcc) ) 

#define IMSVidAnalogTuner_get_CountryCode(This,lcc)	\
    ( (This)->lpVtbl -> get_CountryCode(This,lcc) ) 

#define IMSVidAnalogTuner_put_CountryCode(This,lcc)	\
    ( (This)->lpVtbl -> put_CountryCode(This,lcc) ) 

#define IMSVidAnalogTuner_get_SAP(This,pfSapOn)	\
    ( (This)->lpVtbl -> get_SAP(This,pfSapOn) ) 

#define IMSVidAnalogTuner_put_SAP(This,fSapOn)	\
    ( (This)->lpVtbl -> put_SAP(This,fSapOn) ) 

#define IMSVidAnalogTuner_ChannelAvailable(This,nChannel,SignalStrength,fSignalPresent)	\
    ( (This)->lpVtbl -> ChannelAvailable(This,nChannel,SignalStrength,fSignalPresent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAnalogTuner_INTERFACE_DEFINED__ */


#ifndef __IMSVidAnalogTuner2_INTERFACE_DEFINED__
#define __IMSVidAnalogTuner2_INTERFACE_DEFINED__

/* interface IMSVidAnalogTuner2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidAnalogTuner2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37647BF7-3DDE-4cc8-A4DC-0D534D3D0037")
    IMSVidAnalogTuner2 : public IMSVidAnalogTuner
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TVFormats( 
            /* [retval][out] */ __RPC__out long *Formats) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TunerModes( 
            /* [retval][out] */ __RPC__out long *Modes) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NumAuxInputs( 
            /* [retval][out] */ __RPC__out long *Inputs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAnalogTuner2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAnalogTuner2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAnalogTuner2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAnalogTuner2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidAnalogTuner2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tune )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuneRequest **ppTR);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tune )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in_opt ITuneRequest *pTR);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TuningSpace )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__deref_out_opt ITuningSpace **plTS);
        
        /* [id][propput][restricted][hidden] */ HRESULT ( STDMETHODCALLTYPE *put_TuningSpace )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ __RPC__in_opt ITuningSpace *plTS);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Channel )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out long *Channel);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Channel )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ long Channel);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoFrequency )( 
            IMSVidAnalogTuner2 * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioFrequency )( 
            IMSVidAnalogTuner2 * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CountryCode )( 
            IMSVidAnalogTuner2 * This,
            /* [out][retval] */ __RPC__out long *lcc);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CountryCode )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ long lcc);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SAP )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfSapOn);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SAP )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ VARIANT_BOOL fSapOn);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ChannelAvailable )( 
            IMSVidAnalogTuner2 * This,
            /* [in] */ long nChannel,
            /* [out] */ __RPC__out long *SignalStrength,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *fSignalPresent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TVFormats )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out long *Formats);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TunerModes )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out long *Modes);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumAuxInputs )( 
            IMSVidAnalogTuner2 * This,
            /* [retval][out] */ __RPC__out long *Inputs);
        
        END_INTERFACE
    } IMSVidAnalogTuner2Vtbl;

    interface IMSVidAnalogTuner2
    {
        CONST_VTBL struct IMSVidAnalogTuner2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAnalogTuner2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAnalogTuner2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAnalogTuner2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAnalogTuner2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAnalogTuner2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAnalogTuner2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAnalogTuner2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidAnalogTuner2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidAnalogTuner2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidAnalogTuner2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidAnalogTuner2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidAnalogTuner2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidAnalogTuner2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidAnalogTuner2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidAnalogTuner2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidAnalogTuner2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidAnalogTuner2_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidAnalogTuner2_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 



#define IMSVidAnalogTuner2_get_Tune(This,ppTR)	\
    ( (This)->lpVtbl -> get_Tune(This,ppTR) ) 

#define IMSVidAnalogTuner2_put_Tune(This,pTR)	\
    ( (This)->lpVtbl -> put_Tune(This,pTR) ) 

#define IMSVidAnalogTuner2_get_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> get_TuningSpace(This,plTS) ) 

#define IMSVidAnalogTuner2_put_TuningSpace(This,plTS)	\
    ( (This)->lpVtbl -> put_TuningSpace(This,plTS) ) 


#define IMSVidAnalogTuner2_get_Channel(This,Channel)	\
    ( (This)->lpVtbl -> get_Channel(This,Channel) ) 

#define IMSVidAnalogTuner2_put_Channel(This,Channel)	\
    ( (This)->lpVtbl -> put_Channel(This,Channel) ) 

#define IMSVidAnalogTuner2_get_VideoFrequency(This,lcc)	\
    ( (This)->lpVtbl -> get_VideoFrequency(This,lcc) ) 

#define IMSVidAnalogTuner2_get_AudioFrequency(This,lcc)	\
    ( (This)->lpVtbl -> get_AudioFrequency(This,lcc) ) 

#define IMSVidAnalogTuner2_get_CountryCode(This,lcc)	\
    ( (This)->lpVtbl -> get_CountryCode(This,lcc) ) 

#define IMSVidAnalogTuner2_put_CountryCode(This,lcc)	\
    ( (This)->lpVtbl -> put_CountryCode(This,lcc) ) 

#define IMSVidAnalogTuner2_get_SAP(This,pfSapOn)	\
    ( (This)->lpVtbl -> get_SAP(This,pfSapOn) ) 

#define IMSVidAnalogTuner2_put_SAP(This,fSapOn)	\
    ( (This)->lpVtbl -> put_SAP(This,fSapOn) ) 

#define IMSVidAnalogTuner2_ChannelAvailable(This,nChannel,SignalStrength,fSignalPresent)	\
    ( (This)->lpVtbl -> ChannelAvailable(This,nChannel,SignalStrength,fSignalPresent) ) 


#define IMSVidAnalogTuner2_get_TVFormats(This,Formats)	\
    ( (This)->lpVtbl -> get_TVFormats(This,Formats) ) 

#define IMSVidAnalogTuner2_get_TunerModes(This,Modes)	\
    ( (This)->lpVtbl -> get_TunerModes(This,Modes) ) 

#define IMSVidAnalogTuner2_get_NumAuxInputs(This,Inputs)	\
    ( (This)->lpVtbl -> get_NumAuxInputs(This,Inputs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAnalogTuner2_INTERFACE_DEFINED__ */


#ifndef __IMSVidAnalogTunerEvent_INTERFACE_DEFINED__
#define __IMSVidAnalogTunerEvent_INTERFACE_DEFINED__

/* interface IMSVidAnalogTunerEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidAnalogTunerEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C15D486-911D-11d2-B632-00C04F79498E")
    IMSVidAnalogTunerEvent : public IMSVidTunerEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAnalogTunerEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAnalogTunerEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAnalogTunerEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAnalogTunerEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAnalogTunerEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAnalogTunerEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAnalogTunerEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAnalogTunerEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TuneChanged )( 
            IMSVidAnalogTunerEvent * This,
            /* [in] */ __RPC__in_opt IMSVidTuner *lpd);
        
        END_INTERFACE
    } IMSVidAnalogTunerEventVtbl;

    interface IMSVidAnalogTunerEvent
    {
        CONST_VTBL struct IMSVidAnalogTunerEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAnalogTunerEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAnalogTunerEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAnalogTunerEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAnalogTunerEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAnalogTunerEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAnalogTunerEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAnalogTunerEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidAnalogTunerEvent_TuneChanged(This,lpd)	\
    ( (This)->lpVtbl -> TuneChanged(This,lpd) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAnalogTunerEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidFilePlayback_INTERFACE_DEFINED__
#define __IMSVidFilePlayback_INTERFACE_DEFINED__

/* interface IMSVidFilePlayback */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidFilePlayback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03539-A4C8-11d2-B634-00C04F79498E")
    IMSVidFilePlayback : public IMSVidPlayback
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FileName( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FileName) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FileName( 
            /* [in] */ __RPC__in BSTR FileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFilePlaybackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFilePlayback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFilePlayback * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFilePlayback * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFilePlayback * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFilePlayback * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidFilePlayback * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidFilePlayback * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidFilePlayback * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidFilePlayback * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidFilePlayback * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidFilePlayback * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidFilePlayback * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidFilePlayback * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidFilePlayback * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidFilePlayback * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidFilePlayback * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IMSVidFilePlayback * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FileName);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            IMSVidFilePlayback * This,
            /* [in] */ __RPC__in BSTR FileName);
        
        END_INTERFACE
    } IMSVidFilePlaybackVtbl;

    interface IMSVidFilePlayback
    {
        CONST_VTBL struct IMSVidFilePlaybackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFilePlayback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFilePlayback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFilePlayback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFilePlayback_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFilePlayback_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFilePlayback_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFilePlayback_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidFilePlayback_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidFilePlayback_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidFilePlayback_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidFilePlayback_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidFilePlayback_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidFilePlayback_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidFilePlayback_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidFilePlayback_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidFilePlayback_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidFilePlayback_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidFilePlayback_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidFilePlayback_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidFilePlayback_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidFilePlayback_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidFilePlayback_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidFilePlayback_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidFilePlayback_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidFilePlayback_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidFilePlayback_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidFilePlayback_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidFilePlayback_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidFilePlayback_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidFilePlayback_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidFilePlayback_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidFilePlayback_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 


#define IMSVidFilePlayback_get_FileName(This,FileName)	\
    ( (This)->lpVtbl -> get_FileName(This,FileName) ) 

#define IMSVidFilePlayback_put_FileName(This,FileName)	\
    ( (This)->lpVtbl -> put_FileName(This,FileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFilePlayback_INTERFACE_DEFINED__ */


#ifndef __IMSVidFilePlayback2_INTERFACE_DEFINED__
#define __IMSVidFilePlayback2_INTERFACE_DEFINED__

/* interface IMSVidFilePlayback2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidFilePlayback2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F7E44AF-6E52-4660-BC08-D8D542587D72")
    IMSVidFilePlayback2 : public IMSVidFilePlayback
    {
    public:
        virtual /* [id][hidden][propput] */ HRESULT STDMETHODCALLTYPE put__SourceFilter( 
            /* [in] */ __RPC__in BSTR FileName) = 0;
        
        virtual /* [id][hidden][propput] */ HRESULT STDMETHODCALLTYPE put___SourceFilter( 
            /* [in] */ GUID FileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFilePlayback2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFilePlayback2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFilePlayback2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFilePlayback2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidFilePlayback2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidFilePlayback2 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidFilePlayback2 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidFilePlayback2 * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IMSVidFilePlayback2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FileName);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in BSTR FileName);
        
        /* [id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__SourceFilter )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ __RPC__in BSTR FileName);
        
        /* [id][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put___SourceFilter )( 
            IMSVidFilePlayback2 * This,
            /* [in] */ GUID FileName);
        
        END_INTERFACE
    } IMSVidFilePlayback2Vtbl;

    interface IMSVidFilePlayback2
    {
        CONST_VTBL struct IMSVidFilePlayback2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFilePlayback2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFilePlayback2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFilePlayback2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFilePlayback2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFilePlayback2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFilePlayback2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFilePlayback2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidFilePlayback2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidFilePlayback2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidFilePlayback2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidFilePlayback2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidFilePlayback2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidFilePlayback2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidFilePlayback2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidFilePlayback2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidFilePlayback2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidFilePlayback2_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidFilePlayback2_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidFilePlayback2_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidFilePlayback2_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidFilePlayback2_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidFilePlayback2_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidFilePlayback2_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidFilePlayback2_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidFilePlayback2_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidFilePlayback2_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidFilePlayback2_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidFilePlayback2_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidFilePlayback2_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidFilePlayback2_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidFilePlayback2_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidFilePlayback2_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 


#define IMSVidFilePlayback2_get_FileName(This,FileName)	\
    ( (This)->lpVtbl -> get_FileName(This,FileName) ) 

#define IMSVidFilePlayback2_put_FileName(This,FileName)	\
    ( (This)->lpVtbl -> put_FileName(This,FileName) ) 


#define IMSVidFilePlayback2_put__SourceFilter(This,FileName)	\
    ( (This)->lpVtbl -> put__SourceFilter(This,FileName) ) 

#define IMSVidFilePlayback2_put___SourceFilter(This,FileName)	\
    ( (This)->lpVtbl -> put___SourceFilter(This,FileName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFilePlayback2_INTERFACE_DEFINED__ */


#ifndef __IMSVidFilePlaybackEvent_INTERFACE_DEFINED__
#define __IMSVidFilePlaybackEvent_INTERFACE_DEFINED__

/* interface IMSVidFilePlaybackEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidFilePlaybackEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B0353A-A4C8-11d2-B634-00C04F79498E")
    IMSVidFilePlaybackEvent : public IMSVidPlaybackEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFilePlaybackEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFilePlaybackEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFilePlaybackEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFilePlaybackEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFilePlaybackEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFilePlaybackEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFilePlaybackEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFilePlaybackEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidFilePlaybackEvent * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        END_INTERFACE
    } IMSVidFilePlaybackEventVtbl;

    interface IMSVidFilePlaybackEvent
    {
        CONST_VTBL struct IMSVidFilePlaybackEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFilePlaybackEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFilePlaybackEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFilePlaybackEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFilePlaybackEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFilePlaybackEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFilePlaybackEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFilePlaybackEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidFilePlaybackEvent_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFilePlaybackEvent_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_segment_0000_0023 */
/* [local] */ 

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0023_0001
    {	dvdMenu_Title	= 2,
	dvdMenu_Root	= ( dvdMenu_Title + 1 ) ,
	dvdMenu_Subpicture	= ( dvdMenu_Root + 1 ) ,
	dvdMenu_Audio	= ( dvdMenu_Subpicture + 1 ) ,
	dvdMenu_Angle	= ( dvdMenu_Audio + 1 ) ,
	dvdMenu_Chapter	= ( dvdMenu_Angle + 1 ) 
    } 	DVDMenuIDConstants;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_segment_0000_0023_0002
    {	dvdState_Undefined	= -2,
	dvdState_Unitialized	= ( dvdState_Undefined + 1 ) ,
	dvdState_Stopped	= ( dvdState_Unitialized + 1 ) ,
	dvdState_Paused	= ( dvdState_Stopped + 1 ) ,
	dvdState_Running	= ( dvdState_Paused + 1 ) 
    } 	DVDFilterState;

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0023_0003
    {	dvdStruct_Volume	= 0x1,
	dvdStruct_Title	= 0x2,
	dvdStruct_ParentalID	= 0x3,
	dvdStruct_PartOfTitle	= 0x4,
	dvdStruct_Cell	= 0x5,
	dvdStream_Audio	= 0x10,
	dvdStream_Subpicture	= 0x11,
	dvdStream_Angle	= 0x12,
	dvdChannel_Audio	= 0x20,
	dvdGeneral_Name	= 0x30,
	dvdGeneral_Comments	= 0x31,
	dvdTitle_Series	= 0x38,
	dvdTitle_Movie	= 0x39,
	dvdTitle_Video	= 0x3a,
	dvdTitle_Album	= 0x3b,
	dvdTitle_Song	= 0x3c,
	dvdTitle_Other	= 0x3f,
	dvdTitle_Sub_Series	= 0x40,
	dvdTitle_Sub_Movie	= 0x41,
	dvdTitle_Sub_Video	= 0x42,
	dvdTitle_Sub_Album	= 0x43,
	dvdTitle_Sub_Song	= 0x44,
	dvdTitle_Sub_Other	= 0x47,
	dvdTitle_Orig_Series	= 0x48,
	dvdTitle_Orig_Movie	= 0x49,
	dvdTitle_Orig_Video	= 0x4a,
	dvdTitle_Orig_Album	= 0x4b,
	dvdTitle_Orig_Song	= 0x4c,
	dvdTitle_Orig_Other	= 0x4f,
	dvdOther_Scene	= 0x50,
	dvdOther_Cut	= 0x51,
	dvdOther_Take	= 0x52
    } 	DVDTextStringType;

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0023_0004
    {	dvdSPExt_NotSpecified	= 0,
	dvdSPExt_Caption_Normal	= 1,
	dvdSPExt_Caption_Big	= 2,
	dvdSPExt_Caption_Children	= 3,
	dvdSPExt_CC_Normal	= 5,
	dvdSPExt_CC_Big	= 6,
	dvdSPExt_CC_Children	= 7,
	dvdSPExt_Forced	= 9,
	dvdSPExt_DirectorComments_Normal	= 13,
	dvdSPExt_DirectorComments_Big	= 14,
	dvdSPExt_DirectorComments_Children	= 15
    } 	DVDSPExt;



extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0023_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0023_v0_0_s_ifspec;

#ifndef __IMSVidWebDVD_INTERFACE_DEFINED__
#define __IMSVidWebDVD_INTERFACE_DEFINED__

/* interface IMSVidWebDVD */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidWebDVD;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF45F88B-AC56-4EE2-A73A-ED04E2885D3C")
    IMSVidWebDVD : public IMSVidPlayback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDVDEvent( 
            /* [in] */ long lEvent,
            /* [in] */ LONG_PTR lParam1,
            /* [in] */ LONG_PTR lParam2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayTitle( 
            /* [in] */ long lTitle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayChapterInTitle( 
            /* [in] */ long lTitle,
            /* [in] */ long lChapter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayChapter( 
            /* [in] */ long lChapter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayChaptersAutoStop( 
            /* [in] */ long lTitle,
            /* [in] */ long lstrChapter,
            /* [in] */ long lChapterCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayAtTime( 
            /* [in] */ __RPC__in BSTR strTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayAtTimeInTitle( 
            /* [in] */ long lTitle,
            /* [in] */ __RPC__in BSTR strTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayPeriodInTitleAutoStop( 
            /* [in] */ long lTitle,
            /* [in] */ __RPC__in BSTR strStartTime,
            /* [in] */ __RPC__in BSTR strEndTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReplayChapter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayPrevChapter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayNextChapter( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StillOff( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioLanguage( 
            /* [in] */ long lStream,
            /* [defaultvalue][in] */ VARIANT_BOOL fFormat,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *strAudioLang) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowMenu( 
            /* [in] */ DVDMenuIDConstants MenuID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnFromSubmenu( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonsAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentButton( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAndActivateButton( 
            /* [in] */ long lButton) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ActivateButton( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectRightButton( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectLeftButton( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectLowerButton( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectUpperButton( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ActivateAtPosition( 
            /* [in] */ long xPos,
            /* [in] */ long yPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAtPosition( 
            /* [in] */ long xPos,
            /* [in] */ long yPos) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonAtPosition( 
            /* [in] */ long xPos,
            /* [in] */ long yPos,
            /* [retval][out] */ __RPC__out long *plButton) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfChapters( 
            /* [in] */ long lTitle,
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalTitleTime( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TitlesAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VolumesAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentVolume( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDiscSide( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDomain( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentChapter( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentTitle( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentTime( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DVDTimeCode2bstr( 
            /* [in] */ long timeCode,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pTimeStr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDDirectory( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DVDDirectory( 
            /* [in] */ __RPC__in BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSubpictureStreamEnabled( 
            /* [in] */ long lstream,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsAudioStreamEnabled( 
            /* [in] */ long lstream,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fEnabled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentSubpictureStream( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentSubpictureStream( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubpictureLanguage( 
            long lStream,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *strLanguage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAudioStream( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentAudioStream( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioStreamsAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AnglesAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAngle( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CurrentAngle( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubpictureStreamsAvailable( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubpictureOn( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SubpictureOn( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDUniqueID( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AcceptParentalLevelChange( 
            /* [in] */ VARIANT_BOOL fAccept,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NotifyParentalLevelChange( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectParentalCountry( 
            /* [in] */ long lCountry,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectParentalLevel( 
            /* [in] */ long lParentalLevel,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TitleParentalLevels( 
            /* [in] */ long lTitle,
            /* [retval][out] */ __RPC__out long *plParentalLevels) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayerParentalCountry( 
            /* [retval][out] */ __RPC__out long *plCountryCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlayerParentalLevel( 
            /* [retval][out] */ __RPC__out long *plParentalLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eject( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UOPValid( 
            /* [in] */ long lUOP,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfValid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SPRM( 
            /* [in] */ long lIndex,
            /* [retval][out] */ __RPC__out short *psSPRM) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GPRM( 
            /* [in] */ long lIndex,
            /* [retval][out] */ __RPC__out short *psSPRM) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GPRM( 
            /* [in] */ long lIndex,
            /* [in] */ short sValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDTextStringType( 
            /* [in] */ long lLangIndex,
            /* [in] */ long lStringIndex,
            /* [retval][out] */ __RPC__out DVDTextStringType *pType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDTextString( 
            /* [in] */ long lLangIndex,
            /* [in] */ long lStringIndex,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDTextNumberOfStrings( 
            /* [in] */ long lLangIndex,
            /* [retval][out] */ __RPC__out long *plNumOfStrings) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDTextNumberOfLanguages( 
            /* [retval][out] */ __RPC__out long *plNumOfLangs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDTextLanguageLCID( 
            /* [in] */ long lLangIndex,
            /* [retval][out] */ __RPC__out long *lcid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegionChange( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDAdm( 
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteBookmark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RestoreBookmark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveBookmark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectDefaultAudioLanguage( 
            /* [in] */ long lang,
            /* [in] */ long ext) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectDefaultSubpictureLanguage( 
            /* [in] */ long lang,
            /* [in] */ DVDSPExt ext) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PreferredSubpictureStream( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultMenuLanguage( 
            /* [retval][out] */ __RPC__out long *lang) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultMenuLanguage( 
            /* [in] */ long lang) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSubpictureLanguage( 
            /* [retval][out] */ __RPC__out long *lang) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultAudioLanguage( 
            /* [retval][out] */ __RPC__out long *lang) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSubpictureLanguageExt( 
            /* [retval][out] */ __RPC__out DVDSPExt *ext) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultAudioLanguageExt( 
            /* [retval][out] */ __RPC__out long *ext) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageFromLCID( 
            /* [in] */ long lcid,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *lang) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KaraokeAudioPresentationMode( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_KaraokeAudioPresentationMode( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KaraokeChannelContent( 
            /* [in] */ long lStream,
            /* [in] */ long lChan,
            /* [retval][out] */ __RPC__out long *lContent) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KaraokeChannelAssignment( 
            /* [in] */ long lStream,
            /* [retval][out] */ __RPC__out long *lChannelAssignment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RestorePreferredSettings( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonRect( 
            /* [in] */ long lButton,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DVDScreenInMouseCoordinates( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppRect) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DVDScreenInMouseCoordinates( 
            /* [in] */ __RPC__in_opt IMSVidRect *pRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidWebDVDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidWebDVD * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidWebDVD * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidWebDVD * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidWebDVD * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidWebDVD * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidWebDVD * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidWebDVD * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidWebDVD * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidWebDVD * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidWebDVD * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidWebDVD * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidWebDVD * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidWebDVD * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        HRESULT ( STDMETHODCALLTYPE *OnDVDEvent )( 
            IMSVidWebDVD * This,
            /* [in] */ long lEvent,
            /* [in] */ LONG_PTR lParam1,
            /* [in] */ LONG_PTR lParam2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayTitle )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayChapterInTitle )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [in] */ long lChapter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayChapter )( 
            IMSVidWebDVD * This,
            /* [in] */ long lChapter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayChaptersAutoStop )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [in] */ long lstrChapter,
            /* [in] */ long lChapterCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayAtTime )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in BSTR strTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayAtTimeInTitle )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [in] */ __RPC__in BSTR strTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayPeriodInTitleAutoStop )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [in] */ __RPC__in BSTR strStartTime,
            /* [in] */ __RPC__in BSTR strEndTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReplayChapter )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayPrevChapter )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayNextChapter )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StillOff )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioLanguage )( 
            IMSVidWebDVD * This,
            /* [in] */ long lStream,
            /* [defaultvalue][in] */ VARIANT_BOOL fFormat,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *strAudioLang);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowMenu )( 
            IMSVidWebDVD * This,
            /* [in] */ DVDMenuIDConstants MenuID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnFromSubmenu )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonsAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentButton )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAndActivateButton )( 
            IMSVidWebDVD * This,
            /* [in] */ long lButton);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ActivateButton )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectRightButton )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectLeftButton )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectLowerButton )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectUpperButton )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ActivateAtPosition )( 
            IMSVidWebDVD * This,
            /* [in] */ long xPos,
            /* [in] */ long yPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAtPosition )( 
            IMSVidWebDVD * This,
            /* [in] */ long xPos,
            /* [in] */ long yPos);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonAtPosition )( 
            IMSVidWebDVD * This,
            /* [in] */ long xPos,
            /* [in] */ long yPos,
            /* [retval][out] */ __RPC__out long *plButton);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfChapters )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalTitleTime )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TitlesAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VolumesAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentVolume )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDiscSide )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDomain )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentChapter )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentTitle )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentTime )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DVDTimeCode2bstr )( 
            IMSVidWebDVD * This,
            /* [in] */ long timeCode,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pTimeStr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDDirectory )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DVDDirectory )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSubpictureStreamEnabled )( 
            IMSVidWebDVD * This,
            /* [in] */ long lstream,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsAudioStreamEnabled )( 
            IMSVidWebDVD * This,
            /* [in] */ long lstream,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *fEnabled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentSubpictureStream )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentSubpictureStream )( 
            IMSVidWebDVD * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubpictureLanguage )( 
            IMSVidWebDVD * This,
            long lStream,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *strLanguage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentAudioStream )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentAudioStream )( 
            IMSVidWebDVD * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioStreamsAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AnglesAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentAngle )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentAngle )( 
            IMSVidWebDVD * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubpictureStreamsAvailable )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubpictureOn )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SubpictureOn )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDUniqueID )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AcceptParentalLevelChange )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL fAccept,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NotifyParentalLevelChange )( 
            IMSVidWebDVD * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectParentalCountry )( 
            IMSVidWebDVD * This,
            /* [in] */ long lCountry,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectParentalLevel )( 
            IMSVidWebDVD * This,
            /* [in] */ long lParentalLevel,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TitleParentalLevels )( 
            IMSVidWebDVD * This,
            /* [in] */ long lTitle,
            /* [retval][out] */ __RPC__out long *plParentalLevels);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayerParentalCountry )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *plCountryCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlayerParentalLevel )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *plParentalLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eject )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UOPValid )( 
            IMSVidWebDVD * This,
            /* [in] */ long lUOP,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfValid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SPRM )( 
            IMSVidWebDVD * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ __RPC__out short *psSPRM);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GPRM )( 
            IMSVidWebDVD * This,
            /* [in] */ long lIndex,
            /* [retval][out] */ __RPC__out short *psSPRM);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GPRM )( 
            IMSVidWebDVD * This,
            /* [in] */ long lIndex,
            /* [in] */ short sValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDTextStringType )( 
            IMSVidWebDVD * This,
            /* [in] */ long lLangIndex,
            /* [in] */ long lStringIndex,
            /* [retval][out] */ __RPC__out DVDTextStringType *pType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDTextString )( 
            IMSVidWebDVD * This,
            /* [in] */ long lLangIndex,
            /* [in] */ long lStringIndex,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pstrText);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDTextNumberOfStrings )( 
            IMSVidWebDVD * This,
            /* [in] */ long lLangIndex,
            /* [retval][out] */ __RPC__out long *plNumOfStrings);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDTextNumberOfLanguages )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *plNumOfLangs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDTextLanguageLCID )( 
            IMSVidWebDVD * This,
            /* [in] */ long lLangIndex,
            /* [retval][out] */ __RPC__out long *lcid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RegionChange )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDAdm )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteBookmark )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestoreBookmark )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveBookmark )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectDefaultAudioLanguage )( 
            IMSVidWebDVD * This,
            /* [in] */ long lang,
            /* [in] */ long ext);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectDefaultSubpictureLanguage )( 
            IMSVidWebDVD * This,
            /* [in] */ long lang,
            /* [in] */ DVDSPExt ext);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PreferredSubpictureStream )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultMenuLanguage )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *lang);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultMenuLanguage )( 
            IMSVidWebDVD * This,
            /* [in] */ long lang);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSubpictureLanguage )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *lang);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultAudioLanguage )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *lang);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSubpictureLanguageExt )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out DVDSPExt *ext);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultAudioLanguageExt )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *ext);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageFromLCID )( 
            IMSVidWebDVD * This,
            /* [in] */ long lcid,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *lang);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KaraokeAudioPresentationMode )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KaraokeAudioPresentationMode )( 
            IMSVidWebDVD * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KaraokeChannelContent )( 
            IMSVidWebDVD * This,
            /* [in] */ long lStream,
            /* [in] */ long lChan,
            /* [retval][out] */ __RPC__out long *lContent);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KaraokeChannelAssignment )( 
            IMSVidWebDVD * This,
            /* [in] */ long lStream,
            /* [retval][out] */ __RPC__out long *lChannelAssignment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestorePreferredSettings )( 
            IMSVidWebDVD * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ButtonRect )( 
            IMSVidWebDVD * This,
            /* [in] */ long lButton,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DVDScreenInMouseCoordinates )( 
            IMSVidWebDVD * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppRect);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DVDScreenInMouseCoordinates )( 
            IMSVidWebDVD * This,
            /* [in] */ __RPC__in_opt IMSVidRect *pRect);
        
        END_INTERFACE
    } IMSVidWebDVDVtbl;

    interface IMSVidWebDVD
    {
        CONST_VTBL struct IMSVidWebDVDVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidWebDVD_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidWebDVD_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidWebDVD_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidWebDVD_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidWebDVD_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidWebDVD_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidWebDVD_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidWebDVD_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidWebDVD_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidWebDVD_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidWebDVD_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidWebDVD_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidWebDVD_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidWebDVD_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidWebDVD_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidWebDVD_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidWebDVD_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidWebDVD_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidWebDVD_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidWebDVD_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidWebDVD_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidWebDVD_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidWebDVD_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidWebDVD_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidWebDVD_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidWebDVD_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidWebDVD_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidWebDVD_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidWebDVD_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidWebDVD_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidWebDVD_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidWebDVD_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 


#define IMSVidWebDVD_OnDVDEvent(This,lEvent,lParam1,lParam2)	\
    ( (This)->lpVtbl -> OnDVDEvent(This,lEvent,lParam1,lParam2) ) 

#define IMSVidWebDVD_PlayTitle(This,lTitle)	\
    ( (This)->lpVtbl -> PlayTitle(This,lTitle) ) 

#define IMSVidWebDVD_PlayChapterInTitle(This,lTitle,lChapter)	\
    ( (This)->lpVtbl -> PlayChapterInTitle(This,lTitle,lChapter) ) 

#define IMSVidWebDVD_PlayChapter(This,lChapter)	\
    ( (This)->lpVtbl -> PlayChapter(This,lChapter) ) 

#define IMSVidWebDVD_PlayChaptersAutoStop(This,lTitle,lstrChapter,lChapterCount)	\
    ( (This)->lpVtbl -> PlayChaptersAutoStop(This,lTitle,lstrChapter,lChapterCount) ) 

#define IMSVidWebDVD_PlayAtTime(This,strTime)	\
    ( (This)->lpVtbl -> PlayAtTime(This,strTime) ) 

#define IMSVidWebDVD_PlayAtTimeInTitle(This,lTitle,strTime)	\
    ( (This)->lpVtbl -> PlayAtTimeInTitle(This,lTitle,strTime) ) 

#define IMSVidWebDVD_PlayPeriodInTitleAutoStop(This,lTitle,strStartTime,strEndTime)	\
    ( (This)->lpVtbl -> PlayPeriodInTitleAutoStop(This,lTitle,strStartTime,strEndTime) ) 

#define IMSVidWebDVD_ReplayChapter(This)	\
    ( (This)->lpVtbl -> ReplayChapter(This) ) 

#define IMSVidWebDVD_PlayPrevChapter(This)	\
    ( (This)->lpVtbl -> PlayPrevChapter(This) ) 

#define IMSVidWebDVD_PlayNextChapter(This)	\
    ( (This)->lpVtbl -> PlayNextChapter(This) ) 

#define IMSVidWebDVD_StillOff(This)	\
    ( (This)->lpVtbl -> StillOff(This) ) 

#define IMSVidWebDVD_get_AudioLanguage(This,lStream,fFormat,strAudioLang)	\
    ( (This)->lpVtbl -> get_AudioLanguage(This,lStream,fFormat,strAudioLang) ) 

#define IMSVidWebDVD_ShowMenu(This,MenuID)	\
    ( (This)->lpVtbl -> ShowMenu(This,MenuID) ) 

#define IMSVidWebDVD_Resume(This)	\
    ( (This)->lpVtbl -> Resume(This) ) 

#define IMSVidWebDVD_ReturnFromSubmenu(This)	\
    ( (This)->lpVtbl -> ReturnFromSubmenu(This) ) 

#define IMSVidWebDVD_get_ButtonsAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_ButtonsAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentButton(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentButton(This,pVal) ) 

#define IMSVidWebDVD_SelectAndActivateButton(This,lButton)	\
    ( (This)->lpVtbl -> SelectAndActivateButton(This,lButton) ) 

#define IMSVidWebDVD_ActivateButton(This)	\
    ( (This)->lpVtbl -> ActivateButton(This) ) 

#define IMSVidWebDVD_SelectRightButton(This)	\
    ( (This)->lpVtbl -> SelectRightButton(This) ) 

#define IMSVidWebDVD_SelectLeftButton(This)	\
    ( (This)->lpVtbl -> SelectLeftButton(This) ) 

#define IMSVidWebDVD_SelectLowerButton(This)	\
    ( (This)->lpVtbl -> SelectLowerButton(This) ) 

#define IMSVidWebDVD_SelectUpperButton(This)	\
    ( (This)->lpVtbl -> SelectUpperButton(This) ) 

#define IMSVidWebDVD_ActivateAtPosition(This,xPos,yPos)	\
    ( (This)->lpVtbl -> ActivateAtPosition(This,xPos,yPos) ) 

#define IMSVidWebDVD_SelectAtPosition(This,xPos,yPos)	\
    ( (This)->lpVtbl -> SelectAtPosition(This,xPos,yPos) ) 

#define IMSVidWebDVD_get_ButtonAtPosition(This,xPos,yPos,plButton)	\
    ( (This)->lpVtbl -> get_ButtonAtPosition(This,xPos,yPos,plButton) ) 

#define IMSVidWebDVD_get_NumberOfChapters(This,lTitle,pVal)	\
    ( (This)->lpVtbl -> get_NumberOfChapters(This,lTitle,pVal) ) 

#define IMSVidWebDVD_get_TotalTitleTime(This,pVal)	\
    ( (This)->lpVtbl -> get_TotalTitleTime(This,pVal) ) 

#define IMSVidWebDVD_get_TitlesAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_TitlesAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_VolumesAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_VolumesAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentVolume(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentVolume(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentDiscSide(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDiscSide(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDomain(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentChapter(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentChapter(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentTitle(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentTitle(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentTime(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentTime(This,pVal) ) 

#define IMSVidWebDVD_DVDTimeCode2bstr(This,timeCode,pTimeStr)	\
    ( (This)->lpVtbl -> DVDTimeCode2bstr(This,timeCode,pTimeStr) ) 

#define IMSVidWebDVD_get_DVDDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_DVDDirectory(This,pVal) ) 

#define IMSVidWebDVD_put_DVDDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_DVDDirectory(This,newVal) ) 

#define IMSVidWebDVD_IsSubpictureStreamEnabled(This,lstream,fEnabled)	\
    ( (This)->lpVtbl -> IsSubpictureStreamEnabled(This,lstream,fEnabled) ) 

#define IMSVidWebDVD_IsAudioStreamEnabled(This,lstream,fEnabled)	\
    ( (This)->lpVtbl -> IsAudioStreamEnabled(This,lstream,fEnabled) ) 

#define IMSVidWebDVD_get_CurrentSubpictureStream(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentSubpictureStream(This,pVal) ) 

#define IMSVidWebDVD_put_CurrentSubpictureStream(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentSubpictureStream(This,newVal) ) 

#define IMSVidWebDVD_get_SubpictureLanguage(This,lStream,strLanguage)	\
    ( (This)->lpVtbl -> get_SubpictureLanguage(This,lStream,strLanguage) ) 

#define IMSVidWebDVD_get_CurrentAudioStream(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentAudioStream(This,pVal) ) 

#define IMSVidWebDVD_put_CurrentAudioStream(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentAudioStream(This,newVal) ) 

#define IMSVidWebDVD_get_AudioStreamsAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_AudioStreamsAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_AnglesAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_AnglesAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_CurrentAngle(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentAngle(This,pVal) ) 

#define IMSVidWebDVD_put_CurrentAngle(This,newVal)	\
    ( (This)->lpVtbl -> put_CurrentAngle(This,newVal) ) 

#define IMSVidWebDVD_get_SubpictureStreamsAvailable(This,pVal)	\
    ( (This)->lpVtbl -> get_SubpictureStreamsAvailable(This,pVal) ) 

#define IMSVidWebDVD_get_SubpictureOn(This,pVal)	\
    ( (This)->lpVtbl -> get_SubpictureOn(This,pVal) ) 

#define IMSVidWebDVD_put_SubpictureOn(This,newVal)	\
    ( (This)->lpVtbl -> put_SubpictureOn(This,newVal) ) 

#define IMSVidWebDVD_get_DVDUniqueID(This,pVal)	\
    ( (This)->lpVtbl -> get_DVDUniqueID(This,pVal) ) 

#define IMSVidWebDVD_AcceptParentalLevelChange(This,fAccept,strUserName,strPassword)	\
    ( (This)->lpVtbl -> AcceptParentalLevelChange(This,fAccept,strUserName,strPassword) ) 

#define IMSVidWebDVD_NotifyParentalLevelChange(This,newVal)	\
    ( (This)->lpVtbl -> NotifyParentalLevelChange(This,newVal) ) 

#define IMSVidWebDVD_SelectParentalCountry(This,lCountry,strUserName,strPassword)	\
    ( (This)->lpVtbl -> SelectParentalCountry(This,lCountry,strUserName,strPassword) ) 

#define IMSVidWebDVD_SelectParentalLevel(This,lParentalLevel,strUserName,strPassword)	\
    ( (This)->lpVtbl -> SelectParentalLevel(This,lParentalLevel,strUserName,strPassword) ) 

#define IMSVidWebDVD_get_TitleParentalLevels(This,lTitle,plParentalLevels)	\
    ( (This)->lpVtbl -> get_TitleParentalLevels(This,lTitle,plParentalLevels) ) 

#define IMSVidWebDVD_get_PlayerParentalCountry(This,plCountryCode)	\
    ( (This)->lpVtbl -> get_PlayerParentalCountry(This,plCountryCode) ) 

#define IMSVidWebDVD_get_PlayerParentalLevel(This,plParentalLevel)	\
    ( (This)->lpVtbl -> get_PlayerParentalLevel(This,plParentalLevel) ) 

#define IMSVidWebDVD_Eject(This)	\
    ( (This)->lpVtbl -> Eject(This) ) 

#define IMSVidWebDVD_UOPValid(This,lUOP,pfValid)	\
    ( (This)->lpVtbl -> UOPValid(This,lUOP,pfValid) ) 

#define IMSVidWebDVD_get_SPRM(This,lIndex,psSPRM)	\
    ( (This)->lpVtbl -> get_SPRM(This,lIndex,psSPRM) ) 

#define IMSVidWebDVD_get_GPRM(This,lIndex,psSPRM)	\
    ( (This)->lpVtbl -> get_GPRM(This,lIndex,psSPRM) ) 

#define IMSVidWebDVD_put_GPRM(This,lIndex,sValue)	\
    ( (This)->lpVtbl -> put_GPRM(This,lIndex,sValue) ) 

#define IMSVidWebDVD_get_DVDTextStringType(This,lLangIndex,lStringIndex,pType)	\
    ( (This)->lpVtbl -> get_DVDTextStringType(This,lLangIndex,lStringIndex,pType) ) 

#define IMSVidWebDVD_get_DVDTextString(This,lLangIndex,lStringIndex,pstrText)	\
    ( (This)->lpVtbl -> get_DVDTextString(This,lLangIndex,lStringIndex,pstrText) ) 

#define IMSVidWebDVD_get_DVDTextNumberOfStrings(This,lLangIndex,plNumOfStrings)	\
    ( (This)->lpVtbl -> get_DVDTextNumberOfStrings(This,lLangIndex,plNumOfStrings) ) 

#define IMSVidWebDVD_get_DVDTextNumberOfLanguages(This,plNumOfLangs)	\
    ( (This)->lpVtbl -> get_DVDTextNumberOfLanguages(This,plNumOfLangs) ) 

#define IMSVidWebDVD_get_DVDTextLanguageLCID(This,lLangIndex,lcid)	\
    ( (This)->lpVtbl -> get_DVDTextLanguageLCID(This,lLangIndex,lcid) ) 

#define IMSVidWebDVD_RegionChange(This)	\
    ( (This)->lpVtbl -> RegionChange(This) ) 

#define IMSVidWebDVD_get_DVDAdm(This,pVal)	\
    ( (This)->lpVtbl -> get_DVDAdm(This,pVal) ) 

#define IMSVidWebDVD_DeleteBookmark(This)	\
    ( (This)->lpVtbl -> DeleteBookmark(This) ) 

#define IMSVidWebDVD_RestoreBookmark(This)	\
    ( (This)->lpVtbl -> RestoreBookmark(This) ) 

#define IMSVidWebDVD_SaveBookmark(This)	\
    ( (This)->lpVtbl -> SaveBookmark(This) ) 

#define IMSVidWebDVD_SelectDefaultAudioLanguage(This,lang,ext)	\
    ( (This)->lpVtbl -> SelectDefaultAudioLanguage(This,lang,ext) ) 

#define IMSVidWebDVD_SelectDefaultSubpictureLanguage(This,lang,ext)	\
    ( (This)->lpVtbl -> SelectDefaultSubpictureLanguage(This,lang,ext) ) 

#define IMSVidWebDVD_get_PreferredSubpictureStream(This,pVal)	\
    ( (This)->lpVtbl -> get_PreferredSubpictureStream(This,pVal) ) 

#define IMSVidWebDVD_get_DefaultMenuLanguage(This,lang)	\
    ( (This)->lpVtbl -> get_DefaultMenuLanguage(This,lang) ) 

#define IMSVidWebDVD_put_DefaultMenuLanguage(This,lang)	\
    ( (This)->lpVtbl -> put_DefaultMenuLanguage(This,lang) ) 

#define IMSVidWebDVD_get_DefaultSubpictureLanguage(This,lang)	\
    ( (This)->lpVtbl -> get_DefaultSubpictureLanguage(This,lang) ) 

#define IMSVidWebDVD_get_DefaultAudioLanguage(This,lang)	\
    ( (This)->lpVtbl -> get_DefaultAudioLanguage(This,lang) ) 

#define IMSVidWebDVD_get_DefaultSubpictureLanguageExt(This,ext)	\
    ( (This)->lpVtbl -> get_DefaultSubpictureLanguageExt(This,ext) ) 

#define IMSVidWebDVD_get_DefaultAudioLanguageExt(This,ext)	\
    ( (This)->lpVtbl -> get_DefaultAudioLanguageExt(This,ext) ) 

#define IMSVidWebDVD_get_LanguageFromLCID(This,lcid,lang)	\
    ( (This)->lpVtbl -> get_LanguageFromLCID(This,lcid,lang) ) 

#define IMSVidWebDVD_get_KaraokeAudioPresentationMode(This,pVal)	\
    ( (This)->lpVtbl -> get_KaraokeAudioPresentationMode(This,pVal) ) 

#define IMSVidWebDVD_put_KaraokeAudioPresentationMode(This,newVal)	\
    ( (This)->lpVtbl -> put_KaraokeAudioPresentationMode(This,newVal) ) 

#define IMSVidWebDVD_get_KaraokeChannelContent(This,lStream,lChan,lContent)	\
    ( (This)->lpVtbl -> get_KaraokeChannelContent(This,lStream,lChan,lContent) ) 

#define IMSVidWebDVD_get_KaraokeChannelAssignment(This,lStream,lChannelAssignment)	\
    ( (This)->lpVtbl -> get_KaraokeChannelAssignment(This,lStream,lChannelAssignment) ) 

#define IMSVidWebDVD_RestorePreferredSettings(This)	\
    ( (This)->lpVtbl -> RestorePreferredSettings(This) ) 

#define IMSVidWebDVD_get_ButtonRect(This,lButton,pRect)	\
    ( (This)->lpVtbl -> get_ButtonRect(This,lButton,pRect) ) 

#define IMSVidWebDVD_get_DVDScreenInMouseCoordinates(This,ppRect)	\
    ( (This)->lpVtbl -> get_DVDScreenInMouseCoordinates(This,ppRect) ) 

#define IMSVidWebDVD_put_DVDScreenInMouseCoordinates(This,pRect)	\
    ( (This)->lpVtbl -> put_DVDScreenInMouseCoordinates(This,pRect) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidWebDVD_INTERFACE_DEFINED__ */


#ifndef __IMSVidWebDVDEvent_INTERFACE_DEFINED__
#define __IMSVidWebDVDEvent_INTERFACE_DEFINED__

/* interface IMSVidWebDVDEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidWebDVDEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B4F7A674-9B83-49cb-A357-C63B871BE958")
    IMSVidWebDVDEvent : public IMSVidPlaybackEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DVDNotify( 
            /* [in] */ long lEventCode,
            /* [in] */ VARIANT lParam1,
            /* [in] */ VARIANT lParam2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayForwards( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayBackwards( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowMenu( 
            /* [in] */ DVDMenuIDConstants __MIDL__IMSVidWebDVDEvent0000,
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Resume( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectOrActivateButton( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StillOff( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PauseOn( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeCurrentAudioStream( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeCurrentSubpictureStream( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeCurrentAngle( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayAtTimeInTitle( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayAtTime( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayChapterInTitle( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayChapter( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReplayChapter( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayNextChapter( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnFromSubmenu( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayTitle( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlayPrevChapter( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeKaraokePresMode( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeVideoPresMode( 
            /* [in] */ VARIANT_BOOL bEnabled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidWebDVDEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidWebDVDEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidWebDVDEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidWebDVDEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DVDNotify )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ long lEventCode,
            /* [in] */ VARIANT lParam1,
            /* [in] */ VARIANT lParam2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayForwards )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayBackwards )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowMenu )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ DVDMenuIDConstants __MIDL__IMSVidWebDVDEvent0000,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectOrActivateButton )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StillOff )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PauseOn )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeCurrentAudioStream )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeCurrentSubpictureStream )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeCurrentAngle )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayAtTimeInTitle )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayAtTime )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayChapterInTitle )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayChapter )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReplayChapter )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayNextChapter )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnFromSubmenu )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayTitle )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlayPrevChapter )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeKaraokePresMode )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeVideoPresMode )( 
            IMSVidWebDVDEvent * This,
            /* [in] */ VARIANT_BOOL bEnabled);
        
        END_INTERFACE
    } IMSVidWebDVDEventVtbl;

    interface IMSVidWebDVDEvent
    {
        CONST_VTBL struct IMSVidWebDVDEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidWebDVDEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidWebDVDEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidWebDVDEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidWebDVDEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidWebDVDEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidWebDVDEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidWebDVDEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidWebDVDEvent_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 


#define IMSVidWebDVDEvent_DVDNotify(This,lEventCode,lParam1,lParam2)	\
    ( (This)->lpVtbl -> DVDNotify(This,lEventCode,lParam1,lParam2) ) 

#define IMSVidWebDVDEvent_PlayForwards(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayForwards(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayBackwards(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayBackwards(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ShowMenu(This,__MIDL__IMSVidWebDVDEvent0000,bEnabled)	\
    ( (This)->lpVtbl -> ShowMenu(This,__MIDL__IMSVidWebDVDEvent0000,bEnabled) ) 

#define IMSVidWebDVDEvent_Resume(This,bEnabled)	\
    ( (This)->lpVtbl -> Resume(This,bEnabled) ) 

#define IMSVidWebDVDEvent_SelectOrActivateButton(This,bEnabled)	\
    ( (This)->lpVtbl -> SelectOrActivateButton(This,bEnabled) ) 

#define IMSVidWebDVDEvent_StillOff(This,bEnabled)	\
    ( (This)->lpVtbl -> StillOff(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PauseOn(This,bEnabled)	\
    ( (This)->lpVtbl -> PauseOn(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ChangeCurrentAudioStream(This,bEnabled)	\
    ( (This)->lpVtbl -> ChangeCurrentAudioStream(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ChangeCurrentSubpictureStream(This,bEnabled)	\
    ( (This)->lpVtbl -> ChangeCurrentSubpictureStream(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ChangeCurrentAngle(This,bEnabled)	\
    ( (This)->lpVtbl -> ChangeCurrentAngle(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayAtTimeInTitle(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayAtTimeInTitle(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayAtTime(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayAtTime(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayChapterInTitle(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayChapterInTitle(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayChapter(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayChapter(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ReplayChapter(This,bEnabled)	\
    ( (This)->lpVtbl -> ReplayChapter(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayNextChapter(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayNextChapter(This,bEnabled) ) 

#define IMSVidWebDVDEvent_Stop(This,bEnabled)	\
    ( (This)->lpVtbl -> Stop(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ReturnFromSubmenu(This,bEnabled)	\
    ( (This)->lpVtbl -> ReturnFromSubmenu(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayTitle(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayTitle(This,bEnabled) ) 

#define IMSVidWebDVDEvent_PlayPrevChapter(This,bEnabled)	\
    ( (This)->lpVtbl -> PlayPrevChapter(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ChangeKaraokePresMode(This,bEnabled)	\
    ( (This)->lpVtbl -> ChangeKaraokePresMode(This,bEnabled) ) 

#define IMSVidWebDVDEvent_ChangeVideoPresMode(This,bEnabled)	\
    ( (This)->lpVtbl -> ChangeVideoPresMode(This,bEnabled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidWebDVDEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidWebDVDAdm_INTERFACE_DEFINED__
#define __IMSVidWebDVDAdm_INTERFACE_DEFINED__

/* interface IMSVidWebDVDAdm */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidWebDVDAdm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8BE681A-EB2C-47f0-B415-94D5452F0E05")
    IMSVidWebDVDAdm : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangePassword( 
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strOld,
            /* [in] */ __RPC__in BSTR strNew) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveParentalLevel( 
            /* [in] */ long level,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveParentalCountry( 
            /* [in] */ long country,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword) = 0;
        
        virtual /* [helpstring][restricted][hidden][id] */ HRESULT STDMETHODCALLTYPE ConfirmPassword( 
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParentalLevel( 
            /* [retval][out] */ __RPC__out long *lLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParentalCountry( 
            /* [retval][out] */ __RPC__out long *lCountry) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultAudioLCID( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultAudioLCID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultSubpictureLCID( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultSubpictureLCID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultMenuLCID( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultMenuLCID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BookmarkOnStop( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BookmarkOnStop( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidWebDVDAdmVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidWebDVDAdm * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidWebDVDAdm * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidWebDVDAdm * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangePassword )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strOld,
            /* [in] */ __RPC__in BSTR strNew);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveParentalLevel )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ long level,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveParentalCountry )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ long country,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword);
        
        /* [helpstring][restricted][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *ConfirmPassword )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ __RPC__in BSTR strUserName,
            /* [in] */ __RPC__in BSTR strPassword,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParentalLevel )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out long *lLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParentalCountry )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out long *lCountry);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultAudioLCID )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultAudioLCID )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultSubpictureLCID )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultSubpictureLCID )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultMenuLCID )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultMenuLCID )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BookmarkOnStop )( 
            IMSVidWebDVDAdm * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BookmarkOnStop )( 
            IMSVidWebDVDAdm * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IMSVidWebDVDAdmVtbl;

    interface IMSVidWebDVDAdm
    {
        CONST_VTBL struct IMSVidWebDVDAdmVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidWebDVDAdm_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidWebDVDAdm_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidWebDVDAdm_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidWebDVDAdm_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidWebDVDAdm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidWebDVDAdm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidWebDVDAdm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidWebDVDAdm_ChangePassword(This,strUserName,strOld,strNew)	\
    ( (This)->lpVtbl -> ChangePassword(This,strUserName,strOld,strNew) ) 

#define IMSVidWebDVDAdm_SaveParentalLevel(This,level,strUserName,strPassword)	\
    ( (This)->lpVtbl -> SaveParentalLevel(This,level,strUserName,strPassword) ) 

#define IMSVidWebDVDAdm_SaveParentalCountry(This,country,strUserName,strPassword)	\
    ( (This)->lpVtbl -> SaveParentalCountry(This,country,strUserName,strPassword) ) 

#define IMSVidWebDVDAdm_ConfirmPassword(This,strUserName,strPassword,pVal)	\
    ( (This)->lpVtbl -> ConfirmPassword(This,strUserName,strPassword,pVal) ) 

#define IMSVidWebDVDAdm_GetParentalLevel(This,lLevel)	\
    ( (This)->lpVtbl -> GetParentalLevel(This,lLevel) ) 

#define IMSVidWebDVDAdm_GetParentalCountry(This,lCountry)	\
    ( (This)->lpVtbl -> GetParentalCountry(This,lCountry) ) 

#define IMSVidWebDVDAdm_get_DefaultAudioLCID(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultAudioLCID(This,pVal) ) 

#define IMSVidWebDVDAdm_put_DefaultAudioLCID(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultAudioLCID(This,newVal) ) 

#define IMSVidWebDVDAdm_get_DefaultSubpictureLCID(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultSubpictureLCID(This,pVal) ) 

#define IMSVidWebDVDAdm_put_DefaultSubpictureLCID(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultSubpictureLCID(This,newVal) ) 

#define IMSVidWebDVDAdm_get_DefaultMenuLCID(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultMenuLCID(This,pVal) ) 

#define IMSVidWebDVDAdm_put_DefaultMenuLCID(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultMenuLCID(This,newVal) ) 

#define IMSVidWebDVDAdm_get_BookmarkOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_BookmarkOnStop(This,pVal) ) 

#define IMSVidWebDVDAdm_put_BookmarkOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_BookmarkOnStop(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidWebDVDAdm_INTERFACE_DEFINED__ */


#ifndef __IMSVidOutputDevice_INTERFACE_DEFINED__
#define __IMSVidOutputDevice_INTERFACE_DEFINED__

/* interface IMSVidOutputDevice */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidOutputDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03546-A4C8-11d2-B634-00C04F79498E")
    IMSVidOutputDevice : public IMSVidDevice
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidOutputDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidOutputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidOutputDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidOutputDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidOutputDevice * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidOutputDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidOutputDevice * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidOutputDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidOutputDevice * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidOutputDevice * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidOutputDevice * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidOutputDevice * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        END_INTERFACE
    } IMSVidOutputDeviceVtbl;

    interface IMSVidOutputDevice
    {
        CONST_VTBL struct IMSVidOutputDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidOutputDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidOutputDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidOutputDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidOutputDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidOutputDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidOutputDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidOutputDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidOutputDevice_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidOutputDevice_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidOutputDevice_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidOutputDevice_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidOutputDevice_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidOutputDevice_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidOutputDevice_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidOutputDevice_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidOutputDevice_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidOutputDevice_INTERFACE_DEFINED__ */


#ifndef __IMSVidOutputDeviceEvent_INTERFACE_DEFINED__
#define __IMSVidOutputDeviceEvent_INTERFACE_DEFINED__

/* interface IMSVidOutputDeviceEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidOutputDeviceEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E6A14E2-571C-11d3-B652-00C04F79498E")
    IMSVidOutputDeviceEvent : public IMSVidDeviceEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidOutputDeviceEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidOutputDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidOutputDeviceEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidOutputDeviceEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidOutputDeviceEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidOutputDeviceEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidOutputDeviceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidOutputDeviceEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidOutputDeviceEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        END_INTERFACE
    } IMSVidOutputDeviceEventVtbl;

    interface IMSVidOutputDeviceEvent
    {
        CONST_VTBL struct IMSVidOutputDeviceEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidOutputDeviceEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidOutputDeviceEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidOutputDeviceEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidOutputDeviceEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidOutputDeviceEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidOutputDeviceEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidOutputDeviceEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidOutputDeviceEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidOutputDeviceEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidFeature_INTERFACE_DEFINED__
#define __IMSVidFeature_INTERFACE_DEFINED__

/* interface IMSVidFeature */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidFeature;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03547-A4C8-11d2-B634-00C04F79498E")
    IMSVidFeature : public IMSVidDevice
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFeatureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFeature * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFeature * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFeature * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFeature * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFeature * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFeature * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFeature * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidFeature * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidFeature * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidFeature * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidFeature * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        END_INTERFACE
    } IMSVidFeatureVtbl;

    interface IMSVidFeature
    {
        CONST_VTBL struct IMSVidFeatureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFeature_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFeature_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFeature_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFeature_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFeature_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFeature_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFeature_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidFeature_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidFeature_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidFeature_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidFeature_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidFeature_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidFeature_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidFeature_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidFeature_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidFeature_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFeature_INTERFACE_DEFINED__ */


#ifndef __IMSVidFeatureEvent_INTERFACE_DEFINED__
#define __IMSVidFeatureEvent_INTERFACE_DEFINED__

/* interface IMSVidFeatureEvent */
/* [unique][helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidFeatureEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DD2903C-E0AA-11d2-B63A-00C04F79498E")
    IMSVidFeatureEvent : public IMSVidDeviceEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFeatureEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFeatureEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFeatureEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFeatureEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFeatureEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFeatureEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFeatureEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFeatureEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidFeatureEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        END_INTERFACE
    } IMSVidFeatureEventVtbl;

    interface IMSVidFeatureEvent
    {
        CONST_VTBL struct IMSVidFeatureEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFeatureEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFeatureEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFeatureEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFeatureEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFeatureEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFeatureEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFeatureEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidFeatureEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFeatureEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidEncoder_INTERFACE_DEFINED__
#define __IMSVidEncoder_INTERFACE_DEFINED__

/* interface IMSVidEncoder */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidEncoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0020FD4-BEE7-43d9-A495-9F213117103D")
    IMSVidEncoder : public IMSVidFeature
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoEncoderInterface( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEncInt) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioEncoderInterface( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEncInt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidEncoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidEncoder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidEncoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidEncoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidEncoder * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidEncoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidEncoder * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidEncoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidEncoder * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidEncoder * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidEncoder * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoEncoderInterface )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEncInt);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioEncoderInterface )( 
            IMSVidEncoder * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppEncInt);
        
        END_INTERFACE
    } IMSVidEncoderVtbl;

    interface IMSVidEncoder
    {
        CONST_VTBL struct IMSVidEncoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidEncoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidEncoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidEncoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidEncoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidEncoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidEncoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidEncoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidEncoder_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidEncoder_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidEncoder_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidEncoder_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidEncoder_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidEncoder_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidEncoder_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidEncoder_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidEncoder_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidEncoder_get_VideoEncoderInterface(This,ppEncInt)	\
    ( (This)->lpVtbl -> get_VideoEncoderInterface(This,ppEncInt) ) 

#define IMSVidEncoder_get_AudioEncoderInterface(This,ppEncInt)	\
    ( (This)->lpVtbl -> get_AudioEncoderInterface(This,ppEncInt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidEncoder_INTERFACE_DEFINED__ */


#ifndef __IMSVidXDS_INTERFACE_DEFINED__
#define __IMSVidXDS_INTERFACE_DEFINED__

/* interface IMSVidXDS */
/* [unique][helpstring][uuid][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidXDS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11EBC158-E712-4d1f-8BB3-01ED5274C4CE")
    IMSVidXDS : public IMSVidFeature
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelChangeInterface( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **punkCC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidXDSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidXDS * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidXDS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidXDS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidXDS * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidXDS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidXDS * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidXDS * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidXDS * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidXDS * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidXDS * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelChangeInterface )( 
            IMSVidXDS * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **punkCC);
        
        END_INTERFACE
    } IMSVidXDSVtbl;

    interface IMSVidXDS
    {
        CONST_VTBL struct IMSVidXDSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidXDS_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidXDS_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidXDS_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidXDS_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidXDS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidXDS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidXDS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidXDS_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidXDS_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidXDS_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidXDS_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidXDS_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidXDS_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidXDS_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidXDS_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidXDS_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidXDS_get_ChannelChangeInterface(This,punkCC)	\
    ( (This)->lpVtbl -> get_ChannelChangeInterface(This,punkCC) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidXDS_INTERFACE_DEFINED__ */


#ifndef __IMSVidXDSEvent_INTERFACE_DEFINED__
#define __IMSVidXDSEvent_INTERFACE_DEFINED__

/* interface IMSVidXDSEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidXDSEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6DB2317D-3B23-41ec-BA4B-701F407EAF3A")
    IMSVidXDSEvent : public IMSVidFeatureEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RatingChange( 
            /* [in] */ EnTvRat_System PrevRatingSystem,
            /* [in] */ EnTvRat_GenericLevel PrevLevel,
            /* [in] */ BfEnTvRat_GenericAttributes PrevAttributes,
            /* [in] */ EnTvRat_System NewRatingSystem,
            /* [in] */ EnTvRat_GenericLevel NewLevel,
            /* [in] */ BfEnTvRat_GenericAttributes NewAttributes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidXDSEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidXDSEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidXDSEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidXDSEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidXDSEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidXDSEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidXDSEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidXDSEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidXDSEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingChange )( 
            IMSVidXDSEvent * This,
            /* [in] */ EnTvRat_System PrevRatingSystem,
            /* [in] */ EnTvRat_GenericLevel PrevLevel,
            /* [in] */ BfEnTvRat_GenericAttributes PrevAttributes,
            /* [in] */ EnTvRat_System NewRatingSystem,
            /* [in] */ EnTvRat_GenericLevel NewLevel,
            /* [in] */ BfEnTvRat_GenericAttributes NewAttributes);
        
        END_INTERFACE
    } IMSVidXDSEventVtbl;

    interface IMSVidXDSEvent
    {
        CONST_VTBL struct IMSVidXDSEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidXDSEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidXDSEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidXDSEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidXDSEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidXDSEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidXDSEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidXDSEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidXDSEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidXDSEvent_RatingChange(This,PrevRatingSystem,PrevLevel,PrevAttributes,NewRatingSystem,NewLevel,NewAttributes)	\
    ( (This)->lpVtbl -> RatingChange(This,PrevRatingSystem,PrevLevel,PrevAttributes,NewRatingSystem,NewLevel,NewAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidXDSEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidDataServices_INTERFACE_DEFINED__
#define __IMSVidDataServices_INTERFACE_DEFINED__

/* interface IMSVidDataServices */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidDataServices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("334125C1-77E5-11d3-B653-00C04F79498E")
    IMSVidDataServices : public IMSVidFeature
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidDataServicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidDataServices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidDataServices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidDataServices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidDataServices * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidDataServices * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidDataServices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidDataServices * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidDataServices * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidDataServices * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidDataServices * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidDataServices * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        END_INTERFACE
    } IMSVidDataServicesVtbl;

    interface IMSVidDataServices
    {
        CONST_VTBL struct IMSVidDataServicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidDataServices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidDataServices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidDataServices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidDataServices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidDataServices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidDataServices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidDataServices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidDataServices_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidDataServices_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidDataServices_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidDataServices_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidDataServices_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidDataServices_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidDataServices_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidDataServices_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidDataServices_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidDataServices_INTERFACE_DEFINED__ */


#ifndef __IMSVidDataServicesEvent_INTERFACE_DEFINED__
#define __IMSVidDataServicesEvent_INTERFACE_DEFINED__

/* interface IMSVidDataServicesEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidDataServicesEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("334125C2-77E5-11d3-B653-00C04F79498E")
    IMSVidDataServicesEvent : public IMSVidDeviceEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidDataServicesEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidDataServicesEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidDataServicesEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidDataServicesEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidDataServicesEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidDataServicesEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidDataServicesEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidDataServicesEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidDataServicesEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        END_INTERFACE
    } IMSVidDataServicesEventVtbl;

    interface IMSVidDataServicesEvent
    {
        CONST_VTBL struct IMSVidDataServicesEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidDataServicesEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidDataServicesEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidDataServicesEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidDataServicesEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidDataServicesEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidDataServicesEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidDataServicesEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidDataServicesEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidDataServicesEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidClosedCaptioning_INTERFACE_DEFINED__
#define __IMSVidClosedCaptioning_INTERFACE_DEFINED__

/* interface IMSVidClosedCaptioning */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidClosedCaptioning;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("99652EA1-C1F7-414f-BB7B-1C967DE75983")
    IMSVidClosedCaptioning : public IMSVidFeature
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enable( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *On) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enable( 
            /* [in] */ VARIANT_BOOL On) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidClosedCaptioningVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidClosedCaptioning * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidClosedCaptioning * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidClosedCaptioning * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidClosedCaptioning * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            IMSVidClosedCaptioning * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *On);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            IMSVidClosedCaptioning * This,
            /* [in] */ VARIANT_BOOL On);
        
        END_INTERFACE
    } IMSVidClosedCaptioningVtbl;

    interface IMSVidClosedCaptioning
    {
        CONST_VTBL struct IMSVidClosedCaptioningVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidClosedCaptioning_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidClosedCaptioning_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidClosedCaptioning_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidClosedCaptioning_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidClosedCaptioning_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidClosedCaptioning_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidClosedCaptioning_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidClosedCaptioning_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidClosedCaptioning_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidClosedCaptioning_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidClosedCaptioning_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidClosedCaptioning_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidClosedCaptioning_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidClosedCaptioning_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidClosedCaptioning_get_Enable(This,On)	\
    ( (This)->lpVtbl -> get_Enable(This,On) ) 

#define IMSVidClosedCaptioning_put_Enable(This,On)	\
    ( (This)->lpVtbl -> put_Enable(This,On) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidClosedCaptioning_INTERFACE_DEFINED__ */


#ifndef __IMSVidClosedCaptioning2_INTERFACE_DEFINED__
#define __IMSVidClosedCaptioning2_INTERFACE_DEFINED__

/* interface IMSVidClosedCaptioning2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidClosedCaptioning2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E00CB864-A029-4310-9987-A873F5887D97")
    IMSVidClosedCaptioning2 : public IMSVidClosedCaptioning
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Service( 
            /* [retval][out] */ __RPC__out MSVidCCService *On) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Service( 
            /* [in] */ MSVidCCService On) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidClosedCaptioning2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidClosedCaptioning2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidClosedCaptioning2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidClosedCaptioning2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidClosedCaptioning2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *On);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Service )( 
            IMSVidClosedCaptioning2 * This,
            /* [retval][out] */ __RPC__out MSVidCCService *On);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Service )( 
            IMSVidClosedCaptioning2 * This,
            /* [in] */ MSVidCCService On);
        
        END_INTERFACE
    } IMSVidClosedCaptioning2Vtbl;

    interface IMSVidClosedCaptioning2
    {
        CONST_VTBL struct IMSVidClosedCaptioning2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidClosedCaptioning2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidClosedCaptioning2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidClosedCaptioning2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidClosedCaptioning2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidClosedCaptioning2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidClosedCaptioning2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidClosedCaptioning2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidClosedCaptioning2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidClosedCaptioning2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidClosedCaptioning2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidClosedCaptioning2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidClosedCaptioning2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidClosedCaptioning2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidClosedCaptioning2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidClosedCaptioning2_get_Enable(This,On)	\
    ( (This)->lpVtbl -> get_Enable(This,On) ) 

#define IMSVidClosedCaptioning2_put_Enable(This,On)	\
    ( (This)->lpVtbl -> put_Enable(This,On) ) 


#define IMSVidClosedCaptioning2_get_Service(This,On)	\
    ( (This)->lpVtbl -> get_Service(This,On) ) 

#define IMSVidClosedCaptioning2_put_Service(This,On)	\
    ( (This)->lpVtbl -> put_Service(This,On) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidClosedCaptioning2_INTERFACE_DEFINED__ */


#ifndef __IMSVidClosedCaptioning3_INTERFACE_DEFINED__
#define __IMSVidClosedCaptioning3_INTERFACE_DEFINED__

/* interface IMSVidClosedCaptioning3 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidClosedCaptioning3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8638E8A-7625-4c51-9366-2F40A9831FC0")
    IMSVidClosedCaptioning3 : public IMSVidClosedCaptioning2
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TeleTextFilter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **punkTTFilter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidClosedCaptioning3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidClosedCaptioning3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidClosedCaptioning3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidClosedCaptioning3 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidClosedCaptioning3 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *On);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ VARIANT_BOOL On);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Service )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__out MSVidCCService *On);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Service )( 
            IMSVidClosedCaptioning3 * This,
            /* [in] */ MSVidCCService On);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TeleTextFilter )( 
            IMSVidClosedCaptioning3 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **punkTTFilter);
        
        END_INTERFACE
    } IMSVidClosedCaptioning3Vtbl;

    interface IMSVidClosedCaptioning3
    {
        CONST_VTBL struct IMSVidClosedCaptioning3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidClosedCaptioning3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidClosedCaptioning3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidClosedCaptioning3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidClosedCaptioning3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidClosedCaptioning3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidClosedCaptioning3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidClosedCaptioning3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidClosedCaptioning3_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidClosedCaptioning3_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidClosedCaptioning3_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidClosedCaptioning3_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidClosedCaptioning3_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidClosedCaptioning3_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning3_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidClosedCaptioning3_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidClosedCaptioning3_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidClosedCaptioning3_get_Enable(This,On)	\
    ( (This)->lpVtbl -> get_Enable(This,On) ) 

#define IMSVidClosedCaptioning3_put_Enable(This,On)	\
    ( (This)->lpVtbl -> put_Enable(This,On) ) 


#define IMSVidClosedCaptioning3_get_Service(This,On)	\
    ( (This)->lpVtbl -> get_Service(This,On) ) 

#define IMSVidClosedCaptioning3_put_Service(This,On)	\
    ( (This)->lpVtbl -> put_Service(This,On) ) 


#define IMSVidClosedCaptioning3_get_TeleTextFilter(This,punkTTFilter)	\
    ( (This)->lpVtbl -> get_TeleTextFilter(This,punkTTFilter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidClosedCaptioning3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_segment_0000_0038 */
/* [local] */ 

typedef /* [public][public][public] */ 
enum __MIDL___MIDL_itf_segment_0000_0038_0001
    {	sslFullSize	= 0,
	sslClipByOverScan	= ( sslFullSize + 1 ) ,
	sslClipByClipRect	= ( sslClipByOverScan + 1 ) 
    } 	SourceSizeList;



extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0038_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_segment_0000_0038_v0_0_s_ifspec;

#ifndef __IMSVidVideoRenderer_INTERFACE_DEFINED__
#define __IMSVidVideoRenderer_INTERFACE_DEFINED__

/* interface IMSVidVideoRenderer */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidVideoRenderer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03540-A4C8-11d2-B634-00C04F79498E")
    IMSVidVideoRenderer : public IMSVidOutputDevice
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomCompositorClass( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *CompositorCLSID) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomCompositorClass( 
            /* [in] */ __RPC__in BSTR CompositorCLSID) = 0;
        
        virtual /* [id][restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get__CustomCompositorClass( 
            /* [retval][out] */ __RPC__out GUID *CompositorCLSID) = 0;
        
        virtual /* [id][restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put__CustomCompositorClass( 
            /* [in] */ __RPC__in REFCLSID CompositorCLSID) = 0;
        
        virtual /* [id][restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get__CustomCompositor( 
            /* [retval][out] */ __RPC__deref_out_opt IVMRImageCompositor **Compositor) = 0;
        
        virtual /* [id][restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put__CustomCompositor( 
            /* [in] */ __RPC__in_opt IVMRImageCompositor *Compositor) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MixerBitmap( 
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **MixerPictureDisp) = 0;
        
        virtual /* [id][restricted][hidden][propget] */ HRESULT STDMETHODCALLTYPE get__MixerBitmap( 
            /* [retval][out] */ __RPC__deref_out_opt IVMRMixerBitmap **MixerPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MixerBitmap( 
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp) = 0;
        
        virtual /* [id][restricted][hidden][propput] */ HRESULT STDMETHODCALLTYPE put__MixerBitmap( 
            /* [in] */ __RPC__in VMRALPHABITMAP *MixerPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MixerBitmapPositionRect( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **rDest) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MixerBitmapPositionRect( 
            /* [in] */ __RPC__in_opt IMSVidRect *rDest) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MixerBitmapOpacity( 
            /* [retval][out] */ __RPC__out int *opacity) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MixerBitmapOpacity( 
            /* [in] */ int opacity) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetupMixerBitmap( 
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp,
            /* [in] */ long Opacity,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SourceSize( 
            /* [out][retval] */ __RPC__out SourceSizeList *CurrentSize) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SourceSize( 
            /* [in] */ SourceSizeList NewSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OverScan( 
            /* [out][retval] */ __RPC__out long *plPercent) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_OverScan( 
            /* [in] */ long lPercent) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AvailableSourceRect( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxVidRect( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MinVidRect( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ClippedSourceRect( 
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ClippedSourceRect( 
            /* [in] */ __RPC__in_opt IMSVidRect *pRect) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_UsingOverlay( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_UsingOverlay( 
            /* [in] */ VARIANT_BOOL UseOverlayVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Capture( 
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **currentImage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FramesPerSecond( 
            /* [retval][out] */ __RPC__out long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DecimateInput( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pDeci) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DecimateInput( 
            /* [in] */ VARIANT_BOOL pDeci) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoRendererVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoRenderer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoRenderer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoRenderer * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoRenderer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoRenderer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidVideoRenderer * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidVideoRenderer * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomCompositorClass )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *CompositorCLSID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomCompositorClass )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in BSTR CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositorClass )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out GUID *CompositorCLSID);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositorClass )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in REFCLSID CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositor )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRImageCompositor **Compositor);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositor )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IVMRImageCompositor *Compositor);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmap )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **MixerPictureDisp);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MixerBitmap )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRMixerBitmap **MixerPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmap )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__MixerBitmap )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in VMRALPHABITMAP *MixerPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapPositionRect )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **rDest);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapPositionRect )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapOpacity )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out int *opacity);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapOpacity )( 
            IMSVidVideoRenderer * This,
            /* [in] */ int opacity);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetupMixerBitmap )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp,
            /* [in] */ long Opacity,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceSize )( 
            IMSVidVideoRenderer * This,
            /* [out][retval] */ __RPC__out SourceSizeList *CurrentSize);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceSize )( 
            IMSVidVideoRenderer * This,
            /* [in] */ SourceSizeList NewSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverScan )( 
            IMSVidVideoRenderer * This,
            /* [out][retval] */ __RPC__out long *plPercent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverScan )( 
            IMSVidVideoRenderer * This,
            /* [in] */ long lPercent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvailableSourceRect )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxVidRect )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinVidRect )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClippedSourceRect )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClippedSourceRect )( 
            IMSVidVideoRenderer * This,
            /* [in] */ __RPC__in_opt IMSVidRect *pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsingOverlay )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsingOverlay )( 
            IMSVidVideoRenderer * This,
            /* [in] */ VARIANT_BOOL UseOverlayVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Capture )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **currentImage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FramesPerSecond )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecimateInput )( 
            IMSVidVideoRenderer * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pDeci);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecimateInput )( 
            IMSVidVideoRenderer * This,
            /* [in] */ VARIANT_BOOL pDeci);
        
        END_INTERFACE
    } IMSVidVideoRendererVtbl;

    interface IMSVidVideoRenderer
    {
        CONST_VTBL struct IMSVidVideoRendererVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoRenderer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoRenderer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoRenderer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoRenderer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoRenderer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoRenderer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoRenderer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoRenderer_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidVideoRenderer_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidVideoRenderer_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidVideoRenderer_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidVideoRenderer_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidVideoRenderer_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidVideoRenderer_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidVideoRenderer_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidVideoRenderer_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidVideoRenderer_get_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer_put_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer_get__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer_put__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer_get__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> get__CustomCompositor(This,Compositor) ) 

#define IMSVidVideoRenderer_put__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> put__CustomCompositor(This,Compositor) ) 

#define IMSVidVideoRenderer_get_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> get_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVideoRenderer_get__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> get__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVideoRenderer_put_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> put_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVideoRenderer_put__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> put__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVideoRenderer_get_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> get_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVideoRenderer_put_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> put_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVideoRenderer_get_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> get_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVideoRenderer_put_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> put_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVideoRenderer_SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest)	\
    ( (This)->lpVtbl -> SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest) ) 

#define IMSVidVideoRenderer_get_SourceSize(This,CurrentSize)	\
    ( (This)->lpVtbl -> get_SourceSize(This,CurrentSize) ) 

#define IMSVidVideoRenderer_put_SourceSize(This,NewSize)	\
    ( (This)->lpVtbl -> put_SourceSize(This,NewSize) ) 

#define IMSVidVideoRenderer_get_OverScan(This,plPercent)	\
    ( (This)->lpVtbl -> get_OverScan(This,plPercent) ) 

#define IMSVidVideoRenderer_put_OverScan(This,lPercent)	\
    ( (This)->lpVtbl -> put_OverScan(This,lPercent) ) 

#define IMSVidVideoRenderer_get_AvailableSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_AvailableSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer_get_MaxVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MaxVidRect(This,ppVidRect) ) 

#define IMSVidVideoRenderer_get_MinVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MinVidRect(This,ppVidRect) ) 

#define IMSVidVideoRenderer_get_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_ClippedSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer_put_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> put_ClippedSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer_get_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> get_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVideoRenderer_put_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> put_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVideoRenderer_Capture(This,currentImage)	\
    ( (This)->lpVtbl -> Capture(This,currentImage) ) 

#define IMSVidVideoRenderer_get_FramesPerSecond(This,pVal)	\
    ( (This)->lpVtbl -> get_FramesPerSecond(This,pVal) ) 

#define IMSVidVideoRenderer_get_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> get_DecimateInput(This,pDeci) ) 

#define IMSVidVideoRenderer_put_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> put_DecimateInput(This,pDeci) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoRenderer_INTERFACE_DEFINED__ */


#ifndef __IMSVidVideoRendererEvent_INTERFACE_DEFINED__
#define __IMSVidVideoRendererEvent_INTERFACE_DEFINED__

/* interface IMSVidVideoRendererEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidVideoRendererEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03545-A4C8-11d2-B634-00C04F79498E")
    IMSVidVideoRendererEvent : public IMSVidOutputDeviceEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OverlayUnavailable( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoRendererEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoRendererEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoRendererEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoRendererEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoRendererEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoRendererEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoRendererEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoRendererEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidVideoRendererEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OverlayUnavailable )( 
            IMSVidVideoRendererEvent * This);
        
        END_INTERFACE
    } IMSVidVideoRendererEventVtbl;

    interface IMSVidVideoRendererEvent
    {
        CONST_VTBL struct IMSVidVideoRendererEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoRendererEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoRendererEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoRendererEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoRendererEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoRendererEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoRendererEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoRendererEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoRendererEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidVideoRendererEvent_OverlayUnavailable(This)	\
    ( (This)->lpVtbl -> OverlayUnavailable(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoRendererEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidGenericSink_INTERFACE_DEFINED__
#define __IMSVidGenericSink_INTERFACE_DEFINED__

/* interface IMSVidGenericSink */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidGenericSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C29B41D-455B-4c33-963A-0D28E5E555EA")
    IMSVidGenericSink : public IMSVidOutputDevice
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSinkFilter( 
            __RPC__in BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SinkStreams( 
            /* [retval][out] */ __RPC__out MSVidSinkStreams *pStreams) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SinkStreams( 
            /* [in] */ MSVidSinkStreams Streams) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidGenericSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidGenericSink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidGenericSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidGenericSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidGenericSink * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidGenericSink * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidGenericSink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidGenericSink * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidGenericSink * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidGenericSink * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidGenericSink * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSinkFilter )( 
            IMSVidGenericSink * This,
            __RPC__in BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SinkStreams )( 
            IMSVidGenericSink * This,
            /* [retval][out] */ __RPC__out MSVidSinkStreams *pStreams);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkStreams )( 
            IMSVidGenericSink * This,
            /* [in] */ MSVidSinkStreams Streams);
        
        END_INTERFACE
    } IMSVidGenericSinkVtbl;

    interface IMSVidGenericSink
    {
        CONST_VTBL struct IMSVidGenericSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidGenericSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidGenericSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidGenericSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidGenericSink_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidGenericSink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidGenericSink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidGenericSink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidGenericSink_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidGenericSink_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidGenericSink_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidGenericSink_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidGenericSink_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidGenericSink_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidGenericSink_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidGenericSink_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidGenericSink_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidGenericSink_SetSinkFilter(This,bstrName)	\
    ( (This)->lpVtbl -> SetSinkFilter(This,bstrName) ) 

#define IMSVidGenericSink_get_SinkStreams(This,pStreams)	\
    ( (This)->lpVtbl -> get_SinkStreams(This,pStreams) ) 

#define IMSVidGenericSink_put_SinkStreams(This,Streams)	\
    ( (This)->lpVtbl -> put_SinkStreams(This,Streams) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidGenericSink_INTERFACE_DEFINED__ */


#ifndef __IMSVidGenericSink2_INTERFACE_DEFINED__
#define __IMSVidGenericSink2_INTERFACE_DEFINED__

/* interface IMSVidGenericSink2 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidGenericSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B5A28F3-47F1-4092-B168-60CABEC08F1C")
    IMSVidGenericSink2 : public IMSVidGenericSink
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddFilter( 
            __RPC__in BSTR bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetFilterList( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidGenericSink2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidGenericSink2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidGenericSink2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidGenericSink2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidGenericSink2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidGenericSink2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidGenericSink2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidGenericSink2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidGenericSink2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidGenericSink2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidGenericSink2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSinkFilter )( 
            IMSVidGenericSink2 * This,
            __RPC__in BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SinkStreams )( 
            IMSVidGenericSink2 * This,
            /* [retval][out] */ __RPC__out MSVidSinkStreams *pStreams);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkStreams )( 
            IMSVidGenericSink2 * This,
            /* [in] */ MSVidSinkStreams Streams);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddFilter )( 
            IMSVidGenericSink2 * This,
            __RPC__in BSTR bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetFilterList )( 
            IMSVidGenericSink2 * This);
        
        END_INTERFACE
    } IMSVidGenericSink2Vtbl;

    interface IMSVidGenericSink2
    {
        CONST_VTBL struct IMSVidGenericSink2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidGenericSink2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidGenericSink2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidGenericSink2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidGenericSink2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidGenericSink2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidGenericSink2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidGenericSink2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidGenericSink2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidGenericSink2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidGenericSink2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidGenericSink2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidGenericSink2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidGenericSink2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidGenericSink2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidGenericSink2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidGenericSink2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidGenericSink2_SetSinkFilter(This,bstrName)	\
    ( (This)->lpVtbl -> SetSinkFilter(This,bstrName) ) 

#define IMSVidGenericSink2_get_SinkStreams(This,pStreams)	\
    ( (This)->lpVtbl -> get_SinkStreams(This,pStreams) ) 

#define IMSVidGenericSink2_put_SinkStreams(This,Streams)	\
    ( (This)->lpVtbl -> put_SinkStreams(This,Streams) ) 


#define IMSVidGenericSink2_AddFilter(This,bstrName)	\
    ( (This)->lpVtbl -> AddFilter(This,bstrName) ) 

#define IMSVidGenericSink2_ResetFilterList(This)	\
    ( (This)->lpVtbl -> ResetFilterList(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidGenericSink2_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED__
#define __IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferRecordingControl */
/* [helpstring][uuid][unique][nonextensible][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferRecordingControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("160621AA-BBBC-4326-A824-C395AEBC6E74")
    IMSVidStreamBufferRecordingControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartTime( 
            /* [retval][out] */ __RPC__out long *rtStart) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StartTime( 
            /* [in] */ long rtStart) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StopTime( 
            /* [retval][out] */ __RPC__out long *rtStop) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StopTime( 
            /* [in] */ long rtStop) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingStopped( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *phResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingStarted( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *phResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingType( 
            /* [retval][out] */ __RPC__out RecordingType *dwType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingAttribute( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRecordingAttribute) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferRecordingControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferRecordingControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferRecordingControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartTime )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__out long *rtStart);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StartTime )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ long rtStart);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopTime )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__out long *rtStop);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopTime )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [in] */ long rtStop);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingStopped )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *phResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingStarted )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *phResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingType )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__out RecordingType *dwType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingAttribute )( 
            IMSVidStreamBufferRecordingControl * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRecordingAttribute);
        
        END_INTERFACE
    } IMSVidStreamBufferRecordingControlVtbl;

    interface IMSVidStreamBufferRecordingControl
    {
        CONST_VTBL struct IMSVidStreamBufferRecordingControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferRecordingControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferRecordingControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferRecordingControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferRecordingControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferRecordingControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferRecordingControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferRecordingControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferRecordingControl_get_StartTime(This,rtStart)	\
    ( (This)->lpVtbl -> get_StartTime(This,rtStart) ) 

#define IMSVidStreamBufferRecordingControl_put_StartTime(This,rtStart)	\
    ( (This)->lpVtbl -> put_StartTime(This,rtStart) ) 

#define IMSVidStreamBufferRecordingControl_get_StopTime(This,rtStop)	\
    ( (This)->lpVtbl -> get_StopTime(This,rtStop) ) 

#define IMSVidStreamBufferRecordingControl_put_StopTime(This,rtStop)	\
    ( (This)->lpVtbl -> put_StopTime(This,rtStop) ) 

#define IMSVidStreamBufferRecordingControl_get_RecordingStopped(This,phResult)	\
    ( (This)->lpVtbl -> get_RecordingStopped(This,phResult) ) 

#define IMSVidStreamBufferRecordingControl_get_RecordingStarted(This,phResult)	\
    ( (This)->lpVtbl -> get_RecordingStarted(This,phResult) ) 

#define IMSVidStreamBufferRecordingControl_get_RecordingType(This,dwType)	\
    ( (This)->lpVtbl -> get_RecordingType(This,dwType) ) 

#define IMSVidStreamBufferRecordingControl_get_RecordingAttribute(This,pRecordingAttribute)	\
    ( (This)->lpVtbl -> get_RecordingAttribute(This,pRecordingAttribute) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSink_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSink_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSink */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("159DBB45-CD1B-4dab-83EA-5CB1F4F21D07")
    IMSVidStreamBufferSink : public IMSVidOutputDevice
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentRecorder( 
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReferenceRecorder( 
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SinkName( 
            /* [out][retval] */ __RPC__deref_out_opt BSTR *pName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SinkName( 
            /* [in] */ __RPC__in BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NameSetLock( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SBESink( 
            /* [out][retval] */ __RPC__deref_out_opt IUnknown **sbeConfig) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSink * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSink * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidStreamBufferSink * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidStreamBufferSink * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentRecorder )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferenceRecorder )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SinkName )( 
            IMSVidStreamBufferSink * This,
            /* [out][retval] */ __RPC__deref_out_opt BSTR *pName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkName )( 
            IMSVidStreamBufferSink * This,
            /* [in] */ __RPC__in BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NameSetLock )( 
            IMSVidStreamBufferSink * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SBESink )( 
            IMSVidStreamBufferSink * This,
            /* [out][retval] */ __RPC__deref_out_opt IUnknown **sbeConfig);
        
        END_INTERFACE
    } IMSVidStreamBufferSinkVtbl;

    interface IMSVidStreamBufferSink
    {
        CONST_VTBL struct IMSVidStreamBufferSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSink_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSink_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSink_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSink_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSink_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSink_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSink_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSink_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidStreamBufferSink_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidStreamBufferSink_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidStreamBufferSink_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidStreamBufferSink_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidStreamBufferSink_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidStreamBufferSink_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidStreamBufferSink_get_ContentRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ContentRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink_get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink_get_SinkName(This,pName)	\
    ( (This)->lpVtbl -> get_SinkName(This,pName) ) 

#define IMSVidStreamBufferSink_put_SinkName(This,Name)	\
    ( (This)->lpVtbl -> put_SinkName(This,Name) ) 

#define IMSVidStreamBufferSink_NameSetLock(This)	\
    ( (This)->lpVtbl -> NameSetLock(This) ) 

#define IMSVidStreamBufferSink_get_SBESink(This,sbeConfig)	\
    ( (This)->lpVtbl -> get_SBESink(This,sbeConfig) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSink_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSink2_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSink2_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSink2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2CA9FC63-C131-4E5A-955A-544A47C67146")
    IMSVidStreamBufferSink2 : public IMSVidStreamBufferSink
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockProfile( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSink2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSink2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSink2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSink2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidStreamBufferSink2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidStreamBufferSink2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentRecorder )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferenceRecorder )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SinkName )( 
            IMSVidStreamBufferSink2 * This,
            /* [out][retval] */ __RPC__deref_out_opt BSTR *pName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkName )( 
            IMSVidStreamBufferSink2 * This,
            /* [in] */ __RPC__in BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NameSetLock )( 
            IMSVidStreamBufferSink2 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SBESink )( 
            IMSVidStreamBufferSink2 * This,
            /* [out][retval] */ __RPC__deref_out_opt IUnknown **sbeConfig);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockProfile )( 
            IMSVidStreamBufferSink2 * This);
        
        END_INTERFACE
    } IMSVidStreamBufferSink2Vtbl;

    interface IMSVidStreamBufferSink2
    {
        CONST_VTBL struct IMSVidStreamBufferSink2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSink2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSink2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSink2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSink2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSink2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSink2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSink2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSink2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidStreamBufferSink2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidStreamBufferSink2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidStreamBufferSink2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidStreamBufferSink2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidStreamBufferSink2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidStreamBufferSink2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidStreamBufferSink2_get_ContentRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ContentRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink2_get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink2_get_SinkName(This,pName)	\
    ( (This)->lpVtbl -> get_SinkName(This,pName) ) 

#define IMSVidStreamBufferSink2_put_SinkName(This,Name)	\
    ( (This)->lpVtbl -> put_SinkName(This,Name) ) 

#define IMSVidStreamBufferSink2_NameSetLock(This)	\
    ( (This)->lpVtbl -> NameSetLock(This) ) 

#define IMSVidStreamBufferSink2_get_SBESink(This,sbeConfig)	\
    ( (This)->lpVtbl -> get_SBESink(This,sbeConfig) ) 


#define IMSVidStreamBufferSink2_UnlockProfile(This)	\
    ( (This)->lpVtbl -> UnlockProfile(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSink2_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSink3_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSink3_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSink3 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSink3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F8721D7-7D59-4D8B-99F5-A77775586BD5")
    IMSVidStreamBufferSink3 : public IMSVidStreamBufferSink2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinSeek( 
            /* [retval][out] */ __RPC__out LONG *pdwMin) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CCCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WSTCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AudioAnalysisFilter( 
            /* [in] */ __RPC__in BSTR szCLSID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioAnalysisFilter( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__AudioAnalysisFilter( 
            /* [in] */ GUID guid) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__AudioAnalysisFilter( 
            /* [retval][out] */ __RPC__out GUID *pGuid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VideoAnalysisFilter( 
            /* [in] */ __RPC__in BSTR szCLSID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoAnalysisFilter( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__VideoAnalysisFilter( 
            /* [in] */ GUID guid) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__VideoAnalysisFilter( 
            /* [retval][out] */ __RPC__out GUID *pGuid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataAnalysisFilter( 
            /* [in] */ __RPC__in BSTR szCLSID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataAnalysisFilter( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put__DataAnalysisFilter( 
            /* [in] */ GUID guid) = 0;
        
        virtual /* [restricted][hidden][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__DataAnalysisFilter( 
            /* [retval][out] */ __RPC__out GUID *pGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LicenseErrorCode( 
            /* [retval][out] */ __RPC__out HRESULT *hres) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSink3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSink3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSink3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSink3 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidStreamBufferSink3 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentRecorder )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ReferenceRecorder )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR pszFilename,
            /* [out][retval] */ __RPC__deref_out_opt IMSVidStreamBufferRecordingControl **pRecordingIUnknown);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SinkName )( 
            IMSVidStreamBufferSink3 * This,
            /* [out][retval] */ __RPC__deref_out_opt BSTR *pName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkName )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NameSetLock )( 
            IMSVidStreamBufferSink3 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SBESink )( 
            IMSVidStreamBufferSink3 * This,
            /* [out][retval] */ __RPC__deref_out_opt IUnknown **sbeConfig);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockProfile )( 
            IMSVidStreamBufferSink3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinSeek )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out LONG *pdwMin);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioCounter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoCounter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CCCounter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WSTCounter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AudioAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR szCLSID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID);
        
        /* [restricted][hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__AudioAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ GUID guid);
        
        /* [restricted][hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__AudioAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VideoAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR szCLSID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID);
        
        /* [restricted][hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__VideoAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ GUID guid);
        
        /* [restricted][hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__VideoAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ __RPC__in BSTR szCLSID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pszCLSID);
        
        /* [restricted][hidden][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put__DataAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [in] */ GUID guid);
        
        /* [restricted][hidden][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__DataAnalysisFilter )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out GUID *pGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseErrorCode )( 
            IMSVidStreamBufferSink3 * This,
            /* [retval][out] */ __RPC__out HRESULT *hres);
        
        END_INTERFACE
    } IMSVidStreamBufferSink3Vtbl;

    interface IMSVidStreamBufferSink3
    {
        CONST_VTBL struct IMSVidStreamBufferSink3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSink3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSink3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSink3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSink3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSink3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSink3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSink3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSink3_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidStreamBufferSink3_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidStreamBufferSink3_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidStreamBufferSink3_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidStreamBufferSink3_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidStreamBufferSink3_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink3_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidStreamBufferSink3_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSink3_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidStreamBufferSink3_get_ContentRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ContentRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink3_get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown)	\
    ( (This)->lpVtbl -> get_ReferenceRecorder(This,pszFilename,pRecordingIUnknown) ) 

#define IMSVidStreamBufferSink3_get_SinkName(This,pName)	\
    ( (This)->lpVtbl -> get_SinkName(This,pName) ) 

#define IMSVidStreamBufferSink3_put_SinkName(This,Name)	\
    ( (This)->lpVtbl -> put_SinkName(This,Name) ) 

#define IMSVidStreamBufferSink3_NameSetLock(This)	\
    ( (This)->lpVtbl -> NameSetLock(This) ) 

#define IMSVidStreamBufferSink3_get_SBESink(This,sbeConfig)	\
    ( (This)->lpVtbl -> get_SBESink(This,sbeConfig) ) 


#define IMSVidStreamBufferSink3_UnlockProfile(This)	\
    ( (This)->lpVtbl -> UnlockProfile(This) ) 


#define IMSVidStreamBufferSink3_SetMinSeek(This,pdwMin)	\
    ( (This)->lpVtbl -> SetMinSeek(This,pdwMin) ) 

#define IMSVidStreamBufferSink3_get_AudioCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_AudioCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSink3_get_VideoCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_VideoCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSink3_get_CCCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_CCCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSink3_get_WSTCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_WSTCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSink3_put_AudioAnalysisFilter(This,szCLSID)	\
    ( (This)->lpVtbl -> put_AudioAnalysisFilter(This,szCLSID) ) 

#define IMSVidStreamBufferSink3_get_AudioAnalysisFilter(This,pszCLSID)	\
    ( (This)->lpVtbl -> get_AudioAnalysisFilter(This,pszCLSID) ) 

#define IMSVidStreamBufferSink3_put__AudioAnalysisFilter(This,guid)	\
    ( (This)->lpVtbl -> put__AudioAnalysisFilter(This,guid) ) 

#define IMSVidStreamBufferSink3_get__AudioAnalysisFilter(This,pGuid)	\
    ( (This)->lpVtbl -> get__AudioAnalysisFilter(This,pGuid) ) 

#define IMSVidStreamBufferSink3_put_VideoAnalysisFilter(This,szCLSID)	\
    ( (This)->lpVtbl -> put_VideoAnalysisFilter(This,szCLSID) ) 

#define IMSVidStreamBufferSink3_get_VideoAnalysisFilter(This,pszCLSID)	\
    ( (This)->lpVtbl -> get_VideoAnalysisFilter(This,pszCLSID) ) 

#define IMSVidStreamBufferSink3_put__VideoAnalysisFilter(This,guid)	\
    ( (This)->lpVtbl -> put__VideoAnalysisFilter(This,guid) ) 

#define IMSVidStreamBufferSink3_get__VideoAnalysisFilter(This,pGuid)	\
    ( (This)->lpVtbl -> get__VideoAnalysisFilter(This,pGuid) ) 

#define IMSVidStreamBufferSink3_put_DataAnalysisFilter(This,szCLSID)	\
    ( (This)->lpVtbl -> put_DataAnalysisFilter(This,szCLSID) ) 

#define IMSVidStreamBufferSink3_get_DataAnalysisFilter(This,pszCLSID)	\
    ( (This)->lpVtbl -> get_DataAnalysisFilter(This,pszCLSID) ) 

#define IMSVidStreamBufferSink3_put__DataAnalysisFilter(This,guid)	\
    ( (This)->lpVtbl -> put__DataAnalysisFilter(This,guid) ) 

#define IMSVidStreamBufferSink3_get__DataAnalysisFilter(This,pGuid)	\
    ( (This)->lpVtbl -> get__DataAnalysisFilter(This,pGuid) ) 

#define IMSVidStreamBufferSink3_get_LicenseErrorCode(This,hres)	\
    ( (This)->lpVtbl -> get_LicenseErrorCode(This,hres) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSink3_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSinkEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSinkEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F798A36B-B05B-4bbe-9703-EAEA7D61CD51")
    IMSVidStreamBufferSinkEvent : public IMSVidOutputDeviceEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CertificateFailure( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CertificateSuccess( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteFailure( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSinkEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSinkEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSinkEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidStreamBufferSinkEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSinkEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSinkEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFailure )( 
            IMSVidStreamBufferSinkEvent * This);
        
        END_INTERFACE
    } IMSVidStreamBufferSinkEventVtbl;

    interface IMSVidStreamBufferSinkEvent
    {
        CONST_VTBL struct IMSVidStreamBufferSinkEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSinkEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSinkEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSinkEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSinkEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSinkEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSinkEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSinkEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSinkEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidStreamBufferSinkEvent_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSinkEvent_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSinkEvent_WriteFailure(This)	\
    ( (This)->lpVtbl -> WriteFailure(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSinkEvent2 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSinkEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3D7A5166-72D7-484b-A06F-286187B80CA1")
    IMSVidStreamBufferSinkEvent2 : public IMSVidStreamBufferSinkEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncryptionOn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncryptionOff( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSinkEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidStreamBufferSinkEvent2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFailure )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptionOn )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptionOff )( 
            IMSVidStreamBufferSinkEvent2 * This);
        
        END_INTERFACE
    } IMSVidStreamBufferSinkEvent2Vtbl;

    interface IMSVidStreamBufferSinkEvent2
    {
        CONST_VTBL struct IMSVidStreamBufferSinkEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSinkEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSinkEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSinkEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSinkEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSinkEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSinkEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSinkEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSinkEvent2_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidStreamBufferSinkEvent2_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSinkEvent2_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSinkEvent2_WriteFailure(This)	\
    ( (This)->lpVtbl -> WriteFailure(This) ) 


#define IMSVidStreamBufferSinkEvent2_EncryptionOn(This)	\
    ( (This)->lpVtbl -> EncryptionOn(This) ) 

#define IMSVidStreamBufferSinkEvent2_EncryptionOff(This)	\
    ( (This)->lpVtbl -> EncryptionOff(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSinkEvent3 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSinkEvent3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("735AD8D5-C259-48e9-81E7-D27953665B23")
    IMSVidStreamBufferSinkEvent3 : public IMSVidStreamBufferSinkEvent2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LicenseChange( 
            /* [in] */ long dwProt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSinkEvent3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFailure )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptionOn )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptionOff )( 
            IMSVidStreamBufferSinkEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LicenseChange )( 
            IMSVidStreamBufferSinkEvent3 * This,
            /* [in] */ long dwProt);
        
        END_INTERFACE
    } IMSVidStreamBufferSinkEvent3Vtbl;

    interface IMSVidStreamBufferSinkEvent3
    {
        CONST_VTBL struct IMSVidStreamBufferSinkEvent3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSinkEvent3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSinkEvent3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSinkEvent3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSinkEvent3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSinkEvent3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSinkEvent3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSinkEvent3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSinkEvent3_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidStreamBufferSinkEvent3_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSinkEvent3_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSinkEvent3_WriteFailure(This)	\
    ( (This)->lpVtbl -> WriteFailure(This) ) 


#define IMSVidStreamBufferSinkEvent3_EncryptionOn(This)	\
    ( (This)->lpVtbl -> EncryptionOn(This) ) 

#define IMSVidStreamBufferSinkEvent3_EncryptionOff(This)	\
    ( (This)->lpVtbl -> EncryptionOff(This) ) 


#define IMSVidStreamBufferSinkEvent3_LicenseChange(This,dwProt)	\
    ( (This)->lpVtbl -> LicenseChange(This,dwProt) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSource_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSource_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSource */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EB0C8CF9-6950-4772-87B1-47D11CF3A02F")
    IMSVidStreamBufferSource : public IMSVidFilePlayback
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Start( 
            /* [retval][out] */ __RPC__out long *lStart) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecordingAttribute( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRecordingAttribute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CurrentRatings( 
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *pBfEnAttr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MaxRatingsLevel( 
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enRating,
            /* [in] */ LONG lbfEnAttr) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockUnrated( 
            /* [in] */ VARIANT_BOOL bBlock) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UnratedDelay( 
            /* [in] */ long dwDelay) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SBESource( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **sbeFilter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSource * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSource * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidStreamBufferSource * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidStreamBufferSource * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidStreamBufferSource * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidStreamBufferSource * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FileName);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ __RPC__in BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Start )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__out long *lStart);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingAttribute )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRecordingAttribute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CurrentRatings )( 
            IMSVidStreamBufferSource * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *pBfEnAttr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MaxRatingsLevel )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enRating,
            /* [in] */ LONG lbfEnAttr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnrated )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ VARIANT_BOOL bBlock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UnratedDelay )( 
            IMSVidStreamBufferSource * This,
            /* [in] */ long dwDelay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SBESource )( 
            IMSVidStreamBufferSource * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **sbeFilter);
        
        END_INTERFACE
    } IMSVidStreamBufferSourceVtbl;

    interface IMSVidStreamBufferSource
    {
        CONST_VTBL struct IMSVidStreamBufferSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSource_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSource_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSource_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSource_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSource_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSource_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSource_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSource_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidStreamBufferSource_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidStreamBufferSource_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidStreamBufferSource_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidStreamBufferSource_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidStreamBufferSource_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSource_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidStreamBufferSource_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSource_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidStreamBufferSource_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidStreamBufferSource_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidStreamBufferSource_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidStreamBufferSource_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidStreamBufferSource_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidStreamBufferSource_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidStreamBufferSource_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidStreamBufferSource_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidStreamBufferSource_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidStreamBufferSource_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidStreamBufferSource_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidStreamBufferSource_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidStreamBufferSource_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidStreamBufferSource_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidStreamBufferSource_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidStreamBufferSource_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 


#define IMSVidStreamBufferSource_get_FileName(This,FileName)	\
    ( (This)->lpVtbl -> get_FileName(This,FileName) ) 

#define IMSVidStreamBufferSource_put_FileName(This,FileName)	\
    ( (This)->lpVtbl -> put_FileName(This,FileName) ) 


#define IMSVidStreamBufferSource_get_Start(This,lStart)	\
    ( (This)->lpVtbl -> get_Start(This,lStart) ) 

#define IMSVidStreamBufferSource_get_RecordingAttribute(This,pRecordingAttribute)	\
    ( (This)->lpVtbl -> get_RecordingAttribute(This,pRecordingAttribute) ) 

#define IMSVidStreamBufferSource_CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr)	\
    ( (This)->lpVtbl -> CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr) ) 

#define IMSVidStreamBufferSource_MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr)	\
    ( (This)->lpVtbl -> MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr) ) 

#define IMSVidStreamBufferSource_put_BlockUnrated(This,bBlock)	\
    ( (This)->lpVtbl -> put_BlockUnrated(This,bBlock) ) 

#define IMSVidStreamBufferSource_put_UnratedDelay(This,dwDelay)	\
    ( (This)->lpVtbl -> put_UnratedDelay(This,dwDelay) ) 

#define IMSVidStreamBufferSource_get_SBESource(This,sbeFilter)	\
    ( (This)->lpVtbl -> get_SBESource(This,sbeFilter) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSource_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSource2_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSource2_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSource2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSource2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4BA9059-B1CE-40D8-B9A0-D4EA4A9989D3")
    IMSVidStreamBufferSource2 : public IMSVidStreamBufferSource
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RateEx( 
            /* [in] */ double dwRate,
            /* [in] */ DWORD dwFramesPerSecond) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AudioCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VideoCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CCCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WSTCounter( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSource2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSource2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSource2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSource2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidStreamBufferSource2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsViewable )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in VARIANT *v,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfViewable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *View )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in VARIANT *v);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableResetOnStop )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableResetOnStop )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IMSVidStreamBufferSource2 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IMSVidStreamBufferSource2 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IMSVidStreamBufferSource2 * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanStep )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ VARIANT_BOOL fBackwards,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pfCan);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Step )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ long lStep);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Rate )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ double plRate);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rate )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out double *plRate);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CurrentPosition )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ long lPosition);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentPosition )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out long *lPosition);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionMode )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ PositionModeList lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionMode )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out PositionModeList *lPositionMode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out long *lLength);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *FileName);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ __RPC__in BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Start )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__out long *lStart);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecordingAttribute )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **pRecordingAttribute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CurrentRatings )( 
            IMSVidStreamBufferSource2 * This,
            /* [out] */ __RPC__out EnTvRat_System *pEnSystem,
            /* [out] */ __RPC__out EnTvRat_GenericLevel *pEnRating,
            /* [out] */ __RPC__out LONG *pBfEnAttr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MaxRatingsLevel )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ EnTvRat_System enSystem,
            /* [in] */ EnTvRat_GenericLevel enRating,
            /* [in] */ LONG lbfEnAttr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockUnrated )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ VARIANT_BOOL bBlock);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UnratedDelay )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ long dwDelay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SBESource )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **sbeFilter);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RateEx )( 
            IMSVidStreamBufferSource2 * This,
            /* [in] */ double dwRate,
            /* [in] */ DWORD dwFramesPerSecond);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AudioCounter )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VideoCounter )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CCCounter )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WSTCounter )( 
            IMSVidStreamBufferSource2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **ppUnk);
        
        END_INTERFACE
    } IMSVidStreamBufferSource2Vtbl;

    interface IMSVidStreamBufferSource2
    {
        CONST_VTBL struct IMSVidStreamBufferSource2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSource2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSource2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSource2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSource2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSource2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSource2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSource2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidStreamBufferSource2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidStreamBufferSource2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidStreamBufferSource2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidStreamBufferSource2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidStreamBufferSource2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidStreamBufferSource2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSource2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidStreamBufferSource2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidStreamBufferSource2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 


#define IMSVidStreamBufferSource2_IsViewable(This,v,pfViewable)	\
    ( (This)->lpVtbl -> IsViewable(This,v,pfViewable) ) 

#define IMSVidStreamBufferSource2_View(This,v)	\
    ( (This)->lpVtbl -> View(This,v) ) 


#define IMSVidStreamBufferSource2_get_EnableResetOnStop(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableResetOnStop(This,pVal) ) 

#define IMSVidStreamBufferSource2_put_EnableResetOnStop(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableResetOnStop(This,newVal) ) 

#define IMSVidStreamBufferSource2_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IMSVidStreamBufferSource2_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IMSVidStreamBufferSource2_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IMSVidStreamBufferSource2_get_CanStep(This,fBackwards,pfCan)	\
    ( (This)->lpVtbl -> get_CanStep(This,fBackwards,pfCan) ) 

#define IMSVidStreamBufferSource2_Step(This,lStep)	\
    ( (This)->lpVtbl -> Step(This,lStep) ) 

#define IMSVidStreamBufferSource2_put_Rate(This,plRate)	\
    ( (This)->lpVtbl -> put_Rate(This,plRate) ) 

#define IMSVidStreamBufferSource2_get_Rate(This,plRate)	\
    ( (This)->lpVtbl -> get_Rate(This,plRate) ) 

#define IMSVidStreamBufferSource2_put_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> put_CurrentPosition(This,lPosition) ) 

#define IMSVidStreamBufferSource2_get_CurrentPosition(This,lPosition)	\
    ( (This)->lpVtbl -> get_CurrentPosition(This,lPosition) ) 

#define IMSVidStreamBufferSource2_put_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> put_PositionMode(This,lPositionMode) ) 

#define IMSVidStreamBufferSource2_get_PositionMode(This,lPositionMode)	\
    ( (This)->lpVtbl -> get_PositionMode(This,lPositionMode) ) 

#define IMSVidStreamBufferSource2_get_Length(This,lLength)	\
    ( (This)->lpVtbl -> get_Length(This,lLength) ) 


#define IMSVidStreamBufferSource2_get_FileName(This,FileName)	\
    ( (This)->lpVtbl -> get_FileName(This,FileName) ) 

#define IMSVidStreamBufferSource2_put_FileName(This,FileName)	\
    ( (This)->lpVtbl -> put_FileName(This,FileName) ) 


#define IMSVidStreamBufferSource2_get_Start(This,lStart)	\
    ( (This)->lpVtbl -> get_Start(This,lStart) ) 

#define IMSVidStreamBufferSource2_get_RecordingAttribute(This,pRecordingAttribute)	\
    ( (This)->lpVtbl -> get_RecordingAttribute(This,pRecordingAttribute) ) 

#define IMSVidStreamBufferSource2_CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr)	\
    ( (This)->lpVtbl -> CurrentRatings(This,pEnSystem,pEnRating,pBfEnAttr) ) 

#define IMSVidStreamBufferSource2_MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr)	\
    ( (This)->lpVtbl -> MaxRatingsLevel(This,enSystem,enRating,lbfEnAttr) ) 

#define IMSVidStreamBufferSource2_put_BlockUnrated(This,bBlock)	\
    ( (This)->lpVtbl -> put_BlockUnrated(This,bBlock) ) 

#define IMSVidStreamBufferSource2_put_UnratedDelay(This,dwDelay)	\
    ( (This)->lpVtbl -> put_UnratedDelay(This,dwDelay) ) 

#define IMSVidStreamBufferSource2_get_SBESource(This,sbeFilter)	\
    ( (This)->lpVtbl -> get_SBESource(This,sbeFilter) ) 


#define IMSVidStreamBufferSource2_put_RateEx(This,dwRate,dwFramesPerSecond)	\
    ( (This)->lpVtbl -> put_RateEx(This,dwRate,dwFramesPerSecond) ) 

#define IMSVidStreamBufferSource2_get_AudioCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_AudioCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSource2_get_VideoCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_VideoCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSource2_get_CCCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_CCCounter(This,ppUnk) ) 

#define IMSVidStreamBufferSource2_get_WSTCounter(This,ppUnk)	\
    ( (This)->lpVtbl -> get_WSTCounter(This,ppUnk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSource2_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSourceEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSourceEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("50CE8A7D-9C28-4DA8-9042-CDFA7116F979")
    IMSVidStreamBufferSourceEvent : public IMSVidFilePlaybackEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CertificateFailure( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CertificateSuccess( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RatingsBlocked( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RatingsUnblocked( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RatingsChanged( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TimeHole( 
            /* [in] */ long StreamOffsetMS,
            /* [in] */ long SizeMS) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StaleDataRead( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ContentBecomingStale( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StaleFileDeleted( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSourceEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSourceEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSourceEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsBlocked )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsUnblocked )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsChanged )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TimeHole )( 
            IMSVidStreamBufferSourceEvent * This,
            /* [in] */ long StreamOffsetMS,
            /* [in] */ long SizeMS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleDataRead )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ContentBecomingStale )( 
            IMSVidStreamBufferSourceEvent * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleFileDeleted )( 
            IMSVidStreamBufferSourceEvent * This);
        
        END_INTERFACE
    } IMSVidStreamBufferSourceEventVtbl;

    interface IMSVidStreamBufferSourceEvent
    {
        CONST_VTBL struct IMSVidStreamBufferSourceEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSourceEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSourceEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSourceEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSourceEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSourceEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSourceEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSourceEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidStreamBufferSourceEvent_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 



#define IMSVidStreamBufferSourceEvent_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSourceEvent_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSourceEvent_RatingsBlocked(This)	\
    ( (This)->lpVtbl -> RatingsBlocked(This) ) 

#define IMSVidStreamBufferSourceEvent_RatingsUnblocked(This)	\
    ( (This)->lpVtbl -> RatingsUnblocked(This) ) 

#define IMSVidStreamBufferSourceEvent_RatingsChanged(This)	\
    ( (This)->lpVtbl -> RatingsChanged(This) ) 

#define IMSVidStreamBufferSourceEvent_TimeHole(This,StreamOffsetMS,SizeMS)	\
    ( (This)->lpVtbl -> TimeHole(This,StreamOffsetMS,SizeMS) ) 

#define IMSVidStreamBufferSourceEvent_StaleDataRead(This)	\
    ( (This)->lpVtbl -> StaleDataRead(This) ) 

#define IMSVidStreamBufferSourceEvent_ContentBecomingStale(This)	\
    ( (This)->lpVtbl -> ContentBecomingStale(This) ) 

#define IMSVidStreamBufferSourceEvent_StaleFileDeleted(This)	\
    ( (This)->lpVtbl -> StaleFileDeleted(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSourceEvent2 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSourceEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7AEF50CE-8E22-4BA8-BC06-A92A458B4EF2")
    IMSVidStreamBufferSourceEvent2 : public IMSVidStreamBufferSourceEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RateChange( 
            /* [in] */ double qwNewRate,
            /* [in] */ double qwOldRate) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSourceEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsBlocked )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsUnblocked )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsChanged )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TimeHole )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ long StreamOffsetMS,
            /* [in] */ long SizeMS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleDataRead )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ContentBecomingStale )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleFileDeleted )( 
            IMSVidStreamBufferSourceEvent2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RateChange )( 
            IMSVidStreamBufferSourceEvent2 * This,
            /* [in] */ double qwNewRate,
            /* [in] */ double qwOldRate);
        
        END_INTERFACE
    } IMSVidStreamBufferSourceEvent2Vtbl;

    interface IMSVidStreamBufferSourceEvent2
    {
        CONST_VTBL struct IMSVidStreamBufferSourceEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSourceEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSourceEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSourceEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSourceEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSourceEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSourceEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSourceEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidStreamBufferSourceEvent2_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 



#define IMSVidStreamBufferSourceEvent2_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSourceEvent2_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSourceEvent2_RatingsBlocked(This)	\
    ( (This)->lpVtbl -> RatingsBlocked(This) ) 

#define IMSVidStreamBufferSourceEvent2_RatingsUnblocked(This)	\
    ( (This)->lpVtbl -> RatingsUnblocked(This) ) 

#define IMSVidStreamBufferSourceEvent2_RatingsChanged(This)	\
    ( (This)->lpVtbl -> RatingsChanged(This) ) 

#define IMSVidStreamBufferSourceEvent2_TimeHole(This,StreamOffsetMS,SizeMS)	\
    ( (This)->lpVtbl -> TimeHole(This,StreamOffsetMS,SizeMS) ) 

#define IMSVidStreamBufferSourceEvent2_StaleDataRead(This)	\
    ( (This)->lpVtbl -> StaleDataRead(This) ) 

#define IMSVidStreamBufferSourceEvent2_ContentBecomingStale(This)	\
    ( (This)->lpVtbl -> ContentBecomingStale(This) ) 

#define IMSVidStreamBufferSourceEvent2_StaleFileDeleted(This)	\
    ( (This)->lpVtbl -> StaleFileDeleted(This) ) 


#define IMSVidStreamBufferSourceEvent2_RateChange(This,qwNewRate,qwOldRate)	\
    ( (This)->lpVtbl -> RateChange(This,qwNewRate,qwOldRate) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED__ */


#ifndef __IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED__
#define __IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED__

/* interface IMSVidStreamBufferSourceEvent3 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidStreamBufferSourceEvent3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CEABD6AB-9B90-4570-ADF1-3CE76E00A763")
    IMSVidStreamBufferSourceEvent3 : public IMSVidStreamBufferSourceEvent2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BroadcastEvent( 
            /* [in] */ __RPC__in BSTR Guid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BroadcastEventEx( 
            /* [in] */ __RPC__in BSTR Guid,
            /* [in] */ ULONG Param1,
            /* [in] */ ULONG Param2,
            /* [in] */ ULONG Param3,
            /* [in] */ ULONG Param4) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE COPPBlocked( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE COPPUnblocked( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ContentPrimarilyAudio( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidStreamBufferSourceEvent3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndOfMedia )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ __RPC__in_opt IMSVidPlayback *lpd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateFailure )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CertificateSuccess )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsBlocked )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsUnblocked )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RatingsChanged )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TimeHole )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ long StreamOffsetMS,
            /* [in] */ long SizeMS);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleDataRead )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ContentBecomingStale )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StaleFileDeleted )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RateChange )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ double qwNewRate,
            /* [in] */ double qwOldRate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BroadcastEvent )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ __RPC__in BSTR Guid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BroadcastEventEx )( 
            IMSVidStreamBufferSourceEvent3 * This,
            /* [in] */ __RPC__in BSTR Guid,
            /* [in] */ ULONG Param1,
            /* [in] */ ULONG Param2,
            /* [in] */ ULONG Param3,
            /* [in] */ ULONG Param4);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *COPPBlocked )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *COPPUnblocked )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ContentPrimarilyAudio )( 
            IMSVidStreamBufferSourceEvent3 * This);
        
        END_INTERFACE
    } IMSVidStreamBufferSourceEvent3Vtbl;

    interface IMSVidStreamBufferSourceEvent3
    {
        CONST_VTBL struct IMSVidStreamBufferSourceEvent3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidStreamBufferSourceEvent3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidStreamBufferSourceEvent3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidStreamBufferSourceEvent3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidStreamBufferSourceEvent3_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidStreamBufferSourceEvent3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidStreamBufferSourceEvent3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidStreamBufferSourceEvent3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 



#define IMSVidStreamBufferSourceEvent3_EndOfMedia(This,lpd)	\
    ( (This)->lpVtbl -> EndOfMedia(This,lpd) ) 



#define IMSVidStreamBufferSourceEvent3_CertificateFailure(This)	\
    ( (This)->lpVtbl -> CertificateFailure(This) ) 

#define IMSVidStreamBufferSourceEvent3_CertificateSuccess(This)	\
    ( (This)->lpVtbl -> CertificateSuccess(This) ) 

#define IMSVidStreamBufferSourceEvent3_RatingsBlocked(This)	\
    ( (This)->lpVtbl -> RatingsBlocked(This) ) 

#define IMSVidStreamBufferSourceEvent3_RatingsUnblocked(This)	\
    ( (This)->lpVtbl -> RatingsUnblocked(This) ) 

#define IMSVidStreamBufferSourceEvent3_RatingsChanged(This)	\
    ( (This)->lpVtbl -> RatingsChanged(This) ) 

#define IMSVidStreamBufferSourceEvent3_TimeHole(This,StreamOffsetMS,SizeMS)	\
    ( (This)->lpVtbl -> TimeHole(This,StreamOffsetMS,SizeMS) ) 

#define IMSVidStreamBufferSourceEvent3_StaleDataRead(This)	\
    ( (This)->lpVtbl -> StaleDataRead(This) ) 

#define IMSVidStreamBufferSourceEvent3_ContentBecomingStale(This)	\
    ( (This)->lpVtbl -> ContentBecomingStale(This) ) 

#define IMSVidStreamBufferSourceEvent3_StaleFileDeleted(This)	\
    ( (This)->lpVtbl -> StaleFileDeleted(This) ) 


#define IMSVidStreamBufferSourceEvent3_RateChange(This,qwNewRate,qwOldRate)	\
    ( (This)->lpVtbl -> RateChange(This,qwNewRate,qwOldRate) ) 


#define IMSVidStreamBufferSourceEvent3_BroadcastEvent(This,Guid)	\
    ( (This)->lpVtbl -> BroadcastEvent(This,Guid) ) 

#define IMSVidStreamBufferSourceEvent3_BroadcastEventEx(This,Guid,Param1,Param2,Param3,Param4)	\
    ( (This)->lpVtbl -> BroadcastEventEx(This,Guid,Param1,Param2,Param3,Param4) ) 

#define IMSVidStreamBufferSourceEvent3_COPPBlocked(This)	\
    ( (This)->lpVtbl -> COPPBlocked(This) ) 

#define IMSVidStreamBufferSourceEvent3_COPPUnblocked(This)	\
    ( (This)->lpVtbl -> COPPUnblocked(This) ) 

#define IMSVidStreamBufferSourceEvent3_ContentPrimarilyAudio(This)	\
    ( (This)->lpVtbl -> ContentPrimarilyAudio(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED__ */


#ifndef __IMSVidVideoRenderer2_INTERFACE_DEFINED__
#define __IMSVidVideoRenderer2_INTERFACE_DEFINED__

/* interface IMSVidVideoRenderer2 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidVideoRenderer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BDD5C1E-2810-4159-94BC-05511AE8549B")
    IMSVidVideoRenderer2 : public IMSVidVideoRenderer
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Allocator( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **AllocPresent) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__Allocator( 
            /* [retval][out] */ __RPC__deref_out_opt IVMRSurfaceAllocator **AllocPresent) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Allocator_ID( 
            /* [retval][out] */ __RPC__out long *ID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetAllocator( 
            /* [in] */ __RPC__in_opt IUnknown *AllocPresent,
            /* [defaultvalue][in] */ long ID = -1) = 0;
        
        virtual /* [restricted][hidden][id] */ HRESULT STDMETHODCALLTYPE _SetAllocator( 
            /* [in] */ __RPC__in_opt IVMRSurfaceAllocator *AllocPresent,
            /* [defaultvalue][in] */ long ID = -1) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SuppressEffects( 
            /* [in] */ VARIANT_BOOL bSuppress) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SuppressEffects( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoRenderer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoRenderer2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoRenderer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoRenderer2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidVideoRenderer2 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomCompositorClass )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *CompositorCLSID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomCompositorClass )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in BSTR CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositorClass )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out GUID *CompositorCLSID);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositorClass )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in REFCLSID CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositor )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRImageCompositor **Compositor);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositor )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IVMRImageCompositor *Compositor);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmap )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **MixerPictureDisp);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MixerBitmap )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRMixerBitmap **MixerPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmap )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__MixerBitmap )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in VMRALPHABITMAP *MixerPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapPositionRect )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **rDest);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapPositionRect )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapOpacity )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out int *opacity);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapOpacity )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ int opacity);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetupMixerBitmap )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp,
            /* [in] */ long Opacity,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceSize )( 
            IMSVidVideoRenderer2 * This,
            /* [out][retval] */ __RPC__out SourceSizeList *CurrentSize);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceSize )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ SourceSizeList NewSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverScan )( 
            IMSVidVideoRenderer2 * This,
            /* [out][retval] */ __RPC__out long *plPercent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverScan )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ long lPercent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvailableSourceRect )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxVidRect )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinVidRect )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClippedSourceRect )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClippedSourceRect )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IMSVidRect *pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsingOverlay )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsingOverlay )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ VARIANT_BOOL UseOverlayVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Capture )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **currentImage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FramesPerSecond )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecimateInput )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pDeci);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecimateInput )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ VARIANT_BOOL pDeci);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Allocator )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **AllocPresent);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Allocator )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRSurfaceAllocator **AllocPresent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Allocator_ID )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out long *ID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetAllocator )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IUnknown *AllocPresent,
            /* [defaultvalue][in] */ long ID);
        
        /* [restricted][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *_SetAllocator )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ __RPC__in_opt IVMRSurfaceAllocator *AllocPresent,
            /* [defaultvalue][in] */ long ID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SuppressEffects )( 
            IMSVidVideoRenderer2 * This,
            /* [in] */ VARIANT_BOOL bSuppress);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SuppressEffects )( 
            IMSVidVideoRenderer2 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress);
        
        END_INTERFACE
    } IMSVidVideoRenderer2Vtbl;

    interface IMSVidVideoRenderer2
    {
        CONST_VTBL struct IMSVidVideoRenderer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoRenderer2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoRenderer2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoRenderer2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoRenderer2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoRenderer2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoRenderer2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoRenderer2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoRenderer2_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidVideoRenderer2_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidVideoRenderer2_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidVideoRenderer2_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidVideoRenderer2_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidVideoRenderer2_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidVideoRenderer2_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidVideoRenderer2_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidVideoRenderer2_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidVideoRenderer2_get_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer2_put_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer2_get__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer2_put__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVideoRenderer2_get__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> get__CustomCompositor(This,Compositor) ) 

#define IMSVidVideoRenderer2_put__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> put__CustomCompositor(This,Compositor) ) 

#define IMSVidVideoRenderer2_get_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> get_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVideoRenderer2_get__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> get__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVideoRenderer2_put_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> put_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVideoRenderer2_put__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> put__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVideoRenderer2_get_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> get_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVideoRenderer2_put_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> put_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVideoRenderer2_get_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> get_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVideoRenderer2_put_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> put_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVideoRenderer2_SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest)	\
    ( (This)->lpVtbl -> SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest) ) 

#define IMSVidVideoRenderer2_get_SourceSize(This,CurrentSize)	\
    ( (This)->lpVtbl -> get_SourceSize(This,CurrentSize) ) 

#define IMSVidVideoRenderer2_put_SourceSize(This,NewSize)	\
    ( (This)->lpVtbl -> put_SourceSize(This,NewSize) ) 

#define IMSVidVideoRenderer2_get_OverScan(This,plPercent)	\
    ( (This)->lpVtbl -> get_OverScan(This,plPercent) ) 

#define IMSVidVideoRenderer2_put_OverScan(This,lPercent)	\
    ( (This)->lpVtbl -> put_OverScan(This,lPercent) ) 

#define IMSVidVideoRenderer2_get_AvailableSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_AvailableSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer2_get_MaxVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MaxVidRect(This,ppVidRect) ) 

#define IMSVidVideoRenderer2_get_MinVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MinVidRect(This,ppVidRect) ) 

#define IMSVidVideoRenderer2_get_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_ClippedSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer2_put_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> put_ClippedSourceRect(This,pRect) ) 

#define IMSVidVideoRenderer2_get_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> get_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVideoRenderer2_put_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> put_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVideoRenderer2_Capture(This,currentImage)	\
    ( (This)->lpVtbl -> Capture(This,currentImage) ) 

#define IMSVidVideoRenderer2_get_FramesPerSecond(This,pVal)	\
    ( (This)->lpVtbl -> get_FramesPerSecond(This,pVal) ) 

#define IMSVidVideoRenderer2_get_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> get_DecimateInput(This,pDeci) ) 

#define IMSVidVideoRenderer2_put_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> put_DecimateInput(This,pDeci) ) 


#define IMSVidVideoRenderer2_get_Allocator(This,AllocPresent)	\
    ( (This)->lpVtbl -> get_Allocator(This,AllocPresent) ) 

#define IMSVidVideoRenderer2_get__Allocator(This,AllocPresent)	\
    ( (This)->lpVtbl -> get__Allocator(This,AllocPresent) ) 

#define IMSVidVideoRenderer2_get_Allocator_ID(This,ID)	\
    ( (This)->lpVtbl -> get_Allocator_ID(This,ID) ) 

#define IMSVidVideoRenderer2_SetAllocator(This,AllocPresent,ID)	\
    ( (This)->lpVtbl -> SetAllocator(This,AllocPresent,ID) ) 

#define IMSVidVideoRenderer2__SetAllocator(This,AllocPresent,ID)	\
    ( (This)->lpVtbl -> _SetAllocator(This,AllocPresent,ID) ) 

#define IMSVidVideoRenderer2_put_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> put_SuppressEffects(This,bSuppress) ) 

#define IMSVidVideoRenderer2_get_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> get_SuppressEffects(This,bSuppress) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoRenderer2_INTERFACE_DEFINED__ */


#ifndef __IMSVidVideoRendererEvent2_INTERFACE_DEFINED__
#define __IMSVidVideoRendererEvent2_INTERFACE_DEFINED__

/* interface IMSVidVideoRendererEvent2 */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidVideoRendererEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7145ED66-4730-4fdb-8A53-FDE7508D3E5E")
    IMSVidVideoRendererEvent2 : public IMSVidOutputDeviceEvent
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OverlayUnavailable( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoRendererEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoRendererEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoRendererEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoRendererEvent2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoRendererEvent2 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoRendererEvent2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoRendererEvent2 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoRendererEvent2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidVideoRendererEvent2 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OverlayUnavailable )( 
            IMSVidVideoRendererEvent2 * This);
        
        END_INTERFACE
    } IMSVidVideoRendererEvent2Vtbl;

    interface IMSVidVideoRendererEvent2
    {
        CONST_VTBL struct IMSVidVideoRendererEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoRendererEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoRendererEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoRendererEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoRendererEvent2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoRendererEvent2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoRendererEvent2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoRendererEvent2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoRendererEvent2_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidVideoRendererEvent2_OverlayUnavailable(This)	\
    ( (This)->lpVtbl -> OverlayUnavailable(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoRendererEvent2_INTERFACE_DEFINED__ */


#ifndef __IMSVidVMR9_INTERFACE_DEFINED__
#define __IMSVidVMR9_INTERFACE_DEFINED__

/* interface IMSVidVMR9 */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidVMR9;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D58B0015-EBEF-44bb-BBDD-3F3699D76EA1")
    IMSVidVMR9 : public IMSVidVideoRenderer
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Allocator_ID( 
            /* [retval][out] */ __RPC__out long *ID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetAllocator( 
            /* [in] */ __RPC__in_opt IUnknown *AllocPresent,
            /* [defaultvalue][in] */ long ID = -1) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SuppressEffects( 
            /* [in] */ VARIANT_BOOL bSuppress) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SuppressEffects( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Allocator( 
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **AllocPresent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVMR9Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVMR9 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVMR9 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVMR9 * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVMR9 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVMR9 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidVMR9 * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidVMR9 * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomCompositorClass )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *CompositorCLSID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomCompositorClass )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in BSTR CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositorClass )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out GUID *CompositorCLSID);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositorClass )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in REFCLSID CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositor )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRImageCompositor **Compositor);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositor )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IVMRImageCompositor *Compositor);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmap )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **MixerPictureDisp);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MixerBitmap )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRMixerBitmap **MixerPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmap )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__MixerBitmap )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in VMRALPHABITMAP *MixerPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapPositionRect )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **rDest);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapPositionRect )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapOpacity )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out int *opacity);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapOpacity )( 
            IMSVidVMR9 * This,
            /* [in] */ int opacity);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetupMixerBitmap )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp,
            /* [in] */ long Opacity,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceSize )( 
            IMSVidVMR9 * This,
            /* [out][retval] */ __RPC__out SourceSizeList *CurrentSize);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceSize )( 
            IMSVidVMR9 * This,
            /* [in] */ SourceSizeList NewSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverScan )( 
            IMSVidVMR9 * This,
            /* [out][retval] */ __RPC__out long *plPercent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverScan )( 
            IMSVidVMR9 * This,
            /* [in] */ long lPercent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvailableSourceRect )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxVidRect )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinVidRect )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClippedSourceRect )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClippedSourceRect )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IMSVidRect *pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsingOverlay )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsingOverlay )( 
            IMSVidVMR9 * This,
            /* [in] */ VARIANT_BOOL UseOverlayVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Capture )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **currentImage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FramesPerSecond )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecimateInput )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pDeci);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecimateInput )( 
            IMSVidVMR9 * This,
            /* [in] */ VARIANT_BOOL pDeci);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Allocator_ID )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out long *ID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetAllocator )( 
            IMSVidVMR9 * This,
            /* [in] */ __RPC__in_opt IUnknown *AllocPresent,
            /* [defaultvalue][in] */ long ID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SuppressEffects )( 
            IMSVidVMR9 * This,
            /* [in] */ VARIANT_BOOL bSuppress);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SuppressEffects )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Allocator )( 
            IMSVidVMR9 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **AllocPresent);
        
        END_INTERFACE
    } IMSVidVMR9Vtbl;

    interface IMSVidVMR9
    {
        CONST_VTBL struct IMSVidVMR9Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVMR9_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVMR9_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVMR9_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVMR9_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVMR9_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVMR9_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVMR9_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVMR9_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidVMR9_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidVMR9_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidVMR9_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidVMR9_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidVMR9_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidVMR9_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidVMR9_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidVMR9_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidVMR9_get_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVMR9_put_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVMR9_get__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVMR9_put__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidVMR9_get__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> get__CustomCompositor(This,Compositor) ) 

#define IMSVidVMR9_put__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> put__CustomCompositor(This,Compositor) ) 

#define IMSVidVMR9_get_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> get_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVMR9_get__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> get__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVMR9_put_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> put_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidVMR9_put__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> put__MixerBitmap(This,MixerPicture) ) 

#define IMSVidVMR9_get_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> get_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVMR9_put_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> put_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidVMR9_get_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> get_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVMR9_put_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> put_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidVMR9_SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest)	\
    ( (This)->lpVtbl -> SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest) ) 

#define IMSVidVMR9_get_SourceSize(This,CurrentSize)	\
    ( (This)->lpVtbl -> get_SourceSize(This,CurrentSize) ) 

#define IMSVidVMR9_put_SourceSize(This,NewSize)	\
    ( (This)->lpVtbl -> put_SourceSize(This,NewSize) ) 

#define IMSVidVMR9_get_OverScan(This,plPercent)	\
    ( (This)->lpVtbl -> get_OverScan(This,plPercent) ) 

#define IMSVidVMR9_put_OverScan(This,lPercent)	\
    ( (This)->lpVtbl -> put_OverScan(This,lPercent) ) 

#define IMSVidVMR9_get_AvailableSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_AvailableSourceRect(This,pRect) ) 

#define IMSVidVMR9_get_MaxVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MaxVidRect(This,ppVidRect) ) 

#define IMSVidVMR9_get_MinVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MinVidRect(This,ppVidRect) ) 

#define IMSVidVMR9_get_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_ClippedSourceRect(This,pRect) ) 

#define IMSVidVMR9_put_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> put_ClippedSourceRect(This,pRect) ) 

#define IMSVidVMR9_get_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> get_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVMR9_put_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> put_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidVMR9_Capture(This,currentImage)	\
    ( (This)->lpVtbl -> Capture(This,currentImage) ) 

#define IMSVidVMR9_get_FramesPerSecond(This,pVal)	\
    ( (This)->lpVtbl -> get_FramesPerSecond(This,pVal) ) 

#define IMSVidVMR9_get_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> get_DecimateInput(This,pDeci) ) 

#define IMSVidVMR9_put_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> put_DecimateInput(This,pDeci) ) 


#define IMSVidVMR9_get_Allocator_ID(This,ID)	\
    ( (This)->lpVtbl -> get_Allocator_ID(This,ID) ) 

#define IMSVidVMR9_SetAllocator(This,AllocPresent,ID)	\
    ( (This)->lpVtbl -> SetAllocator(This,AllocPresent,ID) ) 

#define IMSVidVMR9_put_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> put_SuppressEffects(This,bSuppress) ) 

#define IMSVidVMR9_get_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> get_SuppressEffects(This,bSuppress) ) 

#define IMSVidVMR9_get_Allocator(This,AllocPresent)	\
    ( (This)->lpVtbl -> get_Allocator(This,AllocPresent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVMR9_INTERFACE_DEFINED__ */


#ifndef __IMSVidEVR_INTERFACE_DEFINED__
#define __IMSVidEVR_INTERFACE_DEFINED__

/* interface IMSVidEVR */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidEVR;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15E496AE-82A8-4cf9-A6B6-C561DC60398F")
    IMSVidEVR : public IMSVidVideoRenderer
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Presenter( 
            /* [retval][out] */ __RPC__deref_out_opt IMFVideoPresenter **ppAllocPresent) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Presenter( 
            /* [in] */ __RPC__in_opt IMFVideoPresenter *pAllocPresent) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SuppressEffects( 
            /* [in] */ VARIANT_BOOL bSuppress) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SuppressEffects( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidEVRVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidEVR * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidEVR * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidEVR * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidEVR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidEVR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidEVR * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidEVR * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomCompositorClass )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *CompositorCLSID);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomCompositorClass )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in BSTR CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositorClass )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out GUID *CompositorCLSID);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositorClass )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in REFCLSID CompositorCLSID);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__CustomCompositor )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRImageCompositor **Compositor);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__CustomCompositor )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IVMRImageCompositor *Compositor);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmap )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **MixerPictureDisp);
        
        /* [id][restricted][hidden][propget] */ HRESULT ( STDMETHODCALLTYPE *get__MixerBitmap )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IVMRMixerBitmap **MixerPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmap )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp);
        
        /* [id][restricted][hidden][propput] */ HRESULT ( STDMETHODCALLTYPE *put__MixerBitmap )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in VMRALPHABITMAP *MixerPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapPositionRect )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **rDest);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapPositionRect )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MixerBitmapOpacity )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out int *opacity);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MixerBitmapOpacity )( 
            IMSVidEVR * This,
            /* [in] */ int opacity);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetupMixerBitmap )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IPictureDisp *MixerPictureDisp,
            /* [in] */ long Opacity,
            /* [in] */ __RPC__in_opt IMSVidRect *rDest);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SourceSize )( 
            IMSVidEVR * This,
            /* [out][retval] */ __RPC__out SourceSizeList *CurrentSize);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SourceSize )( 
            IMSVidEVR * This,
            /* [in] */ SourceSizeList NewSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OverScan )( 
            IMSVidEVR * This,
            /* [out][retval] */ __RPC__out long *plPercent);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OverScan )( 
            IMSVidEVR * This,
            /* [in] */ long lPercent);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AvailableSourceRect )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxVidRect )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinVidRect )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **ppVidRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClippedSourceRect )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidRect **pRect);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClippedSourceRect )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IMSVidRect *pRect);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsingOverlay )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *UseOverlayVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsingOverlay )( 
            IMSVidEVR * This,
            /* [in] */ VARIANT_BOOL UseOverlayVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Capture )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IPictureDisp **currentImage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FramesPerSecond )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DecimateInput )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pDeci);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DecimateInput )( 
            IMSVidEVR * This,
            /* [in] */ VARIANT_BOOL pDeci);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Presenter )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__deref_out_opt IMFVideoPresenter **ppAllocPresent);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Presenter )( 
            IMSVidEVR * This,
            /* [in] */ __RPC__in_opt IMFVideoPresenter *pAllocPresent);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SuppressEffects )( 
            IMSVidEVR * This,
            /* [in] */ VARIANT_BOOL bSuppress);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SuppressEffects )( 
            IMSVidEVR * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *bSuppress);
        
        END_INTERFACE
    } IMSVidEVRVtbl;

    interface IMSVidEVR
    {
        CONST_VTBL struct IMSVidEVRVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidEVR_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidEVR_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidEVR_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidEVR_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidEVR_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidEVR_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidEVR_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidEVR_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidEVR_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidEVR_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidEVR_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidEVR_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidEVR_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidEVR_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidEVR_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidEVR_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidEVR_get_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidEVR_put_CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put_CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidEVR_get__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> get__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidEVR_put__CustomCompositorClass(This,CompositorCLSID)	\
    ( (This)->lpVtbl -> put__CustomCompositorClass(This,CompositorCLSID) ) 

#define IMSVidEVR_get__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> get__CustomCompositor(This,Compositor) ) 

#define IMSVidEVR_put__CustomCompositor(This,Compositor)	\
    ( (This)->lpVtbl -> put__CustomCompositor(This,Compositor) ) 

#define IMSVidEVR_get_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> get_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidEVR_get__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> get__MixerBitmap(This,MixerPicture) ) 

#define IMSVidEVR_put_MixerBitmap(This,MixerPictureDisp)	\
    ( (This)->lpVtbl -> put_MixerBitmap(This,MixerPictureDisp) ) 

#define IMSVidEVR_put__MixerBitmap(This,MixerPicture)	\
    ( (This)->lpVtbl -> put__MixerBitmap(This,MixerPicture) ) 

#define IMSVidEVR_get_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> get_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidEVR_put_MixerBitmapPositionRect(This,rDest)	\
    ( (This)->lpVtbl -> put_MixerBitmapPositionRect(This,rDest) ) 

#define IMSVidEVR_get_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> get_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidEVR_put_MixerBitmapOpacity(This,opacity)	\
    ( (This)->lpVtbl -> put_MixerBitmapOpacity(This,opacity) ) 

#define IMSVidEVR_SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest)	\
    ( (This)->lpVtbl -> SetupMixerBitmap(This,MixerPictureDisp,Opacity,rDest) ) 

#define IMSVidEVR_get_SourceSize(This,CurrentSize)	\
    ( (This)->lpVtbl -> get_SourceSize(This,CurrentSize) ) 

#define IMSVidEVR_put_SourceSize(This,NewSize)	\
    ( (This)->lpVtbl -> put_SourceSize(This,NewSize) ) 

#define IMSVidEVR_get_OverScan(This,plPercent)	\
    ( (This)->lpVtbl -> get_OverScan(This,plPercent) ) 

#define IMSVidEVR_put_OverScan(This,lPercent)	\
    ( (This)->lpVtbl -> put_OverScan(This,lPercent) ) 

#define IMSVidEVR_get_AvailableSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_AvailableSourceRect(This,pRect) ) 

#define IMSVidEVR_get_MaxVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MaxVidRect(This,ppVidRect) ) 

#define IMSVidEVR_get_MinVidRect(This,ppVidRect)	\
    ( (This)->lpVtbl -> get_MinVidRect(This,ppVidRect) ) 

#define IMSVidEVR_get_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> get_ClippedSourceRect(This,pRect) ) 

#define IMSVidEVR_put_ClippedSourceRect(This,pRect)	\
    ( (This)->lpVtbl -> put_ClippedSourceRect(This,pRect) ) 

#define IMSVidEVR_get_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> get_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidEVR_put_UsingOverlay(This,UseOverlayVal)	\
    ( (This)->lpVtbl -> put_UsingOverlay(This,UseOverlayVal) ) 

#define IMSVidEVR_Capture(This,currentImage)	\
    ( (This)->lpVtbl -> Capture(This,currentImage) ) 

#define IMSVidEVR_get_FramesPerSecond(This,pVal)	\
    ( (This)->lpVtbl -> get_FramesPerSecond(This,pVal) ) 

#define IMSVidEVR_get_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> get_DecimateInput(This,pDeci) ) 

#define IMSVidEVR_put_DecimateInput(This,pDeci)	\
    ( (This)->lpVtbl -> put_DecimateInput(This,pDeci) ) 


#define IMSVidEVR_get_Presenter(This,ppAllocPresent)	\
    ( (This)->lpVtbl -> get_Presenter(This,ppAllocPresent) ) 

#define IMSVidEVR_put_Presenter(This,pAllocPresent)	\
    ( (This)->lpVtbl -> put_Presenter(This,pAllocPresent) ) 

#define IMSVidEVR_put_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> put_SuppressEffects(This,bSuppress) ) 

#define IMSVidEVR_get_SuppressEffects(This,bSuppress)	\
    ( (This)->lpVtbl -> get_SuppressEffects(This,bSuppress) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidEVR_INTERFACE_DEFINED__ */


#ifndef __IMSVidEVREvent_INTERFACE_DEFINED__
#define __IMSVidEVREvent_INTERFACE_DEFINED__

/* interface IMSVidEVREvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidEVREvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("349ABB10-883C-4F22-8714-CECAEEE45D62")
    IMSVidEVREvent : public IMSVidOutputDeviceEvent
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnUserEvent( 
            /* [in] */ long lEventCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidEVREventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidEVREvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidEVREvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidEVREvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidEVREvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidEVREvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidEVREvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidEVREvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidEVREvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OnUserEvent )( 
            IMSVidEVREvent * This,
            /* [in] */ long lEventCode);
        
        END_INTERFACE
    } IMSVidEVREventVtbl;

    interface IMSVidEVREvent
    {
        CONST_VTBL struct IMSVidEVREventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidEVREvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidEVREvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidEVREvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidEVREvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidEVREvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidEVREvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidEVREvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidEVREvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#define IMSVidEVREvent_OnUserEvent(This,lEventCode)	\
    ( (This)->lpVtbl -> OnUserEvent(This,lEventCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidEVREvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidAudioRenderer_INTERFACE_DEFINED__
#define __IMSVidAudioRenderer_INTERFACE_DEFINED__

/* interface IMSVidAudioRenderer */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidAudioRenderer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B0353F-A4C8-11d2-B634-00C04F79498E")
    IMSVidAudioRenderer : public IMSVidOutputDevice
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Volume( 
            /* [in] */ long lVol) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Volume( 
            /* [out][retval] */ __RPC__out long *lVol) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Balance( 
            /* [in] */ long lBal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Balance( 
            /* [out][retval] */ __RPC__out long *lBal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAudioRendererVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAudioRenderer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAudioRenderer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAudioRenderer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAudioRenderer * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAudioRenderer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAudioRenderer * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAudioRenderer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Name);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__out long *Status);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IMSVidAudioRenderer * This,
            /* [in] */ VARIANT_BOOL Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IMSVidAudioRenderer * This,
            /* [out][retval] */ __RPC__out VARIANT_BOOL *Power);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Category )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Guid);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClassID )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *Clsid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__Category )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__out GUID *Guid);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__ClassID )( 
            IMSVidAudioRenderer * This,
            /* [retval][out] */ __RPC__out GUID *Clsid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEqualDevice )( 
            IMSVidAudioRenderer * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *Device,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *IsEqual);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Volume )( 
            IMSVidAudioRenderer * This,
            /* [in] */ long lVol);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Volume )( 
            IMSVidAudioRenderer * This,
            /* [out][retval] */ __RPC__out long *lVol);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Balance )( 
            IMSVidAudioRenderer * This,
            /* [in] */ long lBal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Balance )( 
            IMSVidAudioRenderer * This,
            /* [out][retval] */ __RPC__out long *lBal);
        
        END_INTERFACE
    } IMSVidAudioRendererVtbl;

    interface IMSVidAudioRenderer
    {
        CONST_VTBL struct IMSVidAudioRendererVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAudioRenderer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAudioRenderer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAudioRenderer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAudioRenderer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAudioRenderer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAudioRenderer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAudioRenderer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidAudioRenderer_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IMSVidAudioRenderer_get_Status(This,Status)	\
    ( (This)->lpVtbl -> get_Status(This,Status) ) 

#define IMSVidAudioRenderer_put_Power(This,Power)	\
    ( (This)->lpVtbl -> put_Power(This,Power) ) 

#define IMSVidAudioRenderer_get_Power(This,Power)	\
    ( (This)->lpVtbl -> get_Power(This,Power) ) 

#define IMSVidAudioRenderer_get_Category(This,Guid)	\
    ( (This)->lpVtbl -> get_Category(This,Guid) ) 

#define IMSVidAudioRenderer_get_ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get_ClassID(This,Clsid) ) 

#define IMSVidAudioRenderer_get__Category(This,Guid)	\
    ( (This)->lpVtbl -> get__Category(This,Guid) ) 

#define IMSVidAudioRenderer_get__ClassID(This,Clsid)	\
    ( (This)->lpVtbl -> get__ClassID(This,Clsid) ) 

#define IMSVidAudioRenderer_IsEqualDevice(This,Device,IsEqual)	\
    ( (This)->lpVtbl -> IsEqualDevice(This,Device,IsEqual) ) 



#define IMSVidAudioRenderer_put_Volume(This,lVol)	\
    ( (This)->lpVtbl -> put_Volume(This,lVol) ) 

#define IMSVidAudioRenderer_get_Volume(This,lVol)	\
    ( (This)->lpVtbl -> get_Volume(This,lVol) ) 

#define IMSVidAudioRenderer_put_Balance(This,lBal)	\
    ( (This)->lpVtbl -> put_Balance(This,lBal) ) 

#define IMSVidAudioRenderer_get_Balance(This,lBal)	\
    ( (This)->lpVtbl -> get_Balance(This,lBal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAudioRenderer_INTERFACE_DEFINED__ */


#ifndef __IMSVidAudioRendererEvent_INTERFACE_DEFINED__
#define __IMSVidAudioRendererEvent_INTERFACE_DEFINED__

/* interface IMSVidAudioRendererEvent */
/* [unique][helpstring][uuid][hidden][oleautomation][object] */ 


EXTERN_C const IID IID_IMSVidAudioRendererEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37B03541-A4C8-11d2-B634-00C04F79498E")
    IMSVidAudioRendererEvent : public IMSVidOutputDeviceEvent
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAudioRendererEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAudioRendererEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAudioRendererEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAudioRendererEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAudioRendererEvent * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAudioRendererEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAudioRendererEvent * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAudioRendererEvent * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StateChange )( 
            IMSVidAudioRendererEvent * This,
            /* [in] */ __RPC__in_opt IMSVidDevice *lpd,
            /* [in] */ long oldState,
            /* [in] */ long newState);
        
        END_INTERFACE
    } IMSVidAudioRendererEventVtbl;

    interface IMSVidAudioRendererEvent
    {
        CONST_VTBL struct IMSVidAudioRendererEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAudioRendererEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAudioRendererEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAudioRendererEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAudioRendererEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAudioRendererEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAudioRendererEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAudioRendererEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidAudioRendererEvent_StateChange(This,lpd,oldState,newState)	\
    ( (This)->lpVtbl -> StateChange(This,lpd,oldState,newState) ) 



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAudioRendererEvent_INTERFACE_DEFINED__ */


#ifndef __IMSVidInputDevices_INTERFACE_DEFINED__
#define __IMSVidInputDevices_INTERFACE_DEFINED__

/* interface IMSVidInputDevices */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidInputDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5702CD1-9B79-11d3-B654-00C04F79498E")
    IMSVidInputDevices : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *lCount) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidInputDevice **pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IMSVidInputDevice *pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidInputDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidInputDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidInputDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidInputDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidInputDevices * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidInputDevices * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidInputDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidInputDevices * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMSVidInputDevices * This,
            /* [retval][out] */ __RPC__out long *lCount);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMSVidInputDevices * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMSVidInputDevices * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidInputDevice **pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMSVidInputDevices * This,
            /* [in] */ __RPC__in_opt IMSVidInputDevice *pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMSVidInputDevices * This,
            /* [in] */ VARIANT v);
        
        END_INTERFACE
    } IMSVidInputDevicesVtbl;

    interface IMSVidInputDevices
    {
        CONST_VTBL struct IMSVidInputDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidInputDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidInputDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidInputDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidInputDevices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidInputDevices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidInputDevices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidInputDevices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidInputDevices_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IMSVidInputDevices_get__NewEnum(This,pD)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pD) ) 

#define IMSVidInputDevices_get_Item(This,v,pDB)	\
    ( (This)->lpVtbl -> get_Item(This,v,pDB) ) 

#define IMSVidInputDevices_Add(This,pDB)	\
    ( (This)->lpVtbl -> Add(This,pDB) ) 

#define IMSVidInputDevices_Remove(This,v)	\
    ( (This)->lpVtbl -> Remove(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidInputDevices_INTERFACE_DEFINED__ */


#ifndef __IMSVidOutputDevices_INTERFACE_DEFINED__
#define __IMSVidOutputDevices_INTERFACE_DEFINED__

/* interface IMSVidOutputDevices */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidOutputDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5702CD2-9B79-11d3-B654-00C04F79498E")
    IMSVidOutputDevices : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *lCount) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidOutputDevice **pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IMSVidOutputDevice *pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidOutputDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidOutputDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidOutputDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidOutputDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidOutputDevices * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidOutputDevices * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidOutputDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidOutputDevices * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMSVidOutputDevices * This,
            /* [retval][out] */ __RPC__out long *lCount);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMSVidOutputDevices * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMSVidOutputDevices * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidOutputDevice **pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMSVidOutputDevices * This,
            /* [in] */ __RPC__in_opt IMSVidOutputDevice *pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMSVidOutputDevices * This,
            /* [in] */ VARIANT v);
        
        END_INTERFACE
    } IMSVidOutputDevicesVtbl;

    interface IMSVidOutputDevices
    {
        CONST_VTBL struct IMSVidOutputDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidOutputDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidOutputDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidOutputDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidOutputDevices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidOutputDevices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidOutputDevices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidOutputDevices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidOutputDevices_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IMSVidOutputDevices_get__NewEnum(This,pD)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pD) ) 

#define IMSVidOutputDevices_get_Item(This,v,pDB)	\
    ( (This)->lpVtbl -> get_Item(This,v,pDB) ) 

#define IMSVidOutputDevices_Add(This,pDB)	\
    ( (This)->lpVtbl -> Add(This,pDB) ) 

#define IMSVidOutputDevices_Remove(This,v)	\
    ( (This)->lpVtbl -> Remove(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidOutputDevices_INTERFACE_DEFINED__ */


#ifndef __IMSVidVideoRendererDevices_INTERFACE_DEFINED__
#define __IMSVidVideoRendererDevices_INTERFACE_DEFINED__

/* interface IMSVidVideoRendererDevices */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidVideoRendererDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5702CD3-9B79-11d3-B654-00C04F79498E")
    IMSVidVideoRendererDevices : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *lCount) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidVideoRenderer **pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IMSVidVideoRenderer *pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidVideoRendererDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidVideoRendererDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidVideoRendererDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidVideoRendererDevices * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMSVidVideoRendererDevices * This,
            /* [retval][out] */ __RPC__out long *lCount);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMSVidVideoRendererDevices * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidVideoRenderer **pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ __RPC__in_opt IMSVidVideoRenderer *pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMSVidVideoRendererDevices * This,
            /* [in] */ VARIANT v);
        
        END_INTERFACE
    } IMSVidVideoRendererDevicesVtbl;

    interface IMSVidVideoRendererDevices
    {
        CONST_VTBL struct IMSVidVideoRendererDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidVideoRendererDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidVideoRendererDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidVideoRendererDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidVideoRendererDevices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidVideoRendererDevices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidVideoRendererDevices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidVideoRendererDevices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidVideoRendererDevices_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IMSVidVideoRendererDevices_get__NewEnum(This,pD)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pD) ) 

#define IMSVidVideoRendererDevices_get_Item(This,v,pDB)	\
    ( (This)->lpVtbl -> get_Item(This,v,pDB) ) 

#define IMSVidVideoRendererDevices_Add(This,pDB)	\
    ( (This)->lpVtbl -> Add(This,pDB) ) 

#define IMSVidVideoRendererDevices_Remove(This,v)	\
    ( (This)->lpVtbl -> Remove(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidVideoRendererDevices_INTERFACE_DEFINED__ */


#ifndef __IMSVidAudioRendererDevices_INTERFACE_DEFINED__
#define __IMSVidAudioRendererDevices_INTERFACE_DEFINED__

/* interface IMSVidAudioRendererDevices */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidAudioRendererDevices;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5702CD4-9B79-11d3-B654-00C04F79498E")
    IMSVidAudioRendererDevices : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *lCount) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidAudioRenderer **pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IMSVidAudioRenderer *pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidAudioRendererDevicesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidAudioRendererDevices * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidAudioRendererDevices * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidAudioRendererDevices * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMSVidAudioRendererDevices * This,
            /* [retval][out] */ __RPC__out long *lCount);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMSVidAudioRendererDevices * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidAudioRenderer **pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ __RPC__in_opt IMSVidAudioRenderer *pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMSVidAudioRendererDevices * This,
            /* [in] */ VARIANT v);
        
        END_INTERFACE
    } IMSVidAudioRendererDevicesVtbl;

    interface IMSVidAudioRendererDevices
    {
        CONST_VTBL struct IMSVidAudioRendererDevicesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidAudioRendererDevices_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidAudioRendererDevices_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidAudioRendererDevices_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidAudioRendererDevices_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidAudioRendererDevices_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidAudioRendererDevices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidAudioRendererDevices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidAudioRendererDevices_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IMSVidAudioRendererDevices_get__NewEnum(This,pD)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pD) ) 

#define IMSVidAudioRendererDevices_get_Item(This,v,pDB)	\
    ( (This)->lpVtbl -> get_Item(This,v,pDB) ) 

#define IMSVidAudioRendererDevices_Add(This,pDB)	\
    ( (This)->lpVtbl -> Add(This,pDB) ) 

#define IMSVidAudioRendererDevices_Remove(This,v)	\
    ( (This)->lpVtbl -> Remove(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidAudioRendererDevices_INTERFACE_DEFINED__ */


#ifndef __IMSVidFeatures_INTERFACE_DEFINED__
#define __IMSVidFeatures_INTERFACE_DEFINED__

/* interface IMSVidFeatures */
/* [unique][helpstring][uuid][hidden][oleautomation][dual][object] */ 


EXTERN_C const IID IID_IMSVidFeatures;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C5702CD5-9B79-11d3-B654-00C04F79498E")
    IMSVidFeatures : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ __RPC__out long *lCount) = 0;
        
        virtual /* [restricted][hidden][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidFeature **pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ __RPC__in_opt IMSVidFeature *pDB) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMSVidFeaturesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMSVidFeatures * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMSVidFeatures * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMSVidFeatures * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMSVidFeatures * This,
            /* [out] */ __RPC__out UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMSVidFeatures * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMSVidFeatures * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMSVidFeatures * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMSVidFeatures * This,
            /* [retval][out] */ __RPC__out long *lCount);
        
        /* [restricted][hidden][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMSVidFeatures * This,
            /* [retval][out] */ __RPC__deref_out_opt IEnumVARIANT **pD);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMSVidFeatures * This,
            /* [in] */ VARIANT v,
            /* [retval][out] */ __RPC__deref_out_opt IMSVidFeature **pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMSVidFeatures * This,
            /* [in] */ __RPC__in_opt IMSVidFeature *pDB);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMSVidFeatures * This,
            /* [in] */ VARIANT v);
        
        END_INTERFACE
    } IMSVidFeaturesVtbl;

    interface IMSVidFeatures
    {
        CONST_VTBL struct IMSVidFeaturesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMSVidFeatures_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMSVidFeatures_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMSVidFeatures_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMSVidFeatures_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMSVidFeatures_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMSVidFeatures_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMSVidFeatures_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMSVidFeatures_get_Count(This,lCount)	\
    ( (This)->lpVtbl -> get_Count(This,lCount) ) 

#define IMSVidFeatures_get__NewEnum(This,pD)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pD) ) 

#define IMSVidFeatures_get_Item(This,v,pDB)	\
    ( (This)->lpVtbl -> get_Item(This,v,pDB) ) 

#define IMSVidFeatures_Add(This,pDB)	\
    ( (This)->lpVtbl -> Add(This,pDB) ) 

#define IMSVidFeatures_Remove(This,v)	\
    ( (This)->lpVtbl -> Remove(This,v) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMSVidFeatures_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HDC_UserSize64(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal64(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal64(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree64(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HWND_UserSize64(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal64(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal64(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree64(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



