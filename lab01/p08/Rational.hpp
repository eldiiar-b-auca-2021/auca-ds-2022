#pragma once
#include <iostream>
template <typename T>
class Rational
{
    // by default everything is private
    T mNum; // data member, field
    T mDen;

public:
    Rational()
        : mNum(0), mDen(1) // we can initialize even constants, references + more efficient
    {
    }
    Rational(const T &num, const &den)
        : mNum(num), mDen(den)
    {
        if (mDen == 0)
        {
            throw std::runtime_error("Rational is equal to zero");
        }
    }
    const T &num() const
    {
        return mNum;
    }

    const T &den() const
    {
        return mDen;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &x)
{
    out << x.num() << "/" << x.den();
    return out;
}