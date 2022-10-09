#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int sumOfDigits(int n)
{
    int sum = 0;

    while (n >= 10)
    {
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
        sum = 0;
    }
    return n;
}
int sumOfCh(string line)
{
    int sum = 0;
    for (int i = 0; i < sz(line); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
        {
            sum += line[i] - 'a' + 1;
        }
        else if (line[i] >= 'A' && line[i] <= 'Z')
        {
            sum += line[i] - 'A' + 1;
        }
    }
    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);
    for (string line1, line2; getline(cin, line1), getline(cin, line2);)
    {
        int sumOf1 = sumOfCh(line1);
        int sumOf2 = sumOfCh(line2);
        double sumOfDigits1 = (double)sumOfDigits(sumOf1);
        double sumOfDigits2 = (double)sumOfDigits(sumOf2);
        if (sumOfDigits1 > sumOfDigits2)
        {
            cout << fixed << setprecision(2) << (sumOfDigits2 * 100) / sumOfDigits1 << " %"
                 << "\n";
        }
        else if (sumOfDigits1 < sumOfDigits2)
        {
            cout << fixed << setprecision(2) << (sumOfDigits1 * 100) / sumOfDigits2 << " %"
                 << "\n";
        }
        else if (sumOfDigits1 == sumOfDigits2)
        {
            cout << fixed << setprecision(2) << (sumOfDigits1 * 100) / sumOfDigits2 << " %"
                 << "\n";
        }
    }
    cout << endl;
}