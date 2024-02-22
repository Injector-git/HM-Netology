﻿#include <iostream>
#include <string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class Counter {
private:
    int value;
public:
    Counter() { value = 1; }
    Counter(int value) { this->value = value; }
    void increment() {
        value++;
    }
    void decrement() {
        value--;
    }
    void print() {
        std::cout << value << std::endl;
    }
};

int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string start_value;
    char command;
    bool exit = false;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: " << std::endl;
    std::cin >> start_value;
    if (start_value == "да") {
        int value;
        std::cout << "Введите начальное значение счётчика: " << std::endl;
        std::cin >> value;
        Counter counter(value);
    }
    else Counter counter;

    do{
        std::cout << "Введите команду ('+', '-', '=' или 'x'): " << std::endl;
        std::cin >> command;
        switch (command)
        {
        case '+': counter.increment();
            break;
        case '-': counter.decrement();
            break; 
        case '=': counter.print();
            break; 
        case 'x': exit = true;
            break; 
        default:
            break;
        }

    }while (exit==false);
    std::cout << "До свидания";
}