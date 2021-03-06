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
    explicit AIPlayer(char p);

    std::pair<int, int> calculate_next_move(const GameState &state) const;

    char get_player() const { return player; }

private:
    std::pair<int, int> attempt_win(const GameState &state) const;
    std::pair<int, int> attempt_block(const GameState &state) const;
    std::pair<int, int> attempt_fork(const GameState &state) const;
    std::pair<int, int> attempt_block_fork(const GameState &state) const;
    std::pair<int, int> attempt_corner(const GameState &state) const;
    static std::pair<int, int> take_empty_corner(const GameState &state);
    static std::pair<int, int> take_empty_side(const GameState &state);

    char player;
    char user;
};

#endif //TICTACTOEAI_AIPLAYER_H
