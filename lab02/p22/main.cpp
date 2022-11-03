#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        int sum = 0;
        vector<int> v(size);
        for (int j = 0; j < size; j++)
        {
            cin >> v[j];
        }

        for (int j = 1; j < size; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (v[j] >= v[k])
                {
                    sum += 1;
                }
            }
        }
        cout << sum << endl;
    }
}