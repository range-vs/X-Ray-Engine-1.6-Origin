#ifndef __MPanelCanvasInfo_h
#define __MPanelCanvasInfo_h
//
//-
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+

//
// CLASS:    MPanelCanvasInfo
//
// ****************************************************************************
//
#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MMessage.h>
#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MDoubleArray.h>
#include <maya/MString.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPanelCanvasInfo)

//! \ingroup OpenMayaUI
//! \brief Panel state information setting and retrieval
/*!
This class provides methods for setting and retrieving common information
for all supported panels. Currently, the Graph Editor is the only supported
editor.
*/

class OPENMAYAUI_EXPORT MPanelCanvasInfo
{
	public:
	/*! The constructor. A valid panel control name is required. For
	    example, the panel control name of the default Graph Editor is
	    "graphEditor1GraphEd".
	*/
	MPanelCanvasInfo(const MString &editorName, MStatus *stat = NULL);
	virtual ~MPanelCanvasInfo();


	/*! Return the viewport bounds.
	*/
	MStatus getViewportBounds(	double &left, double &right,
								double &bottom, double &top) const;
	MStatus getViewportBounds(	MDoubleArray &boundsArray) const;

	/*! Return the viewport size.
	*/
	MStatus getViewportSize(	int &width, int &height ) const;

	/*! Set the viewport bounds.
	*/
	MStatus setViewportBounds(	double left, double right,
								double bottom, double top) const;
	MStatus setViewportBounds(	const MDoubleArray &boundsArray) const;

	/*! Returns whether the attached panel control supports drawing
	    primitives in screen space. If such drawing is not supported,
	    the registerDrawUICallback () method will return
	    MStatus::kNotImplemented.
	   
	    Note that for the Graph Editor, if the panel for drawing has not yet
	    been created (e.g., when the default Graph Editor has not yet been
	    opened), this method will return false.
	*/
	bool supportsUIDrawing ();

	void reset();

	/*! Return the name of the currently attached panel.
	*/
	MString name() const;

	static const char* className();

private:

	friend class MGraphEditorInfo;
	virtual void attachToGraphEditor( const MString &editorName
									, MStatus* ReturnStatus
									, const bool reportErrors=false);
	void*	fInternalPtr;
	MCallbackId fGraphEditorCallbackId;

	//! True if and only if attached panel is a Graph Editor
	bool	fIsGraphEditor;
};

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MPanelCanvasInfo */

