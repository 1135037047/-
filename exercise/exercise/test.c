#include <stdio.h>
#include <stdlib.h>

void print1() {
	printf("#\n");
	printf("##\n");
	printf("###\n");
	printf("####\n");
}
void print2() {
	printf("***********************\n");
	printf("  欢迎进入C语言天地!\n");
	printf("***********************\n");
}
void print3() {
	printf("sxd\n");
}
void swith(char *x) {
	printf("%c\n",*x +32);
}
int main() {
	int i = 5, j = 15, k = 20;
	int a1, a2;
	a1 = (++i) * (++j) * (++k);
	a2 = (i++) * (++j) * (k++);
	printf("%d %d %d %d %d\n",i,j,k,a1,a2);
	char a = 'Q';
	char b = 'A';
	swith(&a);
	swith(&b);
	print1();
	print2();
	print3();
	system("pause");
	return 0;
}