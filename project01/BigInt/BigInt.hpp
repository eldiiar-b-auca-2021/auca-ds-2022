#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
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
        for (auto r : value)
        {
            if (isdigit(r) && r != '-')
            {
                mDigits.push_back(r - '0');
            }
            else if (r == '-')
            {
                mIsNegative = true;
            }
            else
            {
                throw std::runtime_error("it is not digit");
            }
        }
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