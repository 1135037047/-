#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu() {
	printf("================\n");
	printf("===1.��ʼ��Ϸ===\n");
	printf("===0.������Ϸ===\n");
	printf("================\n");
	printf("���������Ӧ������ѡ���Ӧ��:\n");
	return ;
}
void game() {
	int random = rand() % 100 + 1;
	int num;
	while (1) {
		scanf("%d",&num);
		if (num > random) {
			printf("����!\n");
		}
		else if (num < random) {
			printf("С��\n");
		}
		else {
			printf("��ϲ��¶���!\n");
			return;
		}
	}	
}

int main() {
	int num;
	Menu();
	srand((unsigned int)time(0));
	while (1) {
		scanf("%d", &num);
		if (num == 1) {
			printf("��Ϸ��ʼ!\n");
			printf("������һ������:\n");
			game();
			putchar('\n');
			printf("������������ѡ��ʼ�µ���Ϸ�������Ϸ\n");
		}
		else if (num == 0) {
			printf("gameover,goodbye!\n");
			break;
		}
		else {
			printf("����������ֲ����Ϲ淶,����������:\n");
		}
	}
	system("pause");
	return 0;
}