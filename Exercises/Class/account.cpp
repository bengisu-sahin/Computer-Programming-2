#include<iostream>
#include "account.h"

using namespace std;

Account::Account(int currentBalance) {
	if (currentBalance > 0)
		accountBalance = currentBalance;
	else
		cout << "Invalid amount." << endl;
}
void Account::credit(int extraMoney) {
	accountBalance += extraMoney;
}
void Account::debit(int lessMoney) {
	if (accountBalance > lessMoney)
		accountBalance = accountBalance - lessMoney;
	else
		cout << "Debit amount exceeded account balance." << endl;
}
int Account::getBalance() const{
	return accountBalance;
}