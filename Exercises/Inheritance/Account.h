#ifndef ACCOUNT_H
#define ACCOUNT_H
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
class Account {
private:
	double balance;
public:
	Account(double ); //constructor with param
	double getBalance() const;
	void credit(double); //add an amount to the current balance
	void debit(double);  //withdraw money from the account
};

#endif // !ACCOUNT_H
