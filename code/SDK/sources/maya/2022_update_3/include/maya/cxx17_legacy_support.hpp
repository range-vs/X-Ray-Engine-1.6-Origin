#pragma once
#ifndef MAYA_CXX17_LEGACY_SUPPORT
#define MAYA_CXX17_LEGACY_SUPPORT
// ===========================================================================
// Copyright 2019 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license
// agreement provided at the time of installation or download, or which
// otherwise accompanies this software in either electronic or hard copy form.
// ===========================================================================

/*
	\brief Support header to compile with C++ 17
	All Maya API headers are already C++ 17 compatible.
	However, some thrird party libraries may not be ready.

	This headers allows plugins to use some legacy code with C++ 17 removed features :
		- `register` keyword
		- `throw`, dynamic exeception specifier on function signature
		- std::unary_function, std::binary_function
		- std::bind1st, std::bind2nd, bindder1st, binder2nd

	Usage example :
	```
		#include <maya/cxx17_enter_legacy_scope.hpp>
			// Third party headers that does not compile well with C++ 17
			#include <boost/...>
			#include <Alembic/...>
		#include <maya/cxx17_exit_legacy_scope.hpp>
	```

	\warning This header is provided as an temproary workaround during migration.
			 Please consider update your codebase and dependencies.

	\warning This header does not work for GCC 7+ with -std=c++17,
			 because it treat removed features as hard error.
*/

#include <functional>

#if defined(__clang__)
// As of Clang 6.0, all these diagnostic are supported
#define MAYA_CXX17_PUSH_WARN _Pragma("clang diagnostic push")
#define MAYA_CXX17_POP_WARN _Pragma("clang diagnostic pop")
#define MAYA_CXX17_DISABLE_REGISTER_WARNING _Pragma("clang diagnostic ignored \"-Wregister\"")
#define MAYA_CXX17_DISABLE_DYN_EXC_SPEC_WARNING _Pragma("clang diagnostic ignored \"-Wdynamic-exception-spec\"")
#elif defined(_MSC_VER)
#define MAYA_CXX17_PUSH_WARN __pragma(warning(push))
#define MAYA_CXX17_POP_WARN __pragma(warning(pop))
#define MAYA_CXX17_DISABLE_REGISTER_WARNING __pragma(warning(disable: 5033))
#define MAYA_CXX17_DISABLE_DYN_EXC_SPEC_WARNING __pragma(warning(disable: 5040 4290))
#elif defined(__GNUC__)
#define MAYA_CXX17_PUSH_WARN _Pragma("GCC diagnostic push")
#define MAYA_CXX17_POP_WARN _Pragma("GCC diagnostic pop")
    #if (__GNUC__ >= 7)
        #define MAYA_CXX17_DISABLE_REGISTER_WARNING _Pragma("GCC diagnostic ignored \"-Wregister\"")
    #else
        // GCC 6 generates no warning / error for 'register' keyword 
        #define MAYA_CXX17_DISABLE_REGISTER_WARNING
    #endif
    #define MAYA_CXX17_DISABLE_DYN_EXC_SPEC_WARNING
    // There is nothing we can do about this, it is a hard error start from GCC 7.x
#else
#define MAYA_CXX17_DISABLE_REGISTER_WARNING
#define MAYA_CXX17_DISABLE_DYN_EXC_SPEC_WARNING 
#endif

#if (__cplusplus >= 201703L) || (defined(_MSVC_LANG) && (_MSVC_LANG >= 201703L))
// Is c++ 17 enabled on current compiler
#define MAYA_CXX17_ENABLED
#endif

#if defined(MAYA_CXX17_ENABLED) || (defined(_HAS_AUTO_PTR_ETC) && !_HAS_AUTO_PTR_ETC)

// Neither libstdc++(GCC) nor libc++(Clang) have removed binary_function etc yet
// This macro does not imply unary_function being removed as of libc++ 9.0
// !defined(_LIBCPP_ENABLE_MAYA_CXX17_REMOVED_FEATURES)
#if !defined(__GLIBCXX__) && !defined(_LIBCPP_VERSION) && !(defined(_HAS_AUTO_PTR_ETC) && _HAS_AUTO_PTR_ETC)
// Defined if STL have std::binary_function etc removed
#define MAYA_CXX17_STL_NO_DEPRECATED_UNARY_FUNCTION
#endif

// libc++ / msvc have removed std::bind1st etc if c++17 is enabled
#if !defined(__GLIBCXX__) && !defined(_LIBCPP_ENABLE_MAYA_CXX17_REMOVED_FEATURES) && !(defined(_HAS_AUTO_PTR_ETC) && _HAS_AUTO_PTR_ETC)
// Defined if STL have std::bind1st etc removed
#define MAYA_CXX17_STL_NO_DEPRECATED_BINDER
#endif

#endif

// std::unary_function / std::binary_function
#if defined(MAYA_CXX17_STL_NO_DEPRECATED_UNARY_FUNCTION)
namespace std{
    template <typename Arg1, typename Result>
    struct unary_function
    {
        typedef Arg1 argument_type;
        typedef Result result_type;
    };

    template <typename Arg1, typename Arg2, typename Result>
    struct binary_function
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
}
#endif // MAYA_CXX17_STL_NO_DEPRECATED_UNARY_FUNCTION

// std::bind1st / std::bind2nd / bindder1st / binder2nd
#if defined(MAYA_CXX17_STL_NO_DEPRECATED_BINDER)
namespace std{
	template< class Fn >
	class binder1st : public unary_function<typename Fn::second_argument_type, typename Fn::result_type> {
	protected:
		Fn op;
		typename Fn::first_argument_type value;
	public:
		binder1st(const Fn& fn, const typename Fn::first_argument_type& value)
		: op(fn), value(value)
		{}

		typename Fn::result_type  operator()(const typename Fn::second_argument_type& x) const
		{
			return op(value, x);
		}

		typename Fn::result_type operator()(typename Fn::second_argument_type& x) const
		{
			return op(value, x);
		}
	};

	template< class Fn >
	class binder2nd : public std::unary_function<typename Fn::first_argument_type, typename Fn::result_type> {
	protected:
		Fn op;
		typename Fn::second_argument_type value;
	public:
		binder2nd(const Fn& fn, const typename Fn::second_argument_type& value)
		: op(fn), value(value)
		{}

		typename Fn::result_type  operator()(const typename Fn::first_argument_type& x) const
		{
			return op(x, value);
		}

		typename Fn::result_type operator()(typename Fn::first_argument_type& x) const
		{
			return op(x, value);
		}
	};

	template< class F, class T >
	binder1st<F> bind1st( const F& f, const T& x )
	{
		return binder1st<F>(f,x);
	}

	template< class F, class T >
	binder2nd<F> bind2nd( const F& f, const T& x )
	{
		return binder2nd<F>(f,x);
	}	
}
#endif // MAYA_CXX17_STL_NO_DEPRECATED_BINDER
#endif // MAYA_CXX17_LEGACY_SUPPORT