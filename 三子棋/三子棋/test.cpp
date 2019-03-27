#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3

char chess_board[MAX_ROW][MAX_COL];
int row;
int col;
//菜单
void Menu() {
	printf("====================\n");
	printf("=====1.开始游戏=====\n");
	printf("=====0.结束游戏=====\n");
	printf("====================\n");
}
//打印棋盘
void Print() {
	for (row = 0; row < MAX_ROW; ++row) {		
		printf("| %c | %c | %c |\n",chess_board[row][0],
			chess_board[row][1], chess_board[row][2]);
		if (row != 2) {
			printf("|---|---|---|\n");
		}
	}
}
//创建棋盘
void Init() {
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
}
//玩家落子
void PlayerMove() {
	printf("请输入您要落子的坐标:\n");
	while (1) {
		scanf("%d %d", &row, &col);
		if (chess_board[row][col] != ' ') {
			printf("您要落子的位置已有棋子,请重新落子:\n");
		}
		else {
			chess_board[row][col] = 'x';
			break;
		}
	}
}
//电脑落子
void ComputerMove() {
	printf("电脑落子.\n");
	while (1) {
		row = rand() % 3;
		col = rand() % 3;
		if (chess_board[row][col] == ' ') {
			chess_board[row][col] = 'o';
			break;
		}
	}
}
//检验胜负
char CheckWinner() {
	for (row = 0; row < MAX_ROW; ++row) {
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2]) {
			if (chess_board[row][0] == 'x') {
				return 'x';
			}
			else if (chess_board[row][0] == 'o') {
				return 'o';
			}
		}
	}
	for (col = 0; col < MAX_COL; ++col) {
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col]) {
			if (chess_board[0][col] == 'x') {
				return 'x';
			}
			else if (chess_board[0][col] == 'o') {
				return 'o';
			}
		}
	}
	//两种对角线胜利情况的判定
	if ((chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2]) || 
		(chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0])) {
		if (chess_board[1][1] == 'x') {
			return 'x';
		}
		else if (chess_board[1][1] == 'o') {
			return 'o';		
		}
	}
	for (row = 0; row < MAX_ROW;++row) {
		for (col = 0; col < MAX_COL;++col) {
			if (chess_board[row][col] == ' ') {
				return ' ';
			}
		}
	}
	return 'p';
}

void Game() {
	srand((unsigned int) time(0));
	char winner = ' ';
	Init();
	Print();
	while (1) {	
		PlayerMove();
		Print();
		winner = CheckWinner();
		if (winner == 'x') {
			printf("恭喜您取得胜利!\n");
			break;
		}
		else if (winner == 'p') {
			printf("您与电脑不分胜负.\n");
			break;
		}
		ComputerMove();
		Print();
		winner = CheckWinner();
		if (winner == 'o') {
			printf("失败来之不易!\n");
			break;
		}
	}
}

int main() {
	int command;
	Menu();
	printf("请您输入指令:\n");
	while (1) {
		scanf("%d", &command);
		if (command == 1) {
			Game();
			printf("本轮游戏结束,你可以选择开始新的游戏或者结束游戏.\n");
		}
		else if (command == 0) {
			printf("goodbye!\n");
			system("pause");
			return 0;
		}
		else {
			printf("您输入的指令有误,请重新输入:\n");
		}
	}
}