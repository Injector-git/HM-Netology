#include "Figure.h"



Figure::Figure() {
    sides_count = 0;
    name = "Фигура: ";
}
void Figure::print_info()
{
    std::cout << "Фигура: " << std::endl;
    std::cout << "Количество сторон: " << sides_count << std::endl;
}
int Figure::get_sides_count() { return sides_count; }
std::string Figure::get_name() { return name; }
