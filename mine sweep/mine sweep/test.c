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
	printf("==1.游戏开始==\n");
	printf("==0.游戏结束==\n");
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
	
	//创建两张地图 展示地图和地雷图
	Init(show_map,mine_map);
	//打印地图(show_map)
	Printf_Map(show_map);
	int row;
	int col;
	printf("请输入要翻开位置的坐标(row col)\n");
	while (1) {
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("您输入的数据不和规范,请重新输入:\n");
			continue;
		}
		else if (show_map[row][col] != '*') {
			printf("您输入的位置已被翻开,请重新输入:\n");
			continue;
		}
		if (mine_map[row][col] == 'x') {
			printf("游戏结束!\n");
			Printf_Map(mine_map);
			break;
		}
		UpdateShow_Map(row,col, show_map,mine_map);
		Printf_Map(show_map);
		//判断游戏胜利 所有非雷格子翻开即为游戏胜利
		if (blank_count_already_show == (MAX_ROW * MAX_COL - MINE_COUNT)) {
			printf("您赢了!\n");
			break;
		}
	}
}

int main() {
	int command;
	//打印菜单
	Menu();
	printf("请输入游戏指令:\n");
	while (1) {
		scanf("%d", &command);
		if (command == 1) {
			//开始游戏
			Game();
			printf("请输入新的指令选择开始新的游戏,或者结束游戏.\n");
		}
		else if (command == 0) {
			printf("goodbay!\n");
			break;
		}
		else {
			printf("您的输入不合规范,请重新输入:");
		}
	}
	system("pause");
	return 0;
}