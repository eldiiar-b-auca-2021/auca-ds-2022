#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
bool isNotRepeated(int a)
{
    vector<int> nums(10);

    while (a != 0)
    {
        int mod = 0;
        mod = a % 10;
        nums[mod]++;
        a = a / 10;
    }
    for (int i = 0; i < sz(nums); i++)
    {
        if (nums[i] > 1)
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
    while (cin >> a >> b)
    {
        int count = 0;
        while (a <= b)
        {
            if (isNotRepeated(a))
            {
                count++;
            }
            a++;
        }
        cout << count << endl;
    }
}