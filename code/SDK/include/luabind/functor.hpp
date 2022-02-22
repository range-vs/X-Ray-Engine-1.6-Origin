//// Copyright (c) 2003 Daniel Wallin and Arvid Norberg
//
//// Permission is hereby granted, free of charge, to any person obtaining a
//// copy of this software and associated documentation files (the "Software"),
//// to deal in the Software without restriction, including without limitation
//// the rights to use, copy, modify, merge, publish, distribute, sublicense,
//// and/or sell copies of the Software, and to permit persons to whom the
//// Software is furnished to do so, subject to the following conditions:
//
//// The above copyright notice and this permission notice shall be included
//// in all copies or substantial portions of the Software.
//
//// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
//// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
//// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
//// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
//// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
//// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
//// OR OTHER DEALINGS IN THE SOFTWARE.
//
//#if !BOOST_PP_IS_ITERATING
//
//#ifndef LUABIND_FUNCTOR_HPP_INCLUDED
//#define LUABIND_FUNCTOR_HPP_INCLUDED
//
//#include <boost/preprocessor/repeat.hpp>
//#include <boost/preprocessor/repetition/enum_params.hpp>
//#include <boost/preprocessor/repetition/enum_params.hpp>
//#include <boost/preprocessor/iteration/iterate.hpp>
//#include <boost/type_traits/is_void.hpp>
//#include <boost/mpl/if.hpp>
//
//#include <luabind/prefix.hpp>
//#include <luabind/config.hpp>
//#include <luabind/detail/policy.hpp>
//#include <luabind/detail/convert_to_lua.hpp>
//#include <luabind/detail/pcall.hpp>
//#include <luabind/error.hpp>
//#include <luabind/detail/stack_utils.hpp>
//
//namespace luabind
//{
//template<class Ret>
//class functor;
//
//	namespace detail
//	{
//
//		struct functor_from;
//
//
//		// if the proxy_functor_caller returns non-void
//			template<class Ret, class Tuple>
//			class proxy_functor_caller
//			{
////			template<class T> friend class luabind::functor;
//			public:
//
//				proxy_functor_caller(luabind::functor<Ret>* o, const Tuple args)
//					: m_func(o)
//					, m_args(args)
//					, m_called(false)
//				{
//				}
//
//				proxy_functor_caller(const proxy_functor_caller& rhs)
//					: m_func(rhs.m_func)
//					, m_args(rhs.m_args)
//					, m_called(rhs.m_called)
//				{
//					rhs.m_called = true;
//				}
//
//				~proxy_functor_caller()
//				{
//					if (m_called) return;
//
//					m_called = true;
//					lua_State* L = m_func->lua_state();
//
//					// get the function
//					m_func->pushvalue();
//
//					push_args_from_tuple<1>::apply(L, m_args);
//					if (pcall(L, boost::tuples::length<Tuple>::value, 0))
//					{ 
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw luabind::error(L);
//#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "the lua function threw an error and exceptions are disabled."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//				}
//
//				operator Ret()
//				{
//					typename default_policy::template generate_converter<Ret, lua_to_cpp>::type converter;
//
//					m_called = true;
//					lua_State* L = m_func->lua_state();
//#ifndef LUABIND_NO_ERROR_CHECKING
//					if (L == 0)
//					{
//	#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L); 
//	#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "tried to call uninitialized functor object."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//	#endif
//					}
//#endif
//
//
//					detail::stack_pop p(L, 1); // pop the return value
//
//					// get the function
//					m_func->pushvalue();
//
//					push_args_from_tuple<1>::apply(L, m_args);
//					if (pcall(L, boost::tuples::length<Tuple>::value, 1))
//					{ 
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw luabind::error(L);
//#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "the lua function threw an error and exceptions are disabled."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//
//#ifndef LUABIND_NO_ERROR_CHECKING
//
//					if (converter.match(L, LUABIND_DECORATE_TYPE(Ret), -1) < 0)
//					{
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw cast_failed(L, LUABIND_TYPEID(Ret));
//#else
//						cast_failed_callback_fun e = get_cast_failed_callback();
//						if (e) e(L, LUABIND_TYPEID(Ret));
//
//						assert(0 && "the lua function's return value could not be converted."
//								"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//#endif
//					return converter.apply(L, LUABIND_DECORATE_TYPE(Ret), -1);
//				}
//
//				template<class Policies>
//				Ret operator[](const Policies& p)
//				{
//					typedef typename detail::find_conversion_policy<0, Policies>::type converter_policy;
//					typename converter_policy::template generate_converter<Ret, lua_to_cpp>::type converter;
//
//					m_called = true;
//					lua_State* L = m_func->lua_state();
//#ifndef LUABIND_NO_ERROR_CHECKING
//					if (L == 0)
//					{
//	#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L); 
//	#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "tried to call uninitialized functor object."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//	#endif
//					}
//#endif
//
//					detail::stack_pop popper(L, 1); // pop the return value
//
//					// get the function
//					m_func->pushvalue();
//
//					detail::push_args_from_tuple<1>::apply(L, m_args, p);
//					if (pcall(L, boost::tuples::length<Tuple>::value, 1))
//					{ 
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L);
//#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "the lua function threw an error and exceptions are disabled."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//
//#ifndef LUABIND_NO_ERROR_CHECKING
//
//					if (converter.match(L, LUABIND_DECORATE_TYPE(Ret), -1) < 0)
//					{
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw cast_failed(L, LUABIND_TYPEID(Ret));
//#else
//						cast_failed_callback_fun e = get_cast_failed_callback();
//						if (e) e(L, LUABIND_TYPEID(Ret));
//
//						assert(0 && "the lua function's return value could not be converted."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//#endif
//					return converter.apply(L, LUABIND_DECORATE_TYPE(Ret), -1);
//				}
//
//			private:
//
//				luabind::functor<Ret>* m_func;
//				Tuple m_args;
//				mutable bool m_called;
//
//			};
//
//		// if the proxy_member_caller returns void
//			template<class Tuple>
//			class proxy_functor_void_caller
//			{
////			template<class T> friend class luabind::functor;
//			public:
//
//				proxy_functor_void_caller(luabind::functor<void>* o, const Tuple args)
//					: m_func(o)
//					, m_args(args)
//					, m_called(false)
//				{
//				}
//
//				proxy_functor_void_caller(const proxy_functor_void_caller& rhs)
//					: m_func(rhs.m_func)
//					, m_args(rhs.m_args)
//					, m_called(rhs.m_called)
//				{
//					rhs.m_called = true;
//				}
//
//				~proxy_functor_void_caller()
//				{
//					if (m_called) return;
//
//					m_called = true;
//					lua_State* L = m_func->lua_state();
//#ifndef LUABIND_NO_ERROR_CHECKING
//					if (L == 0)
//					{
//	#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L); 
//	#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "tried to call uninitialized functor object."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//	#endif
//					}
//#endif
//
//
//					// get the function
//					m_func->pushvalue();
//
//					push_args_from_tuple<1>::apply(L, m_args);
//					if (pcall(L, boost::tuples::length<Tuple>::value, 0))
//					{ 
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw luabind::error(L);
//#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "the lua function threw an error and exceptions are disabled."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//				}
//
//				template<class Policies>
//				void operator[](const Policies& p)
//				{
//					m_called = true;
//					lua_State* L = m_func->lua_state();
//#ifndef LUABIND_NO_ERROR_CHECKING
//					if (L == 0)
//					{
//	#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L); 
//	#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "tried to call uninitialized functor object."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//	#endif
//					}
//#endif
//
//
//					// get the function
//					m_func->pushvalue();
//
//					detail::push_args_from_tuple<1>::apply(L, m_args, p);
//					if (pcall(L, boost::tuples::length<Tuple>::value, 0))
//					{ 
//#ifndef LUABIND_NO_EXCEPTIONS
//						throw error(L); 
//#else
//						error_callback_fun e = get_error_callback();
//						if (e) e(L);
//	
//						assert(0 && "the lua function threw an error and exceptions are disabled."
//							"if you want to handle this error use luabind::set_error_callback()");
//						std::terminate();
//#endif
//					}
//				}
//
//			private:
//
//				luabind::functor<void>* m_func;
//				Tuple m_args;
//				mutable bool m_called;
//
//			};
//
//	} // detail
//
//	template<class Ret>
//	class functor
//	{
//	public:
//
//		functor(lua_State* L, const char* name)
//			: L_(L)
//		{
//			lua_pushstring(L, name);
//			lua_gettable(L, LUA_GLOBALSINDEX);
//			ref_.set(L_);
//		}
//
//		functor()
//			: L_(0)
//		{
//		}
//
//		functor(const functor<Ret>& obj)
//			: L_(obj.L_)
//			, ref_(obj.ref_)
//		{
//		}
//
//		// this is a safe substitute for an implicit converter to bool
//		typedef void (functor::*member_ptr)() const;
//		operator member_ptr() const
//		{
//			if (is_valid()) return &functor::dummy;
//			return 0;
//		}
//
//		const functor<Ret>& operator=(const functor<Ret>& rhs)
//		{
//			L_ = rhs.L_;
//			ref_ = rhs.ref_;
//			return *this;
//		}
//
//		bool operator==(const functor<Ret>& rhs) const
//		{
//			if (!ref_.is_valid() || !rhs.ref_.is_valid()) return false;
//			pushvalue();
//			rhs.pushvalue();
//			bool result = lua_equal(L_, -1, -2) != 0;
//			lua_pop(L_, 2);
//			return result;
//		}
//
//		bool operator!=(const functor<Ret>& rhs) const
//		{
//			if (!ref_.is_valid() || !rhs.ref_.is_valid()) return true;
//			pushvalue();
//			rhs.pushvalue();
//			bool result = lua_equal(L_, -1, -2) == 0;
//			lua_pop(L_, 2);
//			return result;
//		}
//
//		inline bool is_valid() const { return ref_.is_valid(); }
//	
//		lua_State* lua_state() const { return L_; }
//		void pushvalue() const { ref_.get(L_); }
//
//		void reset()
//		{
//			L_ = 0;
//			ref_.reset();
//		}
//
//		#define BOOST_PP_ITERATION_PARAMS_1 (4, (0, LUABIND_MAX_ARITY, <luabind/functor.hpp>, 1))
//		#include BOOST_PP_ITERATE()
//
//// TODO: should be private
//
//		functor(lua_State* L, detail::lua_reference const& ref)
//			: L_(L)
//			, ref_(ref)
//		{
//		}
//
//	private:
//
//		void dummy() const {}
//
//		lua_State* L_;
//		detail::lua_reference ref_;
//	};
//}
//
//#endif // LUABIND_FUNCTOR_HPP_INCLUDED
//
//#else
//
//#define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
//#define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
//
//#if BOOST_PP_ITERATION() > 0
//	template<BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), class A)>
//#endif
//	typename boost::mpl::if_<boost::is_void<Ret>
//		, luabind::detail::proxy_functor_void_caller<boost::tuples::tuple<BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_TUPLE_PARAMS, _)> >
//		, luabind::detail::proxy_functor_caller<Ret, boost::tuples::tuple<BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_TUPLE_PARAMS, _)> > >::type
//	operator()(BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_OPERATOR_PARAMS, _)) const
//	{
//		typedef boost::tuples::tuple<BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_TUPLE_PARAMS, _)> tuple_t;
//#if BOOST_PP_ITERATION() == 0
//		tuple_t args;
//#else
//		tuple_t args(BOOST_PP_ENUM_PARAMS(BOOST_PP_ITERATION(), &a));
//#endif
//
//		typedef typename boost::mpl::if_<boost::is_void<Ret>
//			, luabind::detail::proxy_functor_void_caller<boost::tuples::tuple<BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_TUPLE_PARAMS, _)> >
//			, luabind::detail::proxy_functor_caller<Ret, boost::tuples::tuple<BOOST_PP_ENUM(BOOST_PP_ITERATION(), LUABIND_TUPLE_PARAMS, _)> > >::type proxy_type;
//		
//		return proxy_type(const_cast<luabind::functor<Ret>*>(this), args);
//	}
//
//	#define LUABIND_TUPLE_PARAMS(z, n, data) const A##n *
//	#define LUABIND_OPERATOR_PARAMS(z, n, data) const A##n & a##n
//
//#endif
//

