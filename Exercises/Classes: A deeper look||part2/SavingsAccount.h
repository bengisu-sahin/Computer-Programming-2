#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

using namespace std;

class SavingsAccount
{
private:
	static double annualInterestRate;
	double savingsBalance;
public:
	SavingsAccount(double);
	void calculateMonthlyInterest(); //calculates the monthly interest by multiplying the balance
	double getBalance() const;                                  // by annualInterestRate divided by 12
	static void modifyInterestRate(double);   //sets the static annualInterestRate to a new value
	//A static member function is a special member function, 
	//which is used to access only static data members,
	//any other normal data member cannot be accessed through static member function. 
	//Just like static data member, 
	//static member function is also a class function; 
	//it is not associated with any class object
};

#endif // !SAVINGSACCOUNT_H