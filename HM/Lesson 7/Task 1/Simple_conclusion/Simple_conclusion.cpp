#include <iostream>
#include <string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

int function(std::string str, int forbidden_length) {
    try {
        if (str.length() != forbidden_length) return str.length();
        else throw "bad_lenght";
    }
    catch(const char*){
        throw;

    }
}

int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int lenght;
    std::cout << "Введите запретную длину: ";
    std::cin >> lenght;
    bool exit = false;

    while(!exit){
        try {
            std::string word;
            std::cout << "Введите слово: ";
            std::cin >> word;
            std::cout << "Длина слова \"" << word << "\" равна " << function(word, lenght) << std::endl;
        }
        catch(const char*){
            exit = true;
            std::cout << "Вы ввели слово запретной длины! До свидания";
        }
    }

    return 0;
}
