#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    // experiment with iterators

    // experiment with usual iterator
    vector<int> x = {1, 9, 3};
    auto itX = x.begin();
    *itX += 10;
    cout << *itX << endl;
    itX++;
    cout << *itX << endl;

    // experiment with reverse iterator
    vector<int> y = {1, 3, 9};
    auto itY = y.rbegin();
    *itY += 10;
    cout << *itY << endl;
    itY++;
    cout << *itY << endl;
}