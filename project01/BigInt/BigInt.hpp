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
            if (r == '0' && isFirst)
            {
                throw std::runtime_error("invalid digit");
            }
            else if (isdigit(r))
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
    const bool &getIsNegative() const
    {
        return mIsNegative;
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
inline BigInt operator+(BigInt &n1, BigInt &n2)
{
    std::ostringstream s;
    if (n1.getIsNegative() && n2.getIsNegative())
    {
        s << "-";
    }
    // else if (n1.getIsNegative() && !n2.getIsNegative())
    // {
    //     BigInt result = n2 - n1;
    //     return result;
    // }
    std::vector<int> res;
    std::vector<int> numToRem;
    int i = n1.getMDigits().size() - 1;
    int j = n2.getMDigits().size() - 1;
    while (i >= 0 && j >= 0)
    {
        bool isAdded = true;
        int sum = (n1.getMDigits().at(i) + n2.getMDigits().at(j)) % 10;
        if (numToRem.size() != 0)
        {
            if (i == 0 && j == 0)
            {
                res.push_back(((n1.getMDigits().at(i) + n2.getMDigits().at(j)) + numToRem[0]));
                numToRem.clear();
            }
            else if (((sum + numToRem[0]) / 10) != 0)
            {
                res.push_back((sum + numToRem[0]) % 10);
                numToRem.push_back((sum + numToRem[0]) / 10);
                numToRem.erase(numToRem.begin());
                isAdded = false;
            }
            else
            {
                res.push_back((sum + numToRem[0]) % 10);
                numToRem.clear();
            }
        }
        else
        {
            res.push_back(sum);
        }
        if (isAdded)
        {
            numToRem.push_back((n1.getMDigits().at(i) + n2.getMDigits().at(j)) / 10);
        }
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

    for (int k = 0; k < (int)res.size(); k++)
    {
        s << res[k];
    }
    return BigInt(s.str());
}
inline BigInt operator-(const BigInt &n1, const BigInt &n2)
{
    // BigInt res;
    // if (n1.getIsNegative() && n2.getIsNegative())
    // {
    //     res = n2 - n1;
    // }
    // else if (n1.getIsNegative() && !n2.getIsNegative())
    // {
    //     res = n1 - n2;
    // }
    int i = n1.getMDigits().size() - 1;
    int j = n2.getMDigits().size() - 1;
    std::vector<int> first;
    std::vector<int> second;

    for (int k = 0; k <= i; k++)
    {
        first.push_back(n1.getMDigits()[k]);
    }
    for (int k = 0; k <= j; k++)
    {
        second.push_back(n2.getMDigits()[k]);
    }
    for (int k = 0, l = 0; k < i && l < j; k++, l++)
    {
        if (first[k] > second[l])
        {
        }
        else if (first[k] < second[l])
        {
        }
    }
    std::vector<int> res;
    std::string temp = "";
    while (i >= 0 && j >= 0)
    {
        if (first[i] < second[j])
        {
            for (int k = i - 1; k >= 0; k--)
            {
                if (first[k] != 0)
                {
                    first[k]--;
                    temp += "1";
                    break;
                }
            }
            temp += std::to_string(first[i]);
            res.push_back((stoi(temp)) - second[j]);
            temp = "";
        }
        else
        {
            res.push_back(first[i] - second[j]);
        }
        i--;
        j--;
    }
    reverse(res.begin(), res.end());
    std::ostringstream s;
    bool isFirstZero = true;
    for (int k = 0; k < (int)res.size(); k++)
    {
        if (res[k] != 0 && isFirstZero)
        {
            s << res[k];
            isFirstZero = false;
        }
        else if (!isFirstZero)
        {
            s << res[k];
        }
    }
    return BigInt(s.str());
}
// inline BigInt operator==(const BigInt &n1, const BigInt &n2)
// {

// }