#include <iostream>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class Figure {
protected:
    int sides_count;

public:
    Figure() {
        sides_count = 0;
    }
    int get_sides_count() {
        return sides_count;
    }
};

class Triangle : public Figure {
public:
    Triangle() {
        sides_count = 3;
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle() {
        sides_count = 4;
    }
};

int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure a;
    std::cout << "Фигура: " << a.get_sides_count() << std::endl;

    Triangle b;
    std::cout << "Треугольник: " <<  b.get_sides_count() << std::endl;

    Quadrangle c;
    std::cout << "Четырёхугольник: " << c.get_sides_count() << std::endl;

    return 0;
}