#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
string substitution(string line)
{
    string res;
    for (int i = 0; i < sz(line); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Y')
        {
            res += (char)line[i] + 1;
        }
        else if (line[i] == 'Z')
        {
            res += (char)line[i] - 25;
        }
    }
    return res;
}
/*string permutation(string sumOf1)
{
    string res;
    int i = 1;
    int j = 0;

    while (i <= sz(sumOf1))
    {
        res += sumOf1[i];
        i += 3;
    }
    while (j <= sz(sumOf1))
    {
        res += sumOf1[j];
        j += 3;
    }
    return res;
}*/
int main()
{
    iostream::sync_with_stdio(false);
    for (string a, b; getline(cin, a), getline(cin, b);)
    {
        string sumOf1 = substitution(b);

        cout << sumOf1 << " " << a << endl;
        }
}