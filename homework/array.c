// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的X形图案。
// 多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
// 针对每行输入，输出用“*”组成的X形图案。

#include <stdio.h>

// int main()
// {
//     int n;
//     while (scanf("%d", &n) != EOF)
//     {      // 多组输入：一直读到文件结束
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (i == j || i + j == n - 1)
//                     printf("*");
//                 else
//                     printf(" ");
//             }
//             printf("\n");                 // 每行结束换行
//         }
//     }
//     return 0;
// }

// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的“空心”正方形图案。
// 多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“*”的数量。
// 针对每行输入，输出用“*”组成的“空心”正方形，每个“*”后面有一个空格。

// int main()

// {
//     int a = 0;

//     while (scanf("%d", &a) != EOF)
//     {
//         for (int i = 0; i < a; i++)
//         {
//             for (int j = 0; j < a; j++)
//             {
//                 if ((i>0 && i<(a-1) && j >0 && j<(a-1)))
//                 {
//                     printf("  ");
//                 }
//                 else
//                 {
//                     printf("* ");
//                 }
//             }
//         printf("\n");
//         }
//     }
//     return 0;
// }

// 转置矩阵
// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     int arr[20][20] = {0};
//     int c = a * b;

//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < b; j++)
//         {
//             int d;
//             scanf("%d", &d);
//             arr[i][j] = d;
//         }
//     }

//     //实现转置
//     for(int i=0;i<b;i++)
//     {
//         for(int j=0;j<a;j++)
//         {
//             printf("%d",arr[j][i]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

// 逆序输出：按照输入相反的顺序（越晚输入的越早输出）进行输出。
//  int main()
//  {
//      int a=0;
//      int arr[10]={0};

//     for(int i=0;i<10;i++)
//     {
//         scanf("%d",&a);
//         arr[i] = a;
//     }
//     for(int j=9;j>=0;j--)
//     {
//         printf("%d ",arr[j]);
//     }

//     return 0;
// }

// 输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     int c = a + b;

//     int arr1[1000] = {0};
//     int arr2[1000] = {0};
//     int arr3[2000] = {0};

//     int x = 0;
//     int i = 0;
//     while (i < a)
//     {
//         scanf("%d", &x);
//         arr1[i] = x;
//         arr3[i] = arr1[i];
//         i++;
//     }

//     int y = 0;
//     for (int j = 0; j < b; j++)
//     {
//         scanf("%d", &y);
//         arr2[j] = y;
//         arr3[i + j] = arr2[j];
//     }

//     for (int n = 0; n < c; n++)
//     {
//         for (int m = 0; m < (c-1); m++)
//         {
//             if (arr3[m] > arr3[m + 1])
//             {
//                 int temp = arr3[m];
//                 arr3[m] = arr3[m + 1];
//                 arr3[m + 1] = temp;
//             }
//         }
//     }

//     for (int i = 0; i < c; i++)
//     {
//         printf("%d ", arr3[i]);
//     }

//     return 0;
// }

// 编写一个程序，从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。
// int main()
// {
//     int i = 0;
//     int x = 0;
//     int arr[10] = {0};

//     while (i < 10)
//     {
//         scanf("%d", &x);
//         arr[i] = x;
//         i++;
//     }

//     int c = 0;
//     for (int j = 0; j < 10; j++)
//     {
//         c += arr[j];
//     }
//     float j= (float) c/10;

//     printf("%f", j);
//     return 0;
// }

#include <stdlib.h>
#include <time.h>

// 将数组A中的内容和数组B中的内容进行交换。（数组一样大）
// int main()
// {
//     srand((unsigned int)time(NULL));
//     int arr1[10] = {0};
//     int arr2[10] = {0};
//     // 给两个数组赋值
//     for (int i = 0; i < 10; i++)
//     {
//         arr1[i] = rand() % 100;
//         arr2[i] = rand() % 100;
//     }

//     // 打印初始数组
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%2d ", arr1[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%2d ", arr2[i]);
//     }
//     int arr3[10] = {0};

