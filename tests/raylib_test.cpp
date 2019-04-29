#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>

#include <sol/sol.hpp>

#include "../include/raylib-lua-sol2.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test functions work", "[raylib_test]" ) {
	// Initialize the environment.
	sol::state lua;
	raylib_lua_sol2(lua);

	// IsWindowReady
	lua.script("local windowReady = IsWindowReady()");
	bool ready = lua["windowReady"];
	CHECK(ready == false);

	// Colors
	lua.script("local theColor = GREEN");
	//Color& col = lua["theColor"];
	//CHECK(col.g == 228);

	int a = lua.get<int>("GREEN.g");
	std::cout << "Green.g: " << a << std::endl;
}
