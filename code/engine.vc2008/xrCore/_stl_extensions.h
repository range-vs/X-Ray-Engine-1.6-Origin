//#ifndef _STL_EXT_internal
//#define _STL_EXT_internal
//
//using std::swap;
//
//#include "_type_traits.h"
//
//#ifdef	__BORLANDC__
//#define M_NOSTDCONTAINERS_EXT
//#endif
//#ifdef	_M_AMD64
//#define M_DONTDEFERCLEAR_EXT
//#endif
//
//#define	M_DONTDEFERCLEAR_EXT		//. for mem-debug only
//
////--------	
//#ifdef	M_NOSTDCONTAINERS_EXT
//
//#define xr_list std::list
//#define xr_deque std::deque
//#define xr_stack std::stack
//#define xr_set std::set
//#define xr_multiset std::multiset
//#define xr_map std::map
//#define xr_hash_map std::hash_map
//#define xr_multimap std::multimap
//#define xr_string std::string
//
//template <class T>
//class xr_vector : public std::vector<T> {
//public:
//	typedef	size_t		size_type;
//	typedef T& reference;
//	typedef const T& const_reference;
//public:
//	xr_vector() : std::vector<T>() {}
//	xr_vector(size_t _count, const T& _value) : std::vector<T>(_count, _value) {}
//	explicit xr_vector(size_t _count) : std::vector<T>(_count) {}
//	void	clear() { this->erase(this->begin(), this->end()); }
//	void	clear() { std::vector<T>::clear(); }
//	void	clear() { this->erase(this->begin(), this->end()); }
//	ICF		const_reference	operator[]	(size_type _Pos) const { {VERIFY(_Pos < this->size()); } return (*(this->begin() + _Pos)); }
//	ICF		reference		operator[]	(size_type _Pos) { {VERIFY(_Pos < this->size()); } return (*(this->begin() + _Pos)); }
//};
//
//template	<>
//class	xr_vector<bool> : public std::vector<bool> {
//	typedef	bool		T;
//public:
//	xr_vector<T>() : std::vector<T>() {}
//	xr_vector<T>(size_t _count, const T& _value) : std::vector<T>(_count, _value) {}
//	explicit xr_vector<T>(size_t _count) : std::vector<T>(_count) {}
//	u32		size() const { return (u32)std::vector<T>::size(); }
//	void	clear() { erase(begin(), end()); }
//};
//
//#else
//
//template <class T>
//class	xalloc {
//public:
//	typedef	size_t		size_type;
//	typedef ptrdiff_t	difference_type;
//	typedef T* pointer;
//	typedef const T* const_pointer;
//	typedef T& reference;
//	typedef const T& const_reference;
//	typedef T			value_type;
//
//public:
//	template<class _Other>
//	struct rebind { typedef xalloc<_Other> other; };
//public:
//	pointer					address(reference _Val) const { return (&_Val); }
//	const_pointer			address(const_reference _Val) const { return (&_Val); }
//	xalloc() {	}
//	xalloc(const xalloc<T>&) {	}
//	template<class _Other>							xalloc(const xalloc<_Other>&) {	}
//	template<class _Other>	xalloc<T>& operator=		(const xalloc<_Other>&) { return (*this); }
//	pointer					allocate(size_type n, const void* p = 0) const { return xr_alloc<T>((u32)n); }
//	char* _charalloc(size_type n) { return (char*)allocate(n); }
//	void					deallocate(pointer p, size_type n) const { xr_free(p); }
//	void					deallocate(void* p, size_type n) const { xr_free(p); }
//#ifdef _EDITOR // range fix
//	void					construct(pointer p, const T& _Val) { std::_Construct(p, _Val); }
//	void					destroy(pointer p) { std::_Destroy(p); }
//#else
//	void					construct(pointer p, const T& _Val)
//	{
//		new((void*)p) T(_Val);
//	}
//	void					destroy(pointer p)
//	{
//		p->~T();
//	}
//#endif
//	size_type				max_size() const { size_type _Count = (size_type)(-1) / sizeof(T);	return (0 < _Count ? _Count : 1); }
//};
//
//struct xr_allocator
//{
//	template <typename T>
//	struct helper
//	{
//		typedef xalloc<T>	result;
//	};
//
//	static	void* alloc(const u32& n) { return xr_malloc((u32)n); }
//	template <typename T>
//	static	void	dealloc(T*& p) { xr_free(p); }
//};
//
//
//template<class _Ty, class _Other>	inline	bool operator==(const xalloc<_Ty>&, const xalloc<_Other>&) { return (true); }
//template<class _Ty, class _Other>	inline	bool operator!=(const xalloc<_Ty>&, const xalloc<_Other>&) { return (false); }
//
//namespace std
//{
//	template<class _Tp1, class _Tp2>	inline	xalloc<_Tp2>& __stl_alloc_rebind(xalloc<_Tp1>& __a, const _Tp2*) { return (xalloc<_Tp2>&)(__a); }
//	template<class _Tp1, class _Tp2>	inline	xalloc<_Tp2>	__stl_alloc_create(xalloc<_Tp1>&, const _Tp2*) { return xalloc<_Tp2>(); }
//};
//
//// string(char)
//typedef		std::basic_string<char, std::char_traits<char>, xalloc<char> >	xr_string;

