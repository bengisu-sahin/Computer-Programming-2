#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Coordinates_Rectangle.h"

// Exercise 9.12 || (Enhancing Class Rectangle) || page:412

using namespace std;

class Rectangle 
{
private:
	Coord_Rect P1,P2,P3,P4;
public:
	Rectangle(Coord_Rect, Coord_Rect, Coord_Rect, Coord_Rect);

	void set(Coord_Rect, Coord_Rect, Coord_Rect, Coord_Rect);

	int findLenght();
	int findWidth();
	int findArea();
	int findPerimeter();

	void print();
};

#endif // !RECTANGLE_H