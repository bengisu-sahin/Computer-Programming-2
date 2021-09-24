#include<iostream>//stands for standard input-output stream ~cin,cout,cerr....
#include<iomanip>//iomanip is a library that is used 
                 //to manipulate the output of C++ program.~
                //setiosflags() , setiosflags,setbase,setfill, setprecision,setw

using namespace std;

/*(Write C++ Statements) Write a statement for each of the following:
a) Print integer 40000 left justified in a 15-digit field.
b) Read a string into character array variable state.
c) Print 200 with and without a sign.
d) Print the decimal value 100 in hexadecimal form preceded by 0x.
e) Read characters into array charArray until the character 'p' isencountered, 
up to a limit of 10 characters (including the terminating null character). 
Extract the delimiter from the input stream, and discard it.
f) Print 1.234 in a 9-digit field with preceding zeros.*/

int main() {
	
	cout <<left<<setw(15)<< "40000" << endl;
	char buffer[100];
	cout << "Enter a string: ";
	cin.get(buffer, 100);//cin.get() is used for accessing character array. 
	                     //It includes white space characters.
	                    //cin.get(string_name, size);
	cout << buffer<<endl<<endl;

	cin.clear();/*In C++ the cin is used to take input from user. 
				Sometimes for some reasons some error flags are set. 
				In that time the cin does not take any input. Sometimes it takes some other characters. 
				So if we clear the cin, then the error flags are reset. 
				Then we can use getline(), get() etc. functions.*/

	cout << "With sign: " << showpos << 200<<endl
		<< "Without sign: " << noshowpos << 200 << endl << endl;

	cout <<"Hexadecimal form of 100: " <<hex << 100 << endl<<endl;

	//istream& getline (char* s, streamsize n );
	//istream& getline(char* s, streamsize n, char delim);
	//The delimiting character is the newline character ('\n') for the first form
	//and delim for the second: 
	//when found in the input sequence, it is extracted from the input sequence
	//but discarded and not written to s.
	char charArray[11];
	cout << "Enter up to 10 chars 'p' to end input:\n";
	cin.getline(charArray, 10, 'p');
	cout << charArray << endl << endl;
	cout << setw(15) << right << setfill('0') << 1.234 << endl;

	system("pause");
	return 0;
}
/*In computer programming, data can be placed in a software buffer before it is processed. 
Because writing data to a buffer is much faster than a direct operation, 
using a buffer while programming in C and C++ makes 
a lot of sense and speeds up the calculation process.*/