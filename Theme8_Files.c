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

	FILE* file = fopen("zad1.txt", "r");
	if (file == NULL) 
	{
		printf("Ошибка при открытии файла");
		getch();
		exit(ERROR_OPEN_FILE);
	}
	char* buffer = malloc(100, 1);
	fgets(buffer, 100, file); //считываем строку из файла
	//проверить файл на корректность
	bool file_is_correct = true;
	for (int i = 0; i < strlen(buffer) - 1; i++)
	{
		if (!((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '.' || buffer[i] == ' ')) {
			file_is_correct = false;
			break;
		}
	}
	if (file_is_correct) 
	{
		int probels = 0;
		for (int i = 0; i < strlen(buffer) - 1; i++) {
			if (buffer[i] == ' ') {
				probels++;
			}
		}
		switch (probels)
		{
		case 0:
			fscanf(file, "%f", );
			break;
		default:
			break;
		}
	}
	else
	{
		printf("Данные файла заполнены неверно\n");
	}
}