//// vector
//template	<typename T, typename allocator = xalloc<T> >
//class xr_vector : public std::vector<T, allocator> {
//private:
//	typedef std::vector<T, allocator>	inherited;
//
//public:
//	typedef allocator					allocator_type;
//
//public:
//	xr_vector() : inherited() {}
//	xr_vector(size_t _count, const T& _value) : inherited(_count, _value) {}
//	explicit xr_vector(size_t _count) : inherited(_count) {}
//	u32		size() const { return (u32)inherited::size(); }
//
//	void	clear() { inherited::clear(); }
//	void	clear() { erase(begin(), end()); }
//	void	clear_and_reserve() { if (capacity() <= (size() + size() / 4)) clear(); else { u32 old = size(); clear(); reserve(old); } }
//
//#ifdef M_DONTDEFERCLEAR_EXT
//	void	clear() { clear(); }
//#else
//	void	clear() { clear(); }
//#endif
//
//	const_reference operator[]	(size_type _Pos) const { {VERIFY2(_Pos < size(), make_string("index is out of range: index requested[%d], size of container[%d]", _Pos, size()).c_str()); } return (*(begin() + _Pos)); }
//	reference operator[]		(size_type _Pos) { {VERIFY2(_Pos < size(), make_string("index is out of range: index requested[%d], size of container[%d]", _Pos, size()).c_str()); } return (*(begin() + _Pos)); }
//};
//
//// vector<bool>
//template <>
//class xr_vector<bool, xalloc<bool> > : public std::vector<bool, xalloc<bool> > {
//private:
//	typedef std::vector<bool, xalloc<bool> > inherited;
//
//public:
//	u32		size() const { return (u32)inherited::size(); }
//	void	clear() { erase(begin(), end()); }
//};
//
//template <typename allocator>
//class xr_vector<bool, allocator> : public std::vector<bool, allocator> {
//private:
//	typedef std::vector<bool, allocator> inherited;
//
//public:
//	u32		size() const { return (u32)inherited::size(); }
//	void	clear() { erase(begin(), end()); }
//};
//
//// deque
//template <typename T, typename allocator = xalloc<T> >
//class xr_deque : public std::deque<T, allocator> {
//public:
//	typedef typename allocator								allocator_type;
//	typedef typename allocator_type::value_type				value_type;
//	typedef typename allocator_type::size_type				size_type;
//	u32		size() const { return (u32)__super::size(); }
//};
//
//// stack
//template <typename _Ty, class _C = xr_vector<_Ty> >
//class xr_stack {
//public:
//	typedef typename _C::allocator_type						allocator_type;
//	typedef typename allocator_type::value_type				value_type;
//	typedef typename allocator_type::size_type				size_type;
//
//	//explicit			stack(const allocator_type& _Al = allocator_type()) : c(_Al) {}
//	allocator_type		get_allocator() const { return (c.get_allocator()); }
//	bool				empty() const { return (c.empty()); }
//	u32					size() const { return c.size(); }
//	value_type& top() { return (c.back()); }
//	const value_type& top() const { return (c.back()); }
//	void				push(const value_type& _X) { c.push_back(_X); }
//	void				pop() { c.pop_back(); }
//	bool				operator==		(const xr_stack<_Ty, _C>& _X) const { return (c == _X.c); }
//	bool				operator!=		(const xr_stack<_Ty, _C>& _X) const { return (!(*this == _X)); }
//	bool				operator<		(const xr_stack<_Ty, _C>& _X) const { return (c < _X.c); }
//	bool				operator>		(const xr_stack<_Ty, _C>& _X) const { return (_X < *this); }
//	bool				operator<=		(const xr_stack<_Ty, _C>& _X) const { return (!(_X < *this)); }
//	bool				operator>=		(const xr_stack<_Ty, _C>& _X) const { return (!(*this < _X)); }
//
//protected:
//	_C c;
//};
//
//template	<typename T, typename allocator = xalloc<T> >									class	xr_list : public std::list<T, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class P = std::less<K>, typename allocator = xalloc<K> >				class	xr_set : public std::set<K, P, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class P = std::less<K>, typename allocator = xalloc<K> >				class	xr_multiset : public std::multiset<K, P, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_map : public std::map<K, V, P, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class V, class P = std::less<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_multimap : public std::multimap<K, V, P, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//
//#ifdef STLPORT
//template	<typename V, class _HashFcn = std::hash<V>, class _EqualKey = std::equal_to<V>, typename allocator = xalloc<V> >	class	xr_hash_set : public std::hash_set<V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename V, class _HashFcn = std::hash<V>, class _EqualKey = std::equal_to<V>, typename allocator = xalloc<V> >	class	xr_hash_multiset : public std::hash_multiset<V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//
//template	<typename K, class V, class _HashFcn = std::hash<K>, class _EqualKey = std::equal_to<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_hash_map : public std::hash_map<K, V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class V, class _HashFcn = std::hash<K>, class _EqualKey = std::equal_to<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_hash_multimap : public std::hash_multimap<K, V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//#else 
//	template	<typename K, class V, class _Traits=stdext::hash_compare<K, std::less<K> >, typename allocator = xalloc<std::pair<K,V> > >	class	xr_hash_map		: public stdext::hash_map<K,V,_Traits,allocator>	{ public: u32 size() const {return (u32)__super::size(); } };
//#endif // #ifdef STLPORT
//
//#endif
//
//template	<class _Ty1, class _Ty2> inline	std::pair<_Ty1, _Ty2>		mk_pair(_Ty1 _Val1, _Ty2 _Val2) { return (std::pair<_Ty1, _Ty2>(_Val1, _Val2)); }
//
//struct pred_str : public std::binary_function<char*, char*, bool> {
//	IC bool operator()(const char* x, const char* y) const { return xr_strcmp(x, y) < 0; }
//};
//struct pred_stri : public std::binary_function<char*, char*, bool> {
//	IC bool operator()(const char* x, const char* y) const { return stricmp(x, y) < 0; }
//};

//#include "FixedVector.h"
//#include "buffer_vector.h"
//
//// auxilary definition
//typedef xr_vector< bool > boolVec; typedef boolVec::iterator boolIt;
//typedef xr_vector< BOOL > BOOLVec; typedef BOOLVec::iterator BOOLIt;
//typedef xr_vector< BOOL* > LPBOOLVec; typedef LPBOOLVec::iterator LPBOOLIt;
//typedef xr_vector< Frect > FrectVec; typedef FrectVec::iterator FrectIt;
//typedef xr_vector< Irect > IrectVec; typedef IrectVec::iterator IrectIt;
//typedef xr_vector< Fplane > PlaneVec; typedef PlaneVec::iterator PlaneIt;
//typedef xr_vector< Fvector2 > Fvector2Vec; typedef Fvector2Vec::iterator Fvector2It;
//typedef xr_vector< Fvector > FvectorVec; typedef FvectorVec::iterator FvectorIt;
//typedef xr_vector< Fvector* > LPFvectorVec; typedef LPFvectorVec::iterator LPFvectorIt;
//typedef xr_vector< Fcolor > FcolorVec; typedef FcolorVec::iterator FcolorIt;
//typedef xr_vector< Fcolor* > LPFcolorVec; typedef LPFcolorVec::iterator LPFcolorIt;
//typedef xr_vector< LPSTR > LPSTRVec; typedef LPSTRVec::iterator LPSTRIt;
//typedef xr_vector< LPCSTR > LPCSTRVec; typedef LPCSTRVec::iterator LPCSTRIt;
//typedef xr_vector< string64 > string64Vec; typedef string64Vec::iterator string64It;
//typedef xr_vector< xr_string > SStringVec; typedef SStringVec::iterator SStringVecIt;
//
//typedef xr_vector< s8 > S8Vec; typedef S8Vec::iterator S8It;
//typedef xr_vector< s8* > LPS8Vec; typedef LPS8Vec::iterator LPS8It;
//typedef xr_vector< s16 > S16Vec; typedef S16Vec::iterator S16It;
//typedef xr_vector< s16* > LPS16Vec; typedef LPS16Vec::iterator LPS16It;
//typedef xr_vector< s32 > S32Vec; typedef S32Vec::iterator S32It;
//typedef xr_vector< s32* > LPS32Vec; typedef LPS32Vec::iterator LPS32It;
//typedef xr_vector< u8 > U8Vec; typedef U8Vec::iterator U8It;
//typedef xr_vector< u8* > LPU8Vec; typedef LPU8Vec::iterator LPU8It;
//typedef xr_vector< u16 > U16Vec; typedef U16Vec::iterator U16It;
//typedef xr_vector< u16* > LPU16Vec; typedef LPU16Vec::iterator LPU16It;
//typedef xr_vector< u32 > U32Vec; typedef U32Vec::iterator U32It;
//typedef xr_vector< u32* > LPU32Vec; typedef LPU32Vec::iterator LPU32It;
//typedef xr_vector< float > FloatVec; typedef FloatVec::iterator FloatIt;
//typedef xr_vector< float* > LPFloatVec; typedef LPFloatVec::iterator LPFloatIt;
//typedef xr_vector< int > IntVec; typedef IntVec::iterator IntIt;
//typedef xr_vector< int* > LPIntVec; typedef LPIntVec::iterator LPIntIt;
//
//#ifdef __BORLANDC__
//typedef xr_vector< AnsiString > AStringVec; typedef AStringVec::iterator AStringIt;
//typedef xr_vector< AnsiString* > LPAStringVec; typedef LPAStringVec::iterator LPAStringIt;
//#endif

#ifndef _STL_EXT_internal
#define _STL_EXT_internal

using std::swap;

#include <unordered_map>

#include "_type_traits.h"

#ifdef	__BORLANDC__
#define M_NOSTDCONTAINERS_EXT
#endif
#ifdef	_M_AMD64
#define M_DONTDEFERCLEAR_EXT
#endif

#define	M_DONTDEFERCLEAR_EXT		//. for mem-debug only


template <typename T>
class xalloc
{
public:
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    template <class Other>
    struct rebind
    {
        using other = xalloc<Other>;
    };

    pointer address(reference ref) const { return &ref; }
    const_pointer address(const_reference ref) const { return &ref; }

    xalloc() = default;
    xalloc(const xalloc<T>&) = default;

    template <class Other>
    xalloc(const xalloc<Other>&)
    {
    }

    template <class Other>
    xalloc& operator=(const xalloc<Other>&)
    {
        return *this;
    }

    static pointer allocate(const size_type n, const void* p = nullptr) { return xr_alloc<T>(n); }
    static void deallocate(pointer p, const size_type /*n*/) { xr_free(p); }
    static void deallocate(void* p, const size_type /*n*/) { xr_free(p); }

    template <class U, class... Args>
    static void construct(U* ptr, Args&&... args)
    {
        new (ptr) U(std::forward<Args>(args)...);
    }

    template <class U>
    static void destroy(U* p)
    {
        p->~U();
    }

    static constexpr size_type max_size()
    {
        constexpr auto count = std::numeric_limits<size_type>::max() / sizeof(T);
        return count > 0 ? count : 1;
    }
};

template <class T, class Other>
bool operator==(const xalloc<T>&, const xalloc<Other>&)
{
    return true;
}

template <class T, class Other>
bool operator!=(const xalloc<T>&, const xalloc<Other>&)
{
    return false;
}

template <typename T>
using xr_allocator = xalloc<T>;

template <typename T, typename allocator = xr_allocator<T>>
using xr_vector = std::vector<T, allocator>;

//template <typename K, class V, class Hasher = std::hash<K>, class Traits = std::equal_to<K>,
//    typename allocator = xr_allocator<std::pair<const K, V>>>
//    using xr_unordered_map = std::unordered_map<K, V, Hasher, Traits, allocator>;

using xr_string = std::basic_string<char, std::char_traits<char>, xr_allocator<char>>;

template <typename T, class container = xr_vector<T>>
using xr_stack = std::stack<T, container>;

template <typename K, class P = std::less<K>, typename allocator = xr_allocator<K>>
using xr_set = std::set<K, P, allocator>;

template <typename K, class P = std::less<K>, typename allocator = xr_allocator<K>>
using xr_multiset = std::multiset<K, P, allocator>;

template <typename K, class V, class P = std::less<K>, typename allocator = xr_allocator<std::pair<const K, V>>>
using xr_map = std::map<K, V, P, allocator>;

template <typename K, class V, class P = std::less<K>, typename allocator = xr_allocator<std::pair<const K, V>>>
using xr_multimap = std::multimap<K, V, P, allocator>;

template <typename T, typename allocator = xr_allocator<T>>
using xr_list = std::list<T, allocator>;

template <typename T, typename allocator = xr_allocator<T>>
using xr_deque = std::deque<T, allocator>;

template <typename K, class V, class Hasher = std::hash<K>, class Traits = std::equal_to<K>,
    typename allocator = xr_allocator<std::pair<const K, V>>>
    using xr_unordered_map = std::unordered_map<K, V, Hasher, Traits, allocator>;

//#ifdef STLPORT
//template	<typename V, class _HashFcn = std::hash<V>, class _EqualKey = std::equal_to<V>, typename allocator = xalloc<V> >	class	xr_hash_set : public std::hash_set<V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename V, class _HashFcn = std::hash<V>, class _EqualKey = std::equal_to<V>, typename allocator = xalloc<V> >	class	xr_hash_multiset : public std::hash_multiset<V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//
//template	<typename K, class V, class _HashFcn = std::hash<K>, class _EqualKey = std::equal_to<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_hash_map : public std::hash_map<K, V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//template	<typename K, class V, class _HashFcn = std::hash<K>, class _EqualKey = std::equal_to<K>, typename allocator = xalloc<std::pair<K, V> > >	class	xr_hash_multimap : public std::hash_multimap<K, V, _HashFcn, _EqualKey, allocator> { public: u32 size() const { return (u32)__super::size(); } };
//#else 
//	template	<typename K, class V, class _Traits=stdext::hash_compare<K, std::less<K> >, typename allocator = xalloc<std::pair<K,V> > >	class	xr_hash_map		: public stdext::hash_map<K,V,_Traits,allocator>	{ public: u32 size() const {return (u32)__super::size(); } };
//#endif // #ifdef STLPORT

template	<class _Ty1, class _Ty2> inline	std::pair<_Ty1, _Ty2>		mk_pair(_Ty1 _Val1, _Ty2 _Val2) { return (std::pair<_Ty1, _Ty2>(_Val1, _Val2)); }

