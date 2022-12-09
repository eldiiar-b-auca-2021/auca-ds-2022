#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
struct Skill
{
    string jobDescription;
    int value;
    Skill(const string j, const int v)
        : jobDescription(j), value(v)
    {
    }
};
struct SortLexigraphically
{
    bool operator()(Skill &s1, Skill &s2)
    {
        return s1.jobDescription < s2.jobDescription;
    }
};
int main()
{
    iostream::sync_with_stdio(false);
    vector<Skill> v;
    int n;
    cin >> n;
    int an;
    cin >> an;
    for (int i = 0; i < n; i++)
    {
        string tJDescript;
        cin >> tJDescript;
        int tempV;
        cin >> tempV;
        v.emplace_back(tJDescript, tempV);
    }
    sort(begin(v), end(v), SortLexigraphically());
    for (int i = 0; i < an; i++)
    {
        int sum = 0;

        while (true)
        {
            string temp;
            cin >> temp;
            if (temp == ".")
            {
                break;
            }
            for (auto &e : v)
            {
                if (e.jobDescription == temp)
                {
                    sum += e.value;
                }
            }
        }
        cout << sum << endl;
    }
    // for (int i = 0; i < an; i++)
    // {
    //     string temp;
    //     int sum = 0;
    //     while (true)`
    //     {
    //         cin >> temp;
    //         if (temp == ".")
    //         {
    //             break;
    //         }
    //         auto value = find_if(begin(v), end(v), [temp](Skill &s)
    //                              { return s == temp; });
    //         // if (*value == temp)
    //         // {
    //         //     cout << *value << endl;
    //         // }
    //     }
    // }
}