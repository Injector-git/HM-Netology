#include "MyRectangle.h"

MyRectangle::MyRectangle(int side_a, int side_b) {
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