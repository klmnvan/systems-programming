#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

struct ListItemKr
{
	int id;
	struct ListItemKr* next;
};
typedef struct ListItemKr likr;

typedef int (*f)(int);

int* func(f f, int* arr, int* size);
void z1();
void z2();
void z3();
likr* create(int size);
void showkr(likr* list);
void deleteList(likr* list);
likr* getItemByIndkr(likr* list, int index);
int getSizeList(likr* list);
likr* delBetwKL(likr* list, int k, int l);

int f1(int n) { return n + 1; }
int f2(int n) { return n % 5; }

//ПРОВЕРИТЬ ОСТАТОК ОТ ДЕЛЕНИЯ НА 5
void z1()
{
	int size;
	printf("Введите n: ");
	scanf("%d", &size);
	int* arr = malloc(4 * size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = (i + 1) * 5;
	}
	arr = func(f1, arr, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	arr = func(f2, arr, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int* func(f f, int* arr, int* size)
{
	void* start = arr;
	for (int i = 0; i < *size; i++)
	{
		*arr = f(*arr);
		arr++;
	}
	arr = start;
	return arr;
}

void z2()
{
	int n;
	printf("Введите n: ");
	scanf("%d", &n);
	int** arr = malloc(sizeof(int*) * n);
	void* s1 = arr;
	for (int i = n + 1; i >= 0; i--)
	{
		*arr = malloc(4 * i);
		void* s2 = *arr;
		for (int j = 0; j < i * 2; j += 2)
		{
			**arr = j;
			printf("%d ", **arr);
			(*arr)++;
		}
		printf("\n");
		*arr = s2;
		arr++;
	}
	arr = s1;
	printf("\n");
}

void z3()
{
	int n;
	printf("Введите количество элементов в списке: ");
	scanf("%d", &n);
	likr* list = create(n);
	showkr(list);
	list = delBetwKL(list, 2, 4);
	showkr(list); //отобразили
	deleteList(list); //удалили
	list = create(n); //создали заново
	showkr(list); //отобразили
	list = delBetwKL(list, 0, 2);
	showkr(list); //отобразили
	deleteList(list); //удалили
	list = create(n); //создали заново
	showkr(list); //отобразили
	list = delBetwKL(list, 0, 1);
	showkr(list); //отобразили
	deleteList(list); //удалили
	list = create(n); //создали заново
	showkr(list); //отобразили
	list = delBetwKL(list, 4, 6);
	showkr(list); //отобразили
	deleteList(list); //удалили
	list = create(n); //создали заново
	showkr(list); //отобразили
	list = delBetwKL(list, 0, 6);
	showkr(list); //отобразили
}

likr* create(int size)
{
	likr* start = malloc(sizeof(likr));
	start->id = 1;
	start->next = NULL;

	likr* p, * n; //указатель на предыдущий и следующий элемент
	p = start;

	//(count - 1) - потому что первый элемент уже создан
	for (int i = 0; i < size - 1; i++) {
		n = malloc(sizeof(likr)); //выделили память под следующий элемент
		n->id = p->id + 1;
		p->next = n;
		p = n;
	}
	p->next = NULL;
	return start;
}

void showkr(likr* list)
{
	if (list == NULL)
	{
		printf("Лист пуст");
	}
	while (list != NULL)
	{
		printf("%d ", list->id);
		list = list->next;
	}
	printf("\n");
}

void deleteList(likr* list)
{
	likr* n = list; //следующее значение
	while (n != NULL) //пока следующий не равен NULL
	{
		n = list->next;
		free(list);
		list = n;
	}
}

likr* getItemByIndkr(likr* list, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (list->next != NULL) list = list->next;
		else break;
	}
	return list;
}

int getSizeList(likr* list)
{
	int size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return size;
}

likr* delBetwKL(likr* list, int k, int l)
{
	void* start = list;
	if (k > l)
	{
		printf("k должно быть меньше l");
		return list;
	}
	if (k < 0 || l < 0)
	{
		printf("индексы не могут быть отрицательными");
		return list;
	}
	likr* pf = malloc(sizeof(likr));
	if (k == 0) start = getItemByIndkr(list, l)->next;
	else pf = getItemByIndkr(list, k - 1);
	likr* s = getItemByIndkr(list, l);
	for (int i = 1; i <= l - k + 1; i++) //сколько раз надо удалить
	{
		//li* fn = getItemByInd(list, k + 1);
		likr* f = getItemByIndkr(list, k); //удаляемый элемент | 2
		void* fn = f->next;
		free(f);
		if (k != 0) pf->next = fn;
		else list = fn;
	}
	return start;
}