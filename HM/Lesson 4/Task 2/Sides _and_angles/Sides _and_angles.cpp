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
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C) : Triangle(){
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
    RighTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B){
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = 90;
        name = "Прямоугольный треугольник: ";
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
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int side_a,int side_b,int angle_A,int angle_B) {
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
};

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

    Triangle triangle(10,20,30,50,60,70);
    print_info_triangle(triangle);

    std::cout << std::endl;

    RighTriangle righ_triangle(10, 20, 30, 50, 60);
    print_info_triangle(righ_triangle);

    std::cout << std::endl;

    IsoscelesTriangle isosceles_triangle(10,20,50,60);
    print_info_triangle(isosceles_triangle);

    std::cout << std::endl;

    EquilateralTriangle equilateral_triangle(30);
    print_info_triangle(equilateral_triangle);

    std::cout << std::endl;

    Quadrangle quadrangle(10,20,30,40,50,60,70,80);
    print_info_quadrangle(quadrangle);

    std::cout << std::endl;

    MyRectangle rectangle(10,20);
    print_info_quadrangle(rectangle);

    std::cout << std::endl;

    Square square (20);
    print_info_quadrangle(square);

    std::cout << std::endl;

    Parallelogram parallelogram(20,30,30,40);
    print_info_quadrangle(parallelogram);

    std::cout << std::endl;

    Rhombus rhombus(30, 30, 40);
    print_info_quadrangle(rhombus);

    std::cout << std::endl;
    return 0;
}