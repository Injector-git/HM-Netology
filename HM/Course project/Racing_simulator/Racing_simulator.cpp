#include <iostream>
#include <string>
#include <Windows.h>

#define ground true
#define air false



enum MenuType {
    choose_race_type,
    race_distance,
    choose_action,
    registration,
    race_start,
    stop
};

class Vehicle { // ТС
public:

    int get_id() { return id; }
    std::string get_name() { return name; }
    bool get_type() { return type; }
    int get_speed() { return speed; }
    int get_dtbr() { return dtbr; }
    double  get_rest(int time) { return rest[time]; }
    double get_distance_reduction() { return distance_reduction; }

    Vehicle() {
        id = 0;
        name = "ТС";
        type = ground;
        speed = -1;
        dtbr = -1;
        distance_reduction = -1;
    }
protected:
    int id;// !!!!!!!
    std::string name;
    bool type;// наземный/воздух
    int speed;
    int dtbr; // Driving time before rest(Время движения до отдыха)
    double rest[3]; // Отдых
    double distance_reduction;// Коэффициент сокращения расстояния
};

class AllTerrainBoots : public Vehicle {
public:
    AllTerrainBoots() {
        id = 1;
        name = "Ботинки-вездеходы";
        type = ground;
        speed = 6;
        dtbr = 60;
        rest[0] = 10; rest[1] = 5; rest[2] = 5;
    }
};

class Broom : public Vehicle {
public:
    Broom() {
        id = 2;
        name = "Метла";
        type = air;
        speed = 20;
    }
    Broom(int distance) : Broom() {
        distance_reduction = (distance / 1000)/100.0;
    }
};

class Camel : public Vehicle{
public:
    Camel() {
        id = 3;
        name = "Верблюд";
        type = ground;
        speed = 10;
        dtbr = 30;
        rest[0]=5; rest[1] = 8; rest[2] = 8;
    }
};

class Centaur : public Vehicle {
public:
    Centaur() {
        id = 4;
        name = "Кентавр";
        type = ground;
        speed = 15;
        dtbr = 8;
        rest[0] = 2; rest[1] = 2; rest[2] = 2;
    }
};

class Eagle : public Vehicle {
public:
    Eagle() {
        id = 5;
        name = "Орёл";
        type = air;
        speed = 8;
        distance_reduction = 0.06;
    }
};

class SpeedCamel : public Vehicle {
public:
    SpeedCamel() {
        id = 6;
        name = "Верблюд-быстроход";
        type = ground;
        speed = 40;
        dtbr = 10;
        rest[0] = 5; rest[1] = 6.5; rest[2] = 8;
    }
};

class CarpetPlane : public Vehicle {
public:
    CarpetPlane() {
        id = 7;
        name = "Ковёр-самолёт";
        type = air;
        speed = 10;
    }
    CarpetPlane(int distance) : CarpetPlane() {
        if(distance < 1000) distance_reduction = 0;
        else if (distance < 5000) distance_reduction = 0.03;
        else if (distance < 10000) distance_reduction = 0.1;
        else if (distance >= 10000) distance_reduction = 0.05;
    }
};

class Race {
public:
    int get_distance_length() { return distance_length; }
    int get_action() { return action; }
    int get_vehicle_count() { return vehicle_count; }
    Vehicle* get_vehicle() { return vehicle; }
    int get_race_type() { return race_type; }

    //тип гонки
    void set_race_type() {
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        std::cout << "Выберите тип гонки: "; std::cin >> race_type; std::cout << std::endl;
    }

    //длинна трассы и инициализация ТС
    void set_distance_length() {
        std::cout << "Укажите длинну дистанции (должна быть положительной): "; std::cin >> distance_length; std::cout << std::endl;
        /*
        vehicle[Camel().get_id()] = Camel();
        vehicle[SpeedCamel().get_id()] = SpeedCamel();
        vehicle[Centaur().get_id()] = Centaur();
        vehicle[AllTerrainBoots().get_id()] = AllTerrainBoots();
        vehicle[CarpetPlane().get_id()] = CarpetPlane(distance_length);
        vehicle[Eagle().get_id()] = Eagle();
        vehicle[Broom().get_id()] = Broom(distance_length);
        */
        vehicle[0] = AllTerrainBoots();
        vehicle[1] = Broom(distance_length);
        vehicle[2] = Camel();
        vehicle[3] = Centaur();
        vehicle[4] = Eagle();
        vehicle[5] = SpeedCamel();
        vehicle[6] = CarpetPlane(distance_length);
    }

    //
    int action_selection() {
        if (vehicle_count < 2)std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства" << std::endl;
        std::cout << "1. Зарегистрировать транспорт" << std::endl;
        if (vehicle_count > 1) std::cout << "2. Начать гонку" << std::endl;
        std::cout << "Выберите дествие: "; std::cin >> action; std::cout << std::endl;

        if (action == 1) return registration;
        else if (action == 2) return race_start;
    }

