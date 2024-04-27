#include <iostream>
#include "MyMath.h"
#include <Windows.h>//для корректной работы кириллицы со стрингом

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double value1;
    std::cout << "Введите первое число: ";
    std::cin >> value1;
    std::cout << std::endl;
    double value2;
    std::cout << "Введите второе  число: ";
    std::cout << std::endl;
    std::cin >> value2;

    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): " << std::endl;
    int m;
    std::cin >> m;

    switch (m)
    {
    case 1: std::cout << value1 << " + " << value2 << " = " << add(value1, value2);
        break;
    case 2: std::cout << value1 << " - " << value2 << " = " << sub(value1, value2);
        break;
    case 3: std::cout << value1 << " * " << value2 << " = " << mult(value1, value2);
        break;
    case 4: std::cout << value1 << " / " << value2 << " = " << div(value1, value2);
        break;
    case 5: std::cout << value1 << " в степени " << value2 << " = " << pow(value1, value2);
        break;
    default:
        break;
    }

    return 0;
}