cmake_minimum_required(VERSION 3.20)

project(Arkanoid)

set(CMAKE_CXX_STANDARD 23)

include(CMake/CPM.cmake)

# CPMAddPackage("gh:libsdl-org/SDL#release-3.2.8")
CPMAddPackage(GITHUB_REPOSITORY libsdl-org/SDL GIT_TAG release-3.2.8 OPTIONS "SDL_STATIC ON")

add_subdirectory(src)