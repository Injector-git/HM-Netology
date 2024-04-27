#include"EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(int side_a) {
    this->side_a = side_a;
    this->side_b = side_a;
    this->side_c = side_a;
    this->angle_A = 60;
    this->angle_B = 60;
    this->angle_C = 60;
    name = "Равносторонний треугольник: ";
}