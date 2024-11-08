#include <iostream>
#include <vector>
using namespace std;

bool checkForWinner(vector<vector<char>> &board, char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

void printBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    string user1, user2;
    char ip1, ip2;

    cout << "Enter User 1 name: ";
    cin >> user1;
    cout << "Enter User 1 sign (x/o): ";
    cin >> ip1;
    while (ip1 != 'x' && ip1 != 'o')
    {
        cout << "Invalid sign. Please enter 'x' or 'o': ";
        cin >> ip1;
    }

    cout << "Enter User 2 name: ";
    cin >> user2;
    ip2 = (ip1 == 'x') ? 'o' : 'x'; // Automatically assign the other sign to user2
    cout << user2 << "'s sign is " << ip2 << endl;

    int turn = 1, n;
    cout << "Starting game...\n";

    while (turn <= 9)
    {
        string currentUser = (turn % 2 != 0) ? user1 : user2;
        char currentSign = (turn % 2 != 0) ? ip1 : ip2;

        cout << currentUser << "'s turn. Enter position (1-9): ";
        cin >> n;
        while (n < 1 || n > 9 || board[(n - 1) / 3][(n - 1) % 3] != ' ')
        {
            cout << "Invalid position. Enter a valid position (1-9): ";
            cin >> n;
        }

        board[(n - 1) / 3][(n - 1) % 3] = currentSign;
        printBoard(board);

        if (checkForWinner(board, currentSign))
        {
            cout << "Winner is " << currentUser << " (" << currentSign << ")!\n";
            return 0;
        }
        turn++;
    }

    cout << "It's a draw!\n";
    return 0;
}
