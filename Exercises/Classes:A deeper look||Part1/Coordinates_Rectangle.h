// Exercise 9.12 || (Enhancing Class Rectangle) || page:412
#ifndef COORDINATES_RECTANGLE_H
#define COORDINATES_RECTANGLE_H

using namespace std;

class Coord_Rect
{
private:
	int x;
	int y;
public:
	Coord_Rect(int x = 0, int y = 0) { setX(x); setY(y); }

	void setX(int X) { x = X; }
	void setY(int Y) { y = Y; }

	int getX() { return x; }
	int getY() { return y; }
};

#endif // !COORDINATES_RECTANGLE_H
