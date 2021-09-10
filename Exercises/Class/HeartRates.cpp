#include<iostream>
#include<string>
#include "HeartRates.h"

using namespace std;

HeartRates::HeartRates(string first , string last, int M, int Y, int D)
{
	setName_first(first);
	setName_last(last);
	setYear(Y);
	setMonth(M);
	setDay(D);
	setAge();
}
void HeartRates::setName_first(string first)
{
	firstname = first;
}
void HeartRates::setName_last(string last)
{
	lastname = last;
}
void HeartRates::setYear(int Y)
{
	year = Y;
}
void HeartRates::setDay(int D)
{
	day = D;
}
void HeartRates::setMonth(int M) {
	month = M;
}
void HeartRates::setAge() {
	age = getAges();
}
string HeartRates::getName_first() const
{
	return firstname;
}
string HeartRates::getName_last() const
{
	return lastname;
}
int HeartRates::getYear() const
{
	return year;
}
int HeartRates::getDay() const
{
	return day;

}
int HeartRates::getMonth() const {
	return month;
}

int HeartRates::getAges() 
{
	int today_day, this_year, today_month;

	cout << "\nPlease enter the today's date:" << endl;
	cin >> today_day >> this_year >> today_month;

	if (today_month < getMonth()) {
		return this_year - getYear() - 1;
	}
	else if (today_month > getMonth()) {
		return this_year - getYear();
	}
	else {
		return (today_day < getDay()) ? (this_year - getYear() - 1) : (this_year - getYear());
	}
}
int  HeartRates::getMaxiumumHeartRate()
{
	return 220 - age;
}
void HeartRates::getTargetHeartRate()
{
	cout << "Your Target Heart Rate: "
		<< 0.5 * getMaxiumumHeartRate() << " - "
		<< 0.85 * getMaxiumumHeartRate() << endl;
}
void HeartRates::display()  {
	cout << "\nFirst Name: " << getName_first() << endl
		<< "Last Name: " << getName_last() << endl
		<< "Date of Birth: " << getDay() << "/" << getMonth() << "/" << getYear() << endl
		<< "Age: " << age << endl
		<< "Maximumum Heart Rate : " << getMaxiumumHeartRate() << endl;
	     getTargetHeartRate();
}