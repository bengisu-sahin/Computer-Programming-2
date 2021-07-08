#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

int main() {
	cout << "Bengisu Sahin||152120191064||bngsshn@gmail.com" << endl << "Second Semester||Midterm" << endl;
	int i = 1, j = 0; 
	float grade, class1_grades[100], class2_grades[100];
	char class1_lessons[20][20], class2_lessons[20][20];
	ofstream notes;
	ifstream group1;
	ifstream group2;

	//Build Bar GraPh
	notes.open("students.txt");
	notes << showpoint << fixed;
	notes << setprecision(2);
	notes << setw(32) << "Bar Graph" << endl;
	notes << left << setw(6) << "Course" << right << setw(8) << "Course" << right << setw(9);
	notes << right << setw(10) << 0;
	while (i <= 10) {
		if (i == 10)
			notes << right << setw(6) << i * 10;
		else
			notes << right << setw(5) << i * 10;
		i++;
	}
	notes << endl << "ID" << setw(13) << "Average";
	notes << setw(9) << setfill(' ');
	for (; j <= 100; j = j + 2) {
		if (j % 10 == 0)
			notes << "|";
		if (j % 2 == 0 && j % 10 != 0)
			notes << ".";
	}
	notes << endl;
	//Finish building bar graph

	//READ GROUP1
	int k = 0, l = 0,lesson_counter1=0;
	float total1 = 0, grade_counter1 = 0, toplam1=0, average1;
	group1.open("group1.txt");
	if (!group1) {
		cout << "Cannot open the group1 file " << endl;
		return 1;
	}
	else {

		while (group1 >> class1_lessons[k]) {
			k++;
			while (group1 >> grade) {
				if (grade == -999)
					break;
				else {
					total1 += grade;
					grade_counter1++;
				}
			}
			total1 = static_cast<int> (total1) / grade_counter1;
			class1_grades[l] = total1;
			l++;
			lesson_counter1++;
			grade_counter1 = 0;
			total1 = 0;

		}
		for (i = 0; i < lesson_counter1; i++) {
			toplam1 += class1_grades[i];
		}
		average1 = toplam1 / lesson_counter1;
		group1.close();
	}
	//FINISH READÝNG GROUP1

	//READ GROUP2
	float  total2 = 0, grade_counter2 = 0,average2=0, toplam2=0;
	int x=0, y=0,lesson_counter2=0;
	group2.open("group2.txt");
	if (!group2) {
		cout << "Cannot open the group2 file " << endl;
		return 1;
	}
	else {
		while (group2 >> class2_lessons[x]) {
			x++;
			while (group2 >> grade) {
				if (grade == -999)
					break;
				else {
					total2 += grade;
					grade_counter2++;
				}
			}
			total2 = static_cast<int>(total2) / grade_counter2;
			class2_grades[y] = total2;
			y++;
			total2 = 0;
			grade_counter2 = 0;
			lesson_counter2++;
		}
		for (i = 0; i < lesson_counter2; i++) {
			toplam2 += class2_grades[i];
		}
		average2 = toplam2 / lesson_counter2;
		group2.close();
	}
	//FINISH READING GROUP2

	//WRITE--->STUDENTS.TXT
	for (i = 0; i< lesson_counter2; i++) {
		notes << class1_lessons[i] << right << setw(10) << class1_grades[i];
		notes << right << setw(11) << setfill(' ');
		for (j = 0; j < static_cast<int> (class1_grades[i]) / 2; j++) {
			notes << '*';
		}
		notes << endl;
		notes << right << setw(13) << setfill(' ') << class2_grades[i];
		notes << right << setw(11);
		for (j = 0; j < static_cast<int> (class2_grades[i]) / 2; j++) {
			notes << '#';
		}
		notes << endl;
	}
	
	notes << endl;
	notes << "Group 1 -- ***" << endl
		  << "Group 2 -- ###" << endl;
	notes << "Avg for group1: " << average1 << endl
		  << "Avg for group2: "<<average2 << endl;
	notes.close();

	system("pause");
	return 0;
}