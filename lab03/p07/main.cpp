#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
class Game
{
    std::vector<vector<char>> chessboard = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

public:
    Game(const string &coordinatesOfFigures)
    {
        // std::vector<vector<char>> chessboard(8, vector<char>(8, ' '));
        putInPlace(coordinatesOfFigures);
        attack();
    }

    void putInPlace(const string &coordinatesOfFigures)
    {
        string n = coordinatesOfFigures;

        int x = 0;
        int y = 0;
        for (int i = 0; i < sz(n); i++)
        {
            char temp = n.at(i);
            if (temp == '/')
            {
                x++;
                y = 0;
            }
            else if (isalpha(temp))
            {
                chessboard[x][y] = temp;
                y++;
            }
            else if (isdigit(temp))
            {
                for (int j = 0; j < (int)temp - 48; j++)
                {
                    y++;
                }
            }
        }
    }
    void attack()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (isalpha(chessboard[i][j]))
                {
                    switch (chessboard[i][j])
                    {
                    case 'q':
                    case 'Q':
                        queen(i, j);
                        break;
                    case 'r':
                    case 'R':
                        rook(i, j);
                        break;
                    case 'p':
                        pawn(i, j);
                        break;
                    case 'P':
                        Pawn(i, j);
                        break;
                    case 'b':
                    case 'B':
                        bishop(i, j);
                        break;
                    case 'k':
                    case 'K':
                        king(i, j);
                        break;
                    case 'N':
                    case 'n':
                        knight(i, j);
                        break;
                    }
                }
            }
        }
    }
    void knight(int &x, int &y)
    {
        int i = x + 1;
        int j = y + 2;
        if (i < 8 && j < 8 && !isalpha(chessboard[i][j]))
        {
            chessboard[i][j] = '*';
        }
        int j1 = y - 2;
        if (i < 8 && j1 >= 0 && !isalpha(chessboard[i][j1]))
        {
            chessboard[i][j1] = '*';
        }
        int i2 = x - 1;
        int j2 = y + 2;
        if (i2 >= 0 && j2 < 8 && !isalpha(chessboard[i2][j2]))
        {
            chessboard[i2][j2] = '*';
        }
        int j3 = y - 2;
        if (i2 >= 0 && j3 >= 0 && !isalpha(chessboard[i2][j3]))
        {
            chessboard[i2][j3] = '*';
        }
        int i4 = x + 2;
        int j4 = y + 1;
        if (i4 < 8 && j4 < 8 && !isalpha(chessboard[i4][j4]))
        {
            chessboard[i4][j4] = '*';
        }
        int j5 = y - 1;
        if (i4 < 8 && j5 >= 0 && !isalpha(chessboard[i4][j5]))
        {
            chessboard[i4][j5] = '*';
        }
        int i6 = x - 2;
        if (i6 >= 0 && j5 >= 0 && !isalpha(chessboard[i6][j5]))
        {
            chessboard[i6][j5] = '*';
        }
        if (i6 >= 0 && j4 < 8 && !isalpha(chessboard[i6][j4]))
        {
            chessboard[i6][j4] = '*';
        }
    }
    void king(int &x, int &y)
    {
        int i = x, j = y;
        if (i + 1 < 8 && j + 1 < 8 && !isalpha(chessboard[i + 1][j + 1]))
        {
            chessboard[i + 1][j + 1] = '*';
        }
        if (i + 1 < 8 && j - 1 >= 0 && !isalpha(chessboard[i + 1][j - 1]))
        {
            chessboard[i + 1][j - 1] = '*';
        }
        if (i - 1 >= 0 && j - 1 >= 0 && !isalpha(chessboard[i - 1][j - 1]))
        {
            chessboard[i - 1][j - 1] = '*';
        }
        if (i - 1 >= 0 && j + 1 < 8 && !isalpha(chessboard[i - 1][j + 1]))
        {
            chessboard[i - 1][j + 1] = '*';
        }
        if (j + 1 < 8 && !isalpha(chessboard[i][j + 1]))
        {
            chessboard[i][j + 1] = '*';
        }
        if (j - 1 >= 0 && !isalpha(chessboard[i][j - 1]))
        {
            chessboard[i][j - 1] = '*';
        }
        if (i + 1 < 8 && !isalpha(chessboard[i + 1][j]))
        {
            chessboard[i + 1][j] = '*';
        }
        if (i - 1 >= 0 && !isalpha(chessboard[i - 1][j]))
        {
            chessboard[i - 1][j] = '*';
        }
    }
    void dioganal(int &x, int &y)
    {
        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
        {
            if (!isalpha(chessboard[i][j]))
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
            if (!isalpha(chessboard[i][j]))
            {
                chessboard[i][j] = '*';
            }
            else
            {
                break;
            }
        }
        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
        {
            if (!isalpha(chessboard[i][j]))
            {
                chessboard[i][j] = '*';
            }
            else
            {
                break;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (!isalpha(chessboard[i][j]))
            {
                chessboard[i][j] = '*';
            }
            else
            {
                break;
            }
        }
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
    }
    void vertexes(int &x, int &y)
    {
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
    }
    void bishop(int &x, int &y)
    {
        dioganal(x, y);
    }
    void Pawn(int &x, int &y)
    {
        int i = x - 1;
        int j = y - 1;
        if (i >= 0 && j >= 0 && !isalpha(chessboard[i][j]))
        {
            chessboard[i][j] = '*';
        }
        if (i >= 0 && j + 2 < 8 && !isalpha(chessboard[i][j + 2]))
        {
            chessboard[i][j + 2] = '*';
        }
    }
    void pawn(int &x, int &y)
    {
        int i = x + 1, j = y + 1;
        if (i < 8 && j < 8 && !isalpha(chessboard[i][j]))
        {
            chessboard[i][j] = '*';
        }
        if (i < 8 && j - 2 >= 0 && !isalpha(chessboard[i][j - 2]))
        {
            chessboard[i][j - 2] = '*';
        }
    }
    void rook(int &x, int &y)
    {
        vertexes(x, y);
    }
    void queen(int &x, int &y)
    {
        dioganal(x, y);
        vertexes(x, y);
    }
    int solve()
    {
        int result = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (chessboard[i][j] == ' ')
                {
                    result++;
                }
            }
        }
        return result;
    }
};
int main()
{
    iostream::sync_with_stdio(false);
    for (string cnf; getline(cin, cnf);)
    {
        Game game(cnf);
        cout << game.solve() << endl;
    }
}