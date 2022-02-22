cmake_minimum_required(VERSION 3.16)

project(xrLuabind)

set(CMAKE_CXX_STANDARD 17)

option(LUABIND_BUILD_TESTING "Build luabind with tests" OFF)
option(LUABIND_BUILD_SHARED "Build luabind as a shared library" ON)

if(NOT LUA_FOUND AND NOT LUA51_FOUND)
	find_package(Lua51 REQUIRED)
	set(LUA_INCLUDE_DIRS "${LUA_INCLUDE_DIR}")
endif()

add_subdirectory(luabind)
add_subdirectory(src)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	if(LUABIND_BUILD_TESTING)
		add_subdirectory(test)
	endif()
	add_subdirectory(doc)
endif()
