#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int find(int arr[],int x,int size) {
	int left = 0;
	int right = size;
	while (right >= left) {
		int y = (right + left) / 2;
		if (x > arr[y]) {
			left = y + 1;
		}
		else if (x < arr[y]) {
			right = y - 1;
		}
		else {
			return y;
		}
	}
	return -1;
}

int main() {
	int arr[50];
	int num = 1;
	int n;
	int size;
	size = sizeof(arr) / sizeof(arr[0]) - 1;
	for (int i = 0; i < 50; ++i) {
		num = 3 * i;
		arr[i] = num;
	}
	printf("请输入您要查找的数据:\n");
	scanf("%d",&n);
	printf("%d\n",find(arr,n,size));
	system("pause");
	return 0;
}