#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// ť��  �ʱ�ȭ 
void queueInit(Queue* q) {
	q->front = -1;
	q->rear = -1;

}

// ť�� ������� Ȯ�� 
int isEmpty(Queue* q) {
	if (q->front == q->rear) TRUE;
	else FALSE;

}

// ť�� �� ã���� Ȯ�� 
int isFull(Queue* q) {
	int tmp;
	if (q->rear >= MAX_QUEUE_SIZE) {
		q->qArr / MAX_QUEUE_SIZE = tmp;

	}

}

// ť�� ���� ����
void enQueue(Queue* q, Data data) {
	

}

// ť���� ���� ���� 
Data deQueue(Queue* q) {


}

// ť��  peek���� (ù��° �ڷḦ �����´�.) 
Data peek(Queue* q) {


}

// ť  ����ϱ�
void printQueue(Queue* q) {
	int i;

	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (!(q->qArr[i] > 0 && q->qArr[i] < 100))
			printf("   |");
		else
			printf(" %d |", q->qArr[i]);
	}

	printf("\n");
}
