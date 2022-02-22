#include <stdafx.h>
#include "lua_helper.h"

#include "xrMemory.h"

std::unique_ptr<ScriptBuffer> ScriptBuffer::instanse(nullptr);

ScriptBuffer::~ScriptBuffer()
{
	if (scriptBuffer)
		xr_free(scriptBuffer);
}

void ScriptBuffer::resize(size_t total_size)
{
	if (total_size >= scriptBufferSize)
	{
		scriptBufferSize = total_size;
		scriptBuffer = (char*)xr_realloc(scriptBuffer, scriptBufferSize);
	}
}

std::unique_ptr<ScriptBuffer>& ScriptBuffer::getInstance()
{
	if (!instanse)
	{
		instanse.reset(new ScriptBuffer);
		instanse->scriptBufferSize = 1024 * 1024;
		instanse->scriptBuffer = xr_alloc<char>(instanse->scriptBufferSize);
	}
	return instanse;
}
