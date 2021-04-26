cmake_minimum_required(VERSION 3.11)
project (raylib-lua-sol
  VERSION 0.2.2
  DESCRIPTION "Lua bindings for raylib"
  HOMEPAGE_URL "https://github.com/RobLoach/raylib-lua-sol"
  LANGUAGES C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
configure_file(${CMAKE_SOURCE_DIR}/cmake/CTestCustom.cmake ${CMAKE_BINARY_DIR})

if (MSVC)
  #add_compile_options("/SUBSYSTEM:WINDOWS")
  #add_compile_options("/ENTRY:mainCRTStartup")
  #ADD_DEFINITIONS(/bigobj)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /bigobj")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /bigobj")
  SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /bigobj")
elseif(MINGW OR CYGWIN)
  add_definitions(-O3)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wa,-mbig-obj")
  SET(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -Wa,-mbig-obj")
  SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wa,-mbig-obj")
  SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -Os -Wa,-mbig-obj")
endif()

# Options
option(BUILD_BIN "Binary" ON)
option(BUILD_EXAMPLES "Examples" ON)

add_subdirectory(include)

if (BUILD_BIN)
  # raylib
  find_package(raylib 3.0.0)
  if (NOT raylib_FOUND)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
    add_subdirectory(vendor/raylib)
  endif()

  # Lua
  set(LUA_DIR vendor/lua)
  set(LUA_SRC
      ${LUA_DIR}/lapi.c
      ${LUA_DIR}/lcode.c
      ${LUA_DIR}/lctype.c
      ${LUA_DIR}/ldebug.c
      ${LUA_DIR}/ldo.c
      ${LUA_DIR}/ldump.c
      ${LUA_DIR}/lfunc.c
      ${LUA_DIR}/lgc.c
      ${LUA_DIR}/llex.c
      ${LUA_DIR}/lmem.c
      ${LUA_DIR}/lobject.c
      ${LUA_DIR}/lopcodes.c
      ${LUA_DIR}/lparser.c
      ${LUA_DIR}/lstate.c
      ${LUA_DIR}/lstring.c
      ${LUA_DIR}/ltable.c
      ${LUA_DIR}/ltm.c
      ${LUA_DIR}/lundump.c
      ${LUA_DIR}/lvm.c
      ${LUA_DIR}/lzio.c
      ${LUA_DIR}/lauxlib.c
      ${LUA_DIR}/lbaselib.c
      ${LUA_DIR}/lcorolib.c
      ${LUA_DIR}/ldblib.c
      ${LUA_DIR}/liolib.c
      ${LUA_DIR}/lmathlib.c
      ${LUA_DIR}/loslib.c
      ${LUA_DIR}/lstrlib.c
      ${LUA_DIR}/ltablib.c
      ${LUA_DIR}/lutf8lib.c
      ${LUA_DIR}/loadlib.c
      ${LUA_DIR}/linit.c
  )
  add_library(lua STATIC ${LUA_SRC})
  target_compile_definitions(lua PRIVATE LUA_COMPAT_5_2)
  target_include_directories(lua INTERFACE ${LUA_DIR})

  # Sol2
  set(SOL2_DIR vendor/sol2)
  add_library(sol2 INTERFACE)
  target_include_directories(sol2 INTERFACE ${SOL2_DIR}/include/)

  # Add the binary.
  add_subdirectory(bin)
endif()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

include(CTest)
enable_testing()
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
