#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define ERROR_OPEN_FILE -3 //

void T8Z1();
void T8Z2();
void T8Z3();

void T8Z1() 
{
	printf("������� �������� �����, � ������� ��������� ����� ����������� ���������: ");
	char* fileName = malloc(100 * 1);
	gets(fileName, 100);
	FILE* file = fopen(fileName, "r");
	FILE* fileEnd = fopen("result.txt", "w");
	if (file == NULL) {
		printf("������ ��� �������� �����");
		fprintf(fileEnd, "������ ��� �������� �����");
		getch();
		exit(ERROR_OPEN_FILE);
	}
	char* buffer = malloc(100 * 1);
	fgets(buffer, 100, file); //��������� ������ �� �����
	//��������� ���� �� ������������
	bool file_is_correct = true;
	int countMinus = 0, countPoint = 0, countSp = 0;
	float a = 0.0, b = 0.0, c = 0.0;
	for (int i = 0; i < strlen(buffer) - 1; i++) {
		if (!((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == '.' || buffer[i] == ' ' || buffer[i] == '-')) {
			file_is_correct = false;
			break;
		}
		if (buffer[i] == '-') {
			if (countMinus == 0) countMinus = 1;
			else
			{
				file_is_correct = false;
				break;
			}
		}
		if (buffer[i] == '.') {
			if (countPoint == 0) countPoint = 1;
			else
			{
				file_is_correct = false;
				break;
			}
		}
		if (buffer[i] == ' ') {
			countMinus = 0;
			countPoint = 0;
			countSp++;
		}
	}
	if (file_is_correct) {
		fclose(file);
		FILE* file = fopen(fileName, "r");
		fscanf(file, "%f %f %f", &a, &b, &c);
		if (a == 0.0 && b == 0.0 && c == 0.0) {
			printf("������������ �� ������ ���� ����� 0\n");
		}
		else if (a == 0.0) {
			printf("��������� �� �������� ����������, ��� ��������\n"); // x = -c/b
			printf("x = %f", (-c / b));
			fprintf(fileEnd, "��������� ����� ����������� ��������� �������\n");
			fprintf(fileEnd, "x = %f", (-c / b));
		}
		else if (b == 0.0 && c == 0.0) {
			printf("��������� ����� ����������� ��������� �������\n");
			fprintf(fileEnd, "��������� ����� ����������� ��������� �������\n");
		}
		else if (a != 0.0 && b != 0.0 && c != 0.0) {
			float D = pow(b, 2) - (4 * a * c);
			if (D > 0) {
				printf("������������ ������ 0, ������ 2\n");
				float x1 = (-b - sqrt(D)) / 2 * a;
				float x2 = (-b + sqrt(D)) / 2 * a;
				printf("x1 = %f, x2 = %f", x1, x2);
				fprintf(fileEnd, "������������ ������ 0: %f, ������ 2\n", D);
				fprintf(fileEnd, "x1 = %f, x2 = %f", x1, x2);
			}
			else if (D == 0) {
				printf("������������ ����� 0, ������ ������ ����\n");
				float x1 = (b + sqrt(D))/2*a;
				printf("x = %f", x1);
				fprintf(fileEnd, "������������ ����� 0, ������ ������ ����\n");
				fprintf(fileEnd, "x = %f", x1);
			}
			else {
				fprintf(fileEnd, "������������ ������ ����, � ����� �� ���� ������\n");
			}
		}
		printf("���������� ����� �������� � ���� result.txt\n");
	}
	else {
		printf("���� �������� �������\n");
		fprintf(fileEnd, "���� �������� �������");
	}
	fclose(fileEnd);
}