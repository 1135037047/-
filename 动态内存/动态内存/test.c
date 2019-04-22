#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int arr[20] = { 1,5,2,3,4,8,7,6,9,0,11,21,151,45,6,84,312,486,45,12};
	int *p = (int *)malloc(sizeof(int) * 10);
	if (p == NULL) {
		return 1;
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d ", p[i] = arr[i]);
	}
	p = realloc(p, sizeof(arr));
	if (p == NULL) {
		return 1;
	}
	for (int i = 0; i < 20; ++i) {
		printf("%d ", p[i] = arr[i]);
	}
	free(p);
	int * p1 = (int*)calloc(4,5);
	if (p1 == NULL) {
		return 1;
	}
	printf("%d %d %d %d %d ", p1[0],p1[1], p1[2], p1[3], p1[4]);
	system("pause");
	return 0;
}