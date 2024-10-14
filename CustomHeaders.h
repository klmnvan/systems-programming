#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void addition(int, int);
void multiplication(int, int);
void division(int, int);
void difference(int, int);
char* str_splitter(char*, char*);
double string_to_number(char*);
char* number_to_string(double);

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
	/*for (int i = 0; i < strlen(str1); i++) splitstroke[i] = str1[i];
	for (int i = 0, j = strlen(str1); i < strlen(str2); i++, j++) splitstroke[j] = str2[i];*/

	//� ����� ���
	splitstroke = strcat(str1, str2);
	return splitstroke;
}

char* number_to_string(double number)
{
	size_t buffer_size = snprintf(NULL, 0, "%.16g", number) + 1; //��� ���������� ������� ������
	char* newStr = malloc(buffer_size); 
	if (newStr == NULL) { 
		return NULL;
	}
	snprintf(newStr, buffer_size, "%.16g", number); //������� ��� �������������� ����� � ������
	return newStr;
}

double string_to_number(char* str)
{
	size_t buffer_size = strlen(str) + 1; //��� ���������� ������� ������
	char* endptr;
	double result = strtod(str, &endptr);
	return result;
}
