#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

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
	char* string; //������
	struct ListItem* next; //������ �� ��������� ������� ������
};
typedef struct ListItem likr;

likr* createList(int);
void showList(likr*);
likr* insert(likr*, likr, int);
likr* getItemByInd(likr*, int);
likr* deleteLIByInd(likr*, int);
void freeList(likr*);
likr* swapItems(likr*, int, int);
int min(int, int);
int max(int, int);

/// <summary>
/// �������� ��������� ������ �������� �� 10 ��������� � �����
/// </summary>
void T4Z1()
{
	likr* list = createList(10);
	showList(list);
}

/// <summary>
/// �������� ������������ ������
/// </summary>
/// <param name="count">���������� ���������</param>
/// <returns>��������� �� ������ ������</returns>
likr* createList(int count)
{
	likr* start = malloc(sizeof(likr));
	start->id = 1;
	char* startStr = malloc(6);
	strcpy(startStr, "��. 1");
	//startStr = "��. 1";
	start->string = startStr;
	start->next = NULL;

	likr* p, * n; //��������� �� ���������� � ��������� �������
	p = start;

	//(count - 1) - ������ ��� ������ ������� ��� ������
	for (int i = 0; i < count - 1; i++) {
		n = malloc(sizeof(likr)); //�������� ������ ��� ��������� �������
		n->id = p->id + 1;
		char* newStr = malloc(10);
		char valuesStr[100];
		sprintf(valuesStr, "��. %d", i + 2);
		strcpy(newStr, valuesStr);
		n->string = newStr;
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
void showList(likr* list)
{
	while (list != NULL)
	{
		printf("%s ", list->string);
		list = list->next;
	}
	printf("\n");
}

/// <summary>
/// ������� ��������� ������ ������, �������� �������� �� ������ � �������� ������.
/// </summary>
void T4Z2()
{
	likr* list = createList(10);
	showList(list);
	likr item = { 88, "��. �����", NULL};
	printf("������� � ����� �����\n");
	list = insert(list, item, 10); //������� � ����� �����
	showList(list);
	printf("������� � �����\n");
	list = deleteLIByInd(list, 10); //������� � �����
	showList(list);
	likr item1 = { 88, "��. �����", NULL };
	printf("������� � ����� ������\n");
	list = insert(list, item1, 0); //������� � ����� ������
	showList(list);
	printf("������� � ������ ������\n");
	list = deleteLIByInd(list, 0); //������� � ������ ������
	showList(list);
	likr item2 = { 88, "��. �����", NULL };
	printf("������� �� ������ �����\n");
	list = insert(list, item1, 1); //������� �� ������ �����
	showList(list);
	printf("������� � ������� �����\n");
	list = deleteLIByInd(list, 1); //������� � ������� �����
	showList(list);
	likr item3 = { 88, "��. �����", NULL };
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
likr* insert(likr* list, likr item, int index)
{
	likr* newItem = malloc(sizeof(likr));
	newItem->id = item.id;
	newItem->string = item.string;

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
likr* getItemByInd(likr* list, int index)
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
likr* deleteLIByInd(likr* list, int index)
{
	likr* start = list;
	if (index == 0)
	{
		start = list->next;
		free(list); //������� ������� � ������ 
	}
	else
	{
		likr* delLI = getItemByInd(list, index); //��������� �������
		likr* pDelLI = getItemByInd(list, index - 1); //������� �� ���������
		if (delLI->next != NULL)
		{
			likr* nDelLI = getItemByInd(list, index + 1); //������� ����� ���������
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
void freeList(likr* list)
{
	likr* n = list; //��������� ��������
	while (n != NULL) //���� ��������� �� ����� NULL
	{
		n = list->next;
		free(list->string);
		free(list);
		list = n;
	}
}

/// <summary>
/// ������ ���� ��������� �������
/// </summary>
void T4Z3()
{
	likr* list = createList(10);
	printf("�������� ���\n");
	showList(list);
	printf("������ ��������� � ��������� 2 � 6\n");
	list = swapItems(list, 2, 6);
	showList(list);
	list = swapItems(list, 6, 2); //������� �������
	printf("������ ��������� � ��������� 0 � 1\n");
	list = swapItems(list, 0, 1);
	showList(list);
	list = swapItems(list, 1, 0);
	printf("������ ��������� � ��������� 0 � 9\n");
	list = swapItems(list, 0, 9);
	showList(list);
	list = swapItems(list, 0, 9);
	printf("������ ��������� � ��������� 8 � 9\n");
	list = swapItems(list, 8, 9);
	showList(list);
	list = swapItems(list, 8, 9);
}

/// <summary>
/// ������ ��������� ������ �� �� ��������
/// </summary>
/// <param name="list">��������� �� ������ ������</param>
/// <param name="value1">������ ������� ��������</param>
/// <param name="value2">������ ������� ��������</param>
/// <returns>��������� �� ������ ������</returns>
likr* swapItems(likr* list, int value1, int value2)
{
	//������ 3 
	int indItem1 = min(value1, value2); //������� ��� � ���� �������� ��������
	int indItem2 = max(value1, value2);
	likr* item1p; //�������, ������� �� item1
	likr* item1 = getItemByInd(list, indItem1);
	likr* item2 = getItemByInd(list, indItem2);
	likr* item2p = getItemByInd(list, indItem2 - 1); //�������, ������� �� item2
	//��������� ��������, ����� ���� �� ����������� ��������� ��������� �� ������ �����
	if (indItem1 != 0) {
		item1p = getItemByInd(list, indItem1 - 1);
		item1p->next = item2;
	}
	likr* temp = item1->next; //��������� �������� ������� ����� item1 ��������� �� ��������� item1.next
	item1->next = item2->next;
	item2->next = temp;
	//��������� ������, ����� �������� ����� �����
	if (indItem2 - indItem1 != 1) item2p->next = item1;
	else item2->next = item1;

	if (indItem1 == 0) list = item2;

	return list;

	//������ 2, �� �� ��������, ��� ��� ���� ������ ����� � ��������� ������� � ����� ��������, ��� ������ ��������

	/*
	if (value1 != value2)
	{
		int indItem1 = min(value1, value2); //������� ��� � ���� �������� ��������
		int indItem2 = max(value1, value2);
		li* item2 = getItemByInd(list, indItem2);

		for (int i = indItem1; i < indItem2; i++)
		{
			li* fp = malloc(1 * sizeof(li));
			li* f = getItemByInd(list, i); //����� ������� ����� 1
			li* fn = getItemByInd(list, i + 1);
			void* temp = fn->next; //���������, �� ��� ��������� item+1 �������
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
			li* s = getItemByInd(list, i); //����� ������� ����� 1
			li* sn = getItemByInd(list, i + 1);
			void* temp = sn->next; //���������, �� ��� ��������� item+1 �������
			sp->next = sn;
			sn->next = s;
			s->next = temp;
		}
		if (indItem1 == 0) list = item2;

		return list;

	}*/
	//��������� ���������� �� ������ ��������


	//������ 1, �� �� ��������, ��� ��� ��� �������� � �������� ����� ���������, � �� ������

	//li item1 = *(getItemByInd(list, value1)); //��������� �������� 1 ��������
	//li item2 = *(getItemByInd(list, value2)); //��������� �������� 2 ��������
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