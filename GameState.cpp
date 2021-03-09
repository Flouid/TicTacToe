//
// Created by Louis Keith on 3/9/21.
//

#include "GameState.h"

/**
 * Output operator to make printing the game state easy.
 *
 * @param out for chaining functionality
 * @param state game state to output
 * @return out for chaining functionality
 */
std::ostream & operator<<(std::ostream &out, const GameState &state)
{
    printf("+---+---+---+---+\n");
    printf("|   | 1 | 2 | 3 |\n");
    printf("+---+---+---+---+\n");
    for (int row = 0; row < 3; ++row) {
        printf("| %d | %c | %c | %c |\n", row + 1, state.board[row][0], state.board[row][1], state.board[row][2]);
        printf("+---+---+---+---+\n");
    }
    return out;
}

/**
 * Default constructor initializes the game state to an empty board.
 */
GameState::GameState()
{
    board = {{' ', ' ', ' '},
             {' ', ' ', ' '},
             {' ', ' ', ' '}};
}

/**
 * Takes a set of parameters representing which row and column the user wishes to input
 * and a character to make the move with and makes that move.
 *
 * @param row integer representing the row designator
 * @param col integer representing the column designator
 */
void GameState::make_move(int row, int col, char player_choice)
{
    board[row - 1][col - 1] = player_choice;
}