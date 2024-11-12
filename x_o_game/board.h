#pragma once
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

//האפשרויות שהתאים יכולים להיות

enum CELL
{
	x,
	o,
	empty,
};


//board.cקריאה לפונקציות מ 
void draw_board(enum CELL board[3][3]);
void clean_board(enum CELL board[3][3]);
void set_cell(enum CELL board[3][3], uint8_t row_index,
    uint8_t column_index, enum CELL value);
enum CELL get_cell(enum CELL board[3][3], uint8_t row_index,
    uint8_t column_index);
enum CELL who_wins_at_row(enum CELL board[3][3], uint8_t row_index);
enum CELL who_wins_at_column(enum CELL board[3][3], uint8_t col_index);
enum CELL who_wins_at_diagonal_left(enum CELL board[3][3]);
enum CELL who_wins_at_diagonal_right(enum CELL board[3][3]);











