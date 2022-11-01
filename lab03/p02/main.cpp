#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
void move(int x1, int y1, vector<vector<int>> &puzzle, string &command)
{
    int x = x1;
    int y = y1;
    for (int i = 0; i < sz(command); i++)
    {
        switch (command[i])
        {
        case 'A':
            if (x >= 1)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x - 1][y];
                puzzle[x - 1][y] = temp;
                x -= 1;
            }
            break;
        case 'B':
            if (x < 4)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x + 1][y];
                puzzle[x + 1][y] = temp;
                x += 1;
            }
            break;
        case 'L':
            if (y >= 1)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x][y - 1];
                puzzle[x][y - 1] = temp;
                y -= 1;
            }
            break;
        case 'R':
            if (y <= 3)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x][y + 1];
                puzzle[x][y + 1] = temp;
                y += 1;
            }
            break;
        }
    }
}
int main()
{
    iostream::sync_with_stdio(false);
    for (string s; getline(cin, s) && s != "Z";)
    {

        vector<vector<int>> puzzle(5, vector<int>(5));
        for (int i = 0; i < 5; i++)
        {
            puzzle[0][i] = (int)s[i];
        }
        int count = 1;
        for (string l; getline(cin, l);)
        {
            for (int i = 0; i < 5; i++)
            {
                puzzle[count][i] = (int)l[i];
            }
            count++;
            if (count > 4)
            {
                break;
            }
        }
        cin.clear();
        string command;
        getline(cin, command);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << (char)puzzle[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (puzzle[i][j] == (int)' ')
                {
                    move(i, j, puzzle, command);
                    break;
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << (char)puzzle[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}