add_executable(raylib-lua-sol raylib-lua-sol.cpp)

target_compile_definitions(raylib-lua-sol PUBLIC -DLUA)

set_target_properties(raylib-lua-sol PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)

# GCC 15+ diagnoses uninstantiated sol2 templates as errors (-Wtemplate-body).
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag(-Wno-template-body HAVE_WNO_TEMPLATE_BODY)
if (HAVE_WNO_TEMPLATE_BODY)
  target_compile_options(raylib-lua-sol PRIVATE -Wno-template-body)
endif()

target_link_libraries(raylib-lua-sol
  raylib-lua-sol-hpp
  raylib
  lua
  sol2
)

target_include_directories(raylib-lua-sol PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/../include
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/lua
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/raylib/src
  ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/sol2/include
)
