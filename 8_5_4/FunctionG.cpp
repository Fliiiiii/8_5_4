#define _CRT_SECURE_NO_WARNINGS
#include "FunctionG.h"
#include <iostream>

int FunctionG(int MatrixSize, char filename3[256], char filename4[256]) {
	double Value, max = -1;
	FILE* f3, * f4;
	if ((f3 = fopen(filename3, "rb")) == NULL || (f4 = fopen(filename4, "w+b")) == NULL)
		return -1;
	while (fread(&Value, sizeof(Value), 1, f3) > 0)
		if (abs(Value) > max)
			max = abs(Value);
	fwrite(&max, sizeof(max), 1, f4);
	fclose(f3);
	fclose(f4);
	return 0;
}