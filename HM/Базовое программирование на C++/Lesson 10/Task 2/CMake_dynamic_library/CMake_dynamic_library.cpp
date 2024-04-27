// CMake_dynamic_library.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Leaver.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//для корректной работы кириллицы со стрингом

    setlocale(LC_ALL, "Rus");
    Leaver lv;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    lv.leave(name);
}
