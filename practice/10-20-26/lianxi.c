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

//void test()
//{
//	int n = 0;
//	n++;
//	printf("%d", n);
//}
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		test();
//	}
//	return 0;
//}

//scanf从开始到第一个不符合条件的字符，读不到则返回0。所以打印出来第二个为0
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

//观察printf打印小数时，最小宽度是否会把‘.’算上//不会

//int main()
//{
//	printf("%5.3f",23.14);
//	return 0;
//}

//斐波那契数列的特点是，第0个数是0，第1个数是1，往后的数字都是前2个数字之和
//现在给定⼀个n的值(n从0开始)，计算出第n个斐波那契数（不考虑溢出）。

//int fun(int a)
//{
//	
//	if (a == 1)
//		return 1;
//	if (a == 0)
//		return 0;
//	return  fun(a - 1) + fun(a - 2);
//}
//int main()
//{
//	int a = 0;
//	int num = 0;
//
//	scanf("%d", &a);
//	num = fun(a);
//	printf("%d", num);
//}

//求n的阶乘
//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	return n * fac(n-1);
//}
//int  main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int num = fac(n);
//	printf("%d", num);
//}

//void*规范格式。打印指针占位符使用%p。验证字符串？……？
//char a = 'p';
//int main()
//{
//	char b = 'p';
//	printf("%d\n",(void *) &a);
//	printf("%d",(void *)&b);
//	
//}

//%p打印出来的地址是十六进制的。%d打印出来的十进制。
//int main()
//{
//	int a = 1;
//	printf("%d\n", &a);
//	printf("%d", &a + 1);
//}

//数组名 单独出现的时候仅代表数组首元素的地址。
//int main()
//{
//	int a [5] = {1,2,3,4,5};
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//}

//int main()
//{
//	char a[3] = { 'a','s','d' };
//	printf("%c\n", a[1]);
//	printf("%c",*(a + 1));
//}

//声明里是"类型"，表达式里是"取值"。解引用解的是地址，不是地址时不能用
//int main()
//{
//	int x = 42;
//	int* p = &x;
//
//	printf("%d\n", *p);   // 42 —— 取 p 指向的值
//	*p = 100;             // 通过 p 修改 x，x 变成 100
//}

//sizeof 是 C 的编译期运算符（不是函数），返回某个类型或对象占用的字节数，类型是 size_t。
//打印用% zu（size_t 的格式符）。sizeof 只看类型， 不真正计算表达式
//int a[10];
//int* p = a;
//
//sizeof(a)   // 40  —— 整个数组的字节数（10 * 4）
//sizeof(p)   // 8   —— 指针本身的大小（64 位）
//sizeof(*p)  // 4   —— 一个 int
//形参 int arr[10] 实际等价于 int* arr，数组退化，sizeof 得到的是指针大小。这也是为什么函数里传数组必须额外传长度：
//void f(int arr[10]) 
//{
//    printf("%zu\n", sizeof(arr));   // 8，不是 40！
//}