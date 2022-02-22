//// test_project.cpp : Defines the entry point for the application.
////
//
//#include <vector>
//#include <string>
//#include <filesystem>
//#include <fstream>
//#include <sstream>
//#include <windows.h>
//namespace fs = std::filesystem;
//
//extern "C" {
//#include <lua.h>
//#include <lualib.h>
//#include <lauxlib.h>
//};
//
//#include "luabind/luabind.hpp"
//#include <luabind/class_info.hpp>
//#include "luabind/functor.hpp"
//
//using namespace std;
//using namespace luabind;
//
//typedef char* pstr;
//using pcstr = const char*;
//
////using string512 = char[512];
////using string_path = char[2 * MAX_PATH];
////
////#define SCRIPT_GLOBAL_NAMESPACE "_G"
////
////static const char* file_header_old = "local function script_name() \
////return \"%s\" \
////end \
////local this = {} \
////%s this %s \
////setmetatable(this, {__index = " SCRIPT_GLOBAL_NAMESPACE "}) \
////setfenv(1, this) ";
////
////static const char* file_header = file_header_old;
////
////class ScriptBuffer
////{
////	static std::unique_ptr< ScriptBuffer> instanse;
////
////public:
////	char* scriptBuffer = nullptr;
////	size_t scriptBufferSize = 0;
////
////public:
////	ScriptBuffer() = default;
////	ScriptBuffer(ScriptBuffer&) = delete;
////	ScriptBuffer& operator=(ScriptBuffer&) = delete;
////	ScriptBuffer(ScriptBuffer&&) = delete;
////	const ScriptBuffer& operator=(ScriptBuffer&&) = delete;
////	~ScriptBuffer();
////
////	void resize(size_t total_size);
////
////	static std::unique_ptr< ScriptBuffer>& getInstance();
////};
////
////std::unique_ptr<ScriptBuffer> ScriptBuffer::instanse(nullptr);
////
////ScriptBuffer::~ScriptBuffer()
////{
////	if (scriptBuffer)
////		free(scriptBuffer);
////}
////
////void ScriptBuffer::resize(size_t total_size)
////{
////	if (total_size >= scriptBufferSize)
////	{
////		scriptBufferSize = total_size;
////		scriptBuffer = (char*)realloc(scriptBuffer, scriptBufferSize);
////	}
////}
////
////std::unique_ptr<ScriptBuffer>& ScriptBuffer::getInstance()
////{
////	if (!instanse)
////	{
////		instanse.reset(new ScriptBuffer);
////		instanse->scriptBufferSize = 1024 * 1024;
////		instanse->scriptBuffer = (char*)malloc(instanse->scriptBufferSize);
////	}
////	return instanse;
////}
////
////
////inline char* strconcat(int dest_sz, char* dest, const char* S1, const char* S2)
////{
////	strcpy_s(dest, dest_sz, S1);
////	strcat_s(dest, dest_sz, S2);
////	return  dest;
////}
////
////bool bfCreateNamespaceTable(lua_State* tpLuaVM, LPCSTR caNamespaceName)
////{
////	lua_pushstring(tpLuaVM, "_G");
////	lua_gettable(tpLuaVM, LUA_GLOBALSINDEX);
////	LPSTR			S2 = _strdup(caNamespaceName);
////	LPSTR			S = S2;
////	for (;;) {
////		if (!strlen(S)) {
////			lua_pop(tpLuaVM, 1);
////			//LuaOut(Lua::eLuaMessageTypeError, "the namespace name %s is incorrect!", caNamespaceName);
////			free(S2);
////			return		(false);
////		}
////		LPSTR			S1 = strchr(S, '.');
////		if (S1)
////			*S1 = 0;
////		lua_pushstring(tpLuaVM, S);
////		lua_gettable(tpLuaVM, -2);
////		if (lua_isnil(tpLuaVM, -1)) {
////			lua_pop(tpLuaVM, 1);
////			lua_newtable(tpLuaVM);
////			lua_pushstring(tpLuaVM, S);
////			lua_pushvalue(tpLuaVM, -2);
////			lua_settable(tpLuaVM, -4);
////		}
////		else
////			if (!lua_istable(tpLuaVM, -1)) {
////				free(S2);
////				lua_pop(tpLuaVM, 2);
////				//LuaOut(Lua::eLuaMessageTypeError, "the namespace name %s is already being used by the non-table object!", caNamespaceName);
////				return			(false);
////			}
////		lua_remove(tpLuaVM, -2);
////		if (S1)
////			S = ++S1;
////		else
////			break;
////	}
////	free(S2);
////	return			(true);
////}
////
////void vfCopyGlobals(lua_State* tpLuaVM)
////{
////	lua_newtable(tpLuaVM);
////	lua_pushstring(tpLuaVM, "_G");
////	lua_gettable(tpLuaVM, LUA_GLOBALSINDEX);
////	lua_pushnil(tpLuaVM);
////	while (lua_next(tpLuaVM, -2)) {
////		lua_pushvalue(tpLuaVM, -2);
////		lua_pushvalue(tpLuaVM, -2);
////		lua_settable(tpLuaVM, -6);
////		lua_pop(tpLuaVM, 1);
////	}
////}
////
////bool parse_namespace(pcstr caNamespaceName, pstr b, size_t b_size, pstr c, size_t c_size)
////{
////	*b = 0;
////	*c = 0;
////	std::string r = std::string(caNamespaceName);
////	pstr S = (char*)r.c_str();
////	for (int i = 0;; i++)
////	{
////		if (!strlen(S))
////		{
////			//FATAL("Lua Error : the namespace name %s is incorrect!", caNamespaceName);
////			return false;
////		}
////		pstr S1 = strchr(S, '.');
////		if (S1)
////			*S1 = 0;
////		if (i)
////			strcat_s(b, b_size, "{");
////		strcat_s(b, b_size, S);
////		strcat_s(b, b_size, "=");
////		if (i)
////			strcat_s(c, c_size, "}");
////		if (S1)
////			S = ++S1;
////		else
////			break;
////	}
////	return true;
////}
////
////bool bfLoadBuffer(lua_State* tpLuaVM, LPCSTR caBuffer, size_t tSize, LPCSTR caScriptName, LPCSTR caNameSpaceName)
////{
////	int l_iErrorCode;
////	if (caNameSpaceName && strcmp("_G", caNameSpaceName))
////	{
////		string512 insert, a, b;
////		LPCSTR header = file_header;
////		if (!parse_namespace(caNameSpaceName, a, sizeof(a), b, sizeof(b)))
////			return false;
////		sprintf(insert, header, caNameSpaceName, a, b);
////		const size_t str_len = strlen(insert);
////		const size_t total_size = str_len + tSize;
////		ScriptBuffer::getInstance()->resize(total_size);
////		strcpy_s(ScriptBuffer::getInstance()->scriptBuffer, total_size, insert);
////		CopyMemory(ScriptBuffer::getInstance()->scriptBuffer + str_len, caBuffer, tSize);
////		l_iErrorCode = luaL_loadbuffer(tpLuaVM, ScriptBuffer::getInstance()->scriptBuffer, tSize + str_len, caScriptName);
////	}
////	else
////		l_iErrorCode = luaL_loadbuffer(tpLuaVM, caBuffer, tSize, caScriptName);
////	if (l_iErrorCode) {
////		//#ifdef DEBUG
////		//        if (!bfPrintOutput(tpLuaVM, caScriptName, l_iErrorCode))
////		//            vfPrintError(tpLuaVM, l_iErrorCode);
////		//#endif
////		return false;
////	}
////	return true;
////}
////
////bool bfDoFile(lua_State* tpLuaVM, LPCSTR caScriptName, LPCSTR caNameSpaceName, bool bCall)
////{
////	string_path		l_caLuaFileName;
////	std::ifstream l_tpFileReader(caScriptName);
////	strconcat(sizeof(l_caLuaFileName), l_caLuaFileName, "@", caScriptName);
////	std::stringstream ss;
////	ss << l_tpFileReader.rdbuf();
////	if (!bfLoadBuffer(tpLuaVM, ss.str().c_str(), ss.str().size(), l_caLuaFileName, caNameSpaceName)) {
////		lua_pop(tpLuaVM, 4);
////		return		(false);
////	}
////
////	if (bCall) {
////		lua_call(tpLuaVM, 0, 0);
////	}
////	else
////		lua_insert(tpLuaVM, -4);
////
////	return			(true);
////}
////
////void vfSetNamespace(lua_State* tpLuaVM)
////{
////	lua_pushnil(tpLuaVM);
////	while (lua_next(tpLuaVM, -2)) {
////		lua_pushvalue(tpLuaVM, -2);
////		lua_gettable(tpLuaVM, -5);
////		if (lua_isnil(tpLuaVM, -1)) {
////			lua_pop(tpLuaVM, 1);
////			lua_pushvalue(tpLuaVM, -2);
////			lua_pushvalue(tpLuaVM, -2);
////			lua_pushvalue(tpLuaVM, -2);
////			lua_pushnil(tpLuaVM);
////			lua_settable(tpLuaVM, -7);
////			lua_settable(tpLuaVM, -7);
////		}
////		else {
////			lua_pop(tpLuaVM, 1);
////			lua_pushvalue(tpLuaVM, -2);
////			lua_gettable(tpLuaVM, -4);
////			if (!lua_equal(tpLuaVM, -1, -2)) {
////				lua_pushvalue(tpLuaVM, -3);
////				lua_pushvalue(tpLuaVM, -2);
////				lua_pushvalue(tpLuaVM, -2);
////				lua_pushvalue(tpLuaVM, -5);
////				lua_settable(tpLuaVM, -8);
////				lua_settable(tpLuaVM, -8);
////			}
////			lua_pop(tpLuaVM, 1);
////		}
////		lua_pushvalue(tpLuaVM, -2);
////		lua_pushnil(tpLuaVM);
////		lua_settable(tpLuaVM, -6);
////		lua_pop(tpLuaVM, 1);
////	}
////	lua_pop(tpLuaVM, 3);
////}
////
////bool bfLoadFileIntoNamespace(lua_State* tpLuaVM, LPCSTR caScriptName, LPCSTR caNamespaceName, bool bCall)
////{
////	if (!bfCreateNamespaceTable(tpLuaVM, caNamespaceName))
////		return		(false);
////	vfCopyGlobals(tpLuaVM);
////	if (!bfDoFile(tpLuaVM, caScriptName, caNamespaceName, bCall))
////		return		(false);
////	vfSetNamespace(tpLuaVM);
////	return			(true);
////}
////
////char* strext(const char* S) { return (char*)strrchr(S, '.'); }
////
////class	adopt_compiler
////{
////
////};
//
//static void* lua_alloc(void* ud, void* ptr, size_t osize, size_t nsize)
//{
//    (void)ud;
//    (void)osize;
//    if (!nsize)
//    {
//        free(ptr);
//        return nullptr;
//    }
//    return realloc(ptr, nsize);
//}
//
//static void* __cdecl luabind_allocator(void* context, const void* pointer, size_t const size)
//{
//    if (!size)
//    {
//        void* non_const_pointer = const_cast<LPVOID>(pointer);
//        free(non_const_pointer);
//        return nullptr;
//    }
//    if (!pointer)
//    {
//        return malloc(size);
//    }
//    void* non_const_pointer = const_cast<LPVOID>(pointer);
//    return realloc(non_const_pointer, size);
//}
//
//struct luajit
//{
//    static void open_lib(lua_State* L, pcstr module_name, lua_CFunction function)
//    {
//        lua_pushcfunction(L, function);
//        lua_pushstring(L, module_name);
//        lua_call(L, 1, 0);
//    }
//
//    static void allow_escape_sequences(bool allowed)
//    {
//        lj_allow_escape_sequences(allowed ? 1 : 0);
//    }
//};
//
//int _winMain(_In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ char* lpCmdLine,
//    _In_ int       nCmdShow)
//{
//    AllocConsole();
//    freopen("CONOUT$", "w", stdout);
//
//    // DEBUG LUABIND
//    luabind::allocator = &luabind_allocator;
//    luabind::allocator_context = nullptr;
//    lua_State* LSVM = lua_newstate(lua_alloc, NULL);
//    if (!LSVM)
//    {
//        //Msg("! ERROR : Cannot initialize LUA VM!");
//        return -1;
//    }
//    luabind::open(LSVM);
//    luabind::bind_class_info(LSVM);
//    luajit::open_lib(LSVM, "", luaopen_base);
//    luajit::open_lib(LSVM, LUA_LOADLIBNAME, luaopen_package);
//    luajit::open_lib(LSVM, LUA_TABLIBNAME, luaopen_table);
//    luajit::open_lib(LSVM, LUA_IOLIBNAME, luaopen_io);
//    luajit::open_lib(LSVM, LUA_OSLIBNAME, luaopen_os);
//    luajit::open_lib(LSVM, LUA_MATHLIBNAME, luaopen_math);
//    luajit::open_lib(LSVM, LUA_STRLIBNAME, luaopen_string);
//    luajit::open_lib(LSVM, LUA_BITLIBNAME, luaopen_bit);
//    luajit::open_lib(LSVM, LUA_FFILIBNAME, luaopen_ffi);
//#ifdef DEBUG
//    luajit::open_lib(LSVM, LUA_DBLIBNAME, luaopen_debug);
//#endif
//    //// load shaders
//    //// загрузить список всех шейдеров
//    //std::string path = R"(E:\Program Files\STLK-COP\UEgamedata\shaders\r2)";
//    //int c(0);
//    //for (const auto& entry : fs::directory_iterator(path))
//    //{
//    //    if (fs::is_directory(entry))
//    //        continue;
//    //    ++c;
//    //    string_path namesp, fn;
//    //    strcpy(namesp, entry.path().filename().string().c_str());
//    //    try {
//    //        OutputDebugStringA((entry.path().string() + "\n").c_str());
//    //        bfLoadFileIntoNamespace(LSVM, entry.path().string().c_str(), namesp, true); // перенести из движка сюда
//    //    }
//    //    catch (...)
//    //    {
//    //        // error
//    //        return -1;
//    //    }
//    //}
//    //// поптыка обратиться к луа скрипту
//    //LPCSTR				t_0 = "$null";
//    //LPCSTR				t_1 = "null";
//    //LPCSTR				t_d = "null";
//    //const object				shader = luabind::globals(LSVM)["combine_volumetric"];
//    //const functor<void> element = (object)shader["normal"];
//    //adopt_compiler		ac = adopt_compiler();
//    //element(ac, t_0, t_1, t_d);
//
//
//
//    ////
//
//
//    return true;
//}
//
//int APIENTRY WinMain(HINSTANCE hInstance,
//    HINSTANCE hPrevInstance,
//    char* lpCmdLine,
//    int       nCmdShow)
//{
//    MSG msg = { 0 };
//    return _winMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
//}
//
//


#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <windows.h>
namespace fs = std::filesystem;

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};

typedef char* pstr;
using pcstr = const char*;

using namespace std;

static void* lua_alloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    (void)ud;
    (void)osize;
    if (!nsize)
    {
        free(ptr);
        return nullptr;
    }
    return realloc(ptr, nsize);
}

struct luajit
{
    static void open_lib(lua_State* L, pcstr module_name, lua_CFunction function)
    {
        lua_pushcfunction(L, function);
        lua_pushstring(L, module_name);
        lua_call(L, 1, 0);
    }

    static void allow_escape_sequences(bool allowed)
    {
        lj_allow_escape_sequences(allowed ? 1 : 0);
    }
};

int _winMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    lua_State* LSVM = lua_newstate(lua_alloc, NULL);
    luajit::open_lib(LSVM, "", luaopen_base);
    return true;
}   

int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    char* lpCmdLine,
    int       nCmdShow)
{
    MSG msg = { 0 };
    return _winMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}


