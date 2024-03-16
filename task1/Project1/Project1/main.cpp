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

	bool operator==(Fraction right)
	{
		return this->numerator_ == right.numerator_ && this->denominator_ == right.denominator_;
	}

	bool operator!=(Fraction right)
	{
		return !(this->numerator_ == right.numerator_ && this->denominator_ == right.denominator_);
	}

	bool operator<(Fraction right)
	{
		return static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_) < static_cast<double>(right.numerator_) / static_cast<double>(right.denominator_);
	}

	bool operator>(Fraction right)
	{
		return static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_) > static_cast<double>(right.numerator_) / static_cast<double>(right.denominator_);
	}

	bool operator<=(Fraction right)
	{
		return static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_) <= static_cast<double>(right.numerator_) / static_cast<double>(right.denominator_);
	}

	bool operator>=(Fraction right)
	{
		return static_cast<double>(this->numerator_) / static_cast<double>(this->denominator_) >= static_cast<double>(right.numerator_) / static_cast<double>(right.denominator_);
	}
};

int main(int argc, char** argv)
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}