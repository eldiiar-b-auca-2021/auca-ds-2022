#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
void computeDigits(int n, int &sum, int &count)
{
    sum = 0;
    count = 0;
    do
    {
        sum += n % 10;
        n /= 10;
        count++;
    } while (n);
}
int solve(int &n)
{
    int numOfDigits;
    int sumOfDigits;
    do
    {
        computeDigits(n, sumOfDigits, numOfDigits);
        n = sumOfDigits;
    } while (numOfDigits != 1);
    return n;
}
int main()
{
    iostream::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;)
    {
        cout << solve(n) << endl;
    }
}