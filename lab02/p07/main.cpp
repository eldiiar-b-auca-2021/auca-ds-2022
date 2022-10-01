#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    for (int a, b; cin >> a >> b && a != -1 && b != -1;)
    {
        int firstRes = 0;
        int secondRes = 0;
        if (a > b)
        {
            firstRes = a - b;
            secondRes = 100 - firstRes;
        }
        else if (a < b)
        {
            firstRes = b - a;
            secondRes = 100 - firstRes;
        }
        if (firstRes < secondRes)
        {
            cout << firstRes << "\n";
        }
        else
        {
            cout << secondRes << "\n";
        }
    }
}