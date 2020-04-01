find_package(sol 3.0)
if (NOT sol_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    sol
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG b0c74207d8d86b6d6b6137252bb6494f33947a25
  )
  FetchContent_GetProperties(sol)
  if (NOT sol_POPULATED) # Have we downloaded sol2 yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sol)
    add_subdirectory(${sol_SOURCE_DIR} ${sol_BINARY_DIR})
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${sol_SOURCE_DIR}/cmake" "${sol_SOURCE_DIR}/cmake/Modules")
  endif()
endif()
