#include <bits/stdc++.h>
#include <algorithm>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<string> v;

    for (string line; getline(cin, line);)
    {
        if (line != "")
        {
            reverse(begin(line), end(line));
            v.push_back(line);
        }
        else
        {
            sort(begin(v), end(v), [](string a, string b)
                 { return a < b; });
            vector<string> v2;
            int max1 = 0;
            for (auto &l : v)
            {
                max1 = max(max1, (int)l.size());
                reverse(begin(l), end(l));
                v2.push_back(l);
            }

            for (auto &r : v2)
            {
                cout << right << setw(max1) << r << endl;
            }
            cout << endl;

            v.clear();
        }
    }
    sort(begin(v), end(v), [](string a, string b)
         { return a < b; });
    vector<string> v2;
    int max1 = 0;
    for (auto &l : v)
    {
        max1 = max(max1, (int)l.size());
        reverse(begin(l), end(l));
        v2.push_back(l);
    }

    for (auto &r : v2)
    {
        cout << right << setw(max1) << r << endl;
    }
    v.clear();
}