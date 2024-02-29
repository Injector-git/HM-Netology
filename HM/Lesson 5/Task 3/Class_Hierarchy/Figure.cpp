#include "Figure.h"

Figure::Figure() {
    sides_count = 0;
    name = "Фигура: ";
}
int Figure::get_sides_count() { return sides_count; }
std::string Figure::get_name() { return name; }