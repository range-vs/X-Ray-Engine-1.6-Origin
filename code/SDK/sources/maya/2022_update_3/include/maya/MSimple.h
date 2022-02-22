#pragma once

// =======================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// This computer source code and related instructions and comments are the
// unpublished confidential  and proprietary information of Autodesk, Inc.
// and are protected under applicable copyright and trade secret law. They 
// may not be disclosed to, copied  or used by any third party without the 
// prior written consent of Autodesk, Inc.
// =======================================================================

//
// This header contains two macros that can be used to simplify the
// creation of plug-in commands.
//
// ****************************************************************************

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MString.h>
#include <maya/MArgList.h>
#include <maya/MFnPlugin.h>
#include <maya/MPxCommand.h>
#include <maya/MObject.h>

//! \hideinitializer \ingroup Macros
/*!
  This macro expands to all the code necessary to create an undoable
  command except for the command's "doIt" method.

  This macro expects as arguments the name of the class that will be
  derived from MPxCommand, the name of the organisation owning this
  code, and the version number of the plug-in.

  In addition to the macro, a method with the following prototype
  needs to be implemented.

  \code
  MStatus className::doIt( const MArgList& )
  \endcode

  The macro will generate a class with the given classname that is
  derived from MPxCommand. It will also generate the following methods:

  \code
  void* className::creator()
  MStatus initializePlugin( MObject )
  MStatus uninitializePlugin( MObject )
  \endcode

  All methods inherited from MPxCommand such as \c setResult,
  \c displayWarning, and \c displayError are available.

  \param[in] _className		Name of the class
  \param[in] _vendor		Name of the organisation owning this command
  \param[in] _version		Plug-in version number
*/
#define DeclareSimpleCommand( _className, _vendor, _version )	\
class _className : public MPxCommand {							\
public:															\
					_className() {};							\
	virtual MStatus	doIt ( const MArgList& );					\
	static void*	creator();									\
};																\
void* _className::creator()										\
{																\
	return new _className;										\
}																\
MStatus initializePlugin( MObject _obj )						\
{																\
	MFnPlugin	plugin( _obj, _vendor, _version );				\
	MStatus		stat;											\
	stat = plugin.registerCommand( #_className,					\
	                                _className::creator );	    \
	if ( !stat )												\
		stat.perror("registerCommand");							\
	return stat;												\
}																\
MStatus uninitializePlugin( MObject _obj )						\
{																\
	MFnPlugin	plugin( _obj );									\
	MStatus		stat;											\
	stat = plugin.deregisterCommand( #_className );				\
	if ( !stat )												\
		stat.perror("deregisterCommand");						\
	return stat;												\
}

//! \hideinitializer \ingroup Macros
/*!
  The macro expands to all the code necessary to create a basic
  non-undoable command that calls "functionPtr" from its doIt method.
  One limitation of using this macro is that since "functionPtr" is
  not a member of the class derived from MPxCommand, it cannot call
  methods (like \c setResult) that are inherited from that class.

  This macro requires as argument a function with the prototype:
  \code
  MStatus functionPtr ( const MArgList& )
  \endcode

  The macro will generate a class called _DoItCmd which is derived from
  MPxCommand. It also generate the following methods:

  \code
  void* _DoItCmd::creator()
  MStatus _DoItCmd::doIt( const MArgList& args )
  MStatus initializePlugin( MObject )
  MStatus uninitializePlugin( MObject )
  \endcode

  \param[in] _fnptr Command function pointer
*/
#define DeclareSingle( _fnptr )									\
class _DoItCmd : public MPxCommand {							\
public:															\
					_DoItCmd() {};								\
	virtual MStatus	doIt ( const MArgList& );					\
	static void*	creator();									\
};																\
void* _DoItCmd::creator()										\
{																\
	return new _DoItCmd;										\
}																\
MStatus _DoItCmd::doIt( const MArgList& args )					\
{																\
	return _fnptr(args);										\
}																\
MStatus initializePlugin( MObject _obj )						\
{																\
	MFnPlugin	_plugin( _obj );								\
	MStatus		stat;											\
	stat = _plugin.registerCommand( #_fnptr,                    \
	                                _DoItCmd::creator );	    \
	if ( !stat )												\
		stat.perror("registerCommand");							\
	return stat;												\
}																\
MStatus uninitializePlugin( MObject _obj )						\
{																\
	MFnPlugin	plugin( _obj );									\
	MStatus		stat;											\
	stat = plugin.deregisterCommand( #_fnptr );					\
	if ( !stat )												\
		stat.perror("deregisterCommand");						\
	return stat;												\
}

