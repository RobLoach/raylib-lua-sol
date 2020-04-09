# libraylib-lua-sol static library

add_library(libraylib-lua-sol STATIC libraylib-lua-sol.cpp)

target_compile_definitions(libraylib-lua-sol PUBLIC -DLUA -DLUA_32BITS -DPHYSAC_NO_THREADS) # -DLUA_VERSION_NUM=503)

set_target_properties(libraylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  PREFIX ""
)

target_link_libraries(libraylib-lua-sol
  raylib-lua-sol-hpp
  raylib
  lua
  sol2
)

target_include_directories(libraylib-lua-sol PUBLIC
  ../include
  ../vendor/lua-5.3.5
  ../vendor/raylib/src
  ../vendor/sol2/include
)
