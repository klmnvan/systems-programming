#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include "CustomHeader.h"

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
	printf("����� %lf � ������: %s\n", -5417.9876, number_to_string(-5417.9876, 4));
	printf("����� %lf � ������: %s\n", -0.9876, number_to_string(-0.9876, 4));
	printf("����� %lf � ������: %s\n", 5500.9876, number_to_string(5500.9876, 4));
	printf("����� %lf � ������: %s\n", 005500.9876, number_to_string(005500.9876, 4));
	printf("����� %lf � ������: %s\n", 0, number_to_string(0, 4));
	printf("����� %lf � ������: %s\n", 0.0, number_to_string(0.0, 4));
	printf("������ %s � �����: %lf\n", "-55555.3564", string_to_number("-55555.3564"));
	printf("������ %s � �����: %lf\n", "-0111001.00001", string_to_number("-0111001.00001"));
	printf("������ %s � �����: %lf\n", "15345345", string_to_number("15345345"));
	printf("������� ������ 1: ");
	scanf("%s", str1);
	printf("������� ������ 2: ");
	scanf("%s", str2);
	printf("��������� ����������� �����: %s\n", str_splitter(str1, str2));
}
