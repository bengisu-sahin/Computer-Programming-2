#include "Package.h"
#include<iostream>
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
Package::Package(Person p1, Person p2,double Weight,double per_cost):sender(p1), reciever(p2)
{
	setWeight(Weight);
	setPerCost(per_cost);
}
void Package::setWeight(double Weight) {
	if (Weight < 0) {
		cout << "You entered invalid value." << endl;
		weight = 0;
	}else
		weight = Weight;
}
void Package::setPerCost(double per_cost) {
	if (per_cost < 0) {
		cout << "You entered invalid value." << endl;
		per_cost = 0;
	}
	else
		perCost = per_cost;
}
double Package::getWeight() const {
	return weight;
}
double Package::getPerCost() const {
	return perCost;
}
double Package::calculateCost() {
	double cost = perCost * weight;
	return cost;
}
void Package::display() const {
	cout << "Sender's Informations: " << endl
		<< sender.name << endl << sender.city << endl
		<< sender.state << endl << sender.adress << endl;
	cout<<"Receiver's Informations: "<<endl
		<< reciever.name << endl << reciever.city << endl
		<< reciever.state << endl << reciever.adress << endl;
}