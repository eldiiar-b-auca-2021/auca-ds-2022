#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int N;
    int M;
    while (cin >> N >> M)
    {
        cout << N << " " << M << endl;
        if (N == 0 && M == 0)
        {
            break;
        }
        vector<int> n(N);
        for (int i = 0; i < N; i++)
        {
            cin >> n[i];
        }
        sort(begin(n), end(n), [M](int &i, int &j)
             {
            int modulo1 = i%M;
            int modulo2 = j%M;
            if (modulo1 != modulo2)
            {
                return modulo1 < modulo2;
            }
            if (i % 2 != 0 && j % 2 == 0)
            {
                return true;
            }
            if (i % 2 != 0 && j % 2 != 0)
            {
                if (i > j)
                {
                    return true;
                }
            }
            if (i % 2 == 0 && j % 2 == 0)
            {
                if (i < j)
                {
                    return true;
                }
            }
            return false; });
        for (int j = 0; j < sz(n); j++)
        {
            cout << n[j] << "\n";
        }
    }
}