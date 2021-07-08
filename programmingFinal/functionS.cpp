#include "dictionaryy.h"
#include "wordss.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include <iomanip>
#include <fstream>
#include<string>
#include <algorithm>

using namespace std;

Dictionary::Dictionary()
{
	fstream dataFile;
	string tmp;
	string dicWords;
	int i, j, x = 0;
	dataFile.open("words.txt", std::fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{

		//set<string>words e dosyadaki kelimeleri atama
		dataFile >> tmp;
		while (!dataFile.eof())
		{
			words.insert(tmp);
			dataFile >> tmp;
		}
	}
	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		dicWords = *it;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (dicWords[i] == dicWords[j + 1])
					break;
				else
					x++;
			}
		}
		if (x == 10)
		{
			secrets.push_back(dicWords);
		}

		x = 0;
	}
}
string Dictionary::BringValidWord()
{
	int number;
	string secretWord;
	srand(time(NULL));
	rand();
	number = 1 + rand() % 1630;
	secretWord = secrets[number];
	if (IsWordValid(secretWord) == 1 && TestLegalSecretWord(secretWord) == 1)
		return secretWord;
	else
		return "";
}
bool Dictionary::IsWordValid(string word)
{

	for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		if (*it == word)
		{
			return true;
		}
	}
	return false;
}
bool Dictionary::TestLegalSecretWord(string word)
{
	int i = 0, j = 1;
	for (; i < 5; i++)
	{
		for (; j < 5; j++)
		{
			if (word[i] == word[j])
				return false;
		}
	}
	return true;
}
Dictionary::~Dictionary()
{
}
// word
Words::Words() {
	cout << "Bilbakalim Oyununa Hosgeldiniz:" << endl
		<< "5 harften olusan bir kelime tuttum." << endl;
	numguesses = 0;
	cheated = 0;
}
void Words::playgame(Words &W) {
	string guess;
	Dictionary d1;
	secret = d1.BringValidWord();
	while (guess != secret) {
		cout << "Tahmininiz Nedir? " << endl;
		cin >> guess;
		transform(guess.begin(), guess.end(), guess.begin(), ::tolower);
		if (d1.IsWordValid(guess) == 1 && guess != secret) {
			cout <<"Eslesen harf sayisi: "<< countofMatchLetters(guess)<<endl;
			cout <<"Eslesen harflerin dogru konumu: "<< countofTruePlaceLetters(guess)<<endl;
			numguesses++;
		}
		else if (guess == "xxxxx") {
			cout << "Ipucu: Gizli Kelime: " << secret<<endl;
			numguesses++;
			cheated == 1;
		}
		else if(d1.IsWordValid(guess)==0) {
			cout << "Bu kelime sozlukte yok!" << endl;
			
		}

	}
	numguesses++;
	if (cheated == 1) {
		cout << "Bildiniz ! " << numguesses << " tahminde ipucu kullanarak dogru sonuca ulastiniz."<<endl;
	}
	else {
		cout << "Bildiniz ! " << numguesses << " tahminde dogru sonuca ulastiniz."<<endl;
	}

}
int Words::countofMatchLetters(string guess)
{
	int i,  counter = 0;
	string _secret = secret;
	for (i = 0; i < 5; i++)
	{
		if (_secret.find(guess[i]) != std::string::npos)
		{
			_secret.replace(secret.find(guess[i]), 1, " ");
			counter++;
		}
	}
	return counter;
}

int Words::countofTruePlaceLetters(string guess) {
	int i, counter = 0;
	for (i = 0; i < 5; i++) {
		if (secret[i] == guess[i])
			counter++;
	}
	return counter;
}