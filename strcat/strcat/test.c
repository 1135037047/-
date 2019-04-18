#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


char* Strcat(char * destination,const char* source) {
	int i = 0;
	int j = 0;
	for (; destination[i] != '\0'; ++i);
	for (; source[j] != '\0'; ++j,++i) {
		destination[i] = source[j];
	}
	destination[i] = source[j];
	return destination;
}
int main() {
	char a[1024] = "axnicabi";
	char b[1024] = "hfuash";
	Strcat(a, b);
	printf("%s", a);
	system("pause");
	return 0;
}