#ifndef __MPanelCanvas_h
#define __MPanelCanvas_h
//
//-
// ===========================================================================
// Copyright 2020 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================
//+

//
// CLASS:    MPanelCanvas
//
// ****************************************************************************
//
#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MTypes.h>
#include <maya/MMessage.h>
#include <maya/MStatus.h>
#include <maya/MHWGeometry.h>
#include <maya/MUIDrawManager.h>
#include <maya/MColor.h>
#include <memory>
#include <vector>

class THcallbackManager;

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MPanelCanvas)

//! \ingroup OpenMayaUI
//! \brief Custom Panel user drawing capabilities for supported panels
/*!
This class provides methods for a user to draw additional primitives
to a supporting control. The user can construct this class from the name
of a panel which supports such drawing.
*/

class OPENMAYAUI_EXPORT MPanelCanvas
{
public:
	// Internal implementation
	class Imp;
	friend class Imp;

	MPanelCanvas (const MString &panelControlName, MStatus *stat = NULL);
	~MPanelCanvas();

	/*! Principal layer values
	*/
	OPENMAYA_ENUM( DrawLayer,
		kBackground = 0,
		kFirstDefaultDraw = 100,
		kLastDefaultDraw = 10000
	);

	/*! Graph Editor reserved layers
	*/
	OPENMAYA_ENUM( GraphEditorReservedLayer,
			kGraphEditorUndefined = -1,
			kGraphEditorBackground = DrawLayer::kBackground,
			kGraphEditorFirstDefaultDraw = DrawLayer::kFirstDefaultDraw,
			kGraphEditorGrid = kFirstDefaultDraw,
			kGraphEditorAxisLabels = 1000,
			kGraphEditorCurves = 2000,
			kGraphEditorCurveNames = 3000,
			kGraphEditorTimeMarker = 4000,
			kGraphEditorRetimeToolText = 5000,
			kGraphEditorLastDefaultDraw = DrawLayer::kLastDefaultDraw,
			kGraphEditorOverlayTexture = kLastDefaultDraw
	);

	struct MDrawProperties {
		MColor color;
		float lineWidth;
		MHWRender::MUIDrawManager::LineStyle lineStyle;
		float pointSize;
	};

	/*! UI callback function definition.
	*/
	typedef void(*MDrawUIFunction) (MHWRender::MUIDrawManager &drawMgr,
									void *userData);

	bool supportsUIDrawing ();

	bool isValid ();

	int createVertexBuffer (const MTimeArray &xvals,
							const MFloatArray &yvals,
							const MColorArray *colors = NULL,
							MStatus *stat = NULL);

	int createVertexBuffer (const MFloatArray &xvals,
							const MFloatArray &yvals,
							const MColorArray *colors = NULL,
							MStatus *stat = NULL);

	int createPrimitive (	MHWRender::MGeometry::Primitive primType,
							int vertexBufferId, int startIndex,
							int numVertices,
							const MDrawProperties &props,
							MStatus *stat = NULL);

	MStatus addPrimitive (int primId, int layer);

	MStatus removePrimitive (int primId, int layer);

	MStatus destroyPrimitive (int primId);

	MStatus destroyVertexBuffer (int vertId);

	MStatus refresh();

	MStatus setAutoRefresh( bool enable );

	bool isAutoRefresh ();

	MStatus setLayerVisible(int layer, bool isVisible);

	bool isLayerVisible(int layer, MStatus *stat = NULL);

	int registerDrawUICallback ( int layer,
								MDrawUIFunction func,
								void *clientData = NULL,
								MStatus *returnStatus = NULL);

	void unregisterDrawUICallback ( int callbackId,
									MStatus *returnStatus = NULL);
private:

	friend class ::THcallbackManager;

	static void draw( int callbackManagerId
			 , MHWRender::MUIDrawManager& uiDrawMgr
			 , const std::vector<int>& callbackIds );

	void reset( bool fromCallback = false );

	static const char* className();

#if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4251)
#endif
// This warning, "needs to have dll-interface to be used by clients of class",
// causes trouble when deriving from std
	std::shared_ptr<Imp> fImp;
#if defined(_WIN32)
#pragma warning(pop)
#endif
	MCallbackId		fEditorCallbackId;
};

OPENMAYA_NAMESPACE_CLOSE

#endif /* __cplusplus */
#endif /* _MPanelCanvas */

