#if !defined(MAYA_CXX_17_ENTER_LEGACY_SCOPE)
	#error "Unpair cxx17_exit_legacy_scope"
#elif defined(MAYA_CXX17_ENABLED)
	MAYA_CXX17_POP_WARN
	#if defined(MAYA_CXX17_THROW_NULL_DEFINED)
		#undef throw
	#endif
#endif
