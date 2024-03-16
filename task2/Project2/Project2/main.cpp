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
	void print() {
		std::cout << numerator_ << "/" << denominator_ << "\n";
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


	Fraction operator+(Fraction right)
	{
		if (this->denominator_ == right.denominator_)
		{
			return Fraction(this->numerator_ + right.numerator_, right.denominator_);
		}
		else
		{
			return Fraction((this->numerator_ * right.denominator_) + (right.numerator_ * this->denominator_), this->denominator_ * right.denominator_);
		}
	}

	Fraction operator+(int right)//???
	{
		Fraction newFraction(right * this->denominator_, this->denominator_);
		return *(this) + newFraction;
	}

	Fraction operator-(Fraction right)
	{
		if (this->denominator_ == right.denominator_)
		{
			return Fraction(this->numerator_ - right.numerator_, right.denominator_);
		}
		else
		{
			return Fraction((this->numerator_ * right.denominator_) - (right.numerator_ * this->denominator_), this->denominator_ * right.denominator_);
		}
	}

	Fraction operator-(int right)
	{
		Fraction newFraction(right * this->denominator_, this->denominator_);
		return *(this) - newFraction;
	}

	Fraction operator*(Fraction right)
	{
		return Fraction(this->numerator_ * right.numerator_, this->denominator_ * right.denominator_);
		
	}

	Fraction operator*(int right)
	{
		Fraction newFraction(right * this->denominator_, this->denominator_);
		return *(this) * newFraction;
	}

	Fraction operator/(Fraction right)
	{
		Fraction newFraction(right.denominator_, right.numerator_);
		return  *(this) * newFraction;

	}

	Fraction operator/(int right)
	{
		Fraction newFraction(right * this->denominator_, this->denominator_);
		return *(this) / newFraction;
	}


	
	Fraction operator-()//??? а вернуть самого себя?
	{
		Fraction newFraction(this->numerator_ * -1, this->denominator_ * -1);
		return newFraction;
	}






	Fraction& operator++() 
	{
		re_++; im_++; return *this; 
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}










};

int main(int argc, char** argv)
{
	//Fraction f1(4, 3);
	//Fraction f2(6, 11);
	Fraction f1(3, 4);
	f1.print();
	Fraction f2(4, 5);
	f2.print();
	std::cout << std::endl;

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';


	
/*
	Fraction sum_c_c = f1 + f2;
	sum_c_c.print();
	Fraction sum_c_i = f1 + 3;
	sum_c_i.print();
	Fraction sub_c_c = f1 - f2;
	sub_c_c.print();
	Fraction sub_c_i = f1 - 1;
	sub_c_i.print();
	std::cout << std::endl;
	Fraction mul_c_c = f1 * f2;
	mul_c_c.print();
	Fraction mul_c_i = f1 * 5;
	mul_c_i.print();
	std::cout << std::endl;
	Fraction div_c_c = f1 / f2;
	div_c_c.print();
	Fraction div_c_i = f1 / 5;
	div_c_i.print();*/




	//f1 = -f1;
	//f1.print();

	return 0;
}