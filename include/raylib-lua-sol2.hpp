#ifndef RAYLIB_LUA_SOL2_
#define RAYLIB_LUA_SOL2_

#include <raylib.h>
#include <sol/sol.hpp>
#include <iostream>

void raylib_lua_sol2_color(sol::state &lua) {
	lua.new_usertype<Color>("Color",
		"r", &Color::r,
		"g", &Color::g,
		"b", &Color::b,
		"a", &Color::a);
	lua["LIGHTGRAY"] = Color(LIGHTGRAY);
	lua["GRAY"] = Color(GRAY);
	lua["DARKGRAY"] = Color(DARKGRAY);
	lua["YELLOW"] = Color(YELLOW);
	lua["GOLD"] = Color(GOLD);
	lua["ORANGE"] = Color(ORANGE);
	lua["PINK"] = Color(PINK);
	lua["RED"] = Color(RED);
	lua["MAROON"] = Color(MAROON);
	lua["GREEN"] = Color(GREEN);
	lua["LIME"] = Color(LIME);
	lua["DARKGREEN"] = Color(DARKGREEN);
	lua["SKYBLUE"] = Color(SKYBLUE);
	lua["BLUE"] = Color(BLUE);
	lua["DARKBLUE"] = Color(DARKBLUE);
	lua["PURPLE"] = Color(PURPLE);
	lua["VIOLET"] = Color(VIOLET);
	lua["DARKPURPLE"] = Color(DARKPURPLE);
	lua["BEIGE"] = Color(BEIGE);
	lua["BROWN"] = Color(BROWN);
	lua["DARKBROWN"] = Color(DARKBROWN);
	lua["WHITE"] = Color(WHITE);
	lua["BLACK"] = Color(BLACK);
	lua["BLANK"] = Color(BLANK);
	lua["MAGENTA"] = Color(MAGENTA);
	lua["RAYWHITE"] = Color(RAYWHITE);
}

void raylib_lua_sol2(sol::state &lua) {
	raylib_lua_sol2_color(lua);
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
