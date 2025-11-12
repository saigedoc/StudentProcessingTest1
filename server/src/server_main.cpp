#include <iostream>
#include "student_data.h"
int main() {
    ProcessData pd("student_file_1.txt", "student_file_2.txt");   // создаём объект
    std::vector<std::string> students_data = pd.get_data();            // вызываем метод

    for (int i = 0; i < students_data.size(); ++i){
        
        printf("%s\n", students_data[i].c_str());
    }

    return 0;
}