#include "GameState.h"
#include <sstream>

using namespace std;

char get_x_or_o()
{
    char choice;

    cout << "Play X or O?: ";
    cin >> choice;
    cin.ignore(); // \n character
    if(choice != 'X' && choice != 'O')
        return get_x_or_o();
    return choice;
}

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

int main()
{
    char x_or_o = get_x_or_o();
    string user_input;

    GameState state;
    cout << state;

    for (int i = 0; i < 10; ++i) {
        pair<int, int> move = get_move(state);
        state.make_move(get<0>(move), get<1>(move), x_or_o);
        cout << state;
    }


    return 0;
}
