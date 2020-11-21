#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// ť��  �ʱ�ȭ 
void queueInit(Queue* q) {
	q->front = NULL;
	q->rear = NULL;
}

// ť�� ������� Ȯ�� 
int isEmpty(Queue* q) {
	if (q->front == NULL)
		return TRUE;
	else
		return FALSE;
}

// ť�� ���� ����
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

// ť���� ���� ���� 
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

// ť��  peek���� (ù��° �ڷḦ �����´�.) 
Data peek(Queue* q) {
	return q->front->data;
}

// ť  ����ϱ�
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