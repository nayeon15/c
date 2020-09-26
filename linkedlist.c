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

// 노드추가 flag : 'F'-앞에 추가,  'L'-뒤에 추가  
void LInsert(List* plist, Data data, char flag)
{
	// newNode로 노드를 추가한 후 링크를 연결해 주고 numOfData 증가 
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

// 노드를 삭제한다. (리턴값으로 삭제된 데이터를 넘겨준다.) 
Data LRemove(List* plist)
{






	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}