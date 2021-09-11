#ifndef RATIONAL_H
#define RATIONAL_H
//Self-Review Exercises || Exercise 9.6 || page:411
using namespace std;

class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational();
	Rational(int , int );
	Rational operator + (const Rational &R) 
	{
		return Rational((numerator*R.denominator + R.numerator*denominator), denominator*R.denominator);
	}
	Rational operator - (const Rational &R)
	{
		return Rational((numerator*R.denominator - R.numerator*denominator), denominator*R.denominator);
	}
	Rational operator * (const Rational &R)
	{
		return Rational(numerator*R.numerator, denominator*R.denominator);
	}
	Rational operator / (const Rational &R)
	{
		return Rational(numerator*R.denominator, R.numerator*denominator);
	}
	void display() const;
	void displayFloatingPoint() const;
};

#endif // !RATIONAL_H