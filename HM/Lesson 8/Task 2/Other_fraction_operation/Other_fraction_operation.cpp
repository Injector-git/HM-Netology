#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	friend std::ostream& operator<<(std::ostream& left, Fraction right) {
		left << right.numerator_ << " " << right.denominator_;
		return left;
	}

	Fraction operator+(Fraction right) {
		int new_numerator = numerator_ * right.denominator_ + right.numerator_ * denominator_;
		return Fraction(new_numerator, denominator_ * right.denominator_);
	}

	Fraction operator-(Fraction right) {
		int new_numerator = numerator_ * right.denominator_ - right.numerator_ * denominator_;
		return Fraction(new_numerator, denominator_ * right.denominator_);
	}

	Fraction operator*(Fraction right) {
		return Fraction(numerator_ * right.numerator_, denominator_ * right.denominator_);
	}

	Fraction operator/(Fraction right) {
		return Fraction(numerator_ * right.denominator_, right.numerator_ * denominator_);
	}

	Fraction operator++() {
		return Fraction(++numerator_, ++denominator_);
	}
	Fraction operator++(int) {
		return Fraction(++numerator_, ++denominator_);
	}
	Fraction operator--() {
		return Fraction(--numerator_, --denominator_);
	}
	Fraction operator--(int) {
		return Fraction(--numerator_, --denominator_);
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int num1, num2, den1, den2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;
	std::cout << "Введите знаменатель  дроби 1: ";
	std::cin >> den1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num2;
	std::cout << "Введите знаменатель  дроби 2: ";
	std::cin >> den2;


	Fraction f1(num1, den1);
	Fraction f2(num2, den2);

	std::cout << num1 << "/" << den1 << " + " << num2 << "/" << den2 << " = " << f1+f2 << '\n';
	std::cout << num1 << "/" << den1 << " - " << num2 << "/" << den2 << " = " << f1 - f2 << '\n';
	std::cout << num1 << "/" << den1 << " * " << num2 << "/" << den2 << " = " << f1 * f2 << '\n';
	std::cout << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << f1 / f2 << '\n';
	std::cout << "++" << num1 << "/" << den1 << " / " << num2 << "/" << den2 << " = " << ++f1 / f2  << '\n';
	return 0;
}
