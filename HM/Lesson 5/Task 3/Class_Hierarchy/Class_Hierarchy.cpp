#include <iostream>
#include<string>
#include <Windows.h>//для корректной работы кириллицы со стрингом
#include "Fig.h"

void print_info_triangle(Triangle triangle)
{
    std::cout << triangle.get_name() << std::endl;
    std::cout << "Стороны: " << triangle.get_side_a() << " " << triangle.get_side_b() << " " << triangle.get_side_c() << std::endl;
    std::cout << "Углы: " << triangle.get_angle_A() << " " << triangle.get_angle_B() << " " << triangle.get_angle_C() << std::endl;
}

void print_info_quadrangle(Quadrangle quadrangle)
{
    std::cout << quadrangle.get_name() << std::endl;
    std::cout << "Стороны: " << quadrangle.get_side_a() << " " << quadrangle.get_side_b() << " " << quadrangle.get_side_c() << " " << quadrangle.get_side_d() << std::endl;
    std::cout << "Углы: " << quadrangle.get_angle_A() << " " << quadrangle.get_angle_B() << " " << quadrangle.get_angle_D() << " " << quadrangle.get_angle_C() << std::endl;
}

int main()
{
    //для корректной работы кириллицы со стрингом
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info_triangle(triangle);

    std::cout << std::endl;

    RighTriangle righ_triangle(10, 20, 30, 50, 60);
    print_info_triangle(righ_triangle);

    std::cout << std::endl;

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    print_info_triangle(isosceles_triangle);

    std::cout << std::endl;

    EquilateralTriangle equilateral_triangle(30);
    print_info_triangle(equilateral_triangle);

    std::cout << std::endl;

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info_quadrangle(quadrangle);

    std::cout << std::endl;

    MyRectangle rectangle(10, 20);
    print_info_quadrangle(rectangle);

    std::cout << std::endl;

    Square square(20);
    print_info_quadrangle(square);

    std::cout << std::endl;

    Parallelogram parallelogram(20, 30, 30, 40);
    print_info_quadrangle(parallelogram);

    std::cout << std::endl;

    Rhombus rhombus(30, 30, 40);
    print_info_quadrangle(rhombus);

    std::cout << std::endl;
    return 0;
}