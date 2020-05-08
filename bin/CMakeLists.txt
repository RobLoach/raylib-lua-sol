add_executable(raylib-lua-sol raylib-lua-sol.cpp)

target_compile_definitions(raylib-lua-sol PUBLIC -DLUA -DPHYSAC_NO_THREADS)

set_target_properties(raylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_link_libraries(raylib-lua-sol
  raylib-lua-sol-hpp
  raylib
  lua
  sol2
)

target_include_directories(raylib-lua-sol PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/lua
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib/src
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/sol2/include
)
