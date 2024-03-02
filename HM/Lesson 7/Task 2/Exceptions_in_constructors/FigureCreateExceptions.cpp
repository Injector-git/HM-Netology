#include "FigureCreateExceptions.h"


FigureCreateExceptions::FigureCreateExceptions(const char* exp) {
	this->exp = exp;
}
const char* FigureCreateExceptions::what() { return exp; }
