#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> v1 = {4, 2, 8};
    vector<int> v2 = {3, 2};
    vector<int> numToRem;
    vector<int> res;
    bool isFirst = true;
    int i = v1.size() - 1;
    int j = v2.size() - 1;
    while (i >= 0 && j >= 0)
    {

        int sum = ((v1[i] + v2[j]) % 10);
        if (numToRem.size() != 0)
        {
            res.push_back(sum + numToRem[0]);
            numToRem.clear();
        }
        else
        {
            res.push_back(sum);
        }
        numToRem.push_back((v1[i] + v2[j]) / 10);
        i--, j--;
    }
    while (i >= 0)
    {
        if (numToRem.size() != 0)
        {
            res.push_back(numToRem[0] + v1[i--]);
        }
        else
        {
            res.push_back(v1[i--]);
        }
    }
    reverse(res.begin(), res.end());
    for (int k = 0; k < (int)res.size(); k++)
    {
        cout << res[k];
    }
    cout << endl;
}