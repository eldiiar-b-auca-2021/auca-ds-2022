#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class BigInt
{
    // friend std::ostream &operator>>(, const BigInt &x);
    friend BigInt operator*(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator<(const BigInt &x, const BigInt &y);
    friend bool operator>(const BigInt &x, const BigInt &y);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);

    std::vector<int> mDigits;
    mutable bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }
    BigInt(const int &intValue)
        : mIsNegative(false)
    {
        if (intValue < 0)
        {
            mIsNegative = true;
        }
        string s = to_string(intValue);
        for (auto r : s)
        {
            mDigits.push_back(r - '0');
        }
    }
    BigInt(const std::string &value)
        : mIsNegative(false)
    {
        if (value.length() == 0)
        {
            throw std::runtime_error("empty");
        }
        if (value[0] == '0' && value.length() > 1 && value[1] == '0')
        {
            throw std::runtime_error("zeros before digit");
        }
        bool isFirst = true;
        for (auto r : value)
        {
            if (isdigit(r))
            {
                mDigits.push_back(r - '0');
            }
            else if (r == '-' && isFirst)
            {
                mIsNegative = true;
            }
            else if (r == '+' && isFirst)
            {
                continue;
            }
            else
            {
                throw std::runtime_error("invalid digit");
            }
            isFirst = false;
        }
    }
    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();
        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();
        int carry = 0;
        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if (itX != x.mDigits.rend())
            {
                s += *itX;
                itX++;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                itY++;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            itZ++;
        }
        if (carry == 1)
            *itZ = carry;
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{

    if (x.mIsNegative)
    {
        out << "-";
    }
    for (auto digit : x.mDigits)
    {
        out << digit;
    }
    return out;
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    std::ostringstream res;
    if (!x.mIsNegative && !y.mIsNegative)
    {
        return BigInt::addAbsValues(x, y);
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        x.mIsNegative = false;
        y.mIsNegative = false;
        res << "-";
        res << BigInt::addAbsValues(x, y);
        return BigInt(res.str());
    }
}

// inline BigInt operator-(const BigInt &x, const BigInt &y)
// {
//     if (x.mIsNegative && y.mIsNegative) // -50 -(-50)
//     {
//         x.mIsNegative = false;
//         y.mIsNegative = false;
//         return y - x;
//     }
//     else if (!x.mIsNegative && y.mIsNegative) // 50 -(-522)
//     {
//         y.mIsNegative = false;
//         return y + x;
//     }
//     else if (x.mIsNegative && !y.mIsNegative) // -50 - (100)
//     {
//         ostringstream s;
//         x.mIsNegative = false;
//         s << "-";
//         s << x + y;
//         return BigInt(s.str());
//     }

