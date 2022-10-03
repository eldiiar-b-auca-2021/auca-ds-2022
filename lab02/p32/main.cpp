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
        int a = 0;
        cin >> a;
        vector<int> v(10);
        string s = "";
        for (int i = 1; i <= a; i++)
        {

            s += to_string(i);
        }
        for (int i = 0; i < sz(s); i++)
        {
            int n = s.at(i) - '0';
            v[n]++;
        }
        for (int i = 0; i < sz(v); i++)
        {
            if (i + 1 == sz(v))
            {
                cout << v[i];
            }
            else
            {
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }
}