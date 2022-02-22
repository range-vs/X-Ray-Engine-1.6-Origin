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
// CLASS:    MPxTexContext
//
// ****************************************************************************

#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MEvent.h>
#include <maya/MString.h>
#include <maya/MSyntax.h>
#include <maya/MObject.h>
#include <maya/MPxContext.h>
#include <maya/MSelectionMask.h>
#include <maya/MSelectionList.h>
#include <maya/MPxToolCommand.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPxTexContext)

//! \ingroup OpenMayaUI MPx
//! \brief Base class for user defined contexts working on uv editor 
/*!
This is the base class for user defined contexts working on uv editor.
*/

class OPENMAYAUI_EXPORT MPxTexContext : public MPxContext
{
public:

	MPxTexContext ();
		~MPxTexContext () override;
										
BEGIN_NO_SCRIPT_SUPPORT:
	//! \noscript
	MStatus		doPress ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
	//! \noscript
	MStatus		doRelease( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
	//! \noscript
	MStatus		doDrag ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
	//! \noscript
	MStatus		doPtrMoved ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
END_NO_SCRIPT_SUPPORT:
	
	void viewToPort( double xView, double yView, short &xPort, short &yPort ) const; 
	void portToView( short xPort, short yPort, double &xView, double &yView) const;	
	void viewRect(double &left, double &right, double &bottom, double &top) const;
	void portSize(double &width, double &height) const ;
	
	static bool getMarqueeSelection( double xMin, double yMin, double xMax, double yMax, 
		const MSelectionMask &mask, bool bPickSingle, bool bIgnoreSelectionMode, MSelectionList &selectionList ); 

	static const char*	className();

	MPxToolCommand *newToolCommand() override;

OPENMAYA_PRIVATE:
};

OPENMAYA_NAMESPACE_CLOSE
