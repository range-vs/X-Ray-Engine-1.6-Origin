#pragma once

#include <vector>

#ifdef DLL_EXPORT
#define XRLC_LIGHT_API __declspec(dllexport)
#else
#define XRLC_LIGHT_API __declspec(dllimport)
#endif


struct /*XRLC_LIGHT_API*/ xrLC_GlobalData1
{
public:
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
	int d;

};
extern "C" XRLC_LIGHT_API xrLC_GlobalData1 * _data1();

