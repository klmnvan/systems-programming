#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
//������� �� �������� ���������

//1. ���������� ��������� �� ������� � ������ ���������� �� ������� ��� ����� ��� ������
//2. ����������� ������� ���������� ������� � �������
//3. ����������� ������� �������� ������� �� ��������
//4. ����������� ������� ������� ���� ������� �� ��������
//5. ����������� ������� �� �������� ���� ������������� ������� 
//   � ��������(����� ������ ������� ����������� ������ ���� ���)

//������� � ��� ���, ������� ������������ ������ �� ������ � 
//����������� ������� ���������� � ����� ������������� ��������.
//������, ������� ������ ��������� �� �������
//������� - ��� �������, ������� ����� ��������� ������ ������� � ������� (������� ��� �������)

typedef int (*fp_int)(int, int); //��������� �� �������
typedef fp_int* parr; //������ ���������� �� �������? (�������?)

/// <summary>
/// ���������� �������� � ������
/// </summary>
/// <param name="array_delegate"></param>
/// <param name="new_func"></param>
/// <param name="size"></param>
/// <returns></returns>
fp_int add_delegat(parr array_delegate, fp_int new_func, int size) {
	array_delegate = realloc(array_delegate, sizeof(fp_int) * (size + 1));
	array_delegate[size] = new_func;
	return array_delegate;
}

/// <summary>
/// �������� �������� �� �������
/// </summary>
/// <param name="array_delegate"></param>
/// <param name="new_func"></param>
/// <param name="size"></param>
/// <returns></returns>
fp_int delete_delegat(parr array_delegate, fp_int new_func, int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (array_delegate[i] == new_func) {
			//����� i ����-�� �����
			for (size_t j = i + 1; j < size; j++)
			{
				fp_int temp;
				temp = array_delegate[j - 1];
				array_delegate[j - 1] = array_delegate[j];
				array_delegate[j] = temp;
			}
			array_delegate = realloc(array_delegate, sizeof(fp_int) * (size - 1));
			break;
		}
	}
	return array_delegate;
}


/// <summary>
/// ������ ���� �������
/// </summary>
/// <param name="array_delegate"></param>
/// <param name="size"></param>
/// <param name="a"></param>
/// <param name="b"></param>
void start_all_fucntion(parr array_delegate, int size, int a, int b) {
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", (*array_delegate)(a, b));
		array_delegate++;
	}
}

/// <summary>
/// ������� �� ������� ������� ���������
/// </summary>
/// <param name="array_delegate"></param>
/// <param name="size"></param>
/// <returns></returns>
parr get_distinct_parr(parr array_delegate, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (array_delegate[i] == array_delegate[j]) {
				//����� �������� �������������� ��������, ����� �������, ������� ����� �������� ����� � �����
				if (j + 1 != size) {
					for (size_t k = j + 1; k < size; k++)
					{
						fp_int temp;
						temp = array_delegate[k - 1];
						array_delegate[k - 1] = array_delegate[k];
						array_delegate[k] = temp;
					}
				}
				array_delegate = realloc(array_delegate, sizeof(fp_int) * (size - 1));
				size -= 1;
			}
		}
	}
	return array_delegate;
}

int sum(int a, int b) {
	return a + b;
}

int razn(int a, int b) {
	return a - b;
}

int proiz(int a, int b) {
	return a * b;
}

void T3Z5() {
	parr array_delegate = malloc(0 * sizeof(fp_int));
	array_delegate = add_delegat(array_delegate, sum, 0);
	array_delegate = add_delegat(array_delegate, sum, 1);
	array_delegate = add_delegat(array_delegate, razn, 2);
	array_delegate = add_delegat(array_delegate, razn, 3);
	array_delegate = add_delegat(array_delegate, proiz, 4);
	array_delegate = add_delegat(array_delegate, proiz, 5);
	array_delegate = add_delegat(array_delegate, razn, 6);
	array_delegate = add_delegat(array_delegate, proiz, 7);
	printf("�������� 8 ������� � ������������ � ������\n");
	printf("������:\n");
	start_all_fucntion(array_delegate, 8, 10, 5);
	array_delegate = get_distinct_parr(array_delegate, 8);
	printf("������� ���������\n");
	printf("������:\n");
	start_all_fucntion(array_delegate, 3, 10, 5);
}

void T3Z1_2_3_4() {
	parr array_delegate = malloc(0 * sizeof(fp_int));
	array_delegate = add_delegat(array_delegate, sum, 0);
	array_delegate = add_delegat(array_delegate, proiz, 1);
	array_delegate = add_delegat(array_delegate, razn, 2);
	printf("�������� 3 ������� � ������\n");
	printf("������:\n");
	start_all_fucntion(array_delegate, 3, 10, 5);
	array_delegate = delete_delegat(array_delegate, proiz, 3);
	printf("������� �� ������� ������� �� ������\n");
	printf("������:\n");
	start_all_fucntion(array_delegate, 2, 10, 5);
}

