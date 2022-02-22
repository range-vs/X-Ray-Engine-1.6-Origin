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
// CLASS:    MFnGeometryData
//
// ****************************************************************************

#include <maya/MFnData.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnGeometryData)

//! \ingroup OpenMaya MFn
//! \brief  Geometry data function set. 
/*!
This class is the function set for geometry data.

Geometry data adds matrix and grouping (set) information to regular data
and is used to pass geometry types such as mesh, lattice, and NURBS shape
data through DG connections.

User defined geometry data types (MPxGeometryData) are also supported
by this class.

The matrix within geometry data is the matrix used to convert the object
into local space.
*/
class OPENMAYA_EXPORT MFnGeometryData : public MFnData
{
    declareMFn( MFnGeometryData, MFnData );

public:
    //! Component tag type.
    OPENMAYA_ENUM(ComponentTagCategory,
        kAuto,          // depending on context vert, edge or face type
        kNull,          // undefined empty contents
        kVerts,         // vert type
        kEdges,         // edge type
        kFaces,         // face type
        kUnsupported    // unsupported component type for component tags
    );

    //! Group contents.
    OPENMAYA_ENUM(SubsetState,
        kInvalidGroup,     // component could not be found or resolved
        kEmptyGroup,       // component contains nothing
        kCompleteGroup,    // component contains all elements of the geometry
        kPartialGroup      // component contains some elements of the geometry
    );

    MStatus        setMatrix( const MMatrix & );
    MStatus        getMatrix ( MMatrix & ) const;
    bool           matrixIsIdentity( MStatus * ReturnStatus = NULL ) const;
    bool           matrixIsNotIdentity( MStatus * ReturnStatus = NULL ) const;

    // methods to add/remove object groups
    //
    bool           hasObjectGroup( unsigned int id,
                                   MStatus* ReturnStatus = NULL  ) const;
    MStatus        addObjectGroup( unsigned int );
    MStatus        removeObjectGroup( unsigned int );
    MStatus        changeObjectGroupId( unsigned int , unsigned int );

    // methods to get the i'th object group
    //
    unsigned int       objectGroupCount( MStatus * ReturnStatus = NULL ) const;
    unsigned int       objectGroup( unsigned int index,
                                MStatus* ReturnStatus = NULL ) const;

    // method to get the type of component stored by an object group
    //
    MFn::Type      objectGroupType( unsigned int,
                                    MStatus* ReturnStatus = NULL ) const;

    // methods to access and edit members of object group
    //
    MObject        objectGroupComponent( unsigned int,
                                         MStatus* ReturnStatus = NULL ) const;
    MStatus        setObjectGroupComponent( unsigned int, MObject & );
    MStatus        addObjectGroupComponent( unsigned int, MObject & );
    MStatus        removeObjectGroupComponent( unsigned int, MObject & );

    SubsetState  objectGroupSubsetState( unsigned int, MStatus* ReturnStatus = NULL ) const;

    // Method to copy object groups from the geometry data sent in.
    //
    MStatus        copyObjectGroups( MObject & inGeom );

    // methods to handle componentTags
    MStatus     componentTags(MStringArray& keys) const;
    bool        hasComponentTag(const MString& key,
                            MStatus* ReturnStatus = NULL) const;
    MStatus     addComponentTag(const MString& key);
    MStatus     removeComponentTag(const MString& key);
    MStatus     renameComponentTag(const MString& key, const MString& newKey);

    // methods to set and get the components for a given componentTag
    MObject     componentTagContents(const MString& key,
                                  MStatus* ReturnStatus = NULL) const;
    MStatus     setComponentTagContents(const MString& key, MObject &);
    MFn::Type   componentTagType(const MString& key,
                                      MStatus* ReturnStatus = NULL) const;
    ComponentTagCategory componentTagCategory(const MString& key,
                                      MStatus* ReturnStatus = NULL) const;
    SubsetState componentTagExpressionSubsetState(
                                        const MString& expression,
                                        ComponentTagCategory ctg = MFnGeometryData::ComponentTagCategory::kAuto,
                                        MStatus* ReturnStatus = NULL ) const;
    MObject     resolveComponentTagExpression(const MString& expression,
                                        ComponentTagCategory ctg = MFnGeometryData::ComponentTagCategory::kAuto,
                                        MStatus* ReturnStatus = NULL ) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnGeometryData, MFnData );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No Private members

};

OPENMAYA_NAMESPACE_CLOSE
