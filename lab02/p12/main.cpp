#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    long long n;
    while (cin >> n && n != 0)
    {
        if (n == 0)
        {
            break;
        }
        while (n > 9)
        {
            long long temp = 0;
            while (n)
            {
                temp += n % 10;
                n /= 10;
            }
            n = temp;
        }
        cout << n << endl;
    }
}