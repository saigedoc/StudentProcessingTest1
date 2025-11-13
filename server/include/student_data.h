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
    std::unique_ptr<std::ifstream> file_1;
    std::unique_ptr<std::ifstream> file_2;
public:
    explicit ProcessData(const std::string& filename_1, const std::string& filename_2);
    std::vector<std::string> get_data();
};

#endif