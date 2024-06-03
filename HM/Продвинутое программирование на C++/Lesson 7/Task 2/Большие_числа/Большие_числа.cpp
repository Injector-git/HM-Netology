﻿#include <iostream>
#include <vector>
#include <math.h>


class Big_integer {
public:
	Big_integer(std::string number) {
		for (int i = 0; i < number.size(); i++) {
			vec.push_back(static_cast<int>(number[i]) - 48);
		}
	};
	Big_integer(){}

	/*Big_integer(Big_integer&& other) {// конструктор перемещения
		vec = other.vec;
		other.vec.clear();
	}*/

	friend std::ostream& operator<<(std::ostream& left, Big_integer right) {
		for (int i = 0; i < right.vec.size(); i++)
		{
			left << right.vec[i];
		}
		return left;
	}

	Big_integer& operator=(const Big_integer& right) // оператор копирующего присваивания
	{
		return *this = Big_integer(right);
	}

	Big_integer& operator+(Big_integer& right) {

		Big_integer sum;
		std::vector<int>::reverse_iterator iterator_left= vec.rbegin();
		std::vector<int>::reverse_iterator iterator_right = right.vec.rbegin();
		int ostatok=0,term1 = *iterator_left,term2 = *iterator_right,digit;

		while (ostatok != 0 || term1 != 0 || term2 != 0) {
			digit = (term1 + term2 + ostatok);
			ostatok = digit / 10;
			sum.vec.push_back(digit % 10);
			if (iterator_left + 1 != vec.rend()) term1 = *(++iterator_left);
			else { term1 = 0; }
			if (iterator_right + 1 != right.vec.rend()) term2 = *(++iterator_right);
			else { term2 = 0; }
		}
		return sum;
	}

	Big_integer& operator*(int factor) {
		Big_integer res;
		std::vector<int>::reverse_iterator iterator = vec.rbegin();
		int ostatok=0, mult, digit;
		while(iterator != vec.rend()){
			mult = *iterator;
			digit = mult * factor + ostatok;
			ostatok = digit / 10;
			res.vec.push_back(digit % 10);
			iterator++;
		}
		if(ostatok!=0)res.vec.push_back(ostatok);
		return res;
	}

private:
	std::vector<int> vec;
};

int main()
{
	auto number1 = Big_integer("924575");
	auto number2 = Big_integer("78524");
	auto result = number1 + number2;
	std::cout << result; // 193099
}
