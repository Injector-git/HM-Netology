#include <iostream>
#include "shape.h"



int main()
{
    Coord a(2, 3);
    Coord b(4, 5);
    Line line(a, b);
    line.shift(1, 2);
    line.shift(1, 2, 3);
    line.scaleZ(2);
    line.scaleY(2);
    line.scaleX(2);

    Circle circle(a, b, 5, 6);
    /*circle.shift(1, 2, 3);
    circle.scaleZ(2);
    circle.scaleY(2);
    circle.scaleX(2);*/
    

    std::cout << "Hello World!\n";
}
