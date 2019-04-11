#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int revolve(char* start, char* aim) {
	if (strlen(start) != strlen(aim)) {
		return 0;
	}
	if (!strcmp(start, aim)) {
		return 1;
	}
	int size = 2 * strlen(aim) + 1;
	char* str = (char*)malloc(size);
	strcpy(str, start);
	strcat(str, start);
	if (strstr(str, aim)) {
		return 1;
	}
	free(str);
	return 0;
}
int main() {
	char start[10] = "";
	char aim[10] = "";
	printf("ÇëÊäÈëÔ´×Ö·û´®:\n");
	scanf("%s", start);
	printf("ÇëÊäÈëÄ¿±ê×Ö·û´®:\n");
	scanf("%s", aim);
	printf("%d", revolve(start, aim));
	system("pause");
	return 0;
}