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

/**
 * Determines if either player has won the game or if the game has drawn.
 *      If X has won, returns "X"
 *      If O has won, returns "O"
 *      If the game is a draw, returns "draw"
 *      If none of the above, returns "ongoing"
 *
 * @return string representing the status of the game
 */
std::string GameState::get_status() const
{
    // win detection
    // checks if someone won a row
    for (int row = 0; row < 3; ++row) {
        if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][0] == board[row][2])
            return std::string(1, board[row][0]);
    }
    // checks if someone won a column
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[0][col] == board[2][col])
            return std::string(1, board[0][col]);
    }
    // checks if someone won either diagonal
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return std::string(1, board[0][0]);
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return std::string(1, board[0][0]);

    // draw detection
    int x_count;
    int o_count;
    int row;
    int col;
    // counts how many rows have been drawn
    int rows_drawn = 0;
    for (row = 0; row < 3; ++row) {
        x_count = 0;
        o_count = 0;
        for (col = 0; col < 3; ++col) {
            x_count += board[row][col] == 'X';
            o_count += board[row][col] == 'O';
        }
        rows_drawn += x_count > 0 && o_count > 0;
    }
    // counts how many columns have been drawn
    int cols_drawn = 0;
    for (col = 0; col < 3; ++col) {
        x_count = 0;
        o_count = 0;
        for (row = 0; row < 3; ++row) {
            x_count += board[row][col] == 'X';
            o_count += board[row][col] == 'O';
        }
        cols_drawn += x_count > 0 && o_count > 0;
    }

    // checks if the diagonals have been drawn
    // left diagonal
    int diagonals_drawn = 0;
    x_count = 0;
    o_count = 0;
    for (int i = 0; i < 3; ++i) {
        x_count += board[i][i] == 'X';
        o_count += board[i][i] == 'O';
    }
    diagonals_drawn += x_count > 0 && o_count > 0;
    // right diagonal
    x_count = 0;
    o_count = 0;
    for (int i = 0; i < 3; ++i) {
        x_count += board[i][2 - i] == 'X';
        o_count += board[i][2 - i] == 'O';
    }
    diagonals_drawn += x_count > 0 && o_count > 0;
    if (rows_drawn == 3 && cols_drawn == 3 && diagonals_drawn == 2)
        return "draw";

    // default case
    return "ongoing";
}