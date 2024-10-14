#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "CustomHeaders.h"

//Задание на заголовочные файлы


/// <summary>
/// Вызов заголовочных функций
/// </summary>
void T5Z1()
{
	addition(3, 5);
	multiplication(3, 5);
	division(3, 5);
	difference(3, 5);
	char* str1 = malloc(1 * 100);
	char* str2 = malloc(1 * 100);
	printf("Введите строку 1: ");
	scanf("%s", str1);
	printf("Введите строку 2: ");
	scanf("%s", str2);
	printf("Результат объединения строк: %s\n", str_splitter(str1, str2));
	printf("Число %d в строку: %s\n", 5511, number_to_string(5511));
	printf("Строку %s в число: %lf\n", "-55555.3564", string_to_number("-55555.3564"));
}
