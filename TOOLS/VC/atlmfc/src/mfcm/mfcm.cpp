// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// mfcm.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _M_CEE
#error This file must not be built managed because it contains DllMain.
#endif

static AFX_EXTENSION_MODULE mfcm80DLL = { NULL, NULL };
//Adds extension dll library item to linked list of current module state.
extern "C" void InitMfcm80Dll()
{
	new CDynLinkLibrary(mfcm80DLL);
}

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(mfcm80DLL, hInstance))
			return 0;

		InitMfcm80Dll();

	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		// Terminate the library before destructors are called
		AfxTermExtensionModule(mfcm80DLL);
	}
	return 1;
}

