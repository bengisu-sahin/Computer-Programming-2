#include<iostream>
#include "Rectangle.h"

// Exercise 9.12 || (Enhancing Class Rectangle) || page:412

using namespace std;

Rectangle::Rectangle(Coord_Rect p1, Coord_Rect p2, Coord_Rect p3, Coord_Rect p4)
{
	set(p1, p2, p3, p4);
}
void Rectangle::set(Coord_Rect p1, Coord_Rect p2, Coord_Rect p3, Coord_Rect p4)
{
	if (p1.getX() < 20 && p1.getX() >= 0 && p1.getY() < 20 && p1.getY() >= 0 &&
		p2.getX() < 20 && p2.getX() >= 0 && p2.getY() < 20 && p2.getY() >= 0 &&
		p3.getX() < 20 && p3.getX() >= 0 && p3.getY() < 20 && p3.getY() >= 0 &&
		p4.getX() < 20 && p4.getX() >= 0 && p4.getY() < 20 && p4.getY() >= 0)
	{
		if (p1.getX() == p2.getX() && p3.getX() == p4.getX()) {
			P1 = p1;
			P2 = p2;
			P3 = p3;
			P4 = p4;
			
		}
		else{
			cout << "Rectangle can not be created with these points." << endl;
		}
	}
	else {
		cout << "Invalid coordinates." << endl;
	}

}

int Rectangle::findLenght()
{
	int L;
	L = P2.getY() - P1.getY();
	if (L < 0)
		return -L;
	else
		return L;
}
int Rectangle::findWidth()
{
	int W;
	W = P3.getY() - P4.getY();
	if (W < 0)
		return -W;
	else
		return W;
}
int Rectangle::findArea()
{
	return findWidth()*findLenght();
}
int Rectangle::findPerimeter()
{
	return (findWidth() + findLenght()) * 2;
}
void Rectangle::print()
{
	cout << "Width= " << findWidth() << endl
		<< "Lenght= " << findLenght() << endl
		<< "Area= " << findArea() << endl;
}