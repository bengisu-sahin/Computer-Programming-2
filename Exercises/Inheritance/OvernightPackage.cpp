#include "OvernightPackage.h"
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
OvernightPackage::OvernightPackage(Person P1, Person P2, double w, double pc, double fee) :Package(
	P1, P2, w, pc) {
	overnightFee = fee;
}
double OvernightPackage::overnightCost() {
	//Package::calculateCost();
	double totalFee;
	totalFee = Package::getPerCost() + overnightFee;
	Package::setPerCost(totalFee);
	return Package::calculateCost();
}
void OvernightPackage::display() const {
	Package::display();
}