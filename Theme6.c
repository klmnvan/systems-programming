#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define cvad(A) (A * A)

//Задание на директивы препроцессора

//С помощью данного макроса решите задачу на нахождение длины отрезка по координатам двух его точек.
void T6Z2() 
{
	int x1 = 3, x2 = 3, y1 = 6, y2 = 3;
	//printf("Введите x1 и y1 через пробел: ");
	//scanf("%d %d", &x1, &y1);
	//printf("Введите x2 и y2 через пробел: ");
	//scanf("%d %d", &x2, &y2);
	int d = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	printf("Расстояние между точками: %d", d);
}

void T6Z3()
{
	float x1 = 3, x2 = 3, x3 = 5, y1 = 6, y2 = 3, y3 = 2;
	//printf("Введите x1 и y1 через пробел: ");
	//scanf("%d %d", &x1, &y1);
	//printf("Введите x2 и y2 через пробел: ");
	//scanf("%d %d", &x2, &y2);
	float a = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	float b = sqrt(cvad((x2 - x3)) + cvad((y2 - y3)));
	float c = sqrt(cvad((x3 - x1)) + cvad((y3 - y1)));

	printf("Расстояние между точками: %f %f %f\n", a, b, c);

	if (a + b > c && a + c > b && b + c > a) 
	{
		float P = (a + b + c)/2;
		printf("Треугольник существует. Периметр = %f, площадь = %f\n", P*2, sqrt(P * (P - a)*(P - b)*(P - c)));
		
	}
	else printf("Не существует\n");


}