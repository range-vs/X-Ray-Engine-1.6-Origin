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
// CLASS: MComponentDataIndexing
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MHWGeometry.h>
#include <maya/MDagPath.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MUintArray.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// NAMESPACE

namespace MHWRender
{

// ****************************************************************************
// CLASS DECLARATION (MComponentDataIndexing)

//! \ingroup OpenMayaRender
//! \brief Class for storing index mapping when vertices are shared
/*!

*/
class OPENMAYARENDER_EXPORT MComponentDataIndexing
{
public:

    OPENMAYA_ENUM(MComponentType,
        kFaceVertex
    );

    MUintArray& indices();
    const MUintArray& indices() const;

    MComponentType componentType() const;
    void setComponentType(MComponentType type);

OPENMAYA_PRIVATE:
    MComponentDataIndexing(MUintArray& indices, MComponentType type=kFaceVertex);
    MComponentDataIndexing(const MComponentDataIndexing&);
    ~MComponentDataIndexing();

    MComponentDataIndexing& operator=(const MComponentDataIndexing&);

    MUintArray& fIndices;
    MComponentType fComponentType;
};

// ****************************************************************************
// CLASS DECLARATION (MIndexBufferDescriptorList)
//! \ingroup OpenMayaRender
//! \brief A list of MIndexBufferDescriptor objects
/*!
A list of MIndexBufferDescriptor objects.
*/
class OPENMAYARENDER_EXPORT MComponentDataIndexingList
{
public:
    MComponentDataIndexingList();
    ~MComponentDataIndexingList();

    int	length() const;
    const MComponentDataIndexing* operator[]( int index ) const;
    MComponentDataIndexing* operator[]( int index );

    bool append(const MComponentDataIndexing& desc);
    bool removeAt(int index);
    void clear();

    static const char* className();

OPENMAYA_PRIVATE:
    MComponentDataIndexingList(const MComponentDataIndexingList&) {}
    MComponentDataIndexingList& operator=(const MComponentDataIndexingList&) { return *this; }

    void* fData;
};

} // namespace MHWRender

OPENMAYA_NAMESPACE_CLOSE
