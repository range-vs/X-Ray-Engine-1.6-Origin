#pragma once
//-
// ===========================================================================
// Copyright 2020 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
// ****************************************************************************
//
// FILE:    MTypes.h
//
// ****************************************************************************
//
// DESCRIPTION (MTypes)
//
//		This file contains the definitions for NULL, numeric array types, type 
//		bool, and constants true and false
//
// ****************************************************************************

#include <maya/MApiNamespace.h>

// ****************************************************************************


// ****************************************************************************

// DECLARATIONS

// ****************************************************************************

// Define a CPP macro that reflects a numeric representation of the
// base application version. For example
//	Maya 1.0.1	would be 10
//	Maya	1.5	would be 15
//	Maya 2.0	would be 20
//	...
//	Maya 2017	would be 2017
//	Maya 2018	would be 2018
//
#define MAYA_APP_VERSION 2022

// Define a CPP macro that reflects the current Maya API version.
// This macro is designed to be an integer so that one can do
// CPP arithmetic and comparisons on it.  The digits in the number
// are derived by taking the Maya version number and deleting the '.'
// characters. Dot releases do not update this value so a release with
// version #.#.# would havethe same number as #.#. Thus, for example
//   Maya 1.0.1  would be 100
//   Maya 1.5    would be 150
//   Maya 2.0    would be 200
//   Maya 2.5    would be 250
//   Maya 3.0    would be 300
//   Maya 4.0    would be 400
//   Maya 4.0.1  would be 400
//   Maya 4.0.2  would be 400
//   Maya 4.0.3  would be 400
//   Maya 4.5    would be 450
//   Maya 5.0    would be 500
//   Maya 6.0    would be 600
//   Maya 6.5    would be 650
//   Maya 7.0    would be 700
//   Maya 8.0    would be 800
//   ...
//   Maya 2017   would be 201700
//   Maya 2018   would be 20180000 --> Namespacing the API
//   Maya 2019   would be 201900
//
// since this variable did not exist in the Maya 1.0 API, it will
// default to zero in that release.  Thus a construct such as
//
//    #if MAYA_API_VERSION > 100
//
// will be true in all post 1.0 versions of the API.
//
// API version for to match previous gold API version
//
#define MAYA_API_VERSION 20220300

// Define a CPP macro that reflects the current Maya custom version.
// This macro is designed to be an integer so that one can do CPP arithmetic
// and comparisons on it. The digits in the number are derived by the following
// formula:
//
// MAYA_APP_VERSION * 10000 + MAJOR_VERSION * 100 + MINOR_VERSION
//
// This macro is only relevant for custom builds of Maya.
//
#define MAYA_CUSTOM_VERSION_MAJOR 0
#define MAYA_CUSTOM_VERSION_MINOR 0
#define MAYA_CUSTOM_VERSION_CLIENT ""
#define MAYA_CUSTOM_VERSION (MAYA_APP_VERSION * 10000 + MAYA_CUSTOM_VERSION_MAJOR * 100 + MAYA_CUSTOM_VERSION_MINOR)

#ifdef _WIN32

#ifndef PLUGIN_EXPORT
#define PLUGIN_EXPORT _declspec( dllexport ) 
#endif // PLUGIN_EXPORT

// Typedefs and functions definitions to avoid including windows.h
typedef unsigned short u_short;
#ifndef	STRICT
	#define STRICT 1
#endif

typedef void*			HANDLE;
typedef unsigned long	DWORD;
typedef unsigned int	UINT;
typedef const char*		LPCSTR;

#define OPENMAYA_DECLARE_HANDLE(name) struct name##__; typedef struct name##__ *name

OPENMAYA_DECLARE_HANDLE(HINSTANCE);
OPENMAYA_DECLARE_HANDLE(HWND);
OPENMAYA_DECLARE_HANDLE(HDC);
OPENMAYA_DECLARE_HANDLE(HGLRC);

#if defined(NT_PLUGIN) || defined(NT_APP)
extern "C" {
	__declspec(dllimport) void	__stdcall Sleep( DWORD dwMilliseconds );
	__declspec(dllimport) DWORD	__stdcall GetTickCount( void );

	#if !defined(OutputDebugString)
		__declspec(dllimport) void	__stdcall OutputDebugStringA( LPCSTR lpOutputString );
		inline void	OutputDebugString( LPCSTR lpOutputString )
		{
			OutputDebugStringA(lpOutputString);
		}
	#endif
}

