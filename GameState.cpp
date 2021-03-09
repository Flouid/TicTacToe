//
// Created by Louis Keith on 3/9/21.
//

#include "GameState.h"

std::ostream & operator<<(std::ostream &out, const GameState &state)
{
    printf("+-----+-----+-----+\n");
    for (int row = 0; row < 3; ++row) {
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", state.board[row][0], state.board[row][1], state.board[row][2]);
        printf("|     |     |     |\n");
        printf("+-----+-----+-----+\n");
    }
    return out;
}

GameState::GameState()
{
    board = {{' ', ' ', ' '},
             {' ', ' ', ' '},
             {' ', ' ', ' '}};
}