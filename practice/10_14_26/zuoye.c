#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//在屏幕上输出9*9乘法口诀表
//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//求10 个整数中最大值
//int main()
//{
//	int i, max, num;
//	printf("请输入10个整数：\n");
//	scanf("%d", &max); 
//	for (i = 1; i < 10; i++)
//	{
//		scanf("%d", &num);
//		if (num > max)
//		{
//			max = num; 
//		}
//	}
//	printf("最大值是：%d\n", max);
//	return 0;
//}

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
//int main()
//{
//	double sum = 0;
//	int i;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum -= 1.0 / i;
//		}
//		else
//		{
//			sum += 1.0 / i;
//		}
//	}
//	printf("结果是：%lf\n", sum);
//	return 0;
//}

//编写程序数一下 1到 100 的所有整数中出现多少个数字9并打印
//int main() {
//    int count = 0;
//
//    for (int i = 1; i <= 100; i++) 
//    {
//        int n = i;
//        while (n > 0) 
//        {
//            if (n % 10 == 9)
//            {
//                count++;
//            }
//            n /= 10;
//        }
//    }
//
//    printf("1到100中数字9出现的次数为：%d\n", count);
//    return 0;
//}

//写一个代码：打印100~200之间的素数
//int main()
//{
//	int i, j,a;
//	for (i = 100; i <= 200; i++)
//	{
//		a = 1; 
//		for (j = 2; j * j <= i; j++) 
//		{
//			if (i % j == 0)
//			{
//				a = 0; 
//				break;
//			}
//		}
//		if (a && i > 1) 
//		{
//			printf("%d ", i);
//		}
//	}
//	printf("\n");
//	return 0;
//}

//打印1000年到2000年之间的闰年
//int main()
//{
//	int year;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			printf("%d ", year);
//		}
//	}
//	printf("\n");
//	return 0;
//}


//a, b, c(0 < a, b, c < 10)，表示三角形的三条边。
//
//	在一行上输出一个字符串，表示三角形的类型，具体地：
//	如果三角形是等边三角形，则输出
//	Equilateral triangle!；
//    如果三角形是等腰三角形，则输出
//	Isosceles triangle!；
//	如果三角形是普通三角形，则输出
//	Ordinary triangle!；
//	如果不能构成非退化三角形，则输出
//	Not a triangle!。
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a + b > c && a + c > b && b + c > a)
//	{
//		if (a == b && b == c)
//		{
//			printf("Equilateral triangle!\n");
//		}
//		else if (a == b || a == c || b == c)
//		{
//			printf("Isosceles triangle!\n");
//		}
//		else
//		{
//			printf("Ordinary triangle!\n");
//		}
//	}
//	else
//	{
//		printf("Not a triangle!\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a=0, b=0, c=0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a && b && c)
//	{
//		printf("a = 1\n");
//	}
//	else
//		printf("b = 1\n");
//}