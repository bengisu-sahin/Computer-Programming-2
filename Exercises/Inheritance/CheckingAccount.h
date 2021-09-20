#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
#include "Account.h"

class CheckingAccount :public Account {
private:
	double fee;
public:
	CheckingAccount(double, double);
	void creditWfee(double);
	void debitWfee(double);
};

#endif // !CHECKINGACCOUNT_H