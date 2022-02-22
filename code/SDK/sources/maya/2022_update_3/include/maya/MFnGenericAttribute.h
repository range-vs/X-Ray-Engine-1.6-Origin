#pragma once
//
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
// CLASS:    MFnGenericAttribute
//
// ****************************************************************************

#include <maya/MFnAttribute.h>
#include <maya/MFnData.h>
#include <maya/MFnNumericData.h>
#include <maya/MDeprecate.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnGenericAttribute)

//! \ingroup OpenMaya MFn
//! \brief Generic attribute function set. 
/*!
  MFnGenericAttribute is a function set for attributes that can accept
  several types of data. A generic attribute is similar to a typed
  attribute (MFnTypedAttribute) except that it has a list of types
  that it considers valid.

  If the attribute will only take one type of data then it is more
  efficient to use one of the other attribute function sets such as
  MFnTypedAttribute or MFnNumericAttribute.
*/
class OPENMAYA_EXPORT MFnGenericAttribute : public MFnAttribute
{
	declareMFn(MFnGenericAttribute, MFnAttribute);

public:
	MObject 	create( const MString& full,
						const MString& brief,
						MStatus* ReturnStatus = NULL );
	MStatus		addDataAccept( MFnData::Type newType );
	MStatus		addNumericDataAccept( MFnNumericData::Type newType );
	MStatus		addAccept( const MTypeId& id );
	MStatus		removeDataAccept( MFnData::Type oldType );
	MStatus		removeNumericDataAccept( MFnNumericData::Type oldType );
	MStatus		removeAccept( const MTypeId& id );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnGenericAttribute, MFnAttribute );

	OPENMAYA_DEPRECATED(2019, "Use the MFnGenericAttribute::addDataAccept method instead.")
	MStatus		addAccept( MFnData::Type newType );

	OPENMAYA_DEPRECATED(<2016, "Use the MFnGenericAttribute::addNumericDataAccept method instead.")
	MStatus		addAccept( MFnNumericData::Type newType );

	OPENMAYA_DEPRECATED(2019, "Use the MFnGenericAttribute::removeDataAccept method instead.")
	MStatus		removeAccept( MFnData::Type oldType );

	OPENMAYA_DEPRECATED(<2016, "Use the MFnGenericAttribute::removeNumericDataAccept method instead.")
	MStatus		removeAccept( MFnNumericData::Type oldType );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members
private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE
