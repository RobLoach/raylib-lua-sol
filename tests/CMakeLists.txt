add_test(
  NAME raylib-lua-sol-tests
  COMMAND raylib-lua-sol
  raylib-lua-sol-tests.lua)

file(
  COPY raylib-lua-sol-tests.lua
  DESTINATION .
)
