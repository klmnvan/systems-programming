#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

//ЗАДАНИЕ НА ЛИНЕЙНЫЕ ОДНОСВЯЗНЫЕ СПИСКИ

/*
Создайте линейный список структур(с помощью отдельной функции).
Определителем элемента списка является числовое поле, содержащее его порядковый номер
*/

/*
Опишите дополнительно следующие функции:
  - удаление списка
  - вставка элемента внутрь списка
  - удаление элемента из списка
  - замена двух элементов местами
*/

/*
В качестве дополнительного задания модифицировать список таким образом,
чтобы определителем его элемента являлось слово
*/

struct ListItem
{
	int id; //Определитель списка?
	char* string; //Строка
	struct ListItem* next; //Ссылка на следующий элемент списка
};
typedef struct ListItem li;

li* createList(int);
void showList(li*);
li* insert(li*, li, int);
li* getItemByInd(li*, int);
li* deleteLIByInd(li*, int);
void freeList(li*);
li* swapItems(li*, int, int);
int min(int, int);
int max(int, int);

/// <summary>
/// Создание линейного списка структур из 10 элементов и вывод
/// </summary>
void T4Z1()
{
	li* list = createList(10);
	showList(list);
}

/// <summary>
/// Создание односвязного списка
/// </summary>
/// <param name="count">количество элементов</param>
/// <returns>указатель на начало списка</returns>
li* createList(int count)
{
	li* start = malloc(sizeof(li));
	start->id = 1;
	char* startStr = malloc(6);
	strcpy(startStr, "Эл. 1");
	//startStr = "Эл. 1";
	start->string = startStr;
	start->next = NULL;

	li* p, * n; //указатель на предыдущий и следующий элемент
	p = start;

	//(count - 1) - потому что первый элемент уже создан
	for (int i = 0; i < count - 1; i++) {
		n = malloc(sizeof(li)); //выделили память под следующий элемент
		n->id = p->id + 1;
		char* newStr = malloc(10);
		char valuesStr[100];
		sprintf(valuesStr, "Эл. %d", i + 2);
		strcpy(newStr, valuesStr);
		n->string = newStr;
		p->next = n;
		p = n;
	}
	p->next = NULL;
	return start;
}

/// <summary>
/// Вывод всех элементов списка
/// </summary>
/// <param name="list">указатель на начало списка</param>
void showList(li* list)
{
	while (list != NULL)
	{
		printf("%s ", list->string);
		list = list->next;
	}
	printf("\n");
}

/// <summary>
/// Вставка элементов внутрь списка, удаление элемента из списка и удаление списка.
/// </summary>
void T4Z2()
{
	li* list = createList(10);
	showList(list);
	li item = { 88, "Эл. НОВЫЙ", NULL};
	printf("вставка в самый конец\n");
	list = insert(list, item, 10); //вставка в самый конец
	showList(list);
	printf("удалили с конца\n");
	list = deleteLIByInd(list, 10); //удалили с конца
	showList(list);
	li item1 = { 88, "Эл. НОВЫЙ", NULL };
	printf("вставка в самое начало\n");
	list = insert(list, item1, 0); //вставка в самое начало
	showList(list);
	printf("удалили с самого начала\n");
	list = deleteLIByInd(list, 0); //удалили с самого начала
	showList(list);
	li item2 = { 88, "Эл. НОВЫЙ", NULL };
	printf("вставка на второе место\n");
	list = insert(list, item1, 1); //вставка на второе место
	showList(list);
	printf("удалили с второго места\n");
	list = deleteLIByInd(list, 1); //удалили с второго места
	showList(list);
	li item3 = { 88, "Эл. НОВЫЙ", NULL };
	printf("вставка в центр\n");
	list = insert(list, item1, 5); //вставка в центр
	showList(list);
	printf("удалили с центра\n");
	list = deleteLIByInd(list, 5); //удалили с центра
	showList(list);
	freeList(list); //удалили
}

/// <summary>
/// Вставка в список элемента
/// </summary>
/// <param name="list">указатель на начало списка</param>
/// <param name="item">вставляемый элемент</param>
/// <param name="index">индекс, на какое место нужно вставить элемент</param>
/// <returns>указатель на начало списка</returns>
li* insert(li* list, li item, int index)
{
	li* newItem = malloc(sizeof(li));
	newItem->id = item.id;
	newItem->string = item.string;

	//обработка случая, когда index = 0
	if (index == 0)
	{
		newItem->next = list;
		list = newItem;
	}
	else
	{
		void* start = list; //сохранение головы
		//переходим в списке на элемент по индксу index - 1 (чтобы у него в next поставить на правильный индекс новый элемент)
		list = getItemByInd(list, index - 1);
		void* temp = list->next; //сохранили указатель на элемент, который будет стоять после вставленного
		list->next = newItem;
		newItem->next = temp;
		list = start;
	}
	return list;
}

/// <summary>
/// Метод, который возвращается указатель на n-ый элемент списка.
/// При превышении количества элементов в списке, будет возвращён последний
/// </summary>
/// <param name="list">указатель на начало списка</param>
/// <param name="index">индекс элемента</param>
/// <returns>указатель на начало списка</returns>
li* getItemByInd(li* list, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (list->next != NULL) list = list->next;
		else break;
	}
	return list;
}

