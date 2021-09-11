#include<iostream>
#include "Complex.h"
//Self-Review Exercises || Exercise 9.5 || page:411
using namespace std;

Complex::Complex(double R=0, double I=0)
{
	setParts(R, I);
}
void Complex::setParts(double real,double im) {
	realPart = real;
	imaginaryPart = im;
}
Complex Complex::Add(const Complex &c)
{
	double _real, _im;
	_real = realPart + c.realPart;
	_im = imaginaryPart + c.imaginaryPart;
	return Complex (_real, _im);
}
Complex Complex::Subs(const Complex &c)
{
	return Complex(realPart - c.realPart, imaginaryPart - c.imaginaryPart);
	//realPart and imaginaryPart --->c1
	//c.realPart and c.imaginaryPart ----> c2
}
void Complex::display() const
{

	cout << "Result is: (" << realPart << "," << imaginaryPart << ")" << endl;
}