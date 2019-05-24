find_package(Raylib)
find_package(Sol)
find_package(Lua 5.3 REQUIRED)

add_executable(raylib-lua-sol raylib-lua-sol.cpp)

target_compile_definitions(raylib-lua-sol PUBLIC -DLUA)

set_target_properties(raylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_link_libraries(raylib-lua-sol
  ${LUA_LIBRARY}
  raylib
)

target_include_directories(raylib-lua-sol PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${sol_SOURCE_DIR}/include
    ${LUA_INCLUDE_DIR}
)
