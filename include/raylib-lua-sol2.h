#ifndef RAYLIB_LUA_SOL2_
#define RAYLIB_LUA_SOL2_

#include <sol/sol.hpp>
#include <iostream>

void raylib_lua_sol2(sol::state &lua) {
	lua.set_function("beep", []{
		std::cout << "BEEP!" << std::endl;
	});
}

#endif // RAYLIB_LUA_SOL2_