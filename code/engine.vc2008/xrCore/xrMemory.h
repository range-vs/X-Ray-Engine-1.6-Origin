#pragma once

#include "_types.h"

#include <new>

#include "xrMemory_pso.h"

#ifndef __BORLANDC__

class XRCORE_API xrMemory {
public:
	xrMemory();
	void _initialize();
	void _destroy();

	u32 stat_calls;

	size_t mem_usage();
	void mem_compact();

	void* mem_alloc(size_t size, const char* name = nullptr);
	void* mem_alloc(size_t size, size_t alignment, const char* name = nullptr);
	void* mem_alloc(size_t size, const std::nothrow_t&, const char* name =
		nullptr) noexcept;
	void* mem_alloc(size_t size, size_t alignment, const std::nothrow_t&,
		const char* name = nullptr) noexcept;
	void* mem_realloc(void* ptr, size_t size, const char* name = nullptr);
	void* mem_realloc(void* ptr, size_t size, size_t alignment,
		const char* name = nullptr);
	void mem_free(void* ptr);
	void mem_free(void* ptr, size_t alignment);

	pso_MemCopy* mem_copy;
	pso_MemFill* mem_fill;
	pso_MemFill32* mem_fill32;
};

extern XRCORE_API xrMemory Memory;

// Global C++ new/delete overrides.
[[nodiscard]]

inline void* operator new(size_t size) {
	return Memory.mem_alloc(size);
}

[[nodiscard]]

inline void* operator new(size_t size, const std::nothrow_t&) noexcept {
	return Memory.mem_alloc(size);
}

inline void operator delete(void* ptr) noexcept {
	Memory.mem_free(ptr);
}

inline void operator delete(void* ptr, size_t) noexcept {
	Memory.mem_free(ptr);
}

#ifdef DEBUG_MEMORY_NAME
// new(0)
#include "../editors/Include/stack_trace.h"

template<class T>
IC T* xr_new() {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T();
}

// new(1)
template<class T, class P1>
IC T* xr_new(const P1& p1) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1);
}

// new(2)
template<class T, class P1, class P2>
IC T* xr_new(const P1& p1, const P2& p2) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2);
}

// new(3)
template<class T, class P1, class P2, class P3>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3);
}

// new(4)
template<class T, class P1, class P2, class P3, class P4>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4);
}

// new(5)
template<class T, class P1, class P2, class P3, class P4, class P5>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4, p5);
}

// new(6)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4, p5, p6);
}

// new(7)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7);
}

// new(8)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7, class P8>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7, const P8& p8) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7, p8);
}

// new(9)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7, class P8, class P9>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P8& p9) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T), typeid(T).name());
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7, p8, p9);
}
#else // DEBUG_MEMORY_NAME

// new(0)
template<class T>
IC T* xr_new() {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T();
}

// new(1)
template<class T, class P1>
IC T* xr_new(const P1& p1) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1);
}

// new(2)
template<class T, class P1, class P2>
IC T* xr_new(const P1& p1, const P2& p2) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2);
}

// new(3)
template<class T, class P1, class P2, class P3>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3);
}

// new(4)
template<class T, class P1, class P2, class P3, class P4>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4);
}

// new(5)
template<class T, class P1, class P2, class P3, class P4, class P5>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4, p5);
}

// new(6)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4, p5, p6);
}

// new(7)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7);
}

// new(8)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7, class P8>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7, const P8& p8) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7, p8);
}

// new(9)
template<class T, class P1, class P2, class P3, class P4, class P5, class P6,
	class P7, class P8, class P9>
IC T* xr_new(const P1& p1, const P2& p2, const P3& p3, const P4& p4,
	const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P8& p9) {
	T* ptr = (T*)Memory.mem_alloc(sizeof(T));
	return new(ptr) T(p1, p2, p3, p4, p5, p6, p7, p8, p9);
}
#endif // DEBUG_MEMORY_NAME

