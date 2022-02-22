#ifndef HPYTHON_H
#define HPYTHON_H

#include <Foundation/include/cxx17_enter_legacy_scope.hpp>

#include <Python/Python.h>

#include <Python/structmember.h>
#include <Python/compile.h>
#include <Python/eval.h>

#include <Foundation/include/cxx17_exit_legacy_scope.hpp>

#if PY_MAJOR_VERSION >=3
	#ifndef Python3_defines
		#define Python3_defines
		//#define PyObject_Unicode				PyObject_Str
		//#define PyString_AS_STRING				PyUnicode_AS_UNICODE
		//#define PyString_AsString				PyUnicode_AsUTF8
		//#define PyString_Check				PyUnicode_Check
		//#define PyString_Concat				PyUnicode_Append
		//#define PyString_ConcatAndDel				PyUnicode_AppendAndDel
		//#define PyString_FromFormat				PyUnicode_FromFormat
		//#define PyString_FromString				PyUnicode_FromString
		//#define PyString_FromStringAndSize			PyUnicode_FromStringAndSize
		#if ! defined(PyObject_Unicode)
			#define PyObject_Unicode			PyObject_Str
		#endif
		#if ! defined(PyString_AS_STRING)
			#define PyString_AS_STRING			PyBytes_AS_STRING
		#endif
		#if ! defined(PyString_AsString)
			#define PyString_AsString			PyBytes_AsString
		#endif
		#if ! defined(PyString_AsStringAndSize)
			#define PyString_AsStringAndSize		PyBytes_AsStringAndSize
		#endif
		#if ! defined(PyString_Check)
			#define PyString_Check				PyBytes_Check
		#endif
		#if ! defined(PyString_Concat)
			#define PyString_Concat				PyBytes_Concat
		#endif
		#if ! defined(PyString_ConcatAndDel)
			#define PyString_ConcatAndDel			PyBytes_ConcatAndDel
		#endif
		#if ! defined(PyString_FromFormat)
			#define PyString_FromFormat			PyUnicode_FromFormat
		#endif
		#if ! defined(PyString_FromString)
			#define PyString_FromString			PyUnicode_FromString
		#endif
		#if ! defined(PyString_FromStringAndSize)
			#define PyString_FromStringAndSize		PyUnicode_FromStringAndSize
		#endif
		#if ! defined(PyString_InternFromString)
			#define PyString_InternFromString		PyUnicode_InternFromString
		#endif
		#if ! defined(PyUnicodeObject)
			#define PyUnicodeObject				PyObject
		#endif
		#if ! defined(PyInt_AS_LONG)
			#define PyInt_AS_LONG				PyLong_AS_LONG
		#endif
		#if ! defined(PyInt_AsLong)
			#define PyInt_AsLong				PyLong_AsLong
		#endif
		#if ! defined(PyInt_AsUnsignedLongMask)
			#define PyInt_AsUnsignedLongMask		PyLong_AsUnsignedLongMask
		#endif
		#if ! defined(PyInt_Check)
			#define PyInt_Check				PyLong_Check
		#endif
		#if ! defined(PyInt_CheckExact)
			#define PyInt_CheckExact			PyLong_CheckExact
		#endif
		#if ! defined(PyInt_FromLong)
			#define PyInt_FromLong				PyLong_FromLong
		#endif
	#endif
#endif

#ifndef PyPUBLIC
	#ifdef _WIN32
		#define PyPUBLIC
	#else
		#define PyPUBLIC __attribute__ ((visibility ("default")))
	#endif
#endif

// With XCode, toupper is defined in /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk/System/Library/Frameworks/Python.framework/Headers/pyport.h:731:29: note: expanded from macro 'toupper'
// because of _PY_PORT_CTYPE_UTF8_ISSUE on __APPLE__ only
// Causing issue when including <iostream> after
#ifdef _PY_PORT_CTYPE_UTF8_ISSUE
    #undef isalnum
    #undef isalpha
    #undef islower
    #undef isspace
    #undef isupper
    #undef tolower
    #undef toupper
#endif

#endif
//-
// ==================================================================
// (C) Copyright 2006 by Autodesk, Inc. All Rights Reserved. By using
// this code,  you  are  agreeing  to the terms and conditions of the
// License  Agreement  included  in  the documentation for this code.
// AUTODESK  MAKES  NO  WARRANTIES,  EXPRESS  OR  IMPLIED,  AS TO THE
// CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  AUTODESK PROVIDES THE CODE ON AN 'AS-IS' BASIS AND EXPLICITLY
// DISCLAIMS  ANY  LIABILITY,  INCLUDING CONSEQUENTIAL AND INCIDENTAL
// DAMAGES  FOR ERRORS, OMISSIONS, AND  OTHER  PROBLEMS IN THE  CODE.
//
// Use, duplication,  or disclosure by the U.S. Government is subject
// to  restrictions  set forth  in FAR 52.227-19 (Commercial Computer
// Software Restricted Rights) as well as DFAR 252.227-7013(c)(1)(ii)
// (Rights  in Technical Data and Computer Software),  as applicable.
// ==================================================================
//+
