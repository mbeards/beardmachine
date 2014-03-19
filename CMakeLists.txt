cmake_minimum_required (VERSION 2.6)

project(beardmachine)

file(GLOB_RECURSE beardmachine_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

add_executable(beardmachine ${beardmachine_SOURCES})
