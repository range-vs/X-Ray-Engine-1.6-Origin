#pragma once
#include <memory>

class ScriptBuffer
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