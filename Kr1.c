//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//#include <math.h>
//#include <string.h>
//#include <locale.h>
//#include <stdbool.h>
//
//struct ListItem
//{
//	int id;
//	struct ListItem* next;
//};
//typedef struct ListItem li;
//
//typedef int (*f)(int);
//
//int* func(f f, int* arr, int* size);
//void z1();
//void z2();
//void z3();
//li* create(int size);
//void show(li* list);
//void deleteList(li* list);
//li* getItemByInd(li* list, int index);
//int getSizeList(li* list);
//li* delBetwKL(li* list, int k, int l);
//
//
//int main()
//{
//	system("chcp 1251>nul");
//	int n;
//	printf("Список заданий.\n");
//	printf("1.\n");
//	printf("2.\n");
//	printf("3.\n");
//	printf("Введите номер задания: ");
//	scanf("%d", &n);
//	switch (n)
//	{
//	case 1:
//		z1();
//		break;
//	case 2:
//		z2();
//		break;
//	case 3:
//		z3();
//		break;
//	default:
//		printf("Такого задания нет");
//		break;
//	}
//}
//
//int f1(int n) { return n + 1; }
//int f2(int n) { return n % 5; }
//
////ПРОВЕРИТЬ ОСТАТОК ОТ ДЕЛЕНИЯ НА 5
//void z1()
//{
//	int size;
//	printf("Введите n: ");
//	scanf("%d", &size);
//	int* arr = malloc(4 * size);
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = (i + 1) * 5;
//	}
//	arr = func(f1, arr, &size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	arr = func(f2, arr, &size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int* func(f f, int* arr, int* size)
//{
//	void* start = arr;
//	for (int i = 0; i < *size; i++)
//	{
//		*arr = f(*arr);
//		arr++;
//	}
//	arr = start;
//	return arr;
//}
//
//void z2()
//{
//	int n;
//	printf("Введите n: ");
//	scanf("%d", &n);
//	int** arr = malloc(sizeof(int*) * n);
//	void* s1 = arr;
//	for (int i = n + 1; i >= 0; i--)
//	{
//		*arr = malloc(4 * i);
//		void* s2 = *arr;
//		for (int j = 0; j < i * 2; j += 2)
//		{
//			**arr = j;
//			printf("%d ", **arr);
//			(*arr)++;
//		}
//		printf("\n");
//		*arr = s2;
//		arr++;
//	}
//	arr = s1;
//	printf("\n");
//}
//
//void z3()
//{
//	int n;
//	printf("Введите количество элементов в списке: ");
//	scanf("%d", &n);
//	li* list = create(n);
//	show(list);
//	list = delBetwKL(list, 2, 4);
//	show(list); //отобразили
//	deleteList(list); //удалили
//	list = create(n); //создали заново
//	show(list); //отобразили
//	list = delBetwKL(list, 0, 2);
//	show(list); //отобразили
//	deleteList(list); //удалили
//	list = create(n); //создали заново
//	show(list); //отобразили
//	list = delBetwKL(list, 0, 1);
//	show(list); //отобразили
//	deleteList(list); //удалили
//	list = create(n); //создали заново
//	show(list); //отобразили
//	list = delBetwKL(list, 4, 6);
//	show(list); //отобразили
//	deleteList(list); //удалили
//	list = create(n); //создали заново
//	show(list); //отобразили
//	list = delBetwKL(list, 0, 6);
//	show(list); //отобразили
//}
//
//li* create(int size)
//{
//	li* start = malloc(sizeof(li));
//	start->id = 1;
//	start->next = NULL;
//
//	li* p, * n; //указатель на предыдущий и следующий элемент
//	p = start;
//
//	//(count - 1) - потому что первый элемент уже создан
//	for (int i = 0; i < size - 1; i++) {
//		n = malloc(sizeof(li)); //выделили память под следующий элемент
//		n->id = p->id + 1;
//		p->next = n;
//		p = n;
//	}
//	p->next = NULL;
//	return start;
//}
//
//void show(li* list)
//{
//	if (list == NULL)
//	{
//		printf("Лист пуст");
//	}
//	while (list != NULL)
//	{
//		printf("%d ", list->id);
//		list = list->next;
//	}
//	printf("\n");
//}
//
//void deleteList(li* list)
//{
//	li* n = list; //следующее значение
//	while (n != NULL) //пока следующий не равен NULL
//	{
//		n = list->next;
//		free(list);
//		list = n;
//	}
//}
//
//li* getItemByInd(li* list, int index)
//{
//	for (int i = 0; i < index; i++)
//	{
//		if (list->next != NULL) list = list->next;
//		else break;
//	}
//	return list;
//}
//
//int getSizeList(li* list)
//{
//	int size = 0;
//	while (list != NULL)
//	{
//		size++;
//		list = list->next;
//	}
//	return size;
//}
//
//li* delBetwKL(li* list, int k, int l)
//{
//	void* start = list;
//	if (k > l)
//	{
//		printf("k должно быть меньше l");
//		return list;
//	}
//	if (k < 0 || l < 0)
//	{
//		printf("индексы не могут быть отрицательными");
//		return list;
//	}
//	li* pf = malloc(sizeof(li));
//	if (k == 0) start = getItemByInd(list, l)->next;
//	else pf = getItemByInd(list, k - 1);
//	li* s = getItemByInd(list, l);
//	for (int i = 1; i <= l - k + 1; i++) //сколько раз надо удалить
//	{
//		//li* fn = getItemByInd(list, k + 1);
//		li* f = getItemByInd(list, k); //удаляемый элемент | 2
//		void* fn = f->next;
//		free(f);
//		if (k != 0) pf->next = fn;
//		else list = fn;
//	}
//	return start;
//}