#pragma once
#include <maya/MApiNamespace.h>

//! \brief Pointer to a creator function.
/*!
 \return
	An opaque pointer to the created object. The type of the object
	depends upon where the function is being used.
*/
typedef void *   (*MCreatorFunction)();

//! \brief Pointer to a creator function for a custom evaluator.
/*!
 \return
	A pointer to the created custom evaluator.
*/
typedef MPxCustomEvaluator* (*MCustomEvaluatorCreatorFunction)();

//! \brief Pointer to a creator function for a topology evaluator.
/*!
 \return
	A pointer to the created topology evaluator.
*/
typedef MPxTopologyEvaluator* (*MTopologyEvaluatorCreatorFunction)();

//! \brief Pointer to a syntax creation function.
/*!
 \return The syntax object created.
*/
typedef MSyntax(*MCreateSyntaxFunction)();

//! \brief Pointer to an initialization function.
/*!
 \return Status of the function call.
*/
typedef MStatus(*MInitializeFunction)();

//! \brief Pointer to a function which creates a custom transformation matrix.
/*!
 \return Pointer to the created transformation matrix.
*/
typedef MPxTransformationMatrix* (*MCreateXformMatrixFunction)();

//! \brief Pointer to a function which creates a cache configuration rule filter.
/*!
\param[in] param    the initialization parameter for the created filter.
\return The filter created.
*/
typedef MPxCacheConfigRuleFilter* (*MCreateCacheConfigRuleFilterFunction)(const MString &param);

#ifndef SWIG
    struct _object;
    typedef struct _object PyObject;

    //! \brief Pointer to a function to convert MObject into a Python 2.0 API object.
    /*!
    \param[in] obj    script object.
     \return Status of the function call.
    */
    typedef PyObject*(*MPythonAPI20ValueToObjectFunction)(const MObject& obj);
#endif

//! \ingroup OpenMaya
//! \brief Helper class for plugin callbacks and messages
/*!
Used internally to forward calls to Python scripts and .Net functions
*/
class MPluginCallableInfo
{
public:
	MPluginCallableInfo() = default;
	virtual ~MPluginCallableInfo() = default;
};

// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

