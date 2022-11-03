#pragma once
#include <iostream>
#include <stdexcept>
template <typename T>
class Rational
{
    T mNum;
    T mDen;

public:
    Rational()
        : mNum(0), mDen(1)
    {
    }
    Rational(const T &num, const T &den)
        : mNum(num), mDen(den)
    {
        if (mDen == 0)
        {
            throw std::runtime_error("Rational is equal to zero");
        }
        T a = abs(mNum);
        T b = abs(mDen);
        while (b != 0)
        {
            T t = a % b;
            a = b;
            b = t;
        }
        mNum /= a;
        mDen /= b;

        if (mDen < 0)
        {
            mNum = -mNum;
            mDen = -mDen;
        }
    }
    Rational(const T &num)
        : mNum(num), mDen(1)
    {
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
std::ostream &operator<<(std::ostream &out, const Rational<T> &r)
{
    out << r.num() << "/" << r.den();
    return out;
}
template <typename T>
Rational<T> operator+(const Rational<T> &r1, const Rational<T> &r2)
{
    T num = r1.num() * r2.den() + r1.den() * r2.num();
    T den = r1.den() * r2.den();
    return Rational<T>(num, den);
}
template <typename T>
std::istream operator>>(std::istream &inp, const Rational<T> &r)
{
    T num;
    if (!(inp >> num))
    {
        return inp;
    }
    char ch;
    if (!(inp.get(ch)))
    {
        return inp;
    }
    if (ch != '/')
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }
    if (!(inp.get(ch)))
    {
        inp.putback(ch);
        return inp;
    }
    if (ch == '-' || ch == '+' || isdigit(ch))
    {
        inp.putback(ch);
    }
    else
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }
    T den;
    inp >> den;
    r = Rational<T>(num, den);
    return inp;
}
