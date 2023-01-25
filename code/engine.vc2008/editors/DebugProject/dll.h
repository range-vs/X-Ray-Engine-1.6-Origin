#ifdef IS_DLL
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif


class DLL test_dll
{
public:
	int test();
};

extern DLL test_dll dll;
