#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
class TwoDayPackage :public Package {
private:
	double flat_fee;
public:
	TwoDayPackage(Person,Person,double,double,double);
	double TwoDayCalculateCost(); //redefines Package's calculateCost function
	void display() const;
};

#endif // !TWODAYPACKAGE_H
