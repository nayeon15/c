#pragma once
#define TRUE 1
#define FALSE 0 
#define LIST_LEN 100
typedef int LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
}List;

void ListInit(List* plist);

void LInsert(List* plist, LData pdata);

int LFirst(List* plist, LData* pdata);

int LNext(List* plst, LData* pdata);

LData LRemove(List* plist);

int LCount(List* plist);