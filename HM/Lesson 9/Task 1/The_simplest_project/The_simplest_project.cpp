// The_simplest_project.cpp: определяет точку входа для приложения.
//

#include "The_simplest_project.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	std::string name;
	cout << "Введите имя: ";
	cin >> name;
	cout << "Здравствуйте, " << name << "!";
	return 0;
}
