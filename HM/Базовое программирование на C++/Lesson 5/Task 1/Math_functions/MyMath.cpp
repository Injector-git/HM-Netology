#include "MyMath.h"

double add(double a, double b) {
	return a + b;
}

double sub(double a, double b) {
	return a - b;
}

double mult(double a, double b) {
	return a * b;
}

double div(double a, double b) {
	return a / b;
}

double pow(double a, double b) {
	while (b--)
	{
		a *= a;
	}
	return a;
}