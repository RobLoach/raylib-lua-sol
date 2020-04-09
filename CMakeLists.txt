cmake_minimum_required(VERSION 3.11)
project (raylib-lua-sol
  VERSION 0.2.1
  DESCRIPTION "Lua bindings for raylib"
  HOMEPAGE_URL "https://github.com/RobLoach/raylib-lua-sol"
  LANGUAGES C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# raylib
find_package(raylib 3.0.0)
if (NOT raylib_FOUND)
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
  add_subdirectory(vendor/raylib)
endif()

# Lua
find_package(lua)
if (NOT lua_FOUND)
  add_subdirectory(vendor/lua)
endif()

# Sol2
find_package(sol2)
if (NOT sol2_FOUND)
  add_subdirectory(vendor/sol2)
endif()

# Options
#option(BUILD_LIBRARY "Library" ON)
option(BUILD_BIN "Binary" ON)
option(BUILD_EXAMPLES "Examples" ON)

add_subdirectory(include)
add_subdirectory(lib)

if (BUILD_BIN)
  #add_subdirectory(bin)
endif()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

include(CTest)
enable_testing()
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
