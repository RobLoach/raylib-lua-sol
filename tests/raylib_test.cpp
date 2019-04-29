#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>

#include <sol/sol.hpp>

#include "../include/raylib-lua-sol2.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test functions work", "[raylib_test]" ) {
	/*raylib::Vector2 vec(50, 100);
	CHECK(vec.getX() == 50.0f);

	CHECK(raylib::Window::IsReady() == false);

	raylib::Color c(RED);
	int redInt = c.ToInt();
	CHECK(redInt == ColorToInt(RED));*/


	sol::state lua;
	raylib_lua_sol2(lua);

	lua.script("local windowReady = IsWindowReady()");
	bool ready = lua["windowReady"];
	CHECK(ready == false);
	lua.script("InitWindow(640, 480, \"Hello\")");
	lua.script("windowReady = IsWindowReady()");
	ready = lua["windowReady"];
	CHECK(ready == true);
	lua.script("CloseWindow()");
}
