cmake_minimum_required(VERSION 3.11)
project (raylib-lua-sol
  VERSION 0.1.0
  DESCRIPTION "Lua bindings for raylib"
  HOMEPAGE_URL "https://github.com/RobLoach/raylib-lua-sol"
  LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(BUILD_BIN "Binary" ON)
option(BUILD_EXAMPLES "Examples" ON)
option(BUILD_LIBRARY "Library" ON)

include_directories(include)

if (BUILD_BIN)
  add_subdirectory(bin)
endif()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if (BUILD_LIB)
  add_subdirectory(lib)
endif()

include(CTest)
enable_testing()
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
