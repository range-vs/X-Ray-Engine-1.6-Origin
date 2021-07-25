//#include "stdafx.h"

#include "stack_trace.h"

#ifdef  _DEBUG
void StackTraceUtil::static_constructor::initLogger()
{
  AllocConsole();
  DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_CLOSE, MF_BYCOMMAND);
  //FILE* newStdout;
  //freopen_s(&newStdout, "CONOUT$", "w", stdout);
  freopen("CONOUT$", "w", stdout);
}
StackTraceUtil::static_constructor StackTraceUtil::st_constr;
std::string StackTraceUtil::shift;

void StackTraceUtil::showDebug(const char* m)
{
	//std::ofstream log("log___.txt", std::ios_base::app);
	//if(log)
	//	log << shift << "Debug message: " << m << std::endl;
	std::cout << shift << "Debug message: " << m << std::endl;
}

void StackTraceUtil::showDebug(int m)
{
	//std::ofstream log("log___.txt", std::ios_base::app);
	//if(log)
	//	log << shift << "Debug message: " << m << std::endl;
	std::cout << shift << "Debug message: " << m << std::endl;
}

#endif
