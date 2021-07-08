#ifndef DICTIONARYY_H
#define DICTIONARYY_H

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include<string>
#include <set>
using namespace std;
class Dictionary
{
private:
	set<string> words;
	vector<string> secrets;
	bool TestLegalSecretWord(string word);

public:
	Dictionary();
	~Dictionary();

	string BringValidWord();
	bool IsWordValid(string word);
};
#endif // !DICTIONARYY_H