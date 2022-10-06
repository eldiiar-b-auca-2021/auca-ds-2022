#include <bits/stdc++.h>
#include <iomanip>
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cout << "PERFECTION OUTPUT\n";
    for (int i = 0; cin >> i && i != 0;)
    {
        int sumOfProperD = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sumOfProperD += j;
            }
        }
        if (sumOfProperD == i)
        {
            cout << right << setw(5) << i << "  PERFECT"
                 << "\n";
        }
        else if (sumOfProperD > i)
        {
            cout << right << setw(5) << i << "  ABUNDANT"
                 << "\n";
        }
        else
        {
            cout << right << setw(5) << i << "  DEFICIENT"
                 << "\n";
        }
    }
    cout << "END OF OUTPUT"
         << "\n";
}