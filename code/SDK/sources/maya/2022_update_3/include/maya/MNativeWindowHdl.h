#pragma once
//-
// Copyright 2020 Autodesk, Inc. All rights reserved.
// 
// Use of this software is subject to the terms of the Autodesk
// license agreement provided at the time of installation or download,
// or which otherwise accompanies this software in either electronic
// or hard copy form.
//+
//
// ****************************************************************************

#include <maya/MTypes.h>

/*! \file
    \brief Defines the native window handle type.
*/

#if defined(__linux__)
	typedef unsigned long XID;
	typedef XID Window;
	typedef Window	MNativeWindowHdl;
#elif defined(_WIN32)
	typedef HWND	MNativeWindowHdl;
#elif defined(__APPLE__)
	//class NSView;
	typedef void * MNativeWindowHdl;
#elif defined(DOCS_ONLY)
	/*! \brief Native window handle type.

	  'type' is defined as follows on each supported platform:

	  \code
	  Linux			Window
	  OS X (64-bit)		void* (cast to NSView* before using)
	  Microsoft Windows	HWND
	  \endcode
	*/
	typedef type MNativeWindowHdl;
#else
	#error Unsupported platform.
#endif
