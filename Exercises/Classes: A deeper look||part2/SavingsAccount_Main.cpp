#include<iostream>
#include "SavingsAccount.h"

using namespace std;

int main()
{
	SavingsAccount s1(2000), s2(3000);
	SavingsAccount::modifyInterestRate(0.03);
	s1.calculateMonthlyInterest();
	cout << "Monthly Interest and New Balance in the account for s1 (Annual Interest is:%3): " << endl
		<< s1.getBalance();
	s2.calculateMonthlyInterest();
	cout <<endl<< "Monthly Interest and New Balance in the account for s2 (Annual Interest is:%3): " << endl
		<<s2.getBalance();
	
	cout << endl << endl;

	SavingsAccount::modifyInterestRate(0.04);
	s1.calculateMonthlyInterest();
	cout << "Monthly Interest and New Balance in the account for s1 (Annual Interest is:%3): " << endl
		<< s1.getBalance();
	s2.calculateMonthlyInterest();
	cout << endl << "Monthly Interest and New Balance in the account for s2 (Annual Interest is:%3): " << endl
		<< s2.getBalance();

	cout << endl << endl;

	system("pause");
	return 0;
}