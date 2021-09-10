#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account {
private:
	int accountBalance;
public:
	Account(int );
	void credit(int); //add a money into the current balance
	void debit(int);//withdraw money from the account
	int getBalance() const;
};


#endif // !ACCOUNT_H