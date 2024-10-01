#pragma once
#define N 100
//������� �� ���������

void T2Z1() {
	int a;
	printf("������� ����� �����: ");
	scanf("%d", &a); 
	printf("\n");
	int* pa = a; //��� ��������� �� ���������� a
	printf("�� ����� %d", pa); //��� �� ���������� � ��������� ���������� a
}

void showArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d\n", *arr);
		*arr++;
	}
	//���������� ����� �� ����, ������ ��� ��� ���������� ������ � ���� ���������
}

void T2Z2() {
	int* arr = malloc(N * 4);
	for (size_t i = 0; i < N; i++) *(arr+i) = i; //���������� � ������ ������� ���������� � ���������� ���������� ���������, �� ������� ����� �������� �������� ���� 
	/*for (size_t i = 0; i < N; i++)
	{
		printf("%d", *(arr + i));
	}*/
	showArray(arr, N);
	free(arr); //�������� 
}


void T2Z4() {
	int n = 100;
	int count = 0;
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
		*(arr + i - 1) = arr2;
	}
}

void show1() {
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", i);
	}
}

void show2() {
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", i * i);
	}
}

void show(void (*f)()) {
	f(5, 5);
}

void T2Z5() {
	void (*f1)() = show1;
	show(f1);
	printf("\n");
	void (*f2)() = show2;
	show(f2);
}
