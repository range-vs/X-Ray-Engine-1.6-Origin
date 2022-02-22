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
// CLASS:    MMutexLock
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MMutexLock)
//
// The MMutexLock class provides a heavyweight locking primitive to use with threads
// created by the MThreadPool class.
//
// ****************************************************************************

#include <maya/MApiNamespace.h>
#include <maya/MDeprecate.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MMutexLock)

//! \ingroup OpenMaya
//! \brief Methods for managing locks on threads created. 
/*!
 Mutex lock class now just forwarding to std::mutex.
*/
class OPENMAYA_EXPORT OPENMAYA_DEPRECATED(2020, "Use std::mutex directly") MMutexLock
{

public:
	MMutexLock();

	~MMutexLock();

	void lock();

	void unlock();

	bool tryLock();

private:
	void* f_spinLockRef;
};

OPENMAYA_NAMESPACE_CLOSE
