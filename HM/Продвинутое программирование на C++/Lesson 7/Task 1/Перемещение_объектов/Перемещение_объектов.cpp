#include <iostream>
#include <vector>


void move_vectors(std::vector<std::string> &one, std::vector<std::string>& two) {
	std::vector<std::string> tmp = std::move(one);
	one = std::move(two);
	two = std::move(two);
}

int main()
{
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	move_vectors(one, two);
}
