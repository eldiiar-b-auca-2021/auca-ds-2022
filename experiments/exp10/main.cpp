#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<int> first = {2, 3};
    vector<int> second = {1, 5};
    int i = first.size() - 1;
    int j = second.size() - 1;
    string temp = "";
    vector<int> res;
    while (i >= 0 && j >= 0)
    {
        if (first[i] < second[j])
        {
            if (i > 0)
            {
                first[i - 1]--;
                temp += "1";
                temp += to_string(first[i]);
                cout << stoi(temp) << endl;
                res.push_back((stoi(temp)) - second[j]);
                temp = "";
            }
        }
        else
        {
            res.push_back(first[i] - second[j]);
        }
        i--;
        j--;
    }
    for (int k = 0; k < (int)res.size(); k++)
    {
        cout << res[k] << " ";
    }
}