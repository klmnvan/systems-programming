#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void theme5() {
	int task;
	printf("����: �������� ����������� ������\n");
	printf("������� ����� ������� (1): ");
	scanf("%d", &task);
	printf("\n");
	switch (task)
	{
	case 1:
		T5Z1();
		break;
	default:
		printf("������ ������� ���");
		break;
	}
}

void theme4() {
	int task;
	printf("����: �������� ����������� ������\n");
	printf("1. �������� ��������� ������ �������� �� 10 ��������� � �����\n");
	printf("2. ������� ��������� ������ ������, �������� �������� �� ������ � �������� ������.\n");
	printf("3. ������ ���� ��������� �������\n");
	printf("������� ����� ������� (1-3): ");
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
		printf("������ ������� ���");
		break;
	}
}

void theme3() {
	int task;
	printf("����: �������� ���������\n");
	printf("1. ����������� ��������� �� ������� � ������� ���������� �� ������� ��� ����� ��� ������ + \n   ���������� ������� ���������� ������� � ������� + \n   ���������� ������� �������� ������� �� �������� + \n   ���������� ������� ������� ���� ������� �� ��������\n");
	printf("2. ���������� ������� �� �������� ���� ������������� ������� � �������� (����� ������ ������� ����������� ������ ���� ���)");
	printf("������� ����� ������� (1-2): ");
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
		printf("������ ������� ���");
		break;
	}
}

void theme2() {
	int task;
	printf("����: ���������\n");
	printf("1. �������������� � ����� �������� ������������� ��� ��������� � ��� �� ����������� ����.\n");
	printf("2. ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int. �������� ��������� ������� ������ ���� ����� �������� �� ��������.\n");
	printf("3. ������� ��� ������ �� ����� ������� ������� ������������ ����� (��� ������ ���������� � �������� ��������� �������).\n");
	printf("4. ��������� ���������, ������������ ����������� �������.\n");
	printf("5. �������� ��������� � �������������� ��������� �� ������� � � �������������� ��������� �� ������� � �������� ���������.\n");
	printf("������� ����� ������� (1-5): ");
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
		printf("������ ������� ���");
		break;
	}
}

void theme1() {
	int task;
	printf("����: ������� ��������\n");
	printf("1. ���������� ���������.\n");
	printf("2. ������� ���� �������� ���������.\n");
	printf("3. ������������ (���������).\n");
	printf("������� ����� ������� (1-3): ");
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
		printf("������ ������� ���");
		break;
	}
}

//��������� ����� � ���������
void main(void)
{
	system("chcp 1251>nul");
	srand(clock());
	//theme2();
	int theme;
	printf("�������� ���:\n");
	printf("1. ������� ��������.\n");
	printf("2. ���������.\n");
	printf("3. ��������.\n");
	printf("4. �������� ����������� ������.\n");
	printf("5. ������������ �����.\n");
	printf("������� ����� ���� (1-*): ");
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
		printf("����� ���� ���");
		break;
	}
}

//Help D: