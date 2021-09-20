#include<iostream>
#include"Account.h"
#include"SavingsAccount.h"
#include"CheckingAccount.h"
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
using namespace std;

int main() {
	SavingsAccount sa(1000, .5);
	CheckingAccount ca(1000, 1.5);

	std::cout << "Savings Account initial balance: " << sa.getBalance();
	sa.credit(50);
	std::cout << "\ncredit 50: " << sa.getBalance();
	sa.debit(100);
	std::cout << "\ndebit 100: " << sa.getBalance()
		<< "\nChecking Account initial balance: " << ca.getBalance();
	ca.credit(50);
	cout << "\ncredit 50: " << ca.getBalance();
	ca.debit(100);
	cout << "\ndebit 100: " << ca.getBalance() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}