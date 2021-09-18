#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>
//Exercise:10.11 (Card Shuffling and Dealing) Page:449
using namespace std;

class Card
{
private:

	int face;
	int suit;
	static string faces[];
	static string suits[];

public:
	Card(int, int);
	string toString() const;

};

#endif // !CARD_H