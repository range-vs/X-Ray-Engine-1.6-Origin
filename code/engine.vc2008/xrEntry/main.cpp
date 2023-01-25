#include <Windows.h>
#include "resource.h"

#pragma once(lib, "xrEngine.lib")

constexpr const char* xrEngineHandleDLLName = "xrEngine.dll";
constexpr const char* xrEngineHandleDLLFuncName = "WinMainGlobal";

using WinMainGlobalPointer = int (*)(HINSTANCE, HINSTANCE, char*, int, HWND);

HWND initLogo();
BOOL CALLBACK logDlgProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp); 

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	char* lpCmdLine,
	int       nCmdShow)
{
	auto logo = initLogo();
	HINSTANCE xrEngineHandleDLL(LoadLibrary(xrEngineHandleDLLName));

	if (!xrEngineHandleDLL) 
	{
		OutputDebugString("could not load the dynamic library xrEngine.dll");
		return EXIT_FAILURE;
	}

	auto entryPointFunc = (WinMainGlobalPointer)(GetProcAddress(xrEngineHandleDLL, xrEngineHandleDLLFuncName));
	if (!entryPointFunc) 
	{
		OutputDebugString("could not locate the function WinMainGlobal");
		return EXIT_FAILURE;
	}
	return entryPointFunc(hInstance, hPrevInstance, lpCmdLine, nCmdShow, logo);
}

HWND initLogo()
{
	// Title window
	HWND logoWindow = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_STARTUP), 0, (DLGPROC)logDlgProc); // range fix

	HWND logoPicture = GetDlgItem(logoWindow, IDC_STATIC_LOGO);
	RECT logoRect;
	GetWindowRect(logoPicture, &logoRect);

	SetWindowPos(
		logoWindow,
//#ifndef DEBUG
		HWND_TOPMOST,
//#else
//		HWND_NOTOPMOST,
//#endif // NDEBUG
		0,
		0,
		logoRect.right - logoRect.left,
		logoRect.bottom - logoRect.top,
		SWP_NOMOVE | SWP_SHOWWINDOW// | SWP_NOSIZE
	);
	UpdateWindow(logoWindow);

	return logoWindow;
}

BOOL CALLBACK logDlgProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_INITDIALOG:
	{
		HICON hicon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hw, WM_SETICON, ICON_BIG, (LPARAM)hicon);
		break;
	}
	case WM_DESTROY:
		break;
	case WM_CLOSE:
		DestroyWindow(hw);
		break;
	case WM_COMMAND:
		if (LOWORD(wp) == IDCANCEL)
			DestroyWindow(hw);
		break;
	default:
		return FALSE;
	}
	return TRUE;
}
