# Add catch tests macro
macro(ADD_CATCH_TESTS executable)
  get_target_property(target_files ${executable} SOURCES)

  message("Files: ${target_files}")

  foreach(source ${target_files})
    if(NOT "${source}" MATCHES "/moc_.*cxx")
      string(REGEX MATCH .*cpp source "${source}")
      if(source)
        file(READ "${source}" contents)
        string(REGEX MATCHALL "TEST_CASE\\([ ]*\"[^\"]+\"" found_tests ${contents})
        foreach(hit ${found_tests})
          message("Found Test: ${hit}")
          string(REGEX REPLACE "TEST_CASE\\([ ]*(\"[^\"]+\").*" "\\1" test_name ${hit})
          add_test(${test_name} "${executable}" ${test_name})
          set_tests_properties(${test_name} PROPERTIES TIMEOUT 660 ENVIRONMENT "PATH=${NEWPATH}")
        endforeach()
      endif()
    endif()
  endforeach()
endmacro()

find_package(lua)
find_package(raylib)
find_package(sol2)

list(APPEND SOURCES catch.hpp raylib-lua-sol_test.cpp)
list(APPEND LIBS raylib)
list(APPEND LIBS ${LUA_LIBRARY})
list(APPEND LIBS sol2)

add_executable(raylib-lua-sol_test ${SOURCES})

# C++17
set_target_properties(raylib-lua-sol_test PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

target_compile_definitions(raylib-lua-sol_test PUBLIC -DLUA)

#target_include_directories(raylib_test PUBLIC
#    ${raylib_SOURCE_DIR}/src
#    ${sol_SOURCE_DIR}/include
#    ${LUA_INCLUDE_DIR}
#)

target_link_libraries(raylib-lua-sol_test
  libraylib-lua-sol
  raylib
  sol2
  ${LUA_LIBRARY}
)

ADD_CATCH_TESTS(raylib-lua-sol_test)
