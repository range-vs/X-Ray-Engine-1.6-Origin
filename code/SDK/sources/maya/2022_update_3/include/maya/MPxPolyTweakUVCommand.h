#pragma once
//-
// ===========================================================================
// Copyright 2018 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// CLASS:    MPxPolyTweakUVCommand
//
// ****************************************************************************

#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MPxCommand.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPxPolyTweakUVCommand)

//! \ingroup OpenMaya MPx
//! \brief Base class used for moving polygon UV's.
/*!
This is the base class for UV editing commands on polygonal objects.

The purpose of this command class is to simplify the process of moving
UVs on a polygonal object. The use is only required to provide the new
positions of the UVs that have been modified.
*/
class OPENMAYA_EXPORT MPxPolyTweakUVCommand : public MPxCommand
{
public:
							MPxPolyTweakUVCommand ();
						~MPxPolyTweakUVCommand () override;
	virtual MStatus			parseSyntax (MArgDatabase &argData);
	virtual MStatus			getTweakedUVs (const MObject & mesh,
										   MIntArray & uvList,
										   MFloatArray & uPos,
										   MFloatArray & vPos);
	static MSyntax			newSyntax ();

private:

	MStatus			doIt(const class MArgList &) override;
	MStatus			undoIt() override;
	MStatus			redoIt() override;
	bool			isUndoable() const override;

	void * fData;
};

OPENMAYA_NAMESPACE_CLOSE
