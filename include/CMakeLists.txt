# raylib-lua-sol include

#find_package(raylib)
#find_package(lua)
#find_package(sol2)

add_library(raylib-lua-sol-hpp INTERFACE)
target_include_directories(raylib-lua-sol-hpp INTERFACE
  ./
)