/// <summary>
/// Удаление элемента из листа по его индексу
/// </summary>
/// <param name="list">указатель на начало списка</param>
/// <param name="index">индекс нужного элемента</param>
/// <returns>указатель на начало списка</returns>
li* deleteLIByInd(li* list, int index)
{
	li* start = list;
	if (index == 0)
	{
		start = list->next;
		free(list); //удалили элемент с начала 
	}
	else
	{
		li* delLI = getItemByInd(list, index); //удаляемый элемент
		li* pDelLI = getItemByInd(list, index - 1); //элемент до удалённого
		if (delLI->next != NULL)
		{
			li* nDelLI = getItemByInd(list, index + 1); //элемент после удалённого
			pDelLI->next = nDelLI;
		}
		else
		{
			pDelLI->next = NULL;
		}
		free(delLI); //освободили память
	}
	return start;
}

/// <summary>
/// Очищает память списка
/// </summary>
/// <param name="list">указатель на начало списка</param>
void freeList(li* list)
{
	li* n = list; //следующее значение
	while (n != NULL) //пока следующий не равен NULL
	{
		n = list->next;
		free(list->string);
		free(list);
		list = n;
	}
}

/// <summary>
/// Замена двух элементов местами
/// </summary>
void T4Z3()
{
	li* list = createList(10);
	printf("исходный вид\n");
	showList(list);
	printf("замена элементов с индексами 2 и 6\n");
	list = swapItems(list, 2, 6);
	showList(list);
	list = swapItems(list, 6, 2); //возврат обратно
	printf("замена элементов с индексами 0 и 1\n");
	list = swapItems(list, 0, 1);
	showList(list);
	list = swapItems(list, 1, 0);
	printf("замена элементов с индексами 0 и 9\n");
	list = swapItems(list, 0, 9);
	showList(list);
	list = swapItems(list, 0, 9);
	printf("замена элементов с индексами 8 и 9\n");
	list = swapItems(list, 8, 9);
	showList(list);
	list = swapItems(list, 8, 9);
}

/// <summary>
/// Замена элементов списка по их индексам
/// </summary>
/// <param name="list">указатель на начало списка</param>
/// <param name="value1">индекс первого элемента</param>
/// <param name="value2">индекс второго элемента</param>
/// <returns>указатель на начало списка</returns>
li* swapItems(li* list, int value1, int value2)
{
	//Способ 3 
	int indItem1 = min(value1, value2); //находим мин и макс значения индексов
	int indItem2 = max(value1, value2);
	li* item1p; //элемент, стоящий до item1
	li* item1 = getItemByInd(list, indItem1);
	li* item2 = getItemByInd(list, indItem2);
	li* item2p = getItemByInd(list, indItem2 - 1); //элемент, стоящий до item2
	//обработка ситуации, когда один из меняющийхся элементов находится на первом месте
	if (indItem1 != 0) {
		item1p = getItemByInd(list, indItem1 - 1);
		item1p->next = item2;
	}
	li* temp = item1->next; //запомнили значение идущего после item1 указателя до изменения item1.next
	item1->next = item2->next;
	item2->next = temp;
	//Обработка случая, когда элементы стоят рядом
	if (indItem2 - indItem1 != 1) item2p->next = item1;
	else item2->next = item1;

	if (indItem1 == 0) list = item2;

	return list;

	//Способ 2, но он неверный, так как есть способ проще и программе тяжелее в цикле работать, чем просто поменять

	/*
	if (value1 != value2)
	{
		int indItem1 = min(value1, value2); //находим мин и макс значения индексов
		int indItem2 = max(value1, value2);
		li* item2 = getItemByInd(list, indItem2);

		for (int i = indItem1; i < indItem2; i++)
		{
			li* fp = malloc(1 * sizeof(li));
			li* f = getItemByInd(list, i); //Нашли элемент после 1
			li* fn = getItemByInd(list, i + 1);
			void* temp = fn->next; //сохранили, на что указывает item+1 элемент
			if (i != 0)
			{
				fp = getItemByInd(list, i - 1);
				fp->next = fn;
			}
			else list = fn;
			fn->next = f;
			f->next = temp;
		}

		for (int i = indItem2-2; i > indItem1-1; i--)
		{
			li* sp = getItemByInd(list, i - 1);
			li* s = getItemByInd(list, i); //Нашли элемент после 1
			li* sn = getItemByInd(list, i + 1);
			void* temp = sn->next; //сохранили, на что указывает item+1 элемент
			sp->next = sn;
			sn->next = s;
			s->next = temp;
		}
		if (indItem1 == 0) list = item2;

		return list;

	}*/
	//обработка исключения на равные значения


	//Способ 1, но он неверный, так как это удаление и создание новых элементов, а не замена

	//li item1 = *(getItemByInd(list, value1)); //сохранили значение 1 элемента
	//li item2 = *(getItemByInd(list, value2)); //сохранили значение 2 элемента
	//list = deleteLIByInd(list, value1); 
	//list = insert(list, item2, value1);
	//list = deleteLIByInd(list, value2);
	//list = insert(list, item1, value2);
	//return list;
}


int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}