#include "AIPlayer.h"
#include <sstream>

using namespace std;

/**
 * Gets the user's choice of playing 'X' or 'O'
 * Infinitely repeats until a valid choice is given.
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
 * Infinitely repeats until a valid move is given.
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
 * Driver code to run a game with two human players.
 * The first selects which character they'd like to use, the second gets the other one.
 * Proceeds until a draw or a player wins.
 */
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
    string status;
    while (true) {
        // player 1's turn
        move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), player1);
        cout << state;
        status = state.get_status();
        if (status == "draw") {
            cout << "The game is a draw!\n";
            return;
        }
        else if (status != "ongoing") {
            printf("Player 1 won with %c!\n", player1);
            return;
        }

        // player 2's turn
        move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), player2);
        cout << state;
        status = state.get_status();
        if (status == "draw") {
            cout << "The game is a draw!\n";
            return;
        }
        else if (status != "ongoing") {
            printf("Player 2 won with %c!\n", player2);
            return;
        }
    }
}

/**
 * Driver code to run a game with a human player against an AI opponent.
 * The human selects which character they would like to use and the ai gets the other.
 * Proceeds until the AI wins or draws.
 */
void ai_opponent()
{
    // get player character
    char player = get_x_or_o();
    AIPlayer opponent;
    if (player == 'X')
        opponent = AIPlayer('O');
    else
        opponent = AIPlayer('X');

    // initialize the game state
    GameState state;
    cout << state;

    pair<int, int> move;
    string status;
    while (true) {
        // player 1's turn
        move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), player);
        status = state.get_status();
        if (status == "draw") {
            cout << state;
            cout << "The game is a draw!\n";
            return;
        }
        else if (status != "ongoing") {
            cout << state;
            printf("Player 1 won with %c!\n", player);
            return;
        }

        // ai player's turn
        move = opponent.calculate_next_move(state);
        state.make_move(get<0>(move), get<1>(move), opponent.get_player());
        cout << state;
        status = state.get_status();
        if (status == "draw") {
            cout << "The game is a draw!\n";
            return;
        }
        else if (status != "ongoing") {
            printf("Opponent won with %c!\n", opponent.get_player());
            return;
        }
    }
}

/**
 * Get's the user's choice of mode.
 * Infinitely repeats the prompt until a valid input is given.
 *
 * @return int representing choice of mode
 */
int get_mode()
{
    int choice;
    string user_input;

    while (true) {
        cout << "Which mode would you like to play in?\n";
        cout << "\t[1] Two player\n";
        cout << "\t[2] AI opponent\n";
        cout << "(1/2): ";
        getline(cin, user_input);
        stringstream raw(user_input);
        raw >> choice;
        if (choice == 1 || choice == 2) {
            return choice;
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
    int mode = get_mode();
    if (mode == 1)
        two_player();
    else
        ai_opponent();
    return 0;
}
