/*
by Luis Felipe Alvarez Sanchez A01194173
Aug 13, 2018
11:45 PM
Sudoku
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

//Variables
int matrix[9][9];
int arr[9];
bool isOk = true, isOk2 = true, flag;
int verSum = 0, horSum = 0, sumThree;

//Funcion que checa repetidos en el 3x3
bool checkSudokuSquare(int matrix[9][9]) {
	int i, j, z;
	for (i = 0; i < 9; i++) {
		sumThree = 1;
		for ( j = 0; j < 9; j++) {
			isOk2 = false;
			for (z = 0; z < 9; z++) {
				if (matrix[z / 3 + i / 3 * 3][z % 3 + i % 3 * 3] == sumThree) {
					sumThree++;
					isOk2 = true;
					break;
				}
			}
			if (!isOk2) {
				isOk2 = false;
				return false;
			}
		}
	}
	//return true;
}
//Checks row and column
void checkSudoku(int matrix[9][9]) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			horSum += matrix[i][j];
			verSum += matrix[j][i];
		}
		if (horSum != 45 || verSum != 45) {
			isOk = false;
		}
		horSum = 0;
		verSum = 0;
	}
}
//Fills the matrix function
void fillMatrix(int matrix[9][9]) {
	int value, i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> value;
			matrix[i][j] = value;
		}
	}
}
int main()
{
	fillMatrix(matrix);
	checkSudoku(matrix);

	if(isOk != true || isOk2 != true ){
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
	}
    return 0;
}

