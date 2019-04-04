#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[11] = { 15,15,20,20,5,100,5,6,6,7,7 };
	for (int i = 0; i < 11; ++i) {
		int a = arr[i];
		for (int j = 0; j < 11; ++j) {
			if (i == j) {
				continue;
			}
			a = a ^ arr[j];
		}
		if (a == arr[i]) {
			printf("%d\n",arr[i]);
		}
	}
	system("pause");
	return 0;
}