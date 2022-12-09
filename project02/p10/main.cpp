#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        bool isDigitFirst = false;
        string line;
        getline(cin, line);
        if (line[0] >= '0' && line[0] <= '9')
        {
            isDigitFirst = true;
        }
        istringstream is(line);
        int radius;
        string color;
        if (!isDigitFirst)
        {
            is >> color;
            is >> radius;
        }
        else
        {
            is >> radius;
            is >> color;
            radius /= 2;
        }
        v[i].first = color;
        v[i].second = radius;
    }
    sort(v.begin(), v.end(), [](const pair<string, int> &pair1, const pair<string, int> &pair2)
         { return pair1.second < pair2.second; });
    for (int i = 0; i < sz(v); i++)
    {
        cout << v[i].first << endl;
    }
}