![raylib-lua-sol Logo](logo/raylib-lua-sol_256x256.png)

# raylib-lua-sol

[Lua](http://www.lua.org/) bindings for [raylib](https://www.raylib.com/), a simple and easy-to-use library to enjoy videogames programming, with [sol](https://github.com/ThePhD/sol2) (www.raylib.com)

*raylib-lua-sol* bindings are self-contained in a header-only file: [raylib-lua-sol.h](include/raylib-lua-sol.h). Just include that file
in your project to allow loading and execution of raylib code written in Lua and Sol.

*raylib-lua-sol* could be useful for prototyping, tools development, graphic applications, embedded systems and education.

Ready to learn? Check out the [code examples](examples)!

## Example

``` lua
local screenWidth = 800
local screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window")

SetTargetFPS(60)

while not WindowShouldClose() do
    BeginDrawing()
        ClearBackground(RAYWHITE)
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY)
    EndDrawing()
end
CloseWindow()
```

## CLI

A [`raylib-lua-sol`](bin/raylib-lua-sol.cpp) CLI launcher is provided. This launcher allows you to run raylib lua programs from command line, or just with *drag & drop* of .lua files into *raylib-lua-sol.exe*.

Note that launcher can also be compiled for other platforms, just need to link with Lua, raylib and sol libraries. For more details, just check comments on sources.

``` bash
bin/raylib-lua-sol examples/core_basic_window.lua
```

## Build

``` bash
git clone https://github.com/RobLoach/raylib-lua-sol.git
cd raylib-lua-sol
mkdir build
cd build
cmake ..
make
```

## Development

``` bash
make test
```

# License

raylib-lua-sol is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

*Copyright (c) 2019 Rob Loach ([@RobLoach](https://twitter.com/RobLoach))*
