////////////////////////////////////////////////////////////////////////////
//	Module 		: ai_script_lua_extension.h
//	Created 	: 19.09.2003
//  Modified 	: 22.09.2003
//	Author		: Dmitriy Iassenev
//	Description : XRay Script extensions
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ai_script_space.h"
#include "../common/Noncopyable.hpp"
#include <memory>
//struct CLuaVirtualMachine;

//class ScriptBuffer
//{
//	static std::unique_ptr< ScriptBuffer> instanse;
//
//public:
//	char* scriptBuffer = nullptr;
//	size_t scriptBufferSize = 0;
//
//public:
//	ScriptBuffer() = default;
//	ScriptBuffer(ScriptBuffer&) = delete;
//	ScriptBuffer& operator=(ScriptBuffer&) = delete;
//	ScriptBuffer(ScriptBuffer&&) = delete;
//	const ScriptBuffer& operator=(ScriptBuffer&&) = delete;
//	~ScriptBuffer();
//
//	void resize(size_t total_size);
//
//	static std::unique_ptr< ScriptBuffer>& getInstance();
//};

namespace Script {
#ifndef ENGINE_BUILD
	void				vfExportGlobals				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportFvector				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportFmatrix				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportGame				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportLevel				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportDevice				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportParticles			(CLuaVirtualMachine *tpLuaVM);
	void				vfExportSound				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportHit					(CLuaVirtualMachine *tpLuaVM);
	void				vfExportActions				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportObject				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportEffector			(CLuaVirtualMachine *tpLuaVM);
	void				vfExportArtifactMerger		(CLuaVirtualMachine *tpLuaVM);
	void				vfLoadStandardScripts		(CLuaVirtualMachine *tpLuaVM);
	void				vfExportMemoryObjects		(CLuaVirtualMachine *tpLuaVM);
	void				vfExportToLua				(CLuaVirtualMachine *tpLuaVM);
	void				vfExportActionManagement	(CLuaVirtualMachine *tpLuaVM);
	void				vfExportMotivationManagement(CLuaVirtualMachine *tpLuaVM);
	bool				bfLoadFile					(CLuaVirtualMachine *tpLuaVM, LPCSTR	caScriptName,	bool	bCall = true);
	void				LuaHookCall					(CLuaVirtualMachine *tpLuaVM, lua_Debug *tpLuaDebug);
	int					LuaPanic					(CLuaVirtualMachine *tpLuaVM);
#endif
	bool				bfPrintOutput				(CLuaVirtualMachine *tpLuaVM, LPCSTR	caScriptName, int iErorCode = 0);
	LPCSTR				cafEventToString			(int				iEventCode);
	void				vfPrintError				(CLuaVirtualMachine *tpLuaVM, int		iErrorCode);
	bool				bfListLevelVars				(CLuaVirtualMachine *tpLuaVM, int		iStackLevel);
	bool				bfLoadBuffer				(CLuaVirtualMachine *tpLuaVM, LPCSTR	caBuffer,		size_t	tSize,				LPCSTR	caScriptName, LPCSTR caNameSpaceName = 0);
	bool				bfLoadFileIntoNamespace		(CLuaVirtualMachine *tpLuaVM, LPCSTR	caScriptName,	LPCSTR	caNamespaceName,	bool	bCall);
	bool				bfGetNamespaceTable			(CLuaVirtualMachine *tpLuaVM, LPCSTR	caName);
	CLuaVirtualMachine	*get_namespace_table		(CLuaVirtualMachine *tpLuaVM, LPCSTR	caName);
	bool				bfIsObjectPresent			(CLuaVirtualMachine *tpLuaVM, LPCSTR	caIdentifier,	int type);
	bool				bfIsObjectPresent			(CLuaVirtualMachine *tpLuaVM, LPCSTR	caNamespaceName, LPCSTR	caIdentifier, int type);
	luabind::object		lua_namespace_table			(CLuaVirtualMachine *tpLuaVM, LPCSTR namespace_name);

	bool parse_namespace(pcstr caNamespaceName, pstr b, size_t b_size, pstr c, size_t c_size);

};
