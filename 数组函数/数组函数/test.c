#include <stdio.h>
#include <stdlib.h>

void Init(int arr[],int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
	}
}
void empty(int arr[],int size) {
	memset(arr, 0,size*sizeof(arr));
}

void reverse(int arr[],int size) {
	int temp;
	for (int i = 0; i < size / 2; ++i) {
		temp = arr[size - 1 - i];
		arr[size - 1 - i] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	int arr[10] = {9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(arr) / sizeof(arr[0]);
	Init(arr,size);
	for (int i = 0; i < size; ++i) {
		printf("%d", arr[i]);
	}
	printf("\n");
	empty(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d", arr[i]);
	}
	printf("\n");
	reverse(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}