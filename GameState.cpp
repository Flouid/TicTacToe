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
void GameState::make_move(int row, int col, char player)
{
    board[row - 1][col - 1] = player;
}

/**
 * Takes a set of parameters representing which row and column the user wishes to input.
 * Returns whether or not that set of parameters constitutes a valid move.
 * The move is only valid if the space selected is not already occupied and the parameters correspond
 * to spaces on the board.
 *
 * @param row integer representing the row designator
 * @param col integer representing the column designator
 * @return bool representing validity of move
 */
bool GameState::is_valid_move(int row, int col) const
{
    if (row < 1 || row > 3 || col < 1 || col > 3) {
        return false;
    }
    return board[row - 1][col - 1] == ' ';
}

bool GameState::has_won(char player) const
{
    // checks for any winning rows
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
            return true;
    }
    // checks for any winning columns
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
            return true;
    }
    // checks for winning diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    // default case
    return false;
}