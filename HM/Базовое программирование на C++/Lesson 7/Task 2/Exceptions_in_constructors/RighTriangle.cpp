#include"RighTriangle.h"

RighTriangle::RighTriangle(int side_a, int side_b, int side_c, int angle_A, int angle_B) {
    this->side_a = side_a;
    this->side_b = side_b;
    this->side_c = side_c;
    this->angle_A = angle_A;
    this->angle_B = angle_B;
    this->angle_C = 90;
    if (angle_C != 90) throw FigureCreateExceptions("Угол с не равен 90");//не используется 

    name = "Прямоугольный треугольник: ";
}