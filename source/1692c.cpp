#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    char board[8][8];

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                cin >> board[j][k];
            }
        }

        for (int j = 1; j < 7; j++)
        {
            for (int k = 1; k < 7; k++)
            {
                if (board[j][k] == '#' and board[j - 1][k - 1] == '#' and board[j - 1][k + 1] == '#' and board[j + 1][k - 1] == '#' and board[j + 1][k + 1] == '#')
                {
                    cout << j + 1 << " " << k + 1 << endl;
                }
            }
        }
    }
}