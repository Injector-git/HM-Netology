#include "Rhombus.h"

Rhombus::Rhombus(int side, int angle_A, int angle_B) {
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