//     // 交换数值
//     for (int i = 0; i < 10; i++)
//     {
//         arr3[i] = arr2[i];
//         arr2[i] = arr1[i];
//         arr1[i] = arr3[i];
//     }

//     // 打印交换后的数组
//     printf("\n");
//     printf("\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%2d ", arr1[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < 10; i++)
//     {
//         printf("%2d ", arr2[i]);
//     }

//     return 0;
// }

// 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
// 如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。

// void fun(int a)
// {
//     for (int i = 1; i <= a; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             printf("%2d*%-2d=%2d  ", j, i, i * j);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int a = 0;
//     scanf("%d", &a);
//     fun(a);

//     return 0;
// }

// 实现一个函数is_prime，判断一个数是不是素数。
// 利用上面实现的is_prime函数，打印100到200之间的素数。
// void is_prime(int a)
// {
//     for (int i = 2; i < a; i++)
//     {
//         if (a != 2)
//         {
//             int b = 0;
//             b = a % i;
//             if (b == 0)
//             {
//                 return;
//             }
//         }
//         else
//         {
//             printf("2是素数");
//         }
//     }
//     printf("%d是素数\n", a);
// }

// void fun()
// {
//     for(int i=100;i<=200;i++)
//     {
//         is_prime(i);
//     }
// }

// int main()
// {
//     int a = 0;
//     scanf("%d", &a);
//     is_prime(a);
//     fun();

//     return 0;
// }

// 创建一个整形数组，完成对数组的操作
//  1.实现函数init() 初始化数组为全0
//  2.实现print()  打印数组的每个元素
//  3.实现reverse()  函数完成数组元素的逆置。
//  要求：自己设计以上函数的参数，返回值。

// void init(int *p)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         p = 0;
//         printf("%2d ", p);
//     }
//     printf("\n");
// }
// void print(int *p)
// {
//     for(int i=0;i<10;i++)
//     {
//         printf("%2d ",*(p+i));
//     }
//     printf("\n");
// }

// void reverse(int *p)
// {
//     int arr1[10]={0};
//     for(int i=0;i<10;i++)
//     {
//         arr1[i]= *(p+(9-i));
//         printf("%2d ",arr1[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     srand((unsigned int)time(NULL));
//     int arr[10] = {0};

//     for (int i = 0; i < 10; i++)
//     {
//         arr[i] = rand() % 100;
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // 1.实现函数init() 初始化数组为全0
//     init(arr);

//     // 2.实现print()  打印数组的每个元素
//     print(arr);

//     // 3.实现reverse()  函数完成数组元素的逆置。
//     reverse(arr);

//     return 0;
// }

// 写一个二分查找函数
// 功能：在一个升序数组中查找指定的数值，找到了就返回下标，找不到就返回-1.

// void fun(int arr1[], int a,  int left, int right)
// {
//     while(left <= right)
//     {
//         int mid=left + (right -left)/2;

//         if(a>arr1[mid])
//         {
//             left=mid+1;
//         }
//         if(a<arr1[mid])
//         {
//             right=mid -1;
//         }
//         if(a == arr1[mid])
//         {
//             printf("%d %d",arr1[mid],mid);
//             break;
//         }
//     }
// }
// int main()
// {
//     int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//     int a = 0;
//     scanf("%d", &a);

//     int left = 0;
//     int right = 9;

//    fun(arr, a, left, right);

//     return 0;
// }

// 实现函数判断year是不是润年。
// int main()
// {
//     int year = 0;
//     int i=10;
//     while (i)
//     {
//         scanf("%d", &year);
//         int a=(year % 1000);
//         int b=(year % 4);
//         int c=(year % 400);

//         if (c==0 ||(a==0 && b==0))
//         {
//             printf("%d是闰年。\n", year);
//         }
//         else
//         {
//             printf("%d不是闰年。\n", year);
//         }
//         i--;
//     }

//     return 0;
// }

