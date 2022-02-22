#pragma once
// ===========================================================================
// Copyright 2018 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//
// CLASS:    MPxSkinCluster
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxGeometryFilter.h>
#include <maya/MSelectionList.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! \ingroup OpenMayaAnim MPx
//! \brief Base class for user-defined skin deformers 
/*!
 MPxSkinCluster allows the creation of user-defined skin deformers. 
 It derives from MPxGeometryFilter and so offers all the functionality of that class.
 Additionally, it has the per-vertex skin weights and other skin-related attributes
 of the Maya built-in skinCluster node.

 Custom nodes derived from MPxSkinCluster are treated by Maya just like the built-in skinCluster,
 so all the weight painting/editing etc. tools that artists are used to also work on the custom nodes.
*/
class OPENMAYAANIM_EXPORT MPxSkinCluster : public MPxGeometryFilter
{
public:

	MPxSkinCluster();

	~MPxSkinCluster() override;

	MPxNode::Type type() const override;

	// return the weight value for the given index pair
	//
	float						weightValue( MDataBlock& mblock,
											 unsigned int multiIndex,
											 unsigned int wtIndex);

	// Inherited attributes
	//! weight list attribute, multi
	static MObject weightList;
	//! weight attribute, multi
	static MObject weights;
	//! matrix attribute, multi
	static MObject matrix;
	//! bindPreMatrix attribute, multi
	static MObject bindPreMatrix;

	static const char*	    className();

protected:
// No protected members

OPENMAYA_PRIVATE:
	static void				initialSetup();
};

OPENMAYA_NAMESPACE_CLOSE
