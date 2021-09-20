#include<iostream>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include "Person.h"
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
using namespace std;

int main() {
	Person S{ "Bob", "Bobson", "12 Bob Street",
		"Bobzone" };
	Person R{ "Sue", "Sueson", "12 Sue Street",
		"Suezona" };
	//OvernightPackage P(S,R,12.0, 5.0, 1.0);
	OvernightPackage P(Person("Bob", "Bobson", "12 Bob Street", "BobVille"
		),
		Person("Sue", "Sueson", "12 Sue Street", "SueVille"
			),
		12.0f, 5.0f, 1.0f);
	TwoDayPackage X(S, R, 12, 3, 5);
	cout << ".............INFORMATIONS..........." << endl << endl;
	P.display();
	cout  <<"---Cost for Overnight Package---: "<<P.calculateCost() << endl << endl;
	X.display();
	cout << "---Cost for Two Day Package---: " << X.calculateCost();
	cout << endl << endl;
	system("pause");
	return 0;
}