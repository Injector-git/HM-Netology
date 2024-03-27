#include"Race.h"

    int Race::get_distance_length() { return distance_length; }
    int Race::get_action() { return action; }
    int Race::get_vehicle_count() { return vehicle_count; }
    Vehicle* Race::get_vehicle() { return vehicle; }
    int Race::get_race_type() { return race_type; }

    //тип гонки
    void Race::set_race_type() {
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        std::cout << "Выберите тип гонки: "; std::cin >> race_type; std::cout << std::endl;
    }

    //длинна трассы и инициализация ТС
    void Race::set_distance_length() {
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
    int Race::action_selection() {
        if (vehicle_count < 2)std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства" << std::endl;
        std::cout << "1. Зарегистрировать транспорт" << std::endl;
        if (vehicle_count > 1) std::cout << "2. Начать гонку" << std::endl;
        std::cout << "Выберите дествие: "; std::cin >> action; std::cout << std::endl;

        if (action == 1) return registration;
        else if (action == 2) return race_start;
    }

    //Ввод типов ТС 
    void Race::set_vehicle() {

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
                    if (action - 1 == drivers[i]) {
                        std::cout << vehicle[drivers[i]].get_name() << " Уже зарегистрирован" << std::endl;
                        vehicle_count--;//Неуспешная рег ТС
                        reg = false;
                        break;
                    }

                if (reg == true) {
                    std::cout << vehicle[action - 1].get_name() << " Успешно зарегестрирован!" << std::endl;
                    drivers[vehicle_count - 1] = action - 1;//Успешная рег ТС
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
                    if (vehicle_count > 1 && i != vehicle_count - 1) std::cout << ", ";
                }
                std::cout << std::endl;
            }

            for (int i = 0; i < vehicle_type; i++)// Отрисовка типов ТС
            {
                std::cout << i + 1 << ". " << vehicle[i].get_name() << std::endl;
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
    int Race::race() {
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

        for (int i = 0; i < vehicle_count; i++) {
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

    Race::Race() {
        distance_length = -1;// Длинна пути 
        action = -1;//действие
        vehicle_count = 0;//кол-во машин
        vehicle = new Vehicle[vehicle_type];//Объявление массива всех ТС(Требуется т.к. объявленме воздушных ТС требует инициализированеу длину которой нет изначально!!!!!!!)
        drivers = new int[vehicle_type];//Объявление массива всех участников
        race_type = -1;// Тип гонки
    }

    Race::~Race() {
        delete[] vehicle;
        delete[] drivers;
    }
