#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_MINE 10

//game.c 按 C 编译，text.cpp 按 C++ 编译；
//用 extern "C" 保证 C++ 侧按 C 规则链接这些函数
#ifdef __cplusplus
extern "C" {
#endif

void IntBoard(char board[ROWS][COLS], int row, int col, int set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char mine[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

#ifdef __cplusplus
}
#endif

#endif // GAME_H
