#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
void queen(int &x, int &y, std::vector<vector<char>> &chessboard)
{
    for (int i = x + 1, j = y + 1; i < 8 && j < 8;)
    {
        if (!isalpha(chessboard[i][j]))
        {
            chessboard[i][j] = '*';
        }
        else
        {
            break;
        }
        i++, j++;
    }
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0;)
    {
        if (!isalpha(chessboard[i][j]))
        {
            chessboard[i][j] = '*';
        }
        else
        {
            break;
        }
        i--, j--;
    }
    for (int i = x + 1; i < 8; i++)
    {
        if (!isalpha(chessboard[i][y]))
        {
            chessboard[i][y] = '*';
        }
        else
        {
            break;
        }
    }
    for (int i = x - 1; i >= 0; i--)
    {
        if (!isalpha(chessboard[i][y]))
        {
            chessboard[i][y] = '*';
        }
        else
        {
            break;
        }
    }
    for (int j = y + 1; j < 8; j++)
    {
        if (!isalpha(chessboard[x][j]))
        {
            chessboard[x][j] = '*';
        }
        else
        {
            break;
        }
    }
    for (int j = y - 1; j >= 0; j--)
    {
        if (!isalpha(chessboard[x][j]))
        {
            chessboard[x][j] = '*';
        }
        else
        {
            break;
        }
    }
    for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
    {
        if (!isalpha(chessboard[x][j]))
        {
            chessboard[i][j] = '*';
        }
        else
        {
            break;
        }
    }
    for (int i = x + 1, j = y - 1; j >= 0 && i < 8; i++, j--)
    {
        if (!isalpha(chessboard[x][j]))
        {
            chessboard[i][j] = '*';
        }
        else
        {
            break;
        }
    }
}
int main()
{
    iostream::sync_with_stdio(false);
    vector<vector<char>> chessboard(8, vector<char>(8, '1'));
    int x = 3;
    int y = 7;
    queen(x, y, chessboard);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chessboard[i][j] << " ";
        }
        cout << endl;
    }
}