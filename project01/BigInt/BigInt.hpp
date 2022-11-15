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
    std::vector<int> res;
    std::vector<int> first;
    std::vector<int> second;
    if (n1.getMDigits().size() > n2.getMDigits().size())
    {
        first = n1.getMDigits();
        second = n2.getMDigits();
    }
    else
    {
        first = n2.getMDigits();
        second = n1.getMDigits();
    }
    int numToRem = 0;
    int j = second.size() - 1;
    int numOfSecondV = 0;
    for (int i = first.size() - 1; i >= 0; i--)
    {
        if (j < 0)
        {
            numOfSecondV = 0;
        }
        else
        {
            numOfSecondV = second[j];
        }
        int n = (numOfSecondV + first[i] + numToRem) % 10; // problem fixed with adding numToRem
        res.push_back(n);
        numToRem = (numOfSecondV + first[i] + numToRem) / 10;
        j--;
    }
    if (numToRem == 1)
    {
        res.push_back(1);
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
    std::vector<int> first;
    std::vector<int> second;
    std::ostringstream s;
    int i = 0;
    int j = 0;
    bool isFirst = true;
    if (n1.getMDigits().size() > n2.getMDigits().size())
    {
        i = n1.getMDigits().size() - 1;
        j = n2.getMDigits().size() - 1;
    }
    else if (n1.getMDigits().size() < n2.getMDigits().size())
    {
        isFirst = false;
        i = n2.getMDigits().size() - 1;
        j = n1.getMDigits().size() - 1;
    }
    else if (n1.getMDigits().size() == n2.getMDigits().size())
    {
        for (int k = 0, l = 0; k < (int)n1.getMDigits().size() && l < (int)n2.getMDigits().size(); k++, l++)
        {
            if (n1.getMDigits()[k] < n2.getMDigits()[l])
            {
                isFirst = false;
                i = n2.getMDigits().size() - 1;
                j = n1.getMDigits().size() - 1;
                break;
            }
            else if (n1.getMDigits()[k] > n2.getMDigits()[l])
            {
                i = n1.getMDigits().size() - 1;
                j = n2.getMDigits().size() - 1;
                break;
            }
        }
    }

    if (isFirst)
    {
        for (int k = 0; k <= i; k++)
        {
            first.push_back(n1.getMDigits()[k]);
        }
        for (int k = 0; k <= j; k++)
        {
            second.push_back(n2.getMDigits()[k]);
        }
    }
    else
    {
        s << "-";
        for (int k = 0; k <= i; k++)
        {
            first.push_back(n2.getMDigits()[k]);
        }
        for (int k = 0; k <= j; k++)
        {
            second.push_back(n1.getMDigits()[k]);
        }
    }

    std::vector<int> res;
    std::string temp = "";
    while (i >= 0 && j >= 0)
    {
        if (j == 0)
        {
            for (int k = 0; k <= i - j; k++)
            {
                temp += std::to_string(first[k]);
            }
            res.push_back((stoi(temp)) - second[j]);
            temp = "";
        }
        else if (first[i] < second[j])
        {
            for (int k = i - 1; k >= 0; k--)
            {
                if (first[k] != 0)
                {
                    first[k]--;
                    temp += "1";
                    break;
                }
                else if (first[k] == 0)
                {
                    first[k] = 9;
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

    while (res[0] == 0)
    {
        res.erase(res.begin());
    }
    if (res.size() == 0)
    {
        return BigInt("0");
    }
    for (int k = 0; k < (int)res.size(); k++)
    {
        s << res[k];
    }
    return BigInt(s.str());
}
// inline bool operator==(BigInt &a, BigInt &b)
// {
//     if (a > b)
//     {
//         return false;
//     }
//     else if (a < b)
//     {
//         return false;
//     }
//     return true;
// }
// inline bool operator<(BigInt &a, BigInt &b)
// {
//     if (a.getMDigits().size() < b.getMDigits().size())
//     {
//         return true;
//     }
//     else if (a.getMDigits().size() == b.getMDigits().size())
//     {
//         for (int i = 0; i < (int)a.getMDigits().size(); i++)
//         {
//             if (a.getMDigits()[i] < b.getMDigits()[i])
//             {
//                 return true;
//                 break;
//             }
//         }
//     }
//     return false;
// }
// inline bool operator>(BigInt &a, BigInt &b)
// {
//     if (a.getMDigits().size() > b.getMDigits().size())
//     {
//         return true;
//     }
//     else if (a.getMDigits().size() == b.getMDigits().size())
//     {
//         for (int i = 0; i < (int)a.getMDigits().size(); i++)
//         {
//             if (a.getMDigits()[i] > b.getMDigits()[i])
//             {
//                 return true;
//                 break;
//             }
//         }
//     }
//     return false;
// }
// inline BigInt operator==(const BigInt &n1, const BigInt &n2)
// {

// }