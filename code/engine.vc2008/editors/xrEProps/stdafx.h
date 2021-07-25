//----------------------------------------------------
// file: stdafx.h
//----------------------------------------------------
#ifndef stdafxH
#define stdafxH

#pragma once   

#include <xrCore.h>

#define smart_cast dynamic_cast

//refs
namespace CDB{
	class MODEL;
};

#include "../../xrServerEntities/xrEProps.h"

#include "FolderLib.h"                 

#define ENGINE_API
#define DLL_API		__declspec(dllimport)
#define ECORE_API	__declspec(dllexport)

#include "Defines.h"                 

// libs

#ifdef _WIN64
#pragma comment		(lib,"xrSoundB.a")
#pragma comment		(lib,"xrCoreB.a")
#pragma comment		(lib,"EToolsB.a")
#pragma comment		(lib,"editorB.a")
#pragma comment		(lib,"vclsmp.a")
#else
#pragma comment		(lib,"xrSoundB.lib")
#pragma comment		(lib,"xrCoreB.lib")
#pragma comment		(lib,"EToolsB.lib")
#endif

#endif //stdafxH

