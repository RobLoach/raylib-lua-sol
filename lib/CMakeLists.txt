# libraylib-lua-sol static library

find_package(Raylib)
find_package(Sol)
find_package(Lua 5.3 REQUIRED)


add_library(libraylib-lua-sol STATIC libraylib-lua-sol)

target_compile_definitions(libraylib-lua-sol PUBLIC -DLUA -DPHYSAC_NO_THREADS)

set_target_properties(libraylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  PREFIX ""
)

target_link_libraries(libraylib-lua-sol
  ${LUA_LIBRARY}
  raylib
)

target_include_directories(libraylib-lua-sol PUBLIC
    ${raylib_SOURCE_DIR}/src
    ${sol_SOURCE_DIR}/include
    ${LUA_INCLUDE_DIR}
)
