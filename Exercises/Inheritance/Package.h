#ifndef PACKAGE_H
#define PACKAGE_H
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
#include "Person.h"
#include<string>
using namespace std;

class Package {

private:
	Person sender, reciever;
	double weight, perCost;

public:
	Package(Person, Person, double, double);
	//Setters
	void setWeight(double);
	void setPerCost(double);
	//Getters
	double getWeight() const;
	double getPerCost() const;

	double calculateCost();

	void display() const;

};
 
#endif // !PACKAGE_H
