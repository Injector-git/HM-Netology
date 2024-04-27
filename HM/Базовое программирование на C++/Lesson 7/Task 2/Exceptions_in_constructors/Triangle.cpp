#include "Triangle.h"

    Triangle::Triangle() {
        sides_count = 3;
        name = "Треугольник: ";
    }
    Triangle::Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C) : Triangle() {
        if (angle_A + angle_B + angle_C != 180) throw FigureCreateExceptions("сумма углов не равна 180");
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
    }

    int Triangle::get_side_a() { return side_a; }
    int Triangle::get_side_b() { return side_b; }
    int Triangle::get_side_c() { return side_c; }
    int Triangle::get_angle_A() { return angle_A; }
    int Triangle::get_angle_B() { return angle_B; }
    int Triangle::get_angle_C() { return angle_C; }

    void Triangle::print_info()
    {
        std::cout << name << "(cтороны " << side_a << ", " << side_b << ", " << side_c << "; "
            << "углы " << angle_A << ", " << angle_B << ", " << angle_C << ") создан" << std::endl;
    }