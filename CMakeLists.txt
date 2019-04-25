cmake_minimum_required(VERSION 3.11)
project (raylib-lua-sol2)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include_directories(include)

add_subdirectory(bin)

include(CTest)
enable_testing()
if(BUILD_TESTING)
	add_subdirectory(tests)
endif()