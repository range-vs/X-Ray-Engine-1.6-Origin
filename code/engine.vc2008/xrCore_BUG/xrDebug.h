//#ifndef xrDebugH
//#define xrDebugH
#pragma once

//typedef	void		crashhandler		(void);
typedef	void		on_dialog			(bool before);

#include "stack_wolker/StackWalker.h"

class StackWalkerToString : public StackWalker
{
	std::string buffer;
protected:
	virtual void OnOutput(LPCSTR szText);
public:
	const std::string& getStackTrace()const; 
};

class XRCORE_API	xrDebug
{
private:
	StackWalkerToString stackWolker;
	//crashhandler*	handler	;
	on_dialog*		m_on_dialog;

public:
	void			_initialize			(const bool &dedicated);
	void			_destroy			();
	
public:
	//crashhandler*	get_crashhandler	()							{ return handler;	};
	//void			set_crashhandler	(crashhandler* _handler)	{ handler=_handler;	};

	on_dialog*		get_on_dialog		()							{ return m_on_dialog;	}
	void			set_on_dialog		(on_dialog* on_dialog)		{ m_on_dialog = on_dialog;	}

	LPCSTR			error2string		(long  code	);

	// range fix
	std::string			gather_info			(const char *expression, const char *description, const char *argument0, const char *argument1, const char *file, int line, const char *function);

	void			fail				(const char *e1, const char *file, int line, const char *function, bool &ignore_always);
	void			fail				(const char *e1, const std::string &e2, const char *file, int line, const char *function, bool &ignore_always);
	void			fail				(const char *e1, const char *e2, const char *file, int line, const char *function, bool &ignore_always);
	void			fail				(const char *e1, const char *e2, const char *e3, const char *file, int line, const char *function, bool &ignore_always);
	void			fail				(const char *e1, const char *e2, const char *e3, const char *e4, const char *file, int line, const char *function, bool &ignore_always);
	void			error				(long  code, const char* e1, const char *file, int line, const char *function, bool &ignore_always);
	void			error				(long  code, const char* e1, const char* e2, const char *file, int line, const char *function, bool &ignore_always);
	void _cdecl		fatal				(const char *file, int line, const char *function, const char* F,...);
	void _cdecl		stop(const char* file, int line, const char* function, const char* desc, const char* stack_trace = nullptr);

	void			backend				(const char* reason, const char* expression, const char *argument0, const char *argument1, const char* file, int line, const char *function, bool &ignore_always, bool isMsgBoxOk = false);
	void			do_exit				(const std::string &message);
	std::string stackTrace(HANDLE hThread = GetCurrentThread(), const CONTEXT* context = nullptr);
	void writeStackTraceFromFile(const std::string& header);
	static std::string getLastErrorWindows();
};

// warning
// this function can be used for debug purposes only
IC	std::string __cdecl	make_string		(LPCSTR format,...)
{
	va_list		args;
	va_start	(args,format);

	char		temp[4096];
	vsprintf	(temp,format,args);

	return		std::string(temp);
}

extern XRCORE_API xrDebug Debug;

//// --------------- OPEN XRAY -------------- //
//XRCORE_API void LogStackTrace(const char* header);
//// ---------------------------------------- //

#include "xrDebug_macros.h"

//#endif // xrDebugH