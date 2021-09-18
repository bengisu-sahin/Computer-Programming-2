#include "Card.h"
#include<iostream>
#include<string>
//Exercise:10.11 (Card Shuffling and Dealing) Page:449
using namespace std;

string Card::faces[5] = { "","spades","hearts","diamonds","clubs" };
string Card::suits[14]= { "", "ace",  "two",   "three", "four",
					      "five", "six",  "seven", "eight", "nine",
					      "ten",  "jack", "queen", "king" };

Card::Card(int f, int s) {
	face = f;
	suit = s;

}
string Card::toString() const 
{
	return faces[face] +  " of "  + suits[suit];
}