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
// CLASS:    MDataBlock
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MDataBlock)

//! \ingroup OpenMaya
//! \brief Dependency node data block. 
/*!
An MDataBlock provides storage for the data being received by or sent by the
node.  It is the data for the plugs and attributes of the node.  The data
block is only valid during the compute method of the depend node.  Pointers to
the data block should not be retained after the compute method.

Access to the data in an MDataBlock is done using an MDataHandle or an
MArrayDataHandle.
*/
class OPENMAYA_EXPORT MDataBlock
{

public:
    MDataBlock(const MDataBlock& in);
	virtual		     ~MDataBlock ();

	MDataHandle      inputValue ( const MPlug & plug,
								        MStatus * ReturnStatus = NULL );
	MDataHandle      inputValue ( const MObject & attribute,
								        MStatus * ReturnStatus = NULL );
	MDataHandle      outputValue ( const MPlug & plug,
								        MStatus * ReturnStatus = NULL );
	MDataHandle      outputValue ( const MObject & attribute,
								        MStatus * ReturnStatus = NULL );
	MArrayDataHandle inputArrayValue ( const MPlug & plug,
								        MStatus * ReturnStatus = NULL );
	MArrayDataHandle inputArrayValue ( const MObject & attribute,
								        MStatus * ReturnStatus = NULL );
	MArrayDataHandle outputArrayValue ( const MPlug & plug,
										MStatus * ReturnStatus = NULL );
	MArrayDataHandle outputArrayValue ( const MObject & attribute,
										MStatus * ReturnStatus = NULL );
	MStatus          setClean ( const MPlug & plug );
	MStatus          setClean ( const MObject & attribute );

	bool			isClean ( const MPlug & plug );
	bool			isClean ( const MObject & attribute,
							  MStatus* ReturnStatus=NULL );

	MDGContext       context ( MStatus * ReturnStatus = NULL );
	MStatus          setContext ( const MDGContext & ctx );

	static const char*	className();

protected:
// No protected members

OPENMAYA_PRIVATE:
	MDataBlock( void * ptr );
	void * data;
};

OPENMAYA_NAMESPACE_CLOSE
