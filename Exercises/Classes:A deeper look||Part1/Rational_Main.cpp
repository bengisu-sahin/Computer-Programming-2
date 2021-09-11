#include<iostream>
#include "Rational.h"
//Self-Review Exercises || Exercise 9.6 || page:411
using namespace std;

int main()
{
	
	int n1, d1,n2,d2;
	cout << "Enter numerator and denominator:" << endl;
	cin >> n1 >> d1;
	cout<<endl << "Enter numerator and denominator:" << endl;
	cin >> n2 >> d2;
	Rational R1(n1, d1),R2(n2,d2);
	Rational R3 = R1 + R2;
	R3.display();
	R3.displayFloatingPoint();
	system("pause");
	return 0;
}