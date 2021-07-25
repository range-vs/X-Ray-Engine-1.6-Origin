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
	buffer = szText;
}

const std::string& StackWalkerToString::getStackTrace() const
{
	return buffer;
}

//----------------- OPEN XRAY ------------------//
// TODO: перенести в отдельный файл все про stack trace
//static bool symEngineInitialized = false;
//
//#   if defined(_WIN64)
//#       define MACHINE_TYPE IMAGE_FILE_MACHINE_AMD64
//#   else
//#       define MACHINE_TYPE IMAGE_FILE_MACHINE_I386
//#   endif
//
//bool GetNextStackFrameString(LPSTACKFRAME stackFrame, PCONTEXT threadCtx, xr_string& frameStr)
//{
//	BOOL result = StackWalk(MACHINE_TYPE, GetCurrentProcess(), GetCurrentThread(), stackFrame, threadCtx, NULL,
//		SymFunctionTableAccess, SymGetModuleBase, NULL);
//
//	if (result == FALSE || stackFrame->AddrPC.Offset == 0)
//	{
//		return false;
//	}
//
//	frameStr.clear();
//	string512 formatBuff;
//
//	///
//	/// Module name
//	///
//	HINSTANCE hModule = (HINSTANCE)SymGetModuleBase(GetCurrentProcess(), stackFrame->AddrPC.Offset);
//	if (hModule && GetModuleFileName(hModule, formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0])))
//	{
//		frameStr.append(formatBuff);
//	}
//
//	///
//	/// Address
//	///
//	xr_sprintf(formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0]), " at %p", stackFrame->AddrPC.Offset);
//	frameStr.append(formatBuff);
//
//	///
//	/// Function info
//	///
//	BYTE arrSymBuffer[512];
//	ZeroMemory(arrSymBuffer, sizeof(arrSymBuffer));
//	PIMAGEHLP_SYMBOL functionInfo = reinterpret_cast<PIMAGEHLP_SYMBOL>(arrSymBuffer);
//	functionInfo->SizeOfStruct = sizeof(*functionInfo);
//	functionInfo->MaxNameLength = sizeof(arrSymBuffer) - sizeof(*functionInfo) + 1;
//	DWORD_PTR dwFunctionOffset;
//
//	result = SymGetSymFromAddr(GetCurrentProcess(), stackFrame->AddrPC.Offset, &dwFunctionOffset, functionInfo);
//
//	if (result)
//	{
//		if (dwFunctionOffset)
//		{
//			xr_sprintf(formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0]), " %s() + %Iu byte(s)", functionInfo->Name, dwFunctionOffset);
//		}
//		else
//		{
//			xr_sprintf(formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0]), " %s()", functionInfo->Name);
//		}
//		frameStr.append(formatBuff);
//	}
//
//	///
//	/// Source info
//	///
//	DWORD dwLineOffset;
//	IMAGEHLP_LINE sourceInfo = {};
//	sourceInfo.SizeOfStruct = sizeof(sourceInfo);
//
//	result = SymGetLineFromAddr(GetCurrentProcess(), stackFrame->AddrPC.Offset, &dwLineOffset, &sourceInfo);
//
//	if (result)
//	{
//		if (dwLineOffset)
//		{
//			xr_sprintf(formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0]), " in %s line %u + %u byte(s)", sourceInfo.FileName,
//				sourceInfo.LineNumber, dwLineOffset);
//		}
//		else
//		{
//			xr_sprintf(formatBuff, sizeof(formatBuff) / sizeof(formatBuff[0]), " in %s line %u", sourceInfo.FileName, sourceInfo.LineNumber);
//		}
//		frameStr.append(formatBuff);
//	}
//
//	return true;
//}
//
bool InitializeSymbolEngine()
{
	bool symEngineInitialized = false;
	DWORD dwOptions = SymGetOptions();
	SymSetOptions(dwOptions | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);
	if (SymInitialize(GetCurrentProcess(), NULL, TRUE))
		symEngineInitialized = true;
	return symEngineInitialized;
}

void DeinitializeSymbolEngine(void)
{
	SymCleanup(GetCurrentProcess());
}

