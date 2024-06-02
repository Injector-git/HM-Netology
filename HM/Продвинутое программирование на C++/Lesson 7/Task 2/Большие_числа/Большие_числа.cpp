#include <iostream>
#include <vector>


class Big_integer {
public:
	Big_integer(std::string number){
		str = number;
	};
private:
	std::string str;

};
void move_vectors(std::vector<std::string>& one, std::vector<std::string>& two) {
	std::vector<std::string> tmp = std::move(one);
	one = std::move(two);
	two = std::move(tmp);
}

int main()
{
	auto number1 = Big_integer("114575");
}
