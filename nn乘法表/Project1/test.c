#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("������n*n�˷����Ӧ��n:\n");
	scanf("%d",&n);
	int row = 1;
	int col = 1;
	for (; row <= n; ++row) {
		for (col = 1; col <= row; ++col) {
			printf("%d * %d = %d\t",row,col,row*col);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}