//
//SStringVec BuildStackTrace(PCONTEXT threadCtx, u16 maxFramesCount)
//{
//	// ScopeLock Lock(&dbgHelpLock); --> TODO, нужно ли???
//
//	SStringVec traceResult;
//	STACKFRAME stackFrame = {};
//	xr_string frameStr;
//
//	if (!InitializeSymbolEngine())
//	{
//		Msg("[BuildStackTrace]InitializeSymbolEngine failed with error: %d", GetLastError());
//		return traceResult;
//	}
//
//	traceResult.reserve(maxFramesCount);
//
//#if defined _WIN64
//	stackFrame.AddrPC.Mode = AddrModeFlat;
//	stackFrame.AddrPC.Offset = threadCtx->Rip;
//	stackFrame.AddrStack.Mode = AddrModeFlat;
//	stackFrame.AddrStack.Offset = threadCtx->Rsp;
//	stackFrame.AddrFrame.Mode = AddrModeFlat;
//	stackFrame.AddrFrame.Offset = threadCtx->Rbp;
//#else
//	stackFrame.AddrPC.Mode = AddrModeFlat;
//	stackFrame.AddrPC.Offset = threadCtx->Eip;
//	stackFrame.AddrStack.Mode = AddrModeFlat;
//	stackFrame.AddrStack.Offset = threadCtx->Esp;
//	stackFrame.AddrFrame.Mode = AddrModeFlat;
//	stackFrame.AddrFrame.Offset = threadCtx->Ebp;
//#endif
//
//	while (GetNextStackFrameString(&stackFrame, threadCtx, frameStr) && traceResult.size() <= maxFramesCount)
//	{
//		traceResult.push_back(frameStr);
//	}
//
//	DeinitializeSymbolEngine();
//
//	return traceResult;
//}
//
//SStringVec BuildStackTrace(u16 maxFramesCount = 512)
//{
//	CONTEXT currentThreadCtx = {};
//
//	RtlCaptureContext(&currentThreadCtx); /// GetThreadContext can't be used on the current thread
//	currentThreadCtx.ContextFlags = CONTEXT_FULL;
//
//	return BuildStackTrace(&currentThreadCtx, maxFramesCount);
//}

//void LogStackTrace(const char* header)
//{
//	//SStringVec stackTrace = BuildStackTrace();
//	//Msg("%s", header);
//	//for (int i = 0; i < stackTrace.size(); ++i)
//	//{
//	//	Msg("%s", stackTrace[i].c_str());
//	//}
//	// TODO: add new library stacktrace (no openxray)
//	FlushLog();
//}

//----------------- OPEN XRAY ------------------//

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

	// range fix
	//	if (!IsDebuggerPresent() && !strstr(GetCommandLine(),"-no_call_stack_assert")) 
	//	{
	//			Msg("stack trace:\n");
	//#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
	//		buffer += "stack trace:" + endline + endline;
	//#endif // USE_OWN_ERROR_MESSAGE_WINDOW
	//
	//		SStringVec stackTrace = BuildStackTrace();
	//		for (int i = 2; i < stackTrace.size(); ++i)
	//		{
	//			Msg("%s", stackTrace[i].c_str());
	//#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
	//			buffer += stackTrace[i].c_str() +  endline;
	//#endif // USE_OWN_ERROR_MESSAGE_WINDOW
	//		}
	//
	//		FlushLog();
	//
	//		os_clipboard::copy_to_clipboard(buffer.c_str());
	//	}
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

	//#ifdef XRCORE_STATIC
	//	MessageBox(NULL, assertion_info, "X-Ray error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	//#else
		//FlushLog();

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

	//#endif

	if (get_on_dialog())
		get_on_dialog()	(false);

	CS.Leave();
}

LPCSTR xrDebug::error2string(long code)
{
	LPCSTR result = nullptr;
	static string1024 desc_storage;

#ifdef _M_AMD64
#else
	result = DXGetErrorDescription(code);
#endif
	if (nullptr == result)
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
	if (stack_trace != nullptr)
	{
		Msg("%s", stack_trace);
		FlushLog();
	}
	bool		ignore_always = true;
	backend("fatal error", "<no expression>", desc, 0, file, line, function, ignore_always, true);
}

