cmake_minimum_required(VERSION 3.22.1)

project(
    simple_gtest
    VERSION 1.0.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
    DRIVER_INC_DIR
    "${CMAKE_SOURCE_DIR}/inc/"
)

set(
    MODULE_LIB
    "module"
)

enable_testing()

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/external/)
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest
    GIT_TAG v1.15.2
    GIT_SHALLOW TRUE
)


FetchContent_MakeAvailable(googletest)

add_subdirectory(test)
add_subdirectory(src)

