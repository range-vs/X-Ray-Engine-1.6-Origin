#pragma once
//-
// ===========================================================================
// Copyright 2020 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+
//
// CLASS:    MFnFloatVectorArrayData
//
// ****************************************************************************

#include <maya/MFnData.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnFloatVectorArrayData)

//! \ingroup OpenMaya MFn
//! \brief int array function set for dependency node data.
/*!
  MFnFloatVectorArrayData allows the creation and manipulation of MFloatVectorArray data
  objects for use in the dependency graph.

  If a user written dependency node either accepts or produces MFloatVectorArrays,
  then this class is used to extract or create the data that comes from or
  goes to other dependency graph nodes.  The MDataHandle::type method will
  return kFloatVectorArrayData when data of this type is present.  To access it, the
  MDataHandle::data method is used to get an MObject for the data and this
  should then be used to initialize an instance of MFnFloatVectorArrayData.
*/
class OPENMAYA_EXPORT MFnFloatVectorArrayData : public MFnData
{
	declareMFn(MFnFloatVectorArrayData, MFnData);

public:
	unsigned int	length( MStatus* ReturnStatus = NULL ) const;
	MStatus		    set( MFloatVector& element, unsigned int index );
	MStatus			copyTo( MFloatVectorArray& ) const;
	MStatus			set( const MFloatVectorArray& newArray );
	MFloatVectorArray array( MStatus*ReturnStatus=NULL );
	MObject			create( MStatus*ReturnStatus=NULL );
	MObject			create( const MFloatVectorArray& in, MStatus*ReturnStatus=NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnFloatVectorArrayData, MFnData );

	//!	NO SCRIPT SUPPORT
	const MFloatVector&  operator[]( unsigned int index ) const;
	//!	NO SCRIPT SUPPORT
	MFloatVector&	    operator[]( unsigned int index );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE
