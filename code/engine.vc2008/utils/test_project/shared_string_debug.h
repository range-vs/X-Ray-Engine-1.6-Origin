#pragma once

//---------------------------------------------------------------------------

#include <tchar.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef unsigned int u32;
typedef	unsigned	char	u8;
typedef const char* pcstr;
typedef	char	string4096[4096];
typedef	char	string_path[2 * _MAX_PATH];
typedef	char	string512[512];
typedef	char	string32[32];
typedef	unsigned	__int64	u64;
typedef const char* str_c;
typedef std::uint32_t u32mc;
#define		HEADER		16
#define IC inline
#define DEBUG
#define XRCORE_API
#define ECORE_API

#		define VERIFY(expr)				do {static bool ignore_always = false; if (!ignore_always && !(expr)) throw std::exception("critical exception verify!");} while(0)
#	define R_ASSERT3(expr,e2,e3)		do {static bool ignore_always = false; if (!ignore_always && !(expr)) throw std::exception("critical exception r_assert3!");} while(0)
#	define R_ASSERT(expr)				do {static bool ignore_always = false; if (!ignore_always && !(expr)) throw std::exception("critical exception r_assert!");} while(0)
#	define R_ASSERT2(expr,e2)			do {static bool ignore_always = false; if (!ignore_always && !(expr)) throw std::exception("critical exception r_assert2!");} while(0)
#		define VERIFY2(expr,e2)		do {static bool ignore_always = false; if (!ignore_always && !(expr)) throw std::exception("critical exception verify2!");} while(0)


void* mem_alloc(size_t size)
{
	if (0 == size) size = 1;

	void* data = malloc(size);
	if (!data)
		throw std::exception("Error 11");
	//if(!data)
	//	Debug.fatal		(DEBUG_INFO,"Out of memory. Memory request: %d K",size/1024);
	return data;
}
void	mem_free(void* P)
{
	free(P);
}

template <class T>
IC T* xr_alloc(u32 count) { return  (T*)mem_alloc(count * sizeof(T)); }
template <class T>
IC void		xr_free(T*& P) { if (P) { mem_free((void*)P); P = NULL; }; }

static BOOL crc32_ready = FALSE;
static u32	crc32_table[256];					// Lookup table array

inline u32		Reflect(u32 ref, char ch)		// Reflects CRC bits in the lookup table
{
	// Used only by Init_CRC32_Table().

	u32 value(0);

	// Swap bit 0 for bit 7
	// bit 1 for bit 6, etc.
	for (int i = 1; i < (ch + 1); i++)
	{
		if (ref & 1)
			value |= 1 << (ch - i);
		ref >>= 1;
	}
	return value;
}

void			crc32_init()
{
	// Call this function only once to initialize the CRC table.

	// This is the official polynomial used by CRC-32
	// in PKZip, WinZip and Ethernet.
	u32 ulPolynomial = 0x04c11db7;

	// 256 values representing ASCII character codes.
	for (int i = 0; i <= 0xFF; i++)
	{
		crc32_table[i] = Reflect(i, 8) << 24;
		for (int j = 0; j < 8; j++)
			crc32_table[i] = (crc32_table[i] << 1) ^ (crc32_table[i] & (1 << 31) ? ulPolynomial : 0);
		crc32_table[i] = Reflect(crc32_table[i], 32);
	}
}

u32				crc32(const void* P, u32 len)
{
	if (!crc32_ready)
	{
		crc32_init();
		crc32_ready = TRUE;
	}

	// Pass a text string to this function and it will return the CRC.

	// Once the lookup table has been filled in by the two functions above,
	// this function creates all CRCs using only the lookup table.

	// Be sure to use unsigned variables,
	// because negative values introduce high bits
	// where zero bits are required.

	// Start out with all bits set high.
	u32		ulCRC = 0xffffffff;
	u8* buffer = (u8*)P;

	// Perform the algorithm on each character
	// in the string, using the lookup table values.
	while (len--)
		ulCRC = (ulCRC >> 8) ^ crc32_table[(ulCRC & 0xFF) ^ *buffer++];

	// Exclusive OR the result with the beginning value.
	return ulCRC ^ 0xffffffff;
}

u32				crc32(const void* P, u32 len, u32 starting_crc)
{
	if (!crc32_ready)
	{
		crc32_init();
		crc32_ready = TRUE;
	}

	u32		ulCRC = 0xffffffff ^ starting_crc;
	u8* buffer = (u8*)P;

	while (len--)
		ulCRC = (ulCRC >> 8) ^ crc32_table[(ulCRC & 0xFF) ^ *buffer++];

	return ulCRC ^ 0xffffffff;
}

u32				path_crc32(const char* path, u32 len)
{
	if (!crc32_ready)
	{
		crc32_init();
		crc32_ready = TRUE;
	}

	u32		ulCRC = 0xffffffff;
	u8* buffer = (u8*)path;

	while (len--)
	{
		const u8 c = *buffer;
		if (c != '/' && c != '\\')
		{
			ulCRC = (ulCRC >> 8) ^ crc32_table[(ulCRC & 0xFF) ^ *buffer];
		}

		++buffer;
	}

	return ulCRC ^ 0xffffffff;
}

#pragma pack(push, 4)
#pragma warning(push)
#pragma warning(disable : 4200)
struct	str_value
{
	u32mc					dwReference;
	u32mc					dwLength;
	u32mc					dwCRC;
	str_value* next;
	char* value;

	void print_size()
	{
		cout << sizeof(dwReference) << endl;
		cout << sizeof(dwLength) << endl;
		cout << sizeof(dwCRC) << endl;
		cout << sizeof(next) << endl;
		//cout << sizeof(value) << endl;
		cout << "Total: " << sizeof(str_value) << endl;
	}
	//char* value;
};
#pragma warning(pop)

class xrCriticalSection
{
public:
	class raii
	{
	public:
		raii(xrCriticalSection* critical_section)
			: critical_section(critical_section)
		{
			VERIFY(critical_section);
			critical_section->Enter();
		}
		~raii()
		{
			critical_section->Leave();
		}

	private:
		xrCriticalSection* critical_section;
	};

private:
	xrCriticalSection(xrCriticalSection const& copy) {}; //noncopyable
	void* pmutex;

public:
	xrCriticalSection()
	{
		pmutex = xr_alloc<CRITICAL_SECTION>(1);
		InitializeCriticalSection((CRITICAL_SECTION*)pmutex);
	}

	~xrCriticalSection()
	{
		DeleteCriticalSection((CRITICAL_SECTION*)pmutex);
		xr_free(pmutex);
	}

	void	Enter()
	{
		EnterCriticalSection((CRITICAL_SECTION*)pmutex);
	}

	void	Leave()
	{
		LeaveCriticalSection((CRITICAL_SECTION*)pmutex);
	}

	BOOL	TryEnter()
	{
		return TryEnterCriticalSection((CRITICAL_SECTION*)pmutex);
	}


};

struct str_container_impl
{
	static const u32 buffer_size = 1024 * 256;
	str_value* buffer[buffer_size];
	int              num_docs;

	str_container_impl()
	{
		num_docs = 0;
		ZeroMemory(buffer, sizeof(buffer));
	}

	str_value* find(str_value* value, const char* str)
	{
		str_value* candidate = buffer[value->dwCRC % buffer_size];
		while (candidate)
		{
			if (candidate->dwCRC == value->dwCRC &&
				candidate->dwLength == value->dwLength &&
				!memcmp(candidate->value, str, value->dwLength))
			{
				return candidate;
			}

			candidate = candidate->next;
		}

		return NULL;
	}

	void			 insert(str_value* value)
	{
		str_value** element = &buffer[value->dwCRC % buffer_size];
		value->next = *element;
		*element = value;
	}

	void			 clean()
	{
		for (u32 i = 0; i < buffer_size; ++i)
		{
			str_value** current = &buffer[i];

			while (*current != NULL)
			{
				str_value* value = *current;
				if (!value->dwReference)
				{
					*current = value->next;
					xr_free(value);
				}
				else
				{
					current = &value->next;
				}
			}
		}
	}

	void			 verify()
	{
		for (u32 i = 0; i < buffer_size; ++i)
		{
			str_value* value = buffer[i];
			while (value)
			{
				u32			crc = crc32(value->value, value->dwLength);
				string32	crc_str;
				R_ASSERT3(crc == value->dwCRC, "CorePanic: read-only memory corruption (shared_strings)", itoa(value->dwCRC, crc_str, 16));
				R_ASSERT3(value->dwLength == strlen(value->value), "CorePanic: read-only memory corruption (shared_strings, internal structures)", value->value);
				value = value->next;
			}
		}
	}

	void			dump(FILE* f) const
	{
		for (u32 i = 0; i < buffer_size; ++i)
		{
			str_value* value = buffer[i];
			while (value)
			{
				fprintf(f, "ref[%4d]-len[%3d]-crc[%8X] : %s\n", value->dwReference, value->dwLength, value->dwCRC, value->value);
				value = value->next;
			}
		}
	}

	/*void			dump (IWriter* f) const
	{
		for ( u32 i=0; i<buffer_size; ++i )
		{
			str_value* value = buffer[i];
			string4096		temp;
			while ( value )
			{
				xr_sprintf	(temp, sizeof(temp), "ref[%4d]-len[%3d]-crc[%8X] : %s\n", value->dwReference, value->dwLength, value->dwCRC, value->value);
				f->w_string	(temp);
				value		= value->next;
			}
		}
	}*/

	int				stat_economy()
	{
		int				counter = 0;
		for (u32 i = 0; i < buffer_size; ++i)
		{
			str_value* value = buffer[i];
			while (value)
			{
				counter -= sizeof(str_value);
				counter += (value->dwReference - 1) * (value->dwLength + 1);
				value = value->next;
			}
		}

		return counter;
	}
};

class	str_container
{
private:
	xrCriticalSection					cs;
	str_container_impl* impl;
public:
	str_container() :cs()
	{
		impl = new str_container_impl();
	}

	str_value* dock(str_c value)
	{
		if (0 == value)				return 0;

		cs.Enter();

		/*#ifdef DEBUG_MEMORY_MANAGER
			Memory.stat_strdock			++	;
		#endif // DEBUG_MEMORY_MANAGER */

		str_value* result = 0;

		// calc len
		u32		s_len = strlen(value);
		u32		s_len_with_zero = (u32)s_len + 1;
		VERIFY(sizeof(str_value) + s_len_with_zero < 4096);

		// setup find structure
		char	header[sizeof(str_value)];
		str_value* sv = (str_value*)header;
		sv->dwReference = 0;
		sv->dwLength = s_len;
		sv->dwCRC = crc32(value, s_len);

		// search
		result = impl->find(sv, value);

#ifdef DEBUG
		bool is_leaked_string = !strcmp(value, "enter leaked string here");
#endif //DEBUG

		// it may be the case, string is not found or has "non-exact" match
		if (0 == result
#ifdef DEBUG
			|| is_leaked_string
#endif //DEBUG
			) {

			result = (str_value*)mem_alloc(sizeof(str_value));  // range fix
			result->value = (char*)mem_alloc(s_len_with_zero); // range fix

#ifdef DEBUG
			static int num_leaked_string = 0;
			if (is_leaked_string)
			{
				++num_leaked_string;
				//DEBUG_MESSAGE("leaked_string: %d 0x%08x", num_leaked_string, result);
			}
#endif // DEBUG

			result->dwReference = 0;
			result->dwLength = sv->dwLength;
			result->dwCRC = sv->dwCRC;
			//DEBUG_MESSAGE((string("value -> ") + value).c_str());
			CopyMemory(result->value, value, s_len_with_zero);
			/*DEBUG_MESSAGE((string("result->value after -> ") + result->value).c_str());
			int mem = sizeof(*result);
			stringstream ss;
			ss << mem;
			DEBUG_MESSAGE((string("mem: ") + ss.str()).c_str());*/

			impl->insert(result);
		}
		cs.Leave();

		return	result;
	}

	void		clean()
	{
		cs.Enter();
		impl->clean();
		cs.Leave();
	}

	void		verify()
	{
		cs.Enter();
		impl->verify();
		cs.Leave();
	}

	void		dump()
	{
		cs.Enter();
		FILE* F = fopen("d:\\$str_dump$.txt", "w");
		impl->dump(F);
		fclose(F);
		cs.Leave();
	}

	/*void		dump	(IWriter* W)
	{
		cs.Enter	();
		impl->dump  (W);
		cs.Leave	();
	}*/

	u32			stat_economy()
	{
		cs.Enter();
		int				counter = 0;
		counter -= sizeof(*this);
		counter += impl->stat_economy();
		cs.Leave();
		return			u32(counter);
	}

	~str_container()
	{
		clean();
		//dump ();
		delete impl;
	}
};

str_container* g_pStringContainer = new str_container();


template <class T>
struct _flags {
public:
	typedef T			TYPE;
	typedef _flags<T>	Self;
	typedef Self& SelfRef;
	typedef const Self& SelfCRef;
public:
	T 	flags;

	IC	TYPE	get()									const { return flags; }
	IC	SelfRef	zero() { flags = T(0);	return *this; }
	IC	SelfRef	one() { flags = T(-1);	return *this; }
	IC	SelfRef	invert() { flags = ~flags;		return *this; }
	IC	SelfRef	invert(const Self& f) { flags = ~f.flags;	return *this; }
	IC	SelfRef	invert(const T mask) { flags ^= mask;		return *this; }
	IC	SelfRef	assign(const Self& f) { flags = f.flags;	return *this; }
	IC	SelfRef	assign(const T mask) { flags = mask;		return *this; }
	IC	SelfRef	set(const T mask, BOOL value) { if (value) flags |= mask; else flags &= ~mask; return *this; }
	IC 	BOOL	is(const T mask)						const { return mask == (flags & mask); }
	IC 	BOOL	is_any(const T mask)						const { return BOOL(!!(flags & mask)); }
	IC 	BOOL	test(const T mask)						const { return BOOL(!!(flags & mask)); }
	IC 	SelfRef	_or(const T mask) { flags |= mask;			return *this; }
	IC 	SelfRef	_or(const Self& f, const T mask) { flags = f.flags | mask;	return *this; }
	IC 	SelfRef	_and(const T mask) { flags &= mask;			return *this; }
	IC 	SelfRef	_and(const Self& f, const T mask) { flags = f.flags & mask;	return *this; }
	IC 	BOOL	equal(const Self& f) 			  		const { return flags == f.flags; }
	IC 	BOOL	equal(const Self& f, const T mask) 		const { return (flags & mask) == (f.flags & mask); }
};

typedef _flags<u8>	Flags8;		typedef _flags<u8>	flags8;

BOOL _parse(LPSTR dest, LPCSTR src)
{
	BOOL bInsideSTR = false;
	if (src)
	{
		while (*src)
		{
			if (isspace((u8)*src))
			{
				if (bInsideSTR)
				{
					*dest++ = *src++;
					continue;
				}
				while (*src && isspace(*src))
				{
					++src;
				}
				continue;
			}
			else if (*src == '"')
			{
				bInsideSTR = !bInsideSTR;
			}
			*dest++ = *src++;
		}
	}
	*dest = 0;
	return bInsideSTR;
}

int	_GetItemCount(LPCSTR src, char separator = ',')
{
	u32		cnt = 0;
	if (src && src[0]) {
		LPCSTR	res = src;
		LPCSTR	last_res = res;
		while (0 != (res = strchr(res, separator)))
		{
			res++;
			last_res = res;
			cnt++;
			if (res[0] == separator) break;
		}
		if (strlen(last_res)) cnt++;
	}
	return		cnt;
}

inline char* strconcat(int dest_sz, char* dest, const char* S1, const char* S2)
{
	strcpy_s(dest, dest_sz, S1);
	strcat_s(dest, dest_sz, S2);
	return  dest;
}

LPSTR _TrimLeft(LPSTR str)  // range fix
{
	LPSTR p = str;
	while (*p && (u8(*p) <= u8(' '))) p++;
	if (p != str)
	{
		LPSTR t = str;
		for (; *p; t++, p++)
			*t = *p;
		*t = 0;
	}
	return str;
}

LPSTR _TrimRight(LPSTR str)
{
	LPSTR p = str + strlen(str);
	while ((p != str) && (u8(*p) <= u8(' '))) p--;
	*(++p) = 0;
	return str;
}

