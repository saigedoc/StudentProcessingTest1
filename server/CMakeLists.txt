cmake_minimum_required(VERSION 3.30)
project(Server LANGUAGES CXX)

add_executable(server_app src/server_main.cpp src/student_data.cpp)

find_package(cppzmq REQUIRED)

target_link_libraries(server_app PRIVATE cppzmq cppzmq-static)

target_include_directories(server_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../server/include
)