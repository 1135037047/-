#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 5;
	int arr[20][20];
	for (int i = 0; i < n; ++i) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i;++j) {
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int m = n - i;m; --m) {
			printf(" ");
		}
		for (int j = 0; j <= i;++j) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}