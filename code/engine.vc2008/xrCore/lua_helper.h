#pragma once
#include <memory>

#include "xrCore.h"

#define SCRIPT_GLOBAL_NAMESPACE "_G"

static const char* file_header_old = "local function script_name() \
return \"%s\" \
end \
local this = {} \
%s this %s \
setmetatable(this, {__index = " SCRIPT_GLOBAL_NAMESPACE "}) \
setfenv(1, this) ";

//static const char* file_header_new = "local function script_name() \
//return \"%s\" \
//end \
//local this = {} \
//this." SCRIPT_GLOBAL_NAMESPACE " = " SCRIPT_GLOBAL_NAMESPACE " \
//%s this %s \
//setfenv(1, this) ";

static const char* file_header = file_header_old;

class XRCORE_API ScriptBuffer
{
	static std::unique_ptr< ScriptBuffer> instanse;

public:
	char* scriptBuffer = nullptr;
	size_t scriptBufferSize = 0;

public:
	ScriptBuffer() = default;
	ScriptBuffer(ScriptBuffer&) = delete;
	ScriptBuffer& operator=(ScriptBuffer&) = delete;
	ScriptBuffer(ScriptBuffer&&) = delete;
	const ScriptBuffer& operator=(ScriptBuffer&&) = delete;
	~ScriptBuffer();

	void resize(size_t total_size);

	static std::unique_ptr< ScriptBuffer>& getInstance();
};