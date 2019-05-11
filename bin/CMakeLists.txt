find_package(Raylib)
find_package(Sol2)
find_package(Lua 5.3 REQUIRED)

add_executable(raylib-lua-sol2 raylib-lua-sol2.cpp)

target_compile_definitions(raylib-lua-sol2 PUBLIC -DLUA)

set_target_properties(raylib-lua-sol2 PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_link_libraries(raylib-lua-sol2
  ${LUA_LIBRARY}
  raylib
)

target_include_directories(raylib-lua-sol2 PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${sol2_SOURCE_DIR}/include
    ${LUA_INCLUDE_DIR}
)
