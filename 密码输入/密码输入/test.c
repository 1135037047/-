#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Register(char *arr) {
	char A[20] = { 0 };
	printf("����������:\n");
	for (int i = 1; i < 4; ++i) {
		scanf("%s", A);
		getchar(A);
		if (strcmp(A, arr) == 0) {
			printf("��½�ɹ�!\n");
			break;
		}
		else if (i != 3) {
			printf("���������������!\n");
			printf("������������%d��,����������:\n", 3 - i);
		}
		else {
			printf("�����������3��,�˳�����.");
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