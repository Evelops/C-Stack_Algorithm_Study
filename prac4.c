#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverse();
int main() {
	printf("���ڿ� �Է�:");
	reverse();// ��Ŀ���� ����Ͽ� string�� reverse�Ͽ� ȣ��
	return 0;
}
void reverse() {
	char i;// ���ڿ� i �ʱ�ȭ
	scanf("%c", &i); // ���ڿ� �Է�
	if (i != '\n') {// i�� ���̰� 0�� �ƴҽ�
		reverse();// ���ȣ�� ��� 
		printf("%c", i);
	}
}