#include "SavingsAccount.h"
#include<iostream>
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
using namespace std;

SavingsAccount::SavingsAccount(double currentBalance, double percentage) :Account(currentBalance) {
	percentage = interestRate;
}
double SavingsAccount::calculateInterest() {

	return interestRate * Account::getBalance();
}
