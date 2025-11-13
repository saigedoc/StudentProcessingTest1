cmake_minimum_required(VERSION 3.30)
project(StudentProcessing LANGUAGES CXX)

add_subdirectory(client)

add_subdirectory(server)

file(GLOB_RECURSE ALL_SOURCES "*.cpp" "*.h" "*.txt")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ALL_SOURCES})
