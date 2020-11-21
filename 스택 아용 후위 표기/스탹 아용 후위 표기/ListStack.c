#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

// ���� �ʱ�ȭ 
void stackInit(Stack* pstack) {
	pstack->top = NULL;
}

// ������ ������� Ȯ�� 
int isEmpty(Stack* pstack) {
	if (pstack->top == NULL)
		return TRUE;
	else
		return FALSE;
}

// ������ push ����
void push(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->top;
	pstack->top = newNode;
#ifdef DEBUG
	printf("push : %d\n", data);
#endif
}

// ������ pop����
Data pop(Stack* pstack) {
	Data rdata;
	Node* rnode;

	if (isEmpty(pstack)) {
		printf("stack�� ��� �ֽ��ϴ�.");
		exit(1);
	}

	rdata = pstack->top->data;
	rnode = pstack->top;
	pstack->top = pstack->top->next;
	free(rnode);

#ifdef DEBUG
	printf("pop : %d\n", rdata);
#endif
	return rdata;
}

// ������ peek����
Data peek(Stack* pstack) {
	if (isEmpty(pstack)) {
		return NULL;
	}
	return pstack->top->data;
}