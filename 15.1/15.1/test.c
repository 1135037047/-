#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void find_data(int *arr, int size) {
	assert(arr != NULL);
	assert(size != NULL);
	int i = 0,j = 0;
	int x = 0, y = 0;
	int result = 0;
	int flag = 1;
	for (; i < size; ++i) {
		result ^= arr[i]; 
	}
	for (i = 0; i < 32; ++i) {
		if (result & (flag <<= 1)) {
			break;
		}
	}
	for (i = 0; i < size; ++i) {
		if (arr[i] &  flag) {
			x ^= arr[i];
		}
		else {
			y ^= arr[i];
		}
	}
	printf("%d %d", x, y);
}
int main() {
	int arr[] = { 1,2,3,4,5,6,7,32,20,7,6,5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find_data(arr, size);
	system("pause");
	return 0;
}