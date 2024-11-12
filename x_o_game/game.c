#include <stdio.h>
#include "board.h"
#include <stdint.h>
#include <stdbool.h>
#pragma warning(disable : 4996)

main()
{
    uint8_t row_index, col_index;
    enum CELL board[3][3];
    bool should_exit = false;
    bool game_over;
    bool is_x_turn;
    int value;
    int count;

    while (!should_exit) {
        // Start a new game
        game_over = false;
        is_x_turn = true;
        clean_board(board);
        count = 0;

        // Game loop
        while (!game_over) {
            draw_board(board);
            if (count == 9) {
                game_over = true;
                printf("Game Over! It's a tie!\n");
                continue;
            }

            printf("Enter row (0-2): ");
            scanf("%d", &row_index);
            printf("Enter column (0-2): ");
            scanf("%d", &col_index);

            if (row_index < 0 || col_index < 0) {
                game_over = true;
                should_exit = true;
                continue;
            }

            if (row_index > 2 || col_index > 2 || get_cell(board, row_index, col_index) != empty) {
                printf("Invalid move! Try again.\n");
                continue;
            }

            // Set the current player's move
            if (is_x_turn) {
                value = x;
                is_x_turn = false;
            }
            else {
                value = o;
                is_x_turn = true;
            }

            set_cell(board, row_index, col_index, value);

            // Check for a winner
            if (who_wins_at_row(board, row_index) != empty) {
                printf("Player %d wins! Congratulations!\n", who_wins_at_row(board, row_index));
                game_over = true;
            }

            if (who_wins_at_column(board, col_index) != empty) {
                printf("Player %d wins! Congratulations!\n", who_wins_at_column(board, col_index));
                game_over = true;
            }

            if (who_wins_at_diagonal_right(board) != empty) {
                printf("Player %d wins! Congratulations!\n", who_wins_at_diagonal_right(board));
                game_over = true;
            }

            if (who_wins_at_diagonal_left(board) != empty) {
                printf("Player %d wins! Congratulations!\n", who_wins_at_diagonal_left(board));
                game_over = true;
            }

            count++;
            printf("Moves count: %d\n", count);
        }

        // Ask to play again or exit
        char play_again;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);  // Notice the space before %c to consume any leftover newline character
        if (play_again != 'y' && play_again != 'Y') {
            should_exit = true;
        }
    }
}
