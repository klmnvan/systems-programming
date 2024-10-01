#pragma once
#define N 100
//ЗАДАНИЕ НА УКАЗАТЕЛИ

void T2Z1() {
	int a;
	printf("Введите целое число: ");
	scanf("%d", &a); 
	printf("\n");
	int* pa = a; //Это указатель на переменную a
	printf("Вы ввели %d", pa); //Тут мы обращаемся к указателю переменной a
}

void showArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d\n", *arr);
		*arr++;
	}
	//Возвращать бошку не надо, потому что она сдвигалась только в этом контексте
}

void T2Z2() {
	int* arr = malloc(N * 4);
	for (size_t i = 0; i < N; i++) *(arr+i) = i; //Обращаемся к началу массива указателей и прибавляем количество элементов, на которое нужно сдвинуть значение длля 
	/*for (size_t i = 0; i < N; i++)
	{
		printf("%d", *(arr + i));
	}*/
	showArray(arr, N);
	free(arr); //Очистили 
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
