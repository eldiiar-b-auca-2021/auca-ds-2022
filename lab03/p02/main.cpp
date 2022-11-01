#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
void move(int x, int y, vector<vector<int>> &puzzle, string command)
{
    bool isPossible = false;
    for (int i = 0; i < sz(command); i++)
    {

        switch (command.at(i))
        {
        case 'A':
            if (x >= 1)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x - 1][y];
                puzzle[x - 1][y] = temp;
                x -= 1;
            }
            else
            {
                isPossible = true;
            }
            break;
        case 'B':
            if (x <= 3)
            {
                int temp = puzzle[x][y];
                puzzle[x][y] = puzzle[x + 1][y];
                puzzle[x + 1][y] = temp;
                x += 1;
            }
            else
            {
                isPossible = true;
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
            else
            {
                isPossible = true;
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
            else
            {
                isPossible = true;
            }
            break;
        default:
            isPossible = true;
            break;
        }
        if (isPossible)
        {
            break;
        }
    }
    if (isPossible)
    {
        cout << "This puzzle has no final configuration." << endl;
        cout << endl;
    }
    else
    {
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
int main()
{
    iostream::sync_with_stdio(false);
    int numOfPuzzle = 1;
    for (string s; getline(cin, s) && s != "Z";)
    {

        vector<vector<int>> puzzle(5, vector<int>(5, 0));
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

        int xPos = 0;
        int yPos = 0;
        bool isFound = false;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (puzzle[i][j] == (int)' ')
                {
                    xPos = i;
                    yPos = j;
                    isFound = true;
                    break;
                }
            }
            if (isFound)
            {
                break;
            }
        }
        string command;

        for (char str; cin >> str && str != '0';)
        {
            command += str;
        }
        cin.ignore();
        cout << "Puzzle #" << numOfPuzzle++ << ":" << endl;
        move(xPos, yPos, puzzle, command);
        cin.clear();
    }
}