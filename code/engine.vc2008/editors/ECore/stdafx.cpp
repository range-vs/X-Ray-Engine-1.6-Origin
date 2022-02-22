#include "stdafx.h"
#pragma hdrstop

// external dependencies

#define INITGUID
#include <dinput.h>

// #pragma comment(lib,"vclx")
// #pragma comment(lib,"editorB")
#pragma comment(lib,"dinput8B")
#pragma comment(lib,"freeimageB")
#pragma comment(lib,"dxtB")
#pragma comment(lib,"EToolsB")
#pragma comment(lib,"LWOB")
#pragma comment(lib,"xrEPropsB")
#pragma comment(lib,"xrCoreB")
#pragma comment(lib,"xrSoundB")
#pragma comment(lib, "libogg_static_b")
#pragma comment(lib,"libtheora_static_b")

#ifdef _WIN64
#ifdef __DEBUG
#pragma comment(lib, "d3dx9d_41")
#else
#pragma comment(lib, "d3dx9_41")
#endif
#endif
