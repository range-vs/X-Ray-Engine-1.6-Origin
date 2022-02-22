#pragma once
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
// CLASS:    MFnStandardSurfaceShader
//
// ****************************************************************************

#include <maya/MObject.h>
#include <maya/MStatus.h>
#include <maya/MFnDependencyNode.h>

OPENMAYA_MAJOR_NAMESPACE_OPEN

// ****************************************************************************
// CLASS DECLARATION (MFnStandardSurfaceShader)

//! \ingroup OpenMaya MFn
//! \brief Manage Standard Surface Shaders. 
/*!
 MFnStandardSurfaceShader facilitates the creation and manipulation of
 dependency graph nodes representing standard surface shaders.
*/
class OPENMAYA_EXPORT MFnStandardSurfaceShader : public MFnDependencyNode
{
	declareMFn( MFnStandardSurfaceShader, MFnDependencyNode );

public:
	MObject 	create( bool UIvisible = true, MStatus * ReturnStatus = NULL );
	float	base( MStatus * ReturnStatus = NULL ) const;
	MStatus	setBase( const float& base );
	MColor	baseColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setBaseColor( const MColor& base_color );
	float	diffuseRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setDiffuseRoughness( const float& diffuse_roughness );
	float	metalness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setMetalness( const float& metalness );
	float	specular( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecular( const float& specular );
	MColor	specularColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecularColor( const MColor& specular_color );
	float	specularRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecularRoughness( const float& specular_roughness );
	float	specularIOR( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecularIOR( const float& specular_i_o_r );
	float	specularAnisotropy( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecularAnisotropy( const float& specular_anisotropy );
	float	specularRotation( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSpecularRotation( const float& specular_rotation );
	float	transmission( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmission( const float& transmission );
	MColor	transmissionColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionColor( const MColor& transmission_color );
	float	transmissionDepth( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionDepth( const float& transmission_depth );
	MColor	transmissionScatter( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionScatter( const MColor& transmission_scatter );
	float	transmissionScatterAnisotropy( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionScatterAnisotropy( const float& transmission_scatter_anisotropy );
	float	transmissionDispersion( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionDispersion( const float& transmission_dispersion );
	float	transmissionExtraRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setTransmissionExtraRoughness( const float& transmission_extra_roughness );
	float	subsurface( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSubsurface( const float& subsurface );
	MColor	subsurfaceColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSubsurfaceColor( const MColor& subsurface_color );
	MColor	subsurfaceRadius( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSubsurfaceRadius( const MColor& subsurface_radius );
	float	subsurfaceScale( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSubsurfaceScale( const float& subsurface_scale );
	float	subsurfaceAnisotropy( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSubsurfaceAnisotropy( const float& subsurface_anisotropy );
	float	coat( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoat( const float& coat );
	MColor	coatColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatColor( const MColor& coat_color );
	float	coatRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatRoughness( const float& coat_roughness );
	float	coatIOR( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatIOR( const float& coat_i_o_r );
	float	coatAnisotropy( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatAnisotropy( const float& coat_anisotropy );
	float	coatRotation( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatRotation( const float& coat_rotation );
	float	coatAffectColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatAffectColor( const float& coat_affect_color );
	float	coatAffectRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setCoatAffectRoughness( const float& coat_affect_roughness );
	float	sheen( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSheen( const float& sheen );
	MColor	sheenColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSheenColor( const MColor& sheen_color );
	float	sheenRoughness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setSheenRoughness( const float& sheen_roughness );
	float	emission( MStatus * ReturnStatus = NULL ) const;
	MStatus	setEmission( const float& emission );
	MColor	emissionColor( MStatus * ReturnStatus = NULL ) const;
	MStatus	setEmissionColor( const MColor& emission_color );
	float	thinFilmThickness( MStatus * ReturnStatus = NULL ) const;
	MStatus	setThinFilmThickness( const float& thin_film_thickness );
	float	thinFilmIOR( MStatus * ReturnStatus = NULL ) const;
	MStatus	setThinFilmIOR( const float& thin_film_i_o_r );
	bool	thinWalled( MStatus * ReturnStatus = NULL ) const;
	MStatus	setThinWalled( const bool& thin_walled );
	MColor	opacity( MStatus * ReturnStatus = NULL ) const;
	MStatus	setOpacity( const MColor& opacity );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnStandardSurfaceShader, MFnDependencyNode );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

OPENMAYA_NAMESPACE_CLOSE
