#include <iostream>
#include <string>
#include <Windows.h>

#define ground true
#define air false

int vehicle_count;//кол-во машин
int action;//действие

enum MenuType {
    choose_race_type,
    race_distance,
    choose_action,
    drivers,//vehicle уже занято
    race_start,
    stop
};

class Vehicle { // ТС
public:
    std::string get_name() { return name; }
    bool get_type() { return type; }
    int get_speed() { return speed; }
    int get_dtbr() { return dtbr; }
    double  get_rest(int time) { return rest[time]; }
    virtual double get_distance_reduction(int distance) { return distance_reduction; }

protected:
    std::string name;
    bool type;// наземный/воздух
    int speed;
    int dtbr; // Driving time before rest(Время движения до отдыха)
    double rest[3]{0,0,0}; // Отдых
    double distance_reduction = 0; // Коэффициент сокращения расстояния
};

class Camel : public Vehicle{
public:
    Camel() {
        name = "Верблюд";
        type = ground;
        speed = 10;
        dtbr = 30;
        rest[0]=5; rest[1] = 8; rest[2] = 8;
    }
};

class SpeedCamel : public Vehicle {
public:
    SpeedCamel() {
        name = "Верблюд-быстроход";
        type = ground;
        speed = 40;
        dtbr = 10;
        rest[0] = 5; rest[1] = 6,5; rest[2] = 8;
    }
};

class Centaur : public Vehicle {
public:
    Centaur() {
        name = "Кентавр";
        type = ground;
        speed = 15;
        dtbr = 8;
        rest[0] = 2; rest[1] = 2; rest[2] = 2;
    }
};

class AllTerrainBoots : public Vehicle {
public:
    AllTerrainBoots() {
        name = "Ботинки-вездеходы";
        type = ground;
        speed = 6;
        dtbr = 60;
        rest[0] = 10; rest[1] = 5; rest[2] = 5;
    }
};

class CarpetPlane : public Vehicle {
public:
    CarpetPlane() {
        name = "Ковёр-самолёт";
        type = air;
        speed = 6;
    }
    double get_distance_reduction(int distance) override {
        if (distance < 1000)  return distance_reduction = 1;
        else if (distance < 5000) return distance_reduction = 0.03;
        else if (distance < 10000)  return distance_reduction = 0.1;
        else if (distance >= 10000)  return distance_reduction = 0.05;
    }
    /*CarpetPlane(int distance) : CarpetPlane() {
        if(distance < 1000) distance_reduction = 1;
        else if (distance < 5000) distance_reduction = 0.03;
        else if (distance < 10000) distance_reduction = 0.1;
        else if (distance >= 10000) distance_reduction = 0.05;
    }*/
};

class Eagle : public Vehicle {
public:
    Eagle() {
        name = "Орёл";
        type = air;
        speed = 8;
        distance_reduction = 0, 06;
    }
};

class Broom : public Vehicle {
public:
    Broom() {
        name = "Метла";
        type = air;
        speed = 8;
    }
    double get_distance_reduction (int distance) override {
        return distance_reduction = distance / 1000;
    }
    /*Broom(int distance) : Broom() {
        distance_reduction = distance / 1000;
    }*/
};

Vehicle which_vehicle(int number) {
    switch (number)
    {
    case 1: return AllTerrainBoots();
        break;
    case 2: return Broom();
        break;
    case 3: return Camel();
        break;
    case 4: return Centaur();
        break;
    case 5: return Eagle();
        break;
    case 6: return SpeedCamel();
        break;
    case 7: return CarpetPlane();
        break;
    default:
        //throw
        break;
    }
}

int set_race_type() {
    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

    std::cout << "Выберите тип гонки: "; std::cin >> action; std::cout << std::endl;
    return action;
}

int set_distance_length() {
    int distance_length;// Длинна пути 
    std::cout << "Укажите длинну дистанции (должна быть положительной): "; std::cin >> distance_length; std::cout << std::endl;
    return distance_length;
}

