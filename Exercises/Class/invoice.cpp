#include<iostream>
#include<string>
#include "invoice.h"

using namespace std;

Invoice::Invoice(int p, int q, string num, string des) {
	 setPartNum(num);
	 setPartDescription(des);
	 setPrice(p);
	 setQuantity(q);
}
void Invoice::setPartDescription(string x) 
{
	partDescription = x;
}
void Invoice::setPartNum(string setNum) 
{
	partNumber = setNum;
}

void Invoice::setPrice(int setP) 
{
	price = (setP > 0) ? setP : 0;
}
void Invoice::setQuantity(int setQ) 
{
	if (setQ > 0)
		quantity = setQ;
	else
	quantity=0;
}
string Invoice::getPartNum() const 
{
	return partNumber;
}
string Invoice::getPartDescription() const
{
	return partDescription;
}
int Invoice::getPrice() const
{
	return price;
}
int Invoice::getQuantity() const
{
	return quantity;
}

int Invoice::getInvoiceAmount() 
{
	return price * quantity;
}