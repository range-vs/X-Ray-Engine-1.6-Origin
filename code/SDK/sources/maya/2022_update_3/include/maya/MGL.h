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
// FILE:    MGL.h
//
// ****************************************************************************
//
// DESCRIPTION (MGL)
//
//	This file include the proper OpenGL and OpenGL utility (glu)
//
// ****************************************************************************

#include <maya/MTypes.h>

#if defined(__APPLE__)
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	class NSOpenGLContext;
	//! \brief GL context type (OS X 64-bit)
	typedef	NSOpenGLContext*	MGLContext;

#elif defined (__linux__)
	#include <GL/gl.h>
	#include <GL/glu.h>
    	#if !defined(__glx_h__) && !defined(GLX_H) && !defined(__GLX_glx_h__)
    	    typedef struct __GLXcontextRec *GLXContext;
            typedef struct _XDisplay Display;
    	#endif
	//! \brief GL context type (Linux)
  	typedef	GLXContext	MGLContext;

#elif defined (_WIN32)
	#ifndef APIENTRY
		#define MAYA_APIENTRY_DEFINED
		#define APIENTRY __stdcall
	#endif
	#ifndef CALLBACK
		#define MAYA_CALLBACK_DEFINED
		#define CALLBACK __stdcall
	#endif
	#ifndef WINGDIAPI
		#define MAYA_WINGDIAPI_DEFINED
		#define WINGDIAPI __declspec(dllimport)
	#endif

	#include <gl/Gl.h>
	#include <gl/Glu.h>

	#ifdef MAYA_APIENTRY_DEFINED
		#undef MAYA_APIENTRY_DEFINED
		#undef APIENTRY
	#endif
	#ifdef MAYA_CALLBACK_DEFINED
		#undef MAYA_CALLBACK_DEFINED
		#undef CALLBACK
	#endif
	#ifdef MAYA_WINGDIAPI_DEFINED
		#undef MAYA_WINGDIAPI_DEFINED
		#undef WINGDIAPI
	#endif

    //! \brief GL context type (Microsoft Windows)
    typedef	HGLRC MGLContext;
#else
	#error Unknown OS
#endif //__APPLE__
