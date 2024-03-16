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
		std::cout << numerator_ << "/" << denominator_;
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

	Fraction operator+(int right)
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


	
	Fraction operator-()
	{
		Fraction newFraction(this->numerator_ * -1, this->denominator_ * -1);
		return newFraction;
	}

	Fraction& operator++() 
	{
		this->numerator_ += this->denominator_;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction newFraction = *this;
		++(*this);
		return newFraction;
	}

	Fraction& operator--()
	{
		this->numerator_ -= this->denominator_;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction newFraction = *this;
		--(*this);
		return newFraction;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	int numerator1 = 0;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator1;
	int denominator1 = 0;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator1;
	int numerator2 = 0;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator2;
	int denominator2 = 0;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);

	std::cout << std::endl;
	/*
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	*/

	

	Fraction sum_c_c = f1 + f2;
	f1.print();
	std::cout << " + ";
	f2.print();
	std::cout << " = ";
	sum_c_c.print();
	std::cout << std::endl;

	//Fraction sum_c_i = f1 + 3;//сложение с числом
	//sum_c_i.print();

	Fraction sub_c_c = f1 - f2;
	f1.print();
	std::cout << " - ";
	f2.print();
	std::cout << " = ";
	sub_c_c.print();
	std::cout << std::endl;

	//Fraction sub_c_i = f1 - 1;//вычитание числа
	//sub_c_i.print();

	Fraction mul_c_c = f1 * f2;
	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	mul_c_c.print();
	std::cout << std::endl;

	//Fraction mul_c_i = f1 * 5;//умножение на число
	//mul_c_i.print();

	Fraction div_c_c = f1 / f2;
	f1.print();
	std::cout << " / ";
	f2.print();
	std::cout << " = ";
	div_c_c.print();
	std::cout << std::endl;

	//Fraction div_c_i = f1 / 5;//деление на число
	//div_c_i.print();



	std::cout << "++";
	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	Fraction plus_beforef = ++f1 * f2;
	plus_beforef.print();
	std::cout << std::endl;

	//f1++;
	//f1.print();
	//std::cout << std::endl;

	std::cout << "--";
	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	Fraction minus_before = --f1 * f2;
	minus_before.print();
	std::cout << std::endl;
	
	
	//f1--;
	//f1.print();

	std::cout << "значение до унарного знака -" << std::endl;
	f1.print();
	f1 = -f1;
	std::cout << "\nзначение после унарного знака -" << std::endl;
	f1.print();

	//надо сделать сокращение допустим 15/25 это 3/4
	return 0;
}