int action_selection(int* vehicle) {
    if (vehicle_count < 2)std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства" << std::endl;
    std::cout << "1. Зарегистрировать транспорт" << std::endl;
    if (vehicle_count > 1) std::cout << "2. Начать гонку" << std::endl;
    std::cout << "Выберите дествие: "; std::cin >> action; std::cout << std::endl;

    if (action == 1) return drivers;
    else if (action == 2) return race_start;
    
}

int* set_vehicle(int race, int distance_length,  int* vehicle) {

    vehicle_count = 0;
    int vehicle_type = 1;
    bool reg = false;//Успех рег ТС *

    while (vehicle_type != 0) {//Начало ввода типов ТС

        if (vehicle_count != 0) {//если ли ТС
            if (race == 1 && (vehicle_type == 2 || vehicle_type == 5 || vehicle_type == 7)) {//проверка на заземленме
                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                vehicle_count--;//Неуспешная рег ТС
                reg = false;
            }
            else if (race == 2 && (vehicle_type == 1 || vehicle_type == 3 || vehicle_type == 4 || vehicle_type == 6)) {//проверка на воздушность
                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                vehicle_count--;//Неуспешная рег ТС
                reg = false;
            }

            for (int i = 0; i < vehicle_count; i++)//проверка на повтор ТС
                if (vehicle_type == vehicle[i]) {
                    std::cout << which_vehicle(vehicle_type).get_name() << " Уже зарегистрирован" << std::endl;
                    vehicle_count--;//Неуспешная рег ТС
                    reg = false;
                    break;
                }

            if (reg == true) {
                std::cout << which_vehicle(vehicle_type).get_name() << " Успешно зарегестрирован!" << std::endl;
                vehicle[vehicle_count - 1] = vehicle_type;//Успешная рег ТС
            }
        }

        switch (race)
        {
        case 1:
            std::cout << "Гонка для наземного транспорта Растояние: ";
            break;
        case 2:
            std::cout << "Гонка для воздушного транспорта Растояние: ";
            break;
        case 3:
            std::cout << "Гонка для наземного и воздушного транспорта Растояние: ";
            break;
        default:
            break;
        }
        std::cout << distance_length << std::endl;

        if (vehicle_count != 0) {
            std::cout << "Зарегистрированные транспортные средства: ";
            for (int i = 0; i < vehicle_count; i++) std::cout << which_vehicle(vehicle[i]).get_name() << " "; //сделать , !!!!!!!
            std::cout << std::endl;
        }

        for (int i = 1; i < sizeof(vehicle); i++)
        {
            std::cout << i << ". " << which_vehicle(i).get_name() << std::endl;
        }
        std::cout << "0. Закончить регистрацию" << std::endl;
        std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> vehicle_type; std::cout << std::endl;
        if (vehicle_type != 0)
        {
            vehicle_count++;
            reg = true;
        }

        system("cls");// ОТЧИСТКА КОНСОЛИ
    }// Конец ввода ТС
    return vehicle;

}

int time(Vehicle veh, int distance_lenght) {
    double time = distance_lenght / veh.get_speed();
    double rest_time;
    int stop_counter = static_cast<int>(time) / veh.get_dtbr();

    if (veh.get_type() == ground) {
        for (int i = 0; i < stop_counter; i++) {
            if (i < 3) rest_time = veh.get_rest(i);
            else rest_time = veh.get_rest(2);
            time += rest_time;
        }
        return time;
    }
    else {
        time -= time * veh.get_distance_reduction(distance_lenght);
        return time;
    }

}

