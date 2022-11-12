#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
class BigInt
{

    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    std::vector<int> mDigits;
    bool mIsNegative;
    bool mIsLetter;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }
    BigInt(const std::string &value)
        : mIsNegative(false)
    {
        if (value.length() == 0)
        {
            throw std::runtime_error("empty");
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
    const std::vector<int> &getMDigits() const
    {
        return mDigits;
    }
};
inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{

    if (x.mIsNegative)
    {
        out << "-";
    }
    for (auto digit : x.getMDigits())
    {
        out << digit;
    }
    return out;
}
BigInt operator+(const BigInt &n1, const BigInt &n2)
{
    std::vector<int> res;
    std::vector<int> numToRem;
    int i = n1.getMDigits().size() - 1;
    int j = n2.getMDigits().size() - 1;
    while (i >= 0 && j >= 0)
    {
        int sum = (n1.getMDigits().at(i) + n2.getMDigits().at(j)) % 10;
        if (numToRem.size() != 0)
        {
            res.push_back((sum + numToRem[0]) % 10);
            numToRem.clear();
        }
        else
        {
            res.push_back(sum);
        }
        numToRem.push_back((n1.getMDigits().at(i) + n2.getMDigits().at(j)) / 10);
        i--;
        j--;
    }
    while (i >= 0)
    {
        if (numToRem.size() != 0)
        {
            res.push_back(numToRem[0] + n1.getMDigits()[i]);
            numToRem.clear();
        }
        else
        {
            res.push_back(n1.getMDigits()[i]);
        }
        i--;
    }
    while (j >= 0)
    {
        if (numToRem.size() != 0)
        {
            res.push_back(numToRem[0] + n2.getMDigits()[j]);
            numToRem.clear();
        }
        else
        {
            res.push_back(n2.getMDigits()[j]);
        }
        j--;
    }

    reverse(res.begin(), res.end());
    std::ostringstream s;
    for (int k = 0; k < (int)res.size(); k++)
    {
        s << res[k];
    }
    return BigInt(s.str());
}
// inline BigInt operator==(const BigInt &n1, const BigInt &n2)
// {

// }