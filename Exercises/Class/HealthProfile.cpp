#include<string>
#include<iostream>
#include "HealthProfile.h"

using namespace std;

int main()
{
	string firstName, lastName, gender;
	int height, weight, day, month, year;
	cout << "Please enter your informations..." << endl << endl,
	cout << "Name: ";
	cin >> firstName >> lastName;
	cout << "Gender: ";
	cin >> gender;
	cin.ignore();
	cout << "Height and Weight:";
	cin >> height >> weight;
	cout << "Date of Birth: ";
	cin >> day >> month >> year;

	HealthProfile H1(firstName,lastName,gender,height,weight,day,month,year);
	H1.displayInformation();
	return 0;
}