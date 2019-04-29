find_package(sol2 2.0 QUIET)
if (NOT sol2_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG 2d470857b42e8ef48b749c57308b1458f424f5db
  )
  FetchContent_GetProperties(sol2)
  if (NOT sol2_POPULATED) # Have we downloaded sol2 yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sol2)
    add_subdirectory(${sol2_SOURCE_DIR} ${sol2_BINARY_DIR})
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${sol2_SOURCE_DIR}/cmake" "${sol2_SOURCE_DIR}/cmake/Modules")
  endif()
endif()
