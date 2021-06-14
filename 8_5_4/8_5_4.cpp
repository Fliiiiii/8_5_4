#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <math.h>
#include <stdio.h> 
#include "MatrixA.h"
#include "VectorX.h"
#include "FunctionG.h"
#include "VectorX.h"

void info();

int main()
{
	setlocale(LC_ALL, "Russian");
	char filename1[256], filename2[256], filename3[256], filename4[256];
	int ErrorLevel, i;
	info();
	printf("Введите по порядку имена четырёх файлов:\n");
	scanf(" %[^\n]", filename1);
	scanf(" %[^\n]", filename2);
	scanf(" %[^\n]", filename3);
	scanf(" %[^\n]", filename4);
	ErrorLevel = MatrixA(filename1, filename2);
	if (ErrorLevel >= 0)
	{
		int MatrixSize = ErrorLevel;
		ErrorLevel = VectorX(MatrixSize, filename2, filename3);
		if (ErrorLevel >= 0) {
			ErrorLevel = FunctionG(MatrixSize, filename3, filename4);
			if (ErrorLevel >= 0) {
				printf("Функции успешно выполнены! Вывожу результаты\n");
				FILE* f1, * f2, * f3, * f4;
				if ((f2 = fopen(filename2, "rb")) == NULL || (f3 = fopen(filename3, "rb")) == NULL || (f4 = fopen(filename4, "rb")) == NULL) {
					printf("Ошибка при работе с файлами\n");
					system("pause");
					return false;
				}
				printf("Размер матрицы: %iх%i\n", MatrixSize, MatrixSize);
				printf("Элементы квадратной матрицы A = {\n");
				double Value;
				i = 0;
				while (fread(&Value, sizeof(Value), 1, f2) > 0) {
					i++;
					printf("%11.4g   ", Value);
					if (MatrixSize == i) {
						i = 0;
						printf("\n");
					}
				}
				printf("}\n");
				printf("Компоненты вектора X =\n{ ");
				while (fread(&Value, sizeof(Value), 1, f3) > 0)
					printf("%11.4g   ", Value);
				printf(" }\n");
				fread(&Value, sizeof(Value), 1, f4);
				printf("Значение u = G(X) = %11.4g\n", Value);
				system("pause");
				return true;
			}
		}
	}
	if (ErrorLevel == -1)
		printf("Ошибка при работе с файлами\n");
	else if (ErrorLevel == -2)
		printf("Ошибка размера матрицы\n");
	else if (ErrorLevel == -3)
		printf("Ошибка при выделении памяти\n");
	else
		printf("Неизвестная ошибка #%i\n", ErrorLevel);
	system("pause");
	return false;
}

void info() {
	printf("************[ О ПРОГРАММЕ ]***************\n");
	printf("* Информация: Программа строит матрицу A,*\n");
	printf("* получет комп. вектора X, вычисляет u   *\n");
	printf("* Авторы: Шалагин Д.Д., Басорин И.А      *\n");
	printf("* Группа: КЭ-218                         *\n");
	printf("*         Челябинск, ЮУрГУ, 2021         *\n");
	printf("******************************************\n");
}
