#ifndef WORDSS_H
#define WORDSS_H
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include<string>

using namespace std;

class Words {
private:
	string secret;
	int countofMatchLetters(string guess);
	int countofTruePlaceLetters(string guess);
	int numguesses;
	bool cheated;
public:
	Words();
	~Words() {};
	void playgame(Words &W);

};
#endif // !WORDSS_H
