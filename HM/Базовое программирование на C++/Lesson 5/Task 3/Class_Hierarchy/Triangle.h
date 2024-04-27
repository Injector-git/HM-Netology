#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(int side_a, int side_b, int side_c, int angle_A, int angle_B, int angle_C);

    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_angle_A();
    int get_angle_B();
    int get_angle_C();
protected:
    int side_a;
    int side_b;
    int side_c;
    int angle_A;
    int angle_B;
    int angle_C;
};