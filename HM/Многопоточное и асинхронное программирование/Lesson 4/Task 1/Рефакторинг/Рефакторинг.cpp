#include <iostream>
#include "shape.h"
#include "transform.h"


int main()
{
    Coord a(2, 3);
    Coord b(4, 5);
    Line line(a, b);
 
    Transform tr(line);
    tr.shift(1, 2, 3);

    std::cout << "Hello World!\n";
}
