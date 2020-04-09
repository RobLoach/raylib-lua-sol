#include <string>

#include <sol/sol.hpp>
#include "../include/raylib-lua-sol.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("raylib-lua-sol-test", "[raylib-lua-sol-test]" ) {
	// Initialize the environment.
	sol::state lua;
	raylib_lua_sol(lua);

  SECTION("IsWindowReady") {
  	auto script = lua.safe_script("windowReady = IsWindowReady()", sol::script_pass_on_error);
    REQUIRE(script.valid());
  	bool ready = lua["windowReady"];
  	CHECK(ready == false);
  }

  SECTION("FILES") {
    auto script = lua.safe_script("fileExtension = GetExtension('something.lua')", sol::script_pass_on_error);
    REQUIRE(script.valid());
    std::string fileExtension = lua["fileExtension"];
    CHECK(fileExtension == "lua");
  }

  SECTION("ENUMS") {
    // Check that enums are available.
    ConfigFlag flagFullScreenMode = lua["FLAG_FULLSCREEN_MODE"];
    CHECK(flagFullScreenMode == FLAG_FULLSCREEN_MODE);

    // Check another enum.
    BlendMode blendmodeMultiplied = lua["BLEND_MULTIPLIED"];
    CHECK(blendmodeMultiplied == BLEND_MULTIPLIED);

    // TODO: Make defines constant.
    //auto script = lua.safe_script("FLAG_FULLSCREEN_MODE = 50", sol::script_pass_on_error);
    //REQUIRE_FALSE(script.valid());
  }

  // TODO: Fix structs.
  SECTION("Rectangle") {
    auto script = lua.safe_script("theRect = Rectangle(10.0, 20.0, 30.0, 40.0)", sol::script_pass_on_error);
    REQUIRE(script.valid());
    float width = lua["theRect"]["width"];
    CHECK(width == 30.0f);
  }
}
