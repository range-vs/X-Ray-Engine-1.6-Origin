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
// CLASS:    MPxFluidEmitterNode
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>
#include <maya/MPxEmitterNode.h>
#include <maya/MPointArray.h>
#include <maya/MVectorArray.h>
#include <maya/MDoubleArray.h>
#include <maya/MFnFluid.h>
#include <maya/MColor.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPxFluidEmitterNode)

//! \ingroup OpenMayaFX
//! \brief Base class for user defined particle emitters
/*!
  MPxFluidEmitterNode allows the creation and manipulation of
  dependency graph nodes representing fluid emitters.
*/
class OPENMAYAFX_EXPORT MPxFluidEmitterNode : public MPxEmitterNode
{
public:
	MPxFluidEmitterNode();
	~MPxFluidEmitterNode() override;
	MPxNode::Type	type() const override;
	MStatus			compute(const MPlug& plug, MDataBlock& dataBlock) override;

	virtual MStatus			fluidEmitter( const MObject& fluidObj, const MMatrix& worldMatrix, int plugIndex );

	//! density emission rate attribute
	static MObject mFluidDensityEmission;
	//!	heat emission rate attribute
	static MObject mFluidHeatEmission;
	//! fuel emission rate attribute
	static MObject mFluidFuelEmission;
	//! color emission toggle attribute
	static MObject mEmitFluidColor;
	//! emission color attribute
	static MObject mFluidColor;
	//! emission red color channel attribute
	static MObject mFluidColorR;
	//! emission green color channel attribute
	static MObject mFluidColorG;
	//! emission blue color channel attribute
	static MObject mFluidColorB;
	//! emission dropoff attribute
	static MObject mFluidDropoff;
	//! emission turbulence attribute
	static MObject mTurbulence;
	//! emission jitter attribute
	static MObject mFluidJitter;
	//!	emission function attribute
	static MObject mEmissionFunction;

	double fluidDensityEmission( MDataBlock& block );
	double fluidHeatEmission( MDataBlock& block );
	double fluidFuelEmission( MDataBlock& block );
	bool   fluidEmitColor( MDataBlock& block );
	MColor fluidColor( MDataBlock& block );

	double fluidDropoff( MDataBlock& block );
	double turbulence( MDataBlock& block );
	bool   fluidJitter( MDataBlock& block );

	static const char*	className();

protected:
// No protected members

OPENMAYA_PRIVATE:
	static void			initialSetup();
};

OPENMAYA_NAMESPACE_CLOSE
