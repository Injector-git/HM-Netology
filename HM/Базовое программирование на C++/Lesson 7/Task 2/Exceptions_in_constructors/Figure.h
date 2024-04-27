#pragma once
#include<string>
#include<iostream>
#include "FigureCreateExceptions.h"

class Figure {
public:
    Figure();
    int get_sides_count();
    std::string get_name();
    virtual void print_info();
protected:
    int sides_count;
    std::string name;
};