#pragma once
#include <string>
#include <iostream>
#ifdef VEHICLE_EXPORTS
#define VEHICLELIBRARY_API __declspec(dllexport)
#else
#define VEHICLELIBRARY_API __declspec(dllimport)
#endif
class Vehicle
{
public:
	VEHICLELIBRARY_API std::ostream& get_name();
};



