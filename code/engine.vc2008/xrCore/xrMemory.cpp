#include "stdafx.h"


#include <Psapi.h>

#include "xrMemory_align.h"
#define xr_internal_malloc(size, alignment) xr_aligned_malloc(size, alignment)
#define xr_internal_malloc_nothrow(size, alignment) xr_aligned_malloc(size, alignment)
#define xr_internal_realloc(ptr, size, alignment) xr_aligned_realloc(ptr, size, alignment)
#define xr_internal_free(ptr, alignment) xr_aligned_free(ptr)

#ifdef NDEBUG
constexpr size_t xr_reserved_tail = 8;
#else
constexpr size_t xr_reserved_tail = 0;
#endif

constexpr size_t DEFAULT_ALIGNMENT = 16;

xrMemory Memory;
// Also used in src\xrCore\xrDebug.cpp to prevent use of g_pStringContainer before it initialized
bool shared_str_initialized = false;

extern		pso_MemCopy		xrMemCopy_MMX;
extern		pso_MemCopy		xrMemCopy_x86;
extern		pso_MemFill		xrMemFill_x86;
extern		pso_MemFill32	xrMemFill32_MMX;
extern		pso_MemFill32	xrMemFill32_x86;

xrMemory::xrMemory()
{
    mem_copy = xrMemCopy_x86;
    mem_fill = xrMemFill_x86;
    mem_fill32 = xrMemFill32_x86;
}

void xrMemory::_initialize()
{
#ifndef __BORLANDC__
	stat_calls = 0;
#endif

    g_pStringContainer = xr_new<str_container>();
    shared_str_initialized = true;
    g_pSharedMemoryContainer = xr_new<smem_container>();
}

void xrMemory::_destroy()
{
    xr_delete(g_pSharedMemoryContainer);
    xr_delete(g_pStringContainer);
}

// xr_strdup
XRCORE_API pstr xr_strdup(pcstr string)
{
#ifdef USE_MIMALLOC
    return mi_strdup(string);
#else
	VERIFY(string);
	size_t len = xr_strlen(string) + 1;
	char* memory = (char*)xr_malloc(len);
	CopyMemory(memory, string, len);
	return memory;
#endif
}

XRCORE_API void vminfo(size_t* _free, size_t* reserved, size_t* committed)
{
    MEMORY_BASIC_INFORMATION memory_info;
    memory_info.BaseAddress = nullptr;
    *_free = *reserved = *committed = 0;
    while (VirtualQuery(memory_info.BaseAddress, &memory_info, sizeof(memory_info))) //-V575
    {
        switch (memory_info.State)
        {
        case MEM_FREE: *_free += memory_info.RegionSize; break;
        case MEM_RESERVE: *reserved += memory_info.RegionSize; break;
        case MEM_COMMIT: *committed += memory_info.RegionSize; break;
        }
        memory_info.BaseAddress = (char*)memory_info.BaseAddress + memory_info.RegionSize;
    }
}

XRCORE_API void log_vminfo()
{
    size_t  w_free, w_reserved, w_committed;
    vminfo(&w_free, &w_reserved, &w_committed);
    Msg(
        "* [win32]: free[%d K], reserved[%d K], committed[%d K]",
        w_free / 1024,
        w_reserved / 1024,
        w_committed / 1024
    );
}

size_t xrMemory::mem_usage()
{
    PROCESS_MEMORY_COUNTERS pmc = {};
    if (HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, GetCurrentProcessId()))
    {
        GetProcessMemoryInfo(h, &pmc, sizeof(pmc));
        CloseHandle(h);
    }
    return pmc.PagefileUsage;
}

void xrMemory::mem_compact()
{
    RegFlushKey(HKEY_CLASSES_ROOT);
    RegFlushKey(HKEY_CURRENT_USER);

    /*
    Следующая команда, в целом, не нужна.
    Современные аллокаторы достаточно грамотно и когда нужно возвращают память операционной системе.
    Эта строчка нужна, скорее всего, в определённых ситуациях, вроде использования файлов отображаемых в память,
    которые требуют большие свободные области памяти.
    */
    //HeapCompact(GetProcessHeap(), 0);
    if (g_pStringContainer)
        g_pStringContainer->clean();
    if (g_pSharedMemoryContainer)
        g_pSharedMemoryContainer->clean();

    if (strstr(Core.Params, "-swap_on_compact"))
        SetProcessWorkingSetSize(GetCurrentProcess(), size_t(-1), size_t(-1));
}

#ifndef __BORLANDC__

void* xrMemory::mem_alloc(size_t size, const char* name)
{
    stat_calls++;
    return xr_internal_malloc(size, DEFAULT_ALIGNMENT);
}

void* xrMemory::mem_alloc(size_t size, size_t alignment, const char* name)
{
    stat_calls++;
    return xr_internal_malloc(size, alignment);
}

void* xrMemory::mem_alloc(size_t size, const std::nothrow_t&, const char* name) noexcept
{
    stat_calls++;
    return xr_internal_malloc_nothrow(size, DEFAULT_ALIGNMENT);
}

void* xrMemory::mem_alloc(size_t size, size_t alignment, const std::nothrow_t&, const char* name) noexcept
{
    stat_calls++;
    return xr_internal_malloc_nothrow(size, alignment);
}

void* xrMemory::mem_realloc(void* ptr, size_t size, const char* name)
{
    stat_calls++;
    return xr_internal_realloc(ptr, size, DEFAULT_ALIGNMENT);
}

void* xrMemory::mem_realloc(void* ptr, size_t size, size_t alignment, const char* name)
{
    stat_calls++;
    return xr_internal_realloc(ptr, size, alignment);
}

void xrMemory::mem_free(void* ptr)
{
    stat_calls++;
    xr_internal_free(ptr, DEFAULT_ALIGNMENT);
}

void xrMemory::mem_free(void* ptr, size_t alignment)
{
    stat_calls++;
    xr_internal_free(ptr, alignment);
}

#else

// Borland doesn't support marked aligned allocs ???
void*	xrMemory::mem_alloc		(size_t size, const char* name)
{
	if (0==size) size			= 1;

	void* data 					= malloc	(size);
	if(!data)
		Debug.fatal		(DEBUG_INFO,"Out of memory. Memory request: %d K",size/1024);
	return data;
}
void	xrMemory::mem_free		(void* P)
{
	free						(P);
}
void*	xrMemory::mem_realloc	(void* P, size_t size, const char* name)
{
	void* data					= realloc(P,size);
    if(size&&(0==data))
		Debug.fatal(DEBUG_INFO,"Out of memory. Memory request: %d K",size/1024);
	return data;
}

#endif
