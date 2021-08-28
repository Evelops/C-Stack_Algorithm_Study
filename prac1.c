#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
// ��ũ ����Ʈ�� ����Ͽ� ���� ���� ����� ������ �⺻ ����� push,pop,peek,display 
struct stack { //����ü�� ����Ͽ� stack ����
	int data;
	struct stack* next;
};
struct stack* top = NULL; // top�� ����ִٰ� ����  ó���� ������ ����ִ� �����ΰ���
struct stack* push(struct stack*, int); // ������ ������ �߰� 
struct stack* display(struct stack*); // ���� �����ִ¿�
struct stack* pop(struct stack*); // ���� ������ ���� (������ ���Լ���)
int peek(struct stack*); // ���� ����� 
int main(int argc, char *argv[]) {
	int val, option;
	do { // ��� �� ���̱� ���� �ǽ� 2�� ���� ó�� switch case�� �ۼ�
		printf("\n ********MAIN*************");
		printf("\n 1. Push");
		printf("\n 2. Pop ");
		printf("\n 3. Peek");
		printf("\n 4. Display");
		printf("\n 5. EXIT \n");
		scanf("%d", &option);
		switch (option) {
		case 1:
			printf("\n Enter the data number pushed on stack:");
			scanf("%d", &val); // val �̶�� ������ ������ ���� 
			top = push(top, val); //������ ������ �������� top�� ���ο� ������ ����
			break;
		case 2:
			top = pop(top); // ������ ������ top���� ������ �ϳ��� pop�ؿ�
			break;
		case 3:
			val = peek(top); // ������ ����� �����͸� ������
			if (val != -1)// ������ ���̰� 0�� �ƴҶ� �� ������ ������� ������
				printf("\n������ peek ����:%d", val);// ������ push �� ���� val�̴ϱ� val�� top
			else
				printf("\n������ ����ֽ��ϴ�.");
			break;
		case 4: 
			top = display(top);
			break;
		}
	} while (option != 5);
	return 0;
}
struct stack* push(struct stack* top, int val) //push �Լ�
{
	struct stack* ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack)); // �����Ҵ�
	ptr->data = val;
	if (top == NULL) // ������ ����ִ»����̸� 
	{
		ptr->next = NULL; //������ ������ϱ� ���� ���� ���� �翬�� NULL
		top = ptr; 
	}
	else
	{
		ptr->next = top;// ������ ��� ���� ���� ���� 
		top = ptr;
	}
	return top;
}
struct stack* display(struct stack* top)
{
	struct stack* ptr;
	ptr = top;
	if (top == NULL)
		printf("Empty Stack");
	else
	{
		while (ptr != NULL) //while ������ top�� null �ɶ� ���� �� push �� �� ���� while ������ ���
		{
			printf("\n %d", ptr->data); // �տ��� ���� �������� �� �����ֱ� ���Ѱ� 
			ptr = ptr->next; // ptr�� ���� data ����Ű�� �ϰ� while �ݺ�
		}
	}
	return top;
}
struct stack* pop(struct stack* top)
{
	struct stack* ptr;
	ptr = top;
	if (top == NULL)
		printf("������ ����־ pop�Ҳ� ����");
	else
	{ 
		top = top->next;// ������ null�� �ƴ�
		printf("delete data :%d", ptr->data); // data ��
		free(ptr);//�տ� ���� �޸� �Ҵ簪 �����ٶ��
	}
	return top;
}
int peek(struct stack* top) {
	if (top == NULL)
		return -1;
	else
		return top->data; // top ������ ��ȯ 
}