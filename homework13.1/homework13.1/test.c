#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void func(int *arr,int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 2) {
		}
		else {
			while (1) {
				if (arr[size - 1] % 2 == 0) {
					size = size - 1;
				}
				else {
					break;
				}
			}
			if (i > size - 1) {
				return;
			}
			swap(&arr[i],&arr[size - 1]);
			size = size - 1;
		}
	}
}
int main() {
	int arr[10] = {1,5,8,4,6,2,3,1,5,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	func(arr,size);
	for (int i = 0; i < size; ++i) {
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}