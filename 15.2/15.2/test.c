#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int money;
	printf("买汽水的钱数:\n");
	scanf("%d", &money);
	int result = 20 * 2 - 1;
	printf("可以喝%d瓶汽水.\n",result);
	system("pause");
	return 0;
}