#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//分支与循环语句

//输入一个整数，逆序打印这个整数的每一位数
//假如说输入1234，%的话，432——1，43——2，4——3，0——4。for循环1234
//int main()
//{
//	int a = 0;
//	scanf("%d", &a); 
//	for (; a > 0;a /= 10 )
//	{
//		printf("%d", a % 10);
//	}
//	return 0;
//}

//计算1~100之间3的倍数之和
//int main()
//{
//	int sum = 0;
//	int a = 0;
//	while (a < 100)
//	{
//		if (a % 3 == 0)
//		{
//			sum += a;
//		}
//		a++;
//		
//	}
//	printf("%d", sum);//1683
//}

//利息3%，本金10000。计算5年中，每一年年底，本金加利息的结余
//int main()
//{
//	float a = 10000;
//	for (int i = 1; i <= 5; i++)
//	{
//	 a = a + a * 0.03;
//	 printf("第 %d 年年底结余：%f\n", i, a);
//	}
//}

//找出100~200之间的素数
//拿2~i-1去除i，如果能找到一个数能整除，那么就不是素数。

//int main(void) 
//{
//    int i, j;
//
//    for (i = 100; i <= 200; i++) 
//    {
//        int a = 1;               /* 先假设 i 是素数 */
//        for (j = 2; j < i; j++)
//        {
//            if (i % j == 0)
//            {          /* 能被整除，说明不是素数 */
//                a = 0;
//                break;
//            }
//            
//        }
//        if (a)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}

//猜数字
//有一个随机数，rand()
//改进：菜单循环、可以反复玩、随机数种子只播种一次、能处理错误输入
//
//void menu(void)
//{
//	printf("\n***** 猜数字 *****\n");
//	printf("1. play\n");
//	printf("2. exit\n");
//}
//
////清空当前行剩余的字符；返回 1 表示输入已经结束（EOF）
//static int clear_line(void)
//{
//	int c;
//	while ((c = getchar()) != '\n' && c != EOF)
//		;
//	return c == EOF;
//}
//
//void game(void)
//{
//	int guess = 0;
//	int count = 0;
//	int a = rand() % 100 + 1;          //a的取值范围1~100
//
//	printf("输入1~100之间的数字：\n");
//	while (1)
//	{
//		if (scanf("%d", &guess) != 1)
//		{
//			if (clear_line())          //Ctrl+Z 结束输入
//				break;
//			printf("输入的不是数字，请重新输入：\n");
//			continue;
//		}
//
//		count++;
//		if (a > guess)
//		{
//			printf("小了。\n");
//		}
//		else if (a < guess)
//		{
//			printf("大了。\n");
//		}
//		else
//		{
//			printf("猜中了！你一共猜了 %d 次。\n", count);
//			break;
//		}
//	}
//}
//
//int main(void)
//{
//	int input = 0;
//
//	srand((unsigned int)time(NULL));   //整个程序只播种一次
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		if (scanf("%d", &input) != 1)
//		{
//			if (clear_line())          //输入结束，直接退出
//				break;
//			printf("输入错误，请重新输入。\n");
//			continue;
//		}
//
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("退出游戏。\n");
//			break;
//		default:
//			printf("输入错误，请重新输入。\n");
//			break;
//		}
//	} while (input != 2);
//
//	system("pause");   //让控制台窗口停住，避免程序结束后窗口立刻关闭
//	return 0;
//}