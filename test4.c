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
	for (i = 0; i < n; i++) //�迭�� ũ�� ��ŭ �迭�� �� �־���
		scanf("%d", &arr[i]);
	for (i = 0; i < n; i++)// ��� stack�� ���� push�Ҷ� stack�� ũ�� n��ŭ push �Ҽ� �ִ�
		push(arr[i]);	
	for (i = 0; i < n; i++) {// push �� ��������
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