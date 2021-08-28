#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
// 링크 리스트를 사용하여 스택 구현 기능은 스택의 기본 기능인 push,pop,peek,display 
struct stack { //구조체를 사용하여 stack 구성
	int data;
	struct stack* next;
};
struct stack* top = NULL; // top은 비어있다고 가정  처음에 스택은 비어있는 상태인거임
struct stack* push(struct stack*, int); // 스택의 데이터 추가 
struct stack* display(struct stack*); // 스택 보여주는용
struct stack* pop(struct stack*); // 스택 데이터 제거 (스택은 후입선출)
int peek(struct stack*); // 스택 꼭대기 
int main(int argc, char *argv[]) {
	int val, option;
	do { // 기능 잘 보이기 위해 실습 2번 내용 처럼 switch case로 작성
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
			scanf("%d", &val); // val 이라는 정수형 데이터 삽입 
			top = push(top, val); //스택의 구조상 데이터의 top에 새로운 데이터 삽입
			break;
		case 2:
			top = pop(top); // 스택의 구조상 top에서 데이터 하나를 pop해옴
			break;
		case 3:
			val = peek(top); // 스택의 꼭대기 데이터를 보여줌
			if (val != -1)// 스택의 높이가 0이 아닐때 즉 스택이 비어있지 않을때
				printf("\n스택의 peek 값은:%d", val);// 스택의 push 한 값이 val이니까 val이 top
			else
				printf("\n스택은 비어있습니다.");
			break;
		case 4: 
			top = display(top);
			break;
		}
	} while (option != 5);
	return 0;
}
struct stack* push(struct stack* top, int val) //push 함수
{
	struct stack* ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack)); // 동적할당
	ptr->data = val;
	if (top == NULL) // 스택이 비어있는상태이면 
	{
		ptr->next = NULL; //스택이 비었으니까 스택 다음 값도 당연히 NULL
		top = ptr; 
	}
	else
	{
		ptr->next = top;// 스택이 비어 있지 않은 상태 
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
		while (ptr != NULL) //while 돌려서 top이 null 될때 까지 즉 push 한 값 까지 while 돌려서 출력
		{
			printf("\n %d", ptr->data); // 앞에서 집어 넣은값들 다 보여주기 위한거 
			ptr = ptr->next; // ptr이 다음 data 가르키게 하고 while 반복
		}
	}
	return top;
}
struct stack* pop(struct stack* top)
{
	struct stack* ptr;
	ptr = top;
	if (top == NULL)
		printf("스택이 비어있어서 pop할께 없음");
	else
	{ 
		top = top->next;// 스택이 null이 아님
		printf("delete data :%d", ptr->data); // data 한
		free(ptr);//앞에 동적 메모리 할당값 맞춰줄라고
	}
	return top;
}
int peek(struct stack* top) {
	if (top == NULL)
		return -1;
	else
		return top->data; // top 데이터 반환 
}