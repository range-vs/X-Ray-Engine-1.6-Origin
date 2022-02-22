#ifndef _clew_cl_h
#define _clew_cl_h

/*

	Include everything we need to handle the OpenCL extensions we are using.  CLEW
	doesn't have extension support, so we need to add everything we case about here.

	The basic steps for each method are:

	Header file:
	 - declare the function pointer type.  This should exactly match the OpenCL function.
	 - declare a variable of the defined type to hold the entry point into OpenCL
	 - define a macro which exactly matches the OpenCL function name which instead uses the function pointer

	cpp file:
	 - initialize the function pointer variable to NULL
	 - in an init method, initialize the function pointer variable to the proper value

	I will follow the same naming conventions that clew uses:
	 - function pointers called PFNCLFUNCTIONNAME

	Everything defined here should exactly match the signature of OpenCL functions,
	please don't try to do anything beyond that.  If you want to do something more,
	do it in another file.

*/

/* This header is a simple wrapper on to clew.h

This version is from https://github.com/martijnberger/clew this is not a very active repo, so is copied here
rather forked.

glew.h is unchanged.
glew.c is changed to add extension intialisation to clewInit.

This update depracated a number of functions that Maya uses.

2020/11/23
*/

#include <clew/clew.h>
#include <clew/clew_cl_gl.h>
#include <clew/clew_cl_gl_ext.h>
#include <clew/clew_cl_d3d11.h>
#include <clew/clew_cl_d3d11_ext.h>


// ==================================================================
// Copyright 2020 Autodesk, Inc.  All rights reserved.
// 
// This computer source code  and related  instructions and comments are
// the unpublished confidential and proprietary information of Autodesk,
// Inc. and are  protected  under applicable  copyright and trade secret
// law. They may not  be disclosed to, copied or used by any third party
// without the prior written consent of Autodesk, Inc.
// ==================================================================
//+

#endif // _clew_cl__h