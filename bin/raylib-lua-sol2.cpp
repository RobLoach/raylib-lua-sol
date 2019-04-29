/*******************************************************************************************
*
*   raylib-lua-sol2 v0.0.1 - raylib Lua Sol2 Launcher
*
*   DEPENDENCIES:
*
*   raylib 2.0 - This program uses latest raylib version (www.raylib.com)
*   Sol2       - https://github.com/ThePhD/sol2/
*   Lua
*
*   COMPILATION (GCC):
*
*     mkdir build
*     cd build
*     cmake ..
*     make
*
*   USAGE:
*
*     Just launch your raylib .lua file from command line:
*       ./raylib-lua-sol2 core_basic_window.lua
*
*     or drag & drop your .lua file over raylib-lua-sol2.exe
*
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2018 Rob Loach (@RobLoach)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
********************************************************************************************/

#include <iostream>
#include <string>

#include "raylib.h"
#include "../include/raylib-lua-sol2.hpp"

int main(int argc, char *argv[])
{
    std::string executableName;
    std::string fileToLoad;

    switch (argc) {
        case 0:
            executableName = "raylib-lua-sol2";
            fileToLoad = "main.lua";
            break;
        case 1:
            executableName = argv[0];
            fileToLoad = "main.lua";
            break;
        default:
            executableName = argv[0];
            fileToLoad = argv[1];
            break;
    }

    if (!FileExists(fileToLoad.c_str())) {
        std::cout << "Usage:" << std::endl << "    " << GetFileName(executableName.c_str()) << " myfile.lua" << std::endl << std::endl;
        std::cout << "Attempted file " << fileToLoad << " was not found." << std::endl;
        return 1;
    }

    if (!IsFileExtension(fileToLoad.c_str(), ".lua")) {
        std::cout << "Expected file to be a .lua file." << std::endl;
        return 1;
    }

    // Build the Lua environment.
    sol::state lua;

    // Bootstrap Raylib.
    raylib_lua_sol2(lua);

    // Execute the script.
    lua.script_file(fileToLoad);

    return 0;
}
