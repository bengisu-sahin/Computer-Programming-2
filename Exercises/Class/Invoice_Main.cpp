#include<iostream>
#include<string>
#include "invoice.h"

using namespace std;

int main() {
	Invoice invoice1(12,6,"Hammer","12345");

	cout << "Part Number: " << invoice1.getPartNum();
	cout << "\nPart Description: " << invoice1.getPartDescription();
	cout << "\n"
		<< invoice1.getQuantity() << " x "
		<< invoice1.getInvoiceAmount();
	cout << " = " << invoice1.getInvoiceAmount() << endl;
	system("pause");
	return 0;
}
