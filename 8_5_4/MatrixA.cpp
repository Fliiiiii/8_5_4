#define _CRT_SECURE_NO_WARNINGS
#include "MatrixA.h"
#include <iostream>

int MatrixA(char filename1[256], char filename2[256]) {
	int MatrixSize, i, j, k=1;
	double Value;
	FILE* f1, * f2;
	if ((f1 = fopen(filename1, "r")) == NULL || (f2 = fopen(filename2, "w+b")) == NULL)
		return -1;
	fscanf(f1, "%i", &MatrixSize);
	if (MatrixSize <= 1)
		return -2;
	double** arr = new double* [MatrixSize];
	for (i = 0; i < MatrixSize; i++) {
		arr[i] = new double[MatrixSize];
		if (arr[i] == NULL)
			return -3;
	}
	for (i = 1; i <= MatrixSize; i++)
		for (j = 1; j <= MatrixSize; j++)
			arr[i - 1][j - 1] = (abs(j - 3.0) - 1.3) * (6.5 - j) * pow(2.0, j - 1.0) * (2 * abs(3.3 - i) - 1.5);
	for (i = 0; i < MatrixSize; i++)
		for (j = 0; j < MatrixSize; j++) {
			Value = arr[i][j];
			fwrite(&Value, sizeof(Value), 1, f2);
		}
	for (i = 0; i < MatrixSize; i++)
		delete[] arr[i];
	fclose(f1);
	fclose(f2);
	return MatrixSize;
}