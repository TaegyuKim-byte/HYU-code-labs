#include <iostream>
#include "magic_square.h"

void magic_square(int n, int **matrix) {

	int row=0, col=(n-1)/2;

	for (int num = 1; num <= n * n; num++) {
		matrix[row][col] = num;
		
		int newRow = (row - 1 + n) % n;
		int newCol = (col + 1) % n;

		if (matrix[newRow][newCol] != 0) {
			row = row + 1;
		} else {
			row = newRow;
			col = newCol;
		}

	}	
};
