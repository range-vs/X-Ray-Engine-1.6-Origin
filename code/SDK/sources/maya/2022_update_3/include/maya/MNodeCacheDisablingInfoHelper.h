#ifndef _MNodeCacheDisablingInfoHelper
#define _MNodeCacheDisablingInfoHelper
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#include <maya/MNodeCacheDisablingInfo.h>
#include <maya/MObject.h>
#include <maya/MEvaluationNode.h>
#include <maya/MObjectArray.h>
#include <maya/MPlug.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

/*!
\brief		Provides helpers for MNodeCacheDisablingInfo
*/
class OPENMAYA_EXPORT MNodeCacheDisablingInfoHelper {
public:
	//! \brief Helper to set the reason and mitigation for an unsafe node.
	static void setUnsafeNode(
		MNodeCacheDisablingInfo& disablingInfo,
		const MEvaluationNode& node,
		const MString* nodeCategory = NULL
	);

	//! \brief Helper to set the reason and mitigation for an unsafe value on a node's attribute.
	static void setUnsafeValue(
		MNodeCacheDisablingInfo& disablingInfo,
		const MEvaluationNode& node,
		const MObject& attribute,
		const MString& attributeValue,
		const MString& supportedValue,
		const MString* nodeCategory = NULL
	);

	//! Defines the connection test that can be done on animated attributes
	OPENMAYA_ENUM(ConnectionTestFlag,
		kTestDirtyPlug,      //!< Do not perform an additional test; the attribute is considered animated if part of the dirty plug list.
		kTestHierarchy,      //!< Test whether the plug or any of its parents has a connection; if they don't the attribute is not considered animated.
		kTestPlug,           //!< Test whether the plug has a connection; if it doesn't the attribute is not considered animated.
		kLastConnectionTest, //!< Last value, used for counting
		kTestDefaultValue = kTestDirtyPlug //!< Value used by default for the tests.
	);

	//! \brief Helper to set the reason and mitigation on a node with a conditionally supported attribute if it is animated.
	static bool testAnimatedAttribute(
		MNodeCacheDisablingInfo* disablingInfo,
		MObjectArray& monitoredAttributes,
		const MEvaluationNode& node,
		const MPlug& plug,
		ConnectionTestFlag connectionTest = kTestDefaultValue,
		const MString* nodeCategory = NULL,
		MStatus* ReturnStatus = NULL
	);

	//! \brief Helper to set the reason and mitigation on a node with a conditionally supported boolean attribute.
	static bool testBooleanAttribute(
		MNodeCacheDisablingInfo* disablingInfo,
		MObjectArray& monitoredAttributes,
		const MEvaluationNode& node,
		const MObject& attribute,
		bool supportedValue,
		ConnectionTestFlag connectionTest = kTestDefaultValue,
		const MString* nodeCategory = NULL,
		MStatus* ReturnStatus = NULL
	);

BEGIN_NO_SCRIPT_SUPPORT:
	// These methods do not get SWIG-ed properly for the OpenMayaNet version of the API.
	// For some reasons, even if arrays of int, float or double are working, arrays of short are not.
	// For the time being, we will not SWIG those.
	#if !defined(SWIG)
	//! \brief Helper to set the reason and mitigation on a node with a conditionally supported enum attribute.
	//! NO SCRIPT SUPPORT
	static bool testEnumAttribute(
		MNodeCacheDisablingInfo* disablingInfo,
		MObjectArray& monitoredAttributes,
		const MEvaluationNode& node,
		const MObject& attribute,
		const short supportedValues[],
		int supportedValuesCount,
		ConnectionTestFlag connectionTest = kTestDefaultValue,
		const MString* nodeCategory = NULL,
		MStatus* ReturnStatus = NULL
	);
	#endif
END_NO_SCRIPT_SUPPORT:
};

OPENMAYA_NAMESPACE_CLOSE
#endif // _MNodeCacheDisablingInfoHelper
