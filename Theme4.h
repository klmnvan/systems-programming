#pragma once
//ЗАДАНИЕ НА ЛИНЕЙНЫЕ ОДНОСВЯЗНЫЕ СПИСКИ

//Создайте линейный список структур(с помощью отдельной функции).
//Определителем элемента списка является числовое поле, содержащее его порядковый номер

//Опишите дополнительно следующие функции:
//  --удаление списка
//  --вставка элемента внутрь списка
//  --удаление элемента из списка
//  --замена двух элементов местами

//В качестве дополнительного задания модифицировать список таким образом, 
//чтобы определителем его элемента являлось слово

struct ListItem
{
	int id; //Определитель списка?
	struct ListItem* next; //Ссылка на следующий элемент списка
}; 
typedef struct ListItem li;

/// <summary>
/// Вывод всех элементов списка
/// </summary>
/// <param name="list">указатель на начало списка</param>
void showList(li* list) 
{
	while (list != NULL) 
	{
		printf("%d ", list->id);
		list = list->next;
	}
	printf("\n");
}

/// <summary>
/// Вставка элемента в список
/// </summary>
/// <param name="list">указатель на начало списка</param>
void insertValue(li* list, int index, li* newValue)
{
	for (int i = 0; i < index; i++) 
	{
		list = list->next; //начало деления
	}

	li* list2 = list->next; //конец деления
	list->next = newValue;
	newValue->next = list2;
}

/// <summary>
/// Создание линейного списка структур из 10 элементов и вывод
/// </summary>
void T4Z1() 
{
	li* early = malloc(sizeof(li)); //Создание начала списка, первого элемента
	early->id = 0;
	early->next = NULL;

	li* start = early; //Запомнили начало списка

	for (int i = 1; i < 10; i++) 
	{
		li* next = malloc(sizeof(li));
		next->next = NULL;
		next->id = i;
		early->next = next;
		early = next;		
	}
	showList(start);
}

/// <summary>
/// Вставка элементов внутрь списка, удаление элемента из списка и удаление списка.
/// </summary>
void T4Z2() 
{
	li* early = malloc(sizeof(li)); //Создание начала списка, первого элемента
	early->id = 0;
	early->next = NULL;
	li* start = early; //Запомнили начало списка

	for (int i = 1; i < 5; i++)
	{
		li* next = malloc(sizeof(li));
		next->next = NULL;
		next->id = i;
		early->next = next;
		early = next;
	}
	showList(start);
	li newItem = { 10, NULL };
	insertValue(start, 2, &newItem);
	showList(start);
}

/// <summary>
/// Замена элементов местами
/// </summary>
/// <param name="list">указатель на начало списка</param>
li* swapValues(li* list, int indItem1, int indItem2)
{
	//printf("Память: %d", m_size(list));
	li* start = list;
	li* item1 = NULL;
	li* beforeItem1 = NULL;
	li* afterItem1 = NULL;
	li* item2 = NULL;
	li* beforeItem2 = NULL;
	li* afterItem2 = NULL;
	int count = 0;
	while(list != NULL)
	{
		if (count == indItem1 - 1) beforeItem1 = list; 
		if (count == indItem1)
		{
			item1 = list;
			if (item1->next != NULL) afterItem1 = item1->next;
		}
		if (count == indItem2 - 1) beforeItem2 = list;
		if (count == indItem2) 
		{
			item2 = list;
			if (item2->next != NULL) afterItem2 = item2->next;
		}
		list = list->next;
		count++;
	}
	li* temp = malloc(sizeof(li));
	if (beforeItem1 != NULL) beforeItem1->next = item2;
	if (afterItem1 != NULL) {
		temp = item2->next;
		item2->next = item1->next;
	}
	else
	{
		item2->next = NULL;
	}
	if (beforeItem2 != NULL) beforeItem2->next = item1;
	if (afterItem2 != NULL) item1->next = temp;
	else
	{
		item1->next = NULL;
	}
	if(beforeItem1 == NULL) start = item2;
	if(beforeItem2 == NULL) start = item1;
	return start;
}

/// <summary>
/// Замена двух элементов местами
/// </summary>
void T4Z3() 
{
	li* early = malloc(sizeof(li)); //Создание начала списка, первого элемента
	early->id = 0;
	early->next = NULL;
	li* start = early; //Запомнили начало списка

	for (int i = 1; i < 10; i++)
	{
		li* next = malloc(sizeof(li));
		next->next = NULL;
		next->id = i;
		early->next = next;
		early = next;
	}
	showList(start);
	printf("\n");
	swapValues(start, 4, 7);
	showList(start);
	printf("\n");
	start = swapValues(start, 0, 9);
	showList(start);
	//Это не работает
	/*printf("\n"); 
	start = swapValues(start, 0, 1);
	showList(start);*/
}

