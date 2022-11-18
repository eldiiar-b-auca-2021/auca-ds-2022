#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> v1 = {5, 9};
    vector<int> v2 = {5, 6};
    string res;
    int a = v1.size() - 1;
    int b = v2.size() - 1;
    int numToRem = 0;
    for (int i = b; i >= 0; i--)
    {
        for (int j = a; j >= 0; j--)
        {
            int t = v1[j] * v2[i] + numToRem;
            res += to_string(t % 10);
            numToRem = t / 10;
        }
        if (numToRem != 0)
        {
            res += to_string(numToRem);
            numToRem = 0;
        }
        cout << res << endl;
        res = "";
    }
}