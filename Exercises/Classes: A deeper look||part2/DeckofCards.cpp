#include "Card.h"
#include<iostream>
#include<string>
#include<vector>
#include "DeckofCards.h"
#include<stdlib.h>
#include<time.h>
//Exercise:10.11 (Card Shuffling and Dealing) Page:449
using namespace std;

DeckofCards::DeckofCards() {
	
	int i = 1,j;
	for (; i <= 4; ++i)
	{	
		for (j = 1; j <= 13; j++)
		{
			Card cards(i, j);
			decks.push_back(cards);
		}
	}
}
void DeckofCards::shuffle() {
	srand(time(NULL));
	int i , k;
	for ( k = 1; k <= 26; k++) {
		 i = 1 + rand() % 52;
		 Card tmp = decks.at(k);
		 decks.at(k) = decks.at(i);
		 decks.at(i) = tmp;
	}
}
Card DeckofCards::dealCard()
{
	
		if (moreCards() == true)
		{
			currentCard--;
			return decks[currentCard];
		}
		else
			cout << endl << endl << "All cards dealt" << endl << endl;
	
	
}
bool DeckofCards::moreCards() 
{
	if (currentCard >= 1) {
		
		return true;
	}
		
	else
		return false;
}