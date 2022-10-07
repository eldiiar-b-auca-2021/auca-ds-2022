#include <bits/stdc++.h>
#include <string>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    char ch[120][120];

    for (int a, b; cin >> a >> b;)
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                char temp;
                cin >> temp;
                ch[i][j] = temp;
            }
        }
        int dot = 0;
        int slash = 0;
        for (int i = 0; i < a; i++)
        {
            bool isDot = false;
            int howManyTimes = 0;
            for (int j = 0; j < b; j++)
            {
                if (ch[i][j] == '\\' || ch[i][j] == '/')
                {
                    slash++;
                    howManyTimes++;
                    if (howManyTimes == 1)
                    {
                        isDot = true;
                    }
                    else if (howManyTimes > 1)
                    {
                        isDot = false;
                        howManyTimes = 0;
                    }
                }
                else if (isDot && ch[i][j] == '.')
                {
                    dot++;
                }
            }
        }
        cout << (slash / 2) + dot << endl;
    }
}