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

void two_player()
{
    // get player characters
    char player1 = get_x_or_o();
    char player2;
    if (player1 == 'X')
        player2 = 'O';
    else
        player2 = 'X';

    // initialize the game state
    GameState state;
    cout << state;

    // core gameplay loop
    pair<int, int> move;
    while (true) {
        // player 1's turn
        move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), player1);
        cout << state;
        if (state.has_won(player1)) {
            printf("Player 1 has won with %c!\n", player1);
            return;
        }

        // player 2's turn
        move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), player2);
        cout << state;
        if (state.has_won(player2)) {
            printf("Player 2 has won with %c!\n", player2);
            return;
        }
    }
}

/**
 * Main game driver code.
 *
 * @return exit code
 */
int main()
{
    two_player();
    return 0;
}
