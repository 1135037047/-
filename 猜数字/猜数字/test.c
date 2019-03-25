#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menu() {
	printf("================\n");
	printf("===1.开始游戏===\n");
	printf("===0.结束游戏===\n");
	printf("================\n");
	printf("请您输入对应的数字选择对应项:\n");
	return ;
}
void game() {
	int random = rand() % 100 + 1;
	int num;
	while (1) {
		scanf("%d",&num);
		if (num > random) {
			printf("大了!\n");
		}
		else if (num < random) {
			printf("小了\n");
		}
		else {
			printf("恭喜你猜对了!\n");
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
			printf("游戏开始!\n");
			printf("请输入一个数字:\n");
			game();
			putchar('\n');
			printf("请输入新命令选择开始新的游戏或结束游戏\n");
		}
		else if (num == 0) {
			printf("gameover,goodbye!\n");
			break;
		}
		else {
			printf("您输入的数字不符合规范,请重新输入:\n");
		}
	}
	system("pause");
	return 0;
}