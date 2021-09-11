#include<iostream>
#include "Rational.h"
//Self-Review Exercises || Exercise 9.6 || page:411
using namespace std;

Rational::Rational()
{
	numerator = 1;
	denominator = 2;
}

Rational::Rational(int init_num, int init_den)
{
	int i,gcd;

	if (init_num > init_den) 
	{
		for (i = 1; i <= init_den; i++)
		{
			if (init_num%i == 0 && init_den %i == 0) 
			{
				gcd = i;
			}

		}
	}
	else if (init_den > init_num)
	{
		for (i =1; i <= init_num; i++)
		{
			if (init_num%i == 0 && init_den %i == 0)
			{
				gcd = i;
			}
		}
	}
	numerator = init_num / gcd;
	denominator = init_den / gcd;
}
void Rational::display() const
{
	cout << numerator << "/" << denominator << endl;
}
void Rational::displayFloatingPoint() const
{
	cout << float(numerator) / float(denominator) << endl;
}