//struct pred_str : public std::binary_function<char*, char*, bool> {
//	IC bool operator()(const char* x, const char* y) const { return xr_strcmp(x, y) < 0; }
//};
//struct pred_stri : public std::binary_function<char*, char*, bool> {
//	IC bool operator()(const char* x, const char* y) const { return stricmp(x, y) < 0; }
//};

struct pred_str
{
    bool operator()(const char* x, const char* y) const
    {
        return xr_strcmp(x, y) < 0;
    }
};

struct pred_stri
{
    bool operator()(const char* x, const char* y) const
    {
        return stricmp(x, y) < 0;
    }
};

#include "FixedVector.h"
#include "buffer_vector.h"

// auxilary definition
typedef xr_vector< bool > boolVec; typedef boolVec::iterator boolIt;
typedef xr_vector< BOOL > BOOLVec; typedef BOOLVec::iterator BOOLIt;
typedef xr_vector< BOOL* > LPBOOLVec; typedef LPBOOLVec::iterator LPBOOLIt;
typedef xr_vector< Frect > FrectVec; typedef FrectVec::iterator FrectIt;
typedef xr_vector< Irect > IrectVec; typedef IrectVec::iterator IrectIt;
typedef xr_vector< Fplane > PlaneVec; typedef PlaneVec::iterator PlaneIt;
typedef xr_vector< Fvector2 > Fvector2Vec; typedef Fvector2Vec::iterator Fvector2It;
typedef xr_vector< Fvector > FvectorVec; typedef FvectorVec::iterator FvectorIt;
typedef xr_vector< Fvector* > LPFvectorVec; typedef LPFvectorVec::iterator LPFvectorIt;
typedef xr_vector< Fcolor > FcolorVec; typedef FcolorVec::iterator FcolorIt;
typedef xr_vector< Fcolor* > LPFcolorVec; typedef LPFcolorVec::iterator LPFcolorIt;
typedef xr_vector< LPSTR > LPSTRVec; typedef LPSTRVec::iterator LPSTRIt;
typedef xr_vector< LPCSTR > LPCSTRVec; typedef LPCSTRVec::iterator LPCSTRIt;
typedef xr_vector< string64 > string64Vec; typedef string64Vec::iterator string64It;
typedef xr_vector< xr_string > SStringVec; typedef SStringVec::iterator SStringVecIt;

typedef xr_vector< s8 > S8Vec; typedef S8Vec::iterator S8It;
typedef xr_vector< s8* > LPS8Vec; typedef LPS8Vec::iterator LPS8It;
typedef xr_vector< s16 > S16Vec; typedef S16Vec::iterator S16It;
typedef xr_vector< s16* > LPS16Vec; typedef LPS16Vec::iterator LPS16It;
typedef xr_vector< s32 > S32Vec; typedef S32Vec::iterator S32It;
typedef xr_vector< s32* > LPS32Vec; typedef LPS32Vec::iterator LPS32It;
typedef xr_vector< u8 > U8Vec; typedef U8Vec::iterator U8It;
typedef xr_vector< u8* > LPU8Vec; typedef LPU8Vec::iterator LPU8It;
typedef xr_vector< u16 > U16Vec; typedef U16Vec::iterator U16It;
typedef xr_vector< u16* > LPU16Vec; typedef LPU16Vec::iterator LPU16It;
typedef xr_vector< u32 > U32Vec; typedef U32Vec::iterator U32It;
typedef xr_vector< u32* > LPU32Vec; typedef LPU32Vec::iterator LPU32It;
typedef xr_vector< float > FloatVec; typedef FloatVec::iterator FloatIt;
typedef xr_vector< float* > LPFloatVec; typedef LPFloatVec::iterator LPFloatIt;
typedef xr_vector< int > IntVec; typedef IntVec::iterator IntIt;
typedef xr_vector< int* > LPIntVec; typedef LPIntVec::iterator LPIntIt;

#ifdef __BORLANDC__
typedef xr_vector< AnsiString > AStringVec; typedef AStringVec::iterator AStringIt;
typedef xr_vector< AnsiString* > LPAStringVec; typedef LPAStringVec::iterator LPAStringIt;
#endif

#define xr_stricmp _stricmp


#endif
