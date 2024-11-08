#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
bool checkforans(vector<vector<char>> &board)
{
    // if(board[0][0]=='x')
    if ((board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') || (board[1][0] == 'x' && board[1][1] == 'x' && board[1][1] == 'x') || (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') || (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') || (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') || (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') || (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') || (board[0][2] == 'x' || board[1][1] == 'x' || board[2][0] == 'x'))
    {
        cout << "Winner is XXXXXX";
        return true;
    }
    else if ((board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') || (board[1][0] == 'o' && board[1][1] == 'o' && board[1][1] == 'o') || (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') || (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') || (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') || (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') || (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') || (board[0][2] == 'o' || board[1][1] == 'o' || board[2][0] == 'o'))
    {
        cout << "Winner is oooooo";
        return true;
    }
    return false;
}
// int main()
// {
//     vector<vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
//     // for(int)
//     string user1;
//     cout << "Enter User 1 name : ";
//     cin >> user1;
//     cout << "\n Enter user 1 sign : ";
//     char ip1;
//     cin >> ip1;
//     string user2;
//     cout << "Enter User 2 name : ";
//     cin >> user2;
//     cout << "\n Enter user 2 sign : ";
//     char ip2;
//     cin >> ip2;
//     if (ip1 == 'o' || ip1 == 'x' || ip2 == 'o' || ip2 == 'x')
//     {
//         int i = 1;
//         int n;
//         cout << "Starting with " << user2;
//         while (i <= 9)
//         {
//             if (i % 2 == 0)
//             {
//                 cout << "\n"
//                      << user1 << "'s turn";
//             }
//             else
//             {
//                 cout << "\n"
//                      << user2 << "'s turn";
//             }
//             cin >> n;
//             switch (n)
//             {
//             case 1:
//                 if (i % 2 == 0)
//                 {
//                     board[0][0] = ip1;
//                 }
//                 else
//                 {

//                     board[0][0] = ip2;
//                 }
//                 break;
//             case 2:
//                 if (i % 2 == 0)
//                 {
//                     board[0][1] = ip1;
//                 }
//                 else
//                 {

//                     board[0][1] = ip2;
//                 }
//                 break;
//             case 3:
//                 if (i % 2 == 0)
//                 {
//                     board[0][2] = ip1;
//                 }
//                 else
//                 {

//                     board[0][2] = ip2;
//                 }
//                 break;
//             case 4:
//                 if (i % 2 == 0)
//                 {
//                     board[1][0] = ip1;
//                 }
//                 else
//                 {

//                     board[1][0] = ip2;
//                 }
//                 break;
//             case 5:
//                 if (i % 2 == 0)
//                 {
//                     board[1][1] = ip1;
//                 }
//                 else
//                 {

//                     board[1][1] = ip2;
//                 }
//                 break;
//             case 6:
//                 if (i % 2 == 0)
//                 {
//                     board[1][2] = ip1;
//                 }
//                 else
//                 {

//                     board[1][2] = ip2;
//                 }
//                 break;
//             case 7:
//                 if (i % 2 == 0)
//                 {
//                     board[2][0] = ip1;
//                 }
//                 else
//                 {

//                     board[2][0] = ip2;
//                 }
//                 break;
//             case 8:
//                 if (i % 2 == 0)
//                 {
//                     board[2][1] = ip1;
//                 }
//                 else
//                 {

//                     board[2][1] = ip2;
//                 }
//                 break;
//             case 9:
//                 if (i % 2 == 0)
//                 {
//                     board[2][2] = ip1;
//                 }
//                 else
//                 {

//                     board[2][2] = ip2;
//                 }
//                 break;

//             default:
//                 cout << "Invalid case";
//                 break;
//             }
//             for (int i = 0; i < 3; i++)
//             {
//                 for (int j = 0; j < 3; j++)
//                 {
//                     cout << board[i][j] << "|";
//                 }
//                 cout << endl;
//             }
//             if (checkforans(board))
//             {
//                 cout << "Winner ";
//                 for (int i = 0; i < 3; i++)
//                 {
//                     for (int j = 0; j < 3; j++)
//                     {
//                         cout << board[i][j] << "|";
//                     }
//                     cout << endl;
//                 }
//                 return true;
//             }
//             i++;
//         }
//     }
//     else
//     {
//         while (ip1 != 'o' || ip1 != 'x' || ip2 != 'o' || ip2 != 'x')
//         {
//             cout << "Please enter correct signs only";
//             cout << "as you entered wrong sign , re entre the signs";
//             cout << "\nCurent sign for " << user1;
//             cout << "\n Enter Sign for user " << user1;
//             cin >> ip1;
//             cout << "\nCurent sign for " << user2;
//             // cout<<
//             cout << "\n Enter Sign for user " << user2;
//             cin >> ip2;
//         }
//     }
//     // user input;

//     return 0;
// }

bool checkforans1(vector<vector<char>> &board, char &ip)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == ip && board[i][1] == ip && board[i][2] == ip) || (board[0][i] == ip && board[1][i] == ip && board[2][i] == ip))
        {
            return true;
        }
    }
    if ((board[0][0] == ip && board[1][1] == ip && board[2][2] == ip) || (board[0][2] == ip && board[1][1] == ip && board[2][0] == ip))
    {
        return true;
    }
    return false;
}

int main()
{
    int g = 1;
    while (g == 1)
    {
        g--;
        vector<vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        // for(int)
        string user1;
        cout << "Enter User 1 name : ";
        cin >> user1;
        char ip1;
        cin >> ip1;
        while (ip1 != 'x' && ip1 != 'o')
        {
            cout << "enter valid signe";
            cin >> ip1;
            /* code */
        }
        string user2;
        cout << "Enter User 2 name : ";
        cin >> user2;
        char ip2 = (ip1 == 'x') ? 'o' : 'x';
        cout << "User 1 is " << user1 << "And his sign is" << ip1 << endl;
        cout << "User 2 is " << user2 << "And his sign is" << ip2 << endl;
        int i = 0;
        int n;
        while (i < 9)
        {
            string user = (i % 2 != 0) ? user1 : user2;
            char ip = (i % 2 != 0) ? ip1 : ip2;
            cout << "Enter values from 1 to 9 only";
            cin >> n;
            while (n < 1 || n > 9 || board[(n - 1) / 3][(n - 1) % 3] != ' ')
            {
                cout << "enter a vlid ip";
                cin >> n;
            }
            // boa
            board[(n - 1) / 3][(n - 1) % 3] = ip;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cout << board[i][j] << "|";
                }
                cout << endl
                     << "_____________" << endl;
            }
            if (checkforans1(board, ip))
            {
                cout << "Winner is " << user << " , " << "<-----" << ip << "----->";
                // return true;
                break;
            }
            i++;
        }
        if (i == 9)
        {
            cout << "ITs an draw" << endl;
        }
        cout << "enter 1 to play again enter any other value to exit ";
        cin >> g;
        if (g == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}