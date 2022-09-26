#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int ended = 0;
    int testcase;
    cin >> testcase;
    vector<string> list;
    string n;
    for (int i = 0; i < testcase; i++)
    {
        cin >> n;
        list.push_back(n);
    }
    list.push_back(" ");
    vector<string> congrat = {
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "Rujia",
        "Happy", "birthday", "to", "you"};
    int index = 0;
    if ((int)list.size() < (int)congrat.size() || (int)list.size() == (int)congrat.size())
    {
        for (int i = 0; i < (int)congrat.size(); i++)
        {
            cout << list.at(index) << ": " << congrat.at(i) << endl;
            if (index == testcase - 1)
            {
                index = 0;
                continue;
            }
            index++;
        }
    }
    else
    {
        for (int i = 0; i < (int)congrat.size(); i++)
        {
            cout << list.at(index) << ": " << congrat.at(i) << endl;
            if (index == testcase - 1)
            {
                ended = 1;
                index = 0;
                continue;
            }
            index++;
            if (ended != 1 && i == (int)congrat.size() - 1)
            {
                i = -1;
            }
        }
    }
}