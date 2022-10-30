#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int cases = 0;
    for (int i, j; cin >> i >> j && i != 0 && j != 0;)
    {
        int res = 0;
        cases++;
        if (i == j || i < j)
        {
            cout << "Case " << cases << ": " << 0 << "\n";
            continue;
        }
        for (int k = 1; k <= 26; k++)
        {
            int temp = 0;
            temp = k * j + j;
            if (temp >= i)
            {
                res = k;
                break;
            }
        }
        if (res == 0)
        {
            cout << "Case " << cases << ": "
                 << "impossible"
                 << "\n";
        }
        else
        {
            cout << "Case " << cases << ": " << res << "\n";
        }
    }
}