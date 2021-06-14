#define _CRT_SECURE_NO_WARNINGS

#include "VectorX.h"
#include <iostream>

int VectorX(int MatrixSize, char filename2[256], char filename3[256]) {
	double Value, min, max;
	int i, j;
	FILE* f2, * f3;
	if ((f2 = fopen(filename2, "rb")) == NULL || (f3 = fopen(filename3, "w+b")) == NULL)
		return -1;
	double* vec = new double[MatrixSize];
	if (vec == NULL)
		return -3;
	fread(&Value, sizeof(Value), 1, f2);
	min = Value;
	max = Value;
	i = 1;
	j = 0;
	bool Enter = false;
	while (fread(&Value, sizeof(Value), 1, f2) > 0) {
		Enter = true;
		i++;
		if (Value < min)
			min = Value;
		if (Value > max)
			max = Value;
		if (MatrixSize == i) {
			i = 1;
			vec[j] = abs(max) - abs(min);
			j++;
			fread(&Value, sizeof(Value), 1, f2);
			min = Value;
			max = Value;
		}
	}
	if (!Enter)
		vec[j] = 0;
	for (i = 0; i < MatrixSize; i++)
		fwrite(&vec[i], sizeof(vec[i]), 1, f3);
	fclose(f2);
	fclose(f3);
	delete[] vec;
	return 0;
}