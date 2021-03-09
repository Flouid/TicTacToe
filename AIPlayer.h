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

    std::pair<int, int> calculate_next_move(const GameState &state) const;

    char get_player() const { return player; }

private:
    std::pair<int, int> make_random_move(const GameState &state) const;
    std::pair<int, int> attempt_win(const GameState &state) const;

    char player;
};

#endif //TICTACTOEAI_AIPLAYER_H
