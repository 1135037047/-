#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int leap_year(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 1;
			}
		}
		else {
			return 1;
		}
	}
	return 0;
}
int main() {
	int year;
	int result;
	scanf("%d",&year);
	result = leap_year(year);
	if (result == 1) {
		printf("%d年是闰年!\n", year);
	}
	else {
		printf("%d年不是闰年!\n",year);
	}
	system("pause");
	return 0;
}