// In the case where we really need to include windows.h, let's make sure we are not including too much.
#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif
#define NOSERVICE
#define NOMCX
#define NOIME
#define NOSOUND
#define NOCOMM
#define NOCRYPT
#ifndef NOMINMAX
	#define NOMINMAX
#endif

#ifndef _BOOL
	#define _BOOL
#endif

#ifndef NT_APP
	extern HINSTANCE MhInstPlugin;
#endif

#define uint UINT

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif

#endif // NT_PLUGIN

#ifndef strcasecmp
    #define	strcasecmp _strcmpi
#endif

#else // !_WIN32

#ifndef DLL_PUBLIC
# define DLL_PUBLIC	__attribute__ ((visibility("default")))
# define DLL_PRIVATE __attribute__ ((visibility("hidden")))
#endif

#ifndef PLUGIN_EXPORT
#define PLUGIN_EXPORT DLL_PUBLIC
#endif

#endif // _WIN32

#if (defined (NT_PLUGIN) || defined(NT_APP) || (defined(MAC_PLUGIN) && !defined(__MACH__)))
#ifdef __cplusplus
extern "C" {
#endif

//from /usr/include/math.h
FND_EXPORT extern double	drand48(void);
FND_EXPORT extern double	erand48(unsigned short [3]);
FND_EXPORT extern long		lrand48(void);
FND_EXPORT extern long		nrand48(unsigned short [3]);
FND_EXPORT extern long		mrand48(void);
FND_EXPORT extern long		jrand48(unsigned short [3]);
FND_EXPORT extern void	srand48(long);
FND_EXPORT extern unsigned short * seed48(unsigned short int [3]);
FND_EXPORT extern void	lcong48(unsigned short int [7]);
FND_EXPORT extern long	 random(void);
FND_EXPORT extern int	srandom( unsigned x );

#ifdef __cplusplus
}
#endif
#endif // NT_PLUGIN || MAC_PLUGIN

#ifndef NULL
#	define NULL	0L
#endif 

typedef signed short short2[2];
typedef signed short short3[3];
typedef signed int   long2[2];
typedef signed int   long3[3];
typedef signed int   int2[2];
typedef signed int   int3[3];
typedef float        float2[2];
typedef float        float3[3];
typedef double       double2[2];
typedef double       double3[3];
typedef double       double4[4];

#define MBits64_

#if defined(_WIN32)
	typedef unsigned long long MUint64;
	typedef __int64 MInt64;
#elif defined(linux) || defined(__linux__)
	typedef unsigned long MUint64;
	typedef long MInt64;
#elif defined(__APPLE__)
	typedef unsigned long long MUint64;
	typedef long long MInt64;
#endif

#ifndef __has_include
    #define __has_include(F) 1  // Please remove along with OPENMAYA_DEPRECATED(2020, ...) for MIntPtrSz and MUintPtrSz
    #define MAYA__has_include_DEFINED
#endif
#if __has_include(<maya/MDeprecate.h>)
    #include <maya/MDeprecate.h>
    #if defined(_WIN32)
        #include <basetsd.h>
        OPENMAYA_DEPRECATED(2020, "Type MIntPtrSz should be replaced by standard type intptr_t")
        typedef INT_PTR  MIntPtrSz;
        OPENMAYA_DEPRECATED(2020, "Type MUintPtrSz should be replaced by standard type uintptr_t")
        typedef UINT_PTR MUintPtrSz;
    #else
        #include <stdint.h>
        OPENMAYA_DEPRECATED(2020, "Type MIntPtrSz should be replaced by standard type intptr_t")
        typedef intptr_t  MIntPtrSz;
        OPENMAYA_DEPRECATED(2020, "Type MUintPtrSz should be replaced by standard type uintptr_t")
        typedef uintptr_t MUintPtrSz;
    #endif
#endif
#ifdef MAYA__has_include_DEFINED
    #undef __has_include // Please remove along with OPENMAYA_DEPRECATED(2020, ...) for MIntPtrSz and MUintPtrSz
    #undef MAYA__has_include_DEFINED
#endif

