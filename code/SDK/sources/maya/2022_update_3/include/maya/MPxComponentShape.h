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
// CLASS:    MPxComponentShape
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MPxComponentShape)
//
//  MPxComponentShape is the parent class of user defined shapes that contain
//  an array of points/control vertices/components.
//
//  MPxComponentShape provides various basic support routines needed for any
//  custom shape that supports components. A copy of the data for those components is
//  stored locally to allow fast access, particularly for draw/pick routines.
//
//  User defined shapes are dependency nodes (and DAG nodes) which contain
//  overridable drawing, and selection methods.
//
//  The UI dependent aspects of the shape should be implemented in a class
//  derived from MPxSurfaceShapeUI. This includes the drawing and interactive
//  selection of the shape and any components that the shape implements.
//
// ****************************************************************************

#include <maya/MPxSurfaceShape.h>
#include <maya/MVectorArray.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPxComponentShape)

//! \ingroup OpenMaya MPx
//! \brief Component helper class for surface shapes. 
/*!

  MPxComponentShape allows the implementation of new user defined
  shapes using components. User defined shapes are dependency nodes
  (and DAG nodes) which contain overridable drawing, selection, and
  component methods. This class provides enhanced functionality for
  working with components. As a result, it is a better starting point
  than MPxSurfaceShape for writing surface shape components.

  This class provides methods to manipulate and select the components that make
  up the shape.

  The UI dependent aspects of the shape should be implemented in a class
  derived from MPxSurfaceShapeUI. This includes the drawing and interactive
  selection of the shape.
*/
class OPENMAYA_EXPORT MPxComponentShape : public MPxSurfaceShape
{
public:

	void transformUsing( const MMatrix & matrix, const MObjectArray & componentList ) override;

	void transformUsing( const MMatrix& mat, const MObjectArray& componentList, MPxSurfaceShape::MVertexCachingMode cachingMode, MPointArray* pointCache) override;

	void componentToPlugs( MObject & component, MSelectionList & list ) const override;

	bool match( const MSelectionMask & mask, const MObjectArray& componentList ) const override;


	MObject createFullVertexGroup() const override;

	MObject localShapeInAttr() const override;

	MVectorArray* getControlPoints();

	MStatus setControlPoints( MVectorArray* cps );

protected:
	MVectorArray    myfCps;

private:
};

OPENMAYA_NAMESPACE_CLOSE
