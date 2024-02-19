#include <iostream>
#include <clocale>

enum class months {
    январь = 1,
    февраль,
    март,
    апрель,
    май,
    июнь,
    июль,
    август,
    сентябрь,
    октябрь,
    ноябрь,
    декабрь
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
        switch (static_cast<int>(number)) {
        case static_cast<int>(months::январь): std::cout << "Январь" << std::endl; break;
        case static_cast<int>(months::февраль): std::cout << "Февраль" << std::endl; break;
        case static_cast<int>(months::март): std::cout << "Март" << std::endl; break;
        case static_cast<int>(months::апрель): std::cout << "Апрель" << std::endl; break;
        case static_cast<int>(months::май): std::cout << "Май" << std::endl; break;
        case static_cast<int>(months::июнь): std::cout << "Июнь" << std::endl; break;
        case static_cast<int>(months::июль): std::cout << "Июль" << std::endl; break;
        case static_cast<int>(months::август): std::cout << "Август" << std::endl; break;
        case static_cast<int>(months::сентябрь): std::cout << "Сентябрь" << std::endl; break;
        case static_cast<int>(months::октябрь): std::cout << "Октябрь" << std::endl; break;
        case static_cast<int>(months::ноябрь): std::cout << "Ноябрь" << std::endl; break;
        case static_cast<int>(months::декабрь): std::cout << "Декабрь" << std::endl; break;
        case 0: exit = true;  std::cout << "До свидания"; break;
        default: std::cout << "Неправильный номер!" << std::endl; break;
        }
    } while (exit != true);
}