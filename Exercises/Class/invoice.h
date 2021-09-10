#ifndef  INVOICE_H
#define INVOICE_H
#include<string>
using namespace std;

class Invoice {
private:
	string partNumber;
	string partDescription;
	int price;
	int quantity;
public:
	Invoice(){}//non-param cons.
	Invoice(int, int, string, string); //cons. with param
	void setPartNum(string) ;
	void setPartDescription(string) ;
	void setPrice(int);
	void setQuantity(int);

	string getPartNum() const;
	string getPartDescription() const;
	int getPrice() const;
	int getQuantity() const;

	int  getInvoiceAmount();
};

#endif // ! INVOICE_H