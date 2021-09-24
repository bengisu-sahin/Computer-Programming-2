#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int Dec, Oct, Hex;

	cout << "Enter three type of(decimal,octal,hexadecimal) integer: " << endl;
	cin >> Dec >> Oct >> Hex;

	cout << left << setw(15) << "Decimal" << left << setw(15)
		<< "Octal" << left << setw(15) << "Hexadecimal" << endl;

	cout << std::dec << left << setw(15) << Dec
		<< left << setw(15) << oct << Dec
		<< hex << left << setw(15) << Dec << endl;

	cout << std::dec << left << setw(15) << Oct
		<< left << setw(15) << oct << Oct
		<< hex << left << setw(15) << Oct << endl;

	cout << std::dec << left << setw(15) << Hex
		<< left << setw(15) << oct << Hex
		<< hex << left << setw(15) << Hex << endl;

	return 0;
}