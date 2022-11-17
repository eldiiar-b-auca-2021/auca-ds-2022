#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
class BigInt
{
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend bool operator>(const BigInt &a, const BigInt &b);
    friend BigInt operator+(const BigInt &n1, const BigInt &n2);
    friend BigInt operator-(const BigInt &n1, const BigInt &n2);
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    std::vector<int> mDigits;
    mutable bool mIsNegative;

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
inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    vector<int> first;
    vector<int> second;
    string result;

    if (x.getMDigits().size() > y.getMDigits().size())
    {
        first = x.getMDigits();
        second = y.getMDigits();
    }
    else
    {
        first = y.getMDigits();
        second = x.getMDigits();
    }
    int j = second.size() - 1;
    int remainder = 0;
    int valueOfJ = 0;
    for (int i = (int)first.size() - 1; i >= 0; i--)
    {
        if (j < 0)
        {
            valueOfJ = 0;
        }
        else
        {
            valueOfJ = second[j];
        }
        int t = (first[i] + valueOfJ + remainder);
        result += to_string(t % 10);
        remainder = t / 10;
        j--;
    }
    if (remainder == 1)
    {
        result += to_string(1);
    }
    reverse(result.begin(), result.end());
    return BigInt(result);
}
inline BigInt operator-(const BigInt &x, const BigInt &y)
{
    vector<int> first;
    vector<int> second;
    string result;
    int a = 0;
    int b = 0;
    bool isFirstLonger = true;
    if (x.mDigits.size() > y.mDigits.size())
    {
        a = x.mDigits.size() - 1;
        b = y.mDigits.size() - 1;
    }
    else if (x.mDigits.size() < y.mDigits.size())
    {
        isFirstLonger = false;
        a = y.mDigits.size() - 1;
        b = x.mDigits.size() - 1;
    }
    else if (x.mDigits.size() == y.mDigits.size())
    {
        for (int i = 0; i < (int)x.mDigits.size(); i++)
        {
            if (x.mDigits[i] > y.mDigits[i])
            {
                a = x.mDigits.size() - 1;
                b = y.mDigits.size() - 1;
                break;
            }
            else if (x.mDigits[i] < y.mDigits[i])
            {
                isFirstLonger = false;
                a = y.mDigits.size() - 1;
                b = x.mDigits.size() - 1;
                break;
            }
        }
    }
    if (isFirstLonger)
    {
        for (int i = 0; i <= a; i++)
        {
            first.push_back(x.mDigits[i]);
        }
        for (int i = 0; i <= b; i++)
        {
            second.push_back(y.mDigits[i]);
        }
    }
    else
    {
        for (int i = 0; i <= a; i++)
        {
            first.push_back(y.mDigits[i]);
        }
        for (int i = 0; i <= b; i++)
        {
            second.push_back(x.mDigits[i]);
        }
    }
    int j = second.size() - 1;
    for (int i = (int)first.size() - 1; i >= 0; i--)
    {
        if (j < 0)
        {
            result += to_string(first[i]);
        }
        else if (first[i] < second[j])
        {
            for (int k = i - 1; k >= 0; k--)
            {
                if (first[k] != 0)
                {
                    first[k]--;
                    break;
                }
                else if (first[k] == 0)
                {
                    first[k] = 9;
                }
            }
            result += to_string((first[i] + 10) - second[j]);
        }
        else
        {
            result += to_string(first[i] - second[j]);
        }
        j--;
    }
    int size = result.size() - 1;
    while (result[size--] == '0' && size >= 0)
    {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return BigInt(result);
}
// inline bool operator==(const BigInt &a, const BigInt &b)
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
// inline bool operator<(const BigInt &a, const BigInt &b)
// {
//     if (a > b)
//     {
//         return false;
//     }
//     else if (a > b)
//     {
//         return false;
//     }
//     else if (a == b)
//     {
//         return false;
//     }
//     return true;
// }
// inline bool operator>(const BigInt &a, const BigInt &b)
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
// inline BigInt operator+(const BigInt &n1, const BigInt &n2)
// {
//     string res;
//     vector<int> first;
//     vector<int> second;
//     bool isNegative = false;
//     if (!n1.mIsNegative && n2.mIsNegative) // 12 + (-12)
//     {
//         n2.mIsNegative = false;
//         return n1 - n2;
//     }
//     else if (n1.mIsNegative && n2.mIsNegative) // -12 + (-12)
//     {
//         isNegative = true;
//     }
//     else if (n1.mIsNegative && !n2.mIsNegative) // -12 + 12
//     {
//         n1.mIsNegative = false;
//         return n2 - n1;
//     }
//     if (n1.getMDigits().size() > n2.getMDigits().size())
//     {
//         first = n1.getMDigits();
//         second = n2.getMDigits();
//     }
//     else
//     {
//         first = n2.getMDigits();
//         second = n1.getMDigits();
//     }
//     int numToRem = 0;
//     int j = second.size() - 1;
//     int numOfSecondV = 0;
//     for (int i = first.size() - 1; i >= 0; i--)
//     {
//         if (j < 0)
//         {
//             numOfSecondV = 0;
//         }
//         else
//         {
//             numOfSecondV = second[j];
//         }
//         int n = (numOfSecondV + first[i] + numToRem) % 10; // problem fixed with adding numToRem
//         res += to_string(n);
//         numToRem = (numOfSecondV + first[i] + numToRem) / 10;
//         j--;
//     }
//     if (numToRem == 1)
//     {
//         res += to_string(1);
//     }
//     reverse(res.begin(), res.end());
//     if (isNegative && res.size() > 1)
//     {
//         res.insert(0, "-");
//     }
//     return BigInt(res);
// }
// inline BigInt operator-(const BigInt &n1, const BigInt &n2)
// {
//     vector<int> first;
//     vector<int> second;
//     ostringstream s;
//     int i;
//     int j;
//     bool isFirst = true;

//     if (n1.mIsNegative && !n2.mIsNegative) // (-12) - (12)
//     {
//         n2.mIsNegative = true;
//         return n1 + n2
//     }
//     else if (n1.mIsNegative && n2.mIsNegative) // (-12) -(-12)
//     {
//         n2.mIsNegative = false; // -12 + 12
//         return n1 + n2;
//     }
//     else if (!n1.mIsNegative && n2.mIsNegative) // 12 - (-12)
//     {
//         n2.mIsNegative = false; // 12 + 12
//         return n1 + n2;
//     }
//     if (n1.getMDigits().size() > n2.getMDigits().size())
//     {
//         i = n1.getMDigits().size() - 1;
//         j = n2.getMDigits().size() - 1;
//     }
//     else if (n1.getMDigits().size() < n2.getMDigits().size())
//     {
//         isFirst = false;
//         i = n2.getMDigits().size() - 1;
//         j = n1.getMDigits().size() - 1;
//     }
//     else if (n1.getMDigits().size() == n2.getMDigits().size())
//     {
//         for (int k = 0, l = 0; k < (int)n1.getMDigits().size() && l < (int)n2.getMDigits().size(); k++, l++)
//         {
//             if (n1.getMDigits()[k] < n2.getMDigits()[l])
//             {
//                 isFirst = false;
//                 i = n2.getMDigits().size() - 1;
//                 j = n1.getMDigits().size() - 1;
//                 break;
//             }
//             else if (n1.getMDigits()[k] > n2.getMDigits()[l])
//             {
//                 i = n1.getMDigits().size() - 1;
//                 j = n2.getMDigits().size() - 1;
//                 break;
//             }
//         }
//     }

//     if (isFirst)
//     {
//         for (int k = 0; k <= i; k++)
//         {
//             first.push_back(n1.getMDigits()[k]);
//         }
//         for (int k = 0; k <= j; k++)
//         {
//             second.push_back(n2.getMDigits()[k]);
//         }
//     }
//     else
//     {
//         s << "-";
//         for (int k = 0; k <= i; k++)
//         {
//             first.push_back(n2.getMDigits()[k]);
//         }
//         for (int k = 0; k <= j; k++)
//         {
//             second.push_back(n1.getMDigits()[k]);
//         }
//     }

//     std::vector<int> res;
//     std::string temp = "";
//     while (i >= 0 && j >= 0)
//     {
//         if (j == 0)
//         {
//             for (int k = 0; k <= i - j; k++)
//             {
//                 temp += std::to_string(first[k]);
//             }
//             res.push_back((stoi(temp)) - second[j]);
//             temp = "";
//         }
//         else if (first[i] < second[j])
//         {
//             for (int k = i - 1; k >= 0; k--)
//             {
//                 if (first[k] != 0)
//                 {
//                     first[k]--;
//                     temp += "1";
//                     break;
//                 }
//                 else if (first[k] == 0)
//                 {
//                     first[k] = 9;
//                 }
//             }
//             temp += std::to_string(first[i]);
//             res.push_back((stoi(temp)) - second[j]);
//             temp = "";
//         }
//         else
//         {
//             res.push_back(first[i] - second[j]);
//         }
//         i--;
//         j--;
//     }
//     reverse(res.begin(), res.end());
//     if (res.size() == 1 && res[0] == 0)
//     {
//         return BigInt("0");
//     }
//     while (res[0] == 0)
//     {
//         res.erase(res.begin());
//     }

//     for (int k = 0; k < (int)res.size(); k++)
//     {
//         s << res[k];
//     }
//     return BigInt(s.str());
// }
