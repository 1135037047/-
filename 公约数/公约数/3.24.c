#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	c = abs(a);
	if (abs(a) > abs(b)) {
		c = abs(b);
	}
	for (int i = 1; i < c + 1; i++) {
		if (a % i == 0 && b % i == 0) {
			d = i;
		}
	}
	printf("这两个数的最大公因数是：%d\n", d);
	system("pause");
	return 0;
}