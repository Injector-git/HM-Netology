#include <iostream>
#include "Greeter.h"
#include "Leaver.h"
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//для корректной работы кириллицы со стрингом

    setlocale(LC_ALL, "Rus");
    Greeter gr;
    Leaver lv;
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    gr.greet(name);
    std::cout << std::endl;
    lv.leave(name);
}
