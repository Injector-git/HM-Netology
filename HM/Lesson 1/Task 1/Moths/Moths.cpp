#include <iostream>
#include <clocale>

enum class months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    bool exit = false;
    do {
        std::cout << "Введите номер месяца:";
        std::cin >> number;
        months month = static_cast<months>(number);
        switch (static_cast<months>(number)) {
        case months::January: std::cout << "Январь" << std::endl; break;
        case months::February: std::cout << "Февраль" << std::endl; break;
        case months::March: std::cout << "Март" << std::endl; break;
        case months::April: std::cout << "Апрель" << std::endl; break;
        case months::May: std::cout << "Май" << std::endl; break;
        case months::June: std::cout << "Июнь" << std::endl; break;
        case months::July: std::cout << "Июль" << std::endl; break;
        case months::August: std::cout << "Август" << std::endl; break;
        case months::September: std::cout << "Сентябрь" << std::endl; break;
        case months::October: std::cout << "Октябрь" << std::endl; break;
        case months::November: std::cout << "Ноябрь" << std::endl; break;
        case months::December: std::cout << "Декабрь" << std::endl; break;
        case static_cast<months>(0): exit = true;  std::cout << "До свидания"; break;
        default: std::cout << "Неправильный номер!" << std::endl; break;
        }
    } while (exit != true);
}