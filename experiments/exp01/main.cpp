#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator n;
    ostringstream s;
    s << "{";
    for (n = v.begin(); n != v.end() - 1; n++)
    {
        s << *n << ", ";
    }
    s << v.back() << "}";
    cout << s.str() << endl;
}