// 给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，
// 数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求
// ans[i] == nums[i]
// ans[i + n] == nums[i]
// 具体而言，ans 由两个 nums 数组 串联 形成。
// 返回数组 ans 。
// int *getConcatenation(int *nums, int numsSize, int *returnSize)
// {
//     int n = numsSize;
//     int *ans = (int *)malloc(sizeof(int) * 2 * n);

//     if (ans == NULL)
//     {
//         *returnSize = 0;
//         return NULL;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = nums[i];
//         ans[i + n] = nums[i];
//     }

//     *returnSize = 2 * n;
//     return ans;
// }

// int main(void)
// {
//     int n;
//     scanf("%d", &n);

//     int *nums = (int *)malloc(sizeof(int) * n);

//     if (nums == NULL)
//     {
//         printf("内存分配失败\n");
//         return 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (scanf("%d", &nums[i]) != 1)
//         {
//             printf("输入错误：第 %d 个数没读到\n", i + 1);
//             free(nums);
//             return 1;
//         }
//     }

//     int size = 0;
//     int *ans = getConcatenation(nums, n, &size);
//     if (ans == NULL)
//     {
//         printf("内存分配失败\n");
//         free(nums);
//         return 1;
//     }

//     printf("ans = [");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%s%d", i ? ", " : "", ans[i]);
//     }
//     printf("]\nreturnSize = %d\n", size);

//     free(ans);
//     free(nums);
//     return 0;
// }

// 练习使用动态内存相关的4个函数，并调试观察。
// malloc、calloc、realloc、free

// static void show(const char *tag, const int *p, int n)
// {
//     printf("%-14s地址 %p  内容:", tag, (const void *)p);
//     for (int i = 0; i < n; i++)
//     {
//         printf(" %d", p[i]);
//     }
//     printf("\n");
// }

// int main(void)
// {
//     /* ---------- 1. malloc：分配但不初始化 ---------- */
//     printf("=== 1. mallo;分配但不初始化 ===\n");
//     int *dirty = (int *)malloc(5 * sizeof(int));
//     if (dirty == NULL)
//         return 1;
//     for (int i = 0; i < 5; i++)
//         dirty[i] = 111 * (i + 1);
//     show("写脏后", dirty, 5);
//     free(dirty);

//     int *p = (int *)malloc(5 * sizeof(int));
//     if (p == NULL)
//         return 1;
//     show("malloc 后", p, 5); /* 断点 A */

//     for (int i = 0; i < 5; i++)
//         p[i] = i * 10;

//     /* ---------- 2. calloc：分配并清零 ---------- */
//     printf("\n=== 2. calloc：分配并清零 ===\n");
//     int *q = (int *)calloc(5, sizeof(int));
//     if (q == NULL)
//     {
//         free(p);
//         return 1;
//     }
//     show("calloc 后", q, 5); /* 断点 B */
//     for (int i = 0; i < 5; i++)
//         q[i] = 100 + i;
//     show("手动赋值后", q, 5);

//     /* ---------- 3. realloc：扩容 ---------- */
//     printf("\n=== 3. realloc：扩容 ===\n");
//     printf("扩容前 p = %p\n", (void *)p);
//     int *r = (int *)realloc(p, 10 * sizeof(int));
//     if (r == NULL)
//     {
//         printf("realloc 失败，原内存未动\n");
//         free(p);
//         free(q);
//         return 1;
//     }
//     int moved = (r != p); /* 先判断有没有搬家，再覆盖指针 */
//     p = r;
//     printf("扩容后 p = %p  %s\n", (void *)p,
//            moved ? "因为原地放不下，整块搬到了新地址" : "原地扩展，地址没变");
//     show("前 5 个", p, 5); /* 断点 C */
//     printf("后 5 个: ");
//     for (int i = 5; i < 10; i++)
//         printf(" %d", p[i]);
//     printf("   <- 新区域未初始化，值不确定\n");
//     for (int i = 5; i < 10; i++)
//         p[i] = i * 10;
//     show("写满 10 个", p, 10);