LPSTR _Trim(LPSTR str)
{
	_TrimLeft(str);
	_TrimRight(str);
	return str;
}

LPCSTR _SetPos(LPCSTR src, u32 pos, char separator)
{
	LPCSTR	res = src;
	u32		p = 0;
	while ((p < pos) && (0 != (res = strchr(res, separator))))
	{
		res++;
		p++;
	}
	return		res;
}


LPCSTR _CopyVal(LPCSTR src, LPSTR dst, char separator)
{
	LPCSTR	p;
	size_t	n;
	p = strchr(src, separator);
	n = (p != NULL) ? (p - src) : strlen(src);
	strncpy(dst, src, n);
	dst[n] = 0;
	return		dst;
}

LPSTR _GetItem(LPCSTR src, int index, LPSTR dst, u32 const dst_size, char separator, LPCSTR def, bool trim)
{
	LPCSTR	ptr;
	ptr = _SetPos(src, index, separator);
	if (ptr)	_CopyVal(ptr, dst, separator);
	else	strcpy_s(dst, dst_size, def);
	if (trim)	_Trim(dst);
	return		dst;
}


template <int count>
inline LPSTR	    		_GetItem(LPCSTR src, int index, char(&dst)[count], char separator = ',', LPCSTR def = "", bool trim = true)
{
	return					_GetItem(src, index, dst, count, separator, def, trim);
}

class shared_str
{
	str_value* p_;

protected:
	void _dec()
	{
		if (0 == p_)
			return;
		p_->dwReference--;
		if (0 == p_->dwReference)
			p_ = 0;
	}

public:
	void _set(pcstr rhs)
	{
		str_value* v = g_pStringContainer->dock(rhs);
		if (0 != v)
			v->dwReference++;
		_dec();
		p_ = v;
	}
	void _set(shared_str const& rhs)
	{
		str_value* v = rhs.p_;
		if (0 != v)
			v->dwReference++;
		_dec();
		p_ = v;
	}
	const str_value* _get() const { return p_; }
public:
	shared_str() { p_ = 0; }
	shared_str(pcstr rhs)
	{
		p_ = 0;
		_set(rhs);
	}
	shared_str(shared_str const& rhs)
	{
		p_ = 0;
		_set(rhs);
	}
	~shared_str() { _dec(); }
	// assignment & accessors
	shared_str& operator=(pcstr rhs)
	{
		_set(rhs);
		return (shared_str&)*this;
	}
	shared_str& operator=(shared_str const& rhs)
	{
		_set(rhs);
		return (shared_str&)*this;
	}
	// XXX tamlin: Remove operator*(). It may be convenient, but it's dangerous. Use
	pcstr operator*() const { return p_ ? p_->value : 0; }
	bool operator!() const { return p_ == 0; }
	char operator[](size_t id) { return p_->value[id]; }
	pcstr c_str() const { return p_ ? p_->value : 0; }
	// misc func
	u32 size() const
	{
		if (0 == p_)
			return 0;
		else
			return p_->dwLength;
	}
	void swap(shared_str& rhs)
	{
		str_value* tmp = p_;
		p_ = rhs.p_;
		rhs.p_ = tmp;
	}
	bool equal(const shared_str& rhs) const { return (p_ == rhs.p_); }
	shared_str& __cdecl printf(const char* format, ...)
	{
		string4096 buf;
		va_list p;
		va_start(p, format);
		int vs_sz = vsnprintf(buf, sizeof(buf) - 1, format, p);
		buf[sizeof(buf) - 1] = 0;
		va_end(p);
		if (vs_sz)
			_set(buf);
		return (shared_str&)*this;
	}
};

IC bool operator	==	(shared_str const& a, shared_str const& b) { return a._get() == b._get(); }

#pragma pack(pop)


///-----------------------SHARED_STR-------------------///

class CInifile
{
public:
	struct	Item
	{
		shared_str	first;
		shared_str	second;
		//Item() : first(NULL), second(NULL){};
	};
	typedef std::vector<Item>				Items;
	typedef Items::const_iterator		SectCIt;
	typedef Items::iterator				SectIt_;
	struct	Sect
	{
		shared_str		Name;
		Items			Data;

