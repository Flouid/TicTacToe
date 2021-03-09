//
// Created by Louis Keith on 3/9/21.
//

#ifndef TICTACTOEAI_AIPLAYER_H
#define TICTACTOEAI_AIPLAYER_H

#include "GameState.h"

class AIPlayer
{
public:
    AIPlayer() : AIPlayer(' ') {}
    explicit AIPlayer(char p) : player(p) {}

    std::pair<int, int> calculate_next_move(const GameState &state);

    char get_player() { return player; }

private:
    char player;
};

#endif //TICTACTOEAI_AIPLAYER_H
