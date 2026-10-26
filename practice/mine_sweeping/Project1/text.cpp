#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu();//菜单
void game();//游戏逻辑

int main()
{
	srand((unsigned int) time(NULL));
	int input = 2;

	do 
	{
		menu();
		printf("请输出：");

		if( scanf("%d",&input) != 1 )
		{
			printf("输入错误。");
			while (getchar() != '\n')
			{
				;
			}
			input = 2;
			continue;
		}

		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏；");
			break;
		default:
			printf("选择错误；");
			break;
		}

	} while (input);

	return 0;
}

void menu()
{
	printf("1.play\n");
	printf("0.exit\n");
}

void game()
{
	char show[ROWS][COLS];
	char mine[ROWS][COLS];

	//初始化棋盘
	IntBoard(mine, ROWS, COLS,'0');
	IntBoard(show, ROWS, COLS,'*');

	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);

	FindMine(mine, show, ROW, COL);

}