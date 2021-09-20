#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
#include "Package.h"
#include<iostream>

class OvernightPackage:public Package {
private:
	double overnightFee;
public:
	OvernightPackage(Person, Person, double, double, double);
	double overnightCost();
	void display() const;
};

#endif // !OVERNIGHTPACKAGE_H
