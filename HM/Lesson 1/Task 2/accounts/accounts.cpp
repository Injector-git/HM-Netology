#include <iostream>
#include <clocale>

struct bank_account
{
    int id;
    std::string first_name;
    int balance;
};

void change_balance(bank_account& b, int increment)
{
    b.balance = increment;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    bank_account b;
    std::cout << "Введите номер счёта:";
    std::cin >> b.id;
    std::cout << "Введите имя владельца:";
    std::cin >> b.first_name;
    std::cout << "Введите баланс:";
    std::cin >> b.balance;
    std::cout << "Введите новый баланс:";
    int new_balance; std::cin >> new_balance;
    change_balance(b, new_balance);
    std::cout << "Ваш счёт: " << b.first_name << " " << b.id << " " << b.balance;
}
