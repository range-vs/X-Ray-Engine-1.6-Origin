#include "cxx17_legacy_support.hpp"
#define MAYA_CXX_17_ENTER_LEGACY_SCOPE
#if defined(MAYA_CXX17_ENABLED)
	MAYA_CXX17_PUSH_WARN
	MAYA_CXX17_DISABLE_REGISTER_WARNING
	MAYA_CXX17_DISABLE_DYN_EXC_SPEC_WARNING

	// Duplicate definition of BOOST_NO_AUTO_PTR in user.hpp & _HAS_AUTO_PTR_ETC
	#if defined(_MSC_VER) && defined(_HAS_AUTO_PTR_ETC) && !_HAS_AUTO_PTR_ETC
		#pragma warning(disable: 4005)
	#endif
	#if defined(__APPLE__)
		#pragma clang diagnostic ignored "-Wmacro-redefined"
	#endif

	// GCC 7+ generate hard error on dynamic exception spec, which are used in Abc
#endif
