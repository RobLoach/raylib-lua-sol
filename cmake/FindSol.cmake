find_package(sol 3.0)
if (NOT sol_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    sol
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG e26475e75b0a116de95ce710b573989008b82a57
  )
  FetchContent_GetProperties(sol)
  if (NOT sol_POPULATED) # Have we downloaded sol2 yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(sol)
    add_subdirectory(${sol_SOURCE_DIR} ${sol_BINARY_DIR})
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${sol_SOURCE_DIR}/cmake" "${sol_SOURCE_DIR}/cmake/Modules")
  endif()
endif()
