#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class BigInt
{
    friend bool checkTheValuesOfEqualSizes1(BigInt &x, BigInt &y, int &count);
    friend bool checkTheValuesOfEqualSizes2(BigInt &x, BigInt &y, int &count);
    friend BigInt operator*(BigInt &x, BigInt &y);
    friend bool operator!=(BigInt &x, BigInt &y);
    friend bool operator==(BigInt &x, BigInt &y);
    friend bool operator<(BigInt &x, BigInt &y);
    friend bool operator>(BigInt &x, BigInt &y);
    friend BigInt operator+(BigInt &x, BigInt &y);
    friend BigInt operator-(BigInt &x, BigInt &y);
    friend bool operator>=(BigInt &x, BigInt &y);
    friend bool operator<=(BigInt &x, BigInt &y);
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend bool checkBiggestOne(BigInt &x, BigInt &y);
    mutable std::vector<int> mDigits;
    friend std::istream &operator>>(std::istream &value, const BigInt &x);
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
        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }
    static BigInt subtractAbsValues(BigInt &x, BigInt &y)
    {
        int f = 0, s = 0;
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();
        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()));
        auto itZ = z.mDigits.rbegin();
        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            if (itX != x.mDigits.rend())
            {
                f = *itX;
                itX++;
            }
            if (itY != y.mDigits.rend())
            {
                s = *itY;
                itY++;
            }
            if (f < s)
            {
                for (auto it = itX; it != x.mDigits.rend(); it++)
                {
                    if (*it == 0)
                        *it = 9;
                    else
                    {
                        *it = (*it - 1);
                        *itZ = f - s + 10;
                        itZ++;
                        break;
                    }
                }
            }
            else
            {
                *itZ = f - s;
                itZ++;
            }
            s = 0, f = 0;
        }
        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }
};
inline std::istream &operator>>(std::istream &value, BigInt &x)
{
    string s;
    value >> s;
    x = BigInt(s);
    return value;
}
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

inline BigInt operator+(BigInt &x, BigInt &y)
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
    else if (x.mIsNegative && !y.mIsNegative)
    {
        x.mIsNegative = false;
        if (x <= y)
            return BigInt::subtractAbsValues(y, x);
        else if (x > y)
        {
            res << "-";
            res << BigInt::subtractAbsValues(x, y);
            return BigInt(res.str());
        }
    }
    else if (!x.mIsNegative && y.mIsNegative)
    {
        y.mIsNegative = false;
        if (x > y)
            return BigInt::subtractAbsValues(x, y);
        else if (x < y)
        {
            res << "-";
            res << BigInt::subtractAbsValues(y, x);
            return BigInt(res.str());
        }
    }
    throw std::runtime_error("invalid computation");
}
inline BigInt operator-(BigInt &x, BigInt &y)
{
    std::ostringstream res;
    if (!x.mIsNegative && !y.mIsNegative) // 12 - 23
    {
        if (x >= y)
            return BigInt::subtractAbsValues(x, y);
        else
        {
            res << "-";
            res << BigInt::subtractAbsValues(y, x);
            return BigInt(res.str());
        }
    }
    else if (x.mIsNegative && !y.mIsNegative) // (-45) - 23
    {
        y.mIsNegative = true; // (-23)
        return x + y;         // (-45) + (-23)
    }
    else if (!x.mIsNegative && y.mIsNegative) // 3434 - (-1234)
    {
        y.mIsNegative = false; // 3434 + 1234
        return x + y;
    }
    else if (x.mIsNegative && y.mIsNegative) // (-765) - (-8594)
    {
        y.mIsNegative = false; // (-765) - 8594
        return x + y;          // (-765) + 8594
    }
    throw std::runtime_error("invalid computation");
}
inline bool operator<=(BigInt &x, BigInt &y)
{
    if (x < y || x == y)
    {
        return true;
    }
    return false;
}
inline bool operator>=(BigInt &x, BigInt &y)
{
    if (x > y || x == y)
    {
        return true;
    }
    return false;
}

inline bool operator==(BigInt &x, BigInt &y)
{
    if (!(x > y) && !(x < y))
    {
        return true;
    }

    return false;
}
inline bool operator!=(BigInt &x, BigInt &y)
{
    if (!(x == y))
    {
        return true;
    }
    return false;
}
inline bool operator<(BigInt &x, BigInt &y)
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
            if (checkTheValuesOfEqualSizes2(x, y, count))
                return true;
            else if (count == (int)y.mDigits.size())
                return false;
            else
                return false;
        }
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        if (x.mDigits.size() > y.mDigits.size()) // 12345 > 1234
        {
            return true;
        }
        else if (x.mDigits.size() == y.mDigits.size()) // 123 < 234
        {
            if (checkTheValuesOfEqualSizes2(x, y, count))
                return false;
            else if (count == (int)y.mDigits.size())
                return false;
            else
                return false;
        }
    }
    else if (!x.mIsNegative && y.mIsNegative)
    {
        return false;
    }
    return true;
}
inline bool operator>(BigInt &x, BigInt &y)
{
    int count = 0;
    if (!x.mIsNegative && !y.mIsNegative)
    {
        if (x.mDigits.size() < y.mDigits.size()) // 12 < 123
            return false;
        else if (x.mDigits.size() == y.mDigits.size())
        {
            if (checkTheValuesOfEqualSizes1(x, y, count))
                return true;
            else
                return false;
        }
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        if (x.mDigits.size() > y.mDigits.size()) // 12 < 123
            return false;
        else if (x.mDigits.size() == y.mDigits.size())
        {
            if (checkTheValuesOfEqualSizes1(x, y, count))
                return false;
            else if (count != (int)y.mDigits.size())
                return true;
            else
                return false;
        }
    }
    else if (x.mIsNegative && !y.mIsNegative)
        return false;
    return true;
}
inline bool checkTheValuesOfEqualSizes1(BigInt &x, BigInt &y, int &count)
{
    for (auto i = x.mDigits.begin(), j = y.mDigits.begin(); i != x.mDigits.end(); i++, j++)
    {
        if (*i > *j)
            return true;
        else if (*i < *j)
            return false;
        else if (*i == *j)
            count++;
    }
    return false;
}
inline bool checkTheValuesOfEqualSizes2(BigInt &x, BigInt &y, int &count)
{
    for (auto i = x.mDigits.begin(), j = y.mDigits.begin(); i != x.mDigits.end(); i++, j++)
    {
        if (*i < *j)
            return true;
        else if (*i > *j)
            return false;
        else if (*i == *j)
            count++;
    }
    return false;
}