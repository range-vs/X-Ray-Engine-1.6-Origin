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

#include "../../../SDK/include/stackwalker/StackWalker.h"

//USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
using namespace std;

//USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR, int)
{
	//StackWalker stackWolker;
	//stackWolker.ShowCallstack();

	try
	{
		Application->Run();
	}
	catch (Exception& exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}

