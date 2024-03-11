#pragma once
#include"Figure.h"

class Quadrangle : public Figure {
public:
    Quadrangle();
    Quadrangle(int side_a, int side_b, int side_c, int side_d, int angle_A, int angle_B, int angle_C, int angle_D);

    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_side_d();
    int get_angle_A();
    int get_angle_B();
    int get_angle_C();
    int get_angle_D();
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