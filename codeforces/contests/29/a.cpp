#include <bits/stdc++.h>

/**
 * Rudolph and Tic-Tac-Toe
 * https://codeforces.com/gym/452649/problem/A
 * Time - O(1)
 * Space - O(1)
 */

using namespace std;

int main()
{
    int t;

    string board[3];
    char row, col;

    char res;

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--) {
        for (auto i = 0; i < 3; ++i) cin >> board[i];

        res = '.';

        // diagonal
        if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            res = board[0][0];
        }
        if (board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            res = board[2][0];
        }

        if (res == '.') {
            for (auto i = 0; i < 3; ++i) {
                // row
                if (board[i][0] != '.' && board[i][0] == board[i][1] &&
                    board[i][1] == board[i][2]) {
                    res = board[i][0];
                    break;
                }
                // col
                if (board[0][i] != '.' && board[0][i] == board[1][i] &&
                    board[1][i] == board[2][i]) {
                    res = board[0][i];
                    break;
                }
            }
        }

        if (res != '.')
            cout << res;
        else
            cout << "DRAW";
        cout << "\n";
    }

    return 0;
}
