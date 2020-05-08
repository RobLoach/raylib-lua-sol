local function describe(name, descriptor)
  local errors = {}
  local successes = {}
  function it(spec_line, spec)
    local status = xpcall(spec, function (err)
      table.insert(errors, string.format("\t%s\n\t\t%s\n", spec_line, err))
    end)
    if status then
      table.insert(successes, string.format("\t%s\n", spec_line))
    end
  end
  local status = xpcall(descriptor, function (err)
    table.insert(errors, err)
  end, it)
  print(name)
  if #successes > 0 then
    print('Successes:')
    print(table.concat(successes))
  end
  if #errors > 0 then
    print('Failures:')
    print(table.concat(errors))
    TraceLog(LOG_ERROR, 'Error count: ' .. #errors)
  end
end

describe('raylib-lua-sol Tests', function (it)
  it('Functions', function()
    assert(IsWindowFullscreen() == false, 'IsWindowFullscreen() should be false')
    assert(GetExtension('something.lua') == 'lua', 'GetExtension("something.lua") should return "lua"')
  end)

  it('Enumerations', function ()
    assert(FLAG_FULLSCREEN_MODE == 2, "FLAG_FULLSCREEN_MODE should equal 2")
  end)

  it('Structs', function ()
    local rect = Rectangle(10, 20, 30, 40)
    assert(rect.width == 30, "Rectangle width should be 30")
    rect.width = 500
    assert(rect.width == 500, "Rectangle width should be 500")

    local vec = Vector2(30, 40)
    assert(vec.x == 30)
  end)

  it ('Color', function ()
    assert(RAYWHITE.r == 245, "RAYWHITE should have 245 red")

    local c = Color(100, 100, 100, 255)
    assert(c.g == 100, "c.g should be 100")
  end)
end)
