# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.17.0)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(sol-populate NONE)

include(ExternalProject)
ExternalProject_Add(sol-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/ThePhD/sol2.git" "GIT_TAG" "b0c74207d8d86b6d6b6137252bb6494f33947a25"
                    SOURCE_DIR          "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-src"
                    BINARY_DIR          "D:/Documents/PROJECTS/raylib-lua-sol/build/_deps/sol-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
