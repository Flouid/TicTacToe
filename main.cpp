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

int main()
{
    char x_or_o = get_x_or_o();
    string user_input;

    int row;
    int col;

    GameState state;
    cout << state;
    while (true) {
        cout << "Make a move in the form of \"row, col\": ";
        getline(cin, user_input);
        stringstream raw(user_input);
        raw >> row;
        raw.ignore(); // the ',' character
        raw >> col;
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            continue;
        }
        state.make_move(row, col, x_or_o);
        cout << state;
    }

    return 0;
}
