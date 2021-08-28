#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#define MAX 10// 스택 크기
int stack[MAX], topA = -1, topB = MAX;
void pushA(int val) {
	if (topA == topB)//topA가 MAX일 경우 Overflow 발생.
		printf("\n overflow");
	else
	{
		topA += 1; // topA가 MAX가 아닐때 즉, 비어있을 때 push. 
		stack[topA] = val;
	}
}
int popA() {
	int val;
	if (topA == -1)
	{
		printf("\n Underflow");// topA가 0일때 underflow 
		val = -999;
	}
	else
	{
		val = stack[topA];
		topA--;
	}
	return val;
}
void display_stackA() {
	int i;
	if (topA == -1)
	{
		printf("\n Stack is empty"); 
	}
	{
		for (i = topA; i >= 0; i--) {  // 스택이 null이 아니면 top부터 차례로  스택 A의 값 출력
			printf("\t %d", stack[i]);
		}
	}
}
void pushB(int val) {
	if (topB - 1 == topA)
		printf("\n Overflow");
	else
	{
		topB = -1;//
		stack[topB] = val;
	}
}
int popB()
{
	int val;
	if (topB == MAX)
	{
		printf("\n Underflow");
		val = -999;
	}
	else
	{
		val = stack[topB];
		topB++;
	}
}
void display_stackB()
{
	int i;
	if (topB == MAX)
		printf("\n Stack B is empty");
	else
	{
		for (i = topB; i < MAX; i++)
			printf("\t %d", stack[i]);
	}
}
void main() {
	int option, val;
	do
	{
		printf("\n **********MENU***************");
		printf("\n 1. Push in stack A");
		printf("\n 2. Push in stakc B");
		printf("\n 3. Pop from stack A");
		printf("\n 4. POP FROM STACK B");
		printf("\n 5. DISPLAY STACK A");
		printf("\n 6. DISPLAY STACK B");
		printf("\n 7. EXIT");
		printf("\n Enter your choice:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("\n Etner the value to push on Stack A: ");
			scanf("%d", &val);
			pushA(val);
			break;
		case 2:
			printf("\n Enter the value to push on Stack B:");
			scanf("%d", &val);
			pushB(val);
			break;
		case 3:
			val = popA();
			if (val != -999)
				printf("\n The valuse popped from Stack A=%d", val);
			break;
		case 4:
			val = popB();
			if (val != -999)
				printf("\n The value popped from Stack B=%d", val);
			break;
		case 5:
			printf("\n The contents of stack A are:\n");
			display_stackA();
			break;
		case 6:
			printf("\n The contents of stack B are:\n");
			display_stackB();
			break;
		}
	} while (option != 7);
}