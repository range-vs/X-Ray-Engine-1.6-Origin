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
// CLASS:    MItSubdVertex
//
// ****************************************************************************

#include <maya/MTypes.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MItSubdVertex)

//! \ingroup OpenMaya
//! \brief Subdiv vertex iterator.
/*!
	This class is the iterator for subdiv vertices.
*/ 
class OPENMAYA_EXPORT MItSubdVertex
{
public:
	MItSubdVertex( MObject & subdObject, MStatus * ReturnStatus = NULL );
	virtual ~MItSubdVertex();
	bool		isDone( MStatus * ReturnStatus = NULL );
    MStatus     next();
	MStatus		reset();
	int level(MStatus * ReturnStatus = NULL) const;
	void setLevel( int level, MStatus * ReturnStatus = NULL );
	bool isValid(MStatus * ReturnStatus = NULL) const;
	MUint64		index( MStatus * ReturnStatus = NULL );

	static const char* 	className();

OPENMAYA_PRIVATE_NO_SWIG:
	MStatus     __next__();

protected:

private:
	void     *       f_it;
};

OPENMAYA_NAMESPACE_CLOSE
