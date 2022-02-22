#include "stdafx.h"
#pragma hdrstop

#include "xrdebug.h"
#include "os_clipboard.h"

#include <sal.h>

#ifdef _EDITOR
#include "../dxerr/dxerr.h"
#pragma comment(lib,"dxerr_b")
#else
#include "dxerr.h"
#pragma comment(lib,"dxerr.lib")
#endif

#pragma warning(push)
#pragma warning(disable:4995)
#include <malloc.h>
#include <direct.h>
#pragma warning(pop)

//extern bool shared_str_initialized;

#ifdef __BORLANDC__
#	include "d3d9.h"
#	include "d3dx9.h"
#	include "D3DX_Wrapper.h"
#	pragma comment(lib,"EToolsB")
#	define DEBUG_INVOKE	DebugBreak()
static BOOL			bException = TRUE;
#else
#	define DEBUG_INVOKE	__debugbreak();
static BOOL			bException = FALSE;
#endif

#include <exception>

#include <dbghelp.h>						// MiniDump flags

#ifndef _EDITOR
#include <new.h>							// for _set_new_mode
#endif

//#include <signal.h>							// for signals

#ifdef DEBUG
#	define USE_OWN_ERROR_MESSAGE_WINDOW
#else // DEBUG
#	define USE_OWN_MINI_DUMP
#endif // DEBUG

XRCORE_API	xrDebug		Debug;

static bool	error_after_dialog = false;

void StackWalkerToString::OnOutput(LPCSTR szText)
{
	buffer += szText;
}

std::string StackWalkerToString::getStackTrace()
{
	std::string copy(buffer);
	buffer = "";
	return copy;
}

std::string xrDebug::gather_info(const char* expression, const char* description, const char* argument0, const char* argument1, const char* file, int line, const char* function)
{
	std::string buffer;
	std::string endline = "\n";
	std::string prefix = "[error]";
	bool extended_description = (description && !argument0 && strchr(description, '\n'));

	buffer += endline + "FATAL ERROR" + endline + endline;
	buffer += prefix + "Expression    : " + expression + endline;
	buffer += prefix + "Function      : " + function + endline;
	buffer += prefix + "File          : " + file + endline;
	buffer += prefix + "Line          : " + universal_string::toString(line) + endline;
	buffer += prefix + "Description   : " + description + endline;
	if (argument0)
	{
		if (argument1)
		{
			buffer += prefix + "Argument 0    : " + argument0 + endline;
			buffer += prefix + "Argument 1    : " + argument1 + endline;
		}
		else
			buffer += prefix + "Arguments    : " + argument0 + endline;
	}

	buffer += endline;
	Msg("%s", buffer.c_str());
	FlushLog();
	endline = "\r\n";

#ifdef USE_MEMORY_MONITOR
	memory_monitor::flush_each_time(true);
	memory_monitor::flush_each_time(false);
#endif // USE_MEMORY_MONITOR

	return buffer;
}

