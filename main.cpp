#include "GameState.h"
#include <sstream>

using namespace std;

/**
 * Gets the user's choice of playing 'X' or 'O'
 *
 * @return character representing which character the user wishes to play as
 */
char get_x_or_o()
{
    char choice;
    string user_input;

    while (true) {
        cout << "Play X or O?: ";
        getline(cin, user_input);
        stringstream raw(user_input);
        raw >> choice;
        if (choice == 'X' || choice == 'O')
            return choice;
    }
}

/**
 * Gets a valid move from the user and returns it.
 *
 * @param state game state in order to check that the move is valid
 * @return pair of integers representing the row and column to put a move
 */
pair<int, int> get_move(const GameState &state)
{
    string user_input;
    int row;
    int col;

    while (true) {
        cout << "Make a move in the form of \"row, col\": ";
        getline(cin, user_input);
        stringstream raw(user_input);
        raw >> row;
        raw.ignore(); // the ',' character
        raw >> col;
        if (state.is_valid_move(row, col))
            return {row, col};
    }
}

/**
 * Main game driver code.
 *
 * @return exit code
 */
int main()
{
    // get the user's choice of character
    char x_or_o = get_x_or_o();

    // initialize game state
    GameState state;
    cout << state;

    // core gameplay loop
    while (!state.has_won(x_or_o)) {
        pair<int, int> move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), x_or_o);
        cout << state;
    }


    return 0;
}
