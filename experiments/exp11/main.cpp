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
    BigInt y("2");
    BigInt x("7");
    int n = 1, temp = 0, sum = 1;
    BigInt res(0);
    string s;

    BigInt count("1");
    while (true)
    {
        ostringstream oss;
        res = count * y;
        if (res == x)
        {
            break;
        }
        else if (res > x)
        {
            sum -= 1;
            break;
        }
        sum++;
        count = count + BigInt(1);
        res = 0;
    }
    cout << sum << endl;
    // for (auto itY = y.mDigits.rbegin(); itY != y.mDigits.rend(); itY++)
    // {
    //     count++;
    //     for (auto itX = x.mDigits.rbegin(); itX != x.mDigits.rend(); itX++)
    //     {
    //         sum = *itX * *itY + temp;
    //         if (sum > 9)
    //         {
    //             s += to_string(sum % 10);
    //             temp = sum / 10;
    //         }
    //         else
    //             s += to_string(sum);
    //     }
    //     if (temp != 0)
    //         s += to_string(temp);
    //     reverse(s.begin(), s.end());
    //     for (int i = 1; i < count; i++)
    //     {
    //         s += "0";
    //     }
    //     while (s[0] == '0' && s.size() > 1)
    //     {
    //         s.erase(s.begin());
    //     }
    //     cout << s << endl;
    //     res = res + BigInt(s);
    //     s = "";
    //     temp = 0;
    // }
    // ostringstream ss;
    // ss << res;
    // cout << ss.str() << endl;

    // while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
    // {
    //     if (itX != x.mDigits.rend())
    //     {
    //         xValue = *itX;
    //         itX++;
    //     }
    //     if (itY != y.mDigits.rend())
    //     {
    //         yValue = *itY;
    //         itY++;
    //     }
    //     sum = xValue - yValue + temp;
    //     if (sum < 0)
    //     {
    //         sum += 10;
    //         temp = -1;
    //     }
    //     else
    //     {
    //         temp = 0;
    //     }
    //     yValue = 0;
    //     xValue = 0;
    //     *itZ = sum;
    //     itZ++;
    // }

    // while (itX != first.rend() || itY != second.rend())
    // {
    //     if (itX != first.rend())
    //     {
    //         f = *itX;
    //         itX++;
    //     }
    //     if (itY != second.rend())
    //     {
    //         s = *itY;
    //         itY++;
    //     }
    //     if (f < s)
    //     {
    //         for (auto it = itX; it != first.rend(); it++)
    //         {
    //             if (*it == 0)
    //             {
    //                 *it = 9;
    //             }
    //             else
    //             {
    //                 *it -= 1;
    //                 sum = f - s + 10;
    //                 break;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         sum = f - s;
    //     }
    //     f = 0, s = 0;
    //     cout << sum << " ";
    // }

    // experiment with reverse iterator
    // vector<int> y = {1, 3, 9};
    // auto itY = y.rbegin();
    // for (auto it = itY; it != y.rend(); it++)
    // {
    //     cout << (*(it) = 10) << endl;
    //     cout << *it << endl;
    // }
}