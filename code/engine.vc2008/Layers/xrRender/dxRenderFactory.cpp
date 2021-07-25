#include "stdafx.h"
#include "dxRenderFactory.h"

#include "dxStatGraphRender.h"
#ifndef _EDITOR
	#include "dxLensFlareRender.h"
#endif
#include "dxConsoleRender.h"
#ifndef _EDITOR
	#include "dxThunderboltRender.h"
	#include "dxThunderboltDescRender.h"
	#include "dxRainRender.h"
	#include "dxLensFlareRender.h"
   // #include "dxEnvironmentRender.h"

	#include "dxRenderDeviceRender.h"
	#include "dxObjectSpaceRender.h"
#endif // _EDITOR

#include "dxEnvironmentRender.h"

#include "dxFontRender.h"
#include "dxApplicationRender.h"
#include "dxWallMarkArray.h"
#include "dxStatsRender.h"
#include "dxUISequenceVideoItem.h"
#include "dxUIShader.h"

dxRenderFactory RenderFactoryImpl;

//# include "dx##Class.h" \

#define RENDER_FACTORY_IMPLEMENT(Class) \
	I##Class* dxRenderFactory::Create##Class() \
{ \
	return xr_new<dx##Class>(); \
} \
	void dxRenderFactory::Destroy##Class(I##Class *pObject)\
{ \
	xr_delete((dx##Class*&)pObject); \
} \

/*IStatGraphRender* dxRenderFactory::CreateStatGraphRender()
{
	return xr_new<dxStatGraphRender>();
}
void dxRenderFactory::DestroyStatGraphRender(IStatGraphRender *pObject)
{
	xr_delete((dxStatGraphRender*&)pObject);
}*/

RENDER_FACTORY_IMPLEMENT(StatGraphRender)
RENDER_FACTORY_IMPLEMENT(StatsRender)
RENDER_FACTORY_IMPLEMENT(EnvDescriptorRender)
RENDER_FACTORY_IMPLEMENT(EnvDescriptorMixerRender)
RENDER_FACTORY_IMPLEMENT(EnvironmentRender)

#ifndef _EDITOR
	RENDER_FACTORY_IMPLEMENT(UISequenceVideoItem)
	RENDER_FACTORY_IMPLEMENT(UIShader)
	RENDER_FACTORY_IMPLEMENT(ConsoleRender)
	RENDER_FACTORY_IMPLEMENT(RenderDeviceRender)
#	ifdef DEBUG
		RENDER_FACTORY_IMPLEMENT(ObjectSpaceRender)
#	endif // DEBUG
	RENDER_FACTORY_IMPLEMENT(ApplicationRender)
	RENDER_FACTORY_IMPLEMENT(WallMarkArray)
#endif // _EDITOR

#ifndef _EDITOR
    RENDER_FACTORY_IMPLEMENT(ThunderboltRender)
    RENDER_FACTORY_IMPLEMENT(ThunderboltDescRender)
    RENDER_FACTORY_IMPLEMENT(RainRender)
    RENDER_FACTORY_IMPLEMENT(LensFlareRender)
    RENDER_FACTORY_IMPLEMENT(FlareRender)
#endif
RENDER_FACTORY_IMPLEMENT(FontRender)
