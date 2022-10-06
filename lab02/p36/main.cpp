#include <bits/stdc++.h>
#include <string>
#include <sstream>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int num;
    cin >> num;
    while (num--)
    {
        string line;
        cin >> line;
        istringstream st(line);
        char symbol;
        int val;
        while (st >> symbol >> val)
        {
            for (int i = 0; i < val; i++)
            {
                cout << symbol;
            }
        }
        cout << "\n";
    }
}