    //Ввод типов ТС 
    void set_vehicle() {

        action = 1;
        bool reg = false;//Успех рег ТС

        while (action != 0) {//Начало ввода типов ТС

            if (reg == true) {//попытка регистрации
                if (race_type == 1 && (action == 2 || action == 5 || action == 7)) {//проверка на заземленме
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                    vehicle_count--;//Неуспешная рег ТС
                    reg = false;
                }
                else if (race_type == 2 && (action == 1 || action == 3 || action == 4 || action == 6)) {//проверка на воздушность
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                    vehicle_count--;//Неуспешная рег ТС
                    reg = false;
                }

                for (int i = 0; i < vehicle_count; i++)//проверка на повтор ТС
                    if (action-1 == drivers[i]) {
                        std::cout << vehicle[drivers[i]].get_name() << " Уже зарегистрирован" << std::endl;
                        vehicle_count--;//Неуспешная рег ТС
                        reg = false;
                        break;
                    }

                if (reg == true) {
                    std::cout << vehicle[action-1].get_name() << " Успешно зарегестрирован!" << std::endl;
                    drivers[vehicle_count - 1] = action-1;//Успешная рег ТС
                }
            }

            switch (race_type)
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

            if (vehicle_count > 0) {
                std::cout << "Зарегистрированные транспортные средства: ";
                for (int i = 0; i < vehicle_count; i++) {
                    std::cout << vehicle[drivers[i]].get_name();
                    if (vehicle_count > 1 && i != vehicle_count-1) std::cout << ", ";
                }
                std::cout << std::endl;
            }

            for (int i = 0; i < vehicle_type; i++)// Отрисовка типов ТС
            {
                std::cout << i+1 << ". " << vehicle[i].get_name() << std::endl;
            }

            std::cout << "0. Закончить регистрацию" << std::endl;
            std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: "; std::cin >> action; std::cout << std::endl;
            if (action != 0)
            {
                vehicle_count++;
                reg = true;
            }

            system("cls");// ОТЧИСТКА КОНСОЛИ
        }// Конец ввода ТС
    }

    //Гонка
    int race() {
        std::cout << "Результаты гонки:" << std::endl;

        double* results = new double[vehicle_type];//Результаты на сортировку

        for (int i = 0; i < vehicle_count; i++) {
            results[i] = time(vehicle[drivers[i]]);//Подсчет всех ТС
        }

        int conter = vehicle_count;
        while (conter--)//Сортировка результатов
        {
            bool swapped = false;

            for (int i = 0; i < conter; i++)
            {
                if (results[i] > results[i + 1])
                {
                    double swap = results[i];
                    results[i] = results[i + 1];
                    results[i + 1] = swap;
                    //
                    int swap_d = drivers[i];
                    drivers[i] = drivers[i + 1];
                    drivers[i + 1] = swap_d;

                    swapped = true;
                }
            }

            if (swapped == false)
                break;
        }

        for (int i = 0; i < vehicle_count; i++){
            std::cout << vehicle[drivers[i]].get_name() << "." << " Время: " << results[i] << std::endl;;
        }

        delete[] results;
        std::cout << std::endl;

        int action;
        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите дествие: "; std::cin >> action; std::cout << std::endl;

        vehicle_count = 0;//сброс кол-ва ТС
        for (int i = 0; i < vehicle_type; i++) {//сброс массива drivers
            drivers[i] = 0;
        }
        if (action == 1) return choose_race_type;
        else if (action == 2) return stop;
    }

    Race() {
        distance_length = -1;// Длинна пути 
        action = -1;//действие
        vehicle_count = 0;//кол-во машин
        vehicle = new Vehicle[vehicle_type];//Объявление массива всех ТС(Требуется т.к. объявленме воздушных ТС требует инициализированеу длину которой нет изначально!!!!!!!)
        drivers = new int[vehicle_type];//Объявление массива всех участников
        race_type = -1;// Тип гонки
    }

    ~Race() {
        delete[] vehicle;
        delete[] drivers;
    }

private:
    //переменные для инициализации ТС
    int distance_length;// Длинна пути 
    int action ;//действие
    int vehicle_count ;//кол-во машин
    const int  vehicle_type = 7;//Кол-во типов ТС
    Vehicle* vehicle;// ТС
    int* drivers;//Участнки гонки
    int race_type;// Тип гонки

    double time(Vehicle veh) {//просчет времени
        double time;
        if (veh.get_type() == ground) {
            time = static_cast<double>(distance_length) / veh.get_speed();
            
            int stop_counter = static_cast<int>(time) / veh.get_dtbr();//Кол-во остановок
            if(static_cast<int>(time) % veh.get_dtbr()==0) stop_counter--;
            for (int i = 0; stop_counter > 0; i++) {
                if (i < 3) { time += veh.get_rest(i); stop_counter--; }
                else { time += veh.get_rest(2) * stop_counter; stop_counter = 0; }
            }
            return time;
        }
        else {
            return time = static_cast<double>(distance_length) * (1-veh.get_distance_reduction()) / veh.get_speed();

        }
    }
};



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
