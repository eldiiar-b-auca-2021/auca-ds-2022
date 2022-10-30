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
        int num;
        cin >> num;
        vector<int> v(num);

        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }
        vector<int> an = v;
        if (v.size() == 1)
        {
            int count = 0;
            while (v[0] % 2 == 0)
            {
                v[0] /= 2;
                count++;
            }
            cout << count << endl;
        }
        else
        {
            for (int i = 0; i < num; i++)
            {
                if (v[i] % 2 == 0)
                {
                    int val = v[i];
                    for (int j = i; j < num; j++)
                    {
                        if (val == v[j])
                        {
                            while ((v[j] % 2) == 0)
                            {
                                v[j] = (v[j] / 2);
                            }
                        }
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < num; i++)
            {
                if (v[i] != an[i])
                {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
}