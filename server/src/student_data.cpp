#include "student_data.h"

ProcessData::ProcessData(const std::string& filename_1, const std::string& filename_2){
    
    file_1 = std::make_unique<std::ifstream>(filename_1);
    file_2 = std::make_unique<std::ifstream>(filename_2);
    std::string error_text = "";
    if (!file_1 || !(*file_1)) {
        error_text += filename_1 + ", ";
    }
    if (!file_2 || !(*file_2)) {
        error_text += filename_2 + ".";
    }
    if (!file_1  || !(*file_1) || !file_2 || !(*file_2)){
        error_text = "Failed to open files: " + error_text;
        throw std::runtime_error(error_text);
    }
}

std::vector<std::string> ProcessData::get_data(){
    std::vector<std::string> students;
    std::string line;
    std::string new_line;

    int file_1_status = -1;
    while (true) {
        bool line_status = static_cast<bool> (std::getline(*file_1, line));
        if (!line_status && file_1_status == -1){
            file_1_status = 1;
            break;
        }
        else if (!line_status){
            break;
        }
        else{
            file_1_status = 0;
        }
        students.push_back(line.substr(line.find(" ") + 1));
    }
    int file_2_status = -1;
    while (true) {
        bool line_status = static_cast<bool> (std::getline(*file_2, line));
        if (!line_status && file_2_status == -1){
            file_2_status = 1;
            break;
        }
        else if (!line_status){
            break;
        }
        else{
            file_2_status = 0;
        }
        new_line = line.substr(line.find(" ") + 1);
        auto it = std::find(students.begin(), students.end(), new_line);
        if (it == students.end()) {
            students.push_back(new_line);
        }
    }
    if ((file_1_status == 1) || (file_2_status == 1)){
        throw std::runtime_error("One of used files are empty.");
    }
    std::sort(students.begin(), students.end());
    for (int i=0; i < students.size(); ++i) {
        students[i] = std::to_string(i + 1) + " " + students[i];
    }
    return students;
}

