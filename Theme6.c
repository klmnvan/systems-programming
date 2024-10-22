#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

//������� �� ��������� �������������

#define cvad(A) (A * A) //������� �����
#define sum(n1, n2) (n1 + n2) //����� �����

#define AX 1  //x1  0  1  1  1 	0 
#define AY 2  //y1  4  2  2  2 	4 
#define BX 3  //x2  3  4  3  4 	0 
#define BY 4  //y2  0  3  4  3 	4 
#define CX 5  //x3  4  6  5  10	4 
#define CY 6  //y3  5  1  6  1 	5 

#define AB (sqrt(cvad((AX - BX)) + cvad((AY - BY)))) //������� AB (��������� ������ ����� ������� ���������)
#define BC (sqrt(cvad((BX - CX)) + cvad((BY - CY)))) //������� BC (��������� ������ ����� ������� ���������)
#define AC (sqrt(cvad((CX - AX)) + cvad((CY - AY)))) //������� AC (��������� ������ ����� ������� ���������)

#define K (BY - (AY)) / (BX - (AX)) //��� ��� �� ������� ���� �� ����
#define B (AY)-(K)*(AX) //��� ��� �� ������� ���� �� ����

#define P (AB) + (BC) + (AC) //�������� ������������
#define p (P)/2 //������������ ������������
#define S sqrt(p * (p - AB) * (p - BC) * (p - (AC))) //������� ������������ (��������� ������ ����� ������� ���������)

//������� ��������� ���-�� ����������
#define AB_CVAD (cvad((AX - BX)) + cvad((AY - BY))) //������� AB � ��������
#define BC_CVAD (cvad((BX - CX)) + cvad((BY - CY))) //������� BC � ��������
#define AC_CVAD (cvad((CX - AX)) + cvad((CY - AY))) //������� AC � ��������

#define S_BY_COORDINAT ((AX * (BY - CY) + BX * (CY - AY) + CX * (AY - BY)) / 2) //������ �� �����������

//� ������� ������� ������� ������ ������ �� ���������� ����� ������� �� ����������� ���� ��� �����.
void T6Z2() 
{
	float x1 = 3, x2 = 3, y1 = 6, y2 = 3.2;
	//printf("������� x1 � y1 ����� ������: ");
	//scanf("%d %d", &x1, &y1);
	//printf("������� x2 � y2 ����� ������: ");
	//scanf("%d %d", &x2, &y2);
	float d = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	printf("���������� ����� �������: %f", d);
}

void T6Z3()
{
	//float x1 = 3, x2 = 3, x3 = 5, y1 = 6, y2 = 3, y3 = 2;
	////printf("������� x1 � y1 ����� ������: ");
	////scanf("%d %d", &x1, &y1);
	////printf("������� x2 � y2 ����� ������: ");
	////scanf("%d %d", &x2, &y2);
	//float a = sqrt(cvad((x1 - x2)) + cvad((y1 - y2)));
	//float b = sqrt(cvad((x2 - x3)) + cvad((y2 - y3)));
	//float c = sqrt(cvad((x3 - x1)) + cvad((y3 - y1)));

	//printf("���������� ����� �������: %f %f %f\n", a, b, c);

	//if (a + b > c && a + c > b && b + c > a) 
	//{
	//	float P5 = (a + b + c)/2;
	//	printf("����������� ����������. �������� = %f, ������� = %f\n", P5*2, sqrt(P5 * (P5 - a)*(P5 - b)*(P5- c)));
	//	
	//}
	//else printf("�� ����������\n");

#if (S_BY_COORDINAT > 0)
	printf("����������� ����������. �������� = %f, ������� = %f\n", P, S);
#else
	printf("����������� ��������� ������\n");
#endif
	printf("%d", S_BY_COORDINAT);
}