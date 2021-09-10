#include<iostream>
#include "account.h"

using namespace std;

int main() {
	Account a1(500), a2(10000);
	cout << "Current amount of money for a1 in the account is : " << a1.getBalance() << endl;
	cout << "Current amount of money for a2 in the account is : " << a2.getBalance() << endl;
	a1.credit(100);
	a1.debit(200);
	a2.credit(1000);
	a2.debit(50000);
	cout << "Current amount of money for a1 in the account is : " << a1.getBalance() << endl;
	cout << "Current amount of money for a2 in the account is : " << a2.getBalance() << endl;
	cout << endl << endl;
	system("pause");
	return 0;
}
