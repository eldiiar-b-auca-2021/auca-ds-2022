#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class BigInt
{
    friend BigInt operator-=(BigInt &x, const BigInt &y);
    friend BigInt operator+=(BigInt &x, const BigInt &y);
    friend bool checkTheValuesOfEqualSizes1(const BigInt &x, const BigInt &y, int &count);
    friend bool checkTheValuesOfEqualSizes2(const BigInt &x, const BigInt &y, int &count);
    friend BigInt operator*(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator<(const BigInt &x, const BigInt &y);
    friend bool operator>(const BigInt &x, const BigInt &y);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);
    friend bool operator>=(const BigInt &x, const BigInt &y);
    friend bool operator<=(const BigInt &x, const BigInt &y);
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &value, const BigInt &x);
    friend bool checkBiggestOne(const BigInt &x, const BigInt &y);

public:
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
    static BigInt subtractAbsValues(const BigInt &x, const BigInt &y)
    {
        int xValue = 0, yValue = 0, temp = 0, sum = 0;
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();
        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()));
        auto itZ = z.mDigits.rbegin();
        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            if (itX != x.mDigits.rend())
            {
                xValue = *itX;
                itX++;
            }
            if (itY != y.mDigits.rend())
            {
                yValue = *itY;
                itY++;
            }
            sum = xValue - yValue + temp;
            if (sum < 0)
            {
                sum += 10;
                temp = -1;
            }
            else
                temp = 0;
            yValue = 0;
            xValue = 0;
            *itZ = sum;
            itZ++;
        }
        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }
        return z;
    }
    static BigInt multiplication(const BigInt &x, const BigInt &y)
    {
        int count = 0, sum = 0;
        int temp = 0;
        BigInt res;
        string s;
        for (auto itY = y.mDigits.rbegin(); itY != y.mDigits.rend(); ++itY)
        {
            for (auto itX = x.mDigits.rbegin(); itX != x.mDigits.rend(); itX++)
            {
                sum = ((*itX) * (*itY) + temp);
                temp = sum / 10;
                s += to_string(sum % 10);
            }
            if (temp != 0)
                s += to_string(temp);
            temp = 0;
            reverse(s.begin(), s.end());
            for (int i = 0; i < count; i++)
                s += "0";
            while (s[0] == '0' && s.size() > 1)
            {
                s.erase(s.begin());
            }
            res = res + BigInt(s);
            count++;
            s = "";
        }
        return res;
    }
};
inline std::istream &operator>>(std::istream &value, BigInt &x)
{
    char ch;
    if (!(value >> ch))
    {
        return value;
    }
    if (!(isdigit(ch) || ch == '-' || ch == '+'))
    {
        value.putback(ch);
        value.setstate(std::ios_base::failbit);
        return value;
    }
    std::string s;
    s += ch;
    while (value.get(ch) && isdigit(ch))
    {
        s += ch;
    }

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
inline BigInt operator*(const BigInt &x, const BigInt &y)
{
    if ((!x.mIsNegative && !y.mIsNegative) || (x.mIsNegative && y.mIsNegative))
    {
        return BigInt::multiplication(x, y);
    }
    else if ((x.mIsNegative && !y.mIsNegative) || (y.mIsNegative && !x.mIsNegative))
    {
        BigInt res = BigInt::multiplication(x, y);
        res.mIsNegative = true;
        return res;
    }
    throw std::runtime_error("invalid computation");
}
inline BigInt operator+=(BigInt &x, const BigInt &y)
{
    x = x + y;
    return x;
}
inline BigInt operator-=(BigInt &x, const BigInt &y)
{
    x = x - y;
    return x;
}
inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    if (!x.mIsNegative && !y.mIsNegative)
    {
        return BigInt::addAbsValues(x, y);
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        BigInt res = BigInt::addAbsValues(x, y);
        res.mIsNegative = true;
        return res;
    }
    else if (x.mIsNegative && !y.mIsNegative)
    {
        x.mIsNegative = false;
        if (x <= y)
        {
            x.mIsNegative = true;
            return BigInt::subtractAbsValues(y, x);
        }
        else if (x > y)
        {
            x.mIsNegative = false;
            BigInt ans = BigInt::subtractAbsValues(x, y);
            ans.mIsNegative = true;
            return ans;
        }
    }
    else if (!x.mIsNegative && y.mIsNegative)
    {
        y.mIsNegative = false;
        if (x >= y)
        {
            y.mIsNegative = true;
            return BigInt::subtractAbsValues(x, y);
        }
        else if (x < y)
        {
            y.mIsNegative = true;
            BigInt ans = BigInt::subtractAbsValues(y, x);
            ans.mIsNegative = true;
            return ans;
        }
    }
    throw std::runtime_error("invalid computation");
}
inline BigInt operator-(const BigInt &x, const BigInt &y)
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
        res << x + y;
        y.mIsNegative = false;
        return BigInt(res.str()); // (-45) + (-23)
    }
    else if (!x.mIsNegative && y.mIsNegative) // 3434 - (-1234)
    {
        y.mIsNegative = false; // 3434 + 1234
        res << x + y;
        y.mIsNegative = true;
        return BigInt(res.str());
    }
    else if (x.mIsNegative && y.mIsNegative) // (-765) - (-8594)
    {
        y.mIsNegative = false; // (-765) - 8594
        res << x + y;
        y.mIsNegative = true;
        return BigInt(res.str()); // (-765) + 8594
    }
    throw std::runtime_error("invalid computation");
}
inline bool operator<=(const BigInt &x, const BigInt &y)
{
    if (x < y || x == y)
    {
        return true;
    }
    return false;
}
inline bool operator>=(const BigInt &x, const BigInt &y)
{
    if (x > y || x == y)
    {
        return true;
    }
    return false;
}

inline bool operator==(const BigInt &x, const BigInt &y)
{
    if (!(x > y) && !(x < y))
    {
        return true;
    }

    return false;
}
inline bool operator!=(const BigInt &x, const BigInt &y)
{
    if (!(x == y))
    {
        return true;
    }
    return false;
}
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
inline bool operator>(const BigInt &x, const BigInt &y)
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
inline bool checkTheValuesOfEqualSizes1(const BigInt &x, const BigInt &y, int &count)
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
inline bool checkTheValuesOfEqualSizes2(const BigInt &x, const BigInt &y, int &count)
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