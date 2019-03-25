#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Register(char *arr) {
	char A[20] = { 0 };
	printf("请输入密码:\n");
	for (int i = 1; i < 4; ++i) {
		scanf("%s", A);
		getchar(A);
		if (strcmp(A, arr) == 0) {
			printf("登陆成功!\n");
			break;
		}
		else if (i != 3) {
			printf("您输入的密码有误!\n");
			printf("还可以再输入%d次,请重新输入:\n", 3 - i);
		}
		else {
			printf("您已连续输错3次,退出程序.");
		}
	}
	return;
}

int main() {
	char arr[] = "qwertyu";
	Register(arr);
	system("pause");
	return 0;
}