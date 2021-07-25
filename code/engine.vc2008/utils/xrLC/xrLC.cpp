// xrLC.cpp : Defines the entry point for the application.
//
#include "../xrLC_Light/xrLC_GlobalData.h"
#include <windows.h>

#pragma comment(lib, "xrLC_Light.lib")

int APIENTRY WinMain(HINSTANCE hInst,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	xrLC_GlobalData1* b = _data1();
	b->a.push_back(1);
	xrLC_GlobalData1* c = new xrLC_GlobalData1();

	return 0;
}
