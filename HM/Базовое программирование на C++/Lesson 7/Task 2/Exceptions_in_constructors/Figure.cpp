#include "Figure.h"



Figure::Figure() {
    sides_count = 0;
    name = "������: ";
}
void Figure::print_info()
{
    std::cout << "������: " << std::endl;
    std::cout << "���������� ������: " << sides_count << std::endl;
}
int Figure::get_sides_count() { return sides_count; }
std::string Figure::get_name() { return name; }
