#include"Board.h"


//����� �� ���� x o -
void draw_board(enum CELL board[3][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == x)
				printf("%c", 'x');
			else if (board[i][j] == o)
					printf("%c", 'o');
			else
					printf("%c", '-');
		}
		printf("\n");
	}
}

//���� �� �����
void clean_board(enum CELL board[3][3]) {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = empty;
		}
	}
}

//���� �� ��� �����
void set_cell(enum CELL board[3][3], uint8_t row_index,
	uint8_t column_index, enum CELL value) {

	board[row_index][column_index] = value;
}

//���� �� ��� ����
enum CELL get_cell(enum CELL board[3][3], uint8_t row_index,
	uint8_t column_index) {

	return board[row_index][column_index];
}

//����� �� ����� �����
enum CELL who_wins_at_row(enum CELL board[3][3], uint8_t row_index) {

	for (int i = 0; i < 2; i++) {
		if (board[row_index][i] != board[row_index][i + 1])
			return empty;
	}
	return board[row_index][0];
}

//����� �� ����� ����
enum CELL who_wins_at_column(enum CELL board[3][3], uint8_t col_index) {
	for (int i = 0; i < 2; i++) {
		if (board[i][col_index] != board[i + 1][col_index])
			return empty;
	}
	return board[0][col_index];
}

//����� �� ����� ������� ����
enum CELL who_wins_at_diagonal_left(enum CELL board[3][3]) {

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (board[i][j] != board[i + 1][j + 1])
				return empty;
		}
	}
	return board[0][0];
}

//����� �� ����� ������� �����
enum CELL who_wins_at_diagonal_right(enum CELL board[3][3]) {

	for (int i = 0; i < 2; i++) {
		for (int j = 2; j < 0; j++) {
			if (board[i][j] != board[i + 1][j - 1])
				return empty;
		}
	}
	return board[2][0];
}








