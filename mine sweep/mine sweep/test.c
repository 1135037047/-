#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 10
#define MAX_COL 10
#define MINE_COUNT 10

int blank_count_already_show = 0;
void Menu() {
	printf("==============\n");
	printf("==1.��Ϸ��ʼ==\n");
	printf("==0.��Ϸ����==\n");
	printf("==============\n");
}

void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	int row = 0;
	int col = 0;
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = ' ';
		}
	}
	int count = 0;
	while (count < MINE_COUNT) {
		row = rand() % MAX_ROW;
		col = rand() % MAX_COL;
		if (mine_map[row][col] == ' ') {
			mine_map[row][col] = 'x';
			++count;
		}
	}
}

void Printf_Map(char show_map[MAX_ROW][MAX_COL]) {
	printf("   ");
	for (int row = 0; row < MAX_ROW; ++row) {
		printf(" %d",row);
	}
	printf("\n");
	printf("\n");
	for (int row = 0; row < MAX_ROW;++row) {
		printf(" %d ",row);
		for (int col = 0; col < MAX_COL; ++col) {
			printf(" %c",show_map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShow_Map(int row,int col,char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && row - 1 < MAX_ROW &&
		col - 1 < MAX_COL && mine_map[row - 1][col - 1] == 'x') {
		++count;
	}	
	if (row - 1 >= 0 && col >= 0 && row - 1 < MAX_ROW &&
		col < MAX_COL && mine_map[row - 1][col] == 'x') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0 && row - 1 < MAX_ROW &&
		col + 1 < MAX_COL && mine_map[row - 1][col + 1] == 'x') {
		++count;
	}
	if (row >= 0 && col - 1 >= 0 && row < MAX_ROW &&
		col - 1 < MAX_COL && mine_map[row][col - 1] == 'x') {
		++count;
	}
	if (row >= 0 && col + 1 >= 0 && row < MAX_ROW &&
		col +1 < MAX_COL && mine_map[row][col + 1] == 'x') {
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0 && row + 1 < MAX_ROW &&
		col - 1 < MAX_COL && mine_map[row + 1][col - 1] == 'x') {
		++count;
	}
	if (row + 1 >= 0 && col >= 0 && row + 1 < MAX_ROW &&
		col < MAX_COL && mine_map[row + 1][col] == 'x') {
		++count;
	}
	if (row + 1 >= 0 && col + 1 >= 0 && row + 1 < MAX_ROW &&
		col + 1 < MAX_COL && mine_map[row + 1][col + 1] == 'x') {
		++count;
	}
	show_map[row][col] = '0' + count;
	++blank_count_already_show;
	if (count == 0) {
		if (row - 1 >= 0 && col - 1 >= 0 &&
			row - 1 < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row - 1][col - 1] == '*') {
			UpdateShow_Map(row - 1, col - 1, show_map, mine_map);
		}
		if (row - 1 >= 0 && col >= 0 &&
			row - 1 < MAX_ROW && col < MAX_COL
			&& show_map[row - 1][col] == '*') {
			UpdateShow_Map(row - 1, col, show_map, mine_map);
		}		
		if (row - 1 >= 0 && col + 1 >= 0 &&
			row - 1 < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row - 1][col + 1] == '*') {
			UpdateShow_Map(row - 1, col + 1, show_map, mine_map);
		}	
		if (row >= 0 && col - 1 >= 0 &&
			row < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row][col - 1] == '*') {
			UpdateShow_Map(row, col - 1, show_map, mine_map);
		}		
		if (row >= 0 && col + 1 >= 0 &&
			row < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row][col + 1] == '*') {
			UpdateShow_Map(row, col + 1, show_map, mine_map);
		}		
		if (row + 1 >= 0 && col - 1 >= 0 &&
			row + 1 < MAX_ROW && col - 1 < MAX_COL
			&& show_map[row + 1][col - 1] == '*') {
			UpdateShow_Map(row + 1, col - 1, show_map, mine_map);
		}
		if (row + 1 >= 0 && col >= 0 &&
			row + 1 < MAX_ROW && col < MAX_COL
			&& show_map[row + 1][col] == '*') {
			UpdateShow_Map(row + 1, col, show_map, mine_map);
		}
		if (row + 1 >= 0 && col + 1 >= 0 &&
			row + 1 < MAX_ROW && col + 1 < MAX_COL
			&& show_map[row + 1][col + 1] == '*') {
			UpdateShow_Map(row + 1, col + 1, show_map, mine_map);
		}
	}
}

void Game() {
	srand((unsigned int)time(0));
	char show_map[MAX_ROW][MAX_COL] = { 0 };
	char mine_map[MAX_ROW][MAX_COL] = { 0 };
	
	//�������ŵ�ͼ չʾ��ͼ�͵���ͼ
	Init(show_map,mine_map);
	//��ӡ��ͼ(show_map)
	Printf_Map(show_map);
	int row;
	int col;
	printf("������Ҫ����λ�õ�����(row col)\n");
	while (1) {
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("����������ݲ��͹淶,����������:\n");
			continue;
		}
		else if (show_map[row][col] != '*') {
			printf("�������λ���ѱ�����,����������:\n");
			continue;
		}
		if (mine_map[row][col] == 'x') {
			printf("��Ϸ����!\n");
			Printf_Map(mine_map);
			break;
		}
		UpdateShow_Map(row,col, show_map,mine_map);
		Printf_Map(show_map);
		//�ж���Ϸʤ�� ���з��׸��ӷ�����Ϊ��Ϸʤ��
		if (blank_count_already_show == (MAX_ROW * MAX_COL - MINE_COUNT)) {
			printf("��Ӯ��!\n");
			break;
		}
	}
}

int main() {
	int command;
	//��ӡ�˵�
	Menu();
	printf("��������Ϸָ��:\n");
	while (1) {
		scanf("%d", &command);
		if (command == 1) {
			//��ʼ��Ϸ
			Game();
			printf("�������µ�ָ��ѡ��ʼ�µ���Ϸ,���߽�����Ϸ.\n");
		}
		else if (command == 0) {
			printf("goodbay!\n");
			break;
		}
		else {
			printf("�������벻�Ϲ淶,����������:");
		}
	}
	system("pause");
	return 0;
}