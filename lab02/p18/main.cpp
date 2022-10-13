#include <bits/stdc++.h>
#include <algorithm>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    for (int c, k; cin >> c >> k;)
    {
        vector<int> vC(c);
        for (int i = 0; i < sz(vC); i++)
        {
            cin >> vC[i];
        }
        int s = 0;
        for (int i = 0; i < k; i++)
        {
            int a;
            cin >> a;
            int b;
            cin >> b;
            int countNums = 0;
            vector<int> v(a);
            for (int j = 0; j < a; j++)
            {
                cin >> v[j];
                if (count(vC.begin(), vC.end(), v[j]))
                {
                    countNums++;
                }
            }
            if (countNums >= b)
            {
                s++;
            }
            countNums = 0;
        }
        if (s == k)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}