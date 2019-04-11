#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left_revolve(char* start,int num) {
	int temp;
	int n = strlen(start);
	for (int i = 0; i < num; ++i) {
		temp = start[0];
		for (int j = 0; j < n - 1; ++j) {
			start[j] = start[j + 1];
		}
		start[n - 1] = temp;
	}
}
int main() {
	char start[100] = "";
	int num;
	printf("ÇëÊäÈëÔ´×Ö·û´®:\n");
	scanf("%s",start);
	printf("ÇëÊäÈëÐý×ª×Ö·ûÊý:\n");
	scanf("%d", &num);
	left_revolve(start, num);
	printf("%s\n",start);
	system("pause");
	return 0;
}