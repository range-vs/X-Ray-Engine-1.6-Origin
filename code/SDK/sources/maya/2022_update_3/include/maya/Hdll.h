#pragma once
// ===========================================================================
// Copyright 2018 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#if defined(_MSC_VER)
    #if defined(MAYA_NODLL)
		#define MAYA_DLLIMPORT __declspec()
		#define MAYA_DLLEXPORT __declspec()
    #else
		#define MAYA_DLLIMPORT __declspec(dllimport)
	    #define MAYA_DLLEXPORT __declspec(dllexport)
	#endif
	#define MAYA_DLLNO_IMPORT_EXPORT __declspec()
	#define MAYA_DLLVISIBILITY
#else
	#define MAYA_DLLIMPORT
	#define MAYA_DLLEXPORT		__attribute__ ((visibility("default")))
	#define MAYA_DLLNO_IMPORT_EXPORT
	#define MAYA_DLLVISIBILITY	__attribute__ ((visibility("default")))
#endif
