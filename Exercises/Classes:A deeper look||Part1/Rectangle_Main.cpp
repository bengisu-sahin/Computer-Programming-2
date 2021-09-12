#include<iostream>
#include "Rectangle.h"

// Exercise 9.12 || (Enhancing Class Rectangle) || page:412

int main()
{
	Coord_Rect P1(3, 7), P2(3, 18), P3(5, 18), P4(5,12);
	Rectangle R1(P1, P2, P3, P4);
	R1.print();
	return 0;
}