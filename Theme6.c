#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define cvad(A) (A * A)
#define sum(n1, n2) (n1 + n2)

#define AX 1
#define AY 2
#define BX 1
#define BY 2
#define CX 5
#define CY 6

#define AB (sqrt(cvad((AX - BX)) + cvad((AY - BY))))
#define BC (sqrt(cvad((BX - CX)) + cvad((BY - CY))))
#define AC (sqrt(cvad((CX - AX)) + cvad((CY - AY))))

#define K (BY - (AY)) / (BX - (AX))
#define B (AY)-(K)*(AX)

#define P (AB) + (BC) + (AC)
#define p (P)/2
#define S sqrt(p * (p - AB) * (p - BC) * (p - (AC)))

//Задание на директивы препроцессора

//С помощью данного макроса решите задачу на нахождение длины отрезка по координатам двух его точек.
void T6Z2() 
{
	float x1 = 3, x2 = 3, y1 = 6, y2 = 3.2;
	//printf("Введите x1 и y1 через пробел: ");
	//scanf("%d %d", &x1, &y1);
	//printf("Введите x2 и y2 через пробел: ");
	//scanf("%d %d", &x2, &y2);
	float d = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	printf("Расстояние между точками: %f", d);
}

void T6Z3()
{
	//float x1 = 3, x2 = 3, x3 = 5, y1 = 6, y2 = 3, y3 = 2;
	////printf("Введите x1 и y1 через пробел: ");
	////scanf("%d %d", &x1, &y1);
	////printf("Введите x2 и y2 через пробел: ");
	////scanf("%d %d", &x2, &y2);
	//float a = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	//float b = sqrt(cvad((x2 - x3)) + cvad((y2 - y3)));
	//float c = sqrt(cvad((x3 - x1)) + cvad((y3 - y1)));

	//printf("Расстояние между точками: %f %f %f\n", a, b, c);

	//if (a + b > c && a + c > b && b + c > a) 
	//{
	//	float P5 = (a + b + c)/2;
	//	printf("Треугольник существует. Периметр = %f, площадь = %f\n", P5*2, sqrt(P5 * (P5 - a)*(P5 - b)*(P5- c)));
	//	
	//}
	//else printf("Не существует\n");

#if (((AX == BX) && ((AX!=CX) || (BX!=CY))) || !(CY == K * CX + B)) && (!((AX == BX) && (BX == CX) && (CX == AX)) && !((AY == BY) && (BY == CY) && (CY == AY))) || !(CY == K * CX + B)
	printf("Треугольник существует. Периметр = %f, площадь = %f\n", P, S);
#else
	printf("Треугольник построить нельзя");
#endif

}