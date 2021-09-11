#include <iostream>
#include "Time.h"

using namespace std;

int main() {
	Time t1(23, 59, 58);

	cout << "t1: ";

	t1.printUniversal();

	cout << endl;

	for (int i = 0; i < 10; ++i) {
		t1.tick();

		t1.printUniversal();
			cout << " ";

			t1.printStandard();
			
			cout << std::endl;
		
	}
	return 0;
}