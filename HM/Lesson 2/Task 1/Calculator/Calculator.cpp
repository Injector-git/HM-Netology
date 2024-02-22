#include <iostream>
#include <clocale>

class Calculator {
private:
    double num1, num2;
public:
    double add(int num1, int num2) {
        return num1 + num2;
    }
    double multiply(int num1, int num2) {
        return num1 * num2;
    }
    double subtract_1_2(int num1, int num2) {
        return num1 - num2;
    }
    double subtract_2_1(int num1, int num2) {
        return num2 - num1;
    }
    double divide_1_2(int num1, int num2) {
        return num1 / num2;
    }
    double divide_2_1(int num1, int num2) {
        return num2 / num1;
    }
    bool set_num1(double value) {
        if (value != 0) { num1 = value; return true; }
        else { std::cout << "Неверный ввод!" << std::endl; return false; }
    }
    bool set_num2(double value) {
        if (value != 0) { num2 = value; return true; }
        else { std::cout << "Неверный ввод!" << std::endl; return false; }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Calculator calc;
    double num1, num2;
    while(true){
        do {
            std::cout << "Введите num1:";
            std::cin >> num1;
        } while (calc.set_num1(num1) != true);
        do {
            std::cout << "Введите num2:";
            std::cin >> num2;
        } while (calc.set_num2(num2) != true);

        std::cout << "num1 + num2 = " << calc.add(num1, num2) << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2(num1, num2) << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1(num1, num2) << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply(num1, num2) << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2(num1, num2) << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1(num1, num2) << std::endl;
    }
}
