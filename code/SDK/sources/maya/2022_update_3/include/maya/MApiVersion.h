#ifndef _MApiVersion
#define _MApiVersion
// ===========================================================================
// Copyright 2020 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

#ifndef MNoVersionString

// Create 2 cpp macros which will allow use to get the value of
// the #define MAYA_API_VERSION into a string and assigned to
// the global variable. (OpenMaya) (OpenMaya.py)

// This must be included on each plugin in only one compilation unit.
// Maya uses MApiVersion to know which devkit was used to build the plugin.
// As this must be an exported symbol, declaring it const and/or static breaks its visibility.

#define _versionString1( _version ) _versionString2(_version)
#define _versionString2( _version ) PLUGIN_EXPORT char MApiVersion[] =  #_version

#ifdef __cplusplus
extern "C" {
#endif

_versionString1(MAYA_API_VERSION);

// Include the Maya LT signature file if available.
// This signature is required to match the signer certificate computed hash to allow a plugin
// to be loadable in Maya LT.

#if __has_include(<MAYA_LT_SIGNATURE.h>)
    #include <MAYA_LT_SIGNATURE.h>
#else
    // MAYA SIGNATURE PLACEHOLDER
    PLUGIN_EXPORT char ADSK_PLUGIN_SIGNATURE[] = "\x1d\x20\xb5\xb5\x9d\xb2\xb3\x8d\x70\xab\xd3\x0b\x4e\x25\x81\x72\xa1\x79\x51\x11\xfb\xb3\xd3\xbb\x7c\x2b\x9b\xd7\x84\xeb\xeb\x6d\x95\x55\x12\x2b\xe0\x6c\xec\x32\x4c\xa4\x25\xb9\xb2\xea\xc7\xae\x72\x74\x57\x54\x47\x05\x21\xe1\xb2\x4d\x24\x55\xaa\x4a\x58\x86\x74\xfa\x89\xd3\xdb\xe8\x9f\xea\xe1\x91\xfc\x63\xc6\xd3\x7e\x73\x4c\x0e\x88\x77\xd6\xb8\x6d\x4f\xb2\xd1\xe1\x1d\x37\x86\x36\x72\x78\xe2\x97\x1d\xb8\x36\x5d\xcf\xc5\xcb\xba\xdb\x57\x2a\xd2\xee\x08\x36\xd2\x2e\x56\xe7\xa5\xdc\x4b\x1c\xfb\x0f\xff\x30\x98\x34";
#endif

#ifdef __cplusplus
}
#endif

// Delete the temporary macros
#undef _versionString1
#undef _versionString2

#endif // MNoVersionString

#endif /* _MApiVersion */
