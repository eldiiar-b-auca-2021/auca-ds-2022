#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        vector<int> f, s;
        int bags;
        cin >> bags;
        for (int j = 0; j < bags; j++)
        {
            int n;
            char color;
            cin >> n;
            cin >> color;
            n--;
            if (color == 'R')
            {
                f.push_back(n);
            }
            else
            {
                s.push_back(n);
            }
        }
        sort(f.rbegin(), f.rend());
        sort(s.rbegin(), s.rend());
        int minSize = min(f.size(), s.size());
        auto sum1 = accumulate(begin(f), begin(f) + minSize, 0);
        auto sum2 = accumulate(begin(s), begin(s) + minSize, 0);
        cout << "Case #" << i + 1 << ": " << (sum1 + sum2) << endl;
    }
}