#define BEGIN_NO_SCRIPT_SUPPORT public
#define END_NO_SCRIPT_SUPPORT public

#ifndef SWIG
    // OpenMaya enum declaration to provide reflection
    // maximum of 99 enumerators.

    #define OPENMAYA_MAP(macro, ...) \
        OPENMAYA_IDENTITY( \
            OPENMAYA_APPLY(OPENMAYA_CHOOSE_OPENMAYA_MAP_START, OPENMAYA_COUNT(__VA_ARGS__)) \
                (macro, __VA_ARGS__))
    
    #define OPENMAYA_CHOOSE_OPENMAYA_MAP_START(count) OPENMAYA_MAP ## count
    
    #define OPENMAYA_APPLY(macro, ...) OPENMAYA_IDENTITY(macro(__VA_ARGS__))
    
    #define OPENMAYA_IDENTITY(x) x
    
    #define OPENMAYA_MAP1(m, x)      m(x)
    #define OPENMAYA_MAP2(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP1(m, __VA_ARGS__))
    #define OPENMAYA_MAP3(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP2(m, __VA_ARGS__))
    #define OPENMAYA_MAP4(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP3(m, __VA_ARGS__))
    #define OPENMAYA_MAP5(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP4(m, __VA_ARGS__))
    #define OPENMAYA_MAP6(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP5(m, __VA_ARGS__))
    #define OPENMAYA_MAP7(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP6(m, __VA_ARGS__))
    #define OPENMAYA_MAP8(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP7(m, __VA_ARGS__))
    #define OPENMAYA_MAP9(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP8(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP10(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP9(m, __VA_ARGS__))
    #define OPENMAYA_MAP11(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP10(m, __VA_ARGS__))
    #define OPENMAYA_MAP12(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP11(m, __VA_ARGS__))
    #define OPENMAYA_MAP13(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP12(m, __VA_ARGS__))
    #define OPENMAYA_MAP14(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP13(m, __VA_ARGS__))
    #define OPENMAYA_MAP15(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP14(m, __VA_ARGS__))
    #define OPENMAYA_MAP16(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP15(m, __VA_ARGS__))
    #define OPENMAYA_MAP17(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP16(m, __VA_ARGS__))
    #define OPENMAYA_MAP18(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP17(m, __VA_ARGS__))
    #define OPENMAYA_MAP19(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP18(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP20(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP19(m, __VA_ARGS__))
    #define OPENMAYA_MAP21(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP20(m, __VA_ARGS__))
    #define OPENMAYA_MAP22(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP21(m, __VA_ARGS__))
    #define OPENMAYA_MAP23(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP22(m, __VA_ARGS__))
    #define OPENMAYA_MAP24(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP23(m, __VA_ARGS__))
    #define OPENMAYA_MAP25(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP24(m, __VA_ARGS__))
    #define OPENMAYA_MAP26(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP25(m, __VA_ARGS__))
    #define OPENMAYA_MAP27(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP26(m, __VA_ARGS__))
    #define OPENMAYA_MAP28(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP27(m, __VA_ARGS__))
    #define OPENMAYA_MAP29(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP28(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP30(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP29(m, __VA_ARGS__))
    #define OPENMAYA_MAP31(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP30(m, __VA_ARGS__))
    #define OPENMAYA_MAP32(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP31(m, __VA_ARGS__))
    #define OPENMAYA_MAP33(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP32(m, __VA_ARGS__))
    #define OPENMAYA_MAP34(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP33(m, __VA_ARGS__))
    #define OPENMAYA_MAP35(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP34(m, __VA_ARGS__))
    #define OPENMAYA_MAP36(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP35(m, __VA_ARGS__))
    #define OPENMAYA_MAP37(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP36(m, __VA_ARGS__))
    #define OPENMAYA_MAP38(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP37(m, __VA_ARGS__))
    #define OPENMAYA_MAP39(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP38(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP40(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP39(m, __VA_ARGS__))
    #define OPENMAYA_MAP41(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP40(m, __VA_ARGS__))
    #define OPENMAYA_MAP42(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP41(m, __VA_ARGS__))
    #define OPENMAYA_MAP43(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP42(m, __VA_ARGS__))
    #define OPENMAYA_MAP44(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP43(m, __VA_ARGS__))
    #define OPENMAYA_MAP45(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP44(m, __VA_ARGS__))
    #define OPENMAYA_MAP46(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP45(m, __VA_ARGS__))
    #define OPENMAYA_MAP47(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP46(m, __VA_ARGS__))
    #define OPENMAYA_MAP48(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP47(m, __VA_ARGS__))
    #define OPENMAYA_MAP49(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP48(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP50(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP49(m, __VA_ARGS__))
    #define OPENMAYA_MAP51(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP50(m, __VA_ARGS__))
    #define OPENMAYA_MAP52(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP51(m, __VA_ARGS__))
    #define OPENMAYA_MAP53(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP52(m, __VA_ARGS__))
    #define OPENMAYA_MAP54(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP53(m, __VA_ARGS__))
    #define OPENMAYA_MAP55(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP54(m, __VA_ARGS__))
    #define OPENMAYA_MAP56(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP55(m, __VA_ARGS__))
    #define OPENMAYA_MAP57(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP56(m, __VA_ARGS__))
    #define OPENMAYA_MAP58(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP57(m, __VA_ARGS__))
    #define OPENMAYA_MAP59(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP58(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP60(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP59(m, __VA_ARGS__))
    #define OPENMAYA_MAP61(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP60(m, __VA_ARGS__))
    #define OPENMAYA_MAP62(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP61(m, __VA_ARGS__))
    #define OPENMAYA_MAP63(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP62(m, __VA_ARGS__))
    #define OPENMAYA_MAP64(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP63(m, __VA_ARGS__))
    #define OPENMAYA_MAP65(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP64(m, __VA_ARGS__))
    #define OPENMAYA_MAP66(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP65(m, __VA_ARGS__))
    #define OPENMAYA_MAP67(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP66(m, __VA_ARGS__))
    #define OPENMAYA_MAP68(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP67(m, __VA_ARGS__))
    #define OPENMAYA_MAP69(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP68(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP70(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP69(m, __VA_ARGS__))
    #define OPENMAYA_MAP71(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP70(m, __VA_ARGS__))
    #define OPENMAYA_MAP72(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP71(m, __VA_ARGS__))
    #define OPENMAYA_MAP73(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP72(m, __VA_ARGS__))
    #define OPENMAYA_MAP74(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP73(m, __VA_ARGS__))
    #define OPENMAYA_MAP75(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP74(m, __VA_ARGS__))
    #define OPENMAYA_MAP76(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP75(m, __VA_ARGS__))
    #define OPENMAYA_MAP77(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP76(m, __VA_ARGS__))
    #define OPENMAYA_MAP78(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP77(m, __VA_ARGS__))
    #define OPENMAYA_MAP79(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP78(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP80(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP79(m, __VA_ARGS__))
    #define OPENMAYA_MAP81(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP80(m, __VA_ARGS__))
    #define OPENMAYA_MAP82(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP81(m, __VA_ARGS__))
    #define OPENMAYA_MAP83(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP82(m, __VA_ARGS__))
    #define OPENMAYA_MAP84(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP83(m, __VA_ARGS__))
    #define OPENMAYA_MAP85(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP84(m, __VA_ARGS__))
    #define OPENMAYA_MAP86(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP85(m, __VA_ARGS__))
    #define OPENMAYA_MAP87(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP86(m, __VA_ARGS__))
    #define OPENMAYA_MAP88(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP87(m, __VA_ARGS__))
    #define OPENMAYA_MAP89(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP88(m, __VA_ARGS__))
    
    #define OPENMAYA_MAP90(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP89(m, __VA_ARGS__))
    #define OPENMAYA_MAP91(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP90(m, __VA_ARGS__))
    #define OPENMAYA_MAP92(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP91(m, __VA_ARGS__))
    #define OPENMAYA_MAP93(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP92(m, __VA_ARGS__))
    #define OPENMAYA_MAP94(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP93(m, __VA_ARGS__))
    #define OPENMAYA_MAP95(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP94(m, __VA_ARGS__))
    #define OPENMAYA_MAP96(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP95(m, __VA_ARGS__))
    #define OPENMAYA_MAP97(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP96(m, __VA_ARGS__))
    #define OPENMAYA_MAP98(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP97(m, __VA_ARGS__))
    #define OPENMAYA_MAP99(m, x, ...) m(x) OPENMAYA_IDENTITY(OPENMAYA_MAP98(m, __VA_ARGS__))
    
    #define OPENMAYA_EVALUATE_COUNT(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
                           _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
                           _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
                           _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77, _78, _79, _80, \
                           _81, _82, _83, _84, _85, _86, _87, _88, _89, _90, _91, _92, _93, _94, _95, _96, _97, _98, _99, \
                           count, ...) \
        count
    
    #define OPENMAYA_COUNT(...) \
        OPENMAYA_IDENTITY(OPENMAYA_EVALUATE_COUNT(__VA_ARGS__,     99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, \
                                             80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, \
                                             60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, \
                                             40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
                                             20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1))
    
    // The type "T" mentioned above that drops assignment operations.
    template <typename U>
    struct ignore_assign {
        constexpr explicit ignore_assign(U value) : _value(value) { }
        constexpr operator U() const { return _value; }
    
        constexpr const ignore_assign& operator =(int /*dummy*/) const
        {
            return *this;
        }
    
        U   _value;
    };
    
    // Prepends "(ignore_assign<int>)" to each argument.
    #define OPENMAYA_IGNORE_ASSIGN_SINGLE(e) (ignore_assign<int>)e,
    #define OPENMAYA_IGNORE_ASSIGN(...) \
        OPENMAYA_IDENTITY(OPENMAYA_MAP(OPENMAYA_IGNORE_ASSIGN_SINGLE, __VA_ARGS__))
    
    // Stringizes each argument.
    #define OPENMAYA_STRINGIZE_SINGLE(e) #e,
    #define OPENMAYA_STRINGIZE(...) OPENMAYA_IDENTITY(OPENMAYA_MAP(OPENMAYA_STRINGIZE_SINGLE, __VA_ARGS__))
    
    #define OPENMAYA_ENUM_EXPAND(EnumName, ...) enum EnumName { __VA_ARGS__ }; \
    struct EnumName##_EnumDef { \
        static inline int size() { return OPENMAYA_IDENTITY(OPENMAYA_COUNT(__VA_ARGS__)); }            \
        static inline int value(int index) { const int _values[] = { OPENMAYA_IDENTITY(OPENMAYA_IGNORE_ASSIGN(__VA_ARGS__)) }; return _values[index]; } \
        static inline const char * raw_name(int index) { const char* _raw_names[] = { OPENMAYA_IDENTITY(OPENMAYA_STRINGIZE(__VA_ARGS__)) }; return _raw_names[index]; } \
    }

    #define OPENMAYA_ENUM(EnumName, ...) OPENMAYA_ENUM_EXPAND(EnumName, __VA_ARGS__) // Using 2 levels to expand the arguments
