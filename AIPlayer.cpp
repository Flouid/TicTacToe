//
// Created by Louis Keith on 3/9/21.
//

#include "AIPlayer.h"

std::pair<int, int> AIPlayer::calculate_next_move(const GameState &state) const
{
    std::pair<int, int> move;
    std::pair<int, int> default_move(-1, -1);
    // attempts to find a winning move
    move = attempt_win(state);
    if (move != default_move)
        return move;
    // attempts to find a blocking move
    move = attempt_block(state);
    if (move != default_move)
        return move;
    // attempts to fork
    move = attempt_fork(state);
    if (move != default_move)
        return move;




    return make_random_move(state);
}

std::pair<int, int> AIPlayer::make_random_move(const GameState &state) const
{
    int row;
    int col;
    while (true) {
        row = rand() % 3 + 1;
        col = rand() % 3 + 1;
        if (state.is_valid_move(row, col)) {
            return {row, col};
        }
    }
}


/**
 * Checks if there is a winning move and returns it.
 * Returns {-1, -1} if no winning move was found.
 *
 * @param state gamestate to look for a winning move in
 * @return winning move or {-1, -1}
 */
std::pair<int, int> AIPlayer::attempt_win(const GameState &state) const
{
    int player_count;
    int empty_count;
    int row;
    int col;
    std::pair<int, int> move;

    // checks if there are any opportunities to win on rows
    for (row = 0; row < 3; ++row) {
        player_count = 0;
        empty_count = 0;
        for (col = 0; col < 3; ++col) {
            player_count += state.get_board()[row][col] == player;
            if (state.get_board()[row][col] == ' ') {
                ++empty_count;
                move = {row + 1, col + 1};
            }
        }
        if (player_count == 2 && empty_count == 1) {
            return move;
        }
    }
    // checks if there are any opportunities to win on columns
    for (col = 0; col < 3; ++col) {
        player_count = 0;
        empty_count = 0;
        for (row = 0; row < 3; ++row) {
            player_count += state.get_board()[row][col] == player;
            if (state.get_board()[row][col] == ' ') {
                ++empty_count;
                move = {row + 1, col + 1};
            }
        }
        if (player_count == 2 && empty_count == 1) {
            return move;
        }
    }
    // checks if there are any opportunities to win on diagonals
    // left diagonal
    player_count = 0;
    empty_count = 0;
    row = 0;
    col = 0;
    while (row < 3 && col < 3) {
        player_count += state.get_board()[row][col] == player;
        if (state.get_board()[row][col] == ' ') {
            ++empty_count;
            move = {row + 1, col + 1};
        }
        ++row;
        ++col;
    }
    if (player_count == 2 && empty_count == 1)
        return move;
    // right diagonal
    player_count = 0;
    empty_count = 0;
    row = 0;
    col = 2;
    while (row < 3 && col >= 0) {
        player_count += state.get_board()[row][col] == player;
        if (state.get_board()[row][col] == ' ') {
            ++empty_count;
            move = {row + 1, col + 1};
        }
        ++row;
        --col;
    }
    if (player_count == 2 && empty_count == 1)
        return move;

    // if no winning move was found, return default case
    return {-1, -1};
}

/**
 * Checks if there is a move that will block the opponent from winning and returns it.
 * Returns {-1, -1} if there is no such move.
 *
 * @param state game state to look for a blocking move in
 * @return blocking move or {-1, -1}
 */