// realization functor on all compilers
//#pragma once
//
//#include <luabind/luabind.hpp>
//
//namespace luabind
//{
//    template <class TResult>
//    class functor : public luabind::object
//    {
//    public:
//        functor() {}
//        functor(const luabind::object& obj) : luabind::object(obj) {}
//        TResult operator()() const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult>(*obj);
//        }
//        template <class T1>
//        TResult operator()(const T1& arg1) const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult, T1>(*obj, arg1);
//        }
//        template <class T1, class T2>
//        TResult operator()(const T1& arg1, const T2& arg2) const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult, T1, T2>(*obj, arg1, arg2);
//        }
//        template <class T1, class T2, class T3>
//        TResult operator()(const T1& arg1, const T2& arg2, const T3& arg3) const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult, T1, T2, T3>(*obj, arg1, arg2, arg3);
//        }
//        template <class T1, class T2, class T3, class T4>
//        TResult operator()(const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult, T1, T2, T3, T4>(*obj, arg1, arg2, arg3, arg4);
//        }
//        template <class T1, class T2, class T3, class T4, class T5>
//        TResult operator()(const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) const
//        {
//            auto obj = static_cast<const luabind::object*>(this);
//            return call_function<TResult, T1, T2, T3, T4, T5>(*obj, arg1, arg2, arg3, arg4, arg5);
//        }
//    };
//
//    template <>
//    void functor<void>::operator()() const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void>(*obj);
//    }
//    template <>
//    template <class T1>
//    void functor<void>::operator()(const T1& arg1) const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void, T1>(*obj, arg1);
//    }
//    template <>
//    template <class T1, class T2>
//    void functor<void>::operator()(const T1& arg1, const T2& arg2) const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void, T1, T2>(*obj, arg1, arg2);
//    }
//    template <>
//    template <class T1, class T2, class T3>
//    void functor<void>::operator()(const T1& arg1, const T2& arg2, const T3& arg3) const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void, T1, T2, T3>(*obj, arg1, arg2, arg3);
//    }
//    template <>
//    template <class T1, class T2, class T3, class T4>
//    void functor<void>::operator()(const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4) const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void, T1, T2, T3, T4>(*obj, arg1, arg2, arg3, arg4);
//    }
//    template <>
//    template <class T1, class T2, class T3, class T4, class T5>
//    void functor<void>::operator()(const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4, const T5& arg5) const
//    {
//        auto obj = static_cast<const luabind::object*>(this);
//        call_function<void, T1, T2, T3, T4, T5>(*obj, arg1, arg2, arg3, arg4, arg5);
//    }
//
//}


