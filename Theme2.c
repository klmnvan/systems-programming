#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define N 100000
//������� �� ���������

/// <summary>
/// �������������� � ����� �������� ������������� ��� ��������� � ��� �� ����������� ����
/// </summary>
void T2Z1() {
	int a;
	int* pa = &a; //��� �� ����� ��������� ���� � ����������
	printf("������� ����� �����: ");
	scanf("%d", &a);//��� �� ������� ����� �������� ���������� a, ���� � ������� ��������� ���������
	printf("\n");
	printf("�� ����� %d, %d", *pa, a); //��� �� ���������� � ��������� ���������� a, � � ����� ���������� ����� ��������� � �������, ��� ��� �������� �����
	printf("\n");
	printf("������� ����� ����� ��� ���: ");
	scanf("%d", &a);//��� �� ������ ������ ���������� a, ���� � ������� ��������� ���������
	printf("\n");
	printf("�� ����� %d, %d", *pa, a); //��� �� ���������� � ��������� ���������� a, � � ����� ���������� ����� ��������� � �������, ��� ��� �������� �����
}

/// <summary>
/// ����� �������, ��������� ���������
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void showArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d\n", *arr);
		*arr++;
	}
	//���������� ����� �� ����, ������ ��� ��� ���������� ������ � ��������� ���� �������
}

/// <summary>
/// ������������ �������� � �������� ������� �� ������ �������� ��������� ���� int. 
/// �������� ��������� ������� ������ ���� ����� �������� �� ��������.
/// +
/// ������� ��� ������ �� ����� ������� ������� ������������ ����� (��� ������ ���������� � �������� ��������� �������)
/// </summary>
void T2Z2() {
	int* arr = malloc(N * 4);
	for (size_t i = 0; i < N; i++) *(arr + i) = i; //���������� � ������ ������� ���������� � ���������� ���������� ���������, �� ������� ����� �������� �������� ���� 
	/*for (size_t i = 0; i < N; i++)
	{
		printf("%d", *(arr + i));
	}*/
	showArray(arr, N);
	free(arr); //��������
}

/// <summary>
/// ��������� ���������, ������������ ����������� ������� ���������� ����:
/// 0
/// 1 2
/// 3 4 5
/// 6 7 8 9
/// � ��.
/// </summary>
void T2Z4() {
	int n = 10;
	int count = 0;
	/*
	//������ ������ ������, ���������
	int** arr = malloc(n * sizeof(int*));
	for (size_t i = 1; i <= n; i++)
	{
		int* arr2 = malloc(i * 4);
		for (size_t j = 0; j < i; j++) {
			*(arr2 + j) = count;
			printf("%d ", *(arr2 + j));
			count++;
		}
		printf("\n");
		*(arr + (i - 1)) = arr2;
	}
	*/

	//������ ������ � ��������� ������
	int** arr = malloc(n * sizeof(int*));
	int** golova1 = arr; //��������� ������
	for (size_t i = 1; i <= n; i++)
	{
		*arr = malloc(i * 4);
		int* golova2 = *arr;
		for (size_t j = 0; j < i; j++)
		{
			*(*arr)++ = count++; //������� ������������, ����� ++
			//(*arr)++; //��������� � ��������� �� ������ � ������ ������ ������ � ��������� ������� � ����� ��� �� sizeof(int)
		}
		*arr++ = golova2; //������� ������������, ����� ++ (������ �� * �����)
	}

	//��������� � ������������� ����������
	/*for (int i = 0; i < n; i++) {
		*arr = (int*)malloc((i + 1) * sizeof(int));
		int* golova2 = *arr;
		for (int j = 0; j <= i; j++) {
			*golova2 = count++;
			golova2++;
		}
		*arr++;
	}*/

	arr = golova1;
	for (size_t i = 1; i <= n; i++)
	{
		int* golova2 = *arr;
		for (size_t j = 0; j < i; j++)
		{
			printf("%d\t", **arr);
			(*arr)++; //
		}
		printf("\n");
		*arr++ = golova2;
	}
	arr = golova1;
	int b = 5;
	//�������
	for (size_t i = 0; i < n; i++)
	{
		free(*arr++);
	}
	arr = golova1;
	free(arr);
}

/// <summary>
/// �������, ������� ������� ��� ����� �� 0 �� 4
/// </summary>
void show1() {
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", i);
	}
}

/// <summary>
/// �������, ������� ������� ������� ����� �� 0 �� 4
/// </summary>
void show2() {
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", i * i);
	}
}

/// <summary>
/// �������, ������� �������� ���������� � �� ������� ���� void ��� ����������
/// </summary>
/// <param name="f"></param>
void show(void (*f)()) {
	f();
}

/// <summary>
/// �������� ��������� � �������������� ��������� �� ������� � 
/// � �������������� ��������� �� ������� � �������� ��������� (����� ����� ������ �� �����)
/// </summary>
void T2Z5() {
	void (*f1)() = show1;
	show(f1);
	printf("\n");
	void (*f2)() = show2;
	show(f2);
}
