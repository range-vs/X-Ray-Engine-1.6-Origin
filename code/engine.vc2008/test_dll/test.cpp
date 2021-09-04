#include "test.h"

#include "../xrCore/xrMemory.h"

xrLC_GlobalData_debug* data = 0;

xrLC_GlobalData_debug* lc_global_data_debug()
{
	return data;
}

void create_global_data_debug()
{
	data = xr_new<xrLC_GlobalData_debug>();
}