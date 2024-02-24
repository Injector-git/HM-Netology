#include <iostream>
#include <fstream>
#include<string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class Adres {

    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
public:
    Adres(std::string city, std::string street, int house_number, int apartment_number)
    {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->apartment_number = apartment_number;
    }
    Adres()
    {
        city = "city";
        street = "street";
        house_number = 0;
        apartment_number = 0;
    }
    void set_city(std::string city) {
        this->city = city;
    }
    void set_street(std::string street) {
        this->street = street;
    }
    void set_house_number(int house_number) {
        this->house_number = house_number;
    }
    void set_apartment_number(int apartment_number) {
        this->apartment_number = apartment_number;
    }


    std::string get_city() {
        return  city;
    }
    std::string get_street() {
        return street;
    }
    int get_house_number() {
        return house_number;
    }
    int get_apartment_number() {
        return apartment_number;
    }
};

void sort(Adres* adres, int count)
{
    while (count--)
    {
        bool swapped = false;

        for (int i = 0; i < count; i++)
        {
            if ((adres[i].get_city()).at(0) > (adres[i + 1].get_city()).at(0))
            {
                Adres swap = adres[i];
                adres[i] = adres[i + 1];
                adres[i + 1] = swap;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
int count;

int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream in("in.txt");
    if (in.is_open()) {
        in >> count;
        Adres* adres = new Adres[count];
        for (int i = 0; i < count; i++)
        {
            std::string value_string;

            in >> value_string;
            adres[i].set_city(value_string);

            in >> value_string;
            adres[i].set_street(value_string);

            int value_int;
            in >> value_int;
            adres[i].set_house_number(value_int);

            in >> value_int;
            adres[i].set_apartment_number(value_int);

            std::ofstream out("out.txt");

            if (out.is_open()) {
                out << count << std::endl;
                sort(adres, count);
                for (int i = 0; i < count; i++) {
                    out << adres[i].get_city() << " " << adres[i].get_street() << " " << adres[i].get_house_number() << " " << adres[i].get_apartment_number() << std::endl;
                }
            }
            else std::cout << "не удалось открыть файл";
        }
        delete[] adres;
    }
    else std::cout << "не удалось открыть файл";



    return 0;
}
