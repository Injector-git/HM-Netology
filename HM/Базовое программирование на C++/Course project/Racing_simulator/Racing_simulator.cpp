#include <iostream>
#include <string>
#include <Windows.h>
#include "Race.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//для корректной работы кириллицы со стрингом

    std::cout << "Добро пожаловать в гоночный симулятор" << std::endl;

    int menu = choose_race_type;//какое меню включать

    Race race;

    do {
        switch (menu)
        {

        case choose_race_type: //Выбрать тип гонки

            race.set_race_type();
            menu = race_distance;
            break;

        case race_distance: //Установить длинну трассы
            race.set_distance_length();
            menu = choose_action;
            break;

        case choose_action: //Выбор действия
            menu = race.action_selection();
            break;

        case registration: //Ввод типов ТС 
            race.set_vehicle();
            menu = choose_action;
            break;

        case race_start: //Гонка
            menu = race.race();
            break;
        default:
            break;
        }

        system("cls");// ОТЧИСТКА КОНСОЛИ

    } while (menu != static_cast<int>(stop));
    return 0;
}
