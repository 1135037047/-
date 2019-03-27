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
//�˵�
void Menu() {
	printf("====================\n");
	printf("=====1.��ʼ��Ϸ=====\n");
	printf("=====0.������Ϸ=====\n");
	printf("====================\n");
}
//��ӡ����
void Print() {
	for (row = 0; row < MAX_ROW; ++row) {		
		printf("| %c | %c | %c |\n",chess_board[row][0],
			chess_board[row][1], chess_board[row][2]);
		if (row != 2) {
			printf("|---|---|---|\n");
		}
	}
}
//��������
void Init() {
	for (row = 0; row < MAX_ROW; ++row) {
		for (col = 0; col < MAX_COL; ++col) {
			chess_board[row][col] = ' ';
		}
	}
}
//�������
void PlayerMove() {
	printf("��������Ҫ���ӵ�����:\n");
	while (1) {
		scanf("%d %d", &row, &col);
		if (chess_board[row][col] != ' ') {
			printf("��Ҫ���ӵ�λ����������,����������:\n");
		}
		else {
			chess_board[row][col] = 'x';
			break;
		}
	}
}
//��������
void ComputerMove() {
	printf("��������.\n");
	while (1) {
		row = rand() % 3;
		col = rand() % 3;
		if (chess_board[row][col] == ' ') {
			chess_board[row][col] = 'o';
			break;
		}
	}
}
//����ʤ��
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
	//���ֶԽ���ʤ��������ж�
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
			printf("��ϲ��ȡ��ʤ��!\n");
			break;
		}
		else if (winner == 'p') {
			printf("������Բ���ʤ��.\n");
			break;
		}
		ComputerMove();
		Print();
		winner = CheckWinner();
		if (winner == 'o') {
			printf("ʧ����֮����!\n");
			break;
		}
	}
}

int main() {
	int command;
	Menu();
	printf("��������ָ��:\n");
	while (1) {
		scanf("%d", &command);
		if (command == 1) {
			Game();
			printf("������Ϸ����,�����ѡ��ʼ�µ���Ϸ���߽�����Ϸ.\n");
		}
		else if (command == 0) {
			printf("goodbye!\n");
			system("pause");
			return 0;
		}
		else {
			printf("�������ָ������,����������:\n");
		}
	}
}