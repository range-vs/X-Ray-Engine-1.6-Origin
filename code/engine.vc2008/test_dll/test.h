#pragma once

#include "../xrEngine/stdafx.h"

#ifdef DLL
#define XRLC_LIGHT_API_debug __declspec( dllexport )
#else
#define XRLC_LIGHT_API_debug __declspec( dllimport )
#endif

#include <vector>

class XRLC_LIGHT_API_debug xrLC_GlobalData_debug
{
public:
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	double d{ 0.0 };

};

extern "C" XRLC_LIGHT_API_debug xrLC_GlobalData_debug * lc_global_data_debug();
extern "C" XRLC_LIGHT_API_debug void create_global_data_debug();