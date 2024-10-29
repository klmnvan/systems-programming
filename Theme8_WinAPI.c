#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <Windows.h>

#define ERROR_OPEN_FILE -3 //

//https://learn.microsoft.com/ru-ru/windows/win32/api/fileapi/nf-fileapi-createfilea

void T9Z1();

void T9Z1()
{
	printf("Введите название файла, в котором находятся корни квадратного уравнения: ");
	char* fileName = malloc(100 * 1);
	gets(fileName, 100);

	HANDLE file = CreateFileA(fileName, (GENERIC_READ | GENERIC_WRITE), 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE fileEnd = CreateFileA("result.txt", (GENERIC_READ | GENERIC_WRITE), 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == NULL) {
		printf("Ошибка при открытии файла");
		WriteFile(file, "Ошибка при открытии файла", 100, NULL, NULL);
		getch();
		exit(ERROR_OPEN_FILE);
	}
	int size = GetFileSize(file, NULL);
	char* buffer = malloc(size + 1);
	ReadFile(file, buffer, size + 1, NULL, NULL);
	buffer[size] = '\0';
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
	char* message = malloc(1000);
	if (file_is_correct) {
		//fscanf(file, "%f %f %f", &a, &b, &c);
		int spaceCount = 0, count = 0;
		char* numberBuf = malloc(0);
		for (int i = 0; i < size + 1 && spaceCount < 4; i++) {
			if (buffer[i] != ' ' && buffer[i] != '\0') {
				realloc(numberBuf, 1 * (count + 1));
				numberBuf[count] = buffer[i];
				count++;
			}
			if (buffer[i] == ' ' || buffer[i] == '\0') {
				if (spaceCount == 0) {
					a = atof(numberBuf);
				}
				if (spaceCount == 1) {
					b = atof(numberBuf);
				}
				if (spaceCount == 2) {
					c = atof(numberBuf);
				}
				count = 0;
				spaceCount++;
				numberBuf = malloc(0);
			}
		}
		if (a == 0.0 && b == 0.0 && c == 0.0) {
			printf("Коэффициенты не должны быть равны 0\n");
			sprintf(message, "Коэффициенты не должны быть равны 0\n");
		}
		else if (a == 0.0) {
			printf("Уравнение не является квадратным, оно линейное\n"); // x = -c/b
			printf("x = %f", (-c / b));
			sprintf(message, "Уравнение имеет бесконечное множество решений\n");
			sprintf(message, "x = %f", (-c / b));
		}
		else if (b == 0.0 && c == 0.0) {
			printf("Уравнение имеет бесконечное множество решений\n");
			sprintf(message, "Уравнение имеет бесконечное множество решений\n");
		}
		else if (a != 0.0 && b != 0.0 && c != 0.0) {
			float D = pow(b, 2) - (4 * a * c);
			if (D > 0) {
				printf("Дискриминант больше 0, корней 2\n");
				float x1 = (-b - sqrt(D)) / 2 * a;
				float x2 = (-b + sqrt(D)) / 2 * a;
				printf("x1 = %f, x2 = %f\n", x1, x2);
				sprintf(message, "Дискриминант больше 0: %f, корней 2\n", D);
				sprintf(message, "x1 = %f, x2 = %f", x1, x2);
			}
			else if (D == 0) {
				printf("Дискриминант равен 0, корень только один\n");
				float x1 = (b + sqrt(D)) / 2 * a;
				printf("x = %f", x1);
				sprintf(message, "Дискриминант равен 0, корень только один\n");
				sprintf(message, "x = %f", x1);
			}
			else {
				sprintf(message, "Дискриминант меньше нуля, я такое не умею решать\n");
			}
		}
		else if (c == 0.0) {
			printf("c не должно быть равен 0\n");
			sprintf(message, "c не должно быть равен 0\n");
		}
		printf("Результаты также записаны в файл result.txt\n");
	}
	else {
		printf("Файл заполнен неверно\n");
		sprintf(message, "Файл заполнен неверно");
	}

	WriteFile(fileEnd, message, strlen(message) + 1, NULL, NULL);
	CloseHandle(fileEnd);
}