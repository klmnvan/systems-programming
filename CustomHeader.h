#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void addition(int, int);
void multiplication(int, int);
void division(int, int);
void difference(int, int);
char* str_splitter(char*, char*);
double string_to_number(char*);
char* number_to_string(double, int);

void addition(int a, int b) {
	printf("%d + %d = %d\n", a, b, a + b);
}

void multiplication(int a, int b) {
	printf("%d * %d = %d\n", a, b, a * b);
}

void division(int a, int b) {
	printf("%d / %d = %d\n", a, b, a / b);
}

void difference(int a, int b) {
	printf("%d - %d = %d\n", a, b, a - b);
}

char* str_splitter(char* str1, char* str2)
{
	size_t buffer_size = strlen(str1) + strlen(str2) + 1; //��� ���������� ������� ������
	char* splitstroke = malloc(1 * buffer_size);
	//����� ���
	for (int i = 0; i < strlen(str1); i++) splitstroke[i] = str1[i];
	for (int i = 0, j = strlen(str1); i < strlen(str2); i++, j++) splitstroke[j] = str2[i];
	splitstroke[buffer_size-1] = '\0';
	////� ����� ���
	//splitstroke = strcat(str1, str2);
	return splitstroke;
}

char* number_to_string(double number, int precision)
{
	//���� ����� �������������
	int count = 0;
	char* numberStr = malloc(100);
	if (number < 0) 
	{
		numberStr[count++] = '-';
		number *= -1;
	}
	int integer_multiplier = number; //�������� ����� ����� 
	double fractional_multiplier = number - integer_multiplier; //�������� ������� �����
	//���� ����� ����� 0
	if (integer_multiplier == 0) numberStr[count++] = '0'; 
	else
	{
		//i - ��������� �������
		while (integer_multiplier != 0)
		{
			//54321 % 10 = 1 (� char)
			numberStr[count++] = (integer_multiplier % 10) + '0'; //�������� �����, ������� ������� � ���������� ������� ����� �� 10 � ����������� � char
			integer_multiplier /= 10;
		}
		//������ ����� ����������� ����� �����
		int dop = 0;
		for (int i = 0; i < count / 2; i++) {
			if (numberStr[i] == '-') dop = 1;
			char temp = numberStr[i + dop];
			numberStr[i + dop] = numberStr[count - 1 - i];
			numberStr[count - 1 - i] = temp;
		}
	}
	if (fractional_multiplier != 0.0) 
	{
		numberStr[count++] = '.';
		//k - ���������� ������ ����� �������
		for (int k = 0; k < precision; k++) {
			fractional_multiplier *= 10; //�������� �� 10 ������� �����
			int digit = (int)fractional_multiplier; //�������� �� ������� �����
			numberStr[count++] = digit + '0'; //���������� � � ������
			fractional_multiplier -= digit; //�������� ����� �����, ����� ����� �������� �������
		}
	}

	// ���������� �������� ������� � �����
	numberStr[count] = '\0';

	return numberStr;

	/*
	size_t buffer_size = snprintf(NULL, 0, "%.16g", number) + 1; //��� ���������� ������� ������
	char* newStr = malloc(buffer_size); 
	if (newStr == NULL) { 
		return NULL;
	}
	snprintf(newStr, buffer_size, "%.16g", number); //������� ��� �������������� ����� � ������
	return newStr;
	*/
}

double string_to_number(char* str)
{
	int coefficient = 1; //������������� ��� ���
	int integer_multiplier = 0; //����� �����
	double fractional_multiplier = 0.0; //������� �����

	for (int i = 0; i < strlen(str); i++) 
	{
		if (str[0] == '-') 
		{
			coefficient = -1; //���� ����� � ������, ����������� �� ������ �����
			i++;
		}
		while (isdigit(str[i])) //��������� ����� �����
		{
			integer_multiplier = integer_multiplier * 10 + (str[i] - '0'); 
			i++;
		}
		if (str[i] == '.' || str[i] == ',') //��������� ������� �����
		{
			i++;
			float multiplier = 0.1f; //��������� ������� �����
			while (isdigit(str[i])) {
				fractional_multiplier += (str[i] - '0') * multiplier;
				multiplier *= 0.1f;
				i++;
			}
		}
		break;
	}

	double result = (integer_multiplier + fractional_multiplier) * coefficient;

	return result;

	/*
	size_t buffer_size = strlen(str) + 1; //��� ���������� ������� ������
	char* endptr;
	double result = strtod(str, &endptr);
	return result;
	*/
}
