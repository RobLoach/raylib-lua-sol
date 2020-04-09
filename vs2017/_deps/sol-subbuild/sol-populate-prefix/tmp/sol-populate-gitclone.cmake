
if(NOT "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitinfo.txt" IS_NEWER_THAN "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "D:/Program Files/Git/cmd/git.exe"  clone --no-checkout "https://github.com/ThePhD/sol2.git" "sol-src"
    WORKING_DIRECTORY "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/ThePhD/sol2.git'")
endif()

execute_process(
  COMMAND "D:/Program Files/Git/cmd/git.exe"  checkout b0c74207d8d86b6d6b6137252bb6494f33947a25 --
  WORKING_DIRECTORY "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'b0c74207d8d86b6d6b6137252bb6494f33947a25'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "D:/Program Files/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitinfo.txt"
    "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-subbuild/sol-populate-prefix/src/sol-populate-stamp/sol-populate-gitclone-lastrun.txt'")
endif()

