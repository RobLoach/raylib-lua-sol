# CMake generated Testfile for 
# Source directory: D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/raylib-src/src
# Build directory: D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/raylib-build/src
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(pkg-config--static "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/raylib-src/src/../cmake/test-pkgconfig.sh" "--static")
set_tests_properties(pkg-config--static PROPERTIES  _BACKTRACE_TRIPLES "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/raylib-src/src/CMakeLists.txt;180;add_test;D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/raylib-src/src/CMakeLists.txt;0;")
subdirs("external/glfw")
