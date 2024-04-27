#include <iostream>
#include <clocale>

struct address
{
    std::string city;
    std::string street;
    int number;
    int apartments;
    int index;
};

void print_address(address& b)
{
    std::cout << b.city << "\n" << b.street << "\n" << b.number << "\n" << b.apartments << "\n" << b.index << "\n" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    address a = { "Москва", "Арбат", 12, 8, 123456 };
    print_address(a);
    address b = { "Ижевск", "Пушкина", 59, 143, 953769 };
    print_address(b);
}