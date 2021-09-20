#include"Account.h"
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
#include<iostream>

using std::cout;
using std::endl;

Account::Account(double totalMoney) {
	if (totalMoney >= 0) {
		balance = totalMoney;
	}
	else {
		balance = 0;
		cout << "You entered invalid amount of money." << endl;
	}
}
double Account::getBalance() const {
	return balance;
}
void Account::credit(double extraMoney) {
	balance += extraMoney;
}
void Account::debit(double money) {
	if (money > balance) 
	{
		cout << "Debit amount exceeded account balance."  << endl;		
	}
	else
	{
		balance -= money;
	}

}