		BOOL			line_exist(LPCSTR L, LPCSTR* val = 0);
	};
	typedef	vector<Sect*>		Root;
	typedef Root::iterator			RootIt;
	typedef Root::const_iterator	RootCIt;

	Root			DATA;

	enum { eSaveAtEnd = (1 << 0), eReadOnly = (1 << 1), eOverrideNames = (1 << 2), };
	Flags8			m_flags;

	struct sect_pred
	{
		bool operator()(const CInifile::Sect* x, LPCSTR val)
		{
			return strcmp(x->Name.c_str(), val) < 0;
		}
	};

	struct item_pred
	{
		bool operator()(const CInifile::Item& x, LPCSTR val)
		{
			if ((!x.first) || (!val))
				return x.first.c_str() < val;
			else
				return strcmp(x.first.c_str(), val) < 0;
		}
	};

	static void	insert_item(CInifile::Sect* tgt, const CInifile::Item& I)
	{
		CInifile::SectIt_	sect_it = std::lower_bound(tgt->Data.begin(), tgt->Data.end(), I.first.c_str(), item_pred());
		if (sect_it != tgt->Data.end() && sect_it->first.equal(I.first))
		{
			sect_it->second = I.second;
		}
		else
		{
			tgt->Data.push_back(I);
		}
	}


	Sect& r_section(const shared_str& S)const
	{
		return	r_section(S);
	}

	Sect& r_section(LPCSTR S)const
	{
		char	section[256];
		strcpy_s(section, sizeof(section), S);
		_strlwr(section);
		RootCIt I = std::lower_bound(DATA.begin(), DATA.end(), section, sect_pred());
		/*if (!(I!=DATA.end() && xr_strcmp(*(*I)->Name,section)==0))
		{
			Debug.fatal			(DEBUG_INFO,"Can't open section '%s'. Please attach [*.ini_log] file to your bug report",S);
		}*/
		return	**I;
	}

	LPCSTR	r_string(LPCSTR S, LPCSTR L)const
	{
		Sect const& I = r_section(S);
		SectCIt	A = std::lower_bound(I.Data.begin(), I.Data.end(), L, item_pred());
		if (A != I.Data.end() && A->first == L)
			return A->second.c_str();
		/*else
			Debug.fatal(DEBUG_INFO,"Can't find variable %s in [%s]",L,S); */
		return 0;
	}

