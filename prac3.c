#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
char st[MAX][100], val[100];
int top = -1;
int push(char st[MAX][100], int* top, char val[100]);
int pop(char st[], int* top, char val[100]);
void display(char st[]);
int main()
{
	int option, s;
	do
	{

		printf("\n **********MAIN*************");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. display");
		printf("\n 4. EXIT");
		printf("\n Enter the option:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("\n Enter the student name:");
			scanf("%s", &val);
			s = push(st, &top, val);
			break;
		case 2:
			s = pop(st, &top, val);
			if (s = !- 1)
				printf("\nPop Student:%s", val);
			break;
		case 3:
			display(st);
			break;
		}
	} while (option != 3);
	return 0;
}

int push(char st[MAX][100], int* top, char val[100])
{
	if (*top == MAX - 1)
	{
		printf("\n STACK OVERFLOW");
	}
	else
	{
		*top = *top + 1;
		strcpy(st[*top], val);
		printf("%s push.", val);
	}
}
int pop(char st[MAX][100], int* top, char val[100])
{
	if (*top == -1)
	{
		printf("STACK UNDERFLOW");
	}
	else
	{
		strcpy(val, st[*top]);
		*top = *top - 1;
	}
}
