//
// Created by Louis Keith on 3/9/21.
//

#ifndef TICTACTOEAI_GAMESTATE_H
#define TICTACTOEAI_GAMESTATE_H

#include <iostream>
#include <vector>

/**
 * Data type to represent the game state on a given turn.
 * Internally stores a 2D vector of characters with values ' ', 'X', or 'O'.
 */
class GameState
{
public:
    friend std::ostream & operator<<(std::ostream &out, const GameState &state);

    GameState();

    void make_move(int row, int col, char player);
    bool is_valid_move(int row, int col) const;
    std::string get_status() const;
    std::vector<std::vector<char>> get_board() const { return board; }

private:
    std::vector<std::vector<char>> board;
};

#endif //TICTACTOEAI_GAMESTATE_H
