#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
#include "Account.h"

class SavingsAccount :public Account {
private:
	double interestRate;
public:
	SavingsAccount(double, double);
	double calculateInterest();
};
#endif // !SAVINGSACCOUNT_H