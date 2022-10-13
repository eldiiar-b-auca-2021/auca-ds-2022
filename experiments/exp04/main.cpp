#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> v(n);

    // e is a reference to the indexes
    for (auto &e : v)
    {
        cin >> e;
    }

    for (auto e : v)
    {
        cout << " " << e << endl;
    }
}