	void Load(ifstream& F, LPCSTR path)
	{
		//R_ASSERT(F);
		string4096	str;
		string4096	str2;
		Sect* Current = NULL;

		BOOL bInsideSTR = FALSE;
		while (!F.eof())
		{
			string tmp;
			getline(F, tmp, '\n');
			strcpy(str, tmp.c_str());
			_Trim(str);
			LPSTR comm = strchr(str, ';');
			LPSTR comm_1 = strchr(str, '/');


			if (comm_1 && (*(comm_1 + 1) == '/') && ((!comm) || (comm && (comm_1 < comm))))
			{
				comm = comm_1;
			}

			LPSTR comment = 0;
			if (comm)
			{
				char quot = '"';
				bool in_quot = false;
				LPCSTR q1 = strchr(str, quot);
				if (q1 && q1 < comm)
				{
					LPCSTR q2 = strchr(++q1, quot);
					if (q2 && q2 > comm)
						in_quot = true;
				}

				if (!in_quot)
				{
					*comm = 0;
					comment = comm + 1;
				}
			}

			if (str[0] && (str[0] == '#') && strstr(str, "#include")) //handle includes
			{
				string_path		inc_name;
				//R_ASSERT		(path&&path[0]);
				if (_GetItem(str, 1, inc_name, '"'))
				{
					string_path	fn, inc_path, folder;
					strconcat(sizeof(fn), fn, path, inc_name);
					_splitpath(fn, inc_path, folder, 0, 0);
					strcat_s(inc_path, sizeof(inc_path), folder);
					{
						//IReader* I 	= FS.r_open(fn);
						ifstream I(fn);
						//R_ASSERT3(I,"Can't find include file:", inc_name);
						Load(I, inc_path);
						//FS.r_close	(I);
					}
				}
			}
			else if (str[0] && (str[0] == '[')) //new section ?
			{
				// insert previous filled section
				if (Current)
				{
					//store previous section
					RootIt I = std::lower_bound(DATA.begin(), DATA.end(), Current->Name.c_str(), sect_pred());
					//if ((I!=DATA.end())&&((*I)->Name==Current->Name))
					 //	Debug.fatal(DEBUG_INFO,"Duplicate section '%s' found.",*Current->Name);

					DATA.insert(I, Current);
				}
				Current = new Sect();
				//Current->Name = NULL;
				// start new section
				//R_ASSERT3(strchr(str,']'),"Bad ini section found: ",str);
				LPCSTR inherited_names = strstr(str, "]:");
				if (0 != inherited_names)
				{
					//VERIFY2				(m_flags.test(eReadOnly),"Allow for readonly mode only.");
					inherited_names += 2;
					u32 cnt = _GetItemCount(inherited_names);
					u32 total_count = 0;
					u32 k = 0;
					for (k = 0; k < cnt; ++k) {
						string512	tmp;
						_GetItem(inherited_names, k, tmp);
						Sect& inherited_section = r_section(tmp);
						total_count += inherited_section.Data.size();
					}

					Current->Data.reserve(Current->Data.size() + total_count);

					for (k = 0; k < cnt; ++k)
					{
						string512	tmp;
						_GetItem(inherited_names, k, tmp);
						Sect& inherited_section = r_section(tmp);
						for (SectIt_ it = inherited_section.Data.begin(); it != inherited_section.Data.end(); it++)
							insert_item(Current, *it);
					}
				}
				*strchr(str, ']') = 0;
				Current->Name = _strlwr(str + 1);
			}
			else // name = value
			{
				if (Current)
				{
					string4096			value_raw;
					char* name = str;
					char* t = strchr(name, '=');
					if (t)
					{
						*t = 0;
						_Trim(name);
						++t;
						strcpy_s(value_raw, sizeof(value_raw), t);
						bInsideSTR = _parse(str2, value_raw);
						/*if(bInsideSTR)//multiline str value
						{
							while(bInsideSTR)
							{
								strcat_s		(value_raw, sizeof(value_raw),"\r\n");
								string4096		str_add_raw;
								string tmp;
								getline(F, tmp, '\n');
								strcpy(str_add_raw, tmp.c_str());
								//F->r_string		(str_add_raw, sizeof(str_add_raw));
								//R_ASSERT2		(
								 //	xr_strlen(value_raw) + xr_strlen(str_add_raw) < sizeof(value_raw),
								 //	make_string(
								 //		"Incorrect inifile format: section[%s], variable[%s]. Odd number of quotes (\") found, but should be even.",
								 //		Current->Name.c_str(),
								 //		name
								 //	)
								//);
								strcat_s		(value_raw, sizeof(value_raw),str_add_raw);
								bInsideSTR		= _parse(str2, value_raw);
								if(bInsideSTR)
								{
									if( is_empty_line_now(F) )
										xr_strcat		(value_raw, sizeof(value_raw),"\r\n");
								}
							}
						}*/
					}
					else
					{
						_Trim(name);
						str2[0] = 0;
					}

					Item		I;
					I.first = (name[0] ? name : "");
					I.second = (str2[0] ? str2 : "");

					if (m_flags.test(eReadOnly))
					{
						if (*I.first)
							insert_item(Current, I);
					}
					else
					{
						if (*I.first || *I.second)
							insert_item(Current, I);
					}
				}
			}
		}
		if (Current)
		{
			RootIt I = std::lower_bound(DATA.begin(), DATA.end(), Current->Name.c_str(), sect_pred());
			/*if ((I!=DATA.end())&&((*I)->Name==Current->Name))
				Debug.fatal(DEBUG_INFO,"Duplicate section '%s' found.",*Current->Name); */
			DATA.insert(I, Current);
		}
	}

};


//---------------------------------------------------------------------------
void test()
{
	CInifile cIni;
	std::string _path = "E:\\Program Files\\STLK-COP\\";
	std::transform(_path.begin(), _path.end(), _path.begin(), std::tolower);
	string path = _path + "game_levels.ltx";
	ifstream f(path.c_str());
	cIni.Load(f, _path.c_str());
}
//---------------------------------------------------------------------------
