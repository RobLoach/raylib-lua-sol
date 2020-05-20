package.cpath = package.cpath .. ";./?.so"
r = require "raylib-lua-sol"

obj = r.test.new(24)
print(obj.value)
