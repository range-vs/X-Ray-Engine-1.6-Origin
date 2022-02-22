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
// CLASS:    MPxViewportComputeItem
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MPxViewportComputeItem)
//
//  MPxViewportComputeItem is a virtual base class meant to provide a means for users to
//  attach compute to certain Maya object types such that the lifetime of
//  the compute is managed by Maya.
//
// ****************************************************************************

#include <maya/MApiNamespace.h>
#include <limits.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// NAMESPACE

namespace MHWRender
{

// ****************************************************************************
// INCLUDED HEADER FILES

// ****************************************************************************
// DECLARATIONS

// ****************************************************************************
// CLASS DECLARATION (MPxViewportComputeItem)

//! \ingroup OpenMayaRender MPx
//! \brief Virtual base class for user viewport compute
/*!
MPxViewportComputeItem is a virtual base class meant to provide a means for users to
attach compute to certain Maya object types such that the lifetime of
the compute may be managed by Maya.

When hasExternalOwner is false then the MPxViewportComputeItem is owned by the Maya
object it is attached to and the MPxViewportComputeItem will be deleted when that object
is deleted. When hasExternalOwner is true the lifetime of the MPxViewportComputeItem object
is the responsibility of the allocator.

A typical use case for MPxViewportComputeItem would be to compute stream data for an
MRenderItem. For example, a shaded MRenderItem could be created with only a postion
buffer & an MPxViewportComputeItem attached to compute & fill the normal buffer.

When MPxViewportComputeItem is attached to an MRenderItem it is visible to consolidated
world. Use methods canConsolidate() and cloneForConsolidation() to control how
MPxViewportComputeItem interacts with consolidation.

An MPxViewportComputeItem must declare the action(s) it will take during a call to execute.
These actions reflect access to resources or modification of the associated MRenderItem, or
access to global resources. See setRequiredAction() and execute() for more information.
*/
class OPENMAYARENDER_EXPORT MPxViewportComputeItem
{
public:
    //! Actions an MPxViewportComputeItem may perform during its operator() call. Some MRenderItem functions can never be called during execute(): setDrawMode, setShader, setShaderFromNode, setExcludedFromPostEffect, supportsAdvancedTransparency, setCustomData, enable, castsShadows, recievesShadows, depthPriority, setAllowIsolateSelectCopy, setWAntConsolidation, setCompatibleWithMayaInstancer, setTreatAsTransparent, setSelectionMask, setWantSubSceneConsolidation may never be called.
    enum Action {
        kAccessVirtualDevice = 0x1 << 0, //!< The VP2 Draw API context, such as when calling MVertexBuffer::resourceHandle().
        kAccessConsolidation = 0x1 << 1, //!< The MGeometryIndexMapping for the item (if any).
        kModifyVertexBufferSize = 0x1 << 2, //!< The size of the MVertexBuffers can be modified.
        kModifyMatrix = 0x1 << 3, //!< MRenderItem::setMatrix may be called. Not currently supported.
        kModifyConsolidation = 0x1 << 4, //!< MRenderItem::setSourceIndexMapping() may be called.
        kModifyBounds = 0x1 << 5, //!< Set new object space bounds. Not currently supported.
        kAddVertexStream = 0x1 << 6, //!< New streams may be added to the MRenderItem's MGeometry. Not currently supported.
        kModifyVertexBufferData = 0x1 << 7, //!< Data in MVertexBuffers stored in the MRenderItems MGeometry may be modified.
        kModifyPrimitive = 0x1 << 8, //!< MRenderItem::setPrimitive() may be called. Not currently supported.
        kActionFinal = 0x1 <<9, //!< The final call to execute() for this frame.
        //
        kActionAll = UINT_MAX
    };

    /*!
    A bitmask storing a set of actions.
    */
    struct Actions
    {
        Actions() : bitmask(0) {}
        Actions(unsigned int actions) : bitmask(actions) {}

        void bitSet(Action action);
        void bitClear(Action action);
        bool bitCheck(Action action) const;

        void bitmaskSet(Actions actions);
        void bitmaskClear(Actions actions);
        bool bitmaskCheckAll(Actions actions) const;
        bool bitmaskCheckAny(Actions actions) const;

        unsigned int bitmask;
    };

	MPxViewportComputeItem(bool hasExternalOwner);
    MPxViewportComputeItem(const MPxViewportComputeItem&) = delete;
    MPxViewportComputeItem& operator=(const MPxViewportComputeItem&) = delete;
	virtual ~MPxViewportComputeItem();

	bool hasExternalOwner() const;
	void setHasExternalOwner(bool hasExternalOwner);

    MStatus setRequiredAction(Action action, bool required);
    bool hasRequiredAction(Action action) const;
    Actions requiredActions() const;

    virtual bool execute(const Actions& availableActions, MRenderItem& renderItem) = 0;
    
    virtual bool canConsolidate(const MPxViewportComputeItem& other) const = 0;
    virtual MSharedPtr<MPxViewportComputeItem> cloneForConsolidation() const = 0;

    static const char*	    className();

OPENMAYA_PRIVATE:
    void* fData;
};

} // namespace MHWRender

OPENMAYA_NAMESPACE_CLOSE
