# Сначала создаём библиотеку (если нужно использовать код сервера в клиенте)
#add_library(server_lib STATIC src/student_data.cpp)

# Добавляем заголовки в область видимости
#target_include_directories(server_lib PUBLIC include)

# Создаём исполняемый файл сервера
add_executable(server_app src/server_main.cpp src/student_data.cpp)

# Связываем серверное приложение с библиотекой
#target_link_libraries(server_app PRIVATE server_lib)

# Установка имени выходного файла (опционально)
#set_target_properties(server_app PROPERTIES OUTPUT_NAME "server")
# Добавляем путь к заголовкам сервера
target_include_directories(server_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../server/include
)