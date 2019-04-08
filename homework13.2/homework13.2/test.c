#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 4
int Yanghui(int arr[row][col], int num) {
	int i = 0;
	int j = col - 1;
	int temp;
	while (1) {
		temp = arr[i][j];
		if (num == temp) {
			return 1;
		}
		if (num > temp) {	
			++i;
		}
		if (num < temp) {
			--j;
		}if (i == row || j < 0) {
			return 0;
		}
	}
}
int main(){
	int num;
	int arr[row][col] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
	printf("请输入要查找的数字:\n");
	scanf("%d",&num);
	if (Yanghui(arr, num)) {
		printf("%d在该数组中.\n",num);
	}
	else {
		printf("%d不在该数组中.\n",num);
	}
	system("pause");
	return 0;
}