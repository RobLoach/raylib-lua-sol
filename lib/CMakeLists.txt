add_library(raylib-lua-sol-module SHARED
  raylib-lua-sol-module.cpp
  ${LUA_SRC}
)

target_compile_definitions(raylib-lua-sol-module PUBLIC -DLUA -DLUA_COMPAT_5_2 -DPHYSAC_NO_THREADS)

set_target_properties(raylib-lua-sol-module PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  PREFIX ""
  OUTPUT_NAME "raylib-lua-sol"
  POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(raylib-lua-sol-module PUBLIC
  raylib-lua-sol-hpp
  raylib
  sol2
)

target_include_directories(raylib-lua-sol-module PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/lua
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib/src
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/sol2/include
  ${LUA_DIR}
)

file(COPY raylib-lua-sol-module-test.lua DESTINATION .)
