////////////////////////////////////////////////////////////////////////////
//	Module 		: script_callback_ex_inline.h
//	Created 	: 06.02.2004
//  Modified 	: 11.01.2005
//	Author		: Sergey Zhemeitsev and Dmitriy Iassenev
//	Description : Script callbacks with return value inline functions
////////////////////////////////////////////////////////////////////////////

#pragma once

#define TEMPLATE_SPECIALIZATION			template <typename _return_type>
#define CSScriptCallbackEx				CScriptCallbackEx_<_return_type>

TEMPLATE_SPECIALIZATION
IC	CSScriptCallbackEx::CScriptCallbackEx_				() 
{
}

TEMPLATE_SPECIALIZATION
IC	CSScriptCallbackEx::~CScriptCallbackEx_				()
{
}

TEMPLATE_SPECIALIZATION
IC	void CSScriptCallbackEx::clear						()
{
	m_functor.~functor_type			();
	new (&m_functor) functor_type	();

	m_object.~object_type			();
	new (&m_object)	object_type		();
}

TEMPLATE_SPECIALIZATION
IC	CSScriptCallbackEx::CScriptCallbackEx_				(const CScriptCallbackEx_ &callback)
{
	clear				();
	*this				= callback;
}

TEMPLATE_SPECIALIZATION
IC	CSScriptCallbackEx &CSScriptCallbackEx::operator=	(const CScriptCallbackEx_ &callback)
{
	clear();
	if (callback.m_functor.is_valid() && callback.m_functor.interpreter()) // lua_state
		m_functor = callback.m_functor;
	if (callback.m_object.is_valid() && callback.m_object.interpreter())
		m_object = callback.m_object;
	return *this;
}

TEMPLATE_SPECIALIZATION
IC	void CSScriptCallbackEx::set						(const functor_type &functor)
{
	clear				();
	m_functor			= functor;
}

TEMPLATE_SPECIALIZATION
IC	void CSScriptCallbackEx::set						(const functor_type &functor, const object_type &object)
{
	clear				();
	
	m_functor			= functor;
	m_object			= object;
}

TEMPLATE_SPECIALIZATION
IC	bool CSScriptCallbackEx::empty						() const
{
	return				(!!m_functor.interpreter()); // lua_state
}

TEMPLATE_SPECIALIZATION
IC			bool				CSScriptCallbackEx::operator==				(const CScriptCallbackEx_& callback)const { return compare_safe(m_object, (callback.m_object)) && m_functor == (callback.m_functor); }

TEMPLATE_SPECIALIZATION
IC			bool				CSScriptCallbackEx::operator==				(const object_type& object)		const { return compare_safe(m_object, object); }

IC	bool compare_safe(const luabind::object& o1, const luabind::object& o2)
{
	if ((luabind::type(o1) == LUA_TNIL) && (luabind::type(o2) == LUA_TNIL))
		return (true);

	return (o1 == o2);
}

#undef TEMPLATE_SPECIALIZATION
#undef CSScriptCallbackEx