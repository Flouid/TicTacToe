//
// Created by Louis Keith on 3/9/21.
//

#include "AIPlayer.h"

std::pair<int, int> AIPlayer::calculate_next_move(const GameState &state) const
{
    std::pair<int, int> move;
    move = attempt_win(state);
    if (move != std::pair<int, int>(-1, -1))
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
 * @return move winning move or {-1, -1}
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

    // if now winning move was found, return default case
    return {-1, -1};
}
