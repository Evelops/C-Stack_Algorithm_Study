#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverse();
int main() {
	printf("문자열 입력:");
	reverse();// 리커전을 사용하여 string을 reverse하여 호출
	return 0;
}
void reverse() {
	char i;// 문자열 i 초기화
	scanf("%c", &i); // 문자열 입력
	if (i != '\n') {// i의 길이가 0이 아닐시
		reverse();// 재귀호출 사용 
		printf("%c", i);
	}
}