# raylib-lua-sol.hpp include

add_library(raylib-lua-sol-hpp INTERFACE)
target_include_directories(raylib-lua-sol-hpp INTERFACE . )
file(COPY
  raylib-lua-sol.hpp
  raylib-lua-sol-rlgl.hpp
  DESTINATION .)
