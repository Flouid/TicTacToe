//
// Created by Louis Keith on 3/9/21.
//

#ifndef TICTACTOEAI_GAMESTATE_H
#define TICTACTOEAI_GAMESTATE_H

#include <iostream>
#include <vector>

class GameState
{
public:
    friend std::ostream & operator<<(std::ostream &out, const GameState &state);

    GameState();

private:
    std::vector<std::vector<char>> board;
};

#endif //TICTACTOEAI_GAMESTATE_H
