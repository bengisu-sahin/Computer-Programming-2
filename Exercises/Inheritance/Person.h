#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;
//12.9 (Package Inheritance Hierarchy) page:532 deitel 8th edition
struct Person
{
	string name;
	string adress;
	string city;
	string state;

	Person(string n, string a, string c, string s) :name(n), adress(a), city(c), state(s) {}
};
#endif // !PERSON_H
