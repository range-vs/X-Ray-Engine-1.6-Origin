#ifndef _MNodeCacheSetupInfo
#define _MNodeCacheSetupInfo
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#include <maya/MTypes.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

/*!
\brief		Defines preferences and requirements the node has for Cached Playback
\warning	Do not store pointers to this object
\warning	Users cannot construct or destroy this Maya object
*/
class OPENMAYA_EXPORT MNodeCacheSetupInfo {
private:
	MNodeCacheSetupInfo() = delete;
	~MNodeCacheSetupInfo() = delete;
	MNodeCacheSetupInfo(const MNodeCacheSetupInfo&) = delete;
	MNodeCacheSetupInfo(MNodeCacheSetupInfo&&) = delete;
	MNodeCacheSetupInfo& operator=(const MNodeCacheSetupInfo&) = delete;
	MNodeCacheSetupInfo& operator=(MNodeCacheSetupInfo&&) = delete;

public:
	//! Defines the preference flags that can be set for this node
	OPENMAYA_ENUM(PreferenceFlag,
		kWantToCacheByDefault, //!< Whether or not this node wants to be cached in Evaluation Cache by default.
		kLastPreference        //!< Last value, used for counting
		);

	//! \brief Set a preference flag for this node
	void setPreference(PreferenceFlag, bool);
	//! \brief Get a preference flag for this node
	bool getPreference(PreferenceFlag) const;

	//! Defines the requirement flags that can be set for this node
	OPENMAYA_ENUM(RequirementFlag,
		kSimulationSupport, //!< Whether or not this node requires simulation support, i.e. handling restart time and the such.
		kLastRequirement    //!< Last value, used for counting
	);

	//! \brief Set a requirement flag for this node
	void setRequirement(RequirementFlag, bool);
	//! \brief Get a requirement flag for this node
	bool getRequirement(RequirementFlag) const;
};

OPENMAYA_NAMESPACE_CLOSE
#endif // _MNodeCacheSetupInfo
