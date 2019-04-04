#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int reverse_bit(unsigned int value) {
	int n = 32;
	char a;
	unsigned int result = 0;
	for (int i = 1; i <= n; ++i) {
		a = value % 2;
		value = value / 2;
		result += a * (unsigned int)pow(2, n - i);
	}
	return result;
}
int main() {
	unsigned int num;
	unsigned int result;
	printf("请输入对应的数字:\n");
	scanf("%u",&num);
	result = reverse_bit(num);
	printf("%u",result);
	system("pause");
	return 0;
}