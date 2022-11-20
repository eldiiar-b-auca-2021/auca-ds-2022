#include <bits/stdc++.h>
#include "../../project01/BigInt/BigInt.hpp"
template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    // experiment with iterators

    // experiment with usual iterator
    vector<int> first = {1, 2, 3, 4};
    vector<int> second = {1, 1, 2, 9};
    auto itX = first.rbegin();
    auto itY = second.rbegin();
    vector<int> res;
    int s = 0;
    int f = 0;
    int s = 0;
    while (itX != first.rend() || itY != second.rend())
    {
        if (itX != first.end())
        {
            f = *itX;
            itX++;
        }
        if (itY != second.end())
        {
            s = *itY;
            itY++;
        }
        if (*itX < *itY)
        {
            for (auto it = 1 + itX; it != first.rend(); it++)
            {
                if (*it == 0)
                {
                    *it = 9;
                }
                else
                {
                    *it = (*it - 1);
                    *itX = abs(*itX - *itY);
                    break;
                }
            }
            s = *itX;
        }
        else
        {
            s = *itX - *itY;
        }
        cout << s << " ";
        itX++;
        itY++;
    }

    // experiment with reverse iterator
    // vector<int> y = {1, 3, 9};
    // auto itY = y.rbegin();
    // for (auto it = itY; it != y.rend(); it++)
    // {
    //     cout << (*(it) = 10) << endl;
    //     cout << *it << endl;
    // }
}