//     /* ---------- 4. realloc 缩小 & free ---------- */
//     printf("\n=== 4. realloc 缩小，然后 free ===\n");
//     int *s = (int *)realloc(p, 3 * sizeof(int));
//     if (s != NULL)
//         p = s; /* 缩小时也可能搬家 */
//     show("缩小到 3 个", p, 3);

//     free(p);
//     p = NULL;
//     free(q);
//     q = NULL;
//     printf("释放后 p = %p, q = %p (打印的是指针本身) \n", (void *)p, (void *)q);

//     return 0;
// }

// 使用malloc函数模拟开辟一个3*5的整型二维数组，开辟好后，使用二维数组的下标访问形式，访问空间。
// #define ROWS 3
// #define COLS 5

// int main(void)
// {
//     /* 1. 先申请 ROWS 个 int* ，用来装每一行的首地址 */
//     int **a = (int **)malloc(ROWS * sizeof(int *));
//     if (a == NULL)
//     {
//         printf("分配行指针失败\n");
//         return 1;
//     }

//     /* 2. 再为每一行单独申请 COLS 个 int */
//     for (int i = 0; i < ROWS; i++)
//     {
//         a[i] = (int *)malloc(COLS * sizeof(int));
//         if (a[i] == NULL)
//         {
//             printf("分配第 %d 行失败\n", i);
//             for (int k = 0; k < i; k++)
//                 free(a[k]); /* 把已经分配的行还掉 */
//             free(a);
//             return 1;
//         }
//     }

//     /* 3. 用二维下标访问 */
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             a[i][j] = i * 10 + j;
//         }
//     }
//     for (int i = 0; i < ROWS; i++)
//     {
//         for (int j = 0; j < COLS; j++)
//         {
//             printf("%3d", a[i][j]);
//         }
//         printf("\n");
//     }

//     /* 4. 释放：先还每一行，再还行指针数组，顺序不能反 */
//     for (int i = 0; i < ROWS; i++)
//     {
//         free(a[i]);
//     }
//     free(a);

//     return 0;
// }

// 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
// int main(void)
// {
//     int total = 20;      /* 先买 20 瓶 */
//     int empty = 20;      /* 20 个空瓶 */
//     int round = 0;

//     while (empty >= 2)
//     {
//         round++;
//         int new_bottles = empty / 2;      /* 能换几瓶 */
//         int left = empty % 2;             /* 换完还剩几个空瓶 */
//         total += new_bottles;
//         empty = new_bottles + left;       /* 新喝出来的空瓶 */
//     }

//     printf("总共能喝 %d 瓶\n", total);
//     return 0;
// }

// 打印菱形
// int main()
// {
//     int left=6, right =6;
//     char arr[13]={0};

//     for(int i=13;i>0;i--)
//     {
//         arr[i-1]=' ';
//     }

//     for(;left>=0 && right <=12;left--,right++)
//     {
//         arr[left]='*';
//         arr[right]='*';

//         for(int i=13;i>0;i--)
//         printf("%c",arr[i-1]);

//         printf("\n");
//     }

//     for(;left<=right ;left++,right--)
//     {
//         arr[left]=' ';
//         arr[right]=' ';

//         for(int i=13;i>0;i--)
//         printf("%c",arr[i-1]);

//         printf("\n");
//     }

//     return 0;
// }

// 递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
// int fun(int n)
// {
//     if (n < 1)
//         return 1;
//     return n * fun(n - 1);
// }

// void refun(int n)
// {
//     int s = 1;
//     for (; n > 1; n--)
//     {
//         s *= n;
//     }
//     printf("%d\n", s);
// }
// int main()
// {
//     int  n;
//     scanf("%d", &n);
//     refun(n);

//     int b = fun(n);
//     printf("%d", b);

//     return 0;
// }

// 水仙花数

int main()
{
    int a = 153;
    int s;

    for (int i = 0; s >= 0; i++)
    {
        s = a / (1e1);
    }

    printf("%d", a);

    return 0;
}