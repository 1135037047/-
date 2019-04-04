#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int average(int num1, int num2) {
	int result;
	if (num2 < num1) {
		result = (num1 - num2) / 2 + num2;
	}
	else {
		result = (num2 - num1) / 2 + num1;
	}
	return result;
}

int main() {
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	printf("%d\n",average(num1,num2));
	system("pause");
	return 0;
}