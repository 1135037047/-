#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Prime_num(int num) {
	int a = sqrt(num);
	if (num == 1 || num == 2 || num == 3) {
		if (num == 1) {
			return 0;
		}
		else {
			return 1;
		}
	}
	for (int i = 2; i <= a; ++i) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int num;
	int result;
	printf("��������Ҫ�жϵ���:\n");
	scanf("%d",&num);
	result = Prime_num(num);
	if (result == 1) {
		printf("%d������!\n", num);
	}
	else {
		printf("%d��������!\n",num);
	}
	system("pause");
	return 0;
}