void xrDebug::do_exit(const std::string& message)
{
	FlushLog();
	MessageBox(NULL, message.c_str(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	TerminateProcess(GetCurrentProcess(), 1);
}

void xrDebug::backend(const char* expression, const char* description, const char* argument0, const char* argument1, const char* file, int line, const char* function, bool& ignore_always, bool isMsgBoxOk)
{
	static xrCriticalSection CS
#ifdef PROFILE_CRITICAL_SECTIONS
	(MUTEX_PROFILE_ID(xrDebug::backend))
#endif // PROFILE_CRITICAL_SECTIONS
		;

	CS.Enter();

	error_after_dialog = true;

	std::string assertion_info;
	std::string endline = "\r\n";

	assertion_info = gather_info(expression, description, argument0, argument1, file, line, function);


	if (!isMsgBoxOk)
	{
#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
		assertion_info += endline + "Press CANCEL to abort execution" + endline;
		assertion_info += "Press TRY AGAIN to continue execution" + endline;
		assertion_info += "Press CONTINUE to continue execution and ignore all the errors of this type" + endline + endline;
#endif // USE_OWN_ERROR_MESSAGE_WINDOW
	}

	//if (handler)
	//	handler();

	if (get_on_dialog())
		get_on_dialog()	(true);
	FlushLog();

	os_clipboard::copy_to_clipboard(assertion_info.c_str());
	int	result(0);
	if (isMsgBoxOk)
	{
		MessageBox(NULL, assertion_info.c_str(), "Fatal Error", MB_OK);
		return;
	}
	result = MessageBox(NULL, assertion_info.c_str(), "Fatal Error", MB_CANCELTRYCONTINUE | MB_ICONERROR | MB_SYSTEMMODAL);
	writeStackTraceFromFile("Stack trace:");

	switch (result)
	{
	case IDCANCEL:
	{
		DEBUG_INVOKE;
		break;
	}
	case IDTRYAGAIN:
	{
		error_after_dialog = false;
		break;
	}
	case IDCONTINUE:
	{
		error_after_dialog = false;
		ignore_always = true;
		break;
	}
	default: NODEFAULT;
	}

	if (get_on_dialog())
		get_on_dialog()	(false);

	CS.Leave();
}

LPCSTR xrDebug::error2string(long code)
{
	LPCSTR result = NULL;
	static string1024 desc_storage;

#ifdef _M_AMD64
#else
	result = DXGetErrorDescription(code);
#endif
	if (NULL == result)
	{
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, code, 0, desc_storage, sizeof(desc_storage) - 1, 0);
		result = desc_storage;
	}
	return result;
}

void xrDebug::error(long hr, const char* expr, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(error2string(hr), expr, 0, 0, file, line, function, ignore_always);
}

void xrDebug::error(long hr, const char* expr, const char* e2, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(error2string(hr), expr, e2, 0, file, line, function, ignore_always);
}

void xrDebug::fail(const char* e1, const char* file, int line, const char* function, bool& ignore_always)
{
	backend("assertion failed", e1, 0, 0, file, line, function, ignore_always);
}

void xrDebug::fail(const char* e1, const std::string& e2, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(e1, e2.c_str(), 0, 0, file, line, function, ignore_always);
}

void xrDebug::fail(const char* e1, const char* e2, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(e1, e2, 0, 0, file, line, function, ignore_always);
}

void xrDebug::fail(const char* e1, const char* e2, const char* e3, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(e1, e2, e3, 0, file, line, function, ignore_always);
}

void xrDebug::fail(const char* e1, const char* e2, const char* e3, const char* e4, const char* file, int line, const char* function, bool& ignore_always)
{
	backend(e1, e2, e3, e4, file, line, function, ignore_always);
}

void _cdecl xrDebug::stop(const char* file, int line, const char* function, const char* desc, const char* stack_trace)
{
	if (stack_trace != NULL)
	{
		Msg("%s%s", "Stack trace:\n", stack_trace);
		FlushLog();
	}
	bool ignore_always = true;
	backend("fatal error", "<no expression>", desc, 0, file, line, function, ignore_always, true);
}

void __cdecl xrDebug::fatal(const char* file, int line, const char* function, const char* F, ...)
{
	string4096	buffer;

	va_list		p;
	va_start(p, F);
	vsprintf(buffer, F, p);
	va_end(p);

	bool		ignore_always = true;

	backend("fatal error", "<no expression>", buffer, 0, file, line, function, ignore_always, true);
}

typedef void (*full_memory_stats_callback_type) ();
XRCORE_API full_memory_stats_callback_type g_full_memory_stats_callback = 0;

int out_of_memory_handler(size_t size)
{
	if (g_full_memory_stats_callback)
		g_full_memory_stats_callback();
	else
	{
		Memory.mem_compact();
#ifndef _EDITOR
		u32					crt_heap = Memory.mem_usage(); // mem_usage_impl((HANDLE)_get_heap_handle(), 0, 0);
#else // _EDITOR
		u32					crt_heap = 0;
#endif // _EDITOR
		u32					process_heap = Memory.mem_usage(); //mem_usage_impl(GetProcessHeap(), 0, 0);
		int					eco_strings = (int)g_pStringContainer->stat_economy();
		int					eco_smem = (int)g_pSharedMemoryContainer->stat_economy();
		Msg("* [x-ray]: crt heap[%d K], process heap[%d K]", crt_heap / 1024, process_heap / 1024);
		Msg("* [x-ray]: economy: strings[%d K], smem[%d K]", eco_strings / 1024, eco_smem);
	}

	std::string desc = "Out of memory. Memory request: %d KB" + universal_string::toString(size / 1024);
	Debug.fatal(DEBUG_INFO, desc.c_str());
	return					1;
}

#ifdef M_BORLAND
static void __cdecl def_new_handler()
{
	FATAL("Out of memory.");
}

void	xrDebug::_initialize(const bool& dedicated)
{
	//handler = 0;
	m_on_dialog = 0;
	std::set_new_handler(def_new_handler);	// exception-handler for 'out of memory' condition
}
#else

void debug_on_thread_spawn()
{
	_set_new_handler(&out_of_memory_handler);
}

void	xrDebug::_initialize(const bool& dedicated)
{
	debug_on_thread_spawn();
}
#endif

void xrDebug::_destroy()
{
}

std::string xrDebug::stackTrace(HANDLE hThread, const CONTEXT* context)
{
	stackWolker.ShowCallstack(hThread, context);
	return stackWolker.getStackTrace();
}

void xrDebug::writeStackTraceFromFile(const std::string& header)
{
	std::string _stackTrace(stackTrace());
	Msg("%s", header.c_str());
	Msg("%s", _stackTrace.c_str());
	FlushLog();
}

std::string xrDebug::getLastErrorWindows()
{
	DWORD error_code = GetLastError();
	LPVOID message;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		error_code,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&message,
		0,
		NULL
	);
	std::string msg = "Unknown error. See stack trace.";
	if (error_code != 0)
		msg = "[error][" + universal_string::toString(error_code) + "]    : " + (LPSTR)message + " See stack trace.";
	return msg;
}

void LogStackTrace(const char* header)
{
	Debug.writeStackTraceFromFile(header);
}