#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int area(int a, int b, int c) {
	return (a + b)*c / 2;
}
void grade(int *grade) {
	printf("�ܷ�:%d\n", grade[1] + grade[2] + grade[3] + grade[0]);
	printf("ƽ����:%f\n", (grade[1] + grade[2] + grade[3] + grade[0]) / 4.0);
	int max, min;
	max = min = grade[0];
	for (int i = 0; i < 4; ++i) {
		if (grade[i] < min) {
			min = grade[i];
		}
		if (grade[i] > max) {
			max = grade[i];
		}
	}
	printf("��߷�:%d\n��ͷ�:%d\n", max, min);
}
int main() {
	printf("�������������ε����µױ߳��͸�:");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("�����������:%d\n", area(a, b, c));
	system("pause");
	printf("������ĳͬѧ�ĳɼ�:");
	int grade1[4] = { 0 };
	scanf("%d %d %d %d", &grade1[0], &grade1[1], &grade1[2], &grade1[3]);
	grade(grade1);
	system("pause");
	return 0;
}