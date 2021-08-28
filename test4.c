#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int stk[10];
int top = -1;
int pop();
void push(int);
int main(){
	int val, i, n, arr[10];
	printf("\n Enter the number of elements in the array:");
	scanf("%d", &n);
	printf("\n Enter the elemenets of the array:");
	for (i = 0; i < n; i++) //배열의 크기 만큼 배열의 값 넣어줌
		scanf("%d", &arr[i]);
	for (i = 0; i < n; i++)// 얘는 stack에 값을 push할때 stack의 크기 n만큼 push 할수 있다
		push(arr[i]);	
	for (i = 0; i < n; i++) {// push 와 마찬가지
		val = pop();
		arr[i] = val;
	}
	printf("\n The reversed array is:");
	for (i = 0; i < n; i++) {
		printf("\n %d", arr[i]);
	}
	return 0;
}
void push(int val) {
	stk[++top] = val;
}
int pop() {
	return(stk[top--]);
}