template<bool _is_pm, typename T>
struct xr_special_free {
	IC void operator()(T*& ptr) {
		void* _real_ptr = dynamic_cast<void*>(ptr);
		ptr->~T();
		Memory.mem_free(_real_ptr);
	}

};

template<typename T>
struct xr_special_free<false, T> {
	IC void operator()(T*& ptr) {
		ptr->~T();
		Memory.mem_free(ptr);
	}
};

template<class T>
IC void xr_delete(T*& ptr) {
	if (ptr) {
		xr_special_free<std::is_polymorphic<T>::value, T>()(ptr);
		ptr = NULL;
	}
}

template<class T>
IC void xr_delete(T* const & ptr) {
	if (ptr) {
		xr_special_free<std::is_polymorphic<T>::value, T>(ptr);
		const_cast<T*&>(ptr) = NULL;
	}
}

#else

class XRCORE_API xrMemory {
public:
	xrMemory();
	void _initialize();
	void _destroy();

	size_t mem_usage();
	void mem_compact();

	void* mem_alloc(size_t size, const char* name = nullptr);
	void* mem_realloc(void* ptr, size_t size, const char* name = nullptr);
	void mem_free(void* ptr);

	pso_MemCopy* mem_copy;
	pso_MemFill* mem_fill;
	pso_MemFill32* mem_fill32;
};

extern XRCORE_API xrMemory Memory;

template <class T>
IC	T*		xr_new		()
{
	return new T();
}
// new(1)
template <class T, class P1>
IC	T*		xr_new		(P1 p1) {
	return new T(p1);
}
// new(2)
template <class T, class P1, class P2>
IC	T*		xr_new		(P1 p1, P2 p2)
{
	return new T(p1,p2);
}
// new(3)
template <class T, class P1, class P2, class P3>
IC	T*		xr_new		(P1 p1, P2 p2, P3 p3) {
	return new T(p1,p2,p3);
}
// new(4)
template <class T, class P1, class P2, class P3, class P4>
IC	T*		xr_new		(P1 p1, P2 p2, P3 p3, P4 p4) {
	return new T(p1,p2,p3,p4);
}
// new(5)
template <class T, class P1, class P2, class P3, class P4, class P5>
IC	T*		xr_new		(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) {
	return new T(p1,p2,p3,p4,p5);
}
// new(6)
template <class T, class P1, class P2, class P3, class P4, class P5, class P6>
IC	T*		xr_new		(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) {
	return new T(p1,p2,p3,p4,p5,p6);
}
// new(7)
template <class T, class P1, class P2, class P3, class P4, class P5, class P6, class P7>
IC	T*		xr_new		(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7) {
	return new T(p1,p2,p3,p4,p5,p6,p7);
}

//	#define xr_delete(ptr) if (ptr){delete ptr; ptr=0;}
template <class T>
IC	void	xr_delete	(T* &ptr)
{
	if (ptr)
	{
		delete ptr;
		const_cast<T*&>(ptr) = NULL;
	}
}

#endif

#undef ZeroMemory
#undef CopyMemory
#undef FillMemory
#define ZeroMemory(dst, size) memset(dst, 0, size)
#define CopyMemory(dst, src, size) memcpy(dst, src, size)
#define FillMemory(dst, size, val) memset(dst, val, size)


// generic "C"-like allocations/deallocations
template<class T>
inline T* xr_alloc(size_t count) {
	return (T*)Memory.mem_alloc(count * sizeof(T));
}

template<class T>
inline void xr_free(T*& ptr) noexcept {
	if (ptr) {
		Memory.mem_free((void*)ptr);
		ptr = nullptr;
	}
}

inline void* xr_malloc(size_t size) {
	return Memory.mem_alloc(size);
}

inline void* xr_realloc(void* ptr, size_t size) {
	return Memory.mem_realloc(ptr, size);
}

XRCORE_API pstr xr_strdup(pcstr string);

XRCORE_API void log_vminfo();
