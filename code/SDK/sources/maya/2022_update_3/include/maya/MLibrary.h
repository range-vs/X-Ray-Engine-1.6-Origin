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
// CLASS:    MLibrary
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MTypes.h>

#ifndef SWIG
//	Make sure those functions have the proper export/visibility
	PLUGIN_EXPORT MStatus initialize (const char* applicationName, bool useBatchLicense = false);
	PLUGIN_EXPORT MStatus initialize (bool wantScriptOutput, const char* applicationName, bool useBatchLicense = false);
	PLUGIN_EXPORT void cleanup( int exitStatus = 0, bool exitWhenDone = true );
#endif

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MLibrary)

//! Set up Maya to run in library mode. (OpenMaya)
/*!
 Initialize and cleanup routines for Maya running in library mode.

When creating a "library mode" Maya application, this class must be
used in the program's main routine to initialize Maya, and later
to cleanUp allocated Maya state.  A typical usage would be:

\code
    main(int argc, char **argv)
    {
        MStatus status;
        status = MLibrary::initialize (argv[0], true);
        if ( !status ) {
            status.perror("MLibrary::initialize");
            return (1);
        }

        // Maya API code goes here

        MLibrary::cleanup();
        return (0);
    }
\endcode

If the call to cleanup is omitted, you will get errors when the program
exits as the static destructors in the Maya libraries are run.
*/
class OPENMAYA_EXPORT MLibrary
{
public:
						MLibrary ();
	virtual				~MLibrary ();
	static MStatus		initialize (const char* applicationName,
									bool useBatchLicense = false);
	static MStatus		initialize (bool wantScriptOutput,
									const char* applicationName,
									bool useBatchLicense = false);

	static void			cleanup( int exitStatus = 0, bool exitWhenDone = true );

protected:
// No protected members

private:
// No private members

};

OPENMAYA_NAMESPACE_CLOSE
