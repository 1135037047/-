#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *arr,int size) {
	if (arr[0] == '\0'||size < 0) {
		return;
	}
	char temp;;
	temp = arr[0];
	arr[0] = arr[size -1];
	arr[size - 1] = '\0';
	swap(arr + 1,size - 2);
	arr[size - 1] = temp;
}
void _size(char *arr,int size) {
	int num = 0;
	for (int i = 0; i < size; ++i) {	
		if (arr[i] == ' '||arr[i] == '\0') {	
			swap(arr + i - num ,num);
			num = 0;
		}
		else {
			num = num + 1;
		}
	}
}
int main() {
	int size;
	char arr[] = "student a am i";
	size = sizeof(arr) / sizeof(arr[0]);
	_size(arr,size);
	swap(arr,size - 1);
	printf("%s\n",arr);
	system("pause");
	return 0;
}