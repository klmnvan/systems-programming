#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "CustomHeader.h"
#define N1 3
#define N2 5
#define BUFFER 100

//Задание на заголовочные файлы

/// <summary>
/// Вызов заголовочных функций
/// </summary>
void T5Z1()
{
	addition(N1, N2);
	multiplication(N1, N2);
	division(N1, N2);
	difference(N1, N2);
	char* str1 = malloc(BUFFER);
	char* str2 = malloc(BUFFER);
	printf("Число %lf в строку: %s\n", -5417.9876, number_to_string(-5417.9876, 4));
	printf("Число %lf в строку: %s\n", -0.9876, number_to_string(-0.9876, 4));
	printf("Число %lf в строку: %s\n", 5500.9876, number_to_string(5500.9876, 4));
	printf("Число %lf в строку: %s\n", 005500.9876, number_to_string(005500.9876, 4));
	printf("Число %lf в строку: %s\n", 0, number_to_string(0, 4));
	printf("Число %lf в строку: %s\n", 0.0, number_to_string(0.0, 4));
	printf("Строку %s в число: %lf\n", "-55555.3564", string_to_number("-55555.3564"));
	printf("Строку %s в число: %lf\n", "-0111001.00001", string_to_number("-0111001.00001"));
	printf("Строку %s в число: %.lf\n", "15345345", string_to_number("15345345"));
	printf("Введите строку 1: ");
	scanf("%s", str1);
	printf("Введите строку 2: ");
	scanf("%s", str2);
	printf("Результат объединения строк: %s\n", str_splitter(str1, str2));
}


