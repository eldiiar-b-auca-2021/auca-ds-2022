#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        int m = 0;
        int f = 0;
        for (int j = 0; j < sz(str); j++)
        {
            if (str.at(j) == 'F')
            {
                f++;
            }
            else if (str.at(j) == 'M')
            {
                m++;
            }
        }

        if (m == f)
        {
            cout << "LOOP\n";
        }
        else
        {
            cout << "NO LOOP\n";
        }
    }
}