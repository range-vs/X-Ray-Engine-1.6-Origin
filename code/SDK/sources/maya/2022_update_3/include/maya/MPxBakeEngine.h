#pragma once
//-
// ===========================================================================
// Copyright 2017 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// CLASS:    MPxBakeEngine
//
// ***************************************************************************

#include <maya/MFloatArray.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ***************************************************************************
// CLASS DECLARATION (MPxBakeEngine)

//! \ingroup OpenMaya MPx
//! \brief  Baking functionality. 
/*!
The MPxBakeEngine class is a way for users to override the viewport
representation of shaders. Users can provide their own baking engine
to bake advanced shading properties into a texture.  This texture is
used by the viewport to represent the shading properties.
*/
class OPENMAYA_EXPORT MPxBakeEngine
{
public:
    MPxBakeEngine();
	virtual ~MPxBakeEngine();
	void setNeedTransparency(bool t);
	void getUVRange(MFloatArray minUV, MFloatArray maxUV);
	virtual MStatus bake(const MDagPath& objectPath,
							const MDagPath& cameraPath,
							const MPlug &samplePlug,
							MImage & bakeResult) = 0;
OPENMAYA_PRIVATE:
    bool fNeedTransparency;
    MFloatArray fMinUV;
    MFloatArray fMaxUV;

    void* fInstance;
};

OPENMAYA_NAMESPACE_CLOSE
