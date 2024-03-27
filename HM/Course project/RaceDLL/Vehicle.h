#pragma once
#include <string>
#include"RACE_DLL.h"

#define ground true
#define air false

class Vehicle { // ТС
public:

    RACEDll_API int get_id();
    RACEDll_API std::string get_name();
    RACEDll_API bool get_type();
    RACEDll_API int get_speed();
    RACEDll_API int get_dtbr();
    RACEDll_API double  get_rest(int time);
    RACEDll_API double get_distance_reduction();

    RACEDll_API Vehicle();

protected:
    int id;// !!!!!!!
    std::string name;
    bool type;// наземный/воздух
    int speed;
    int dtbr; // Driving time before rest(Время движения до отдыха)
    double rest[3]; // Отдых
    double distance_reduction;// Коэффициент сокращения расстояния
};

