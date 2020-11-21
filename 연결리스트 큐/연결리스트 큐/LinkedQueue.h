#pragma once
#pragma once
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _listQueue {
	Node* front;
	Node* rear;
}Queue;

// ť��  �ʱ�ȭ 
void queueInit(Queue* q);

// ������ ������� Ȯ�� 
int isEmpty(Queue* q);

// ť�� ���� ����
void enQueue(Queue* q, Data data);

// ť���� ���� ���� 
Data deQueue(Queue* q);

// ť peek����
Data peek(Queue* q);

// ť ����ϱ�
void printQueue(Queue* q);