#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
bool isRepeated(int num)
{
    vector<int> v(10);
    while (num)
    {
        int mod = num % 10;
        v[mod]++;
        num /= 10;
    }
    for (int i = 0; i < sz(v); i++)
    {
        if (v[i] > 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{

    iostream::sync_with_stdio(false);

    int a, b;
    for (; cin >> a >> b;)
    {
        int count = 0;
        for (int i = a; i <= b; i++)
        {
            if (isRepeated(i))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}