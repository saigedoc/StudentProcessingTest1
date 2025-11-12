#include "student_data.h"

ProcessData::ProcessData(const std::string& filename_1, const std::string& filename_2){
    file_1 = std::make_unique<std::ifstream>(filename_1);
    file_2 = std::make_unique<std::ifstream>(filename_2);
    std::string error_text = "";
    if (!file_1 or !(*file_1)) {
        error_text += filename_1 + ", ";
    }
    if (!file_2 or !(*file_2)) {
        error_text += filename_2 + ".";
    }
    if (!file_1  or !(*file_1) or !file_2 or !(*file_2)){
        error_text = "Failed to open files: " + error_text;
        throw std::runtime_error(error_text + " Error: " + std::strerror(errno));
    }
    //students_1 = std::unique_ptr<std::ifstream, decltype(&std::fclose)>(file_1, &std::fclose);
    //students_2 = std::unique_ptr<std::ifstream, decltype(&std::fclose)>(file_2, &std::fclose);
}

std::vector<std::string> ProcessData::get_data(){
    std::vector<std::string> students;
    std::string line;
    std::string new_line;
    std::vector<std::string> result;
    while (std::getline(*file_1, line)) {
        printf("%s\n", line);
        students.push_back(line.substr(line.find(" ") + 1));
    }
    while (std::getline(*file_2, line)) {
        //printf("%s\n", line);
        new_line = line.substr(line.find(" ") + 1);
        auto it = std::find(students.begin(), students.end(), new_line);
        if (it == students.end()) {
            students.push_back(new_line);
        }
        printf("test\n");
        printf("%s\n", new_line);
    }
    
    std::sort(students.begin(), students.end());
    for (int i=0; i < students.size(); ++i) {
        students[i] = std::to_string(i + 1) + " " +students[i];
    }
    return result;
}

