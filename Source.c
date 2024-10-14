#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void theme5() {
	int task;
	printf("ТЕМА: Линейные односвязные списки\n");
	printf("Введите номер задания (1): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T5Z1();
		break;
	default:
		printf("Такого задания нет");
		break;
	}
}

void theme4() {
	int task;
	printf("ТЕМА: Линейные односвязные списки\n");
	printf("1. Создание линейного списка структур из 10 элементов и вывод\n");
	printf("2. Вставка элементов внутрь списка, удаление элемента из списка и удаление списка.\n");
	printf("3. Замена двух элементов местами\n");
	printf("Введите номер задания (1-3): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T4Z1();
		break;
	case 2:
		T4Z2();
		break;
	case 3:
		T4Z3();
		break;
	default:
		printf("Такого задания нет");
		break;
	}
}

void theme3() {
	int task;
	printf("ТЕМА: Создание делегатов\n");
	printf("1. Определение указателя на функцию и массива указателей на функцию как новый тип данных + \n   Реализация функции добавления функций в делегат + \n   Реализация функции удаления функций из делегата + \n   Реализация функции запуска всех функций из делегата\n");
	printf("2. Реализация функции по удалению всех повторяющихся функций в делегате (чтобы каждая функция встречалась только один раз)");
	printf("Введите номер задания (1-2): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T3Z1_2_3_4();
		break;
	case 2:
		T3Z5();
		break;
	default:
		printf("Такого задания нет");
		break;
	}
}

void theme2() {
	int task;
	printf("ТЕМА: Указатели\n");
	printf("1. Редактирование и вывод значения целочисленной при обращении к ней из консольного окна.\n");
	printf("2. Динамическое создание и удаление массива из одного миллиона элементов типа int. значения элементов массива должны быть равны значению их индексов.\n");
	printf("3. Функция для вывода на экран консоли массива произвольной длины (сам массив передается в качестве аргумента функции).\n");
	printf("4. Используя указатели, сформировать треугольную матрицу.\n");
	printf("5. Написать программу с использованием указателя на функцию и с использованием указателя на функцию в качестве аргумента.\n");
	printf("Введите номер задания (1-5): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T2Z1();
		break;
	case 2:
		T2Z2();
		break;
	case 3:
		T2Z2();
		break;
	case 4:
		T2Z4();
		break;
	case 5:
		T2Z5();
		break;
	default:
		printf("Такого задания нет");
		break;
	}
}

void theme1() {
	int task;
	printf("ТЕМА: Входной контроль\n");
	printf("1. Квадратное уравнение.\n");
	printf("2. Система двух линейных уравнений.\n");
	printf("3. Перестановки (факториал).\n");
	printf("Введите номер задания (1-3): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T1Z1();
		break;
	case 2:
		T1Z2();
		break;
	case 3:
		T1Z3();
		break;
	default:
		printf("Такого задания нет");
		break;
	}
}

//Стартовая точка в программе
void main(void)
{
	system("chcp 1251>nul");
	srand(clock());
	//theme2();
	int theme;
	printf("Перечень тем:\n");
	printf("1. Входной контроль.\n");
	printf("2. Указатели.\n");
	printf("3. Делегаты.\n");
	printf("4. Линейные односвязные списки.\n");
	printf("5. Заголовочные файлы.\n");
	printf("Введите номер темы (1-*): ");
	scanf("%d", &theme);
	printf("\n");
	switch (theme)
	{
	case 1:
		theme1();
		break;
	case 2:
		theme2();
		break;
	case 3:
		theme3();
		break;
	case 4:
		theme4();
		break;
	case 5:
		theme5();
		break;
	default:
		printf("Такой темы нет");
		break;
	}
}

//Help D: