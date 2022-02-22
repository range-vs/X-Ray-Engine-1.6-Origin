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
// CLASS:    MPxSelectionContext
//
// ****************************************************************************

#include <maya/MPxContext.h>
#include <maya/MPoint.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPxSelectionContext)

//! \ingroup OpenMayaUI MPx
//! \brief Base class for interative selection tools 
/*!
This class is used in creating user defined tools that use the internal
selection mechanism in maya.
*/
class OPENMAYAUI_EXPORT MPxSelectionContext : public MPxContext
{
public:
	MPxSelectionContext ();
		~MPxSelectionContext () override;

BEGIN_NO_SCRIPT_SUPPORT:
		// Interfaces for viewport 2.0
		//! \noscript
		MStatus		doPress ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
		//! \noscript
		MStatus		doRelease( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
		//! \noscript
		MStatus		doDrag ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
		//! \noscript
		MStatus		doHold ( MEvent & event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
END_NO_SCRIPT_SUPPORT:

	MStatus		doPress ( MEvent & event ) override;
	MStatus		doRelease ( MEvent & event ) override;
	MStatus		doDrag ( MEvent & event ) override;
	MStatus		doHold ( MEvent & event ) override;
	MStatus 	helpStateHasChanged ( MEvent & ) override;

	MStatus     addManipulator( const MObject & manipulator ) override;
	MStatus     deleteManipulators() override;

	MStatus				setAllowPreSelectHilight();
	MStatus				setAllowSoftSelect();
	MStatus				setAllowSymmetry();
	MStatus				setAllowDoubleClickAction();

	MStatus				setImage( const MString & image, ImageIndex index );
	MString				image( ImageIndex index, MStatus * ReturnStatus = NULL ) const;
BEGIN_NO_SCRIPT_SUPPORT:
	//!     NO SCRIPT SUPPORT
	MStatus				getImage( MString & image, ImageIndex index ) const;
END_NO_SCRIPT_SUPPORT:

	// SCRIPT USE ONLY
	bool _isSelecting()
		{ return isSelecting(); }
	MPoint _startPoint()
		{ return startPoint(); }
	MPoint _lastDragPoint()
		{ return lastDragPoint(); }
	MPxToolCommand* _newToolCommand()
		{ return newToolCommand(); }
	//

protected:

	// These methods determine whether the tool will select
	// an object or operate on an object
	//!	USE _isSelecting() IN SCRIPT
	bool        isSelecting();

	// Get the world space location of the selection point
	//!	USE _startPoint() IN SCRIPT
	MPoint 		startPoint();		// point where dragging started
	//!	USE _lastDragPoint() IN SCRIPT
	MPoint 		lastDragPoint();	// preview drag point (both in WS)


	// Create an instance of a tool command for use in
	// this context.
	//
	//! CALL _newToolCommand() IN SCRIPT
	MPxToolCommand *	newToolCommand() override;

public:
	// Temporarily putting these virtual functions at the end
	void		abortAction() override;
	bool		processNumericalInput( const MDoubleArray &values, const MIntArray &flags, bool isAbsolute ) override;
	bool		feedbackNumericalInput() const override;
	MSyntax::MArgType	argTypeNumericalInput( unsigned int index ) const override;

	static const char*	className();

OPENMAYA_PRIVATE:
};

OPENMAYA_NAMESPACE_CLOSE
