#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
// #include "../include/raylib-lua-sol.hpp"

class test {
public:
  int value;
  test(){

  };
  test(int val) {
    value = val;
  };
};

namespace my_object {
  sol::table open_my_object(sol::this_state L) {
    sol::state_view lua(L);

    //raylib_lua_sol(lua);
    sol::table module = lua.create_table();
    module.new_usertype<test>("test",
      sol::constructors<test(), test(int)>(),
      "value", &test::value);

    return module;
  }

}

extern "C" int luaopen_raylib(lua_State* L) {
  // pass the lua_State,
  // the index to start grabbing arguments from,
  // and the function itself
  // optionally, you can pass extra arguments to the function if that's necessary,
  // but that's advanced usage and is generally reserved for internals only
  return sol::stack::call_lua(L, 1, my_object::open_my_object );
}
