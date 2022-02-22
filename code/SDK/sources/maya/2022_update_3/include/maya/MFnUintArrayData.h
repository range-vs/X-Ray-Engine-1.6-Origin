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
// CLASS:    MFnUintArrayData
//
// ****************************************************************************

#include <maya/MFnData.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnUintArrayData)

//! \ingroup OpenMaya MFn
//! \brief int array function set for dependency node data.
/*!
  MFnUintArrayData allows the creation and manipulation of MIntArray data
  objects for use in the dependency graph.

  If a user written dependency node either accepts or produces MUintArrays,
  then this class is used to extract or create the data that comes from or
  goes to other dependency graph nodes.  The MDataHandle::type method will
  return kUintArray when data of this type is present.  To access it, the
  MDataHandle::data method is used to get an MObject for the data and this
  should then be used to initialize an instance of MFnUintArrayData.
*/
class OPENMAYA_EXPORT MFnUintArrayData : public MFnData
{
 declareMFn(MFnUintArrayData, MFnData);

public:
    unsigned int length( MStatus* ReturnStatus = NULL ) const;
    unsigned int operator[]( unsigned int index ) const;
    MStatus set( unsigned int element, unsigned int index );
    MStatus copyTo( MUintArray& ) const;
    MStatus set( const MUintArray& newArray );
    MUintArray array( MStatus*ReturnStatus=NULL );
    MObject create( MStatus*ReturnStatus=NULL );
    MObject create( const MUintArray& in, MStatus*ReturnStatus=NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 declareMFnConstConstructor( MFnUintArrayData, MFnData );

 //! NO SCRIPT SUPPORT
 unsigned int&         operator[]( unsigned int index );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE
