package = "raylib-lua-sol"
version = "0.0.1-1"
source = {
  url = "git://github.com/RobLoach/raylib-lua-sol.git"
}
description = {
  summary = "raylib for Lua, using sol.",
  detailed = [[
    raylib-lua-sol bindings are self-contained in a header-only file: raylib-lua-sol.h. Just include that file in your project to allow loading and execution of raylib code written in Lua and Sol.
  ]],
  license = "zlib",
  homepage = "https://github.com/robloach/raylib-lua-sol"
}
dependencies = {
  "lua >= 5.2"
}
build = {
  type = "cmake",

  variables = {
    BUILD_BIN = "OFF",
    BUILD_SHARED_LIBS = "ON",
    LUA_INCLUDE_DIR = "$(LUA_INCDIR)",
    LUA_PATH="$(LUADIR)",
    LUA_CPATH="$(LIBDIR)",
    CMAKE_BUILD_TYPE="Release",
    CMAKE_PREFIX_PATH="$(LUA_BINDIR)/..",
    CMAKE_INSTALL_PREFIX="$(PREFIX)"
  }
}
