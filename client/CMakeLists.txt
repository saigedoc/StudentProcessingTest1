cmake_minimum_required(VERSION 3.30)
project(Server LANGUAGES CXX)


add_executable(client_app src/client_main.cpp)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "vcpkg toolchain loaded: ${VCPKG_TARGET_TRIPLET}")

find_package(cppzmq REQUIRED)

target_link_libraries(client_app PRIVATE cppzmq cppzmq-static)

target_include_directories(client_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../client/include
)