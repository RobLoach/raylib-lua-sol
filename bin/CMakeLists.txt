find_package(raylib)
find_package(lua)
find_package(sol2)

add_executable(raylib-lua-sol raylib-lua-sol.cpp)

target_compile_definitions(raylib-lua-sol PUBLIC -DLUA -DPHYSAC_NO_THREADS)

set_target_properties(raylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_link_libraries(raylib-lua-sol
  raylib-lua-sol-hpp
  libraylib-lua-sol
  raylib
  ${LUA_LIBRARY}
  liblua
  sol2
)

target_include_directories(raylib-lua-sol PUBLIC
  ${raylib_SOURCE_DIR}/src
  ${sol2_SOURCE_DIR}
  ${LUA_INCLUDE_DIR}
  ../vendor/lua/src
  ${lua_BINARY_DIR}
)
