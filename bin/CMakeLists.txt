add_executable(raylib-lua-sol raylib-lua-sol.cpp)

set_target_properties(raylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_link_libraries(raylib-lua-sol
  libraylib-lua-sol
)
