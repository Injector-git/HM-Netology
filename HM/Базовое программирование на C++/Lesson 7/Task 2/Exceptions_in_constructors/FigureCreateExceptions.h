#pragma once
#include <iostream>
#include <string>

const class FigureCreateExceptions
{
public:
	FigureCreateExceptions(const char* exp);
	const char* what();
private:
	const char* exp;
};

