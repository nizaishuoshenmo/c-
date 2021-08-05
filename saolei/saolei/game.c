#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "saolei.h"
void menu()
{
	printf("*********************\n");
	printf("***1.play  0.exit****\n");
	printf("*********************\n");
}
void game()
{
	//雷的信息储存
	//1。布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);	
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//对于rand的时间戳
	do
	{
		
		menu();
		printf("请选择>:");
		scanf("%d", &input) ;
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break; 
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}