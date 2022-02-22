#pragma once
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//
// CLASS:    MIndexMapper
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MIndexMapper)
//
// An MIndexMapper maps indices between the full set of a geometry and the
//    subset of indices that is affected by a deformer.
//    If a deformer affects f.e only 1000 verts of a total of 15000 verts then 
//    the affectMap will be of size 1000 and contain the indices into the full
//    table of points.
//  
// ****************************************************************************

#include <maya/MIntArray.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! \ingroup OpenMayaAnim
//! \brief Index mapper containing indices of a subset of a geometry
/*!
    An MIndexMapper maps indices between the full set of a geometry and the
    subset of indices that is affected by a deformer.
    If a deformer affects f.e only 1000 verts of a total of 15000 verts then 
    the affectMap will be of size 1000 and contain the indices into the full
    table of points.
*/
class OPENMAYAANIM_EXPORT MIndexMapper{
public:
    using Index = unsigned int;
    static Index InvalidIndex;
    MIndexMapper();
    ~MIndexMapper();
    MIndexMapper(const MIndexMapper&);
    MIndexMapper(MIndexMapper&&);

    Index fullCount() const;
    Index affectCount() const;

    Index affectToFull(Index aid) const;
    Index fullToAffect(Index vid) const;

    bool isIdentityMap() const;

    MIntArray affectMap()const;

OPENMAYA_PRIVATE:
    struct IndexMapperImpl;
    IndexMapperImpl *fImpl = {nullptr};
};
OPENMAYA_NAMESPACE_CLOSE
