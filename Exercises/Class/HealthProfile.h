#ifndef HEALTHPROFÝLE
#define HEALTHPROFÝLE_H
#include<string>
#include<iostream>

using namespace std;

class HealthProfile {
private:
	string firstName;
	string lastName;
	string gender;
	int day, month, year;
	int height;
	int weight;
	int age;

	public:
		HealthProfile(string, string,string, int, int, int, int, int);//constructor

		void setName_first(string);
		void setName_last(string);
		void setGender(string);
		void set_height(int);
		void set_weight(int);
		void setDoB(int,int,int);
		void setAge();

		string getName_first() const;
		string getName_last() const;
		string get_gender() const;
		int get_height() const;
		int get_weight() const;
		int getAge() const;

		double getBMI() const;
		void getTargetHeartRate() const;
		int getMaxHeartRate() const;

		void displayInformation() const;
		void showBMI() const;
};

#endif // !HEALTHPROFÝLE