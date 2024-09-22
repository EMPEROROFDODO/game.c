
#include"game.h"

void game()
{
	//创建棋盘
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');

	//检查是否成功初始化
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);

	//设置地雷
	SetMine(mine, ROW, COL);
	
	//检查是否成功设置地雷
	//DisplayBoard(mine, ROW, COL);

	//查找地雷
	FindMine(mine, show, ROW, COL);

}
int main()
{
	int input = 0;
	do{
		menu();
		printf("请做出你的选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input);
	return 0;
}