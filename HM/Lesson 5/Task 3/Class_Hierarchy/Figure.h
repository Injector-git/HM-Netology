#pragma once
#include<string>

class Figure {
public:
    Figure();
    int get_sides_count();
    std::string get_name();
protected:
    int sides_count;
    std::string name;
};