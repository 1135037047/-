#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int ch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch >= 65 && ch <= 90) {
			putchar(ch + 32);
		}
		if(ch >= 97 && ch <= 122) {
			putchar(ch - 32);			
		}
		if (ch >= 48 && ch <= 57) {
		}
		
	}
	system("pause");
	return 0;
}