//     vector<int> first;
//     vector<int> second;
//     string result;
//     int a = 0;
//     int b = 0;
//     bool isFirstLonger = true;
//     if (x.mDigits.size() > y.mDigits.size())
//     {
//         a = x.mDigits.size() - 1;
//         b = y.mDigits.size() - 1;
//     }
//     else if (x.mDigits.size() < y.mDigits.size())
//     {
//         isFirstLonger = false;
//         a = y.mDigits.size() - 1;
//         b = x.mDigits.size() - 1;
//     }
//     else if (x.mDigits.size() == y.mDigits.size())
//     {
//         for (int i = 0; i < (int)x.mDigits.size(); i++)
//         {
//             if (x.mDigits[i] > y.mDigits[i])
//             {
//                 a = x.mDigits.size() - 1;
//                 b = y.mDigits.size() - 1;
//                 break;
//             }
//             else if (x.mDigits[i] < y.mDigits[i])
//             {
//                 isFirstLonger = false;
//                 a = y.mDigits.size() - 1;
//                 b = x.mDigits.size() - 1;
//                 break;
//             }
//         }
//     }
//     if (isFirstLonger)
//     {
//         for (int i = 0; i <= a; i++)
//         {
//             first.push_back(x.mDigits[i]);
//         }
//         for (int i = 0; i <= b; i++)
//         {
//             second.push_back(y.mDigits[i]);
//         }
//     }
//     else
//     {
//         for (int i = 0; i <= a; i++)
//         {
//             first.push_back(y.mDigits[i]);
//         }
//         for (int i = 0; i <= b; i++)
//         {
//             second.push_back(x.mDigits[i]);
//         }
//     }
//     int j = second.size() - 1;
//     for (int i = (int)first.size() - 1; i >= 0; i--)
//     {
//         if (j < 0)
//         {
//             result += to_string(first[i]);
//         }
//         else if (first[i] < second[j])
//         {
//             for (int k = i - 1; k >= 0; k--)
//             {
//                 if (first[k] != 0)
//                 {
//                     first[k]--;
//                     break;
//                 }
//                 else if (first[k] == 0)
//                 {
//                     first[k] = 9;
//                 }
//             }
//             result += to_string((first[i] + 10) - second[j]);
//         }
//         else
//         {
//             result += to_string(first[i] - second[j]);
//         }
//         j--;
//     }
//     int size = result.size() - 1;
//     while (result[size--] == '0' && size >= 0)
//     {
//         result.pop_back();
//     }
//     reverse(result.begin(), result.end());
//     if (!isFirstLonger) // 23 - 100 // 100 -23
//     {
//         result.insert(0, "-");
//     }
//     return BigInt(result);
// }
// inline BigInt operator*(const BigInt &x, const BigInt &y)
// {
//     string res;
//     int a = 0;
//     int b = 0;
//     vector<int> multiplier1;
//     vector<int> multiplier2;
//     if (x.mDigits.size() > y.mDigits.size())
//     {
//         a = x.mDigits.size() - 1;
//         b = y.mDigits.size() - 1;
//         multiplier1 = x.mDigits;
//         multiplier2 = y.mDigits;
//     }
//     else
//     {
//         a = y.mDigits.size() - 1;
//         b = x.mDigits.size() - 1;
//         multiplier1 = y.mDigits;
//         multiplier2 = x.mDigits;
//     }
//     int numToRem = 0;
//     int count = 0;
//     BigInt r("0");
//     for (int i = b; i >= 0; i--)
//     {
//         count++;
//         for (int j = a; j >= 0; j--)
//         {
//             int t = multiplier1[j] * multiplier2[i] + numToRem;
//             res += to_string(t % 10);
//             numToRem = t / 10;
//         }
//         if (numToRem != 0)
//         {
//             res += to_string(numToRem);
//             numToRem = 0;
//         }
//         reverse(res.begin(), res.end());
//         r = (r + BigInt(res));
//         for (int k = 0; k < count; k++)
//         {
//             res += "0";
//         }
//     }
//     return r;
// }
inline bool operator<(const BigInt &x, const BigInt &y)
{
    int count = 0;
    if (!x.mIsNegative && !y.mIsNegative)
    {
        if (x.mDigits.size() > y.mDigits.size()) // 12345 > 1234
        {
            return false;
        }
        else if (x.mDigits.size() == y.mDigits.size()) // 123 < 234
        {
            for (int i = 0; i < (int)x.mDigits.size(); i++)
            {
                if (x.mDigits[i] > y.mDigits[i]) // 1 > 2
                {
                    return false;
                }
                else if (x.mDigits[i] == y.mDigits[i])
                {
                    count++;
                }
            }
        }
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        if (x.mDigits.size() < y.mDigits.size()) // -123 < -1233324
        {
            return false;
        }
        else if (x.mDigits.size() == y.mDigits.size()) // -12 < -23
        {
            for (int i = 0; i < (int)x.mDigits.size(); i++)
            {
                if (x.mDigits[i] < y.mDigits[i]) // -1 < -2
                {
                    return false;
                }
                else if (x.mDigits[i] == y.mDigits[i])
                {
                    count++;
                }
            }
        }
    }
    else if (!x.mIsNegative && y.mIsNegative)
    {
        return false;
    }
    else if (count == (int)x.mDigits.size() - 1)
    {
        return false;
    }
    return true;
}
inline bool operator>(const BigInt &x, const BigInt &y)
{
    int count = 0;
    if (!x.mIsNegative && !y.mIsNegative)
    {
        if (x.mDigits.size() < y.mDigits.size()) // 12 < 123
        {
            return false;
        }
        else if (x.mDigits.size() == y.mDigits.size())
        {
            for (int i = 0; i < (int)x.mDigits.size(); i++)
            {
                if (x.mDigits[i] < y.mDigits[i]) // 123 234
                {
                    return false;
                }
                else if (x.mDigits[i] == y.mDigits[i])
                {
                    count++;
                }
            }
        }
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        if (x.mDigits.size() < y.mDigits.size()) // -123 > -2345
        {
            return false;
        }
        else if (x.mDigits.size() == y.mDigits.size())
        {
            for (int i = 0; i < (int)x.mDigits.size(); i++)
            {
                if (x.mDigits[i] > y.mDigits[i]) // -223 -134
                {
                    return false;
                }
                else if (x.mDigits[i] == y.mDigits[i])
                {
                    count++;
                }
            }
        }
    }
    else if (x.mIsNegative && !y.mIsNegative)
    {
        return false;
    }
    else if (count == (int)x.mDigits.size() - 1)
    {
        return false;
    }
    return true;
}
inline bool operator==(const BigInt &x, const BigInt &y)
{
    if (!(x > y))
    {
        return false;
    }
    else if (!(x < y))
    {
        return false;
    }
    return true;
}
inline bool operator!=(const BigInt &x, const BigInt &y)
{
    if (!(x == y))
    {
        return true;
    }
    return false;
}
