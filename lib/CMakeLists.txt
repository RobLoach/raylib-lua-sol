# libraylib-lua-sol static library

find_package(raylib)
find_package(lua)
find_package(sol2)

add_library(libraylib-lua-sol STATIC libraylib-lua-sol.cpp)

target_compile_definitions(libraylib-lua-sol PUBLIC -DLUA -DPHYSAC_NO_THREADS -DLUA_VERSION_NUM=503)

set_target_properties(libraylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  PREFIX ""
)

target_link_libraries(libraylib-lua-sol
  raylib-lua-sol-hpp
  raylib
  ${LUA_LIBRARY}
  liblua
  sol2
)

target_include_directories(libraylib-lua-sol PUBLIC
  ../include
  ${raylib_SOURCE_DIR}/src
  ${sol2_SOURCE_DIR}/single/include
  ${LUA_INCLUDE_DIR}
  ${lua_BINARY_DIR}
)
