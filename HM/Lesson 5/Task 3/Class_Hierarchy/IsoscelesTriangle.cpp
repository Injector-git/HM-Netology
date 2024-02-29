#include"IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(int side_a, int side_b, int angle_A, int angle_B) {
    this->side_a = side_a;
    this->side_b = side_b;
    this->side_c = side_a;
    this->angle_A = angle_A;
    this->angle_B = angle_B;
    this->angle_C = angle_A;
    name = "Равнобедренный треугольник: ";
}
