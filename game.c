#include"game.h"




//菜单
void menu()
{
	printf("--------------------\n");
	printf("----   1.play   ----\n");
	printf("----   0.exit   ----\n");
	printf("--------------------\n");
}

//定义函数
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("\n&&&  扫雷游戏  ----\n");
	printf(" ");
	for (i = 1; i <= col; i++)
	{
		printf(" %d", i);
	}
	printf("\n");
	printf("  -");
	for (i = 1; i < col; i++)
	{
		printf("--");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d| ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n&&&----------------\n\n");
}

//设置地雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	srand((unsigned int)time(NULL));
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//得到坐标周围雷的数量
static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1]-8*'0';
}

//查找地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = row * col - EASY_COUNT;
	while (win)
	{
		DisplayBoard(show, ROW, COL);
		printf("请输入你要排查的坐标:\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("恭喜你，被炸死了!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] == '*')
			{
				int ret = GetMineCount(mine,x,y);
				if (ret == 0)
				{
					show[x][y] = ' ';
				}
				else
				{
					show[x][y] = ret + '0';
				}
				win--;
				system("cls");
			}
			else
			{
				system("cls");
				printf("坐标已排查过，其重新输入!\n");
			}
		}
		else
		{
			system("cls");
			printf("坐标不合法，请重新输入!\n");
		}
	}
	if (win == 0)
	{
		printf("很遗憾，你赢了\n");
	}
}