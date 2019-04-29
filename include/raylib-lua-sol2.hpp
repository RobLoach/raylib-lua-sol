#ifndef RAYLIB_LUA_SOL2_
#define RAYLIB_LUA_SOL2_

#include <raylib.h>
#include <sol/sol.hpp>
#include <iostream>

void raylib_lua_sol2(sol::state &lua) {

	lua.new_usertype<Color>("Color",
		"r", &Color::r,
		"g", &Color::g,
		"b", &Color::b,
		"a", &Color::a);

	lua["RAYWHITE"] = RAYWHITE;
	lua["LIGHTGRAY"] = LIGHTGRAY;

	lua.set_function("IsWindowReady", IsWindowReady);
	lua.set_function("InitWindow", InitWindow);
	lua.set_function("CloseWindow", CloseWindow);
	lua.set_function("SetTargetFPS", SetTargetFPS);
	lua.set_function("WindowShouldClose", WindowShouldClose);
	lua.set_function("BeginDrawing", BeginDrawing);
	lua.set_function("ClearBackground", ClearBackground);
	lua.set_function("DrawText", DrawText);
	lua.set_function("EndDrawing", EndDrawing);
}

#endif // RAYLIB_LUA_SOL2_
