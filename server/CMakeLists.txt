cmake_minimum_required(VERSION 3.30)
project(Server LANGUAGES CXX)
# Сначала создаём библиотеку (если нужно использовать код сервера в клиенте)
#add_library(server_lib STATIC src/student_data.cpp)

# Добавляем заголовки в область видимости
#target_include_directories(server_lib PUBLIC include)

# Создаём исполняемый файл сервера
add_executable(server_app src/server_main.cpp src/student_data.cpp)

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "CMAKE_FIND_ROOT_PATH: ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "vcpkg toolchain loaded: ${VCPKG_TARGET_TRIPLET}")

find_package(cppzmq REQUIRED)

# Связываем серверное приложение с библиотекой
#target_link_libraries(server_app PRIVATE server_lib)
target_link_libraries(server_app PRIVATE cppzmq cppzmq-static)
# Установка имени выходного файла (опционально)
#set_target_properties(server_app PROPERTIES OUTPUT_NAME "server")
# Добавляем путь к заголовкам сервера
target_include_directories(server_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../server/include
)