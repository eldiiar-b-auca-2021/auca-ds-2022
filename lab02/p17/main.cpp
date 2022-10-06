#include <bits/stdc++.h>
#include <string>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int a;
    int b;
    cin >> a;
    cin >> b;
    string str;
    int dot = 1;
    int slash = 0;
    bool isSlash = false;
    for (int i = 0; i < b; i++)
    {
        getline(cin, str);
        for (int j = 0; j < sz(str); j++)
        {
            if (str.at(j) == '\\')
            {
                slash++;
                isSlash = true;
            }
            else if (str.at(j) == '/')
            {
                slash++;
                isSlash = false;
            }
            if (isSlash && str.at(j) == '.')
            {
                dot++;
            }
        }
    }
    cout << (slash / 2) + dot << endl;
}