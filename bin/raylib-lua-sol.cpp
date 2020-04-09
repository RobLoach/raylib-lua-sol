/*******************************************************************************************
*
*   raylib-lua-sol v0.0.1 - Launcher for raylib Lua applications.
*
*   DEPENDENCIES:
*
*   raylib - http://www.raylib.com
*   sol    - https://github.com/ThePhD/sol2/
*   Lua    - http://www.lua.org
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
*       ./raylib-lua-sol core_basic_window.lua
*
*     or drag & drop your .lua file over raylib-lua-sol.exe
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

#include <sol/sol.hpp>
#include <iostream>
#include <string>

#include "raylib.h"

#define SOL_PRINT_ERRORS
#include "raylib-lua-sol.hpp"

int main(int argc, char *argv[])
{
    std::string executableName;
    std::string fileToLoad;

    switch (argc) {
        case 0:
            executableName = "raylib-lua-sol";
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

    // Load some of the Lua base libraries.
    lua.open_libraries(
      sol::lib::base,
      sol::lib::package,
      sol::lib::string,
      sol::lib::math,
      sol::lib::table,
      sol::lib::jit);

    // Bootstrap Raylib.
    raylib_lua_sol(lua);

    // Execute the script.
    // TODO: Use JIT compiler
    auto result = lua.safe_script_file(fileToLoad, sol::script_pass_on_error);
    if (!result.valid()) {
      sol::error err = result;
      std::cerr << "The code was unable to run." << std::endl << err.what() << std::endl;
      return 1;
    }

    return 0;
}