int  race(int* vehicle, int distance_lenght) {
    Vehicle veh;
    std::cout << "Результаты гонки:" << std::endl;
    for (int i = 0; i < vehicle_count; i++) {
        Vehicle veh = which_vehicle(vehicle[i]);
        std::cout << veh.get_name() << "." << " Время: " << time(veh, distance_lenght) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "1. Провести еще одну гонку" << std::endl;
    std::cout << "2. Выйти" << std::endl;
    std::cout << "Выберите дествие: "; std::cin >> action; std::cout << std::endl;

    vehicle_count=0;//сброс кол-ва ТС
    for (int i = 0; i < sizeof(vehicle); i++) {//сброс масства ТС
        vehicle[i] = 0;
    }
    if (action == 1) return choose_race_type;
    else if (action == 2) return stop;
} 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//для корректной работы кириллицы со стрингом


    std::cout << "Добро пожаловать в гоночный симулятор" << std::endl;

    //Vehicle* drivers = new Vehicle[7];//7 ТС
    // 
    //переменные для инициализации ТС
    int vehicle[7];//7  ТС
    int race_type;// Тип гонки
    int distance_length;// Длинна пути 
    int menu= choose_race_type;//какое меню включать

    /* инициализация всех ТС
    AllTerrainBoots boots;
    Broom broom;
    Camel camel;
    Centaur cent;
    Eagle eagle;
    SpeedCamel scamel;
    CarpetPlane carpet;*/

    do {
        switch (menu)
        {
            case choose_race_type: //Выбрать тип гонки
                race_type = set_race_type();
                menu = race_distance;
                break;

            case race_distance: //Установить длинну трассы
                distance_length = set_distance_length();
                menu = choose_action;
                break;

            case choose_action: //Выбор действия
                menu = action_selection(vehicle);
                break;

            case drivers: //Ввод типов ТС 
                set_vehicle(race_type, distance_length, vehicle);//(не нужно приcваивать массив так как он с ним и работает)
                menu = choose_action;
                break;

            case race_start: //Ввод типов ТС 
                menu = race(vehicle, distance_length);
                break;
        default:
            break;
        }

        system("cls");// ОТЧИСТКА КОНСОЛИ

       /*while (vehicle != 0) {//Начало ввода типов ТС

            if (drivers_count != 0) {//если ли ТС
                if (race == 1 && (vehicle == 2 || vehicle == 5 || vehicle == 7)) {//проверка на заземленме
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                    drivers_count--;//Неуспешная рег ТС
                    reg = false;
                }
                else if (race == 2 && (vehicle == 1 || vehicle == 3 || vehicle == 4 || vehicle == 6)) {//проверка на воздушность
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                    drivers_count--;//Неуспешная рег ТС
                    reg = false;
                }

                for (int i = 0; i < drivers_count; i++)//проверка на повтор ТС
                    if (vehicle == drivers[i]) {
                        std::cout << which_vehicle(vehicle) << " Уже зарегистрирован" << std::endl;
                        drivers_count--;//Неуспешная рег ТС
                        reg = false;
                        break;
                    }

                if (reg == true) {
                    std::cout << which_vehicle(vehicle) << " Успешно зарегестрирован!" << std::endl;
                    drivers[drivers_count - 1] = vehicle;//Успешная рег ТС
                }
            }
                        
            switch (race)
            {
            case 1:
                std::cout << "Гонка для наземного транспорта Растояние: ";
                break;
            case 2:
                std::cout << "Гонка для воздушного транспорта Растояние: ";
                break;
            case 3:
                std::cout << "Гонка для наземного и воздушного транспорта Растояние: ";
                break;
            default:
                break;
            }
            std::cout << distance_length << std::endl;

            if (drivers_count != 0) {
                std::cout << "Зарегистрированные транспортные средства: ";
                for (int i = 0; i < drivers_count; i++) std::cout << which_vehicle(drivers[i]) << " "; //сделать , 
                std::cout << std::endl;
            }

            std::cout << "1. " << boots.get_name() << std::endl;//ground
            std::cout << "2. " << broom.get_name() << std::endl;//air
            std::cout << "3. " << camel.get_name() << std::endl;//ground
            std::cout << "4. " << cent.get_name() << std::endl;//ground
            std::cout << "5. " << eagle.get_name() << std::endl;//air
            std::cout << "6. " << scamel.get_name() << std::endl;//ground
            std::cout << "7. " << carpet.get_name() << std::endl;//air
            std::cout << "0.  Закончить регистрацию" << std::endl;
            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> vehicle; std::cout << std::endl;
            drivers_count++;
            reg = true;
            system("cls");// ОТЧИСТКА КОНСОЛИ
        }// Конец ввода тс */ 
        
    } while (menu != static_cast<int>(stop));
    return 0;
}
