#include <iostream>
#include "student_data.h"
#include <Windows.h>
int main() {
    //SetConsoleCP(65001);// установка кодовой страницы win-cp 1251 в поток ввода
    //SetConsoleOutputCP(65001); // установка кодовой страницы win-cp 1251 в поток вывода
    SetConsoleOutputCP(CP_UTF8);
    printf("FUCK\n");
    ProcessData pd("student_file_1.txt", "student_file_2.txt");   // создаём объект
    std::vector<std::string> students_data = pd.get_data();            // вызываем метод

    printf("Start\n");
    printf("%s", students_data.size());
    for (int i = 0; i < students_data.size(); ++i){
        
        printf("1%s\n", students_data[i].c_str());
    }
    printf("Done\n");
    //std::cout << "Name: " << obj.getName() << "\n";

    return 0;
}