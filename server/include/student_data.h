#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H

#include <string>
#include <memory>  // Для std::unique_ptr
#include <cstdio>  // Для std::FILE
#include <stdexcept>  // Для std::runtime_error
#include <algorithm>  // Для std::sort
#include <vector>     // Для std::vector
#include <iostream>
#include <fstream>
#include <cerrno>  // Для errno
#include <cstring> // Для std::strerror
class ProcessData {
private:
    // Внутренняя реализация: smart pointer для автоматического закрытия файла
    //std::unique_ptr<std::ifstream, decltype(&std::fclose)> file_1 = std::make_unique<std::ifstream>;
    std::unique_ptr<std::ifstream> file_1;
    std::unique_ptr<std::ifstream> file_2;

    // Метод для чтения строки из файла (const-correctness)
    //std::string read_line() const;

public:
    // Конструктор: открывает файл, бросает исключение при ошибке
    explicit ProcessData(const std::string& filename_1, const std::string& filename_2);

    // Деструктор: автоматически закрывает файл (RAII)
    //~ProcessData() = default;  // unique_ptr сам вызовет fclose

    std::vector<std::string> get_data();
    
};

#endif