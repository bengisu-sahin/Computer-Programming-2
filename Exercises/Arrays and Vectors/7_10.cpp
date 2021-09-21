#include<iostream>
#include<stdlib.h>

using namespace std;

void calculateSalary(double *,int num);
void Counters(int *, double[],int size);

int main()
{
	const int size = 9;
	int counters[size] = { 0 };
	int numOfelemans,numOfsales;
	double *spSalary;
	cout << "Enter the number of employees." << endl;
	cin >> numOfelemans;
	spSalary = new double[numOfelemans];
	for (int i = 0; i < numOfelemans; ++i) {
		cout << "Please enter the salesperson's gross sales amount for a week: "  ;
		cin>> numOfsales;
		calculateSalary(&spSalary[i], numOfsales);
	}
	Counters(counters,spSalary, numOfelemans);
	for (int j = 0; j < size; j++) {
		if(j!=size-1)
		cout << "$" << j + 2 << "00-" << j + 2
			<< "99: " << counters[j] << endl;
		else {
			cout<<"$1000+:   "<< counters[j] << endl;
		}

	}
	system("pause");
	return 0;
}
void calculateSalary(double *ptr,int num)
{
	*ptr = 200 + num * 0.09;
}
void Counters(int *ptr , double salary [], int elemans)
{
	int i = 0;
	for (; i < elemans; ++i) {
		 if (salary[i] > 999) {
			++ptr[8];
		}
		else if (salary[i] > 899) {
			++ptr[7];
		}
		else if (salary[i] > 799) {
			++ptr[6];
		}
		else if (salary[i] > 699) {
			++ptr[5];
		}
		else if (salary[i] > 599) {
			++ptr[4];
		}
		else if (salary[i] > 499) {
			++ptr[3];
		}
		else if (salary[i] > 399) {
			++ptr[2];
		}
		else if (salary[i] > 299) {
			++ptr[1];
		}
		else if (salary[i] >= 200) {
			++ptr[0];
		}
	}
	}