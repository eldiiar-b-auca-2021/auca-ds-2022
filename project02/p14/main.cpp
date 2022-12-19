#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    bool first = false;
    for (int n; cin >> n && n != 0;)
    {
        vector<string> v(n);
        if (first)
        {
            cout << endl;
        }
        first = true;
        for (int i = 0; i < sz(v); i++)
        {
            cin >> v[i];
        }
        stable_sort(begin(v), end(v), [](const string &f, const string &s)
                    { if (f[0] == s[0])
                    {
                        if (sz(f) > 0 && sz(s) > 0)
                        return f[1] < s[1];
                    }
                        return f < s; });
        for (int i = 0; i < sz(v); i++)
        {
            cout << v[i] << endl;
        }
    }
}