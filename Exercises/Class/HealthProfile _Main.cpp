#include<string>
#include<iostream>
#include "HealthProfile.h"

using namespace std;
//constructor
HealthProfile::HealthProfile(string first, string last, string Gender,
	int Height, int Weight, int Day, int Month, int Year) 
{
	setName_first(first);
	setName_last(last);
	setGender(Gender);
	set_height(Height);
	set_weight(Weight);
	setDoB(Day, Month, Year);
	setAge();
}
//set functions
void HealthProfile::setName_first(string first)
{
	firstName = first;
}
void HealthProfile::setName_last(string last)
{
	lastName = last;
}
void HealthProfile::setGender(string Gender)
{
	gender = Gender;
}
void HealthProfile::set_height(int Height)
{
	height = Height;
}
void HealthProfile::set_weight(int Weight)
{
	weight = Weight;
}
void HealthProfile::setDoB(int Day, int Month, int Year)
{
	day = Day; month = Month; year = Year;
}
// get functions
string HealthProfile::getName_first() const {
	return firstName;
}
string HealthProfile::getName_last() const
{
	return lastName;
}
string HealthProfile::get_gender() const
{
	return gender;
}
int HealthProfile::get_height() const
{
	return height;
}
int HealthProfile::get_weight() const
{
	return weight;
}
void HealthProfile::setAge()
{
	int today_day, this_year, today_month;

	cout << "\nPlease enter the today's date:" << endl;
	cin >> today_day >> today_month>> this_year;

	if (today_month < month) {
		age = this_year - year - 1;

	}
	else if (today_month > month) {
		age = this_year - year;
		
	}
	else {
		age = (today_day < day) ? (this_year - year - 1) : (this_year - year);
		
	}
}
int HealthProfile::getAge() const {
	
	return age;
}
int HealthProfile::getMaxHeartRate() const
{ 
	return 220 - getAge(); 
}
void HealthProfile::getTargetHeartRate() const
{
	cout << "Your Target Heart Rate: ";
	cout << 0.5 * getMaxHeartRate() << " - " << 0.85 * getMaxHeartRate()
		<< endl;
}
double HealthProfile::getBMI() const 
{
	return ((get_weight() * 703) / (get_height() * get_height()));
}
void HealthProfile::showBMI() const {
	cout<< "BMI: " << getBMI() << endl;
}
void HealthProfile::displayInformation() const
{
	cout << "\nName: " << getName_first() << " " << getName_last() << endl
		<< "Age: " << getAge() << endl
		<< "Gender: " << get_gender() << endl
		<< "Height and Weight: " << get_weight() << "/" << get_weight() << endl
		<< "Date of Birth: " << day << "/" << month << "/" << year << endl
		<< "Max Heart Rate: " << getMaxHeartRate() << endl;
		
	     getTargetHeartRate();
}