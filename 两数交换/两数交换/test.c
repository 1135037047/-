#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
int main() {
	int x, y;
	scanf("%d %d",&x,&y);
	swap(&x, &y);
	printf("x = %d,y = %d\n",x,y);
	system("pause");
	return 0;
}