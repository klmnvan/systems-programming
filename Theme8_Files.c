#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define ERROR_OPEN_FILE -3 //

void T8Z1();
void T8Z2();
void T8Z3();

void T8Z1() 
{
	printf("Введите название файла, в котором находятся корни квадратного уравнения: ");
	char* fileName = malloc(100 * 1);
	gets(fileName, 100);
	FILE* file = fopen(fileName, "r");
	FILE* fileEnd = fopen("result.txt", "w");
	if (file == NULL) {
		printf("Ошибка при открытии файла");
		fprintf(fileEnd, "Ошибка при открытии файла");
		getch();
		exit(ERROR_OPEN_FILE);
	}
	char* buffer = malloc(100 * 1);
	fgets(buffer, 100, file); //считываем строку из файла
	//проверить файл на корректность
	bool file_is_correct = true;
	int countMinus = 0, countPoint = 0, countSp = 0;
	float a = 0.0, b = 0.0, c = 0.0;
	for (int i = 0; i < strlen(buffer) - 1; i++) {
		if (!((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '.' || buffer[i] == ' ' || buffer[i] == '-')) {
			file_is_correct = false;
			break;
		}
		if (buffer[i] == '-') {
			if (countMinus == 0) countMinus = 1;
			else
			{
				file_is_correct = false;
				break;
			}
		}
		if (buffer[i] == '.') {
			if (countPoint == 0) countPoint = 1;
			else
			{
				file_is_correct = false;
				break;
			}
		}
		if (buffer[i] == ' ') {
			countMinus = 0;
			countPoint = 0;
			countSp++;
		}
	}
	if (file_is_correct) {
		fclose(file);
		FILE* file = fopen(fileName, "r");
		fscanf(file, "%f %f %f", &a, &b, &c);
		if (a == 0.0 && b == 0.0 && c == 0.0) {
			printf("Коэффициенты не должны быть равны 0\n");
		}
		else if (a == 0.0) {
			printf("Уравнение не является квадратным, оно линейное\n"); // x = -c/b
			printf("x = %f", (-c / b));
			fprintf(fileEnd, "Уравнение имеет бесконечное множество решений\n");
			fprintf(fileEnd, "x = %f", (-c / b));
		}
		else if (b == 0.0 && c == 0.0) {
			printf("Уравнение имеет бесконечное множество решений\n");
			fprintf(fileEnd, "Уравнение имеет бесконечное множество решений\n");
		}
		else if (a != 0.0 && b != 0.0 && c != 0.0) {
			float D = pow(b, 2) - (4 * a * c);
			if (D > 0) {
				printf("Дискриминант больше 0, корней 2\n");
				float x1 = (-b - sqrt(D)) / 2 * a;
				float x2 = (-b + sqrt(D)) / 2 * a;
				printf("x1 = %f, x2 = %f", x1, x2);
				fprintf(fileEnd, "Дискриминант больше 0: %f, корней 2\n", D);
				fprintf(fileEnd, "x1 = %f, x2 = %f", x1, x2);
			}
			else if (D == 0) {
				printf("Дискриминант равен 0, корень только один\n");
				float x1 = (b + sqrt(D))/2*a;
				printf("x = %f", x1);
				fprintf(fileEnd, "Дискриминант равен 0, корень только один\n");
				fprintf(fileEnd, "x = %f", x1);
			}
			else {
				fprintf(fileEnd, "Дискриминант меньше нуля, я такое не умею решать\n");
			}
		}
		printf("Результаты также записаны в файл result.txt\n");
	}
	else {
		printf("Файл заполнен неверно\n");
		fprintf(fileEnd, "Файл заполнен неверно");
	}
	fclose(fileEnd);
}