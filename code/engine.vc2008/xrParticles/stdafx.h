// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
// Third generation by Oles.

#ifndef stdafxH
#define stdafxH

#pragma once

#include "../xrCore/xrCore.h"

#include "psystem.h"

/*
#ifdef __BORLANDC__
#pragma comment( lib, "x:\\xrCoreB.lib"	)
#else
#pragma comment( lib, "xrCore.lib"	)
#endif
*/

#ifdef __BORLANDC__
#ifdef _WIN64
#pragma comment(lib,	"xrCoreB.a"		)
#else
#pragma comment(lib,	"xrCoreB.lib"		)
#endif
#else
#pragma comment( lib, "xrCore.lib"	)
#endif

#endif //stdafxH
