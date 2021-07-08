#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include <iomanip>
#include <fstream>

#define FILTERSIZE 100

using namespace std;

double total(double mirrored_image[21][21], int i,int j, double kernel[9][9], int filterSize);

int main() {
	ifstream infile;
	int imageSize, filterSize, whitePx, blackPx,mirrorSize;
	int i, j, num;
	double input_image[9][9];

	double value,kernel[9][9] = { 0 };
	int f,d;

	double input_grid[21][21], output_grid[21][21];
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			input_grid[i][j] = 0;
			output_grid[i][j] = 0;
		}
	}
	cout << "Processing data..." << endl << endl;

	infile.open("inputs.txt");
	if (!infile) {
		cout << "Cannot open the inputs file.";
		return 1;
	}
	else {
		infile >> imageSize >> filterSize >> whitePx >> blackPx;
		//cout << imageSize << endl << filterSize <<endl<<whitePx << endl << blackPx << endl;
		infile.close();
	}
	
	cout.setf(ios::fixed);
	cout.precision(4);

	srand(time(NULL));
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			num = rand() % whitePx + blackPx;
			input_image[i][j] = num;
		}
	}

	//print image
	cout << "Input Image (" << imageSize << "x" << imageSize << ")" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			cout << right << setw(9)<< input_image[i][j];
		}
		cout << endl;
	}
	cout << endl<<endl;
	f = filterSize / 2;
	for (d = 0; d < f; d++)
	{
		value = 1.0 / pow((2 * (d + 1) + 1), 2);
		for (i = -(d + 1); i <= d + 1; i++)
		{
			for (j = -(d + 1); j <= d + 1; j++)
				kernel[f - i][f - j] = kernel[f - i][f - j] + value;
		}

	}


	for (i = 0; i < filterSize; i++)
	{
		for (j = 0; j < filterSize; j++)
		{
			kernel[i][j] = kernel[i][j] / static_cast<double>(filterSize);
		}
	}


	//print kernel/gauss filter
	cout << "Gaussian Filter (" << filterSize << "x" << filterSize << ")" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < filterSize; i++)
	{
		for (j = 0; j < filterSize; j++)
		{

			cout << right << setw(9) << kernel[i][j];

		}
		cout << endl;
	}

	mirrorSize = filterSize / 2;
	int  roundx = 0, roundy = 0;
	double mirrored_image[21][21];
	//for 0,0
	for ( roundx = 0; roundx <= mirrorSize; roundx++) {

		for ( roundy = 0; roundy <= mirrorSize; roundy++) {
			 mirrored_image[roundx][roundy] = input_image[0][0];
		}
	}
	//for 0,imageSize-1
	mirrored_image[mirrorSize][imageSize - 1 + mirrorSize]= input_image[0][imageSize-1];
	for (roundx=mirrorSize; roundx >= 0; roundx--) {
		for ( roundy = 0; roundy <= mirrorSize; roundy++) {
			mirrored_image[roundx][imageSize - 1 + mirrorSize+ roundy] = input_image[0][imageSize - 1];
		}
		
	}
	//imageSize-1,0
	mirrored_image[imageSize - 1 + mirrorSize][mirrorSize] = input_image[imageSize - 1][0];
	for (roundx = 0; roundx <= mirrorSize; roundx++) {
		for (roundy = mirrorSize; roundy >= 0;roundy--) {
			mirrored_image[imageSize - 1 + roundx + mirrorSize][roundy] = input_image[imageSize - 1][0];
		}
	}
	//imageSize-1,imageSize-1
	mirrored_image[imageSize - 1 + mirrorSize][imageSize - 1 + mirrorSize] = input_image[imageSize - 1][imageSize - 1];
	for (roundx = 0; roundx <= mirrorSize; roundx++) {
		for (roundy = 0; roundy <=mirrorSize; roundy++) {
			mirrored_image[imageSize - 1 + roundx + mirrorSize][imageSize - 1+roundy + mirrorSize] = input_image[imageSize - 1][imageSize - 1];
		}
	}
	
	//inside
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			mirrored_image[i + mirrorSize][j + mirrorSize] = input_image[i][j];
		}
	}
	//upper-side
	
	for (roundy = 1; roundy < imageSize-1; roundy++) {
		mirrored_image[mirrorSize][mirrorSize + roundy]=input_image[0][roundy];
		for (roundx = 1; roundx <= mirrorSize; roundx++) {
			mirrored_image[mirrorSize - roundx][mirrorSize + roundy] = input_image[0][roundy];
		}
	}
	//lower-side
	for (roundy = 1; roundy < imageSize - 1; roundy++) {
		mirrored_image[mirrorSize+imageSize][mirrorSize + roundy] = input_image[imageSize-1][roundy];
		for (roundx = 1; roundx <= mirrorSize; roundx++) {
			mirrored_image[mirrorSize + imageSize-1 + roundx][mirrorSize + roundy] = input_image[imageSize-1][roundy];
		}
	}
	//left-side
	for (roundy = 1; roundy < imageSize - 1; roundy++) {
		mirrored_image[mirrorSize + roundy][mirrorSize] = input_image[roundy][0];
		for (roundx = mirrorSize; roundx >0; roundx--) {
			mirrored_image[mirrorSize + roundy][mirrorSize-roundx] = input_image[roundy][0];
		}
	}
	//right-side
	for (roundy = 1; roundy < imageSize - 1; roundy++) {
		mirrored_image[mirrorSize + roundy][mirrorSize+ imageSize - 1] = input_image[roundy][imageSize-1];
		for (roundx = mirrorSize; roundx > 0; roundx--) {
			mirrored_image[mirrorSize + roundy][mirrorSize + roundx + imageSize - 1] = input_image[roundy][imageSize - 1];
		}
	}
	//print mirrored image
	/*for (i = 0; i < imageSize + 2 * mirrorSize; i++) {
		for (j = 0; j < imageSize + 2 * mirrorSize; j++) {
			cout << mirrored_image[i][j] << ' ';
		}
		cout << endl;
	}*/
	int startingPoint=(21-(imageSize+mirrorSize*2))/2;
	//build-inputgrid with mirrored matrix
	for (i = 0; i < imageSize+2*mirrorSize; i++) {
		for (j = 0; j < imageSize + 2 * mirrorSize; j++) {
			input_grid[i+ startingPoint][j+ startingPoint] = mirrored_image[i][j];
		}
	}
	cout << endl<<endl<<endl;
	//print input_grid
	cout << "Input Grid: Edge Mirrored Image (21x21)" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21 ; j++) {
			cout << right << setw(9)<< input_grid[i][j];
		}
		cout << endl;
	}
	cout << endl<<endl;
	double cutted_image[21][21];
	j = 0;
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			cutted_image[i][j] = total(mirrored_image, i,j, kernel, filterSize);
	

		}
	}

	//print image
	/*for (i = 0; i < imageSize + 2 * mirrorSize; i++) {
		for (j = 0; j < imageSize + 2 * mirrorSize; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}*/
	cout << endl;
	cout << "Output (Filtered) Image (" << imageSize << "x" << imageSize << ")" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			cout << right << setw(9) << cutted_image[i][j];
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	int startingPoint2 = (21 - (imageSize)) / 2;
	//build-outputgrid with mirrored matrix
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			output_grid[i + startingPoint2][j + startingPoint2] = cutted_image[i][j];
		}
	}
	//print outpt_grid
	cout << "Output Grid: Cutted-Edge Image (21x21)" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			cout << right << setw(9) << output_grid[i][j];
		}
		cout << endl;
	}
	ofstream outfile("outputs.txt");
	outfile << std::fixed << std::setprecision(4);
	outfile << "Input Image (" <<imageSize<< "x" << imageSize<< ")" << endl
		    << "-------------------------------------------------------------------------------" << endl; 
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			outfile << right << setw(9) <<input_image[i][j];
		}
		outfile << endl;
	}
	outfile <<endl<< "-------------------------------------------------------------------------------" << endl;
	outfile << "Gaussian Filter (" <<filterSize <<"x"<< filterSize <<")"<< endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < filterSize; i++)
	{
		for (j = 0; j < filterSize; j++)
		{

			outfile << right << setw(9) << kernel[i][j];

		}
		outfile << endl;
	}
	outfile << endl << "-------------------------------------------------------------------------------" << endl;
	outfile << "Input Grid: Edge Mirrored Image (21x21)" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			outfile << right << setw(9)<< input_grid[i][j] ;
		}
		outfile << endl;
	}
	outfile << endl;
	outfile << endl << "-------------------------------------------------------------------------------" << endl;
	outfile << "Output Grid: Cutted-Edge Image (21x21)" << endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 21; j++) {
			outfile <<right<<setw(9)<< output_grid[i][j];
		}
		outfile << endl;
	}
	outfile << endl << "-------------------------------------------------------------------------------" << endl;
	outfile << "Output (Filtered) Image (" <<imageSize <<"x"<< imageSize <<")"<< endl
		<< "-------------------------------------------------------------------------------" << endl;
	for (i = 0; i < imageSize; i++) {
		for (j = 0; j < imageSize; j++) {
			outfile <<  right << setw(9)<<cutted_image[i][j];
		}
		outfile << endl;
	}
	outfile.close();
	system("pause");
}double total(double mirrored_image[21][21], int i, int j, double kernel[9][9],int filterSize) {
	double total = 0;
	int k,l;
	for (k = 0; k < filterSize; k++) {
		for (l = 0; l < filterSize; l++) {
			total += mirrored_image[i + k][l+j] * kernel[k][l];
		}
	}
	total = total / pow(filterSize,2);
	return total;
}