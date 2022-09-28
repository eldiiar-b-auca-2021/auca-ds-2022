#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--)
    {
        int r = 0;
        int c = 0;
        cin >> r;
        cin >> c;
        cout << (r / 3) * (c / 3) << endl;
    }
}