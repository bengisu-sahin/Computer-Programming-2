#include"CheckingAccount.h"
//12.10(Account Inheritance Hierarchy) page=533 deitel cpp 8th edition
CheckingAccount::CheckingAccount(double currentBalance, double Fee) :Account(currentBalance) {
	fee = Fee;
}
void CheckingAccount::creditWfee(double money) {
	money = money - fee;
	Account::credit(money);
}
void CheckingAccount::debitWfee(double money) {
	money = money + fee;
	Account::debit(money);
}