#include <iostream>
#include<iomanip>

using std::cout;
using std::endl;

int main(){
	char bb = 'B',*b;
	b = &bb;
	cout << static_cast<int>(*b) << endl
		<< static_cast<double>(*b) << endl
		<< static_cast<float>(*b) << endl
		<< static_cast<long int>(*b) << endl
		<< static_cast<unsigned int>(*b) << endl
		<< static_cast<unsigned short int> (*b) << endl
		<< static_cast<signed short int> (*b) << endl
		<< static_cast<signed long int>(*b) << endl
		<< static_cast<unsigned long int>(*b) << endl;
	return 0;
}