#else
    #define OPENMAYA_ENUM(EnumName, ...) enum EnumName { __VA_ARGS__ }
#endif

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! Space transformation identifiers
/*!
  MSpace encompasses all of the types of transformation possible. The
  MSpace identifiers are used to determine the space in which the user
  is applying or querying transformation or component (i.e. vertex
  positions) data of a Maya object.

  Note that not all the MSpace types can be passed into all methods
  which take an MSpace as a parameter.  The MSpace enumerated type can
  be split into two parts, types which can be passed into MFnTransform
  and MTransformationMatrix classes (kTransform, kPreTransform and
  kPostTransform) and types which can be passed into shape classes
  such as MFnMesh, MFnNurbsSurface and MFnCamera (kWorld and kObject).

  The following is a description of each of the MSpace types.

  <dl>
  <dt><b>kInvalid</b></dt>

  <dd>There are currently no methods in the API that return a result
  of type MSpace. This may be used for user defined methods that
  return a result of type MSpace to signify an invalid result.</dd>

  <dt><b>kTransform</b></dt>

  <dd>The data applied or queried using the kTransform type represents a
  transform's local (or relative) coordinates system. This type is
  valid for methods of MFnTransform and MTransformationMatrix classes.</dd>

  <dt><b>kPreTransform</b></dt>

  <dd>The data applied or queried using the kPreTransform type represents
  pre-transformed matrix data. Given a matrix which has had other
  matrix operations applied to it, this type is used to obtain a
  matrix that does not taken into consideration any other matrix
  operations. This type is valid for methods of the
  MTransformationMatrix classes.</dd>

  <dt><b>kPostTransform</b></dt>

  <dd>The data applied or queried using the kPostTransform type
  represents post-transformed matrix data. Given a matrix which has
  had other matrix operations applied to it, this type is used to
  obtain a matrix that has taken into consideration all other matrix
  operations. This type is valid for methods of the
  MTransformationMatrix classes.</dd>

  <dt><b>kWorld</b></dt>

  <dd>The data applied or queried using the kWorld type represents the
  data for the objects world coordinates system. The results of this
  type will take into consideration all the transforms in the objects
  hierarchy. This type can be used with shape classes such as MFnMesh,
  MFnNurbsSurface and MFnCamera and the MFnTransform class. Note that
  to get the proper world space transformation data with
  MSpace::kWorld you <b>MUST</b> use the class constructor which
  initializes the function set with an MDagPath object.</dd>

  <dt><b>kObject</b></dt>

  <dd>The data applied or queried using the kObject type represents
  the data for the objects local coordinates system. The results of
  this type will be in the local space of the object (object
  space). This enum can only be used with shape classes such as
  MFnMesh, MFnNurbsSurface and MFnCamera.</dd>

  <dt><b>kLast</b></dt>

  <dd>This simply signifies the end of the MSpace enumerated
  types. All values that precede this value represent a coordinate
  system (with the exception of kInvalid which represents an invalid
  result.)</dd>

  </dl>

  \par Comparative Description:

  There are four spaces in which to apply a transformation.

  <ul>
  <li> World Space - This is the space that an object is in after it
  has had all of its transformations applied to it. A world space
  transformation is the the very last transformation that would be
  applied to the object.
  <li> Object Space - This is the space in which an object is
  defined. An object space transformation would be the first
  transformation that would be applied to an object. This is the same
  as pre-transform space.
  <li> Post Transform Space - This is the space in which the object
  lives after having the transformations of its transform node
  applied. For example, when a primitive object is created in Maya,
  there is a shape node which defined the geometry and a transform
  node which positions/orients the geometry. The space that the
  geometry is in is object space. After applying the transformations
  of the transform node to the geometry, the transformed geometry is
  in post transform space.
  <li> Transform Space - This space depends on the type of
  transformation being applied. Transform nodes define a fixed
  sequence of affine transformations. Basically, there is scale
  followed by rotation and finally translation. There are four spaces
  here:

		1) The space before applying the scale.\n
		2) The space after the scale but before the rotation.\n
		3) The space between the rotation and translation.\n
		4) The space after the translation.\n
		
		Space 1) is pre-transform space.\n
		Space 4) is post-transform space.\n
		Spaces 2) and 3) define transform spaces.\n 
		  
	If applying a transform space scale, this transform will be
	applied after the current scale but before the rotation (space
	2). If applying a transform space rotation, this transform will be
	applied after the current rotation but before the
	translation. Applying a translation in transform space, the
	translation will be applied after the current translation.
  </ul>
*/
class MSpace {
public:

    //! Transformation spaces.
    OPENMAYA_ENUM(Space,
		kInvalid = 0,				//!< Invalid value.
	 	kTransform = 1,				//!< Transform matrix (relative) space.
 		kPreTransform = 2,			//!< Pre-transform matrix (geometry).
 		kPostTransform = 3,			//!< Post-transform matrix (world) space.
 		kWorld = 4,					//!< transform in world space.
 		kObject = kPreTransform,	//!< Same as pre-transform space.
		kLast = 5					//!< Last value, used for counting.
	);

};

OPENMAYA_NAMESPACE_CLOSE

#include <sys/stat.h>
// stat does not work reliably on NT for directories. Trailing '\'s cause an 
// error on NT4.0 and trailing '/'s and '\'s cause an error on Windows 2000.
// Use the following STAT macro to get consistent behavior on NT and UNIX.
//
#ifndef STAT
#ifdef _WIN32
#   define STAT statNT
#   define stat _stat64
#   define fstat _fstat64
#else
#   define STAT statUNIX
#endif
#ifdef __cplusplus
	extern "C" {
#endif
	FND_EXPORT int STAT(const char *path, struct stat *buffer);
#ifdef __cplusplus
	}
#endif
#endif
