#pragma once

#include <windows.h>

#	ifdef XRCORE_EXPORTS
#		define XRCORE_API __declspec(dllexport)
#	else
#		define XRCORE_API __declspec(dllimport)
#	endif

#include "..\..\..\..\xrCore\xrDebug_macros.h"

void 	XRCORE_API	__cdecl		Msg(LPCSTR format, ...);

#pragma comment(lib, "xrCore.lib")