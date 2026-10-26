#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int GetMIneCount(char mine[ROWS][COLS], int x, int y);

void IntBoard(char board[ROWS][COLS], int row, int col,int set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	//打印列号
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}

	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号

		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = 10;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col -EASY_MINE)
	{
		printf("输入排查雷的位置：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] != '1')
				{
					int num = GetMIneCount(mine,x,y);
					show[x][y] = num + '0';
					DisplayBoard(show, row, col);
					win++;
				}
				else
				{
					printf("你输了；\n");
					DisplayBoard(mine, row, col);
					break;
				}
			}
			else
			{
				printf("重复；\n");
			}
		}
		else
		{
			printf("输入错误；");
		}
	}
	if (win == row * col - EASY_MINE)
	{
		printf("WIN；\n");
		DisplayBoard(mine, ROW, COL);
	}
}

int GetMIneCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
	       mine[x][y - 1] + mine[x][y + 1] +
	       mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}