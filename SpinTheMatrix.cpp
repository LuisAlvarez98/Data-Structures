/*
	by Luis Felipe Alvarez Sanchez A01194173
	Aug 8, 2018
	6:25 PM
	SpinTheMatrix Class
*/
#include <iostream>
using namespace std;

int matrix_new[4][4];
int matrix_org[4][4];

//Get move function
int getMove(int n) {
	int move;
	if (n < 0 && n >= -4) {
		if (n % 4 == 0) {
			move = 4;
		}
		else if (n % 3 == 0) {
			move = 1;

		}
		else if (n % 2 == 0) {
			move = 2;
		}
		else {
			move = 3;
		}
	}
	else{
		if (n % 4 == 0) {
			move = 4;
		}
		else if (n % 3 == 0) {
			move = 3;
		}
		else if (n % 2 == 0) {
			move = 2;
		}
		else if (n % 1 == 0) {
			move = 1;
		}
	}
	return move;
}
//Spin the matrix function
void spin(int matrix[4][4],int move) {
	int i, j;
	for (int p = 0; p < move; p++) {
		for (i = 0; i< 4; i++) {
			for (j = 0; j < 4; j++) {
				matrix[j][3 - i] = matrix_org[i][j];
			}
		}
		for (i = 0; i< 4; i++) {
			for (j = 0; j < 4; j++) {
				matrix_org[i][j] = matrix[i][j];
			}
		}
	}
}

//Input matrix function 
void fillMatrix(int matrix[4][4]) {
	int value, i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			cin >> value;
			matrix[i][j] = value;
		}
	}
}
//Show matrix function
void showMatrix(int matrix[4][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (j < 3) {
				cout << matrix[i][j] << " ";
			}else {
				cout << matrix[i][j];
			}
		
		}
		cout << "\n";
	}
}
//Main
int main()
{
	//Ask for n
	int n;
	cin >> n;
	fillMatrix(matrix_org);
	spin(matrix_new,getMove(n));
	showMatrix(matrix_new);

    return 0;
}

