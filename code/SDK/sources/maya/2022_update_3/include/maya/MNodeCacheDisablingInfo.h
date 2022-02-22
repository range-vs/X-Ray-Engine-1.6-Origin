#ifndef _MNodeCacheDisablingInfo
#define _MNodeCacheDisablingInfo
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#include <maya/MString.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

/*!
\brief		Defines additional info about why the node disables Cached Playback
\warning	Do not store pointers to this object
\warning	Users cannot construct or destroy this Maya object
*/
class OPENMAYA_EXPORT MNodeCacheDisablingInfo {
private:
	MNodeCacheDisablingInfo() = delete;
	~MNodeCacheDisablingInfo() = delete;
	MNodeCacheDisablingInfo(const MNodeCacheDisablingInfo&) = delete;
	MNodeCacheDisablingInfo(MNodeCacheDisablingInfo&&) = delete;
	MNodeCacheDisablingInfo& operator=(const MNodeCacheDisablingInfo&) = delete;
	MNodeCacheDisablingInfo& operator=(MNodeCacheDisablingInfo&&) = delete;

public:
	//! \brief Sets if the cache should be disabled because of this node.
	void setCacheDisabled(bool disabled);
	//! \brief Gets if the cache should be disabled because of this node.
	bool getCacheDisabled() const;

	//! \brief Sets the reason for disabling Cached Playback.
	void setReason(const MString& reason);

	//! \brief Sets the mitigation to fix the reason for disabling Cached Playback.
	void setMitigation(const MString& mitigation);

	//! \brief Resets the disabling info to an enabled state.
	void reset();

};

OPENMAYA_NAMESPACE_CLOSE
#endif // _MNodeCacheDisablingInfo
