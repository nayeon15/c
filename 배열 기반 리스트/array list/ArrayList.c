#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist) {
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData pdata) {
	if (plist->numOfData >= LIST_LEN) {
		return;
	}
	for (int i = plist->numOfData-1; i > plist->curPosition; i--) {
		plist->arr[i] = plist->arr[i-1];
	}
	plist->arr[++plist->curPosition] = pdata;
	plist->numOfData++;
}
int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData <= 0)return 0;
	plist->curPosition = 0;
	*pdata = plist->arr[0];
	return 1;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition>=(plist->numOfData)-1)
		return 0;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return 1;
}

LData LRemove(List* plist) {
	int data = plist->arr[plist->curPosition];
	if (plist->numOfData <= 0 || plist->curPosition <= 0)
		return 0;

	for (int i = plist->curPosition; i < (plist->numOfData) - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->numOfData)--;
	(plist->curPosition)--;
	return data;
}

int LCount(List* plist) {
	return plist->numOfData;
}



