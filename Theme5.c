#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "CustomHeaders.h"

//������� �� ������������ �����


/// <summary>
/// ����� ������������ �������
/// </summary>
void T5Z1()
{
	addition(3, 5);
	multiplication(3, 5);
	division(3, 5);
	difference(3, 5);
	char* str1 = malloc(1 * 100);
	char* str2 = malloc(1 * 100);
	printf("������� ������ 1: ");
	scanf("%s", str1);
	printf("������� ������ 2: ");
	scanf("%s", str2);
	printf("��������� ����������� �����: %s\n", str_splitter(str1, str2));
	printf("����� %d � ������: %s\n", 5511, number_to_string(5511));
	printf("������ %s � �����: %lf\n", "-55555.3564", string_to_number("-55555.3564"));
}