void __cdecl xrDebug::fatal(const char* file, int line, const char* function, const char* F, ...)
{
	string8192	buffer;

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
		u32					crt_heap = mem_usage_impl((HANDLE)_get_heap_handle(), 0, 0);
#else // _EDITOR
		u32					crt_heap = 0;
#endif // _EDITOR
		u32					process_heap = mem_usage_impl(GetProcessHeap(), 0, 0);
		int					eco_strings = (int)g_pStringContainer->stat_economy();
		int					eco_smem = (int)g_pSharedMemoryContainer->stat_economy();
		Msg("* [x-ray]: crt heap[%d K], process heap[%d K]", crt_heap / 1024, process_heap / 1024);
		Msg("* [x-ray]: economy: strings[%d K], smem[%d K]", eco_strings / 1024, eco_smem);
	}

	std::string desc = "Out of memory. Memory request: %d KB" + universal_string::toString(size / 1024);
	Debug.fatal(DEBUG_INFO, desc.c_str());
	return					1;
}

//extern LPCSTR log_name();

//XRCORE_API string_path g_bug_report_file;

//void CALLBACK PreErrorHandler	(INT_PTR)
//{
//
//}

//#if 1
//extern void BuildStackTrace(struct _EXCEPTION_POINTERS *pExceptionInfo);
//typedef LONG WINAPI UnhandledExceptionFilterType(struct _EXCEPTION_POINTERS *pExceptionInfo);
//typedef LONG ( __stdcall *PFNCHFILTFN ) ( EXCEPTION_POINTERS * pExPtrs ) ;
//extern "C" BOOL __stdcall SetCrashHandlerFilter ( PFNCHFILTFN pFn );
//
//static UnhandledExceptionFilterType	*previous_filter = 0;
//
//#ifdef USE_OWN_MINI_DUMP
//typedef BOOL (WINAPI *MINIDUMPWRITEDUMP)(HANDLE hProcess, DWORD dwPid, HANDLE hFile, MINIDUMP_TYPE DumpType,
//										 CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
//										 CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
//										 CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam
//										 );
//
//void save_mini_dump			(_EXCEPTION_POINTERS *pExceptionInfo)
//{
//	// firstly see if dbghelp.dll is around and has the function we need
//	// look next to the EXE first, as the one in System32 might be old 
//	// (e.g. Windows 2000)
//	HMODULE hDll	= NULL;
//	string_path		szDbgHelpPath;
//
//	if (GetModuleFileName( NULL, szDbgHelpPath, _MAX_PATH ))
//	{
//		char *pSlash = strchr( szDbgHelpPath, '\\' );
//		if (pSlash)
//		{
//			xr_strcpy	(pSlash+1, sizeof(szDbgHelpPath)-(pSlash - szDbgHelpPath), "DBGHELP.DLL" );
//			hDll = ::LoadLibrary( szDbgHelpPath );
//		}
//	}
//
//	if (hDll==NULL)
//	{
//		// load any version we can
//		hDll = ::LoadLibrary( "DBGHELP.DLL" );
//	}
//
//	LPCTSTR szResult = NULL;
//
//	if (hDll)
//	{
//		MINIDUMPWRITEDUMP pDump = (MINIDUMPWRITEDUMP)::GetProcAddress( hDll, "MiniDumpWriteDump" );
//		if (pDump)
//		{
//			string_path	szDumpPath;
//			string_path	szScratch;
//			string64	t_stemp;
//
//			timestamp	(t_stemp);
//			xr_strcpy		( szDumpPath, Core.ApplicationName);
//			xr_strcat		( szDumpPath, "_"					);
//			xr_strcat		( szDumpPath, Core.UserName			);
//			xr_strcat		( szDumpPath, "_"					);
//			xr_strcat		( szDumpPath, t_stemp				);
//			xr_strcat		( szDumpPath, ".mdmp"				);
//
//			__try {
//				if (FS.path_exist("$logs$"))
//					FS.update_path	(szDumpPath,"$logs$",szDumpPath);
//			}
//            __except( EXCEPTION_EXECUTE_HANDLER ) {
//				string_path	temp;
//				xr_strcpy		(temp,szDumpPath);
//				xr_strcpy		(szDumpPath,"logs/");
//				xr_strcat		(szDumpPath,temp);
//            }
//
//			// create the file
//			HANDLE hFile = ::CreateFile( szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
//			if (INVALID_HANDLE_VALUE==hFile)	
//			{
//				// try to place into current directory
//				MoveMemory	(szDumpPath,szDumpPath+5,strlen(szDumpPath));
//				hFile		= ::CreateFile( szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
//			}
//			if (hFile!=INVALID_HANDLE_VALUE)
//			{
//				_MINIDUMP_EXCEPTION_INFORMATION ExInfo;
//
//				ExInfo.ThreadId				= ::GetCurrentThreadId();
//				ExInfo.ExceptionPointers	= pExceptionInfo;
//				ExInfo.ClientPointers		= NULL;
//
//				// write the dump
//				MINIDUMP_TYPE	dump_flags	= MINIDUMP_TYPE(MiniDumpNormal | MiniDumpFilterMemory | MiniDumpScanMemory );
//
//				BOOL bOK = pDump( GetCurrentProcess(), GetCurrentProcessId(), hFile, dump_flags, &ExInfo, NULL, NULL );
//				if (bOK)
//				{
//					xr_sprintf( szScratch, 2*_MAX_PATH, "Saved dump file to '%s'", szDumpPath );
//					szResult = szScratch;
////					retval = EXCEPTION_EXECUTE_HANDLER;
//				}
//				else
//				{
//					xr_sprintf( szScratch, 2*_MAX_PATH, "Failed to save dump file to '%s' (error %d)", szDumpPath, GetLastError() );
//					szResult = szScratch;
//				}
//				::CloseHandle(hFile);
//			}
//			else
//			{
//				xr_sprintf( szScratch, 2*_MAX_PATH, "Failed to create dump file '%s' (error %d)", szDumpPath, GetLastError() );
//				szResult = szScratch;
//			}
//		}
//		else
//		{
//			szResult = "DBGHELP.DLL too old";
//		}
//	}
//	else
//	{
//		szResult = "DBGHELP.DLL not found";
//	}
//}
//#endif // USE_OWN_MINI_DUMP
//
//void format_message	(LPSTR buffer, const u32 &buffer_size)
//{
//    LPVOID		message;
//    DWORD		error_code = GetLastError(); 
//
//	if (!error_code) {
//		*buffer	= 0;
//		return;
//	}
//
//    FormatMessage(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
//        FORMAT_MESSAGE_FROM_SYSTEM,
//        NULL,
//        error_code,
//        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//        (LPSTR)&message,
//        0,
//		NULL
//	);
//
//	xr_sprintf	(buffer,buffer_size,"[error][%8d]    : %s",error_code,message);
//    LocalFree	(message);
//}
//
//#ifndef _EDITOR
//    #include <errorrep.h>
//    #pragma comment( lib, "faultrep.lib" )
//#endif
//
//LONG WINAPI UnhandledFilter	(_EXCEPTION_POINTERS *pExceptionInfo)
//{
//	string256				error_message;
//	format_message			(error_message,sizeof(error_message));
//
////	if (!error_after_dialog && !strstr(GetCommandLine(),"-no_call_stack_assert")) {
////		CONTEXT				save = *pExceptionInfo->ContextRecord;
////		SStringVec stackTrace = BuildStackTrace		(pExceptionInfo->ContextRecord, 1024);
////		*pExceptionInfo->ContextRecord = save;
////
////		Msg("stack trace:\n");
////#ifdef DEBUG
////		if (!IsDebuggerPresent())
////			os_clipboard::copy_to_clipboard("stack trace:\r\n\r\n");
////#endif
////
////		string4096			buffer;
////		for (int i = 0; i < stackTrace.size(); ++i)
////		{
////			Msg("%s", stackTrace[i].c_str());
////			xr_sprintf(buffer, sizeof(buffer), "%s\r\n", stackTrace[i].c_str());
////#ifdef DEBUG
////			if (!IsDebuggerPresent())
////				os_clipboard::update_clipboard(buffer);
////#endif // #ifdef DEBUG
////		}
////
////		if (*error_message) 
////		{
////			Msg			("\n%s",error_message);
////
////			xr_strcat			(error_message,sizeof(error_message),"\r\n");
////#ifdef DEBUG
////			if (!IsDebuggerPresent())
////				os_clipboard::update_clipboard(buffer);
////#endif // #ifdef DEBUG
////		}
////	}
//
//	LogStackTrace("Stack trace:");
//	//FlushLog			();
//
//#ifndef USE_OWN_ERROR_MESSAGE_WINDOW
//#	ifdef USE_OWN_MINI_DUMP
//		save_mini_dump		(pExceptionInfo);
//#	endif // USE_OWN_MINI_DUMP
//#else // USE_OWN_ERROR_MESSAGE_WINDOW
//	if (!error_after_dialog) 
//	{
//		if (Debug.get_on_dialog())
//			Debug.get_on_dialog()(true);
//
//		MessageBox(NULL,(std::string("Fatal error occured\n\nPress OK to abort program execution.\nDescription: ") + error_message).c_str(),
//			"Fatal error",MB_OK|MB_ICONERROR|MB_SYSTEMMODAL);
//	}
//#endif // USE_OWN_ERROR_MESSAGE_WINDOW
//
//#ifndef _EDITOR
//	ReportFault				( pExceptionInfo, 0 );
//#endif
//
//	if (!previous_filter)
//	{
//#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
//		if (Debug.get_on_dialog())
//			Debug.get_on_dialog()(false);
//#endif // USE_OWN_ERROR_MESSAGE_WINDOW
//
//		return (EXCEPTION_EXECUTE_HANDLER) ;
//	}
//
//	previous_filter(pExceptionInfo);
//
//#ifdef USE_OWN_ERROR_MESSAGE_WINDOW
//	if (Debug.get_on_dialog())
//		Debug.get_on_dialog()(false);
//#endif // USE_OWN_ERROR_MESSAGE_WINDOW
//
//	return (EXCEPTION_EXECUTE_HANDLER) ;
//}
//#endif

//////////////////////////////////////////////////////////////////////
#ifdef M_BORLAND
static void __cdecl def_new_handler()
{
	FATAL("Out of memory.");
}

void	xrDebug::_initialize(const bool& dedicated)
{
	if (!InitializeSymbolEngine())
	{
		Msg("[BuildStackTrace]InitializeSymbolEngine failed with error: %d", GetLastError());
		std::abort();
	}
	handler = 0;
	m_on_dialog = 0;
	std::set_new_handler(def_new_handler);	// exception-handler for 'out of memory' condition
//		::SetUnhandledExceptionFilter	(UnhandledFilter);	// exception handler to all "unhandled" exceptions
}
#else
//    typedef int		(__cdecl * _PNH)( size_t );
//    _CRTIMP int		__cdecl _set_new_mode( int );
//    //_CRTIMP _PNH	__cdecl _set_new_handler( _PNH );
//
//	void _terminate		()
//	{
//		if (strstr(GetCommandLine(),"-silent_error_mode"))
//			exit				(-1);
//
//		std::string assertion_info;
//		
//		assertion_info = Debug.gather_info(
//		//gather_info				(
//			"<no expression>",
//			"Unexpected application termination",
//			0,
//			0,
//	#ifdef ANONYMOUS_BUILD
//			"",
//			0,
//	#else
//			__FILE__,
//			__LINE__,
//	#endif
//	#ifndef _EDITOR
//			__FUNCTION__
//	#else // _EDITOR
//			""
//	#endif // _EDITOR
//		);
//		
//		std::string endline = "\r\n";
//		assertion_info += "Press OK to abort execution" + endline;
//
//		MessageBox				(
//			NULL,
//			assertion_info.c_str(),
//			"Fatal Error",
//			MB_OK|MB_ICONERROR|MB_SYSTEMMODAL
//		);
//		
//		DEBUG_INVOKE
//	}
//
//	static void handler_base				(LPCSTR reason_string)
//	{
//		bool							ignore_always = false;
//		Debug.backend					(
//			"error handler is invoked!",
//			reason_string,
//			0,
//			0,
//			DEBUG_INFO,
//			ignore_always
//		);
//	}
//
//	static void invalid_parameter_handler	(
//			const wchar_t *expression,
//			const wchar_t *function,
//			const wchar_t *file,
//			unsigned int line,
//			uintptr_t reserved
//		)
//	{
//		bool							ignore_always = false;
//
//		string4096						expression_;
//		string4096						function_;
//		string4096						file_;
//		size_t							converted_chars = 0;
////		errno_t							err = 
//		if (expression)
//			wcstombs_s	(
//				&converted_chars, 
//				expression_,
//				sizeof(expression_),
//				expression,
//				(wcslen(expression) + 1)*2*sizeof(char)
//			);
//		else
//			xr_strcpy					(expression_,"");
//
//		if (function)
//			wcstombs_s	(
//				&converted_chars, 
//				function_,
//				sizeof(function_),
//				function,
//				(wcslen(function) + 1)*2*sizeof(char)
//			);
//		else
//			xr_strcpy					(function_,__FUNCTION__);
//
//		if (file)
//			wcstombs_s	(
//				&converted_chars, 
//				file_,
//				sizeof(file_),
//				file,
//				(wcslen(file) + 1)*2*sizeof(char)
//			);
//		else {
//			line						= __LINE__;
//			xr_strcpy					(file_,__FILE__);
//		}
//
//		Debug.backend					(
//			"error handler is invoked!",
//			expression_,
//			0,
//			0,
//			file_,
//			line,
//			function_,
//			ignore_always
//		);
//	}
//
//	static void pure_call_handler			()
//	{
//		handler_base					("pure virtual function call");
//	}
//
//#ifdef XRAY_USE_EXCEPTIONS
//	static void unexpected_handler			()
//	{
//		handler_base					("unexpected program termination");
//	}
//#endif // XRAY_USE_EXCEPTIONS
//
//	static void abort_handler				(int signal)
//	{
//		handler_base					("application is aborting");
//	}
//
//	static void floating_point_handler		(int signal)
//	{
//		handler_base					("floating point error");
//	}
//
//	static void illegal_instruction_handler	(int signal)
//	{
//		handler_base					("illegal instruction");
//	}
//
//	static void termination_handler			(int signal)
//	{
//		handler_base					("termination with exit code 3");
//	}
//
//	void debug_on_thread_spawn			()
//	{
//
//		_set_abort_behavior				(0,_WRITE_ABORT_MSG | _CALL_REPORTFAULT);
//		signal							(SIGABRT,		abort_handler);
//		signal							(SIGABRT_COMPAT,abort_handler);
//		signal							(SIGFPE,		floating_point_handler);
//		signal							(SIGILL,		illegal_instruction_handler);
//		signal							(SIGINT,		0);
////		signal							(SIGSEGV,		storage_access_handler);
//		signal							(SIGTERM,		termination_handler);
//
//		_set_invalid_parameter_handler	(&invalid_parameter_handler);
//
//		_set_new_mode					(1);
//		_set_new_handler				(&out_of_memory_handler);
////		std::set_new_handler			(&std_out_of_memory_handler);
//
//		_set_purecall_handler			(&pure_call_handler);
//
//#if 0// should be if we use exceptions
//		std::set_unexpected				(_terminate);
//#endif
//	}

void	xrDebug::_initialize(const bool& dedicated)
{
	//static bool is_dedicated		= dedicated;

	//*g_bug_report_file				= 0;

	if (!InitializeSymbolEngine())
	{
		Msg("[BuildStackTrace]InitializeSymbolEngine failed with error: %d", GetLastError());
		std::abort();
	}

	_set_new_handler(&out_of_memory_handler);

	//debug_on_thread_spawn			();

	//previous_filter					= ::SetUnhandledExceptionFilter(UnhandledFilter);	// exception handler to all "unhandled" exceptions

//#if 0
//		struct foo {static void	recurs	(const u32 &count)
//		{
//			if (!count)
//				return;
//
//			_alloca			(4096);
//			recurs			(count - 1);
//		}};
//		foo::recurs			(u32(-1));
//		std::terminate		();
//#endif // 0
}
#endif

void xrDebug::_destroy()
{
	DeinitializeSymbolEngine();
}

std::string xrDebug::stackTrace(HANDLE hThread, const CONTEXT* context)
{
	stackWolker.ShowCallstack(hThread, context);
	return stackWolker.getStackTrace();
}

void xrDebug::writeStackTraceFromFile(const std::string& header)
{
	std::string _stackTrace(stackTrace());
	Msg("%s", header);
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