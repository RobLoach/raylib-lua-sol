cmake_minimum_required(VERSION 3.11)
project (raylib-lua-sol
  VERSION 0.2.1
  DESCRIPTION "Lua bindings for raylib"
  HOMEPAGE_URL "https://github.com/RobLoach/raylib-lua-sol"
  LANGUAGES C CXX)


IF (WIN32)
  #add_compile_options("/SUBSYSTEM:WINDOWS")
  #add_compile_options("/ENTRY:mainCRTStartup")
  #ADD_DEFINITIONS(/bigobj)
  #SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
  #SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  #SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /bigobj")
  #SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /bigobj")
  #SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /bigobj")

  set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
  set(CMAKE_FIND_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")

  set(LUA_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/lua53.lib")
  set(LUA_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/lib/lua")
  set(LUA_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/lua/include")
  find_package(lua 5.3)
ENDIF()

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_LIBRARY "Library" ON)
option(BUILD_BIN "Binary" ON)
option(BUILD_EXAMPLES "Examples" ON)

include_directories(include)

if (BUILD_LIB)
  add_subdirectory(lib)
endif()

if (BUILD_BIN)
  add_subdirectory(bin)
endif()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

#include(CTest)
#enable_testing()
#if(BUILD_TESTING)
#  add_subdirectory(tests)
#endif()
