#include <bits/stdc++.h>
#include <algorithm>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> v;
    int num;
    cin >> num;
    int n;
    for (int j = 0; j < num; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        cout << "Case " << j + 1 << ": " << v.at(1) << "\n";
        v.clear();
    }
}