#pragma once
//������� �� �������� ����������� ������

/*
�������� �������� ������ ��������(� ������� ��������� �������).
������������� �������� ������ �������� �������� ����, ���������� ��� ���������� �����
*/

/*
������� ������������� ��������� �������:
  - �������� ������
  - ������� �������� ������ ������
  - �������� �������� �� ������
  - ������ ���� ��������� �������
*/

/*
� �������� ��������������� ������� �������������� ������ ����� �������,
����� ������������� ��� �������� �������� �����
*/

struct ListItem
{
	int id; //������������ ������?
	struct ListItem* next; //������ �� ��������� ������� ������
}; 
typedef struct ListItem li;

li* createList(int);
void showList(li*);
li* insert(li*, li, int);
li* getItemByInd(li*, int);
li* deleteLIByInd(li*, int);
void freeList(li*);
li* swapItems(li*, int, int);

/// <summary>
/// �������� ��������� ������ �������� �� 10 ��������� � �����
/// </summary>
void T4Z1()
{
	li* list = createList(10);
	showList(list);
}

/// <summary>
/// �������� ������������ ������
/// </summary>
/// <param name="count">���������� ���������</param>
/// <returns>��������� �� ������ ������</returns>
li* createList(int count)
{
	li *start = malloc(sizeof(li));
	start->id = 1;
	start->next = NULL;

	li *p, *n; //��������� �� ���������� � ��������� �������
	p = start;

	//(count - 1) - ������ ��� ������ ������� ��� ������
	for (int i = 0; i < count - 1; i++) {
		n = malloc(sizeof(li)); //�������� ������ ��� ��������� �������
		n->id = p->id + 1;
		p->next = n;
		p = n;
	}
	p->next = NULL;
	return start;
}

/// <summary>
/// ����� ���� ��������� ������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
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
/// ������� ��������� ������ ������, �������� �������� �� ������ � �������� ������.
/// </summary>
void T4Z2()
{
	li* list = createList(10);
	showList(list);
	li item = { 88, NULL };
	printf("������� � ����� �����\n");
	list = insert(list, item, 10); //������� � ����� �����
	showList(list);
	printf("������� � �����\n");
	list = deleteLIByInd(list, 10); //������� � �����
	showList(list);
	li item1 = { 88, NULL };
	printf("������� � ����� ������\n");
	list = insert(list, item1, 0); //������� � ����� ������
	showList(list);
	printf("������� � ������ ������\n");
	list = deleteLIByInd(list, 0); //������� � ������ ������
	showList(list);
	li item2 = { 88, NULL };
	printf("������� �� ������ �����\n");
	list = insert(list, item1, 1); //������� �� ������ �����
	showList(list);
	printf("������� � ������� �����\n");
	list = deleteLIByInd(list, 1); //������� � ������� �����
	showList(list);
	li item3 = { 88, NULL };
	printf("������� � �����\n");
	list = insert(list, item1, 5); //������� � �����
	showList(list);
	printf("������� � ������\n");
	list = deleteLIByInd(list, 5); //������� � ������
	showList(list);
	freeList(list); //�������
}

/// <summary>
/// ������� � ������ ��������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
/// <param name="item">����������� �������</param>
/// <param name="index">������, �� ����� ����� ����� �������� �������</param>
/// <returns>��������� �� ������ ������</returns>
li* insert(li* list, li item, int index) 
{
	li* newItem = malloc(sizeof(li));
	newItem->id = item.id;
	
	//��������� ������, ����� index = 0
	if (index == 0) 
	{
		newItem->next = list;
		list = newItem;
	}
	else
	{
		void* start = list; //���������� ������
		//��������� � ������ �� ������� �� ������ index - 1 (����� � ���� � next ��������� �� ���������� ������ ����� �������)
		list = getItemByInd(list, index - 1);
		void* temp = list->next; //��������� ��������� �� �������, ������� ����� ������ ����� ������������
		list->next = newItem;
		newItem->next = temp;
		list = start;
	}
	return list;
}

/// <summary>
/// �����, ������� ������������ ��������� �� n-�� ������� ������.
/// ��� ���������� ���������� ��������� � ������, ����� ��������� ���������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
/// <param name="index">������ ��������</param>
/// <returns>��������� �� ������ ������</returns>
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
/// �������� �������� �� ����� �� ��� �������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
/// <param name="index">������ ������� ��������</param>
/// <returns>��������� �� ������ ������</returns>
li* deleteLIByInd(li* list, int index) 
{
	li* start = list;
	if (index == 0) 
	{
		start = list->next;
		free(list); //������� ������� � ������ 
	} 
	else
	{
		li* delLI = getItemByInd(list, index); //��������� �������
		li* pDelLI = getItemByInd(list, index - 1); //������� �� ���������
		if (delLI->next != NULL) 
		{
			li* nDelLI = getItemByInd(list, index + 1); //������� ����� ���������
			pDelLI->next = nDelLI;
		}
		else
		{
			pDelLI->next = NULL;
		}
		free(delLI); //���������� ������
	}
	return start;
}

/// <summary>
/// ������� ������ ������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
void freeList(li* list) 
{
	li* n = list; //��������� ��������
	while (n != NULL) //���� ��������� �� ����� NULL
	{
		n = list->next;
		free(list);
		list = n;
	}
}

/// <summary>
/// ������ ���� ��������� �������
/// </summary>
void T4Z3()
{
	li* list = createList(10);
	printf("�������� ���\n");
	showList(list);
	printf("������ ��������� � ��������� 3 � 7\n");
	list = swapItems(list, 7, 3);
	showList(list);
	list = swapItems(list, 7, 3); //������� �������
	printf("������ ��������� � ��������� 0 � 1\n");
	list = swapItems(list, 0, 1);
	showList(list);
	list = swapItems(list, 1, 0);
	printf("������ ��������� � ��������� 0 � 9\n");
	list = swapItems(list, 0, 9);
	showList(list);
	list = swapItems(list, 0, 8);
}

/// <summary>
/// ������ ��������� ������ �� �� ��������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
/// <param name="value1">������ ������� ��������</param>
/// <param name="value2">������ ������� ��������</param>
/// <returns>��������� �� ������ ������</returns>
li* swapItems(li* list, int value1, int value2)
{
	li item1 = *(getItemByInd(list, value1)); //��������� �������� 1 ��������
	li item2 = *(getItemByInd(list, value2)); //��������� �������� 2 ��������
	list = deleteLIByInd(list, value1); 
	list = insert(list, item2, value1);
	list = deleteLIByInd(list, value2);
	list = insert(list, item1, value2);
	return list;
}