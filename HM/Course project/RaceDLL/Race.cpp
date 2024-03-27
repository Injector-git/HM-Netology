#include"Race.h"

    int Race::get_distance_length() { return distance_length; }
    int Race::get_action() { return action; }
    int Race::get_vehicle_count() { return vehicle_count; }
    Vehicle* Race::get_vehicle() { return vehicle; }
    int Race::get_race_type() { return race_type; }

    //��� �����
    void Race::set_race_type() {
        std::cout << "1. ����� ��� ��������� ����������" << std::endl;
        std::cout << "2. ����� ��� ���������� ����������" << std::endl;
        std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;

        std::cout << "�������� ��� �����: "; std::cin >> race_type; std::cout << std::endl;
    }

    //������ ������ � ������������� ��
    void Race::set_distance_length() {
        std::cout << "������� ������ ��������� (������ ���� �������������): "; std::cin >> distance_length; std::cout << std::endl;
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
        if (vehicle_count < 2)std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
        std::cout << "1. ���������������� ���������" << std::endl;
        if (vehicle_count > 1) std::cout << "2. ������ �����" << std::endl;
        std::cout << "�������� �������: "; std::cin >> action; std::cout << std::endl;

        if (action == 1) return registration;
        else if (action == 2) return race_start;
    }

    //���� ����� �� 
    void Race::set_vehicle() {

        action = 1;
        bool reg = false;//����� ��� ��

        while (action != 0) {//������ ����� ����� ��

            if (reg == true) {//������� �����������
                if (race_type == 1 && (action == 2 || action == 5 || action == 7)) {//�������� �� ����������
                    std::cout << "������� ���������������� ������������ ��� ������������� ��������" << std::endl;
                    vehicle_count--;//���������� ��� ��
                    reg = false;
                }
                else if (race_type == 2 && (action == 1 || action == 3 || action == 4 || action == 6)) {//�������� �� �����������
                    std::cout << "������� ���������������� ������������ ��� ������������� ��������" << std::endl;
                    vehicle_count--;//���������� ��� ��
                    reg = false;
                }

                for (int i = 0; i < vehicle_count; i++)//�������� �� ������ ��
                    if (action - 1 == drivers[i]) {
                        std::cout << vehicle[drivers[i]].get_name() << " ��� ���������������" << std::endl;
                        vehicle_count--;//���������� ��� ��
                        reg = false;
                        break;
                    }

                if (reg == true) {
                    std::cout << vehicle[action - 1].get_name() << " ������� ���������������!" << std::endl;
                    drivers[vehicle_count - 1] = action - 1;//�������� ��� ��
                }
            }

            switch (race_type)
            {
            case 1:
                std::cout << "����� ��� ��������� ���������� ���������: ";
                break;
            case 2:
                std::cout << "����� ��� ���������� ���������� ���������: ";
                break;
            case 3:
                std::cout << "����� ��� ��������� � ���������� ���������� ���������: ";
                break;
            default:
                break;
            }
            std::cout << distance_length << std::endl;

            if (vehicle_count > 0) {
                std::cout << "������������������ ������������ ��������: ";
                for (int i = 0; i < vehicle_count; i++) {
                    std::cout << vehicle[drivers[i]].get_name();
                    if (vehicle_count > 1 && i != vehicle_count - 1) std::cout << ", ";
                }
                std::cout << std::endl;
            }

            for (int i = 0; i < vehicle_type; i++)// ��������� ����� ��
            {
                std::cout << i + 1 << ". " << vehicle[i].get_name() << std::endl;
            }

            std::cout << "0. ��������� �����������" << std::endl;
            std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: "; std::cin >> action; std::cout << std::endl;
            if (action != 0)
            {
                vehicle_count++;
                reg = true;
            }

            system("cls");// �������� �������
        }// ����� ����� ��
    }

    //�����
    int Race::race() {
        std::cout << "���������� �����:" << std::endl;

        double* results = new double[vehicle_type];//���������� �� ����������

        for (int i = 0; i < vehicle_count; i++) {
            results[i] = time(vehicle[drivers[i]]);//������� ���� ��
        }

        int conter = vehicle_count;
        while (conter--)//���������� �����������
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
            std::cout << vehicle[drivers[i]].get_name() << "." << " �����: " << results[i] << std::endl;;
        }

        delete[] results;
        std::cout << std::endl;

        int action;
        std::cout << "1. �������� ��� ���� �����" << std::endl;
        std::cout << "2. �����" << std::endl;
        std::cout << "�������� �������: "; std::cin >> action; std::cout << std::endl;

        vehicle_count = 0;//����� ���-�� ��
        for (int i = 0; i < vehicle_type; i++) {//����� ������� drivers
            drivers[i] = 0;
        }
        if (action == 1) return choose_race_type;
        else if (action == 2) return stop;
    }

    Race::Race() {
        distance_length = -1;// ������ ���� 
        action = -1;//��������
        vehicle_count = 0;//���-�� �����
        vehicle = new Vehicle[vehicle_type];//���������� ������� ���� ��(��������� �.�. ���������� ��������� �� ������� ����������������� ����� ������� ��� ����������!!!!!!!)
        drivers = new int[vehicle_type];//���������� ������� ���� ����������
        race_type = -1;// ��� �����
    }

    Race::~Race() {
        delete[] vehicle;
        delete[] drivers;
    }
