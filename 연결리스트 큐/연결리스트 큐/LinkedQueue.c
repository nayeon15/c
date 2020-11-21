#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// 큐의  초기화 
void queueInit(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

// 큐가 비었는지 확인 
int isEmpty(Queue* q) {
	if (q->front == NULL)
		return TRUE;
	else
		return FALSE;
}

// 큐에 삽입 연산
void enQueue(Queue* q, Data data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->data = data;

	if (isEmpty(q)) {
		q->front = newnode;
		q->rear = newnode;
	}
	else {
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

// 큐에서 삭제 연산 
Data deQueue(Queue* q) {
	Node* delNode;
	int rdata;

	if (isEmpty(q)) {
		printf("memory if full");
		exit(-1);
	}

	delNode = q->front;
	rdata = delNode->data;
	q->front = q->front->next;

	free(delNode);
	return rdata;
}

// 큐의  peek연산 (첫번째 자료를 가져온다.) 
Data peek(Queue* q) {
	return q->front->data;
}

// 큐  출력하기
void printQueue(Queue* q) {
	int i;
	Node* pNode;

	printf(" |");
	pNode = q->front;
	while (pNode != NULL) {
		printf(" %d |", pNode->data);
		pNode = pNode->next;
	}

	printf("\n");
}