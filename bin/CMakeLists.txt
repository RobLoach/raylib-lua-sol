find_package(Raylib)
find_package(Sol2)
find_package(Lua)

add_executable(raylib-lua-sol2 raylib-lua-sol2.cpp)
target_link_libraries(raylib-lua-sol2 raylib)
target_include_directories(raylib-lua-sol2 PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${sol2_SOURCE_DIR}/include
    ${lua_SOURCE_DIR}
)