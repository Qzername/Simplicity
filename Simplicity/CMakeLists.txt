cmake_minimum_required(VERSION 4.1)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(SimplicityExamples LANGUAGES CXX)

add_subdirectory(Simplicity)
add_subdirectory(Examples/BasicWindow)