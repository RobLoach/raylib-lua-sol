<img align="left" src="logo/raylib-lua_256x256.png" width=256>

[Lua](http://www.lua.org/) bindings for [raylib](https://www.raylib.com/), a simple and easy-to-use library to enjoy videogames programming, through [sol](https://github.com/ThePhD/sol2) (www.raylib.com)

raylib-lua-sol binding is self-contained in a header-only file: [raylib-lua-sol.h](include/raylib-lua-sol.h). Just include that file
in your project to allow loading and execution of raylib code written in Lua. Check [code examples](examples) for reference.

raylib-lua-sol could be useful for prototyping, tools development, graphic applications, embedded systems and education.

### CLI

A raylib-lua-sol CLI launcher is also provided: [raylib-lua-sol](bin/raylib-lua-sol.cpp). This launcher allows you to run raylib lua programs from command line, or just with *drag & drop* of .lua files into *raylib-lua-sol.exe*.

Note that launcher can also be compiled for other platforms, just need to link with Lua, raylib and sol libraries. For more details, just check comments on sources.

### Build

```
mkdir build
cd build
cmake ..
make
make test
```

# License

raylib-lua-sol is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

*Copyright (c) 2019 Rob Loach ([@RobLoach](https://twitter.com/RobLoach))*
