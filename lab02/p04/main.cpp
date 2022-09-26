#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int c;
    int solution;
    cin >> c;
    while (c--)
    {
        int num;
        cin >> num;
        solution = num * 567;
        solution /= 9;
        solution += 7492;
        solution *= 235;
        solution /= 47;
        solution -= 498;
        solution /= 10;
        cout << abs(solution %= 10) << endl;
    }
}