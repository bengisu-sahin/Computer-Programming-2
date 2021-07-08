#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include <iomanip>
#include <fstream>

#define MAX 100
#define Move_Max 10000

using namespace std;

bool isMonster(int x, int y, int lyrnth[MAX][MAX]);
bool isGold(int x, int y, int lyrnth[MAX][MAX]); 
bool isWall(int x, int y, int lyrnth[MAX][MAX]); 
bool endOrnot(int x, int y, int size, int lyrnth[MAX][MAX]);
bool keptGoldsOrnot(int a[Move_Max], int b[Move_Max], int x, int y, int goldenCounter);

class BuildLabyrienth {
public:
	void DisplayMessage();
	void SolutionPath(int lyrnth[MAX][MAX], int size);//çýkýþ yolu yap
	void BuildGameElemans(int lyrnth[MAX][MAX], int size);
	void display(int lyrnth[MAX][MAX], int size);
};
void BuildLabyrienth::DisplayMessage() {
	int sml = 3;
	char ch = sml;
	cout << "---------------------------------------------------------------------------------------------------" << endl
		<< setw(60) << "WELCOME TO THE MAZE GAME" << endl
		<< "---------------------------------------------------------------------------------------------------" << endl
		<< "~GAME INSTRUCTIONS~" << endl
		<< "------------------"<<endl
		<< ch<<"THE PLAYER WINS THE GAEM WHEN REACH THE LAST LINE WITHOUT BEING CAUGHT BY MONSTERS." <<ch<< endl
		<<ch<< "PLAYER STARTS FROM (0,0) POINT." << ch<<endl
		<< ch<<"1--->WALLS"<<endl<< ch << "0--->PATH"<<endl << ch << "@--->GOLDEN "<<endl << ch <<char(245)<<"--->MONSTER" << endl
		<< "---------------------------------------------------------------------------------------------------" << endl;
}
void BuildLabyrienth::SolutionPath(int lyrnth[MAX][MAX], int size) {
	int column = 0, row = 0,way;
	srand(time(NULL));
	while (row != size - 1)
	{
		if (row == 0 && column == 0) {//(0,0)
			way = 1 + rand() % 2;
			if (way == 1) {
				column++;
				lyrnth[row][column] = 0;
			}
			if (way == 2) {
				row++;
				lyrnth[row][column] = 0;
			}
		}
		if (row == 0 && column == size - 1) {//(0,size-1)
			way = 2 + rand() % 3;
			if (way == 2) {
				row++;
				lyrnth[row][column] = 0;
			}
			if (way == 3) {
				column--;
				lyrnth[row][column] = 0;
			}
		}

		if (row == 0 && column != 0 && column != size - 1) {//(0,orta)
			way = 1 + rand() % 3;
			if (way == 1) {
				column++;
				lyrnth[row][column] = 0;
			}
			if (way == 2) {
				row++;
				lyrnth[row][column] = 0;
			}
			if (way == 3) {
				column--;
				lyrnth[row][column] = 0;
			}
		
		}
		if (row != 0 && row != size - 2 && column == 0){ //(orta,0)
			way = 1 + rand() % 3;
			if (way == 1) {
				column++;
				lyrnth[row][column] = 0;
			}
			if (way == 2) {
				row++;
				lyrnth[row][column] = 0;
			}
			if (way == 3) {
				row--;
				lyrnth[row][column] = 0;
			}
		}
		if (row != 0 && row != size - 1 && column != 0 && column != size-1) {//(orta,orta)
			way = 1 + rand() % 3;
			if (way == 1) {
				column++;
				lyrnth[row][column] = 0;
			}
			if (way == 2) {
				row++;
				lyrnth[row][column] = 0;
			}
			if (way == 3) {
				column--;
				lyrnth[row][column] = 0;
			}
			if (way == 4) {
				row--;
				lyrnth[row][column] = 0;
			}
		}
		if (column == size - 1 && row != 0) {//(1,4) 5x5
			way = 1 + rand() % 3;
			if (way == 1) {
				row++;
				lyrnth[row][column] = 0;
			}
			if (way == 2) {
				column--;
				lyrnth[row][column] = 0;
			}
			if (way == 3) {
				row--;
				lyrnth[row][column] = 0;
			}
		}
		if (row == size - 2) {//size-2
			row++;
			lyrnth[row][column] = 0;
		}
	}

}void BuildLabyrienth::BuildGameElemans(int lyrnth[MAX][MAX], int size) {
	int eleman;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (lyrnth[i][j] == 1) {
				eleman = 1 + rand() % 3; //1---> 1-2-3
				lyrnth[i][j] = eleman;
			}
			if (lyrnth[i][j] == 0) {
				eleman = (5 + (rand() % 2));  //0--->0 ve 1 üretiliyor üzerine 5 ekleniyor---> 5 - 6
				if(eleman==5 && i==size-1)
					lyrnth[i][j] = 6;
				else
					lyrnth[i][j] = eleman;
			}

		}
	}
	
}
void BuildLabyrienth::display(int lyrnth[MAX][MAX], int size) {
	int i, j;
	//canavar ve altýnlarý yerleþtir
	//2---->canavar 3------>altýn
	int y = 245, z = 64;
	lyrnth[0][0] = 0;
	/*for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cout << lyrnth[i][j];
		}
		cout << endl;
	}*/
	//coordinate numbers for lbyr
	cout << endl << endl;
	cout << setw(13) << 0;
	for (i = 1; i < size; i++) {
		cout << setw(4) << i;
	}cout << endl;
	cout << setw(13) << "-";
	for (i =1; i < size; i++) {
		cout << setw(4) << "-";
	}
	cout << endl;
	for (i = 0; i < size; i++) {
		cout << setw(8) << i<<"|";
		for (j = 0; j < size; j++) {
			if (lyrnth[i][j] == 2)
				cout << setw(4) << char(y);//canavar

			else if (lyrnth[i][j] == 6 || lyrnth[i][j] == 3)
				cout << setw(4) << 0;
			else if (lyrnth[i][j] == 5 && i!=size-1)
				cout << setw(4) << char(z); //altýn
			else
				cout << setw(4) << lyrnth[i][j];

		}
		cout << endl;
	}

}
typedef struct Movements {
	int coordinateX[Move_Max];
	int coordinateY[Move_Max];
}playerMovements;
int main() 
{
	int lyrnth[MAX][MAX];
	int size;
	int i, j,k,l;
	int sml = 3;
	int row = 0, column = 0,x=0,y=0,goldenCounter=0;
	char direction='B',ch=sml;
	int keepGoldensCoorX[Move_Max] = { 0 }, keepGoldensCoorY[Move_Max] = { 0 };
	

	cout << "Please enter the labyrienth size:";
	cin >> size;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			lyrnth[i][j] = 1;
	}
	
	BuildLabyrienth GameLbyr;
	GameLbyr.DisplayMessage();
	GameLbyr.SolutionPath(lyrnth, size);
	GameLbyr.BuildGameElemans(lyrnth, size);
	GameLbyr.display(lyrnth, size);
	playerMovements player;
	player.coordinateX[0] = 0;
	player.coordinateY[0] = 0;
	
	while (direction != toupper('e')) {
		cin >> direction;
		if (toupper(direction) == 'D') {
			x++;
			if (isGold(x, y, lyrnth) == 1) {
				if (keptGoldsOrnot(keepGoldensCoorX, keepGoldensCoorY, x, y, goldenCounter) == 1) {
					keepGoldensCoorX[goldenCounter] = x;
					keepGoldensCoorY[goldenCounter] = y;
					goldenCounter++;

				}
			}
				
			if (isWall(x, y, lyrnth) == 1) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				x--;
			}	

			row++; column++;
			player.coordinateX[row] = x;
			player.coordinateY[column] = y;

			cout << "You are at (" << player.coordinateX[row] << "," << player.coordinateY[column] << ")" << endl;

			if (isMonster(x, y, lyrnth) == 1) {
				cout << "YOU LOST THE GAME." << endl;
				cout << "Please enter the labyrienth size:";
				cin >> size;
				for (i = 0; i < size; i++) {
					for (j = 0; j < size; j++)
						lyrnth[i][j] = 1;
				}
				x = 0; y = 0;
				goldenCounter = 0;
				row = 0, column = 0;
				for (l = 0; l < Move_Max; l++) {
					keepGoldensCoorX[l] = { 0 }, keepGoldensCoorY[l] = { 0 };
				}

				for (k = 0; k < Move_Max; k++) {
					player.coordinateX[k] = 0;
					player.coordinateY[k] = 0;
				}
				BuildLabyrienth GameLbyr;
				GameLbyr.DisplayMessage();
				GameLbyr.SolutionPath(lyrnth, size);
				GameLbyr.BuildGameElemans(lyrnth, size);
				GameLbyr.display(lyrnth, size);
				playerMovements player;
				player.coordinateX[0] = 0;
				player.coordinateY[0] = 0;
				
			}
			if (toupper(direction) == 'E') {
				cout << "GAME ENDED";
				break;
			}

			if (endOrnot(x, y, size, lyrnth) == 1) {
				cout <<ch<< "YOU WIN THE GAME."<<ch<<endl<<"THE GOLD YOU COLLECT:" << goldenCounter;

				break;
			}
		
		}
			
		if (toupper(direction) == 'U') {
			x--;
			if (x < 0 ) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				x++;
			}
			if (isGold(x, y, lyrnth) == 1) {
				if (keptGoldsOrnot(keepGoldensCoorX, keepGoldensCoorY, x, y, goldenCounter) == 1) {
					keepGoldensCoorX[goldenCounter] = x;
					keepGoldensCoorY[goldenCounter] = y;
					goldenCounter++;

				}
			}
			if(isWall(x, y, lyrnth) == 1) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				x++;
			}
			row++; column++;
			player.coordinateX[row] = x;
			player.coordinateY[column] = y;

			cout << "You are at (" << player.coordinateX[row] << "," << player.coordinateY[column] << ")" << endl;

			if (isMonster(x, y, lyrnth) == 1) {
				cout << "YOU LOST THE GAME." << endl;
				cout << "Please enter the labyrienth size:";
				cin >> size;
				for (i = 0; i < size; i++) {
					for (j = 0; j < size; j++)
						lyrnth[i][j] = 1;
				}for (k = 0; k < Move_Max; k++) {
					player.coordinateX[k] = 0;
					player.coordinateY[k] = 0;
				}
				row = 0, column = 0;
				goldenCounter = 0;
				x = 0; y = 0;
				for(l = 0; l < Move_Max; l++){
				keepGoldensCoorX[l] = { 0 }, keepGoldensCoorY[l] = { 0 };
				}
				
				BuildLabyrienth GameLbyr;
				GameLbyr.DisplayMessage();
				GameLbyr.SolutionPath(lyrnth, size);
				GameLbyr.BuildGameElemans(lyrnth, size);
				GameLbyr.display(lyrnth, size);
				playerMovements player;
				player.coordinateX[0] = 0;
				player.coordinateY[0] = 0;

			}
			if (toupper(direction) == 'E') {
					cout << "GAME ENDED";
					break;
				}
				
			
			if (endOrnot(x, y, size, lyrnth) == 1) {
				cout << ch << "YOU WIN THE GAME." << ch << endl << "THE GOLD YOU COLLECT:" << goldenCounter;
				break;
			}

		}
		if (toupper(direction) == 'R') {
			y++;
			if (y > size-1) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				y--;;
			}
			if (isGold(x, y, lyrnth) == 1) {
				if (keptGoldsOrnot(keepGoldensCoorX, keepGoldensCoorY, x, y, goldenCounter) == 1) {
					keepGoldensCoorX[goldenCounter] = x;
					keepGoldensCoorY[goldenCounter] = y;
					goldenCounter++;

				}

			}
			if(isWall(x, y, lyrnth) == 1) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				y--;
			}
			row++; column++;
			player.coordinateX[row] = x;
			player.coordinateY[column] = y;

			cout << "You are at (" << player.coordinateX[row] << "," << player.coordinateY[column] << ")" << endl;

			if (isMonster(x, y, lyrnth) == 1) {
				cout << "YOU LOST THE GAME." << endl;
				cout << "Please enter the labyrienth size:";
				cin >> size;
				for (i = 0; i < size; i++) {
					for (j = 0; j < size; j++)
						lyrnth[i][j] = 1;
				}for (k = 0; k < Move_Max; k++) {
					player.coordinateX[k] = 0;
					player.coordinateY[k] = 0;
				}row = 0, column = 0;
				goldenCounter = 0;
				x = 0; y = 0;
				for (l = 0; l < Move_Max; l++) {
					keepGoldensCoorX[l] = { 0 }, keepGoldensCoorY[l] = { 0 };
				}

				BuildLabyrienth GameLbyr;
				GameLbyr.DisplayMessage();
				GameLbyr.SolutionPath(lyrnth, size);
				GameLbyr.BuildGameElemans(lyrnth, size);
				GameLbyr.display(lyrnth, size);
				playerMovements player;
				player.coordinateX[0] = 0;
				player.coordinateY[0] = 0;

			}
			if (endOrnot(x, y, size, lyrnth) == 1) {
				cout << ch << "YOU WIN THE GAME." << ch << endl << "THE GOLD YOU COLLECT:" << goldenCounter;
				break;
				}
			if (toupper(direction) == 'E') {
					cout << "GAME ENDED";
					break;
				}	
		
		}
		if (toupper(direction) == 'L') {
			y--;
			if (y < 0) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				y++;
			}
			if (isGold(x, y, lyrnth) == 1) {
				if (keptGoldsOrnot(keepGoldensCoorX, keepGoldensCoorY, x, y, goldenCounter) == 1) {
					keepGoldensCoorX[goldenCounter] = x;
					keepGoldensCoorY[goldenCounter] = y;
					goldenCounter++;

				}
			}
			if(isWall(x, y, lyrnth) == 1) {
				cout << "You tried invalid movements,please enter a new direction." << endl;
				y++;
			}
			row++; column++;
			player.coordinateX[row] = x;
			player.coordinateY[column] = y;

			cout << "You are at (" << player.coordinateX[row] << "," << player.coordinateY[column] << ")" << endl;

			if (isMonster(x, y, lyrnth) == 1) {
				cout << "YOU LOST THE GAME." << endl;
				cout << "Please enter the labyrienth size:";
				cin >> size;
				for (i = 0; i < size; i++) {
					for (j = 0; j < size; j++)
						lyrnth[i][j] = 1;
				}for (k = 0; k < Move_Max; k++) {
					player.coordinateX[k] = 0;
					player.coordinateY[k] = 0;
				}row = 0, column = 0;
				goldenCounter = 0;
				x = 0; y = 0;
				for (l = 0; l < Move_Max; l++) {
					keepGoldensCoorX[l] = { 0 }, keepGoldensCoorY[l] = { 0 };
				}

				BuildLabyrienth GameLbyr;
				GameLbyr.DisplayMessage();
				GameLbyr.SolutionPath(lyrnth, size);
				GameLbyr.BuildGameElemans(lyrnth, size);
				GameLbyr.display(lyrnth, size);
				playerMovements player;
				player.coordinateX[0] = 0;
				player.coordinateY[0] = 0;

			}
			if (toupper(direction) == 'E') {
					cout << "GAME ENDED";
					break;
				}
				
			if (endOrnot(x, y, size, lyrnth) == 1) {
				cout << ch << "YOU WIN THE GAME." << ch << endl << "THE GOLD YOU COLLECT:" << goldenCounter;
				break;
			}
			if (toupper(direction) == 'E') {
					cout << "GAME ENDED";
					break;
				}			
		}
		if (toupper(direction) == 'E') {
			cout << "GAME ENDED";
			break;
		}
		
	}

	//file processing
	ofstream output;
	output.open("coordinates.txt");
	output << "The Way Out of the Labyrinth" << endl
		<< "----------------------------" << endl
		<< setw(7)<<" x "<< setw(5) << "y" << endl
	    << setw(6) << "-" << setw(6) << "-" << endl;
	for (i = 0; i <= row; i++) {
		output << setw(6) << player.coordinateX[i] << setw(6) << player.coordinateY[i] << endl;
		  }
	output.close();

	return 0;
	system("pause");

}
bool isMonster(int x, int y, int lyrnth[MAX][MAX]) {
	if (lyrnth[x][y] == 2)
		return true;
	else
		return false;
}
bool isGold(int x, int y, int lyrnth[MAX][MAX]) {
	if ( lyrnth[x][y]==5)
		return true;
	else
		return false;
}
bool isWall(int x, int y, int lyrnth[MAX][MAX]) {
	if (lyrnth[x][y] == 1)
		return true;
	else
		return false;
}
bool endOrnot(int x, int y,int size, int lyrnth[MAX][MAX]) {
	if ((lyrnth[x][y] == 6 || lyrnth[x][y] == 5 || lyrnth[x][y] == 3) && x==size-1)
		return true;
	else
		return false;
}
bool keptGoldsOrnot(int a[Move_Max], int b[Move_Max], int x, int y, int goldenCounter)
{
	int i=0;

	while ( i <= goldenCounter) {
		if ((a[i] != x || b[i] != y)!=0) {
			i++;
		}
		if (a[i] == x && b[i] == y)
			return false;
	}
	
	return true;
}