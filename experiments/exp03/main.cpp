#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    // var = new ArrayList<Integer>();
    vector<int> v;
    // cout << v.size() << endl;
    cout << sz(v) << endl;

    // v.add(1)
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < sz(v); i++)
    {
        // v.get(i)
        cout << "v[" << i << "] = " << v[i] << endl;
    }
    // v.set(2, 10);
    v[2] = 10;

    for (auto e : v)
    {
        cout << " " << e << endl;
    }
}