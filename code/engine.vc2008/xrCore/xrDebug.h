//#ifndef xrDebugH
//#define xrDebugH
//#pragma once
//
//#include <stack_wolker\StackWalker.h>
//
////typedef	void		crashhandler		(void);
//typedef	void		on_dialog			(bool before);
//
//class XRCORE_API	xrDebug
//{
//private:
//	//crashhandler*	handler	;
//	on_dialog*		m_on_dialog;
//
//public:
//	void			_initialize			(const bool &dedicated);
//	void			_destroy			();
//	
//public:
//	//crashhandler*	get_crashhandler	()							{ return handler;	};
//	//void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};
//
//	on_dialog*		get_on_dialog		()							{ return m_on_dialog;	}
//	void			set_on_dialog		(on_dialog* on_dialog)		{ m_on_dialog = on_dialog;	}
//
//	LPCSTR			error2string		(long  code	);
//
//	void			gather_info			(const char *expression, const char *description, const char *argument0, const char *argument1, const char *file, int line, const char *function, LPSTR assertion_info, unsigned int assertion_info_size);
//	template <int count>
//	inline void		gather_info			(const char *expression, const char *description, const char *argument0, const char *argument1, const char *file, int line, const char *function, char (&assertion_info)[count])
//	{
//		gather_info	( expression, description, argument0, argument1, file, line, function, assertion_info, count);
//	}
//
//	void			fail				(const char *e1, const char *file, int line, const char *function, bool &ignore_always);
//	void			fail				(const char *e1, const std::string &e2, const char *file, int line, const char *function, bool &ignore_always);
//	void			fail				(const char *e1, const char *e2, const char *file, int line, const char *function, bool &ignore_always);
//	void			fail				(const char *e1, const char *e2, const char *e3, const char *file, int line, const char *function, bool &ignore_always);
//	void			fail				(const char *e1, const char *e2, const char *e3, const char *e4, const char *file, int line, const char *function, bool &ignore_always);
//	void			error				(long  code, const char* e1, const char *file, int line, const char *function, bool &ignore_always);
//	void			error				(long  code, const char* e1, const char* e2, const char *file, int line, const char *function, bool &ignore_always);
//	void _cdecl		fatal				(const char *file, int line, const char *function, const char* F,...);
//	void			backend				(const char* reason, const char* expression, const char *argument0, const char *argument1, const char* file, int line, const char *function, bool &ignore_always);
//	void			do_exit				(const std::string &message);
//};
//
//// warning
//// this function can be used for debug purposes only
//IC	std::string __cdecl	make_string		(LPCSTR format,...)
//{
//	va_list		args;
//	va_start	(args,format);
//
//	char		temp[4096];
//	vsprintf	(temp,format,args);
//
//	return		std::string(temp);
//}
//
//extern XRCORE_API	xrDebug		Debug;
//
//// --------------- OPEN XRAY -------------- //
///*XRCORE_API bool GetNextStackFrameString(LPSTACKFRAME stackFrame, PCONTEXT threadCtx, xr_string& frameStr);
//XRCORE_API bool InitializeSymbolEngine();
//XRCORE_API void DeinitializeSymbolEngine(void);
//XRCORE_API SStringVec BuildStackTrace(PCONTEXT threadCtx, u16 maxFramesCount);
//XRCORE_API SStringVec BuildStackTrace(u16 maxFramesCount = 512);*/
//XRCORE_API void LogStackTrace(const char* header);
//// ---------------------------------------- //
//
////XRCORE_API void LogStackTrace	(LPCSTR header);
//
//#include "xrDebug_macros.h"
//
//#endif // xrDebugH

//#ifndef xrDebugH
//#define xrDebugH
#pragma once

#include <string>

//typedef	void		crashhandler		(void);
typedef	void		on_dialog(bool before);

#include <stackwalker/StackWalker.h>

class StackWalkerToString : public StackWalker
{
	std::string buffer;
protected:
	virtual void OnOutput(LPCSTR szText);
public:
	std::string getStackTrace();
};

class XRCORE_API	xrDebug
{
private:
	StackWalkerToString stackWolker;
	//crashhandler*	handler	;
	on_dialog* m_on_dialog;

public:
	void			_initialize(const bool& dedicated);
	void			_destroy();

public:
	//crashhandler*	get_crashhandler	()							{ return handler;	};
	//void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};

	on_dialog* get_on_dialog() { return m_on_dialog; }
	void			set_on_dialog(on_dialog* on_dialog) { m_on_dialog = on_dialog; }

	LPCSTR			error2string(long  code);

	// range fix
	std::string			gather_info(const char* expression, const char* description, const char* argument0, const char* argument1, const char* file, int line, const char* function);

	void			fail(const char* e1, const char* file, int line, const char* function, bool& ignore_always);
	void			fail(const char* e1, const std::string& e2, const char* file, int line, const char* function, bool& ignore_always);
	void			fail(const char* e1, const char* e2, const char* file, int line, const char* function, bool& ignore_always);
	void			fail(const char* e1, const char* e2, const char* e3, const char* file, int line, const char* function, bool& ignore_always);
	void			fail(const char* e1, const char* e2, const char* e3, const char* e4, const char* file, int line, const char* function, bool& ignore_always);
	void			error(long  code, const char* e1, const char* file, int line, const char* function, bool& ignore_always);
	void			error(long  code, const char* e1, const char* e2, const char* file, int line, const char* function, bool& ignore_always);
	void _cdecl		fatal(const char* file, int line, const char* function, const char* F, ...);
	void _cdecl		stop(const char* file, int line, const char* function, const char* desc, const char* stack_trace = NULL);

	void			backend(const char* reason, const char* expression, const char* argument0, const char* argument1, const char* file, int line, const char* function, bool& ignore_always, bool isMsgBoxOk = false);
	void			do_exit(const std::string& message);
	std::string stackTrace(HANDLE hThread = GetCurrentThread(), const CONTEXT* context = NULL);
	void writeStackTraceFromFile(const std::string& header);
	static std::string getLastErrorWindows();
};

// warning
// this function can be used for debug purposes only
inline	std::string __cdecl	make_string(LPCSTR format, ...)
{
	va_list		args;
	va_start(args, format);

	char		temp[4096];
	vsprintf(temp, format, args);

	return		std::string(temp);
}

extern XRCORE_API xrDebug Debug;

XRCORE_API void LogStackTrace(const char* header);

#include "xrDebug_macros.h"

//#endif // xrDebugH