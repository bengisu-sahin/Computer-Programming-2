#include<iomanip>
#include<string>
#include "HeartRates.h"

using namespace std;

int main() {
	HeartRates H1("Bengisu", "Sahin", 11, 2000,25);
	H1.display();
	system("pause");
	return 0;
}