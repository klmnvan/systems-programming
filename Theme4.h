#pragma once
//������� �� �������� ����������� ������

//�������� �������� ������ ��������(� ������� ��������� �������).
//������������� �������� ������ �������� �������� ����, ���������� ��� ���������� �����

//������� ������������� ��������� �������:
//  --�������� ������
//  --������� �������� ������ ������
//  --�������� �������� �� ������
//  --������ ���� ��������� �������

//� �������� ��������������� ������� �������������� ������ ����� �������, 
//����� ������������� ��� �������� �������� �����

struct ListItem
{
	int id; //������������ ������?
	struct ListItem* next; //������ �� ��������� ������� ������
}; 
typedef struct ListItem li;

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
/// ������� �������� � ������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
void insertValue(li* list, int index, li* newValue)
{
	for (int i = 0; i < index; i++) 
	{
		list = list->next; //������ �������
	}

	li* list2 = list->next; //����� �������
	list->next = newValue;
	newValue->next = list2;
}

/// <summary>
/// �������� ��������� ������ �������� �� 10 ��������� � �����
/// </summary>
void T4Z1() 
{
	li* early = malloc(sizeof(li)); //�������� ������ ������, ������� ��������
	early->id = 0;
	early->next = NULL;

	li* start = early; //��������� ������ ������

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
/// ������� ��������� ������ ������, �������� �������� �� ������ � �������� ������.
/// </summary>
void T4Z2() 
{
	li* early = malloc(sizeof(li)); //�������� ������ ������, ������� ��������
	early->id = 0;
	early->next = NULL;
	li* start = early; //��������� ������ ������

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
/// ������ ��������� �������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
li* swapValues(li* list, int indItem1, int indItem2)
{
	//printf("������: %d", m_size(list));
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
/// ������ ���� ��������� �������
/// </summary>
void T4Z3() 
{
	li* early = malloc(sizeof(li)); //�������� ������ ������, ������� ��������
	early->id = 0;
	early->next = NULL;
	li* start = early; //��������� ������ ������

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
	//��� �� ��������
	/*printf("\n"); 
	start = swapValues(start, 0, 1);
	showList(start);*/
}

