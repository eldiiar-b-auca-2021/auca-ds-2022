#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Rational
{
    // by default everything is private
    T mNum; // data member, field
    T mDen;

public:
    Rational()
        : mNum(0), mDen(1)
    {
    }
    Rational(const T &num)
        : mNum(num), mDen(1) // we can initialize even constants, references + more efficient
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
        mDen /= a;

        if (mDen < 0)
        {
            mNum = -mNum;
            mDen = -mDen;
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
template <typename T>
std::istream &operator>>(std::istream &inp, Rational<T> &r)
{
    T num;
    if (!(inp >> num))
    {
        return inp;
    }

    char ch;
    if (!inp.get(ch))
    {
        return inp;
    }
    if (ch != '/')
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }
    if (!inp.get(ch))
    {
        return inp;
    }
    if (ch == '+' || ch == '-')
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
    if (!(inp >> den))
    {
        return inp;
    }
    r = Rational<T>(num, den);
    return inp;
}
template <typename T>
Rational<T> operator+(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() + a.den() * b.num();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator-(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() - a.den() * b.num();
    T den = a.den() * b.den();
    return Rational<T>(num, den);
}
template <typename T>
Rational<T> operator*(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.num();
    T den = a.den() * b.den();
    return Rational<T>(num, den);
}
template <typename T>
Rational<T> operator/(const Rational<T> &a, const Rational<T> &b)
{
    if (b == Rational<T>())
    {
        throw std::runtime_error("Rational: division by zero");
    }
    T num = a.num() * b.den();
    T den = a.den() * b.num();
}
template <typename T>
bool operator==(const Rational<T> &a, const Rational<T> &b)
{
    return a.den() == b.den() && a.num() == b.num();
}
template <typename T>
bool operator!=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a == b);
}
template <typename T>
bool operator>(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() > a.den() * b.num();
}
template <typenmae T>
bool operator<(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() < a.den() * b.num();
}
template <typename T>
bool operator<=(const Rational<T> &a, const Rational<T> &b)
{
    return !(b < a);
}
template <typename T>
bool operator>=(const Rational<T> &a, const Rational<T> &b)
{
    return !(b > a);
}
