#include<iostream>
#include "Complex.h"
//Self-Review Exercises || Exercise 9.5 || page:411
using namespace std;

int main()
{
	
	double r1, i1,r2,i2;
	cout << "Enter the first Complex Number's real and imaginary part: " << endl;
	cin >> r1 >> i1;
	Complex c1(r1, i1);
	
	cout << "Enter the second Complex Number's real and imaginary part: " << endl;
	cin >> r2 >> i2;
	Complex c2(r2, i2);
	
	Complex result1=c1.Subs(c2); 
	result1.display();
	Complex result2 = c1.Add(c2);
	result2.display();
	system("pause");
	return 0;
}