#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    vector<string> song = {
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "you",
        "Happy",
        "birthday",
        "to",
        "Rujia",
        "Happy",
        "birthday",
        "to",
        "you",
    };
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n <= 16)
    {
        int j = 0;
        for (int i = 0; i < 16; i++)
        {
            if (j == n)
            {
                j = 0;
            }
            cout << v[j++] << ": " << song[i] << "\n";
        }
    }
    else if (n > 16)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (j == 16)
            {
                j = 0;
            }
            cout << v[i] << ": " << song[j++] << "\n";
        }
        if (j != 16)
        {
            for (int i = j, k = 0; i < 16; i++, k++)
            {
                cout << v[k] << ": " << song[i] << "\n";
            }
        }
    }
}