#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>

#include <sol/sol.hpp>

#include "../include/raylib-lua-sol.hpp"
#include "catch.hpp"

TEST_CASE("raylib_test functions work", "[raylib_test]" ) {
	// Initialize the environment.
	sol::state lua;
	raylib_lua_sol(lua);

	// IsWindowReady
	auto r1 = lua.safe_script("windowReady = IsWindowReady()", sol::script_pass_on_error);
  REQUIRE(r1.valid());
	bool ready = lua["windowReady"];
	CHECK(ready == false);

  // Enums
  ConfigFlag d = lua["ConfigFlag"]["FLAG_FULLSCREEN_MODE"];
  REQUIRE(d == ConfigFlag::FLAG_FULLSCREEN_MODE);
  auto r2 = lua.safe_script("ConfigFlag.FLAG_FULLSCREEN_MODE = 50", sol::script_pass_on_error);
  REQUIRE_FALSE(r2.valid());
  d = lua["ConfigFlag"]["FLAG_FULLSCREEN_MODE"];
  REQUIRE(d == ConfigFlag::FLAG_FULLSCREEN_MODE);
  BlendMode blendmodeMultiplied = lua["BlendMode"]["BLEND_MULTIPLIED"];
  REQUIRE(blendmodeMultiplied == BlendMode::BLEND_MULTIPLIED);

  // Rectangle
  auto r3 = lua.safe_script("theRect = Rectangle(10.0, 20.0, 30.0, 40.0)", sol::script_pass_on_error);
  REQUIRE(r3.valid());
  float w = lua["theRect"]["width"];
  REQUIRE(w == 30);
}
