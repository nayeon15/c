#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// ����߰� flag : 'F'-�տ� �߰�,  'L'-�ڿ� �߰�  
void LInsert(List* plist, Data data, char flag)
{
	// newNode�� ��带 �߰��� �� ��ũ�� ������ �ְ� numOfData ���� 
	Node * newNode = (Node*)malloc(sizeof(Node));



}

int LFirst(List* plist, Data* pdata)
{



	return TRUE;
}

int LNext(List* plist, Data* pdata)
{




	return TRUE;
}

// ��带 �����Ѵ�. (���ϰ����� ������ �����͸� �Ѱ��ش�.) 
Data LRemove(List* plist)
{






	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}