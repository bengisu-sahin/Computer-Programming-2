#include "SavingsAccount.h"

using namespace std;

//define and initilaze static data member at global namespace scope
double SavingsAccount::annualInterestRate = 0; //can not include static keyword
//static data member can be initialized once !!!

SavingsAccount::SavingsAccount(double init_balance)
{
	savingsBalance = init_balance;
}
void  SavingsAccount::calculateMonthlyInterest()
{
	savingsBalance+= (savingsBalance*(annualInterestRate / 12));
}
 void SavingsAccount::modifyInterestRate(double new_rate)
{
	 annualInterestRate = new_rate;

}
 double SavingsAccount::getBalance() const
 {
	 return savingsBalance;
 }