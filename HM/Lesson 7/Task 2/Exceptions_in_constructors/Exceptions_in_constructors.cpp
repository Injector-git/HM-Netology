#include <iostream>
#include "Fig.h"
#include <Windows.h>//для корректной работы кириллицы со стрингом

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

    try {
        Triangle triangle(10, 20, 30, 40, 60, 70); //углы = 170
        triangle.print_info();
    }
    catch (FigureCreateExceptions ex) { std::cout << "Ошибка создания фигуры.Причина: " << ex.what() << std::endl; }

    std::cout << std::endl;

    try {
        Triangle triangle(10, 20, 30, 50, 60, 70); //углы = 180
        triangle.print_info();
    }
    catch (FigureCreateExceptions ex) { std::cout << "Ошибка создания фигуры.Причина: " << ex.what() << std::endl; }

    std::cout << std::endl;

    try
    {
        Quadrangle quadrangle(10, 20, 30, 40, 80, 90, 110, 80); //углы = 360
        quadrangle.print_info();
    }
    catch (FigureCreateExceptions ex) { std::cout << "Ошибка создания фигуры.Причина: " << ex.what() << std::endl; }

    std::cout << std::endl;

    try
    {
        Quadrangle quadrangle(10, 20, 30, 40, 80, 60, 70, 80); //углы = 290
        quadrangle.print_info();
    }
    catch (FigureCreateExceptions ex) { std::cout << "Ошибка создания фигуры.Причина: " << ex.what() << std::endl; }

    std::cout << std::endl;

    try {
        RighTriangle righ_triangle(10, 20, 30, 50, 60); //всегда правильный
        righ_triangle.print_info();
    }
    catch (FigureCreateExceptions ex) { std::cout << "Ошибка создания фигуры.Причина: " << ex.what() << std::endl; }

    std::cout << std::endl;

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);//всегда правильный
    isosceles_triangle.print_info();

    std::cout << std::endl;

    EquilateralTriangle equilateral_triangle(30);//всегда правильный
    equilateral_triangle.print_info();

    std::cout << std::endl;

    MyRectangle rectangle(10, 20);//всегда правильный
    rectangle.print_info();

    std::cout << std::endl;

    Square square(20);//всегда правильный
    square.print_info();

    std::cout << std::endl;

    Parallelogram parallelogram(20, 30, 30, 40);//всегда правильный
    parallelogram.print_info();

    std::cout << std::endl;

    Rhombus rhombus(30, 30, 40);//всегда правильный
    rhombus.print_info();

    std::cout << std::endl;

    return 0;
}