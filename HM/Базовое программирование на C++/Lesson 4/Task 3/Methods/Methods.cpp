#include <iostream>
#include<string>
#include <Windows.h>//для корректной работы кириллицы со стрингом

class Figure {
public:
    Figure() {
        sides_count = 0;
        name = "Фигура: ";
    }

    int get_sides_count() {
        return sides_count;
    }

    std::string get_name() {
        return name;
    }

    virtual void print_info()
    {
        std::cout << "Фигура: " << std::endl;
        if (check()) std::cout << "Правильная" << std::endl;
        else std::cout << "Неправильная" << std::endl;
        std::cout << "Количество сторон: " <<  sides_count << std::endl;
    }

    virtual bool check()
    {
        return true;
    }

protected:
    int sides_count;
    std::string name;
};

class Triangle : public Figure {
public:
    Triangle() {
        sides_count = 3;
        name = "Треугольник: ";
    }
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C) : Triangle() {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }

    int get_side_a() {
        return side_a;
    }
    int get_side_b() {
        return side_b;
    }
    int get_side_c() {
        return side_c;
    }
    int get_angle_A() {
        return angle_A;
    }
    int get_angle_B() {
        return angle_B;
    }
    int get_angle_C() {
        return angle_C;
    }

    void print_info() override
    {
        std::cout << name  << std::endl;
        if (check()) std::cout << "Правильная" << std::endl;
        else std::cout << "Неправильная" << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
        std::cout << "Стороны: " << side_a << " " << side_b << " " << side_c << std::endl;
        std::cout << "Углы: " << angle_A << " " << angle_B << " " << angle_C << std::endl;
    }

    bool check() override
    {
        if (angle_A + angle_B + angle_C == 180 && sides_count == 3) return true;
        else return false;
    }
protected:
    int side_a;
    int side_b;
    int side_c;
    int angle_A;
    int angle_B;
    int angle_C;
};

class RighTriangle : public Triangle {
public:
    RighTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B) {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = 90;
        name = "Прямоугольный треугольник: ";
    }

    bool check() override
    {
        if (angle_A + angle_B + angle_C == 180 && angle_C == 90) return true;
        else return false;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int side_a, int side_b, int angle_A, int angle_B) {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_a;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_A;
        name = "Равнобедренный треугольник: ";
    }

    bool check() override
    {
        if (angle_A == angle_C && side_a == side_c) return true;
        else return false;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side_a) {
        this->side_a = side_a;
        this->side_b = side_a;
        this->side_c = side_a;
        this->angle_A = 60;
        this->angle_B = 60;
        this->angle_C = 60;
        name = "Равносторонний треугольник: ";
    }

    bool check() override
    {
        if (angle_A == angle_B == angle_C == 60 && side_a == side_b == side_c) return true;
        else return false;
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle() {
        sides_count = 4;
        name = "Четырёхугольник: ";
    }
    Quadrangle(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D) : Quadrangle() {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;
    }

    int get_side_a() {
        return side_a;
    }
    int get_side_b() {
        return side_b;
    }
    int get_side_c() {
        return side_c;
    }
    int get_side_d() {
        return side_d;
    }
    int get_angle_A() {
        return angle_A;
    }
    int get_angle_B() {
        return angle_B;
    }
    int get_angle_C() {
        return angle_C;
    }
    int get_angle_D() {
        return angle_D;
    }

    void print_info() override
    {
        std::cout << name << std::endl;
        if (check()) std::cout << "Правильная" << std::endl;
        else std::cout << "Неправильная" << std::endl;
        std::cout << "Количество сторон: " << sides_count << std::endl;
        std::cout << "Стороны: " << side_a << " " << side_b << " " << side_c << " " << side_d << std::endl;
        std::cout << "Углы: " << angle_A << " " << angle_B << " " << angle_C << " " << angle_D << std::endl;
    }

    bool check() override
    {
        if (angle_A + angle_B + angle_C + angle_D == 360 && sides_count == 4 ) return true;
        else return false;
    }

protected:
    int side_a;
    int side_b;
    int side_c;
    int side_d;
    int angle_A;
    int angle_B;
    int angle_C;
    int angle_D;
};

class MyRectangle : public Quadrangle {
public:
    MyRectangle(int side_a, int side_b) {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_a;
        this->side_d = side_b;
        this->angle_A = 90;
        this->angle_B = 90;
        this->angle_C = 90;
        this->angle_D = 90;
        name = "Прямоугольник: ";
    }

    bool check() override
    {
        if (90 == angle_A == angle_B == angle_C == angle_D && side_a == side_c && side_b == side_d) return true;
        else return false;
    }
};

class Square : public Quadrangle {
public:
    Square(int side) {
        this->side_a = side;
        this->side_b = side;
        this->side_c = side;
        this->side_d = side;
        this->angle_A = 90;
        this->angle_B = 90;
        this->angle_C = 90;
        this->angle_D = 90;
        name = "Квадрат: ";
    }

    bool check() override
    {
        if (90 == angle_A == angle_B == angle_C == angle_D && side_a == side_b == side_c == side_d) return true;
        else return false;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int side_a, int side_b, int angle_A, int angle_B) {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_a;
        this->side_d = side_b;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_A;
        this->angle_D = angle_B;
        name = "Параллелограмм: ";
    }

    bool check() override
    {
        if ( side_a == side_c && side_b == side_d && angle_A == angle_C && angle_B == angle_D) return true;
        else return false;
    }
};

class Rhombus : public Quadrangle {
public:
    Rhombus(int side, int angle_A, int angle_B) {
        this->side_a = side;
        this->side_b = side;
        this->side_c = side;
        this->side_d = side;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_A;
        this->angle_D = angle_B;
        name = "Ромб: ";
    }

    bool check() override
    {
        if ( side_a == side_b == side_c == side_d && angle_A == angle_C && angle_B == angle_D) return true;
        else return false;
    }
};

int main()
{
    //Figure* fig = &triangle;
    //fig->print_info();
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    figure.print_info();

    std::cout << std::endl;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print_info();

    std::cout << std::endl;

    RighTriangle righ_triangle(10, 20, 30, 50, 60);
    righ_triangle.print_info();

    std::cout << std::endl;

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    isosceles_triangle.print_info();

    std::cout << std::endl;
    
    EquilateralTriangle equilateral_triangle(30);
    equilateral_triangle.print_info();

    std::cout << std::endl;

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    quadrangle.print_info();

    std::cout << std::endl;

    MyRectangle rectangle(10, 20);
    rectangle.print_info();

    std::cout << std::endl;

    Square square(20);
    square.print_info();

    std::cout << std::endl;

    Parallelogram parallelogram(20, 30, 30, 40);
    parallelogram.print_info();

    std::cout << std::endl;

    Rhombus rhombus(30, 30, 40);
    rhombus.print_info();

    std::cout << std::endl;

    return 0;
}