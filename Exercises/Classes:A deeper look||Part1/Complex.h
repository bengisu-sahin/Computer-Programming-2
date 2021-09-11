#ifndef COMPLEX_H
#define COMPLEX_H
//Self-Review Exercises || Exercise 9.5 || page:411
using namespace std;

class Complex {
private:
	double realPart;
	double imaginaryPart;
public:
	Complex(double , double );


	Complex Add(const Complex &);   //returns an Complex obj
	Complex Subs(const Complex &); //returns an Complex obj
	void setParts(double real, double im);
	void display() const;
};

#endif // !COMPLEX_H