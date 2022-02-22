#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

//#include "../Include/stack_trace.h"
//#include "../../../SDK/include/stackwolker/StackWalker.h"

//#pragma comment(lib, "stack_wolker_b")

//#include "../../../SDK/include/stackwalker/StackWalker.h"

//USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
using namespace std;

//USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR, int)
{
	//StackWalker stackWolker;
	//stackWolker.ShowCallstack();

	/*try
	{
		Application->Run();
	}
	catch (Exception& exception)
	{
		Application->ShowException(&exception);
	}
	return 0;  */

	HMODULE h;
	try
	{
		h = LoadLibrary("c:\\X-Ray-Engine-1.6-Origin\\bins\\Win64\\Debug\\XRSOUNDB.DLL");
		h = LoadLibrary("c:\\X-Ray-Engine-1.6-Origin\\bins\\Win64\\Debug\\XRECOREB.DLL");
	}
	catch(...)
	{
        int a = 46;
	}
	h = LoadLibrary("c:\\X-Ray-Engine-1.6-Origin\\bins\\Win64\\Debug\\XREPROPSB.DLL");
	h = LoadLibrary("c:\\X-Ray-Engine-1.6-Origin\\bins\\Win64\\Debug\\XRCOREB.DLL");
	h = LoadLibrary("c:\\X-Ray-Engine-1.6-Origin\\bins\\Win64\\Debug\\CC32C270MT.DLL");

    int a = 45;

    return 0;
}

