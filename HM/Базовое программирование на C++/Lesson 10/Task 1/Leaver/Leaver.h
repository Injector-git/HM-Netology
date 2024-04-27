#pragma once
#include <string>
#include <iostream>
#ifdef LEAVERLIBRARYDYNAMIC_EXPORTS
#define LEAVERLIBRARY_API __declspec(dllexport)
#else
#define LEAVERLIBRARY_API __declspec(dllimport)
#endif
class Leaver
	{
	public:
		LEAVERLIBRARY_API std::ostream& leave(std::string name);
	};

