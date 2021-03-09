//
// Created by Louis Keith on 3/9/21.
//

#ifndef TICTACTOEAI_AIPLAYER_H
#define TICTACTOEAI_AIPLAYER_H

#include "GameState.h"

class AIPlayer
{
public:
    AIPlayer(char p) : player(p) {}

private:
    char player;
};

#endif //TICTACTOEAI_AIPLAYER_H
