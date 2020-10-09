#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	//����Ʈ�� 5���� �����͸� ����
	LInsert(&list, 3, 'L');
	LInsert(&list, 4, 'L');
	LInsert(&list, 5, 'L');
	LInsert(&list, 2, 'F');
	LInsert(&list, 1, 'F');

	+
	// ��ü ������ ��� ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2�� ����� ã�Ƽ� ��� ���� ///////
	nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// ��ü ������ ��� ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}