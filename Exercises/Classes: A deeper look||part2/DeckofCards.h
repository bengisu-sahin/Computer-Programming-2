#include "Card.h"
#include<iostream>
#include<string>
#include<vector>
//Exercise:10.11 (Card Shuffling and Dealing) Page:449
using namespace std;

class DeckofCards {
private:
	int currentCard=52;
	vector<Card>decks;
public:
	DeckofCards();
	void shuffle();
	Card dealCard();
	bool moreCards();
};