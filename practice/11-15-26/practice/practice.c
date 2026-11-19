#include <stdio.h>

//arr[i]=*(arr+i)
//int main(void)
//{
//    char* c[] = { "ENYER", "new", "piont", "first" };
//    char** cp[] = { c + 3, c + 2, c + 1, c };
//    char*** cpp = cp;
//
//    char* a1 = **++cpp;            /* "new"  */
//    char* a2 = *(--*(++cpp)) + 3;  /* "new"+3 -> "" */
//    char* a3 = *cpp[-2] + 3;       /* "first"+3 -> "st" 
//    char* a4 = cpp[-1][-1] + 1;    /* "ENYER"+1 -> "NYER"
//    printf("%s %s %s %s\n", a1, a2, a3, a4);
//    return 0;
//}
// 
//最大公约数，辗转相除法
//void fun(int a, int b)
//{
//	int c = 1;
//	if (b > a)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
//	while (c > 0)
//	{
//		c = a % b;
//		if (c > 0)
//		{
//			a = b;
//			b = c;
//		}
//		else break;
//	} 
//
//	printf("%d", b);
//}
//int main()
//{
//	int a, b;
//	scanf_s("%d %d", &a, &b);
//	fun(a,b);
//	return 1;
//}

//猜数字游戏
