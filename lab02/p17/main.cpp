#include <bits/stdc++.h>
#include <string>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int a;
    int b;
    cin >> a;
    cin >> b;
    char ch[120][120];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char temp;
            cin >> temp;
            if (temp != '\\' && temp != '/')
            {
            }
            ch[i][j] = temp;
        }
    }

    int slash = 0;
    for (int i = 0; i < a; i++)
    {
        bool isInSquare = false;
        for (int j = 0; j < b; j++)
        {
            if (ch[i][j] == '\\' || ch[i][j] == '/')
            {
                slash++;
                isInSquare = true;
            }
            else if (isInSquare)
            {
                slash += 2;
            }
        }
    }
    cout << (slash / 2) << endl;
}