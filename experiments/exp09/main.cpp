#include <bits/stdc++.h>
#include "../../project01/BigInt/BigInt.hpp"
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {5, 6, 5, 5};
    string res;
    int a = v1.size() - 1;
    int b = v2.size() - 1;
    int numToRem = 0;
    int count = 0;
    BigInt r("0");
    for (int i = b; i >= 0; i--)
    {
        count++;
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
        reverse(res.begin(), res.end());
        r = (r + BigInt(res));
        res = "";
        for (int k = 0; k < count; k++)
        {
            res += "0";
        }
    }
    ostringstream sout;
    sout << r;
    cout << sout.str() << endl;
}