#include "stdafx.h"
#pragma hdrstop

#ifndef _EDITOR
#include "x_ray.h"
#endif
#include "load_screen_renderer.h"

CLoadScreenRenderer::CLoadScreenRenderer()
:b_registered(false)
{}

void CLoadScreenRenderer::start(bool b_user_input) 
{
#ifndef _EDITOR
	Device.seqRender.Add			(this, 0);
	b_registered					= true;
	b_need_user_input				= b_user_input;
#endif
}

void CLoadScreenRenderer::stop()
{
#ifndef _EDITOR
	if(!b_registered)				return;
	Device.seqRender.Remove			(this);
	pApp->destroy_loading_shaders	();
	b_registered					= false;
	b_need_user_input				= false;
#endif
}

void CLoadScreenRenderer::OnRender() 
{
#ifndef _EDITOR
	pApp->load_draw_internal();
#endif
}