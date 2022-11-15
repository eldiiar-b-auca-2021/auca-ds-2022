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
        if (j == 0)
        {
            for (int k = 0; k <= i - j; k++)
            {
                temp += std::to_string(first[k]);
            }
            res.push_back((stoi(temp)) - second[j]);
            temp = "";
        }
        else if (first[i] < second[j])
        {
            for (int k = i - 1; k >= 0; k--)
            {
                if (first[k] != 0)
                {
                    first[k]--;
                    temp += "1";
                    break;
                }
                else if (first[k] == 0)
                {
                    first[k] = 9;
                }
            }
            temp += std::to_string(first[i]);
            res.push_back((stoi(temp)) - second[j]);
            temp = "";
        }
        else
        {
            res.push_back(first[i] - second[j]);
        }
        i--;
        j--;
    }
    reverse(res.begin(), res.end());

    while (res[0] == 0)
    {
        res.erase(res.begin());
    }
    for (int k = 0; k < (int)res.size(); k++)
    {
        cout << res[k] << " ";
    }
    cout << endl;
}