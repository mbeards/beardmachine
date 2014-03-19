cmake_minimum_required (VERSION 2.6)

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

project(beardmachine)

file(GLOB_RECURSE beardmachine_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_executable(beardmachine ${beardmachine_SOURCES})
