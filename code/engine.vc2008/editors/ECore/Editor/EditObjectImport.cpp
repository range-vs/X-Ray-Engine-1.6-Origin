//----------------------------------------------------
// file: CEditableObjectImport.cpp
//----------------------------------------------------

#include "stdafx.h"
#pragma hdrstop

#include "EditObject.h"
//#include "lwo2.h"
#include "LW_SHADERDEF.h"
#include "EditMesh.h"

extern "C" {
#include "lwo2.h"
};

#ifdef _EDITOR
	#include "ResourceManager.h"
    
	extern "C" __declspec(dllimport) lwObject* LWO_ImportObject(char* filename, lwObject *new_obj);
	extern "C" __declspec(dllimport) void LWO_CloseFile(lwObject *new_obj);
#endif

typedef xr_map< void*,int > VMIndexLink; typedef VMIndexLink::iterator VMIndexLinkIt;

bool CompareFunc(const st_VMapPt& vm0, const st_VMapPt& vm1){
	return vm0.vmap_index<vm1.vmap_index;
};


