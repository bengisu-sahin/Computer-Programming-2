#include "TwoDayPackage.h"
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
TwoDayPackage::TwoDayPackage(Person P1, Person P2, double w, double pc, double fee) :Package(
	P1, P2, w, pc) {
	flat_fee = fee;
}
double TwoDayPackage::TwoDayCalculateCost() {
	double cost;
	cost=Package::calculateCost();
	return cost + flat_fee;
}
void TwoDayPackage::display() const {
	Package::display();
}