#pragma once

#include "luabind/luabind.hpp"
#include <type_traits>
#include <luabind/detail/format_signature.hpp>
#include <luabind/detail/inheritance.hpp>

namespace luabind
{
    template <typename TResult, typename... Policies>
    class functor : public adl::object
    {
    public:
        functor() {}
        functor(const adl::object& obj) : adl::object(obj) {}
        template <typename... Args>
        TResult operator()(Args&&... args) const
        {
            auto obj = static_cast<const adl::object*>(this);
            return call_function<TResult, policy_list<Policies...>>(*obj, std::forward<Args>(args)...);
        }
    };

    // XXX: review
    // Returning void_type has been allowed since C++03 for templates. VS2015.3 even throws an ERROR,
    // so this specialization has no purpose.
    template <>
    template <typename... Args>
    void functor<void>::operator()(Args&&... args) const
    {
        auto obj = static_cast<const adl::object*>(this);
        call_function<void, policy_list<>>(*obj, std::forward<Args>(args)...);
    }

    namespace detail
    {
        template <typename T>
        struct type_to_string<functor<T>>
        {
            static void get(lua_State* L)
            {
                lua_pushstring(L, "function<");
                type_to_string<T>::get(L);
                lua_pushstring(L, ">");
                lua_concat(L, 3);
            }
        };
    }

    template <typename T>
    struct default_converter<functor<T>> : native_converter_base<functor<T>>
    {
        static int compute_score(lua_State* luaState, int index)
        {
            return lua_isfunction(luaState, index) || lua_isnil(luaState, index) ? 0 : no_match;
        }

        static functor<T> to_cpp_deferred(lua_State* luaState, int index)
        {
            if (lua_isnil(luaState, index))
                return functor<T>();
            return object(from_stack(luaState, index));
        }

        static void to_lua_deferred(lua_State* luaState, functor<T> const& value) { value.push(luaState); }
    };

    template <typename T>
    struct default_converter<const functor<T>> : default_converter<functor<T>>
    {
    };

    template <typename T>
    struct default_converter<const functor<T>&> : default_converter<functor<T>>
    {
    };
}
