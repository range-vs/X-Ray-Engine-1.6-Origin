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
// CLASS:    MFnFalloffData
//
// ****************************************************************************

#include <maya/MFnData.h>
#include <maya/MFloatArray.h>
#include <maya/MFnGeometryData.h>
#include <maya/MIndexMapper.h>
#include <maya/MSharedPtr.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

//! \ingroup OpenMayaAnim
//! \brief identifier for weight buffer
/*!
    An MBufferIdentifier form a unique identifier for a weight buffer.
    It can be form with an MpxNode* and a layerId to be able to provide more than one layer per node.
*/
class OPENMAYAANIM_EXPORT MBufferIdentifier
{
public:
  MBufferIdentifier(MPxNode* source, unsigned int layerId=0);
  MBufferIdentifier(const MBufferIdentifier&);
  MBufferIdentifier(MBufferIdentifier&&);
  ~MBufferIdentifier();
  MBufferIdentifier& operator=(const MBufferIdentifier&);
  MBufferIdentifier& operator=(MBufferIdentifier&&);

OPENMAYA_PRIVATE:
  MBufferIdentifier(void *);
  void* impl{nullptr};
};


//! \ingroup OpenMayaAnim
//! \brief falloff context use in a falloff function to get/set information for weight computation.
/*!
    An MFalloffContext is provided to a MFalloffFunction::operator() that user override to create its own weight falloff.
*/
class OPENMAYAANIM_EXPORT MFalloffContext
{
  public:

  MFloatArray getValues(const MBufferIdentifier& bufferId)const;
  void        setValue(const MFloatArray& array, const MBufferIdentifier& bufferId);
  bool isTopologyDirty()const;
  bool isSync(int syncId, const MBufferIdentifier& bufferId)const;
  void sync(int syncId, const MBufferIdentifier& bufferId);
  MObject getGeometry(bool originalGeometry=false);
  MIndexMapper getIndexMapper()const;

OPENMAYA_PRIVATE:
  MFalloffContext()=delete;
  MFalloffContext(void*);
  ~MFalloffContext();
  
  void* impl;
};


//! \ingroup OpenMayaAnim
//! \brief base class falloff function
/*!
    An MFalloffFunction is meant to be sub-classed to define your weight falloff function.
*/
class OPENMAYAANIM_EXPORT MFalloffFunction
{
  public:
    virtual ~MFalloffFunction();

  //! \ingroup OpenMayaAnim
  //! \brief Return Value data type for a falloff function
  /*!
      ReturValue indicate the buffer with the bufferId
      it indicated if it require Original Geometry or the Current geometry from the current geom deformer
      it returns as well if the buffer is intact from last evaluation "Cached"
  */
  struct OPENMAYAANIM_EXPORT ReturnValue{
    enum Requirement{
        None = 0,
        OriginalGeom = 1,
        CurrentGeom = 2
    };
    enum CachedIndicator{
        NotCached = 0,
        Cached = 1
    };
    
    ReturnValue();
    ReturnValue(const MBufferIdentifier& bufferId, Requirement, CachedIndicator);
    ReturnValue(ReturnValue&&);
    ~ReturnValue();

    MBufferIdentifier getBufferId()const;
    Requirement       getRequirement()const;
    CachedIndicator   getCachedIndicator()const;

  private:
    ReturnValue(const ReturnValue&);
OPENMAYA_PRIVATE:
    struct Impl;
    Impl* impl;
    ReturnValue(const Impl&);
      
  };
  virtual ReturnValue operator()(MFalloffContext&)=0;
};


// ****************************************************************************
// CLASS DECLARATION (MFnFalloffData)

//! \ingroup OpenMaya MFn
//! \brief Matrix function set for dependency node data.
/*!
  MFnFalloffData allows the creation and manipulation of falloff data function.
  Falloff data are created to define or call a falloff function.
  User can create its own falloff by subclassing MFalloffFunction
*/
class OPENMAYAANIM_EXPORT MFnFalloffData : public MFnData
{
	declareMFn(MFnFalloffData, MFnData);

public:

  MFalloffFunction::ReturnValue call(MFalloffContext& accessor);

	MObject					create(MSharedPtr<MFalloffFunction>, MStatus* ReturnStatus=NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnFalloffData, MFnData );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE
