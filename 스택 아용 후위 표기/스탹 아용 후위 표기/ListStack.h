#define TRUE 1
#define FALSE 0
#define STACK_LEN 100
#define DEBUG

typedef int Data;
typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack {
	Node* top;
} ListStack;

typedef ListStack Stack;

// ���� �ʱ�ȭ 
void stackInit(Stack* pstack);

// ������ ������� Ȯ�� 
int isEmpty(Stack* pstack);

// ������ push ����
void push(Stack* pstack, Data data);

// ������ pop����
Data pop(Stack* pstack);

// ������ peek����
Data peek(Stack* pstack);