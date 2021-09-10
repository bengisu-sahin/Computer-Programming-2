#ifndef HEARTRATES_H
#define HEARTRATES_H
#include<iomanip>
#include<string>
using namespace std;

class HeartRates {
private:
	string firstname;
	string lastname;
	int month;
	int year;
	int day;
	int age;
public:
	HeartRates(string , string , int , int , int );

	void setName_first(string);
	void setName_last(string);
	void setYear(int);
	void setDay(int);
	void setMonth(int);
	void setAge();

	string getName_first() const;
	string getName_last() const;
	int getYear() const;
	int getDay() const;
	int getMonth() const;

	int getAges();
	int  getMaxiumumHeartRate();
	void getTargetHeartRate();

	void display() ;
};

#endif // !HEARTRATES_H