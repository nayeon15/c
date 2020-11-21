#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListStack.h"

Stack stack;
Data exp[100], result[100];

// ��ȣ �˻� 
int isSyntaxError();

// ����ǥ�⸦ ����ǥ������� ��ȯ
void infix_to_postfix();

int main() {

	// stack �ʱ�ȭ 
	stackInit(&stack);

	// ���� �Է¹ޱ�  
	printf("������ �Է����ּ���: ");
	fgets(exp, 100, stdin);
	printf("\n");
	// ��ȣ �˻�
	printf("------ ��ȣ�˻� ---------\n");
	if (isSyntaxError()) {
		printf("��ȣ�� �߸��ƽ��ϴ�.");
		exit(1);
	}

	printf("------- ����ǥ��� ��ȯ  --------\n");
	infix_to_postfix();

	// ����ǥ�������� ���	
	printf("����ǥ���� : %s\n", result);

	return 0;
}

// ��ȣ �˻� --------------------//
int isSyntaxError() {
	int len = strlen(exp) - 1;

	for (int i = 0; i < len; i++) {
		switch (exp[i]) {
		case '(':
			push(&stack, exp[i]);
			break;
		case ')':
			if (isEmpty(&stack)) {
				return TRUE;
			}
			pop(&stack);
		}
	}
	if (isEmpty(&stack))
		return FALSE;
	else
		return TRUE;
}

// ����ǥ�⸦ ����ǥ��� ��ȯ --------------------//
void infix_to_postfix() {
	int idx=0; // result���� ���� ���� �ε��� 
	Data tmp;
	int len = strlen(exp) - 1;

	// �ݺ����� �̿��Ͽ� ����ǥ������� ��ȯ 
	for (int i = 0; i < len;i++) {
		switch (exp[i]) {
		case'(':
			push(&stack, exp[i]);
			break;
		case ')':
			tmp = pop(&stack);
			while (tmp!='(') {
				result[idx++] = tmp;
				tmp = pop(&stack);
			}
		case'+': case '-':
			while (1) {
				tmp = peek(&stack);
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
					result[idx++] = pop(&stack);
				}
				else break;
			}
			push(&stack, exp[i]);
			break;
		case '*': case'/':
			tmp = peek(&stack);
			if (tmp == '*' || tmp == '/') {
				result[idx++] = pop(&stack);
			}
			push(&stack, exp[i]);
			break;
		default:
			result[idx++] = exp[i];
			break;
		}
	}

	// ���ÿ� �����ڰ� ���� ������
	while (!isEmpty(&stack)) {
		result[idx++] = pop(&stack);
	}

	// ���� �迭 �������� �� �� ����
	result[idx] = '\0';
}