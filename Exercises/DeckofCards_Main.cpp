#include "DeckofCards.h"
#include<iostream>
#include<string>
//Exercise:10.11 (Card Shuffling and Dealing) Page:449
using namespace std;

int main()
{
	DeckofCards deck1;
	deck1.shuffle();
	
	while (deck1.moreCards() == true) 
	{
		cout << deck1.dealCard().toString() << endl;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}