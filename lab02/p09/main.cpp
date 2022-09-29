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
        int a = 0;
        cin >> a;
        vector<int> v(a);
        for (int i = 0; i < a; i++)
        {
            cin >> v[i];
        }
        int max = v[0];
        int min = v[a - 1];
        for (int i = 0; i < a; i++)
        {
            if (v[i] > max)
            {
                max = v[i];
            }
            if (v[i] < min)
            {
                min = v[i];
            }
        }
        cout << (max - min) * 2 << endl;
    }
}