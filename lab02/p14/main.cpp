#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    bool isFirst = true;
    while (n--)
    {
        vector<int> v(10);
        for (int i = 0; i < sz(v); i++)
        {
            cin >> v[i];
        }
        int increase = 0;
        int decrease = 0;
        for (int i = 1; i < sz(v); i++)
        {
            if (v[i] > v[i - 1])
            {
                increase++;
            }
            else if (v[i - 1] > v[i])
            {
                decrease++;
            }
        }
        if (isFirst)
        {
            cout << "Lumberjacks:" << endl;
            isFirst = false;
        }
        if (increase == 9 || decrease == 9)
        {
            cout << "Ordered" << endl;
        }
        else
        {
            cout << "Unordered" << endl;
        }
        v.clear();
    }
}