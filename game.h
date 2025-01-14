#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//头文件
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//定义宏
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

//菜单
void menu();

//定义函数
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//设置地雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//查找地雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);