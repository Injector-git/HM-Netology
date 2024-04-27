#pragma once

#include"RACE_DLL.h"
#include"Veh.h"
#include <iostream>

enum MenuType {// !!!!!!!!!!
    choose_race_type,
    race_distance,
    choose_action,
    registration,
    race_start,
    stop
};

class Race {
public:
    RACEDll_API int get_distance_length();
    RACEDll_API int get_action();
    RACEDll_API int get_vehicle_count();
    RACEDll_API Vehicle* get_vehicle();
    RACEDll_API int get_race_type();

    //тип гонки
    RACEDll_API void set_race_type();

    //длинна трассы и инициализация ТС
    RACEDll_API void set_distance_length();

    //
    RACEDll_API int action_selection();

    //длинна трассы и инициализация ТС
    RACEDll_API void set_vehicle();

    //Гонка
    RACEDll_API int race();

    RACEDll_API Race();

    RACEDll_API ~Race();

private:
    //переменные для инициализации ТС
    int distance_length;// Длинна пути 
    int action;//действие
    int vehicle_count;//кол-во машин
    const int  vehicle_type = 7;//Кол-во типов ТС
    Vehicle* vehicle;// ТС
    int* drivers;//Участнки гонки
    int race_type;// Тип гонки

    double time(Vehicle veh) {//просчет времени
        double time;
        if (veh.get_type() == ground) {
            time = static_cast<double>(distance_length) / veh.get_speed();

            int stop_counter = static_cast<int>(time) / veh.get_dtbr();//Кол-во остановок
            if (static_cast<int>(time) % veh.get_dtbr() == 0) stop_counter--;
            for (int i = 0; stop_counter > 0; i++) {
                if (i < 3) { time += veh.get_rest(i); stop_counter--; }
                else { time += veh.get_rest(2) * stop_counter; stop_counter = 0; }
            }
            return time;
        }
        else {
            return time = static_cast<double>(distance_length) * (1 - veh.get_distance_reduction()) / veh.get_speed();

        }
    }
};