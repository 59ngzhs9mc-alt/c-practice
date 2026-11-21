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