std::pair<int, int> AIPlayer::attempt_block(const GameState &state) const
{
    char user;
    if (player == 'X')
        user = 'O';
    else
        user = 'X';

    int player_count;
    int empty_count;
    int row;
    int col;
    std::pair<int, int> move;

    // checks if there are any opportunities to win on rows
    for (row = 0; row < 3; ++row) {
        player_count = 0;
        empty_count = 0;
        for (col = 0; col < 3; ++col) {
            player_count += state.get_board()[row][col] == user;
            if (state.get_board()[row][col] == ' ') {
                ++empty_count;
                move = {row + 1, col + 1};
            }
        }
        if (player_count == 2 && empty_count == 1) {
            return move;
        }
    }
    // checks if there are any opportunities to win on columns
    for (col = 0; col < 3; ++col) {
        player_count = 0;
        empty_count = 0;
        for (row = 0; row < 3; ++row) {
            player_count += state.get_board()[row][col] == user;
            if (state.get_board()[row][col] == ' ') {
                ++empty_count;
                move = {row + 1, col + 1};
            }
        }
        if (player_count == 2 && empty_count == 1) {
            return move;
        }
    }
    // checks if there are any opportunities to win on diagonals
    // left diagonal
    player_count = 0;
    empty_count = 0;
    row = 0;
    col = 0;
    while (row < 3 && col < 3) {
        player_count += state.get_board()[row][col] == user;
        if (state.get_board()[row][col] == ' ') {
            ++empty_count;
            move = {row + 1, col + 1};
        }
        ++row;
        ++col;
    }
    if (player_count == 2 && empty_count == 1)
        return move;
    // right diagonal
    player_count = 0;
    empty_count = 0;
    row = 0;
    col = 2;
    while (row < 3 && col >= 0) {
        player_count += state.get_board()[row][col] == user;
        if (state.get_board()[row][col] == ' ') {
            ++empty_count;
            move = {row + 1, col + 1};
        }
        ++row;
        --col;
    }
    if (player_count == 2 && empty_count == 1)
        return move;

    // if no blocking move was found, return default case
    return {-1, -1};
}

/**
 * Attempt to to find a move that forks the user.
 * Returns {-1, -1} if there is no such move.
 *
 * @param state game state to look for a forking move in
 * @return forking move or {-1, -1}
 */
std::pair<int, int> AIPlayer::attempt_fork(const GameState &state) const
{
    bool adj_ai_tile;
    bool adj_empty_tile;
    // iterate over every tile in the board
    for(int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int contributing_lines = 0;
            // checks if the current tile is empty...
            if (state.get_board()[row][col] == ' ') {
                // checks if the current row contributes to a fork
                adj_ai_tile = false;
                adj_empty_tile = false;
                for (int i = 1; i < 3; ++i) {
                    if (state.get_board()[(row + i) % 3][col] == player)
                        adj_ai_tile = true;
                    if (state.get_board()[(row + i) % 3][col] == ' ')
                        adj_empty_tile = true;
                }
                contributing_lines += (adj_ai_tile && adj_empty_tile);
                // checks if the current column contributes to a fork
                adj_ai_tile = false;
                adj_empty_tile = false;
                for (int i = 1; i < 3; ++i) {
                    if (state.get_board()[row][(col + i) % 3] == player)
                        adj_ai_tile = true;
                    if (state.get_board()[row][(col + i) % 3] == ' ')
                        adj_empty_tile = true;
                }
                contributing_lines += (adj_ai_tile && adj_empty_tile);
                // checks if the left diagonal can be a contributing line
                adj_ai_tile = false;
                adj_empty_tile = false;
                if (row == 0 && col == 0) {
                    for (int i = 1; i < 3; ++i) {
                        if (state.get_board()[i][i] == player)
                            adj_ai_tile = true;
                        if (state.get_board()[i][i] == ' ')
                            adj_empty_tile = true;
                    }
                }
                contributing_lines += (adj_ai_tile && adj_empty_tile);
                // checks if the right diagonal can be a contributing line
                adj_ai_tile = false;
                adj_empty_tile = false;
                if (row == 0 && col == 2) {
                    for (int i = 1; i < 3; ++i) {
                        if (state.get_board()[i][2 - i] == player)
                            adj_ai_tile = true;
                        if (state.get_board()[i][2 - i] == ' ')
                            adj_empty_tile = true;
                    }
                }
                contributing_lines += (adj_ai_tile && adj_empty_tile);
            }
            if (contributing_lines > 1)
                return {row, col};
        }
    }
    return {-1, -1};
}