#ifndef STACK_TRACE_H
#define STACK_TRACE_H

#pragma hdrstop
#pragma once

#include <string>
#include <windows.h>
#include <fstream>
#include <iostream>

#ifdef  _DEBUG

class StackTraceUtil
{
	static std::string shift;
	std::string func;
	std::string file;

	struct static_constructor
	{
		static void initLogger();
		static_constructor()
		{
			initLogger();
		}
	};

	static static_constructor st_constr;

public:
   StackTraceUtil(const char* file, const char* func)
   {
	  this->func = func;
	  this->file = file;
	  shift += "   ";
	  //std::ofstream log("log___.txt", std::ios_base::app);
	  //if(log)
	  //	log << shift << "Input function: " << file << " -> " << func << std::endl;
	  std::cout << shift << "Input function: " << file << " -> " << func << std::endl;
   }
   ~StackTraceUtil()
   {
	  //std::ofstream log("log___.txt", std::ios_base::app);
	  //if(log)
	  //	log << shift <<"Output function: " << file << " -> " << func << std::endl;
	  //shift.resize(shift.length() - 3);
	  std::cout << shift <<"Output function: " << file << " -> " << func << std::endl;
	  shift.resize(shift.length() - 3);
   }
   /*template <class T>
   static void showDebug(T m)
   {
	 std::cout << shift << "Debug message: " << m << std::endl;
   } */
   static void showDebug(const char* m);
   static void showDebug(int m);
};

//template void StackTraceUtil::showDebug<int>(int);
//template void StackTraceUtil::showDebug<const char*>(const char*);

#define STACK_TRACE StackTraceUtil st(__FILE__, __FUNCTION__);
#define DEBUG_MESSAGE(m) StackTraceUtil::showDebug(m);

#else
#define STACK_TRACE
#define DEBUG_MESSAGE(m)
#endif

#endif