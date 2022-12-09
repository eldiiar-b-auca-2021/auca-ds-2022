#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
struct Pair
{
    int ascii;
    int value;
    Pair(int asc, int val)
        : ascii(asc), value(val)
    {
    }
};
int main()
{
    iostream::sync_with_stdio(false);
    bool first = true;
    for (string line; getline(cin, line);)
    {
        if (!first)
        {
            cout << "\n";
        }
        first = false;
        vector<int> v(128);
        for (char ch : line)
        {
            int valueOfCh = (int)ch;
            if (valueOfCh >= 32 && valueOfCh < 128)
            {
                v[valueOfCh]++;
            }
        }
        vector<Pair> p;
        for (int i = 32; i < 128; i++)
        {
            p.emplace_back(i, v[i]);
        }
        sort(begin(p), end(p), [](Pair &f, Pair &s)
             { 
             if (f.value == s.value)
             {
                return f.ascii > s.ascii;
             }
             return f.value < s.value; });

        for (int i = 0; i < sz(p); i++)
        {
            if (0 != p[i].value)
            {
                cout << p[i].ascii << " " << p[i].value << endl;
            }
        }
    }
}