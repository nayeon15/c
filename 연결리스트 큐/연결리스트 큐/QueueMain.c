#include <stdio.h>
#include "LinkedQueue.h"

int main() {
	Queue q;

	// 큐 초기화 
	queueInit(&q);

	enQueue(&q, 1); printQueue(&q);
	enQueue(&q, 2); printQueue(&q);
	enQueue(&q, 3); printQueue(&q);
	enQueue(&q, 4); printQueue(&q);

	deQueue(&q); printQueue(&q);
	deQueue(&q); printQueue(&q);

	enqueue(&q, 5); printqueue(&q);
	enqueue(&q, 6); printqueue(&q);

	system("pause");
	return 0;
}