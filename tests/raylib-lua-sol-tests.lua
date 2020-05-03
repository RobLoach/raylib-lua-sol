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
  it('IsWindowFullscreen()', function ()
    assert(IsWindowFullscreen() == false, 'IsWindowFullscreen() should be false')
  end)

  it('GetExtension()', function ()
    assert(GetExtension('something.lua') == 'lua', 'GetExtension("something.lua") should return "lua"')
  end)

  it('FLAG_FULLSCREEN_MODE', function ()
    assert(FLAG_FULLSCREEN_MODE == 2, "FLAG_FULLSCREEN_MODE should equal 2")
  end)
end)
